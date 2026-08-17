# Resource-Conditioned Neural Computation

A small, falsification-oriented mechanism study of neural execution under explicit resource conditions and runtime availability constraints.

## Status

**Public mechanism note / reproduction package. Not a hard-real-time claim.**

The narrow systems idea under test is:

> A fixed neural system can change the internal computation it actually executes as an explicit normalized resource condition changes, while an independent runtime mechanism constrains which execution classes are available.

The repository intentionally stays small. It does **not** claim WCET/hard-real-time guarantees, physical energy savings, universal superiority to external schedulers/NAS, unconstrained architecture discovery, arbitrary hardware portability, or LLM generalization.

## Strongest current mechanism result

The harder 4-bit-parity follow-up uses a supplied three-stage `skip / lookup / compute` supernet. Capability parameters and the resource router start from scratch and capability parameters are **never frozen**.

The successful recipe separates:

1. fallback capability preservation;
2. capability readiness before strong resource pressure;
3. correlated autoregressive allocation;
4. binary feasibility from within-feasible-set resource optimization.

Across five seeds:

| condition | hard accuracy | tie-aware minimum-cost rate | worst seed | mean regret |
|---|---:|---:|---:|---:|
| immediate joint factorized | 99.75% | 21.90% | 0.00% | 0.24381 |
| immediate joint autoregressive | 100.00% | 37.15% | 0.00% | 0.19536 |
| capability-gated factorized | 100.00% | 81.95% | 51.75% | 0.00978 |
| capability-gated autoregressive | 100.00% | 97.25% | 91.75% | 0.00171 |
| **capability-gated constrained autoregressive** | **100.00%** | **98.55%** | **95.75%** | **0.00057** |
| matched price-blind control | 100.00% | 50.25% | 50.25% | 0.15863 |

A sampled autoregressive follow-up removes complete-topology marginalization and full-domain feasibility from router training and still reaches **95.05% mean / 91.25% worst-seed** minimum-cost rate at 100% final task accuracy.

See [`notes/joint_parity_curriculum.md`](notes/joint_parity_curriculum.md).

## New robustness boundary: search space and hardware cost structure

The latest robustness experiment keeps all single-primitive capabilities at 100% and changes the supplied search space / resource-cost structure.

| configuration | mean hard accuracy | mean tie-aware min-cost rate | worst seed |
|---|---:|---:|---:|
| 3-stage homogeneous costs | 100% | 87.70% | 53.00% |
| 4-stage homogeneous costs | 100% | **98.10%** | **91.25%** |
| 4-stage, heterogeneous op availability only | 100% | 90.00% | 50.25% |
| 4-stage, **stage-dependent costs only** | 100% | **33.00%** | **0.00%** |
| 4-stage, availability + stage-dependent costs | 100% | **41.65%** | **22.00%** |

Increasing depth from three to four stages does not itself break the mechanism. The main failure appears when route/stage resource costs become non-uniform. Increasing price-ratio training anchors from 7 to 21 does not rescue that condition: mean optimality falls to **21.20%**, with a 0% worst seed.

This materially narrows the portability interpretation: a small global scarcity vector is not sufficient evidence for route-dependent or non-separable hardware changes.

See [`notes/searchspace_contract_robustness.md`](notes/searchspace_contract_robustness.md).

## Route-local calibration diagnostic

A separate frozen-capability interface diagnostic gives the runtime a richer stage-local calibration contract. With 256 generated training hardware profiles and 20 disjoint held-out profiles, a flat calibration-aware policy reaches:

- **73.10% mean** held-out minimum-cost rate across three router seeds;
- **70.05% worst seed**;
- **24.99%** for the matched calibration-blind control;
- **25.63%** when calibration inputs are deliberately swapped at inference.

The intervention shows that route-local calibration information matters, but the learned policy remains below the analytic scheduler. A calibration-aware autoregressive diagnostic also collapses to one route in the tested seed (**5.25%** minimum-cost rate), so richer contract information does not by itself solve routing optimization.

Therefore the current portability boundary is:

> separable/global runtime recalibration is supported only in the narrow earlier simulation; non-separable stage-/route-local cost changes require a richer contract and/or external scheduling, and robust learned use of that richer contract is not yet established.

## Evidence ladder

1. **Two physically distinct strategies:** lookup/copy vs algorithmic MLP; price intervention flips the chosen strategy. Exact analytic scheduling remains the oracle when costs are known.
2. **One fixed network, different internal circuits:** changing only resource condition changes the executed module sequence; inactive modules are not executed.
3. **Three internal circuits:** discrete price anchors generalize to held-out continuous ratios; price-aware routing beats a matched price-blind control, but only slightly beats a nearest-anchor external scheduler.
4. **Joint capability acquisition:** fallback supervision prevents capability forgetting; centered relative prices remove irrelevant common-scale dependence.
5. **Constrained subgraph discovery:** a supplied `skip / lookup / compute` supernet learns multiple resource-conditioned hard subgraphs without complete-route labels on XOR.
6. **Harder parity:** capability readiness, correlated routing, and feasibility/resource separation are all needed for stable freeze-free training in the tested toy.
7. **Robustness falsification:** stage-dependent non-separable route costs break the simple global-contract policy despite perfect task capability.

Detailed evidence is in `notes/`, `results/`, and [`CLAIMS_AND_LIMITS.md`](CLAIMS_AND_LIMITS.md).

## Resource proxies

The main resource-conditioned experiments use two normalized coordinates:

- **compute proxy:** approximate executed operation/MAC count;
- **parameter-footprint proxy:** parameters associated with the selected expert/circuit.

The second coordinate is **not** measured runtime memory traffic, bandwidth, cache pressure, reduced resident memory, or energy. All parameters remain resident in the same model/process.

## Runtime availability / real-time boundary

A separate runtime mask can disable execution classes. Neural price routing cannot override that mask; if no route is available, the implementation does not force an uncertified fallback.

Ordinary Linux/PyTorch timing is **not WCET**. Same-core contention experiments show scheduler/preemption tails can destroy stable route-specific empirical P99 separation. Stronger timing guarantees require a more predictable platform, scheduler/runtime isolation, or formal/static timing analysis.

## Related work / novelty boundary

**Not claimed as novel:** LUT neurons/networks, differentiable logic networks, dynamic routing, neural architecture search, once-for-all subnetworks, or runtime subnetwork switching.

Representative prior work and the exact novelty boundary are documented in [`RELATED_WORK.md`](RELATED_WORK.md).

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
python experiments/router_stabilization_audit.py --suite
python experiments/joint_parity_correlated_curriculum.py --suite
python experiments/sampled_joint_parity_policy.py
python experiments/searchspace_robustness.py --suite --out results/searchspace_robustness_full.json
python experiments/nonseparable_contract_diagnostic.py --suite
```

The committed result JSONs are compact authoritative summaries; suite runs can emit fuller traces.

## Repository scope

This is a mechanism study, not a scaling project. It does not currently target LLMs, GPUs, or production RTOS deployment.

## License

Apache License 2.0. See `LICENSE`.
