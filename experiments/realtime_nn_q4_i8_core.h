#ifndef REALTIME_NN_Q4_I8_CORE_H
#define REALTIME_NN_Q4_I8_CORE_H

#include <stdint.h>

#define RTNN_L 9
#define RTNN_C 32
#define RTNN_F 128
#define RTNN_BLOCKS 8
#define RTNN_CLASS_COUNT 5
#define RTNN_Q4_I8_WORKSPACE_BYTES 3776

typedef struct {
    int8_t h[RTNN_L][RTNN_C];
    int8_t z[RTNN_L][RTNN_C];
    int8_t tmp[RTNN_L][RTNN_F];
    int32_t ff[RTNN_L][RTNN_C];
    int32_t a[RTNN_C];
    int32_t n[RTNN_C];
    int32_t pre[RTNN_F];
    int32_t out[RTNN_C];
} RTNNQ4I8Workspace;

typedef struct { int32_t logit0, logit1; } RTNNQ4I8Result;

typedef struct {
    uint8_t cls;
    uint8_t blocks;
    uint32_t linear_macs;
    uint32_t activation_lut_calls;
} RTNNQ4I8ExecutionClass;

int rtnn_q4_i8_init(void);
RTNNQ4I8Result rtnn_q4_i8_infer(RTNNQ4I8Workspace* workspace, uint16_t input_state, uint8_t execution_class);
const RTNNQ4I8ExecutionClass* rtnn_q4_i8_execution_classes(void);

#endif
