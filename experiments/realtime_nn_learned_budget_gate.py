import argparse, json, math, os, random, statistics, time
from pathlib import Path
import torch, torch.nn as nn, torch.nn.functional as F

torch.set_num_threads(1)
try: torch.set_num_interop_threads(1)
except RuntimeError: pass
S=8; R=4; H=48; KS=[1,2,4,8]; BUDGETS=[k/S for k in KS]
EXPERT_MACS=2*H + 8*H*H; HEAD_MACS=(H+1)*2; CONTROLLER_MACS=S*(2*16+16)

def make_data(n,seed):
    g=torch.Generator().manual_seed(seed); bits=torch.randint(0,2,(n,S),generator=g).float(); rr=random.Random(seed); masks=[]
    for _ in range(n):
        ids=rr.sample(range(S),R); m=[0.]*S
        for i in ids:m[i]=1.
        masks.append(m)
    mask=torch.tensor(masks); y=((bits*mask).sum(1)>=3).long(); return bits,mask,y
TRB,TRM,TRY=make_data(12000,101); TEB,TEM,TEY=make_data(4000,202)
class Expert(nn.Module):
    def __init__(self): super().__init__(); self.a=nn.Linear(2,H); self.b=nn.Linear(H,4*H); self.c=nn.Linear(4*H,H)
    def forward(self,z):
        h=torch.tanh(self.a(z)); return torch.tanh(h+.2*self.c(F.gelu(self.b(h))))
class Net(nn.Module):
    def __init__(self):
        super().__init__(); self.experts=nn.ModuleList([Expert() for _ in range(S)]); self.score=nn.Sequential(nn.Linear(2,16),nn.Tanh(),nn.Linear(16,1)); self.head=nn.Linear(H+1,2)
    def scores(self,mask,k):
        bb=torch.full_like(mask,float(k)/S); return self.score(torch.stack([mask,bb],-1)).squeeze(-1)
    def ids(self,mask,k,mode='learned'):
        if mode=='learned': return self.scores(mask,k).topk(k,dim=1).indices
        return torch.arange(k)[None,:].expand(mask.size(0),-1)
    def dense_train(self,bits,mask,k,mode='learned'):
        ex=torch.stack([e(torch.stack([bits[:,j],mask[:,j]],1)) for j,e in enumerate(self.experts)],1)
        ids=self.ids(mask,k,mode); sel=torch.zeros(mask.size(0),S); sel.scatter_(1,ids,1.); h=(ex*sel[:,:,None]).sum(1)
        return self.head(torch.cat([h,torch.full((bits.size(0),1),float(k)/S)],1))
    def hard(self,bits,mask,k,mode='learned'):
        ids=self.ids(mask,k,mode); rows=[]
        for n in range(bits.size(0)):
            h=torch.zeros(H)
            for j in ids[n].tolist(): h=h+self.experts[j](torch.stack([bits[n,j],mask[n,j]]).view(1,2))[0]
            rows.append(h)
        h=torch.stack(rows); return self.head(torch.cat([h,torch.full((bits.size(0),1),float(k)/S)],1))
    def dense_infer(self,bits,mask,k): return self.dense_train(bits,mask,k,'learned')
def train(seed,gate_steps=150,task_steps=350):
    torch.manual_seed(seed); random.seed(seed); m=Net(); go=torch.optim.AdamW(m.score.parameters(),lr=5e-3)
    for _ in range(gate_steps):
        ix=torch.randint(0,len(TRB),(512,)); z=m.scores(TRM[ix],4); loss=F.binary_cross_entropy_with_logits(z,TRM[ix]); go.zero_grad();loss.backward();go.step()
    for p in m.score.parameters():p.requires_grad_(False)
    opt=torch.optim.AdamW([p for p in m.parameters() if p.requires_grad],lr=3e-3); rng=random.Random(700+seed)
    for _ in range(task_steps):
        ix=torch.randint(0,len(TRB),(256,)); k=rng.choice(KS); z=m.dense_train(TRB[ix],TRM[ix],k,'learned'); loss=F.cross_entropy(z,TRY[ix]);opt.zero_grad();loss.backward();opt.step()
    return m.eval()
@torch.no_grad()
def accs(m,mode): return {str(k):float((m.dense_train(TEB,TEM,k,mode).argmax(1)==TEY).float().mean()) for k in KS}
@torch.no_grad()
def relevance(m,k):
    ids=m.ids(TEM,k,'learned'); return float(torch.gather(TEM,1,ids).mean())
@torch.no_grad()
def trace(m,fn,k):
    hits=[]; hs=[e.register_forward_hook(lambda mod,inp,out,i=i:hits.append(i)) for i,e in enumerate(m.experts)]
    try:z=fn(TEB[:1],TEM[:1],k)
    finally:
        for h in hs:h.remove()
    return hits,z
def pct(v,p):
    s=sorted(v);return s[min(len(s)-1,max(0,math.ceil(p*len(s))-1))]
def summ(v):return {'median_us':statistics.median(v),'p90_us':pct(v,.9),'p99_us':pct(v,.99),'mean_us':statistics.mean(v),'max_us':max(v)}
def lat(m,fn,k,reps=400,warm=50):
    v=[]
    with torch.inference_mode():
        for _ in range(warm):fn(TEB[:1],TEM[:1],k)
        for _ in range(reps):
            t=time.perf_counter_ns();fn(TEB[:1],TEM[:1],k);v.append((time.perf_counter_ns()-t)/1000.)
    return v
