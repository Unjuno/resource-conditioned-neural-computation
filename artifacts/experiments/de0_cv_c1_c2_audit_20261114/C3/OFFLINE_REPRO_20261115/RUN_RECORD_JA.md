# 基板なし解析・再現性作業記録 — 2026-11-15

## 実行環境と保全

* Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
* CWD: `C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114`
* Branch: `codex/stage-c3-jtag-pilot-20261114`; start HEAD: `b332ba02ab992227140998a1d67513c690ae17cf`; origin fetch/push は正しい Unjuno repository。
* Python `3.11.9`; この作業のPowerShell host `7.6.9`; PowerShell auditorは`powershell.exe`から起動（その子プロセスの版はこのrun logには記録されていない）; Quartus Prime Lite `25.1std.0 Build 1129`。
* 生実測データ、凍結入力、model、schedule、binding、SOF、ELF、過去の失敗ログを編集・削除していない。git履歴を書換えず、commit/push/PR/mergeはしていない。
* 基板不在作業のみ。JTAG、KEY、SOF設定、電源、配線、設定変更は0回。

## 主なコマンドと結果

以下の相対パスは上記CWD基準。

| 目的 | コマンド（要約） | 結果・証跡 |
|---|---|---|
| repository確認 | `git status --short --branch`; `git remote -v`; `git rev-parse HEAD` | 正しいorigin、専用branch、開始HEAD一致。今回の未commit差分は新規解析・説明資料のみ。 |
| C2J2独立再集計 | `python artifacts/.../C3/source/reanalyze_c2j2_frozen_campaign.py --c3-root artifacts/.../C3 --out-dir artifacts/.../C3/campaign/analysis/C3_C2J2_INDEPENDENT_REAUDIT_20261115_RETRY05` | exit 0; `c2j2_independent_reaggregation_final_retry05.log/.exitcode`; 24,840行、13 schedules。結果と図表のSHAはRETRY05の`SHA256SUMS.txt`。 |
| Python構文確認 | `python -m py_compile artifacts/.../C3/source/audit_saved_c3_v2_runs.py artifacts/.../C3/source/create_key_reset_replay_gate.py artifacts/.../C3/source/normalize_native_source_paths.py artifacts/.../C3/source/reanalyze_c2j2_frozen_campaign.py` | exit 0; `python_compile.log/.exitcode`。 |
| 保存C3 v2 42件 | `python artifacts/.../C3/source/audit_saved_c3_v2_runs.py --result-json <saved-run> --result-csv <saved-run> --cases-csv <saved-run> --binding-json <saved-run> --raw-log <saved-run> --output-json <offline-output>` | exit 0; `c3v2_saved_run2_audit.stdout.json`, `.stderr.log`, `.exitcode`。 |
| 保存C3 v2 20件 | 同上、SESSION1の実ファイルを指定 | exit 0; `c3v2_pilot20_audit.stdout.json`, `.stderr.log`, `.exitcode`。 |
| C3 v2負例・回帰 | `python artifacts/.../C3/source/test_audit_saved_c3_v2_runs.py` | 13 tests pass; `c3v2_saved_run_unit_tests.log/.exitcode`。 |
| native source mapping | `python artifacts/.../C3/source/normalize_native_source_paths.py --source-list <frozen-list> --repo-root . --output-dir artifacts/.../C3/OFFLINE_REPRO_20261115/native_source_map` | exit 0; 146 entries; 141 external Ibex entries absent. Mapping only; no source equivalence claim. |
| Tcl自己試験 | Quartus bin CWDで `quartus_stp_tcl.exe -t <ASCII-temp>\check_c3_v2_loaded_build.tcl --self-test` | exit 0; `identity_tcl_selftest.log/.exitcode`; STP API/JTAG/基板アクセスなし。 |
| PowerShell既存監査42件 | 既存`audit_c3_v2_jtag_results.ps1`を保存42件へ実行 | exit 0; `powershell_existing_audit_42_retry01.log/.exitcode`。 |
| PowerShell既存監査20件 | 同監査を保存20件へ実行 | exit 1; 262文字の深いpathで`Get-Content`が結果JSONを開けない。相対・絶対の再試行も同じpath error。データ不一致ではない。Python監査はextended path対応後に20/20 pass。 |
| 構文・差分・SHA manifest | `python -m py_compile <C3 checker/test/helper sources>`; `git diff --check`; `python C3/source/create_offline_repro_manifest.py --c3-root <C3>`; 同コマンドに`--verify` | compile/diff/manifest作成・照合はすべてexit 0。manifestは120ファイル。ログは`python_compile_final01.*`, `git_diff_check_final01.*`, `manifest_generation_final01.*`。 |

