/* C2 JTAG mailbox firmware: no UART transmit or receive path. */
#include "rtnn_experiment_runner.h"
#include "rtnn_experiment_wire.h"
#include "heldout360.h"
#include <stdint.h>

#define C2_MMIO_BASE       UINT32_C(0x00020000)
#define C2_STATUS          (C2_MMIO_BASE + UINT32_C(0x020))
#define C2_REQ_WORDS       (C2_MMIO_BASE + UINT32_C(0x024))
#define C2_REQ_ACK         (C2_MMIO_BASE + UINT32_C(0x088))
#define C2_RSP_WORDS       (C2_MMIO_BASE + UINT32_C(0x08c))
#define C2_RSP_COMMIT      (C2_MMIO_BASE + UINT32_C(0x0bc))
#define C2_STATUS_VALID    UINT32_C(1)
#define C2_MODEL_ID        UINT32_C(0x52544e4e)
#ifndef C2_BUILD_ID
#define C2_BUILD_ID        UINT32_C(0x43324a31)
#endif
#define C2_REQUEST_BYTES   100u
#define C2_RESPONSE_BYTES  48u

static volatile uint32_t *mmio(uint32_t a) {
  return (volatile uint32_t *)(uintptr_t)a;
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
  return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
         ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static void store_response(const rtnn_exp_response_t *r) {
  uint8_t bytes[C2_RESPONSE_BYTES];
  rtnn_wire_encode_response(r, bytes);
  for (uint32_t i = 0; i < C2_RESPONSE_BYTES / 4u; ++i)
    *mmio(C2_RSP_WORDS + i * 4u) = load_le32(bytes + i * 4u);
  /* The peripheral only publishes after this final commit write. */
  *mmio(C2_RSP_COMMIT) = r->seq;
}

static void response_error(rtnn_exp_response_t *r, uint8_t status) {
  r->status = status;
  r->stop_reason = 0;
  r->admitted_exit = -1;
  r->executed_exit = -1;
  r->prediction = -1;
  r->label = -1;
  r->cycles = 0;
}

static int frozen_pixels_match(uint16_t id, const uint8_t *pixels) {
  if (id >= RTNN_TEST_COUNT) return 0;
  for (uint32_t i = 0; i < 64u; ++i)
    if (pixels[i] != rtnn_test_pixels[id][i]) return 0;
  return 1;
}

int main(void) {
  uint32_t last_seq = 0;
  uint8_t have_last_seq = 0;
  for (;;) {
    if ((*mmio(C2_STATUS) & C2_STATUS_VALID) == 0) continue;

    uint8_t wire[C2_REQUEST_BYTES];
    for (uint32_t i = 0; i < C2_REQUEST_BYTES / 4u; ++i) {
      uint32_t w = *mmio(C2_REQ_WORDS + i * 4u);
      wire[i*4u+0u]=(uint8_t)w; wire[i*4u+1u]=(uint8_t)(w>>8);
      wire[i*4u+2u]=(uint8_t)(w>>16); wire[i*4u+3u]=(uint8_t)(w>>24);
    }
    /* Copy complete request before acknowledging it; no JTAG activity is
       allowed to touch inference RAM after this point. */
    *mmio(C2_REQ_ACK) = 1u;

    rtnn_exp_request_t req = {0};
    rtnn_exp_response_t rsp = {0};
    int frame_ok = rtnn_wire_decode_request(wire, &req) == 0;
    if (frame_ok) {
      rsp.seq = req.seq; rsp.input_id = req.input_id; rsp.mode = req.mode;
      rsp.budget_q16 = req.budget_q16; rsp.deadline_cycles = req.deadline_cycles;
      rsp.model_id = C2_MODEL_ID; rsp.build_id = C2_BUILD_ID;
      if (rtnn_wire_crc(wire + RTNN_REQ_LEN, 64u) != load_le32(wire + 96u)) {
        response_error(&rsp, RTNN_STATUS_BAD_REQUEST);
      } else if (req.seq == 0u || (have_last_seq && req.seq == last_seq)) {
        response_error(&rsp, RTNN_STATUS_BAD_REQUEST);
      } else if (req.model_id != C2_MODEL_ID || req.build_id != C2_BUILD_ID) {
        response_error(&rsp, RTNN_STATUS_WRONG_ID);
      } else if (!frozen_pixels_match(req.input_id, wire + RTNN_REQ_LEN)) {
        response_error(&rsp, RTNN_STATUS_BAD_REQUEST);
      } else {
        rtnn_fw_config_t cfg = {0};
        cfg.model_id = C2_MODEL_ID; cfg.build_id = C2_BUILD_ID;
        cfg.binding_id = 0; cfg.has_fpga_cycle_binding = 0;
        cfg.cycle_now = machine_cycles;
        (void)rtnn_fw_execute(&req, &rsp, &cfg);
      }
      last_seq = req.seq; have_last_seq = 1;
    } else {
      /* Preserve request identity in a BAD_FRAME response even when the
         request CRC/version is invalid. These offsets are fixed by RTNQ v1. */
      rsp.seq = load_le32(wire + 8u);
      rsp.input_id = (uint16_t)wire[12] | ((uint16_t)wire[13] << 8);
      rsp.mode = wire[5]; rsp.budget_q16 = (uint16_t)wire[14] | ((uint16_t)wire[15] << 8);
      rsp.model_id = C2_MODEL_ID; rsp.build_id = C2_BUILD_ID;
      response_error(&rsp, RTNN_STATUS_BAD_FRAME);
    }
    store_response(&rsp);
  }
}
