import argparse, json, math, random, statistics, time
from pathlib import Path
import torch
import torch.nn as nn
import torch.nn.functional as F

torch.set_num_threads(1)
try: torch.set_num_interop_threads(1)
except RuntimeError: pass

ROOT=Path(__file__).resolve().parents[1] if Path(__file__).resolve().parent.name=='experiments' else Path('/mnt/data')
L=9; H=24; FF=64; DEPTHS=[0,2,4,6,8]
PRICES=[0.0,0.2,0.3,0.5,0.85,1.0,1.2,1.5,2.0]
X=torch.tensor([[float((s>>i)&1) for i in range(L)] for s in range(512)])
TARGET_WEIGHT=torch.tensor([1.0,.95,.85,.75,.65,.55,.45,.35,.25])

class LocalAttentionMLPBlock(nn.Module):
    def __init__(self):
        super().__init__()
        self.n1=nn.LayerNorm(H); self.q=nn.Linear(H,H); self.k=nn.Linear(H,H); self.v=nn.Linear(H,H); self.o=nn.Linear(H,H)
        self.n2=nn.LayerNorm(H); self.f1=nn.Linear(H,FF); self.f2=nn.Linear(FF,H)
    def forward(self,h):
        x=self.n1(h); q=self.q(x); k=self.k(x); v=self.v(x)
        kr=torch.cat([k[:,1:],k[:,-1:]],1); vr=torch.cat([v[:,1:],v[:,-1:]],1)
        scores=torch.stack([(q*k).sum(-1),(q*kr).sum(-1)],-1)/math.sqrt(H)
        a=torch.softmax(scores,-1); ctx=a[...,0,None]*v+a[...,1,None]*vr
        h=h+self.o(ctx)
        return h+0.25*self.f2(F.gelu(self.f1(self.n2(h))))

class PriceConditionedSequenceNet(nn.Module):
    def __init__(self,price_visible=True):
        super().__init__(); self.price_visible=price_visible
        self.emb=nn.Embedding(2,H); self.pos=nn.Parameter(torch.randn(L,H)*.02)
        self.blocks=nn.ModuleList([LocalAttentionMLPBlock() for _ in range(8)])
        self.head=nn.Linear(H,L)
        self.controller=nn.Sequential(nn.Linear(2,24),nn.Tanh(),nn.Linear(24,len(DEPTHS)))
    def base(self,x): return self.emb(x.long())+self.pos[None]
    def all_depth_logits(self,x):
        h=self.base(x); outs={0:self.head(h[:,0])}
        for i,b in enumerate(self.blocks,1):
            h=b(h)
            if i in DEPTHS: outs[i]=self.head(h[:,0])
        return torch.stack([outs[d] for d in DEPTHS],1)
    def per_example_loss(self,z,y):
        b=F.binary_cross_entropy_with_logits(z,y[:,None,:].expand_as(z),reduction='none')
        return (b*TARGET_WEIGHT[None,None,:]).sum(-1)/TARGET_WEIGHT.sum()
    def controller_logits(self,price,cap=8):
        p=torch.as_tensor(price,dtype=torch.float32); p=p[None] if p.ndim==0 else p
        c=torch.as_tensor(cap,dtype=torch.float32); c=c[None] if c.ndim==0 else c
        if c.numel()==1 and p.numel()>1: c=c.expand_as(p)
        x=torch.stack([torch.log1p(p),c/8.0],1)
        if not self.price_visible: x[:,0]=0.0
        return self.controller(x)
    @torch.no_grad()
    def choose_depth(self,price,cap=8):
        logits=self.controller_logits(torch.tensor([price]),torch.tensor([cap]))[0].clone()
        for i,d in enumerate(DEPTHS):
            if d>cap: logits[i]=-1e9
        return DEPTHS[int(logits.argmax())]
    @torch.no_grad()
    def hard(self,x,price,cap=8):
        d=self.choose_depth(price,cap); h=self.base(x)
        for i in range(d): h=self.blocks[i](h)
        return self.head(h[:,0]),d
    @torch.no_grad()
    def dense_equivalent(self,x,price,cap=8):
        d=self.choose_depth(price,cap); h=self.base(x)
        for i,b in enumerate(self.blocks):
            cand=b(h)
            if i<d: h=cand
        return self.head(h[:,0]),d

def train(seed,price_visible=True,capability_steps=500,cost_scale=.7):
    torch.manual_seed(seed); random.seed(seed); m=PriceConditionedSequenceNet(price_visible)
    cap=[p for n,p in m.named_parameters() if not n.startswith('controller.')]
    opt=torch.optim.AdamW(cap,lr=2e-3,weight_decay=1e-5); g=torch.Generator().manual_seed(44+seed)
    for _ in range(capability_steps):
        ix=torch.randint(0,512,(128,),generator=g); z=m.all_depth_logits(X[ix]); loss=m.per_example_loss(z,X[ix]).mean()
        opt.zero_grad(); loss.backward(); torch.nn.utils.clip_grad_norm_(cap,5); opt.step()
    with torch.no_grad():
        z=m.all_depth_logits(X); mean_ce=m.per_example_loss(z,X).mean(0); d=torch.tensor(DEPTHS,dtype=mean_ce.dtype)
        prices=torch.linspace(0,2.0,201)
        pp=[];cc=[];tt=[]
        for cap in DEPTHS:
            energy=mean_ce[None,:]+cost_scale*prices[:,None]*d[None,:]/8
            energy[:,d>cap]=1e6
            pp.append(prices); cc.append(torch.full_like(prices,float(cap))); tt.append(energy.argmin(1))
        pp=torch.cat(pp);cc=torch.cat(cc);target=torch.cat(tt)
    optc=torch.optim.AdamW(m.controller.parameters(),lr=5e-3)
    for _ in range(800):
        logits=m.controller_logits(pp,cc); loss=F.cross_entropy(logits,target); optc.zero_grad(); loss.backward(); optc.step()
    return m.eval(),mean_ce.detach()

