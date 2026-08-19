# Claims and limits

This document states the **strongest claims currently supported by the repository** and the boundaries that must remain explicit. Historical experiment-by-experiment detail is kept in `EXPERIMENT_INDEX.md` and the individual notes/results.

## Strongest supported research statement

> One fixed neural-network parameter set can accept a normalized runtime compute budget `b ∈ [0,1]`, lower that continuous interface fail-closed to finite maximum-work execution classes, choose less work when additional computation is not useful, physically skip inactive computation, and preserve the resulting execution contract through a same-model Q15 freestanding implementation. On one exact pinned Ibex RTL Simple System build, the finite classes have an exact measured cycle binding, and the software-side budget/deadline contract plus fixed-class control-flow properties have been independently checked with CBMC and BINSEC/custom binary analysis.

This is a strong **research-prototype Real-Time NN** statement. It is **not yet a production FPGA/ASIC/silicon WCET certificate**.

## Supported direct evidence

### 1. Budget changes physical neural computation

Across the research chain, one fixed NN physically changes optional depth/width/expert/block execution under resource conditions. Inactive operations are structurally skipped rather than merely zero-masked. Finite execution classes provide a maximum-work boundary suitable for later timing binding.

The preferred public resource interface is continuous:

\[
b\in[0,1].
\]

The backend lowers `b` to the largest finite admissible class no greater than the resource grant. Budget is a **maximum permission**, not an obligation to consume exact work.

### 2. Extra admitted compute need not be consumed

Sequence experiments falsify the stronger assumption that more forced computation must always improve quality. The deployed semantics therefore separate:

- admitted maximum compute;
- model-preferred useful compute;
- actual effective execution.

Conceptually:

\[
e = \min(b,p(x,s)).
\]

The model may stop below the admitted ceiling when additional computation is predicted to be unnecessary or harmful.

### 3. Held-out real-sequence generalization

On held-out handwritten-digit row sequences, formal seeds 60--64 give:

- adaptive test accuracy: **93.56%** average;
- average physical compute: **20.23%**;
- capability gain from the 0% exit to the useful frontier: **+43.83 percentage points**;
- formal seeds passing the preregistered boundary: **5/5**;
- cap/count violations: **0**.

This supports generalizable adaptive computation on an independent held-out real-sequence task.

A separate chronological weekly-CO2 experiment remains a negative boundary: later-time depth utility shifts relative to validation and only 3/5 seeds pass. **Temporal/nonstationary distribution-shift robustness is not established.**

### 4. Same-model freestanding lowering

The real-sequence models are exported into one generic freestanding C implementation.

Across seeds 60--64:

- finite-exit Python/C prediction mismatches: **0 / 12,600**;
- preferred-exit mismatches in the float same-model C path: **0 / 1,800**;
- unresolved external symbols in the audited freestanding objects: **0**.

Representative seed 63 with 21 continuous-budget audit points gives **7,560** held-out sample×budget cases with prediction mismatch 0, executed-exit mismatch 0, and cap violation 0.

### 5. Fixed-point time-predictable lowering

The same real-data model is lowered to a Q15/fixed-iteration implementation using integer LUTs and fixed-iteration numerical kernels.

Five-seed Q15 reference evidence:

- finite-exit mismatch vs float: **0 / 12,600**;
- preferred-exit mismatch vs float: **1 / 1,800**.

Representative seed 63 integer C:

- exit-prediction mismatch: **0 / 2,520**;
- preferred-exit mismatch: **0 / 360**;
- caller-owned workspace: **4,608 bytes**.

The final audited fixed-class Cortex-M4/RV32 neural paths remove unresolved arithmetic runtime helpers, floating-point operations, and hardware DIV/REM from the neural numeric path.

### 6. Continuous budget + deadline software contract

The freestanding runtime composes:

\[
C_{\mathrm{effective}}=
\min(C_{\mathrm{budget}},C_{\mathrm{preferred}},C_{\mathrm{deadline}}).
\]

Earlier exhaustive/property audits report zero structural mismatches/violations over:

- all 65,536 Q0.16 budget values;
- 16,777,216 budget×preferred combinations;
- 655,360 deadline/budget/preference combinations;
- same-model 52,920 held-out sample×budget×deadline cases.

