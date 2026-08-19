#include <stdio.h>
#include "realtime_nn_real_sequence_core.h"
#include "realtime_nn_real_sequence_test_generated.h"
int main(void){
 RTNNRealSequenceWorkspace w; int mism[7]={0}, correct[7]={0};
 for(int n=0;n<RTNN_TEST_N;++n){for(int e=0;e<7;++e){float z[10];rtnn_real_sequence_infer_exit(&w,RTNN_TEST_X[n],(uint8_t)e,z);int p=0;for(int c=1;c<10;++c)if(z[c]>z[p])p=c;mism[e]+=(p!=RTNN_REF_PRED[e][n]);correct[e]+=(p==RTNN_TEST_Y[n]);}}
 int pref_dist[7]={0}, policy_correct=0, pref_mismatch=0;double mean_exit=0;
 for(int n=0;n<RTNN_TEST_N;++n){uint8_t p=rtnn_real_sequence_preferred_exit(&w,RTNN_TEST_X[n]);pref_dist[p]++;pref_mismatch+=(p!=RTNN_REF_PREF[n]);mean_exit+=p;float z[10];uint8_t e;rtnn_real_sequence_infer_budget(&w,RTNN_TEST_X[n],65535u,6u,z,&e);int q=0;for(int c=1;c<10;++c)if(z[c]>z[q])q=c;policy_correct+=(q==RTNN_TEST_Y[n]);}
 printf("exit_mismatches=");for(int e=0;e<7;++e)printf("%s%d",e?",":"",mism[e]);printf("\n");
 printf("exit_accuracy=");for(int e=0;e<7;++e)printf("%s%.9f",e?",":"",(double)correct[e]/RTNN_TEST_N);printf("\n");
 printf("preferred_dist=");for(int e=0;e<7;++e)printf("%s%d",e?",":"",pref_dist[e]);printf("\n");
 printf("pref_mismatch=%d policy_accuracy=%.9f mean_compute=%.9f\n",pref_mismatch,(double)policy_correct/RTNN_TEST_N,mean_exit/(RTNN_TEST_N*6.0));
 int bad=0;for(unsigned b=0;b<=65535u;++b){unsigned c=rtnn_real_sequence_budget_ceiling_q16((uint16_t)b);if(c>6u || (uint64_t)c*65535u>(uint64_t)b*6u)bad++;if(c<6u && (uint64_t)(c+1)*65535u<=(uint64_t)b*6u)bad++;}
 printf("budget_property_bad=%d invalid_effective=%u\n",bad,(unsigned)rtnn_real_sequence_effective_exit_q16(65535u,255u,6u));
 return 0;
}
