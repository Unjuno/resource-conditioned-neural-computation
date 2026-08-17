"""Router-parameterization audit after capability is held fixed.

This is a diagnostic, not the main topology-discovery training recipe. It isolates
allocation from capability acquisition on the harder 4-bit-parity toy. All six
single-primitive probe topologies are first trained to exact full-domain accuracy.
The resulting capability snapshot is then frozen while several resource routers
optimize the same supplied 27-topology search space.
"""
import argparse, json, random
from pathlib import Path
import torch
import torch.nn as nn
import torch.nn.functional as F
import topology_search_discovery as base

torch.set_num_threads(1)
ROOT=Path(__file__).resolve().parents[1]
DEFAULT_OUT=ROOT/'results'/'router_stabilization_audit_results.json'
TOPOS=base.TOPOLOGIES
TIDX=torch.tensor(TOPOS,dtype=torch.long)
APS=torch.stack([base.price(r) for r in base.ANCHORS])

def forward_topology_grad(m,idx,x,t):
    h=m.enc(x)
    for s,o in enumerate(t): h=m.stages[s].hard(h,idx,int(o))
    return m.head(h)

def train_capabilities(seed,steps=1500):
    y=base.labels('parity4'); torch.manual_seed(seed); random.seed(seed); m=base.SearchNet(True)
    pars=[p for n,p in m.named_parameters() if not n.startswith('router.')]
    opt=torch.optim.AdamW(pars,lr=2e-3,weight_decay=1e-6)
    singles=[]
    for s in range(3):
        for o in [1,2]:
            t=[0,0,0]; t[s]=o; singles.append(tuple(t))
    for step in range(steps):
        sel=torch.randint(0,base.N,(256,))
        chosen=[singles[(step+2*j)%6] for j in range(3)]
        loss=sum(F.cross_entropy(forward_topology_grad(m,sel,base.BITS[sel],t),y[sel]) for t in chosen)/3
        opt.zero_grad(); loss.backward(); opt.step()
    return m.eval(),singles

def capability_snapshot(m):
    y=base.labels('parity4'); acc=[]; margins=[]
    with torch.no_grad():
        for t in TOPOS:
            log=forward_topology_grad(m,base.IDX,base.BITS,t); pred=log.argmax(1)
            acc.append(float((pred==y).float().mean()))
            cor=log.gather(1,y[:,None]).squeeze(1); oth=log.gather(1,(1-y)[:,None]).squeeze(1)
            margins.append(float(F.relu(0.8-(cor-oth)).mean()))
    feasible=torch.tensor([a==1.0 for a in acc],dtype=torch.float)
    costs=torch.stack([torch.tensor([(base.OP_COST[list(t)].sum(0)*p).sum() for t in TOPOS]) for p in APS])
    return acc,torch.tensor(margins),feasible,costs

class FactorizedRouter(nn.Module):
    def __init__(self): super().__init__(); self.net=nn.Sequential(nn.Linear(2,24),nn.Tanh(),nn.Linear(24,9))
    def feat(self,p): z=torch.log(p.clamp_min(1e-8)); return z-z.mean(1,keepdim=True)
    def stage_prob(self,p): return F.softmax(self.net(self.feat(p)).view(-1,3,3),dim=-1)
    def logprob_topologies(self,p):
        pr=self.stage_prob(p); q=torch.ones(p.size(0),len(TOPOS))
        for s in range(3): q*=pr[:,s,TIDX[:,s]]
        return torch.log(q.clamp_min(1e-12))
    @torch.no_grad()
    def topology(self,p): return tuple(int(v) for v in self.net(self.feat(p)).view(-1,3,3).argmax(-1)[0])

class FlatRouter(nn.Module):
    def __init__(self): super().__init__(); self.net=nn.Sequential(nn.Linear(2,32),nn.Tanh(),nn.Linear(32,len(TOPOS)))
    def feat(self,p): z=torch.log(p.clamp_min(1e-8)); return z-z.mean(1,keepdim=True)
    def logprob_topologies(self,p): return F.log_softmax(self.net(self.feat(p)),dim=-1)
    @torch.no_grad()
    def topology(self,p): return TOPOS[int(self.net(self.feat(p)).argmax(1)[0])]

class AutoregressiveRouter(nn.Module):
    def __init__(self):
        super().__init__(); self.h=nn.Sequential(nn.Linear(2,24),nn.Tanh()); self.s0=nn.Linear(24,3)
        self.s1=nn.Sequential(nn.Linear(27,24),nn.Tanh(),nn.Linear(24,3))
        self.s2=nn.Sequential(nn.Linear(30,24),nn.Tanh(),nn.Linear(24,3))
    def feat(self,p): z=torch.log(p.clamp_min(1e-8)); return z-z.mean(1,keepdim=True)
    def logprob_topologies(self,p):
        h=self.h(self.feat(p)); lp0=F.log_softmax(self.s0(h),dim=-1); rows=[]
        for t in TOPOS:
            o0=F.one_hot(torch.full((p.size(0),),t[0],dtype=torch.long),3).float()
            lp1=F.log_softmax(self.s1(torch.cat([h,o0],1)),dim=-1)
            o1=F.one_hot(torch.full((p.size(0),),t[1],dtype=torch.long),3).float()
            lp2=F.log_softmax(self.s2(torch.cat([h,o0,o1],1)),dim=-1)
            rows.append(lp0[:,t[0]]+lp1[:,t[1]]+lp2[:,t[2]])
        return torch.stack(rows,1)
    @torch.no_grad()
    def topology(self,p):
        h=self.h(self.feat(p)); a=int(self.s0(h).argmax(1)[0]); o0=F.one_hot(torch.tensor([a]),3).float()
        b=int(self.s1(torch.cat([h,o0],1)).argmax(1)[0]); o1=F.one_hot(torch.tensor([b]),3).float()
        c=int(self.s2(torch.cat([h,o0,o1],1)).argmax(1)[0]); return (a,b,c)

