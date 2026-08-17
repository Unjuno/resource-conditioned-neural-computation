import argparse, json, math, os, random, statistics, time
from pathlib import Path
import torch, torch.nn as nn, torch.nn.functional as F

torch.set_num_threads(1)
try: torch.set_num_interop_threads(1)
except RuntimeError: pass
ROOT=Path(__file__).resolve().parents[1]
S=8; R=4; Q=4; H=48; KS=[1,2,4,8]

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
TRF,TRR,TRY=make_data(20000,101); TEF,TER,TEY=make_data(5000,202)
class Expert(nn.Module):
    def __init__(self):
        super().__init__(); self.a=nn.Linear(1+2*Q,H); self.b=nn.Linear(H,4*H); self.c=nn.Linear(4*H,H)
    def forward(self,z):
        h=torch.tanh(self.a(z)); return torch.tanh(h+.2*self.c(F.gelu(self.b(h))))
class Net(nn.Module):
    def __init__(self):
        super().__init__(); self.experts=nn.ModuleList([Expert() for _ in range(S)]); self.ctrl=nn.Sequential(nn.Linear(2*Q+1,24),nn.Tanh(),nn.Linear(24,1)); self.head=nn.Linear(H+1,2)
    def scores(self,feat,k):
        z=torch.cat([feat[:,:,1:],torch.full((feat.size(0),S,1),float(k)/S)],-1); return self.ctrl(z).squeeze(-1)
    def train_forward(self,feat,k,tau=1.0):
        ex=torch.stack([e(feat[:,j]) for j,e in enumerate(self.experts)],1); sc=self.scores(feat,k); ids=sc.topk(k,1).indices
        hard=torch.zeros_like(sc); hard.scatter_(1,ids,1.)
        if k==S: gate=hard
        else:
            soft=torch.softmax(sc/tau,1)*k; gate=hard+(soft-soft.detach())
        h=(ex*gate[:,:,None]).sum(1); return self.head(torch.cat([h,torch.full((feat.size(0),1),float(k)/S)],1)),ids
    @torch.no_grad()
    def ids(self,feat,k,mode):
        if mode=='learned': return self.scores(feat,k).topk(k,1).indices
        if mode=='prefix': return torch.arange(k)[None,:].expand(feat.size(0),-1)
        if mode=='oracle':
            key=feat[:,:,1:1+Q].argmax(-1); query=feat[:,:,1+Q:].argmax(-1); return key.eq(query).float().topk(k,1).indices
        raise KeyError(mode)
    @torch.no_grad()
    def hard(self,feat,k,mode='learned'):
        ids=self.ids(feat,k,mode); rows=[]
        for n in range(feat.size(0)):
            h=torch.zeros(H)
            for j in ids[n].tolist(): h=h+self.experts[j](feat[n:n+1,j])[0]
            rows.append(h)
        h=torch.stack(rows); return self.head(torch.cat([h,torch.full((feat.size(0),1),float(k)/S)],1)),ids
    @torch.no_grad()
    def dense(self,feat,k):
        ex=torch.stack([e(feat[:,j]) for j,e in enumerate(self.experts)],1); ids=self.ids(feat,k,'learned'); sel=torch.zeros(feat.size(0),S); sel.scatter_(1,ids,1.); h=(ex*sel[:,:,None]).sum(1)
        return self.head(torch.cat([h,torch.full((feat.size(0),1),float(k)/S)],1)),ids

def train(seed,steps=1200):
    torch.manual_seed(seed); random.seed(seed); m=Net(); opt=torch.optim.AdamW(m.parameters(),lr=2e-3,weight_decay=1e-6); rng=random.Random(300+seed)
    for step in range(steps):
        ix=torch.randint(0,len(TRF),(256,)); k=rng.choice(KS); tau=max(.3,1-step/steps*.7)
        z,_=m.train_forward(TRF[ix],k,tau); loss=F.cross_entropy(z,TRY[ix]); opt.zero_grad(); loss.backward(); torch.nn.utils.clip_grad_norm_(m.parameters(),5); opt.step()
    return m.eval()
