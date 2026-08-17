"""Matched audit of router-parameterization sensitivity on the public s4_hom toy.

The baseline intentionally mirrors experiments/searchspace_robustness.py. Two
one-variable ablations change either the capability-probe sampling stride or the
AR router head parameterization. This is a diagnostic, not a new architecture.
"""
import argparse, itertools, json, math, random
from pathlib import Path
import torch
import torch.nn as nn
import torch.nn.functional as F

torch.set_num_threads(1)
ROOT=Path(__file__).resolve().parents[1]
DEFAULT_OUT=ROOT/'results'/'router_parameterization_sensitivity_results.json'
N_BITS=8; N=1<<N_BITS; H=16
IDX=torch.arange(N); SH=torch.arange(N_BITS)
BITS=((IDX[:,None]>>SH)&1).float(); Y=BITS[:,0].long()^BITS[:,1].long()^BITS[:,2].long()^BITS[:,3].long()
ANCHORS=[.02,.08,.25,1.,4.,12.5,50.]
BASE_COST=torch.tensor([[.02,.01],[.08,1.],[1.,.10]],dtype=torch.float)
TOPOS=list(itertools.product(range(3),repeat=4)); TIDX=torch.tensor(TOPOS,dtype=torch.long)
SINGLES=[]
for s in range(4):
    for o in (1,2):
        t=[0]*4;t[s]=o;SINGLES.append(tuple(t))

def price(r,scale=.1): return torch.tensor([scale*math.sqrt(r),scale/math.sqrt(r)],dtype=torch.float)
APS=torch.stack([price(r) for r in ANCHORS])
COSTS=torch.stack([torch.tensor([float((BASE_COST[list(t)].sum(0)*p).sum()) for t in TOPOS]) for p in APS])

class ComputeOp(nn.Module):
    def __init__(self):super().__init__();self.a=nn.Linear(H,6);self.b=nn.Linear(6,H)
    def forward(self,h):
        for _ in range(3):h=h+self.b(torch.tanh(self.a(h)))
        return torch.tanh(h)
class Stage(nn.Module):
    def __init__(self):super().__init__();self.lookup=nn.Embedding(N,H);self.compute=ComputeOp()
    def hard(self,h,idx,o):
        if o==0:return h
        if o==1:return torch.tanh(h+self.lookup(idx))
        return self.compute(h)
class Net(nn.Module):
    def __init__(self):super().__init__();self.enc=nn.Linear(N_BITS,H);self.stages=nn.ModuleList([Stage() for _ in range(4)]);self.head=nn.Linear(H,2)
    def forward_topology(self,idx,x,t):
        h=self.enc(x)
        for s,o in enumerate(t):h=self.stages[s].hard(h,idx,int(o))
        return self.head(h)

class ExistingAR(nn.Module):
    def __init__(self):
        super().__init__();self.h=nn.Sequential(nn.Linear(2,24),nn.Tanh());self.heads=nn.ModuleList()
        for s in range(4):
            if s==0:self.heads.append(nn.Linear(24,3))
            else:self.heads.append(nn.Sequential(nn.Linear(24+3*s,24),nn.Tanh(),nn.Linear(24,3)))
    def feat(self,p):z=torch.log(p.clamp_min(1e-8));return z-z.mean(1,keepdim=True)
    def logprob(self,p):
        B,T=p.size(0),len(TOPOS);h=self.h(self.feat(p));total=torch.zeros(B,T)
        for s in range(4):
            if s==0:inp=h[:,None,:].expand(B,T,24).reshape(B*T,24)
            else:
                hh=h[:,None,:].expand(B,T,24);oh=[F.one_hot(TIDX[:,j],3).float()[None].expand(B,T,3) for j in range(s)];inp=torch.cat([hh]+oh,-1).reshape(B*T,24+3*s)
            lp=F.log_softmax(self.heads[s](inp).view(B,T,3),-1);total+=lp.gather(2,TIDX[:,s][None,:,None].expand(B,T,1)).squeeze(2)
        return total
    @torch.no_grad()
    def topology(self,p):
        h=self.h(self.feat(p));hist=[];out=[]
        for s in range(4):
            z=self.heads[s](torch.cat([h]+hist,1) if hist else h);a=z.argmax(1);out.append(int(a[0]));hist.append(F.one_hot(a,3).float())
        return tuple(out)

