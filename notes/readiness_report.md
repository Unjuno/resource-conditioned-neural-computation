# Resource-Conditioned Neural Computation — Preprint Readiness Report

## Status

**STOP condition remains reached for a short arXiv-style mechanism note, subject to the public review window.**

The strongest defensible claim remains narrow:

> a neural system can use an explicit resource condition to change the actually executed internal computation, while an independent runtime mechanism constrains feasibility.

The newest experiments strengthen the **boundary**, not the headline: the mechanism survives four-stage homogeneous search spaces, but a simple global resource contract becomes unreliable when stage/route costs change non-uniformly.

## Evidence ladder

1. **Two-strategy constructive test:** resource-price intervention switches physically different lookup/copy and algorithmic paths. Analytic scheduling remains the oracle when costs are known.
2. **Direct internal-circuit execution:** one fixed network changes its actually executed module sequence; inactive modules are verified not to run.
3. **Three internal circuits:** held-out continuous resource ratios and matched price-blind controls support the resource-conditioned selection mechanism, with only a small advantage over a strong discrete scheduler.
4. **Joint capability acquisition:** explicit fallback supervision prevents capability forgetting; relative price coordinates remove irrelevant global scale.
5. **Constrained topology discovery:** a supplied primitive supernet produces multiple resource-conditioned hard subgraphs without complete-route labels on XOR.
6. **Freeze-free parity curriculum:** capability readiness + correlated constrained routing reaches **98.55% mean / 95.75% worst-seed** minimum-cost rate at 100% task accuracy over five seeds. A sampled-policy version reaches **95.05% / 91.25%** without complete-topology marginalization in router training.
7. **Search-space robustness:** four-stage homogeneous costs remain strong at **98.10% mean / 91.25% worst-seed**. Stage-dependent costs collapse to **33.00% mean / 0% worst seed**, despite perfect task capability. Increasing price anchors to 21 does not repair this.
8. **Non-separable contract diagnostic:** route-local calibration information improves a flat held-out-profile policy to **73.10% mean** versus **24.99% blind**, and swapping the calibration signal reduces performance to **25.63%**. This is still well below the analytic oracle; the tested autoregressive policy collapses.
9. **Runtime timing negative:** ordinary Linux same-core contention prevents stable route-specific empirical P99 separation and does not establish WCET.

## Current interpretation

The project now has two distinct interfaces:

### Model-side learning interface

- preserve capability;
- wait for capability readiness before strong resource pressure;
- represent correlated subgraph decisions;
- treat task validity/availability as a constraint rather than one more soft price term.

### Runtime-to-model resource interface

A low-dimensional normalized scarcity vector is plausible only when hardware/resource effects are approximately **separable across routes**. The earlier calibration-transfer experiment supports that narrow case.

The new stage-dependent-cost ablation shows that this does **not** extend automatically to route-local/non-separable hardware effects. In those cases, the runtime must either expose richer route-/operation-local calibration, perform more scheduling itself, or both. The current learned route-local diagnostic does not yet reach oracle performance.

This is an important correction to any broad claim that “move to new hardware, recalibrate runtime only” is generally sufficient.

## Defensible claims

### Supported

1. Resource condition can control actual internal neural execution in the tested finite systems.
2. The mechanism extends beyond a two-route toy to multiple circuits and constrained subgraphs.
3. Capability and resource allocation can be trained without freezing capability parameters under explicit capability-preserving/capability-gated training.
4. Correlated routing and feasibility/resource separation materially improve harder parity allocation.
5. The mechanism survives a four-stage homogeneous search-space change.
6. Route-local calibration input has a reproducible intervention effect on held-out hardware-profile routing.
7. Runtime availability can override neural price routing by construction.

### Not supported

1. Hard real-time/WCET guarantees.
2. Physical energy or memory-bandwidth savings.
3. Universal superiority to external scheduling/NAS.
4. General/unconstrained architecture discovery.
5. A single undifferentiated self-organizing objective.
6. A universal capability-readiness threshold.
7. Scalable NAS from the finite exact-search diagnostics.
8. LLM/large-model generalization.
9. Arbitrary hardware portability.
10. Stable route-specific P99 safety masks on ordinary Linux.
11. Reliable learned routing under non-separable stage-/route-local cost changes; the latest experiments expose this as an open failure mode.

## Recommended framing

A short mechanism note remains defensible under a title such as:

**Resource-Conditioned Neural Computation: Learned Price-Aware Execution Paths under Runtime Availability Constraints**

The note should explicitly include the new negative boundary:

> normalized resource contracts are promising as an interface, but simple global scarcity coordinates are not sufficient evidence for non-separable hardware portability.

Further experiments should resolve concrete review objections rather than scale for its own sake.
