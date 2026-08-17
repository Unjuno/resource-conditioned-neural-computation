import argparse, json, math, multiprocessing as mp, os, random, statistics, time
from pathlib import Path
import torch
import realtime_nn_budget_execution as b

torch.set_num_threads(1)
try: torch.set_num_interop_threads(1)
except RuntimeError: pass
ROOT=Path(__file__).resolve().parents[1]
B=b.BUDGETS

def periodic_worker(cpu,stop,busy_ms=.35,sleep_ms=1.65):
    try: os.sched_setaffinity(0,{cpu})
    except Exception: pass
    x=1.000001
    while not stop.is_set():
        end=time.perf_counter()+busy_ms/1000.
        while time.perf_counter()<end:
            x=x*1.0000001+0.0000001
        time.sleep(sleep_ms/1000.)

def busy_worker(cpu,stop):
    try: os.sched_setaffinity(0,{cpu})
    except Exception: pass
    x=1.000001
    while not stop.is_set(): x=x*1.0000001+0.0000001

def pct(v,p):
    s=sorted(v); return s[min(len(s)-1,max(0,math.ceil(p*len(s))-1))]

def interleaved_measure(m,seed,per_budget):
    rng=random.Random(seed); vals={bb:[] for bb in B}; seq=[]
    for bb in B: seq += [bb]*per_budget
    rng.shuffle(seq)
    with torch.inference_mode():
        for _ in range(80): m.hard(b.X[341:342],1.0)
        for bb in seq:
            j=rng.randrange(b.N); t=time.perf_counter_ns(); m.hard(b.X[j:j+1],bb); vals[bb].append((time.perf_counter_ns()-t)/1000.)
    return {str(bb):{'p50_us':pct(vals[bb],.50),'p95_us':pct(vals[bb],.95),'p99_us':pct(vals[bb],.99),'max_us':max(vals[bb])} for bb in B}

def repeated_state(m,cpu,mode,repeats,per_budget,seedbase):
    out=[]; stop=None; p=None
    if mode!='idle':
        stop=mp.Event(); target=periodic_worker if mode=='periodic' else busy_worker; args=(cpu,stop)
        p=mp.Process(target=target,args=args); p.start(); time.sleep(.25)
    try:
        for r in range(repeats): out.append(interleaved_measure(m,seedbase+r,per_budget))
    finally:
        if p is not None:
            stop.set(); p.join(timeout=2)
            if p.is_alive(): p.terminate(); p.join()
    return out

def summarize_repeats(rows):
    out={}
    for bb in B:
        xs=[r[str(bb)]['p95_us'] for r in rows]; mu=statistics.mean(xs)
        out[str(bb)]={'mean_p95_us':mu,'min_p95_us':min(xs),'max_p95_us':max(xs),'cv':statistics.pstdev(xs)/mu if mu else 0.,'values_us':xs}
    return out

def high_sample_busy_probe(m,cpu,per_budget=1800):
    stop=mp.Event(); p=mp.Process(target=busy_worker,args=(cpu,stop)); p.start(); time.sleep(.3)
    vals={bb:[] for bb in [.25,.5,.75,1.]}; rng=random.Random(918273); seq=[]
    for bb in vals: seq += [bb]*per_budget
    rng.shuffle(seq)
    try:
        with torch.inference_mode():
            for _ in range(100): m.hard(b.X[341:342],1.)
            for bb in seq:
                j=rng.randrange(b.N); t=time.perf_counter_ns(); m.hard(b.X[j:j+1],bb); vals[bb].append((time.perf_counter_ns()-t)/1000.)
    finally:
        stop.set(); p.join(timeout=2)
        if p.is_alive(): p.terminate(); p.join()
    out={}
    for bb,v in vals.items():
        out[str(bb)]={'n':len(v),'p50_us':pct(v,.50),'p90_us':pct(v,.90),'p95_us':pct(v,.95),'p97_us':pct(v,.97),'p99_us':pct(v,.99),'max_us':max(v),'fraction_over_4ms':sum(x>4000 for x in v)/len(v)}
    return out

def run_seed(seed,repeats,per_budget,include_high_sample=False):
    cpu=sorted(os.sched_getaffinity(0))[0]; os.sched_setaffinity(0,{cpu}); m=b.train(seed)
    states={}
    for i,mode in enumerate(('idle','periodic','busy')):
        rr=repeated_state(m,cpu,mode,repeats,per_budget,10000+seed*1000+i*100)
        states[mode]={'repeats':rr,'summary':summarize_repeats(rr)}
    out={'seed':seed,'states':states,'load_over_idle_mean_p95_ratio':{}}
    for mode in ('periodic','busy'):
        out['load_over_idle_mean_p95_ratio'][mode]={str(bb):states[mode]['summary'][str(bb)]['mean_p95_us']/states['idle']['summary'][str(bb)]['mean_p95_us'] for bb in B}
    if include_high_sample: out['continuous_busy_high_sample']=high_sample_busy_probe(m,cpu)
    return out

def main():
    ap=argparse.ArgumentParser(); ap.add_argument('--seeds',type=int,default=2); ap.add_argument('--repeats',type=int,default=6); ap.add_argument('--per-budget',type=int,default=160); ap.add_argument('--high-sample-seed',type=int,default=0); ap.add_argument('--out',default=str(ROOT/'results'/'realtime_nn_machine_state_timing_audit_results.json')); a=ap.parse_args()
    rows=[]
    for seed in range(a.seeds):
        r=run_seed(seed,a.repeats,a.per_budget,seed==a.high_sample_seed); rows.append(r); print('seed',seed,'busy-cv',{k:round(v['cv'],3) for k,v in r['states']['busy']['summary'].items()},flush=True)
    out={'setup':{'model':'fixed-depth direct Real-Time NN','machine_states':['idle','same-core periodic competitor','same-core continuous busy competitor'],'calibration':'randomly interleaved budget measurements; repeated empirical P95 estimates','timing_boundary':'ordinary Linux/PyTorch timing; diagnostic only, not WCET/hard real time','purpose':'test whether a categorical machine-state -> empirical P95 timing table is stable enough for runtime admission'},'seeds':rows,'conclusion':{'stable_state_to_p95_table_established':False,'reason':'Repeated P95 estimates can switch between fast and scheduler-preempted latency modes; a single categorical state label does not yield stable execution-class bounds on ordinary Linux.','systems_implication':'Real hard-RT use needs scheduler/interference control, time-predictable execution, or defensible WCET; reducing NN work can reduce exposure to interference but cannot certify deadlines by itself.'}}
    Path(a.out).write_text(json.dumps(out,indent=2)); print(json.dumps(out['conclusion'],indent=2))
if __name__=='__main__': main()
