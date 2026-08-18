#include "realtime_nn_continuous_runtime_contract.h"

const RTNNMaxWorkClass RTNN_MAX_WORK_CLASSES[RTNN_EXECUTION_CLASS_COUNT] = {
    {0, 0,     0u, 64u,     0u,     0u,     2u, 8064u},
    {1, 2, 16383u, 182336u, 3456u,  576u, 3970u, 8064u},
    {2, 4, 32767u, 364608u, 6912u, 1152u, 7938u, 8064u},
    {3, 6, 49151u, 546880u,10368u, 1728u,11906u, 8064u},
    {4, 8, 65535u, 729152u,13824u, 2304u,15874u, 8064u}
};

uint8_t rtnn_budget_to_max_class(uint16_t budget_q16) {
    uint8_t best = 0u;
    for (uint8_t c = 1u; c < RTNN_EXECUTION_CLASS_COUNT; ++c) {
        if (RTNN_MAX_WORK_CLASSES[c].normalized_q16 <= budget_q16) best = c;
    }
    return best;
}

uint8_t rtnn_effective_class(uint16_t budget_q16, uint8_t preferred_max_class) {
    const uint8_t budget_class = rtnn_budget_to_max_class(budget_q16);
    if (preferred_max_class >= RTNN_EXECUTION_CLASS_COUNT) return 0u;
    return preferred_max_class < budget_class ? preferred_max_class : budget_class;
}

int8_t rtnn_admit_continuous_execution_class(uint32_t deadline,
                                              uint64_t deployed_build_id,
                                              const RTNNContinuousTimingBinding* binding) {
    if (!binding || binding->manifest_id != RTNN_CONTINUOUS_MANIFEST_ID) return -1;
    if (binding->certified_build_id != deployed_build_id) return -1;
    if (deadline < binding->runtime_overhead_ticks) return -1;
    const uint32_t usable = deadline - binding->runtime_overhead_ticks;
    int8_t best = -1;
    for (uint8_t c = 0u; c < RTNN_EXECUTION_CLASS_COUNT; ++c) {
        const uint32_t bound = binding->upper_ticks[c];
        if (bound != RTNN_BOUND_INVALID && bound <= usable) best = (int8_t)c;
    }
    return best;
}

int8_t rtnn_admit_effective_class(uint32_t deadline,
                                  uint64_t deployed_build_id,
                                  const RTNNContinuousTimingBinding* binding,
                                  uint16_t budget_q16,
                                  uint8_t preferred_max_class) {
    const int8_t deadline_class = rtnn_admit_continuous_execution_class(deadline, deployed_build_id, binding);
    if (deadline_class < 0) return -1;
    const uint8_t policy_class = rtnn_effective_class(budget_q16, preferred_max_class);
    return (int8_t)(policy_class < (uint8_t)deadline_class ? policy_class : (uint8_t)deadline_class);
}
