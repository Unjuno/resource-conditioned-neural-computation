import argparse, json, math, os, random, statistics, time
from pathlib import Path
import torch
import realtime_nn_learned_budget_gate as b

torch.set_num_threads(1)
try: torch.set_num_interop_threads(1)
except RuntimeError: pass
KS=b.KS

def pct(vals,p):
    s=sorted(vals); return s[min(len(s)-1,max(0,math.ceil(p*len(s))-1))]
def summarize(vals):
    return {'median_us':statistics.median(vals),'p90_us':pct(vals,.90),'p95_us':pct(vals,.95),'p99_us':pct(vals,.99),'mean_us':statistics.mean(vals),'max_us':max(vals)}
@torch.no_grad()
def oracle_ids(mask,k): return mask.topk(k,dim=1).indices
@torch.no_grad()
def hard_oracle(m,bits,mask,k):
    ids=oracle_ids(mask,k); rows=[]
    for n in range(bits.size(0)):
        h=torch.zeros(b.H)
        for j in ids[n].tolist(): h=h+m.experts[j](torch.stack([bits[n,j],mask[n,j]]).view(1,2))[0]
        rows.append(h)
    h=torch.stack(rows); return m.head(torch.cat([h,torch.full((bits.size(0),1),float(k)/b.S)],1))
POLICIES=('learned_hard','prefix_hard','oracle_hard','dense_learned')
def policy_fn(m,name):
    if name=='learned_hard': return lambda bits,mask,k:m.hard(bits,mask,k,'learned')
    if name=='prefix_hard': return lambda bits,mask,k:m.hard(bits,mask,k,'prefix')
    if name=='oracle_hard': return lambda bits,mask,k:hard_oracle(m,bits,mask,k)
    if name=='dense_learned': return m.dense_infer
    raise KeyError(name)
def calibrate(m,seed,reps=700,warm=80):
    rng=random.Random(12000+seed); raw={p:{} for p in POLICIES}
    for p in POLICIES:
        fn=policy_fn(m,p)
        for k in KS:
            vals=[]
            with torch.inference_mode():
                for _ in range(warm):
                    j=rng.randrange(len(b.TEB)); fn(b.TEB[j:j+1],b.TEM[j:j+1],k)
                for _ in range(reps):
                    j=rng.randrange(len(b.TEB)); bits=b.TEB[j:j+1]; mask=b.TEM[j:j+1]
                    t0=time.perf_counter_ns(); fn(bits,mask,k); vals.append((time.perf_counter_ns()-t0)/1000.)
            raw[p][k]=summarize(vals)
    bounds={p:{} for p in POLICIES}
    for p in POLICIES:
        prev=0.
        for k in KS:
            v=max(raw[p][k]['p95_us'],prev*1.000001); bounds[p][k]=v; prev=v
    return raw,bounds
def admit(bounds,D):
    ok=[k for k in KS if bounds[k]<=D]; return max(ok) if ok else None
def learned_deadlines(bounds):
    out={}
    for i,k in enumerate(KS): out[k]=(bounds[k]+bounds[KS[i+1]])/2. if i+1<len(KS) else bounds[k]*1.15
    return out
def evaluate_deadlines(m,seed,bounds,deadlines,reps=800):
    rng=random.Random(14000+seed); request_ids=[rng.randrange(len(b.TEB)) for _ in range(reps)]; rows=[]
    for target_k in KS:
        D=deadlines[target_k]
        for p in ('learned_hard','prefix_hard','oracle_hard','dense_learned','always_full'):
            if p=='always_full': chosen_k=8; fn=policy_fn(m,'prefix_hard')
            else: chosen_k=admit(bounds[p],D); fn=policy_fn(m,p)
            misses=correct=ontime_correct=rejected=0; vals=[]
            with torch.inference_mode():
                for j in request_ids:
                    bits=b.TEB[j:j+1]; mask=b.TEM[j:j+1]; yy=int(b.TEY[j]); t0=time.perf_counter_ns()
                    if chosen_k is None:
                        vals.append((time.perf_counter_ns()-t0)/1000.); rejected+=1; misses+=1; continue
                    z=fn(bits,mask,chosen_k); us=(time.perf_counter_ns()-t0)/1000.; vals.append(us)
                    hit=us<=D; corr=int(z.argmax(1))==yy; misses+=int(not hit); correct+=int(corr); ontime_correct+=int(hit and corr)
            rows.append({'target_learned_class_k':target_k,'deadline_us':D,'policy':p,'admitted_k':chosen_k,'miss_rate':misses/reps,'accuracy':correct/reps,'on_time_correct_rate':ontime_correct/reps,'reject_rate':rejected/reps,'latency':summarize(vals)})
    return rows
