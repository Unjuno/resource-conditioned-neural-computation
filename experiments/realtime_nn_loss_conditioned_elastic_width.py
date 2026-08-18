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

ROOT = Path(__file__).resolve().parents[1] if Path(__file__).resolve().parent.name == 'experiments' else Path('/mnt/data')
S = 8
H = 56
KS = [0, 1, 3, 4, 6, 8]
BASE_IMPORTANCE = torch.tensor([2.0, 1.4, 1.0, 0.7, 0.5, 0.35, 0.25, 0.18])
PRICES = [0.0, 0.05, 0.1, 0.2, 0.4, 0.7, 1.0, 1.5, 2.5, 4.0, 7.0]


def make_data(n, seed):
    g = torch.Generator().manual_seed(seed)
    signs = torch.where(torch.rand(n, S, generator=g) > 0.5, 1.0, -1.0)
    mags = []
    for _ in range(n):
        perm = torch.randperm(S, generator=g)
        jitter = 0.92 + 0.16 * torch.rand(S, generator=g)
        mags.append(BASE_IMPORTANCE[perm] * jitter)
    mag = torch.stack(mags)
    y = ((mag * signs).sum(1) > 0).long()
    pos = F.one_hot(torch.arange(S), S).float()[None].expand(n, -1, -1)
    feat = torch.cat([signs[:, :, None], mag[:, :, None], pos], -1)
    meta = torch.cat([mag[:, :, None], pos], -1)
    return feat, meta, mag, y


TRF, TRM, TRMAG, TRY = make_data(10000, 101)
TEF, TEM, TEMAG, TEY = make_data(2500, 202)


class Expert(nn.Module):
    def __init__(self):
        super().__init__()
        self.a = nn.Linear(2 + S, H)
        self.b = nn.Linear(H, 4 * H)
        self.c = nn.Linear(4 * H, H)
        self.o = nn.Linear(H, H)

    def forward(self, x):
        h = torch.tanh(self.a(x))
        h = torch.tanh(h + 0.2 * self.c(F.gelu(self.b(h))))
        return self.o(h)


class ElasticWidthNet(nn.Module):
    def __init__(self, price_visible=True):
        super().__init__()
        self.price_visible = price_visible
        self.experts = nn.ModuleList([Expert() for _ in range(S)])
        # Selector is cheap: it sees importance metadata, not the expensive sign/content.
        self.selector = nn.Sequential(nn.Linear(1 + S, 24), nn.Tanh(), nn.Linear(24, 1))
        self.width_controller = nn.Sequential(nn.Linear(1, 24), nn.Tanh(), nn.Linear(24, len(KS)))
        self.head = nn.Sequential(nn.Linear(H + 1, 32), nn.Tanh(), nn.Linear(32, 2))

    def selector_scores(self, meta):
        return self.selector(meta).squeeze(-1)

    def width_logits(self, price):
        p = torch.as_tensor(price, dtype=torch.float32)
        if p.ndim == 0:
            p = p[None]
        x = torch.log1p(p)[:, None]
        if not self.price_visible:
            x = torch.zeros_like(x)
        return self.width_controller(x)

    def all_width_logits(self, feat, meta, tau=0.35):
        # Training surrogate evaluates all experts. Inference below does not.
        expert_out = torch.stack([e(feat[:, j]) for j, e in enumerate(self.experts)], 1)
        score = self.selector_scores(meta)
        rows = []
        for k in KS:
            if k == 0:
                gate = torch.zeros_like(score)
            else:
                ids = score.topk(k, 1).indices
                hard = torch.zeros_like(score)
                hard.scatter_(1, ids, 1.0)
                soft = torch.softmax(score / tau, 1) * k
                gate = hard + (soft - soft.detach())
            h = (expert_out * gate[:, :, None]).sum(1)
            frac = torch.full((feat.size(0), 1), k / S)
            rows.append(self.head(torch.cat([h, frac], 1)))
        return torch.stack(rows, 1)

    def training_objective(self, feat, meta, y, price, tau, cost_scale=0.55):
        z = self.all_width_logits(feat, meta, tau)
        per_width_ce = torch.stack(
            [F.cross_entropy(z[:, i], y, reduction='none') for i in range(len(KS))], 1
        )
        # Keep all execution widths task-capable.
        capability_loss = per_width_ce.mean()

        # No hand-written width label. Derive the target from task loss + supplied work price.
        mean_ce = per_width_ce.detach().mean(0)
        kvec = torch.tensor(KS, dtype=mean_ce.dtype)
        energy = mean_ce + cost_scale * float(price) * (kvec / S)
        target = torch.softmax(-energy / 0.06, 0).detach()
        pred_logp = torch.log_softmax(self.width_logits(torch.tensor([price]))[0] / 0.5, 0)
        width_loss = -(target * pred_logp).sum()
        return capability_loss + 0.35 * width_loss

    @torch.no_grad()
    def choose_k(self, price):
        return KS[int(self.width_logits(torch.tensor([price]))[0].argmax())]

    @torch.no_grad()
    def dense_equivalent(self, feat, meta, price):
        k = self.choose_k(price)
        score = self.selector_scores(meta)
        expert_out = torch.stack([e(feat[:, j]) for j, e in enumerate(self.experts)], 1)
        if k == 0:
            gate = torch.zeros_like(score)
        else:
            ids = score.topk(k, 1).indices
            gate = torch.zeros_like(score)
            gate.scatter_(1, ids, 1.0)
        h = (expert_out * gate[:, :, None]).sum(1)
        frac = torch.full((feat.size(0), 1), k / S)
        return self.head(torch.cat([h, frac], 1)), gate

    @torch.no_grad()
    def physical_one(self, feat, meta, price):
        k = self.choose_k(price)
        score = self.selector_scores(meta)[0]
        ids = [] if k == 0 else score.topk(k).indices.tolist()
        h = torch.zeros(H)
        for j in ids:
            h += self.experts[j](feat[:, j])[0]
        frac = torch.tensor([[k / S]], dtype=h.dtype)
        return self.head(torch.cat([h[None], frac], 1)), ids, k


