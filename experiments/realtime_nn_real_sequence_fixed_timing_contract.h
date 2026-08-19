#ifndef RTNN_REAL_SEQUENCE_FIXED_TIMING_CONTRACT_H
#define RTNN_REAL_SEQUENCE_FIXED_TIMING_CONTRACT_H
#include <stdint.h>
#define RTNN_FIXED_TIMING_CLASSES 7u
#define RTNN_FIXED_BOUND_INVALID UINT32_MAX
typedef struct {
 uint32_t model_id;
 uint32_t build_id;
 uint32_t total_upper_cycles[RTNN_FIXED_TIMING_CLASSES];
} RTNNFixedConditionalTimingBinding;
int8_t rtnn_fixed_admit_total_cycles(uint32_t deadline_cycles,uint32_t deployed_model_id,uint32_t deployed_build_id,const RTNNFixedConditionalTimingBinding* binding);
#endif
