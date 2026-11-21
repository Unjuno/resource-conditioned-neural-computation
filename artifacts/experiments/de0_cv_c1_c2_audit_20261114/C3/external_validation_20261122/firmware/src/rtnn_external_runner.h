#ifndef RTNN_EXTERNAL_RUNNER_H
#define RTNN_EXTERNAL_RUNNER_H
#include "rtnn_external_wire.h"
#include <stdint.h>
typedef uint64_t (*rtnn_ext_clock_read_t)(void *ctx);
typedef struct {
  uint32_t model_id, build_id, binding_id;
  rtnn_ext_clock_read_t cycle_now;
  void *cycle_ctx;
} rtnn_ext_config_t;
int rtnn_ext_execute(const rtnn_ext_request_t *req, const uint8_t pixels[64],
                     uint32_t payload_crc32, rtnn_ext_response_t *out,
                     const rtnn_ext_config_t *cfg);
#endif
