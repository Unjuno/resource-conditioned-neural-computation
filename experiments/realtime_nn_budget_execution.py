import argparse, json, math, os, random, statistics, time
from pathlib import Path
import torch, torch.nn as nn, torch.nn.functional as F

torch.set_num_threads(1)
try: torch.set_num_interop_threads(1)
except RuntimeError: pass
ROOT=Path(__file__).resolve().parents[1] if '__file__' in globals() else Path('.')
BUDGETS=[0.,.25,.5,.75,1.]; DEPTHS=[0,2,4,6,8]
L=9; N=1<<L; C=32; K=8; BLOCK_MACS=10*L*C*C; HEAD_MACS=C*2
IDX=torch.arange(N); SH=torch.arange(L); X=((IDX[:,None]>>SH)&1).long(); Y=(X.sum(1)>=5).long()
W={0:.08,2:.12,4:.20,6:.25,8:.35}

class Block(nn.Module):
    def __init__(self):
        super().__init__(); self.selfp=nn.Linear(C,C); self.neigh=nn.Linear(C,C); self.ff1=nn.Linear(C,4*C); self.ff2=nn.Linear(4*C,C)
    def forward(self,h):
        nb=torch.zeros_like(h); nb[:,:-1]=h[:,1:]
        z=torch.tanh(self.selfp(h)+self.neigh(nb))
        return torch.tanh(z+.2*self.ff2(F.gelu(self.ff1(z))))
class Net(nn.Module):
    def __init__(self): super().__init__(); self.emb=nn.Embedding(2,C); self.blocks=nn.ModuleList([Block() for _ in range(K)]); self.head=nn.Linear(C,2)
    @staticmethod
    def depth(b): return DEPTHS[min(4,max(0,int(round(float(b)*4))))]
    def all_depths(self,x):
        h=self.emb(x); out={0:self.head(h[:,0])}
        for i,blk in enumerate(self.blocks,1):
            h=blk(h)
            if i in DEPTHS: out[i]=self.head(h[:,0])
        return out
    def hard(self,x,b):
        h=self.emb(x)
        for i in range(self.depth(b)): h=self.blocks[i](h)
        return self.head(h[:,0])
    def dense(self,x,b):
        d=self.depth(b); h=self.emb(x)
        for i,blk in enumerate(self.blocks):
            cand=blk(h); h=cand if i<d else h+(cand-h)*0.
        return self.head(h[:,0])

def train(seed,steps=140):
    torch.manual_seed(seed); random.seed(seed); m=Net(); opt=torch.optim.AdamW(m.parameters(),lr=3e-3,weight_decay=1e-6)
    for _ in range(steps):
        out=m.all_depths(X); loss=sum(W[d]*F.cross_entropy(out[d],Y) for d in DEPTHS); opt.zero_grad(); loss.backward(); opt.step()
    return m.eval()
def pct(v,p):
    s=sorted(v); return s[min(len(s)-1,max(0,math.ceil(p*len(s))-1))]
def summary(v): return {'median_us':statistics.median(v),'p90_us':pct(v,.9),'p99_us':pct(v,.99),'mean_us':statistics.mean(v),'max_us':max(v)}
def samples(m,fn,b,reps=400,warm=50):
    vals=[]
    with torch.inference_mode():
        for _ in range(warm): fn(X[341:342],b)
        for _ in range(reps):
            t=time.perf_counter_ns(); fn(X[341:342],b); vals.append((time.perf_counter_ns()-t)/1000.)
    return vals
@torch.no_grad()
def trace(m,fn,b):
    hits=[]; hh=[blk.register_forward_hook(lambda mod,inp,out,i=i:hits.append(i)) for i,blk in enumerate(m.blocks)]
    try: z=fn(X[341:342],b)
    finally:
        for h in hh:h.remove()
    return hits,z

