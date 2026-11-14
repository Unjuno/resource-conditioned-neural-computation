# C3 Gate B evidence audit — execution record

Date: 2026-11-15 JST
Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
Branch/HEAD: `codex/stage-c3-jtag-pilot-20261114` / `c17c44e5556acc9c9e2d4fdbd114714c9c1ad804`

This was a read-only consistency audit of preserved C3 v2 evidence. It did not rebuild Quartus, change constraints, program the FPGA, send the Terasic inquiry, or reclassify historical measurements.

Tool: Python 3.11.9
CWD: `C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114`
Command:

```text
python "C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114\artifacts\experiments\de0_cv_c1_c2_audit_20261114\C3\source\audit_c3_gate_b_evidence.py" --repo "C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114" --output "C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114\artifacts\experiments\de0_cv_c1_c2_audit_20261114\C3\evidence\C3_GATE_B_EVIDENCE_AUDIT_20261115_FINAL"
```

Exit code: `0`. The audit hashed and verified 59 source evidence files: Quartus project/SOF/flat RTL/RAM images, firmware ELF/BIN and manifests, frozen Q15 weights and host references, native SV source snapshots/source-list, all 13 SOF-bound schedule bindings, the four-corner TimeQuest reports, unconstrained-path summary, CDC route-delay summary, and post-fit Quartus/Design Assistant reports.

It checked that every schedule binding names the same SOF, ELF, model/reference, RTL/source-list snapshots, RAM lanes, build, campaign and frozen schedule identities (13 bindings, 24,840 rows total). The four corners each contain 20 reported setup and 20 hold paths with 0 reported violations and the recorded worst slack values. The SDC contains only two KEY[0] reset exceptions and two internal 16 ns bundled-data screening constraints. The 16 D102 structures remain reported. TimeQuest still lists 2 unconstrained input ports/41 paths and 4 unconstrained output ports/8 paths.

The JSON result explicitly classifies B-SIGNOFF `BLOCKED`, internal STA as `PASS_FOR_REPORTED_CONSTRAINED_PATHS_ONLY`, and B-EMPIRICAL as `PASS_LIMITED`. This does not establish that every path is constrained, bound the physical onboard USB-Blaster interface, or prove CDC metastability/MTBF, WCET, or hard deadlines.

SHA-256:
- Audit script: `47cd75dc8bc6edad0a968097d1f17dc4ac345199f7327f3b2e05b01f884973f4`
- C3 v2 SOF: `85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d`
- `gate_b_audit.json`: see `SHA256SUMS.txt`

Raw command output is preserved in `python_audit.log`; exit code is in `python_audit.exitcode`. Earlier parser failures and the preliminary 55-input audit are retained in sibling logs/evidence folders.
