# RTNN C3 基板なし解析・再現性準備 — 2026-11-15

## 判定

このレポートは保存済みデータを再検算した結果であり、新しい基板測定ではない。C2J2旧構成とC3 v2はbuild/SOF単位で分けている。

| 工程 | 判定 | 結果 |
|---|---|---|
| 旧C2J2キャンペーン再集計 | **PASS_DATA_INTEGRITY_EMPIRICAL_ONLY** | 13 schedule、24,840/24,840行を生CSV・frozen schedule・oracleから再検算。RUN4/RUN5集約CSVも全行一致。 |
| 旧C2J2統計 | **記述値のみ** | cycle差は計算したがcold-boot独立性が不足するため速度優位は主張しない。1 pp精度非劣性はINCONCLUSIVE。 |
| C3 v2保存42件 | **PASS_SAVED_PHYSICAL_EVIDENCE_AUDIT** | JSON/CSV/cases/raw log、ID、CRC、64-bit cycleを別実装で再照合。これは新規測定ではない。 |
| C3 v2 pilot 20件 | **PASS_SAVED_PHYSICAL_EVIDENCE_AUDIT** | 同上。SESSION1の結果で、KEY reset replayではない。 |
| C3 v2負例監査 | **PASS** | 13件のPython unittest。重複・欠落・uint64 overflow・単調性・差分・CRC・応答ID・build混合・mock path・reset gate誤用・read-only identity checkerを含む。 |
| C3 v2保存STA/CDCレポート再監査 | **内部経路LIMITED PASS / B-SIGNOFF BLOCKED** | 保存ログの4 corner、req 800/800・rsp 480/480 route index、UCP、16件D102を再集計。response source collection 484件は、追加Quartus STA-only再実行で480 logical bit coordinates＋4 `~DUPLICATE` fitter registersと特定。600 path上限で4 cornerを再出力し、全480 bit indexを各1回routeすることを確認。外部JTAG I/Oは未制約、D102は未抑制。詳細は[`Gate B audit`](../evidence/GATE_B_C3V2_AUDIT_20261115/GATE_B_AUDIT_JA.md)、[selector再照合記録](../evidence/GATE_B_D102_SELECTOR_RECHECK_20261115/RUN_RECORD_JA.md)、[監査JSON](../evidence/GATE_B_D102_SELECTOR_RECHECK_20261115/d102_protocol_audit_retry03.json)。この再実行は複製fitted projectに対するSTAのみで、Fitter/Assembler/SOF/基板を再実行していない。 |
| Gate B 59-file source/evidence audit at current HEAD | **PASS_FOR_REPORTED_EVIDENCE_ONLY / B-SIGNOFF BLOCKED** | Earlier saved audit ran at parent commit `c17c44e`; rerun from current branch HEAD `b332ba0` rehashed the 59 listed evidence files, checked all 13 bindings/24,840 rows, four setup/hold corners and 16 D102 findings. Classification remains blocked for external JTAG timing and unconstrained I/O. This is a read-only evidence consistency audit, not Quartus or board timing signoff. See [current-HEAD run record](../evidence/C3_GATE_B_EVIDENCE_AUDIT_20261115_CURRENT_HEAD/RUN_RECORD_JA.md). |
| bundled-data hold sequence | **LIMITED — current fixed firmware path** | Request/response hold、sync、capture pending、ack/consumeをソース・既存42-case testbench・4-corner routed-delay reportへ対応付けた。response registerはcommit中の任意CPU MMIO writeをSoC RTLでロックしていないため、holdは保存済み固定firmwareのcommit後poll動作に依存する。これはfinite simulationで、formal CDC proofではない。[sequence audit](../evidence/GATE_B_C3V2_AUDIT_20261115/BUNDLED_DATA_HOLD_SEQUENCE_20261115_JA.md)。 |
| 未制約I/Oの用途分類・歴史status整合 | **分類明確化、Gate判定据置** | TDI/TMS/TDOは外部JTAG capture/setup timing不足の機能端点。LEDR[0/1/3]は表示LEDで同期受信先なし。LED出力はUCP一覧とFitter drive/slew warningから削除・false-path化していない。旧manual reviewのB-EMPIRICAL blockedは当時の32-bit response/source review時点で、C3 v2 64-bit pilotの`PASS_LIMITED`とはbuild・gate scopeが異なる。詳細と入力hashは[追加照合記録](../evidence/GATE_B_C3V2_AUDIT_20261115/UCP_AND_STATUS_CHRONOLOGY_RECHECK_20261115_JA.md)。 |
| Terasic System CD archive recheck | **PASS — saved archive integrity; timing blocker remains** | Official ZIP rehashed (`ed4ac9cf...`), ZIP test PASS, 1,089 members and selected file hashes match. Content scan covered `.qar/.qsf/.qpf/.sdc/.v/.sv/.vhd/.vhdl`; no project-source reference to EPM240/MAX II/USB-Blaster and all project device declarations are Cyclone V. Binary reverse engineering was not performed, so scope is explicit. See [recheck record](../evidence/JTAG_CONTROLLER_PACKAGE_RECHECK_20261115/RUN_RECORD_JA.md). |
| ロード済みbuild識別Tcl | **PASS_OFFLINE_SELFTEST** | Quartus STP Tcl 25.1 Build 1129、自己試験終了コード0。`--self-test`なのでJTAG APIは呼ばず、基板にアクセスしていない。 |
| KEY reset replay | **PENDING_HUMAN_ACTION** | KEY[0]の押下・解放は今回実施していない。gate JSONは生成していない。 |
| C3 v2 24,840件物理campaign | **NOT_RUN** | reset replay gate成立前。新C3 v2の物理取得行数は0。 |
| 正式タイミングsignoff | **BLOCKED** | 外部JTAG timingが未確定。今回のオフライン作業で格上げしていない。 |

