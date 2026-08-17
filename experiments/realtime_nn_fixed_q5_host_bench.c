#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include "realtime_nn_fixed_q5_core.h"
static RTNNQ5Workspace W;
static int label(unsigned s){int n=0;for(int i=0;i<9;i++)n+=(s>>i)&1u;return n>=5;}
static double usdiff(struct timespec a,struct timespec b){return(b.tv_sec-a.tv_sec)*1e6+(b.tv_nsec-a.tv_nsec)/1e3;}
static int cmpd(const void*a,const void*b){double x=*(const double*)a,y=*(const double*)b;return x<y?-1:x>y;}
int main(int argc,char**argv){int reps=argc>1?atoi(argv[1]):5000;if(!rtnn_q5_init())return 2;for(int c=0;c<5;c++){int ok=0;for(int s=0;s<512;s++){RTNNQ5Result r=rtnn_q5_infer(&W,(uint16_t)s,(uint8_t)c);ok+=(r.logit1>r.logit0)==label((unsigned)s);}printf("class=%d acc=%.9f\n",c,ok/512.0);}for(int s=0;s<512;s++){RTNNQ5Result a=rtnn_q5_infer(&W,(uint16_t)s,0),b=rtnn_q5_infer(&W,(uint16_t)s,255);if(a.logit0!=b.logit0||a.logit1!=b.logit1)return 3;}puts("invalid_class_fail_closed=1");for(int c=0;c<5;c++){double*v=malloc(sizeof(double)*reps);if(!v)return 4;for(int k=0;k<500;k++)rtnn_q5_infer(&W,(uint16_t)(k&511),(uint8_t)c);volatile int sink=0;for(int k=0;k<reps;k++){struct timespec a,b;clock_gettime(CLOCK_MONOTONIC,&a);RTNNQ5Result r=rtnn_q5_infer(&W,(uint16_t)((k*73)&511),(uint8_t)c);clock_gettime(CLOCK_MONOTONIC,&b);sink+=r.logit0;v[k]=usdiff(a,b);}qsort(v,reps,sizeof(double),cmpd);printf("class=%d p50_us=%.6f p95_us=%.6f p99_us=%.6f sink=%d\n",c,v[reps/2],v[(int)(reps*.95)],v[(int)(reps*.99)],sink);free(v);}return 0;}
