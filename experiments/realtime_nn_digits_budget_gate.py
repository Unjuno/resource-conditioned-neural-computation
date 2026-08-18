import argparse, torch, torch.nn as nn, torch.nn.functional as F, random, time, statistics, math, json, itertools
from pathlib import Path
from sklearn.datasets import load_digits
from sklearn.model_selection import train_test_split
import numpy as np

torch.set_num_threads(1)
try: torch.set_num_interop_threads(1)
except RuntimeError: pass
ROOT=Path(__file__).resolve().parents[1] if '__file__' in globals() else Path('.')
KS=[1,2,4,8]; S=8; E=32
CTRL_MACS_PER_ROW=(8+8+1)*16+16; CTRL_MACS=8*CTRL_MACS_PER_ROW
EXPERT_MACS=8*48+48*96+96*E
HEAD_MACS=(E+1)*48+48*10
D=load_digits(); xx=np.asarray(D.data,dtype=np.float32).reshape(-1,8,8)/16.; yy=np.asarray(D.target,dtype=np.int64); ids=np.arange(len(yy))
tr,tmp=train_test_split(ids,test_size=.4,random_state=123,stratify=yy); va,te=train_test_split(tmp,test_size=.5,random_state=456,stratify=yy[tmp])
X=torch.tensor(xx); Y=torch.tensor(yy); TRX=X[tr];TRY=Y[tr];VAX=X[va];VAY=Y[va];TEX=X[te];TEY=Y[te]
pos=torch.eye(8)

class Expert(nn.Module):
    def __init__(self): super().__init__(); self.a=nn.Linear(8,48);self.b=nn.Linear(48,96);self.c=nn.Linear(96,E)
    def forward(self,z): h=torch.tanh(self.a(z));return torch.tanh(self.c(F.gelu(self.b(h))))
class Net(nn.Module):
    def __init__(self):
        super().__init__();self.experts=nn.ModuleList([Expert() for _ in range(S)]);self.ctrl=nn.Sequential(nn.Linear(17,16),nn.Tanh(),nn.Linear(16,1));self.head=nn.Sequential(nn.Linear(E+1,48),nn.Tanh(),nn.Linear(48,10))
    def scores(self,z,k):
        b=z.size(0);return self.ctrl(torch.cat([z,pos[None].expand(b,-1,-1),torch.full((b,S,1),float(k)/S)],-1)).squeeze(-1)
    def train_forward(self,z,k,tau):
        ex=torch.stack([e(z[:,j]) for j,e in enumerate(self.experts)],1)
        if k==S: gate=torch.ones(z.size(0),S);ids=torch.arange(S)[None].expand(z.size(0),-1)
        else:
            sc=self.scores(z,k);ids=sc.topk(k,1).indices;hard=torch.zeros_like(sc);hard.scatter_(1,ids,1.);soft=torch.softmax(sc/tau,1)*k;gate=hard+(soft-soft.detach())
        h=(ex*gate[:,:,None]).sum(1)/k;return self.head(torch.cat([h,torch.full((z.size(0),1),float(k)/S)],1)),ids
    @torch.no_grad()
    def select_ids(self,z,k,mode='learned',subset=None):
        if k==S:return torch.arange(S)[None].expand(z.size(0),-1)
        if mode=='learned':return self.scores(z,k).topk(k,1).indices
        if mode=='prefix':return torch.arange(k)[None].expand(z.size(0),-1)
        if mode=='subset':return torch.tensor(subset)[None].expand(z.size(0),-1)
        raise KeyError(mode)
    @torch.no_grad()
    def hard(self,z,k,mode='learned',subset=None):
        ids=self.select_ids(z,k,mode,subset);rows=[]
        for n in range(z.size(0)):
            h=torch.zeros(E)
            for j in ids[n].tolist():h+=self.experts[j](z[n:n+1,j])[0]
            rows.append(h/k)
        h=torch.stack(rows);return self.head(torch.cat([h,torch.full((z.size(0),1),float(k)/S)],1)),ids
    @torch.no_grad()
    def dense(self,z,k):
        ex=torch.stack([e(z[:,j]) for j,e in enumerate(self.experts)],1);ids=self.select_ids(z,k,'learned');m=torch.zeros(z.size(0),S);m.scatter_(1,ids,1.);h=(ex*m[:,:,None]).sum(1)/k;return self.head(torch.cat([h,torch.full((z.size(0),1),float(k)/S)],1)),ids

