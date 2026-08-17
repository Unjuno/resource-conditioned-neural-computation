"""Resource-conditioned subgraph discovery inside a supplied supernet search space.

This experiment does NOT claim unconstrained neural architecture discovery. The primitive
operations and a 3-stage supernet are supplied by the experimenter; complete routes are
not enumerated or supervised during training. A price-conditioned router learns one
operation per stage, yielding 3^3=27 possible hard topologies.
"""
import argparse, itertools, json, math, random
from pathlib import Path
import torch
import torch.nn as nn
import torch.nn.functional as F

torch.set_num_threads(1)
BASE = Path(__file__).resolve().parents[1]
DEFAULT_OUT = BASE / 'results' / 'topology_search_discovery_results.json'
N_BITS=8; N=1<<N_BITS; H=16; STAGES=3
IDX=torch.arange(N,dtype=torch.long); SH=torch.arange(N_BITS,dtype=torch.long)
BITS=((IDX[:,None]>>SH)&1).float()
ANCHORS=[0.02,0.08,0.25,1.0,4.0,12.5,50.0]
OP_NAMES=['skip','lookup','compute']
OP_COST=torch.tensor([[0.02,0.01],[0.08,1.0],[1.0,0.10]],dtype=torch.float)
TOPOLOGIES=list(itertools.product(range(3),repeat=STAGES))

def labels(task):
    if task=='xor2': return BITS[:,0].long() ^ BITS[:,1].long()
    if task=='parity4': return BITS[:,0].long() ^ BITS[:,1].long() ^ BITS[:,2].long() ^ BITS[:,3].long()
    raise ValueError(task)

def price(ratio,scale=0.1): return torch.tensor([scale*math.sqrt(ratio),scale/math.sqrt(ratio)],dtype=torch.float)

class ComputeOp(nn.Module):
    def __init__(self):
        super().__init__(); self.a=nn.Linear(H,6); self.b=nn.Linear(6,H)
    def forward(self,h):
        for _ in range(3): h=h+self.b(torch.tanh(self.a(h)))
        return torch.tanh(h)

class Stage(nn.Module):
    def __init__(self):
        super().__init__(); self.lookup=nn.Embedding(N,H); self.compute=ComputeOp()
    def ops(self,h,idx): return [h,torch.tanh(h+self.lookup(idx)),self.compute(h)]
    def hard(self,h,idx,op):
        if op==0: return h
        if op==1: return torch.tanh(h+self.lookup(idx))
        if op==2: return self.compute(h)
        raise ValueError(op)

class SearchNet(nn.Module):
    def __init__(self,price_aware=True):
        super().__init__(); self.price_aware=price_aware
        self.enc=nn.Linear(N_BITS,H); self.stages=nn.ModuleList([Stage() for _ in range(STAGES)]); self.head=nn.Linear(H,2)
        self.router=nn.Sequential(nn.Linear(2,24),nn.Tanh(),nn.Linear(24,STAGES*3))
    def features(self,p):
        z=torch.log(p.clamp_min(1e-8)); z=z-z.mean(1,keepdim=True)
        return z if self.price_aware else torch.zeros_like(z)
    def route_logits(self,p): return self.router(self.features(p)).view(-1,STAGES,3)
    def gates(self,p,tau): return F.gumbel_softmax(self.route_logits(p),tau=tau,hard=True,dim=-1)
    def forward_train(self,idx,x,p,tau):
        h=self.enc(x); g=self.gates(p,tau)
        for s,stage in enumerate(self.stages):
            ops=stage.ops(h,idx); h=sum(g[:,s,k:k+1]*ops[k] for k in range(3))
        return self.head(h),g
    @torch.no_grad()
    def topology(self,p): return tuple(int(v) for v in self.route_logits(p.view(1,2)).argmax(-1)[0])
    @torch.no_grad()
    def forward_topology(self,idx,x,topo,trace=False):
        h=self.enc(x); active=['enc']
        for s,op in enumerate(topo):
            h=self.stages[s].hard(h,idx,int(op))
            if int(op)!=0: active.append(f'stage{s}:{OP_NAMES[int(op)]}')
        active.append('head'); out=self.head(h)
        return (out,active) if trace else out

def topo_cost(t,p): return float((OP_COST[list(t)].sum(0)*p).sum())

def train(seed,task='xor2',price_aware=True,steps=None):
    y=labels(task); steps=steps or (1800 if task=='xor2' else 2200)
    torch.manual_seed(seed); random.seed(seed); m=SearchNet(price_aware)
    opt=torch.optim.AdamW(m.parameters(),lr=2e-3,weight_decay=1e-6); ps=torch.stack([price(r) for r in ANCHORS])
    for step in range(steps):
        bs=512; sel=torch.randint(0,N,(bs,)); p=ps[torch.randint(0,len(ANCHORS),(bs,))]
        logits,g=m.forward_train(sel,BITS[sel],p,max(0.35,1.0-step/2600))
        task_loss=F.cross_entropy(logits,y[sel])
        rc=(g*(p[:,None,None]*OP_COST[None,None,:,:]).sum(-1)).sum((1,2)).mean()
        usage=g.float().mean((0,1)); explore=((usage-1/3.)**2).sum(); ew=0.10*max(0.0,1.0-step/(steps*0.65))
        loss=task_loss+0.32*rc+ew*explore
        opt.zero_grad(); loss.backward(); opt.step()
    return m.eval()

