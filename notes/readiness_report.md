# Resource-Conditioned Neural Computation — Preprint Readiness Report

## Status

**STOP condition remains reached for a short arXiv-style technical/mechanism note, subject to the public review window.**

The evidence supports a narrow claim: a fixed-parameter neural system can use an explicit resource-price signal to change the actually executed internal computation strategy while an independent runtime availability mask constrains which execution classes may run.

The newest experiment strengthens this only to **resource-conditioned subgraph discovery inside a supplied supernet search space**. It does not establish unconstrained/general neural architecture discovery.

The evidence does **not** support a hard-real-time/WCET guarantee, a physical energy claim, universal superiority over external scheduling or NAS, arbitrary hardware portability, general spontaneous architecture discovery, or novelty of LUT-based neural computation, dynamic routing, or runtime subnetwork switching.

## Core constructive result

The original two-strategy experiment uses functionally equivalent retrieval/copy and algorithmic computation paths with different normalized compute and active-parameter-footprint proxies. Both retain 100% task accuracy. The final price-aware and price-blind routers are matched in architecture and parameter count, and price-input interventions reverse routing in the expected direction.

The analytic `argmin_j price · cost_j` scheduler remains an exact oracle for the toy cost table. The result establishes that a neural router can learn the resource-conditioned selection rule; it does not establish that learning beats exact external scheduling when costs are known.

## Direct fixed-network internal-circuit check

A follow-up places the alternatives inside one `ResourceConditionedCircuitNet` with one shared classifier head. The model contains a retrieval node and a separate algorithmic stem plus four residual compute blocks. `forward_selected()` executes only the chosen internal subgraph.

Across three seeds, both internal circuits achieve 100% accuracy over all 4,096 task states. Holding task input fixed and changing only the resource condition changes the selected module sequence while preserving the prediction over the complete finite domain. Forward-hook counts verify that the inactive subgraph is not executed.

This directly supports **resource-conditioned effective internal circuits**, not merely variable iteration count. Candidate subgraphs are deliberately constructed; spontaneous circuit discovery and input-difficulty adaptation are not shown in this experiment.

See [`internal_circuit_experiment.md`](internal_circuit_experiment.md).

## Three-circuit extension

A stronger follow-up uses one `MultiCircuitNet` with three internal execution regimes sharing a classifier head:

1. retrieval — high active parameter-footprint proxy, very low compute proxy;
2. shallow compute — intermediate footprint and compute;
3. tied-deep compute — low active parameter-footprint proxy, high repeated compute.

The finite-domain task has 256 possible inputs. Across five seeds, **all three circuits achieve 100% accuracy on all inputs**. For the same fixed input, changing only the resource contract selects all three distinct executed traces in every seed, and forward hooks verify exclusive execution.

Router training uses only seven discrete compute/footprint price-ratio anchors. On held-out dense continuous ratios, mean oracle-route agreement is **98.64%** and the worst seed is **98.49%**. A nearest-training-anchor discrete external scheduler reaches **98.25%**, so the interpolation advantage is real but small.

Across 4,000 random price/mask contracts per seed, the matched price-aware router reaches **98.72%** mean oracle agreement while the price-blind router reaches **45.82%**. Mean normalized oracle regret is ~0.00076 vs ~0.30036.

See [`multicircuit_contract_transfer.md`](multicircuit_contract_transfer.md).

## Joint specialization without capability pretraining or freeze

A separate experiment asks whether the three candidate circuit types and router can be trained together from scratch rather than acquiring capabilities first and freezing them.

All circuit parameters and the router are initialized together. The successful condition adds an auxiliary task loss to **every potentially admissible circuit** each step so a rarely selected fallback cannot silently lose task capability. Candidate topologies are still deliberately constructed in this experiment.

Across five seeds:

- **Naive joint:** the retrieval route falls to **71.95% mean forced accuracy** (minimum **67.19%**), is never used in the held-out dense sweep, and random-contract oracle agreement is **68.33%**.
- **Capability-preserving joint:** every route remains **100% accurate in all five seeds**, all three routes are used in **5/5 seeds**, held-out dense oracle agreement is **98.15%**, random price/mask agreement is **97.36%**, and mean normalized regret is **0.00055**.
- **Capability-preserving price-blind:** every route remains 100% accurate, but dense oracle agreement is only **34.91%** and the same shallow route is selected across the three price regimes.

The joint model sees only seven discrete price-ratio anchors during training. Dense continuous price ratios are held out. For the same fixed input, the capability-preserving price-aware model selects tied-deep under footprint-expensive conditions, shallow compute under balanced prices, and retrieval under compute-expensive conditions.

### Relative-price representation

The analytic objective is homogeneous in price: multiplying every price coordinate by the same positive scalar cannot change the optimal route. Raw absolute log-price features nevertheless learn spurious common-scale dependence.

