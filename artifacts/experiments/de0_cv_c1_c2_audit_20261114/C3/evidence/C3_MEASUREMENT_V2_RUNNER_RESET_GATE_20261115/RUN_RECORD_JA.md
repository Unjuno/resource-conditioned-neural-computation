# C3 v2 full-schedule reset-gate interlock

Date: 2026-11-15 (JST)  
Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`  
Branch/HEAD at start: `codex/stage-c3-jtag-pilot-20261114` / `c17c44e5556acc9c9e2d4fdbd114714c9c1ad804`  
Scope: host Tcl runner and offline binding validation only. No JTAG cable was opened and no board was programmed.

## Finding and change

The prior full-schedule runner checked the frozen campaign binding and rows but did not enforce the documented ten-input KEY-reset replay gate. A caller could directly invoke a complete `primary_01`–`primary_10` binding with `ALL` before that replay had passed.

The runner now requires a `rtnn-c3-key-reset-replay-gate-v1` evidence file for every complete frozen schedule, including all three diagnostic and ten primary schedules. Pilot subset runs remain available for the pre-reset pilot and its reset replay. Before creating the output directory or entering the JTAG operation path, the runner checks the gate's reset action/attestation, build and SOF identity, 20 frozen pilot sequence IDs, referenced result/audit paths, both file hashes, reset result fields, and independent audit status/identity. The Tcl test checks valid evidence, absent-gate rejection, altered result SHA rejection, and direct full-primary and diagnostic invocations failing closed. This gate records operator attestation; software cannot itself prove that KEY[0] was physically pressed and released.

No reset replay gate JSON has been created. The reported first 20-request pilot session remains PASS for that session only; KEY-reset replay is still pending and all full-schedule physical campaign runs remain blocked. No measurement values were added or relabeled.

## Verification

Quartus Prime Signal Tap Tcl Only 25.1std.0 Build 1129. The process CWD was the repository root `C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114`; Tcl files and campaign bindings were staged under the ASCII path `D:\rtnn-c3-resetgate-test-retry11-20261115`:

```text
& C:\altera_lite\25.1std\quartus\bin64\quartus_stp_tcl.exe -t D:\rtnn-c3-resetgate-test-retry11-20261115\test_c3_campaign_runner.tcl D:\rtnn-c3-resetgate-test-retry11-20261115\run_c3_campaign_v2.tcl D:\rtnn-c3-resetgate-test-retry11-20261115\run_c3_campaign_v2.tcl D:\rtnn-c3-resetgate-test-retry11-20261115
```

The test parsed all 13 SOF-bound frozen schedule bindings and their 24,840 rows, validated the 20-row pilot subset and sequence negatives, checked reset-gate positive/negative SHA cases, and attempted primary and diagnostic `ALL` runs without a gate. Both failed closed before JTAG. Final result: exit 0; Quartus reported 0 errors and 0 warnings. The TBBmalloc `_msize` compatibility notice remains in the raw log.

Final test log and exit code: `attempt11_quartus_stp_tcl.log`, `attempt11.exitcode`. Failed source/test iterations, including the attempted wrong-SOF negative fixture in `attempt10`, are retained with exit codes. `attempt08` and `attempt09` were preliminary PASS results; `attempt11` is the final PASS covering both primary and diagnostic full schedules. None accessed JTAG.

The pre-interlock source was preserved and hash-checked under `runner_before_reset_gate/`: runner SHA-256 `f7678c43560b24842e08ba3a0d8b66eb3abbb206173e840538f394a3f96fa7eb`; test SHA-256 `935ffdb3bd753b74ed8a4bb751f1b90934861950b3f297202213e2d39ebf3683`.

Current source manifest is in `C3/source/campaign_runner_v2_20261115/SHA256SUMS.txt`, SHA-256 `2c27410465eedf1257b8f488164538755c7ac24f6880d68966968d764538aae5`; the verification log is `source_manifest_verify.log`. This new host-side interlock does not alter RTL, firmware, SOF, frozen model/data/schedules, the empirical status of prior results, or B-SIGNOFF.

## Status

* Runner reset interlock and host Tcl test: **PASS**.
* B-SIGNOFF: **BLOCKED**, unchanged due to missing board-specific external JTAG timing specification.
* Ten-input KEY-reset replay: **NOT_RUN / pending operator action**.
* Frozen physical campaign: **NOT_RUN**, 0 campaign rows.
* Push, PR, merge, and Terasic inquiry: **NOT_PERFORMED**.
