import json, math, random
from pathlib import Path
import torch
import torch.nn as nn
import torch.nn.functional as F

torch.set_num_threads(1)

N_BITS = 8
N_STATES = 1 << N_BITS
H = 8
SHALLOW_W = 20
TIED_STEPS = 10
BASE = Path(__file__).resolve().parents[1]
OUT = BASE / 'results' / 'multicircuit_contract_transfer_results.json'

idx_all = torch.arange(N_STATES, dtype=torch.long)
shifts = torch.arange(N_BITS, dtype=torch.long)
bits_all = ((idx_all[:, None] >> shifts) & 1).float()
left = (bits_all[:, :4].sum(1) >= 2).long()
right = (bits_all[:, 4:].sum(1) >= 2).long()
y_all = left ^ right


class MultiCircuitNet(nn.Module):
    """One parameterized model with three resource-distinct internal circuits.

    0 retrieval: embedding -> shared head
    1 shallow:   8 -> 20 -> 8 -> shared head
    2 tied-deep: 8 -> 8 -> shared residual block x10 -> shared head

    The tied-deep path intentionally trades low active parameter footprint for
    repeated computation. Candidate circuits are constructed, not discovered.
    """
    def __init__(self, use_price=True):
        super().__init__()
        self.use_price = use_price
        self.retrieval = nn.Embedding(N_STATES, H)
        self.shallow1 = nn.Linear(N_BITS, SHALLOW_W)
        self.shallow2 = nn.Linear(SHALLOW_W, H)
        self.tied_stem = nn.Linear(N_BITS, H)
        self.tied_block = nn.Linear(H, H)
        self.head = nn.Linear(H, 2)
        # price(2) + availability(3) -> 3 routes; identical for aware/blind.
        self.router = nn.Sequential(nn.Linear(5, 24), nn.Tanh(), nn.Linear(24, 3))

    def circuit_hidden(self, bits, idx, route):
        if route == 0:
            return self.retrieval(idx), ['retrieval']
        if route == 1:
            h = F.relu(self.shallow1(bits))
            h = F.relu(self.shallow2(h))
            return h, ['shallow1', 'shallow2']
        if route == 2:
            h = F.relu(self.tied_stem(bits))
            active = ['tied_stem']
            for k in range(TIED_STEPS):
                h = F.relu(h + self.tied_block(h))
                active.append(f'tied_block@{k}')
            return h, active
        raise ValueError(route)

    def forward_route(self, bits, idx, route):
        h, active = self.circuit_hidden(bits, idx, route)
        return self.head(h), active + ['head']

    def router_logits(self, price, availability):
        pf = torch.log(price.clamp_min(1e-8)) if self.use_price else torch.zeros_like(price)
        z = self.router(torch.cat([pf, availability], 1))
        return z + (availability - 1.0) * 1e4

    def choose(self, price, availability):
        return self.router_logits(price, availability).argmax(1)

    @torch.no_grad()
    def forward_selected(self, bits, idx, price, availability):
        if availability.sum(1).eq(0).any():
            raise RuntimeError('not admitted: no execution circuit available')
        r = int(self.choose(price, availability)[0])
        logits, trace = self.forward_route(bits, idx, r)
        return logits, r, trace


def profile_costs(m):
    hp = sum(p.numel() for p in m.head.parameters())
    active_params = [
        sum(p.numel() for p in m.retrieval.parameters()) + hp,
        sum(p.numel() for p in m.shallow1.parameters()) + sum(p.numel() for p in m.shallow2.parameters()) + hp,
        sum(p.numel() for p in m.tied_stem.parameters()) + sum(p.numel() for p in m.tied_block.parameters()) + hp,
    ]
    ops = [
        H + H * 2,
        N_BITS * SHALLOW_W + SHALLOW_W * H + H * 2,
        N_BITS * H + TIED_STEPS * H * H + H * 2,
    ]
    comp = torch.tensor(ops, dtype=torch.float)
    foot = torch.tensor(active_params, dtype=torch.float)
    C = torch.stack([comp / comp.max(), foot / foot.max()], 1)
    return C, {
        'active_parameter_footprint_proxy': active_params,
        'compute_ops_proxy': ops,
        'resource_columns': ['compute_proxy', 'active_parameter_footprint_proxy'],
        'total_resident_params': sum(p.numel() for p in m.parameters()),
    }


