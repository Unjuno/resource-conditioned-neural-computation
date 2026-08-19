# Real-Time NN direction

## Core research goal

The primary goal is a resource-conditioned neural network whose **actual internal execution** changes under a runtime-admitted real-time resource contract. Router/gate quality is secondary unless it fixes a concrete failure in the physical execution and deadline chain.

```text
RTOS / runtime
    ↓
remaining deadline + bounded target state
    ↓
normalized safe compute budget b ∈ [0,1]
    ↓
largest certified finite maximum-work class <= b
    ↓
the same neural-network parameters
    ↓
input/state-specific preferred useful compute p(x,s)
    ↓
effective work e = min(b,p)
    ↓
physical internal execution
    ↓
target/build-specific timing binding
    ↓
deadline admission
```

`b=0` means 0% and `b=1` means 100% of the normalized neural compute envelope. Intermediate values are continuous percentages at the public interface; an analyzable backend lowers them fail-closed to finite physical classes. Budget is a **maximum admissible amount of work**, not an obligation to consume all admitted work.

Current finite fractions are:

\[
q_j\in\{0,1/6,2/6,3/6,4/6,5/6,1\}.
\]

This does **not** mean machine instruction count is physically continuous. The continuous coordinate is the runtime contract; the execution/certification backend remains finite and analyzable.

## Research-goal status

### Goal A — physical budget-conditioned computation: PASS

One fixed NN can physically change optional depth/width/expert/block execution under resource conditions with hard skip audits and finite work classes.

### Goal B — generalizable adaptive computation: PASS with a temporal-shift boundary

On held-out handwritten-digit row sequences, formal seeds 60--64 reach **93.56%** adaptive test accuracy at **20.23%** average physical compute, with 5/5 passing seeds and zero cap/count violations.

A separate chronological weekly-CO2 task remains a negative boundary: temporal/nonstationary depth utility shifts between validation and later test periods. Temporal distribution-shift robustness is not established.

### Goal C — same-model software/formal integration substantially closed; physical-target certification remains

The current same-model path is:

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
    -> pinned Simple-System deterministic LUT-memory timing audit
    -> CBMC finite runtime-contract proof
    -> CBMC mechanically extracted deployed-control proof
    -> deadline admission interface
