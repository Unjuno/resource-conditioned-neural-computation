import json, math, multiprocessing as mp, os, statistics, time
from pathlib import Path
import torch

from multicircuit_contract_transfer import (
    train_capabilities, clone_capabilities, train_router, profile_costs,
    bits_all, idx_all, y_all, make_price
)

# Empirical runtime-state experiment. Ordinary Linux/PyTorch timing only.
# This is NOT WCET or a hard-real-time guarantee.

torch.set_num_threads(1)
BASE = Path(__file__).resolve().parents[1]
OUT = BASE / 'results' / 'multicircuit_runtime_state_calibration_results.json'


def burner(cpu, stop):
    os.sched_setaffinity(0, {cpu})
    x = 1.000001
    while not stop.is_set():
        for _ in range(50000):
            x = x * 1.0000001 + 0.0000001


def q99(xs):
    ys = sorted(xs)
    n = len(ys)
    k = min(n - 1, math.ceil((n + 1) * 0.99) - 1)
    return ys[k]


def time_forced(model, route, price, N=1400):
    a = torch.zeros(1, 3); a[0, route] = 1
    p = torch.tensor([price], dtype=torch.float)
    ii = torch.tensor([173]); bb = bits_all[ii]
    with torch.no_grad():
        for _ in range(150):
            model.choose(p, a); model.forward_route(bb, ii, route)
        xs=[]
        for _ in range(N):
            t=time.perf_counter_ns()
            model.choose(p, a); model.forward_route(bb, ii, route)
            xs.append((time.perf_counter_ns()-t)/1000.0)
    xs.sort()
    return {
        'median': statistics.median(xs),
        'p95': xs[int(.95*(N-1))],
        'p99': xs[int(.99*(N-1))],
        'q99_order_stat': q99(xs),
        'max': xs[-1],
    }


def calibrate(model, price, N=1400):
    return [time_forced(model, r, price, N) for r in range(3)]


def mask_from_bounds(cal, D):
    return torch.tensor([[1.0 if x['q99_order_stat'] <= D else 0.0 for x in cal]])


def eval_condition(model, price, mask, D, N=3500):
    ii = torch.tensor([173]); bb=bits_all[ii]; target=int(y_all[ii])
    p=torch.tensor([price], dtype=torch.float)
    if mask.sum()==0:
        return {'admitted':False,'route':None,'miss':None,'accuracy':None,'mean_us':None,'p99_us':None}
    times=[]; misses=0; correct=0; routes=[]
    with torch.no_grad():
        for _ in range(N):
            t=time.perf_counter_ns()
            r=int(model.choose(p,mask)[0]); logits,_=model.forward_route(bb,ii,r)
            us=(time.perf_counter_ns()-t)/1000.0
            times.append(us); routes.append(r)
            misses += int(us>D)
            correct += int(int(logits.argmax(1))==target)
    times.sort()
    return {
        'admitted':True,
        'route': max(set(routes), key=routes.count),
        'route_hist':[routes.count(j)/N for j in range(3)],
        'miss': misses/N,
        'accuracy':correct/N,
        'mean_us':statistics.mean(times),
        'p99_us':times[int(.99*(N-1))],
        'max_us':times[-1],
    }


def run_once(rep):
    cpus=sorted(os.sched_getaffinity(0)); cpu=cpus[0]
    os.sched_setaffinity(0,{cpu})

    base=train_capabilities(rep % 3)
    C,_=profile_costs(base)
    model=train_router(clone_capabilities(base,True),100+rep,C,True)
    # footprint-scarce price makes tied-deep route preferred when all are available.
    price=make_price(0.03)

    idle_cal=calibrate(model,price,N=1800)

    stop=mp.Event(); proc=mp.Process(target=burner,args=(cpu,stop)); proc.start(); time.sleep(.25)
    try:
        load_cal=calibrate(model,price,N=1800)

        # Choose one deadline from the two calibration snapshots so that, when
        # the measured separation exists, all routes are admissible when idle
        # while the tied-deep route is rejected under contention and the two
        # lighter routes remain admissible. This is a constructed operating point,
        # not a universal deadline claim.
        lower=max(max(x['q99_order_stat'] for x in idle_cal),
                  load_cal[0]['q99_order_stat'], load_cal[1]['q99_order_stat'])
        upper=load_cal[2]['q99_order_stat']
        separation=upper > lower*1.05
        if separation:
            D=min(lower*1.20, (lower+upper)/2.0)
        else:
            D=lower*1.20

        idle_mask=mask_from_bounds(idle_cal,D)
        load_mask=mask_from_bounds(load_cal,D)
        idle_eval=eval_condition(model,price,idle_mask,D,N=3000)
        # Hold everything else fixed: same input, price, model and deadline.
        stale_eval=eval_condition(model,price,idle_mask,D,N=3000)
        fresh_eval=eval_condition(model,price,load_mask,D,N=3000)
    finally:
        stop.set(); proc.join()

    return {
        'rep':rep,'cpu':cpu,'price':price,'deadline_us':D,
        'calibration_separation_exists':separation,
        'idle_calibration':idle_cal,'loaded_calibration':load_cal,
        'idle_mask':idle_mask[0].tolist(),'loaded_mask':load_mask[0].tolist(),
        'idle_eval':idle_eval,
        'loaded_with_stale_idle_mask':stale_eval,
        'loaded_with_state_recalibrated_mask':fresh_eval,
    }

def main():
    rows=[run_once(r) for r in range(3)]
    fresh_misses=[r['loaded_with_state_recalibrated_mask']['miss'] for r in rows if r['loaded_with_state_recalibrated_mask']['miss'] is not None]
    fresh_acc=[r['loaded_with_state_recalibrated_mask']['accuracy'] for r in rows if r['loaded_with_state_recalibrated_mask']['accuracy'] is not None]
    summary={
        'repetitions':len(rows),
        'calibration_separation_reps':sum(int(r['calibration_separation_exists']) for r in rows),
        'idle_all_three_safe_reps':sum(int(r['idle_mask']==[1.0,1.0,1.0]) for r in rows),
        'loaded_excludes_tied_deep_reps':sum(int(r['loaded_mask'][2]==0.0) for r in rows),
        'loaded_keeps_at_least_one_light_route_reps':sum(int(r['loaded_mask'][0]==1.0 or r['loaded_mask'][1]==1.0) for r in rows),
        'runtime_state_changes_selected_route_reps':sum(int(r['idle_eval']['route'] is not None and r['loaded_with_state_recalibrated_mask']['route'] is not None and r['idle_eval']['route'] != r['loaded_with_state_recalibrated_mask']['route']) for r in rows),
        'stale_mask_mean_miss_under_load':sum(r['loaded_with_stale_idle_mask']['miss'] for r in rows if r['loaded_with_stale_idle_mask']['miss'] is not None)/sum(r['loaded_with_stale_idle_mask']['miss'] is not None for r in rows),
        'recalibrated_mask_mean_miss_under_load':sum(fresh_misses)/len(fresh_misses) if fresh_misses else None,
        'all_admitted_accuracy_1':all(x==1.0 for x in fresh_acc) and all(r['idle_eval']['accuracy']==1.0 for r in rows if r['idle_eval']['accuracy'] is not None),
    }
    OUT.write_text(json.dumps({'summary':summary,'runs':rows},indent=2))
    print(json.dumps(summary,indent=2))

if __name__=='__main__': main()
