#include <stdio.h>
#include <stdint.h>
#include "realtime_nn_real_sequence_fixed_core.h"
#include "realtime_nn_real_sequence_test_generated.h"
static int argmax(const int32_t*z){int b=0;for(int i=1;i<10;++i)if(z[i]>z[b])b=i;return b;}
int main(void){RTNNFixedWorkspace w;int32_t z[10];unsigned mm=0,pm=0,acc[7]={0},dist[7]={0};
 for(unsigned n=0;n<RTNN_TEST_N;++n){
  for(unsigned e=0;e<7;++e){rtnn_fixed_infer_exit(&w,RTNN_TEST_X[n],(uint8_t)e,z);int p=argmax(z);mm+=(p!=RTNN_REF_PRED[e][n]);acc[e]+=(p==RTNN_TEST_Y[n]);}
  uint8_t p=rtnn_fixed_preferred_exit(&w,RTNN_TEST_X[n]);pm+=(p!=RTNN_REF_PREF[n]);if(p<7)dist[p]++;
 }
 printf("exit_mismatch=%u pref_mismatch=%u workspace=%zu\n",mm,pm,sizeof(w));
 for(int e=0;e<7;++e)printf("e%d_acc=%u/%u dist=%u\n",e,acc[e],RTNN_TEST_N,dist[e]);
 return (mm||pm)?1:0;
}
