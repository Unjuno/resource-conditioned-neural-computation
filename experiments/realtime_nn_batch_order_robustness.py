import argparse, json, random, statistics
from pathlib import Path

import torch
import torch.nn.functional as F

from realtime_nn_incremental_refinement import (
    ROOT, TRAIN_N, TRF, TRY, SharedHead, audit_model,
)


def train(model_seed: int, batch_seed: int, steps: int = 800):
    torch.manual_seed(model_seed)
    random.seed(model_seed)
    m = SharedHead()
    opt = torch.optim.AdamW(m.parameters(), lr=2e-3, weight_decay=1e-6)
    g = torch.Generator().manual_seed(batch_seed)
    for step in range(steps):
        ix = torch.randint(0, TRAIN_N, (256,), generator=g)
        feat, y = TRF[ix], TRY[ix]
        tau = max(0.3, 1.0 - step / steps * 0.7)
        outs = m.train_logits_all(feat, tau)
        loss = torch.stack([F.cross_entropy(z, y) for z in outs]).mean()
        opt.zero_grad()
        loss.backward()
        torch.nn.utils.clip_grad_norm_(m.parameters(), 5.0)
        opt.step()
    return m.eval()


def run_one(model_seed, batch_seed, steps):
    m = train(model_seed, batch_seed, steps)
    return {"model_seed": model_seed, "batch_seed": batch_seed, **audit_model(m)}


def aggregate(rows):
    strict = sum(r["strict_non_decreasing"] for r in rows)
    mean_acc = {str(k): statistics.mean(r["accuracy"][str(k)] for r in rows) for k in range(1, 9)}
    out = {
        "strict_monotonic_runs": strict,
        "total_runs": len(rows),
        "strict_fraction": strict / len(rows),
        "mean_max_adjacent_drop_pp": statistics.mean(r["max_adjacent_drop_pp"] for r in rows),
        "max_observed_adjacent_drop_pp": max(r["max_adjacent_drop_pp"] for r in rows),
        "mean_accuracy": mean_acc,
        "all_nested_zero": all(r["nested_violations"] == 0 for r in rows),
        "all_hard_cap_pass": all(r["hard_cap_pass"] for r in rows),
    }
    decision = (
        out["strict_fraction"] >= 0.8
        and out["mean_max_adjacent_drop_pp"] <= 0.1
        and mean_acc["4"] >= 0.98
        and out["all_nested_zero"]
        and out["all_hard_cap_pass"]
    )
    out["hypothesis"] = {
        "H": "Joint all-class training is robust to minibatch order on the supplied task.",
        "PASS_conditions": {
            "strict_fraction_min": 0.8,
            "mean_max_adjacent_drop_pp_max": 0.1,
            "k4_accuracy_min": 0.98,
            "nested_violations": 0,
            "hard_cap": True,
        },
        "decision": "PASS" if decision else "FAIL",
    }
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--model-seeds", default="0,1,2")
    ap.add_argument("--batch-seeds", default="100,101,102")
    ap.add_argument("--steps", type=int, default=800)
    ap.add_argument("--out", default=str(ROOT / "results" / "realtime_nn_batch_order_robustness_results.json"))
    a = ap.parse_args()
    model_seeds = [int(x) for x in a.model_seeds.split(",") if x]
    batch_seeds = [int(x) for x in a.batch_seeds.split(",") if x]
    rows = []
    for ms in model_seeds:
        for bs in batch_seeds:
            r = run_one(ms, bs, a.steps)
            rows.append(r)
            print(ms, bs, r["strict_non_decreasing"], r["max_adjacent_drop_pp"], flush=True)
    result = {
        "setup": {
            "model_seeds": model_seeds,
            "batch_seeds": batch_seeds,
            "steps": a.steps,
            "training": "joint all-8-class CE",
            "architecture": "shared hidden-state accumulation baseline",
            "purpose": "separate model initialization from minibatch-order randomness",
            "timing_claim": "none",
        },
        "runs": rows,
        "aggregate": aggregate(rows),
    }
    Path(a.out).parent.mkdir(parents=True, exist_ok=True)
    Path(a.out).write_text(json.dumps(result, indent=2))
    print(json.dumps(result["aggregate"], indent=2))


if __name__ == "__main__":
    main()