def run(seed,reps=400,rounds=3):
    m=train(seed); acc={str(b):float((m.hard(X,b).argmax(1)==Y).float().mean()) for b in BUDGETS}
    audit={}; diffs={}
    for b in BUDGETS:
        h,zh=trace(m,m.hard,b); d,zd=trace(m,m.dense,b); audit[str(b)]={'hard':h,'dense':d}; diffs[str(b)]=float((zh-zd).abs().max())
    raw={(mode,str(b)):[] for mode in ('hard','dense') for b in BUDGETS}; rng=random.Random(5000+seed); order=[(mode,b) for mode in ('hard','dense') for b in BUDGETS]
    for _ in range(rounds):
        rng.shuffle(order)
        for mode,b in order: raw[(mode,str(b))]+=samples(m,m.hard if mode=='hard' else m.dense,b,reps)
    timing={mode:{str(b):summary(raw[(mode,str(b))]) for b in BUDGETS} for mode in ('hard','dense')}
    calib={}
    for b in BUDGETS:
        v=samples(m,m.hard,b,700,80); calib[b]={'p50':pct(v,.5),'p90':pct(v,.9),'p95':pct(v,.95),'p99':pct(v,.99)}
    bounds={}; prev=0.
    for b in BUDGETS: bounds[b]=max(calib[b]['p95'],prev*1.000001); prev=bounds[b]
    deadlines={b:((bounds[b]+bounds[BUDGETS[i+1]])/2 if i<4 else bounds[b]*1.15) for i,b in enumerate(BUDGETS)}
    def admit(D):
        ok=[b for b in BUDGETS if bounds[b]<=D]; return max(ok) if ok else None
    miss={str(b):{} for b in BUDGETS}
    for target in BUDGETS:
        D=deadlines[target]
        for policy in ('adaptive_hard','adaptive_dense','full_depth'):
            nmiss=0
            with torch.inference_mode():
                for _ in range(500):
                    j=rng.randrange(N); xx=X[j:j+1]; t=time.perf_counter_ns()
                    if policy=='adaptive_hard': b=admit(D); fn=m.hard
                    elif policy=='adaptive_dense': b=admit(D); fn=m.dense
                    else: b=1.; fn=m.hard
                    if b is None: nmiss+=1; continue
                    fn(xx,b); nmiss+=int((time.perf_counter_ns()-t)/1000.>D)
            miss[str(target)][policy]=nmiss/500
    hm=[timing['hard'][str(b)]['median_us'] for b in BUDGETS]; dm=[timing['dense'][str(b)]['median_us'] for b in BUDGETS]; q=[calib[b]['p99'] for b in BUDGETS]
    return {'seed':seed,'accuracy':acc,'work':{str(b):{'depth':Net.depth(b),'total_linear_macs':Net.depth(b)*BLOCK_MACS+HEAD_MACS} for b in BUDGETS},'trace_audit':audit,'max_output_diff':max(diffs.values()),'hard_median_us':{str(b):timing['hard'][str(b)]['median_us'] for b in BUDGETS},'dense_median_us':{str(b):timing['dense'][str(b)]['median_us'] for b in BUDGETS},'deadline_miss_rate':miss,'raw_q99_strictly_increasing':all(q[i]<q[i+1] for i in range(4)),'checks':{'hard_latency_monotonic':all(hm[i]<hm[i+1] for i in range(4)),'hard_low_high_speedup':hm[-1]/hm[0],'hard_trace_pass':all(len(audit[str(b)]['hard'])==Net.depth(b) for b in BUDGETS),'dense_trace_pass':all(len(audit[str(b)]['dense'])==8 for b in BUDGETS),'outputs_match':max(diffs.values())<1e-7}}
def suite(seeds=3,reps=400,rounds=3):
    rows=[run(s,reps,rounds) for s in range(seeds)]
    return {'setup':{'task':'9-bit majority / complete 512-state domain','budgets':BUDGETS,'depths':DEPTHS,'block_linear_macs':BLOCK_MACS,'timing_boundary':'ordinary Linux/PyTorch empirical timing; not WCET/hard real time'},'seeds':rows,'aggregate':{'all_seeds_hard_latency_monotonic':all(r['checks']['hard_latency_monotonic'] for r in rows),'all_seeds_trace_pass':all(r['checks']['hard_trace_pass'] and r['checks']['dense_trace_pass'] for r in rows),'mean_hard_low_high_speedup':statistics.mean(r['checks']['hard_low_high_speedup'] for r in rows),'q99_monotonic_seeds':sum(r['raw_q99_strictly_increasing'] for r in rows),'mean_accuracy_by_budget':{str(b):statistics.mean(r['accuracy'][str(b)] for r in rows) for b in BUDGETS},'mean_hard_median_us_by_budget':{str(b):statistics.mean(r['hard_median_us'][str(b)] for r in rows) for b in BUDGETS},'mean_dense_median_us_by_budget':{str(b):statistics.mean(r['dense_median_us'][str(b)] for r in rows) for b in BUDGETS}}}
if __name__=='__main__':
    ap=argparse.ArgumentParser(); ap.add_argument('--seeds',type=int,default=3); ap.add_argument('--reps',type=int,default=400); ap.add_argument('--rounds',type=int,default=3); ap.add_argument('--out',default=str(ROOT/'results'/'realtime_nn_budget_execution_results.json')); a=ap.parse_args()
    try:
        cpus=sorted(os.sched_getaffinity(0)); os.sched_setaffinity(0,{cpus[0]})
    except Exception: pass
    r=suite(a.seeds,a.reps,a.rounds); Path(a.out).write_text(json.dumps(r,indent=2)); print(json.dumps(r['aggregate'],indent=2))
