# Resource-Conditioned Neural Computation — Preprint Readiness Report

## Status

**STOP condition reached for a short arXiv-style technical/mechanism note, subject to the public review window.**

The evidence supports a narrow claim: a fixed-parameter neural system can learn to use a continuous resource-price signal to switch between functionally equivalent but resource-distinct computation strategies, while an independent runtime mask constrains selectable execution classes using empirical statistical timing bounds.

The evidence does **not** support a hard-real-time/WCET guarantee, a physical energy claim, universal superiority over external scheduling, or novelty of LUT-based neural computation itself.

## Final reproduction architecture

Two equal-quality strategies solve the same 12-bit majority task:

1. **Lookup / copy path** — parameter-footprint-heavy, compute-light.
   - 8,192 parameters.
   - ~2-operation lookup proxy.
2. **Algorithmic MLP path** — lower parameter footprint, compute-heavy.
   - 4,706 parameters.
   - 4,544 linear MACs.

Both strategies achieve 100% full-state task accuracy in all three final seeds.

The resource table has two normalized columns: `compute_proxy` and `parameter_footprint_proxy`. The latter is parameter count only. It is not measured memory traffic, bandwidth, cache behavior, resident-memory reduction, or joules.

A small router observes resource prices and a runtime availability mask. Experts are frozen during routing post-training.

## Related-work / novelty boundary

LUT and logic-based neural computation are established research areas. Representative prior work includes Deep Differentiable Logic Gate Networks, Differentiable Weightless Neural Networks (DWN), NeuraLUT, LL-ViT with LUT neurons, and recent fully trainable deep LUT networks. See [`../RELATED_WORK.md`](../RELATED_WORK.md).

Accordingly, the lookup path in this repository is **not** presented as a novel neuron, network family, or hardware mapping technique. It is a deliberately simple execution regime used to isolate a different question:

> Can a model use an explicit continuous resource-price signal to choose among already-valid neural execution regimes with different resource profiles, while an independent runtime availability mask constrains which regimes may execute?

The present experiments also do **not** establish that this mechanism improves DWN, NeuraLUT, LL-ViT, or other LUT/logic architectures. Those systems are possible future substrates, not validated targets of the current result.

## Direct fixed-network internal-circuit check

A follow-up experiment places the alternative execution regimes inside one `ResourceConditionedCircuitNet` with one shared classifier head. The model contains a retrieval node and a separate algorithmic stem plus four residual compute blocks. The router is part of the same fixed parameterized model, and `forward_selected()` executes only the chosen internal subgraph.

Across three seeds, both internal circuits achieve 100% accuracy over all 4,096 task states. Holding each task input fixed and changing only the resource condition changes the selected module sequence while preserving the prediction over the complete finite domain. Forward-hook counts verify that the inactive subgraph is not executed, avoiding the earlier failure mode where all branches could be computed before selection.

The price-aware and price-blind routers remain matched at 114 parameters, and the learned router matches the analytic oracle at all 27 tested price-ratio points. This directly supports the narrow statement that resource condition can control an **effective internal circuit** inside one fixed parameterized network. It does not establish spontaneous discovery of useful circuits: the candidate subgraphs were deliberately constructed before router post-training, and the router does not observe task input or difficulty.

See [`internal_circuit_experiment.md`](internal_circuit_experiment.md) and `../results/internal_circuit_conditioning_results.json`.

## Matched price-blind control

The final price-aware and price-blind routers use the same architecture and the same parameter count: **114 parameters each**. Both are trained against the same log-uniform resource-price distribution and the same random safe-mask distribution. The price-blind control receives zeroed price features, so it cannot condition its decision on the realized price vector.

This replaces the earlier weaker control that also used a smaller input layer.

## Main mechanism result

Across three seeds:

- **Compute proxy expensive:** the price-aware router selects lookup/copy while preserving 100% accuracy.
- **Parameter-footprint proxy expensive:** the price-aware router selects the algorithmic MLP while preserving 100% accuracy.
- A sweep of compute-price / footprint-price from 0.04 to 25 changes router probabilities continuously and crosses a decision boundary while accuracy remains 100%.
- At all 27 tested sweep points (9 ratios × 3 seeds), the learned price-aware router selects the same route as the analytic oracle `argmin_j price · cost_j`; mean tested oracle regret is 0.

The oracle result is an important limitation as well as a sanity check: this toy experiment establishes that a neural router can learn the resource-conditioned selection rule, not that learning beats an external scheduler when the cost table is known exactly.

