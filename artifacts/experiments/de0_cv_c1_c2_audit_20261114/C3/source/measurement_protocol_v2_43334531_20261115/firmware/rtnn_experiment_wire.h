#ifndef RTNN_EXPERIMENT_WIRE_H
#define RTNN_EXPERIMENT_WIRE_H
#include <stdint.h>
#define RTNN_REQ_LEN 32u
#define RTNN_RSP_LEN 60u
#define RTNN_REQUEST_VERSION 1u
#define RTNN_RESPONSE_VERSION 2u

enum {RTNN_MODE_STATUS=0, RTNN_MODE_FIXED=1, RTNN_MODE_CAPPED=2,
      RTNN_MODE_ADAPTIVE=3, RTNN_MODE_DEADLINE=4};
enum {RTNN_STATUS_OK=0,RTNN_STATUS_REJECTED=1,RTNN_STATUS_BAD_FRAME=2,
      RTNN_STATUS_WRONG_ID=3,RTNN_STATUS_BAD_REQUEST=4,RTNN_STATUS_INTERNAL=5,
      RTNN_STATUS_COUNTER_INVALID=6};
enum {RTNN_CYCLE_VALID=1u,RTNN_CYCLE_REGRESSION=2u,RTNN_CYCLE_ZERO=4u};

typedef struct {
  uint32_t seq;
  uint16_t input_id;
  uint8_t mode, fixed_exit;
  uint16_t budget_q16;
  uint32_t deadline_cycles, model_id, build_id;
} rtnn_exp_request_t;

typedef struct {
  uint32_t seq;
  uint16_t input_id;
  uint8_t mode, status, stop_reason;
  uint16_t budget_q16;
  uint32_t deadline_cycles;
  int8_t admitted_exit, executed_exit, prediction, label;
  uint64_t cycles_start,cycles_end;
  uint32_t model_id,build_id,binding_id,flags;
} rtnn_exp_response_t;

uint32_t rtnn_wire_crc(const uint8_t *bytes, uint32_t n);
void rtnn_wire_encode_request(const rtnn_exp_request_t *p,uint8_t out[RTNN_REQ_LEN]);
void rtnn_wire_encode_response(const rtnn_exp_response_t *p,uint8_t out[RTNN_RSP_LEN]);
int rtnn_wire_decode_request(const uint8_t in[RTNN_REQ_LEN],rtnn_exp_request_t *p);
int rtnn_wire_decode_response(const uint8_t in[RTNN_RSP_LEN],rtnn_exp_response_t *p);
#endif