@torch.no_grad()
def hook_budget_audit(m):
    out={}
    for p in ('learned_hard','prefix_hard','oracle_hard','dense_learned'):
        fn=policy_fn(m,p); out[p]={}
        for k in KS:
            hits=[]; hs=[e.register_forward_hook(lambda mod,inp,o,i=i:hits.append(i)) for i,e in enumerate(m.experts)]
            try: fn(b.TEB[:1],b.TEM[:1],k)
            finally:
                for h in hs:h.remove()
            out[p][str(k)]=hits
    return out
def run_seed(seed,calib_reps=700,test_reps=800):
    m=b.train(seed); raw,bounds=calibrate(m,seed,calib_reps); deadlines=learned_deadlines(bounds['learned_hard']); rows=evaluate_deadlines(m,seed,bounds,deadlines,test_reps); audit=hook_budget_audit(m)
    checks={'learned_hard_cap':all(len(audit['learned_hard'][str(k)])==k for k in KS),'prefix_hard_cap':all(len(audit['prefix_hard'][str(k)])==k for k in KS),'oracle_hard_cap':all(len(audit['oracle_hard'][str(k)])==k for k in KS),'dense_executes_all':all(len(audit['dense_learned'][str(k)])==b.S for k in KS),'learned_p95_monotone':all(bounds['learned_hard'][KS[i]]<bounds['learned_hard'][KS[i+1]] for i in range(len(KS)-1))}
    return {'seed':seed,'calibration':{p:{str(k):raw[p][k] for k in KS} for p in POLICIES},'p95_monotone_bounds_us':{p:{str(k):bounds[p][k] for k in KS} for p in POLICIES},'deadlines_us':{str(k):deadlines[k] for k in KS},'deadline_rows':rows,'hook_audit':audit,'checks':checks}
def aggregate(seeds):
    def rows_for(target,policy): return [next(r for r in s['deadline_rows'] if r['target_learned_class_k']==target and r['policy']==policy) for s in seeds]
    table={}
    for k in KS:
        table[str(k)]={}
        for p in ('learned_hard','prefix_hard','oracle_hard','dense_learned','always_full'):
            rr=rows_for(k,p); table[str(k)][p]={'mean_admitted_k':statistics.mean((r['admitted_k'] or 0) for r in rr),'mean_miss_rate':statistics.mean(r['miss_rate'] for r in rr),'mean_accuracy':statistics.mean(r['accuracy'] for r in rr),'mean_on_time_correct_rate':statistics.mean(r['on_time_correct_rate'] for r in rr),'mean_median_latency_us':statistics.mean(r['latency']['median_us'] for r in rr)}
    return {'all_budget_audits_pass':all(all(s['checks'].values()) for s in seeds),'by_target_learned_class':table}
def main():
    ap=argparse.ArgumentParser(); ap.add_argument('--seeds',type=int,default=3);ap.add_argument('--calib-reps',type=int,default=700);ap.add_argument('--test-reps',type=int,default=800);ap.add_argument('--out',default=str(Path(__file__).resolve().parents[1]/'results'/'realtime_nn_learned_deadline_results.json'));a=ap.parse_args()
    try:c=sorted(os.sched_getaffinity(0))[0];os.sched_setaffinity(0,{c})
    except Exception:pass
    rows=[]
    for s in range(a.seeds):
        r=run_seed(s,a.calib_reps,a.test_reps);rows.append(r);print('seed',s,r['checks'],flush=True)
    out={'setup':{'task':'8-slot relevance-majority toy from learned budget gate experiment','deadline_grid':'common absolute deadlines defined from learned-hard P95 class midpoints; all policies evaluated on same deadlines within each seed','admission':'policy-specific empirical P95 monotone execution-class bounds','policies':['learned_hard','prefix_hard','oracle_hard','dense_learned','always_full'],'timing_boundary':'ordinary Linux/PyTorch soft/weakly-hard prototype; not WCET/hard real time','oracle_boundary':'relevance mask is directly exposed by the synthetic task, so oracle_hard is an intentionally strong external baseline'},'seeds':rows,'aggregate':aggregate(rows)}
    Path(a.out).write_text(json.dumps(out,indent=2));print(json.dumps(out['aggregate'],indent=2))
if __name__=='__main__':main()