class GenericAR(ExistingAR):
    def __init__(self):
        nn.Module.__init__(self);self.h=nn.Sequential(nn.Linear(2,24),nn.Tanh());self.heads=nn.ModuleList([nn.Sequential(nn.Linear(24+3*s,24),nn.Tanh(),nn.Linear(24,3)) for s in range(4)])

def full_accs(m):
    with torch.no_grad():return torch.tensor([float((m.forward_topology(IDX,BITS,t).argmax(1)==Y).float().mean()) for t in TOPOS])
def train(seed,router_kind='existing',stride=2):
    torch.manual_seed(seed);random.seed(seed);m=Net();r=ExistingAR() if router_kind=='existing' else GenericAR();mo=torch.optim.AdamW(m.parameters(),lr=2e-3,weight_decay=1e-6);ro=torch.optim.AdamW(r.parameters(),lr=3.5e-3,weight_decay=1e-6);on=False;feas=torch.zeros(len(TOPOS))
    for step in range(1800):
        if step%50==0:
            if not on:
                with torch.no_grad():pa=[float((m.forward_topology(IDX,BITS,t).argmax(1)==Y).float().mean()) for t in SINGLES]
                if min(pa)>=.95:on=True;feas=(full_accs(m)==1.).float()
            else:feas=(full_accs(m)==1.).float()
        sel=torch.randint(0,N,(256,));chosen=[SINGLES[(step+stride*j)%len(SINGLES)] for j in range(4)];loss=sum(F.cross_entropy(m.forward_topology(sel,BITS[sel],t),Y[sel]) for t in chosen)/4;mo.zero_grad();loss.backward();mo.step()
        if on:
            vals=COSTS+3*(1-feas)[None,:]
            for _ in range(3):
                lp=r.logprob(APS);q=lp.exp();ent=-(q*lp).sum(1).mean();L=(q*vals).sum(1).mean()-.02*ent;ro.zero_grad();L.backward();ro.step()
    ac=full_accs(m);valid=[t for t,a in zip(TOPOS,ac) if a==1.];hit=0;reg=0.;hard=0
    for rr in [10**(-2+4*i/399) for i in range(400)]:
        p=price(rr);t=r.topology(p.view(1,2));hard+=int(float(ac[TOPOS.index(t)])==1.);best=min(float((BASE_COST[list(v)].sum(0)*p).sum()) for v in valid);c=float((BASE_COST[list(t)].sum(0)*p).sum());hit+=int(c<=best+1e-7);reg+=max(0,c-best)
    return {'seed':seed,'hard_accuracy':hard/400,'tie_optimal_cost_rate':hit/400,'mean_regret':reg/400}
CONDITIONS={'matched_baseline':('existing',2),'capability_stride_only':('existing',3),'router_head_only':('generic',2)}
def suite(out=DEFAULT_OUT,seeds=5):
    R={'setup':{'task':'public s4_hom 4-bit-parity condition','purpose':'one-variable implementation-sensitivity audit','boundary':'not a search-space scaling result'},'conditions':{}}
    for name,(rk,st) in CONDITIONS.items():
        rows=[train(s,rk,st) for s in range(seeds)];R['conditions'][name]={'seeds':rows,'aggregate':{'mean_optimal':sum(x['tie_optimal_cost_rate'] for x in rows)/seeds,'min_optimal':min(x['tie_optimal_cost_rate'] for x in rows),'mean_hard_accuracy':sum(x['hard_accuracy'] for x in rows)/seeds,'mean_regret':sum(x['mean_regret'] for x in rows)/seeds}};print(name,R['conditions'][name]['aggregate'],flush=True)
    Path(out).write_text(json.dumps(R,indent=2));return R
if __name__=='__main__':
    ap=argparse.ArgumentParser();ap.add_argument('--out',default=str(DEFAULT_OUT));ap.add_argument('--seeds',type=int,default=5);a=ap.parse_args();suite(a.out,a.seeds)
