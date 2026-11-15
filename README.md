# Resource-Conditioned Neural Computation

A falsification-oriented research prototype toward a **Real-Time Neural Network (RTNN)**: one fixed neural parameter set whose **physically executed internal computation changes under a runtime-admitted resource/deadline contract**.

The research target is not router accuracy. It is the complete system chain:

```text
remaining deadline / target state
    -> normalized admitted budget b in [0,1]
    -> finite maximum-work class
    -> same NN parameters
    -> preferred useful compute p(x,s)
    -> effective execution e = min(b,p)
    -> physically executed neural work
    -> target/build-specific timing bound
    -> deadline admission
```

The public budget is continuous (`b ∈ [0,1]`), but the analyzable backend lowers it fail-closed to finite physical classes. A budget is a **maximum permission**, not a requirement to consume all available compute.

## Current evidence snapshot

### Stage C3 revised measurement gates — 2026-11-15

**B-SIGNOFF remains BLOCKED.** Board/cable TCK frequency and duty plus external TDI/TMS/TDO timing remain unverified. Quartus also reports unconstrained output paths for the status LEDs `LEDR[0/1/3]`; these drive on-board indicators without an external synchronous receiver, so no receiver setup/hold budget is assigned. Their UCP entries and Fitter drive/slew warnings remain visible; they are not false-pathed. The external JTAG timing gap independently blocks signoff. No WCET, hard-deadline, or board-wide timing guarantee is claimed. See the [port-by-port UCP disposition](artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/GATE_B_C3V2_AUDIT_20261115/UCP_AND_STATUS_CHRONOLOGY_RECHECK_20261115_JA.md).

**B-EMPIRICAL remains limited to the measured C3 v2 build and board; it is not a timing signoff.** Build `43334531` returns 64-bit `mcycle` start/end samples. The 42-case replay, preselected ten-input run, frozen C3 v2 campaign (24,840/24,840 across 13/13 schedules), and additional KEY-reset replays passed their saved JSON/CSV/raw-log audits. The campaign's 24,840 rows remain archived separately from historical C2J2 rows and were collected on one board in one continuous, cold-boot-unverified power session. The latest additional reset replay RUN5 is a separate 20-row experiment with its own gate; it was not added to the campaign. No per-schedule physical reset telemetry was recorded. The full campaign is **EMPIRICAL_ONLY** and does not establish cross-boot variability, speed superiority, accuracy non-inferiority, WCET, or hard-deadline guarantees. The preserved run records report native, sv2v and Quartus-flat regressions, Quartus Fitter/Assembler, and four-corner internal STA as passed. The clean repository checkout still lacks 141 Ibex RTL dependency files from the frozen 146-source list. On 2026-11-15, a fresh WSL Ubuntu 24.04 native rebuild nevertheless passed using the pinned Ibex commit and all 146 source-file hashes available in the current local `/opt/rtnn-tools/ibex` installation; this is current-machine reproducibility, not a self-contained clean-checkout build. See [`native graph rebuild record`](artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/C3_MEASUREMENT_V2_RTL_REPRODUCE_20261115/RUN_RECORD_JA.md). Quartus D102 remains visible for the bundled-data CDC paths; it was reviewed, not waived. A finite 38-condition native/Quartus-flat CDC phase stress test also passed, without proving metastability immunity or external timing. The aggregate row/identity/hash audit is [`C3V2_CAMPAIGN_AGGREGATE_AUDIT_20261115.json`](artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/PHYSICAL_C3_V2_20261115/FROZEN_CAMPAIGN/C3V2_CAMPAIGN_AGGREGATE_AUDIT_20261115.json). Current status and independent offline reanalysis: [`C3_CURRENT_STATUS_20261115_POST_KEY_RESET_RUN5_JA.md`](artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/C3_CURRENT_STATUS_20261115_POST_KEY_RESET_RUN5_JA.md), [`ANALYSIS_AND_REPRODUCIBILITY_REPORT_JA.md`](artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/OFFLINE_REPRO_20261115/ANALYSIS_AND_REPRODUCIBILITY_REPORT_JA.md).

The saved C3 v2 Quartus/STA reports were independently reparsed: internal four-corner route coverage is recorded, while external TDI/TMS/TDO timing remains unconstrained and **B-SIGNOFF remains BLOCKED**. The 16 unwaived D102 structures were mapped to the retained RTL and finite regression assertions. A Quartus STA-only recheck on a SHA-verified copy reconciled the 484 response source instances as 480 logical payload bits plus four fitter-generated duplicate registers, with all 480 bit indexes routed exactly once per corner. See [`GATE_B_AUDIT_JA.md`](artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/GATE_B_C3V2_AUDIT_20261115/GATE_B_AUDIT_JA.md) and [`D102 selector recheck`](artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/GATE_B_D102_SELECTOR_RECHECK_20261115/RUN_RECORD_JA.md). This was an offline STA run on a copied fitted project, not a new Fitter/Assembler run or hardware operation.

