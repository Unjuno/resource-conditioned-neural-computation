import argparse, json, math, random, statistics, time
from pathlib import Path

import torch
import torch.nn as nn
import torch.nn.functional as F

torch.set_num_threads(1)
try:
    torch.set_num_interop_threads(1)
except RuntimeError:
    pass

ROOT = Path(__file__).resolve().parents[1]
S, R, Q, H = 8, 4, 4, 48
TRAIN_N, TEST_N = 16000, 2000
BETAS = [i / 64.0 for i in range(65)]
UNSEEN_BETAS = [(i + 0.5) / 16.0 for i in range(16)]


def beta_to_k(beta: float) -> int:
    # 8 finite physical classes under a continuous runtime control.
    return min(S, 1 + int(math.floor(float(beta) * S)))


def make_data(n, seed):
    g = torch.Generator().manual_seed(seed)
    rr = random.Random(seed)
    bits = torch.randint(0, 2, (n, S), generator=g).float()
    queries = torch.randint(0, Q, (n,), generator=g)
    keys = torch.empty(n, S, dtype=torch.long)
    rel = torch.zeros(n, S)
    for i in range(n):
        ids = set(rr.sample(range(S), R))
        q = int(queries[i])
        for j in range(S):
            if j in ids:
                keys[i, j] = q
                rel[i, j] = 1.0
            else:
                keys[i, j] = rr.choice([x for x in range(Q) if x != q])
    y = ((bits * rel).sum(1) >= 3).long()
    ko = F.one_hot(keys, Q).float()
    qo = F.one_hot(queries, Q).float()[:, None, :].expand(-1, S, -1)
    feat = torch.cat([bits[:, :, None], ko, qo], -1)
    return feat, rel, y


TRF, TRR, TRY = make_data(TRAIN_N, 101)
TEF, TER, TEY = make_data(TEST_N, 202)


class Expert(nn.Module):
    def __init__(self):
        super().__init__()
        self.a = nn.Linear(1 + 2 * Q, H)
        self.b = nn.Linear(H, 4 * H)
        self.c = nn.Linear(4 * H, H)

    def forward(self, z):
        h = torch.tanh(self.a(z))
        return torch.tanh(h + 0.2 * self.c(F.gelu(self.b(h))))


class BudgetOrderingNet(nn.Module):
    def __init__(self, policy: str):
        super().__init__()
        assert policy in {"nested", "free"}
        self.policy = policy
        self.experts = nn.ModuleList([Expert() for _ in range(S)])
        ctrl_in = 2 * Q + (0 if policy == "nested" else 1)
        self.ctrl = nn.Sequential(nn.Linear(ctrl_in, 24), nn.Tanh(), nn.Linear(24, 1))
        self.head = nn.Linear(H + 1, 2)

    def scores(self, feat, beta):
        base = feat[:, :, 1:]
        if self.policy == "free":
            b = torch.full((feat.size(0), S, 1), float(beta), dtype=feat.dtype)
            base = torch.cat([base, b], -1)
        return self.ctrl(base).squeeze(-1)

    def train_forward(self, feat, beta, tau=1.0):
        k = beta_to_k(beta)
        ex = torch.stack([e(feat[:, j]) for j, e in enumerate(self.experts)], 1)
        sc = self.scores(feat, beta)
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
        return self.head(torch.cat([h, budget_col], 1)), ids

    @torch.no_grad()
    def ids(self, feat, beta, mode=None):
        k = beta_to_k(beta)
        if mode == "prefix":
            return torch.arange(k)[None, :].expand(feat.size(0), -1)
        return self.scores(feat, beta).topk(k, 1).indices

    @torch.no_grad()
    def hard(self, feat, beta, mode=None):
        # Exact per-sample physical execution path; used for hook/timing audits.
        k = beta_to_k(beta)
        ids = self.ids(feat, beta, mode)
        rows = []
        for n in range(feat.size(0)):
            h = torch.zeros(H)
            for j in ids[n].tolist():
                h = h + self.experts[j](feat[n:n+1, j])[0]
            rows.append(h)
        h = torch.stack(rows)
        budget_col = torch.full((feat.size(0), 1), k / S)
        return self.head(torch.cat([h, budget_col], 1)), ids

    @torch.no_grad()
    def hard_grouped(self, feat, beta, mode=None):
        # Same selected per-sample computation, grouped by expert for fast accuracy audits.
        k = beta_to_k(beta)
        ids = self.ids(feat, beta, mode)
        h = torch.zeros(feat.size(0), H)
        selected = torch.zeros(feat.size(0), S, dtype=torch.bool)
        selected.scatter_(1, ids, True)
        for j, expert in enumerate(self.experts):
            rows = selected[:, j].nonzero(as_tuple=False).squeeze(1)
            if rows.numel():
                h[rows] += expert(feat[rows, j])
        budget_col = torch.full((feat.size(0), 1), k / S)
        return self.head(torch.cat([h, budget_col], 1)), ids


