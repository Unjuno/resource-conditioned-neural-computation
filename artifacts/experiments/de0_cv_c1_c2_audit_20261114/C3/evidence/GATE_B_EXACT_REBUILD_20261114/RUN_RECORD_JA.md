# Gate B: exact-input Quartus rebuild audit

* Date: 2026-11-14 JST
* Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
* Branch at run: `codex/stage-c3-jtag-pilot-20261114`
* HEAD before this evidence addition: `94870227ae920fe4064c2eeadccac231bc04f074`
* Result: **BLOCKED for full board timing signoff**; exact-input compile, internal STA, CDC path audit and scoped D101 audit reproduced.

## Run identity and preservation

The source evidence remains in `C2/evidence/quartus_d101/`. Quartus compiled byte-for-byte copies in `D:\rtnn_c3_gateb_exact_rebuild_20261114`; it did not run in the repository, alter C2 evidence, program the board, or touch flash. The only repository changes from this work are this C3 evidence directory and its hash-manifest entries.

Tool: Quartus Prime Lite 25.1std.0 Build 1129 (10/21/2025), installed at `C:\altera_lite\25.1std`.
Compile command: `quartus_sh.exe --flow compile rtnn_c2`
Compile cwd: `D:\rtnn_c3_gateb_exact_rebuild_20261114`
Observed process exit: 0; full compilation successful; 0 errors, 392 warnings; elapsed 00:09:53. `quartus_sh_compile.exitcode` preserves the exit sentinel.
DRC command: `quartus_drc.exe rtnn_c2 -c rtnn_c2`
DRC cwd: same; observed process exit: 0; Design Assistant 0 errors, 0 warnings.
Four-corner CDC command: `quartus_sta.exe -t allcorners_cdc_audit_disposition.tcl`
Four-corner audit cwd: same; observed script exit: 0; four operating conditions reported.

Inputs were byte-identical to the stored C2 inputs. Their full basename/hash list is `input_SHA256SUMS.txt`; key input hashes:

| Input | SHA-256 |
|---|---|
| `rtnn_c2.qsf` | `9d270c2f57ca7f6ee1f68f4d525a685625a7cc5311b0a55ee363e23f823f675e` |
| `rtnn_de0_cv_c2.sdc` | `8ba18e9829ebb9754278867948a1b0fffb360144738f1c3e45f1650592a87690` |
| `rtnn_c2_soc_flat.v` | `fdfcdf037eb55225e3e6eef06b01fc92e608951c54ece946461408131f2e5ca7` |
| `rtnn_de0_cv_c2_top.sv` | `639e58115cc2f249b7aceb9e89fd2670896c5810ea442c31836926ac3bed5d5a` |
| `rtnn_c2_global_buf.v` | `98d4ac6fc5b541197efc046e647af0537f68a42789b3c8fce4872ae60e125a5a` |
| `rtnn_ram_lane0.hex` | `7704b387d02830327de288cfcced5d1a485c75b6f0cb838db1da4e87661f5f5a` |
| `rtnn_ram_lane1.hex` | `8c98d35b71595a0fc6fb40be2177dbac3883b4439a5ae894355bd3c3288af1c6` |
| `rtnn_ram_lane2.hex` | `8e8d201adf2f8e383d42bb116d75fa3e0fb6675d8bf96c694a8fc969547d5873` |
| `rtnn_ram_lane3.hex` | `affa1411c8c1ea6c443b2b6729502b58b63a6561fcf3177c65d7f34e635e1d11` |

## Fitter, STA, CDC

Fitter succeeded for Cyclone V QSF `DEVICE` value `5CEBA4F23C7`, top `rtnn_de0_cv_c2_top`. The DE0-CV board/FPGA is identified by the full orderable part `5CEBA4F23C7N`; Quartus omits the `N` lead-free suffix in its selected-device display, as Altera documents. The `F23` package designation is confirmed by Altera's Cyclone V 5CEBA4 pin-information document. The QSF itself does not contain the trailing `N`. Resource use: 4,034/18,480 ALMs (22%), 6,293 registers, 256/308 RAM blocks (83%), 3 DSP blocks, 0 PLLs. No logic retiming improvement was reported. ([Altera Quartus Prime software support](https://docs.altera.com/r/docs/683121/current/the-automotive-grade-device-handbook/quartus-prime-software-support), [Cyclone V 5CEBA4 pin information](https://docs.altera.com/api/khub/documents/1NKb_F4CYX7DE7fZeiacWA/content))

