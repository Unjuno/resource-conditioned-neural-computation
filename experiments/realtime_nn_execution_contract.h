#ifndef RTNN_EXECUTION_CONTRACT_H
#define RTNN_EXECUTION_CONTRACT_H
#include <stdint.h>

#define RTNN_EXECUTION_CLASS_COUNT 5u
/* First 64 bits of the committed manifest SHA-256 c497a83885b3c291... */
#define RTNN_EXECUTION_MANIFEST_ID UINT64_C(0xc497a83885b3c291)
#define RTNN_BOUND_INVALID UINT32_MAX

typedef struct {
    uint8_t cls;
    uint8_t blocks;
    uint32_t linear_macs;
    uint32_t activation_lut_calls;
    uint32_t residual_scale_ops;
    uint32_t linear_outputs;
} RTNNStaticExecutionClass;

typedef struct {
    uint64_t manifest_id;
    uint32_t runtime_overhead_ticks;
    /* RTNN_BOUND_INVALID means this class has no defensible target bound. */
    uint32_t upper_ticks[RTNN_EXECUTION_CLASS_COUNT];
} RTNNTargetTimingBinding;

extern const RTNNStaticExecutionClass RTNN_STATIC_CLASSES[RTNN_EXECUTION_CLASS_COUNT];

/* Returns -1 when no certified class fits, binding identity is wrong, or binding is NULL. */
int8_t rtnn_admit_execution_class(uint32_t deadline_remaining_ticks,
                                  const RTNNTargetTimingBinding* binding);

#endif
