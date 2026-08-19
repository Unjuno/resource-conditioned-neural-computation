#ifndef RTNN_REAL_SEQUENCE_RUNTIME_CONTRACT_H
#define RTNN_REAL_SEQUENCE_RUNTIME_CONTRACT_H
#include <stdint.h>
#include "realtime_nn_real_sequence_core.h"
#include "realtime_nn_real_sequence_identity_generated.h"
#define RTNN_REAL_SEQUENCE_BOUND_INVALID UINT32_MAX
typedef struct {
 uint64_t manifest_id;
 uint64_t certified_build_id;
 uint32_t runtime_overhead_ticks;
 uint32_t upper_ticks[RTNN_REAL_SEQUENCE_EXIT_COUNT];
} RTNNRealSequenceTimingBinding;
int8_t rtnn_real_sequence_admit_deadline(uint32_t deadline_ticks,uint64_t deployed_build_id,const RTNNRealSequenceTimingBinding* binding);
int8_t rtnn_real_sequence_infer_deadline_budget(RTNNRealSequenceWorkspace* w,const uint8_t pixels[64],uint16_t budget_q16,uint32_t deadline_ticks,uint64_t deployed_build_id,const RTNNRealSequenceTimingBinding* binding,float logits[10],uint8_t* executed_exit);
#endif
