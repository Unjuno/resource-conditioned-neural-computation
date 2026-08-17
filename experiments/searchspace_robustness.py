import itertools, json, math, random, time
from dataclasses import dataclass
from pathlib import Path
import torch
import torch.nn as nn
import torch.nn.functional as F

torch.set_num_threads(1)
N_BITS=8; N=1<<N_BITS; H=16
IDX=torch.arange(N); SH=torch.arange(N_BITS)
BITS=((IDX[:,None]>>SH)&1).float(); Y=(BITS[:,0].long()^BITS[:,1].long()^BITS[:,2].long()^BITS[:,3].long())
ANCHORS=[.02,.08,.25,1.,4.,12.5,50.]
BASE_COST=torch.tensor([[.02,.01],[.08,1.],[1.,.10]],dtype=torch.float)

def price(r,scale=.1): return torch.tensor([scale*math.sqrt(r),scale/math.sqrt(r)],dtype=torch.float)
APS=torch.stack([price(r) for r in ANCHORS])
@dataclass
class Config:
    name:str; stages:int; allowed:list; scales:list
CONFIGS={
 's3_hom':Config('s3_hom',3,[[1,1,1]]*3,[[1.,1.]]*3),
 's4_hom':Config('s4_hom',4,[[1,1,1]]*4,[[1.,1.]]*4),
 's4_avail_only':Config('s4_avail_only',4,[[1,1,1],[1,0,1],[1,1,0],[1,1,1]],[[1.,1.]]*4),
 's4_cost_only':Config('s4_cost_only',4,[[1,1,1]]*4,[[1.,1.],[.78,1.18],[1.22,.72],[.92,1.08]]),
 's4_hetero':Config('s4_hetero',4,[[1,1,1],[1,0,1],[1,1,0],[1,1,1]],[[1.,1.],[.78,1.18],[1.22,.72],[.92,1.08]]),
}
class ComputeOp(nn.Module):
    def __init__(self): super().__init__(); self.a=nn.Linear(H,6); self.b=nn.Linear(6,H)
    def forward(self,h):
        for _ in range(3): h=h+self.b(torch.tanh(self.a(h)))
        return torch.tanh(h)
class Stage(nn.Module):
    def __init__(self): super().__init__(); self.lookup=nn.Embedding(N,H); self.compute=ComputeOp()
    def hard(self,h,idx,o):
        if o==0:return h
        if o==1:return torch.tanh(h+self.lookup(idx))
        return self.compute(h)
class Net(nn.Module):
    def __init__(self,c): super().__init__(); self.c=c; self.enc=nn.Linear(N_BITS,H); self.stages=nn.ModuleList([Stage() for _ in range(c.stages)]); self.head=nn.Linear(H,2)
    def forward_topology(self,idx,x,t):
        h=self.enc(x)
        for s,o in enumerate(t): h=self.stages[s].hard(h,idx,int(o))
        return self.head(h)
