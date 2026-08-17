# Resource-Conditioned Neural Computation — Readiness Report

## Status correction — Real-Time NN direction

**The previous STOP/readiness condition is revoked for the intended Real-Time NN research goal.**

A short note about resource-conditioned routing/subgraph selection could be written from the existing precursor experiments, but that is **not the intended endpoint of this project**.

The intended claim is:

> one fixed neural network receives an admitted budget/resource condition, changes the internal computation it actually executes, and thereby changes actual inference work and measured latency in a predictable way that can be used by a real-time runtime.

That claim is **not yet ready** because the repository has not yet demonstrated the complete chain in one experiment:

```text
budget
  → internal activation pattern
  → physically executed work
  → measured end-to-end latency
  → deadline behavior
```

## Why the previous readiness judgment was wrong

The experimental program drifted toward router-policy optimization, route-oracle agreement, topology search, and resource-proxy regret. Those experiments produced useful diagnostics, but they are not sufficient to establish a Real-Time NN.

In particular, high agreement with an analytic resource-cost oracle does not answer the central systems question:

> does a smaller admitted budget cause the **same network** to execute a smaller/faster internal circuit in reality?

The primary readiness criterion must therefore be based on actual conditional execution and actual timing, not router optimality.

## Evidence retained as precursor support

The current repository still establishes several useful ingredients:

1. **Resource-conditioned internal execution:** one fixed parameterized network can execute different internal module sequences when only the resource condition changes.
2. **Inactive-subgraph audit:** forward hooks verify cases where non-selected modules do not execute.
3. **Multiple execution regimes:** finite toy networks can maintain task capability across resource-distinct internal paths.
4. **Capability preservation:** conditional execution can fail by forgetting fallback paths; explicit capability preservation helps.
5. **Conditional-subgraph formation:** supplied primitive supernets can form different hard subgraphs under resource conditions in toy settings.
6. **Runtime feasibility separation:** an external availability constraint can override neural choice.
7. **Timing negative:** ordinary Linux/PyTorch tail measurements are too unstable for WCET/hard-real-time interpretation.
8. **Optimization caution:** learned routing can be sensitive to objective formulation and policy parameterization.

These findings inform implementation of a Real-Time NN, but they do not complete it.

## New primary experiment gate

The next main-line experiment must use **one fixed network** and evaluate several admitted budgets on the same inputs.

For each budget, record:

- active block IDs;
- active channel/neuron counts where applicable;
- execution trace proving inactive modules are skipped;
- actual executed MAC/operation count or another implementation-level work measure;
- end-to-end latency samples;
- accuracy/task score.

The first required result is a reproducible mapping such as:

```text
budget B1 < B2 < B3
    ↓
executed work C1 < C2 < C3
    ↓
measured latency T1 < T2 < T3
```

The exact relation need not be perfectly linear, but it must be monotonic or calibratable enough for runtime admission.

## Runtime integration gate

After the budget/activation/latency relation is established, a runtime experiment should map:

```text
deadline + machine state → admitted budget B
```

and evaluate:

- deadline miss rate;
- task quality;
- chosen activation pattern;
- executed work;
- latency distribution.

The runtime, not the NN, should own hardware-dependent timing knowledge.

## Hard-real-time gate

A true hard-real-time claim remains a later and separate threshold. Ordinary Linux/PyTorch measurements are not WCET.

Hard-real-time readiness would require a defensible bound through static/formal WCET, a time-predictable platform, controlled scheduler/runtime isolation, or another accepted real-time timing argument.

## Router/topology experiments after this correction

Router and topology experiments remain in the repository as **secondary diagnostics**. They should not be presented as the strongest final evidence unless they directly improve or explain the measured budget → activation → latency chain.

Useful questions include:

- does a gating mechanism introduce more overhead than it saves?
- does fine-grained conditional activation actually reduce wall-clock time on the target implementation?
- which activation granularity gives stable timing classes?
- can the runtime predict latency from the selected activation pattern?

Questions such as "which router gives the highest route-oracle agreement?" are secondary unless they affect those systems metrics.

## Readiness criteria for the intended note

A Real-Time NN mechanism note becomes coherent when the repository has, at minimum:

1. same-network budget-conditioned physical execution;
2. measured work reduction/increase across budgets;
3. measured latency reduction/increase across budgets;
4. task-quality trade-off characterization;
5. same-input budget counterfactuals;
6. a simple runtime deadline-to-budget experiment;
7. explicit timing limitations and no WCET overclaim.

Until then, **do not mark the Real-Time NN note as STOP/readiness reached**.

## Recommended framing

The intended architectural motivation is:

**Real-Time Neural Computation: Budget-Conditioned Internal Activation for Predictable Inference Time**

The previous router-heavy framing should be treated as precursor mechanism work, not the project title or endpoint.
