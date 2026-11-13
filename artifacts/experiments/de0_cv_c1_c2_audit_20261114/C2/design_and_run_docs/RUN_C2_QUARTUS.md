# Reproducing the C2 Quartus build

Project: `quartus_c2/rtnn_c2.qpf`
Device: `5CEBA4F23C7` (Cyclone V)
Tool used: Quartus Prime Lite 25.1std.0 Build 1129

From PowerShell:
```powershell
Set-Location quartus_c2
& 'C:\altera_lite\25.1std\quartus\bin64\quartus_sh.exe' --flow compile rtnn_c2
```

This exact source set elaborated `rtnn_de0_cv_c2_top` and `sld_virtual_jtag`, then Quartus Map exited 3 with Out of memory at 5,045 MB. No SOF was emitted. Fitter, STA and Design Assistant were not run. Preserve that failure record under `evidence/quartus_c2_v2_20261112/`. This project is not approved for board programming until all synthesis/timing gates pass.
## 2026-11-12 rerun result

The workspace v2 attempt (`evidence/quartus_c2_v2_20261112/`) failed in Map from memory pressure. A preserved-source rerun was performed on D: at `D:\rtnn_c2_quartus_v3_20261112` with input hashes recorded in `evidence/quartus_c2_v3_20261112/INPUT_SHA256SUMS.txt`. Direct command:

```powershell
Set-Location D:\rtnn_c2_quartus_v3_20261112
& 'C:\altera_lite\25.1std\quartus\bin64\quartus_sh.exe' --flow compile rtnn_c2
```

The v3 run reached auto JTAG debug fabric generation then exited 3 because Windows Device Guard blocked Quartus `ip-generate.exe`; Quartus could not elaborate `sld_hub:auto_hub`. The component was reported as **NotSigned** by Windows Code Integrity. Fitter, STA, Design Assistant, and SOF generation were not run. Do not bypass the organization policy. After the authorized policy resolution permits this component to execute, rerun the command in a fresh D: build directory, then require Fitter, all-corner STA, and Design Assistant before any SRAM-only board programming. The live JTAG enumeration currently passes read-only (`USB-Blaster [USB-0]`, IDCODE `02B050DD`), but no C2 image has been loaded.

## 2026-11-13 global-TCK reproducible project

A separate maintained candidate project now exists at `quartus_c2_globaltck/`; it routes Virtual-JTAG TCK through the Cyclone V global buffer and uses the 2026-11-13 C2J2 flat SoC/RAM inputs. The exact-input build completed after removing ineffective `set_max_skew` commands from the SDC. Compile, Fitter and Assembler exited 0. Full logs/reports are saved under `evidence/quartus_globaltck_repro_20261113/`. This candidate remains **not approved for board programming**: JTAG I/O timing and D101 CDC/DA closure are unresolved.

The official Cyclone V FPGA JTAG timing values and why they do not by themselves determine the on-board USB-Blaster CPLD path are recorded in `evidence/JTAG_TIMING_RESEARCH_20261113.md`.



## 2026-11-13 follow-up: exact-node D101 disposition candidate

The Windows Device Guard block described above is historical. Quartus Prime Lite 25.1 was subsequently able to complete a fresh full build in `D:\rtnn_c2_d101_disposition_20261113`; no Device Guard bypass was performed. The build generated a candidate SOF and completed Fitter/STA. Post-fit Design Assistant returned 0 errors, 0 warnings, and 0 High violations using 801 exact per-node D101 assignments. The global D101/D102/D103 rules remain enabled; the raw unwaived D101 report is preserved separately. Exact assignment syntax, evidence, and hashes are in `evidence/quartus_d101_exact_disposition_20261113/`.

All four corners contain complete request/response net-delay path coverage with positive reported net-delay slack. However, Timing Analyzer still explicitly reports that setup/hold requirements are not fully constrained, including JTAG and LED I/O. Therefore the C2 image is not yet approved for board configuration. The candidate SOF was not programmed, and Flash/CFM was not touched. Physical Virtual-JTAG transaction and 42-case measurements remain NOT_RUN.