def train_router(kind,values,seed,steps=700):
    torch.manual_seed(seed); random.seed(seed)
    cls={'factorized':FactorizedRouter,'flat':FlatRouter,'autoregressive':AutoregressiveRouter}[kind]
    r=cls(); opt=torch.optim.AdamW(r.parameters(),lr=3.5e-3,weight_decay=1e-6)
    for step in range(steps):
        lp=r.logprob_topologies(APS); q=lp.exp(); ent=-(q*lp).sum(1).mean()
        loss=(q*values).sum(1).mean()-0.03*max(0.0,1-step/280)*ent
        opt.zero_grad(); loss.backward(); opt.step()
    with torch.no_grad(): objective=float((r.logprob_topologies(APS).exp()*values).sum(1).mean())
    return r.eval(),objective

def evaluate_router(r,acc):
    valid=[t for t,a in zip(TOPOS,acc) if a==1.0]; used=set(); full=optimal=0; regret=0.0
    for ratio in [10**(-2+4*i/399) for i in range(400)]:
        p=base.price(ratio); t=r.topology(p.view(1,2)); used.add(t); full+=int(acc[TOPOS.index(t)]==1.0)
        best=min(base.topo_cost(v,p) for v in valid); c=base.topo_cost(t,p)
        optimal+=int(c<=best+1e-7); regret+=max(0.0,c-best)
    return {'hard_accuracy':full/400,'tie_optimal_cost_rate':optimal/400,'mean_regret':regret/400,
            'num_routes':len(used),
            'probes':{k:list(r.topology(base.price(x).view(1,2))) for k,x in [('footprint_expensive',0.02),('balanced',1.0),('compute_expensive',50.0)]}}

def run_seed(seed):
    m,singles=train_capabilities(seed); acc,margin,feasible,costs=capability_snapshot(m)
    out={'seed':seed,'num_feasible_topologies':int(feasible.sum()),
         'single_probe_accuracy':{str(t):acc[TOPOS.index(t)] for t in singles},'routers':{}}
    binary=costs+3*(1-feasible)[None,:]; confidence=0.60*costs+margin[None,:]
    for name,kind,values in [('factorized_confidence','factorized',confidence),('factorized_binary','factorized',binary),('autoregressive_binary','autoregressive',binary),('flat_binary','flat',binary)]:
        r,obj=train_router(kind,values,1000+seed); e=evaluate_router(r,acc); e['anchor_objective']=obj; out['routers'][name]=e
    candidates=[]
    for k in range(4):
        r,obj=train_router('autoregressive',binary,2000+seed*10+k); candidates.append((obj,r))
    obj,r=min(candidates,key=lambda z:z[0]); e=evaluate_router(r,acc); e['anchor_objective']=obj; e['num_restarts']=4
    out['routers']['autoregressive_multistart4']=e
    return out

def aggregate(rows):
    names=rows[0]['routers']; out={}
    for name in names:
        vals=[r['routers'][name] for r in rows]
        out[name]={'mean_tie_optimal_cost_rate':sum(v['tie_optimal_cost_rate'] for v in vals)/len(vals),
                   'min_tie_optimal_cost_rate':min(v['tie_optimal_cost_rate'] for v in vals),
                   'mean_regret':sum(v['mean_regret'] for v in vals)/len(vals),
                   'mean_hard_accuracy':sum(v['hard_accuracy'] for v in vals)/len(vals)}
    return out

def suite(out_path):
    rows=[]
    for seed in range(5):
        row=run_seed(seed); rows.append(row); print(seed,{k:round(v['tie_optimal_cost_rate'],4) for k,v in row['routers'].items()},flush=True)
    result={'setup':{'task':'4-bit parity over the complete 256-state domain',
                     'purpose':'diagnostic isolation of router optimization after capability acquisition',
                     'all_six_single_primitive_probes_required':True,
                     'resource_objective':['compute_proxy','active_parameter_footprint_proxy'],
                     'boundary':'Capabilities are deliberately trained first and frozen for this audit. This does not demonstrate joint topology discovery.'},
            'seeds':rows,'aggregate':aggregate(rows)}
    Path(out_path).write_text(json.dumps(result,indent=2)); return result

if __name__=='__main__':
    ap=argparse.ArgumentParser(); ap.add_argument('--seed',type=int); ap.add_argument('--suite',action='store_true'); ap.add_argument('--out',default=str(DEFAULT_OUT)); a=ap.parse_args()
    if a.suite: suite(a.out)
    else: print(json.dumps(run_seed(0 if a.seed is None else a.seed),indent=2))
