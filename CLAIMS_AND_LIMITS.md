# Claims and limits

## Core Real-Time NN target — not yet fully demonstrated

The intended claim is stronger and more specific than "resource-conditioned routing":

> A single fixed neural network can change its actually executed internal computation as an admitted time/compute/resource budget changes, such that actual executed work and measured inference latency change in a predictable way while useful task quality is retained.

For the intended Real-Time NN line, the required causal chain is:

```text
budget
  → internal activation pattern
  → physically executed work
  → measured latency
  → deadline behavior
```

**The current repository does not yet demonstrate this full chain in one experiment.**

## Supported precursor claims

The existing experiments support narrower facts:

1. A resource condition can act as an execution-control signal in the tested finite toy systems.
2. One fixed parameter set can change the **actually executed internal module sequence** as the resource condition changes while preserving task output.
3. Forward-hook audits verify cases where inactive subgraphs are not executed.
4. An independent runtime availability mask can override neural execution choices, separating feasibility from within-available-set optimization.
5. Same-architecture price-blind controls and resource-input interventions show that reported route switches depend on the resource signal rather than only a fixed route preference.
6. For deliberately supplied candidate circuits, capability and allocation can be trained jointly without capability freezing when fallback capability is explicitly preserved.
7. A supplied primitive supernet can form multiple resource-conditioned hard subgraphs in finite toy tasks without complete-route labels.
8. Capability readiness, correlated allocation, and feasibility/resource separation materially affect allocation stability on the harder parity toy.
9. Simple normalized resource contracts work only under limited cost structures; non-separable stage/route cost changes expose failures.
10. Learned resource allocation can be sensitive to router/policy parameterization even when task, search space, anchors, and cost objective are held fixed.
11. Ordinary Linux/PyTorch tail timing is not stable enough to be treated as WCET or a hard-real-time guarantee.

These are **precursor and implementation-diagnostic claims**. They are not the Real-Time NN endpoint.

## What is now the primary experimental metric

For Real-Time NN work, the repository should prioritize:

- active block/channel/neuron/edge counts;
- physical execution trace;
- executed operation/MAC count or equivalent implementation-level work;
- measured end-to-end latency distribution;
- task quality under each budget;
- deadline miss behavior under a runtime budget-admission policy.

Route-oracle agreement and proxy resource regret may remain useful diagnostics, but they are **secondary**.

## Router-policy work is secondary

Routers, gates, masks, and conditional controllers are possible implementation mechanisms. The project does not treat "finding the best router architecture" as its research objective.

Existing router-heavy experiments are retained because they expose relevant failure modes:

- capability forgetting;
- shortcut collapse;
- sensitivity to training order;
- correlated-decision difficulties;
- objective/local-minimum sensitivity;
- non-separable contract failures;
- policy-parameterization sensitivity.

Future router work should be justified only by whether it improves the direct Real-Time NN chain from budget to actual execution time.

## Runtime / RTOS responsibility split

The target architecture is:

```text
hardware / OS state
    ↓
runtime / RTOS timing model
    ↓
safe admitted normalized budget
    ↓
same neural network
    ↓
budget-conditioned internal execution
```

The runtime owns hardware-specific timing knowledge. The network should ideally consume a normalized contract.

A hard-real-time claim additionally requires a defensible timing bound such as formal/static WCET, time-predictable hardware, or an equivalent guarantee. Empirical Linux/PyTorch timing alone is insufficient.

## Resource-proxy definition

Precursor experiments use normalized compute and parameter-footprint proxies. Parameter footprint is not measured runtime memory traffic, bandwidth, cache pressure, reduced resident memory, or energy.

The core Real-Time NN experiment must move beyond proxy-only evaluation and measure actual executed work and actual latency.

## Explicitly not claimed

1. A complete Real-Time NN has already been demonstrated.
2. A Real-Time LM has already been demonstrated.
3. Hard real-time guarantees or WCET bounds.
4. Joule-level energy savings or measured memory-bandwidth savings.
5. Reduced total resident model memory from route switching.
6. Universal superiority over adaptive routing, MoE, early exit, NAS, once-for-all subnetworks, or external schedulers.
7. Necessity of a learned router when route costs are known exactly.
8. General/unconstrained automatic discovery of useful neural architecture.
9. A single undifferentiated objective that robustly self-organizes capability, topology, feasibility, resource allocation, and timing.
10. A scalable NAS method.
11. Input-difficulty adaptation in the reported resource routers.
12. Generalization to LLMs or large neural networks.
13. Novelty of LUT neurons/networks, differentiable logic networks, dynamic routing, NAS, or runtime subnetwork switching.
14. Arbitrary hardware portability.
15. Stable route-specific P99 safety masks under ordinary Linux contention.
16. Robustness to arbitrary router/policy parameterization.
17. That high route-oracle agreement is sufficient evidence for Real-Time NN behavior without measured budget-conditioned latency.

## Important negative results retained

- Weak resource pressure can be ignored; overly strong pressure can collapse useful capability.
- Naive joint specialization can forget fallback capability.
- Resource pressure introduced before alternative computation paths mature can lock the system into shortcuts.
- Direct constrained topology search can preserve accuracy while retaining redundant operations.
- Non-separable stage/route costs can break simple global resource contracts.
- Learned allocation remains below analytic scheduling in several known-cost toy settings.
- Router parameterization itself can materially affect seed stability.
- Ordinary Linux/PyTorch timing remains too jittery for WCET-style claims.

## Direction lock

Before adding a new main-line experiment, ask:

> Does this test whether changing the budget of the **same neural network** changes **actual internal activation**, **actual executed work**, or **actual inference time**?

If not, it belongs under secondary diagnostics rather than the main Real-Time NN claim.
