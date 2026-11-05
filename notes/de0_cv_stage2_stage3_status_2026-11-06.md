# DE0-CV Stage 2 evidence review and Stage 3 gate (2026-11-06)

**State: reported Stage 2 execution / Stage 3 evidence pending.** This is an evidence ledger, **not** an FPGA acceptance certificate.

## 1. Evidence provenance

- Evidence cut-off: the operator's **2026-11-03** report, headed STATUS_2026-11-03_JA.md.
- Reported workspace: de0cv_setup/verified_inputs_2026-11-03/stage2_finalwork/fpga/de0_cv/evidence/codex_setup/codex_2026-11-03_run_02/.
- That local STATUS file and its raw logs have **not** been attached to this GitHub change. Every reported PASS below therefore means **operator-reported, pending raw-artifact audit**.
- This repository's existing README, certification ZIP, Ibex Simple-System evidence and frozen board-free vectors are **not** equivalent to an independently accepted DE0-CV result.
- A later Stage 3 local run may exist, but no new STA or physical-board evidence was available for this review. **Unknown is not FAIL, nor PASS.**
- This document contains no performance measurement obtained on DE0-CV.

## 2. Reported outcome at evidence cut-off

| Gate | Reported finding | Classification for this ledger |
|---|---|---|
| Stage 2 canonical ZIP | SHA-256 matches its manifest | REPORTED_PASS; check manifest and file bytes |
| Three input ZIPs / nine overlay files | All three archives pass integrity; nine overlay SHA-256 values match | REPORTED_PASS; fetch underlying manifests |
| Host regression | 98 passing tests | REPORTED_PASS; require original command, run log and exit status |
| RV32 functional gate | 720 passing ISA-level checks | REPORTED_PASS; **not Ibex cycle timing** |
| RAM and UART TX/RX RTL units | PASS | REPORTED_PASS; require source and simulator identity |
| Fixed Ibex SoC inference | Fixed and adaptive Q15 predicted labels match the supplied reference | REPORTED_PASS; confirm sample identities, exits, binary, reference SHA |
| SoC regression after sv2v | PASS, 108 warnings recorded | REPORTED_PASS_WITH_WARNINGS; triage **all** 108 warnings by severity |
| Quartus Fitter / STA | Both tools executed; no tested seed met the 50 MHz setup objective | **TIMING_NOT_CLOSED** |
| Best reported fit | HPerf seed 2, 48.29 MHz, worst setup slack -0.710 ns | **50_MHZ_FAIL**; preserve reports, seed and SDC |
| DE0-CV program / on-board inference | NOT_RUN on 2026-11-03 due to timing and constraint gaps | **NOT_RUN_AT_CUTOFF**; later status requires fresh evidence |
| FPGA cycle / energy / hard deadline claim | No valid physical measurements submitted | **UNSUPPORTED** |

Reported C: drive free space was approximately 3.4 GiB, while WSL free space was approximately 952 GiB **at that time only**. Recheck free space before a new Quartus run; do not treat these numbers as current.

## 3. Meaning of the timing result

Target clock is 50 MHz, requiring a nominal period of 20 ns. The reported worst setup slack is negative and the best estimated attainable frequency is 48.29 MHz; therefore **no 50 MHz hardware-validation PASS is supported**.

| Variable | Meaning (Japanese) | SI unit | Definition | Domain / assumption | Type |
|---|---|---|---|---|---|
| \(f_{\rm req}\) | 要求クロック周波数 | Hz | nominated target clock | \(50\times10^6\) Hz | positive real scalar |
| \(T_{\rm req}\) | 要求クロック周期 | s | \(1/f_{\rm req}\) | one nominal clock domain | positive real scalar |
| \(s_{\rm setup}\) | 最悪setup slack | s | minimum reported setup slack | signed, same timing corner and constraint set | real scalar |
| \(f_{\rm fit}\) | Fitter/STA報告の達成周波数 | Hz | target-specific frequency estimate | quoted as reported, not measured physical oscillator | positive real scalar |

\[
T_{\rm req}=\frac{1}{50\times10^6\ {\rm Hz}}=20\ {\rm ns}.
\]