```

This is strong research-prototype evidence. It is **not yet an FPGA/ASIC/silicon production WCET certificate**.

## Same-model Q15 / freestanding preservation

The five-seed Q15 reference has:

- finite-exit prediction mismatches versus float: **0 / 12,600**;
- preferred-exit mismatches versus float: **1 / 1,800**.

Representative seed 63 integer C has:

- exit-prediction mismatches: **0 / 2,520**;
- preferred-exit mismatches: **0 / 360**.

The final fixed-class Cortex-M4/RV32 neural numeric paths eliminate unresolved arithmetic helpers, floating-point operations, and hardware DIV/REM.

The adaptive wrapper can still contain public-control arithmetic, but that is kept separate from the fixed-class numeric certification path.

## Pinned Ibex RTL timing binding

The previous custom arithmetic processor model, `RTNN-IBEX-DIT-v1`, is a **negative result**. Actual pinned Ibex RTL exceeds that arithmetic estimate for every full-work certification class. The old formula must not be used for admission.

The accepted RTL experiment pins upstream Ibex commit:

`7b5df75a041affe56e8c235260f98a09b3319008`

and uses the official Simple System with the recorded fixed configuration, including `SecureIbex=1`, `RV32MSingleCycle`, two-stage execution, no I-cache/branch predictor, deterministic one-cycle Simple-System RAM, and no interfering master in the validation harness.

Seven fixed classes were run on three held-out inputs with preferred exits 1, 3, and 5. Across all 21 fixed-class cases:

- prediction mismatch versus native integer reference: **0**;
- input-to-input cycle range inside each class: **0**.

Exact-build measured fixed-class counts are:

| external class ceiling | fixed-class RTL cycles |
|---:|---:|
| 0% | 29,620 |
| 16.7% | 615,569 |
| 33.3% | 1,201,521 |
| 50% | 1,787,473 |
| 66.7% | 2,373,425 |
| 83.3% | 2,959,377 |
| 100% | 2,959,381 |

Admission + adaptive maximum-work binding:

| external class ceiling | admission + adaptive RTL cycles |
|---:|---:|
| 0% | 29,843 |
| 16.7% | 657,454 |
| 33.3% | 1,285,058 |
| 50% | 1,912,662 |
| 66.7% | 2,540,266 |
| 83.3% | 3,167,870 |
| 100% | 3,167,870 |

The 100% external grant shares the deployed runtime envelope of the 83.3% class because the validated preferred maximum is exit 5/6. A full resource grant does not force useless extra work.

The timing table is **build-specific**. It binds exact neural assets, exact machine image, compiler/toolchain, RTL revision/configuration, and memory integration. It is not a portable cycle formula.

## Exact-binary software control-flow audit

The exact ELF/bin used in the RTL evidence was audited with a custom RV32IM taint interpreter. All 64 neural input bytes are tainted and propagated through registers and memory.

For every fixed class `0..6`:

- neural-input-dependent conditional branches: **0**;
- neural-input-dependent indirect-control targets: **0**;
- neural-input-dependent store addresses: **0**;
- hardware DIV/REM instructions on the fixed-class path: **0**.

Exactly four load instruction sites have neural-input-dependent addresses:

- `0x001002ec`;
- `0x001002f0`;
- `0x0010152c`;
- `0x00101530`.

They are exp/GELU LUT interpolation reads. The complete post-clamp Q15 index domains remain inside the finite LUTs.

The adaptive `rtnn_fixed_infer_budget` path is intentionally different. Its neural-input-dependent conditional control localizes to the intended entropy early-stop decision. The fixed-class statement must not be misapplied to adaptive control.

The custom interpreter is not formally verified, so this evidence alone is `PASS_WITH_SCOPE`, not a WCET theorem.

## Independent BINSEC control-flow cross-check

To reduce dependence on the custom interpreter, the same exact RTL-tested RV32 ELF was independently analyzed with pinned third-party BINSEC `checkct` in control-flow mode.

Across classes `0..6`:

- classes passed: **7/7**;
- one completed path per class;
- pending paths: **0**;
- discontinued/unknown paths: **0**;
- `Program status: secure` for every class;
- control-flow leak sites: **0**;
- control-flow checks: **933,653 / 933,653**;
- unrolled instructions: **9,176,039**;
- branching points: **574,502**.

This independently corroborates the fixed-class compiled control-flow noninterference result.

A generic full relational memory check remains a negative/resource boundary: class 1 exceeds the supplied runner resources when relational memory-address checking is enabled over the LUT-heavy network. That is neither interpreted as a control-flow failure nor promoted to a generic memory proof.

## Pinned Simple-System deterministic LUT-memory timing

The four input-indexed load addresses are now analyzed against the **actual pinned Simple-System memory integration** rather than being left as an unresolved timing assumption.

Exact artifact and placement audit:

- all four sites remain aligned 32-bit RV32 `LW` instructions;
- input-indexed store sites: **0**;
- `fx_gelu_lut`: 4,097 words, wholly inside the 1 MiB RAM window;
- `fx_exp_lut`: 8,193 words, wholly inside the same RAM window;
- all legal LUT word addresses exhaustively checked: **12,290**;
- legal LUT addresses uniquely decoding to RAM: **12,290 / 12,290**;
- decode failures: **0**.

The pinned `ram_2p.sv` control is synthesized with Yosys while only primitive RAM **data values** are stubbed. For data-port `a_rvalid_o` the generated control netlist has:

- one async-reset FF driver;
- D exactly `a_req_i`;
- clock exactly `clk_i`;
- reset exactly `rst_ni`;
- primary-input fan-in `a_req_i`, `clk_i`, `rst_ni`;
- address signals in the transitive response-valid fan-in: **0**.

Together with the one-host Simple-System bus response-selection structure, legal LUT reads have a **one-cycle address-independent response latency in this exact memory model**. The address changes the returned LUT value, not the response-valid timing path.

This closes the specific four-LUT-load timing gap for the pinned Simple System. It does **not** establish generic constant-time memory behavior. Cache, SDRAM, bank/interleave effects, arbitration, DMA, another RAM wrapper, or FPGA integration require new target-specific evidence.

## CBMC finite runtime-contract proof

CBMC 6.10.0 checks the finite runtime contract over complete integer domains. The proof links the repository's actual deadline-admission implementation.

The five proof entry points report `VERIFICATION SUCCESSFUL` for:

1. continuous Q0.16 budget lowering — in-range, monotone, fail-closed, greatest-fit;
2. actual deadline admission — highest certified class fitting every 32-bit deadline, with wrong/null identity failing closed;
3. partial certification — uncertified `UINT32_MAX` entries are never admitted and higher fitting certified classes are not skipped;
4. effective execution — execution remains below budget, deadline, preference, and policy ceilings;
5. Q15 LUT indices — exact clamp/index arithmetic remains inside finite exp/GELU table domains for arbitrary signed-32-bit inputs.

This is a formal result for the represented finite C/runtime contract. It is not a proof of the whole neural arithmetic, compiler, processor pipeline, or physical device.

## CBMC proof of actual deployed control bodies

A second CBMC experiment removes the hand-copied source-control modeling gap. A deterministic extractor copies exact deployed bodies for:

- `rtnn_fixed_budget_ceiling_q16()`;
- `rtnn_fixed_infer_budget()`;
- `rtnn_fixed_certify_class()`.

For this control proof, numerical kernels are abstracted deliberately: `entropy10()` is nondeterministic and `run_block()` is instrumented as the physical optional-block invocation. Consequently every possible early-stop sequence is covered.

CBMC proves:

- actual Q0.16 lowering is monotone, fail-closed, in-range, and greatest-fit;
- for every Q0.16 budget, every deadline-class byte, and every entropy outcome, optional blocks execute in canonical order and never exceed the effective cap;
- reported `executed` equals the physical `run_block()` count;
- invalid deadline classes fail closed;
- the same cap holds with a NULL optional `executed` pointer;
- fixed certification executes exactly the normalized maximum-work number of optional blocks in canonical order.

This closes the deployed finite-control source-model duplication gap. It does not by itself prove compiler equivalence, the numerical kernels, processor RTL, or physical timing.

## Durable certification artifact identity

Timing certification uses a frozen machine artifact rather than a retraining seed as identity.

The exact certification package is now stored in Git under:

`artifacts/certification/ibex_simple_system/`

with:

- frozen ZIP SHA-256: `9150b0763e5d7b7c305441befdb4161ccf95612edd924b525f8388e06d9a86b0`;
- contained ELF SHA-256: `234a7f46cf227a11f5d97f3c778cbb0c4ed4f7067f8994bcca86c4b08ff4e742`;
- contained loadable BIN SHA-256: `266ecb70c723b2164f6fe9039f27d4cb49c4d7271d4aca0cf69f2692cdfdf7a1`.

The memory-formal workflow now unpacks and verifies this repository-frozen package instead of depending on the retention lifetime of the original Actions artifact.

Research reproducibility and timing certification remain separate:

- research reproduction: seed + training recipe + statistical result;
- timing certification: frozen neural assets + exact machine image + toolchain + processor/RTL/memory/physical target identity.

## Evidence hierarchy now achieved on the software/RTL side

The current result should be read as several distinct layers rather than one oversized "formal proof":

```text
CBMC deployed source control
        ↓
