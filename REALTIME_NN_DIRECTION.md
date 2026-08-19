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

### Goal C — same-model integration PASS; pinned RTL + independent binary control-flow evidence + formal deployed control reached

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
    -> exact-RV32 custom noninterference audit
    -> third-party BINSEC fixed-class control-flow cross-check
    -> CBMC finite runtime-contract proof
    -> CBMC proof of mechanically extracted deployed control bodies
    -> deadline admission
```

The five-seed Q15 reference has 0/12,600 exit-prediction mismatches and 1/1,800 preferred-exit mismatches versus float. Representative seed 63 integer C has 0/2,520 exit-prediction mismatches and 0/360 preferred-exit mismatches. The final Cortex-M4 and RV32 fixed-class analysis cores eliminate unresolved runtime arithmetic helpers, floating-point operations, and hardware DIV/REM from the neural numeric path.

The previous custom arithmetic processor model, `RTNN-IBEX-DIT-v1`, is a **negative result**: actual pinned Ibex RTL exceeded that arithmetic cycle estimate for every full-work certification class. It must not be used for admission.

The RTL experiment pins upstream Ibex commit `7b5df75a041affe56e8c235260f98a09b3319008` and uses the official Simple System with `SecureIbex=1` (which enables the internal data-independent timing path in this revision), `RV32MSingleCycle`, two-stage execution, no I-cache/branch predictor, and deterministic one-cycle Simple System RAM with zero additional instruction delay.

A strengthened RTL audit runs every one of the seven fixed classes on three distinct held-out inputs with preferred depths 1, 3, and 5. All 21 fixed-class predictions match the native integer reference and every class has **zero input-to-input cycle range**. The exact-build measured certification counts are:

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

The exact timing table is **build-specific**. Strengthening only the harness changed every fixed-class count by exactly one cycle while the three inputs still remained identical. Timing evidence therefore binds the frozen Q15 artifact, exact machine image, compiler/toolchain, RTL commit, and RTL configuration rather than a training seed or portable cycle formula.

## Exact-binary software timing audit

The same exact ELF/bin used in the RTL evidence was audited with a custom RV32IM taint interpreter. All 64 neural input bytes are tainted and taint is propagated through registers and memory.

For every fixed class `0..6`:

- neural-input-dependent conditional branches: **0**;
- neural-input-dependent indirect-control targets: **0**;
- neural-input-dependent store addresses: **0**;
- hardware DIV/REM instructions on the fixed-class path: **0**.

Exactly four load instruction sites have input-dependent addresses: `0x1002ec`, `0x1002f0`, `0x10152c`, and `0x101530`. They are exp/GELU LUT interpolation reads. The complete post-clamp Q15 index domains were enumerated and remain inside `fx_exp_lut[8193]` and `fx_gelu_lut[4097]`.

This gives a structural explanation for the observed fixed-class RTL cycle invariance **under the pinned memory model**: hidden neural-input-dependent machine-code branching was not found, while the remaining input-dependent addresses access deterministic address-independent Simple System RAM. The same statement does not transfer to a cache, external SDRAM, arbitration fabric, or another memory implementation without a new analysis.

The adaptive `rtnn_fixed_infer_budget` path is intentionally different. Across held-out inputs whose preferred exits are 1, 3, and 5, all neural-input-dependent conditional-control events localize to a single machine-code site, `0x101848`, the entropy early-stop decision. There is no input-dependent indirect control or store address. The wrapper contains one `DIVU` for public Q16 budget lowering; the fixed-class certification path contains none. Under the pinned `SecureIbex=1` configuration, the divider's early completion is disabled by the data-independent timing mode.

The custom taint interpreter is **not formally verified**. Its instruction semantics were cross-checked on six embedded held-out vector/class cases with 0 prediction mismatches and a synthetic known-tainted-branch negative control that the analyzer correctly detects. Therefore this evidence is `PASS_WITH_SCOPE`, not a WCET theorem.

## Third-party BINSEC control-flow cross-check

To reduce dependence on the custom interpreter, the same exact RTL-tested RV32 ELF was analyzed independently with BINSEC `checkct` using all 64 neural input bytes as secret data.

The final all-class run pins BINSEC image `binsec/binsec@sha256:2a51e455f055874d71cbf030a778e8be19455876bcd57c1845c163fed6fc482f` (version `dfe4739`) and enables the control-flow feature while disabling the chosen-value and relational checkct engines. BINSEC SSE still performs complete path execution/feasibility for the fixed class.

Across classes `0..6`:

- classes passed: **7/7**;
- one completed path per class;
- pending paths: **0**;
- discontinued paths: **0**;
- `Program status: secure` for every class;
- control-flow leak sites: **0**;
- control-flow checks: **933,653 / 933,653**;
- unrolled instructions explored: **9,176,039**;
- branching points: **574,502**.

This independently corroborates the fixed-class machine-code control-flow noninterference result and removes the custom interpreter as the sole evidence for that property.

A generic full constant-time smoke test is kept as a negative/resource boundary. Class 0 completes with both control-flow and memory-access checks secure. Class 1 exits `137` on the supplied GitHub runner when relational memory-address analysis is enabled over the LUT-heavy network. The same class-1 path completes under control-flow-only analysis and passes 47,971/47,971 flow checks. Therefore the resource failure is **not** interpreted as a control-flow failure or silently promoted to a memory proof.

The known input-indexed exp/GELU LUT addresses remain a separate timing-model obligation. They are compatible with the pinned deterministic address-independent RAM, but a cache, external SDRAM, arbitration fabric, or another memory implementation needs a new proof or target-specific bound.

## CBMC finite software-contract proof

CBMC 6.10.0 checks the finite runtime contract over complete integer domains. The proof directly links the repository's actual `rtnn_fixed_admit_total_cycles()` implementation.

The five proof entry points all report `VERIFICATION SUCCESSFUL`:

1. **continuous Q0.16 budget lowering** — in-range, monotone, fail-closed, greatest-fit for arbitrary budgets;
2. **actual deadline admission** — for every 32-bit deadline, the returned RTL-bound class fits and no higher class fits; wrong model/build IDs and null binding fail closed;
3. **partial certification** — for arbitrary seven-entry timing tables, un-certified `UINT32_MAX` entries are never admitted, and no higher certified class that fits is skipped;
4. **effective execution** — for all budgets, deadlines, and preferred exits `0..5`, execution remains below budget, deadline, preference, and policy ceilings, with the committed RTL bound still within the admitted deadline;
5. **Q15 LUT indices** — arbitrary signed 32-bit inputs remain in the finite exp/GELU table domains after the exact clamp/index arithmetic.

This is a formal result for the represented finite C/runtime contract. It does **not** prove the whole neural arithmetic, compiler preservation, Ibex pipeline, or physical device timing.

## CBMC proof of actual deployed control bodies

A second CBMC experiment removes the remaining source-model duplication for the neural execution-control path. A deterministic extractor reads `realtime_nn_real_sequence_fixed_core.c` and copies the exact function bodies for:

- `rtnn_fixed_budget_ceiling_q16()`;
- `rtnn_fixed_infer_budget()`;
- `rtnn_fixed_certify_class()`.

The extraction records the full deployed-core SHA and each function-body SHA. Neural numerical kernels are replaced only for this control proof: `entropy10()` is nondeterministic, while `run_block()` is instrumented as the physical optional-block call. Consequently, every possible continue/stop decision sequence is included rather than only observed entropy outcomes.

CBMC 6.10.0 proves all four entry points with bounds/pointer/signed-overflow/divide-by-zero checks and loop unwinding assertions:

1. **actual deployed Q0.16 lowering** — in-range, monotone, fail-closed, greatest-fit for every ordered `uint16_t` budget pair;
2. **actual adaptive physical-call cap** — for every `uint16_t` budget, every `uint8_t` deadline-class input, and every possible entropy outcome, optional `run_block()` calls remain canonical and do not exceed `min(budget ceiling, normalized deadline, policy max exit)`; reported `executed` equals the physical call count; invalid deadline values `>6` fail closed to zero blocks;
3. **NULL executed-output path** — passing `executed == NULL` cannot bypass the cap or canonical order;
4. **actual fixed-class certification work** — every `uint8_t` class input is normalized fail-closed, capped by deployed policy maximum exit 5, and executes exactly the resulting optional-block count in canonical order.

The final documented PR head was re-proved by workflow run `32222548911`; extraction plus all four proof steps completed successfully.

This closes the source-level finite-control modeling gap more strongly than a hand-copied model. It still abstracts neural numerical arithmetic and does **not** prove compiler preservation, the complete compiled neural machine code, Ibex pipeline timing, or physical-device WCET. Those remain separate binary/RTL/target evidence layers.

## Artifact identity policy

The first RTL CI attempt exposed a reproducibility boundary: retraining seed 63 on a GitHub runner did not reproduce the earlier local Q15 SHA bit-for-bit. Therefore:

- **research reproducibility** uses seed + training recipe and is judged statistically;
- **timing certification** uses a frozen Q15 artifact and exact machine-image hashes.

Every RTL/noninterference evidence artifact records or checks the exact Q15/build identity. The retained Actions artifact is supporting evidence rather than a durable production artifact archive; long-term certification should freeze the exact ELF/bin in a durable release/archive with the same hashes.

## Required evidence for a full production hard-real-time claim

The research path demonstrates items 1--9 and strong target-specific/software evidence for 10--11 below:

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

Pinned RTL measurement, two independent fixed-class machine-code control-flow audits, CBMC verification of the finite software admission/cap contract, and CBMC proof of the mechanically extracted deployed neural-control bodies substantially strengthen items 10--11 over Linux timing and the rejected arithmetic model. They are still **not** an FPGA/ASIC/silicon production WCET certificate or a complete formal proof of compiler preservation plus target memory/processor physical timing. A different physical implementation, memory system, interrupt/DMA policy, compiler, RTL revision, or processor configuration requires new timing evidence.

## Current negative boundaries

Retain these as first-class results:

- Linux P95/P99 or observed-max × arbitrary margin is not a hard admission contract;
- the old arithmetic `RTNN-IBEX-DIT-v1` cycle formula is falsified by actual pinned Ibex RTL;
- a training seed is not a bitwise certification artifact identity;
- the custom taint interpreter is useful but is no longer the sole fixed-class control-flow evidence;
- BINSEC generic full relational memory checking for class 1 exceeds the supplied runner resources; this is not a control-flow failure;
- CBMC proof of deployed source control does not by itself prove compiler preservation, full neural machine code, processor RTL, or physical timing;
- input-dependent LUT addresses are timing-benign only under the explicitly modeled deterministic memory behavior;
- nominal MAC reduction does not guarantee wall-clock reduction on every backend;
- forcing exact admitted work can reduce task quality;
- concurrent preferred-compute optimization missed the stable-frontier baseline;
- toy held-out horizon-value prediction failed;
- chronological temporal distribution shift remains unresolved.

## Immediate priorities

1. Close the remaining **memory/compiler/target timing gap** rather than adding more input samples: bind the four input-indexed LUT accesses to the selected deterministic on-chip memory and strengthen source↔compiled-binary/processor timing correspondence where production proof requires it.
2. When physical validation is desired, use the available DE0-CV with controlled on-chip memory and a fixed clock; derive a new FPGA-specific timing binding instead of copying the Simple System table.
3. Freeze the exact certification ELF/bin in a durable artifact location with their recorded hashes before treating the evidence as long-lived deployment certification.
4. Extend compiled/timing deployment across additional formal seeds only if cross-seed compiled deployment robustness is required.
5. Treat chronological/nonstationary temporal generalization as a separate ML-side problem; larger LM-scale work remains downstream of the target-certification question.

## Explicit nonclaims

Current work does **not** establish:

- a universal Ibex WCET theorem;
- generic constant-time memory behavior for arbitrary memory hierarchies;
- an FPGA/ASIC/silicon production WCET guarantee;
- arbitrary memory/hardware timing portability;
- temporal distribution-shift robustness;
- an LLM-scale real-time generalization.

The current RTL timing binding, custom/BINSEC control-flow evidence, CBMC finite runtime-contract proof, and deployed source-control proof are valid only within their explicitly stated artifact and model boundaries.

## Direction lock

Future main-line experiments should answer:

> Does this move the **same neural model** closer to controllable physical execution under `b ∈ [0,1]`, a finite maximum-work envelope, and a defensible deadline guarantee?

If not, it is secondary diagnostics.
