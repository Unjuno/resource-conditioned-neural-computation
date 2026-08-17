# Router parameterization sensitivity audit

## Why this audit exists

A generalized follow-up initially appeared to contradict the public four-stage homogeneous-cost result. Before treating that as a search-space failure, the public `s4_hom` experiment was reimplemented exactly.

The matched reimplementation reproduces the committed result: **98.10% mean / 91.25% worst-seed** tie-aware minimum-cost rate across five seeds.

Therefore the apparent contradiction was not accepted as a new search-space result. The implementation differences were isolated instead.

## One-variable ablations

All conditions use the same four-stage homogeneous `skip / lookup / compute` search space, 4-bit-parity task, seven price anchors, exact finite-search-space resource objective, and 1800 total training steps.

| condition | mean optimal rate | worst seed |
|---|---:|---:|
| matched public baseline | **98.10%** | 91.25% |
| change only capability-probe sampling stride (`+2` -> `+3`) | **98.35%** | 92.25% |
| change only AR head parameterization | **86.35%** | **50.25%** |

The router-head ablation replaces the public first-stage linear categorical head with the same two-layer `Linear -> tanh -> Linear` form used at later autoregressive stages. The rest of the training recipe remains matched.

## Interpretation

The public four-stage result is reproducible, but the routing optimization is **sensitive to seemingly small policy parameterization choices**. The capability sampling change does not materially damage the result in this audit; the router-head change does.

This is consistent with the earlier parity router-stabilization audit: task capability and resource-policy optimization are distinct, and resource allocation can enter poor local optima even when valid subgraphs exist.

The appropriate conclusion is not that four-stage search fails. It is:

> the learned resource policy is implementation-sensitive, so router architecture must be treated as a substantive experimental variable rather than incidental plumbing.

## What this changes

- The committed `s4_hom` robustness result remains authoritative.
- A generalized implementation that produced lower depth-4 performance is **not** promoted as an independent search-space falsification because it changed policy parameterization at the same time.
- Future search-space comparisons should use architecture-matched routers or explicitly report router-parameterization ablations.

## What this does not show

- general superiority of the public AR head architecture;
- robustness to large search spaces;
- a scalable NAS solution;
- superiority over analytic scheduling when costs are known;
- hard-real-time, physical energy, or memory-traffic guarantees.