exact compiled RV32 control-flow audits
(custom + independent BINSEC)
        ↓
pinned target-specific LUT memory timing structure
        ↓
exact-build pinned Ibex RTL cycle measurement
        ↓
deadline binding interface
```

Each layer has a different proof scope. None is silently substituted for physical FPGA/ASIC certification.

## Current negative boundaries

Retain these as first-class results:

- Linux P95/P99 or observed-max × arbitrary margin is not a hard admission contract;
- the old arithmetic `RTNN-IBEX-DIT-v1` cycle formula is falsified by actual pinned Ibex RTL;
- a training seed is not a bitwise certification artifact identity;
- generic BINSEC full relational memory analysis for a LUT-heavy class exceeds supplied runner resources;
- source-level CBMC does not prove compiler equivalence, the whole processor pipeline, or physical timing;
- the pinned Simple-System memory result is not portable to caches, SDRAM, arbitration, or another target;
- nominal MAC reduction does not guarantee wall-clock reduction on every backend;
- forcing exact admitted work can reduce task quality;
- concurrent preferred-compute optimization missed the stable-frontier baseline;
- toy held-out horizon-value prediction failed;
- chronological temporal distribution shift remains unresolved.

## Immediate priorities

Hardware is intentionally deferred for now. Software/formal work should not return to route-score tuning or uncontrolled timing sampling.

1. Keep the frozen certification package, source/binary hashes, workflow checks, and top-level claims synchronized.
2. If another pre-hardware formal layer is pursued, target **whole-processor/target WCET or timing correspondence**, not already-proved finite control properties.
3. Prepare deterministic frozen vectors/result schemas so later board work is a direct automated comparison against the Q15 reference.
4. When physical validation resumes, run the preregistered DE0-CV experiment in `notes/realtime_nn_de0_cv_next_stage.md`.
5. Treat temporal/nonstationary ML generalization as a separate problem; larger neural/LM-scale work remains downstream of physical target certification.

## Next physical stage — DE0-CV

The planned experiment is:

> Execute the **same seed-63 Q15/freestanding seven-class RTNN contract** on **DE0-CV**, initially with an **Ibex softcore + controlled on-chip RAM + fixed clock**, derive a brand-new FPGA-specific class timing table, and then test deadline admission.

The Simple-System cycle table and memory proof are **not copied** to the FPGA. The DE0-CV build must receive its own processor/configuration identity, memory analysis, static timing result, cycle/time binding, and bitstream/build identity.

## Explicit nonclaims

Current work does **not** establish:

- a universal Ibex WCET theorem;
- generic constant-time memory behavior for arbitrary memory hierarchies;
- DE0-CV timing results;
- an FPGA/ASIC/silicon production WCET guarantee;
- cache/SDRAM/DMA/multi-master/interrupt timing portability;
- compiler/processor equivalence from source-level CBMC alone;
- temporal distribution-shift robustness;
- LLM-scale real-time generalization.

## Direction lock

Future main-line work should answer:

> Does this move the **same neural model** closer to controllable physical execution under `b ∈ [0,1]`, a finite maximum-work envelope, and a defensible deadline guarantee?

If not, it is secondary diagnostics.
