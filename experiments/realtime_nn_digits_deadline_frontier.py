import argparse,random,time,math,statistics,json,torch
from pathlib import Path
import realtime_nn_digits_budget_gate as b
ROOT=Path(__file__).resolve().parents[1] if '__file__' in globals() else Path('.')

def pct(v,p):
 s=sorted(v);return s[min(len(s)-1,max(0,math.ceil(p*len(s))-1))]
def calibrate(m,seed,subs,reps=260):
 rng=random.Random(3000+seed);pols=['learned','static','prefix'];raw={p:{} for p in pols}
 for p in pols:
  for k in b.KS:
   vals=[]
   for _ in range(45):
    j=rng.randrange(len(b.TEX));
    if p=='learned':m.hard(b.TEX[j:j+1],k,'learned')
    elif p=='prefix':m.hard(b.TEX[j:j+1],k,'prefix')
    else:m.hard(b.TEX[j:j+1],k,'subset',subs[k])
   for _ in range(reps):
    j=rng.randrange(len(b.TEX));t=time.perf_counter_ns()
    if p=='learned':m.hard(b.TEX[j:j+1],k,'learned')
    elif p=='prefix':m.hard(b.TEX[j:j+1],k,'prefix')
    else:m.hard(b.TEX[j:j+1],k,'subset',subs[k])
    vals.append((time.perf_counter_ns()-t)/1000.)
   raw[p][k]={'p50':statistics.median(vals),'p95':pct(vals,.95),'p99':pct(vals,.99)}
 bounds={p:{} for p in pols}
 for p in pols:
  prev=0
  for k in b.KS: bounds[p][k]=max(raw[p][k]['p95'],prev*1.000001);prev=bounds[p][k]
 return raw,bounds
def admit(bounds,D):
 ok=[k for k in b.KS if bounds[k]<=D];return max(ok) if ok else None
def eval_policy(m,p,k,subs,j):
 if p=='learned':return m.hard(b.TEX[j:j+1],k,'learned')[0]
 if p=='prefix':return m.hard(b.TEX[j:j+1],k,'prefix')[0]
 return m.hard(b.TEX[j:j+1],k,'subset',subs[k])[0]
def run(seed):
 m=b.train(seed);subs={k:b.best_static(m,k)[1] for k in b.KS};raw,bounds=calibrate(m,seed,subs)
 lo=min(bounds[p][1] for p in bounds)*.85;hi=max(bounds[p][8] for p in bounds)*1.15
 deadlines=[math.exp(math.log(lo)+(math.log(hi)-math.log(lo))*i/19) for i in range(20)]
 rng=random.Random(6000+seed);req=[rng.randrange(len(b.TEX)) for _ in range(180)];rows=[]
 for di,D in enumerate(deadlines):
  for p in ['learned','static','prefix']:
   k=admit(bounds[p],D);miss=corr=otc=reject=0
   for j in req:
    t=time.perf_counter_ns()
    if k is None:miss+=1;reject+=1;continue
    z=eval_policy(m,p,k,subs,j);us=(time.perf_counter_ns()-t)/1000.;c=int(z.argmax(1))==int(b.TEY[j]);hit=us<=D;miss+=int(not hit);corr+=int(c);otc+=int(c and hit)
   rows.append({'deadline_index':di,'deadline_us':D,'policy':p,'admitted_k':k,'miss_rate':miss/len(req),'accuracy':corr/len(req),'on_time_correct':otc/len(req),'reject_rate':reject/len(req)})
 return {'seed':seed,'subsets':{str(k):list(v) for k,v in subs.items()},'calibration':{'raw':raw,'bounds':bounds},'rows':rows}
def aggregate(seed_rows):
    front=[]
    for di in range(20):
        e={'deadline_index':di,'mean_deadline_us':statistics.mean(next(x for x in r['rows'] if x['deadline_index']==di and x['policy']=='learned')['deadline_us'] for r in seed_rows)}
        for p in ['learned','static','prefix']:
            rr=[next(x for x in r['rows'] if x['deadline_index']==di and x['policy']==p) for r in seed_rows]
            e[p]={'mean_miss':statistics.mean(x['miss_rate'] for x in rr),'mean_otc':statistics.mean(x['on_time_correct'] for x in rr),'mean_accuracy':statistics.mean(x['accuracy'] for x in rr),'mean_k':statistics.mean((x['admitted_k'] or 0) for x in rr),'mean_reject':statistics.mean(x['reject_rate'] for x in rr)}
        front.append(e)
    matched=[]
    for e in front:
        l,s=e['learned'],e['static']
        if l['mean_reject']<1 and s['mean_reject']<1 and abs(l['mean_miss']-s['mean_miss'])<=.03:
            matched.append({'deadline_index':e['deadline_index'],'mean_deadline_us':e['mean_deadline_us'],'learned_mean_k':l['mean_k'],'static_mean_k':s['mean_k'],'learned_miss':l['mean_miss'],'static_miss':s['mean_miss'],'learned_otc':l['mean_otc'],'static_otc':s['mean_otc'],'delta_otc':l['mean_otc']-s['mean_otc']})
    return {'frontier':front,'matched_definition':'abs(mean learned miss - mean static miss) <= 0.03, neither fully rejected','matched_count':len(matched),'learned_positive_count':sum(x['delta_otc']>0 for x in matched),'mean_delta_otc':statistics.mean(x['delta_otc'] for x in matched) if matched else None,'median_delta_otc':statistics.median(x['delta_otc'] for x in matched) if matched else None,'matched_points':matched}

def main():
    ap=argparse.ArgumentParser(); ap.add_argument('--seed',type=int); ap.add_argument('--seeds',type=int,default=3); ap.add_argument('--out',default=str(ROOT/'results'/'realtime_nn_digits_deadline_frontier_results.json')); a=ap.parse_args()
    seeds=[a.seed] if a.seed is not None else list(range(a.seeds)); rows=[]
    for seed in seeds:
        r=run(seed); rows.append(r); print('seed',seed,'done',flush=True)
    result={'setup':{'comparison':'per-seed common absolute deadline sweep; each policy admits largest k fitting its own empirical monotone P95 bound','policies':['learned input-dependent','validation-selected static subset','prefix'],'timing_boundary':'ordinary Linux/PyTorch empirical P95; soft/weakly-hard only'},'seeds':rows,'aggregate':aggregate(rows)}
    Path(a.out).write_text(json.dumps(result,indent=2)); print(json.dumps({k:result['aggregate'][k] for k in ['matched_count','learned_positive_count','mean_delta_otc','median_delta_otc']},indent=2))
if __name__=='__main__': main()
