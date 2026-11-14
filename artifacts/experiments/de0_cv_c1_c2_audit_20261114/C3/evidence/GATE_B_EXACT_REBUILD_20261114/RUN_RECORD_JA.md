# Gate B: exact-input Quartus rebuild audit

* Date: 2026-11-14 JST
* Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
* Branch at run: `codex/stage-c3-jtag-pilot-20261114`
* HEAD before this evidence addition: `94870227ae920fe4064c2eeadccac231bc04f074`
* Result: **BLOCKED for full board timing signoff**; exact-input compile, internal STA, CDC path audit and scoped D101 audit reproduced.

## Run identity and preservation

The source evidence remains in `C2/evidence/quartus_d101/`. Quartus compiled byte-for-byte copies in `D:\rtnn_c3_gateb_exact_rebuild_20261114`; it did not run in the repository, alter C2 evidence, program the board, or touch flash. The only repository changes from this work are this C3 evidence directory and its hash-manifest entries.

Tool: Quartus Prime Lite 25.1std.0 Build 1129 (10/21/2025), installed at `C:\altera_lite\25.1std`.
Compile command: `quartus_sh.exe --flow compile rtnn_c2`
Compile cwd: `D:\rtnn_c3_gateb_exact_rebuild_20261114`
Observed process exit: 0; full compilation successful; 0 errors, 392 warnings; elapsed 00:09:53. `quartus_sh_compile.exitcode` preserves the exit sentinel.
DRC command: `quartus_drc.exe rtnn_c2 -c rtnn_c2`
DRC cwd: same; observed process exit: 0; Design Assistant 0 errors, 0 warnings.
Four-corner CDC command: `quartus_sta.exe -t allcorners_cdc_audit_disposition.tcl`
Four-corner audit cwd: same; observed script exit: 0; four operating conditions reported.

Inputs were byte-identical to the stored C2 inputs. Their full basename/hash list is `input_SHA256SUMS.txt`; key input hashes:

| Input | SHA-256 |
|---|---|
| `rtnn_c2.qsf` | `9d270c2f57ca7f6ee1f68f4d525a685625a7cc5311b0a55ee363e23f823f675e` |
| `rtnn_de0_cv_c2.sdc` | `8ba18e9829ebb9754278867948a1b0fffb360144738f1c3e45f1650592a87690` |
| `rtnn_c2_soc_flat.v` | `fdfcdf037eb55225e3e6eef06b01fc92e608951c54ece946461408131f2e5ca7` |
| `rtnn_de0_cv_c2_top.sv` | `639e58115cc2f249b7aceb9e89fd2670896c5810ea442c31836926ac3bed5d5a` |
| `rtnn_c2_global_buf.v` | `98d4ac6fc5b541197efc046e647af0537f68a42789b3c8fce4872ae60e125a5a` |
| `rtnn_ram_lane0.hex` | `7704b387d02830327de288cfcced5d1a485c75b6f0cb838db1da4e87661f5f5a` |
| `rtnn_ram_lane1.hex` | `8c98d35b71595a0fc6fb40be2177dbac3883b4439a5ae894355bd3c3288af1c6` |
| `rtnn_ram_lane2.hex` | `8e8d201adf2f8e383d42bb116d75fa3e0fb6675d8bf96c694a8fc969547d5873` |
| `rtnn_ram_lane3.hex` | `affa1411c8c1ea6c443b2b6729502b58b63a6561fcf3177c65d7f34e635e1d11` |

## Fitter, STA, CDC

Fitter succeeded for Cyclone V QSF `DEVICE` value `5CEBA4F23C7`, top `rtnn_de0_cv_c2_top`. The DE0-CV board/FPGA is identified by the full orderable part `5CEBA4F23C7N`; Quartus omits the `N` lead-free suffix in its selected-device display, as Altera documents. The `F23` package designation is confirmed by Altera's Cyclone V 5CEBA4 pin-information document. The QSF itself does not contain the trailing `N`. Resource use: 4,034/18,480 ALMs (22%), 6,293 registers, 256/308 RAM blocks (83%), 3 DSP blocks, 0 PLLs. No logic retiming improvement was reported. ([Altera Quartus Prime software support](https://docs.altera.com/r/docs/683121/current/the-automotive-grade-device-handbook/quartus-prime-software-support), [Cyclone V 5CEBA4 pin information](https://docs.altera.com/api/khub/documents/1NKb_F4CYX7DE7fZeiacWA/content))