def train_capabilities(seed):
    torch.manual_seed(seed); random.seed(seed)
    m = MultiCircuitNet(True)
    # Train both algorithmic circuits and the shared head jointly.
    for p in m.retrieval.parameters(): p.requires_grad_(False)
    for p in m.router.parameters(): p.requires_grad_(False)
    opt = torch.optim.AdamW(
        list(m.shallow1.parameters()) + list(m.shallow2.parameters()) +
        list(m.tied_stem.parameters()) + list(m.tied_block.parameters()) +
        list(m.head.parameters()), lr=4e-3, weight_decay=1e-6)
    for step in range(2500):
        l1, _ = m.forward_route(bits_all, idx_all, 1)
        l2, _ = m.forward_route(bits_all, idx_all, 2)
        loss = F.cross_entropy(l1, y_all) + F.cross_entropy(l2, y_all)
        opt.zero_grad(); loss.backward(); opt.step()
        if step % 50 == 0:
            if (l1.argmax(1) == y_all).all() and (l2.argmax(1) == y_all).all():
                break

    # Fit retrieval representations against the now-frozen shared head.
    for p in m.parameters(): p.requires_grad_(False)
    for p in m.retrieval.parameters(): p.requires_grad_(True)
    opt = torch.optim.Adam(m.retrieval.parameters(), lr=5e-2)
    for step2 in range(500):
        l0, _ = m.forward_route(bits_all, idx_all, 0)
        loss = F.cross_entropy(l0, y_all)
        opt.zero_grad(); loss.backward(); opt.step()
        if step2 % 20 == 0 and (l0.argmax(1) == y_all).all():
            break

    for name, p in m.named_parameters():
        p.requires_grad_(name.startswith('router.'))
    return m.eval()


@torch.no_grad()
def route_accuracy(m, r):
    logits, _ = m.forward_route(bits_all, idx_all, r)
    return float((logits.argmax(1) == y_all).float().mean())


def clone_capabilities(src, use_price):
    dst = MultiCircuitNet(use_price)
    sd = dst.state_dict(); srcsd = src.state_dict()
    for k in sd:
        if not k.startswith('router.'):
            sd[k] = srcsd[k].clone()
    dst.load_state_dict(sd)
    for name,p in dst.named_parameters(): p.requires_grad_(name.startswith('router.'))
    return dst


def make_price(ratio, scale=0.1):
    return [scale * math.sqrt(ratio), scale / math.sqrt(ratio)]


def oracle(price, availability, C):
    a = torch.tensor(availability, dtype=torch.bool)
    if not bool(a.any()): return None
    p = torch.tensor(price, dtype=torch.float)
    c = (C * p[None, :]).sum(1).masked_fill(~a, float('inf'))
    return int(c.argmin())


def train_router(m, seed, C, use_price):
    m.use_price = use_price
    torch.manual_seed(seed + (1000 if use_price else 2000)); random.seed(seed + 77)
    for mod in m.router.modules():
        if hasattr(mod, 'reset_parameters'): mod.reset_parameters()
    opt = torch.optim.Adam(m.router.parameters(), lr=7e-3)
    # Deliberately sparse price-ratio training anchors. Dense interpolation is held out.
    anchors = torch.tensor([0.03, 0.1, 0.3, 1.0, 3.0, 10.0, 30.0])
    for _ in range(1800):
        n = 384
        ridx = torch.randint(0, len(anchors), (n,))
        ratios = anchors[ridx]
        scales = torch.exp(torch.rand(n) * 4.0 - 2.0) * 0.1
        pc = scales * torch.sqrt(ratios); pf = scales / torch.sqrt(ratios)
        p = torch.stack([pc, pf], 1)
        # random availability: all-safe plus every single route removal and occasional single-safe
        mask = torch.ones(n, 3)
        u = torch.rand(n)
        mask[(u >= .60) & (u < .70), 0] = 0
        mask[(u >= .70) & (u < .80), 1] = 0
        mask[(u >= .80) & (u < .90), 2] = 0
        mask[(u >= .90) & (u < .933), :] = torch.tensor([1.,0.,0.])
        mask[(u >= .933) & (u < .966), :] = torch.tensor([0.,1.,0.])
        mask[u >= .966, :] = torch.tensor([0.,0.,1.])
        prob = m.router_logits(p, mask).softmax(1)
        ecost = (p[:,None,:] * C[None,:,:]).sum(2)
        loss = (prob * ecost).sum(1).mean() + 5e-4 * (prob * torch.log(prob.clamp_min(1e-8))).sum(1).mean()
        opt.zero_grad(); loss.backward(); opt.step()
    return m.eval()


