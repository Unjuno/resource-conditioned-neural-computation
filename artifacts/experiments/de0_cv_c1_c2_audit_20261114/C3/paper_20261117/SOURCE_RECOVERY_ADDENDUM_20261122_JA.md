# RTL source recovery addendum (2026-11-22)

## Result

The previously missing project-owned source bytes have been recovered from the separate, correct Unjuno audit worktree at branch `codex/stage-c3-jtag-pilot-20261114`, HEAD `c13335d38c6ce478ad4a026f607ebf5890dc799b`. The five project-owned source variants are preserved byte-for-byte in `source_recovery_20261122/`; their hashes match the frozen 146-entry manifest. The pinned Ibex checkout is commit `7b5df75a041affe56e8c235260f98a09b3319008`.

**Updated source-level result: PASS, 146/146 hashes. Native Verilator simulation: PASS.** The explicit source map and five byte-exact project variants are now in the public research branch. A fresh clone of commit `6e07b86` used the tracked preparation script and passed the mapped native regression. This does not prove Quartus/SOF bit identity or board timing signoff. See [`CLEAN_CLONE_REGRESSION_RUN_RECORD_20261122_JA.md`](CLEAN_CLONE_REGRESSION_RUN_RECORD_20261122_JA.md).

The old 2026-11-21 reports remain unchanged as historical records. Their 145/146 result accurately describes that audit. The newer result supersedes it only for the explicitly mapped graph in this addendum.

## Why the byte variants are archived separately

The Windows worktree has `core.autocrlf=true`. The tracked text-file Git object for `ibex_top_gate_bypass.sv` has SHA-256 `1360b260617425c8e5ae3b9952940dcc39281b0b339210db5511cf811de93270`; its recovered raw bytes have the frozen expected SHA-256 `e1728fb66338b61a815a30062923698de7b6ff5e62d5c2bd3e996633254b3f50`. The difference is consistent with mixed CRLF/LF line endings normalized by Git's text conversion. No source file or frozen manifest was replaced. The archive directory contains `.gitattributes` with `* -text` so Git preserves all archived source, vector, and raw-log bytes as stored.

Five project-owned variants and expected SHA-256 values:

| Source | SHA-256 |
|---|---|
| `ibex_multdiv_fast.csa.sv` | `f74def2c52d42c46dffbabdb1e114dab10fe5120412d9ad7240d427d9ee0f7b0` |
| `ibex_top_gate_bypass.sv` | `e1728fb66338b61a815a30062923698de7b6ff5e62d5c2bd3e996633254b3f50` |
| `rtnn_de0_cv_ram.sv` | `bd8eb683a03cfa7db66f778106e5e1b10317c9930c50d735e4e5175ecae00b02` |
| `rtnn_de0_cv_soc_c2.sv` | `0902a2b9db68fbc27c4aa155b5fb43025a46529b519850c78e7386694d6d19af` |
| `rtnn_c2_vjtag_mailbox.sv` | `7cc0cb69bfddf4309f3b95370ce7c0e06b99e235eb8204b40816f40ff0f719d1` |

## Regression evidence

Run folder: `source_recovery_20261122/native_regression_run1/`.

- Verilator `5.020`; WSL Ubuntu 24.04; Python `3.12.3`; 146 frozen source entries, partitioned as 141 pinned Ibex files and 5 exact recovered project variants.
- `source_hash_check.status=PASS`; `source_count.txt=146`; all compile/run/overall exit-code files contain `0`.
- The native SoC regression reports `C2_FIXED_IBEX_Q15_SOC_PASS cases=42 reset_recovery=PASS`. The log contains the 42 scheduled cases and two reset-recovery case records.
- Six explicit negative-response cases are logged: bad frame CRC, duplicate sequence, bad payload CRC, unknown input, unknown model, and unknown build. The testbench's aggregate pass line also reports the busy/reset case. The response-write guard passes: partial write rejected, full commit accepted, empty recommit rejected.
- Verilator warnings were retained, not suppressed: 138 warnings in the 42-case compile log and 139 in the response-write-guard compile log, with warning classes `BLKSEQ`, `DECLFILENAME`, `PINCONNECTEMPTY`, `SYNCASYNCNET`, `UNUSEDPARAM`, and `UNUSEDSIGNAL` (the guard compile did not emit `SYNCASYNCNET`). `-Wno-fatal` allowed the test binaries to be built; PASS does not mean warning-free. Full warning text is in the run logs.
- The first attempted mapping that used normalized worktree text failed at 144/146; that failure is retained as `NATIVE_SOURCE_RECOVERY_AUDIT.json`. The corrected byte-exact mapping is `NATIVE_SOURCE_RECOVERY_AUDIT_RUN2.json` and is 146/146.

Commands used in WSL from the archived run folder:

```bash
sha256sum -c source_manifest_exact.sha256
bash ./run_native_v2_regression.sh
```

The script records source presence, tool version, compile/run logs and exit codes. The mapped source list refers to the exact archived evidence paths and the pinned Ibex location `/opt/rtnn-tools/ibex`; a fresh machine must provide the same pinned Ibex revision and recreate the explicit path mapping before rerunning.

## Research interpretation

This closes the source-hash gap for the native frozen regression graph and verifies that its saved 42-case/reset/negative-test suite still passes. It does not change the empirical scope or prior statistical results. In particular:

- B-SIGNOFF remains `BLOCKED_EXTERNAL_BOARD_TIMING`; CDC/D102 findings remain open.
- B-EMPIRICAL remains `PASS_LIMITED` for its existing scope.
- Accuracy noninferiority remains `INCONCLUSIVE`; the observed cycle reduction remains exploratory and single-board/session bounded.
- C3 v2 KEY0 reset replay remains `PENDING_OPERATOR`; the full new C3 v2 campaign remains `NOT_RUN`.
- Quartus rebuild, SOF identity reproduction, board access, WCET, and hard deadline are not established by this native run.

Machine-readable source map and audit outputs are alongside this document. `SHA256SUMS_SOURCE_RECOVERY_20261122.txt` records the archived evidence payload while excluding generated Verilator object directories.
