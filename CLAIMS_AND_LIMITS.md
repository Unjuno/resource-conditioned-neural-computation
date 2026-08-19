# Claims and limits

This document states the **strongest claims currently supported by the repository** and the boundaries that must remain explicit. Historical experiment detail is retained in `EXPERIMENT_INDEX.md` and the individual notes/results.

## Strongest supported research statement

> One fixed neural-network parameter set can accept a normalized runtime compute budget `b ∈ [0,1]`, lower that continuous interface fail-closed to finite maximum-work execution classes, choose less work when additional computation is not useful, physically skip inactive computation, and preserve the execution contract through a same-model Q15 freestanding implementation. For one exact frozen RV32 artifact on one pinned Ibex Simple-System configuration, the repository has an exact-build measured RTL cycle binding, two independent compiled control-flow analyses, a target-specific deterministic LUT-memory timing argument, and CBMC proofs of the finite/deployed source control contract.

This supports a strong **research-prototype Real-Time NN** statement. It is **not yet a production FPGA/ASIC/silicon WCET certificate**.

## 1. Budget changes physical neural computation

One fixed NN physically changes optional depth/width/expert/block execution under resource conditions. Inactive operations are structurally skipped rather than merely zero-masked.

The public resource interface is continuous:

\[
b\in[0,1].
\]

An analyzable backend lowers `b` to the largest finite admissible class no greater than the grant. Budget is a **maximum permission**, not an obligation to consume exact work.

Current finite normalized classes are:

\[
q_j\in\{0,1/6,2/6,3/6,4/6,5/6,1\}.
\]

This is not a claim of continuously variable machine instruction count.

## 2. Extra admitted compute need not be consumed

Sequence experiments falsify the stronger assumption that more forced computation must always improve quality. The deployed semantics separate:

- admitted maximum compute;
- model-preferred useful compute;
- actual effective execution.

Conceptually:

\[
e=\min(b,p(x,s)).
\]

The model may stop below the admitted ceiling.

## 3. Held-out real-sequence generalization

On held-out handwritten-digit row sequences, formal seeds 60--64 give:

- adaptive test accuracy: **93.56%** average;
- average physical compute: **20.23%**;
- capability gain from 0% exit to the useful frontier: **+43.83 percentage points**;
- seeds passing the preregistered boundary: **5/5**;
- cap/count violations: **0**.

This supports adaptive computation on an independent held-out real-sequence task.

A separate chronological weekly-CO2 experiment remains a negative boundary. Later-time depth utility shifts relative to validation. **Temporal/nonstationary distribution-shift robustness is not established.**

## 4. Same-model freestanding and Q15 lowering

Across seeds 60--64, one generic freestanding implementation preserves the finite-exit model path.

Float same-model C evidence:

- finite-exit Python/C prediction mismatches: **0 / 12,600**;
- preferred-exit mismatches: **0 / 1,800**;
- unresolved external symbols in audited freestanding objects: **0**.

Q15 evidence:

- finite-exit mismatch versus float: **0 / 12,600**;
- preferred-exit mismatch versus float: **1 / 1,800**.

Representative seed 63 integer C:

- exit-prediction mismatch: **0 / 2,520**;
- preferred-exit mismatch: **0 / 360**;
- caller-owned workspace: **4,608 bytes**.

The final fixed-class Cortex-M4/RV32 neural numeric path removes unresolved arithmetic helpers, floating-point instructions, and hardware DIV/REM.

## 5. Continuous budget + deadline software contract

The runtime composes finite ceilings conceptually as:

\[
C_{effective}=\min(C_{budget},C_{preferred},C_{deadline},C_{policy}).
\]

Earlier exhaustive/property audits report zero structural mismatches/violations over complete or large finite domains, including all 65,536 Q0.16 budget values and same-model held-out budget/deadline cases.

Invalid identities and partial certification fail closed.

## 6. CBMC finite runtime-contract proof

CBMC 6.10.0 checks the represented finite C/runtime contract over complete integer domains. All five proof entry points report `VERIFICATION SUCCESSFUL`:

1. Q0.16 continuous-budget lowering is in-range, monotone, greatest-fit, and fail-closed;
2. the actual deadline-admission implementation returns the highest certified timing class that fits every 32-bit deadline and rejects wrong/null identity state;
3. arbitrary partial-certification tables never admit an uncertified `UINT32_MAX` class and do not skip a higher fitting certified class;
4. effective execution remains below budget, deadline, preferred, and policy ceilings;
5. exact Q15 exp/GELU clamp/index arithmetic stays inside the finite LUT domains for arbitrary signed-32-bit inputs.