The raw-log-price ablation retains **97.96%** agreement on the fixed-scale dense sweep but falls to **79.56%** on random contracts with varying common price scale. Centering log prices within each contract restores the main result to **97.36%** random-contract agreement.

This is evidence for a normalized resource-contract interface based on **relative scarcity coordinates** when the decision depends only on price ratios.

### Gradient-separation diagnostic

Completely separating capability and allocation optimizers is not required in this toy. The decoupled diagnostic reaches **97.51%** held-out dense agreement and **96.17%** random-contract agreement, slightly below the ordinary capability-preserving joint result.

The stronger training lesson is therefore not “always separate every gradient,” but “preserve capability on every route the runtime may later require.”

See [`joint_self_specialization.md`](joint_self_specialization.md).

## Constrained topology-search follow-up

The latest experiment removes the short list of complete named execution routes. Instead, the experimenter supplies a three-stage supernet in which each stage can select `skip`, `lookup`, or `compute`. This defines **27 possible hard topologies**, but complete topologies are never used as training labels.

On the main XOR finite-domain task, across five seeds:

- the resource-price-aware system selects **4 distinct hard topologies in every seed** over the held-out dense price sweep;
- every selected hard topology remains **100% correct over all 256 inputs** at every tested price point;
- **5/5 seeds** use compute-only execution when the parameter-footprint proxy is expensive;
- **5/5 seeds** use lookup-only / lookup-heavy execution when the compute proxy is expensive;
- exact stage placement varies across seeds;
- the matched price-blind system selects exactly **one fixed topology in 5/5 seeds**.

This supports the narrower statement that **resource-conditioned subgraphs can be learned inside a supplied operation search space without complete-route supervision**.

### Global-resource-optimality failure

The discovered topology is not reliably the globally cheapest valid topology. After training, all 27 hard topologies are evaluated exhaustively and the cheapest topology with 100% full-domain accuracy is used as an oracle.

The directly learned topology matches this oracle on only **70.75%** of the dense price sweep on average across five seeds, with mean normalized proxy regret ~**0.01651**. The primary failure mode is redundant active operations.

A validation-only local pruning diagnostic removes active operations when replacing them with `skip` preserves 100% full-domain accuracy. It improves mean oracle agreement to **88.9%** and mean regret to ~**0.00274**, but one seed remains poorly consolidated. The pruning result is deliberately reported separately from the topology produced by the learned router.

### Harder-task stress result

The same procedure is less stable on 4-bit parity. Across three seeds, all selected hard topologies remain 100% accurate, but only **1/3 seeds** discovers multiple resource-conditioned topologies; **2/3 seeds** collapse to a single lookup topology.

Therefore robust/general topology self-organization is **not supported**.

Several optimizer variants also failed to improve the main result: soft-mixture training often fails after hard discretization; deterministic straight-through is less resource-optimal; primitive DropPath preserves task accuracy but encourages redundant multi-operation topologies; router-only consolidation can damage hard accuracy.

See [`topology_search_discovery.md`](topology_search_discovery.md).

## Simulated normalized-contract transfer

The frozen three-circuit router from the earlier extension is evaluated under four simulated runtime/hardware calibration profiles. The runtime multiplies an abstract scarcity vector by a two-dimensional calibration vector before emitting the effective resource price; hardware identity is never given to the model.

Across five seeds, mean oracle agreement remains:

- compute-friendly: **97.85%**
- balanced: **98.07%**
- compute-scarce: **98.51%**
- footprint-scarce: **97.99%**

This supports only a **separable multiplicative normalized-contract interface**. It is not evidence that arbitrary real hardware, compilers, accelerators, or non-separable route-cost changes can be handled by recalibration alone.

## Runtime timing / safety-mask evidence

Earlier shared empirical timing-mask experiments established the intended responsibility split at a toy level: runtime calibration determines the available execution classes and the neural router optimizes only inside that set. No forced fallback is used when the safe set is empty.

However, a same-core Linux contention follow-up provides an important negative result. The experiment pins inference to one CPU, adds a competing busy process on that CPU, measures each forced route, and builds an empirical 99%-order-statistic mask.

The desired route-specific separation was **not stable**. Across three independent invocations of the three-repetition script, the number of repetitions that produced the intended state-dependent separation was **0/3, 1/3, and 0/3**. Several-millisecond scheduler/preemption tails often affected even the shortest routes, and state recalibration did not consistently improve held-out miss rate.

Therefore the stronger statement

> state-conditioned route-wise P99 calibration on ordinary Linux is sufficient for a stable runtime safety mask

is **not supported**.

This does not invalidate the architectural separation between runtime availability and neural routing; it shows that the runtime side requires a more predictable platform, stronger isolation/scheduler integration, or formal/static timing analysis for stronger guarantees.

