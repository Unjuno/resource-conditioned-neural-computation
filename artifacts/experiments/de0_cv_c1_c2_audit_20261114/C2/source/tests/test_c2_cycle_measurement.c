#include "rtnn_experiment_runner.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#define C2_MODEL_ID UINT32_C(0x52544e4e)
#define C2_BUILD_ID UINT32_C(0x43324a31)

typedef struct {
  uint64_t samples[2];
  unsigned reads;
} clock_script_t;

static uint64_t scripted_clock(void *opaque) {
  clock_script_t *clock = (clock_script_t *)opaque;
  if (clock->reads >= 2u) {
    fprintf(stderr, "runner read cycle callback more than twice\n");
    exit(2);
  }
  return clock->samples[clock->reads++];
}

static void run_valid_delta(const char *name, uint64_t before, uint64_t after,
                            uint32_t expected) {
  clock_script_t clock = {{before, after}, 0u};
  const rtnn_fw_config_t cfg = {
    .model_id = C2_MODEL_ID,
    .build_id = C2_BUILD_ID,
    .binding_id = 0u,
    .has_fpga_cycle_binding = 0u,
    .cycle_now = scripted_clock,
    .cycle_ctx = &clock
  };
  const rtnn_exp_request_t req = {
    .seq = 1u,
    .input_id = 0u,
    .mode = RTNN_MODE_FIXED,
    .fixed_exit = 2u,
    .budget_q16 = UINT16_MAX,
    .deadline_cycles = 0u,
    .model_id = C2_MODEL_ID,
    .build_id = C2_BUILD_ID
  };
  rtnn_exp_response_t rsp;
  int rc = rtnn_fw_execute(&req, &rsp, &cfg);
  if (rc != 0) {
    fprintf(stderr, "%s failed: runner rc=%d\n", name, rc);
    exit(1);
  }
  if (rsp.status != RTNN_STATUS_OK || rsp.cycles != expected ||
      clock.reads != 2u) {
    fprintf(stderr,
      "%s failed: status=%u cycles=%" PRIu32 " reads=%u expected=%" PRIu32 "\n",
      name, rsp.status, rsp.cycles, clock.reads, expected);
    exit(1);
  }
  printf("C2_CYCLE_PASS %s cycles=%" PRIu32 " reads=%u\n",
         name, rsp.cycles, clock.reads);
}

static void run_invalid_delta(const char *name, uint64_t before, uint64_t after) {
  clock_script_t clock = {{before, after}, 0u};
  const rtnn_fw_config_t cfg = {
    .model_id = C2_MODEL_ID,
    .build_id = C2_BUILD_ID,
    .binding_id = 0u,
    .has_fpga_cycle_binding = 0u,
    .cycle_now = scripted_clock,
    .cycle_ctx = &clock
  };
  const rtnn_exp_request_t req = {
    .seq = 1u,
    .input_id = 0u,
    .mode = RTNN_MODE_FIXED,
    .fixed_exit = 2u,
    .budget_q16 = UINT16_MAX,
    .deadline_cycles = 0u,
    .model_id = C2_MODEL_ID,
    .build_id = C2_BUILD_ID
  };
  rtnn_exp_response_t rsp;
  int rc = rtnn_fw_execute(&req, &rsp, &cfg);
  if (rc != 0) {
    fprintf(stderr, "%s failed: runner rc=%d\n", name, rc);
    exit(1);
  }
  if (rsp.status != RTNN_STATUS_INTERNAL || rsp.cycles != 0u ||
      clock.reads != 2u) {
    fprintf(stderr,
      "%s failed: status=%u cycles=%" PRIu32 " reads=%u\n",
      name, rsp.status, rsp.cycles, clock.reads);
    exit(1);
  }
  printf("C2_CYCLE_PASS %s status=INTERNAL cycles=0 reads=%u\n",
         name, clock.reads);
}

int main(void) {
  run_valid_delta("u64_wrap_100", UINT64_MAX - UINT64_C(49), UINT64_C(50), 100u);
  run_valid_delta("low32_wrap_64", UINT64_C(0x00000000fffffff0),
                  UINT64_C(0x0000000100000030), 64u);
  run_invalid_delta("zero_delta", UINT64_C(1000), UINT64_C(1000));
  run_invalid_delta("delta_over_u32", UINT64_C(0), UINT64_C(0x100000000));
  puts("C2_CYCLE_MEASUREMENT_TEST_PASS frozen_q15=linked physical_clock=NONE");
  return 0;
}
