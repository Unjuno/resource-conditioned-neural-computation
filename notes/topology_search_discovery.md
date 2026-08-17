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
- exact stage placement varies across seeds (for example, the compute operation appears at stage 1 in one seed and stage 0 in the others), so the full route is not a fixed named circuit supplied in advance.

With the resource-price features zeroed, the matched price-blind system selects exactly **one fixed topology in 5/5 seeds**.

This is the strongest evidence in the repository so far that resource condition can participate in learning the effective subgraph itself rather than only selecting among a short hand-enumerated route list.

## Important optimization failure: global resource optimum

Topology discovery is not the same as finding the globally cheapest valid topology.

After training, all 27 hard topologies are evaluated exhaustively. For each price, the global oracle is defined as the lowest proxy-cost topology among those that achieve 100% full-domain accuracy.

The learned price-aware topology matches that oracle only **70.75% on average across five seeds**, despite maintaining 100% task accuracy. Mean proxy regret is approximately **0.01651**.

The main failure mode is redundant active operations, especially multiple lookup operations after one lookup has already become sufficient.

A separate **post-hoc local pruning diagnostic** removes an active operation only when replacing it by `skip` preserves 100% full-domain accuracy. This improves mean oracle agreement to **88.9%** and reduces mean regret to approximately **0.00274**, but it still does not solve every seed (one seed remains at 58.5% oracle agreement).

The pruning result is reported separately because it is not the topology produced directly by the learned router.

## Harder-task stress test: 4-bit parity

The same search procedure is less stable on 4-bit parity.

Across three seeds:

- all selected hard topologies remain 100% accurate;
- only **1/3 seeds** discovers multiple resource-conditioned topologies;
- **2/3 seeds** collapse to a single lookup topology.

Therefore the result does **not** support a claim that useful resource-conditioned topology discovery emerges reliably across tasks.

## Optimizer ablations

Several alternatives were tested and retained as negative diagnostics:

| training variant | mean hard accuracy on dense sweep | mean global-oracle agreement | observation |
|---|---:|---:|---|
| Gumbel straight-through (main) | 100% | 70.75% | stable task capability and price-conditioned topology diversity, but redundant ops remain |
| soft mixture | 65.55% | 58.4% | soft training often fails after hard discretization |
| deterministic straight-through argmax | 96.05% | 34.75% | less stable hard capability and poor resource optimality |
| primitive DropPath | 100% | 10.7% | preserves capability but encourages redundant multi-op topologies |

A router-only consolidation pass was also attempted. It improved some seeds but damaged hard accuracy in another seed, so it is not promoted as a solution.

## What this supports

A narrow statement is supported on the XOR toy:

> Given a hand-specified supernet of resource-distinct primitive operations, a price-conditioned neural router can learn multiple accurate hard subgraphs without complete-route supervision, and the selected operation pattern changes systematically with the resource-price direction.

## What this does not support

- unconstrained or general neural architecture discovery;
- novelty of neural architecture search, dynamic routing, runtime subnetwork switching, or once-for-all subnetworks;
- globally resource-optimal topology search;
- robust topology discovery across harder tasks (the parity stress test is unstable);
- spontaneous invention of new primitive operations;
- hard real-time/WCET guarantees;
- physical memory, bandwidth, or Joule savings;
- large-model/LLM generalization.

## Related-work implication

This result moves the repository closer to established dynamic-routing / NAS / once-for-all work. Relevant prior art includes dynamic routing networks, Adaptive Neural Trees, Once-for-All networks, Dynamic-OFA, and hardware-aware dynamic NAS such as HADAS. The repository should not claim novelty for topology search or runtime subnetwork switching themselves.

The remaining narrow systems question is the combination of an explicit normalized resource-price contract, internal resource-conditioned execution, and an independent runtime availability constraint.