def train(seed,steps=1800):
    torch.manual_seed(seed);random.seed(seed);m=Net();opt=torch.optim.AdamW(m.parameters(),lr=2e-3,weight_decay=1e-5);rng=random.Random(100+seed)
    for st in range(steps):
        ix=torch.randint(0,len(TRX),(128,));k=rng.choice(KS);tau=max(.25,1-.75*st/steps);o,_=m.train_forward(TRX[ix],k,tau);loss=F.cross_entropy(o,TRY[ix]);opt.zero_grad();loss.backward();torch.nn.utils.clip_grad_norm_(m.parameters(),5);opt.step()
    return m.eval()
@torch.no_grad()
def eval_acc(m,data,label,k,mode='learned',subset=None):
    ps=[]
    for a in range(0,len(data),64):ps.append(m.hard(data[a:a+64],k,mode,subset)[0].argmax(1))
    return float((torch.cat(ps)==label).float().mean())
def best_static(m,k):
    best=(-1,None)
    for ss in itertools.combinations(range(S),k):
        a=eval_acc(m,VAX,VAY,k,'subset',ss)
        if a>best[0]:best=(a,ss)
    return best
@torch.no_grad()
def content_ablation(m,k,seed):
    ids=m.select_ids(TEX,k,'learned');g=torch.Generator().manual_seed(700+seed+k);perm=torch.randperm(len(TEX),generator=g);rows=[]
    for n in range(len(TEX)):
        h=torch.zeros(E)
        for j in ids[n].tolist():h+=m.experts[j](TEX[perm[n]:perm[n]+1,j])[0]
        rows.append(h/k)
    h=torch.stack(rows);z=m.head(torch.cat([h,torch.full((len(TEX),1),float(k)/S)],1));return float((z.argmax(1)==TEY).float().mean())
@torch.no_grad()
def constant_identity_ablation(m,k):
    const=[]
    for j,e in enumerate(m.experts):const.append(e(TRX[:,j]).mean(0))
    const=torch.stack(const);ids=m.select_ids(TEX,k,'learned');h=torch.stack([const[ids[n]].sum(0)/k for n in range(len(TEX))]);z=m.head(torch.cat([h,torch.full((len(TEX),1),float(k)/S)],1));return float((z.argmax(1)==TEY).float().mean())
def pct(v,p):s=sorted(v);return s[min(len(s)-1,max(0,math.ceil(p*len(s))-1))]
def timing(m,k,mode,reps=300):
    rng=random.Random(900+k);fn=(lambda z:m.dense(z,k)[0]) if mode=='dense' else (lambda z:m.hard(z,k,mode)[0]);vals=[]
    for _ in range(50):j=rng.randrange(len(TEX));fn(TEX[j:j+1])
    for _ in range(reps):j=rng.randrange(len(TEX));t=time.perf_counter_ns();fn(TEX[j:j+1]);vals.append((time.perf_counter_ns()-t)/1000.)
    return {'p50_us':statistics.median(vals),'p95_us':pct(vals,.95),'p99_us':pct(vals,.99),'max_us':max(vals)}
@torch.no_grad()
def hooks(m,k,mode):
    hit=[];hs=[e.register_forward_hook(lambda mod,inp,out,i=i:hit.append(i)) for i,e in enumerate(m.experts)]
    try:
        if mode=='dense':m.dense(TEX[:1],k)
        else:m.hard(TEX[:1],k,mode)
    finally:
        for h in hs:h.remove()
    return hit