## 旧C2J2の独立再集計

入力元は凍結campaign SHA-256 `d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc`、campaign JSON SHA-256 `3d97a1cd87395e294299cacb617474367c89a9295355cd25fb1b4fa67464c936`、heldout input SHA-256 `eeba9000a918bcba911007e78905c5052fc743422f95cb314a0fc9f4ecdfb14c`、Q15 oracle SHA-256 `4e1a3ddcabe1884b1607c77d19b10da8a86d53da3f4c060c30d7449635ec3cf4`、Q15 weight header SHA-256 `961a76b7e220bf2f665e7c04ab62063600aa2e7eccf3403d80ea730bc993ad9f`。旧build `43324a32`、model `52544e4e`、SOF `5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6`へ固定した。C3 v2データは入力していない。

| schedule | frozen/expected | raw取得 | 重複・欠損・余分 |
|---|---:|---:|---:|
| diagnostic_fixed | 2,520 | 2,520 | 0 |
| diagnostic_adaptive | 7,560 | 7,560 | 0 |
| diagnostic_capped | 7,560 | 7,560 | 0 |
| primary_01 | 720 | 720 | 0 |
| primary_02–primary_10（9×720） | **6,480** | **6,480** | 0 |
| 合計 | **24,840** | **24,840** | 0 |

全件でfrozen sequence/input/mode/budget/expected exits/期待Q15予測との照合、応答ID、CRC、予測、Exit、cap、cycle_valid、timeout/trap/errorを確認し違反0。case CSV SHA、分割chunk SHA・sequence範囲、保存manifestのoutput SHAも照合。primary_02–10の旧run記録にあった`7,200`は9×720と合わない転記誤りで、生データから**6,480**へ訂正した。総数24,840は変わらない。旧RUN4とRUN5の結合CSVは各hash `f8651f29f42febe85a3c83a3ae245c0bcea56caadafc1fe9b7dd11a1f77277cf`で一致し、独立再結合した24,840行と各列で一致した。

### 主解析（事前登録単位を保持）

primary schedule 10本の各360 inputをIDで対応付けた3,600組。bootstrapは360独立input IDを単位に10反復を平均し、seed 63、5,000 replicates。

| 指標 | 保存値からの再計算 |
|---|---:|
| fixed Exit 2 cycle平均（3,600観測） | 943,924.77 |
| adaptive cycle平均（3,600観測） | 746,322.99 |
| fixed2 − adaptive平均差 | +197,601.77 cycles |
| 対応差のinput-bootstrap 95% CI | [158,616.47, 235,071.07] cycles |
| 平均削減率、同じ入力bootstrap | 20.934% [16.804%, 24.904%] |
| 360入力ごとの平均サイクル差の中央値 | +377,974 cycles |
| fixed2 cycle分布（p25 / median / p75） | 943,924 / 943,925 / 943,925 cycles |
| adaptive cycle分布（p25 / median / p75） | 565,950 / 565,951 / 1,071,495 cycles |
| adaptiveが少ないcycleだった入力 | 263/360 |
| adaptiveが多いcycleだった入力 | 97/360 |

