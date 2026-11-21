#include "rtnn_external_wire.h"

static uint16_t rd16(const uint8_t *b) { return (uint16_t)b[0] | ((uint16_t)b[1] << 8); }
static uint32_t rd32(const uint8_t *b) {
  return (uint32_t)b[0] | ((uint32_t)b[1] << 8) |
         ((uint32_t)b[2] << 16) | ((uint32_t)b[3] << 24);
}
static void wr16(uint8_t *b, uint16_t x) { b[0]=(uint8_t)x; b[1]=(uint8_t)(x>>8); }
static void wr32(uint8_t *b, uint32_t x) {
  for (unsigned i=0; i<4; ++i) b[i]=(uint8_t)(x>>(8u*i));
}
static void wr64(uint8_t *b, uint64_t x) {
  for (unsigned i=0; i<8; ++i) b[i]=(uint8_t)(x>>(8u*i));
}
static int magic4(const uint8_t *b, const char *s) {
  return b[0]==(uint8_t)s[0] && b[1]==(uint8_t)s[1] &&
         b[2]==(uint8_t)s[2] && b[3]==(uint8_t)s[3];
}

uint32_t rtnn_ext_crc32(const uint8_t *b, uint32_t n) {
  uint32_t c=0xffffffffu;
  for (uint32_t i=0; i<n; ++i) {
    c ^= b[i];
    for (unsigned j=0; j<8; ++j) {
      uint32_t mask=0u-(c&1u);
      c=(c>>1)^(0xedb88320u&mask);
    }
  }
  return ~c;
}

void rtnn_ext_encode_request_header(const rtnn_ext_request_t *p,
                                    uint8_t b[RTNN_EXT_REQ_HEADER_LEN]) {
  b[0]='R'; b[1]='T'; b[2]='N'; b[3]='Q'; b[4]=RTNN_EXT_REQUEST_VERSION;
  b[5]=p->mode; b[6]=p->fixed_exit; b[7]=0;
  wr32(b+8,p->seq); wr16(b+12,p->input_id); wr16(b+14,p->budget_q16);
  wr32(b+16,p->deadline_cycles); wr32(b+20,p->model_id); wr32(b+24,p->build_id);
  wr32(b+28,rtnn_ext_crc32(b,28));
}

int rtnn_ext_decode_request_header(const uint8_t *b, rtnn_ext_request_t *p) {
  if (!b || !p || !magic4(b,"RTNQ") || b[4]!=RTNN_EXT_REQUEST_VERSION ||
      b[7]!=0 || rd32(b+28)!=rtnn_ext_crc32(b,28)) return -1;
  p->mode=b[5]; p->fixed_exit=b[6]; p->seq=rd32(b+8); p->input_id=rd16(b+12);
  p->budget_q16=rd16(b+14); p->deadline_cycles=rd32(b+16);
  p->model_id=rd32(b+20); p->build_id=rd32(b+24);
  if (p->seq==0 || p->input_id==0 || p->input_id>RTNN_EXT_INPUT_COUNT ||
      p->budget_q16!=65535u || p->deadline_cycles!=0 || p->model_id==0 ||
      p->build_id==0 ||
      !((p->mode==RTNN_EXT_MODE_FIXED2 && p->fixed_exit==2u) ||
        (p->mode==RTNN_EXT_MODE_ADAPTIVE && p->fixed_exit==0u))) return -2;
  return 0;
}

void rtnn_ext_encode_response(const rtnn_ext_response_t *p,
                              uint8_t b[RTNN_EXT_RSP_LEN]) {
  b[0]='R'; b[1]='T'; b[2]='N'; b[3]='R'; b[4]=RTNN_EXT_RESPONSE_VERSION;
  b[5]=p->status; b[6]=p->mode; b[7]=p->stop_reason;
  wr32(b+8,p->seq); wr16(b+12,p->input_id); wr16(b+14,p->budget_q16);
  wr32(b+16,p->payload_crc32);
  b[20]=(uint8_t)p->admitted_exit; b[21]=(uint8_t)p->executed_exit;
  b[22]=(uint8_t)p->prediction; b[23]=(uint8_t)p->label;
  wr64(b+24,p->cycles_start); wr64(b+32,p->cycles_end);
  wr32(b+40,p->model_id); wr32(b+44,p->build_id);
  wr32(b+48,p->binding_id); wr32(b+52,p->flags);
  wr32(b+56,rtnn_ext_crc32(b,56));
}

int rtnn_ext_decode_response(const uint8_t *b, rtnn_ext_response_t *p) {
  if (!b || !p || !magic4(b,"RTNR") || b[4]!=RTNN_EXT_RESPONSE_VERSION ||
      rd32(b+56)!=rtnn_ext_crc32(b,56) || b[6]>RTNN_EXT_MODE_ADAPTIVE || b[7]>2u)
    return -1;
  p->status=b[5]; p->mode=b[6]; p->stop_reason=b[7]; p->seq=rd32(b+8);
  p->input_id=rd16(b+12); p->budget_q16=rd16(b+14); p->payload_crc32=rd32(b+16);
  p->admitted_exit=(int8_t)b[20]; p->executed_exit=(int8_t)b[21];
  p->prediction=(int8_t)b[22]; p->label=(int8_t)b[23];
  p->cycles_start=(uint64_t)rd32(b+24)|((uint64_t)rd32(b+28)<<32);
  p->cycles_end=(uint64_t)rd32(b+32)|((uint64_t)rd32(b+36)<<32);
  p->model_id=rd32(b+40); p->build_id=rd32(b+44);
  p->binding_id=rd32(b+48); p->flags=rd32(b+52);
  if (p->status==RTNN_EXT_STATUS_OK) {
    if (!((p->mode==RTNN_EXT_MODE_FIXED2 && p->admitted_exit==2 &&
           p->executed_exit==2 && p->stop_reason==RTNN_EXT_STOP_NONE) ||
          (p->mode==RTNN_EXT_MODE_ADAPTIVE && p->admitted_exit==6 &&
           p->executed_exit>=0 && p->executed_exit<=5 && p->stop_reason>=1 && p->stop_reason<=2)) ||
        p->prediction<0 || p->prediction>9 || p->label!=-1 ||
        p->budget_q16!=65535u || p->cycles_start==0 || p->cycles_end<=p->cycles_start ||
        p->flags!=RTNN_EXT_CYCLE_VALID) return -1;
  } else if (p->status==RTNN_EXT_STATUS_COUNTER_INVALID) {
    if (p->admitted_exit!=-1 || p->executed_exit!=-1 || p->prediction!=-1 ||
        p->label!=-1 ||
        !((p->flags==RTNN_EXT_CYCLE_REGRESSION && p->cycles_end<p->cycles_start) ||
          (p->flags==RTNN_EXT_CYCLE_ZERO && p->cycles_end==p->cycles_start))) return -1;
  } else {
    if (p->admitted_exit!=-1 || p->executed_exit!=-1 || p->prediction!=-1 ||
        p->label!=-1 || p->cycles_start!=0 || p->cycles_end!=0 || p->flags!=0 ||
        p->stop_reason!=RTNN_EXT_STOP_NONE) return -1;
  }
  return 0;
}
