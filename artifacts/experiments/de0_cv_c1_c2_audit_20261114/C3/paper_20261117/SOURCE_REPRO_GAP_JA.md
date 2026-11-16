# C3 v2 RTL source portability gap — 2026-11-17

## Audit scope

Read-only recheck from an independent Linux clone of the public RTNN paper branch and a separately fetched official upstream Ibex checkout:

- Upstream: https://github.com/lowRISC/ibex
- Ibex commit: 7b5df75a041affe56e8c235260f98a09b3319008 (detached, clean)
- Original audit evidence: C3/evidence/C3_MEASUREMENT_V2_RTL_REPRODUCE_20261115/
- Original 146-source SHA records: ibex_source_manifest.sha256 in that evidence folder
- Source-graph checker: audit_native_source_portability.py
- Machine-readable result: NATIVE_SOURCE_PORTABILITY_AUDIT.json

**Result: BLOCKED_SOURCE_HASH_MISMATCH, 145/146 files match.** The external Ibex source files match **141/141**. The five project-owned C2/C3 sources match **4/5**. This is a source-identity result only; the remote environment has no Verilator executable, and no RTL simulation, Quartus, SOF reconstruction or FPGA programming was executed.

## Exact mismatch

The current public path:

artifacts/experiments/de0_cv_c1_c2_audit_20261114/C2/source/ibex_integration/ibex_top_gate_bypass.sv

- SHA-256 required by frozen regression manifest: e1728fb66338b61a815a30062923698de7b6ff5e62d5c2bd3e996633254b3f50
- SHA-256 present in the clean Git checkout: 1360b260617425c8e5ae3b9952940dcc39281b0b339210db5511cf811de93270
- A simple LF→CRLF conversion does **not** reconcile them. Do not treat this as a line-ending-only mismatch.
- The file has one introduction in the available repository history (fc4923d, 2026-11-14), and the current tree contains that nonmatching version. The expected bytes were not found in the current tracked filename.
- Do not overwrite the tracked version or alter the original frozen evidence manifest to conceal the discrepancy.

## Distinct source-list identities

The 146-entry CRLF baseline list in C3/source/measurement_protocol_v2_43334531_20261115/native_source_list_baseline.txt has SHA-256:

4bddc5bd5e37cbd24015189d49e4a21677d570e5cb1c0a7c9dd503da30e6bfba

The actual native regression reproduction list in C3/evidence/C3_MEASUREMENT_V2_RTL_REPRODUCE_20261115/native_sources_v2.txt has SHA-256:

61636721b1ccbd669b52f5ee2db57e600f6c8bbe00208ae2d92725dd050ac17f

The first **144 paths are identical after newline normalization**. The reproduction list replaces the two trailing baseline C2 versions with C3 v2 SoC/mailbox snapshots. They are not interchangeable source-graph identifiers.

## Safe resolution path

1. In the original Windows/WSL worktree and any preserved build staging area, locate the **exact** ibex_top_gate_bypass.sv bytes with SHA-256 e1728fb6…633254b3f50. Preserve the source/commit/build context and its retrieval method; never substitute a visually similar file.
2. Archive the recovered variant in a **new, versioned** evidence folder; keep the current tracked file and the original 2026-11-15 logs unchanged. Re-run the 146/146 checker against an explicit source-map pointing to the recovered variant.
3. Use Verilator 5.020 and the exact source list for the native 42-request, reset, and negative-case regressions, retaining source, toolchain and output hashes. Bit-identical SOF reproducibility requires additional Quartus source/setting/toolchain checks and is **not** implied by native simulation.
4. If the exact source cannot be located, document the reproducibility restriction in the paper. Do not claim 146/146 clean-checkout reproducibility.

The paper's previously calculated FPGA cycle numbers remain saved and independently auditable; source-to-RTL reproduction is a separate, currently open dependency.

**ERROR CHECK:** 141 pinned upstream matches, 4 project source matches, 1 project source mismatch, source-list identity split verified. The Python checker intentionally produces a nonzero failure status for this case while preserving a JSON findings file.