差のCIは保存されたrun集合に対する条件付きの記述値である。確認済みの独立cold bootが不足しているので、凍結計画に必要なboot間推定は成立せず、**速度優位は主張しない**。教師ラベル正解率はfixed2=339/360、adaptive=339/360。入力ID単位のpaired accuracy差は0 pp、95%区間は[-1.389,+1.389] ppであり、1 pp非劣性は**INCONCLUSIVE**。反復3,600組を独立分類入力3,600件とは数えない。

| adaptiveが遅かった代表input | fixed2平均 | adaptive平均 | fixed2−adaptive |
|---:|---:|---:|---:|
| 261 | 943,924 | 2,547,937 | −1,604,013 |
| 57 | 943,924 | 2,547,936 | −1,604,012 |
| 145 | 943,924 | 2,547,936 | −1,604,012 |
| 230 | 943,926 | 2,547,938 | −1,604,012 |
| 251 | 943,925 | 2,547,937 | −1,604,012 |
| 283 | 943,925 | 2,547,937 | −1,604,012 |
| 71 | 943,925 | 2,547,936 | −1,604,011 |

全360入力表は[`adaptive_slowest_20_inputs.csv`](../campaign/analysis/C3_C2J2_INDEPENDENT_REAUDIT_20261115_RETRY05/adaptive_slowest_20_inputs.csv)。20件は探索的な例示で、事前登録主解析とは分ける。adaptive executed Exit countsはExit 1: 2,630、Exit 2: 810、Exit 3: 70、Exit 4: 20、Exit 5: 70。fixed2の3,600行はすべてExit 2。

## 論文用図表（旧C2J2実測のみ）

各SVGにbuild ID、SOF SHA、独立input数、primary反復条件、測定境界、`EMPIRICAL_ONLY`と未成立の限界をSVG metadata/footerで記載した。新C3 v2のcampaign実測図は作っていない。

1. [入力別paired cycle差](../campaign/analysis/C3_C2J2_INDEPENDENT_REAUDIT_20261115_RETRY05/figure_01_paired_cycle_saving.svg)
2. [固定・適応のcycle経験CDF](../campaign/analysis/C3_C2J2_INDEPENDENT_REAUDIT_20261115_RETRY05/figure_02_cycle_distribution_cdf.svg)
3. [executed Exit別cycle分布](../campaign/analysis/C3_C2J2_INDEPENDENT_REAUDIT_20261115_RETRY05/figure_03_executed_exit_vs_cycles.svg)
4. [教師ラベル正答率とcycleのtrade-off](../campaign/analysis/C3_C2J2_INDEPENDENT_REAUDIT_20261115_RETRY05/figure_04_accuracy_cycle_tradeoff.svg)

図表元CSVは`primary_paired_by_input.csv`、`primary_rows_for_figures.csv`、`adaptive_slowest_20_inputs.csv`、`adaptive_fastest_20_inputs.csv`。全生成物hashは同じ分析フォルダの`SHA256SUMS.txt`。

## C3 v2解析系

追加した[`audit_saved_c3_v2_runs.py`](../source/audit_saved_c3_v2_runs.py)はJSON・CSV・frozen case・binding・raw JTAG logを相互照合する。各ケースのsequence一意性と順序、case/runのinput/mode/期待予測/Exit、応答ID、model/build/SOF、CRC、status/error、uint64範囲、`end > start`、`end-start == cycles == reported_cycles`、生応答hexを検査する。CLIはC3 v2の保存実機証拠ディレクトリ内だけを受け付け、`SAVED_PHYSICAL_EVIDENCE_NOT_NEW_MEASUREMENT`と明記する。保存済み42件と20件は独立再監査PASS。

