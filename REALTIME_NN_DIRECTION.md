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

### Goal C — same-model integration PASS; hard timing remains UNCERTAIN

The exact real-data sequence model has now been lowered to a generic freestanding C core.

Across seeds 60--64:

- **12,600 / 12,600** finite-exit held-out predictions match PyTorch;
- **1,800 / 1,800** preferred-exit decisions match PyTorch;
- all five freestanding core objects have zero unresolved external symbols.

For representative seed 63, the same deployed model additionally passes:

- 7,560 held-out sample × continuous-budget cases with zero prediction/executed-exit/cap mismatches;
- 52,920 held-out sample × budget × deadline-contract cases with zero admission/executed-exit/prediction mismatches;
- partial-certification fail-closed behavior;
- wrong build and wrong manifest rejection;
- combined freestanding core + runtime contract with zero unresolved external symbols;
- freestanding Clang compilation for ARMv7-M, RV32, and AArch64 targets.

The seed-63 export emits a target-independent maximum-work manifest with seven normalized classes, a 4,608-byte caller-owned workspace, explicit maximum structural work, and `target_timing_bounds = null`.

The earlier integration gap is therefore closed:

```text
real held-out model
    -> generated weights / policy / LUTs
    -> same-model freestanding C
    -> continuous budget
    -> preferred early stopping
    -> maximum-work manifest
    -> deadline admission interface
```

**Hard timing certification is still not established.** The exact seed-63 adaptive binary was CPU-affinity pinned and measured with `RDTSCP`; across 15 timing runs, later observed maxima reach about **12.50×** the first calibration maximum, and even `observed max × 8` is exceeded for multiple classes. The current environment has no WCET analyzer, no time-predictable bare-metal execution target, and no permission for `SCHED_FIFO`.

Therefore Linux observed maxima remain empirical diagnostics, not WCET.

An empirical RTOS-style same-model demonstrator is also implemented. It shows that deadline admission changes physical compute and can improve on-time-correct behavior versus always-full execution in several deadline regimes, but its P99 timing table is deliberately not promoted to a hard real-time guarantee.

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

Items 1--9 and the software/interface part of item 11 are now demonstrated for the same real-data model path. **Item 10 is the principal missing proof**, and a hard interpretation of item 11 depends on it.

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

1. **Concrete hard-timing target:** run the same exported real-data model/build on a time-predictable target or with a defensible WCET/static timing analyzer under fixed compiler, memory/cache, interrupt, DMA, and scheduling assumptions.
2. **Certified final RTOS experiment:** populate the timing binding only from defensible bounds for that exact build, then measure deadline misses, on-time correct, admitted class, effective compute, actual cycles, and bound slack.
3. **Temporal-shift research:** treat nonstationary time-series depth-utility drift as a separate generalization problem rather than silently merging it into the independent-sample PASS.
4. Larger language-model-scale work remains downstream of these items.

## Explicit nonclaims

Current work does not establish:

- hard real-time or WCET guarantees;
- a complete production Real-Time NN;
- temporal distribution-shift robustness;
- a Real-Time LM or LLM-scale generalization;
- universal wall-clock benefit from nominal compute reduction;
- arbitrary hardware/timing portability.

## Direction lock

Future main-line experiments should answer:

> Does this move the **same neural model** closer to controllable physical execution under `b ∈ [0,1]`, a finite maximum-work envelope, and a defensible deadline guarantee?

If not, it is secondary diagnostics.
