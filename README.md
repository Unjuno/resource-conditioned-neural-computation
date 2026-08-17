# Resource-Conditioned Neural Computation

A small, falsification-oriented mechanism study of neural execution under explicit resource conditions and runtime availability constraints.

## Status

**Public mechanism note / reproduction package. Not a hard-real-time claim.**

The narrow systems idea under test is:

> A fixed neural system can change the internal computation it actually executes as an explicit normalized resource condition changes, while an independent runtime mechanism constrains which execution classes are available.

The repository intentionally stays small. It does **not** claim WCET/hard-real-time guarantees, physical energy savings, universal superiority to external schedulers/NAS, unconstrained architecture discovery, or LLM generalization.

## Strongest current mechanism result

The latest follow-up uses the harder **4-bit parity** toy inside the same supplied three-stage supernet. Each stage may use `skip`, `lookup`, or `compute`; complete routes are not task labels.

Capability parameters and the resource router start from scratch and **capability parameters are never frozen**. The successful training recipe separates three concerns:

1. preserve fallback primitive capability;
2. delay strong resource optimization until fallback capabilities have matured;
3. use correlated autoregressive allocation with a binary feasibility/resource-cost split.

Across five seeds:

| condition | hard accuracy | tie-aware minimum-cost rate | worst seed | mean regret |
|---|---:|---:|---:|---:|
| immediate joint factorized | 99.75% | 21.90% | 0.00% | 0.24381 |
| immediate joint autoregressive | 100.00% | 37.15% | 0.00% | 0.19536 |
| capability-gated factorized | 100.00% | 81.95% | 51.75% | 0.00978 |
| capability-gated autoregressive | 100.00% | 97.25% | 91.75% | 0.00171 |
| **capability-gated constrained autoregressive** | **100.00%** | **98.55%** | **95.75%** | **0.00057** |
| matched price-blind control | 100.00% | 50.25% | 50.25% | 0.15863 |

All five constrained-autoregressive seeds use multiple hard subgraphs. At resource extremes they consistently choose compute-only execution when the parameter-footprint proxy is expensive and lookup-only execution when compute is expensive; exact stage placement remains seed-dependent.

This is **not** a single undifferentiated end-to-end self-organization result. It is better described as capability-gated, constrained joint/alternating optimization with no capability freeze.

See [`notes/joint_parity_curriculum.md`](notes/joint_parity_curriculum.md).

## Capability readiness matters

A three-seed threshold sweep varies how mature the six single-primitive probes must be before resource optimization begins.

- 80–90% readiness: worst-seed cost-optimality remains **49.75%**;
- 95% readiness: worst-seed cost-optimality rises to **95.75%**;
- 99–100% remains similarly strong in this toy.

This supports a training-order/curriculum interpretation. **95% is not claimed as a universal threshold.**

See [`results/capability_gate_threshold_sweep.json`](results/capability_gate_threshold_sweep.json).

## Removing exact topology enumeration from router training

The strongest constrained diagnostic computes an exact expectation over the tiny 27-topology space. A second experiment removes that advantage from router training:

- autoregressive sampled policy gradient;
- four sampled topologies per price anchor;
- feasibility estimated on fresh 64-state calibration minibatches;
- no full-domain feasibility and no complete-topology marginalization in router training;
- capability parameters continue training and never freeze.

Across five seeds, exhaustive final evaluation gives:

- **100% hard task accuracy** in all seeds;
- **95.05% mean** tie-aware minimum-cost rate;
- **91.25% worst seed**;
- mean regret **0.00285**;
- multiple routes in **5/5 seeds**.

This is weaker than exact marginalization (95.05% vs 98.55%) but shows that the parity result is not solely an artifact of enumerating all 27 topologies during router training.

See [`experiments/sampled_joint_parity_policy.py`](experiments/sampled_joint_parity_policy.py).

## Evidence ladder

The repository builds the claim through increasingly direct falsification tests rather than one large benchmark.

### 1. Two physically distinct strategies

A lookup/copy path and an algorithmic MLP solve the same task while carrying different compute and parameter-footprint proxies. Resource price changes the selected path; swapping the price signal flips the selected strategy and worsens the defined resource objective.

For the known two-route cost table, analytic `argmin(price · cost)` remains the oracle. **Learning is not claimed to beat exact external scheduling when costs are known.**

### 2. One fixed network, different executed internal circuits

`ResourceConditionedCircuitNet` places retrieval and algorithmic subgraphs inside one fixed parameter set. Changing only resource condition changes the actually executed module sequence while preserving the prediction over all 4,096 finite task states. Forward hooks verify inactive modules are not executed.

See [`notes/internal_circuit_experiment.md`](notes/internal_circuit_experiment.md).

### 3. Three resource-distinct internal circuits

