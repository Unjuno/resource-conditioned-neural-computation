#define _GNU_SOURCE
#include "realtime_nn_core.h"
#include "realtime_nn_continuous_runtime_contract.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <x86intrin.h>

#define NCAL 800
#define NTEST 3000
/* First 64 bits of the exact regenerated realtime_nn_core.o SHA-256 used in the audit. */
#define BUILD_ID UINT64_C(0x9f2dfee5ad9ffe4c)

static uint64_t measure(RTNNWorkspace* w, uint16_t x, uint8_t c) {
    unsigned aux;
    _mm_lfence();
    const uint64_t a = __rdtscp(&aux);
    RTNNResult r = rtnn_infer(w, x, c);
    const uint64_t b = __rdtscp(&aux);
    _mm_lfence();
    static volatile float sink;
    sink += r.logit0;
    return b - a;
}

int main(void) {
    cpu_set_t set;
    CPU_ZERO(&set);
    const int cp = sched_getcpu();
    if (cp >= 0) { CPU_SET(cp, &set); (void)sched_setaffinity(0, sizeof(set), &set); }
    if (!rtnn_init()) return 2;

    RTNNWorkspace w;
    uint64_t rawmax[5] = {0}, base[5] = {0};
    for (int c = 0; c < 5; ++c) {
        for (int i = 0; i < 80; ++i) (void)measure(&w, (uint16_t)((i * 73 + 11) & 511), (uint8_t)c);
        for (int i = 0; i < NCAL; ++i) {
            const uint64_t z = measure(&w, (uint16_t)((i * 149 + 37) & 511), (uint8_t)c);
            if (z > rawmax[c]) rawmax[c] = z;
        }
    }
    uint64_t prev = 0;
    for (int c = 0; c < 5; ++c) {
        uint64_t v = rawmax[c];
        if (v < prev) v = prev;
        base[c] = v;
        prev = v;
    }

    printf("cpu=%d ncal=%d ntest=%d\n", sched_getcpu(), NCAL, NTEST);
    for (int c = 0; c < 5; ++c)
        printf("cal class=%d raw_max=%llu monotone_max=%llu\n", c,
               (unsigned long long)rawmax[c], (unsigned long long)base[c]);

    for (int factor = 1; factor <= 4; factor *= 2) {
        uint64_t bound64[5];
        RTNNContinuousTimingBinding bind = {RTNN_CONTINUOUS_MANIFEST_ID, BUILD_ID, 0, {0}};
        for (int c = 0; c < 5; ++c) {
            bound64[c] = base[c] * (uint64_t)factor;
            bind.upper_ticks[c] = bound64[c] > UINT32_MAX ? UINT32_MAX : (uint32_t)bound64[c];
        }
        uint64_t exceed[5] = {0};
        for (int c = 0; c < 5; ++c)
            for (int i = 0; i < NTEST; ++i) {
                const uint64_t z = measure(&w, (uint16_t)((i * 251 + 17 + c * 31) & 511), (uint8_t)c);
                exceed[c] += z > bound64[c];
            }

        uint64_t demo_miss = 0, demo_cases = 0;
        for (int target = 0; target < 5; ++target) {
            const uint32_t D = bind.upper_ticks[target];
            for (int i = 0; i < 800; ++i) {
                const uint16_t budget = (uint16_t)((i * 9973u) & 65535u);
                const uint8_t pref = (uint8_t)((i * 7 + target) % 5);
                const int8_t e = rtnn_admit_effective_class(D, BUILD_ID, &bind, budget, pref);
                if (e < 0) continue;
                const uint64_t z = measure(&w, (uint16_t)((i * 181 + target * 43) & 511), (uint8_t)e);
                demo_miss += z > D;
                ++demo_cases;
            }
        }
        printf("factor=%d", factor);
        for (int c = 0; c < 5; ++c)
            printf(" class%d_exceed=%llu/%d", c, (unsigned long long)exceed[c], NTEST);
        printf(" admission_demo_miss=%llu/%llu\n", (unsigned long long)demo_miss,
               (unsigned long long)demo_cases);
    }

    RTNNContinuousTimingBinding partial = {
        RTNN_CONTINUOUS_MANIFEST_ID, BUILD_ID, 0,
        {1000u, 2000u, RTNN_BOUND_INVALID, RTNN_BOUND_INVALID, RTNN_BOUND_INVALID}
    };
    printf("wrong_build_rejected=%d partial_large_deadline_class=%d\n",
           rtnn_admit_continuous_execution_class(100000u, BUILD_ID + 1u, &partial) == -1,
           (int)rtnn_admit_continuous_execution_class(100000u, BUILD_ID, &partial));
    return 0;
}
