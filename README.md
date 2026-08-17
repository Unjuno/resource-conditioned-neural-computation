# Resource-Conditioned Neural Computation

A small, falsification-oriented mechanism study of neural execution-path selection under explicit resource prices and runtime safety masks.

## Status

**Public mechanism note / reproduction package. Not a hard-real-time claim.**

The narrow result supported by the included experiments is:

> A fixed-parameter neural system can learn to select between functionally equivalent but resource-distinct execution paths using a continuous resource-price signal, while an independent runtime mask constrains the selectable execution classes for statistical deadline safety.

The package deliberately includes negative results and does **not** claim WCET guarantees, universal Pareto superiority, energy savings in joules, or generalization to LLMs.

## Constructive example

Two strategies solve the same 12-bit majority task at 100% accuracy:

- **Lookup / copy path:** parameter-footprint-heavy, compute-light.
- **Algorithmic MLP path:** lower parameter footprint, compute-heavy.

In the current reproduction script, the lookup expert has 8,192 parameters and an approximately 2-operation lookup proxy, while the MLP has 4,706 parameters and 4,544 linear MACs. The second resource coordinate is therefore a **normalized parameter-footprint proxy**. It is **not** a measurement of runtime memory traffic, bandwidth, resident-memory reduction, or energy.

A small router observes two resource prices: one for the compute proxy and one for the parameter-footprint proxy. With both paths available, changing only their price ratio changes the selected path while task accuracy remains 100%. The routing probabilities vary smoothly with the continuous price ratio and cross a learned decision boundary.

A separate runtime mask can disable execution classes based on held-out timing calibration. The learned resource-price policy cannot override this mask. If the runtime declares no execution class safe, the public implementation returns **not admitted** rather than executing an uncertified fallback route.

## Related work / novelty boundary

**LUT-based neural computation, dynamic routing, neural architecture search, once-for-all subnetworks, and runtime subnetwork switching are not claimed as novel here.** Prior work already includes differentiable logic-gate/LUT networks, dynamically routed neural graphs, Adaptive Neural Trees, Once-for-All, Dynamic-OFA, and hardware-aware dynamic NAS such as HADAS.

The lookup path here is only a clean constructive example of one execution regime. The narrower question is whether a model can use an explicit normalized resource-price signal to change its actual internal execution while an independent runtime mask constrains feasibility.

See [`RELATED_WORK.md`](RELATED_WORK.md) for the explicit prior-art boundary.

## Main observations

- Across three seeds, compute-expensive conditions route to lookup/copy while preserving task accuracy.
- Parameter-footprint-proxy-expensive conditions route to algorithmic computation.
- A continuous price-ratio sweep changes the routing distribution while preserving 100% accuracy at every tested point.
- The price-aware and price-blind controls use the **same router architecture and parameter count (114 parameters)**; the control receives zeroed price features and is trained against the same price distribution.
- On the tested two-route objective, the learned price-aware router matches the analytic external scheduler `argmin_j price · cost_j` at all 27 sweep points (9 ratios × 3 seeds). This repository therefore does **not** claim that learning is superior to an analytic scheduler when the route-cost table is known exactly.
- Under a shared runtime safe set, price-aware routing reduces the tested normalized resource objective at identical task accuracy in the footprint-proxy-expensive condition.
- Corrupting the price signal reverses the routing decision and worsens the actual resource objective, providing an intervention-based negative control for fixed-route preference.

See [`notes/readiness_report.md`](notes/readiness_report.md) for exact claims, limitations, and prior falsification results.

## Direct internal-circuit test

The repository also contains a direct test of the original architectural claim: **one fixed parameterized network changes the internal subgraph that is actually executed when only the resource condition changes**.

The model contains a retrieval node, an algorithmic stem with four residual compute blocks, a shared classifier head, and a resource-conditioned router. Under one resource condition the executed trace is `retrieval -> head`; under another it is `stem -> block0 -> block1 -> block2 -> block3 -> head`.