def train(seed, price_visible=True, steps=850, cost_scale=0.55):
    torch.manual_seed(seed)
    random.seed(seed)
    m = ElasticWidthNet(price_visible)
    opt = torch.optim.AdamW(m.parameters(), lr=2e-3, weight_decay=1e-6)
    g = torch.Generator().manual_seed(900 + seed)
    for step in range(steps):
        ix = torch.randint(0, len(TRF), (192,), generator=g)
        if step % 7 == 0:
            price = 0.0
        else:
            price = float(torch.exp(torch.empty(1).uniform_(math.log(0.03), math.log(7.0), generator=g)))
        tau = max(0.22, 1 - step / steps * 0.78)
        loss = m.training_objective(TRF[ix], TRM[ix], TRY[ix], price, tau, cost_scale)
        opt.zero_grad()
        loss.backward()
        torch.nn.utils.clip_grad_norm_(m.parameters(), 5)
        opt.step()
    return m.eval()


def percentile(v, p):
    s = sorted(v)
    return s[min(len(s) - 1, max(0, math.ceil(p * len(s)) - 1))]


@torch.no_grad()
def fixed_width_audit(m):
    preds = {k: [] for k in KS}
    losses = {k: [] for k in KS}
    overlap = {k: [] for k in KS if k}
    for a in range(0, len(TEF), 500):
        z = m.all_width_logits(TEF[a:a + 500], TEM[a:a + 500], 0.2)
        score = m.selector_scores(TEM[a:a + 500])
        for i, k in enumerate(KS):
            preds[k].append(z[:, i].argmax(1))
            losses[k].append(F.cross_entropy(z[:, i], TEY[a:a + 500], reduction='none'))
        for k in overlap:
            ids = score.topk(k, 1).indices
            oracle = TEMAG[a:a + 500].topk(k, 1).indices
            for n in range(ids.size(0)):
                overlap[k].append(len(set(ids[n].tolist()) & set(oracle[n].tolist())) / k)
    return {
        str(k): {
            'accuracy': float((torch.cat(preds[k]) == TEY).float().mean()),
            'ce': float(torch.cat(losses[k]).mean()),
            'top_importance_overlap': statistics.mean(overlap[k]) if k else None,
        }
        for k in KS
    }


@torch.no_grad()
def price_audit(m):
    out = {}
    for p in PRICES:
        preds, active = [], []
        for a in range(0, len(TEF), 500):
            z, gate = m.dense_equivalent(TEF[a:a + 500], TEM[a:a + 500], p)
            preds.append(z.argmax(1))
            active.append(gate.sum(1))
        out[str(p)] = {
            'k': m.choose_k(p),
            'accuracy': float((torch.cat(preds) == TEY).float().mean()),
            'mean_active': float(torch.cat(active).float().mean()),
        }
    return out


