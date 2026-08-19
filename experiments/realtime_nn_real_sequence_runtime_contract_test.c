#include <stdio.h>
#include <stdint.h>
#include "realtime_nn_real_sequence_runtime_contract.h"
#include "realtime_nn_real_sequence_test_generated.h"
#define BID UINT64_C(0x63a11ce55aa55163)
static int argmax10(const float z[10]){int a=0;for(int i=1;i<10;++i)if(z[i]>z[a])a=i;return a;}
static uint16_t budget_grid(int gi){return (uint16_t)((gi*65535u)/20u);}
int main(void){
 RTNNRealSequenceTimingBinding b={RTNN_REAL_SEQUENCE_MANIFEST_ID,BID,10u,{100u,200u,300u,400u,500u,600u,700u}};
 int bad=0,pred_bad=0,exec_bad=0,cases=0;RTNNRealSequenceWorkspace w;
 for(int dc=0;dc<7;++dc){uint32_t D=10u+b.upper_ticks[dc];if(rtnn_real_sequence_admit_deadline(D,BID,&b)!=dc)bad++;for(int gi=0;gi<=20;++gi){uint16_t q=budget_grid(gi);uint8_t cap=rtnn_real_sequence_budget_ceiling_q16(q);for(int n=0;n<RTNN_TEST_N;++n){float z[10];uint8_t e=255;int8_t ac=rtnn_real_sequence_infer_deadline_budget(&w,RTNN_TEST_X[n],q,D,BID,&b,z,&e);uint8_t expect=RTNN_REF_PREF[n];if(cap<expect)expect=cap;if(dc<expect)expect=(uint8_t)dc;if(expect>RTNN_REAL_SEQUENCE_POLICY_MAX_EXIT)expect=RTNN_REAL_SEQUENCE_POLICY_MAX_EXIT;bad+=(ac!=dc);exec_bad+=(e!=expect);pred_bad+=(argmax10(z)!=RTNN_REF_PRED[expect][n]);cases++;}}}
 RTNNRealSequenceTimingBinding partial=b;for(int i=2;i<7;++i)partial.upper_ticks[i]=RTNN_REAL_SEQUENCE_BOUND_INVALID;if(rtnn_real_sequence_admit_deadline(100000u,BID,&partial)!=1)bad++;
 if(rtnn_real_sequence_admit_deadline(100000u,BID+1,&b)!=-1)bad++;RTNNRealSequenceTimingBinding wrong=b;wrong.manifest_id^=1;if(rtnn_real_sequence_admit_deadline(100000u,BID,&wrong)!=-1)bad++;
 printf("cases=%d admit_bad=%d executed_bad=%d prediction_bad=%d partial_fail_closed=%d wrong_build_rejected=%d wrong_manifest_rejected=%d\n",cases,bad,exec_bad,pred_bad,rtnn_real_sequence_admit_deadline(100000u,BID,&partial)==1,rtnn_real_sequence_admit_deadline(100000u,BID+1,&b)==-1,rtnn_real_sequence_admit_deadline(100000u,BID,&wrong)==-1);
 return (bad||exec_bad||pred_bad)?1:0;
}