def run(seed,reps=400,rounds=3):
    m=train(seed); la=accs(m,'learned'); pa=accs(m,'prefix'); rel={str(k):relevance(m,k) for k in KS};audit={};diff={}
    for k in KS:
        h,z=trace(m,lambda b,ma,kk:m.hard(b,ma,kk,'learned'),k); d,zd=trace(m,m.dense_infer,k); p,zp=trace(m,lambda b,ma,kk:m.hard(b,ma,kk,'prefix'),k)
        audit[str(k)]={'learned_hard':h,'prefix_hard':p,'learned_dense':d};diff[str(k)]=float((z-zd).abs().max())
    raw={(mode,k):[] for mode in ('learned_hard','prefix_hard','dense') for k in KS};rng=random.Random(900+seed); order=list(raw)
    for _ in range(rounds):
        rng.shuffle(order)
        for mode,k in order:
            fn=(lambda b,ma,kk:m.hard(b,ma,kk,'learned')) if mode=='learned_hard' else ((lambda b,ma,kk:m.hard(b,ma,kk,'prefix')) if mode=='prefix_hard' else m.dense_infer)
            raw[(mode,k)]+=lat(m,fn,k,reps,40)
    timing={mode:{str(k):summ(raw[(mode,k)]) for k in KS} for mode in ('learned_hard','prefix_hard','dense')}
    hm=[timing['learned_hard'][str(k)]['median_us'] for k in KS]
    return {'seed':seed,'learned_accuracy':la,'prefix_accuracy':pa,'selected_relevant_fraction':rel,'timing':timing,'trace_audit':audit,'max_hard_dense_output_diff':max(diff.values()),'work':{str(k):{'expert_calls':k,'learned_linear_macs':CONTROLLER_MACS+k*EXPERT_MACS+HEAD_MACS,'prefix_linear_macs':k*EXPERT_MACS+HEAD_MACS,'dense_linear_macs':CONTROLLER_MACS+S*EXPERT_MACS+HEAD_MACS} for k in KS},'checks':{'hard_budget_compliance':all(len(audit[str(k)]['learned_hard'])==k and len(audit[str(k)]['prefix_hard'])==k for k in KS),'dense_executes_all':all(len(audit[str(k)]['learned_dense'])==S for k in KS),'hard_dense_outputs_match':max(diff.values())<1e-6,'learned_median_latency_monotonic':all(hm[i]<hm[i+1] for i in range(len(hm)-1))}}
def aggregate(rows):
    return {'seeds':len(rows),'all_budget_compliance':all(r['checks']['hard_budget_compliance'] for r in rows),'all_dense_executes_all':all(r['checks']['dense_executes_all'] for r in rows),'all_hard_dense_outputs_match':all(r['checks']['hard_dense_outputs_match'] for r in rows),'all_learned_latency_monotonic':all(r['checks']['learned_median_latency_monotonic'] for r in rows),'mean_learned_accuracy':{str(k):statistics.mean(r['learned_accuracy'][str(k)] for r in rows) for k in KS},'mean_prefix_accuracy':{str(k):statistics.mean(r['prefix_accuracy'][str(k)] for r in rows) for k in KS},'mean_learned_median_us':{str(k):statistics.mean(r['timing']['learned_hard'][str(k)]['median_us'] for r in rows) for k in KS},'mean_prefix_median_us':{str(k):statistics.mean(r['timing']['prefix_hard'][str(k)]['median_us'] for r in rows) for k in KS},'mean_dense_median_us':{str(k):statistics.mean(r['timing']['dense'][str(k)]['median_us'] for r in rows) for k in KS},'mean_relevant_fraction':{str(k):statistics.mean(r['selected_relevant_fraction'][str(k)] for r in rows) for k in KS}}
if __name__=='__main__':
    ap=argparse.ArgumentParser();ap.add_argument('--seeds',type=int,default=3);ap.add_argument('--reps',type=int,default=400);ap.add_argument('--rounds',type=int,default=3);ap.add_argument('--out',default=str(Path(__file__).resolve().parents[1]/'results'/'realtime_nn_learned_budget_gate_results.json'));a=ap.parse_args()
    try:c=sorted(os.sched_getaffinity(0))[0];os.sched_setaffinity(0,{c})
    except:pass
    rows=[]
    for s in range(a.seeds):
        r=run(s,a.reps,a.rounds);rows.append(r);print('seed',s,r['checks'],r['learned_accuracy'],r['prefix_accuracy'],flush=True)
    out={'setup':{'task':'8 slots; 4 relevant slots; label is strict majority over relevant bits','budgets_expert_calls':KS,'controller':'learned relevance scorer plus hard runtime top-k budget cap','physical_skip':'hard inference calls exactly k selected experts','dense_control':'all 8 experts computed then unselected outputs suppressed','timing_boundary':'ordinary Linux/PyTorch, not WCET'},'seeds':rows,'aggregate':aggregate(rows)};Path(a.out).write_text(json.dumps(out,indent=2));print(json.dumps(out['aggregate'],indent=2))
