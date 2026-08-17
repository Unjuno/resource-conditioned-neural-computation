# Resource-Conditioned Real-Time Neural Computation — Preprint Readiness Report

## Status

**STOP condition reached for a short arXiv-style technical/mechanism note.**

The evidence supports a narrow claim: a fixed-parameter neural system can learn to use a continuous resource-price signal to switch between functionally equivalent but physically different computation strategies, while an independent runtime mask can constrain the selectable execution classes for statistical deadline safety.

The evidence does **not** support a hard-real-time/WCET guarantee or a claim of universal Pareto superiority over all adaptive-routing baselines.

## Core architecture tested

Two equal-quality strategies solve the same discrete task:

1. **Lookup / copy path** — memory-heavy, compute-light.
   - 32,768 parameters in the earlier full experiment.
   - ~2 MAC-equivalent operations per inference.
   - Measured median latency ~4–5 us in the earlier implementation.
2. **Algorithmic MLP path** — memory-light, compute-heavy.
   - 5,378 parameters in the earlier full experiment.
   - ~5,248 MACs.
   - Measured median latency ~17 us.

A small router observes resource prices and an RTOS/runtime availability mask. Experts are frozen during routing post-training in the safest variant.

## Main mechanism result

Across three seeds, with both strategies trained to 100% task accuracy:

- **Compute expensive:** 3/3 seeds routed to lookup/copy while preserving 100% accuracy.
- **Memory expensive:** 2/3 seeds routed fully to algorithmic compute and one seed routed mostly to algorithmic compute.
- Resource cost was reduced at equal task accuracy relative to a price-blind same-capacity control.
- A continuous sweep of compute-price / memory-price caused a continuous transition from algorithmic routing to lookup routing while accuracy remained 100%.

This establishes resource price as a usable continuous control variable for effective neural execution path selection in the tested system.

## Final shared conformal/P99-style RTOS-mask experiment

A fresh standalone three-seed experiment used:

- exact lookup expert,
- trained deep MLP expert with 100% full-state accuracy in all three seeds,
- price-aware router,
- price-blind control router,
- **one shared execution-class calibration** used by both policies,
- one-sided 99% nonparametric/conformal upper bounds for each execution class,
- identical safe masks for price-aware and control policies.

### Safety behavior

When only the lower-latency class was declared safe, both policies selected the same class. Thus resource price did **not** override the RTOS safety mask.

When both execution classes were safe, the price-aware router selected the lower resource-cost strategy according to the current price vector.

### Memory-expensive condition, both classes safe

Three-seed aggregate, 3,600 held-out inferences per policy:

- **Price-aware:** accuracy 100%; mean normalized resource cost ~0.62446; miss rate 0.25% (9/3600; approximate Wilson 95% CI ~0.13–0.47%).
- **Price-blind control:** accuracy 100%; mean normalized resource cost ~1.00002; miss rate 0.111% (4/3600; approximate Wilson 95% CI ~0.043–0.286%).

Thus the price-aware policy reduced the tested normalized resource objective by about **37.6% at identical accuracy and identical safe-set availability**, while the statistical deadline miss rate remained below 1% in both policies. It did not improve latency: it deliberately chose the slower but memory-cheaper algorithmic path under a memory-expensive resource state.

This distinction is central: the RTOS mask handles safety; resource price optimizes within the safe set.

## Negative control

The price signal was deliberately corrupted while keeping the learned router fixed.

Across three seeds:

- Under **compute-expensive** actual conditions, the correct price signal selected lookup in 3/3 seeds. Swapping the signal selected the algorithmic path in 3/3 seeds and raised normalized cost from ~0.05044 to ~1.02872.
- Under **memory-expensive** actual conditions, the correct signal selected the algorithmic path in 3/3 seeds. Swapping or replacing the price by a constant selected lookup in 3/3 seeds and raised normalized cost from ~0.62446 to ~1.00002.

Therefore the observed routing is not explained by a fixed router preference; the learned policy is causally sensitive to the resource-price input.

## Prior falsification results retained

The broader experiment program produced several negative results that constrain the claim:

1. Weak compute-price penalties can be ignored entirely.
2. Excessively strong fixed penalties can cause abrupt cheap-policy collapse rather than smooth adaptation.
3. Jointly specializing experts can cause capability forgetting; runtime fallback then becomes unsafe. Freezing acquired capabilities and post-training the router was more robust.
4. Linear `compute_time + memory_time` latency models did not reliably predict end-to-end route latency on Linux/PyTorch.
5. Naive online safety-factor adaptation was unstable under OS jitter.
6. Calibration under one runtime load did not transfer reliably to a different runtime load; state-conditioned recalibration restored statistical coverage.
7. A resource vector is not automatically superior to a scalar. Additional dimensions can be redundant/noisy.
8. Price-conditioned routing did not automatically dominate a strong input-only adaptive-routing baseline in quality–compute Pareto efficiency.

These failures are part of the evidence package and should remain in any preprint.

## Defensible claims

### Supported

1. Resource price can be learned as a **continuous neural execution-control signal**.
2. A fixed parameter set can select different effective computation strategies according to resource prices.
3. Functionally equivalent copy/memory and compute/algorithmic strategies can be switched while preserving task accuracy.
4. An independent runtime safe mask can override economic routing, cleanly separating statistical timing safety from within-safe-set resource optimization.
5. The learned policy fails a signal-swap negative control in the expected direction, supporting causal use of resource condition rather than fixed routing.

### Not supported

1. Hard real-time guarantees or WCET bounds.
2. General energy savings in Joules; current resource costs are normalized proxies.
3. Universal superiority to all conditional-computation or external-scheduler approaches.
4. Large-model/LLM generalization.
5. Claims that resource-conditioned functional circuits always self-organize without architectural or training constraints.

## Recommended preprint framing

A narrow mechanism note is defensible under a title such as:

**Resource-Conditioned Neural Computation: Learned Price-Aware Execution Paths under Runtime Safety Masks**

The paper should emphasize:

- resource-conditioned execution rather than LLMs,
- copy-vs-compute as the clean constructive example,
- continuous price-ratio intervention,
- shared statistical execution-class mask,
- negative controls and failure modes,
- separation of responsibilities: runtime safety vs neural resource optimization.

Do not frame this as a new hard-real-time neural network architecture yet.

## Next action

Hold the mechanism claim fixed during the initial public review window. New experiments should be added only to resolve a concrete critique, reproduction failure, or confound. If no unresolved core objection remains after the review window, freeze a revision and use it as the reproducibility reference for a short technical note.
