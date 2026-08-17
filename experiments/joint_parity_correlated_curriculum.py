import argparse, itertools, json, math, random, time
from pathlib import Path
import torch
import torch.nn as nn
import torch.nn.functional as F

torch.set_num_threads(1)
ROOT=Path(__file__).resolve().parents[1]
DEFAULT_OUT=ROOT/'results'/'joint_parity_correlated_curriculum_results.json'
DEFAULT_THRESH_OUT=ROOT/'results'/'capability_gate_threshold_sweep.json'
N_BITS=8; N=1<<N_BITS; H=16; STAGES=3
IDX=torch.arange(N,dtype=torch.long); SH=torch.arange(N_BITS,dtype=torch.long)
BITS=((IDX[:,None]>>SH)&1).float()
Y=(BITS[:,0].long()^BITS[:,1].long()^BITS[:,2].long()^BITS[:,3].long())
ANCHORS=[0.02,0.08,0.25,1.0,4.0,12.5,50.0]
OP_NAMES=['skip','lookup','compute']
OP_COST=torch.tensor([[0.02,0.01],[0.08,1.0],[1.0,0.10]],dtype=torch.float)
TOPOS=list(itertools.product(range(3),repeat=STAGES)); TIDX=torch.tensor(TOPOS,dtype=torch.long)
SINGLES=[]
for s in range(STAGES):
    for o in (1,2):
        t=[0,0,0]; t[s]=o; SINGLES.append(tuple(t))

def price(ratio,scale=0.1):
    return torch.tensor([scale*math.sqrt(ratio),scale/math.sqrt(ratio)],dtype=torch.float)
APS=torch.stack([price(r) for r in ANCHORS])

def topo_cost_vec(p):
    return torch.stack([(OP_COST[list(t)].sum(0)*p).sum() for t in TOPOS])
COSTS=torch.stack([topo_cost_vec(p) for p in APS])

class ComputeOp(nn.Module):
    def __init__(self):
        super().__init__(); self.a=nn.Linear(H,6); self.b=nn.Linear(6,H)
    def forward(self,h):
        for _ in range(3): h=h+self.b(torch.tanh(self.a(h)))
        return torch.tanh(h)

class Stage(nn.Module):
    def __init__(self):
        super().__init__(); self.lookup=nn.Embedding(N,H); self.compute=ComputeOp()
    def hard(self,h,idx,o):
        if o==0: return h
        if o==1: return torch.tanh(h+self.lookup(idx))
        return self.compute(h)

class Net(nn.Module):
    def __init__(self):
        super().__init__(); self.enc=nn.Linear(N_BITS,H); self.stages=nn.ModuleList([Stage() for _ in range(3)]); self.head=nn.Linear(H,2)
    def forward_topology(self,idx,x,t):
        h=self.enc(x)
        for s,o in enumerate(t): h=self.stages[s].hard(h,idx,int(o))
        return self.head(h)

class FactorizedRouter(nn.Module):
    def __init__(self): super().__init__(); self.net=nn.Sequential(nn.Linear(2,24),nn.Tanh(),nn.Linear(24,9))
    def feat(self,p): z=torch.log(p.clamp_min(1e-8)); return z-z.mean(1,keepdim=True)
    def logprob_topologies(self,p):
        pr=F.softmax(self.net(self.feat(p)).view(-1,3,3),-1); q=torch.ones(p.size(0),len(TOPOS))
        for s in range(3): q*=pr[:,s,TIDX[:,s]]
        return torch.log(q.clamp_min(1e-12))
    @torch.no_grad()
    def topology(self,p): return tuple(int(v) for v in self.net(self.feat(p)).view(-1,3,3).argmax(-1)[0])

class ARRouter(nn.Module):
    def __init__(self,price_aware=True):
        super().__init__(); self.price_aware=price_aware; self.h=nn.Sequential(nn.Linear(2,24),nn.Tanh()); self.s0=nn.Linear(24,3)
        self.s1=nn.Sequential(nn.Linear(27,24),nn.Tanh(),nn.Linear(24,3)); self.s2=nn.Sequential(nn.Linear(30,24),nn.Tanh(),nn.Linear(24,3))
    def feat(self,p):
        z=torch.log(p.clamp_min(1e-8)); z=z-z.mean(1,keepdim=True)
        return z if self.price_aware else torch.zeros_like(z)
    def logprob_topologies(self,p):
        B=p.size(0); h=self.h(self.feat(p)); lp0=F.log_softmax(self.s0(h),-1)
        o0=F.one_hot(TIDX[:,0],3).float(); o1=F.one_hot(TIDX[:,1],3).float()
        hh=h[:,None,:].expand(B,len(TOPOS),24)
        o0b=o0[None,:,:].expand(B,len(TOPOS),3); o1b=o1[None,:,:].expand(B,len(TOPOS),3)
        lp1=F.log_softmax(self.s1(torch.cat([hh,o0b],-1).reshape(B*len(TOPOS),27)),-1).view(B,len(TOPOS),3)
        lp2=F.log_softmax(self.s2(torch.cat([hh,o0b,o1b],-1).reshape(B*len(TOPOS),30)),-1).view(B,len(TOPOS),3)
        return lp0[:,TIDX[:,0]] + lp1.gather(2,TIDX[:,1][None,:,None].expand(B,-1,1)).squeeze(2) + lp2.gather(2,TIDX[:,2][None,:,None].expand(B,-1,1)).squeeze(2)
    @torch.no_grad()
    def topology(self,p):
        h=self.h(self.feat(p)); a=int(self.s0(h).argmax(1)[0]); o0=F.one_hot(torch.tensor([a]),3).float()
        b=int(self.s1(torch.cat([h,o0],1)).argmax(1)[0]); o1=F.one_hot(torch.tensor([b]),3).float()
        c=int(self.s2(torch.cat([h,o0,o1],1)).argmax(1)[0]); return (a,b,c)

