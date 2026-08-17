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
11. In a separate joint-from-scratch experiment, all three circuit parameter sets and the router are trained together without capability pretraining or freezing. With all-circuit capability-preserving supervision, all three routes retain 100% full-domain accuracy in all five seeds and all three routes are used in every seed.
12. That joint-from-scratch model sees only seven discrete price-ratio anchors during training but reaches 98.15% mean oracle-route agreement on held-out dense continuous ratios and 97.36% on random price/mask contracts.
13. Centering log prices to remove common-scale information materially improves random-contract robustness: the centered representation reaches 97.36% mean oracle agreement versus 79.56% for the raw-log-price ablation under changing common price scale.
14. In the constrained topology-search follow-up, the experimenter supplies only a three-stage supernet with per-stage `skip`, `lookup`, and `compute` primitives (27 possible hard topologies), not complete route labels. On XOR, the resource-price-aware model selects four hard topologies in every one of five seeds while preserving 100% exhaustive task accuracy; the matched price-blind model selects one fixed topology in every seed.
15. In that topology-search follow-up, all five price-aware seeds use compute-only execution when the parameter-footprint proxy is expensive and lookup-only/lookup-heavy execution when the compute proxy is expensive; exact stage placement varies across seeds.

The direct internal-circuit experiment additionally verifies, across three seeds and all 4,096 finite task states per seed, that changing only the resource condition changes the actually executed internal subgraph while preserving the correct prediction. Forward-hook counts verify that the inactive subgraph is not executed. The alternative subgraphs were deliberately constructed; spontaneous circuit discovery is **not** claimed.

The three-circuit and joint-from-scratch experiments extend that construction to three distinct resource profiles and three executed traces. The topology-search follow-up relaxes the complete-route specification further, but still supplies primitive operation types and a fixed three-stage search space. It therefore supports **constrained subgraph discovery**, not unconstrained architecture discovery.

## Resource-proxy definition

The resource-proxy experiments use two normalized coordinates:

- **compute proxy:** approximate executed operation/MAC count;
- **parameter-footprint proxy:** parameter count associated with the selected expert/circuit.

The parameter-footprint coordinate is **not** measured runtime memory traffic, bandwidth, cache pressure, resident-memory reduction, or energy. All parameters remain resident in the same model/process during inference.

## Related-work boundary

Lookup-table neurons/networks, differentiable logic networks, dynamic routing, neural architecture search, once-for-all subnetworks, and runtime architecture switching are established prior work. This repository does **not** claim novelty for those ideas.

The lookup/retrieval paths are used as deliberately simple execution regimes with resource profiles different from the algorithmic circuits. The narrow mechanism under test is the **explicit resource-conditioned choice of internal execution under a normalized resource contract**, combined with an independent runtime availability mask.

See [`RELATED_WORK.md`](RELATED_WORK.md) for representative prior work including LUT/logic networks, dynamic routing, Adaptive Neural Trees, Once-for-All, Dynamic-OFA, and HADAS.

## Explicitly not claimed

1. Hard real-time guarantees or WCET bounds.
2. Joule-level energy savings.
3. Reduced total resident model memory when switching routes.
4. Universal superiority over adaptive routing, mixture-of-experts, early exit, neural architecture search, once-for-all subnetworks, or external schedulers.
5. Generalization to LLMs or large neural networks.
6. Automatic self-organization of useful circuit topology under arbitrary architectures or objectives.
7. Hardware-independent timing guarantees.
8. Necessity of a learned router when route costs are exactly known: an analytic `argmin(price · cost)` scheduler remains the oracle in the toy objectives.
9. Novelty of LUT neurons, LUT networks, differentiable logic networks, dynamic routing, neural architecture search, or runtime subnetwork switching.
10. Demonstrated improvement of the present routing mechanism on DWN, NeuraLUT, LL-ViT, OFA, Dynamic-OFA, HADAS, Adaptive Neural Trees, or other related systems.
11. Input-difficulty adaptation in the direct internal-circuit, three-circuit, joint-from-scratch, or topology-search experiments; their routers observe resource condition rather than task difficulty.
12. Real hardware portability from the simulated calibration-transfer experiment. That test assumes a separable multiplicative mapping from runtime/hardware state to the two-dimensional effective resource price.
13. That a learned continuous router materially dominates a strong discrete external scheduler in the three-circuit interpolation test; the measured dense-ratio advantage is only about 0.39 percentage points.
14. Unconstrained self-organization under a single undifferentiated joint objective. The successful joint-from-scratch condition explicitly applies task supervision to every potentially admissible circuit to preserve fallback capability.
15. Globally resource-optimal topology discovery. In the XOR topology-search follow-up, direct learned topologies match the cheapest 100%-accurate hard topology on only 70.75% of the dense sweep on average.
16. Robust topology discovery across tasks. In the 4-bit-parity stress test, only 1/3 seeds discovers multiple resource-conditioned topologies and 2/3 collapse to a single lookup topology.

## Important negative results retained

- Weak price penalties may be ignored.
- Strong fixed penalties may collapse to a cheap policy.
- Naive joint specialization can cause fallback-capability forgetting. In the joint-from-scratch ablation, the retrieval route falls to 71.95% mean forced accuracy and is never used in the dense sweep, while the capability-preserving variant keeps all three routes at 100%.
- Raw absolute log-price features can create unnecessary dependence on common price scale. The raw-log-price ablation remains strong on fixed-scale sweeps but falls to 79.56% mean oracle agreement on random contracts with varying common scale; relative centered log prices recover 97.36%.
- Complete gradient separation is not required in the joint toy: the decoupled diagnostic reaches 97.51% held-out dense agreement, slightly below the ordinary capability-preserving joint result at 98.15%.
- Constrained topology search does not automatically minimize the resource objective. The main XOR search maintains 100% task accuracy but reaches only 70.75% mean global-oracle agreement because redundant active operations can remain. Validation-only local pruning improves this to 88.9% but does not fix every seed.
- The same topology-search procedure is not robust on 4-bit parity: only 1/3 seeds uses multiple resource-conditioned topologies.
- Soft-mixture, deterministic straight-through, and primitive-DropPath topology-search variants did not improve the main result; they either damaged hard-discretized task accuracy or increased redundant topology selection.
- Simple linear compute+memory timing models did not capture end-to-end tail latency on Linux/PyTorch.
- Runtime-load distribution shift breaks calibration unless the timing model is recalibrated or conditioned on state.
- The same-core contention follow-up shows a stronger limitation: even state-specific empirical P99/order-statistic calibration did **not** reliably produce route-specific safe/unsafe separation on ordinary Linux, because scheduler/preemption tails affected short and long routes alike. Recalibration did not consistently improve held-out miss rate across independent invocations.
- Additional resource-vector dimensions can be redundant or harmful.
- Resource-conditioned routing did not automatically dominate a strong input-only adaptive-routing baseline on quality-compute Pareto efficiency.
