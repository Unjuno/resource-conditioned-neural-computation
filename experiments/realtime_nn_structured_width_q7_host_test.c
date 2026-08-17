#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "realtime_nn_structured_width_q7_core.h"
static RTNNSWWorkspace W;
static int label(unsigned s){int n=0;for(int i=0;i<9;i++)n+=(s>>i)&1u;return n>=5;}
static double us(struct timespec a,struct timespec b){return(b.tv_sec-a.tv_sec)*1e6+(b.tv_nsec-a.tv_nsec)/1e3;}
static int cmp(const void*a,const void*b){double x=*(const double*)a,y=*(const double*)b;return(x>y)-(x<y);}
int main(int argc,char**argv){int reps=argc>1?atoi(argv[1]):1200;if(!rtnn_sw_q7_init())return 2;const RTNNSWClass*c=rtnn_sw_q7_classes();for(int k=0;k<5;k++){int ok=0;for(int s=0;s<512;s++){RTNNSWResult r=rtnn_sw_q7_infer(&W,(uint16_t)s,(uint8_t)k);ok+=(r.logit1>r.logit0)==label((unsigned)s);}printf("class=%d depth=%u width=%u macs=%u acc=%.9f\n",k,c[k].depth,c[k].width,c[k].linear_macs,ok/512.);}for(int s=0;s<512;s++){RTNNSWResult a=rtnn_sw_q7_infer(&W,(uint16_t)s,0),b=rtnn_sw_q7_infer(&W,(uint16_t)s,255);if(a.logit0!=b.logit0||a.logit1!=b.logit1)return 3;}puts("invalid_class_fail_closed=1");volatile int sink=0;for(int k=0;k<5;k++){double*v=malloc(sizeof(double)*reps);if(!v)return 4;for(int i=0;i<300;i++)sink+=rtnn_sw_q7_infer(&W,(uint16_t)(i&511),(uint8_t)k).logit0;for(int i=0;i<reps;i++){struct timespec a,b;clock_gettime(CLOCK_MONOTONIC_RAW,&a);RTNNSWResult r=rtnn_sw_q7_infer(&W,(uint16_t)((i*73)&511),(uint8_t)k);clock_gettime(CLOCK_MONOTONIC_RAW,&b);sink+=r.logit0;v[i]=us(a,b);}qsort(v,reps,sizeof(double),cmp);printf("class=%d p50_us=%.6f p95_us=%.6f p99_us=%.6f\n",k,v[reps/2],v[(int)(reps*.95)],v[(int)(reps*.99)]);free(v);}fprintf(stderr,"sink=%d\n",sink);return 0;}
