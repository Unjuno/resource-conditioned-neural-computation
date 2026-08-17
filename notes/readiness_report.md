# Resource-Conditioned Neural Computation — Preprint Readiness Report

## Status

**STOP condition remains reached for a short arXiv-style technical/mechanism note, subject to the public review window.**

The strongest defensible systems claim remains narrow:

> a neural system can use an explicit normalized resource condition to change the actually executed internal computation strategy, while an independent runtime availability mechanism constrains which execution classes may run.

The evidence now extends from hand-constructed route choice to **resource-conditioned subgraph discovery inside a supplied primitive-operation supernet** on an easy finite-domain task. It still does **not** establish general or unconstrained neural architecture discovery.

The package deliberately retains negative results. It does not support hard-real-time/WCET guarantees, physical energy claims, universal superiority over scheduling/NAS, arbitrary hardware portability, or LLM generalization.

## Evidence ladder

### 1. Two-strategy constructive result

Functionally equivalent retrieval/copy and algorithmic computation paths have different normalized compute and active-parameter-footprint proxies. Both preserve task accuracy. A matched price-aware router changes route with resource price, a price-blind control does not, and price-input intervention reverses routing in the expected direction.

For the known two-route cost table, an analytic `argmin(price · cost)` scheduler remains the exact oracle. The experiment establishes the mechanism, not superiority to exact external scheduling.

### 2. Direct internal-circuit execution

A fixed `ResourceConditionedCircuitNet` contains both retrieval and algorithmic subgraphs plus a shared head. Across three seeds and all 4,096 finite task states, changing only resource condition changes the actually executed module sequence while preserving the correct prediction. Forward hooks verify that inactive modules are not executed.

This supports **resource-conditioned effective internal circuits**, not merely variable iteration count.

### 3. Three resource-distinct circuits and contract generalization

A fixed network with retrieval, shallow-compute, and tied-deep-compute traces keeps all three routes at 100% accuracy across five seeds. Training the router on seven discrete price-ratio anchors generalizes to held-out continuous ratios at **98.64% mean oracle-route agreement**. Across 4,000 random price/mask contracts per seed, the price-aware router reaches **98.72%** mean oracle agreement versus **45.82%** for the matched price-blind router.

A nearest-anchor external scheduler reaches 98.25% on the dense ratio test, so the neural interpolation advantage is small.

### 4. Joint capability acquisition and allocation from scratch

With three deliberately constructed candidate circuit types, naive joint optimization forgets the retrieval fallback: mean forced accuracy falls to **71.95%**.

Adding task supervision to every potentially admissible circuit preserves all three capabilities at 100% in all five seeds. The resulting model reaches **98.15%** held-out dense agreement and **97.36%** random-contract agreement without capability pretraining or freezing.

A relative-price representation is important: raw log prices fall to **79.56%** under changing common price scale, while centered relative log prices recover 97.36%.

This does not establish spontaneous topology discovery because the three candidate circuit types are supplied.

### 5. Constrained topology discovery inside a supplied supernet

The next experiment removes the short list of complete named routes. A three-stage supernet supplies only `skip`, `lookup`, and `compute`, yielding 27 possible hard topologies. Complete routes are not used as training labels.

On XOR across five seeds:

- every price-aware seed selects four distinct hard topologies;
- every selected topology remains 100% correct over all 256 inputs;
- all five seeds use compute-only execution when the parameter-footprint proxy is expensive;
- all five use lookup-only / lookup-heavy execution when compute is expensive;
- exact stage placement varies across seeds;
- the price-blind control selects one fixed topology in all five seeds.

This supports **resource-conditioned subgraph discovery inside a supplied search space**.

#### Corrected cost-optimality metric

The original `global_oracle_agreement` used exact topology identity against one arbitrarily chosen minimum-cost topology. Stage-symmetric topologies can tie in cost, so exact identity is not the correct primary metric.

The re-audit gives:

- direct learned topology: **73.10% tie-aware minimum-cost rate**, mean regret ~**0.01651**;
- validation-only local pruning: **94.6% tie-aware minimum-cost rate**, mean regret ~**0.00274**.

The older 70.75% and 88.9% figures are retained only as exact-route-identity audit values.

The conclusion is unchanged: direct topology search is not globally resource-optimal, and pruning helps but does not solve every seed.

### 6. Harder parity stress test and router-factorization audit

The original end-to-end 4-bit-parity topology search is unstable: only **1/3 seeds** discovers multiple resource-conditioned topologies; **2/3** collapse to one lookup topology.

A controlled five-seed follow-up separates capability from allocation. The six single-primitive placements — one lookup or one compute at each stage — are first trained to **100% full-domain accuracy in every seed**, then capability is frozen while routers optimize the same 27-topology resource objective.

