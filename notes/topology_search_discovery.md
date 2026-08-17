# Resource-conditioned topology search inside a supplied supernet

## Question

How far can the resource-conditioned mechanism be pushed toward topology discovery without predefining a small list of complete execution routes?

This experiment replaces the earlier hand-enumerated retrieval / shallow / tied-deep route list with a small supernet. The experimenter still supplies the primitive operations and stage count. The learned object is the per-stage operation assignment as a function of resource price.

This is therefore **resource-conditioned subgraph discovery inside a supplied search space**, not unconstrained neural architecture discovery.

## Search space

One `SearchNet` has three stages. Each stage can choose one of:

- `skip`;
- `lookup` — compute-light, active-parameter-footprint-heavy;
- `compute` — repeated small-weight nonlinear transform, compute-heavy, footprint-light.

There are `3^3 = 27` possible hard topologies. Complete topologies are never used as training labels.

The router receives centered relative log resource prices. Training uses only seven price-ratio anchors:

`[0.02, 0.08, 0.25, 1, 4, 12.5, 50]`

The main task is XOR of two input bits, evaluated exhaustively over all 256 eight-bit inputs. A harder 4-bit parity task is retained as a stress/negative result.

## Main five-seed result: XOR

With the resource-price signal enabled:

- every seed selects **4 distinct hard topologies** over the held-out dense price sweep;
- every selected topology is **100% correct over all 256 inputs** at every tested price point;
- **5/5 seeds** use a compute-only topology when the parameter-footprint proxy is expensive;
- **5/5 seeds** use a lookup-only / lookup-heavy topology when the compute proxy is expensive;
- exact stage placement varies across seeds, so the full route is not a fixed named circuit supplied in advance.

With the resource-price features zeroed, the matched price-blind system selects exactly **one fixed topology in 5/5 seeds**.

This is the strongest evidence in the repository so far that resource condition can participate in learning the effective subgraph itself rather than only selecting among a short hand-enumerated route list.

## Metric correction: topology identity is not cost optimality

The original report used `global_oracle_agreement`, which compared the learned topology against one topology returned by Python `min()`. This is a poor cost-optimality metric when several stage-symmetric topologies have exactly the same minimum resource cost.

The original exact-route-identity number is retained for audit history, but the primary cost-optimality metrics are now **tie-aware minimum-cost rate** and regret.

Across the five XOR seeds:

- exact selected-route identity with one arbitrarily chosen oracle route: **70.75%**;
- tie-aware minimum-cost rate: **73.10%**;
- mean proxy regret: **0.01651**.

The correction changes the metric, not the main conclusion: the directly learned topologies are still not reliably resource-optimal.

## Post-hoc local pruning diagnostic

A separate validation-only local pruning diagnostic removes an active operation only when replacing it by `skip` preserves 100% full-domain accuracy.

Across five seeds:

- exact route identity with one oracle route: **88.9%**;
- tie-aware minimum-cost rate: **94.6%**;
- mean regret: **0.00274**.

The pruning result is reported separately because it is not the topology produced directly by the learned router. One seed remains only **87.0%** tie-aware optimal after pruning, so the consolidation problem is not fully solved.

## Harder-task stress test: 4-bit parity

The same end-to-end Gumbel search procedure is less stable on 4-bit parity.

Across three seeds:

- all selected hard topologies remain 100% accurate;
- only **1/3 seeds** discovers multiple resource-conditioned topologies;
- **2/3 seeds** collapse to a single lookup topology.

Therefore the result does **not** support a claim that useful resource-conditioned topology discovery emerges reliably across tasks.

## Router-stabilization diagnostic

A follow-up audit asks whether the parity failure is only a capability problem.

To isolate allocation, the six single-primitive probe topologies — one lookup or one compute operation at each of the three stages — are trained to **100% full-domain parity accuracy in all five seeds**. Capability parameters are then frozen, and several routers optimize the same 27-topology resource objective.

All router variants retain **100% hard task accuracy**. Their five-seed resource results are:

| router / objective | mean tie-aware optimal-cost rate | worst seed | mean regret |
|---|---:|---:|---:|
| independent-stage factorized + confidence/margin objective | 83.95% | 51.75% | 0.00905 |
| independent-stage factorized + binary feasibility | 77.30% | 49.75% | 0.01264 |
| **autoregressive + binary feasibility** | **94.85%** | **93.50%** | **0.00235** |
| flat 27-way route policy + binary feasibility | 94.20% | 92.50% | **0.00146** |
| autoregressive, best of four restarts by the same training objective | 95.60% | 92.00% | 0.00155 |

This shows that capability preservation alone is not sufficient. Even with identical valid primitives, independent per-stage routing can fall into poor resource-allocation optima. Allowing later stage choices to condition on earlier choices is substantially more stable in this controlled diagnostic.

The flat 27-way policy explicitly enumerates complete routes and is retained only as a small-search-space reference. The autoregressive router does not enumerate complete routes as output classes, but its present audit objective still sums exactly over all 27 topologies during training. Neither result is presented as a scalable NAS method.

See [`router_stabilization_audit.md`](router_stabilization_audit.md).

## Optimizer ablations retained as negative results

Several alternatives were tested in the original joint search:

| training variant | mean hard accuracy on dense sweep | original exact-route oracle agreement | observation |
|---|---:|---:|---|
| Gumbel straight-through (main) | 100% | 70.75% | stable XOR capability and topology diversity, but redundant ops remain |
| soft mixture | 65.55% | 58.4% | soft training often fails after hard discretization |
| deterministic straight-through argmax | 96.05% | 34.75% | less stable hard capability and poor resource optimality |
| primitive DropPath | 100% | 10.7% | preserves capability but encourages redundant multi-op topologies |

A router-only consolidation pass was also attempted. It improved some seeds but damaged hard accuracy in another seed, so it is not promoted as a solution.

## What this supports

A narrow statement is supported on the XOR toy:

> Given a hand-specified supernet of resource-distinct primitive operations, a price-conditioned neural router can learn multiple accurate hard subgraphs without complete-route supervision, and the selected operation pattern changes systematically with the resource-price direction.

The stabilization audit further supports a narrower diagnostic statement:

> once primitive capability is controlled, correlated topology decisions remain an important optimization issue; an autoregressive router is markedly more stable than an independent-stage router in the tested parity search space.

## What this does not support

- unconstrained or general neural architecture discovery;
- novelty of neural architecture search, dynamic routing, runtime subnetwork switching, or once-for-all subnetworks;
- globally resource-optimal topology search;
- robust end-to-end topology discovery across harder tasks;
- a joint-from-scratch parity solution from the frozen-capability router audit;
- spontaneous invention of new primitive operations;
- a scalable alternative to NAS;
- hard real-time/WCET guarantees;
- physical memory, bandwidth, or Joule savings;
- large-model/LLM generalization.

## Related-work implication

This result moves the repository closer to established dynamic-routing / NAS / once-for-all work. Relevant prior art includes dynamic routing networks, Adaptive Neural Trees, Once-for-All networks, Dynamic-OFA, and hardware-aware dynamic NAS such as HADAS. The repository should not claim novelty for topology search or runtime subnetwork switching themselves.

The remaining narrow systems question is the combination of an explicit normalized resource-price contract, internal resource-conditioned execution, and an independent runtime availability constraint.