## 失敗した試行と修正理由

失敗ログは診断証跡として残し、上書き・削除していない。

1. 初期C2集計は結合CSVと分割chunkを取り違えたためcase hash照合に失敗。凍結campaign側の統合CSVを正本とし、chunk hash・範囲も別々に検証するよう修正。
2. 初期parserは旧`primary_01`の非chunked形式を前提化できず、旧runに存在しないchunks manifestを探した。旧形式と他primaryの形式を分岐して再処理。
3. 次の再試行はlegacy primaryのmerged CSV pathを誤認したため入力ファイルなし。保存レイアウトを追跡し修正。
4. UTF-8ログ出力後のWindows CP932コンソールでem dashを表示できず終了。成果物は生成済みでも処理終了を失敗記録し、UTF-8出力先で最終runを再実行。
5. 古いC2 row schemaにない`response_model_id`を必須と誤認。実在フィールドとfrozen bindingで照合し、optional fieldが存在する場合のみ検査するよう変更。
6. 既存PowerShell監査は20件runの深いpath (262 characters) を開けず失敗。Python checkerにWin32 extended-path対応を追加。実機再開手順はASCII短縮stageを使い、監査・archive後もキャンペーン側が参照するまでstageを保持する。
7. 保存20件と42件のPowerShell/ Python pathの違いはファイル探索の不一致として扱わず、各監査器を個別実行。Pythonの独立checkerは両方をPASS。

## 成果物の再現とデータ分類

* 旧C2J2のcanonical独立出力は`campaign/analysis/C3_C2J2_INDEPENDENT_REAUDIT_20261115_RETRY05/`。初回、RETRY01、RETRY03、RETRY04を含む失敗・中間出力ディレクトリは保全されているが、最終値として引用するのはRETRY05のみ。
* C3 v2 checkerは**保存された物理runの再監査**専用。`SAVED_PHYSICAL_EVIDENCE_NOT_NEW_MEASUREMENT`を出力する。mock pathは拒否され、C2J2とC3 v2の異identityの結果を結合しない。
* 結果行のmcycle差はFPGA内で保存されたstart/end間のcycleであり、JTAG転送やPC wall-clock時間ではない。cold bootの独立性、外部JTAG timing、絶対周波数は本作業では検証していない。

## 独立して残る制約

native 146-source graphはsource list hashを固定したが、141 Ibex RTL依存とそのcommit/hashが正しいrepository内にない。そのためnative source graph再buildは`NOT_REPRODUCIBLE_YET`。KEY reset replayは人の実操作待ちであり、C3 v2 full physical campaignは0行。Formal B-SIGNOFF、hard deadline/WCETは未成立。1 percentage-point accuracy noninferiorityはINCONCLUSIVE。

## 最終整合性確認（追記）

2026-11-15のオフライン再開時に、`git remote get-url origin`、`git rev-parse HEAD`、`git status --short --branch`で正しいorigin・専用branch・HEAD `b332ba02ab992227140998a1d67513c690ae17cf`を確認した。READMEの回帰説明に「過去runでPASS」と「現在のrepositoryからnative 146-source graphを再構築できない」を併記し、過去記録を再実行済みと誤読しないようにした。

再確認コマンドと結果:

```powershell
python artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/source/test_audit_saved_c3_v2_runs.py
# exit 0; 13 tests passed
python -m py_compile artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/source/audit_saved_c3_v2_runs.py artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/source/create_key_reset_replay_gate.py artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/source/normalize_native_source_paths.py artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/source/reanalyze_c2j2_frozen_campaign.py
# exit 0; Python 3.11.9
git diff --check
# exit 0
python artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/source/create_offline_repro_manifest.py --c3-root artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3 --verify
# exit 0; 146 files verified after README clarification
```