13件のunittestは実在する保存済みrunを基準にメモリ上の入力を変異し、期待失敗を確認する。mock/syntheticデータは一時ディレクトリだけでpath拒否をテストし、物理データとして出力しない。旧C2J2とC3 v2のbuild/SOF/model/scheduleを統合する操作はbuild consistency guardで拒否する。reset gate作成器[`create_key_reset_replay_gate.py`](../source/create_key_reset_replay_gate.py)も用意したが実行していない。既存SESSION1実験IDからgateを作れない負例テストはPASS。

既存PowerShell auditorは42件をPASSした。20件ファイルを含む保存場所はMAX_PATHを超える262文字で、PowerShellの既存auditorは相対/絶対パスの両方でファイルを開けずFAILした。これはデータ不一致ではない。新Python checkerはWin32 extended path経由で42/20双方をPASSした。実機再開runは短いASCII一時領域で実行し、PowerShell監査後に証跡treeへ保存してPython独立監査する。PowerShell 20件失敗ログは`OFFLINE_REPRO_20261115/powershell_existing_audit_20_retry01.log`に保管。

## source/build/依存と再現範囲

* repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`; branch `codex/stage-c3-jtag-pilot-20261114`;開始時HEAD `b332ba02ab992227140998a1d67513c690ae17cf`。
* 使用版: Python 3.11.9、作業shell PowerShell 7.6.9、Quartus Prime Lite 25.1std.0 Build 1129（自己試験ログ）。既存PowerShell auditorは`powershell.exe`で起動したが、その子プロセスの版はこのrun logに保存されていない。本turnでQuartus compile、JTAG、Programmerは実行していない。
* 既存C3 v2の保全identity: build `43334531`、SOF `85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d`、ELF `9cbf537bd9440deaf5c78abf6b204da9cbcd2fe3795acf444d733dbd581002b6`、model `52544e4e`、campaign `d6c98f59...`。
* native source-listは146 entry、原本SHA `4bddc5bd5e37cbd24015189d49e4a21677d570e5cb1c0a7c9dd503da30e6bfba`。原本は変更していない。パスmappingは[`native_source_list_path_map.json`](native_source_map/native_source_list_path_map.json)に分離。
* 146 sourceのうち141件は古いLinux絶対prefix `/opt/rtnn-tools/ibex/`。正しいリポジトリ内に該当Ibex RTLはなく、Ibex依存commit/SHAもこのmappingだけでは特定できない。残る5件は旧`/mnt/c/Users/junny/.../C2/`絶対pathをrepository相対へ解決し、ファイル存在を確認した。したがって現在のrepositoryからnative 146-source graphの再buildは**NOT_REPRODUCIBLE_YET**。架空のIBEX_ROOTやversionを補っていない。
* 図表生成はPython標準ライブラリのSVGで実装。matplotlibは不要。この解析/保存run auditでQuartus再buildやWSLは不要。

## 再実行コマンド

PowerShell、正しいrepository rootで実行する。`OUT`は未使用の新しいdirectory名にする（analyzerは上書きを拒否する）。

```powershell
python --version
$c3 = 'artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3'
python "$c3/source/reanalyze_c2j2_frozen_campaign.py" --c3-root "$c3" --out-dir "$c3/campaign/analysis/C3_C2J2_INDEPENDENT_REAUDIT_<NEW_ID>"
python "$c3/source/test_audit_saved_c3_v2_runs.py"
python -m py_compile "$c3/source/audit_saved_c3_v2_runs.py" "$c3/source/create_key_reset_replay_gate.py" "$c3/source/normalize_native_source_paths.py" "$c3/source/reanalyze_c2j2_frozen_campaign.py"
python "$c3/source/audit_c3_v2_gate_b_saved_reports.py" --c3-root "$c3" --output-json "$c3/evidence/GATE_B_C3V2_AUDIT_20261115/<NEW_RUN_ID>.json"
```

保存済みのC3 v2 run再監査コマンド例は`OFFLINE_REPRO_20261115`の`c3v2_saved_run2_audit.stdout.json`と`c3v2_pilot20_audit.stdout.json`に保存。実物のJTAG操作は含まれない。

## 限界

ここで確認したのは旧buildの保存行、集約、派生解析とC3 v2保存pilotの整合性だけ。cold boot、C3 v2 reset replay、物理campaign、外部JTAG timing signoff、WCET、absolute-time校正、1 pp accuracy noninferiorityの証拠を新規には得ていない。cycle差が正でも速度優位として結論しない。