Invalid identities and partial certification fail closed.

### 7. CBMC finite runtime-contract proof

CBMC 6.10.0 checks the represented finite C/runtime contract over complete integer domains. All five proof entry points report `VERIFICATION SUCCESSFUL`:

1. Q0.16 continuous-budget lowering is in-range, monotone, greatest-fit, and fail-closed;
2. the actual `rtnn_fixed_admit_total_cycles()` implementation returns the highest timing class that fits every 32-bit deadline and rejects wrong/null identity state;
3. arbitrary partial-certification tables never admit an uncertified `UINT32_MAX` class and do not skip a higher certified class that fits;
4. effective execution remains below budget, deadline, preferred, and policy ceilings;
5. exact Q15 exp/GELU clamp/index arithmetic stays within the finite LUT domains for arbitrary signed-32-bit inputs.

**Boundary:** CBMC proves the modeled C/runtime properties. It does not by itself prove compiler preservation, the complete neural machine code, processor pipeline timing, or physical-device WCET.

### 8. Pinned Ibex RTL measured timing binding

The exact Q15 RV32 artifact was executed on pinned upstream Ibex commit:

`7b5df75a041affe56e8c235260f98a09b3319008`

with the official Simple System configured for:

- `SecureIbex=1` / data-independent timing path in this revision;
- `RV32MSingleCycle`;
- two-stage execution;
- no I-cache or branch predictor;
- deterministic one-cycle Simple System RAM with zero additional instruction delay;
- no interrupt, DMA, or competing master in the validation harness.

Exact artifact identity recorded in the RTL evidence:

- ELF SHA-256: `234a7f46cf227a11f5d97f3c778cbb0c4ed4f7067f8994bcca86c4b08ff4e742`;
- loadable binary SHA-256: `266ecb70c723b2164f6fe9039f27d4cb49c4d7271d4aca0cf69f2692cdfdf7a1`.

Fixed-class measured RTL cycles:

| normalized ceiling | cycles |
|---:|---:|
| 0% | 29,620 |
| 16.7% | 615,569 |
| 33.3% | 1,201,521 |
| 50% | 1,787,473 |
| 66.7% | 2,373,425 |
| 83.3% | 2,959,377 |
| 100% | 2,959,381 |

All seven fixed classes were run on three distinct held-out inputs with preferred exits 1, 3, and 5:

- fixed-class cases: **21**;
- prediction mismatches vs native integer reference: **0**;
- input-to-input cycle range within every fixed class: **0**.

The real admission + adaptive-inference path also has 21 RTL cases with prediction mismatch 0, executed-exit mismatch 0, unsafe admission 0, and committed runtime-binding exceedance 0.

This is an **exact-build measured RTL binding**, not a portable timing formula.

### 9. Old arithmetic timing formula is falsified

The earlier custom instruction-category timing model `RTNN-IBEX-DIT-v1` underestimates actual pinned Ibex RTL for the full-work certification classes. It is a retained negative result and **must not be used for deadline admission**.

This directly demonstrates why nominal instruction/MAC accounting cannot substitute for target-pipeline validation.

### 10. Exact-binary fixed-class control-flow noninterference

A custom RV32IM taint interpreter marks all 64 neural input bytes as input-dependent in the exact RTL-tested binary.

For every fixed class `0..6` it reports:

- input-dependent conditional branches: **0**;
- input-dependent indirect-control targets: **0**;
- input-dependent store addresses: **0**;
- hardware DIV/REM instructions on the fixed-class path: **0**.

Four input-dependent load-address instruction sites remain, all belonging to exp/GELU LUT interpolation. Exhaustive post-clamp integer-domain checks keep those accesses within their finite LUTs.

The adaptive path intentionally contains neural-input-dependent control at one machine-code site, the entropy early-stop decision. That is expected behavior, not a hidden fixed-class timing path.

**Boundary:** the custom interpreter is not itself formally verified.

### 11. Independent BINSEC control-flow cross-check

The exact same RTL-tested ELF was independently analyzed with pinned third-party BINSEC.