Quartus、STP/JTAG、KEY、SOF、電源には触れていない。変更は未commit・未pushで、履歴変更なし。

### D102構造の追加再照合

保存D102構造をRTL・有限42-case testbench・4-corner route indexへ結び付けるため、`C3/source/audit_c3_v2_d102_protocol.py`を追加した。Retry01はD102 summaryの空白幅を文字列で固定して照合したためexit 1。生レポートの列値を読む実装に直し、失敗した`d102_protocol_audit_retry01.*`を保全した。Retry02は以下でexit 0となった。

```powershell
python -m py_compile artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/source/audit_c3_v2_d102_protocol.py
python artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/source/audit_c3_v2_d102_protocol.py --c3-root artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3 --output-json artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/GATE_B_C3V2_AUDIT_20261115/d102_protocol_audit_retry02.json
```

JSONはD102 16構造（request 800 bit 1束、response 15×32 bit）、各cornerのrequest 800/800とresponse 480/480 route index、RTL handshake signature、有限testbenchの5 assertion、D102非抑制を記録する。既存selector-countにあるresponse 484 source対480 destinationの差は未解明のまま明示し、全selector対応をPASSとはしていない。これは保存資料の静的照合であり、形式CDC証明でもQuartus再実行でもない。

再実行時に使ったPythonは3.11.9。リポジトリoriginは`https://github.com/Unjuno/resource-conditioned-neural-computation.git`、branchは`codex/stage-c3-jtag-pilot-20261114`、HEADは`b332ba02ab992227140998a1d67513c690ae17cf`。ハードウェア、JTAG、KEY、SOF、電源は未操作。Gate B-SIGNOFFは外部JTAG timing未制約のためBLOCKEDを維持する。

修正後の最終確認では、D102監査器と関連Pythonソースの`py_compile`がexit 0、`test_audit_saved_c3_v2_runs.py`は13/13 PASS、`git diff --check`はexit 0。`d102_protocol_audit_retry02.json` SHA-256は`a1964dc37f25a2d6da28332946874da1c62aaa6df6de13d9bb4d1fee3934e177`。最終SHA-256 manifestは152 filesを生成後、`--verify`で152 files一致を確認した。

### Altera公式JTAG制約ガイド再確認

2026-11-15にAltera公式USB-Blaster III timing waveformとQuartus constraint procedureを読み、一般に実際のJTAG setup/deviceに対応するTCKとmin/max I/O delayが必要であることを照合した。この資料はUSB-Blaster III向けであり、DE0-CV内蔵FT245BL/EPM240T100経路の数値は提供しない。TDO節の`set_input_delay`例はtarget-device視点の出力信号方向と整合しないため転記していない。Terasic公式manual URLの再openはtimeoutし、既存manual review以外の新しいboard timing dataは得られなかった。検索語、出典、適用範囲は`evidence/GATE_B_C3V2_AUDIT_20261115/OFFICIAL_GUIDANCE_RECHECK_20261115_JA.md`。そのSHA-256は`1ff5daf892d4c35712d255500c67077d8632b01d1b5c882eea45632fc3f07571`。

既存のoffline preparation manifestは更新前の内容を`OFFLINE_REPRO_20261115/SHA256SUMS_PRE_GUIDANCE_RECHECK_20261115.txt`へ保全した。更新後のcurrent manifestは179 filesで生成・照合し、公式資料再確認記録とstatus/audit追記を含めた。`create_offline_repro_manifest.py --verify`と`git diff --check`はいずれもexit 0。

### Bundled-data hold/capture sequence audit

C3 v2のmailbox RTL、SoC response MMIO、固定firmware、既存42-case simulation guard、STA RETRY03のnet-delay reportをソース行とhashで対応付けた。requestはackまで、responseは固定firmwareがcommit後にpollへ戻り次要求をconsumeまで受け付けない経路において、source stable→2段同期→capture-pending→ack/consumeとなる。4 cornerの保存route maxはrequest `3.323/3.186/2.183/1.891 ns`、response `3.633/3.521/2.373/2.050 ns`で、SDCの16 ns per-route screen内。`report_max_skew`自体は出力なしで、max-minus-minをformal skewとは扱わない。SoCはcommit後の任意CPU response-register writeを明示的に禁止しておらず、payload holdは固定firmware sequenceに依存する。有限TBは現行sequenceを検査するがformal CDC proofではない。詳細は`evidence/GATE_B_C3V2_AUDIT_20261115/BUNDLED_DATA_HOLD_SEQUENCE_20261115_JA.md`。本追記は保存済み成果物のread-only監査でsimulationを再実行していない。