The regenerated STA report has positive internal slack in all four Quartus operating conditions. Worst setup is +0.821 ns (Slow 1100mV, 85C, `CLOCK_50`); worst hold is +0.116 ns (Fast 1100mV, 0C, `CLOCK_50`). `CLOCK_50` remains constrained at 20 ns (50 MHz). The SLD hub's HDL-embedded SDC creates a nominal `altera_reserved_tck` at 30 MHz; this is not a measured USB-Blaster clock.

The reproduced unconstrained-path summary is **not zero**:

* 2 unconstrained input ports and 41 input-port paths: `altera_reserved_tdi`, `altera_reserved_tms`. The raw report includes paths from TDI into user RTL, including `req_shift_tck_q[799]`; reserved JTAG naming alone is not grounds for excluding those paths.
* 4 unconstrained output ports and 8 output-port paths: `altera_reserved_tdo`, `LEDR[0]`, `LEDR[1]`, `LEDR[3]`.
* No unconstrained clocks. Quartus explicitly reports setup and hold are not fully constrained.

The SDC has no broad user-authored TCK/system-clock false path. Its reset exceptions are limited to asynchronous reset assertion/release synchronizer endpoints. The SLD hub's embedded SDC does apply `set_clock_groups -asynchronous -group {altera_reserved_tck}`, which cuts ordinary cross-domain setup/hold transfer analysis between TCK and other clocks. The existing bundled-data protocol uses held request/response buses with toggle/acknowledge synchronization. The four-corner path audit rechecked 800/800 same-index request data paths and 384/384 response data paths; actual worst net delays remained below the existing 16 ns and 24 ns bounds, respectively. These explicit net-delay checks are independent of the clock-group exception, but do not prove setup/hold, max skew, earliest capture, or external JTAG timing. The raw `report_max_skew` outputs contain `Nothing to report.` in all four corners, so max-skew is **NOT_EVALUATED**, not a pass.

Design Assistant's exact local D101 disposition audit passed: 801 explicit local D101 suppressions (800 request hold registers and the one recorded response representative), with global D101/D102/D103 enabled, zero high-severity violations and zero DA errors/warnings. The full DRC report, including its local suppression inventory, is preserved in `rtnn_c2.drc.rpt`; local suppressions are documented rather than treated as absent findings. A fresh `report_metastability -nchains 1000` run found 392 chains: 9 reset/scalar-control synchronizer chains were calculated and included in Design MTBF, while 383 uncalculated rows are automatically grouped response-payload paths (381 unique bit pairings plus two duplicate aliases), not 383 scalar synchronizers. The full 31,751,098-byte report has SHA-256 `00120db779ae93c5aaf3bc083bbafd8259cdf2c3ffda5cdd9920ca328faef038`, identical to the prior exact-input report; its local D: path and extraction summary hash are in `c3_mtbf_report_identity.json`.

The corrected phase analysis establishes that the payload is captured on the third destination edge, but arbitrary source/destination phase leaves only **two complete destination periods** from source update to that capture: 40 ns request (20 ns `CLOCK_50`) and 60 ns response (30 ns minimum TCK). The earlier 60/90 ns comparison overstated this interval and has been superseded. The route-only path maxima remain 3.358/3.157 ns; subtracting these from 40/60 ns gives 36.642/56.843 ns, explicitly **not STA slack** because this route-only report omits clock-to-Q, destination setup, clock uncertainty, and physical TCK envelope.

A focused, non-production TimeQuest experiment is preserved under `focused_cdc_recheck_20261114/`. With the original SLD asynchronous clock group present, adding 40/60 ns `set_max_delay` checks produced no setup paths; adding 20 ns `set_max_skew` checks likewise produced Quartus Warning 332182 (“No path is found”) and `Nothing to report` in every corner. For diagnosis only, a separate in-memory Tcl run issued `remove_clock_groups -all` (the source SDC/QSF/RTL were not changed), applied 40 ns request and 60 ns response max delays, and found 800/800 and 384/384 setup paths with zero violations at all four corners. Worst slack by corner was request +32.704, +32.957, +36.018, +36.381 ns and response +57.936, +57.933, +58.625, +58.780 ns. This isolates a promising protocol-bounded data-path result, but is **not** final CDC signoff: removing all clock groups globally in the diagnostic run also changes unrelated crossings, one-bit synchronizer paths have not yet been given a complete targeted exception/constraint policy, and the board-level JTAG I/O timing remains open. Firmware/RTL source-hold identity and order audit also passed. The corrected route-envelope and focused path checks therefore remain limited internal evidence, not full board-level CDC/timing signoff.

