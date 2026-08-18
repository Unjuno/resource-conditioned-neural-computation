# Real-Time NN direction

## Core research goal

The primary goal of this repository is **not** to optimize a router as an end in itself.

The intended system is a resource-conditioned neural network whose **actual internal execution** changes under a runtime-admitted real-time resource contract:

```text
RTOS / runtime
    ↓
deadline + machine state
    ↓
normalized safe compute budget b ∈ [0,1]
    ↓
largest certified finite maximum-work class <= b
    ↓
the same neural-network parameters
    ↓
input/state-specific preferred compute inside the admitted cap
    ↓
physical internal execution changes
    ↓
certified target-specific timing bound
    ↓
output before the deadline when admission is feasible
```

The external control coordinate is now deliberately normalized:

- `b = 0` means 0% of the maximum admitted neural compute envelope;
- `b = 1` means 100%;
- intermediate values are ordinary continuous percentages.

This is an **interface contract**, not a claim that machine instructions vary continuously. An analyzable implementation may lower continuous `b` fail-closed to a finite set of certified physical execution classes.

The central experimental question is:

> Holding the task input and network parameters fixed, can changing only the normalized runtime budget change which internal computation is physically executed, such that useful quality/work trade-offs are obtained while the physical path stays inside a finite certifiable maximum-work envelope?

A routing module, gate, mask, stopping policy, or value predictor may be used as an implementation mechanism, but these are secondary to the physical execution contract.

## Current preferred runtime contract

The latest sequence results support the following design:

```text
continuous runtime budget b ∈ [0,1]
    -> finite maximum admitted physical class
    -> input-dependent, budget-independent nested block ranking
    -> preferred compute p(x/state) ∈ [0,1]
    -> effective compute e = min(p, admitted cap)
    -> physical execution subset
```

The preferred compute value is represented externally as a normalized fraction/percentage even when the backend implements it with finite work classes.

The budget is a **maximum admissible amount of work**, not an obligation to consume all admitted work. Forced extra computation has already been falsified as universally useful in the causal sequence task.

## Required evidence for the full Real-Time NN claim

The complete claim requires evidence for all of the following in one system:

1. **same weights** across all budgets;
2. **same input** in counterfactual budget tests;
3. normalized external budget `b ∈ [0,1]`;
4. budget-dependent active blocks/channels/experts/edges;
5. inactive computation is **actually skipped**, not merely zero-masked after dense execution;
6. exact or conservatively bounded implementation-level work for every admitted physical class;
7. task quality under the budget frontier;
8. finite target-independent execution classes/manifests;
9. target/compiler/build/RTOS-specific safe timing bound for each admitted class;
10. runtime mapping from remaining deadline/machine state to `b` or its admitted physical ceiling;
11. deadline-miss/on-time-correct measurements under that policy.

The intended causal chain is:

```text
normalized budget b
    → admitted finite physical envelope
    → internal activation / stopping
    → physically executed compute
    → certified timing bound
    → deadline behavior
```

## What is already supported

On the supplied toy and causal-sequence experiments, the repository already supports:

- one fixed NN executing different physical depths under different budgets;
- structured active width with a backend-dependent physical speedup boundary;
- sparse expert-width and transformer-like conditional computation;
- input-dependent non-prefix nested routing;
- joint all-class training as a strong protection against capability regression;
- budget-as-cap semantics rather than exact-work semantics;
- fine-grained finite classes;
- continuous normalized external budgets lowered to finite physical classes;
- stable-frontier horizon-value stopping that improves the supplied full-fit sequence quality/work frontier;
- generated/freestanding integer backends, fixed workspaces, numeric-range audits, cross-ISA compile audits, execution manifests, and build-bound timing-certificate interfaces.

These are mechanism and analyzable-implementation results. They are **not WCET** and do not yet establish a production Real-Time NN.

## Current negative boundaries

The repository also retains several important falsifications:

- ordinary Linux P95/P99 timing is not a hard real-time admission contract;
- nominal MAC reduction does not guarantee lower wall-clock latency on every backend;
- forcing the admitted exact work can reduce task quality;
- additive logit refinement did not improve the matched monotonicity audit;
- concurrent preferred-compute optimization (straight-through, relaxed, and online-decoupled variants) missed the stable post-trained frontier;
- the current horizon-value predictor does **not** generalize under the supplied 4-fold held-out-prompt audit.

## Runtime integration target

Hardware-dependent timing information belongs to the runtime/certification side:

```text
hardware / OS state
  ├─ CPU/NPU performance
  ├─ DVFS
  ├─ contention/interference assumptions
  ├─ temperature/clock assumptions
  └─ target/compiler/build-specific timing certification
          ↓
       runtime
          ↓
 normalized safe budget b ∈ [0,1]
          ↓
 finite certified maximum-work class
          ↓
         NN
```

The NN should consume the normalized budget rather than a hardware model name or raw milliseconds. For strict hard-real-time claims, measurement-based Linux/PyTorch timing is insufficient; a defensible WCET/static bound, time-predictable platform, or equivalent target-specific guarantee is required.

## Immediate research priorities

1. Test the normalized-budget/horizon-value mechanism on a **real temporal dataset with genuine train/test separation**. The held-out value-generalization failure is now the main ML uncertainty.
2. Lower `b ∈ [0,1]` plus finite maximum-work semantics into the latest generated/freestanding backend and expose normalized class fractions in the execution manifest.
3. Attach target/compiler/build-specific timing bounds to those finite classes on one controlled target.
4. Integrate runtime deadline admission and measure deadline/on-time-correct behavior.
5. Only after those steps should the work expand to larger language-model-scale systems.

## Explicit nonclaims

Current work does not yet establish:

- hard real-time or WCET guarantees;
- a complete production Real-Time NN;
- a Real-Time LM or LLM-scale generalization;
- held-out/general value-of-computation prediction;
- Joule-level energy savings;
- universal wall-clock benefit from nominal compute reduction;
- arbitrary hardware/timing portability.

## Direction lock

Future experiments should be evaluated first by this question:

> Does this experiment move us closer to controlling **actual neural execution time** through the normalized budget of the **same neural network**, while preserving a finite certifiable physical execution envelope?

If not, it belongs under secondary diagnostics.
