#ifndef RTNN_REAL_SEQUENCE_FIXED_CORE_H
#define RTNN_REAL_SEQUENCE_FIXED_CORE_H
#include <stdint.h>
#define RTNN_FX_CLASSES 7u
#define RTNN_FX_BLOCKS 6u
typedef struct {
 int32_t h[8][16];
 int32_t x[8][16];
 int32_t q[2][8][8], k[2][8][8], v[2][8][8];
 int32_t attcat[8][16];
 int32_t tmp[8][16];
 int32_t ff[8][32];
} RTNNFixedWorkspace;
uint8_t rtnn_fixed_budget_ceiling_q16(uint16_t budget_q16);
void rtnn_fixed_infer_exit(RTNNFixedWorkspace* w,const uint8_t pixels[64],uint8_t exit_class,int32_t logits[10]);
uint8_t rtnn_fixed_preferred_exit(RTNNFixedWorkspace* w,const uint8_t pixels[64]);
void rtnn_fixed_infer_budget(RTNNFixedWorkspace* w,const uint8_t pixels[64],uint16_t budget_q16,uint8_t deadline_class,int32_t logits[10],uint8_t* executed_exit);
/* Worst no-stop path used for static instruction/cycle-envelope analysis. */
void rtnn_fixed_certify_class(RTNNFixedWorkspace* w,const uint8_t pixels[64],uint8_t exit_class,int32_t logits[10]);
#endif