@torch.no_grad()
def timing_audit(m, reps=80):
    rng = random.Random(77)
    out = {}
    for p in PRICES:
        hard, dense = [], []
        for _ in range(15):
            j = rng.randrange(len(TEF))
            m.physical_one(TEF[j:j + 1], TEM[j:j + 1], p)
            m.dense_equivalent(TEF[j:j + 1], TEM[j:j + 1], p)
        for _ in range(reps):
            j = rng.randrange(len(TEF))
            t = time.perf_counter_ns()
            m.physical_one(TEF[j:j + 1], TEM[j:j + 1], p)
            hard.append((time.perf_counter_ns() - t) / 1000.0)
            t = time.perf_counter_ns()
            m.dense_equivalent(TEF[j:j + 1], TEM[j:j + 1], p)
            dense.append((time.perf_counter_ns() - t) / 1000.0)
        out[str(p)] = {
            'k': m.choose_k(p),
            'hard_median_us': statistics.median(hard),
            'hard_p95_us': percentile(hard, 0.95),
            'dense_median_us': statistics.median(dense),
        }
    return out


@torch.no_grad()
def physical_equivalence_audit(m):
    max_diff = 0.0
    mismatches = 0
    tested = 0
    for p in [0.0, 0.4, 0.7, 1.0, 1.5, 2.5]:
        for j in range(50):
            hard, _, _ = m.physical_one(TEF[j:j + 1], TEM[j:j + 1], p)
            dense, _ = m.dense_equivalent(TEF[j:j + 1], TEM[j:j + 1], p)
            max_diff = max(max_diff, float((hard - dense).abs().max()))
            mismatches += int(int(hard.argmax(1)) != int(dense.argmax(1)))
            tested += 1
    return {'examples': tested, 'prediction_mismatches': mismatches, 'max_logit_abs_diff': max_diff}


@torch.no_grad()
def counterfactual_audit(m, input_index=17):
    rows = []
    for p in [0.0, 0.5, 0.8, 1.2, 1.8, 3.0]:
        hits = []
        hooks = [e.register_forward_hook(lambda mod, inp, out, j=j: hits.append(j)) for j, e in enumerate(m.experts)]
        try:
            z, ids, k = m.physical_one(TEF[input_index:input_index + 1], TEM[input_index:input_index + 1], p)
        finally:
            for h in hooks:
                h.remove()
        rows.append({
            'price': p,
            'k': k,
            'selected_ids': ids,
            'hook_hits': hits,
            'prediction': int(z.argmax(1)),
            'label': int(TEY[input_index]),
        })
    return rows


def loss_oracle_agreement(fixed, price_rows, cost_scale=0.55):
    agree = 0
    rows = []
    for p in PRICES:
        energy = {
            k: fixed[str(k)]['ce'] + cost_scale * p * k / S
            for k in KS
        }
        oracle_k = min(KS, key=lambda k: energy[k])
        chosen = price_rows[str(p)]['k']
        agree += int(oracle_k == chosen)
        rows.append({'price': p, 'oracle_k': oracle_k, 'chosen_k': chosen})
    return {'agreement_count': agree, 'total': len(PRICES), 'rows': rows}


def run(seed, mode, steps, timing_reps, cost_scale):
    visible = mode == 'aware'
    m = train(seed, visible, steps, cost_scale)
    fixed = fixed_width_audit(m)
    prices = price_audit(m)
    out = {
        'seed': seed,
        'mode': mode,
        'fixed_width': fixed,
        'price_conditioned': prices,
        'loss_oracle': loss_oracle_agreement(fixed, prices, cost_scale),
    }
    if mode == 'aware':
        out['timing'] = timing_audit(m, timing_reps)
        out['physical_equivalence'] = physical_equivalence_audit(m)
        out['same_input_counterfactual'] = counterfactual_audit(m)
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--seed', type=int, default=0)
    ap.add_argument('--mode', choices=['aware', 'blind'], default='aware')
    ap.add_argument('--steps', type=int, default=850)
    ap.add_argument('--timing-reps', type=int, default=80)
    ap.add_argument('--cost-scale', type=float, default=0.55)
    ap.add_argument('--out')
    args = ap.parse_args()
    try:
        cpu = sorted(__import__('os').sched_getaffinity(0))[0]
        __import__('os').sched_setaffinity(0, {cpu})
    except Exception:
        pass
    out = run(args.seed, args.mode, args.steps, args.timing_reps, args.cost_scale)
    if args.out:
        Path(args.out).write_text(json.dumps(out, indent=2))
    print(json.dumps(out, indent=2))


if __name__ == '__main__':
    main()
