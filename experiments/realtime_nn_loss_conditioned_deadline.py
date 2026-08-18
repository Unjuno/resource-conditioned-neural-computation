import argparse, json, math, random, statistics, time
from pathlib import Path
import torch
import realtime_nn_loss_conditioned_elastic_width as e


def percentile(v, p):
    s = sorted(v)
    return s[min(len(s) - 1, max(0, math.ceil(p * len(s)) - 1))]


def price_representatives(m, max_price=7.0, points=701):
    by = {}
    for i in range(points):
        price = max_price * i / (points - 1)
        by.setdefault(m.choose_k(price), []).append(price)
    return {k: (min(v) + max(v)) / 2 for k, v in by.items()}


def run_one(m, price, j):
    t = time.perf_counter_ns()
    z, _, k = m.physical_one(e.TEF[j:j + 1], e.TEM[j:j + 1], price)
    return (time.perf_counter_ns() - t) / 1000.0, int(z.argmax(1)), k


def run(seed=0, steps=850, cost_scale=0.55, calib_reps=300, test_reps=600):
    m = e.train(seed, True, steps, cost_scale)
    reps = price_representatives(m)
    reachable = sorted(reps)
    rng = random.Random(123 + seed)
    raw = {}
    with torch.inference_mode():
        for k in reachable:
            price = reps[k]
            vals = []
            for _ in range(50):
                j = rng.randrange(len(e.TEF)); run_one(m, price, j)
            for _ in range(calib_reps):
                j = rng.randrange(len(e.TEF)); vals.append(run_one(m, price, j)[0])
            raw[k] = {
                'price': price,
                'median_us': statistics.median(vals),
                'p95_us': percentile(vals, 0.95),
                'p99_us': percentile(vals, 0.99),
            }
    # monotone envelope over work classes; empirical soft admission only.
    bounds = {}
    prev = 0.0
    for k in reachable:
        bounds[k] = max(raw[k]['p95_us'], prev * 1.000001)
        prev = bounds[k]
    deadlines = {k: bounds[k] * 1.08 for k in reachable}
    req = [rng.randrange(len(e.TEF)) for _ in range(test_reps)]
    rows = []
    with torch.inference_mode():
        for target, deadline in deadlines.items():
            ok = [k for k in reachable if bounds[k] <= deadline]
            admitted = max(ok) if ok else min(reachable)
            price = reps[admitted]
            miss = correct = otc = 0
            vals = []
            for j in req:
                us, pred, actual_k = run_one(m, price, j)
                vals.append(us)
                hit = us <= deadline
                corr = pred == int(e.TEY[j])
                miss += int(not hit); correct += int(corr); otc += int(hit and corr)
            rows.append({
                'target_class': target,
                'deadline_us': deadline,
                'policy': 'price_conditioned',
                'admitted_k': admitted,
                'price': price,
                'miss_rate': miss / test_reps,
                'accuracy': correct / test_reps,
                'on_time_correct_rate': otc / test_reps,
                'median_us': statistics.median(vals),
            })
            full_k = max(reachable); full_price = reps[full_k]
            miss = correct = otc = 0
            vals = []
            for j in req:
                us, pred, _ = run_one(m, full_price, j)
                vals.append(us)
                hit = us <= deadline; corr = pred == int(e.TEY[j])
                miss += int(not hit); correct += int(corr); otc += int(hit and corr)
            rows.append({
                'target_class': target,
                'deadline_us': deadline,
                'policy': 'always_full',
                'admitted_k': full_k,
                'price': full_price,
                'miss_rate': miss / test_reps,
                'accuracy': correct / test_reps,
                'on_time_correct_rate': otc / test_reps,
                'median_us': statistics.median(vals),
            })
    return {
        'seed': seed,
        'timing_boundary': 'ordinary Linux/PyTorch empirical P95 soft/weakly-hard audit; not WCET',
        'representative_price_by_reachable_k': {str(k): v for k, v in reps.items()},
        'raw_calibration': {str(k): v for k, v in raw.items()},
        'monotone_p95_bounds_us': {str(k): v for k, v in bounds.items()},
        'rows': rows,
    }


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--seed', type=int, default=0)
    ap.add_argument('--steps', type=int, default=850)
    ap.add_argument('--cost-scale', type=float, default=0.55)
    ap.add_argument('--calib-reps', type=int, default=300)
    ap.add_argument('--test-reps', type=int, default=600)
    ap.add_argument('--out')
    args = ap.parse_args()
    out = run(args.seed, args.steps, args.cost_scale, args.calib_reps, args.test_reps)
    if args.out:
        Path(args.out).write_text(json.dumps(out, indent=2))
    print(json.dumps(out, indent=2))


if __name__ == '__main__':
    main()
