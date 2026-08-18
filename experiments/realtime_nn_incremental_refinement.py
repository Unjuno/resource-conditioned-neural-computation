import argparse, json, random, statistics, math, time
from pathlib import Path
import torch
import torch.nn as nn
import torch.nn.functional as F

torch.set_num_threads(1)
try: torch.set_num_interop_threads(1)
except RuntimeError: pass

ROOT = Path(__file__).resolve().parents[1]
S,R,Q,H=8,4,4,48
TRAIN_N,TEST_N=16000,2000

def make_data(n,seed):
    g=torch.Generator().manual_seed(seed); rr=random.Random(seed)
    bits=torch.randint(0,2,(n,S),generator=g).float(); queries=torch.randint(0,Q,(n,),generator=g)
    keys=torch.empty(n,S,dtype=torch.long); rel=torch.zeros(n,S)
    for i in range(n):
        ids=set(rr.sample(range(S),R)); q=int(queries[i])
        for j in range(S):
            if j in ids: keys[i,j]=q; rel[i,j]=1.
            else: keys[i,j]=rr.choice([x for x in range(Q) if x!=q])
    y=((bits*rel).sum(1)>=3).long()
    ko=F.one_hot(keys,Q).float(); qo=F.one_hot(queries,Q).float()[:,None,:].expand(-1,S,-1)
    feat=torch.cat([bits[:,:,None],ko,qo],-1)
    return feat,rel,y
TRF,TRR,TRY=make_data(TRAIN_N,101); TEF,TER,TEY=make_data(TEST_N,202)

class Expert(nn.Module):
    def __init__(self):
        super().__init__(); self.a=nn.Linear(1+2*Q,H); self.b=nn.Linear(H,4*H); self.c=nn.Linear(4*H,H)
    def forward(self,z):
        h=torch.tanh(self.a(z)); return torch.tanh(h+.2*self.c(F.gelu(self.b(h))))

class Base(nn.Module):
    def __init__(self):
        super().__init__(); self.experts=nn.ModuleList([Expert() for _ in range(S)]); self.ctrl=nn.Sequential(nn.Linear(2*Q,24),nn.Tanh(),nn.Linear(24,1))
    def scores(self,feat): return self.ctrl(feat[:,:,1:]).squeeze(-1)
    def ids(self,feat,k): return self.scores(feat).topk(k,1).indices

class SharedHead(Base):
    def __init__(self): super().__init__(); self.head=nn.Linear(H+1,2)
    def train_logits_all(self,feat,tau):
        ex=torch.stack([e(feat[:,j]) for j,e in enumerate(self.experts)],1); sc=self.scores(feat); outs=[]
        for k in range(1,S+1):
            ids=sc.topk(k,1).indices; hard=torch.zeros_like(sc); hard.scatter_(1,ids,1.)
            gate=hard if k==S else hard+(torch.softmax(sc/tau,1)*k-torch.softmax(sc/tau,1).detach()*k)
            h=(ex*gate[:,:,None]).sum(1); b=torch.full((feat.size(0),1),k/S,dtype=feat.dtype)
            outs.append(self.head(torch.cat([h,b],1)))
        return outs
    @torch.no_grad()
    def eval_logits(self,feat,k):
        ex=torch.stack([e(feat[:,j]) for j,e in enumerate(self.experts)],1); sc=self.scores(feat); ids=sc.topk(k,1).indices
        gate=torch.zeros_like(sc); gate.scatter_(1,ids,1.); h=(ex*gate[:,:,None]).sum(1); b=torch.full((feat.size(0),1),k/S)
        return self.head(torch.cat([h,b],1)),ids
    @torch.no_grad()
    def hard_one(self,feat,k):
        ids=self.ids(feat,k); h=torch.zeros(H)
        for j in ids[0].tolist(): h += self.experts[j](feat[:,j])[0]
        b=torch.tensor([[k/S]],dtype=feat.dtype); return self.head(torch.cat([h[None],b],1)),ids

class AdditiveEvidence(Base):
    def __init__(self):
        super().__init__(); self.vote=nn.Linear(H,2); self.budget_bias=nn.Linear(1,2)
    def train_logits_all(self,feat,tau):
        ex=torch.stack([e(feat[:,j]) for j,e in enumerate(self.experts)],1); votes=self.vote(ex); sc=self.scores(feat); outs=[]
        soft0=torch.softmax(sc/tau,1)
        for k in range(1,S+1):
            ids=sc.topk(k,1).indices; hard=torch.zeros_like(sc); hard.scatter_(1,ids,1.)
            gate=hard if k==S else hard+(soft0*k-soft0.detach()*k)
            z=(votes*gate[:,:,None]).sum(1); b=torch.full((feat.size(0),1),k/S,dtype=feat.dtype)
            outs.append(z+self.budget_bias(b))
        return outs
    @torch.no_grad()
    def eval_logits(self,feat,k):
        ex=torch.stack([e(feat[:,j]) for j,e in enumerate(self.experts)],1); votes=self.vote(ex); sc=self.scores(feat); ids=sc.topk(k,1).indices
        gate=torch.zeros_like(sc); gate.scatter_(1,ids,1.); b=torch.full((feat.size(0),1),k/S)
        return (votes*gate[:,:,None]).sum(1)+self.budget_bias(b),ids
    @torch.no_grad()
    def hard_one(self,feat,k):
        ids=self.ids(feat,k); z=torch.zeros(2)
        for j in ids[0].tolist(): z += self.vote(self.experts[j](feat[:,j])[0])
        b=torch.tensor([[k/S]],dtype=feat.dtype); return z[None]+self.budget_bias(b),ids


