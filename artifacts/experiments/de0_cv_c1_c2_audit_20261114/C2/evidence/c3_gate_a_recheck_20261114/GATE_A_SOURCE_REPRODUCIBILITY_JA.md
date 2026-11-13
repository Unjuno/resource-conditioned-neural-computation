# Stage C3 Gate A — C2 source provenance and independent regression

Date: 2026-11-14 JST

Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation`

Base: `codex/de0-cv-c1-c2-audit-20261114` at `fc4923d7275e8cbaf0bcf4aa2e62f974390bd377`

Work branch: `codex/stage-c3-repro-timing-20261114`

Outcome: **BLOCKED for final-SystemVerilog provenance; candidate-source native and sv2v regressions PASS.**

## Scope and preservation

The C2 audit package and final Quartus flat input were read without changing them. The former `kardaneh/RTnn` worktree was not modified. One directly referenced C2 CSA overlay missing from the archived source package was copied read-only from the old worktree into `C2/source/ibex_integration/ibex_multdiv_fast.csa.sv`; source and copy SHA-256 both equal `f74def2c52d42c46dffbabdb1e114dab10fe5120412d9ad7240d427d9ee0f7b0`. The original file remains untouched.

Generated Verilator objects were written under `%LOCALAPPDATA%\Temp\rtnn_c3_gateA_*_20261114`, outside Git. Raw compile/run logs, source list, source hash list, converted candidate RTL, and audit outputs are retained in this directory. Frozen weights, reference vectors, original C1/C2 evidence, SOF, QSF, and SDC were not changed.

## Provenance findings

The final D101 Quartus project QSF names `rtnn_c2_soc_flat.v` as its RTL input; its build log locates `rtnn_c2_vjtag_mailbox` inside that flat file. Final flat SHA-256 is `fdfcdf037eb55225e3e6eef06b01fc92e608951c54ece946461408131f2e5ca7`. The archived Quartus input does not name or identify the 146-entry SystemVerilog source graph that generated this flat file.

The preserved FuseSoC-derived source list has 146 entries and SHA-256 `4bddc5bd5e37cbd24015189d49e4a21677d570e5cb1c0a7c9dd503da30e6bfba`. It uses Ibex commit `7b5df75a041affe56e8c235260f98a09b3319008`; the checkout is clean. Its mailbox is the capture-delay candidate, SHA-256 `363a0f3bd601f9c3f2f53d635e1da54887e6754cda2fc4774b43c3fb969fb96f`. Its regenerated complete sv2v RTL differs from the final Quartus flat. The mailbox difference is substantive:

- Candidate source uses two-stage 800-bit request and 384-bit response bus registers (`req_bus_sync1/2_sys_q`, `rsp_bus_sync1/2_tck_q`) before capture.
- Final Quartus flat has no such bus synchronizer registers. On its capture-pending edge it samples `req_hold_tck_q` and `response_data_i` directly.

These implementations produce identical recorded CSV output for the 42 frozen requests and negative/reset checks, but the CDC source is not identical and functional agreement on these vectors does not prove source identity or timing equivalence. Therefore the candidate graph cannot be relabeled as the source of the final D101 SOF.

Candidate complete sv2v RTL SHA-256 is `d93ed8b4c30a0e4e51d657730095aa9114d23794c12e62068267b405be63ead2` (720,081 bytes). Final flat SHA-256 is above (719,656 bytes). The retained unified diff shows the mailbox bus-path differences and a small `unused_scramble_inputs` declaration difference. The CDC difference alone is sufficient to keep provenance blocked.

Other unchanged identities from the audited C2 build: Quartus Prime Lite 25.1std.0 Build 1129; device `5CEBA4F23C7`; build ID `43324a32`; QSF SHA-256 `9d270c2f57ca7f6ee1f68f4d525a685625a7cc5311b0a55ee363e23f823f675e`; SDC SHA-256 `8ba18e9829ebb9754278867948a1b0fffb360144738f1c3e45f1650592a87690`; SOF SHA-256 `5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6`; seed-63 Q15 weight-header SHA-256 `961a76b7e220bf2f665e7c04ab62063600aa2e7eccf3403d80ea730bc993ad9f`.

## Regression results

Working directory for WSL runs was this directory under `/mnt/c/Users/junny/OneDrive/ドキュメント/ChatGPT/resource-conditioned-neural-computation-audit-20261114/artifacts/experiments/de0_cv_c1_c2_audit_20261114/C2/evidence/c3_gate_a_recheck_20261114`.

| Candidate configuration | Command / tool | Compile | Run | Independent audit |
|---|---|---:|---:|---:|
| Native SystemVerilog, 146-source list | `bash ./run_candidate_native.sh`; Verilator 5.020 `--binary --timing -Wall -Wno-fatal`, 2 jobs | 0 | 0 | 0 |
| sv2v converted, all 146 sources, `SYNTHESIS` defined to omit Ibex `ifndef SYNTHESIS` functional-coverage instrumentation | `bash ./run_candidate_sv2v_synthesis_guard.sh`; sv2v 0.0.13 then same Verilator flags | 0 | 0 | 0 |
| First all-source sv2v attempt without synthesis guard | `bash ./run_candidate_sv2v.sh` | 1 | NOT_RUN | — |
| Corrected conversion but malformed Verilator `-D SYNTHESIS` argument (two tokens) | preserved `*_macro_arg_attempt.*` | 1 | NOT_RUN | — |

The unguarded sv2v output failed in Verilator at the Ibex functional coverage member reference `gen_dummy_instr.dummy_instr_i.lfsr_data.instr_type`; Verilator reported unsupported member access and an internal width error. The code is inside `ifndef SYNTHESIS` in `ibex_if_stage.sv`. Repeating with `SYNTHESIS` removes that coverage-only block. **LowRISC `prim_assert.sv` selects dummy `ASSERT_*` macros when either `VERILATOR` or `SYNTHESIS` is defined, so these runs do not execute Ibex RTL SVA assertions.** The testbench's procedural CDC checks, `$fatal` comparisons, seven negative/recovery cases, and result audit do execute. This is a limitation of this regression and is not described as SVA verification. The successful warning log has 210 warnings: ASCRANGE 1, BLKSEQ 4, DECLFILENAME 1, PINCONNECTEMPTY 80, SYNCASYNCNET 2, UNOPTFLAT 3, UNUSEDPARAM 23, UNUSEDSIGNAL 3, WIDTHEXPAND 91, WIDTHTRUNC 2. `-Wno-fatal` was used; warnings are retained, not suppressed from the report.

Both successful configurations passed 42 frozen cases, two reset replays, and seven negative/recovery cases. Independent audit status is `PASS_RTL_SIMULATION_ONLY`; no hardware measurement is inferred. Native, sv2v, and final-flat result CSVs are byte-identical, each SHA-256 `dd15b0f87e059c7279392ae4e59a647c63f78db5a278572ae34d8046d9cd002e`.

Verilator version: `5.020 2024-01-01 rev (Debian 5.020-1)`. sv2v version: `0.0.13`. The full 146-source SHA list and the 65-file C3 evidence manifest are `native_source_sha256.txt` and `SHA256SUMS_C3_GATE_A_20261114.txt`; both were rechecked with zero hash mismatches.

The first remapped source-list attempt exposed Windows CRLF (`\r`) characters in path lines; that presence-check log is preserved as `native_source_presence_crlf_attempt.*`. The runner was corrected to strip CR at read time. No source content was changed to address that harness issue.

## Gate decision

**Gate A remains BLOCKED.** Established: the final Quartus input flat RTL is preserved and hash-identified; the fixed-Ibex 146-entry candidate graph and pinned Ibex commit are identified; the candidate native and sv2v simulations match the final flat regression byte-for-byte for the frozen regression set. Missing: a traceable source snapshot/manifest linking the final D101 flat RTL/SOF to its actual SystemVerilog mailbox and all upstream sources. The candidate mailbox is observably different, so patching only missing signal names or promoting it to final-source status would be incorrect.

Required to close Gate A: recover the exact SystemVerilog source snapshot and source-to-flat conversion command/manifest used to create the D101 input, or establish a new, explicitly versioned C3 source/build from the preserved candidate graph and rerun Quartus against that build. The latter would be a new configuration and cannot retroactively prove the provenance of C2J2 SOF `5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6`.

Gate B, C, D, and E were not started under the ordered-gate rule. No new Quartus build, SRAM programming, Flash/CFM operation, 360-input measurement, or statistical claim was made.
