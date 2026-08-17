# Claims and limits

## Supported by the included experiments

1. **Resource price can act as a neural execution-control signal** in the tested finite toy systems.
2. A fixed parameter set can change the **actually executed internal module sequence** as resource conditions change while preserving task output.
3. Functionally equivalent retrieval/copy and algorithmic/compute strategies can be switched while preserving accuracy in the tested tasks.
4. An independent runtime availability mask can override resource-price routing, separating feasibility from within-safe-set resource optimization.
5. Price-input intervention changes the selected path in the expected wrong direction and worsens the defined normalized resource objective.
6. Same-architecture, same-parameter-count price-blind controls do not reproduce the price-dependent route switch.
7. In the three-circuit experiment, one fixed network selects retrieval, shallow-compute, and tied-deep-compute traces; all three remain 100% accurate over all 256 inputs in all five seeds and forward hooks verify exclusive execution.
8. Training that router on seven discrete price-ratio anchors generalizes to held-out continuous ratios with **98.64% mean oracle-route agreement**; a nearest-anchor external scheduler reaches **98.25%**, so the learned interpolation advantage is small.
9. Across 4,000 random price/mask contracts per seed, that price-aware router reaches **98.72%** mean oracle agreement versus **45.82%** for the matched price-blind router.
10. Under a simulated separable multiplicative runtime-calibration model, the same frozen router retains about **97.85%–98.51%** mean oracle agreement across four calibration profiles without receiving hardware identity.
11. For deliberately supplied three-route circuits, joint-from-scratch capability acquisition and allocation can work without capability pretraining/freeze when task supervision preserves every potentially admissible fallback: all three routes stay 100% accurate in all five seeds, with **98.15%** held-out dense and **97.36%** random-contract agreement.
12. Centering log prices to remove common-scale information materially improves robustness in that objective: **97.36%** random-contract agreement versus **79.56%** for raw log prices.
13. In the constrained topology-search follow-up, a supplied three-stage `skip / lookup / compute` supernet has 27 possible hard topologies but no complete-route labels. On XOR, the price-aware model selects four hard topologies in every one of five seeds at 100% exhaustive task accuracy; the matched price-blind model selects one fixed topology in every seed.
14. Re-auditing XOR with a tie-aware cost metric gives **73.10%** mean minimum-cost rate for the directly learned topology and **94.6%** after validation-only local pruning; corresponding mean regrets are ~0.01651 and ~0.00274.
15. In a frozen-capability parity diagnostic, all six single-primitive placements reach 100% accuracy in all five seeds. Under the same resource objective, an independent-stage router reaches **77.30%** mean tie-aware optimal-cost rate (minimum 49.75%) while an autoregressive router reaches **94.85%** (minimum 93.50%).
16. A new **freeze-free parity curriculum** trains capability and routing from scratch without ever freezing capability parameters. If resource allocation starts immediately, the independent router averages **21.90%** and the autoregressive router **37.15%** tie-aware optimal-cost rate despite capability insurance.
17. Delaying resource optimization until fallback primitives are mature improves the same task substantially: gated factorized reaches **81.95%**, gated autoregressive **97.25%**, and the capability-gated constrained autoregressive condition reaches **98.55% mean / 95.75% worst-seed** tie-aware minimum-cost rate at **100% hard task accuracy in all five seeds**.
18. The matched price-blind version of that same autoregressive curriculum preserves 100% task accuracy but selects one fixed route in all five seeds and reaches only **50.25%** cost-optimality.
19. A three-seed readiness sweep shows a sharp stability change in this toy between 90% and 95% single-primitive readiness: worst-seed cost-optimality rises from **49.75%** to **95.75%**. This is evidence for training-order/curriculum sensitivity, not a universal 95% threshold.
20. Removing exact complete-topology marginalization from router training and replacing it with an autoregressive sampled policy using fresh 64-state feasibility samples still gives **100% hard accuracy**, **95.05% mean / 91.25% worst-seed** tie-aware minimum-cost rate, and multiple routes in **5/5 seeds**.

## Current interpretation

The experiments now separate four distinct roles:

1. **capability preservation** — fallback primitives/routes that may be required later must remain task-capable;
2. **capability readiness** — strong resource pressure introduced too early can lock the system into a shortcut before alternatives mature;
3. **correlated allocation** — coordinated subgraph decisions can require a correlated router representation rather than independent stage choices;
4. **feasibility vs optimization** — task validity should constrain resource optimization rather than be traded against price as an undifferentiated soft reward.