All router variants keep **100% hard task accuracy**. Resource allocation differs strongly:

| router | mean tie-aware optimal-cost rate | worst seed | mean regret |
|---|---:|---:|---:|
| independent-stage factorized + binary feasibility | 77.30% | 49.75% | 0.01264 |
| **autoregressive + binary feasibility** | **94.85%** | **93.50%** | **0.00235** |
| flat 27-way route policy + binary feasibility | 94.20% | 92.50% | **0.00146** |
| autoregressive best-of-4 restarts | 95.60% | 92.00% | 0.00155 |

This identifies a second failure mode beyond capability forgetting: **correlated topology decisions are difficult for an independent per-stage router even when all required primitive capabilities exist**.

The flat 27-way policy is only a small-search-space diagnostic. The autoregressive audit also computes an exact expectation over all 27 topologies during training. Neither is presented as a scalable NAS solution, and capability is frozen deliberately. The joint parity discovery problem therefore remains open.

### 7. Simulated normalized-contract transfer

A frozen three-circuit router consumes runtime-recalibrated resource prices under four separable multiplicative calibration profiles without receiving hardware identity. Mean oracle agreement remains approximately **97.85%–98.51%**.

This supports only a narrow normalized-contract interface under that simulation. It is not evidence of arbitrary real-hardware portability.

### 8. Runtime timing negative result

A same-core Linux contention experiment attempts route-wise empirical 99%-order-statistic calibration. The desired route-specific safe/unsafe separation is not stable across independent invocations: scheduler/preemption tails affect even short routes, and state-specific recalibration does not consistently improve held-out miss rate.

Therefore:

> route-wise state-conditioned P99 calibration on ordinary Linux is sufficient for a stable runtime safety mask

is **not supported**.

Stronger real-time claims require more predictable hardware/runtime isolation, scheduler integration, or formal/static timing analysis.

## Current interpretation

The experiments now point to three distinct layers that should not be conflated:

1. **capability** — every execution path the runtime may need must remain task-capable;
2. **allocation** — resource price chooses among capable paths, and correlated subgraph decisions may require a correlated router representation;
3. **feasibility / timing** — runtime availability is a separate constraint and cannot be inferred from ordinary Linux tail measurements as if they were WCET.

The central mechanism survives increasingly direct tests, but stronger self-organization claims become optimization/search questions rather than simple routing claims.

## Defensible claims

### Supported

1. Explicit resource price can function as a neural execution-control signal in the tested systems.
2. One fixed parameterized network can change its actually executed internal module sequence as resource conditions change while preserving task output in finite toy domains.
3. The effect extends from two to three resource-distinct circuits.
4. Capability acquisition and resource allocation can be learned jointly from scratch for deliberately supplied candidate circuits when fallback capability is explicitly preserved.
5. Relative scarcity coordinates improve robustness to irrelevant common price scaling in the tested objective.
6. A supplied primitive-operation supernet can learn multiple accurate resource-conditioned hard subgraphs without complete-route labels on XOR.
7. Tie-aware auditing confirms that the direct topology search remains imperfect and that local pruning materially reduces resource regret.
8. With capability fixed on parity, correlated autoregressive routing is substantially more stable than independent-stage routing in the tested search space.
9. Runtime availability can override neural resource-price routing by construction.

### Not supported

1. Hard real-time guarantees or WCET bounds.
2. Physical energy savings in joules.
3. Reduced total resident memory from route switching.
4. Universal superiority to external scheduling or NAS.
5. General/unconstrained architecture discovery.
6. Robust joint topology discovery on the harder parity task.
7. A scalable NAS method from the exact 27-topology router audits.
8. Large-model/LLM generalization.
9. Real-hardware portability from the simulated calibration-transfer result.
10. Stable route-specific P99 safety masks under ordinary Linux contention.

## Recommended preprint framing

A narrow mechanism note remains defensible under a title such as:

**Resource-Conditioned Neural Computation: Learned Price-Aware Execution Paths under Runtime Safety Masks**

The stronger architectural motivation can be stated explicitly: resource conditions can control the effective internal circuit of one fixed neural system, and resource-conditioned subgraphs can emerge inside a supplied primitive search space without complete-route labels on a simple task.

Do not frame this as a new NAS method, general spontaneous architecture discovery, a hard-real-time neural architecture, a new LUT-network architecture, a physical energy result, or a proof of general hardware portability.

## Next action

Hold the mechanism claim fixed during the remaining public review window. Further experiments should target concrete unresolved objections: especially robust joint topology discovery beyond XOR, a scalable alternative to exact topology marginalization, or stronger runtime timing guarantees on a suitable platform. If no unresolved core objection remains after the review window, freeze a revision and use it as the reproducibility reference for a short technical note.
