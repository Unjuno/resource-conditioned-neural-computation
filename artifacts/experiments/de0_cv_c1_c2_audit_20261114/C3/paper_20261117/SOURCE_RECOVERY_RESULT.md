# RTL source recovery result (2026-11-21)

## Outcome

**SOURCE_REPRO_BLOCKED: exact expected `ibex_top_gate_bypass.sv` bytes not recovered.** The expected SHA-256 is `e1728fb66338b61a815a30062923698de7b6ff5e62d5c2bd3e996633254b3f50`. The saved clean-Linux audit recorded 145/146 source-file matches, including 141/141 pinned upstream Ibex files and 4/5 project-owned files. The expected source mismatch is therefore isolated to one project-owned file in that audited graph.

## This turn's read-only recovery checks

1. Rechecked the public paper branch's tracked file history with `git log --all --follow` for `C2/source/ibex_integration/ibex_top_gate_bypass.sv`. The available history shows only the introduction commit `fc4923d`.
2. Enumerated every file named `ibex_top_gate_bypass.sv` in the paper worktree. Only the tracked C2 source was found. Its committed LF byte stream SHA-256 is `1360b260617425c8e5ae3b9952940dcc39281b0b339210db5511cf811de93270`; the Windows checkout's CRLF byte stream hashes to `2bc07a897d7c9054d5a9338a4be71337caa442246d79236380d280c3aa177bf9`. Neither equals the expected SHA. This confirms that the Windows-vs-Linux line-ending difference is a separate presentation detail and does not recover the required source.
3. Checked installed WSL distributions (`Ubuntu-22.04`, `Ubuntu-22.04-C`, `Ubuntu-24.04`) and attempted a read-only shell probe in Ubuntu-22.04. The launch did not return within 10 seconds and was interrupted; no distro files were changed and no source was found there.
4. The preserved C2/C3 evidence folders contain the existing build-input and source manifests, but no additional exact target copy. No hash-targeted source was reconstructed or substituted.

## Consequence

The saved data analysis remains reproducible independently of the complete RTL source graph. The physical SOF/ELF and raw JTAG evidence are preserved, but clean-checkout regeneration of the exact 146-source RTL/SOF chain is not established. Do not change the tracked RTL or frozen manifest to hide the mismatch. Further source recovery is useful only if a preserved WSL work area or external build archive becomes accessible; repeating the same public Git history search adds no evidence.

## Status

- Expected exact file recovered: **NO**
- Current 146-source identity: **145/146 saved audit; still blocked**
- Native Verilator re-regression from the exact graph: **NOT_RUN**
- Quartus/SOF bit-identical rebuild: **NOT_RUN**
- New board operation: **NOT_RUN**