See [`runtime_contention_negative.md`](runtime_contention_negative.md).

## Related-work / novelty boundary

LUT/logic neural computation, dynamic routing, neural architecture search, once-for-all subnetworks, and runtime architecture switching are established research areas. See [`../RELATED_WORK.md`](../RELATED_WORK.md).

The topology-search follow-up is therefore not presented as a new NAS method. The remaining narrow mechanism under review is the combination of an explicit normalized resource-price/control contract, resource-conditioned internal execution, and an independent runtime availability constraint.

## Defensible claims

### Supported

1. Resource price can function as a neural execution-control signal in the tested systems.
2. A fixed parameterized network can change its actually executed internal module sequence as resource conditions change while preserving task output in the finite toy domains.
3. The effect extends from two to three resource-distinct internal circuits.
4. A matched price-aware router strongly outperforms a price-blind router on random resource/mask contracts in the three-circuit toys.
5. Given deliberately constructed candidate circuit types and explicit all-circuit capability supervision, route capabilities and a resource-conditioned allocation policy can be learned jointly from scratch without capability pretraining or freezing in the tested toy.
6. Relative/centered log-price coordinates improve robustness to irrelevant common price scaling in the tested objective.
7. Given a supplied supernet of resource-distinct primitive operations, a price-conditioned router can learn multiple accurate hard subgraphs without complete-route supervision on the XOR toy.
8. A frozen router can consume recalibrated normalized contracts under the tested separable multiplicative simulation without receiving hardware identity.
9. An independent availability mask can override resource-price routing by construction.
10. Price-input intervention changes routing in the expected direction.

### Not supported

1. Hard real-time guarantees or WCET bounds.
2. General energy savings in joules.
3. Reduced total resident memory from route switching.
4. Universal superiority to external schedulers or NAS; analytic scheduling remains an oracle when route costs are known exactly.
5. A large advantage over a strong discrete price-bin scheduler; the dense three-circuit interpolation gain is small.
6. Large-model/LLM generalization.
7. General or unconstrained neural architecture discovery.
8. Globally resource-optimal topology search; the XOR learned topologies reach only 70.75% mean global-oracle agreement before post-hoc pruning.
9. Robust topology discovery across tasks; the 4-bit-parity stress test yields multiple topologies in only 1/3 seeds.
10. Input-dependent difficulty adaptation in the reported routers.
11. Novelty of LUT neurons, dynamic routing, NAS, once-for-all networks, or runtime subnetwork switching.
12. Demonstrated gains on existing related architectures such as DWN, NeuraLUT, LL-ViT, OFA, Dynamic-OFA, HADAS, or Adaptive Neural Trees.
13. Real-hardware portability from the simulated calibration-transfer result.
14. Stable route-specific P99 safety masks under ordinary Linux contention.

## Prior falsification results retained

1. Weak compute-price penalties can be ignored entirely.
2. Excessively strong fixed penalties can cause abrupt cheap-policy collapse rather than smooth adaptation.
3. Naive jointly selected expert training can cause capability forgetting; the five-seed joint-from-scratch ablation reproduces this failure and shows that explicit capability preservation fixes it in the tested toy.
4. Raw absolute log-price features can learn spurious common-scale dependence even when only price ratios should matter.
5. Constrained topology search can preserve task accuracy while still retaining redundant active operations and missing the global resource optimum.
6. The same topology-search procedure is not robust on the harder parity stress task.
7. Linear `compute_time + memory_time` latency models did not reliably predict end-to-end route latency on Linux/PyTorch.
8. Naive online safety-factor adaptation was unstable under OS jitter.
9. Calibration under one runtime load may fail under another. Earlier controlled toy experiments sometimes recovered statistical coverage with matched-state recalibration, but the same-core contention experiment shows that this recovery is not stable or universal.
10. A resource vector is not automatically superior to a scalar; additional dimensions can be redundant/noisy.
11. Price-conditioned routing did not automatically dominate a strong input-only adaptive-routing baseline in quality–compute Pareto efficiency.

## Recommended preprint framing

A narrow mechanism note remains defensible under a title such as:

**Resource-Conditioned Neural Computation: Learned Price-Aware Execution Paths under Runtime Safety Masks**

The stronger architectural motivation can now be stated explicitly: resource conditions can control the effective internal circuit of one fixed neural system, and a supplied primitive-operation supernet can learn different accurate hard subgraphs without complete-route supervision on the easy XOR toy.

Do not frame this as a new NAS method, general spontaneous architecture discovery, a hard-real-time neural architecture, a new LUT-network architecture, a physical energy result, or a proof of general hardware portability.

## Next action

Hold this mechanism claim fixed during the remaining public review window. Add experiments only to resolve a concrete critique, reproduction failure, or confound. If no unresolved core objection remains after the review window, freeze a revision and use it as the reproducibility reference for a short technical note.