The retained Terasic DE0-CV System CD ZIP was rehashed and its 1,089-member index rechecked. The archive contains Cyclone V demonstration projects and the ControlPanel SOF, but the scanned project/source files contain no EPM240/MAX II/USB-Blaster controller source references and the listed device assignments are Cyclone V. The scan did not reverse engineer binaries; it provides no board-specific external JTAG timing. See the [archive recheck record](artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/JTAG_CONTROLLER_PACKAGE_RECHECK_20261115/RUN_RECORD_JA.md).

The current main line has progressed from mechanism toys to a same-model real-data/Q15/freestanding/RTL/formal chain.

### Goal A — physical budget-conditioned computation: PASS

Across multiple experiments, one fixed NN physically changes optional depth, structured width, expert count, or block execution under resource conditions. Hard hooks verify that inactive work is not executed.

### Goal B — held-out adaptive computation: PASS with a temporal-shift boundary

On independent held-out handwritten-digit row sequences, formal seeds 60--64 reach:

- **93.56%** adaptive test accuracy;
- **20.23%** mean physical compute;
- **5/5** seeds passing the preregistered boundary;
- **0** cap/count violations.

A separate chronological weekly-CO2 experiment remains a negative result: later-time depth utility shifts relative to validation. Temporal/nonstationary robustness is not established.

### Goal C — software/formal integration substantially closed; DE0-CV empirical qualification recorded

An empirical DE0-CV C2J2 qualification is now archived under `artifacts/experiments/de0_cv_c1_c2_audit_20261114/`: the reported SRAM-only JTAG run completed 42 frozen requests and returned matching frozen-model predictions, execution classes, response IDs, CRCs, and nonzero FPGA cycle counts. A separate Verilator run now also covers the exact final Quartus flat RTL (`fdfcdf...`) for all 42 requests, reset replays, and negative cases. It uses a testbench copy whose CDC checks sample the RTL's explicit capture-pending edges; the original check sampled one cycle too early and its failure is preserved. The native 146-source SystemVerilog rebuild remains blocked because the migrated development RTL lacks the capture-pending source revision represented in the final Quartus flat RTL. This is empirical evidence for one board/build, not board-level timing signoff or a production WCET certificate. The seven-class fixed/admission timing binding preregistered in `notes/realtime_nn_de0_cv_next_stage.md` remains incomplete. The earlier CDC regression flat RTL (`F899...`) is a different source hash and remains identified as an earlier-source run.

Current same-model chain:

```text
held-out real-sequence model
    -> Q15 fixed-iteration model/policy
    -> freestanding integer C
    -> continuous b in [0,1]
    -> seven finite maximum-work classes
    -> budget/deadline ceiling + preferred stopping
    -> maximum-work manifest
    -> pinned Ibex RTL timing binding
    -> exact-RV32 custom noninterference audit
    -> independent BINSEC fixed-class control-flow audit
    -> pinned Simple-System deterministic LUT-memory timing audit
    -> CBMC finite runtime-contract proof
    -> CBMC proof of mechanically extracted deployed control
    -> deadline admission interface
```

This is strong research-prototype evidence. It is **not yet an FPGA/ASIC/silicon production WCET certificate**.

## Key current results

### Same-model Q15 / freestanding preservation

Five-seed Q15 reference evidence:

- finite-exit mismatch versus float: **0 / 12,600**;
- preferred-exit mismatch versus float: **1 / 1,800**.

Representative seed 63 integer C:

- exit-prediction mismatch: **0 / 2,520**;
- preferred-exit mismatch: **0 / 360**;
- caller-owned workspace: **4,608 bytes**.

The audited fixed-class neural numeric path removes unresolved arithmetic helpers, floating-point operations, and hardware DIV/REM.

### Pinned Ibex exact-build RTL timing

For the exact frozen RV32 artifact on pinned upstream Ibex commit `7b5df75a041affe56e8c235260f98a09b3319008`, all seven fixed classes were run on three held-out inputs with preferred exits 1, 3, and 5.

- fixed-class prediction mismatches: **0 / 21**;
- input-to-input cycle range inside every fixed class: **0**.

Measured fixed-class cycles:

| normalized class | cycles |
|---:|---:|
| 0% | 29,620 |
| 16.7% | 615,569 |
| 33.3% | 1,201,521 |
| 50% | 1,787,473 |
| 66.7% | 2,373,425 |
| 83.3% | 2,959,377 |
| 100% | 2,959,381 |

These are **exact-build RTL measurements**, not a universal timing formula.

### Compiled control-flow evidence

The exact RTL-tested fixed-class ELF has zero neural-input-dependent conditional branches or indirect-control targets according to a custom RV32 taint audit.

Independent pinned BINSEC analysis then completes all seven fixed classes as `secure`:

- control-flow checks: **933,653 / 933,653**;
- pending paths: **0**;
- leak sites: **0**;
- unrolled instructions explored: **9,176,039**.

The adaptive path intentionally contains neural-input-dependent early-stop control; the fixed-class claim is not applied to that branch.

### Target-specific LUT-memory timing

Four input-dependent load-address sites remain in exp/GELU LUT interpolation. For the pinned one-host Ibex Simple System, the repository now checks the actual memory integration:

