#include "realtime_nn_real_sequence_runtime_contract.h"
int8_t rtnn_real_sequence_admit_deadline(uint32_t deadline_ticks,uint64_t deployed_build_id,const RTNNRealSequenceTimingBinding* b){
 if(!b || b->manifest_id!=RTNN_REAL_SEQUENCE_MANIFEST_ID || b->certified_build_id!=deployed_build_id)return -1;
 if(deadline_ticks<b->runtime_overhead_ticks)return -1;
 uint32_t usable=deadline_ticks-b->runtime_overhead_ticks;int8_t best=-1;
 for(uint8_t c=0;c<RTNN_REAL_SEQUENCE_EXIT_COUNT;++c){uint32_t u=b->upper_ticks[c];if(u!=RTNN_REAL_SEQUENCE_BOUND_INVALID && u<=usable)best=(int8_t)c;}
 return best;
}
int8_t rtnn_real_sequence_infer_deadline_budget(RTNNRealSequenceWorkspace* w,const uint8_t pixels[64],uint16_t budget_q16,uint32_t deadline_ticks,uint64_t deployed_build_id,const RTNNRealSequenceTimingBinding* b,float logits[10],uint8_t* executed_exit){
 int8_t c=rtnn_real_sequence_admit_deadline(deadline_ticks,deployed_build_id,b);if(c<0){if(executed_exit)*executed_exit=0;return -1;}rtnn_real_sequence_infer_budget(w,pixels,budget_q16,(uint8_t)c,logits,executed_exit);return c;
}