def train(seed,kind,steps=800):
    torch.manual_seed(seed); random.seed(seed)
    m=SharedHead() if kind=='shared' else AdditiveEvidence()
    opt=torch.optim.AdamW(m.parameters(),lr=2e-3,weight_decay=1e-6)
    g=torch.Generator().manual_seed(900+seed)
    for step in range(steps):
        ix=torch.randint(0,TRAIN_N,(256,),generator=g); feat=TRF[ix]; y=TRY[ix]; tau=max(.3,1-step/steps*.7)
        outs=m.train_logits_all(feat,tau); loss=torch.stack([F.cross_entropy(z,y) for z in outs]).mean()
        opt.zero_grad(); loss.backward(); torch.nn.utils.clip_grad_norm_(m.parameters(),5); opt.step()
    return m.eval()

@torch.no_grad()
def audit_model(m):
    acc={}; relevance={}
    for k in range(1,S+1):
        ps=[]; rs=[]
        for a in range(0,TEST_N,256):
            z,ids=m.eval_logits(TEF[a:a+256],k); ps.append(z.argmax(1)); rs.append(torch.gather(TER[a:a+256],1,ids).mean())
        acc[str(k)]=float((torch.cat(ps)==TEY).float().mean()); relevance[str(k)]=float(torch.stack(rs).mean())
    vals=[acc[str(k)] for k in range(1,S+1)]; drops=[max(0.,vals[i]-vals[i+1]) for i in range(S-1)]
    x=TEF[:512]; allids=[m.ids(x,k) for k in range(1,S+1)]; nv=0
    for n in range(len(x)):
        prev=set()
        for ki,ids in enumerate(allids,1):
            cur=set(ids[n].tolist())
            if ki>1 and not prev.issubset(cur): nv+=1
            prev=cur
    hook_pass=True; hook_rows=[]
    for k in [1,2,4,6,8]:
        hits=[]; hs=[e.register_forward_hook(lambda mod,inp,out,j=j:hits.append(j)) for j,e in enumerate(m.experts)]
        try: _,ids=m.hard_one(TEF[:1],k)
        finally:
            for h in hs:h.remove()
        ok=(len(hits)==k and set(hits)==set(ids[0].tolist())); hook_pass &= ok; hook_rows.append({'k':k,'hits':hits,'selected':ids[0].tolist(),'pass':ok})
    return {'accuracy':acc,'selected_relevant_fraction':relevance,'strict_non_decreasing':all(vals[i]<=vals[i+1]+1e-12 for i in range(S-1)),
            'max_adjacent_drop_pp':100*max(drops),'k4_to_k8_drop_pp':100*(vals[3]-vals[7]),'nested_violations':nv,'hard_cap_pass':hook_pass,'hook_rows':hook_rows}

def run(seeds,steps):
    rows=[]
    for s in range(seeds):
        rr={'seed':s}
        for kind in ['shared','additive']:
            m=train(s,kind,steps); rr[kind]=audit_model(m)
            print('seed',s,kind,rr[kind]['accuracy'],rr[kind]['strict_non_decreasing'],rr[kind]['max_adjacent_drop_pp'],flush=True)
        rows.append(rr)
    agg={}
    for kind in ['shared','additive']:
        agg[kind]={
            'mean_accuracy':{str(k):statistics.mean(r[kind]['accuracy'][str(k)] for r in rows) for k in range(1,S+1)},
            'strict_monotonic_seeds':sum(r[kind]['strict_non_decreasing'] for r in rows),
            'mean_max_adjacent_drop_pp':statistics.mean(r[kind]['max_adjacent_drop_pp'] for r in rows),
            'mean_k4_to_k8_drop_pp':statistics.mean(r[kind]['k4_to_k8_drop_pp'] for r in rows),
            'nested_violations':sum(r[kind]['nested_violations'] for r in rows),
            'all_hard_cap_pass':all(r[kind]['hard_cap_pass'] for r in rows),
        }
    add=agg['additive']; sh=agg['shared']
    pass_cond=(add['strict_monotonic_seeds'] > sh['strict_monotonic_seeds'] and add['mean_max_adjacent_drop_pp'] < sh['mean_max_adjacent_drop_pp'] and add['mean_accuracy']['4']>=sh['mean_accuracy']['4']-.01 and add['nested_violations']==0 and add['all_hard_cap_pass'])
    agg['hypothesis']={'H':'Additive logit-evidence refinement reduces residual high-budget utility regression relative to the matched shared hidden-state baseline without materially sacrificing intermediate quality.',
       'PASS_conditions':{'strict_monotonic_seeds_must_exceed_shared':True,'mean_max_adjacent_drop_pp_must_be_below_shared':True,'additive_k4_gap_vs_shared_pp_min':-1.0,'nested_violations':0,'hard_cap':True},'decision':'PASS' if pass_cond else 'FAIL'}
    return {'setup':{'task':'same 8-slot/4-relevant strict-majority task','training':'all 8 execution classes jointly each update','physical_contract':'beta-independent learned ranking; class k physically calls exactly top-k experts','shared':'sum selected H-vectors then one shared head','additive':'each selected expert emits a 2-logit correction; corrections add directly to running output','timing_claim':'none'},'seeds':rows,'aggregate':agg}

def main():
    ap=argparse.ArgumentParser(); ap.add_argument('--seeds',type=int,default=10); ap.add_argument('--steps',type=int,default=800); ap.add_argument('--out',default=str(ROOT/'results'/'realtime_nn_incremental_refinement_results.json')); a=ap.parse_args()
    r=run(a.seeds,a.steps); Path(a.out).write_text(json.dumps(r,indent=2)); print(json.dumps(r['aggregate'],indent=2))
if __name__=='__main__':main()