@torch.no_grad()
def dense_unseen_sweep(m, C):
    # 401 points; only seven discrete price-ratio anchors are used in router training.
    ratios = torch.logspace(-2, 2, 401)
    rows=[]; agree=0; route_counts=[0,0,0]
    a = torch.ones(1,3)
    anchors = [0.03,0.1,0.3,1.0,3.0,10.0,30.0]
    anchor_routes = [oracle(make_price(r), [1,1,1], C) for r in anchors]
    heldout = 0; heldout_agree=0; discrete_agree=0
    for r in ratios.tolist():
        price = make_price(r)
        p = torch.tensor([price])
        prob = m.router_logits(p,a).softmax(1)[0]
        rr = int(prob.argmax()); oo=oracle(price,[1,1,1],C)
        agree += int(rr==oo); route_counts[rr]+=1
        # Strong simple baseline: nearest training anchor in log-price-ratio space.
        ai = min(range(len(anchors)), key=lambda i: abs(math.log(r)-math.log(anchors[i])))
        discrete_route = anchor_routes[ai]
        discrete_agree += int(discrete_route == oo)
        is_anchor = any(abs(math.log(r/x)) < 1e-6 for x in anchors)
        if not is_anchor:
            heldout += 1; heldout_agree += int(rr==oo)
        rows.append({'ratio':r,'route':rr,'oracle':oo,'discrete_anchor_route':discrete_route,'prob':prob.tolist()})
    transitions=[]
    prev=None
    for row in rows:
        if row['route'] != prev:
            transitions.append(row)
            prev=row['route']
    return {'agreement':agree/len(rows),'heldout_agreement':heldout_agree/heldout,
            'discrete_anchor_agreement':discrete_agree/len(rows),
            'route_counts':route_counts,'n':len(rows),'heldout_n':heldout,
            'training_anchors':anchors,'anchor_routes':anchor_routes,
            'learned_route_transitions':transitions}


@torch.no_grad()
def random_contract_eval(m, C, n=4000, seed=0):
    g=torch.Generator().manual_seed(seed)
    lp=torch.rand(n,2,generator=g)*9.0-4.5
    prices=torch.exp(lp)*0.1
    masks=torch.ones(n,3)
    u=torch.rand(n,generator=g)
    masks[(u>=.55)&(u<.65),0]=0
    masks[(u>=.65)&(u<.75),1]=0
    masks[(u>=.75)&(u<.85),2]=0
    masks[(u>=.85)&(u<.90),:]=torch.tensor([1.,0.,0.])
    masks[(u>=.90)&(u<.95),:]=torch.tensor([0.,1.,0.])
    masks[u>=.95,:]=torch.tensor([0.,0.,1.])
    routes=m.choose(prices,masks)
    ecost=(prices[:,None,:]*C[None,:,:]).sum(2).masked_fill(~masks.bool(),float('inf'))
    oroutes=ecost.argmin(1)
    chosen=ecost[torch.arange(n),routes]
    best=ecost[torch.arange(n),oroutes]
    regret=chosen-best
    return {'agreement':float((routes==oroutes).float().mean()),
            'mean_regret':float(regret.mean()), 'p95_regret':float(torch.quantile(regret,.95)),
            'max_regret':float(regret.max())}


@torch.no_grad()
def simulated_hardware_transfer(m, C, seed=0):
    # Runtime-only recalibration: hardware multipliers convert an abstract user
    # scarcity vector into an effective resource price. Router weights are frozen;
    # hardware identity is never given to the model.
    hardware = {
        'compute_friendly': [0.35, 1.4],
        'balanced': [1.0,1.0],
        'compute_scarce': [2.5,0.55],
        'footprint_scarce': [0.65,2.2],
    }
    g=torch.Generator().manual_seed(seed+999)
    rows={}
    for name,h in hardware.items():
        n=1500
        scarcity=torch.exp(torch.rand(n,2,generator=g)*6.0-3.0)*0.1
        eff=scarcity*torch.tensor(h)[None,:]
        mask=torch.ones(n,3)
        routes=m.choose(eff,mask)
        ecost=(eff[:,None,:]*C[None,:,:]).sum(2)
        oracle_routes=ecost.argmin(1)
        rows[name]={'agreement':float((routes==oracle_routes).float().mean()),
                    'route_hist':[(routes==j).float().mean().item() for j in range(3)],
                    'n':n}
    return rows


@torch.no_grad()
def same_input_three_regimes(m):
    # Pick ratios well inside each oracle region. Same task input; only contract changes.
    settings={'footprint_scarce':0.03,'balanced_tradeoff':0.5,'compute_scarce':10.0}
    ii=torch.tensor([173]); bb=bits_all[ii]; target=int(y_all[ii])
    a=torch.ones(1,3); out={}
    for name,r in settings.items():
        p=torch.tensor([make_price(r)])
        logits,route,trace=m.forward_selected(bb,ii,p,a)
        out[name]={'ratio':r,'route':route,'trace':trace,'pred':int(logits.argmax(1)),'target':target}
    return out


