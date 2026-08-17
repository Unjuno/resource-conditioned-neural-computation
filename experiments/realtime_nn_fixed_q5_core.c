#include "realtime_nn_fixed_q5_core.h"
#include "realtime_nn_fixed_q5_generated.h"
_Static_assert(sizeof(RTNNQ5Workspace)==RTNN_Q5_WORKSPACE_BYTES,"workspace");
typedef struct { const int16_t *sw,*sb,*nw,*nb,*f1w,*f1b,*f2w,*f2b; } Block;
typedef struct { const int16_t* emb; Block b[RTNN_BLOCKS]; const int16_t *hw,*hb; } Model;
static Model M;
static const int16_t* take(unsigned long* o,unsigned long n){const int16_t*p=RTNN_QWEIGHTS+*o;*o+=n;return p;}
int rtnn_q5_init(void){unsigned long o=0;M.emb=take(&o,2*RTNN_C);for(int k=0;k<RTNN_BLOCKS;k++){M.b[k].sw=take(&o,RTNN_C*RTNN_C);M.b[k].sb=take(&o,RTNN_C);M.b[k].nw=take(&o,RTNN_C*RTNN_C);M.b[k].nb=take(&o,RTNN_C);M.b[k].f1w=take(&o,RTNN_F*RTNN_C);M.b[k].f1b=take(&o,RTNN_F);M.b[k].f2w=take(&o,RTNN_C*RTNN_F);M.b[k].f2b=take(&o,RTNN_C);}M.hw=take(&o,2*RTNN_C);M.hb=take(&o,2);return o==RTNN_WEIGHT_COUNT;}
static int16_t clamp16(int32_t x){if(x>32767)return 32767;if(x<-32768)return -32768;return (int16_t)x;}
static int32_t round_q5(int32_t x){if(x>=0)return(x+16)>>5;return-(((-x)+16)>>5);}
static int16_t lin1(const int16_t*w,const int16_t*b,const int16_t*x,int row,int in){int32_t a=((int32_t)b[row])<<5;const int16_t*r=w+row*in;for(int i=0;i<in;i++)a+=(int32_t)r[i]*x[i];return clamp16(round_q5(a));}
static void lin(const int16_t*w,const int16_t*b,const int16_t*x,int16_t*y,int out,int in){for(int o=0;o<out;o++)y[o]=lin1(w,b,x,o,in);}
static int16_t lut(const int16_t*t,int32_t x){if(x<=-256)return t[0];if(x>=256)return t[256];int32_t u=x+256;int i=(int)((u+1)>>1);if(i<0)i=0;if(i>256)i=256;return t[i];}
static void copy32(int16_t*d,const int16_t*s){for(int j=0;j<RTNN_C;j++)d[j]=s[j];}
static void init_state(RTNNQ5Workspace*s,uint16_t x){for(int p=0;p<RTNN_L;p++){int bit=(x>>p)&1;copy32(s->h[p],M.emb+bit*RTNN_C);}}
static void block(RTNNQ5Workspace*s,int bi){const Block*q=&M.b[bi];for(int p=0;p<RTNN_L;p++){int16_t a[RTNN_C],n[RTNN_C];lin(q->sw,q->sb,s->h[p],a,RTNN_C,RTNN_C);if(p<RTNN_L-1)lin(q->nw,q->nb,s->h[p+1],n,RTNN_C,RTNN_C);else copy32(n,q->nb);for(int j=0;j<RTNN_C;j++)s->z[p][j]=lut(RTNN_QTANH,(int32_t)a[j]+n[j]);lin(q->f1w,q->f1b,s->z[p],s->tmp[p],RTNN_F,RTNN_C);for(int j=0;j<RTNN_F;j++)s->tmp[p][j]=lut(RTNN_QGELU,s->tmp[p][j]);lin(q->f2w,q->f2b,s->tmp[p],s->ff[p],RTNN_C,RTNN_F);for(int j=0;j<RTNN_C;j++){int32_t ff=s->ff[p][j];int32_t adj=ff>=0?(ff+2)/5:-(((-ff)+2)/5);s->h[p][j]=lut(RTNN_QTANH,(int32_t)s->z[p][j]+adj);}}}
static RTNNQ5Result finish(RTNNQ5Workspace*s){RTNNQ5Result r={lin1(M.hw,M.hb,s->h[0],0,RTNN_C),lin1(M.hw,M.hb,s->h[0],1,RTNN_C)};return r;}
RTNNQ5Result rtnn_q5_infer(RTNNQ5Workspace*s,uint16_t x,uint8_t c){init_state(s,x);int d=(c==0?0:c==1?2:c==2?4:c==3?6:c==4?8:0);for(int i=0;i<d;i++)block(s,i);return finish(s);}
