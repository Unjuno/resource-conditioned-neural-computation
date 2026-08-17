#ifndef RTNN_STRUCTURED_WIDTH_Q7_CORE_H
#define RTNN_STRUCTURED_WIDTH_Q7_CORE_H
#include <stdint.h>
#define RTNN_SW_L 9
#define RTNN_SW_C 32
#define RTNN_SW_F 128
#define RTNN_SW_BLOCKS 8
#define RTNN_SW_CLASS_COUNT 5
#define RTNN_SW_WORKSPACE_BYTES 4032
typedef struct { int16_t h[RTNN_SW_L][RTNN_SW_C], z[RTNN_SW_L][RTNN_SW_C], tmp[RTNN_SW_L][RTNN_SW_F], ff[RTNN_SW_L][RTNN_SW_C]; } RTNNSWWorkspace;
typedef struct { int16_t logit0, logit1; } RTNNSWResult;
typedef struct { uint8_t cls, depth, width; uint32_t linear_macs; } RTNNSWClass;
int rtnn_sw_q7_init(void);
RTNNSWResult rtnn_sw_q7_infer(RTNNSWWorkspace*, uint16_t, uint8_t);
const RTNNSWClass* rtnn_sw_q7_classes(void);
#endif
