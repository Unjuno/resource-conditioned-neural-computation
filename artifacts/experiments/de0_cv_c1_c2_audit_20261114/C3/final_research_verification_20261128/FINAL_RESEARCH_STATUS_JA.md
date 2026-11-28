# RTNN 最終研究検証 — 2026-11-28

> **最新状態（2026-11-28、primary session 01完了後）**：以下に残る「primary NOT_RUN」「実機データなし」等の文は、各節に記録された当時点の履歴スナップショットであり、現在状態ではない。履歴ログを改変せず、現在の判定はこの追記を優先する。

## 最新ゲート状態

* 対象branch `codex/external-validation-20261122`、HEAD `8ae54fea823ff59fcbd04849e53eba1f047d6bad`、originは正しいUnjunoリポジトリ。旧`kardaneh/RTnn`は未使用。
* 3-session計画のsession 01を完了：`C3_EXTVAL_PRIMARY_20261128_S01`。固定2/adaptive各3,813件、合計7,626/7,626。保存raw JTAG要求・応答、結果CSV、CPU Q15 oracleを独立監査し、identity/CRC/予測/Exit/counter整合PASS、不一致・欠損0。
* session 01単独の経験値：fixed2正解3,482/3,813、平均943,905.78 cycles。adaptive正解3,485/3,813、平均759,704.67 cycles。対応平均cycle削減19.515%（入力bootstrap 95%区間18.106–20.871%）。adaptiveが遅い入力929/3,813。非劣性の数値下限−0.639 ppで事前margin−1 ppを数値上クリアしたが、1 sessionのみの数値結果。
* session 01だけでは、3-session cycle gate、起動間再現性、母集団への速度優位・精度非劣性は判定しない。`COLD_BOOT_UNVERIFIED`を維持する。session 02/03は未実行。
* 独立監査JSON：`primary_session01_independent_audit.json`。SHA-256：`18e2fffdf124a40d8011b5ff71ed3271cfe2a8555b4eec6ed03b17b33b15a43e`。監査コードSHA、各runファイルSHA、件数、sequence範囲、build identityを記録。これは保存ログ間の整合性監査であり、ログが物理的に取得されたことの暗号学的証明ではない。
* 現在の最初の人手待ち：session 02前のboard power transitionについて、操作者が何を行ったかの確認。読み取り専用identityだけから電源断を推定しない。いずれのセッションも、完全なrail遮断を裏付ける証拠がなければ独立cold bootとは認定しない。
* 以下の未解決状態は維持：`DATA_EXPOSURE_UNCERTAIN`、`WRITER_CLUSTER_UNKNOWN`、`PREREGISTRATION_TIMELINE_UNVERIFIED`、`COLD_BOOT_UNVERIFIED`、`FORMAL_TIMING_SIGNOFF_BLOCKED`。

詳細なsession 01進捗は`../external_validation_20261122/build/physical_primary_3session_20261128/PRIMARY_CAMPAIGN_PROGRESS_JA.md`、再集計は`../external_validation_20261122/build/physical_primary_3session_20261128/session_01/analysis_single/analysis.json`にある。

## 判定