**Boundary:** this proves the represented C/runtime properties. It does not prove the entire neural arithmetic, compiler preservation, processor pipeline, or physical-device WCET.

## 7. CBMC proof of deployed neural-control bodies

A complementary proof mechanically extracts the exact deployed source bodies of:

- `rtnn_fixed_budget_ceiling_q16()`;
- `rtnn_fixed_infer_budget()`;
- `rtnn_fixed_certify_class()`.

For the control proof, neural numerical kernels are intentionally abstracted: `entropy10()` is nondeterministic so every possible continue/stop outcome is covered, while `run_block()` is instrumented as the physical optional-block call.

CBMC proves:

- the deployed Q0.16 lowering body is in-range, monotone, fail-closed, and greatest-fit;
- for all budgets, deadline-class bytes, and entropy outcomes, optional blocks execute only in canonical order and never exceed the effective ceiling;
- reported `executed` equals physical `run_block()` count;
- invalid deadline classes fail closed;
- the cap remains true when the optional `executed` pointer is NULL;
- certification executes exactly the normalized/policy-capped fixed class in canonical order.

**Boundary:** numerical kernels are abstracted and source-level CBMC does not establish compiler or processor timing equivalence.

## 8. Pinned Ibex RTL measured timing binding

The exact Q15 RV32 artifact was executed on pinned upstream Ibex commit:

`7b5df75a041affe56e8c235260f98a09b3319008`

with the recorded Simple-System configuration, including the data-independent timing path in that revision, `RV32MSingleCycle`, two-stage execution, no I-cache/branch predictor, deterministic one-cycle Simple-System RAM, and no interfering master in the validation harness.

Exact artifact identity:

- ELF SHA-256: `234a7f46cf227a11f5d97f3c778cbb0c4ed4f7067f8994bcca86c4b08ff4e742`;
- loadable BIN SHA-256: `266ecb70c723b2164f6fe9039f27d4cb49c4d7271d4aca0cf69f2692cdfdf7a1`.

Fixed-class measured cycles:

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
- prediction mismatches versus native integer reference: **0**;
- input-to-input cycle range within every fixed class: **0**.

The real admission + adaptive-inference path also has 21 RTL cases with prediction mismatch 0, executed-exit mismatch 0, unsafe admission 0, and committed runtime-binding exceedance 0.

This is an **exact-build measured RTL binding**, not a portable timing formula or universal WCET theorem.

## 9. Old arithmetic timing formula is falsified

The earlier custom instruction-category model `RTNN-IBEX-DIT-v1` underestimates actual pinned Ibex RTL for the full-work certification classes. It is retained as a negative result and **must not be used for deadline admission**.

## 10. Exact-binary fixed-class control-flow noninterference

A custom RV32IM taint interpreter marks all 64 neural input bytes as input-dependent in the exact RTL-tested binary.

For every fixed class `0..6` it reports:

- input-dependent conditional branches: **0**;
- input-dependent indirect-control targets: **0**;
- input-dependent store addresses: **0**;
- hardware DIV/REM on the fixed-class path: **0**.

Four input-dependent load-address instruction sites remain, all belonging to exp/GELU LUT interpolation. The custom interpreter is not formally verified.

The adaptive path intentionally contains neural-input-dependent control at the entropy early-stop decision. That is expected and is not a hidden fixed-class branch.

## 11. Independent BINSEC control-flow cross-check

The same exact RTL-tested ELF was independently analyzed with pinned third-party BINSEC.

Across all seven fixed classes:

- classes passing: **7 / 7**;
- completed paths: **1 per class**;
- pending paths: **0**;
- program status: **secure** for every class;
- control-flow leak sites: **0**;
- control-flow checks: **933,653 / 933,653**;
- unrolled instructions: **9,176,039**;
- branching points: **574,502**.

Generic full relational memory analysis is not claimed. A LUT-heavy class exceeds the supplied runner resources when relational memory-address analysis is enabled. This is recorded as a resource boundary, not a memory proof and not a control-flow failure.

## 12. Pinned Simple-System LUT-memory timing

The four input-dependent load addresses are now bound to the actual pinned Simple-System deterministic RAM/bus integration.

Exact audit results:

- all four sites remain aligned RV32 `LW` instructions;
- input-indexed stores: **0**;
- both exp/GELU LUTs are wholly inside the 1 MiB RAM region;
- legal LUT word addresses exhaustively checked: **12,290**;
- addresses uniquely decoding to RAM: **12,290 / 12,290**;
- decode failures: **0**.

Yosys synthesis of the pinned `ram_2p` response-valid control shows:

- one async-reset FF drives `a_rvalid_o`;
- its D input is exactly `a_req_i`;
- the response-valid transitive primary-input fan-in is request/clock/reset;
- address signals in that fan-in: **0**.

