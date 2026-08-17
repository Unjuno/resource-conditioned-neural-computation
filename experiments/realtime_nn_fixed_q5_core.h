#ifndef REALTIME_NN_FIXED_Q5_CORE_H
#define REALTIME_NN_FIXED_Q5_CORE_H
#include <stdint.h>
#define RTNN_L 9
#define RTNN_C 32
#define RTNN_F 128
#define RTNN_BLOCKS 8
#define RTNN_CLASSES 5
#define RTNN_Q5_WORKSPACE_BYTES 4032
typedef struct { int16_t h[RTNN_L][RTNN_C], z[RTNN_L][RTNN_C], tmp[RTNN_L][RTNN_F], ff[RTNN_L][RTNN_C]; } RTNNQ5Workspace;
typedef struct { int16_t logit0, logit1; } RTNNQ5Result;
int rtnn_q5_init(void);
RTNNQ5Result rtnn_q5_infer(RTNNQ5Workspace*, uint16_t, uint8_t);
#endif