def train(seed, policy, steps=1000):
    torch.manual_seed(seed)
    random.seed(seed)
    m = BudgetOrderingNet(policy)
    opt = torch.optim.AdamW(m.parameters(), lr=2e-3, weight_decay=1e-6)
    rng = random.Random(300 + seed + (0 if policy == "nested" else 10000))
    for step in range(steps):
        ix = torch.randint(0, TRAIN_N, (256,))
        beta = rng.random()  # continuous; almost surely not a fixed training grid point
        tau = max(0.3, 1.0 - step / steps * 0.7)
        z, _ = m.train_forward(TRF[ix], beta, tau)
        loss = F.cross_entropy(z, TRY[ix])
        opt.zero_grad()
        loss.backward()
        torch.nn.utils.clip_grad_norm_(m.parameters(), 5.0)
        opt.step()
    return m.eval()


@torch.no_grad()
def accuracy_at_beta(m, beta, mode=None):
    preds, rels = [], []
    for a in range(0, TEST_N, 256):
        z, ids = m.hard_grouped(TEF[a:a+256], beta, mode=mode)
        preds.append(z.argmax(1))
        rels.append(torch.gather(TER[a:a+256], 1, ids).mean())
    return {
        "accuracy": float((torch.cat(preds) == TEY).float().mean()),
        "selected_relevant_fraction": float(torch.stack(rels).mean()),
        "k": beta_to_k(beta),
    }


@torch.no_grad()
def nestedness_audit(m, sample_n=512):
    # For each input, selected set at k must be subset of selected set at k+1.
    violations = 0
    comparisons = 0
    examples = []
    x = TEF[:sample_n]
    reps = [(k - 0.5) / S for k in range(1, S + 1)]
    all_ids = [m.ids(x, b) for b in reps]
    for n in range(sample_n):
        prev = set()
        for k_idx, ids in enumerate(all_ids, 1):
            cur = set(ids[n].tolist())
            if k_idx > 1:
                comparisons += 1
                if not prev.issubset(cur):
                    violations += 1
                    if len(examples) < 5:
                        examples.append({"sample": n, "k_prev": k_idx-1, "prev": sorted(prev), "k": k_idx, "cur": sorted(cur)})
            prev = cur
    return {"comparisons": comparisons, "violations": violations, "violation_rate": violations / comparisons, "examples": examples}


@torch.no_grad()
def hard_cap_hook_audit(m):
    rows = []
    for beta in [0.0, 0.07, 0.19, 0.33, 0.52, 0.74, 0.99]:
        hits = []
        hs = [e.register_forward_hook(lambda mod, inp, out, j=j: hits.append(j)) for j, e in enumerate(m.experts)]
        try:
            _, ids = m.hard(TEF[:1], beta)
        finally:
            for h in hs:
                h.remove()
        rows.append({"beta": beta, "k": beta_to_k(beta), "selected": ids[0].tolist(), "hook_hits": hits, "pass": len(hits) == beta_to_k(beta)})
    return rows


def pct(v, p):
    s = sorted(v)
    return s[min(len(s)-1, max(0, math.ceil(p * len(s)) - 1))]


@torch.no_grad()
def timing_audit(m, seed, reps=80):
    rng = random.Random(8000 + seed)
    out = {}
    for k in range(1, S + 1):
        beta = (k - 0.5) / S
        vals = []
        for _ in range(20):
            j = rng.randrange(TEST_N)
            m.hard(TEF[j:j+1], beta)
        for _ in range(reps):
            j = rng.randrange(TEST_N)
            t = time.perf_counter_ns()
            m.hard(TEF[j:j+1], beta)
            vals.append((time.perf_counter_ns() - t) / 1000.0)
        out[str(k)] = {"median_us": statistics.median(vals), "p95_us": pct(vals, 0.95)}
    med = [out[str(k)]["median_us"] for k in range(1, S + 1)]
    out["strictly_monotonic_median"] = all(med[i] < med[i+1] for i in range(S-1))
    return out


def run_seed(seed, steps, timing_reps):
    models = {p: train(seed, p, steps=steps) for p in ["nested", "free"]}
    policies = {}
    for p, m in models.items():
        policies[p] = {
            "by_class": {str(k): accuracy_at_beta(m, (k - 0.5) / S) for k in range(1, S + 1)},
            "unseen_budget": [dict(beta=b, **accuracy_at_beta(m, b)) for b in UNSEEN_BETAS],
            "nestedness": nestedness_audit(m),
            "hard_cap_hooks": hard_cap_hook_audit(m),
            "timing": timing_audit(m, seed + (0 if p == "nested" else 100), reps=timing_reps),
        }
    # Prefix baseline uses the nested model's trained experts/head but fixed expert identities.
    policies["prefix"] = {
        "by_class": {str(k): accuracy_at_beta(models["nested"], (k - 0.5) / S, mode="prefix") for k in range(1, S + 1)}
    }
    return {"seed": seed, "policies": policies}


