# Repository update audit — 2026-11-15

## Target and starting state

- Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
- Worktree: `C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114`
- Branch: `codex/stage-c3-jtag-pilot-20261114`
- Starting HEAD: `b332ba02ab992227140998a1d67513c690ae17cf`
- At audit start, the branch remote pointed to the same HEAD; `main` was not the target.
- No staged changes were present. Existing modified and untracked C3 files were preserved.

## Evidence preservation and manifest reconciliation

The recursive C3 checksum audit found 1,514 entries across the then-existing 75 manifests. Eighteen referenced files were absent from their evidence folders. They were restored as byte-for-byte copies from already-preserved files in the C3 source/offline evidence tree, and each copied file was checked against the hash recorded by its original manifest. This did not synthesize or edit measurement results.

The audit then found ten pre-existing checksum discrepancies. The original manifests and source records were retained unchanged:

- One mismatch is the historical `RUN_RECORD_JA.md` in `evidence/GATE_B_EXACT_REBUILD_20261114`; the current tracked file already had that content at the starting HEAD, so this update did not introduce it.
- Six mismatches were stale hashes in the offline-reproduction snapshot after its referenced current documentation/scripts had changed.
- Three mismatches were stale hashes in the campaign-runner source manifest after its README/Tcl/test sources had changed.

Two supplemental manifests now record the current bytes without rewriting those historical manifests:

- `OFFLINE_REPRO_20261115/SHA256SUMS_CURRENT_20261115.txt`: 234 entries, 0 missing, 0 mismatches.
- `source/campaign_runner_v2_20261115/SHA256SUMS_CURRENT_20261115.txt`: 6 entries, 0 missing, 0 mismatches. This includes the attempt14 Tcl regression evidence.

The 18 restored files and both supplemental manifests are included in the repository update. The 10 historical discrepancies remain visible and are not represented as repaired historical evidence.

## New evidence included

- C3 v2 KEY[0]-reset replay RUN5: 20/20 saved requests passed the recorded checks; user reported pressing and releasing KEY[0]. No SOF, Flash/CFM, power, wiring, or clock setting was changed during the replay. See `evidence/PHYSICAL_C3_V2_20261115/KEY_RESET_REPLAY/C3V2_TENINPUT_KEY_RESET_REPLAY_20261115_RUN5/`.
- Finite CDC mailbox phase stress: 38/38 tested conditions across native and Quartus-flat RTL, 1,216 transactions; finite simulation is not a metastability, MTBF, or external timing proof.
- Official timing-source audit remains limited to available official material. The onboard USB-Blaster timing requirements remain unresolved.
- Campaign runner attempt14 is recorded as a host-side Tcl regression; it is not a new physical campaign run.

## Gate interpretation

`B-SIGNOFF` remains BLOCKED because board-level external JTAG timing constraints are unresolved; D102 remains visible and unwaived. `B-EMPIRICAL` remains limited to its documented build and empirical conditions. The saved 24,840-row campaign is historical evidence; RUN5's 20 replay rows are separate and were not added to that campaign. No WCET, hard-deadline, calibrated absolute-time, or accuracy-noninferiority claim is made here.

## Checks before publication

- New supplemental manifests were recomputed from current repository files and verified with zero missing entries or hash mismatches.
- The tracked source/document diff passed `git diff --check` before staging. A full staged `git diff --check` also flagged trailing spaces in preserved Quartus logs, intentionally empty final TSV fields, and extra terminal blank lines in archived generated files; those bytes were retained to preserve original evidence hashes. `git -c core.whitespace=cr-at-eol diff --cached --check` was used to distinguish CRLF from actual trailing whitespace.
- Large ignored Verilator build/cache directories matching `obj_v2_*` remain excluded by `.gitignore`.
- This audit note describes evidence and repository bookkeeping; it does not modify the frozen model, frozen input/campaign schedules, or prior physical measurements.