@torch.no_grad()
def topology_accuracy(m,task):
    y=labels(task); out={}
    for t in TOPOLOGIES:
        out[t]=float((m.forward_topology(IDX,BITS,t).argmax(1)==y).float().mean())
    return out

def locally_prune(t,p,acc):
    # Validation-only consolidation: remove active primitive ops when replacing them by skip
    # preserves exact full-domain accuracy. This is reported separately from learned topology.
    active=[i for i,v in enumerate(t) if v!=0]; candidates=[]
    for mask in range(1<<len(active)):
        q=list(t)
        for j,pos in enumerate(active):
            if not ((mask>>j)&1): q[pos]=0
        q=tuple(q)
        if acc[q]==1.0: candidates.append(q)
    return min(candidates,key=lambda q:topo_cost(q,p)) if candidates else t

@torch.no_grad()
def evaluate(m,seed,task):
    y=labels(task); acc=topology_accuracy(m,task); valid=[t for t,a in acc.items() if a==1.0]
    dense=[10**(-2+4*i/399) for i in range(400)]
    selected=[]; selected_pruned=[]; full=match=matchp=0; regret=regretp=0.0; first={}
    for r in dense:
        p=price(r); t=m.topology(p); q=locally_prune(t,p,acc); selected.append(t); selected_pruned.append(q); first.setdefault(t,r)
        full+=int(acc[t]==1.0)
        if valid:
            o=min(valid,key=lambda z:topo_cost(z,p)); match+=int(t==o); matchp+=int(q==o)
            regret+=max(0.0,topo_cost(t,p)-topo_cost(o,p)); regretp+=max(0.0,topo_cost(q,p)-topo_cost(o,p))
    probes={}
    for name,r in [('footprint_expensive',0.02),('balanced',1.0),('compute_expensive',50.0)]:
        p=price(r); t=m.topology(p); probes[name]={'ratio':r,'topology':list(t),'lookup_count':sum(v==1 for v in t),'compute_count':sum(v==2 for v in t)}
    reps=[]; fi=123
    for t in sorted(set(selected)):
        r=first[t]; pred,trace=m.forward_topology(IDX[fi:fi+1],BITS[fi:fi+1],t,True)
        reps.append({'first_ratio':r,'topology':list(t),'trace':trace,'prediction':int(pred.argmax(1)),'target':int(y[fi])})
    return {'seed':seed,'task':task,'num_perfect_topologies':len(valid),'num_selected_topologies':len(set(selected)),
            'selected_topologies':[list(t) for t in sorted(set(selected))], 'dense_hard_accuracy':full/400,
            'global_oracle_agreement':match/400,'mean_global_regret':regret/400,
            'posthoc_local_prune_oracle_agreement':matchp/400,'posthoc_local_prune_regret':regretp/400,
            'posthoc_pruned_topologies':[list(t) for t in sorted(set(selected_pruned))], 'endpoint_probes':probes,
            'representative_fixed_input_traces':reps}

def agg(rows):
    keys=['num_perfect_topologies','num_selected_topologies','dense_hard_accuracy','global_oracle_agreement','mean_global_regret','posthoc_local_prune_oracle_agreement','posthoc_local_prune_regret']
    return {k:sum(r[k] for r in rows)/len(rows) for k in keys} | {'seeds_with_multiple_topologies':sum(r['num_selected_topologies']>1 for r in rows)}

def run_suite(out_path):
    result={'setup':{'search_space':'3 stages x {skip, lookup, compute} = 27 hard topologies','topology_labels_used':False,'training_price_anchors':ANCHORS,
                     'resource_columns':['compute_proxy','active_parameter_footprint_proxy'],
                     'boundary':'Primitive operations and stage count are supplied. This is subgraph discovery inside a hand-specified supernet, not unconstrained architecture discovery.'},
            'xor2':{},'parity4_negative':{}}
    for mode,aware in [('price_aware',True),('price_blind',False)]:
        rows=[]
        for s in range(5):
            m=train(s,'xor2',aware); ev=evaluate(m,s,'xor2'); rows.append(ev); print(mode,s,ev['num_selected_topologies'],ev['dense_hard_accuracy'],ev['global_oracle_agreement'],flush=True)
        result['xor2'][mode]={'seeds':rows,'aggregate':agg(rows)}
    rows=[]
    for s in range(3):
        m=train(s,'parity4',True); ev=evaluate(m,s,'parity4'); rows.append(ev); print('parity4',s,ev['num_selected_topologies'],ev['dense_hard_accuracy'],flush=True)
    result['parity4_negative']={'price_aware':{'seeds':rows,'aggregate':agg(rows)}}
    Path(out_path).write_text(json.dumps(result,indent=2)); return result

if __name__=='__main__':
    ap=argparse.ArgumentParser(); ap.add_argument('--suite',action='store_true'); ap.add_argument('--seed',type=int,default=0); ap.add_argument('--task',choices=['xor2','parity4'],default='xor2'); ap.add_argument('--blind',action='store_true'); ap.add_argument('--out',default=str(DEFAULT_OUT)); a=ap.parse_args()
    if a.suite: run_suite(a.out)
    else:
        m=train(a.seed,a.task,not a.blind); print(json.dumps(evaluate(m,a.seed,a.task),indent=2))