- both LUTs are wholly inside the 1 MiB RAM window;
- all **12,290** legal LUT word addresses decode uniquely to RAM;
- all four sites remain aligned RV32 `LW` instructions;
- Yosys synthesis shows `a_rvalid_o` is one request-register stage with **zero address fan-in**.

Thus varying legal LUT addresses change data but not response latency in this exact Simple-System memory model. This result does **not** transfer automatically to cache, SDRAM, arbitration, another RAM, or FPGA memory.

### CBMC finite/deployed control proofs

CBMC 6.10.0 proves the finite runtime contract over complete represented integer domains, including:

- Q0.16 continuous-budget lowering;
- actual deadline admission;
- partial-certification fail-closed behavior;
- effective execution ceilings;
- exp/GELU LUT index bounds.

A second proof mechanically extracts the deployed bodies of `rtnn_fixed_budget_ceiling_q16()`, `rtnn_fixed_infer_budget()`, and `rtnn_fixed_certify_class()`. With entropy abstracted nondeterministically, every possible early-stop outcome is covered and physical optional-block calls never exceed the effective cap.

### Durable certification artifact

The exact package used by the Ibex timing/binary/memory evidence is frozen under:

`artifacts/certification/ibex_simple_system/`

Identity:

- frozen ZIP SHA-256: `9150b0763e5d7b7c305441befdb4161ccf95612edd924b525f8388e06d9a86b0`;
- ELF SHA-256: `234a7f46cf227a11f5d97f3c778cbb0c4ed4f7067f8994bcca86c4b08ff4e742`;
- BIN SHA-256: `266ecb70c723b2164f6fe9039f27d4cb49c4d7271d4aca0cf69f2692cdfdf7a1`.

CI rechecks the frozen package and derives the board-free preflight reference from it. The current formal memory workflow no longer relies on the retention lifetime of the original Actions artifact.

## Next physical stage — DE0-CV

**DE0-CV has not yet been tested.** Hardware work is intentionally deferred.

The preregistered next physical experiment is:

> Run the **same seed-63 Q15/freestanding seven-class RTNN contract** on **DE0-CV**, initially with an **Ibex softcore + controlled on-chip RAM + fixed clock**, derive a **new FPGA-specific timing table**, and then test deadline admission.

The Simple-System cycle table is not copied to the FPGA. The DE0-CV build must get its own processor/memory/configuration identity, static timing result, cycle/time binding, and build/bitstream identity.

Board-free vectors are already frozen in:

`artifacts/certification/de0_cv_preflight_vectors.json`

Detailed plan:

[`notes/realtime_nn_de0_cv_next_stage.md`](notes/realtime_nn_de0_cv_next_stage.md)

## Important negative results retained

The repository intentionally keeps falsifications rather than rewriting history:

- ordinary Linux P95/P99 and observed-max × arbitrary margin are not hard WCET evidence;
- the old arithmetic `RTNN-IBEX-DIT-v1` cycle formula is falsified by actual Ibex RTL;
- a training seed is not a bitwise certification identity;
- generic BINSEC full relational-memory analysis of a LUT-heavy class exceeds the supplied runner resources;
- nominal MAC reduction does not guarantee latency reduction on every backend;
- forced extra compute can reduce quality;
- concurrent preferred-compute training did not match the stable post-trained frontier;
- held-out horizon-value prediction failed on the toy cross-fit audit;
- chronological temporal distribution shift remains unresolved.

## Repository map

- [`REALTIME_NN_DIRECTION.md`](REALTIME_NN_DIRECTION.md) — current research direction and evidence hierarchy.
- [`CLAIMS_AND_LIMITS.md`](CLAIMS_AND_LIMITS.md) — strongest supported claims and explicit nonclaims.
- [`EXPERIMENT_INDEX.md`](EXPERIMENT_INDEX.md) — experiment-by-experiment result index, including negative results.
- [`EXPERIMENT_PLAN_REALTIME_NN.md`](EXPERIMENT_PLAN_REALTIME_NN.md) — current plan from software/formal closure to physical target validation.
- [`notes/`](notes/) — detailed experiment notes.
- [`results/`](results/) — machine-readable result records.
- [`experiments/`](experiments/) — experiment/audit code.
- [`artifacts/certification/`](artifacts/certification/) — frozen certification identity and board-free reference material.

## Explicit nonclaims

Current work does not establish:

- a universal Ibex WCET theorem;
- generic constant-time behavior for arbitrary memory systems;
- DE0-CV timing results;
- an FPGA/ASIC/silicon production WCET guarantee;
- cache/SDRAM/DMA/multi-master/interrupt timing portability;
- compiler/whole-processor equivalence from source-level CBMC alone;
- temporal distribution-shift robustness;
- LLM-scale real-time generalization.

## Direction rule

New main-line work should answer:

> Does this move the **same neural model** closer to controllable physical execution under `b ∈ [0,1]`, a finite maximum-work envelope, and a defensible deadline guarantee?

If not, it is secondary diagnostics.

Repository update audit for the 2026-11-15 C3 evidence publication: [REPOSITORY_UPDATE_AUDIT_20261115.md](artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/REPOSITORY_UPDATE_AUDIT_20261115.md).