* primary予定表: **PASS_OFFLINE_ONLY** — 凍結manifest・pixel bytes/SHA・host-only label・Q15 oracle・mode順・CRC・identityを7,626行すべて照合。これは実機データではない。
* 保存済みRUN4 pilot: **PASS_LIMITED_FUNCTIONAL_EVIDENCE** — 今回 `PILOT_GATE_VALIDATOR.py --verify-gate` を保存gateに対して再実行し、20要求、10画像、oracle一致を再検証。raw応答も新しい監査器で再デコードし、pair/counter/CRC/ID/framingを独立点検した。
* PowerShell/Tcl fail-closed: **PASS_OFFLINE** — primary gateなしのPowerShell起動、binding作成、Tcl直接起動は機器検出前に拒否する既存試験がPASS。Tcl runtime mockは隔離tempでのみ20件を完走し、production監査ではmock拒否。
* 新しいprimary実機評価: **NOT_RUN** — primaryを実行する承認は今回確認できていない。過去のSRAM＋pilot許可はprimaryに及ばない。
* 主張適格性: `DATA_EXPOSURE_UNCERTAIN`; `WRITER_CLUSTER_UNKNOWN`; `PREREGISTRATION_TIMELINE_UNVERIFIED`; `COLD_BOOT_UNVERIFIED`; `FORMAL_TIMING_SIGNOFF_BLOCKED` を維持。
* 既存 `sklearn.load_digits` heldout上の同一凍結Q15停止方式比較: **PASS_OFFLINE_EXPLORATORY** — RUN8で固定Exit 0〜6、凍結entropy、validationで閾値選定したmax-softmax/top-two margin、事後oracleの11方式を比較。Pareto図と全画像出力を保全し、統計は探索的、block数はcycleではない。外部UCI primary結果は未取得。以前のtoolchain-blocked記載はZig経由の実行以前の状態であり、この比較については解消済み。
* 旧C3 v2 24,840要求の再現可能な再集計: **PASS_SAVED_EVIDENCE_EMPIRICAL_ONLY** — 新しい出力先へ保存済みraw campaignから再実行。13/13 schedules、24,840 rows、primary 7,200 rows/360入力を確認。fixed2/adaptive平均 cycle 943,929.77/746,327.99、観測削減20.934%、入力単位95%区間16.804–24.903%。これはbuild `43334531` 固有の経験的結果で、新buildの測定と混ぜない。accuracy差の区間−1.389〜+1.389 ppは1 pp非劣性を示さない。

## pilot保存値の記述的再集計

RUN4の既存`physical_results.csv`のみから再生成: fixed2/adaptive各10件で教師ラベル正解は各10/10、adaptiveのcycleが少ない入力8/10、ID 519・667では各127,563 cycle多い。fixed2中央値943,906、adaptive中央値565,923、ratio-of-sums記述削減率29.33%。選択pilot 10入力・単一電源epochの記述値であり、信頼区間・非劣性・一般的速度優位を示さない。実機の新しい操作は一切実行していない。

## 新規成果

このディレクトリに独立primary/raw JTAG監査器、schedule generator、負例テスト、pilot再集計器、primary post-run解析器、1-session exploratory amendment草稿、形式証拠対応表、英語論文addendum、claim-evidence matrixを保存した。オフライン予定表はsequence 22–7647。sequence 2–21はRUN4、RUN2/3の失敗ログはsequence 1を使った記録に基づく。これは現在FPGA状態の読み出しではないため、実機前にsequence状態確認が必要。

## 実行した検証

* `py -3.11 -B .../test_primary_audit.py`: 14/14 PASS。
* `py -3.11 -B .../test_pilot_descriptive.py`: 3/3 PASS。
* `py -3.11 -B .../test_primary_analysis.py`: 2/2 PASS（offline scheduleとphysical-run欠落拒否）。
* `py -3.11 -B .../safety_gates_v1_20261122/test_runner_preflight.py`: 4/4 PASS。
* `py -3.11 -B .../host_v2_20261126/test_mock_runtime.py`: 1/1 PASS、Quartus STP mock runtime。
* `PYTHONPATH=$env:TEMP/rtnn_sklearn_1_8_0 py -3.11 -B .../scripts/test_stats_core.py`: 4/4 PASS。
* `py -3.11 -B .../scripts/test_physical_audit_fail_closed.py`: 2/2 PASS。
* 合計30/30テストPASS。RUN4 gate validatorも独立再検証PASS。

最初のstats-core実行ではSciPyが既定Python環境に無く2件が環境エラーになった。保存済みSciPy依存環境をPYTHONPATHで指定して再実行し4/4 PASS。存在しないテストファイル名を誤って指定した1コマンドもあり、ファイルを変更せず停止。詳細は`RUN_RECORD_JA.md`。

## 残る人手作業