@torch.no_grad()
def hook_audit(m):
    names=['retrieval','shallow1','shallow2','tied_stem','tied_block','head']
    counts={k:0 for k in names}; handles=[]
    def hk(name):
        def f(*args): counts[name]+=1
        return f
    for name in names:
        handles.append(getattr(m,name).register_forward_hook(hk(name)))
    ii=torch.tensor([173]);bb=bits_all[ii];a=torch.ones(1,3)
    rows={}
    for label,r in [('retrieval',10.0),('shallow',0.5),('tied_deep',0.03)]:
        for k in counts: counts[k]=0
        _,route,trace=m.forward_selected(bb,ii,torch.tensor([make_price(r)]),a)
        rows[label]={'route':route,'trace':trace,'hook_counts':dict(counts)}
    for h in handles:h.remove()
    ok=(rows['retrieval']['hook_counts']['retrieval']==1 and rows['retrieval']['hook_counts']['shallow1']==0 and rows['retrieval']['hook_counts']['tied_stem']==0 and
        rows['shallow']['hook_counts']['retrieval']==0 and rows['shallow']['hook_counts']['shallow1']==1 and rows['shallow']['hook_counts']['shallow2']==1 and rows['shallow']['hook_counts']['tied_stem']==0 and
        rows['tied_deep']['hook_counts']['retrieval']==0 and rows['tied_deep']['hook_counts']['shallow1']==0 and rows['tied_deep']['hook_counts']['tied_stem']==1 and rows['tied_deep']['hook_counts']['tied_block']==TIED_STEPS)
    return {'rows':rows,'exclusive_execution_verified':bool(ok)}


def main():
    seeds=[]
    for seed in [0,1,2,3,4]:
        base=train_capabilities(seed)
        acc=[route_accuracy(base,r) for r in range(3)]
        C,meta=profile_costs(base)
        aware=train_router(clone_capabilities(base,True),seed,C,True)
        blind=train_router(clone_capabilities(base,False),seed,C,False)
        sweep=dense_unseen_sweep(aware,C)
        rand_aware=random_contract_eval(aware,C,4000,seed+10)
        rand_blind=random_contract_eval(blind,C,4000,seed+10)
        hw=simulated_hardware_transfer(aware,C,seed)
        trace=same_input_three_regimes(aware)
        hooks=hook_audit(aware)
        no_safe=False
        try:
            ii=torch.tensor([0]); aware.forward_selected(bits_all[ii],ii,torch.tensor([[.1,.1]]),torch.zeros(1,3))
        except RuntimeError: no_safe=True
        seeds.append({'seed':seed,'accuracy':acc,'C':C.tolist(),'meta':meta,
                      'router_params_aware':sum(p.numel() for p in aware.router.parameters()),
                      'router_params_blind':sum(p.numel() for p in blind.router.parameters()),
                      'dense_sweep':sweep,'random_aware':rand_aware,'random_blind':rand_blind,
                      'hardware_transfer':hw,'same_input_three_regimes':trace,'hook_audit':hooks,
                      'no_safe_rejected':no_safe})

    summary={
        'seeds':len(seeds),
        'all_circuits_100pct_all_seeds':all(all(abs(a-1.0)<1e-12 for a in s['accuracy']) for s in seeds),
        'dense_unseen_mean_oracle_agreement':sum(s['dense_sweep']['heldout_agreement'] for s in seeds)/len(seeds),
        'dense_unseen_min_oracle_agreement':min(s['dense_sweep']['heldout_agreement'] for s in seeds),
        'dense_discrete_anchor_mean_oracle_agreement':sum(s['dense_sweep']['discrete_anchor_agreement'] for s in seeds)/len(seeds),
        'all_three_routes_used_all_seeds':all(all(c>0 for c in s['dense_sweep']['route_counts']) for s in seeds),
        'random_contract_aware_mean_agreement':sum(s['random_aware']['agreement'] for s in seeds)/len(seeds),
        'random_contract_blind_mean_agreement':sum(s['random_blind']['agreement'] for s in seeds)/len(seeds),
        'random_contract_aware_mean_regret':sum(s['random_aware']['mean_regret'] for s in seeds)/len(seeds),
        'random_contract_blind_mean_regret':sum(s['random_blind']['mean_regret'] for s in seeds)/len(seeds),
        'hardware_transfer_mean_agreement':{h:sum(s['hardware_transfer'][h]['agreement'] for s in seeds)/len(seeds) for h in seeds[0]['hardware_transfer']},
        'same_input_three_distinct_routes_all_seeds':all(len(set(v['route'] for v in s['same_input_three_regimes'].values()))==3 for s in seeds),
        'exclusive_execution_verified_all_seeds':all(s['hook_audit']['exclusive_execution_verified'] for s in seeds),
        'matched_router_params_all_seeds':all(s['router_params_aware']==s['router_params_blind'] for s in seeds),
        'no_safe_rejected_all_seeds':all(s['no_safe_rejected'] for s in seeds),
    }
    OUT.write_text(json.dumps({'summary':summary,'seeds':seeds},indent=2))
    print(json.dumps(summary,indent=2))

if __name__=='__main__': main()