@torch.no_grad()
def full_accs(m):
    return torch.tensor([float((m.forward_topology(IDX,BITS,t).argmax(1)==Y).float().mean()) for t in TOPOS])

@torch.no_grad()
def probe_accs(m):
    a=full_accs(m); return {str(t):float(a[TOPOS.index(t)]) for t in SINGLES}

def capability_step(m,opt,step,include_router_route=None):
    sel=torch.randint(0,N,(256,)); loss=0.0
    chosen=[SINGLES[(step+2*j)%6] for j in range(3)]
    for t in chosen: loss=loss+F.cross_entropy(m.forward_topology(sel,BITS[sel],t),Y[sel])/3
    if include_router_route is not None:
        loss=0.85*loss+0.15*F.cross_entropy(m.forward_topology(sel,BITS[sel],include_router_route),Y[sel])
    opt.zero_grad(); loss.backward(); opt.step(); return float(loss.detach())

def router_step(router,opt,feasible,binary=True,confidence_penalty=None,steps=1):
    for _ in range(steps):
        lp=router.logprob_topologies(APS); q=lp.exp(); ent=-(q*lp).sum(1).mean()
        if binary:
            values=COSTS+3.0*(1-feasible)[None,:]
        else:
            values=COSTS+confidence_penalty[None,:]
        loss=(q*values).sum(1).mean()-0.02*ent
        opt.zero_grad(); loss.backward(); opt.step()
    return float(loss.detach())

@torch.no_grad()
def evaluate(m,r):
    acc=full_accs(m); valid=[TOPOS[i] for i,a in enumerate(acc) if a==1.0]
    full=optc=0; regret=0.0; used=set(); dense=[10**(-2+4*i/399) for i in range(400)]
    for ratio in dense:
        p=price(ratio); t=r.topology(p.view(1,2)); used.add(t); a=float(acc[TOPOS.index(t)]); full+=int(a==1.0)
        if valid:
            best=min(float((OP_COST[list(v)].sum(0)*p).sum()) for v in valid)
            c=float((OP_COST[list(t)].sum(0)*p).sum()); optc+=int(c<=best+1e-7); regret+=max(0,c-best)
    probes={k:list(r.topology(price(x).view(1,2))) for k,x in [('footprint_expensive',0.02),('balanced',1.0),('compute_expensive',50.0)]}
    return {'hard_accuracy':full/400,'tie_optimal_cost_rate':optc/400,'mean_regret':regret/400,'num_routes':len(used),'routes':[list(t) for t in sorted(used)],'probe_accs':probe_accs(m),'probes':probes,'num_feasible_topologies':len(valid)}

def train(seed,mode,total_steps=1600,gate_threshold=1.0):
    torch.manual_seed(seed); random.seed(seed)
    m=Net(); r=(ARRouter(price_aware=('blind' not in mode)) if 'ar' in mode else FactorizedRouter())
    mop=torch.optim.AdamW(m.parameters(),lr=2e-3,weight_decay=1e-6); rop=torch.optim.AdamW(r.parameters(),lr=3.5e-3,weight_decay=1e-6)
    router_on=(mode in ('joint_ar','joint_factorized'))
    activated_at=0 if router_on else None
    last_feas=torch.zeros(len(TOPOS))
    for step in range(total_steps):
        audit_period = 50 if not router_on else 100
        if step%audit_period==0:
            with torch.no_grad():
                if not router_on:
                    pa=[]
                    for t in SINGLES: pa.append(float((m.forward_topology(IDX,BITS,t).argmax(1)==Y).float().mean()))
                    minprobe=min(pa)
                else:
                    acc=full_accs(m); last_feas=(acc==1.0).float(); minprobe=min(float(acc[TOPOS.index(t)]) for t in SINGLES)
            if mode in ('gated_ar','gated_factorized','constrained_ar','constrained_ar_blind') and not router_on and minprobe>=gate_threshold:
                router_on=True; activated_at=step
                with torch.no_grad():
                    acc=full_accs(m); last_feas=(acc==1.0).float()
        route=None
        if router_on:
            ratio=ANCHORS[step%len(ANCHORS)]; route=r.topology(price(ratio).view(1,2))
        capability_step(m,mop,step,route)
        if router_on:
            router_step(r,rop,last_feas,binary=True,steps=(3 if mode in ('constrained_ar','constrained_ar_blind') else 1))
    return m.eval(),r.eval(),activated_at