Across three seeds, both circuits retain 100% accuracy over all 4,096 task states. An exhaustive same-input counterfactual check confirms that changing only the resource condition changes the selected circuit while preserving the prediction over the complete finite domain. Forward hooks verify that modules on the inactive subgraph are not executed.

This directly supports **resource-conditioned effective internal circuits**, not merely variable iteration count. It does **not** show spontaneous circuit discovery: the alternative subgraphs were deliberately constructed and only the router was post-trained after capability acquisition. See [`notes/internal_circuit_experiment.md`](notes/internal_circuit_experiment.md).

## Three-circuit contract generalization

A stronger follow-up puts **three** resource-distinct circuits inside one fixed network with a shared classifier head:

- retrieval: high active parameter-footprint proxy, very low compute proxy;
- shallow compute: intermediate footprint and compute;
- tied-deep compute: low active parameter-footprint proxy, high repeated compute.

Across five seeds, all three circuits achieve 100% accuracy over the complete 256-input finite domain. Holding the task input fixed and changing only the resource contract selects all three distinct executed traces in every seed, and forward hooks verify exclusive execution of the selected subgraph.

The router is trained on only seven discrete price-ratio anchors. On held-out dense continuous ratios, mean oracle-route agreement is **98.64%** (minimum seed **98.49%**). A nearest-anchor discrete external scheduler reaches **98.25%**, so the learned interpolation advantage over that strong simple baseline is present but small. Over 4,000 random price/mask contracts per seed, the price-aware router reaches **98.72%** mean oracle agreement versus **45.82%** for the matched price-blind router.

A simulated runtime-calibration transfer keeps the NN and router frozen, applies one of four separable multiplicative calibration profiles to the abstract scarcity vector, and never gives hardware identity to the model. Mean oracle agreement remains approximately **97.85%–98.51%** across the four profiles. This supports only a narrow normalized-contract interface under that separable simulation; it is not evidence of arbitrary real-hardware portability.

See [`notes/multicircuit_contract_transfer.md`](notes/multicircuit_contract_transfer.md).

## Joint specialization from scratch

A separate follow-up removes capability pretraining and freezing. The same three circuit types and router are initialized together and trained from scratch in one run. Candidate topologies are still deliberately constructed; this is **not** spontaneous topology discovery.

Naive joint optimization fails: the retrieval fallback route drops to **71.95% mean forced accuracy** across five seeds (minimum **67.19%**) and is never selected in the held-out dense sweep.

Adding a task loss on every potentially admissible circuit prevents that forgetting. In the capability-preserving joint condition:

- all three circuits remain **100% accurate in all 5 seeds**;
- all three routes are selected in **5/5 seeds**;
- training sees only seven discrete price-ratio anchors;
- held-out dense continuous ratios reach **98.15% mean oracle-route agreement**;
- 4,000 random price/mask contracts per seed reach **97.36% mean oracle agreement** with mean normalized regret **0.00055**;
- the same fixed input routes to tied-deep, shallow, or retrieval solely as the resource price changes.

The matched capability-preserving price-blind control keeps every route accurate but does not specialize: held-out dense agreement is **34.91%**, and it selects the same shallow route across the three price regimes.

A scale-invariance ablation also matters. When the router sees raw log prices, fixed-scale dense agreement stays high (**97.96%**) but random-contract agreement falls to **79.56%** when the common price scale changes. Centering log prices per contract restores the stronger result, matching the fact that multiplying all price coordinates by the same positive scalar cannot change `argmin(price · cost)`.

Complete gradient separation is not required: a diagnostic that trains capabilities and allocation with separate optimizers reaches **97.51%** held-out dense agreement, slightly below the ordinary capability-preserving joint result.

See [`notes/joint_self_specialization.md`](notes/joint_self_specialization.md).

## Constrained topology-search follow-up