def pct(v,p):
    s=sorted(v); return s[min(len(s)-1,max(0,math.ceil(p*len(s))-1))]

def fixed_depth_audit(m):
    with torch.no_grad(): z=m.all_depth_logits(X)
    out={}
    for i,d in enumerate(DEPTHS):
        pred=(z[:,i]>0).float(); out[str(d)]={
            'bit_accuracy':float((pred==X).float().mean()),
            'weighted_bit_accuracy':float((((pred==X).float()*TARGET_WEIGHT).sum(1)/TARGET_WEIGHT.sum()).mean()),
            'weighted_bce':float(m.per_example_loss(z[:,i:i+1],X).mean())
        }
    return out

def price_sweep(m):
    out={}
    with torch.no_grad():
        for p in PRICES:
            z,d=m.hard(X,p); pred=(z>0).float(); out[str(p)]={'depth':d,'bit_accuracy':float((pred==X).float().mean()),'weighted_bit_accuracy':float((((pred==X).float()*TARGET_WEIGHT).sum(1)/TARGET_WEIGHT.sum()).mean())}
    return out

def timing_audit(m,reps=100):
    rng=random.Random(700); out={}
    with torch.no_grad():
        for p in PRICES:
            hard=[];dense=[]
            for _ in range(20): j=rng.randrange(512);m.hard(X[j:j+1],p);m.dense_equivalent(X[j:j+1],p)
            for _ in range(reps):
                j=rng.randrange(512);t=time.perf_counter_ns();m.hard(X[j:j+1],p);hard.append((time.perf_counter_ns()-t)/1000)
                t=time.perf_counter_ns();m.dense_equivalent(X[j:j+1],p);dense.append((time.perf_counter_ns()-t)/1000)
            out[str(p)]={'depth':m.choose_depth(p),'hard_median_us':statistics.median(hard),'hard_p95_us':pct(hard,.95),'dense_median_us':statistics.median(dense)}
    return out

def equivalence(m):
    mm=0;md=0.0
    with torch.no_grad():
        for p in [0,.5,.7,1,1.5]:
            for j in range(50):
                a,_=m.hard(X[j:j+1],p);b,_=m.dense_equivalent(X[j:j+1],p);mm+=int(not torch.equal(a>0,b>0));md=max(md,float((a-b).abs().max()))
    return {'cases':250,'prediction_vector_mismatches':mm,'max_logit_abs_diff':md}

def hook_counterfactual(m,input_index=173):
    rows=[]
    for p in [0,.5,.7,1,1.5]:
        hits=[];hs=[b.register_forward_hook(lambda mod,inp,out,j=j:hits.append(j)) for j,b in enumerate(m.blocks)]
        try: z,d=m.hard(X[input_index:input_index+1],p)
        finally:
            for h in hs:h.remove()
        rows.append({'price':p,'depth':d,'hook_blocks':hits,'predicted_bits':(z[0]>0).int().tolist(),'target_bits':X[input_index].int().tolist()})
    return rows

def loss_oracle(fixed,sweep,cost_scale=.7):
    rows=[];agree=0
    for p in PRICES:
        energy={d:fixed[str(d)]['weighted_bce']+cost_scale*p*d/8 for d in DEPTHS};oracle=min(DEPTHS,key=lambda d:energy[d]);chosen=sweep[str(p)]['depth'];agree+=int(oracle==chosen);rows.append({'price':p,'oracle_depth':oracle,'chosen_depth':chosen})
    return {'agreement_count':agree,'total':len(PRICES),'rows':rows}

def cap_price_audit(m):
    out={}
    for cap in DEPTHS:
        out[str(cap)]={}
        for p in [0.2,0.5,0.7,1.0,1.5]:
            d=m.choose_depth(p,cap);out[str(cap)][str(p)]={'depth':d,'within_cap':d<=cap}
    return out

def cap_hook_audit(m,input_index=173):
    rows=[]
    for cap,p in [(8,.2),(6,.2),(4,.2),(4,.7),(2,.2),(2,1.0),(0,.2)]:
        hits=[];hs=[b.register_forward_hook(lambda mod,inp,out,j=j:hits.append(j)) for j,b in enumerate(m.blocks)]
        try:z,d=m.hard(X[input_index:input_index+1],p,cap)
        finally:
            [h.remove() for h in hs]
        rows.append({'cap':cap,'price':p,'depth':d,'hook_blocks':hits,'cap_respected':d<=cap})
    return rows

def run(seed,mode='aware',reps=100):
    m,_=train(seed,mode=='aware'); fixed=fixed_depth_audit(m);sw=price_sweep(m);out={'seed':seed,'mode':mode,'fixed_depth':fixed,'price_sweep':sw,'loss_oracle':loss_oracle(fixed,sw),'cap_price_audit':cap_price_audit(m),'cap_hook_audit':cap_hook_audit(m)}
    if mode=='aware':out['timing']=timing_audit(m,reps);out['physical_equivalence']=equivalence(m);out['same_input_counterfactual']=hook_counterfactual(m)
    return out

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--seed',type=int,default=0);ap.add_argument('--mode',choices=['aware','blind'],default='aware');ap.add_argument('--timing-reps',type=int,default=100);ap.add_argument('--out');a=ap.parse_args();r=run(a.seed,a.mode,a.timing_reps)
    if a.out:Path(a.out).write_text(json.dumps(r,indent=2))
    print(json.dumps(r,indent=2))
if __name__=='__main__':main()
