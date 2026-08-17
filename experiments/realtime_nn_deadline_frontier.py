import argparse, json, math, os, random, statistics, time
from pathlib import Path
import torch
import realtime_nn_learned_budget_gate as b
import realtime_nn_learned_deadline_integration as d

torch.set_num_threads(1)
try: torch.set_num_interop_threads(1)
except RuntimeError: pass
ROOT=Path(__file__).resolve().parents[1]
POLICIES=('learned_hard','prefix_hard','oracle_hard','dense_learned','always_full')

def eval_policy(m,policy,bounds,D,ids):
    if policy=='always_full': k=8; fn=d.policy_fn(m,'prefix_hard')
    else: k=d.admit(bounds[policy],D); fn=d.policy_fn(m,policy)
    miss=correct=otc=reject=0; vals=[]
    with torch.inference_mode():
        for j in ids:
            bits=b.TEB[j:j+1]; mask=b.TEM[j:j+1]; yy=int(b.TEY[j]); t0=time.perf_counter_ns()
            if k is None:
                vals.append((time.perf_counter_ns()-t0)/1000.); miss+=1; reject+=1; continue
            z=fn(bits,mask,k); us=(time.perf_counter_ns()-t0)/1000.; vals.append(us); hit=us<=D; corr=int(z.argmax(1))==yy
            miss+=int(not hit); correct+=int(corr); otc+=int(hit and corr)
    return {'deadline_us':D,'policy':policy,'admitted_k':k,'miss_rate':miss/len(ids),'accuracy':correct/len(ids),'on_time_correct_rate':otc/len(ids),'reject_rate':reject/len(ids),'median_us':statistics.median(vals)}

def run_seed(seed,calib_reps=350,test_reps=350,n_deadlines=25):
    m=b.train(seed); _,bounds=d.calibrate(m,seed,calib_reps)
    lo=max(5.0,bounds['learned_hard'][1]*.8); hi=max(bounds['learned_hard'][8],bounds['prefix_hard'][8],bounds['oracle_hard'][8])*1.2
    deadlines=[math.exp(math.log(lo)+(math.log(hi)-math.log(lo))*i/(n_deadlines-1)) for i in range(n_deadlines)]
    rng=random.Random(22000+seed); ids=[rng.randrange(len(b.TEB)) for _ in range(test_reps)]; rows=[]
    for D in deadlines:
        for p in POLICIES: rows.append(eval_policy(m,p,bounds,D,ids))
    return {'seed':seed,'rows':rows}

def aggregate(seeds,n_deadlines):
    frontier=[]
    for i in range(n_deadlines):
        e={'deadline_index':i,'mean_deadline_us':statistics.mean([r for r in s['rows'] if r['policy']=='learned_hard'][i]['deadline_us'] for s in seeds)}
        for p in POLICIES:
            rr=[[r for r in s['rows'] if r['policy']==p][i] for s in seeds]
            e[p]={'mean_admitted_k':statistics.mean((r['admitted_k'] or 0) for r in rr),'mean_miss_rate':statistics.mean(r['miss_rate'] for r in rr),'mean_accuracy':statistics.mean(r['accuracy'] for r in rr),'mean_on_time_correct_rate':statistics.mean(r['on_time_correct_rate'] for r in rr)}
        frontier.append(e)
    matched=[]
    for e in frontier:
        l=e['learned_hard']; p=e['prefix_hard']
        if abs(l['mean_miss_rate']-p['mean_miss_rate'])<=.02:
            matched.append({'deadline_us':e['mean_deadline_us'],'learned_miss':l['mean_miss_rate'],'prefix_miss':p['mean_miss_rate'],'learned_otc':l['mean_on_time_correct_rate'],'prefix_otc':p['mean_on_time_correct_rate'],'delta_otc':l['mean_on_time_correct_rate']-p['mean_on_time_correct_rate'],'learned_k':l['mean_admitted_k'],'prefix_k':p['mean_admitted_k']})
    return {'frontier':frontier,'matched_miss_common_deadlines':matched,'matched_count':len(matched),'matched_learned_positive_count':sum(x['delta_otc']>0 for x in matched),'matched_mean_delta_otc':statistics.mean(x['delta_otc'] for x in matched) if matched else None}

def main():
    ap=argparse.ArgumentParser(); ap.add_argument('--seed',type=int); ap.add_argument('--seeds',type=int,default=3); ap.add_argument('--calib-reps',type=int,default=350); ap.add_argument('--test-reps',type=int,default=350); ap.add_argument('--deadlines',type=int,default=25); ap.add_argument('--out',default=str(ROOT/'results'/'realtime_nn_deadline_frontier_results.json')); a=ap.parse_args()
    try: os.sched_setaffinity(0,{sorted(os.sched_getaffinity(0))[0]})
    except Exception: pass
    ids=[a.seed] if a.seed is not None else list(range(a.seeds)); seeds=[]
    for seed in ids:
        r=run_seed(seed,a.calib_reps,a.test_reps,a.deadlines); seeds.append(r); print('seed',seed,'done',flush=True)
    out={'setup':{'task':'explicit-relevance learned-budget-gate toy','comparison':'common absolute deadline sweep; each policy admits largest k fitting its own empirical monotone P95 class bound','primary_metric':'on_time_correct_rate','matched_definition':'absolute learned-vs-prefix miss-rate difference <= 2 percentage points','timing_boundary':'ordinary Linux/PyTorch soft/weakly-hard prototype; not WCET'},'seeds':seeds,'aggregate':aggregate(seeds,a.deadlines)}
    Path(a.out).write_text(json.dumps(out,indent=2)); print(json.dumps({k:out['aggregate'][k] for k in ('matched_count','matched_learned_positive_count','matched_mean_delta_otc')},indent=2))
if __name__=='__main__': main()
