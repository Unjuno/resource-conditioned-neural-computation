#define _POSIX_C_SOURCE 200809L
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "realtime_nn_weights_generated.h"
#include "realtime_nn_activation_lut_generated.h"

#define L 9
#define C 32
#define F 128
#define K 8
#define BLOCK_MACS 92160
#define HEAD_MACS 64

typedef struct { const float *sw,*sb,*nw,*nb,*f1w,*f1b,*f2w,*f2b; } Block;
typedef struct { const float* emb; Block block[K]; const float* hw; const float* hb; } Model;
typedef struct { float a,b; } Result;
typedef struct { float h[L][C],z[L][C],tmp[L][F],ff[L][C]; } Scratch;

static Model M;
static Scratch WORKSPACE;
static double SAMPLES[20000];

static const float* take(size_t* o,size_t n){const float*p=RT_WEIGHTS+*o;*o+=n;return p;}
static int init_model(void){
    size_t o=0;M.emb=take(&o,2*C);
    for(int k=0;k<K;k++){
        M.block[k].sw=take(&o,C*C);M.block[k].sb=take(&o,C);
        M.block[k].nw=take(&o,C*C);M.block[k].nb=take(&o,C);
        M.block[k].f1w=take(&o,F*C);M.block[k].f1b=take(&o,F);
        M.block[k].f2w=take(&o,C*F);M.block[k].f2b=take(&o,C);
    }
    M.hw=take(&o,2*C);M.hb=take(&o,2);return o==RT_WEIGHT_COUNT;
}

// Fixed-size, bounded-table activation implementation. The generated tables
// contain exact reference values at uniformly spaced points in [-8, 8].
static inline float lut_interp(const float* table,float x){
    if(x<=ACT_LUT_LO)return table[0];
    if(x>=ACT_LUT_HI)return table[ACT_LUT_N-1];
    float u=(x-ACT_LUT_LO)/ACT_LUT_STEP;
    int i=(int)u;
    float t=u-(float)i;
    return table[i]+t*(table[i+1]-table[i]);
}
static inline float rt_tanh(float x){return lut_interp(TANH_LUT,x);}
static inline float rt_gelu(float x){return lut_interp(GELU_LUT,x);}

static inline void lin(const float*w,const float*b,const float*x,float*y,int O,int I){for(int o=0;o<O;o++){float s=b[o];const float*row=w+o*I;for(int i=0;i<I;i++)s+=row[i]*x[i];y[o]=s;}}
static void init_state(Scratch*s,uint16_t state){for(int p=0;p<L;p++){int bit=(state>>p)&1;memcpy(s->h[p],M.emb+bit*C,sizeof(float)*C);}}
static void run_block(Scratch*s,int bi){
    const Block*q=&M.block[bi];
    for(int p=0;p<L;p++){
        float a[C],n[C];lin(q->sw,q->sb,s->h[p],a,C,C);
        if(p<L-1)lin(q->nw,q->nb,s->h[p+1],n,C,C);else memcpy(n,q->nb,sizeof(float)*C);
        for(int j=0;j<C;j++)s->z[p][j]=rt_tanh(a[j]+n[j]);
        lin(q->f1w,q->f1b,s->z[p],s->tmp[p],F,C);for(int j=0;j<F;j++)s->tmp[p][j]=rt_gelu(s->tmp[p][j]);
        lin(q->f2w,q->f2b,s->tmp[p],s->ff[p],C,F);for(int j=0;j<C;j++)s->h[p][j]=rt_tanh(s->z[p][j]+.2f*s->ff[p][j]);
    }
}
static Result finish(const Scratch*s){float y[2];lin(M.hw,M.hb,s->h[0],y,2,C);Result r={y[0],y[1]};return r;}
static Result infer_d0(Scratch*s,uint16_t st){init_state(s,st);return finish(s);}
static Result infer_d2(Scratch*s,uint16_t st){init_state(s,st);run_block(s,0);run_block(s,1);return finish(s);}
static Result infer_d4(Scratch*s,uint16_t st){init_state(s,st);run_block(s,0);run_block(s,1);run_block(s,2);run_block(s,3);return finish(s);}
static Result infer_d6(Scratch*s,uint16_t st){init_state(s,st);run_block(s,0);run_block(s,1);run_block(s,2);run_block(s,3);run_block(s,4);run_block(s,5);return finish(s);}
static Result infer_d8(Scratch*s,uint16_t st){init_state(s,st);run_block(s,0);run_block(s,1);run_block(s,2);run_block(s,3);run_block(s,4);run_block(s,5);run_block(s,6);run_block(s,7);return finish(s);}
static Result infer_class(Scratch*s,uint16_t st,int cls){switch(cls){case 0:return infer_d0(s,st);case 1:return infer_d2(s,st);case 2:return infer_d4(s,st);case 3:return infer_d6(s,st);default:return infer_d8(s,st);}}

static double usec(void){struct timespec t;clock_gettime(CLOCK_MONOTONIC_RAW,&t);return t.tv_sec*1e6+t.tv_nsec/1e3;}
static int cmpd(const void*a,const void*b){double x=*(const double*)a,y=*(const double*)b;return (x>y)-(x<y);}
static double quant(double*v,int n,double q){qsort(v,n,sizeof(double),cmpd);int i=(int)ceil(q*n)-1;if(i<0)i=0;if(i>=n)i=n-1;return v[i];}

int main(int argc,char**argv){
    if(!init_model())return 3;int reps=argc>1?atoi(argv[1]):2000;if(reps>20000)reps=20000;
    const int dep[5]={0,2,4,6,8};volatile float sink=0;
    for(int c=0;c<5;c++){
        int ok=0;for(int st=0;st<512;st++){Result r=infer_class(&WORKSPACE,(uint16_t)st,c);int pred=r.b>r.a;int label=__builtin_popcount((unsigned)st)>=5;ok+=pred==label;}
        printf("class=%d depth=%d acc=%.9f macs=%d\n",c,dep[c],ok/512.0,HEAD_MACS+dep[c]*BLOCK_MACS);
    }
    for(int c=0;c<5;c++){
        for(int i=0;i<500;i++)sink+=infer_class(&WORKSPACE,(uint16_t)(i&511),c).a;
        for(int i=0;i<reps;i++){double a=usec();sink+=infer_class(&WORKSPACE,(uint16_t)((i*131)&511),c).a;double z=usec();SAMPLES[i]=z-a;}
        double p50=quant(SAMPLES,reps,.5),p95=quant(SAMPLES,reps,.95),p99=quant(SAMPLES,reps,.99);
        printf("class=%d depth=%d p50_us=%.6f p95_us=%.6f p99_us=%.6f\n",c,dep[c],p50,p95,p99);
    }
    fprintf(stderr,"sink=%f\n",sink);return 0;
}
