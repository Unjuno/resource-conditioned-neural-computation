#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <numeric>
#include <random>
#include <sched.h>
#include <string>
#include <sys/mman.h>
#include <sys/resource.h>
#include <vector>

constexpr int L=9,C=32,F=128,K=8;
struct Block {const float *sw,*sb,*nw,*nb,*f1w,*f1b,*f2w,*f2b;};
struct Model {
    std::vector<float>w; const float*emb; Block b[K]; const float*hw; const float*hb;
    const float*take(size_t& o,size_t n){const float*p=w.data()+o;o+=n;return p;}
    bool load(const char*fn){
        std::ifstream f(fn,std::ios::binary); uint32_t n=0; f.read((char*)&n,4); w.resize(n); f.read((char*)w.data(),n*4); if(!f)return false;
        size_t o=0; emb=take(o,2*C);
        for(int k=0;k<K;k++){b[k].sw=take(o,C*C);b[k].sb=take(o,C);b[k].nw=take(o,C*C);b[k].nb=take(o,C);b[k].f1w=take(o,F*C);b[k].f1b=take(o,F);b[k].f2w=take(o,C*F);b[k].f2b=take(o,C);}
        hw=take(o,2*C);hb=take(o,2);return o==w.size();
    }
};
inline float gelu(float x){return .5f*x*(1.f+std::erf(x*.7071067811865475f));}
inline void lin(const float*w,const float*b,const float*x,float*y,int O,int I){for(int o=0;o<O;o++){float s=b[o];for(int i=0;i<I;i++)s+=w[o*I+i]*x[i];y[o]=s;}}
struct Res{float a,b;};
Res infer(const Model&m,uint16_t state,int depth){
    alignas(64) float h[L][C],z[L][C],t[L][F],ff[L][C];
    for(int p=0;p<L;p++){int bit=(state>>p)&1;memcpy(h[p],m.emb+bit*C,C*4);}
    for(int bi=0;bi<depth;bi++){
        auto&q=m.b[bi];
        for(int p=0;p<L;p++){
            float a[C],n[C]; lin(q.sw,q.sb,h[p],a,C,C);
            if(p<L-1)lin(q.nw,q.nb,h[p+1],n,C,C);else memcpy(n,q.nb,C*4);
            for(int j=0;j<C;j++)z[p][j]=std::tanh(a[j]+n[j]);
            lin(q.f1w,q.f1b,z[p],t[p],F,C);for(int j=0;j<F;j++)t[p][j]=gelu(t[p][j]);
            lin(q.f2w,q.f2b,t[p],ff[p],C,F);for(int j=0;j<C;j++)h[p][j]=std::tanh(z[p][j]+.2f*ff[p][j]);
        }
    }
    float y[2];lin(m.hw,m.hb,h[0],y,2,C);return{y[0],y[1]};
}
double q(std::vector<double>v,double p){std::sort(v.begin(),v.end());size_t i=(size_t)std::ceil(p*v.size())-1;if(i>=v.size())i=v.size()-1;return v[i];}
void pin(int cpu){cpu_set_t s;CPU_ZERO(&s);CPU_SET(cpu,&s);sched_setaffinity(0,sizeof(s),&s);}

int main(int argc,char**argv){
    if(argc<2){fprintf(stderr,"usage: %s weights.bin [reps=800] [cpu=0] [mlock_weights=0|1]\n",argv[0]);return 2;}
    int reps=argc>2?atoi(argv[2]):800; int cpu=argc>3?atoi(argv[3]):0; bool dolock=argc>4?atoi(argv[4]):false; pin(cpu);
    Model m;if(!m.load(argv[1])){fprintf(stderr,"weight load failed\n");return 3;}
    int lockok=0;if(dolock){lockok=(mlock(m.w.data(),m.w.size()*sizeof(float))==0);if(!lockok)fprintf(stderr,"mlock errno=%d %s\n",errno,strerror(errno));}
    printf("MEMLOCK requested=%d ok=%d bytes=%zu\n",(int)dolock,lockok,m.w.size()*sizeof(float));
    const int D[5]={0,2,4,6,8}; std::mt19937 rng(12345); std::uniform_int_distribution<int>ud(0,511); volatile double checksum=0;
    for(int d:D){
        for(int i=0;i<1000;i++){auto r=infer(m,ud(rng),d);checksum+=r.a;}
        std::vector<double>us;us.reserve(reps);struct rusage r0{},r1{};getrusage(RUSAGE_SELF,&r0);
        for(int i=0;i<reps;i++){auto t0=std::chrono::steady_clock::now();auto r=infer(m,ud(rng),d);auto t1=std::chrono::steady_clock::now();checksum+=r.a;us.push_back(std::chrono::duration<double,std::micro>(t1-t0).count());}
        getrusage(RUSAGE_SELF,&r1);double mean=std::accumulate(us.begin(),us.end(),0.)/us.size();
        printf("depth=%d macs=%d p50_us=%.6f p95_us=%.6f p99_us=%.6f mean_us=%.6f max_us=%.6f minflt=%ld majflt=%ld nvcsw=%ld nivcsw=%ld\n",d,64+d*92160,q(us,.5),q(us,.95),q(us,.99),mean,*std::max_element(us.begin(),us.end()),r1.ru_minflt-r0.ru_minflt,r1.ru_majflt-r0.ru_majflt,r1.ru_nvcsw-r0.ru_nvcsw,r1.ru_nivcsw-r0.ru_nivcsw);
    }
    fprintf(stderr,"checksum=%f\n",checksum);
}
