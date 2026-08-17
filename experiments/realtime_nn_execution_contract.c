#include "realtime_nn_execution_contract.h"

const RTNNStaticExecutionClass RTNN_STATIC_CLASSES[RTNN_EXECUTION_CLASS_COUNT] = {
    {0, 0, 64u, 0u, 0u, 2u},
    {1, 2, 182336u, 3456u, 576u, 3970u},
    {2, 4, 364608u, 6912u, 1152u, 7938u},
    {3, 6, 546880u, 10368u, 1728u, 11906u},
    {4, 8, 729152u, 13824u, 2304u, 15874u}
};

int8_t rtnn_admit_execution_class(uint32_t deadline,
                                  const RTNNTargetTimingBinding* binding) {
    if (!binding || binding->manifest_id != RTNN_EXECUTION_MANIFEST_ID) return -1;
    if (deadline < binding->runtime_overhead_ticks) return -1;

    const uint32_t usable = deadline - binding->runtime_overhead_ticks;
    int8_t best = -1;
    for (uint8_t c = 0; c < RTNN_EXECUTION_CLASS_COUNT; ++c) {
        const uint32_t bound = binding->upper_ticks[c];
        if (bound != RTNN_BOUND_INVALID && bound <= usable) best = (int8_t)c;
    }
    return best;
}
