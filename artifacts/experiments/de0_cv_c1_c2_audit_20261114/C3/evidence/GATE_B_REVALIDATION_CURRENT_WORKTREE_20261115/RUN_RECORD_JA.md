# Gate B evidence revalidation — current worktree, 2026-11-15

## Scope and repository identity

- Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
- Branch: `codex/stage-c3-jtag-pilot-20261114`
- Local HEAD: `b332ba02ab992227140998a1d67513c690ae17cf`
- Read-only `git ls-remote` confirmed that remote branch points to the same HEAD. `main` remains `ea903d3b76c4cb50732c3f9c72c8ed2084c2cb23`.
- CWD used by the runner: `C:\Users\junny\OneDrive\ドキュメント\ChatGPT\RTNN`; script inputs/outputs were passed by absolute `R:\...` paths (`R:` is a temporary `subst` alias for the correct repo root).
- Worktree changes were preserved. No reset, clean, commit, push, PR, merge, Quartus project build, JTAG, or board operation occurred in this revalidation.

## Reproduced offline audits

All three Python commands exited 0. These are rechecks of retained RTL/QSF/SDC/Quartus reports, not a new Quartus build or formal CDC proof.

```powershell
python C3/source/audit_c3_v2_gate_b_saved_reports.py --c3-root C3 --output-json C3/evidence/GATE_B_REVALIDATION_CURRENT_WORKTREE_20261115/saved_sta_audit.json
python C3/source/audit_c3_v2_d102_protocol.py --c3-root C3 --selector-recheck-root C3/evidence/GATE_B_D102_SELECTOR_RECHECK_20261115 --output-json C3/evidence/GATE_B_REVALIDATION_CURRENT_WORKTREE_20261115/d102_cdc_audit.json
python C3/source/audit_c3_v2_ucp_disposition.py --c3-root C3 --output-json C3/evidence/GATE_B_REVALIDATION_CURRENT_WORKTREE_20261115/ucp_disposition_audit.json
```

| Audit | Exit | Result |
|---|---:|---|
| Saved STA/build identity | 0 | `INTERNAL_REPORTS_REAUDITED_EXTERNAL_IO_SIGNOFF_BLOCKED`; Quartus 25.1std.0 Build 1129, build `43334531`, SOF SHA `85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d`; QSF/SDC/flat RTL match saved artifact manifest. |
| D102/CDC structure and selector recheck | 0 | `D102_SELECTOR_COUNT_RECONCILED_NOT_FORMAL_CDC_PROOF_B_SIGNOFF_BLOCKED`; 16 D102 warnings remain unsuppressed; request route coverage 800/800 and response 480/480 in four saved corners. The previous 484 source instances resolve to 480 logical payload bits plus four Quartus duplicate instances. |
| UCP roles | 0 | `LED_INDICATOR_PORTS_CLASSIFIED; EXTERNAL_JTAG_TIMING_STILL_BLOCKED`; functional TDI/TMS/TDO timing remains unresolved. |

The saved four-corner top-20 setup/hold summaries have positive reported slack: slow 85 C +1.803/+0.259 ns; slow 0 C +1.887/+0.242 ns; fast 85 C +10.027/+0.134 ns; fast 0 C +11.154/+0.124 ns. These are the reported constrained-path summaries, not proof that every required path is constrained. The two 16 ns bundled-data net-delay limits remain empirical screening thresholds; worst recorded route delays in the four saved corners were 3.633, 3.521, 2.373 and 2.050 ns.

TimeQuest still reports two unconstrained input ports (`altera_reserved_tdi`, `altera_reserved_tms`; 41 paths each for setup and hold) and four unconstrained output ports (`altera_reserved_tdo`, `LEDR[0]`, `LEDR[1]`, `LEDR[3]`; 8 paths each). The LED ports are onboard indicators without synchronous external receivers; their UCP entries and Fitter drive/slew warnings remain visible. No false paths or new I/O delay values were added. The `altera_reserved_tck` 33.333 ns model is Quartus/IP embedded, not measured DE0-CV TCK.

## Official timing-source check

- Terasic's DE0-CV product specification identifies Cyclone V `5CEBA4F23C7N` and an onboard USB-Blaster, but does not publish onboard-controller TCK duty/launch/capture timing for the fitted board revision: <https://www.terasic.com.tw/cgi-bin/page/archive.pl?CategoryNo=163&Language=China&No=921&PartNo=2>.
- The current Altera Cyclone V FPGA JTAG table gives target-side minima: TCK period 30 ns (167 ns for the footnoted volatile-key condition), high/low 14 ns, TDI setup 1 ns, TMS setup 3 ns, hold 5 ns, and TDO clock-to-output max 11 ns with voltage adder rules: <https://docs.altera.com/r/docs/683801/current/cyclone-v-device-datasheet/fpga-jtag-configuration-timing?contentId=tHclXha2uF6DJBsBSWaFRA>.
- The MAX II handbook lists EPM240 global-clock `tCO` max values 4.3/5.6/6.9 ns for speed grades -3/-4/-5 at the stated 3.3-V LVTTL/10-pF condition: <https://docs.altera.com/api/khub/documents/EVNBSY8oxDghXeEwnyVZvQ/content>. The retained package scan identifies an EPM240T100 family path but does not identify the installed speed grade or a complete JTAG controller capture window. These component values do not supply the actual DE0-CV controller launch/capture and path min/max budget.
- The board-specific System CD archive recheck found no source project or timing model for the onboard controller. No timing request was sent to Terasic.
- A fresh read of Terasic's current resource page and Altera's current USB-Blaster III guide confirms that the latter's delay table is specific to the external USB-Blaster III cable. It is not applied to the DE0-CV onboard USB-Blaster. The direct source-scope comparison and the unsent targeted request are recorded in `OFFICIAL_JTAG_TIMING_SOURCE_AUDIT_20261115.md`.

## Gate decision

- Internal saved reports and the UCP/CDC evidence were revalidated for identity and scope.
- D102 remains unwaived. Saved route reports and finite RTL assertions do not prove every CDC trace, analog metastability/MTBF, all-PVT operation, or board-level timing.
- **B-SIGNOFF remains BLOCKED** until the actual PCB revision and corresponding onboard USB-Blaster/CPLD timing or a documented, calibrated characterization provides TCK period/duty/edge and TDI/TMS/TDO min/max timing at the Cyclone V/controller interfaces. Do not add guessed I/O delays or false paths.
- B-EMPIRICAL remains `PASS_LIMITED` for the existing measured board/build only; it is not signoff, WCET, or hard-deadline evidence. The existing C3 campaign and KEY-reset runs remain empirical evidence, not a replacement for Gate B signoff.

## Output and source hashes

The JSON results, per-command logs/exit codes, this record, official-source note, and SHA-256 manifest are colocated. `INPUT_SHA256.txt` records the exact audit scripts, QSF/SDC/flat RTL, unconstrained-path report, Design Assistant report, selector collection lists, and prior current-HEAD gate JSON. `SHA256SUMS.txt` covers the saved outputs. The manifests for all three reports and all referenced STA/CDC source artifacts were verified by their respective audit scripts.