The regenerated STA report has positive internal slack in all four Quartus operating conditions. Worst setup is +0.821 ns (Slow 1100mV, 85C, `CLOCK_50`); worst hold is +0.116 ns (Fast 1100mV, 0C, `CLOCK_50`). `CLOCK_50` remains constrained at 20 ns (50 MHz). The SLD hub's HDL-embedded SDC creates a nominal `altera_reserved_tck` at 30 MHz; this is not a measured USB-Blaster clock.

The reproduced unconstrained-path summary is **not zero**:

* 2 unconstrained input ports and 41 input-port paths: `altera_reserved_tdi`, `altera_reserved_tms`. The raw report includes paths from TDI into user RTL, including `req_shift_tck_q[799]`; reserved JTAG naming alone is not grounds for excluding those paths.
* 4 unconstrained output ports and 8 output-port paths: `altera_reserved_tdo`, `LEDR[0]`, `LEDR[1]`, `LEDR[3]`.
* No unconstrained clocks. Quartus explicitly reports setup and hold are not fully constrained.

The SDC has no broad user-authored TCK/system-clock false path. Its reset exceptions are limited to asynchronous reset assertion/release synchronizer endpoints. The SLD hub's embedded SDC does apply `set_clock_groups -asynchronous -group {altera_reserved_tck}`, which cuts ordinary cross-domain setup/hold transfer analysis between TCK and other clocks. The existing bundled-data protocol uses held request/response buses with toggle/acknowledge synchronization. The four-corner path audit rechecked 800/800 same-index request data paths and 384/384 response data paths; actual worst net delays remained below the existing 16 ns and 24 ns bounds, respectively. These explicit net-delay checks are independent of the clock-group exception, but do not prove setup/hold, max skew, earliest capture, or external JTAG timing. The raw `report_max_skew` outputs contain `Nothing to report.` in all four corners, so max-skew is **NOT_EVALUATED**, not a pass.

Design Assistant's exact local D101 disposition audit passed: 801 explicit local D101 suppressions (800 request hold registers and the one recorded response representative), with global D101/D102/D103 enabled, zero high-severity violations and zero DA errors/warnings. The full DRC report, including its local suppression inventory, is preserved in `rtnn_c2.drc.rpt`; local suppressions are documented rather than treated as absent findings. A fresh `report_metastability -nchains 1000` run found 392 chains: 9 reset/scalar-control synchronizer chains were calculated and included in Design MTBF, while 383 uncalculated rows are automatically grouped response-payload paths (381 unique bit pairings plus two duplicate aliases), not 383 scalar synchronizers. The full 31,751,098-byte report has SHA-256 `00120db779ae93c5aaf3bc083bbafd8259cdf2c3ffda5cdd9920ca328faef038`, identical to the prior exact-input report; its local D: path and extraction summary hash are in `c3_mtbf_report_identity.json`.

The corrected phase analysis establishes that the payload is captured on the third destination edge, but arbitrary source/destination phase leaves only **two complete destination periods** from source update to that capture: 40 ns request (20 ns `CLOCK_50`) and 60 ns response (30 ns minimum TCK). The earlier 60/90 ns comparison overstated this interval and has been superseded. The route-only path maxima remain 3.358/3.157 ns; subtracting these from 40/60 ns gives 36.642/56.843 ns, explicitly **not STA slack** because this route-only report omits clock-to-Q, destination setup, clock uncertainty, and physical TCK envelope.