class AR(nn.Module):
    def __init__(self,c,aware=True):
        super().__init__(); self.c=c; self.aware=aware; self.h=nn.Sequential(nn.Linear(2,24),nn.Tanh()); self.heads=nn.ModuleList()
        for s in range(c.stages):
            if s==0:self.heads.append(nn.Linear(24,3))
            else:self.heads.append(nn.Sequential(nn.Linear(24+3*s,24),nn.Tanh(),nn.Linear(24,3)))
    def feat(self,p):
        z=torch.log(p.clamp_min(1e-8)); z-=z.mean(1,keepdim=True); return z if self.aware else torch.zeros_like(z)
    def logits(self,h,hist,s):
        x=torch.cat([h]+hist,1) if hist else h; z=self.heads[s](x); allow=torch.tensor(self.c.allowed[s],dtype=torch.bool,device=z.device); return z.masked_fill(~allow[None,:],-1e9)
    def logprob_topologies(self,p,topos):
        B=p.size(0); T=len(topos); tidx=torch.tensor(topos,dtype=torch.long,device=p.device); h=self.h(self.feat(p)); total=torch.zeros(B,T,device=p.device)
        for s in range(self.c.stages):
            if s==0:
                inp=h[:,None,:].expand(B,T,24).reshape(B*T,24)
            else:
                hh=h[:,None,:].expand(B,T,24)
                oh=[F.one_hot(tidx[:,j],3).float()[None,:,:].expand(B,T,3) for j in range(s)]
                inp=torch.cat([hh]+oh,-1).reshape(B*T,24+3*s)
            z=self.heads[s](inp).view(B,T,3); allow=torch.tensor(self.c.allowed[s],dtype=torch.bool,device=z.device); z=z.masked_fill(~allow[None,None,:],-1e9); lp=F.log_softmax(z,-1)
            total+=lp.gather(2,tidx[:,s][None,:,None].expand(B,T,1)).squeeze(2)
        return total
    @torch.no_grad()
    def topology(self,p):
        h=self.h(self.feat(p)); hist=[]; out=[]
        for s in range(self.c.stages):
            z=self.logits(h,hist,s); a=z.argmax(1); out.append(int(a[0])); hist.append(F.one_hot(a,3).float())
        return tuple(out)

def topos(c): return list(itertools.product(*[[i for i,v in enumerate(a) if v] for a in c.allowed]))
def singles(c):
    out=[]
    for s in range(c.stages):
        for o in (1,2):
            if c.allowed[s][o]: t=[0]*c.stages; t[s]=o; out.append(tuple(t))
    return out
def cost(c,t,p):
    v=torch.zeros(2)
    for s,o in enumerate(t): v+=BASE_COST[o]*torch.tensor(c.scales[s])
    return float((v*p).sum())
def costs_matrix(c,ts): return torch.stack([torch.tensor([cost(c,t,p) for t in ts]) for p in APS])
@torch.no_grad()
def full_accs(m,ts): return torch.tensor([float((m.forward_topology(IDX,BITS,t).argmax(1)==Y).float().mean()) for t in ts])

def capability_step(m,opt,c,step):
    ss=singles(c); sel=torch.randint(0,N,(256,)); k=min(4,len(ss)); chosen=[ss[(step+2*j)%len(ss)] for j in range(k)]
    loss=sum(F.cross_entropy(m.forward_topology(sel,BITS[sel],t),Y[sel]) for t in chosen)/len(chosen); opt.zero_grad(); loss.backward(); opt.step()

def train(c,seed,steps=1800,threshold=.95,aware=True):
    torch.manual_seed(seed);random.seed(seed); ts=topos(c); ss=singles(c); cm=costs_matrix(c,ts); m=Net(c); r=AR(c,aware); mo=torch.optim.AdamW(m.parameters(),lr=2e-3,weight_decay=1e-6); ro=torch.optim.AdamW(r.parameters(),lr=3.5e-3,weight_decay=1e-6)
    on=False; activated=None; feas=torch.zeros(len(ts))
    for step in range(steps):
        if step%50==0:
            if not on:
                with torch.no_grad():
                    pa=[float((m.forward_topology(IDX,BITS,t).argmax(1)==Y).float().mean()) for t in ss]
                if min(pa)>=threshold:
                    on=True;activated=step;feas=(full_accs(m,ts)==1.).float()
            else:
                feas=(full_accs(m,ts)==1.).float()
        capability_step(m,mo,c,step)
        if on:
            for _ in range(3):
                lp=r.logprob_topologies(APS,ts); q=lp.exp(); ent=-(q*lp).sum(1).mean(); vals=cm+3.*(1-feas)[None,:]; loss=(q*vals).sum(1).mean()-.02*ent; ro.zero_grad(); loss.backward(); ro.step()
    return m.eval(),r.eval(),activated
