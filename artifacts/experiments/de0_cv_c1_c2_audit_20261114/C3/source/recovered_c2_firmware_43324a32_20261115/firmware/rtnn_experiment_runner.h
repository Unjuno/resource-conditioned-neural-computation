#ifndef RTNN_EXPERIMENT_RUNNER_H
#define RTNN_EXPERIMENT_RUNNER_H
#include "rtnn_experiment_wire.h"
#include <stdint.h>
typedef uint64_t (*rtnn_clock_read_t)(void* ctx);
typedef struct {
  uint32_t model_id;
  uint32_t build_id;
  uint32_t binding_id;
  uint8_t has_fpga_cycle_binding;
  uint32_t upper_total_cycles[7];
  rtnn_clock_read_t cycle_now;
  void* cycle_ctx;
} rtnn_fw_config_t;
// Returns 0 with one complete result; never executes NN on a rejected request.
int rtnn_fw_execute(const rtnn_exp_request_t*req, rtnn_exp_response_t*out,
                    const rtnn_fw_config_t*cfg);
#endif