Together with the one-host bus response-selection structure, legal LUT reads have **one-cycle address-independent response latency in this exact Simple-System memory model**.

This closes the four-LUT-load timing gap **for the pinned Simple System only**. It does not prove constant latency for caches, SDRAM, banked/interleaved memory, arbitration, another RAM wrapper, or DE0-CV.

## 13. Durable certification artifact

A training seed is not a certification identity. The exact machine package used by the Ibex timing/binary/memory evidence is now frozen in Git under:

`artifacts/certification/ibex_simple_system/`

with:

- frozen ZIP SHA-256: `9150b0763e5d7b7c305441befdb4161ccf95612edd924b525f8388e06d9a86b0`;
- contained ELF SHA-256: `234a7f46cf227a11f5d97f3c778cbb0c4ed4f7067f8994bcca86c4b08ff4e742`;
- contained BIN SHA-256: `266ecb70c723b2164f6fe9039f27d4cb49c4d7271d4aca0cf69f2692cdfdf7a1`.

The deterministic-memory workflow consumes this repository-frozen package and rechecks the hashes; it no longer depends on the original Actions artifact retention lifetime.

Research reproducibility remains seed/recipe/statistical. Timing certification remains exact-artifact/build/target-specific.

## Timing and memory boundary

The strongest current timing statement is target-specific:

> For the identified frozen Q15/RV32 artifact on the identified pinned Ibex Simple-System configuration, measured finite-class RTL cycle bindings exist; fixed-class neural input does not influence compiled control flow according to two independent binary-level analyses; the remaining varying LUT addresses select a deterministic one-cycle RAM response path under an exhaustively checked legal address domain; and the finite/deployed source control contract is proved over its represented input domains with CBMC.

This is materially stronger than Linux percentile timing or a custom instruction-count model. It still does **not** prove the entire processor/physical implementation as a production hard-WCET theorem.

If the implementation moves to another FPGA memory, cache, SDRAM, arbitration, DMA, interrupts, another compiler, another processor configuration, or another physical target, timing must be rebound and revalidated.

## Current major negative boundaries

1. Ordinary Linux P95/P99 and observed maximum × arbitrary safety factor are not hard WCET evidence.
2. The old arithmetic `RTNN-IBEX-DIT-v1` timing formula is falsified by actual RTL.
3. Training seed/recipe alone is not bitwise certification identity.
4. Generic BINSEC full relational-memory analysis of a LUT-heavy path exceeds the supplied runner resources.
5. CBMC source/control proof does not by itself prove compiler preservation, full neural machine code, whole processor RTL, or physical timing.
6. The Simple-System deterministic-memory result does not transfer to DE0-CV or arbitrary memories.
7. Nominal MAC reduction does not guarantee wall-clock speedup on every backend.
8. Forcing exact admitted work can reduce task quality.
9. Concurrent end-to-end preferred-compute training did not match the stable post-trained frontier.
10. Toy held-out horizon-value generalization failed.
11. Chronological/nonstationary temporal generalization remains unresolved.

## Explicitly not claimed

1. A universal Ibex WCET theorem.
2. An FPGA/ASIC/silicon production WCET guarantee.
3. Generic constant-time memory behavior for arbitrary memory hierarchies.
4. DE0-CV timing or memory behavior.
5. Cache/SDRAM/DMA/multi-master/interrupt timing tolerance.
6. Compiler equivalence of every source-level proof property.
7. Temporal distribution-shift robustness.
8. Universal learned-policy superiority over fixed or analytic scheduling baselines.
9. Unconstrained self-organized architecture discovery.
10. Autoregressive LLM-scale real-time generalization.

## Remaining production-hard-real-time work

The next evidence gap is no longer another router/loss experiment or the four Simple-System LUT addresses.

The remaining path is:

1. optionally strengthen whole-processor/target timing proof methodology before hardware;
2. prepare frozen board vectors and machine-readable output checks;
3. when physical validation is resumed, deploy the same seed-63 Q15 seven-class contract to **DE0-CV** with controlled on-chip RAM and a fixed clock;
4. derive a **new FPGA-specific** cycle/time table and memory argument rather than copying the Simple-System table;
5. test deadline admission against that new binding;
6. only then add interference, external memory, DMA/multi-master effects, or mixed criticality.

The preregistered DE0-CV plan is in `notes/realtime_nn_de0_cv_next_stage.md`.

## Direction lock

Future main-line work should answer:

> Does this move the **same neural model** closer to controllable physical execution under `b ∈ [0,1]`, a finite maximum-work envelope, and a defensible deadline guarantee?

If not, it is secondary diagnostics.
