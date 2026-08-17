#include <stdio.h>
#include "realtime_nn_core.h"

static RTNNWorkspace W;

static int label_for(unsigned state) {
    int ones = 0;
    for (int i = 0; i < RTNN_L; ++i) ones += (state >> i) & 1u;
    return ones >= 5;
}

int main(void) {
    if (!rtnn_init()) return 2;
    const RTNNExecutionClass* classes = rtnn_execution_classes();
    for (int c = 0; c < RTNN_CLASS_COUNT; ++c) {
        int ok = 0;
        for (int s = 0; s < 512; ++s) {
            RTNNResult r = rtnn_infer(&W, (uint16_t)s, (uint8_t)c);
            const int pred = r.logit1 > r.logit0;
            ok += pred == label_for((unsigned)s);
        }
        printf("class=%d blocks=%u macs=%u lut=%u acc=%.9f\n",
               c, classes[c].blocks, classes[c].linear_macs,
               classes[c].activation_lut_calls, ok / 512.0);
    }

    /* Invalid runtime class must fail closed to class 0, not expand work. */
    for (int s = 0; s < 512; ++s) {
        RTNNResult a = rtnn_infer(&W, (uint16_t)s, 0);
        RTNNResult b = rtnn_infer(&W, (uint16_t)s, 255);
        if (a.logit0 != b.logit0 || a.logit1 != b.logit1) return 3;
    }
    puts("invalid_class_fail_closed=1");
    return 0;
}
