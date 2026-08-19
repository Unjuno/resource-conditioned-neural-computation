#ifndef REALTIME_NN_REAL_SEQUENCE_CORE_H
#define REALTIME_NN_REAL_SEQUENCE_CORE_H
#include <stdint.h>
#define RTNN_REAL_SEQUENCE_T 8
#define RTNN_REAL_SEQUENCE_H 16
#define RTNN_REAL_SEQUENCE_FF 32
#define RTNN_REAL_SEQUENCE_CLASSES 10
#define RTNN_REAL_SEQUENCE_BLOCKS 6
#define RTNN_REAL_SEQUENCE_EXIT_COUNT 7
#define RTNN_REAL_SEQUENCE_BUDGET_MAX 65535u
#include "realtime_nn_real_sequence_policy_generated.h"

typedef struct {
    float h[RTNN_REAL_SEQUENCE_T][RTNN_REAL_SEQUENCE_H];
    float x[RTNN_REAL_SEQUENCE_T][RTNN_REAL_SEQUENCE_H];
    float q[2][RTNN_REAL_SEQUENCE_T][8];
    float k[2][RTNN_REAL_SEQUENCE_T][8];
    float v[2][RTNN_REAL_SEQUENCE_T][8];
    float attcat[RTNN_REAL_SEQUENCE_T][RTNN_REAL_SEQUENCE_H];
    float ff[RTNN_REAL_SEQUENCE_T][RTNN_REAL_SEQUENCE_FF];
    float tmp[RTNN_REAL_SEQUENCE_T][RTNN_REAL_SEQUENCE_H];
} RTNNRealSequenceWorkspace;

uint8_t rtnn_real_sequence_budget_ceiling_q16(uint16_t b);
uint8_t rtnn_real_sequence_effective_exit_q16(uint16_t b, uint8_t preferred_exit, uint8_t deadline_exit);
void rtnn_real_sequence_infer_exit(RTNNRealSequenceWorkspace* w, const uint8_t pixels[64], uint8_t exit, float logits[10]);
uint8_t rtnn_real_sequence_preferred_exit(RTNNRealSequenceWorkspace* w, const uint8_t pixels[64]);
void rtnn_real_sequence_infer_budget(RTNNRealSequenceWorkspace* w, const uint8_t pixels[64], uint16_t budget_q16, uint8_t deadline_exit, float logits[10], uint8_t* executed_exit);
#endif