1. primaryを実施するかどうか、規模（提案1 session exploratory）と明示承認を決める。
2. その決定前にamendmentをレビューし、primary結果を見る前に署名/時刻/SHA/適用commitを固定する。
3. 実機の新build・mailbox状態・次sequenceをread-onlyで確認し、許可されたら新しいprimary bindingを作る。
4. 7,626件を実機で実行してから`audit_primary.py run`、続いて`analyze_audited_primary.py`を実行。mockは不可。
5. legacy `load_digits`での同一Q15停止方式比較は完了済み（固定Exit 0〜6、entropy、validation選択max-softmax/margin、事後oracle）。これは探索解析であり、UCI primary結果として流用しない。UCI側で方式を追加・変更する必要があるなら、primary結果を見る前に独立amendmentへ固定する。
6. writer ID/データ来歴、外部JTAG timing仕様、正式STA/WCETは別の証拠を入手しない限り未確定。

この時点ではprimary性能結果や確認的仮説の最終判定を報告できない。研究報告は、既存のソフトウェア/RTL scope内の形式・測定証拠と、10画像pilotの限定機能デモに限定する。

## 2026-11-28 最新追記：Q15停止則の補助解析

`Q15_STOPPING_ANALYSIS_JA.md` に、固定Q15 coreを再実行したExit別分類・停止方式比較を追加した。validation359/heldout360の全7 Exit予測が既存oracleと一致。固定Exit 0〜6、entropy、validation閾値のmax-softmax/top-two margin、事後oracleを含む全11方式の比較表とPareto図を保存した。既存entropy停止はheldout360でfixed2と同じ339/360正解、平均1.358 optional blocks対fixed2の2.000。entropy-only誤り3件とfixed2-only誤り3件を明示した。精度差bootstrap区間は0を含み、writer clusterも未確定のため非劣性は主張しない。optional blockはcycleではない。旧状態の`BLOCKED_TOOLCHAIN/LOGIT_ARTIFACT`はこのload_digits探索解析については解消済み。新規UCI画像の実機主要評価は未実施。

これは既存sklearn heldoutの探索的再解析であり、新規UCI画像の外部検証にも実機速度試験にも当たらない。primary外部評価は未実行。旧C3 pilot 20/20は限定的な機能整合性証拠としてのみ維持する。

### 統合英語草稿

`MANUSCRIPT_EN_DRAFT_20261128B.md` を新規作成し、CBMC、pinned Ibex RTL、旧C3 v2 campaign、新build DE0-CV pilot、Q15停止方式の探索的解析を証拠層ごとに分けて統合した。歴史的な `paper_20261117/MANUSCRIPT_DRAFT_EN.md` は変更していない。新稿では旧buildの24,840件を新buildの証拠に流用せず、UCI primary 7,626要求はoffline templateのみ、実機未実施と明記した。source/evidence表、参考文献リンク、変数の意味と範囲を追加し、凍結primary計画の判定と旧heldout探索解析を区別した。数値・統計・未解決ゲートは既存の監査済み記録から転記し、新しい実験結果は追加していない。レビュー前の原稿であり投稿用完成稿ではない。

UCI公式資料の追加確認に基づき、原稿へ筆記者pool分割の限定を追加した。公式記録はtraining sideの30人とtest sideの別の13人を記し、RTNNの追跡済み`load_digits`配列は`optdigits.tes`と一致する。よって追跡済み旧データとの間にはsplit-level writer separationの根拠がある。一方、未記録の`optdigits.tra`先行使用は否定できず、tra各行のwriter IDもないため、`DATA_EXPOSURE_UNCERTAIN`と`WRITER_CLUSTER_UNKNOWN`を維持する。出典はUCI dataset record、既存`PRIOR_DATA_USE_AUDIT_JA.md`と`DATASET_AUDIT_JA.md`。

凍結事前登録の未実施primary条件も原稿に明記した。予定は3 session×7,626要求=22,878要求。H1は片側paired Clopper–Pearson/Bonferroni下限が−1 ppを超える条件、H2は点推定5%以上かつ10,000回bootstrap 95%下限>5%である。どちらも未評価。旧heldoutの20,000反復percentile bootstrapは探索解析であり、H1の規定検定と同一視しない。提案の1-session amendmentは未承認・未適用。

