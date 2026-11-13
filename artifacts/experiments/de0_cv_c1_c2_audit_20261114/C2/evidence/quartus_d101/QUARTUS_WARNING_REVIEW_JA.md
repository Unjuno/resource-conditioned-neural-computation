# Quartus warning review — exact-node disposition candidate

Date: 2026-11-13 (JST)  
Build: C2J2 / `43324a32`; Quartus Prime Lite 25.1std.0 Build 1129  
Source log: `quartus_compile_d101_exact_disposition.log`  
Total: 392 Quartus warnings; no warning was suppressed or converted into a pass.

| Warning | Count | Review |
|---|---:|---|
| 10335, unrecognized synthesis attributes | 216 | 108 `full_case` and 108 `parallel_case` attributes on the generated flat SystemVerilog are not recognized by Quartus. They are optimization hints, not functional statements. Kept visible; no source edit was made to remove them. Their effect on Quartus optimization should be revisited if the supported RTL path changes. |
| 10766, ignored `full_case` attribute on explicit-default cases | 76 | Quartus says it ignores the attribute because those `case` statements have explicit `default` branches. This is redundant-hint behavior; logic was not changed to clear the warning. |
| 10036, assigned but never read | 89 | All reported object names are explicitly marked `unused_*` in the fixed Ibex/SoC wiring, except one generated `_sv2v_0` helper. These are output/tie-off observability signals rather than missing assignments. The full instance/line list remains in the compile log. |
| 10230, width truncation | 4 | At flat RTL line 6876, `32 - operand_b_i[4:0]` produces 1..32 and is narrowed to six bits, which represents that full range. At lines 6894-6895, a 32-bit unsized literal zero narrows to one bit and remains zero. At line 7699, `cm_stack_adj_base(rlist)` is 0/16/32/48/64 and `spimm*16` is 0/16/32/48; the sum is at most 112 and fits the seven-bit result. No code change was made. |
| 12473, processor count | 3 | The build was configured to use one processor although 14 are available. This affects compile time only. |
| 13024 / 13410, stuck output | 1 + 1 | Fitter reports `LEDR[2]` stuck at GND. The top maps this bit to the `halted` status output. This is recorded as the fitted behavior; LEDR[2] therefore does not provide a changing hardware indicator in this build. |
| 15714, incomplete I/O assignments | 1 | The Fitter report specifies that `LEDR[0..3]` lack explicit drive-strength and slew-rate assignments. No values were invented or added. This remains an I/O implementation review item. |
| 292013, LogicLock license | 1 | Lite edition reports the subscription-only LogicLock feature unavailable. The candidate QSF has no LogicLock assignment; that feature is not used. |

The warning review does not close STA. The final Timing Analyzer report explicitly says setup/hold requirements are not fully constrained. It lists `altera_reserved_tdi`, `altera_reserved_tms`, `altera_reserved_tdo`, and LED outputs without I/O delays. The JTAG delay values cannot be inferred from the Cyclone V's FPGA-side setup/hold specifications alone because the DE0-CV routes its on-board USB-Blaster through an FT245BL and EPM240T100 CPLD. See `evidence/JTAG_TIMING_RESEARCH_20261113.md`.

The compile log, `.fit.rpt`, `.sta.rpt`, and `.drc.rpt` remain the authoritative full reports. This review is a classification and does not alter RTL, expected values, assertions, or timing exceptions.
