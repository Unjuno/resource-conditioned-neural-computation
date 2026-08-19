#include "realtime_nn_real_sequence_fixed_timing_contract.h"
int8_t rtnn_fixed_admit_total_cycles(uint32_t deadline,uint32_t model_id,uint32_t build_id,const RTNNFixedConditionalTimingBinding* b){
 if(!b || b->model_id!=model_id || b->build_id!=build_id) return -1;
 int8_t best=-1;
 for(uint8_t c=0;c<RTNN_FIXED_TIMING_CLASSES;++c){uint32_t u=b->total_upper_cycles[c];if(u!=RTNN_FIXED_BOUND_INVALID && u<=deadline)best=(int8_t)c;}
 return best;
}
