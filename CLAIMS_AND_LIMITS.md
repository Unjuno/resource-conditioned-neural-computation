# Claims and limits

## Supported by the included experiments

1. **Resource price can act as a neural execution-control signal** in the tested finite toy systems.
2. A fixed parameter set can change the **actually executed internal module sequence** as resource conditions change while preserving task output.
3. An independent runtime availability mask can override neural price routing, separating feasibility from within-safe-set resource optimization.
4. Price-input interventions and matched price-blind controls show that the resource signal, rather than a fixed route preference, drives the reported route switches.
5. Three supplied resource-distinct circuits remain 100% capable across five seeds; their router reaches 98.64% held-out dense oracle-route agreement and 98.72% random-contract agreement, while a matched price-blind router reaches 45.82% on the random contracts.
6. For supplied candidate circuits, capability and allocation can be trained from scratch without capability freezing when fallback capability is explicitly preserved.
7. Centered relative log-price features materially reduce spurious dependence on irrelevant common price scaling.
8. A supplied `skip / lookup / compute` supernet can learn multiple accurate resource-conditioned hard subgraphs without complete-route labels on the tested XOR toy.
9. On the harder parity toy, immediate joint optimization is unstable even with capability insurance. Capability readiness plus correlated constrained routing reaches **98.55% mean / 95.75% worst-seed** tie-aware minimum-cost rate at 100% hard accuracy across five seeds.
10. Removing exact topology marginalization from parity router training still yields **95.05% mean / 91.25% worst-seed** minimum-cost rate at 100% final task accuracy.
11. Search-space depth alone is not the dominant failure mode in the newest robustness test: four-stage homogeneous routing reaches **98.10% mean / 91.25% worst-seed** minimum-cost rate with all single-primitive capabilities at 100%.
12. **Stage-dependent resource costs are a strong failure mode:** four-stage cost-heterogeneous routing falls to **33.00% mean / 0% worst-seed** minimum-cost rate despite 100% task accuracy and perfect single-primitive capability. Heterogeneous availability plus costs reaches only 41.65% mean / 22% worst seed.
13. Increasing the cost-heterogeneous condition from 7 to 21 price-ratio anchors does not repair the failure; mean minimum-cost rate is **21.20%**.
14. In a frozen-capability route-local calibration diagnostic with 256 training hardware profiles, a calibration-aware flat policy reaches **73.10% mean / 70.05% worst-seed** held-out minimum-cost rate versus **24.99%** for a matched calibration-blind control. Swapping calibration inputs reduces it to **25.63%**.

## Current interpretation

The experiments separate at least five roles:

1. **capability preservation** — fallback primitives/routes that may be required later must remain task-capable;
2. **capability readiness** — strong resource pressure introduced too early can lock the system into a shortcut;
3. **correlated allocation** — coordinated subgraph decisions may require correlated routing rather than independent stage choices;
4. **feasibility vs optimization** — validity/availability should constrain resource optimization rather than be traded as one soft scalar reward;
5. **contract expressiveness** — one small global resource vector is adequate only for the tested separable/simple cost structures; route-local/non-separable hardware cost changes require a richer runtime representation or external scheduling.

## Resource-proxy definition

The experiments use normalized **compute** and **parameter-footprint** proxies. Parameter footprint is not measured runtime memory traffic, bandwidth, cache pressure, reduced resident memory, or energy.

## Explicitly not claimed

1. Hard real-time guarantees or WCET bounds.
2. Joule-level energy savings or measured memory-bandwidth savings.
3. Reduced total resident model memory from route switching.
4. Universal superiority over adaptive routing, MoE, early exit, NAS, once-for-all subnetworks, or external schedulers.
5. Necessity of a learned router when route costs are known exactly; analytic `argmin(price · cost)` remains an oracle in the toy objectives.
6. General/unconstrained automatic discovery of useful neural architecture.
7. A single undifferentiated objective that robustly self-organizes capability, topology, feasibility, and resource allocation.
8. A universal capability-readiness threshold.
9. A scalable NAS method from the finite exact-search diagnostics.
10. Input-difficulty adaptation in the reported resource routers.
11. Generalization to LLMs or large neural networks.
12. Novelty of LUT neurons/networks, differentiable logic networks, dynamic routing, NAS, or runtime subnetwork switching.
13. **Arbitrary hardware portability.** The earlier positive calibration-transfer result is limited to a separable multiplicative simulation. The new stage-dependent-cost experiments show that non-separable route costs are not reliably handled by the same simple global contract.
14. That a richer route-local calibration contract solves portability: the flat diagnostic reaches only 73.10% mean held-out optimality, and the tested autoregressive policy collapses to one route.
15. Stable route-specific P99 safety masks under ordinary Linux contention.

## Important negative results retained

- Weak resource penalties can be ignored; overly strong fixed penalties can collapse to a cheap policy.
- Naive joint specialization can cause fallback-capability forgetting.
- Raw absolute log-price features can learn spurious common-scale dependence.
- Direct constrained topology search can keep 100% task accuracy while retaining redundant operations and missing the global resource optimum.
- Capability preservation alone does not solve parity allocation; correlation alone does not solve it either when resource pressure starts too early.
- Search-space changes are not monotonic: three-stage homogeneous routing has a 53% worst seed while four-stage homogeneous routing is much more stable.
- Heterogeneous operation availability is moderately unstable, but stage-dependent **cost** heterogeneity is the stronger failure in the current ablation.
- Denser price anchors do not fix the stage-dependent-cost failure.
- Route-local calibration information has a clear intervention effect, but learned held-out profile routing remains below the analytic oracle and is optimization-sensitive.
- Ordinary Linux/PyTorch timing remains too jittery for WCET-style claims.
- Additional resource-vector dimensions can be redundant or harmful.
- Resource-conditioned routing does not automatically Pareto-dominate strong input-only adaptive-routing baselines.
