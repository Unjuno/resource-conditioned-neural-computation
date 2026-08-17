# Resource-Conditioned / Real-Time Neural Network — Experiment Status

## Scope
Container-only, CPU-only mechanism experiments. No large models, no GPU, no language benchmark scaling.

## 1. Core circuit-conditioning result
Previous experiments established that an external compute/resource condition can causally change the effective execution circuit of a fixed parameter set. Counterfactual tests held the input fixed and changed only the resource condition.

## 2. Learned expert self-organization
A small multi-expert network was trained on four synthetic task families. Experts were actual learned neural modules, not a hand-written accuracy table.

After joint resource-conditioned post-training, forced-expert accuracies diverged substantially by task family, showing functional specialization. With normalized log resource prices and beta around 1.5–2.0, route selection changed with resource composition:
- compute expensive -> greater use of the memory-heavy expert
- memory expensive -> greater use of the compute-heavy expert

This switching was clear in 2/3 seeds in both directions and partial in the third. However, unconstrained joint specialization caused capability forgetting and performed poorly when an RTOS mask later forced a non-preferred fallback expert.

## 3. Frozen-expert post-training
Freezing pretrained experts and training only the resource-conditioned router produced much more reproducible route switching while preserving fallback capability. This supports a post-training interpretation: learn resource allocation after capability acquisition.

## 4. Conditioned vs unconditioned control
With learned experts and beta=2.0, a price-conditioned router was compared against a same-capacity router that could not observe price.

Across 3 seeds, in asymmetric resource states the conditioned router reduced the training objective by paying a small accuracy cost to avoid expensive resources. In balanced/cheap states the control remained slightly better, showing that conditioning is not universally beneficial.

## 5. Copy-vs-compute experiment (physically differentiated strategies)
To align abstract resource costs with actual implementation properties, two equal-quality strategies were constructed and learned:

- **Lookup strategy:** 32,768 parameters, ~2 MAC-equivalent operations per inference, median ~4–5 us. Memory-heavy / compute-light.
- **Algorithmic MLP strategy:** 5,378 parameters, ~5,248 MACs, median ~17 us. Memory-light / compute-heavy.

Both reached 100% accuracy on the finite synthetic task domain.

A resource-conditioned router was then trained with the same task accuracy objective plus resource price.

### 3-seed aggregate (accuracy 100% in all conditions)
- **Compute expensive:** conditioned mean resource cost 0.02778 vs unconditioned 0.13350 -> **79.2% lower cost**.
- **Memory expensive:** conditioned 0.21888 vs unconditioned 0.28185 -> **22.3% lower cost** overall. Two seeds switched fully to the algorithmic strategy; one switched partially.
- Balanced/cheap regimes were not improved; the conditioned router sometimes paid unnecessary cost there.

### Continuous price-ratio sweep
For seed 0, holding geometric mean price approximately fixed and sweeping compute-price / memory-price from 0.04 to 25 produced a continuous route transition:
- low ratio -> algorithmic MLP 100%
- intermediate ratio -> mixed routing
- high ratio -> lookup 100%

Accuracy remained 100% at every sweep point. This rules out a purely discrete-label interpretation and supports resource price as a continuous control variable.

## 6. RTOS-style safe execution mask
A mask-aware router was trained so that runtime can declare execution classes unavailable. Safety mask and price were separated:
- mask = hard feasibility/safety information from runtime
- price = soft optimization signal within the safe set

Initial per-policy calibration was unfair because the two policies received different masks. A corrected experiment constructed **one shared execution-class calibration** and supplied the identical mask to price-aware and mask-only policies.

Shared P95 class bounds in one representative run were approximately:
- cheap: 58.1 us
- lookup: 56.8 us
- algorithmic: 78.1 us
- large universal: 134.2 us

### Representative shared-mask results, accuracy = 100%
Compute-expensive condition:
- D=154.3 us: price-aware miss 2.95%, mask-only 6.43%
- D=241.6 us: price-aware miss 0.93%, mask-only 2.18%

Memory-expensive condition:
- D=154.3 us: price-aware miss 4.35%, mask-only 4.45%
- D=241.6 us: price-aware miss 1.83%, mask-only 2.03%

At tighter deadlines the P95 class mask still allows significant tail misses, so this is soft/probabilistic real-time only.

## 7. Key negative results / falsifications
1. Simply adding a price input does not automatically create economic routing; weak penalties are ignored.
2. Naive soft penalties can collapse abruptly to the cheapest route.
3. Resource vectors with irrelevant dimensions can hurt; compute+memory outperformed compute+memory+risk in one transfer experiment.
4. Microbenchmark-linear timing models did not reliably predict route latency; direct execution-class calibration was better.
5. Joint expert specialization can destroy fallback capability under runtime masks.
6. Resource-conditioned routing is not automatically Pareto-superior to a strong input-only adaptive router.
7. P95/P99 measured bounds are not WCET and do not imply hard real-time guarantees.

## 8. Current architecture hypothesis
The most defensible architecture after the experiments is:

RTOS/runtime
  -> measure/estimate current state
  -> construct conservative safe execution-class mask
  -> provide resource price vector (at minimum compute + memory)
  -> fixed-capability NN with post-trained mask-aware resource router
  -> choose the highest-utility circuit inside the safe set

This separates safety from learned optimization.

## 9. Current H/T/D/C/U
**H:** Given two or more functionally valid computation strategies with different physical resource profiles, a resource-conditioned router can select among them according to runtime resource prices while preserving task quality; an RTOS mask can independently restrict the choice to statistically safe execution classes.

**T:** Tiny CPU-only experts, 3 seeds for the copy-vs-compute resource experiment, continuous price-ratio counterfactual sweep, shared execution-class calibration, held-out inference timing.

**D:** PASS for continuous resource-conditioned strategy selection and large resource-cost reduction at equal accuracy in asymmetric price regimes. PARTIAL for RTOS deadline reliability. FAIL for hard-real-time guarantee.

**C:** A non-conditioned scheduler may match or beat the learned router if it has perfect knowledge of strategy quality and resource costs; runtime calibration error can dominate model-side gains.

**U:** Linux scheduling jitter, Python/PyTorch dispatch overhead, P95/P99 sample error, synthetic-task bias, cost normalization, and incomplete seed robustness for memory-expensive switching.

## 10. Final falsification closure
The shared P99/conformal execution-class-mask experiment was subsequently completed across three seeds. With identical safe-set availability and 100% task accuracy, price-aware routing reduced the tested normalized resource objective in the memory-expensive both-safe condition. A signal-swap negative control reversed route selection and worsened the actual resource objective. See `readiness_report.md` and the final JSON results for the closed mechanism claim.
