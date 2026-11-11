# DE0-CV C1 board self-test evidence update (2026-11-11)

**Status: operator-reported C1 autonomous Q15 self-test PASS on a physical DE0-CV; raw evidence has not been independently reviewed in this GitHub branch.** Not an external-input benchmark, calibrated clock result, statistically supported speedup, or WCET certificate.

This is a dated update to the [2026-11-06 evidence ledger](de0_cv_stage2_stage3_status_2026-11-06.md); do not erase the earlier 2026-11-03 negative 50 MHz setup result. The supplied chronology covers 2026-11-10/11, and the new local logs/reports were not made available as bytes here.

## 1. Latest reported gates

| Gate | Reported result | Precise claim boundary |
|---|---|---|
| Fixed Ibex + frozen Q15 simulation | 20-request autonomous self-test PASS; reset replay PASS | Functional regression on 20 prescribed cases, not arbitrary new inputs |
| sv2v | Same regression PASS after translation | Tested function consistency, not a universal RTL equivalence proof |
| Quartus Fitter / all-corner STA / post-fit Design Assistant | All PASS | Reported implementation closure for **this diagnostic configuration** |
| Worst setup slack | **+0.916 ns** | STA-derived slack at the declared clock/constraints, not measured oscillator accuracy |
| Worst hold slack | **+0.122 ns** | STA-derived hold slack under reported analysis conditions |
| SRAM configuration | Quartus Programmer reported success for diagnostic SOF; flash was not written | Volatile FPGA configuration; reload required after power loss |
| JTAG device check | IDCODE **02B050DD** before/after boundary scan | Device detection, not proof of inference contents or timing |
| Post-config boundary scan | **LEDR[3:0] = 1000** | Digital sample of pins driven by the configured design |
| Visual operator confirmation | **LEDR3 only illuminated** | Visible pins agree with JTAG sampled pins |
| SHA-256 | **145/145** files matched reported manifest | Integrity relative to that manifest, not independent semantic validation |
| Host-driven external USB-UART requests | **NOT_RUN**; 3.3 V interface needed | No host-selected arbitrary input/response campaign |
| Board oscillator actual frequency and ppm | **NOT_MEASURED** with calibrated instrument | No measured clock calibration |
| Full paper campaign and physical cycle comparison | **NOT_RUN** | No FPGA speedup, statistical noninferiority or hard-time bound |

The user reports that status reports and the manifest in the **local working tree** were updated, without a tracked-source commit. This note does not reproduce those logs and does not claim the remote GitHub branch contains their raw evidence.

## 2. LED result semantics

The C1 diagnostic RTL defines LEDR[3] as PASS, LEDR[2] as FAIL and LEDR[3:0]=1000 (only LEDR3 on) as the expected success output. The active-high red LED electrical convention is consistent with the [Terasic DE0-CV product and User Manual resources](https://www.terasic.com.tw/cgi-bin/page/archive.pl?CategoryNo=13&Language=English&No=921&PartNo=4). Seven-segment or unrelated status LEDs do not substitute for the red LED vector.

**Boundary scan and visual observation are two ways to observe the same PASS output, not two independent evaluations of 20 Q15 predictions.** The LED alone cannot prove that all cases were executed correctly unless the checker is audited.

Reported newly created RTL in the local working copy:
- de0cv_setup/stage3_experiments/ibex_csa_2026-11-03/c1_autonomous_selftest_20261110/rtnn_c1_selftest_checker.sv
- de0cv_setup/stage3_experiments/ibex_csa_2026-11-03/c1_autonomous_selftest_20261110/rtnn_c1_selftest_checker_tb.sv
- de0cv_setup/stage3_experiments/ibex_csa_2026-11-03/c1_autonomous_selftest_20261110/rtnn_c1_autonomous_selftest.sv

## 3. Independent review gate

Before publishing this as a fully verified C1 hardware functional result, retrieve the exact local 145-entry evidence manifest and:
1. compare source, ROM/RAM image, Q15 oracle, exact diagnostic SOF, board/IDCODE and all log hashes;
2. inspect checker request count, required expected predictions, trap/timeout/mismatch handling, positive and negative TB cases and PASS/FAIL latch and reset logic;
3. check that missing/incorrect cases **cannot** assert PASS;
4. inspect full-corner setup/hold reports, timing exceptions/unconstrained paths, pin assignment and JTAG/BSDL capture script;
5. determine whether a **physical KEY[0] reset-and-recovery** was observed: only reset replay in simulation is explicit in the supplied trace;
6. distinguish accepted 20-case self-test from 42-case migration pilot and frozen 360-input protocol.

JTAG IDCODE and a consistent SHA manifest strengthen provenance but do not attest to the semantic correctness of an uninspected checker. A new firmware or measurement SOF must have a **new** timing closure and source/build identity.

## 4. Next experimental sequence

1. Archive and audit latest C1 reports and source/bitstream evidence without rewriting historic Stage 2 failures.
2. If still absent, run and log physical KEY[0] reset recovery on the *same loaded* SOF; power-cycle/reload is a distinct test.
3. Enable controlled host inputs with a properly wired **3.3-V logic-level USB-UART** (never RS-232 voltages or 5 V). Verify echo, identities, CRC, monotonic sequence, timeouts, and exact Q15 oracle. If UART hardware cannot be acquired, separately design a versioned on-chip benchmark with explicit JTAG-readable results; exclude diagnostic transfer overhead from inference timing.
4. Reconcile the separate paper overlay, **13 existing schedules / 24,840 planned rows**, 360 frozen inputs and hashes *before* collection; do not silently alter the campaign.
5. Perform the 42-case board pilot, 2,520 fixed-exit census, 7,560 budget-class census, and registered paired fixed2/adaptive repetition schedule, with per-input, per-boot, per-run raw cycle and output captures. These are **future tasks**, not accomplished by C1.
6. Compute paired cycle advantage and accuracy noninferiority from complete audited captures. The previously documented 339/360 versus 339/360 offline accuracy does not prove a 1-percentage-point noninferiority criterion.
7. Separate a later target-specific deadline-binding and hard-WCET investigation. Observed maxima, LED PASS and STA closure alone are insufficient.

See [measurement protocol](de0_cv_paper_protocol_2026-11-06.md) and [Codex handoff](de0_cv_codex_handoff_2026-11-06.md).

## 5. H/T/D/C/U

- **H**: the exact deployed C1 checker asserts PASS if and only if all twenty prescribed frozen Q15 results match expected values on the board.
- **T**: inspect exact C1 checker and its negative tests, evidence-manifest hashes and final image identity; reproduce logged 20-case simulation and observable board gates. Distinguish on-board reset from simulation replay.
- **D**: operator-reported C1 self-test PASS; **independent audit UNCERTAIN** pending raw evidence. External UART, frequency calibration, paper cycle comparison and deadline evidence are NOT_RUN.
- **C**: stale SOF, incorrect BSDL pin map, prematurely latched PASS, truncated request set, failed trap detection and hidden reset bugs can yield false conclusions.
- **U**: clock tolerance and STA corner assumptions, UART acquisition, checker coverage, physical reset reproducibility and uninspected log provenance; no fabricated combined uncertainty or coverage factor.

This update does not change Q15 neural parameters, Simple-System cycle tables, firmware, FPGA designs or any already frozen campaign identity.
