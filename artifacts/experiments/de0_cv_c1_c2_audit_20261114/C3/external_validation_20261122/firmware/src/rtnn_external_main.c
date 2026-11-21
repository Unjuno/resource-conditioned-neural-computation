/* New-image JTAG firmware: the 64-byte payload, never a ROM lookup, feeds Q15. */
#include "rtnn_external_wire.h"
#include "rtnn_external_runner.h"
#include <stdint.h>

#define EXT_MMIO_BASE UINT32_C(0x00020000)
#define EXT_STATUS (EXT_MMIO_BASE + UINT32_C(0x020))
#define EXT_REQ_WORDS (EXT_MMIO_BASE + UINT32_C(0x024))
#define EXT_REQ_ACK (EXT_MMIO_BASE + UINT32_C(0x088))
#define EXT_RSP_WORDS (EXT_MMIO_BASE + UINT32_C(0x08c))
#define EXT_RSP_COMMIT (EXT_MMIO_BASE + UINT32_C(0x0c8))
#define EXT_STATUS_VALID UINT32_C(1)
#define EXT_MODEL_ID UINT32_C(0x52544e4e)
#define EXT_BUILD_ID UINT32_C(0x45585631)
#define EXT_BINDING_ID UINT32_C(0x45585632)

static volatile uint32_t *mmio(uint32_t address) {
  return (volatile uint32_t *)(uintptr_t)address;
}

static uint64_t machine_cycles(void *unused) {
  (void)unused;
  uint32_t hi0, lo, hi1;
  do {
    __asm__ volatile("csrr %0, mcycleh" : "=r"(hi0));
    __asm__ volatile("csrr %0, mcycle" : "=r"(lo));
    __asm__ volatile("csrr %0, mcycleh" : "=r"(hi1));
  } while (hi0 != hi1);
  return ((uint64_t)hi1 << 32) | lo;
}

static uint32_t load_le32(const uint8_t *p) {
  return (uint32_t)p[0] | ((uint32_t)p[1]<<8) |
         ((uint32_t)p[2]<<16) | ((uint32_t)p[3]<<24);
}
static uint16_t load_le16(const uint8_t *p) {
  return (uint16_t)p[0] | ((uint16_t)p[1]<<8);
}

static void set_error(rtnn_ext_response_t *r, uint8_t status) {
  r->status=status; r->stop_reason=RTNN_EXT_STOP_NONE;
  r->admitted_exit=-1; r->executed_exit=-1; r->prediction=-1; r->label=-1;
  r->cycles_start=0; r->cycles_end=0; r->flags=0;
}

static void publish_response(const rtnn_ext_response_t *response) {
  uint8_t bytes[RTNN_EXT_RSP_LEN];
  rtnn_ext_encode_response(response,bytes);
  for (uint32_t i=0; i<RTNN_EXT_RSP_LEN/4u; ++i)
    *mmio(EXT_RSP_WORDS+i*4u)=load_le32(bytes+i*4u);
  /* The mailbox publishes only after this sequence commit. */
  *mmio(EXT_RSP_COMMIT)=response->seq;
}

int main(void) {
  uint32_t last_seq=0;
  for (;;) {
    if ((*mmio(EXT_STATUS)&EXT_STATUS_VALID)==0) continue;

    /* Snapshot the complete immutable JTAG frame before acknowledging it. */
    uint8_t wire[RTNN_EXT_REQ_LEN];
    for (uint32_t i=0; i<RTNN_EXT_REQ_LEN/4u; ++i) {
      uint32_t w=*mmio(EXT_REQ_WORDS+i*4u);
      wire[i*4u+0u]=(uint8_t)w;
      wire[i*4u+1u]=(uint8_t)(w>>8);
      wire[i*4u+2u]=(uint8_t)(w>>16);
      wire[i*4u+3u]=(uint8_t)(w>>24);
    }
    *mmio(EXT_REQ_ACK)=1u;

    rtnn_ext_request_t req={0};
    rtnn_ext_response_t rsp={0};
    int header_status=rtnn_ext_decode_request_header(wire,&req);
    uint16_t raw_id=load_le16(wire+12);
    uint32_t payload_crc=rtnn_ext_crc32(wire+RTNN_EXT_REQ_HEADER_LEN,RTNN_EXT_PIXEL_LEN);
    rsp.seq=load_le32(wire+8);
    rsp.input_id=raw_id;
    rsp.mode=(wire[5]<=RTNN_EXT_MODE_ADAPTIVE)?wire[5]:0u;
    rsp.status=RTNN_EXT_STATUS_BAD_FRAME;
    rsp.stop_reason=RTNN_EXT_STOP_NONE;
    rsp.budget_q16=load_le16(wire+14);
    rsp.payload_crc32=payload_crc;
    rsp.admitted_exit=-1; rsp.executed_exit=-1;
    rsp.prediction=-1; rsp.label=-1;
    rsp.cycles_start=0; rsp.cycles_end=0;
    rsp.model_id=EXT_MODEL_ID; rsp.build_id=EXT_BUILD_ID;
    rsp.binding_id=EXT_BINDING_ID; rsp.flags=0;

    if (header_status==-2) {
      set_error(&rsp,RTNN_EXT_STATUS_BAD_REQUEST);
    } else if (header_status!=0) {
      set_error(&rsp,RTNN_EXT_STATUS_BAD_FRAME);
    } else {
      rsp.seq=req.seq; rsp.input_id=req.input_id; rsp.mode=req.mode;
      rsp.budget_q16=req.budget_q16;
      if (req.model_id!=EXT_MODEL_ID || req.build_id!=EXT_BUILD_ID) {
        set_error(&rsp,RTNN_EXT_STATUS_WRONG_ID);
      } else if (last_seq!=0u && req.seq<=last_seq) {
        set_error(&rsp,RTNN_EXT_STATUS_BAD_REQUEST);
      } else {
        /* Consume a valid new sequence even if payload validation fails. */
        last_seq=req.seq;
        if (load_le32(wire+96u)!=payload_crc) {
          set_error(&rsp,RTNN_EXT_STATUS_BAD_PAYLOAD);
        } else {
          const uint8_t *pixels=wire+RTNN_EXT_REQ_HEADER_LEN;
          uint32_t bad_pixel=0;
          for (uint32_t i=0; i<RTNN_EXT_PIXEL_LEN; ++i) bad_pixel|=(uint32_t)(pixels[i]>16u);
          if (bad_pixel) {
            set_error(&rsp,RTNN_EXT_STATUS_BAD_PAYLOAD);
          } else {
            rtnn_ext_config_t cfg={0};
            cfg.model_id=EXT_MODEL_ID; cfg.build_id=EXT_BUILD_ID;
            cfg.binding_id=EXT_BINDING_ID; cfg.cycle_now=machine_cycles;
            cfg.cycle_ctx=0;
            (void)rtnn_ext_execute(&req,pixels,payload_crc,&rsp,&cfg);
          }
        }
      }
    }
    publish_response(&rsp);
  }
}
