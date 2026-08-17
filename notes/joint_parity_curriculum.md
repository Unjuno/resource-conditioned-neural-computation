# Freeze-free parity curriculum and sampled routing follow-up

## Question

Can the harder 4-bit-parity topology-discovery failure be improved **without freezing capability parameters**, and without reducing the problem back to a fixed list of named routes?

The earlier audit showed that two failure modes interact: capability acquisition can collapse, and an independent per-stage router can be unstable even after capability is controlled. This follow-up tests whether training order, correlated allocation, and an explicit feasibility/resource split are enough to stabilize the same three-stage `skip / lookup / compute` supernet.

The experiment remains a tiny finite-domain mechanism study. Primitive operations and the three-stage search space are supplied by the experimenter.

## Main freeze-free experiment

All models start from scratch. Capability parameters are **never frozen**. Throughout training, rotating auxiliary task losses keep the six single-primitive probes (one lookup or one compute at each stage) capable.

Five conditions are compared:

1. `joint_factorized`: independent per-stage resource router active from step 0;
2. `joint_ar`: autoregressive resource router active from step 0;
3. `gated_factorized`: independent router activated only after all six probes become fully capable;
4. `gated_ar`: autoregressive router activated after capability readiness;
5. `constrained_ar`: same capability gate plus stronger alternating resource-policy updates using a binary feasibility barrier and resource cost.

A matched `constrained_ar_blind` control uses the same autoregressive architecture and curriculum but receives zeroed price features.

### Five-seed results

| mode | mean hard accuracy | mean tie-aware min-cost rate | worst seed | mean regret | seeds using >1 route |
|---|---:|---:|---:|---:|---:|
| joint factorized | 99.75% | 21.90% | 0.00% | 0.24381 | 2/5 |
| joint autoregressive | 100.00% | 37.15% | 0.00% | 0.19536 | 2/5 |
| gated factorized | 100.00% | 81.95% | 51.75% | 0.00978 | 5/5 |
| gated autoregressive | 100.00% | 97.25% | 91.75% | 0.00171 | 5/5 |
| **constrained autoregressive** | **100.00%** | **98.55%** | **95.75%** | **0.00057** | **5/5** |
| matched price-blind | 100.00% | 50.25% | 50.25% | 0.15863 | 0/5 |

The central result is that **correlation alone is not sufficient**: `joint_ar` still collapses badly in several seeds when resource optimization starts immediately. Delaying resource allocation until fallback primitives are capable is the larger intervention. Correlated autoregressive allocation then removes the remaining seed-specific instability that persists for the gated factorized router.

For the `constrained_ar` condition, all five seeds preserve 100% full-domain task accuracy, all five use multiple hard subgraphs, and mean tie-aware minimum-cost rate is **98.55%** with a **95.75% worst seed**. The matched price-blind control stays at 100% task accuracy but selects one fixed route in every seed and reaches only **50.25%** cost-optimality.

At the resource extremes, every `constrained_ar` seed uses a compute-only topology when the parameter-footprint proxy is expensive and a lookup-only topology when compute is expensive. The exact stage placement remains seed-dependent.

## Capability-readiness threshold sweep

The capability gate is not merely cosmetic. A three-seed sweep changes the minimum single-primitive probe accuracy required before resource optimization is activated.

| readiness threshold | mean min-cost rate | worst seed | mean hard accuracy |
|---|---:|---:|---:|
| 0% | 77.67% | 49.75% | 99.08% |
| 80% | 80.92% | 49.75% | 100.00% |
| 90% | 80.92% | 49.75% | 100.00% |
| 95% | 98.50% | 95.75% | 100.00% |
| 99% | 98.42% | 95.75% | 100.00% |
| 100% | 97.67% | 95.75% | 100.00% |

The sharpest change occurs between 90% and 95% readiness in this toy: the worst-seed cost-optimality rises from 49.75% to 95.75%. This supports a curriculum interpretation rather than a claim that one universal numeric threshold exists.

## Removing exact topology enumeration from router training

The strongest `constrained_ar` diagnostic still computes an exact expectation over all 27 topologies and uses periodic full-domain feasibility checks. To test whether the result is only an artifact of that exact enumeration, a second experiment replaces the router update with an **autoregressive sampled policy-gradient** objective:

- no complete topology enumeration in router training;
- four sampled topologies per resource-price anchor;
- binary feasibility estimated on fresh 64-state calibration minibatches;
- capability parameters continue training and are never frozen;
- the complete 256-state domain is used only for final evaluation.

Across five seeds:

- mean hard accuracy: **100.00%**;
- mean tie-aware minimum-cost rate: **95.05%**;
- worst seed: **91.25%**;
- mean regret: **0.00285**;
- multiple routes used: **5/5**.

Performance is lower than exact marginalization (95.05% vs 98.55%) but remains far above the matched price-blind control. This reduces, but does not remove, the concern that the parity result depends on exhaustive search-space enumeration.

## Mechanistic interpretation

The experiments now separate four roles:

1. **capability preservation** — primitives that may be needed later must remain able to solve the task;
2. **capability readiness** — strong resource pressure introduced too early can lock the system into a shortcut before alternatives mature;
3. **correlated allocation** — coordinated subgraph decisions are more stable with an autoregressive router than independent stage choices in difficult seeds;
4. **feasibility vs optimization** — task-validity is treated as a constraint/barrier, while resource price optimizes within the currently valid set.

This resembles the runtime/model responsibility split already seen elsewhere in the repository: feasibility should constrain optimization rather than be traded against it as an undifferentiated soft reward.

## What this supports

A stronger but still narrow statement is supported:

> Within the supplied three-stage primitive search space, resource-conditioned parity subgraphs can be learned from scratch without freezing capability parameters when training explicitly preserves and matures fallback capabilities before strong resource allocation, and correlated routing is used for the subsequent allocation problem.

The sampled-policy follow-up shows that the effect survives removal of exact complete-topology marginalization in router training in this tiny search space.

## What this does not support

- unconstrained architecture discovery;
- a single end-to-end undifferentiated loss that self-organizes everything automatically;
- a scalable NAS method;
- a universal 95% readiness threshold;
- removal of all search-space knowledge: primitive types and stage count remain supplied;
- input-difficulty-dependent routing;
- hard real-time/WCET guarantees;
- physical memory, bandwidth, or Joule savings;
- large-model/LLM generalization.

The successful training is better described as **capability-gated, constrained joint/alternating optimization** than as unconstrained spontaneous self-organization.