@torch.no_grad()
def evaluate(m,r,c):
    ts=topos(c); ac=full_accs(m,ts); valid=[t for t,a in zip(ts,ac) if a==1.]; hard=optc=0;reg=0.;used=set()
    for rr in [10**(-2+4*i/399) for i in range(400)]:
        p=price(rr);t=r.topology(p.view(1,2));used.add(t);a=float(ac[ts.index(t)]);hard+=int(a==1.)
        if valid:
            best=min(cost(c,v,p) for v in valid);cc=cost(c,t,p);optc+=int(cc<=best+1e-7);reg+=max(0,cc-best)
    return {'hard_accuracy':hard/400,'tie_optimal_cost_rate':optc/400,'mean_regret':reg/400,'num_routes':len(used),'routes':[list(x) for x in sorted(used)],'num_valid':len(valid),'single_probe_min_accuracy':min(float(ac[ts.index(t)]) for t in singles(c)),'probes':{k:list(r.topology(price(x).view(1,2))) for k,x in [('footprint_expensive',.02),('balanced',1.),('compute_expensive',50.)]}}

def run(name,seed,aware=True):
    c=CONFIGS[name]; t=time.time();m,r,a=train(c,seed,aware=aware);v=evaluate(m,r,c);v['activated_at']=a;v['seconds']=time.time()-t;return v

def aggregate_rows(rows):
    import statistics
    return {
        'mean_hard_accuracy': statistics.mean(r['hard_accuracy'] for r in rows),
        'mean_tie_optimal_cost_rate': statistics.mean(r['tie_optimal_cost_rate'] for r in rows),
        'min_tie_optimal_cost_rate': min(r['tie_optimal_cost_rate'] for r in rows),
        'mean_regret': statistics.mean(r['mean_regret'] for r in rows),
        'seeds_multiple_routes': sum(r['num_routes'] > 1 for r in rows),
        'min_single_probe_accuracy': min(r['single_probe_min_accuracy'] for r in rows),
    }

def public_suite(out_path, seeds=5):
    global ANCHORS, APS
    result={'setup':{
        'task':'4-bit parity over complete 256-state domain',
        'resource_columns':['compute_proxy','active_parameter_footprint_proxy'],
        'router':'capability-gated autoregressive policy with exact expectation over finite search space',
        'boundary':'Search-space and contract robustness diagnostic; not scalable NAS and not physical memory/energy measurement.'},
        'configs':{},'dense_anchor_cost_only':{}}
    for name in ['s3_hom','s4_hom','s4_avail_only','s4_cost_only','s4_hetero']:
        rows=[]
        for seed in range(seeds):
            v=run(name,seed,True); rows.append(v); print(name,seed,v['tie_optimal_cost_rate'],flush=True)
        result['configs'][name]={'seeds':rows,'aggregate':aggregate_rows(rows)}
    old_a,old_p=ANCHORS,APS
    ratios=[10**(-1.69897 + (1.69897+1.69897)*i/20) for i in range(21)]
    ANCHORS=ratios; APS=torch.stack([price(r) for r in ratios])
    rows=[]
    for seed in range(seeds):
        v=run('s4_cost_only',seed,True); rows.append(v); print('dense_anchor',seed,v['tie_optimal_cost_rate'],flush=True)
    result['dense_anchor_cost_only']={'training_anchors':ratios,'seeds':rows,'aggregate':aggregate_rows(rows)}
    ANCHORS,APS=old_a,old_p
    Path(out_path).write_text(json.dumps(result,indent=2)); return result

if __name__=='__main__':
    import argparse
    ap=argparse.ArgumentParser(); ap.add_argument('--config',choices=CONFIGS,default='s3_hom'); ap.add_argument('--seed',type=int,default=0); ap.add_argument('--blind',action='store_true'); ap.add_argument('--suite',action='store_true'); ap.add_argument('--seeds',type=int,default=5); ap.add_argument('--out',default='searchspace_robustness_results.json'); a=ap.parse_args()
    if a.suite:
        public_suite(a.out,a.seeds)
    else:
        v=run(a.config,a.seed,not a.blind); print(json.dumps(v,indent=2)); Path(a.out).write_text(json.dumps(v,indent=2))
