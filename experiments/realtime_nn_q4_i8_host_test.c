#include <stdio.h>
#include "realtime_nn_q4_i8_core.h"

static RTNNQ4I8Workspace W;

static int label_for(unsigned state) {
    int ones = 0;
    for (int i = 0; i < RTNN_L; ++i) ones += (state >> i) & 1u;
    return ones >= 5;
}

int main(void) {
    if (!rtnn_q4_i8_init()) return 2;
    const RTNNQ4I8ExecutionClass* classes = rtnn_q4_i8_execution_classes();
    for (int c = 0; c < RTNN_CLASS_COUNT; ++c) {
        int correct = 0;
        for (int state = 0; state < 512; ++state) {
            RTNNQ4I8Result r = rtnn_q4_i8_infer(&W, (uint16_t)state, (uint8_t)c);
            correct += ((r.logit1 > r.logit0) == label_for((unsigned)state));
        }
        printf(
            "class=%d blocks=%u macs=%u lut=%u acc=%.9f\n",
            c,
            classes[c].blocks,
            classes[c].linear_macs,
            classes[c].activation_lut_calls,
            correct / 512.0
        );
    }
    for (int state = 0; state < 512; ++state) {
        RTNNQ4I8Result a = rtnn_q4_i8_infer(&W, (uint16_t)state, 0);
        RTNNQ4I8Result b = rtnn_q4_i8_infer(&W, (uint16_t)state, 255);
        if (a.logit0 != b.logit0 || a.logit1 != b.logit1) return 3;
    }
    puts("invalid_class_fail_closed=1");
    return 0;
}
