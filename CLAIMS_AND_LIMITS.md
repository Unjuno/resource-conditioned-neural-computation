# Claims and limits

## Supported by the included experiments

1. Resource price can act as a continuous neural execution-control signal in the tested toy system.
2. A fixed parameter set can select different effective computation strategies as resource prices change.
3. Functionally equivalent lookup/copy and algorithmic/compute strategies can be switched while preserving task accuracy in the tested synthetic task.
4. An independent runtime availability mask can override resource-price routing, separating statistical timing constraints from within-safe-set resource optimization.
5. Deliberately corrupting the resource-price signal changes the selected path in the expected wrong direction and increases the actual normalized resource objective.
6. A same-architecture, same-parameter-count price-blind control does not reproduce the price-dependent route switch.

## Resource-proxy definition

The current final experiment uses two normalized resource coordinates:

- **compute proxy:** approximate operation/MAC count;
- **parameter-footprint proxy:** expert parameter count.

The parameter-footprint coordinate is **not** measured runtime memory traffic, bandwidth, cache pressure, resident-memory reduction, or energy. Both experts are resident in the same process during inference.

## Related-work boundary

Lookup-table neurons/networks and differentiable logic networks are established prior work. This repository does **not** claim novelty for LUT-based neural computation, LUT neurons, mapping sub-networks into LUTs, or LUT-oriented edge/FPGA inference.

The current lookup expert is used only as one deliberately simple execution regime with a different resource profile from the MLP expert. The narrow mechanism under test is the **resource-conditioned choice among already-valid execution regimes**, combined with an independent runtime availability mask.

See [`RELATED_WORK.md`](RELATED_WORK.md) for representative prior work including Differentiable Weightless Neural Networks, NeuraLUT, LL-ViT, deep differentiable logic-gate networks, and fully trainable deep LUT networks.

## Explicitly not claimed

1. Hard real-time guarantees or WCET bounds.
2. Joule-level energy savings.
3. Reduced total resident model memory when switching routes.
4. Universal superiority over adaptive routing, mixture-of-experts, early exit, or external schedulers.
5. Generalization to LLMs or large neural networks.
6. Automatic self-organization of useful circuits under arbitrary architectures or objectives.
7. Hardware-independent timing guarantees.
8. Necessity of a learned router when route costs are exactly known: in the final two-route toy objective, an analytic `argmin(price · cost)` scheduler is an oracle baseline and the learned router matches it on the tested sweep.
9. Novelty of LUT neurons, LUT networks, differentiable logic networks, or LUT-based neural hardware mapping.
10. Demonstrated improvement of the present routing mechanism on DWN, NeuraLUT, LL-ViT, or other LUT/logic-network architectures.

## Important negative results retained

- Weak price penalties may be ignored.
- Strong fixed penalties may collapse to a cheap policy.
- Joint expert specialization can cause fallback-capability forgetting.
- Simple linear compute+memory timing models did not capture end-to-end tail latency on Linux/PyTorch.
- Runtime-load distribution shift breaks calibration unless the timing model is recalibrated or conditioned on state.
- Additional resource-vector dimensions can be redundant or harmful.
- Resource-conditioned routing did not automatically dominate a strong input-only adaptive-routing baseline on quality-compute Pareto efficiency.
