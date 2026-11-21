#ifndef RTNN_EXTERNAL_WIRE_H
#define RTNN_EXTERNAL_WIRE_H
#include <stdint.h>

#define RTNN_EXT_REQ_HEADER_LEN 32u
#define RTNN_EXT_PIXEL_LEN 64u
#define RTNN_EXT_REQ_LEN 100u
#define RTNN_EXT_RSP_LEN 60u
#define RTNN_EXT_REQUEST_VERSION 2u
#define RTNN_EXT_RESPONSE_VERSION 3u
#define RTNN_EXT_INPUT_COUNT 3823u

enum { RTNN_EXT_MODE_FIXED2 = 1u, RTNN_EXT_MODE_ADAPTIVE = 3u };
enum { RTNN_EXT_STATUS_OK=0u, RTNN_EXT_STATUS_BAD_FRAME=2u,
       RTNN_EXT_STATUS_WRONG_ID=3u, RTNN_EXT_STATUS_BAD_REQUEST=4u,
       RTNN_EXT_STATUS_INTERNAL=5u, RTNN_EXT_STATUS_COUNTER_INVALID=6u,
       RTNN_EXT_STATUS_BAD_PAYLOAD=7u };
enum { RTNN_EXT_CYCLE_VALID=1u, RTNN_EXT_CYCLE_REGRESSION=2u,
       RTNN_EXT_CYCLE_ZERO=4u };
enum { RTNN_EXT_STOP_NONE=0u, RTNN_EXT_STOP_ENTROPY=1u,
       RTNN_EXT_STOP_BUDGET=2u };

typedef struct {
  uint32_t seq;
  uint16_t input_id;
  uint8_t mode, fixed_exit;
  uint16_t budget_q16;
  uint32_t deadline_cycles, model_id, build_id;
} rtnn_ext_request_t;

typedef struct {
  uint32_t seq;
  uint16_t input_id;
  uint8_t mode, status, stop_reason;
  uint16_t budget_q16;
  uint32_t payload_crc32;
  int8_t admitted_exit, executed_exit, prediction, label;
  uint64_t cycles_start, cycles_end;
  uint32_t model_id, build_id, binding_id, flags;
} rtnn_ext_response_t;

uint32_t rtnn_ext_crc32(const uint8_t *bytes, uint32_t length);
void rtnn_ext_encode_request_header(const rtnn_ext_request_t *request,
                                    uint8_t out[RTNN_EXT_REQ_HEADER_LEN]);
int rtnn_ext_decode_request_header(const uint8_t in[RTNN_EXT_REQ_HEADER_LEN],
                                   rtnn_ext_request_t *request);
void rtnn_ext_encode_response(const rtnn_ext_response_t *response,
                              uint8_t out[RTNN_EXT_RSP_LEN]);
int rtnn_ext_decode_response(const uint8_t in[RTNN_EXT_RSP_LEN],
                             rtnn_ext_response_t *response);

#endif
