#define _POSIX_C_SOURCE 200809L
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "realtime_nn_q4_i8_core.h"

static RTNNQ4I8Workspace W;
static volatile int32_t sink;

static int compare_double(const void* a, const void* b) {
    double x = *(const double*)a;
    double y = *(const double*)b;
    return (x > y) - (x < y);
}

static double elapsed_us(struct timespec a, struct timespec b) {
    return (b.tv_sec - a.tv_sec) * 1e6 + (b.tv_nsec - a.tv_nsec) / 1e3;
}

int main(int argc, char** argv) {
    int reps = argc > 1 ? atoi(argv[1]) : 1500;
    if (!rtnn_q4_i8_init()) return 2;
    uint32_t rng = 1;
    for (int c = 0; c < RTNN_CLASS_COUNT; ++c) {
        for (int i = 0; i < 500; ++i) {
            rng = rng * 1664525u + 1013904223u;
            sink += rtnn_q4_i8_infer(&W, (uint16_t)(rng & 511), (uint8_t)c).logit0;
        }
        double* values = malloc((size_t)reps * sizeof(double));
        if (!values) return 3;
        for (int i = 0; i < reps; ++i) {
            rng = rng * 1664525u + 1013904223u;
            struct timespec a, b;
            clock_gettime(CLOCK_MONOTONIC, &a);
            RTNNQ4I8Result z = rtnn_q4_i8_infer(&W, (uint16_t)(rng & 511), (uint8_t)c);
            clock_gettime(CLOCK_MONOTONIC, &b);
            sink += z.logit0;
            values[i] = elapsed_us(a, b);
        }
        qsort(values, (size_t)reps, sizeof(double), compare_double);
        printf("class=%d p50_us=%.3f p95_us=%.3f p99_us=%.3f\n",
               c, values[reps / 2], values[(int)(reps * 0.95)], values[(int)(reps * 0.99)]);
        free(values);
    }
    return sink == 123456789;
}
