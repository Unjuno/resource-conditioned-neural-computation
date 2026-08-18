import argparse, json, random, statistics
from pathlib import Path

import torch
import torch.nn.functional as F

from realtime_nn_continuous_budget_ordering import (
    S, TRAIN_N, TEST_N, TRF, TRY, TEF, TEY,
    BudgetOrderingNet, nestedness_audit, hard_cap_hook_audit,
)

ROOT = Path(__file__).resolve().parents[1]


def train_joint(seed: int, steps: int = 800):
    torch.manual_seed(seed)
    random.seed(seed)
    m = BudgetOrderingNet("nested")
    opt = torch.optim.AdamW(m.parameters(), lr=2e-3, weight_decay=1e-6)
    for step in range(steps):
        ix = torch.randint(0, TRAIN_N, (256,))
        feat = TRF[ix]
        y = TRY[ix]
        ex = torch.stack([e(feat[:, j]) for j, e in enumerate(m.experts)], 1)
        sc = m.scores(feat, 0.0)
        tau = max(0.3, 1.0 - step / steps * 0.7)
        losses = []
        for k in range(1, S + 1):
            ids = sc.topk(k, 1).indices
            hard = torch.zeros_like(sc)
            hard.scatter_(1, ids, 1.0)
            if k == S:
                gate = hard
            else:
                soft = torch.softmax(sc / tau, 1) * k
                gate = hard + (soft - soft.detach())
            h = (ex * gate[:, :, None]).sum(1)
            budget_col = torch.full((feat.size(0), 1), k / S, dtype=feat.dtype)
            z = m.head(torch.cat([h, budget_col], 1))
            losses.append(F.cross_entropy(z, y))
        loss = torch.stack(losses).mean()
        opt.zero_grad()
        loss.backward()
        torch.nn.utils.clip_grad_norm_(m.parameters(), 5.0)
        opt.step()
    return m.eval()


@torch.no_grad()
def accuracy_classes(m):
    out = {}
    for k in range(1, S + 1):
        beta = (k - 0.5) / S
        preds = []
        for a in range(0, TEST_N, 256):
            z, _ = m.hard_grouped(TEF[a:a+256], beta)
            preds.append(z.argmax(1))
        out[str(k)] = float((torch.cat(preds) == TEY).float().mean())
    return out


def quality_audit(acc):
    vals = [acc[str(k)] for k in range(1, S + 1)]
    drops = [max(0.0, vals[i] - vals[i + 1]) for i in range(S - 1)]
    return {
        "strict_non_decreasing": all(vals[i] <= vals[i + 1] + 1e-12 for i in range(S - 1)),
        "max_adjacent_drop_pp": 100.0 * max(drops),
        "k4_to_k8_drop_pp": 100.0 * (vals[3] - vals[7]),
    }


def run_seed(seed, steps):
    m = train_joint(seed, steps)
    acc = accuracy_classes(m)
    return {
        "seed": seed,
        "accuracy": acc,
        "quality_monotonicity": quality_audit(acc),
        "nestedness": nestedness_audit(m),
        "hard_cap_all_pass": all(x["pass"] for x in hard_cap_hook_audit(m)),
    }


def aggregate(rows):
    acc = {str(k): statistics.mean(r["accuracy"][str(k)] for r in rows) for k in range(1, S + 1)}
    audits = [r["quality_monotonicity"] for r in rows]
    nested_viol = sum(r["nestedness"]["violations"] for r in rows)
    hard_ok = all(r["hard_cap_all_pass"] for r in rows)
    strict = sum(a["strict_non_decreasing"] for a in audits)
    mean_drop = statistics.mean(a["max_adjacent_drop_pp"] for a in audits)
    k4k8 = statistics.mean(a["k4_to_k8_drop_pp"] for a in audits)
    decision = (
        strict >= 2 and mean_drop <= 0.5 and nested_viol == 0 and hard_ok and acc["4"] >= 0.98
    )
    return {
        "mean_accuracy": acc,
        "strict_monotonic_seeds": strict,
        "mean_max_adjacent_drop_pp": mean_drop,
        "mean_k4_to_k8_drop_pp": k4k8,
        "nested_violations": nested_viol,
        "all_hard_cap_checks_pass": hard_ok,
        "hypothesis": {
            "H": "Training all eight nested execution classes on every update is sufficient to remove most utility regression without an explicit monotonicity penalty.",
            "PASS_conditions": {
                "strict_monotonic_seeds_min": 2,
                "mean_max_adjacent_drop_pp_max": 0.5,
                "nested_violations": 0,
                "hard_cap_checks": True,
                "k4_accuracy_min": 0.98,
            },
        },
        "decision": "PASS" if decision else "FAIL",
    }


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--seed", type=int)
    ap.add_argument("--seeds", type=int, default=3)
    ap.add_argument("--steps", type=int, default=800)
    ap.add_argument("--out", default=str(ROOT / "results" / "realtime_nn_joint_budget_training_results.json"))
    a = ap.parse_args()
    seed_list = [a.seed] if a.seed is not None else list(range(a.seeds))
    rows = []
    for seed in seed_list:
        r = run_seed(seed, a.steps)
        rows.append(r)
        print("seed", seed, r["accuracy"], r["quality_monotonicity"], flush=True)
    result = {
        "setup": {
            "architecture": "same nested learned ordering and 8 finite physical classes as continuous-budget audit",
            "training_change": "each optimizer update averages task CE over all 8 execution classes instead of sampling one beta/class",
            "explicit_monotonicity_penalty": False,
            "timing_boundary": "no timing claim; this experiment targets utility behavior only",
        },
        "seeds": rows,
        "aggregate": aggregate(rows),
    }
    Path(a.out).parent.mkdir(parents=True, exist_ok=True)
    Path(a.out).write_text(json.dumps(result, indent=2))
    print(json.dumps(result["aggregate"], indent=2))


if __name__ == "__main__":
    main()
