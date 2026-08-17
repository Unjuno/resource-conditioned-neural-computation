# Router stabilization audit on the parity stress task

## Question

The constrained topology-search experiment fails to produce multiple resource-conditioned topologies reliably on 4-bit parity. Is that failure caused only by missing compute capability, or does the router parameterization itself remain a bottleneck after capability is controlled?

This experiment is deliberately diagnostic. It does **not** claim joint topology discovery.

## Controlled capability snapshot

The same 3-stage / 27-topology search space is used. Before comparing routers, the six single-primitive probe topologies are trained explicitly:

- one `lookup` at stage 0, 1, or 2;
- one `compute` at stage 0, 1, or 2;
- all other stages `skip`.

Across all five seeds, all six probes reach **100% accuracy over the complete 256-state 4-bit-parity domain**. The capability parameters are then frozen. This removes the earlier confound where a compute-only route sometimes never became capable.

The router comparison therefore asks only: given the same valid topology set and the same resource-cost table, how reliably does the routing parameterization recover a minimum-cost valid topology as resource price changes?

## Tie-aware metric

Several stage placements can have exactly the same resource cost. The primary metric is therefore **tie-aware optimal-cost rate**: a selected topology counts as optimal when its cost equals the minimum cost among all 100%-accurate topologies, regardless of which tied topology a Python `min()` call happens to return.

Mean regret is also reported.

## Five-seed results

All router variants maintain **100% hard task accuracy**, so the differences below are allocation differences rather than quality differences.

| router / objective | mean tie-aware optimal-cost rate | worst seed | mean regret |
|---|---:|---:|---:|
| independent-stage factorized + confidence/margin objective | 83.95% | 51.75% | 0.00905 |
| independent-stage factorized + binary feasibility | 77.30% | 49.75% | 0.01264 |
| **autoregressive + binary feasibility** | **94.85%** | **93.50%** | **0.00235** |
| flat 27-way route policy + binary feasibility | 94.20% | 92.50% | **0.00146** |
| autoregressive, best of 4 restarts by the same training objective | 95.60% | 92.00% | 0.00155 |

The binary-feasibility objective assigns no extra reward to a topology merely for having a larger classification margin once it is already exactly correct. Importantly, binary feasibility alone does **not** rescue the independent-stage factorization: two seeds remain near 50% cost-optimality.

## Interpretation

The controlled result points to a second failure mode beyond capability forgetting:

> resource-conditioned topology decisions are correlated decisions, and treating every stage as an independent categorical choice can create poor local optima even when all required primitive capabilities already exist.

An autoregressive router, where later stage choices condition on earlier choices, is markedly more stable in this diagnostic. A flat route-level categorical policy is also stable, but it explicitly enumerates all 27 complete topologies and is therefore retained only as a small-search-space reference.

The autoregressive router does not enumerate complete routes as output classes, but the present training audit still computes an exact expectation over all 27 topologies. That is feasible only because the search space is tiny. This result is therefore **not a scalable NAS method claim**.

Multiple random restarts modestly improve the mean but do not monotonically improve every seed, so local minima are not eliminated simply by restarting.

## What this changes

The parity failure should no longer be described as only "lookup shortcut collapse." The evidence now separates at least three interacting requirements:

1. **capability preservation** — compute/lookup primitives that may be needed later must actually remain capable;
2. **correlated allocation** — the router must represent coordinated subgraph choices rather than only independent per-stage preferences;
3. **optimization stability** — even correlated routers retain residual local-optimum error.

This strengthens the negative boundary around unconstrained self-organization: a useful topology search procedure needs more than a resource penalty and a large supernet.

## What this does not show

- a joint-from-scratch solution to the parity topology-discovery problem;
- general superiority of autoregressive routers;
- a scalable alternative to NAS;
- topology discovery without a supplied primitive search space;
- physical memory/energy savings;
- hard-real-time or WCET guarantees.

See `results/router_stabilization_audit_results.json` for the five-seed summary and `experiments/router_stabilization_audit.py` for reproduction.
