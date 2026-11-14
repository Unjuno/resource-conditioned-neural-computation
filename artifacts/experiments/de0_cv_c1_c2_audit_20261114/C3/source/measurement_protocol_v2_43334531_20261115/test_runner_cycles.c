#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "firmware/rtnn_experiment_runner.h"
#include "model/realtime_nn_real_sequence_fixed_core.h"
#include "generated/heldout360.h"

typedef struct { uint64_t values[2]; unsigned index; } clock_script_t;
static uint64_t scripted_clock(void *ctx) {
  clock_script_t *s = (clock_script_t *)ctx;
  return s->values[s->index++];
}

static int run_case(uint64_t start, uint64_t end, uint32_t expected_status,
                    uint32_t expected_flags, uint64_t expected_delta) {
  clock_script_t clock = {{start, end}, 0};
  rtnn_fw_config_t cfg;
  memset(&cfg, 0, sizeof(cfg));
  cfg.model_id = UINT32_C(0x52544e4e);
  cfg.build_id = UINT32_C(0x43334531);
  cfg.binding_id = UINT32_C(0x43334531);
  cfg.cycle_now = scripted_clock;
  cfg.cycle_ctx = &clock;
  rtnn_exp_request_t req;
  memset(&req, 0, sizeof(req));
  req.seq = 1; req.input_id = 0; req.mode = RTNN_MODE_FIXED;
  req.fixed_exit = 0; req.budget_q16 = UINT16_MAX;
  req.model_id = cfg.model_id; req.build_id = cfg.build_id;
  rtnn_exp_response_t rsp;
  memset(&rsp, 0, sizeof(rsp));
  if (rtnn_fw_execute(&req, &rsp, &cfg) != 0) return 1;
  if (clock.index != 2 || rsp.status != expected_status || rsp.flags != expected_flags ||
      rsp.cycles_start != start || rsp.cycles_end != end) return 2;
  if (expected_flags == RTNN_CYCLE_VALID && end - start != expected_delta) return 3;
  if (expected_flags != RTNN_CYCLE_VALID && rsp.prediction != 3) return 4;
  return 0;
}

int main(void) {
  int rc;
  rc = run_case(100, 200, RTNN_STATUS_OK, RTNN_CYCLE_VALID, 100);
  if (rc) { fprintf(stderr, "counter_normal_failed=%d\n", rc); return 1; }
  rc = run_case(UINT64_MAX - 3, 2, RTNN_STATUS_COUNTER_INVALID,
                RTNN_CYCLE_REGRESSION, 0);
  if (rc) { fprintf(stderr, "counter_regression_failed=%d\n", rc); return 2; }
  rc = run_case(77, 77, RTNN_STATUS_COUNTER_INVALID, RTNN_CYCLE_ZERO, 0);
  if (rc) { fprintf(stderr, "counter_zero_failed=%d\n", rc); return 3; }
  rc = run_case(UINT64_C(0xfffffff0), UINT64_C(0x100000010),
                RTNN_STATUS_OK, RTNN_CYCLE_VALID, 32);
  if (rc) { fprintf(stderr, "low32_wrap_without_u64_wrap_failed=%d\n", rc); return 4; }
  puts("C3_RUNNER_COUNTER_PASS normal=1 regression_flagged=1 zero_flagged=1 low32_wrap_valid=1");
  return 0;
}