Dimensional check: \(1/{\rm Hz}={\rm s}\). The 48.29 MHz value is a **tool-derived timing result**, not measured runtime throughput. Negative setup slack does not by itself prove what happens in a particular on-board attempt; it prevents timing-signoff at the specified constraints.

## 4. Unresolved gate A: audit the constraints before changing RTL

Inspect the actual .sdc, .qsf, TimeQuest reports and all warnings. At minimum:
- exact input/reference and generated clock definitions, periods, uncertainty, reset handling;
- unconstrained setup/hold paths, CDC, clock groups and justified timing exceptions;
- board pins, I/O standard, voltage, peripheral timing assumptions and reset synchronizers;
- clock-domain assumptions, BRAM inference, memory init, read-during-write behaviour;
- worst setup and hold paths, WNS/TNS, per-corner evidence, source versus routing delay;
- warning categories, fatal/critical warnings and accepted waivers with written reasoning;
- Quartus version, selected device, Fitter seed and settings, exact RTL/SDC/QSF hashes.

Do **not** hide paths with unsupported false-path/multicycle exceptions or relax the clock merely to turn a report green. If 50 MHz cannot be met, a lower-clock build is a **new named experimental configuration**, not a 50 MHz PASS.

## 5. Stage 3 acceptance gates

- **G-A: evidence reconciliation.** Obtain all Stage 2 logs and the newest local Stage 3 outputs; verify SHA-256, command lines, exit codes, repository/overlay identity and warnings. Record contradictions rather than overwriting history.
- **G-B: constrained timing closure.** Fitter and post-fit STA PASS at 50 MHz under justified I/O, setup, hold, reset and clock constraints, with no unresolved mandatory paths. Preserve exact reports for the passing SOF.
- **G-C: functional non-regression.** Re-execute relevant 98 host, 720 RV32, RAM/UART, sv2v and Q15 SoC gates for the **exact modified build**, or explicitly explain and audit changed counts. One functional mismatch FAILS the corresponding gate.
- **G-D: board bring-up, only after safe hardware preflight.** Record board identity and pins; program the exact SOF only with operator authorization; audit actual UART frames and frozen Q15 predictions. Pilot 42 cases precede a full 360-input campaign.
- **G-E: publishable measurement readiness.** Fix a new target/ELF/SOF/campaign identity and measurement schema before any comparisons. Board timing is not imported from Ibex Simple System.

Stop work at the first structural or correctness mismatch. Missing artifacts are **UNCERTAIN**, not zero errors.

## 6. H / T / D / C / U

- **H:** The frozen seed-63 Q15 functionality can be preserved in a DE0-CV build that closes 50 MHz STA and runs on a precisely identified board.
- **T:** Audit exact SDC and worst paths; apply minimal, reviewed fixes; rerun functional regressions; test 42 on-board pilot cases, then frozen campaigns. Keep all rejects and failures.
- **D:** PASS only when timing closure, target identity, regression and real board evidence all satisfy their separate gates. FAIL on an actual violation. UNCERTAIN where raw evidence is missing.
- **C:** A real logic/routing critical path, incorrect or missing timing constraints, non-equivalent RAM behaviour, UART framing and unexpected resets can each invalidate acceptance.
- **U:** PVT/STA corners, clock tolerance, capture resolution, UART integrity, board voltage/temperature and provenance limitations remain explicit; no fabricated combined uncertainty \(u_c\) or coverage \(k\).

## 7. Integration policy

Keep historical 2026-10-30 and 2026-11-02 stage-gate documents as evidence of **their** dates; do not silently rewrite old NOT_RUN rows. Stage 2 achievements may update the latest state only after importing the relevant logs and confirming actual source/build identity.

Any separate paper-analysis overlay and the Codex Stage 2 workspace must be diff-reviewed before merging. Do not conflate campaign SHA versions. This note is documentation only and does not change firmware, models, bitstreams, deadline bindings or reported scientific conclusions.

Related: [existing physical-stage preregistration](realtime_nn_de0_cv_next_stage.md); [paper campaign handoff](de0_cv_paper_protocol_2026-11-06.md); [Codex procedure](de0_cv_codex_handoff_2026-11-06.md).