## Bitstream identity

The historical C2 physical SOF remains unchanged at SHA-256 `5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6`. The exact-input rebuild generated a 2,446,808-byte SOF with SHA-256 `995633cf36043355a8ae7ae0375e200a1c52834e88480161939ef667e7e13319`; 4,085 byte positions differ from the historical SOF. This rebuilt candidate is retained under the explicit `NOT_PHYSICALLY_TESTED` filename and was not loaded to the FPGA. Equal RTL/QSF/SDC/input hashes and matching broad fitted resource/timing summaries do not establish bitstream equivalence. The build reports do not yet explain all SOF byte differences; this remains a reproducibility question. Do not substitute the candidate for the historically measured SOF.

## Warnings and decision

The 392 compiler warnings are retained in `quartus_sh_compile.log`; they include repeated unused Ibex signal warnings, processor-count notices, the Lite-only LogicLock feature notice, and incomplete I/O assignment warnings. Fitter ended with 0 errors and 3 warnings; STA ended with 0 errors and 1 warning. The explicit incomplete pin assignment warning and unconstrained external/status endpoints remain visible. Design Assistant's zero-warning summary applies only to its enabled/checkable rules and does not override STA's unconstrained-path result.

During this re-audit, the copied path-audit helper was found to search only for `No paths were found`, while Quartus's four raw skew reports say `Nothing to report.`. Its first JSON therefore encoded four false booleans, not a measured skew result. The C3-scoped helper now records each corner as `NOT_EVALUATED`, preserves the original JSON as `c2_postfit_path_audit.pre_fix_20261114.json`, and reruns with exit 0 for path coverage/net-delay checks. The raw outputs remain the governing evidence; no max-skew PASS is claimed.

Gate B remains **BLOCKED**. Official Cyclone V JTAG endpoint numbers do not provide the DE0-CV onboard USB-Blaster/CPLD/PCB/cable propagation and skew, and the installed `jtagconfig --getparam 1 JtagClock` query failed with “No parameter named JtagClock”; actual external TCK is still unknown. USB-Blaster III/Cable-II example delays are not transplanted to this onboard USB-Blaster. No false paths or relaxed constraints were added to the source SDC. A candidate-only follow-up now tests seven exact scalar first-stage false-path pairs plus 40/60 ns bundled max-delay and max-skew checks in all four corners. Quartus Lite 25.1 reports the candidate bundle paths clean after globally removing the SLD clock group in memory, but that diagnostic treatment and its ordinary max-delay relationships are not production-ready; `set_data_delay` is unsupported in this Legacy analyzer. The tested production SDC remains unchanged, and targeted exception semantics/path coverage still need to be justified and validated in the actual production constraint configuration. External closure also needs board/cable-specific TDI/TMS-to-TCK and TDO timing (or a defensible validated measurement model), plus a documented endpoint policy for status LEDs. Only then should the SDC be revised and all gates rerun. Gate C for this new rebuilt SOF is NOT_RUN; the already-completed historical C3 24,840-row empirical campaign is not invalidated, and it remains bound only to its recorded tested SOF. No new candidate-specific Gate D campaign was run.

## Evidence index

`quartus_sh_compile.log`, Fitter/map/STA/DRC reports, four-corner path/skew/net-delay reports, D101 and path audit JSON, audit Tcl/scripts, candidate SOF, and `SHA256SUMS.txt` are stored alongside this record. The full repository-relative input evidence is kept at `C2/evidence/quartus_d101/` and was not rewritten.

## 2026-11-14 追補：同期器段間パスの4コーナー確認

元のC2 SDCと既存post-fitデータベースを変更せず、7組の1段目→2段目同期レジスタ間について各コーナーのsetup経路を個別列挙した。Quartus Prime Lite 25.1std.0 Build 1129 の `quartus_sta.exe -t sync_stage1_to_stage2_4corner_20261114.tcl` を `D:\rtnn_c3_gateb_exact_rebuild_20261114` から実行し、終了コード0。スクリプトは各送受信端点が1個、各コーナーで各ペアの経路が1本であることをassertする。

