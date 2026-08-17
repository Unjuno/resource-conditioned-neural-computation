# Claims and limits

## Supported by the included experiments

1. Resource price can act as a continuous neural execution-control signal in the tested toy systems.
2. A fixed parameter set can select different effective computation strategies as resource prices change. In the direct internal-circuit experiment, the selected module sequence itself changes while the task prediction is preserved.
3. Functionally equivalent retrieval/copy and algorithmic/compute strategies can be switched while preserving task accuracy in the tested synthetic tasks.
4. An independent runtime availability mask can override resource-price routing, separating statistical timing constraints from within-safe-set resource optimization.
5. Deliberately corrupting the resource-price signal changes the selected path in the expected wrong direction and increases the actual normalized resource objective.
6. Same-architecture, same-parameter-count price-blind controls do not reproduce the price-dependent route switch.
7. In the three-circuit follow-up, one fixed network selects among retrieval, shallow-compute, and tied-deep-compute internal traces; all three circuits achieve 100% accuracy across all 256 finite inputs in all five seeds, and forward hooks verify exclusive execution.
8. Training the three-circuit router on seven discrete price-ratio anchors generalizes to held-out continuous price ratios with 98.64% mean oracle-route agreement across five seeds. The gain over a nearest-anchor discrete external scheduler is small: 98.64% vs 98.25%.
9. Across 4,000 random price/mask contracts per seed, the three-circuit price-aware router reaches 98.72% mean oracle agreement versus 45.82% for the matched price-blind router.
10. Under a simulated separable multiplicative runtime-calibration model, the same frozen three-circuit router retains about 97.85%–98.51% mean oracle agreement across four calibration profiles without receiving a hardware identity.

The direct internal-circuit experiment additionally verifies, across three seeds and all 4,096 finite task states per seed, that changing only the resource condition changes the actually executed internal subgraph while preserving the correct prediction. Forward-hook counts verify that the inactive subgraph is not executed. The alternative subgraphs were deliberately constructed; spontaneous circuit discovery is **not** claimed.

The three-circuit experiment extends that construction to three distinct resource profiles and three executed traces. It still does **not** establish spontaneous discovery of useful circuit topology.

## Resource-proxy definition

The resource-proxy experiments use two normalized coordinates:

- **compute proxy:** approximate executed operation/MAC count;
- **parameter-footprint proxy:** parameter count associated with the selected expert/circuit.

The parameter-footprint coordinate is **not** measured runtime memory traffic, bandwidth, cache pressure, resident-memory reduction, or energy. All parameters remain resident in the same model/process during inference.

## Related-work boundary

Lookup-table neurons/networks and differentiable logic networks are established prior work. This repository does **not** claim novelty for LUT-based neural computation, LUT neurons, mapping sub-networks into LUTs, or LUT-oriented edge/FPGA inference.

The lookup/retrieval paths are used as deliberately simple execution regimes with resource profiles different from the algorithmic circuits. The narrow mechanism under test is the **resource-conditioned choice among already-valid execution regimes**, combined with an independent runtime availability mask.

See [`RELATED_WORK.md`](RELATED_WORK.md) for representative prior work including Differentiable Weightless Neural Networks, NeuraLUT, LL-ViT, deep differentiable logic-gate networks, and fully trainable deep LUT networks.

## Explicitly not claimed

1. Hard real-time guarantees or WCET bounds.
2. Joule-level energy savings.
3. Reduced total resident model memory when switching routes.
4. Universal superiority over adaptive routing, mixture-of-experts, early exit, or external schedulers.
5. Generalization to LLMs or large neural networks.
6. Automatic self-organization of useful circuits under arbitrary architectures or objectives.
7. Hardware-independent timing guarantees.
8. Necessity of a learned router when route costs are exactly known: an analytic `argmin(price · cost)` scheduler remains the oracle in the toy objectives.
9. Novelty of LUT neurons, LUT networks, differentiable logic networks, or LUT-based neural hardware mapping.
10. Demonstrated improvement of the present routing mechanism on DWN, NeuraLUT, LL-ViT, or other LUT/logic-network architectures.
11. Input-difficulty adaptation in the direct internal-circuit or three-circuit experiments; their routers observe resource price and availability mask, not task content.
12. Real hardware portability from the simulated calibration-transfer experiment. That test assumes a separable multiplicative mapping from runtime/hardware state to the two-dimensional effective resource price.
13. That a learned continuous router materially dominates a strong discrete external scheduler in the three-circuit interpolation test; the measured dense-ratio advantage is only about 0.39 percentage points.

## Important negative results retained

- Weak price penalties may be ignored.
- Strong fixed penalties may collapse to a cheap policy.
- Joint expert specialization can cause fallback-capability forgetting.
- Simple linear compute+memory timing models did not capture end-to-end tail latency on Linux/PyTorch.
- Runtime-load distribution shift breaks calibration unless the timing model is recalibrated or conditioned on state.
- The new same-core contention follow-up shows a stronger limitation: even state-specific empirical P99/order-statistic calibration did **not** reliably produce route-specific safe/unsafe separation on ordinary Linux, because scheduler/preemption tails affected short and long routes alike. Recalibration did not consistently improve held-out miss rate across independent invocations.
- Additional resource-vector dimensions can be redundant or harmful.
- Resource-conditioned routing did not automatically dominate a strong input-only adaptive-routing baseline on quality-compute Pareto efficiency.
