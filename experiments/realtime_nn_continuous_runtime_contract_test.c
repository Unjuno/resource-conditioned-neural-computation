#include "realtime_nn_continuous_runtime_contract.h"
#include <stdint.h>
#include <stdio.h>

static int fail = 0;
#define CHECK(x) do { if (!(x)) ++fail; } while (0)

int main(void) {
    uint8_t prev = 0u;
    uint32_t lowering_cases = 0u;
    for (uint32_t q = 0; q <= 65535u; ++q) {
        const uint8_t c = rtnn_budget_to_max_class((uint16_t)q);
        CHECK(c < RTNN_EXECUTION_CLASS_COUNT);
        CHECK(RTNN_MAX_WORK_CLASSES[c].normalized_q16 <= q);
        CHECK(c >= prev);
        if (c + 1u < RTNN_EXECUTION_CLASS_COUNT)
            CHECK(RTNN_MAX_WORK_CLASSES[c + 1u].normalized_q16 > q);
        prev = c;
        ++lowering_cases;
    }

    uint64_t effective_cases = 0u;
    for (uint32_t q = 0; q <= 65535u; ++q) {
        const uint8_t bc = rtnn_budget_to_max_class((uint16_t)q);
        for (uint32_t p = 0; p < 256u; ++p) {
            const uint8_t e = rtnn_effective_class((uint16_t)q, (uint8_t)p);
            CHECK(e <= bc);
            if (p < RTNN_EXECUTION_CLASS_COUNT) CHECK(e <= p);
            else CHECK(e == 0u);
            ++effective_cases;
        }
    }

    const uint64_t build = UINT64_C(0x1020304050607080);
    RTNNContinuousTimingBinding bind = {
        RTNN_CONTINUOUS_MANIFEST_ID, build, 7u,
        {10u, 20u, 40u, 80u, 160u}
    };
    uint64_t admission_cases = 0u;
    for (uint32_t deadline = 0; deadline < 512u; ++deadline) {
        const int8_t dc = rtnn_admit_continuous_execution_class(deadline, build, &bind);
        for (uint32_t q = 0; q <= 65535u; q += 257u) {
            for (uint32_t p = 0; p < RTNN_EXECUTION_CLASS_COUNT; ++p) {
                const int8_t e = rtnn_admit_effective_class(deadline, build, &bind, (uint16_t)q, (uint8_t)p);
                if (dc < 0) CHECK(e == -1);
                else {
                    CHECK(e >= 0 && e <= dc);
                    CHECK((uint8_t)e <= rtnn_budget_to_max_class((uint16_t)q));
                    CHECK((uint8_t)e <= p);
                }
                ++admission_cases;
            }
        }
    }

    CHECK(rtnn_admit_continuous_execution_class(1000u, build + 1u, &bind) == -1);
    bind.manifest_id ^= 1u;
    CHECK(rtnn_admit_continuous_execution_class(1000u, build, &bind) == -1);
    bind.manifest_id = RTNN_CONTINUOUS_MANIFEST_ID;
    CHECK(rtnn_admit_effective_class(1000u, build, &bind, 65535u, 255u) == 0);

    printf("lowering_cases=%u\n", lowering_cases);
    printf("effective_cases=%llu\n", (unsigned long long)effective_cases);
    printf("admission_cases=%llu\n", (unsigned long long)admission_cases);
    printf("all_properties_pass=%d\n", fail == 0);
    return fail ? 1 : 0;
}
