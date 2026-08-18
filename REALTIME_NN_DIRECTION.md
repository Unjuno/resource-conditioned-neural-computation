# Real-Time NN direction

## Core research goal

The primary goal is a resource-conditioned neural network whose **actual internal execution** changes under a runtime-admitted real-time resource contract. Router quality is secondary.

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
input/state-specific preferred useful compute
    ↓
physical internal execution changes
    ↓
certified target/build-specific timing bound
    ↓
output before the deadline when admission is feasible
```

`b=0` means 0% and `b=1` means 100% of the maximum neural compute envelope. Intermediate values are ordinary continuous percentages at the interface. This does **not** imply continuously interpolated machine instructions: the backend lowers `b` fail-closed to finite physical classes.

## Current preferred runtime contract

```text
continuous runtime budget b ∈ [0,1]
    -> finite maximum admitted physical class
    -> preferred maximum useful compute p(x/state)
    -> deadline-certified maximum class
    -> effective class = minimum of the three ceilings
    -> nested physical execution
```

Budget is a **maximum admissible amount of work**, not an obligation to consume all admitted work. Forced extra computation has already been falsified as universally useful.

## Research-goal status

### Goal A — physical budget-conditioned computation: PASS

The repository supports one fixed NN changing physical depth/width/expert/block execution under resource conditions, including hard physical skip audits and finite work classes.

### Goal B — generalizable adaptive computation: PASS with a temporal-shift boundary

A formal held-out real-sequence experiment treats each handwritten digit as eight row tokens and uses six optional self-attention/MLP blocks with exits. Validation chooses the maximum useful depth; entropy may stop earlier. Test labels are not used for policy fitting.

Across formal seeds 60--64:

- adaptive held-out test accuracy: **93.56%**;
- validation-selected-depth test accuracy: 93.44%;
- average physical compute: **20.23%**;
- capability gain from the 0% exit to useful compute: **+43.83 pp**;
- cap/count violations: 0;
- passing seeds: 5/5.

This establishes an independent-sample real-sequence generalization result.

A separate chronological weekly-CO2 experiment is a negative boundary: validation-tuned stopping reaches 69.08% versus 70.11% full-depth, only 3/5 seeds pass, and useful depth shifts between validation and later test periods. **Temporal/nonstationary distribution-shift robustness remains unresolved.**

### Goal C — hard-real-time RTNN: PARTIAL; hard timing remains UNCERTAIN

The continuous runtime contract is now implemented as Q0.16 in a freestanding C object. Exhaustive audits cover:

- all 65,536 normalized budget values;
- 16,777,216 budget × uint8 preferred-class combinations;
- 655,360 deadline/budget/preferred composition cases.

All contract properties pass, invalid preferred classes fail closed, and the contract object has zero unresolved external symbols. A maximum-work manifest exposes 0/25/50/75/100% ceilings for the existing freestanding core, with exact maximum blocks, MACs, LUT calls, workspace, and allowed nested block IDs.

The deadline admission interface also passes identity and partial-certification properties: wrong build/manifest rejects, and uncertified classes are never inferred or admitted.

However, **hard timing certification is not established**. The exact regenerated neural object was affinity-pinned and measured with `RDTSCP`; class medians scale with physical work, but scheduler/preemption produces multi-million-cycle maxima whose class ordering changes across runs. Calibration maxima are exceeded by held-out measurements, and even arbitrary 2x/4x safety factors are not stable proof. The current environment has no WCET analyzer or time-predictable bare-metal target, and real-time `SCHED_FIFO` privilege is unavailable.

Therefore measurement maxima remain empirical diagnostics, not WCET.

## Required evidence for the full Real-Time NN claim

The complete claim requires all of the following in **one deployed system**:

1. same weights across all budgets;
2. same input in counterfactual budget tests;
3. normalized external budget `b ∈ [0,1]`;
4. budget-dependent active internal computation;
5. inactive computation physically skipped;
6. exact or conservatively bounded work for each finite class;
7. held-out task quality under the budget frontier;
8. target-independent maximum-work manifest;
9. exact deployed build identity;
10. defensible target/compiler/build/RTOS timing upper bound per admitted class;
11. deadline admission and on-time-correct/deadline-miss measurements.

The current evidence does **not** yet satisfy items 9--11 for the same real-data model. The real-sequence model and the existing freestanding timing core are separate artifacts; cross-backend lowering of the exact real-sequence model remains an integration step.

## Current negative boundaries

Retain these as first-class results:

- Linux P95/P99 is not a hard real-time admission contract;
- observed maximum latency/cycles, even multiplied by an arbitrary safety factor, is not a certified upper bound;
- nominal MAC reduction does not guarantee wall-clock reduction on every backend;
- forcing exact admitted work can reduce task quality;
- additive logit refinement gave no matched advantage;
- concurrent preferred-compute optimization missed the stable-frontier baseline;
- toy held-out horizon-value prediction failed;
- chronological temporal distribution shift remains unresolved even though independent-sample real-sequence generalization passes.

## Immediate priorities

1. **Concrete hard-timing target:** run the finite-class binary on a time-predictable target or with a defensible WCET/static timing analyzer under fixed compiler, memory/cache, interrupt, DMA, and scheduling assumptions.
2. **Same-model integration:** lower the exact real-sequence model and its maximum-useful-depth/early-exit policy into the freestanding boundary, then require Python/C prediction, exit, and work-class equality.
3. **Final RTOS experiment:** only after the same deployed model has defensible `T_j` bounds, evaluate deadline miss, on-time correct, admitted `b`, effective compute, actual cycles, and bound slack.
4. **Temporal-shift research:** treat nonstationary time-series depth-utility drift as a separate generalization problem rather than silently merging it into the independent-sample PASS.
5. Larger language-model-scale work remains downstream of these items.

## Explicit nonclaims

Current work does not establish:

- hard real-time or WCET guarantees;
- a complete production Real-Time NN;
- a single same-model chain from real-data generalization through certified timing;
- temporal distribution-shift robustness;
- a Real-Time LM or LLM-scale generalization;
- universal wall-clock benefit from nominal compute reduction;
- arbitrary hardware/timing portability.

## Direction lock

Future main-line experiments should answer:

> Does this move the **same neural model** closer to controllable physical execution under `b ∈ [0,1]`, a finite maximum-work envelope, and a defensible deadline guarantee?

If not, it is secondary diagnostics.