A focused, non-production TimeQuest experiment is preserved under `focused_cdc_recheck_20261114/`. With the original SLD asynchronous clock group present, adding 40/60 ns `set_max_delay` checks produced no setup paths; adding 20 ns `set_max_skew` checks likewise produced Quartus Warning 332182 (“No path is found”) and `Nothing to report` in every corner. For diagnosis only, a separate in-memory Tcl run issued `remove_clock_groups -all` (the source SDC/QSF/RTL were not changed), applied 40 ns request and 60 ns response max delays, and found 800/800 and 384/384 setup paths with zero violations at all four corners. Worst slack by corner was request +32.704, +32.957, +36.018, +36.381 ns and response +57.936, +57.933, +58.625, +58.780 ns. This isolates a promising protocol-bounded data-path result, but is **not** final CDC signoff: removing all clock groups globally in the diagnostic run also changes unrelated crossings, one-bit synchronizer paths have not yet been given a complete targeted exception/constraint policy, and the board-level JTAG I/O timing remains open. Firmware/RTL source-hold identity and order audit also passed. The corrected route-envelope and focused path checks therefore remain limited internal evidence, not full board-level CDC/timing signoff.

## Bitstream identity

The historical C2 physical SOF remains unchanged at SHA-256 `5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6`. The exact-input rebuild generated a 2,446,808-byte SOF with SHA-256 `995633cf36043355a8ae7ae0375e200a1c52834e88480161939ef667e7e13319`; 4,085 byte positions differ from the historical SOF. This rebuilt candidate is retained under the explicit `NOT_PHYSICALLY_TESTED` filename and was not loaded to the FPGA. Equal RTL/QSF/SDC/input hashes and matching broad fitted resource/timing summaries do not establish bitstream equivalence. The build reports do not yet explain all SOF byte differences; this remains a reproducibility question. Do not substitute the candidate for the historically measured SOF.

## Warnings and decision

The 392 compiler warnings are retained in `quartus_sh_compile.log`; they include repeated unused Ibex signal warnings, processor-count notices, the Lite-only LogicLock feature notice, and incomplete I/O assignment warnings. Fitter ended with 0 errors and 3 warnings; STA ended with 0 errors and 1 warning. The explicit incomplete pin assignment warning and unconstrained external/status endpoints remain visible. Design Assistant's zero-warning summary applies only to its enabled/checkable rules and does not override STA's unconstrained-path result.

During this re-audit, the copied path-audit helper was found to search only for `No paths were found`, while Quartus's four raw skew reports say `Nothing to report.`. Its first JSON therefore encoded four false booleans, not a measured skew result. The C3-scoped helper now records each corner as `NOT_EVALUATED`, preserves the original JSON as `c2_postfit_path_audit.pre_fix_20261114.json`, and reruns with exit 0 for path coverage/net-delay checks. The raw outputs remain the governing evidence; no max-skew PASS is claimed.

Gate B remains **BLOCKED**. Official Cyclone V JTAG endpoint numbers do not provide the DE0-CV onboard USB-Blaster/CPLD/PCB/cable propagation and skew, and the installed `jtagconfig --getparam 1 JtagClock` query failed with “No parameter named JtagClock”; actual external TCK is still unknown. USB-Blaster III/Cable-II example delays are not transplanted to this onboard USB-Blaster. No false paths or relaxed constraints were added to the source SDC. Remaining internal CDC work includes a final targeted exception/constraint policy for one-bit synchronizers, acknowledgement paths, and bundled-data capture paths; the experimental 40/60 ns checks are not yet part of the production SDC. External closure also needs board/cable-specific TDI/TMS-to-TCK and TDO timing (or a defensible validated measurement model), plus a documented endpoint policy for status LEDs. Only then should the SDC be revised and all gates rerun. Gate C for this new rebuilt SOF is NOT_RUN; the already-completed historical C3 24,840-row empirical campaign is not invalidated, and it remains bound only to its recorded tested SOF. No new candidate-specific Gate D campaign was run.

## Evidence index

`quartus_sh_compile.log`, Fitter/map/STA/DRC reports, four-corner path/skew/net-delay reports, D101 and path audit JSON, audit Tcl/scripts, candidate SOF, and `SHA256SUMS.txt` are stored alongside this record. The full repository-relative input evidence is kept at `C2/evidence/quartus_d101/` and was not rewritten.
