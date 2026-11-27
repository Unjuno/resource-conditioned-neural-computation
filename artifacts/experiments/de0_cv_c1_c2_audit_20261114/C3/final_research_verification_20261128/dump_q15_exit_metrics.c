#include "realtime_nn_real_sequence_fixed_core.h"
#include "realtime_nn_real_sequence_fixed_weights_generated.h"
#include <stdint.h>
#include <stdio.h>
#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#endif

/* Analysis-only Q15 probability helper copied algebraically from entropy10()
 * in the frozen core. It reads that core's frozen exp LUT; it never changes
 * model inputs, weights, predictions, or the deployed firmware. */
static uint64_t mask64(uint64_t c){return UINT64_C(0)-(c&1u);}
static uint32_t mask32(uint32_t c){return 0u-(c&1u);}
static int32_t select32(uint32_t m,int32_t t,int32_t f){return (int32_t)(((uint32_t)t&m)|((uint32_t)f&~m));}
static uint32_t ge64_32(uint64_t a,uint32_t b){uint32_t hi=(uint32_t)(a>>32),lo=(uint32_t)a;return (hi!=0u)|(lo>=b);}
static uint64_t div64_32(uint64_t num,uint32_t den){uint64_t q=0,rem=0;for(int i=63;i>=0;--i){uint64_t bit=(num>>(unsigned)i)&1u;rem=(rem<<1)|bit;uint64_t m=mask64(ge64_32(rem,den));rem-=((uint64_t)den)&m;q|=(UINT64_C(1)<<(unsigned)i)&m;}return q;}
static uint32_t expq(int32_t x){const int32_t lo=-32*RTNN_FX_S,step=RTNN_FX_S/256;int32_t xc=select32(mask32((uint32_t)(x>0)),0,x);xc=select32(mask32((uint32_t)(xc<lo)),lo,xc);uint32_t off=(uint32_t)(xc-lo),i=off>>7,r=off&127u,top=i>>13;i-=top;r+=top<<7;uint64_t a=fx_exp_lut[i],b=fx_exp_lut[i+1];return (uint32_t)((a*(step-r)+b*r+(step/2))>>7);}
static void confidence_margin_q15(const int32_t z[10],uint32_t*out_conf,uint32_t*out_margin,uint32_t*out_sum){int32_t mx=z[0];for(int i=1;i<10;++i)if(z[i]>mx)mx=z[i];uint32_t ex[10],den=0,p[10],sum=0;for(int i=0;i<10;++i){ex[i]=expq(z[i]-mx);den+=ex[i];}uint64_t inv=div64_32(UINT64_C(1)<<48,den);uint32_t first=0,second=0;for(int i=0;i<10;++i){p[i]=(uint32_t)(((uint64_t)ex[i]*inv+(UINT64_C(1)<<32))>>33);sum+=p[i];if(p[i]>=first){second=first;first=p[i];}else if(p[i]>second)second=p[i];}*out_conf=first;*out_margin=first-second;*out_sum=sum;}
static int argmax10(const int32_t z[10]){int b=0;for(int i=1;i<10;++i)if(z[i]>z[b])b=i;return b;}
int main(void){
#ifdef _WIN32
 if(_setmode(_fileno(stdin),_O_BINARY)==-1)return 6;
 if(_setmode(_fileno(stdout),_O_BINARY)==-1)return 7;
#endif
 RTNNFixedWorkspace w;uint8_t pixels[64];int32_t logits[10];unsigned long id=0;puts("input_id,exit,prediction,max_probability_q15,top2_margin_q15,probability_sum_q15,entropy_preferred_exit");while(fread(pixels,1,64,stdin)==64){++id;for(unsigned j=0;j<64;++j)if(pixels[j]>16)return 3;uint8_t preferred=rtnn_fixed_preferred_exit(&w,pixels);if(preferred>RTNN_FX_POLICY_MAX_EXIT)return 4;for(uint8_t e=0;e<7;++e){uint32_t conf,margin,sum;rtnn_fixed_infer_exit(&w,pixels,e,logits);confidence_margin_q15(logits,&conf,&margin,&sum);printf("%lu,%u,%d,%u,%u,%u,%u\n",id,(unsigned)e,argmax10(logits),conf,margin,sum,(unsigned)preferred);}}if(!feof(stdin))return 5;return 0;}
