#define _GNU_SOURCE
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <x86intrin.h>
#include "realtime_nn_real_sequence_core.h"
#include "realtime_nn_real_sequence_test_generated.h"
#define R 700
static int cmpu64(const void*a,const void*b){uint64_t x=*(const uint64_t*)a,y=*(const uint64_t*)b;return x<y?-1:x>y?1:0;}
static uint16_t budget_for_class(int c){ if(c>=6)return 65535u; return (uint16_t)(((uint32_t)c*65535u+5u)/6u); }
int main(void){
 cpu_set_t set;CPU_ZERO(&set);CPU_SET(0,&set);int aff=sched_setaffinity(0,sizeof(set),&set);
 printf("affinity_rc=%d\n",aff);
 RTNNRealSequenceWorkspace w; static uint64_t v[R]; volatile float sink=0;
 for(int run=0;run<3;++run){printf("run=%d\n",run);for(int c=0;c<7;++c){uint16_t b=budget_for_class(c);int maxexit=0;for(int r=0;r<R;++r){int n=(r*73+run*97+c*19)%RTNN_TEST_N;float z[10];uint8_t e;unsigned aux;uint64_t t0=__rdtscp(&aux);rtnn_real_sequence_infer_budget(&w,RTNN_TEST_X[n],b,(uint8_t)c,z,&e);uint64_t t1=__rdtscp(&aux);v[r]=t1-t0;if(e>maxexit)maxexit=e;sink+=z[0];}qsort(v,R,sizeof(v[0]),cmpu64);printf("class=%d budget_q16=%u max_exit=%d min=%llu med=%llu p99=%llu max=%llu\n",c,(unsigned)b,maxexit,(unsigned long long)v[0],(unsigned long long)v[R/2],(unsigned long long)v[(R*99)/100],(unsigned long long)v[R-1]);}}
 if(sink==123.456f)puts("sink");return 0;
}