The latest experiment removes the short list of complete named routes. Instead, one three-stage supernet supplies only primitive operations: `skip`, `lookup`, or `compute` at each stage. This creates **27 possible hard topologies**, but complete topologies are never used as training labels.

On the main XOR toy, the resource-price-aware model:

- selects **4 distinct hard topologies in every one of 5 seeds** over the held-out dense price sweep;
- keeps **100% exhaustive task accuracy** at every tested price point;
- uses a **compute-only** topology when the parameter-footprint proxy is expensive in **5/5 seeds**;
- uses a **lookup-only / lookup-heavy** topology when the compute proxy is expensive in **5/5 seeds**;
- learns different exact stage placements across seeds, rather than reproducing one fixed named route.

The matched price-blind version selects exactly **one fixed topology in 5/5 seeds**.

This is evidence for **resource-conditioned subgraph discovery inside a supplied supernet search space**. It is not evidence for unconstrained architecture discovery.

The optimization remains imperfect. After training, all 27 hard topologies are exhaustively checked; the learned topology matches the globally cheapest 100%-accurate topology only **70.75%** of the dense price sweep on average. A separate validation-only local pruning diagnostic improves this to **88.9%**, but one seed remains poorly consolidated.

A harder 4-bit-parity stress test is also unstable: only **1/3 seeds** discovers multiple resource-conditioned topologies, while **2/3 seeds** collapse to a single lookup topology. Therefore the repository does **not** claim that topology discovery is robust across tasks.

See [`notes/topology_search_discovery.md`](notes/topology_search_discovery.md).

## Runtime contention negative result

A same-core Linux contention follow-up attempted to turn empirical 99%-order-statistic timing calibration into a route-specific availability mask. The desired separation was **not stable** across independent invocations: scheduler/preemption tails of several milliseconds often affected even short routes, and state recalibration did not consistently improve held-out miss rate.

This falsifies the simple claim that route-wise P99 recalibration on ordinary Linux is by itself sufficient to obtain a stable runtime safety mask. See [`notes/runtime_contention_negative.md`](notes/runtime_contention_negative.md).

## Reproduce

Python 3.10+ is recommended.

```bash
python -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
python experiments/price_mask_conformal_multiseed.py
python experiments/price_negative_control.py
python experiments/internal_circuit_conditioning.py
python experiments/multicircuit_contract_transfer.py
python experiments/multicircuit_runtime_state_calibration.py
python experiments/joint_self_specialization.py
python experiments/topology_search_discovery.py --suite
```

Generated JSON is written to `results/`.

### Timing caveat

Latency measurements depend strongly on OS/runtime state. The scripts set one PyTorch thread and attempt CPU affinity, but ordinary Linux/PyTorch measurements are **not WCET measurements**. The contention follow-up further shows that scheduler/preemption tails can dominate route-local timing and make empirical P99 class separation unstable. Do not interpret the statistical mask as a hard-real-time guarantee.

## What would falsify the useful interpretation?

Useful criticism includes evidence that:

1. interventions on the resource-price input do not actually control routing;
2. an equivalent price-blind policy reproduces the same resource adaptation under matched conditions;
3. the timing-mask result is an artifact of calibration leakage;
4. the result disappears under a clean reimplementation;
5. a materially identical prior method already establishes the same narrow mechanism and runtime/model responsibility split;
6. the three-circuit result is explained by a weaker discrete controller once price/mask information and capacity are matched;
7. the joint-from-scratch result disappears when fallback capability and price normalization are matched fairly;
8. the constrained topology-search result disappears under a stronger matched supernet/NAS baseline or fails to transfer beyond the easy XOR setting.

Please open an issue using the critique/reproduction templates.

## Repository scope

This repository intentionally stays small. It is not a scaling project and does not currently target LLMs, GPUs, or production RTOS deployment.

## License

Licensed under the Apache License 2.0. See `LICENSE` in the repository root.
