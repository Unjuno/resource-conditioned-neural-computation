# Stage C3 Gate A — final C2 source provenance and reproducibility

Date: 2026-11-14 JST

Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation`

Work branch: `codex/stage-c3-repro-timing-20261114`

## Gate A status

**PASS for the recovered C2 D101 configuration's source identity and the recorded 42-case regressions.** The key missing source was recovered from the preserved `rtnn_c2_bundled_capture_20261113_native` build. Its capture-pending mailbox SHA-256 is `b4107f64666f27f798be25ba013a15a7f993c9d5bde07b7f9fa241ca498871d0`. The matching `rtnn_c2_soc_flat_corrected.v` in the paired sv2v workspace is byte-identical to the D101 Quartus flat input, SHA-256 `fdfcdf037eb55225e3e6eef06b01fc92e608951c54ece946461408131f2e5ca7` (719,656 bytes). The corresponding preserved D101 Quartus project used the same flat SHA and has a successful Quartus compile log and a SOF with SHA-256 `878dd27ee42e17073e7cb937fbc0d67ae1ee53f59aee619907a00d433f5f19f4`.

This closes the previous BLOCKED finding about missing `req_capture_pending_sys_q` and `rsp_capture_pending_tck_q`: they are present in the recovered SystemVerilog mailbox. The earlier 2FF capture-delay candidate (mailbox SHA `363a0f3bd601f9c3f2f53d635e1da54887e6754cda2fc4774b43c3fb969fb96f`) remains a different implementation and is not used to identify the D101 source.

## Provenance and fixed inputs

The recovered native graph contains 146 SystemVerilog entries. Its ordered source list is SHA-256 `777887085c1ae9ad6bf4b6f0376185fcc98c5eb74eb0600bc041219004948e03`; per-source hashes are in `candidate_native_source_sha256.txt`, whose SHA-256 is `b29ca3ff7fdefff5f904ab4f8c1421a50b5e8322334b5d6a865c0ab6d72cd696`. All 146 referenced files resolved in the preserved WSL/tool and old-worktree locations. The Ibex checkout is clean at commit `7b5df75a041affe56e8c235260f98a09b3319008`. The graph's four project overlay files are kept in the original old worktree and their paths/hashes are recorded in the per-source list; the old `kardaneh/RTnn` repository was read-only and unchanged.

Frozen model header SHA-256: `961a76b7e220bf2f665e7c04ab62063600aa2e7eccf3403d80ea730bc993ad9f`.

Quartus inputs recovered and preserved here:

| File | SHA-256 |
|---|---|
| `final_candidate_rtnn_c2_soc_flat.v` | `fdfcdf037eb55225e3e6eef06b01fc92e608951c54ece946461408131f2e5ca7` |
| `rtnn_c2_vjtag_mailbox_final_candidate.sv` | `b4107f64666f27f798be25ba013a15a7f993c9d5bde07b7f9fa241ca498871d0` |
| `final_candidate_rtnn_c2.qsf` | `6dfde92473708e4697c869d423c1c532f1c5dd27fc27749cb0b293a73d9527d1` |
| `final_candidate_rtnn_de0_cv_c2.sdc` | `8ba18e9829ebb9754278867948a1b0fffb360144738f1c3e45f1650592a87690` |
| `final_candidate_rtnn_c2.sof` | `878dd27ee42e17073e7cb937fbc0d67ae1ee53f59aee619907a00d433f5f19f4` |

The QSF targets Cyclone V `5CEBA4F23C7`, top `rtnn_de0_cv_c2_top`, and names the flat Verilog plus the board top and global buffer. The SDC and QSF have been preserved. The SOF is the recovered bundled-capture image, not the separately reported physical-run SOF (`5aa5be...`). This artifact identity distinction must be retained.

## Recorded regression evidence

The preserved WSL command for native RTL is `bash ./run.sh` in `/mnt/d/rtnn_c2_bundled_capture_20261113_native`. It consumes the exact ordered 146-source list and runs Verilator 5.020 (`--binary --timing -Wall -Wno-fatal`, two build jobs). Its compile and simulation exitcode files currently say 2 because this workspace contains an earlier failed attempt. The later paired corrected sv2v run's preserved command is `bash ./run_corrected.sh` in `/mnt/d/rtnn_c2_bundled_capture_20261113_sv2v`; however its output files were subsequently overwritten by another failed run and its exitcode files also say 2. Accordingly, these original two workspace exitcode sentinels are **not** cited as successful evidence.

Successful, unambiguous regression evidence comes from the independently preserved `c3_gate_a_recheck_20261114` run in this repository:

| Path | Scope | Compile/run/audit |
|---|---|---|
| `native_compile.log`, `native_run.log`, `native_audit.log` | 146-source native SystemVerilog candidate | 0 / 0 / 0 |
| `sv2v_synthesis_compile.log`, `sv2v_synthesis_run.log`, `sv2v_synthesis_audit.log` | Full converted candidate graph with `SYNTHESIS` guard required by Verilator/Ibex coverage instrumentation | 0 / 0 / 0 |
| `candidate_full_sv2v_synthesis.v` | Converted graph output | SHA stored in adjacent `candidate_full_sv2v_synthesis.sha256` |

Each successful run passes the 42 frozen requests, two reset replays and seven negative/recovery cases. Native, converted and final-flat regression CSVs match byte-for-byte; SHA-256 `dd15b0f87e059c7279392ae4e59a647c63f78db5a278572ae34d8046d9cd002e`. The independent audit says `PASS_RTL_SIMULATION_ONLY`; it is not physical measurement evidence.

The initial sv2v attempt without `SYNTHESIS` failed on Ibex `ifndef SYNTHESIS` functional-coverage instrumentation (`gen_dummy_instr...lfsr_data.instr_type`). Using `SYNTHESIS` permits conversion/compile/run but also makes LowRISC `prim_assert.sv` choose dummy assertion macros. RTL SVA therefore did not execute in that Verilator run; the testbench's procedural CDC checks and negative/reset assertions did execute. Warnings were retained, and `-Wno-fatal` was used. The previous candidate warning inventory is recorded in this directory; do not interpret exit code 0 as warning-free or as a formal CDC proof.

The earlier Gate A audit's two-FF candidate diff is preserved as `source_vs_final_flat.diff`. It is superseded for source identity by the recovered capture-pending candidate, and remains useful as a rejected alternate.

## Quartus and timing caveat

The preserved recovered Quartus workspace has build files timestamped 2026-11-13 19:24 JST and logs identifying Quartus Prime Lite 25.1std.0 Build 1129. They contain successful Analysis & Synthesis, Fitter, Assembler and Timing Analyzer messages; this turn reviewed the preserved logs rather than rerunning the flow. Its Fitter summary reports 4,034 / 18,480 ALMs, 6,293 registers, 2,097,152 block-memory bits (256 / 308 RAM blocks), and 3 DSP blocks. The STA summary reports positive slacks for the constrained `CLOCK_50` and `altera_reserved_tck` analyses; the minimum observed hold slack is +0.116 ns and the minimum observed setup slack is +0.821 ns across the four model corners represented in the archived report.

This is not Gate B signoff. The STA report still has an `Unconstrained Paths Summary`, and the compile log reports incomplete I/O assignments. The recovered archived STA script exits 1, and the post-fit Design Assistant sentinel also exits 1; their raw logs are retained outside the repository in the old build workspace. No claim is made that reset, all external JTAG I/O, CDC max-delay, or every required path has been fully constrained or accepted. Gate B remains BLOCKED pending full constraint/CDC/Design Assistant review and a successful fresh run.

## Decisions and next gates

* Gate A: **PASS**, limited to recovery and identity of the saved D101 flat/SOF build, and the recorded native/sv2v/final-flat frozen regression evidence above.
* Gate B: **BLOCKED**, due to unconstrained paths, incomplete I/O assignments, and failed archived STA/Design Assistant status sentinels.
* Gate C: **NOT_RUN** for a new C3 image. The recovered SOF above is not newly programmed and no Flash/CFM operation occurred.
* Gates D–F: **NOT_RUN**. No 360-input campaign, new statistics, or deadline guarantee was produced.

No Quartus rebuild, board programming, Flash/CFM change, push, PR, or merge was performed in this turn. The exact recovered source and build artifacts in this evidence directory are for reproducible review; the C2J2 physical run must continue to be identified by its own SOF SHA and run record.


The mapping in candidate_native_source_sha256.txt resolves the Linux /opt/rtnn-tools/ibex paths under the WSL tool installation, /mnt/c/.../RTNN paths under the preserved wrong worktree (read-only), and /mnt/d/... under the preserved D-workspace. It records per-file SHA-256 without copying or changing the old worktree. The ordered source graph file from the old build has SHA-256 777887085c1ae9ad6bf4b6f0376185fcc98c5eb74eb0600bc041219004948e03.

The standalone C3_BUNDLED_CAPTURE_EVIDENCE_SHA256.txt is a six-file quick identity list; C3_RECOVERED_BUILD_ARTIFACTS_SHA256.txt covers the preserved build artifacts copied into this repository. The final recovered bundle SOF (878dd27...) differs from the physical-run SOF identified in the C2 record (5aa5be...); the SOF used for the 42 physical cases remains the latter. Gate A is therefore provenance recovery for the archived build variant, not retroactive proof that the exact physical-run SOF is byte-identical to the recovered bundle output.

### Archived timing/Design Assistant details

The 2026-11-13 final Quartus flat build report set is preserved as `final_candidate_quartus_compile_corrected.log`, `final_candidate_rtnn_c2.fit.summary`, `final_candidate_rtnn_c2.sta.summary`, and `final_candidate_da_postfit.log`. The companion STA script and reports are also preserved. The STA report explicitly lists 2 unconstrained input ports (`altera_reserved_tdi`, `altera_reserved_tms`) with 41 setup/hold input paths, and 4 unconstrained outputs (`LEDR[0]`, `LEDR[1]`, `LEDR[3]`, `altera_reserved_tdo`) with 8 setup/hold output paths. Both `CLOCK_50` (20 ns) and `altera_reserved_tck` (33.333 ns) are identified as constrained clocks. Reported worst setup is +0.821 ns and worst hold +0.116 ns over the reported corners, but these numbers do not cover the unconstrained external paths.

The timing script explicitly collects 800 request bundled-data paths and 384 response bundled-data paths. Its report shows worst max net delays 3.358 ns (required 16 ns, slack 12.642 ns) and 3.157 ns (required 24 ns, slack 20.843 ns). The raw Tcl returns success, but these bounds alone do not prove mailbox data stability through the full synchronized handshake at every phase, nor do they classify the remaining unconstrained ports.

Post-fit Design Assistant completed successfully as a tool process but reported D101 High: 801 asynchronous clock-domain interface structures (“data bits are not synchronized”). The run log was truncated to 30 node messages by Quartus; it names request mailbox `req_hold_tck_q` bits and the report says the full compilation report is needed for all 801. No blanket D101 waiver is claimed here. The C2 audit package describes a separate per-node disposition of 801 nodes; that supporting full disposition and a protocol/hold-time proof have not been independently reconstructed in this Gate B pass. The recovered build's DA exit sentinel is 0, not evidence that the warning is resolved.

The old workspace’s STA and Design Assistant exit sentinels are 0 for this `bundled_capture` run; the earlier `bundle_scoped_d101` workspace has distinct sentinels and must not be substituted. This correction supersedes the initial wording above that called the recovered STA script/DA sentinels failed. Gate B is still BLOCKED because the external ports and D101 warnings have not been fully justified/closed, even though the tools ran successfully.
