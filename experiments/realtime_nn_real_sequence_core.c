#include "realtime_nn_real_sequence_core.h"
#include "realtime_nn_real_sequence_weights_generated.h"

typedef struct {
    const float *n1w,*n1b,*iw,*ib,*ow,*ob,*n2w,*n2b,*aw,*ab,*bw,*bb;
} RTNNBlockW;
typedef struct { const float *w,*b; } RTNNHeadW;

static const RTNNBlockW BW[6] = {
 {b0_n1_w,b0_n1_b,b0_att_in_w,b0_att_in_b,b0_att_out_w,b0_att_out_b,b0_n2_w,b0_n2_b,b0_a_w,b0_a_b,b0_b_w,b0_b_b},
 {b1_n1_w,b1_n1_b,b1_att_in_w,b1_att_in_b,b1_att_out_w,b1_att_out_b,b1_n2_w,b1_n2_b,b1_a_w,b1_a_b,b1_b_w,b1_b_b},
 {b2_n1_w,b2_n1_b,b2_att_in_w,b2_att_in_b,b2_att_out_w,b2_att_out_b,b2_n2_w,b2_n2_b,b2_a_w,b2_a_b,b2_b_w,b2_b_b},
 {b3_n1_w,b3_n1_b,b3_att_in_w,b3_att_in_b,b3_att_out_w,b3_att_out_b,b3_n2_w,b3_n2_b,b3_a_w,b3_a_b,b3_b_w,b3_b_b},
 {b4_n1_w,b4_n1_b,b4_att_in_w,b4_att_in_b,b4_att_out_w,b4_att_out_b,b4_n2_w,b4_n2_b,b4_a_w,b4_a_b,b4_b_w,b4_b_b},
 {b5_n1_w,b5_n1_b,b5_att_in_w,b5_att_in_b,b5_att_out_w,b5_att_out_b,b5_n2_w,b5_n2_b,b5_a_w,b5_a_b,b5_b_w,b5_b_b}
};
static const RTNNHeadW HW[7]={{h0_w,h0_b},{h1_w,h1_b},{h2_w,h2_b},{h3_w,h3_b},{h4_w,h4_b},{h5_w,h5_b},{h6_w,h6_b}};

