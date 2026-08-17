import json, math, random
from pathlib import Path
import torch
import torch.nn as nn
import torch.nn.functional as F

# Minimal direct test of the original architectural claim:
# one fixed parameterized network, one shared output head, and resource-conditioned
# internal subgraph selection. This is not a hard-real-time experiment.

torch.set_num_threads(1)
N_BITS = 12
N_STATES = 1 << N_BITS
H = 16
BASE = Path(__file__).resolve().parents[1]
OUT = BASE / 'results' / 'internal_circuit_conditioning_results.json'


def all_states():
    idx = torch.arange(N_STATES, dtype=torch.long)
    shifts = torch.arange(N_BITS, dtype=torch.long)
    bits = ((idx[:, None] >> shifts) & 1).float()
    y = (bits.sum(1) >= (N_BITS // 2 + 1)).long()
    return idx, bits, y


ALL_IDX, ALL_BITS, ALL_Y = all_states()


class ResidualBlock(nn.Module):
    def __init__(self, width=H):
        super().__init__()
        self.fc = nn.Linear(width, width)

    def forward(self, x):
        return F.relu(x + self.fc(x))


class ResourceConditionedCircuitNet(nn.Module):
    """One model with two internal execution subgraphs and a shared classifier head.

    circuit 0: retrieval node -> shared head
    circuit 1: stem -> four residual compute blocks -> shared head

    Only the selected internal subgraph is executed in forward_selected().
    """

    def __init__(self, use_price=True):
        super().__init__()
        self.use_price = use_price
        self.retrieval = nn.Embedding(N_STATES, H)
        self.stem = nn.Linear(N_BITS, H)
        self.compute_blocks = nn.ModuleList([ResidualBlock(H) for _ in range(4)])
        self.head = nn.Linear(H, 2)
        # matched architecture for price-aware and price-blind routing
        self.router = nn.Sequential(nn.Linear(4, 16), nn.Tanh(), nn.Linear(16, 2))

    def router_logits(self, price, availability):
        price_features = torch.log(price.clamp_min(1e-6)) if self.use_price else torch.zeros_like(price)
        x = torch.cat([price_features, availability], dim=1)
        z = self.router(x)
        return z + (availability - 1.0) * 1e4

    def choose(self, price, availability):
        return self.router_logits(price, availability).argmax(1)

    def forward_circuit(self, idx, bits, circuit):
        if circuit == 0:
            h = self.retrieval(idx)
            active = ['retrieval', 'head']
        elif circuit == 1:
            h = F.relu(self.stem(bits))
            active = ['stem']
            for i, block in enumerate(self.compute_blocks):
                h = block(h)
                active.append(f'compute_block_{i}')
            active.append('head')
        else:
            raise ValueError(circuit)
        return self.head(h), active

    @torch.no_grad()
    def forward_selected(self, idx, bits, price, availability):
        if availability.sum(1).eq(0).any():
            raise RuntimeError('not admitted: no execution circuit available')
        j = int(self.choose(price, availability)[0])
        logits, active = self.forward_circuit(idx, bits, j)
        return logits, j, active


def circuit_costs(model):
    # Active parameter-footprint proxy counts parameters touched by the selected
    # circuit, not total resident model memory. Compute proxy counts dense MACs
    # plus a small lookup proxy.
    head_p = sum(p.numel() for p in model.head.parameters())
    retrieval_p = sum(p.numel() for p in model.retrieval.parameters()) + head_p
    compute_p = sum(p.numel() for p in model.stem.parameters()) + \
                sum(p.numel() for b in model.compute_blocks for p in b.parameters()) + head_p

    retrieval_ops = H + H * 2  # lookup proxy + shared head MACs
    compute_ops = N_BITS * H + 4 * H * H + H * 2

    comp = torch.tensor([retrieval_ops, compute_ops], dtype=torch.float)
    foot = torch.tensor([retrieval_p, compute_p], dtype=torch.float)
    C = torch.stack([comp / comp.max(), foot / foot.max()], dim=1)
    return C, {
        'active_params_proxy': [retrieval_p, compute_p],
        'compute_ops_proxy': [retrieval_ops, compute_ops],
        'resource_columns': ['compute_proxy', 'active_parameter_footprint_proxy'],
        'total_resident_params': sum(p.numel() for p in model.parameters()),
    }


def train_capabilities(seed):
    torch.manual_seed(seed)
    random.seed(seed)
    m = ResourceConditionedCircuitNet(use_price=True)

    # 1) Train algorithmic internal circuit + shared head.
    for p in m.retrieval.parameters():
        p.requires_grad_(False)
    for p in m.router.parameters():
        p.requires_grad_(False)
    opt = torch.optim.AdamW(
        list(m.stem.parameters()) + list(m.compute_blocks.parameters()) + list(m.head.parameters()),
        lr=3e-3, weight_decay=1e-5)
    for _ in range(900):
        sel = torch.randint(0, N_STATES, (512,))
        logits, _ = m.forward_circuit(sel, ALL_BITS[sel], 1)
        loss = F.cross_entropy(logits, ALL_Y[sel])
        opt.zero_grad(); loss.backward(); opt.step()

    # 2) Train retrieval internal node against the same frozen shared head.
    for p in m.stem.parameters(): p.requires_grad_(False)
    for p in m.compute_blocks.parameters(): p.requires_grad_(False)
    for p in m.head.parameters(): p.requires_grad_(False)
    for p in m.retrieval.parameters(): p.requires_grad_(True)
    opt = torch.optim.Adam(m.retrieval.parameters(), lr=5e-2)
    for _ in range(250):
        sel = torch.randint(0, N_STATES, (1024,))
        logits, _ = m.forward_circuit(sel, ALL_BITS[sel], 0)
        loss = F.cross_entropy(logits, ALL_Y[sel])
        opt.zero_grad(); loss.backward(); opt.step()

    # freeze capabilities before routing post-training
    for name, p in m.named_parameters():
        p.requires_grad_(name.startswith('router.'))
    return m


@torch.no_grad()
def forced_accuracy(m, circuit):
    logits, _ = m.forward_circuit(ALL_IDX, ALL_BITS, circuit)
    return float((logits.argmax(1) == ALL_Y).float().mean())


def train_router(m, seed, C, use_price, steps=1200):
    m.use_price = use_price
    torch.manual_seed(seed + (1000 if use_price else 2000))
    random.seed(seed + 1000)
    # reset only router; capability parameters stay identical/frozen
    for mod in m.router.modules():
        if hasattr(mod, 'reset_parameters'):
            mod.reset_parameters()
    opt = torch.optim.Adam(m.router.parameters(), lr=6e-3)
    for _ in range(steps):
        n = 256
        p = torch.exp(torch.rand(n, 2) * 6.0 - 3.0)
        u = torch.rand(n)
        mask = torch.ones(n, 2)
        mask[u < .15, 1] = 0
        mask[(u >= .15) & (u < .30), 0] = 0
        prob = m.router_logits(p, mask).softmax(1)
        ecost = (p[:, None, :] * C[None, :, :]).sum(2)
        # equal-quality circuits: optimize resource objective only
        loss = (prob * ecost).sum(1).mean() + 1e-3 * (prob * torch.log(prob.clamp_min(1e-8))).sum(1).mean()
        opt.zero_grad(); loss.backward(); opt.step()
    return m.eval()


def oracle_choice(price, availability, C):
    p = torch.tensor(price, dtype=torch.float)
    a = availability.bool()
    if not bool(a.any()):
        return None
    costs = (C * p[None, :]).sum(1).masked_fill(~a, float('inf'))
    return int(costs.argmin())


@torch.no_grad()
def sweep(m, C):
    ratios = [0.04, 0.1, 0.25, 0.5, 1, 2, 4, 10, 25]
    out = []
    availability = torch.ones(1, 2)
    for r in ratios:
        # hold geometric mean near 0.1
        pc = 0.1 * math.sqrt(r)
        pf = 0.1 / math.sqrt(r)
        p = torch.tensor([[pc, pf]], dtype=torch.float)
        prob = m.router_logits(p, availability).softmax(1)[0]
        route = int(prob.argmax())
        oracle = oracle_choice([pc, pf], availability[0], C)
        out.append({'ratio': r, 'price': [pc, pf], 'prob': prob.tolist(), 'route': route, 'oracle': oracle})
    return out


@torch.no_grad()
def fixed_input_counterfactual(m):
    # Hold the task input fixed and change only resource price. We report one
    # explicit trace and also verify the claim exhaustively over all 4096 states.
    idx = torch.tensor([1234])
    bits = ALL_BITS[idx]
    y = int(ALL_Y[idx].item())
    settings = {
        'compute_expensive': [1.0, .05],
        'footprint_expensive': [.05, 1.0],
    }
    rows = {}
    availability = torch.ones(1, 2)
    routes = {}
    for name, price in settings.items():
        p = torch.tensor([price], dtype=torch.float)
        logits, route, active = m.forward_selected(idx, bits, p, availability)
        routes[name] = route
        rows[name] = {
            'route': route,
            'active_modules': active,
            'prediction': int(logits.argmax(1).item()),
            'target': y,
        }

    # Exhaustive same-input counterfactual check over the finite task domain.
    logits_c, _ = m.forward_circuit(ALL_IDX, ALL_BITS, routes['compute_expensive'])
    logits_f, _ = m.forward_circuit(ALL_IDX, ALL_BITS, routes['footprint_expensive'])
    pred_c = logits_c.argmax(1)
    pred_f = logits_f.argmax(1)
    rows['exhaustive_check'] = {
        'n_inputs': N_STATES,
        'route_changed': routes['compute_expensive'] != routes['footprint_expensive'],
        'compute_expensive_accuracy': float((pred_c == ALL_Y).float().mean()),
        'footprint_expensive_accuracy': float((pred_f == ALL_Y).float().mean()),
        'prediction_agreement': float((pred_c == pred_f).float().mean()),
    }
    return rows


@torch.no_grad()
def execution_hook_audit(m):
    counts = {'retrieval':0, 'stem':0, 'head':0}
    for i in range(len(m.compute_blocks)):
        counts[f'compute_block_{i}'] = 0

    handles = []
    def hook_for(name):
        def _hook(*args):
            counts[name] += 1
        return _hook

    handles.append(m.retrieval.register_forward_hook(hook_for('retrieval')))
    handles.append(m.stem.register_forward_hook(hook_for('stem')))
    handles.append(m.head.register_forward_hook(hook_for('head')))
    for i, block in enumerate(m.compute_blocks):
        handles.append(block.register_forward_hook(hook_for(f'compute_block_{i}')))

    idx = torch.tensor([1234]); bits = ALL_BITS[idx]; a = torch.ones(1,2)
    traces = {}
    for name, price in {'compute_expensive':[1.0,.05], 'footprint_expensive':[.05,1.0]}.items():
        for k in counts: counts[k] = 0
        logits, route, active = m.forward_selected(idx, bits, torch.tensor([price],dtype=torch.float), a)
        traces[name] = {'route':route, 'declared_active':active, 'hook_counts':dict(counts)}

    for h in handles: h.remove()
    retrieval_ok = traces['compute_expensive']['hook_counts']['retrieval'] == 1 and \
                   traces['compute_expensive']['hook_counts']['stem'] == 0 and \
                   all(traces['compute_expensive']['hook_counts'][f'compute_block_{i}'] == 0 for i in range(4))
    compute_ok = traces['footprint_expensive']['hook_counts']['retrieval'] == 0 and \
                 traces['footprint_expensive']['hook_counts']['stem'] == 1 and \
                 all(traces['footprint_expensive']['hook_counts'][f'compute_block_{i}'] == 1 for i in range(4))
    return {'traces':traces, 'inactive_subgraph_not_executed': bool(retrieval_ok and compute_ok)}


@torch.no_grad()
def intervention(m, C):
    envs = {
        'compute_expensive': [1.0, .05],
        'footprint_expensive': [.05, 1.0],
    }
    availability = torch.ones(1, 2)
    out = {}
    for env, actual in envs.items():
        swapped = envs['footprint_expensive' if env == 'compute_expensive' else 'compute_expensive']
        row = {}
        for signal, router_price in [('true', actual), ('swapped', swapped), ('constant', [.1, .1])]:
            p = torch.tensor([router_price], dtype=torch.float)
            route = int(m.choose(p, availability)[0])
            actual_cost = float((torch.tensor(actual) * C[route]).sum())
            row[signal] = {'route': route, 'actual_resource_objective': actual_cost}
        out[env] = row
    return out


def clone_capabilities(src, use_price):
    dst = ResourceConditionedCircuitNet(use_price=use_price)
    # copy all capability parameters, not router
    sd = src.state_dict()
    dst_sd = dst.state_dict()
    for k, v in sd.items():
        if not k.startswith('router.'):
            dst_sd[k] = v.clone()
    dst.load_state_dict(dst_sd)
    for name, p in dst.named_parameters():
        p.requires_grad_(name.startswith('router.'))
    return dst


def main():
    all_seed_rows = []
    for seed in [0, 1, 2]:
        base = train_capabilities(seed)
        acc = [forced_accuracy(base, 0), forced_accuracy(base, 1)]
        C, meta = circuit_costs(base)

        price_model = clone_capabilities(base, True)
        control_model = clone_capabilities(base, False)
        price_model = train_router(price_model, seed, C, True)
        control_model = train_router(control_model, seed, C, False)

        sw = sweep(price_model, C)
        oracle_agreement = sum(int(x['route'] == x['oracle']) for x in sw)
        counterfactual = fixed_input_counterfactual(price_model)
        inter = intervention(price_model, C)
        hook_audit = execution_hook_audit(price_model)

        # Matched-control response at two asymmetric prices.
        control_rows = {}
        for name, price in {'compute_expensive':[1.0,.05], 'footprint_expensive':[.05,1.0]}.items():
            p = torch.tensor([price], dtype=torch.float)
            a = torch.ones(1,2)
            control_rows[name] = int(control_model.choose(p, a)[0])

        # No-safe-route semantics.
        no_safe = None
        try:
            idx = torch.tensor([0]); bits = ALL_BITS[idx]
            price_model.forward_selected(idx, bits, torch.tensor([[.1,.1]]), torch.zeros(1,2))
        except RuntimeError as e:
            no_safe = str(e)

        all_seed_rows.append({
            'seed': seed,
            'forced_accuracy': acc,
            'cost_matrix': C.tolist(),
            'meta': meta,
            'router_params_price': sum(p.numel() for p in price_model.router.parameters()),
            'router_params_control': sum(p.numel() for p in control_model.router.parameters()),
            'sweep': sw,
            'oracle_agreement': oracle_agreement,
            'fixed_input_counterfactual': counterfactual,
            'intervention': inter,
            'execution_hook_audit': hook_audit,
            'price_blind_control_routes': control_rows,
            'no_safe_route': no_safe,
        })

    summary = {
        'all_forced_accuracy_1': all(all(abs(a - 1.0) < 1e-9 for a in r['forced_accuracy']) for r in all_seed_rows),
        'oracle_agreement_points': sum(r['oracle_agreement'] for r in all_seed_rows),
        'oracle_total_points': 27,
        'counterfactual_route_changed_all_seeds': all(
            r['fixed_input_counterfactual']['compute_expensive']['route'] != r['fixed_input_counterfactual']['footprint_expensive']['route']
            for r in all_seed_rows),
        'counterfactual_prediction_preserved_all_seeds': all(
            r['fixed_input_counterfactual']['exhaustive_check']['compute_expensive_accuracy'] == 1.0 and
            r['fixed_input_counterfactual']['exhaustive_check']['footprint_expensive_accuracy'] == 1.0 and
            r['fixed_input_counterfactual']['exhaustive_check']['prediction_agreement'] == 1.0
            for r in all_seed_rows),
        'counterfactual_inputs_checked_per_seed': N_STATES,
        'matched_router_params': [[r['router_params_price'], r['router_params_control']] for r in all_seed_rows],
        'no_safe_route_rejected_all_seeds': all(r['no_safe_route'] is not None for r in all_seed_rows),
        'inactive_subgraph_not_executed_all_seeds': all(r['execution_hook_audit']['inactive_subgraph_not_executed'] for r in all_seed_rows),
    }
    OUT.parent.mkdir(parents=True, exist_ok=True)
    OUT.write_text(json.dumps({'summary': summary, 'seeds': all_seed_rows}, indent=2))
    print(json.dumps(summary, indent=2))


if __name__ == '__main__':
    main()