Across all seven fixed classes:

- classes passing: **7 / 7**;
- completed paths: **1 per class**;
- pending paths: **0**;
- `Program status`: **secure** for every class;
- control-flow leak sites: **0**;
- control-flow checks: **933,653 / 933,653**;
- unrolled instructions explored: **9,176,039**;
- branching points explored: **574,502**.

This materially reduces reliance on the custom interpreter for the fixed-class control-flow claim.

Generic full constant-time memory analysis is **not** claimed: class 0 completes with memory checks secure, while class 1 exceeds the supplied GitHub runner resources (exit 137) when relational memory-address analysis is enabled over the LUT-heavy path. The same class completes and passes all 47,971 control-flow checks when memory relational analysis is disabled. This is recorded as a resource boundary, not a control-flow failure and not a memory proof.

## Artifact identity policy

A training seed is **not** a certification identity. Retraining seed 63 on a different runner did not reproduce the previous Q15 artifact bit-for-bit.

Therefore:

- **research reproducibility:** seed + training recipe + statistical result;
- **timing certification:** frozen Q15 artifact + exact machine image + compiler/toolchain + processor/RTL/memory configuration + timing evidence.

The current RTL/BINSEC evidence records exact hashes. Actions artifacts are supporting evidence; a production certification process should additionally retain the exact ELF/bin in a durable long-term artifact archive.

## Timing and memory boundary

The strongest current timing statement is target-specific:

> For the identified Q15 machine artifact on the identified pinned Ibex Simple System configuration, measured finite-class RTL cycle bindings exist; fixed-class neural input does not influence machine-code control flow according to two independent binary-level analyses; the remaining input-dependent LUT addresses are bounded and execute against deterministic address-independent RAM in that target model.

This still does **not** prove generic memory constant-time behavior or physical-device WCET.

If the implementation moves to cache, SDRAM, another SRAM, bus arbitration, DMA, interrupts, FPGA fabric, another compiler, or another processor configuration, timing must be rebound and revalidated.

## Current major negative boundaries

1. Ordinary Linux P95/P99 and observed maximum×arbitrary safety factor are not hard WCET evidence.
2. The old arithmetic `RTNN-IBEX-DIT-v1` timing formula is falsified by actual RTL.
3. Training seed/recipe alone is not bitwise certification identity.
4. Generic relational full-memory constant-time analysis of the LUT-heavy class-1 path exceeded the supplied runner resources.
5. Nominal MAC reduction does not guarantee wall-clock speedup on every backend.
6. Forcing exact admitted work can reduce task quality.
7. Concurrent end-to-end preferred-compute training did not match the stable post-trained frontier.
8. Toy held-out horizon-value generalization failed.
9. Chronological/nonstationary temporal generalization remains unresolved.

## Explicitly not claimed

1. A universal Ibex WCET theorem.
2. An FPGA/ASIC/silicon production WCET guarantee.
3. Generic constant-time memory behavior for arbitrary memory hierarchies.
4. Arbitrary compiler/hardware/timing portability.
5. Temporal distribution-shift robustness.
6. Training-time sparse execution for every research training protocol.
7. Universal learned-policy superiority over fixed or analytic scheduling baselines.
8. Unconstrained self-organized architecture discovery.
9. Autoregressive LLM-scale real-time generalization.
10. That measured RTL timing alone constitutes a formal all-input WCET proof.

## Remaining production-hard-real-time work

The next evidence gap is no longer another router or neural loss experiment. It is the target timing boundary:

1. bind/prove the four input-indexed LUT accesses to the selected deterministic memory implementation;
2. retain the exact certification machine artifact durably;
3. when physical validation is desired, map the same contract to the available DE0-CV using controlled on-chip memory and a fixed clock, then derive a **new FPGA-specific timing binding** rather than copying the Simple System cycle table;
4. if a software-only production proof is required, add a stronger static/formal target-timing method that covers the processor/memory implementation itself.

## Direction lock

Before promoting a new main-line experiment, ask:

> Does it move the same neural model closer to a defensible chain `deadline → admitted finite work → physical neural execution → target/build timing bound → on-time output`?

If not, it belongs under secondary diagnostics.
