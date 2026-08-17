#include <stdio.h>
#include <stdint.h>
#include "realtime_nn_execution_contract.h"

static uint32_t rng_state = 1u;
static uint32_t rnd(void) {
    rng_state = rng_state * 1664525u + 1013904223u;
    return rng_state;
}

static int8_t oracle(uint32_t deadline, const RTNNTargetTimingBinding* b) {
    if (!b || b->manifest_id != RTNN_EXECUTION_MANIFEST_ID) return -1;
    if (deadline < b->runtime_overhead_ticks) return -1;
    const uint32_t usable = deadline - b->runtime_overhead_ticks;
    int8_t best = -1;
    for (int i = 0; i < 5; ++i) {
        if (b->upper_ticks[i] != RTNN_BOUND_INVALID && b->upper_ticks[i] <= usable)
            best = (int8_t)i;
    }
    return best;
}

static int check_binding(const RTNNTargetTimingBinding* b) {
    for (int i = 0; i < 100000; ++i) {
        const uint32_t deadline = rnd() % 2000u;
        const int8_t got = rtnn_admit_execution_class(deadline, b);
        const int8_t want = oracle(deadline, b);
        if (got != want) return 10;
        if (got >= 0) {
            const uint32_t usable = deadline - b->runtime_overhead_ticks;
            if (b->upper_ticks[(int)got] > usable) return 11;
        }
    }
    return 0;
}

int main(void) {
    /* Synthetic bindings exercise the interface only; they are not measured timing claims. */
    const RTNNTargetTimingBinding fast = {
        RTNN_EXECUTION_MANIFEST_ID, 8u, {30u, 90u, 160u, 240u, 330u}
    };
    const RTNNTargetTimingBinding slow = {
        RTNN_EXECUTION_MANIFEST_ID, 12u, {40u, 150u, 290u, 450u, 650u}
    };
    const RTNNTargetTimingBinding partial = {
        RTNN_EXECUTION_MANIFEST_ID, 5u,
        {25u, 100u, RTNN_BOUND_INVALID, RTNN_BOUND_INVALID, RTNN_BOUND_INVALID}
    };
    const RTNNTargetTimingBinding wrong_manifest = {
        UINT64_C(0), 0u, {1u, 2u, 3u, 4u, 5u}
    };

    if (check_binding(&fast) || check_binding(&slow) || check_binding(&partial)) return 2;
    if (rtnn_admit_execution_class(1000000u, &partial) > 1) return 3;
    if (rtnn_admit_execution_class(100u, &wrong_manifest) != -1) return 4;
    if (rtnn_admit_execution_class(100u, 0) != -1) return 5;

    for (int i = 1; i < 5; ++i) {
        if (RTNN_STATIC_CLASSES[i].blocks <= RTNN_STATIC_CLASSES[i-1].blocks) return 6;
        if (RTNN_STATIC_CLASSES[i].linear_macs <= RTNN_STATIC_CLASSES[i-1].linear_macs) return 7;
    }

    puts("property_deadlines_per_binding=100000");
    puts("all_admission_properties_pass=1");
    puts("uncertified_classes_never_admitted=1");
    puts("wrong_manifest_rejected=1");
    for (unsigned i = 0; i < RTNN_EXECUTION_CLASS_COUNT; ++i) {
        printf("class=%u blocks=%u macs=%u luts=%u residual=%u outputs=%u\n",
               i,
               RTNN_STATIC_CLASSES[i].blocks,
               RTNN_STATIC_CLASSES[i].linear_macs,
               RTNN_STATIC_CLASSES[i].activation_lut_calls,
               RTNN_STATIC_CLASSES[i].residual_scale_ops,
               RTNN_STATIC_CLASSES[i].linear_outputs);
    }
    return 0;
}
