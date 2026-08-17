import argparse, json, math, random
from pathlib import Path
import torch
import torch.nn as nn
import torch.nn.functional as F

# Joint self-specialization toy.
# Candidate circuit topologies are constructed, but all circuit parameters and
# the router are learned from scratch in the same run; there is no capability
# pretraining or capability freeze. The experiment tests whether capability-
# preserving supervision allows resource-conditioned specialization to emerge
# without fallback forgetting.

torch.set_num_threads(1)
N_BITS = 8
N_STATES = 1 << N_BITS
H = 16
ROUTE_NAMES = ['retrieval', 'shallow_compute', 'tied_deep_compute']
ANCHOR_RATIOS = torch.tensor([0.02, 0.08, 0.25, 1.0, 4.0, 12.5, 50.0])
BASE = Path(__file__).resolve().parents[1]
DEFAULT_OUT = BASE / 'results' / 'joint_self_specialization_results.json'


def all_states():
    idx = torch.arange(N_STATES, dtype=torch.long)
    shifts = torch.arange(N_BITS, dtype=torch.long)
    bits = ((idx[:, None] >> shifts) & 1).float()
    y = (bits.sum(1) >= (N_BITS // 2 + 1)).long()
    return idx, bits, y


ALL_IDX, ALL_BITS, ALL_Y = all_states()


class SuperNet(nn.Module):
    def __init__(self, use_price=True, centered_price=True):
        super().__init__()
        self.use_price = use_price
        self.centered_price = centered_price
        self.retrieval = nn.Embedding(N_STATES, H)
        self.shallow1 = nn.Linear(N_BITS, 32)
        self.shallow2 = nn.Linear(32, H)
        self.deep_stem = nn.Linear(N_BITS, H)
        self.deep_tied = nn.Linear(H, H)
        self.head = nn.Linear(H, 2)
        self.router = nn.Sequential(nn.Linear(5, 24), nn.Tanh(), nn.Linear(24, 3))

    def route_logits(self, price, availability):
        if self.use_price:
            lp = torch.log(price.clamp_min(1e-8))
            price_features = lp - lp.mean(1, keepdim=True) if self.centered_price else lp
        else:
            price_features = torch.zeros_like(price)
        z = self.router(torch.cat([price_features, availability], 1))
        return z + (availability - 1.0) * 1e4

    def circuit(self, idx, bits, j):
        if j == 0:
            h = self.retrieval(idx)
        elif j == 1:
            h = F.relu(self.shallow2(F.relu(self.shallow1(bits))))
        elif j == 2:
            h = F.relu(self.deep_stem(bits))
            for _ in range(8):
                h = F.relu(h + self.deep_tied(h))
        else:
            raise ValueError(j)
        return self.head(h)

    def all_logits(self, idx, bits):
        return torch.stack([self.circuit(idx, bits, j) for j in range(3)], 1)


def resource_costs(m):
    head_p = sum(p.numel() for p in m.head.parameters())
    active_params = [
        sum(p.numel() for p in m.retrieval.parameters()) + head_p,
        sum(p.numel() for p in m.shallow1.parameters()) + sum(p.numel() for p in m.shallow2.parameters()) + head_p,
        sum(p.numel() for p in m.deep_stem.parameters()) + sum(p.numel() for p in m.deep_tied.parameters()) + head_p,
    ]
    ops = [
        H + H * 2,
        N_BITS * 32 + 32 * H + H * 2,
        N_BITS * H + 8 * H * H + H * 2,
    ]
    comp = torch.tensor(ops, dtype=torch.float)
    foot = torch.tensor(active_params, dtype=torch.float)
    C = torch.stack([comp / comp.max(), foot / foot.max()], 1)
    return C, {
        'route_names': ROUTE_NAMES,
        'compute_ops_proxy': ops,
        'active_params_proxy': active_params,
        'normalized_costs': C.tolist(),
        'router_params': sum(p.numel() for p in m.router.parameters()),
        'total_resident_params': sum(p.numel() for p in m.parameters()),
        'resource_columns': ['compute_proxy', 'active_parameter_footprint_proxy'],
    }


def sample_batch(n):
    sel = torch.randint(0, N_STATES, (n,))
    return ALL_IDX[sel], ALL_BITS[sel], ALL_Y[sel]


def sample_anchor_prices(n):
    r = ANCHOR_RATIOS[torch.randint(0, len(ANCHOR_RATIOS), (n,))]
    return torch.stack([0.1 * torch.sqrt(r), 0.1 / torch.sqrt(r)], 1)


def sample_availability(n):
    a = torch.ones(n, 3)
    u = torch.rand(n)
    a[(u >= .70) & (u < .80), 0] = 0
    a[(u >= .80) & (u < .90), 1] = 0
    a[u >= .90, 2] = 0
    return a


def train_coupled(seed, insured=True, use_price=True, centered_price=True, steps=1600, beta=.8, aux_gamma=.45):
    torch.manual_seed(seed); random.seed(seed)
    m = SuperNet(use_price=use_price, centered_price=centered_price)
    C, meta = resource_costs(m)
    opt = torch.optim.AdamW(m.parameters(), lr=2.5e-3, weight_decay=1e-5)
    for st in range(steps):
        idx, bits, y = sample_batch(320)
        price = sample_anchor_prices(len(idx)); availability = sample_availability(len(idx))
        z = m.route_logits(price, availability)
        gate = F.gumbel_softmax(z, tau=max(.3, 1.-.7*st/steps), hard=True, dim=1)
        logits = m.all_logits(idx, bits)
        selected = (logits * gate[:, :, None]).sum(1)
        loss = F.cross_entropy(selected, y) + beta * (((gate @ C) * price).sum(1).mean())
        if insured:
            # Capability insurance: every route remains directly supervised even
            # when the resource router rarely selects it.
            loss += aux_gamma * sum(F.cross_entropy(logits[:, j], y) for j in range(3)) / 3.
        opt.zero_grad(); loss.backward(); opt.step()
    return m.eval(), C, meta


def train_decoupled(seed, steps=1600, entropy=.002):
    torch.manual_seed(seed); random.seed(seed)
    m = SuperNet(use_price=True, centered_price=True); C, meta = resource_costs(m)
    cap_params = [p for n,p in m.named_parameters() if not n.startswith('router.')]
    cap_opt = torch.optim.AdamW(cap_params, lr=2.5e-3, weight_decay=1e-5)
    route_opt = torch.optim.AdamW(m.router.parameters(), lr=4e-3, weight_decay=1e-5)
    for _ in range(steps):
        idx,bits,y = sample_batch(320)
        logits = m.all_logits(idx,bits)
        cap_loss = sum(F.cross_entropy(logits[:,j],y) for j in range(3))/3.
        cap_opt.zero_grad(); cap_loss.backward(); cap_opt.step()

        price = sample_anchor_prices(384); availability = sample_availability(len(price))
        prob = m.route_logits(price,availability).softmax(1)
        ecost = (price[:,None,:] * C[None,:,:]).sum(2)
        H = -(prob * torch.log(prob.clamp_min(1e-9))).sum(1).mean()
        route_loss = (prob * ecost).sum(1).mean() + entropy * H
        route_opt.zero_grad(); route_loss.backward(); route_opt.step()
    return m.eval(), C, meta


def oracle(price, availability, C):
    p = torch.as_tensor(price, dtype=torch.float)
    a = torch.as_tensor(availability, dtype=torch.bool)
    if not bool(a.any()): return None
    v = (C * p[None,:]).sum(1).masked_fill(~a, float('inf'))
    return int(v.argmin())


@torch.no_grad()
def route_quality(m):
    out=[]
    for j in range(3):
        l=m.circuit(ALL_IDX,ALL_BITS,j)
        out.append({'acc':float((l.argmax(1)==ALL_Y).float().mean()),'ce':float(F.cross_entropy(l,ALL_Y))})
    return out


@torch.no_grad()
def dense_sweep(m,C,n=401):
    ratios=torch.logspace(math.log10(.02),math.log10(50.),n); availability=torch.ones(1,3)
    agree=0;counts=[0,0,0]
    for r in ratios:
        pc=.1*math.sqrt(float(r));pf=.1/math.sqrt(float(r));p=torch.tensor([[pc,pf]])
        j=int(m.route_logits(p,availability).argmax(1)[0]);o=oracle([pc,pf],availability[0],C)
        agree+=int(j==o);counts[j]+=1
    return {'oracle_agreement':agree/n,'route_counts':counts}


@torch.no_grad()
def random_contracts(m,C,n=4000,seed=0):
    g=torch.Generator().manual_seed(seed)
    price=torch.exp(torch.empty(n,2).uniform_(-3.,1.,generator=g));availability=torch.ones(n,3);u=torch.rand(n,generator=g)
    availability[(u>=.65)&(u<.75),0]=0;availability[(u>=.75)&(u<.85),1]=0;availability[(u>=.85)&(u<.95),2]=0
    pred=m.route_logits(price,availability).argmax(1);agree=0;regret=0.
    for i in range(n):
        o=oracle(price[i],availability[i],C);j=int(pred[i]);agree+=int(j==o)
        regret += float((price[i]*C[j]).sum()-(price[i]*C[o]).sum())
    return {'oracle_agreement':agree/n,'mean_regret':regret/n}


@torch.no_grad()
def same_input(m):
    idx=torch.tensor([173]);bits=ALL_BITS[idx]
    settings={'footprint_expensive':[.03,1.0],'balanced':[.1,.1],'compute_expensive':[1.0,.03]};out={}
    for name,price in settings.items():
        p=torch.tensor([price]);a=torch.ones(1,3);j=int(m.route_logits(p,a).argmax(1)[0]);pred=int(m.circuit(idx,bits,j).argmax(1)[0])
        out[name]={'route':j,'route_name':ROUTE_NAMES[j],'prediction':pred,'target':int(ALL_Y[idx][0])}
    return out


def evaluate(m,C,seed):
    return {'route_quality':route_quality(m),'dense_sweep':dense_sweep(m,C),'random_contracts':random_contracts(m,C,seed=50000+seed),'same_input':same_input(m)}


def aggregate(rows):
    mean=lambda xs:sum(xs)/len(xs)
    return {
        'mean_forced_acc':[mean([r['route_quality'][j]['acc'] for r in rows]) for j in range(3)],
        'min_forced_acc':min(q['acc'] for r in rows for q in r['route_quality']),
        'mean_dense_oracle_agreement':mean([r['dense_sweep']['oracle_agreement'] for r in rows]),
        'min_dense_oracle_agreement':min(r['dense_sweep']['oracle_agreement'] for r in rows),
        'seeds_using_all_three':sum(all(c>0 for c in r['dense_sweep']['route_counts']) for r in rows),
        'mean_random_oracle_agreement':mean([r['random_contracts']['oracle_agreement'] for r in rows]),
        'mean_random_regret':mean([r['random_contracts']['mean_regret'] for r in rows]),
    }


MODE_FNS = {
    'naive_joint': lambda s: train_coupled(s, insured=False, use_price=True, centered_price=True),
    'capability_preserving_joint': lambda s: train_coupled(s, insured=True, use_price=True, centered_price=True),
    'capability_preserving_price_blind': lambda s: train_coupled(s, insured=True, use_price=False, centered_price=True),
    'raw_log_price_ablation': lambda s: train_coupled(s, insured=True, use_price=True, centered_price=False),
    'gradient_decoupled_diagnostic': lambda s: train_decoupled(s),
}


def main():
    ap=argparse.ArgumentParser();ap.add_argument('--mode',action='append',choices=list(MODE_FNS));ap.add_argument('--seeds',default='0,1,2,3,4');ap.add_argument('--out',default=str(DEFAULT_OUT));args=ap.parse_args()
    modes=args.mode or list(MODE_FNS);seeds=[int(x) for x in args.seeds.split(',') if x]
    result={'experiment':'joint_self_specialization','task':{'bits':N_BITS,'states':N_STATES},'training_price_ratio_anchors':ANCHOR_RATIOS.tolist(),'modes':{}}
    meta=None
    for mode in modes:
        rows=[]
        for seed in seeds:
            m,C,meta=MODE_FNS[mode](seed);ev=evaluate(m,C,seed);ev['seed']=seed;rows.append(ev)
            print(mode,seed,[q['acc'] for q in ev['route_quality']],ev['dense_sweep'],ev['random_contracts'],ev['same_input'],flush=True)
        result['modes'][mode]={'aggregate':aggregate(rows),'seeds':rows}
    result['resource_meta']=meta
    Path(args.out).write_text(json.dumps(result,indent=2));print('wrote',args.out)

if __name__=='__main__':main()
