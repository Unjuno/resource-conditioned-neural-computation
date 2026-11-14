# C3 Gate B evidence audit — execution record

Date: 2026-11-15 JST
Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
Branch/HEAD: `codex/stage-c3-jtag-pilot-20261114` / `c17c44e5556acc9c9e2d4fdbd114714c9c1ad804`

This was a read-only audit of preserved C3 v2 evidence. It did not rebuild Quartus, change constraints, program the FPGA, send the Terasic inquiry, or reclassify historical measurements.

Tool: Python 3.11.9
CWD: `C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114`
Command:

```text
python "C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114\artifacts\experiments\de0_cv_c1_c2_audit_20261114\C3\source\audit_c3_gate_b_evidence.py" --repo "C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114" --output "C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114\artifacts\experiments\de0_cv_c1_c2_audit_20261114\C3\evidence\C3_GATE_B_EVIDENCE_AUDIT_20261115"
```

Exit code: `0`. The script hashed and verified 55 inputs: Quartus project/SOF/flat RTL/RAM images, firmware ELF/BIN and build manifests, frozen Q15 weights and host/reference inputs, all 13 SOF-bound schedule bindings, four-corner TimeQuest reports, unconstrained-path report, CDC routing summaries, and post-fit Design Assistant/Quartus reports.

Checks: 4 corners each contained 20 reported setup and 20 hold paths with 0 reported violations and the expected slack values; SDC contained only the two KEY[0] reset exceptions and two 16 ns bundled-data screening constraints; TimeQuest still listed 2 unconstrained input ports/41 paths and 4 unconstrained output ports/8 paths; all 8 request/response corner summaries remained under 16 ns; D102 remained visible for 16 structures; all 13 schedule bindings matched the same SOF, ELF, Q15 host reference, model/build identity, RAM image, campaign and frozen schedule definitions.

The JSON result explicitly classifies B-SIGNOFF `BLOCKED` and internal STA only as `PASS_FOR_REPORTED_CONSTRAINED_PATHS_ONLY`. B-EMPIRICAL remains `PASS_LIMITED`; no timing, WCET or hard-deadline guarantee follows.

SHA-256:
- Audit script: `65c70bb977656cf38a008729ff3c5b0c2e8248eae72137f7a579615ece6a5f47`
- C3 v2 SOF: `85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d`
- Gate audit result: see `SHA256SUMS.txt`

The raw command output is preserved in `python_audit.log`; the exit code is in `python_audit.exitcode`. Earlier parser failures are preserved in the sibling retry logs.