## Final shared empirical timing-mask experiment

The final three-seed experiment uses:

- one shared execution-class calibration for price-aware and price-blind policies;
- one-sided 99% finite-sample/order-statistic bounds for each class;
- identical safe masks for both policies;
- no forced fallback when the safe set is empty: such a request is marked **not admitted**.

When only the lower-latency class is declared safe, both policies select that class. Resource price cannot override the runtime mask.

When both classes are safe, the price-aware router can select the lower normalized resource-cost path for the current resource vector.

In the current rerun, under the **parameter-footprint-proxy-expensive** both-safe condition, aggregated across three seeds:

- **Price-aware:** accuracy 100%; normalized resource objective ~0.62446.
- **Price-blind same-capacity control:** accuracy 100%; normalized resource objective ~1.00002.

This is about a **37.6% reduction in the tested normalized proxy objective at identical task accuracy and identical safe-set availability**. It is not a 37.6% reduction in physical memory, bandwidth, energy, or latency. The price-aware policy deliberately chooses the slower MLP when the footprint proxy is expensive.

Absolute miss rates are not promoted as a stable headline result because ordinary Linux/PyTorch tail timing varies materially across reruns.

## Negative control

The price input is deliberately corrupted while the learned price-aware router is kept fixed.

Across three seeds:

- Under **compute-expensive** actual conditions, the true signal selects lookup in 3/3 seeds; swapping the signal selects the MLP in 3/3 seeds and raises normalized cost from ~0.05044 to ~1.02872.
- Under **footprint-proxy-expensive** actual conditions, the true signal selects the MLP in 3/3 seeds; swapping or replacing the signal by a constant selects lookup in 3/3 seeds and raises normalized cost from ~0.62446 to ~1.00002.

This is best described as an **input intervention** showing that the learned router actually uses the resource-price input. It is not a claim of a broader causal-inference identification result.

## Prior falsification results retained

1. Weak compute-price penalties can be ignored entirely.
2. Excessively strong fixed penalties can cause abrupt cheap-policy collapse rather than smooth adaptation.
3. Jointly specializing experts can cause capability forgetting; runtime fallback then becomes unsafe.
4. Linear `compute_time + memory_time` latency models did not reliably predict end-to-end route latency on Linux/PyTorch.
5. Naive online safety-factor adaptation was unstable under OS jitter.
6. Calibration under one runtime load did not transfer reliably to a different runtime load; state-conditioned recalibration restored statistical coverage in the toy experiment.
7. A resource vector is not automatically superior to a scalar; additional dimensions can be redundant/noisy.
8. Price-conditioned routing did not automatically dominate a strong input-only adaptive-routing baseline in quality–compute Pareto efficiency.

## Defensible claims

### Supported

1. Resource price can be learned as a continuous neural execution-control signal in this tested system.
2. A fixed parameter set can select different effective computation strategies according to resource prices; the direct internal-circuit test verifies that the actually executed module sequence changes while predictions remain fixed over the complete finite toy domain.
3. Functionally equivalent copy/lookup and algorithmic strategies can be switched while preserving task accuracy.
4. An independent runtime mask can override economic routing, separating empirical timing constraints from within-safe-set proxy optimization.
5. Price-input intervention reverses routing in the expected direction.

### Not supported

1. Hard real-time guarantees or WCET bounds.
2. General energy savings in joules.
3. Reduced total resident memory from route switching.
4. Universal superiority to external schedulers; the analytic oracle is exact for the current two-route toy cost table.
5. Large-model/LLM generalization.
6. Automatic circuit self-organization under arbitrary architectures or objectives.
7. Novelty of LUT neurons, LUT networks, differentiable logic networks, or LUT-based hardware mapping.
8. Demonstrated gains on existing LUT/logic architectures such as DWN, NeuraLUT, or LL-ViT.
9. Input-dependent difficulty adaptation in the direct internal-circuit experiment.

## Recommended preprint framing

A narrow mechanism note remains defensible under a title such as:

**Resource-Conditioned Neural Computation: Learned Price-Aware Execution Paths under Runtime Safety Masks**

Do not frame this as a new hard-real-time neural network architecture or as a new LUT-network architecture.

## Next action

Hold the mechanism claim fixed during the initial public review window. New experiments should be added only to resolve a concrete critique, reproduction failure, or confound. If no unresolved core objection remains after the review window, freeze a revision and use it as the reproducibility reference for a short technical note.