@torch.no_grad()
def accuracy(m,mode):
    out={}
    for k in KS:
        preds=[]; rel=[]
        for a in range(0,len(TEF),256):
            z,ids=m.hard(TEF[a:a+256],k,mode); preds.append(z.argmax(1)); rel.append(torch.gather(TER[a:a+256],1,ids).mean())
        out[str(k)]={'accuracy':float((torch.cat(preds)==TEY).float().mean()),'selected_relevant_fraction':float(torch.stack(rel).mean())}
    return out
def pct(v,p):
    s=sorted(v); return s[min(len(s)-1,max(0,math.ceil(p*len(s))-1))]
def summ(v): return {'median_us':statistics.median(v),'p90_us':pct(v,.9),'p95_us':pct(v,.95),'p99_us':pct(v,.99),'mean_us':statistics.mean(v),'max_us':max(v)}
def fn_for(m,policy):
    if policy=='learned_hard': return lambda x,k:m.hard(x,k,'learned')[0]
    if policy=='prefix_hard': return lambda x,k:m.hard(x,k,'prefix')[0]
    if policy=='oracle_hard': return lambda x,k:m.hard(x,k,'oracle')[0]
    if policy=='dense_learned': return lambda x,k:m.dense(x,k)[0]
    raise KeyError(policy)
def timing(m,seed,reps=250,rounds=1):
    rng=random.Random(5000+seed); policies=['learned_hard','prefix_hard','oracle_hard','dense_learned']; raw={(p,k):[] for p in policies for k in KS}; order=list(raw)
    with torch.inference_mode():
        for _ in range(rounds):
            rng.shuffle(order)
            for p,k in order:
                fn=fn_for(m,p)
                for _ in range(40): j=rng.randrange(len(TEF)); fn(TEF[j:j+1],k)
                for _ in range(reps):
                    j=rng.randrange(len(TEF)); t=time.perf_counter_ns(); fn(TEF[j:j+1],k); raw[(p,k)].append((time.perf_counter_ns()-t)/1000.)
    return {p:{str(k):summ(raw[(p,k)]) for k in KS} for p in policies}
@torch.no_grad()
def hook_audit(m):
    out={}
    for p in ['learned_hard','prefix_hard','oracle_hard','dense_learned']:
        out[p]={}
        for k in KS:
            hits=[]; hs=[e.register_forward_hook(lambda mod,inp,o,i=i:hits.append(i)) for i,e in enumerate(m.experts)]
            try: fn_for(m,p)(TEF[:1],k)
            finally:
                for h in hs:h.remove()
            out[p][str(k)]=hits
    return out
def deadline_test(m,seed,calib_reps=400,test_reps=500):
    policies=['learned_hard','prefix_hard','oracle_hard','dense_learned']; rng=random.Random(9000+seed); raw={p:{} for p in policies}
    for p in policies:
        fn=fn_for(m,p)
        for k in KS:
            vals=[]
            with torch.inference_mode():
                for _ in range(60): j=rng.randrange(len(TEF)); fn(TEF[j:j+1],k)
                for _ in range(calib_reps):
                    j=rng.randrange(len(TEF)); t=time.perf_counter_ns(); fn(TEF[j:j+1],k); vals.append((time.perf_counter_ns()-t)/1000.)
            raw[p][k]=summ(vals)
    bounds={p:{} for p in policies}
    for p in policies:
        prev=0.
        for k in KS:
            bounds[p][k]=max(raw[p][k]['p95_us'],prev*1.000001); prev=bounds[p][k]
    lb=bounds['learned_hard']; deadlines={k:((lb[k]+lb[KS[i+1]])/2 if i+1<len(KS) else lb[k]*1.15) for i,k in enumerate(KS)}
    def admit(bb,D):
        ok=[k for k in KS if bb[k]<=D]; return max(ok) if ok else None
    req=[rng.randrange(len(TEF)) for _ in range(test_reps)]; rows=[]
    for target in KS:
        D=deadlines[target]
        for p in ['learned_hard','prefix_hard','oracle_hard','dense_learned','always_full']:
            if p=='always_full': k=8; fn=fn_for(m,'prefix_hard')
            else: k=admit(bounds[p],D); fn=fn_for(m,p)
            miss=corr=ontime=reject=0; vals=[]
            with torch.inference_mode():
                for j in req:
                    t=time.perf_counter_ns()
                    if k is None: vals.append((time.perf_counter_ns()-t)/1000.); miss+=1; reject+=1; continue
                    z=fn(TEF[j:j+1],k); us=(time.perf_counter_ns()-t)/1000.; vals.append(us); c=int(z.argmax(1))==int(TEY[j]); hit=us<=D
                    miss+=int(not hit); corr+=int(c); ontime+=int(c and hit)
            rows.append({'target_learned_class_k':target,'deadline_us':D,'policy':p,'admitted_k':k,'miss_rate':miss/test_reps,'accuracy':corr/test_reps,'on_time_correct_rate':ontime/test_reps,'reject_rate':reject/test_reps,'latency':summ(vals)})
    return {'bounds_us':{p:{str(k):bounds[p][k] for k in KS} for p in policies},'deadlines_us':{str(k):deadlines[k] for k in KS},'rows':rows}