未追跡`physical_pilot_RUN2_preparation/`は20件候補入力CSVのみと確認。raw JTAG、実行状態、実測結果、独立監査証拠は見つからず、新しいpilot実施とは判定しない。CSVは変更・削除せず未追跡のまま保全。

統合稿と`CLAIM_EVIDENCE_MATRIX.csv`のpathを再照合し、解決できなかった参照3件（行列1、本文2）を実在pathへ修正。最終確認で行列13件・本文12件の参照が全件存在する。詳細は`RUN_RECORD_JA.md`。

Exit間の正誤遷移も全360件で監査し、12画像で「浅いExitで正解した後、後段Exitで誤りに戻る」非単調性を確認した。Exit 5→6は改善0・退行3。Exit 2以降で精度が単調に上がるとの主張はこのデータに反する。全入力のExit予測・正誤は `exit_counterexamples_RUN2_20261128/` に保存した。

### 現在のゲート

| 仮説・ゲート | 状態 | 根拠 |
|---|---|---|
| 新buildの10画像pilotでCPU Q15 oracleを再現 | PASS_LIMITED | 既存RUN4の20/20実機要求・独立監査。 |
| primaryの7,626要求の整合性・監査準備 | PASS_OFFLINE_ONLY | schedule/validatorと既存offline tests。実測結果はない。 |
| fixed2に対するentropy停止の正答率差 | INCONCLUSIVE_EXPLORATORY | heldout正解数は同じだがpaired image区間は0をまたぎ、writer cluster不明。 |
| 停止方式による演算block差 | DESCRIPTIVE_ONLY | Q15再実行でoptional blocks差を算出。cycle・遅延を測定していない。 |
| 新UCI外部評価の機能・精度・cycle | NOT_RUN | primary 3,813画像の実機投入なし。 |
| 正式タイミング/WCET/期限保証 | BLOCKED | 外部JTAG timingや基板条件の証拠不足。 |

変更していない保留ラベル：`DATA_EXPOSURE_UNCERTAIN`、`WRITER_CLUSTER_UNKNOWN`、`PREREGISTRATION_TIMELINE_UNVERIFIED`、`COLD_BOOT_UNVERIFIED`、`FORMAL_TIMING_SIGNOFF_BLOCKED`。

## 仮説別の判定（H / T / D / C / U）

| 仮説・主張 | 判定 | 根拠と範囲 |
|---|---|---|
| 新firmwareの動的画像入力が固定Q15 oracleと整合する | **PASS_LIMITED** | DE0-CV RUN4のpilot 10画像×2方式、20/20要求。外部標本精度や全UCI評価は未検証。 |
| 新UCI候補でadaptiveがfixed2より5%以上cyclesを削減 | **NOT_EVALUATED** | 3,813画像の実機primaryは未実施。旧C3 v2の別buildでは観測削減20.934%だが、既知結果を使ったfixed2 comparator、固定360画像、独立cold boot未確認の経験値。閾値達成を新規仮説のPASSに使わない。 |
| 新UCI候補でaccuracy差の1 pp非劣性を満たす | **NOT_EVALUATED / PRIOR ANALYSES INCONCLUSIVE** | UCI primary未実施。旧360入力で両方式339/360という同数でも、対応差区間は−1.389〜+1.389 ppで1 pp条件を示さない。筆記者clusterも未確定。 |
| adaptive停止が同一Q15の計算量を下げうる | **OFFLINE_EXPLORATORY SUPPORT** | legacy heldoutでentropy平均1.358 optional blocks、fixed2は2.000。confidence方式もvalidation調整後のheldoutで比較。optional blockはFPGA cyclesではない。 |
| 深いExitは個別予測を常に改善する | **FALSIFIED ON OBSERVED HELDOUT SET** | 360画像の12件で浅いExitの正解後に深いExitで誤りへ戻った。一般母集団の割合や因果説明には拡張しない。 |
| 有限work制御・pinned Ibexのcycle binding | **PASS_WITH_SCOPE** | CBMCと指定pinned Simple-System RTLの保存済み証明・測定。新外部入力firmwareの全設定、DE0-CV物理timing、WCETの証明ではない。 |
| DE0-CVの外部JTAG timing・formal WCET | **BLOCKED** | 外部JTAG timing前提と完全な基板制約/証拠が不足。経験的cycle結果で解除しない。 |

