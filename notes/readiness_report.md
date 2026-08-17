# Resource-Conditioned Neural Computation — Preprint Readiness Report

## Status

**STOP condition remains reached for a short arXiv-style technical/mechanism note, subject to the public review window.**

The strongest defensible systems claim remains narrow:

> a neural system can use an explicit normalized resource condition to change the actually executed internal computation strategy, while an independent runtime availability mechanism constrains which execution classes may run.

The evidence now extends from hand-constructed route choice to constrained subgraph discovery inside a supplied primitive-operation supernet, including a harder parity follow-up where capability and resource routing are trained from scratch **without freezing capability parameters** under a capability-gated constrained curriculum.

This still does **not** establish unconstrained/general neural architecture discovery, a single undifferentiated self-organizing objective, hard real-time/WCET guarantees, physical energy savings, arbitrary hardware portability, or LLM generalization.

## Evidence ladder

### 1. Two-strategy constructive result

Functionally equivalent retrieval/copy and algorithmic computation paths have different normalized compute and active-parameter-footprint proxies. A matched price-aware router changes route with resource price, a price-blind control does not, and price-input intervention reverses routing in the expected direction.

For the known two-route cost table, analytic `argmin(price · cost)` remains the exact oracle. This establishes a mechanism/interface, not superiority to exact external scheduling.

### 2. Direct fixed-network internal-circuit execution

One fixed `ResourceConditionedCircuitNet` changes its actually executed module sequence when only the resource condition changes. Across three seeds and all 4,096 finite task states, prediction is preserved and forward hooks confirm inactive modules are not executed.

### 3. Three resource-distinct circuits and contract generalization

A fixed network with retrieval, shallow-compute, and tied-deep-compute traces keeps all three routes at 100% accuracy across five seeds. Seven discrete training price ratios generalize to held-out continuous ratios at **98.64% mean oracle agreement**; a nearest-anchor external scheduler reaches **98.25%**. Across random price/mask contracts, the price-aware router reaches **98.72%** versus **45.82%** for the matched price-blind router.

### 4. Joint capability acquisition for supplied candidate circuits

With three deliberately constructed circuit types, naive joint training forgets a fallback. Adding task supervision to every potentially admissible circuit preserves all three at 100% in all five seeds and yields **98.15%** held-out dense agreement and **97.36%** random-contract agreement without capability pretraining/freeze.

Relative price coordinates matter: raw log prices fall to **79.56%** under common-scale shift while centered log prices recover 97.36%.

### 5. Constrained topology discovery inside a supplied supernet

A three-stage `skip / lookup / compute` supernet defines 27 hard topologies but no complete-route labels. On XOR across five seeds, every price-aware seed selects four distinct hard topologies at 100% exhaustive task accuracy, while the price-blind control selects one fixed topology.

Tie-aware re-audit gives **73.10%** direct minimum-cost rate with regret ~0.01651. Validation-only local pruning improves this to **94.6%** with regret ~0.00274. The direct topology search is therefore still not globally resource-optimal.

### 6. Frozen-capability parity router audit

The original end-to-end parity search is unstable. Holding capability fixed after making all six single-primitive placements 100% accurate reveals that router structure is another bottleneck:

| router | mean tie-aware optimal-cost rate | worst seed | mean regret |
|---|---:|---:|---:|
| independent-stage factorized | 77.30% | 49.75% | 0.01264 |
| autoregressive | 94.85% | 93.50% | 0.00235 |
| flat 27-way route policy | 94.20% | 92.50% | 0.00146 |

This identifies correlated allocation as important, but capability is frozen deliberately in this diagnostic.

### 7. Freeze-free parity curriculum

The newest experiment removes the freeze. Capability parameters and resource routing start from scratch in the same run, with rotating supervision preserving the six single-primitive fallback capabilities.

Five conditions isolate training order and router structure:

| condition | mean hard accuracy | mean tie-aware min-cost rate | worst seed | mean regret |
|---|---:|---:|---:|---:|
| immediate joint factorized | 99.75% | 21.90% | 0.00% | 0.24381 |
| immediate joint autoregressive | 100.00% | 37.15% | 0.00% | 0.19536 |
| capability-gated factorized | 100.00% | 81.95% | 51.75% | 0.00978 |
| capability-gated autoregressive | 100.00% | 97.25% | 91.75% | 0.00171 |
| **capability-gated constrained autoregressive** | **100.00%** | **98.55%** | **95.75%** | **0.00057** |
| matched price-blind | 100.00% | 50.25% | 50.25% | 0.15863 |

All five successful constrained-autoregressive seeds use multiple hard subgraphs. At resource extremes, all use compute-only execution when parameter footprint is expensive and lookup-only execution when compute is expensive; exact stage placement varies by seed.

