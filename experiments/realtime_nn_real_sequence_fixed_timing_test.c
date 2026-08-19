#include <stdio.h>
#include <stdint.h>
#include "realtime_nn_real_sequence_fixed_core.h"
#include "realtime_nn_real_sequence_fixed_timing_contract.h"
#include "realtime_nn_real_sequence_test_generated.h"
/* seed-63 canonical Q15 model SHA begins b53c6dbc; stripped RV32 load-image SHA begins 234b3ac1. */
#define MODEL_ID UINT32_C(0xb53c6dbc)
#define BUILD_ID UINT32_C(0x234b3ac1)
static const RTNNFixedConditionalTimingBinding B={MODEL_ID,BUILD_ID,{22180u,549778u,1077368u,1604958u,2132548u,2660139u,2660140u}};
static int argmax(const int32_t*z){int b=0;for(int i=1;i<10;++i)if(z[i]>z[b])b=i;return b;}
static uint16_t bq(int i){return (uint16_t)((i*65535u+10u)/20u);}
int main(void){
 RTNNFixedWorkspace w;int32_t z[10];unsigned adm=0,exm=0,pm=0,cap=0;unsigned long long cases=0;
 for(unsigned n=0;n<RTNN_TEST_N;++n)for(int bi=0;bi<=20;++bi){uint16_t q=bq(bi);uint8_t bc=rtnn_fixed_budget_ceiling_q16(q);for(int dc=0;dc<7;++dc){
  int8_t a=rtnn_fixed_admit_total_cycles(B.total_upper_cycles[dc],MODEL_ID,BUILD_ID,&B);adm+=(a!=dc);
  uint8_t ex=RTNN_REF_PREF[n];if(ex>bc)ex=bc;if(ex>(uint8_t)dc)ex=(uint8_t)dc;if(ex>5u)ex=5u;
  uint8_t got=255;rtnn_fixed_infer_budget(&w,RTNN_TEST_X[n],q,(uint8_t)a,z,&got);exm+=(got!=ex);pm+=(argmax(z)!=RTNN_REF_PRED[ex][n]);cap+=(got>bc||got>(uint8_t)dc);++cases;
 }}
 RTNNFixedConditionalTimingBinding p=B;for(int c=3;c<7;++c)p.total_upper_cycles[c]=RTNN_FIXED_BOUND_INVALID;
 int partial=rtnn_fixed_admit_total_cycles(UINT32_MAX,MODEL_ID,BUILD_ID,&p)==2;
 int wrong_model=rtnn_fixed_admit_total_cycles(UINT32_MAX,0,BUILD_ID,&B)==-1;
 int wrong_build=rtnn_fixed_admit_total_cycles(UINT32_MAX,MODEL_ID,0,&B)==-1;
 printf("cases=%llu admission_mismatch=%u exit_mismatch=%u pred_mismatch=%u cap_violation=%u partial_ok=%d wrong_model=%d wrong_build=%d\n",cases,adm,exm,pm,cap,partial,wrong_model,wrong_build);
 return (adm||exm||pm||cap||!partial||!wrong_model||!wrong_build)?1:0;
}