現行offline manifestを更新する前に、直前版は`OFFLINE_REPRO_20261115/SHA256SUMS_POST_GUIDANCE_PRE_CDC_20261115.txt`へ保全した。現行版に本監査、status/report追記、SHA sidecarを含める。

### Gate B selector差分のQuartus再照合（追記）

追加STAでselector-count差の理由を検査した。元Quartusプロジェクト318ファイル（75,367,201 byte）を`D:\rtnn-c3-measurement-v2-d102-selector-recheck-20261115`へ複製し、コピー前に全318 hash一致を確認した。Timing Analyzerはこの複製でのみ起動。Quartus Prime Lite 25.1std.0 Build 1129、CWDは上記D: directory、実行コマンドは`quartus_sta.exe -t .\run_d102_selector_recheck.tcl`。STA exit 0、0 errors・1 warning（processor count 12473）。Fitter、Assembler、SOF生成や基板操作はなし。元D: projectは終了後に318/318 SHA一致を再確認し、exit 0。

response source collection 484件の内訳は、480 logical `(word,bit)` coordinatesと4つのQuartus `~DUPLICATE` node（`[1][15]`, `[2][13]`, `[2][22]`, `[2][23]`）。同期1段目は480 bit。`-npaths 600`の4-corner reportは全cornerで480 routesを出し、480論理bit indexをそれぞれ一度ずつmatching destinationへroute。route outputでは`[2][22]`と`[2][23]`のduplicate instancesが各cornerで選ばれ、他2ビットは元instanceが選ばれる。このため484対480は、480 payload coordinatesと4 fitted duplicate nodesとして照合できた。これはQuartus node identityとroute endpointsの整合であり、CDC形式証明・MTBF・外部JTAG timing保証ではない。

再現資料は`evidence/GATE_B_D102_SELECTOR_RECHECK_20261115/`。独立監査`d102_protocol_audit_retry03.json`はexit 0、SHA-256 `2fec69be51023a4ceb270473689b7cfa46310df50c79b152c1c804d4b6da0d32`。再確認した13件のC3 v2 testsとPython compileはexit 0、manifestは176 files生成・176 files照合、`git diff --check`はexit 0。Gate B内部CDC selector差は説明できたが、JTAG外部I/O timing未制約のためB-SIGNOFFはBLOCKEDを維持する。成果は未commit・未push。基板/JTAG/KEY/SOF/電源操作なし。


### CDC追記後のマニフェスト再照合

前節の記述に「現行manifestに本監査を含める」とある時点の版を`SHA256SUMS_POST_CDC_PRE_MANIFEST_RECONCILE_20261115.txt`へ保全した。今回の正規generatorを正しいC3ルートで実行し、現行対象範囲を実走査したところ、manifestは126 filesであることを確認した。以前の本文にある179/176件という記載は、対象範囲・時点が異なる旧ログ値で、現在のmanifest件数としては誤り。過去ログは書き換えず、この訂正を適用する。現在版は再生成後に`--verify`で照合する。

再現コマンド（PowerShell 7.6.9、repository rootをCWD）:

```powershell
python artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/source/create_offline_repro_manifest.py --c3-root artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3
python artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/source/create_offline_repro_manifest.py --c3-root artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3 --verify
```

### Gate B 59-file identity audit at the current HEAD

The previously preserved consistency audit was executed at `c17c44e5556acc9c9e2d4fdbd114714c9c1ad804`, the direct parent of the current dedicated branch HEAD `b332ba02ab992227140998a1d67513c690ae17cf`. To establish current-state provenance, the same read-only audit was executed once at the current HEAD. It exited 0 after hashing 59 listed inputs, matching 13 schedule bindings/24,840 frozen rows, parsing four setup/hold corners, and retaining all 16 D102 structures. It reports `B-SIGNOFF=BLOCKED; B-EMPIRICAL=PASS_LIMITED`; there is no change to gate classification. The command, output, limitations and local SHA list are in `evidence/C3_GATE_B_EVIDENCE_AUDIT_20261115_CURRENT_HEAD/`. The older parent-HEAD run remains intact.

