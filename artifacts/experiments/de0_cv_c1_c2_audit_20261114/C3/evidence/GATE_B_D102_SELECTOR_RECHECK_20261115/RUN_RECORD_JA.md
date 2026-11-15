# C3 v2 response selector discrepancy — STA-only recheck

Date: 2026-11-15  
Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`  
Branch / HEAD: `codex/stage-c3-jtag-pilot-20261114` / `b332ba02ab992227140998a1d67513c690ae17cf`  
Build: `43334531`; SOF SHA-256 `85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d`  
Quartus: Prime Lite 25.1std.0 Build 1129

## Purpose

The retained TimeQuest selector-count file said 484 response source registers and 480 first-stage destination registers, while each saved response route report listed 480 paths. The earlier audit preserved the four-entry difference as unresolved. This run asks Quartus for the full source-name collection and sets the report limit to 600, then checks each returned source/destination bit index.

## Isolation and inputs

The original project at `D:\rtnn-c3-measurement-v2-quartus-retry02` was not opened for this run. It was copied to the separate work directory `D:\rtnn-c3-measurement-v2-d102-selector-recheck-20261115`. Before launching Quartus, SHA-256 was calculated for all 318 files in the original project and compared with the copy: `PASS_COPY_IDENTICAL files=318 bytes=75367201`. The full pre-run project hash list is `source_project_manifest.sha256`. Quartus ran only in the copied directory; generated reports were then copied into this evidence folder.

The retained QSF, SDC, flat RTL, SOF, fitted database and RAM image files were copied with the same pre-run hashes. STA ran only in the copy; any STA-generated state was confined there. After the run, `verify_project_manifest.py` rechecked all 318 original-directory files against the pre-copy hash list: exit 0, no mismatch. The checker additionally matches the preserved build identity, flat RTL SHA, SOF SHA and existing artifact manifest.

## Command and result

CWD: `D:\rtnn-c3-measurement-v2-d102-selector-recheck-20261115`

```powershell
& 'C:\altera_lite\25.1std\quartus\bin64\quartus_sta.exe' -t .\run_d102_selector_recheck.tcl
```

Quartus exit code: **0** (`quartus_sta_retry01.exitcode`). It reported 4 operating corners and 480 response paths in each corner with `-npaths 600`. The single Quartus warning was 12473 (the project asks for one processor while 14 are available); there were 0 errors. No compilation, Analysis & Synthesis, Fitter, Assembler, SOF generation, JTAG, or board action was run.

The STA Tcl prints every register in the source and destination collections with `get_register_info -name`:

* Response source collection: 484 register instances.
* Unique logical coordinates: all 15 words × 32 bits = 480.
* Four additional Quartus `~DUPLICATE` instances: `response_words_q[1][15]`, `[2][13]`, `[2][22]`, `[2][23]`; each has its original logical coordinate in the same collection.
* Response synchronizer destination collection: 480 unique bits, `[0]` through `[479]`.
* Each of the four corner route reports contains 480 unique logical source coordinates and all 480 matching destination bit indexes. The route report selects duplicate cell instances for `[2][22]` and `[2][23]` in all corners; the original instances are selected for `[1][15]` and `[2][13]`.
* Worst reported response route delays for corners 0–3: 3.633, 3.521, 2.373, 2.050 ns. These are fitted internal-route observations under this build's existing screen, not external JTAG timing limits.

Thus the count difference is reconciled as **480 logical payload bits + 4 fitted duplicate-register instances**. The 4 corner reports preserve the exact selected instance names. This is a reconciliation of Quartus collection names and reported route endpoints, not an independent formal equivalence proof of the duplicate cells.

## Reproduction and independent audit

The exact Tcl is `run_d102_selector_recheck.tcl`; Quartus stdout/stderr is `quartus_sta_retry01.log`; source names, destination names, four path reports and corner count are saved beside this record. A PowerShell launcher attempt failed before Quartus started because its relative log path was resolved after changing CWD; that diagnostic is preserved in `launcher_attempt01_failure.log`.

From repository root, run:

```powershell
python -m py_compile artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/source/audit_c3_v2_d102_protocol.py
python artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/source/audit_c3_v2_d102_protocol.py --c3-root artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3 --selector-recheck-root artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/GATE_B_D102_SELECTOR_RECHECK_20261115 --output-json artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/GATE_B_D102_SELECTOR_RECHECK_20261115/<NEW_ID>.json
python artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/GATE_B_D102_SELECTOR_RECHECK_20261115/verify_project_manifest.py --manifest artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/GATE_B_D102_SELECTOR_RECHECK_20261115/source_project_manifest.sha256 --project-root D:\rtnn-c3-measurement-v2-quartus-retry02
```

The recorded independent audit is `d102_protocol_audit_retry03.json`, exit code 0, SHA-256 `2fec69be51023a4ceb270473689b7cfa46310df50c79b152c1c804d4b6da0d32`. The original-project immutability recheck is in `original_project_unchanged_check.log` with exit code 0.

## Gate effect

This resolves the 484/480 selector-count discrepancy for the retained fitted build. D102 remains enabled and reported (16 structures), and the finite RTL assertions are not a formal CDC proof. External TDI/TMS/TDO timing remains unconstrained. Therefore B-SIGNOFF stays **BLOCKED**; the result does not establish board/cable timing, MTBF, WCET, or hard deadline guarantees.