static float rsqrt_approx(float x) {
    union { float f; uint32_t u; } z = {x};
    z.u = 0x5f375a86u - (z.u >> 1);
    float y=z.f;
    for (int i=0;i<5;++i) y = y * (1.5f - 0.5f*x*y*y);
    return y;
}
static float exp_neg(float x) {
    if (x >= 0.0f) return 1.0f;
    if (x <= RTNN_EXP_LO) return rtnn_exp_lut[0];
    float u=(x-RTNN_EXP_LO)/RTNN_EXP_STEP; int i=(int)u; float f=u-(float)i;
    if (i>=RTNN_EXP_N-1) return rtnn_exp_lut[RTNN_EXP_N-1];
    return rtnn_exp_lut[i] + f*(rtnn_exp_lut[i+1]-rtnn_exp_lut[i]);
}
static float gelu(float x) {
    if (x <= RTNN_GELU_LO) return 0.0f;
    if (x >= RTNN_GELU_HI) return x;
    float u=(x-RTNN_GELU_LO)/RTNN_GELU_STEP; int i=(int)u; float f=u-(float)i;
    return rtnn_gelu_lut[i]+f*(rtnn_gelu_lut[i+1]-rtnn_gelu_lut[i]);
}
static void linear(const float* w,const float* b,const float* x,float* y,int out,int in) {
    for(int o=0;o<out;++o){float s=b[o];for(int i=0;i<in;++i)s+=w[o*in+i]*x[i];y[o]=s;}
}
static void layernorm(const float* x,float* y,const float* g,const float* b) {
    float m=0.0f; for(int i=0;i<16;++i)m+=x[i];m*=0.0625f;
    float v0=0.0f; for(int i=0;i<16;++i){float d=x[i]-m;v0+=d*d;}v0*=0.0625f;
    float inv=rsqrt_approx(v0+1e-5f);
    for(int i=0;i<16;++i)y[i]=(x[i]-m)*inv*g[i]+b[i];
}
static void init_state(RTNNRealSequenceWorkspace* w,const uint8_t p[64]) {
    for(int t=0;t<8;++t){
        float in[8];for(int j=0;j<8;++j)in[j]=(float)p[t*8+j]*(1.0f/16.0f);
        linear(emb_w,emb_b,in,w->h[t],16,8);
        for(int j=0;j<16;++j)w->h[t][j]+=pos[t*16+j];
    }
}
static void run_block(RTNNRealSequenceWorkspace* w,int bi) {
    const RTNNBlockW* q=&BW[bi];
    for(int t=0;t<8;++t)layernorm(w->h[t],w->x[t],q->n1w,q->n1b);
    for(int t=0;t<8;++t){
        float y[48];linear(q->iw,q->ib,w->x[t],y,48,16);
        for(int j=0;j<16;++j){int hd=j/8,d=j%8;w->q[hd][t][d]=y[j];w->k[hd][t][d]=y[16+j];w->v[hd][t][d]=y[32+j];}
    }
    const float scale=0.3535533905932738f;
    for(int hd=0;hd<2;++hd){for(int tq=0;tq<8;++tq){
        float sc[8], mx=-3.4e38f; for(int tk=0;tk<8;++tk){float s=0;for(int d=0;d<8;++d)s+=w->q[hd][tq][d]*w->k[hd][tk][d];s*=scale;sc[tk]=s;if(s>mx)mx=s;}
        float den=0,pr[8];for(int tk=0;tk<8;++tk){pr[tk]=exp_neg(sc[tk]-mx);den+=pr[tk];}
        float inv=1.0f/den;for(int d=0;d<8;++d){float s=0;for(int tk=0;tk<8;++tk)s+=(pr[tk]*inv)*w->v[hd][tk][d];w->attcat[tq][hd*8+d]=s;}
    }}
    for(int t=0;t<8;++t){linear(q->ow,q->ob,w->attcat[t],w->tmp[t],16,16);for(int j=0;j<16;++j)w->h[t][j]+=w->tmp[t][j];}
    for(int t=0;t<8;++t){layernorm(w->h[t],w->x[t],q->n2w,q->n2b);linear(q->aw,q->ab,w->x[t],w->ff[t],32,16);for(int j=0;j<32;++j)w->ff[t][j]=gelu(w->ff[t][j]);linear(q->bw,q->bb,w->ff[t],w->tmp[t],16,32);for(int j=0;j<16;++j)w->h[t][j]+=0.35f*w->tmp[t][j];}
}
static void finish(const RTNNRealSequenceWorkspace* w,uint8_t e,float z[10]) {
    float m[16]={0};for(int t=0;t<8;++t)for(int j=0;j<16;++j)m[j]+=w->h[t][j]*0.125f;linear(HW[e].w,HW[e].b,m,z,10,16);
}
static float entropy10(const float z[10]) {
    float mx=z[0];for(int i=1;i<10;++i)if(z[i]>mx)mx=z[i];float p[10],den=0;for(int i=0;i<10;++i){p[i]=exp_neg(z[i]-mx);den+=p[i];}
    float inv=1.0f/den, h=0.0f;
    float y=(den-1.0f)/(den+1.0f), y2=y*y, term=y, l=0.0f;
    for(int n=1;n<=19;n+=2){l += term/(float)n; term*=y2;} l*=2.0f;
    for(int i=0;i<10;++i){float pi=p[i]*inv;h += pi*(mx-z[i]);} return h+l;
}
uint8_t rtnn_real_sequence_budget_ceiling_q16(uint16_t b){return (uint8_t)(((uint32_t)b*6u)/65535u);}
uint8_t rtnn_real_sequence_effective_exit_q16(uint16_t b,uint8_t preferred,uint8_t deadline){
    uint8_t c=rtnn_real_sequence_budget_ceiling_q16(b); if(preferred>6u)preferred=0u;if(deadline>6u)deadline=0u;if(preferred<c)c=preferred;if(deadline<c)c=deadline;return c;
}
void rtnn_real_sequence_infer_exit(RTNNRealSequenceWorkspace* w,const uint8_t p[64],uint8_t e,float z[10]){if(e>6u)e=0u;init_state(w,p);for(uint8_t i=0;i<e;++i)run_block(w,i);finish(w,e,z);}
uint8_t rtnn_real_sequence_preferred_exit(RTNNRealSequenceWorkspace* w,const uint8_t p[64]){
    init_state(w,p); float z[10]; finish(w,0,z);
    for(uint8_t e=0;e<RTNN_REAL_SEQUENCE_POLICY_MAX_EXIT;++e){if(entropy10(z)<=RTNN_REAL_SEQUENCE_POLICY_TAU)return e;run_block(w,e);finish(w,e+1,z);}return RTNN_REAL_SEQUENCE_POLICY_MAX_EXIT;
}
void rtnn_real_sequence_infer_budget(RTNNRealSequenceWorkspace* w,const uint8_t p[64],uint16_t b,uint8_t deadline,float z[10],uint8_t* executed){
    uint8_t allowed=rtnn_real_sequence_budget_ceiling_q16(b);
    if(deadline>6u)deadline=0u;
    if(deadline<allowed)allowed=deadline;
    if(RTNN_REAL_SEQUENCE_POLICY_MAX_EXIT<allowed)allowed=RTNN_REAL_SEQUENCE_POLICY_MAX_EXIT;
    init_state(w,p); finish(w,0,z);
    uint8_t e=0u;
    while(e<allowed){
        if(entropy10(z)<=RTNN_REAL_SEQUENCE_POLICY_TAU)break;
        run_block(w,e); ++e; finish(w,e,z);
    }
    if(executed)*executed=e;
}