def run_seed(seed):
    modes=['joint_factorized','joint_ar','gated_factorized','gated_ar','constrained_ar','constrained_ar_blind']
    out={'seed':seed,'modes':{}}
    for mode in modes:
        t0=time.time(); m,r,act=train(seed,mode); ev=evaluate(m,r); ev['router_activated_at']=act; ev['seconds']=time.time()-t0
        out['modes'][mode]=ev
        print(seed,mode,ev['hard_accuracy'],ev['tie_optimal_cost_rate'],ev['num_routes'],act,flush=True)
    return out

def aggregate(rows):
    modes=rows[0]['modes']; out={}
    for mode in modes:
        vals=[r['modes'][mode] for r in rows]
        out[mode]={
            'mean_hard_accuracy':sum(v['hard_accuracy'] for v in vals)/len(vals),
            'min_hard_accuracy':min(v['hard_accuracy'] for v in vals),
            'mean_tie_optimal_cost_rate':sum(v['tie_optimal_cost_rate'] for v in vals)/len(vals),
            'min_tie_optimal_cost_rate':min(v['tie_optimal_cost_rate'] for v in vals),
            'mean_regret':sum(v['mean_regret'] for v in vals)/len(vals),
            'seeds_using_multiple_routes':sum(v['num_routes']>1 for v in vals),
            'seeds_all_probes_perfect':sum(min(v['probe_accs'].values())==1.0 for v in vals),
        }
    return out

def suite(out_path,seeds=5):
    rows=[run_seed(s) for s in range(seeds)]
    result={'setup':{'task':'4-bit parity over 256 states','freeze_used':False,'complete_route_labels_used':False,
                     'primitive_capability_insurance':'rotating task loss over six single-primitive probes throughout training',
                     'router':'factorized or autoregressive','feasibility':'periodic exact finite-domain binary feasibility mask for router objective',
                     'boundary':'Capability-gated modes delay resource optimization until all six single-primitive probes are exactly correct; capability weights are never frozen.'},
            'seeds':rows,'aggregate':aggregate(rows)}
    Path(out_path).write_text(json.dumps(result,indent=2)); return result

def threshold_sweep(out_path=DEFAULT_THRESH_OUT,seeds=3):
    thresholds=[0.0,0.8,0.9,0.95,0.99,1.0]
    rows={}; summary={}
    for th in thresholds:
        rr=[]
        for seed in range(seeds):
            m,r,a=train(seed,'constrained_ar',gate_threshold=th); v=evaluate(m,r)
            rr.append({'seed':seed,'activation':a,'hard_accuracy':v['hard_accuracy'],
                       'tie_optimal_cost_rate':v['tie_optimal_cost_rate'],
                       'mean_regret':v['mean_regret'],'num_routes':v['num_routes']})
            print('threshold',th,'seed',seed,'activation',a,'accuracy',v['hard_accuracy'],
                  'optimal',v['tie_optimal_cost_rate'],flush=True)
        rows[str(th)]=rr
        summary[str(th)]={'mean_optimal_cost_rate':sum(x['tie_optimal_cost_rate'] for x in rr)/len(rr),
                          'min_optimal_cost_rate':min(x['tie_optimal_cost_rate'] for x in rr),
                          'mean_hard_accuracy':sum(x['hard_accuracy'] for x in rr)/len(rr),
                          'activations':[x['activation'] for x in rr]}
    result={'setup':{'task':'4-bit parity','seeds':seeds,
                     'question':'How much capability readiness is needed before resource optimization becomes stable?',
                     'boundary':'Threshold is measured on six single-primitive probes; capability parameters are never frozen.'},
            'rows':rows,'summary':summary}
    Path(out_path).write_text(json.dumps(result,indent=2)); return result

if __name__=='__main__':
    ap=argparse.ArgumentParser(); ap.add_argument('--seed',type=int,default=0); ap.add_argument('--suite',action='store_true'); ap.add_argument('--threshold-sweep',action='store_true'); ap.add_argument('--seeds',type=int,default=5); ap.add_argument('--out',default=str(DEFAULT_OUT)); a=ap.parse_args()
    if a.threshold_sweep:
        threshold_sweep(DEFAULT_THRESH_OUT,3 if a.seeds==5 else a.seeds)
    elif a.suite:
        suite(a.out,a.seeds)
    else:
        print(json.dumps(run_seed(a.seed),indent=2))
