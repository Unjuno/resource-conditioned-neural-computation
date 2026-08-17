"""Re-audit topology-search cost optimality with ties handled correctly.

The original `global_oracle_agreement` compares a selected topology against one
arbitrarily chosen minimum-cost topology. Because stage-symmetric topologies can
have identical resource cost, route identity can undercount resource-optimal choices.
This audit reports both exact-route agreement and tie-aware minimum-cost rate.
"""
import argparse, json
from pathlib import Path
import topology_search_discovery as base

ROOT=Path(__file__).resolve().parents[1]
DEFAULT_OUT=ROOT/'results'/'topology_tie_aware_metric_audit_results.json'

def evaluate(seed,task='xor2'):
    m=base.train(seed,task,True); acc=base.topology_accuracy(m,task); valid=[t for t,a in acc.items() if a==1.0]
    exact=tie=prune_exact=prune_tie=full=0; regret=prune_regret=0.0
    for ratio in [10**(-2+4*i/399) for i in range(400)]:
        p=base.price(ratio); t=m.topology(p); q=base.locally_prune(t,p,acc); full+=int(acc[t]==1.0)
        costs={v:base.topo_cost(v,p) for v in valid}; min_cost=min(costs.values()); oracle=min(valid,key=lambda v:costs[v])
        c=base.topo_cost(t,p); pc=base.topo_cost(q,p)
        exact+=int(t==oracle); tie+=int(c<=min_cost+1e-7); prune_exact+=int(q==oracle); prune_tie+=int(pc<=min_cost+1e-7)
        regret+=max(0.0,c-min_cost); prune_regret+=max(0.0,pc-min_cost)
    return {'seed':seed,'exact':exact/400,'tie':tie/400,'regret':regret/400,'prune_exact':prune_exact/400,
            'prune_tie':prune_tie/400,'prune_regret':prune_regret/400,'hardacc':full/400}

def suite(out_path):
    rows=[evaluate(s) for s in range(5)]; keys=['exact','tie','regret','prune_exact','prune_tie','prune_regret','hardacc']
    result={'setup':{'task':'xor2','seeds':list(range(5)),'dense_price_points':400,
                     'reason':'Exact route identity is not a valid cost-optimality metric when multiple topologies tie at the same minimum resource cost.'},
            'seeds':rows,'aggregate':{k:sum(r[k] for r in rows)/len(rows) for k in keys}}
    Path(out_path).write_text(json.dumps(result,indent=2)); return result

if __name__=='__main__':
    ap=argparse.ArgumentParser(); ap.add_argument('--seed',type=int); ap.add_argument('--suite',action='store_true'); ap.add_argument('--out',default=str(DEFAULT_OUT)); a=ap.parse_args()
    if a.suite: suite(a.out)
    else: print(json.dumps(evaluate(0 if a.seed is None else a.seed),indent=2))
