#ifndef RTNN_CONTINUOUS_RUNTIME_CONTRACT_H
#define RTNN_CONTINUOUS_RUNTIME_CONTRACT_H
#include <stdint.h>

#define RTNN_EXECUTION_CLASS_COUNT 5u
#define RTNN_BUDGET_Q16_MAX UINT16_MAX
#define RTNN_BOUND_INVALID UINT32_MAX
/* First 64 bits of the canonical max-work manifest SHA-256. */
#define RTNN_CONTINUOUS_MANIFEST_ID UINT64_C(0xc17d5c3137b5e5ef)

typedef struct {
    uint8_t cls;
    uint8_t blocks;
    uint16_t normalized_q16;
    uint32_t max_linear_macs;
    uint32_t max_activation_lut_calls;
    uint32_t max_residual_scale_ops;
    uint32_t max_linear_outputs;
    uint32_t max_workspace_bytes;
} RTNNMaxWorkClass;

typedef struct {
    uint64_t manifest_id;
    uint64_t certified_build_id;
    uint32_t runtime_overhead_ticks;
    uint32_t upper_ticks[RTNN_EXECUTION_CLASS_COUNT];
} RTNNContinuousTimingBinding;

extern const RTNNMaxWorkClass RTNN_MAX_WORK_CLASSES[RTNN_EXECUTION_CLASS_COUNT];

/* External b in [0,1] is represented as unsigned Q0.16 over 0..65535. */
uint8_t rtnn_budget_to_max_class(uint16_t budget_q16);

/* Invalid preferred class fails closed to class 0. */
uint8_t rtnn_effective_class(uint16_t budget_q16, uint8_t preferred_max_class);

/* Highest explicitly certified class fitting deadline, or -1 on rejection. */
int8_t rtnn_admit_continuous_execution_class(uint32_t deadline_remaining_ticks,
                                              uint64_t deployed_build_id,
                                              const RTNNContinuousTimingBinding* binding);

/* min(deadline-certified class, budget ceiling, preferred useful class). */
int8_t rtnn_admit_effective_class(uint32_t deadline_remaining_ticks,
                                  uint64_t deployed_build_id,
                                  const RTNNContinuousTimingBinding* binding,
                                  uint16_t budget_q16,
                                  uint8_t preferred_max_class);

#endif