This shows that **correlation alone is not sufficient**. The larger intervention is delaying strong resource allocation until fallback capabilities have matured, then solving allocation with a correlated router and an explicit binary feasibility/resource split.

A three-seed readiness sweep reinforces this: worst-seed cost-optimality stays at **49.75%** for 80–90% readiness but rises to **95.75%** at 95% readiness in this toy. No universal 95% threshold is claimed.

### 8. Sampled policy without exact complete-topology marginalization

The exact constrained router still has a strong tiny-search-space advantage: it computes expectations over all 27 topologies and periodically uses full-domain feasibility.

A follow-up removes those two features from router training. An autoregressive sampled policy draws four topologies per price anchor and uses fresh 64-state calibration minibatches for binary feasibility. Capability parameters continue training and never freeze; the complete 256-state domain is used only for final evaluation.

Across five seeds:

- hard task accuracy: **100% in all seeds**;
- mean tie-aware minimum-cost rate: **95.05%**;
- worst seed: **91.25%**;
- mean regret: **0.00285**;
- multiple routes: **5/5 seeds**.

This is weaker than exact marginalization (95.05% vs 98.55%) but shows the parity result is not solely an artifact of enumerating all 27 topologies during router training.

### 9. Simulated normalized-contract transfer

A frozen three-circuit router consumes runtime-recalibrated resource prices under four separable multiplicative calibration profiles without receiving hardware identity. Mean oracle agreement remains approximately **97.85%–98.51%**.

This supports only a narrow normalized-contract interface under that simulation.

### 10. Runtime timing negative result

Same-core Linux contention prevents stable route-specific empirical P99 separation. Scheduler/preemption tails affect short and long routes, and state-specific recalibration does not consistently improve held-out miss rate.

Therefore route-wise P99 calibration on ordinary Linux is **not** a hard-real-time/WCET result.

## Current interpretation

The experiments now point to four layers that should not be conflated:

1. **capability preservation** — every execution path the runtime may need later must remain task-capable;
2. **capability readiness** — applying resource pressure too early can lock the model into a shortcut before alternatives mature;
3. **correlated allocation** — useful resource-conditioned subgraphs can require coordinated choices rather than independent stage decisions;
4. **feasibility/timing** — validity/availability should constrain resource optimization instead of being traded against price as one soft scalar reward.

This is increasingly consistent with the original runtime/model split: runtime feasibility defines what may run; resource price chooses among valid choices; the neural system implements the resource-conditioned internal computation.

## Defensible claims

### Supported

1. Explicit resource condition can control the actually executed internal computation in the tested finite systems.
2. The effect extends from two routes to multiple resource-distinct circuits and constrained subgraphs in a supplied search space.
3. Capability acquisition and resource allocation can be trained from scratch without freezing capability parameters under an explicit capability-preserving curriculum.
4. On parity, delaying resource allocation until fallback capability is mature and using correlated constrained routing yields **98.55% mean / 95.75% worst-seed** tie-aware minimum-cost rate at 100% task accuracy across five seeds.
5. The matched price-blind curriculum stays at one route and **50.25%** cost-optimality.
6. The parity effect survives replacing exact complete-topology marginalization with sampled autoregressive policy training, at **95.05% mean / 91.25% worst-seed**.
7. Relative scarcity coordinates improve robustness when only price ratios matter.
8. Runtime availability can override neural price routing by construction.

### Not supported

1. Hard real-time guarantees or WCET bounds.
2. Physical energy savings in joules.
3. Reduced total resident memory from route switching.
4. Universal superiority to external scheduling or NAS.
5. General/unconstrained architecture discovery.
6. A single undifferentiated end-to-end objective that reliably self-organizes capability, topology, feasibility, and resource allocation.
7. A universal capability-readiness threshold.
8. A scalable NAS method; the sampled-policy experiment still uses a tiny supplied search space and known proxy costs.
9. Large-model/LLM generalization.
10. Arbitrary real-hardware portability.
11. Stable route-specific P99 safety masks under ordinary Linux contention.

## Recommended preprint framing

A short mechanism note remains defensible under a title such as:

**Resource-Conditioned Neural Computation: Learned Price-Aware Execution Paths under Runtime Availability Constraints**

The architectural motivation can now be stated more directly: resource conditions can control the effective internal circuit of one fixed neural system, and constrained resource-conditioned subgraphs can be learned without freezing capability parameters in the tested toy when capability readiness, correlated allocation, and feasibility/resource separation are handled explicitly.

Do **not** frame this as a new general NAS method, unconstrained spontaneous architecture discovery, a hard-real-time neural architecture, a physical energy result, or a proof of general hardware portability.

## Next action

The mechanism is now coherent enough for the intended short technical note. Further experiments should be added only to resolve a concrete public-review objection or reproduction failure, not to scale for its own sake.
