# C3 Gate B 保存証拠監査 — 現在HEADでの再確認

- Date: 2026-11-15 JST
- Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
- Branch/HEAD: `codex/stage-c3-jtag-pilot-20261114` / `b332ba02ab992227140998a1d67513c690ae17cf`
- Prior saved audit HEAD: `c17c44e5556acc9c9e2d4fdbd114714c9c1ad804` (current HEAD is its direct child).
- Purpose: confirm that the previously saved 59-file Gate B evidence audit remains reproducible and identity-consistent from the current branch head.
- Tool: Python 3.11.9; CWD: repository root.
- Command (PowerShell-expanded paths): `python "C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114\artifacts\experiments\de0_cv_c1_c2_audit_20261114\C3\source\audit_c3_gate_b_evidence.py" --repo "C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114" --output "C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114\artifacts\experiments\de0_cv_c1_c2_audit_20261114\C3\evidence\C3_GATE_B_EVIDENCE_AUDIT_20261115_CURRENT_HEAD"`
- Exit: 0. Output: `PASS: 59 inputs hashed; 13 campaign bindings identity-matched; 4 setup/hold corners parsed; 16 CDC structures retained`.
- Result: `B-SIGNOFF=BLOCKED; B-EMPIRICAL=PASS_LIMITED`.

This read-only audit checks preserved file identities and the reported timing/campaign records. It did not run Quartus, contact Terasic, access JTAG, program or reset the FPGA, or claim full-board timing signoff. The same blockers remain: external TDI/TMS/TDO timing values are absent; 2 unconstrained input ports/41 paths and 4 output ports/8 paths remain in the preserved report; all 16 D102 warnings remain visible. The internal routed-path summaries are limited to the listed constrained paths.

The earlier run record is retained unchanged in `../C3_GATE_B_EVIDENCE_AUDIT_20261115_FINAL/`. Its HEAD was the direct parent of this run's HEAD; its result was not rewritten. Input and output hashes are in this directory's `SHA256SUMS.txt`; full stdout and exit code are preserved under `OFFLINE_REPRO_20261115/`.
