# Real-Time NN direction

## Core research goal

The primary goal of this repository is **not** to optimize a router as an end in itself.

The intended system is a **resource-/budget-conditioned neural network** for real-time systems:

```text
RTOS / runtime
    ↓
deadline + machine state
    ↓
safe compute/time budget B
    ↓
the same neural network parameters
    ↓
B-conditioned internal activation / effective circuit
    ↓
actual executed compute changes
    ↓
actual inference latency changes
    ↓
output before the deadline when the admitted budget is feasible
```

The central experimental question is therefore:

> Holding the task input and network parameters fixed, can changing only the supplied budget/resource condition change which internal computation is physically executed, such that executed work and measured latency change in a predictable direction while useful task quality is retained?

A routing module, gate, mask, or controller may be used as an implementation mechanism, but **router optimization is secondary**. It is not the research target.

## Required evidence for the core claim

The core Real-Time NN claim is not considered demonstrated until one experiment measures all of the following in the same system:

1. **same weights** across all budgets;
2. **same input** in counterfactual budget tests;
3. budget-dependent **active blocks / channels / neurons / edges**;
4. inactive computation is **actually skipped**, not merely multiplied by zero after dense execution;
5. budget-dependent **executed operation count** or another implementation-level compute measure;
6. budget-dependent **measured end-to-end inference latency**;
7. task quality / accuracy under each budget;
8. monotonic or otherwise calibratable relation between budget, executed computation, and latency;
9. a runtime mapping from deadline/machine state to an admitted budget;
10. deadline-miss measurements under that runtime policy.

The intended causal chain is:

```text
budget / resource condition
    → internal activation pattern
    → physically executed compute
    → measured inference latency
    → deadline behavior
```

If an experiment does not test this chain, it is supporting evidence only.

## Primary next experiment

Construct one small fixed-parameter network with budget-conditioned conditional execution at block and/or channel granularity.

For a fixed input `x`, evaluate several budgets `B1 < B2 < ... < Bk` and record:

- active block IDs;
- active channel counts if applicable;
- execution trace from hooks/instrumentation;
- executed MAC/operation proxy;
- wall-clock latency distribution;
- prediction / task score.

The implementation must branch around inactive modules so they are not executed.

The first success criterion is not hard real-time. It is a reproducible relation of the form:

```text
smaller admitted budget
    → smaller executed subgraph
    → less actual executed work
    → lower measured latency
```

with the same network parameters.

## Runtime integration target

The runtime should own hardware-dependent timing information:

```text
hardware / OS state
  ├─ CPU/NPU performance
  ├─ DVFS
  ├─ contention
  ├─ temperature
  └─ timing calibration / WCET information
          ↓
       runtime
          ↓
 normalized safe budget / execution contract
          ↓
         NN
```

The NN should ideally consume a normalized budget/resource contract rather than a hardware model name or raw milliseconds.

For strict hard-real-time claims, measurement-based Linux/PyTorch timing is insufficient. Formal/static WCET, a time-predictable platform, or another defensible timing guarantee would be required.

## Status of existing router/subgraph experiments

Existing lookup-vs-compute, multi-circuit, topology-search, price-conditioned routing, and router-parameterization experiments remain useful **precursor and diagnostic evidence**. They show that resource conditions can alter executed internal paths and expose several optimization failure modes.

They do **not** by themselves establish the Real-Time NN target because most optimize resource proxies or route choice rather than directly demonstrating a budget → physical activation → measured latency → deadline chain.

Accordingly:

- router architecture studies are secondary implementation diagnostics;
- resource-proxy optimality is not the primary Real-Time NN metric;
- the main metric set must include actual executed work and measured latency;
- the repository should not present route-oracle agreement as the strongest final result for the Real-Time NN research goal.

## Explicit nonclaims

Current work does not yet establish:

- hard real-time or WCET guarantees;
- a complete Real-Time NN;
- a Real-Time LM;
- Joule-level energy savings;
- physical memory-bandwidth savings;
- general hardware portability;
- LLM-scale generalization.

## Direction lock

Future experiments should be evaluated first by this question:

> Does this experiment move us closer to controlling **actual neural execution time** by changing the budget of the **same neural network**?

If not, it should be treated as a secondary diagnostic rather than the main research line.
