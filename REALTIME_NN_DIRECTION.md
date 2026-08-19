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
target/build-specific timing binding
    ↓
output before the deadline when admission is feasible
```

`b=0` means 0% and `b=1` means 100% of the maximum neural compute envelope. Intermediate values are continuous percentages at the interface; the backend lowers them fail-closed to finite physical classes. Budget is a maximum admissible amount of work, not an obligation to consume all admitted work.

## Research-goal status

### Goal A — physical budget-conditioned computation: PASS

One fixed NN can physically change depth/width/expert/block execution under resource conditions with hard skip audits and finite work classes.

### Goal B — generalizable adaptive computation: PASS with a temporal-shift boundary

On held-out handwritten-digit row sequences, formal seeds 60--64 reach **93.56%** adaptive test accuracy at **20.23%** average physical compute, with 5/5 passing seeds and zero cap/count violations. A separate chronological weekly-CO2 task remains a negative boundary: temporal/nonstationary depth utility shifts between validation and later test periods.

### Goal C — same-model integration PASS; pinned RTL validation reached

The same real-data path now connects:

```text
real held-out model
    -> Q15 fixed-iteration model/policy
    -> freestanding integer C
    -> continuous b in [0,1]
    -> budget/deadline ceiling
    -> preferred early stopping
    -> nested physical execution
    -> maximum-work manifest
    -> pinned Ibex RTL timing binding
    -> deadline admission
```

The five-seed Q15 reference has 0/12,600 exit-prediction mismatches and 1/1,800 preferred-exit mismatches versus float. Representative seed 63 integer C has 0/2,520 exit-prediction mismatches and 0/360 preferred-exit mismatches. The final Cortex-M4 and RV32 analysis cores eliminate unresolved runtime arithmetic helpers, floating-point operations, and hardware DIV/REM from the neural numeric path.

The previous custom arithmetic processor model, `RTNN-IBEX-DIT-v1`, is now a **negative result**: actual pinned Ibex RTL exceeded that arithmetic cycle estimate for every full-work certification class. It must not be used for admission.

The current RTL experiment pins upstream Ibex commit `7b5df75a041affe56e8c235260f98a09b3319008` and uses the official Simple System with `SecureIbex=1` (which enables the internal data-independent timing path in this revision), `RV32MSingleCycle`, two-stage execution, no I-cache/branch predictor, and deterministic one-cycle Simple System RAM with zero additional instruction delay.

A strengthened RTL audit runs every one of the seven fixed classes on three distinct held-out inputs with preferred depths 1, 3, and 5. In the derivation run, all 21 fixed-class predictions match the native integer reference and every class has **zero input-to-input cycle range**. The resulting exact-build certification counts are:

| external class ceiling | fixed-class RTL cycles |
|---:|---:|
| 0% | 29,620 |
| 16.7% | 615,569 |
| 33.3% | 1,201,521 |
| 50% | 1,787,473 |
| 66.7% | 2,373,425 |
| 83.3% | 2,959,377 |
| 100% | 2,959,381 |

The admission + real adaptive-inference maximum-work envelope is:

| external class ceiling | admission + adaptive RTL cycles |
|---:|---:|
| 0% | 29,843 |
| 16.7% | 657,454 |
| 33.3% | 1,285,058 |
| 50% | 1,912,662 |
| 66.7% | 2,540,266 |
| 83.3% | 3,167,870 |
| 100% | 3,167,870 |

The 100% class shares the deployed runtime envelope of the 83.3% class because the validated preferred maximum is exit 5/6. A full resource grant does not force useless extra work.

The exact timing table is **build-specific**. Strengthening only the harness changed every fixed-class count by exactly one cycle, while the three inputs still remained identical. This confirms that timing evidence must be bound to the exact frozen Q15 artifact, exact machine image, compiler/toolchain, RTL commit, and RTL configuration rather than to a training seed or a portable cycle formula.

## Artifact identity policy

The first RTL CI attempt also exposed a separate reproducibility boundary: retraining seed 63 on a GitHub runner did not reproduce the earlier local Q15 SHA bit-for-bit. Therefore:

- **research reproducibility** uses seed + training recipe and is judged statistically;
- **timing certification** uses a frozen Q15 artifact and exact machine-image hashes.

Every RTL evidence artifact records the Q15 canonical/header hashes plus ELF/binary hashes.

## Required evidence for a full production hard-real-time claim

The research path demonstrates items 1--9 and the RTL/software portion of 10--11 below:

1. same neural model across budgets;
2. same input in counterfactual budget tests;
3. continuous external `b ∈ [0,1]`;
4. budget-dependent physical internal computation;
5. inactive compute physically skipped;
6. finite maximum-work classes;
7. held-out task quality under the budget frontier;
8. target-independent maximum-work manifest;
9. exact deployed artifact/build identity;
10. target/build-specific timing upper bound;
11. deadline admission and on-time-correct evidence.

The pinned RTL experiment substantially strengthens item 10 over Linux timing and over the rejected arithmetic model. It is still **not** an FPGA/ASIC/silicon production WCET certificate. A different physical implementation, memory system, interrupt/DMA policy, compiler, RTL revision, or processor configuration requires its own timing evidence.

## Current negative boundaries

Retain these as first-class results:

- Linux P95/P99 or observed-max × arbitrary margin is not a hard admission contract;
- the old arithmetic `RTNN-IBEX-DIT-v1` cycle formula is falsified by actual pinned Ibex RTL;
- a training seed is not a bitwise certification artifact identity;
- nominal MAC reduction does not guarantee wall-clock reduction on every backend;
- forcing exact admitted work can reduce task quality;
- concurrent preferred-compute optimization missed the stable-frontier baseline;
- toy held-out horizon-value prediction failed;
- chronological temporal distribution shift remains unresolved.

## Immediate priorities

1. Keep RTL timing evidence bound to the exact frozen Q15 artifact and machine image; any changed build requires revalidation.
2. If production hard-real-time deployment is required, reproduce the validated binding on an FPGA/ASIC or apply an accepted WCET/static timing methodology to the same target configuration.
3. Extend compiled/timing deployment across additional formal seeds only if cross-seed deployment robustness is required.
4. Treat chronological/nonstationary temporal generalization as a separate ML-side problem.
5. Larger LM-scale work remains downstream of the target-certification question.

## Explicit nonclaims

Current work does **not** establish:

- a universal Ibex WCET theorem;
- an FPGA/ASIC/silicon production WCET guarantee;
- arbitrary hardware/timing portability;
- temporal distribution-shift robustness;
- an LLM-scale real-time generalization.

The RTL timing binding is valid only for the explicitly pinned simulation configuration and exact build evidence to which it is attached.

## Direction lock

Future main-line experiments should answer:

> Does this move the **same neural model** closer to controllable physical execution under `b ∈ [0,1]`, a finite maximum-work envelope, and a defensible deadline guarantee?

If not, it is secondary diagnostics.