A fixed network uses retrieval, shallow compute, or tied-deep compute. All three stay 100% accurate across five seeds. A router trained on seven discrete price-ratio anchors reaches **98.64%** held-out dense oracle agreement; a nearest-anchor external scheduler reaches **98.25%**, so the neural interpolation advantage is small.

Across random price/mask contracts, the price-aware router reaches **98.72%** versus **45.82%** for the matched price-blind router.

See [`notes/multicircuit_contract_transfer.md`](notes/multicircuit_contract_transfer.md).

### 4. Joint capability acquisition for supplied candidate circuits

Naive joint training forgets fallback capability. Supervising every potentially admissible circuit prevents that failure and yields **98.15%** held-out dense and **97.36%** random-contract agreement without capability pretraining/freeze.

Relative price representation matters: raw log prices fall to **79.56%** under irrelevant common-scale shift, while centered relative log prices recover 97.36%.

See [`notes/joint_self_specialization.md`](notes/joint_self_specialization.md).

### 5. Constrained subgraph discovery without complete-route labels

A three-stage `skip / lookup / compute` supernet defines 27 hard topologies. On XOR, five price-aware seeds each discover four resource-conditioned hard topologies at 100% exhaustive accuracy; the matched price-blind system selects one fixed topology.

Direct topology search is not globally resource-optimal. Tie-aware re-audit gives **73.10%** minimum-cost rate before pruning and **94.6%** after validation-only local pruning.

See [`notes/topology_search_discovery.md`](notes/topology_search_discovery.md).

### 6. Harder parity: capability, correlation, and training order

The original end-to-end parity search collapses in 2/3 seeds. A frozen-capability audit shows independent per-stage routing remains unstable even after all primitive capabilities are perfect, while autoregressive routing is much more stable.

The latest freeze-free curriculum then shows that **correlation alone is insufficient**: immediate autoregressive joint training still averages only 37.15% cost-optimality. Capability readiness plus correlated constrained routing is the key intervention in the tested setup.

See [`notes/router_stabilization_audit.md`](notes/router_stabilization_audit.md) and [`notes/joint_parity_curriculum.md`](notes/joint_parity_curriculum.md).

## Resource proxies

The main resource-conditioned experiments use two normalized coordinates:

- **compute proxy:** approximate executed operation/MAC count;
- **parameter-footprint proxy:** parameters associated with the selected expert/circuit.

The second coordinate is **not** measured runtime memory traffic, bandwidth, cache pressure, reduced resident memory, or energy. All parameters remain resident in the same model/process.

## Runtime availability / real-time boundary

A separate runtime mask can disable execution classes. Neural price routing cannot override that mask; if no route is available, the public implementation does not force an uncertified fallback.

However, ordinary Linux/PyTorch timing is **not WCET**. A same-core contention follow-up shows scheduler/preemption tails can destroy stable route-specific empirical P99 separation. Therefore the repository does not claim hard real-time behavior from these timing experiments.

Stronger guarantees would require a more predictable platform, scheduler/runtime isolation, or formal/static timing analysis.

## Related work / novelty boundary

**Not claimed as novel:** LUT neurons/networks, differentiable logic networks, dynamic routing, neural architecture search, once-for-all subnetworks, or runtime subnetwork switching.

Representative prior work and the exact novelty boundary are documented in [`RELATED_WORK.md`](RELATED_WORK.md).

The remaining narrow systems question is the combination of:

1. an explicit normalized resource contract/price;
2. resource-conditioned internal neural execution;
3. an independent runtime availability constraint.

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
python experiments/joint_self_specialization.py
python experiments/topology_search_discovery.py --suite
python experiments/topology_tie_aware_metric_audit.py --suite
python experiments/router_stabilization_audit.py --suite
python experiments/joint_parity_correlated_curriculum.py --suite
python experiments/joint_parity_correlated_curriculum.py --threshold-sweep
python experiments/sampled_joint_parity_policy.py
```

Generated JSON is written to `results/`.

## What would falsify the useful interpretation?

Useful criticism includes evidence that:

1. resource-price interventions do not actually control routing under matched conditions;
2. a price-blind matched policy reproduces the same adaptation;
3. fallback capability or feasibility information leaks the desired route label;
4. the freeze-free parity result disappears in a clean reimplementation;
5. the readiness/correlation effects disappear under stronger matched optimization baselines;
6. a materially identical prior method already establishes the same narrow mechanism and runtime/model responsibility split;
7. the result depends entirely on exhaustive topology enumeration — the sampled-policy follow-up partially addresses, but does not eliminate, this concern;
8. the mechanism fails once moved beyond the deliberately tiny supplied search space.

Please use the public review issue/templates for critique, prior art, or reproduction failures.

## Repository scope

This is a mechanism study, not a scaling project. It does not currently target LLMs, GPUs, or production RTOS deployment.

## License

Apache License 2.0. See `LICENSE`.