def run(seed,steps=1800,timing_reps=300):
    m=train(seed,steps);r={'seed':seed,'classes':{}}
    for k in KS:
        bs=best_static(m,k);learn=eval_acc(m,TEX,TEY,k);prefix=eval_acc(m,TEX,TEY,k,'prefix');static=eval_acc(m,TEX,TEY,k,'subset',bs[1]);shuf=content_ablation(m,k,seed);ident=constant_identity_ablation(m,k)
        with torch.no_grad():sel=m.select_ids(TEX,k);hist=(torch.bincount(sel.reshape(-1),minlength=S).float()/sel.numel()).tolist()
        r['classes'][str(k)]={'accuracy':{'learned':learn,'prefix':prefix,'best_static_validation_selected':static,'content_shuffled':shuf,'identity_constant':ident},'best_static_subset':list(bs[1]),'best_static_validation_accuracy':bs[0],'selection_hist':hist,'linear_macs':{'learned_hard':HEAD_MACS+k*EXPERT_MACS+(0 if k==S else CTRL_MACS),'prefix_hard':HEAD_MACS+k*EXPERT_MACS,'dense_learned':HEAD_MACS+S*EXPERT_MACS+(0 if k==S else CTRL_MACS)},'timing':{'learned_hard':timing(m,k,'learned',timing_reps),'prefix_hard':timing(m,k,'prefix',timing_reps),'dense_learned':timing(m,k,'dense',timing_reps)},'hook_counts':{'learned_hard':len(hooks(m,k,'learned')),'prefix_hard':len(hooks(m,k,'prefix')),'dense_learned':len(hooks(m,k,'dense'))}}
    r['checks']={'hard_cap':all(r['classes'][str(k)]['hook_counts']['learned_hard']==k for k in KS),'dense_all':all(r['classes'][str(k)]['hook_counts']['dense_learned']==S for k in KS),'latency_monotonic':all(r['classes'][str(KS[i])]['timing']['learned_hard']['p50_us']<r['classes'][str(KS[i+1])]['timing']['learned_hard']['p50_us'] for i in range(3))}
    return r
def aggregate(rows):
    out={'all_seeds_hard_cap':all(r['checks']['hard_cap'] for r in rows),'all_seeds_dense_executes_all':all(r['checks']['dense_all'] for r in rows),'all_seeds_learned_p50_monotonic':all(r['checks']['latency_monotonic'] for r in rows),'by_k':{}}
    for k in KS:
        kk=str(k); out['by_k'][kk]={}
        for name in ['learned','prefix','best_static_validation_selected','content_shuffled','identity_constant']:
            out['by_k'][kk][name]=statistics.mean(r['classes'][kk]['accuracy'][name] for r in rows)
        for name in ['learned_hard','prefix_hard','dense_learned']:
            out['by_k'][kk][name+'_p50_us']=statistics.mean(r['classes'][kk]['timing'][name]['p50_us'] for r in rows)
        out['by_k'][kk]['linear_macs']=rows[0]['classes'][kk]['linear_macs']
    return out

def main():
    ap=argparse.ArgumentParser(); ap.add_argument('--seed',type=int); ap.add_argument('--seeds',type=int,default=3); ap.add_argument('--steps',type=int,default=1800); ap.add_argument('--timing-reps',type=int,default=300); ap.add_argument('--out',default=str(ROOT/'results'/'realtime_nn_digits_budget_gate_results.json')); a=ap.parse_args()
    seeds=[a.seed] if a.seed is not None else list(range(a.seeds)); rows=[]
    for seed in seeds:
        r=run(seed,a.steps,a.timing_reps); rows.append(r); print('seed',seed,r['checks'],flush=True)
    result={'setup':{'dataset':'sklearn digits 8x8; fixed stratified 60/20/20 train/validation/test','budgets':KS,'experts':'8 row-local expert MLPs','controller_visibility':'each row pixels + row position + budget only','training':'task cross-entropy only; no relevance labels; straight-through hard top-k surrogate','inference':'physically executes exactly k selected experts','static_baseline':'best subset chosen only on validation and evaluated on held-out test','timing_boundary':'ordinary Linux/PyTorch batch-1; not WCET/hard real time'},'seeds':rows,'aggregate':aggregate(rows)}
    Path(a.out).write_text(json.dumps(result,indent=2)); print(json.dumps(result['aggregate'],indent=2))
if __name__=='__main__': main()
