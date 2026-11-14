# C2 bundled-data CDC focused recheck

* Date: 2026-11-14 JST
* Quartus Prime Lite: 25.1std.0 Build 1129
* Project: exact-input C2 build in `D:\rtnn_c3_gateb_exact_rebuild_20261114`
* Source QSF / SDC / flat RTL SHA-256: `9d270c2f57ca7f6ee1f68f4d525a685625a7cc5311b0a55ee363e23f823f675e` / `8ba18e9829ebb9754278867948a1b0fffb360144738f1c3e45f1650592a87690` / `fdfcdf037eb55225e3e6eef06b01fc92e608951c54ece946461408131f2e5ca7`

## Capture phase correction

The RTL synchronizes the request/response toggle through two destination registers and captures the payload when the old second-stage value is observed by the event-detection logic. That capture occurs on the third destination edge after the source toggle. The source update can precede the first destination edge by an arbitrarily small interval, so only two full destination periods are guaranteed before the third edge. Using the frozen 20 ns `CLOCK_50` period and the Cyclone V minimum 30 ns TCK period gives 40 ns request and 60 ns response windows. The previous 60/90 ns statement was incorrect and is superseded by the corrected audit JSON in the parent directory.

These are protocol-derived earliest-capture windows, not measured board timing. The route-only maxima (3.358 ns request, 3.157 ns response) and their differences from 40/60 ns do not include the complete setup path and are not STA slack.

## STA experiments

All commands below ran in the isolated D: project directory. No QSF, SDC, RTL, fitted database, candidate SOF, or board state was changed by these TimeQuest-only Tcl experiments.

| Run | Tcl | Exit | Observation |
|---|---|---:|---|
| Max delay with original SLD asynchronous group | `bundle_maxdelay_with_vendor_clock_group.tcl` | 0 | Quartus reported no setup paths for the exact bundle endpoints; the vendor-embedded asynchronous group masks path-based max-delay checks in this Lite 25.1 run. |
| Max skew with original SLD asynchronous group | `bundle_maxskew_with_vendor_clock_group.tcl` | 0 | Warning 332182 said no path satisfied each request/response `set_max_skew`; all four raw reports say `Nothing to report.`. No skew result is claimed. |
| Focused max-delay diagnostic after `remove_clock_groups -all` | `bundle_maxdelay_without_clock_groups_exploratory.tcl` | 0 | Diagnostic only: this removes all clock groups in-memory, then sets 40 ns request and 60 ns response limits. It finds 800/800 and 384/384 setup paths with zero violations at each of four corners. |

The exploratory worst setup slack values (corner order from the saved Tcl reports) were:

| Corner | Request paths | Request worst slack | Response paths | Response worst slack |
|---|---:|---:|---:|---:|
| Slow 1100 mV, 85 °C | 800 | +32.704 ns | 384 | +57.936 ns |
| Slow 1100 mV, 0 °C | 800 | +32.957 ns | 384 | +57.933 ns |
| Fast 1100 mV, 85 °C | 800 | +36.018 ns | 384 | +58.625 ns |
| Fast 1100 mV, 0 °C | 800 | +36.381 ns | 384 | +58.780 ns |

The max-delay diagnostic is evidence that the exact bundle paths can meet these protocol windows under this isolated setup/analysis. It is not a production Gate B pass: `remove_clock_groups -all` also changes timing treatment for unrelated CDC paths, and this run did not establish a complete targeted policy for the scalar synchronizers and acknowledge paths. The original source SDC still contains the embedded SLD asynchronous group; no constraint has been promoted from this diagnostic into the source project.

The original-group max-skew result remains `NOT_EVALUATED`. Gate B also remains blocked by unconstrained external TDI/TMS/TDO timing, unknown onboard USB-Blaster TCK, LED endpoint disposition, and incomplete whole-design CDC exception/constraint coverage.


## Quartus Lite targeted CDC probe (diagnostic only)

* Quartus: Prime Lite 25.1std.0 Build 1129, Legacy Timing Analyzer.
* CWD: `D:\rtnn_c3_gateb_exact_rebuild_20261114`.
* No repository SDC/QSF/RTL, fitted database, SOF, or board state was changed by these STA-only probes.

A direct `set_data_delay -from ... -to ... <value>` probe returned Tcl `rc=1` for both bus directions with `ERROR: The set_data_delay constraint is not supported in the Legacy Timing Analyzer`. The enclosing probe log ended with Quartus 0 errors because the Tcl script intentionally caught and printed the command failure; do not mistake that process exit for successful constraint application. `set_data_delay` therefore cannot be used by this installed Lite 25.1 legacy analyzer. (The available online command documentation found during this audit is for Pro Edition and is not applied to this Lite result.)

A separate candidate-only experiment removed the SLD asynchronous clock group in memory, then added seven exact scalar crossing false paths from each source toggle/state register to its first receiving synchronizer register, and applied 40 ns request / 60 ns response `set_max_delay` to the bundled buses. The 7 destinations resolved one-to-one; two source collections included Quartus duplicate aliases, for 9 source nodes total. The endpoint counts were request 800/800 and response 394 source aliases / 384 capture destinations. The exception inventory records the seven explicit scalar pairs and the bundle exceptions. Four-corner result: all 800 request and 384 response paths were found, zero setup violations; worst slacks match the full path reports (+32.704/+32.957/+36.018/+36.381 ns request and +57.936/+57.933/+58.625/+58.780 ns response). A one-corner clock-pair report after these explicit exceptions found only the bundle paths in the reported TCK↔system directions; this is not evidence about the externally timed TDI/TMS/TDO paths.

An additional candidate-only `set_max_skew` report, also after removing the global clock group in memory, used the protocol capture windows (40 ns request, 60 ns response) as explicit bounds. All four corners reported 32 path records (latest and earliest arrivals for the 2 bus assignments), zero violations. Actual max skew by corner was request 3.528/3.431/2.239/1.978 ns and response 3.330/3.249/2.103/1.874 ns; these are exploratory fitted-netlist values under this diagnostic clock treatment. An earlier 20 ns request / 30 ns response trial is also preserved but superseded; those tighter values were not taken as protocol requirements. The final reported diagnostic uses 40/60 ns. With the original SLD asynchronous group present, the same Lite 25.1 tool produced no max-skew paths, so these results do not constitute production-constraint signoff.

The first targeted Tcl attempt stopped because the query required exactly one source node and Quartus returned a duplicate alias for `rsp_toggle_sys_q`; the alias was inspected and the corrected experiment includes both source nodes. The first max-skew report invocation also used unsupported `-from/-to` report arguments; the corrected invocation uses `report_max_skew -npaths 8`. These are tool-script/query failures, not RTL failures, and their logs are preserved beside the corrected runs. Every successful TimeQuest run still emitted Warning 12473 (project requests one processor while 14 are available); no timing/RTL warning was suppressed.

### Gate disposition

This probe shows a plausible targeted internal CDC treatment and positive bounded bus-path/skew reports, but it is not a production SDC or Gate B pass: the diagnostic removes the vendor clock group globally, uses ordinary Lite `set_max_delay` timing relationships, and does not close external USB-Blaster/CPLD/cable TDI/TMS/TDO timing or measured TCK. The tested source SDC remains unchanged. Gate B stays **BLOCKED** until targeted constraints are justified and rerun in a production configuration, and external I/O assumptions are supported by board-specific evidence.