def run(seed):
    m=train(seed); a={mode:accuracy(m,mode) for mode in ['learned','prefix','oracle']}; t=timing(m,seed); hooks=hook_audit(m); dl=deadline_test(m,seed); lm=[t['learned_hard'][str(k)]['median_us'] for k in KS]
    checks={'learned_hard_cap':all(len(hooks['learned_hard'][str(k)])==k for k in KS),'prefix_hard_cap':all(len(hooks['prefix_hard'][str(k)])==k for k in KS),'oracle_hard_cap':all(len(hooks['oracle_hard'][str(k)])==k for k in KS),'dense_all':all(len(hooks['dense_learned'][str(k)])==S for k in KS),'learned_latency_monotonic':all(lm[i]<lm[i+1] for i in range(3))}
    return {'seed':seed,'accuracy':a,'timing':t,'hook_audit':hooks,'deadline':dl,'checks':checks}
def aggregate(rows):
    out={'all_checks_pass':all(all(r['checks'].values()) for r in rows),'accuracy':{},'timing':{},'deadline':{}}
    for k in KS:
        out['accuracy'][str(k)]={mode:statistics.mean(r['accuracy'][mode][str(k)]['accuracy'] for r in rows) for mode in ['learned','prefix','oracle']}; out['accuracy'][str(k)]['learned_relevance']=statistics.mean(r['accuracy']['learned'][str(k)]['selected_relevant_fraction'] for r in rows)
        out['timing'][str(k)]={p:statistics.mean(r['timing'][p][str(k)]['median_us'] for r in rows) for p in ['learned_hard','prefix_hard','oracle_hard','dense_learned']}
        out['deadline'][str(k)]={}
        for p in ['learned_hard','prefix_hard','oracle_hard','dense_learned','always_full']:
            rr=[next(x for x in r['deadline']['rows'] if x['target_learned_class_k']==k and x['policy']==p) for r in rows]; out['deadline'][str(k)][p]={'mean_admitted_k':statistics.mean((x['admitted_k'] or 0) for x in rr),'mean_miss_rate':statistics.mean(x['miss_rate'] for x in rr),'mean_accuracy':statistics.mean(x['accuracy'] for x in rr),'mean_on_time_correct_rate':statistics.mean(x['on_time_correct_rate'] for x in rr)}
    return out
def main():
    ap=argparse.ArgumentParser(); ap.add_argument('--seed',type=int);ap.add_argument('--seeds',type=int,default=3);ap.add_argument('--out',default=str(ROOT/'results'/'realtime_nn_task_only_gate_results.json'));a=ap.parse_args()
    try:c=sorted(os.sched_getaffinity(0))[0];os.sched_setaffinity(0,{c})
    except Exception:pass
    ss=[a.seed] if a.seed is not None else list(range(a.seeds));rows=[]
    for s in ss:
        r=run(s);rows.append(r);print('seed',s,r['checks'],r['accuracy']['learned'],flush=True)
    out={'setup':{'task':'8 slots with categorical keys and a global query; exactly 4 key-query matches; label is strict majority of matching-slot bits','controller_training':'task loss only; no relevance labels or relevance auxiliary loss; straight-through hard top-k surrogate; no capability warmup','hard_budget':'inference physically executes exactly k selected experts','oracle':'external analytic key==query relevance selector retained as strong baseline','timing_boundary':'ordinary Linux/PyTorch empirical timing; not WCET/hard real time'},'seeds':rows,'aggregate':aggregate(rows)};Path(a.out).write_text(json.dumps(out,indent=2));print(json.dumps(out['aggregate'],indent=2))
if __name__=='__main__':main()
