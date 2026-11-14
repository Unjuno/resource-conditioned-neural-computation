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
Observed process exit: 0; full compilation successful; 0 errors, 392 warnings; elapsed 00:09:53.
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

Fitter succeeded for Cyclone V `5CEBA4F23C7` (QSF part selection retains package `N`), top `rtnn_de0_cv_c2_top`. Resource use: 4,034/18,480 ALMs (22%), 6,293 registers, 256/308 RAM blocks (83%), 3 DSP blocks, 0 PLLs. No logic retiming improvement was reported.

The regenerated STA report has positive internal slack in all four Quartus operating conditions. Worst setup is +0.821 ns (Slow 1100mV, 85C, `CLOCK_50`); worst hold is +0.116 ns (Fast 1100mV, 0C, `CLOCK_50`). `CLOCK_50` remains constrained at 20 ns (50 MHz). The SLD hub's HDL-embedded SDC creates a nominal `altera_reserved_tck` at 30 MHz; this is not a measured USB-Blaster clock.

The reproduced unconstrained-path summary is **not zero**:

* 2 unconstrained input ports and 41 input-port paths: `altera_reserved_tdi`, `altera_reserved_tms`.
* 4 unconstrained output ports and 8 output-port paths: `altera_reserved_tdo`, `LEDR[0]`, `LEDR[1]`, `LEDR[3]`.
* No unconstrained clocks. Quartus explicitly reports setup and hold are not fully constrained.

The SDC has no broad user-authored TCK/system-clock false path. Its reset exceptions are limited to asynchronous reset assertion/release synchronizer endpoints. The SLD hub's embedded SDC does apply `set_clock_groups -asynchronous -group {altera_reserved_tck}`, which cuts ordinary cross-domain setup/hold transfer analysis between TCK and other clocks. The existing bundled-data protocol uses held request/response buses with toggle/acknowledge synchronization. The four-corner path audit rechecked 800/800 same-index request data paths and 384/384 response data paths; actual worst net delays remained below the existing 16 ns and 24 ns bounds, respectively. These explicit net-delay checks are independent of the clock-group exception, but do not prove setup/hold, max skew, earliest capture, or external JTAG timing. `report_max_skew` returned “No paths were found” in all four corners, so no skew result is claimed.

Design Assistant's exact local D101 disposition audit passed: 801 explicit local D101 suppressions (800 request hold registers and the one recorded response representative), with global D101/D102/D103 enabled, zero high-severity violations and zero DA errors/warnings. The raw warning inventory is preserved in `rtnn_c2.drc.rpt`; local suppressions are documented rather than treated as absent warnings. The metastability report found 392 synchronizer chains but says 97.7% could not have MTBF calculated; therefore this is not a complete quantitative CDC reliability signoff.

## Bitstream identity

The historical C2 physical SOF remains unchanged at SHA-256 `5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6`. The exact-input rebuild generated a 2,446,808-byte SOF with SHA-256 `995633cf36043355a8ae7ae0375e200a1c52834e88480161939ef667e7e13319`; 4,085 byte positions differ from the historical SOF. This rebuilt candidate is retained under the explicit `NOT_PHYSICALLY_TESTED` filename and was not loaded to the FPGA. Equal RTL/QSF/SDC/input hashes and matching broad fitted resource/timing summaries do not establish bitstream equivalence. The build reports do not yet explain all SOF byte differences; this remains a reproducibility question. Do not substitute the candidate for the historically measured SOF.

## Warnings and decision

The 392 compiler warnings are retained in `quartus_sh_compile.log`; they include repeated unused Ibex signal warnings, processor-count notices, the Lite-only LogicLock feature notice, and incomplete I/O assignment warnings. Fitter ended with 0 errors and 3 warnings; STA ended with 0 errors and 1 warning. The explicit incomplete pin assignment warning and unconstrained external/status endpoints remain visible. Design Assistant's zero-warning summary applies only to its enabled/checkable rules and does not override STA's unconstrained-path result.

Gate B remains **BLOCKED**. Official Cyclone V JTAG endpoint numbers do not provide the DE0-CV onboard USB-Blaster/CPLD/PCB/cable propagation and skew, and the installed `jtagconfig --getparam 1 JtagClock` query failed with “No parameter named JtagClock”; actual external TCK is still unknown. USB-Blaster III/Cable-II example delays are not transplanted to this onboard USB-Blaster. No false paths or relaxed constraints were added. Required next evidence is board/cable-specific TDI/TMS-to-TCK and TDO timing (or a defensible validated measurement model), plus a documented endpoint policy for status LEDs. Only then should the SDC be revised and all gates rerun. Gate C for a new rebuilt SOF and Gate D remain unstarted for this candidate; historical C2 empirical evidence remains separately valid only for its recorded SOF.

## Evidence index

`quartus_sh_compile.log`, Fitter/map/STA/DRC reports, four-corner path/skew/net-delay reports, D101 and path audit JSON, audit Tcl/scripts, candidate SOF, and `SHA256SUMS.txt` are stored alongside this record. The full repository-relative input evidence is kept at `C2/evidence/quartus_d101/` and was not rewritten.
