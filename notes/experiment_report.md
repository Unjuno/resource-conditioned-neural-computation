# Resource-Conditioned Neural Computation — Experiment Status

## Scope
Container-only, CPU-only mechanism experiments. No large models, no GPU, no language benchmark scaling.

## 1. Core circuit-conditioning result
Across the experiment program, changing only an external compute/resource condition was sufficient to change the effective execution path of a fixed parameter set in multiple toy architectures.

## 2. Important exploratory failures
The broader search produced several constraints on the useful claim:

- weak resource penalties can be ignored;
- strong fixed penalties can collapse to the cheapest policy;
- unconstrained joint expert specialization can destroy fallback capability;
- simple microbenchmark-linear timing models do not capture end-to-end tail latency reliably on Linux/PyTorch;
- runtime-load distribution shift can invalidate timing calibration;
- adding resource-vector dimensions can hurt;
- resource-conditioned routing is not automatically Pareto-superior to a strong input-only adaptive router.

These failures motivated the final reduced mechanism experiment.

## 3. Final copy-vs-compute reproduction
The final public reproduction uses two equal-quality strategies for the same 12-bit majority task:

- **Lookup strategy:** 8,192 parameters, ~2-operation lookup proxy; parameter-footprint-heavy and compute-light.
- **Algorithmic MLP strategy:** 4,706 parameters, 4,544 linear MACs; lower parameter footprint and compute-heavy.

Both achieve 100% full-state accuracy for all three seeds.

The resource vector is explicitly a **proxy vector**:

1. normalized operation/MAC count;
2. normalized expert parameter count.

The second coordinate is not measured memory bandwidth, runtime memory traffic, cache cost, resident-memory reduction, or energy.

## 4. Matched control
The final price-aware and price-blind routers are architecturally identical and each has 114 parameters. Both are trained under the same price distribution and mask distribution. The control receives zeroed price features.

This closes an earlier audit issue where the control had a smaller input layer.

## 5. Continuous resource-price intervention
Holding task and safe mask fixed while sweeping compute-price / footprint-proxy-price changes router probabilities and route choice. Across 9 ratios × 3 seeds, the learned route matches the analytic external oracle `argmin(price · cost)` at every tested point, with zero tested regret.

This has two interpretations:

- positive: the neural router learns the intended continuous resource-conditioned selection rule;
- limiting: a learned router is not necessary in this toy setting when exact route costs are already available to an external scheduler.

## 6. Runtime mask
The runtime supplies a hard availability mask derived from held-out empirical timing calibration. The neural router may optimize only within the available set.

If no route is declared safe, the final public code returns `admitted: false`; it does not force an uncertified fallback route.

P95/P99/order-statistic measurements on ordinary Linux/PyTorch are not WCET and do not imply hard-real-time guarantees.

## 7. Final proxy-objective result
In the footprint-proxy-expensive both-safe condition, the final three-seed rerun preserves 100% accuracy for both policies while the price-aware policy uses normalized proxy objective ~0.62446 versus ~1.00002 for the matched price-blind control, a ~37.6% reduction in that **proxy objective**.

This should not be translated into a physical memory, energy, or latency percentage.

## 8. Price-signal negative control
Swapping the resource-price signal reverses the selected path in 3/3 seeds in both asymmetric environments and increases the objective evaluated under the actual environment price. This supports the narrow statement that routing is intervention-sensitive to the resource-price input.

## 9. Current architecture hypothesis

RTOS/runtime
  -> estimate current timing state
  -> construct a conservative safe execution-class mask
  -> optionally provide resource prices/proxies
  -> fixed-capability NN with post-trained mask-aware resource router
  -> choose a valid circuit inside the safe set

Safety and learned optimization remain separate responsibilities.

## 10. Current H/T/D/C/U
**H:** Given two or more functionally valid strategies with different resource profiles, a resource-conditioned router can learn to choose among them according to resource prices while preserving task quality; a runtime mask can independently restrict choice to empirically safe execution classes.

**T:** Tiny CPU-only experts, three seeds, continuous price-ratio intervention, same-capacity price-blind control, analytic oracle, shared held-out timing calibration, price-swap negative control.

**D:** PASS for resource-conditioned strategy selection. PASS for matching the analytic toy oracle over the tested sweep. PARTIAL for statistical runtime timing behavior. FAIL for hard-real-time guarantee.

**C:** The analytic scheduler is exact for the current known two-route proxy cost table, so this experiment does not establish a benefit of learning over external scheduling.

**U:** Linux scheduling jitter, Python/PyTorch dispatch overhead, empirical-tail sample error, synthetic-task bias, and the gap between resource proxies and real physical resource use.