Uは画像露出履歴、筆記者内相関、電源起動独立性、校正済み時間、外部JTAG timingを含む。値のない不確かさは推定不能のままとし、入力bootstrapでボード/起動間不確かさを代用しない。

### 2026-11-28追記：primary測定前のcase/raw-frame guard

Primary preflightの内容検証を追加した。binding作成とJTAG前段で7,626件すべてをfrozen primary manifestの画素SHA・label、primary input bytes、CPU oracleのmode別予測/Exit/stop/cap、既存offline order template、連番sequenceと照合する。後続sessionのsequenceにより先行runの再監査を誤拒否しないことも検査する。保存済みraw request/responseを復号し、frame/CRC/identity/入力/結果/mcycle区間をCSVと独立照合する。sequence履歴は保存JTAG logから最大値を読み、最大観測sequence 21より後から始める。`prepare_primary_execution.py`はこの順序から新しいcase CSVをofflineで準備するが、今回は実験CSV/bindingを作成せず、JTAGにも接続していない。

`host_v2_20261126`に対応するPython/PowerShell/Tcl offline testsとraw parser試験は35/35 PASS。詳細な変更、実行ログ、25項目のSHA manifestは`final_research_verification_20261128/primary_audit_hardening_RUN1_20261128/SHA256SUMS.txt`。途中失敗の保全場所は`final_research_verification_20261128/primary_audit_hardening_RUN1_20261128/PRIMARY_AUDIT_HARDENING_RUN1_20261128.md`。

Primary 7,626件は**NOT_RUN**。最初の未解決アクションは、ユーザーによるscope/amendment決定と、実機前での明示許可。現在のscope選択・amendment固定・実機identity確認を終えるまで、主測定へ進まない。

### 2026-11-28追記：claim-evidence matrixの参照監査

`CLAIM_EVIDENCE_MATRIX.csv`のC6/C7/C8 `evidence`欄に説明文が入り、ファイルとして追跡できない不備を修正。11 claimすべての参照先をリポジトリ内の実ファイルに置き換え、将来の欠損・パストラバーサル・状態改変を検出する`verify_claim_evidence_matrix.py`を追加した。実行結果は11/11 claim path解決、validator負例テスト5/5 PASS、`py_compile` PASS。未実施primary・データ適格性・JTAG timing状態を格上げしていない。記録は`claim_evidence_matrix_audit_RUN1_20261128/`。

### 関連研究のスコープ監査（2026-11-28）

統合英語草稿の関連研究[7]を確認し、entropy-driven video frame processing-rate adaptationとして限定した。これは画像ごとの内部early exitとは異なる。文献とUCI writer-pool情報の監査記録、実行ログ、SHA manifestは`BIBLIOGRAPHY_SCOPE_AUDIT_20261128.md`および`literature_scope_audit_RUN1_20261128/`にある。この修正で研究の新規性や実験状態は格上げしていない。`DATA_EXPOSURE_UNCERTAIN`、`WRITER_CLUSTER_UNKNOWN`、`PREREGISTRATION_TIMELINE_UNVERIFIED`、`COLD_BOOT_UNVERIFIED`、`FORMAL_TIMING_SIGNOFF_BLOCKED`、primary `NOT_RUN`は維持する。

### 最終オフライン回帰（2026-11-28）

論文Q15表11/11行照合、停止方式/Exit遷移/primary監査/解析の24/24テストを再実行してPASS。保存ログとSHA一覧は`final_offline_audit_RUN1_20261128/`。これはオフライン成果物検査であり、新規実機データではない。primaryはNOT_RUN、主要な来歴・writer cluster・cold boot・正式タイミング未解決状態は維持する。
