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

`b=0` means 0% and `b=1` means 100% of the maximum neural compute envelope. Intermediate values are continuous percentages at the interface; the backend lowers them fail-closed to finite physical classes.

## Current preferred runtime contract

```text
continuous runtime budget b ∈ [0,1]
    -> finite maximum admitted physical class
    -> preferred maximum useful compute p(x/state)
    -> deadline-certified maximum class
    -> effective class = minimum of the three ceilings
    -> nested physical execution
```

Budget is a **maximum admissible amount of work**, not an obligation to consume all admitted work.

## Research-goal status

### Goal A — physical budget-conditioned computation: PASS

One fixed NN can physically change depth/width/expert/block execution under resource conditions with hard skip audits and finite work classes.

### Goal B — generalizable adaptive computation: PASS with a temporal-shift boundary

On held-out handwritten-digit row sequences, formal seeds 60--64 reach **93.56%** adaptive test accuracy at **20.23%** average physical compute, with 5/5 passing seeds and zero cap/count violations. A separate chronological weekly-CO2 task remains a negative boundary: temporal/nonstationary depth utility shifts between validation and later test periods.

### Goal C — same-model integration PASS; conditional static timing now exists

The exact real-data sequence model is already connected through:

```text
real held-out model
    -> generated static model/policy
    -> same-model freestanding C
    -> continuous budget
    -> preferred early stopping
    -> maximum-work manifest
    -> deadline admission interface
```

The float same-model path has 0/12,600 finite-exit prediction mismatches and 0/1,800 preferred-exit mismatches across seeds 60--64.

The latest hard-timing audit adds a **Q15 fixed-iteration path**:

- five-seed Q15 reference: 0/12,600 exit-prediction mismatches and 1/1,800 preferred-exit mismatches versus float;
- representative seed 63 integer C: 0/2,520 exit-prediction mismatches and 0/360 preferred-exit mismatches;
- fixed 64-iteration integer division, fixed 32-iteration integer square root, integer exp/GELU LUTs;
- data-dependent numerical select/max operations lowered through explicit mask/select helpers;
- final Cortex-M4 soft-float object: zero unresolved external symbols, zero floating-point instructions, zero hardware divide instructions;
- RV32IM analysis build: no DIV/REM or floating-point instructions.

The certification path forces execution to the admitted maximum class while retaining the entropy-evaluation overhead. Four distinct held-out inputs have identical RV32 dynamic instruction-category counts for every class.

Under the explicit conditional processor/memory model `RTNN-IBEX-DIT-v1` (RV32IM, Ibex-style `DataIndTiming`, single-cycle multiplier, aligned zero-wait SRAM, no cache/interrupt/DMA/debug/bus contention), the total admission + worst adaptive-inference envelopes are:

| external ceiling | conditional total upper cycles |
|---:|---:|
| 0% | 22,180 |
| 16.7% | 549,778 |
| 33.3% | 1,077,368 |
| 50% | 1,604,958 |
| 66.7% | 2,132,548 |
| 83.3% | 2,660,139 |
| 100% | 2,660,140 |

A fixed-point 360 × 21-budget × 7-deadline audit gives 52,920 cases with zero admission, executed-exit, prediction, or cap mismatches. Partial certification and wrong model/build identity fail closed.

This is a meaningful advance over Linux timing: it is a finite **static conditional timing model**, not an empirical percentile or observed-maximum margin.

However, it is still **not a physical-device WCET certificate**. No matching Ibex RTL simulation, FPGA/ASIC run, or accepted target WCET analyzer was available in-session. The custom RV32 instruction interpreter is an audit tool, not a formal ISA/RTL proof.

## Required evidence for the full Real-Time NN claim

A complete deployed hard-real-time claim requires:

1. same weights across all budgets;
2. same input in counterfactual budget tests;
3. normalized external budget `b ∈ [0,1]`;
4. budget-dependent physical internal computation;
5. inactive computation physically skipped;
6. exact or conservatively bounded work per finite class;
7. held-out task quality under the budget frontier;
8. target-independent maximum-work manifest;
9. exact deployed build identity;
10. defensible target/compiler/build/RTOS timing upper bound per admitted class;
11. deadline admission and on-time-correct/deadline-miss evidence.

Items 1--9 and the software/interface part of 11 are demonstrated on the same real-data path. Item 10 now has a **conditional processor-model candidate**, but still requires RTL/physical/static-analyzer validation before becoming a deployed timing certificate. A hard interpretation of item 11 depends on that validation.

## Current negative boundaries

Retain these as first-class results:

- Linux P95/P99 is not a hard real-time admission contract;
- observed maximum latency/cycles, even multiplied by an arbitrary safety factor, is not a certified upper bound;
- an early integer Cortex-M4 build still contained `__aeabi_uldivmod`; it was rejected and replaced by fixed restoring division;
- nominal MAC reduction does not guarantee wall-clock reduction on every backend;
- forcing exact admitted work can reduce task quality;
- concurrent preferred-compute optimization missed the stable-frontier baseline;
- toy held-out horizon-value prediction failed;
- chronological temporal distribution shift remains unresolved.

## Immediate priorities

1. **Validate the conditional timing model on a matching target.** Run the exact Q15 RV32IM build on Ibex RTL/FPGA/ASIC with `DataIndTiming`, the selected multiplier configuration, controlled SRAM latency, and interrupts/DMA/interference disabled, or apply an accepted WCET/static timing analyzer.
2. Compare every measured/analyzed class against the conditional envelope. If any class exceeds it, identify the failed pipeline/memory/integration assumption and revise the target binding rather than adding empirical margin.
3. If the model survives, issue the exact target/build-specific `T_j` table and run the final certified deadline/on-time-correct experiment.
4. Extend the integer deployment audit across all five formal seeds if cross-seed compiled deployment robustness is needed.
5. Treat temporal distribution shift as a separate ML-side problem; larger LM-scale work remains downstream of physical-target timing validation.

## Explicit nonclaims

Current work does **not** establish:

- a physical-device or production WCET guarantee;
- a complete production hard-real-time RTNN;
- temporal distribution-shift robustness;
- arbitrary hardware/timing portability;
- a Real-Time LM or LLM-scale generalization.

The `RTNN-IBEX-DIT-v1` table is valid only as a conditional upper-bound model under its explicit assumptions until independent RTL/target validation is obtained.

## Direction lock

Future main-line experiments should answer:

> Does this move the **same neural model** closer to controllable physical execution under `b ∈ [0,1]`, a finite maximum-work envelope, and a defensible deadline guarantee?

If not, it is secondary diagnostics.
