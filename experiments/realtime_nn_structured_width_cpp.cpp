#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <vector>

constexpr int L=9,C=32,F=128,K=8;
struct Block{const float *sw,*sb,*nw,*nb,*f1w,*f1b,*f2w,*f2b;};
struct Model{std::vector<float>x;const float*emb;Block b[K];const float*hw,*hb;const float*take(size_t&o,size_t n){const float*p=x.data()+o;o+=n;return p;}bool load(const char*p){std::ifstream f(p,std::ios::binary);uint32_t n=0;f.read((char*)&n,4);if(!f)return false;x.resize(n);f.read((char*)x.data(),n*4);if(!f)return false;size_t o=0;emb=take(o,2*C);for(int k=0;k<K;k++){b[k].sw=take(o,C*C);b[k].sb=take(o,C);b[k].nw=take(o,C*C);b[k].nb=take(o,C);b[k].f1w=take(o,F*C);b[k].f1b=take(o,F);b[k].f2w=take(o,C*F);b[k].f2b=take(o,C);}hw=take(o,2*C);hb=take(o,2);return o==x.size();}};
inline float gelu(float x){return .5f*x*(1.f+std::erf(x*.7071067811865475f));}
inline void lin(const float*w,const float*b,const float*x,float*y,int O,int I,int stride){for(int o=0;o<O;o++){float z=b[o];const float*r=w+o*stride;for(int i=0;i<I;i++)z+=r[i]*x[i];y[o]=z;}}
struct R{float a,b;};
R infer(const Model&m,uint16_t st,int d,int w,bool dense){alignas(64)float h[L][C]={},z[L][C]={},tmp[L][F]={},ff[L][C]={};const int H=dense?C:w,G=dense?F:4*w;for(int p=0;p<L;p++){int bit=(st>>p)&1;for(int j=0;j<H;j++)h[p][j]=(j<w)?m.emb[bit*C+j]:0.f;}for(int bi=0;bi<d;bi++){const auto&q=m.b[bi];for(int p=0;p<L;p++){float a[C]={},n[C]={};lin(q.sw,q.sb,h[p],a,H,H,C);if(p<L-1)lin(q.nw,q.nb,h[p+1],n,H,H,C);else for(int j=0;j<H;j++)n[j]=q.nb[j];for(int j=0;j<H;j++)z[p][j]=(j<w)?std::tanh(a[j]+n[j]):0.f;lin(q.f1w,q.f1b,z[p],tmp[p],G,H,C);for(int j=0;j<G;j++)tmp[p][j]=(j<4*w)?gelu(tmp[p][j]):0.f;lin(q.f2w,q.f2b,tmp[p],ff[p],H,G,F);for(int j=0;j<H;j++)h[p][j]=(j<w)?std::tanh(z[p][j]+.2f*ff[p][j]):0.f;}}float y[2];lin(m.hw,m.hb,h[0],y,2,H,C);return{y[0],y[1]};}
double quant(std::vector<double>v,double p){std::sort(v.begin(),v.end());size_t i=(size_t)(p*v.size());if(i>=v.size())i=v.size()-1;return v[i];}
int main(int argc,char**argv){if(argc<2){std::fprintf(stderr,"usage: %s weights.bin [reps=2500]\n",argv[0]);return 2;}int reps=argc>2?std::atoi(argv[2]):2500;Model m;if(!m.load(argv[1]))return 3;const int ds[5]={0,2,4,6,8},ws[5]={8,8,16,24,32};for(int c=0;c<5;c++){int ok=0;float md=0;for(int s=0;s<512;s++){R a=infer(m,(uint16_t)s,ds[c],ws[c],false),b=infer(m,(uint16_t)s,ds[c],ws[c],true);md=std::max(md,std::max(std::fabs(a.a-b.a),std::fabs(a.b-b.b)));ok+=(a.b>a.a)==(__builtin_popcount((unsigned)s)>=5);}std::printf("class=%d acc=%.9f maxdiff=%g\n",c,ok/512.,md);}volatile float sink=0;for(int c=0;c<5;c++)for(int mode=0;mode<2;mode++){std::vector<double>v;v.reserve(reps);for(int i=0;i<200;i++)sink+=infer(m,(uint16_t)(i&511),ds[c],ws[c],mode).a;for(int i=0;i<reps;i++){auto t=std::chrono::steady_clock::now();sink+=infer(m,(uint16_t)((i*73)&511),ds[c],ws[c],mode).a;auto e=std::chrono::steady_clock::now();v.push_back(std::chrono::duration<double,std::micro>(e-t).count());}std::printf("class=%d mode=%s p50_us=%.6f p95_us=%.6f\n",c,mode?"dense_mask":"slim",quant(v,.5),quant(v,.95));}std::fprintf(stderr,"sink=%f\n",sink);return 0;}
