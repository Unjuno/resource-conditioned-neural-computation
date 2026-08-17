#include "realtime_nn_structured_width_q7_core.h"
#include "realtime_nn_structured_width_q7_generated.h"
_Static_assert(sizeof(RTNNSWWorkspace)==RTNN_SW_WORKSPACE_BYTES,"workspace");
typedef struct{const int16_t*sw,*sb,*nw,*nb,*f1w,*f1b,*f2w,*f2b;}Block;typedef struct{const int16_t*emb;Block b[8];const int16_t*hw,*hb;}Model;static Model M;
static const RTNNSWClass CLS[5]={{0,0,8,16},{1,2,8,11408},{2,4,16,91168},{3,6,24,307632},{4,8,32,729152}};
static const int16_t*take(unsigned long*o,unsigned long n){const int16_t*p=RTNN_SW_QWEIGHTS+*o;*o+=n;return p;}
int rtnn_sw_q7_init(void){unsigned long o=0;M.emb=take(&o,64);for(int k=0;k<8;k++){M.b[k].sw=take(&o,1024);M.b[k].sb=take(&o,32);M.b[k].nw=take(&o,1024);M.b[k].nb=take(&o,32);M.b[k].f1w=take(&o,4096);M.b[k].f1b=take(&o,128);M.b[k].f2w=take(&o,4096);M.b[k].f2b=take(&o,32);}M.hw=take(&o,64);M.hb=take(&o,2);return o==RTNN_SW_WEIGHT_COUNT;}
static int32_t rp2(int32_t x,int32_t half,unsigned sh){int32_t n=x<0,m=-n,a=(x^m)+n,r=(a+half)>>sh;return r*(1-(n<<1));}
static int16_t sat(int32_t x){int32_t lo=x<-32768;x+=(-32768-x)*lo;int32_t hi=x>32767;x+=(32767-x)*hi;return(int16_t)x;}
static int16_t l1(const int16_t*w,const int16_t*b,const int16_t*x,int row,int in,int stride){int32_t a=((int32_t)b[row])<<7;for(int i=0;i<in;i++)a+=(int32_t)w[row*stride+i]*x[i];return sat(rp2(a,64,7));}
static void lin(const int16_t*w,const int16_t*b,const int16_t*x,int16_t*y,int O,int I,int stride){for(int o=0;o<O;o++)y[o]=l1(w,b,x,o,I,stride);}
static int16_t lut(const int16_t*t,int32_t x){const int32_t lo=-1024,hi=1024;int32_t below=x<lo;x+=(lo-x)*below;int32_t above=x>hi;x+=(hi-x)*above;int i=(int)((x-lo+4)>>3);return t[i];}
static void init(RTNNSWWorkspace*s,uint16_t st,int w){for(int p=0;p<9;p++){int bit=(st>>p)&1;for(int j=0;j<w;j++)s->h[p][j]=M.emb[bit*32+j];}}
static void block(RTNNSWWorkspace*s,int bi,int w){const Block*q=&M.b[bi];int G=4*w;for(int p=0;p<9;p++){int16_t a[32],n[32];lin(q->sw,q->sb,s->h[p],a,w,w,32);if(p<8)lin(q->nw,q->nb,s->h[p+1],n,w,w,32);else for(int j=0;j<w;j++)n[j]=q->nb[j];for(int j=0;j<w;j++)s->z[p][j]=lut(RTNN_SW_QTANH,(int32_t)a[j]+n[j]);lin(q->f1w,q->f1b,s->z[p],s->tmp[p],G,w,32);for(int j=0;j<G;j++)s->tmp[p][j]=lut(RTNN_SW_QGELU,s->tmp[p][j]);lin(q->f2w,q->f2b,s->tmp[p],s->ff[p],w,G,128);for(int j=0;j<w;j++){int32_t adj=rp2((int32_t)s->ff[p][j]*51,128,8);s->h[p][j]=lut(RTNN_SW_QTANH,(int32_t)s->z[p][j]+adj);}}}
RTNNSWResult rtnn_sw_q7_infer(RTNNSWWorkspace*s,uint16_t st,uint8_t c){if(c>=5)c=0;int d=CLS[c].depth,w=CLS[c].width;init(s,st,w);for(int i=0;i<d;i++)block(s,i,w);RTNNSWResult r={l1(M.hw,M.hb,s->h[0],0,w,32),l1(M.hw,M.hb,s->h[0],1,w,32)};return r;}
const RTNNSWClass*rtnn_sw_q7_classes(void){return CLS;}