対象はreq、rsp-consume、req-ack、rsp、busy、error、doneの同期段間7ペア、合計28 setup経路。全経路でslackは正。ペア別4コーナー最小/最大slackは以下の通り（TimeQuest表示単位ns）：

| ペア | 最小 | 最大 |
|---|---:|---:|
| req_sync1_sys_q → req_sync2_sys_q | +18.913 | +19.476 |
| rsp_consume_sync1_sys_q → rsp_consume_sync2_sys_q | +18.856 | +19.472 |
| req_ack_sync1_tck_q → req_ack_sync2_tck_q | +31.811 | +32.589 |
| rsp_sync1_tck_q → rsp_sync2_tck_q | +31.737 | +32.579 |
| busy_sync1_tck_q → busy_sync2_tck_q | +31.907 | +32.632 |
| error_sync1_tck_q → error_sync2_tck_q | +31.806 | +32.596 |
| done_sync1_tck_q → done_sync2_tck_q | +31.716 | +32.584 |

Quartusは引き続きsetup/holdがfully constrainedでないと報告する。元のSDCの未制約端点一覧、例外一覧、全28経路の生レポートを本ディレクトリに保存した。起動時のTBBmalloc警告とWarning 12473（1 processor設定、14利用可能）あり。

最初の実行はUnicodeを含む作業パスをQuartus CLIへ渡したためログ上のパスが文字化けし、終了コード3となった。失敗ログも親ディレクトリに保持した。TclをASCII専用のD:作業場所へコピーして再実行し、同じ既存データベースを読み取り専用で解析して成功した。

この確認は同期段間の内部setup経路のみに限定され、同期器のMTBF、非同期位相全域、held-bus捕捉窓、外部JTAG TDI/TMS/TDOのsetup/hold、未制約LED出力を証明しない。元SDCの変更・候補SOFの書込みはしていない。従ってGate Bは引き続きBLOCKEDであり、この結果だけではGate Cへ進まない。

## 2026-11-14 追補：ステータスLED出力端点の分類

DE0-CV回路図のSheet 14（Terasic公式System CD、表示器/LEDシート）ではLEDR0–LEDR3は各330 Ωの抵抗ネットワークを介してLEDへ接続され、外部クロック入力や同期capture部品は接続されていない。LEDは視覚表示の負荷であり、外部setup/hold要件を持つ同期インターフェースではない。この根拠に基づき、LEDR[0], LEDR[1], LEDR[3]へのfalse pathを**診断Tcl内だけ**で適用した。IntelのTiming Analyzer Cookbookも、JTAG/デバッグ信号が設計に含まれる場合の制約分類を説明しており、数値制約は装置構成固有とする。Board-specificなJTAG値はこの例から流用していない。

Quartus Prime Lite 25.1std.0 Build 1129で4コーナーを個別解析した。選択したLEDポートは3個ちょうど。false path適用後、各コーナーのUnconstrained Paths Summaryは出力ポート1個・出力経路5本となり、残るのは `altera_reserved_tdo`。元の8経路からLED出力3経路が除外され、JTAG TDOの未制約は残る。解析終了コード0だが、Timing Analyzerはなおsetup/hold fully constrainedでないと報告する。

これはLEDが同期タイミング端点でないことを数え上げ付きで確認した診断であり、false pathを本番SDCへ追加したものではない。JTAG TDI/TMSの入力遅延、TDO受信側の要求、実TCKとlaunch/capture位相は解決していないためGate BはBLOCKEDのまま。RTL/QSF/元SDC、実機状態には変更なし。

参考： [Terasic公式DE0-CV System CD](https://download.terasic.com/downloads/cd-rom/de0-cv/)（基板回路図）、[Intel Quartus Prime Timing Analyzer Cookbook: JTAG Signals](https://docs.altera.com/r/docs/683081/22.2/quartus-prime-timing-analyzer-cookbook/jtag-signals?contentId=HqsgrDMGTE4REitNdjYy5w)。保存した既存JTAG調査記録は `C2/evidence/jtag_timing_research_20261113/JTAG_TIMING_RESEARCH_FOLLOWUP_20261113_JA.md`。
