#ifndef REALTIME_NN_CORE_H
#define REALTIME_NN_CORE_H

#include <stdint.h>

#define RTNN_L 9
#define RTNN_C 32
#define RTNN_F 128
#define RTNN_BLOCKS 8
#define RTNN_CLASS_COUNT 5
#define RTNN_WORKSPACE_BYTES 8064

typedef struct {
    float h[RTNN_L][RTNN_C];
    float z[RTNN_L][RTNN_C];
    float tmp[RTNN_L][RTNN_F];
    float ff[RTNN_L][RTNN_C];
} RTNNWorkspace;

typedef struct {
    float logit0;
    float logit1;
} RTNNResult;

typedef struct {
    uint8_t cls;
    uint8_t blocks;
    uint32_t linear_macs;
    uint32_t activation_lut_calls;
} RTNNExecutionClass;

/* Initialize internal pointers into the generated static weight table. */
int rtnn_init(void);

/*
 * Execute one finite work class. Valid classes are 0..RTNN_CLASS_COUNT-1.
 * Invalid class values fail closed to class 0 so malformed runtime input
 * cannot silently increase neural work beyond the minimum class.
 */
RTNNResult rtnn_infer(RTNNWorkspace* workspace, uint16_t input_state, uint8_t execution_class);

const RTNNExecutionClass* rtnn_execution_classes(void);

#endif