The newest parity result is therefore best described as **capability-gated, constrained joint/alternating optimization with no capability freeze**, not unconstrained spontaneous self-organization.

## Resource-proxy definition

The resource-proxy experiments use two normalized coordinates:

- **compute proxy:** approximate executed operation/MAC count;
- **parameter-footprint proxy:** parameter count associated with the selected expert/circuit.

The parameter-footprint coordinate is **not** measured runtime memory traffic, bandwidth, cache pressure, resident-memory reduction, or energy. All parameters remain resident in the same model/process during inference.

## Related-work boundary

Lookup-table neurons/networks, differentiable logic networks, dynamic routing, neural architecture search, once-for-all subnetworks, and runtime architecture switching are established prior work. This repository does **not** claim novelty for those ideas.

The narrow mechanism under test is the **explicit resource-conditioned choice of internal execution under a normalized resource contract**, combined with an independent runtime availability constraint. See [`RELATED_WORK.md`](RELATED_WORK.md).

## Explicitly not claimed

1. Hard real-time guarantees or WCET bounds.
2. Joule-level energy savings.
3. Reduced total resident model memory from route switching.
4. Universal superiority over adaptive routing, mixture-of-experts, early exit, NAS, once-for-all subnetworks, or external schedulers.
5. Generalization to LLMs or large neural networks.
6. Unconstrained/general automatic discovery of useful circuit topology under arbitrary architectures or objectives.
7. Hardware-independent timing guarantees.
8. Necessity of a learned router when route costs are exactly known; analytic `argmin(price · cost)` remains an oracle in the toy objectives.
9. Novelty of LUT neurons, LUT networks, differentiable logic networks, dynamic routing, NAS, or runtime subnetwork switching.
10. Demonstrated improvement on DWN, NeuraLUT, LL-ViT, OFA, Dynamic-OFA, HADAS, Adaptive Neural Trees, or other related systems.
11. Input-difficulty adaptation in the reported routing experiments; their routers observe resource condition rather than task difficulty.
12. Real-hardware portability from the simulated calibration-transfer experiment.
13. A large advantage over a strong discrete scheduler in the three-circuit interpolation test; the measured dense-ratio advantage is only about 0.39 percentage points.
14. Globally resource-optimal unconstrained topology discovery. The direct XOR search remains imperfect before post-hoc pruning.
15. A single undifferentiated end-to-end objective that robustly self-organizes capability, topology, feasibility, and resource allocation. Immediate joint parity optimization remains unstable.
16. A universal capability-readiness threshold. The observed 95% transition is specific to this toy/setup.
17. A scalable NAS method from the exact 27-topology experiments. The sampled-policy follow-up removes complete-topology marginalization but still uses a tiny supplied search space and known proxy costs.
18. Stable route-specific P99 safety masks under ordinary Linux contention.

## Important negative results retained

- Weak resource penalties can be ignored; overly strong fixed penalties can collapse to a cheap policy.
- Naive joint specialization can cause fallback-capability forgetting.
- Raw absolute log-price features can learn spurious common-scale dependence.
- Constrained topology search can keep 100% task accuracy while retaining redundant active operations and missing the global resource optimum.
- The original end-to-end parity topology search collapses to one lookup topology in 2/3 seeds.
- Capability preservation alone does not solve parity allocation: the frozen-capability independent-stage router falls as low as 49.75% cost-optimality.
- **Correlation alone also does not solve it:** immediate autoregressive joint training averages only 37.15% and has a 0% worst seed.
- Capability gating alone is insufficient in difficult seeds: gated factorized routing has a 51.75% worst seed, while gated autoregressive routing is substantially more stable.
- The sampled-policy result is weaker than exact marginalization (95.05% vs 98.55%), so removing exhaustive router expectation has a measurable cost.
- Soft-mixture, deterministic straight-through, primitive-DropPath, and simple router-only consolidation diagnostics did not provide a generally better topology-search solution.
- Ordinary Linux/PyTorch timing remains too jittery for WCET-style claims; same-core contention can destroy stable route-specific P99 separation.
- Additional resource-vector dimensions can be redundant or harmful.
- Resource-conditioned routing does not automatically Pareto-dominate strong input-only adaptive-routing baselines.