CWD was the correct repository root. Command:

```powershell
python "C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114\artifacts\experiments\de0_cv_c1_c2_audit_20261114\C3\source\audit_c3_gate_b_evidence.py" --repo "C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114" --output "C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114\artifacts\experiments\de0_cv_c1_c2_audit_20261114\C3\evidence\C3_GATE_B_EVIDENCE_AUDIT_20261115_CURRENT_HEAD"
```

Exit code 0. No Quartus, JTAG, board, key, power, external inquiry, or source/constraint modification was involved. The DE0-CV-specific timing blocker is unchanged; the official product-page search showed the published user manual entry but no board-specific controller timing specification. The Terasic page could not be opened in the web retrieval, and no new timing data was obtained. Do not treat this unsuccessful fetch as a new specification review or repeat the same lookup absent new material.

### Remote branch identity recheck

Command (PowerShell, repository root): `git ls-remote origin refs/heads/codex/stage-c3-jtag-pilot-20261114`. Exit 0; remote ref resolved to `b332ba02ab992227140998a1d67513c690ae17cf`, equal to local HEAD. Captured stdout and exit code: `origin_branch_head_recheck.log` and `.exitcode`.

### UCP端点とstatus chronologyの現HEAD再照合

未制約LED/JTAG端点をtop RTL・QSF・SDC・TimeQuest reportへ結び直し、古いmanual reviewのゲート記述とC3 v2現行statusの適用範囲を比較した。新規 checker `source/audit_c3_v2_ucp_disposition.py` は期待するsource/report hashes、4つのUCP count、各port名、LED pin/function mapping、delay constraint不在、C3 v2 current audit gate classificationを検査する。出力は`evidence/GATE_B_C3V2_AUDIT_20261115/ucp_disposition_audit_retry01.json`、exit 0。Python 3.11.9、PowerShell 7.6.9、CWDはrepository root。

```powershell
python -m py_compile artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/source/audit_c3_v2_ucp_disposition.py
python artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/source/audit_c3_v2_ucp_disposition.py --c3-root artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3 --output-json artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/GATE_B_C3V2_AUDIT_20261115/ucp_disposition_audit_retry01.json
```

実結果: LED/JTAG UCP rolesとstatus chronologyを保存RTL/QSF/SDC/STA identityに照合。TDI/TMS/TDOの外部タイミング不足は残り、LEDR[0/1/3]は表示器として区別したがUCP/fitter警告は残した。C2時代のB-EMPIRICAL BLOCKEDと、C3 v2 build `43334531`のpilot適格性PASS_LIMITEDは別build/scope。native 146-source依存グラフ再build未解決。Quartus/JTAG/基板操作なし。

### Retained Terasic System CD archive recheck

Rehashed the retained official `DE0-CV_v.1.2.1_SystemCD.zip` at `D:\RTNN_C3_external_docs_20261114` and validated the ZIP plus the previously selected member hashes. The first audit parser attempt failed with exit 1 because its QSF-line selector omitted `USE_CONFIGURATION_DEVICE`; the original log is retained. After correcting the parser, retry02 and the broader text-based project/source scan retry03 exited 0. The latter scanned `.qar/.qsf/.qpf/.sdc/.v/.sv/.vhd/.vhdl` content: six project device declarations were all Cyclone V `5CEBA4F23C7`, with no EPM240/MAX II/USB-Blaster controller terms. The scan does not reverse engineer binary images/DLLs. Raw outputs and exit codes are preserved; see `evidence/JTAG_CONTROLLER_PACKAGE_RECHECK_20261115/RUN_RECORD_JA.md`.

This confirms that the already retained vendor package does not supply the missing board-specific external JTAG timing input within the inspected scope. The task now requires new external evidence (Terasic timing data or appropriately instrumented board/cable characterization). No board or JTAG operation was performed.

The final archive audit JSON is `system_cd_timing_assets_audit_retry04.json`; its status string is scoped to the text-based project/source scan. Retry04 used the same input ZIP SHA and passed compilation and content/inventory checks. The earlier retry01 parser failure remains recorded and was not overwritten.