def aggregate(rows):
    by_class = {}
    for k in range(1, S + 1):
        by_class[str(k)] = {}
        for p in ["nested", "free", "prefix"]:
            by_class[str(k)][p] = statistics.mean(r["policies"][p]["by_class"][str(k)]["accuracy"] for r in rows)
    nested_free_gap = statistics.mean(by_class[str(k)]["free"] - by_class[str(k)]["nested"] for k in range(1, S + 1))
    mid_adv = by_class["4"]["nested"] - by_class["4"]["prefix"]
    nested_viol = sum(r["policies"]["nested"]["nestedness"]["violations"] for r in rows)
    free_viol = sum(r["policies"]["free"]["nestedness"]["violations"] for r in rows)
    all_hooks = all(x["pass"] for r in rows for p in ["nested", "free"] for x in r["policies"][p]["hard_cap_hooks"])
    unseen_acc = {
        p: statistics.mean(x["accuracy"] for r in rows for x in r["policies"][p]["unseen_budget"])
        for p in ["nested", "free"]
    }
    quality_rows = []
    for r in rows:
        vals = [r["policies"]["nested"]["by_class"][str(k)]["accuracy"] for k in range(1, S + 1)]
        drops = [max(0.0, vals[i] - vals[i + 1]) for i in range(S - 1)]
        quality_rows.append({
            "seed": r["seed"],
            "strict_non_decreasing": all(vals[i] <= vals[i + 1] + 1e-12 for i in range(S - 1)),
            "max_adjacent_drop_pp": 100.0 * max(drops),
            "k4_to_k8_drop_pp": 100.0 * (vals[3] - vals[7]),
        })
    return {
        "by_class_accuracy": by_class,
        "mean_free_minus_nested_accuracy_pp": 100.0 * nested_free_gap,
        "k4_nested_minus_prefix_accuracy_pp": 100.0 * mid_adv,
        "nested_total_violations": nested_viol,
        "free_total_violations": free_viol,
        "all_hard_cap_hook_checks_pass": all_hooks,
        "mean_unseen_budget_accuracy": unseen_acc,
        "hypothesis": {
            "H": "Nested learned ordering preserves most free-policy quality, enforces zero path-nestedness violations, and materially beats prefix at intermediate work.",
            "PASS_conditions": {
                "nestedness_violations": 0,
                "hard_cap_hook_checks": True,
                "mean_free_minus_nested_accuracy_pp_max": 2.0,
                "k4_nested_minus_prefix_accuracy_pp_min": 5.0,
            },
        },
        "decision": "PASS" if (nested_viol == 0 and all_hooks and 100.0*nested_free_gap <= 2.0 and 100.0*mid_adv >= 5.0) else "FAIL",
        "quality_monotonicity_audit": {
            "H": "Task accuracy is non-decreasing as the admitted nested execution class grows.",
            "PASS_condition": "strict non-decreasing accuracy across all 8 classes in all seeds",
            "per_seed": quality_rows,
            "strict_pass_seeds": sum(x["strict_non_decreasing"] for x in quality_rows),
            "mean_k4_to_k8_drop_pp": statistics.mean(x["k4_to_k8_drop_pp"] for x in quality_rows),
            "decision": "PASS" if all(x["strict_non_decreasing"] for x in quality_rows) else "FAIL",
        },
    }


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--seed", type=int, default=None)
    ap.add_argument("--seeds", type=int, default=3)
    ap.add_argument("--steps", type=int, default=800)
    ap.add_argument("--timing-reps", type=int, default=5)
    ap.add_argument("--out", default=str(ROOT / "results" / "realtime_nn_continuous_budget_ordering_results.json"))
    a = ap.parse_args()
    rows = []
    seed_list = [a.seed] if a.seed is not None else list(range(a.seeds))
    for seed in seed_list:
        r = run_seed(seed, a.steps, a.timing_reps)
        rows.append(r)
        print("seed", seed, "nested k4", r["policies"]["nested"]["by_class"]["4"]["accuracy"], "free k4", r["policies"]["free"]["by_class"]["4"]["accuracy"], flush=True)
    out = {
        "setup": {
            "task": "8 slots; exactly 4 match a categorical query; predict strict majority of matching-slot bits",
            "continuous_control": "beta in [0,1] maps fail-closed to one of 8 finite physical expert-call classes",
            "nested_policy": "input-conditioned beta-independent ranking; top-k prefix of learned per-input ordering",
            "free_policy": "input- and beta-conditioned ranking; top-k may reorder across budgets",
            "training": "task loss only with beta sampled continuously from Uniform(0,1); no relevance labels",
            "timing_boundary": "container/PyTorch/Linux empirical timing only; not WCET or hard-real-time evidence",
        },
        "seeds": rows,
        "aggregate": aggregate(rows),
    }
    Path(a.out).parent.mkdir(parents=True, exist_ok=True)
    Path(a.out).write_text(json.dumps(out, indent=2))
    print(json.dumps(out["aggregate"], indent=2))


if __name__ == "__main__":
    main()
