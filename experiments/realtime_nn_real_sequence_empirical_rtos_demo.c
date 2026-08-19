#define _GNU_SOURCE
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sched.h>
#include <x86intrin.h>
#include "realtime_nn_real_sequence_runtime_contract.h"
#include "realtime_nn_real_sequence_test_generated.h"
#define BID UINT64_C(0x63a11ce55aa55163)
#define CAL 600
#define EVAL 900
static int cmpu64(const void*a,const void*b){uint64_t x=*(const uint64_t*)a,y=*(const uint64_t*)b;return x<y?-1:x>y?1:0;}
static int argmax10(const float z[10]){int a=0;for(int i=1;i<10;++i)if(z[i]>z[a])a=i;return a;}
static uint16_t budget_for_class(int c){if(c>=6)return 65535u;return (uint16_t)(((uint32_t)c*65535u+5u)/6u);}
static uint64_t measure_budget(RTNNRealSequenceWorkspace*w,int n,int c,float z[10],uint8_t*e){unsigned aux;uint64_t t0=__rdtscp(&aux);rtnn_real_sequence_infer_budget(w,RTNN_TEST_X[n],budget_for_class(c),(uint8_t)c,z,e);return __rdtscp(&aux)-t0;}
static uint64_t measure_exit(RTNNRealSequenceWorkspace*w,int n,int c,float z[10]){unsigned aux;uint64_t t0=__rdtscp(&aux);rtnn_real_sequence_infer_exit(w,RTNN_TEST_X[n],(uint8_t)c,z);return __rdtscp(&aux)-t0;}
int main(void){cpu_set_t set;CPU_ZERO(&set);CPU_SET(0,&set);printf("affinity_rc=%d\n",sched_setaffinity(0,sizeof(set),&set));RTNNRealSequenceWorkspace w;static uint64_t v[CAL];RTNNRealSequenceTimingBinding b={RTNN_REAL_SEQUENCE_MANIFEST_ID,BID,0,{0}};
 for(int c=0;c<=5;++c){for(int r=0;r<CAL;++r){float z[10];uint8_t e;int n=(r*71+c*29)%RTNN_TEST_N;v[r]=measure_budget(&w,n,c,z,&e);}qsort(v,CAL,sizeof(v[0]),cmpu64);uint32_t p99=(uint32_t)v[(CAL*99)/100];if(c>0 && p99<=b.upper_ticks[c-1])p99=b.upper_ticks[c-1]+1;b.upper_ticks[c]=p99;printf("cal_class=%d p99_envelope=%u cal_max=%llu\n",c,p99,(unsigned long long)v[CAL-1]);}b.upper_ticks[6]=RTNN_REAL_SEQUENCE_BOUND_INVALID;
 for(int c=0;c<=5;++c){uint32_t D=b.upper_ticks[c];int rt_miss=0,rt_corr=0,rt_otc=0,full_miss=0,full_corr=0,full_otc=0,f1_miss=0,f1_corr=0,f1_otc=0;double rt_e=0;for(int r=0;r<EVAL;++r){int n=(r*83+c*41+17)%RTNN_TEST_N;float z[10];uint8_t e=0;unsigned aux;uint64_t t0=__rdtscp(&aux);int8_t ac=rtnn_real_sequence_infer_deadline_budget(&w,RTNN_TEST_X[n],65535u,D,BID,&b,z,&e);uint64_t dt=__rdtscp(&aux)-t0;int p=argmax10(z),ok=(ac>=0 && p==RTNN_TEST_Y[n]);rt_corr+=ok;rt_miss+=(dt>D);rt_otc+=(ok && dt<=D);rt_e+=e;
 uint64_t df=measure_exit(&w,n,5,z);p=argmax10(z);ok=(p==RTNN_TEST_Y[n]);full_corr+=ok;full_miss+=(df>D);full_otc+=(ok&&df<=D);
 uint64_t d1=measure_exit(&w,n,1,z);p=argmax10(z);ok=(p==RTNN_TEST_Y[n]);f1_corr+=ok;f1_miss+=(d1>D);f1_otc+=(ok&&d1<=D);
 }
 printf("deadline_class=%d D=%u rtnn_acc=%.6f rtnn_miss=%.6f rtnn_otc=%.6f rtnn_mean_compute=%.6f full_acc=%.6f full_miss=%.6f full_otc=%.6f fixed1_acc=%.6f fixed1_miss=%.6f fixed1_otc=%.6f\n",c,D,(double)rt_corr/EVAL,(double)rt_miss/EVAL,(double)rt_otc/EVAL,rt_e/(EVAL*6.0),(double)full_corr/EVAL,(double)full_miss/EVAL,(double)full_otc/EVAL,(double)f1_corr/EVAL,(double)f1_miss/EVAL,(double)f1_otc/EVAL);
 }
 return 0;}
