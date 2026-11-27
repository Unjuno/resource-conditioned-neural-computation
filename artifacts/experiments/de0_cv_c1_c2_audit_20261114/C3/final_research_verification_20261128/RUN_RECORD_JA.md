# 実行記録 — 2026-11-28

## 対象と保全

- 正repo: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
- branch: `codex/external-validation-20261122`
- start HEAD: `6ab7cdd31d2eae71ef8b1defc87a1abc69982ff7`
- tracked worktree clean。既存未追跡 `external_validation_20261122/build/physical_pilot_RUN2_preparation/` は保全。
- 旧 `kardaneh/RTnn` cwdは使用せず、書き込んでいない。
- 物理操作、JTAG、SOF/Flash、KEY0、電源、配線、oscilloscope操作なし。
- 既存SOF・ELFを再ハッシュし、SHA-256がそれぞれ `5e333e9377b7188a394d04b93b98833d91afb2cd53eca8d976e6aa715dfa00c4`、`4673f6a8b90493c15c327ed3be1167e0fcf3ff2be60292dcb12a1391124a0c2e` と一致。Q15 weight header hashはbuild manifest記載 `961a76b7e220bf2f665e7c04ab62063600aa2e7eccf3403d80ea730bc993ad9f`。

## 実行コマンドと結果

1. `py -3.11 -B artifacts/.../C3/final_research_verification_20261128/audit_primary.py schedule --cases artifacts/.../external_validation_20261122/build/host_cases_primary_attempt2/cases.csv --sequence-start 1` — 7,626件/3,813画像を凍結schedule監査。PASS。
2. `prepare_primary_schedule.py`で同じscheduleをoffline templateとしてsequence 22から再採番。metadataに `NOT_PHYSICAL_NOT_BOUND`, `binding_created=false`, `physical_authorized=false` を記録。
3. `test_primary_audit.py` — 14/14 PASS（不足・重複・順序・pixel・label・oracle・CRC・build・raw log・manifest traversal拒否を含む）。
4. `test_pilot_descriptive.py` — 3/3 PASS。RUN4の保存CSVを読むだけで検証。
5. `analyze_pilot_descriptive.py --results .../physical_pilot_RUN4_complete_20261126/physical_results.csv --out .../PILOT_DESCRIPTIVE_REANALYSIS.json` — 記述値を新dirへ出力。元RUN4は変更なし。
6. `safety_gates_v1_20261122/test_runner_preflight.py` — 4/4 PASS。PowerShell gate前拒否、Tcl gate前拒否、pilot preflight、primary binding拒否。
7. `host_v2_20261126/test_mock_runtime.py` — 1/1 PASS。Quartus STP mockのみ。production auditはmock outputを拒否。
8. `scripts/test_stats_core.py` — 初回SciPy import unavailable。その後 `PYTHONPATH=$env:TEMP/rtnn_sklearn_1_8_0` で4/4 PASS。
9. `scripts/test_physical_audit_fail_closed.py` — 2/2 PASS。
10. `test_primary_analysis.py` — offline schedule準備とphysical-run不足拒否の2テスト。
11. `PILOT_GATE_VALIDATOR.py --verify-gate .../pilot_gate_RUN4_20261126.json` — 実際のgate証拠を再読込し、`PILOT_AUDIT_PASS`、`EMPIRICAL_ONLY`。操作者申告は実行証明でない旨も確認。
12. `wsl.exe -d Ubuntu-22.04 -- bash ...` — `ERROR_NO_SUCH_DEVICE`でext4.vhdx mount失敗。起動状態変更やWSL再起動は行わず。
13. ツール探索 — Quartus Prime Lite 25.1 STPあり。C compiler（clang/gcc/MSVC）はPATHと標準位置で確認できず。実機操作なし。
14. `SHA256SUMS.txt` — 新規成果物を相対pathでhash。manifest自身は自己参照を避けるため除外。

途中、存在しない `test_audit_and_analyze.py` を指定したコマンドが一度失敗。既存コードへの影響なし。SciPyの環境エラーも依存パス指定後に解消している。

同様に `test_primary_analysis.py` の最初の実行で監査器のpackage import path不備を検出。package rootをsys.pathに追加するよう直し、その後2/2 PASS。新しく検出した問題と修正を含むfinal test countは30/30 PASS。

## 実験ファイルの境界

`primary_schedule_OFFLINE_TEMPLATE.csv` は凍結manifestからの予定表であり、実験binding・承認・実機結果ではない。RUN4 raw/CSV、旧C2J2/旧C3成果物は変更しない。mockは既存テストの一時ディレクトリ内に隔離された。

## 再現コマンド

PowerShell repository rootから:

```powershell
$d = 'artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128'
py -3.11 -B "$d/test_primary_audit.py"
py -3.11 -B "$d/test_pilot_descriptive.py"
py -3.11 -B "$d/test_primary_analysis.py"
py -3.11 -B 'artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/external_validation_20261122/safety_gates_v1_20261122/test_runner_preflight.py'
py -3.11 -B 'artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/external_validation_20261122/host_v2_20261126/test_mock_runtime.py'
$env:PYTHONPATH = Join-Path $env:TEMP 'rtnn_sklearn_1_8_0'
py -3.11 -B 'artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/external_validation_20261122/scripts/test_stats_core.py'
Remove-Item Env:PYTHONPATH
py -3.11 -B 'artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/external_validation_20261122/scripts/test_physical_audit_fail_closed.py'
```

## 2026-11-28追記：凍結Q15停止方式のオフライン比較

正しい作業クローン `resource-conditioned-neural-computation-c3-paper`、origin `Unjuno/resource-conditioned-neural-computation`、branch `codex/external-validation-20261122`、開始HEAD/remote HEAD `6bcdaac39fd20c38c3f00b609cfecad7d43ffabf` を確認。実験準備用の `physical_pilot_RUN2_preparation/` は未追跡の既存データなので変更しなかった。別の `RTNN` 旧クローンはoriginが `kardaneh/RTNN` で大量の差分があり、読み取り確認後は一切変更していない。

### 実行コマンド

```powershell
$repo = 'C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-c3-paper'
$d = Join-Path $repo 'artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128'
$zig = Join-Path $env:TEMP 'rtnn-zig-0.17.1-20261128\zig-x86_64-windows-0.17.1\zig.exe'
$sklearn = Join-Path $env:TEMP 'rtnn_sklearn_1_8_0'
python (Join-Path $d 'run_stopping_comparison.py') --zig $zig --sklearn-path $sklearn --out-dir (Join-Path $d 'q15_stopping_comparison_RUN8_20261128')
python (Join-Path $d 'test_stopping_comparison.py') -v
```

Zig 0.17.1 Windows x86_64 archiveをTEMPへ展開し、システムへのインストールやrepository追加はしていない。archive SHA-256: `B03F477A1943673E02ACA0F570E8030DFFD536CE1F45CBC4D3326EC31159562E`。C core・生成重みSHAは凍結値と一致。検証359件とheldout360件、各7 ExitをC helperで実行。Windows stdinのCR-LF変換を発見しstdin/stdout双方をbinary modeに固定。RUN8で359×7/360×7行、全Exit予測・preferred Exitのoracle不一致0、Q15確率合計32768±8を確認した。RUN8に実行stdoutとcompiler/raw input/outputの各SHAを保存。

初期のRUN1〜RUN5で検出・修正した入力切詰め、列スキーマ、Q15スケール、集計アクセス、固定方式check数の問題は `OFFLINE_Q15_ATTEMPTS_JA.md` に記録。RUN8のartifact検査5件、Exit遷移の独立検査3件がPASS。既存30件のオフラインテストは前回記録済みで無目的に再実行していない。

RUN8でentropy停止は固定2と同じ339/360正解、平均optional blocks 1.358対2.000。誤りの入替はentropyのみ誤り3件、固定2のみ誤り3件。適応方式3種のpaired correctness bootstrap 95%区間は全て0を含む。Q15 block数は実測cycleではなく、cycle削減や非劣性を証明しない。詳細は `Q15_STOPPING_ANALYSIS_JA.md`。

この追記で解消した以前の「alternate stopping rule分析未着手」は、旧sklearn heldoutの探索的オフライン比較に限る。UCI primary 3,813画像の評価、実機primary 7,626要求、一般化性能または確認的統計は未実施。`DATA_EXPOSURE_UNCERTAIN`、`WRITER_CLUSTER_UNKNOWN`、`PREREGISTRATION_TIMELINE_UNVERIFIED`、`COLD_BOOT_UNVERIFIED`、`FORMAL_TIMING_SIGNOFF_BLOCKED`は変更していない。

### 統合英語草稿の作成

`MANUSCRIPT_EN_DRAFT_20261128B.md` を追加。既存の監査済み資料から、研究の方法、source/formal証拠、pinned Ibex RTL結果、DE0-CV RUN4 pilot、legacy heldout Q15停止則比較、UCI primary未実施をbuildと証拠範囲ごとに整理した。原稿内にartifact evidence mapと関連文献DOI/公式datasetリンクを加え、変数の意味・範囲を明記した。凍結primaryの事前指定統計条件と今回のlegacy heldout探索区間を区別した。古いC3 v2原稿および測定記録は変更していない。新たな実験・物理操作はしていない。文書の数値は対応する保存済み記録に照合し、manifestへ追加する。

UCI公式記録を再確認し、optdigits.traのtraining side 30 writersとoptdigits.tesの別13 writersというpool分離情報を確認した。既存`PRIOR_DATA_USE_AUDIT_JA.md`は追跡済みRTNNコードが`sklearn.load_digits`を使い、公式test side配列と一致する点を既に記録している。これに基づくsplit-level分離を新稿へ追記。ただし不記録の過去使用と行単位クラスタ情報は解決していないため、既存のexposure/writer statusは変更しない。新たな実験は行っていない。

新稿へ凍結primary統計ゲート（H1: paired Clopper–Pearson/Bonferroni下限>−1 pp、H2: cycle削減点推定≥5%かつ10,000回paired input bootstrap 95%下限>5%）と3 session計画（計22,878要求）を記述した。実測未実施、1-session amendment未承認、時系列未確認を明示。legacy heldout bootstrapを事前登録H1の結果として扱わない。

未追跡`physical_pilot_RUN2_preparation/`を読み取り専用で確認。実体は`cases.csv/cases.csv`の20要求候補CSV（21行、header込み、SHA-256 `5f7bece95b30620eaf70e53d21bcdc087baa4b10116f591461c714b9a5bbcc8f`）のみで、run status、JTAG raw log、結果CSV、監査JSON、manifestはない。新実機RUN2の証拠として扱わず、そのまま保全し未追跡のままにした。

### Pilot要約値の原データ再照合

`analyze_pilot_descriptive.py --results <physical_pilot_RUN4_complete_20261126/physical_results.csv> --out $env:TEMP/rtnn_pilot_manuscript_recheck_20261128.json` を再実行。20/20ケース、10/10画像/方式、Q15 oracle一致、teacher正答各10/10、adaptiveが速い8件を再確認。fixed2/adaptiveの平均cycleは943,905.6/667,031.9、中央値は943,906/565,923、ratio-of-sums削減率は29.332774%で、草稿の表示値とプログラムassertで照合PASS。物理測定を追加せず、RUN4原本も変更していない。出力JSONはTEMPに作成。

### 主張・pathの照合

`CLAIM_EVIDENCE_MATRIX.csv` と統合英語稿のbacktick pathを複数の根ディレクトリから解決するオフライン確認を実施。最初にC10のExit遷移CSV pathと旧C3稿2箇所が解決不能と判明。すべて実在artifactへのrepository-relative pathに修正し、再走査でclaim matrixの13 evidence paths、英語稿の12 path literalsが全件解決（missing 0）。科学的数値・raw測定値は変更していない。

### Exit correctnessの遷移・反例

`analyze_exit_counterexamples.py --run-dir <RUN8> --out-dir <new-empty-dir>` を実行。凍結heldout SHA照合、360×7予測を既存oracleと全件照合して不一致0。遷移監査は3件のテストでPASS。Exit 0→1で158回復/1退行、1→2で14/3、2→3で3/4、3→4で0/2、4→5で1/1、5→6で0/3。正解Exitの後に誤りへ戻るケースは12/360。Exit 6は診断専用で、適応許容上限はExit 5のまま。確定RUN8由来の出力は `exit_counterexamples_RUN2_20261128/`、標準出力とテストログは同階層に保存。

更新した全ディレクトリ用の別manifestは `SHA256SUMS_POSTRUN_20261128.txt`（72件、manifest自身と前回の `SHA256SUMS.txt` を除く）。前回コミットのmanifestは上書きせず保持。

### 2026-11-28追記：旧C3 v2 実機campaignの独立再集計と論文統合

旧C3 v2の実機データを、新buildの結果へ混ぜず論文の統合稿へ反映する目的で再集計した。正しいrepoの`codex/external-validation-20261122`、origin `Unjuno/resource-conditioned-neural-computation`、開始HEAD `4fc1940d8e6257f781b92425d403a1322a153406`を確認。既存未追跡`external_validation_20261122/build/physical_pilot_RUN2_preparation/`は変更していない。

実行コマンド:

```powershell
py -3.11 -B 'artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/paper_20261117/reanalyze_c3v2_primary.py' --out-dir 'artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128/c3v2_historical_reanalysis_RUN1_20261128'
```

結果は`PASS: C3v2 13/13 24840 rows; primary 360 IDs x 10; +5 cycle shift 7200 pairs`。要約はfixed2 943,929.77 cycles、adaptive 746,327.99、差197,601.77、記述的削減20.93395%、input-ID resamplingの95%区間16.80384–24.90345%、adaptiveが速い/遅い入力263/97、両方式339/360正答、 paired accuracy差区間−1.38889〜+1.38889 pp。保存出力は上記run directoryの`analysis.json`、`input_level.csv`、`primary_sessions.csv`、図2点、SHA manifest。原campaignと旧C3 v2のbuild/SOF/ELF identityを保持し、別の今回buildへ移植しない。

統合稿に独立したSection 4.4を追加し、歴史的C3 v2の定量結果をそのartifact identity・統計上の単位・test-blindでないcomparator・cold-boot未確認・タイミング/CDC sign-off未完了とともに記載した。`CLAIM_EVIDENCE_MATRIX.csv`にC11を追加。新buildのRUN4 pilot、pinned-Ibex cycle binding、旧C3 v2実機campaignを別々の主張として扱う。

`test_reanalyze_c3v2_primary.py -v`を再実行し11/11 PASS。real-row fixtureと誤build、CRC、prediction、Exit、cycle interval、wrap、SHA、既存出力上書き拒否の各負例を含む。`git diff --check`もPASS。新しいintegrated manuscript内の歴史campaign 4参照とclaim matrixの証拠参照は実在ファイルを指す。更新manifestは変更文書と新しい再集計出力を含め、全項目SHAを照合した。今回、実機操作とprimary campaignは実行していない。

### 2026-11-28追記：Q15停止方式の実行状態を整合

現在の`FINAL_RESEARCH_STATUS_JA.md`に古い`BLOCKED_TOOLCHAIN/LOGIT_ARTIFACT`記載が残っていたが、これはZig経由の成功したQ15解析RUN8と矛盾していた。保存された`STOPPING_COMPARISON.json`と`Q15_STOPPING_ANALYSIS_JA.md`を照合し、validation359件・heldout360件に対する固定Exit 0〜6、entropy、validation選択max-softmax/margin、retrospective oracleの11方式評価が存在することを確認した。block数のaccuracy Pareto図も保存済み。`py -3.11 -B .../test_stopping_comparison.py -v`: 5/5 PASS（frozen Q15 identity、全指標行、CSV/stdout同一性、counterexample保持、cycle/confirmatory主張がないこと）。

統合英語稿のSection 4.2へ固定Exit全段階とPareto図を追加した。Exit 6は診断専用、oracleは教師ラベルを必要とし実行可能方式ではないこと、optional blockはcycle指標ではないことを明記した。C9 evidence rowへPareto図のパスを追加し、状態表の古いblockerを「legacy heldout探索解析では解消、UCI external primaryは未実施」に修正した。`DATA_EXPOSURE_UNCERTAIN`等の制限と主要実機未実施は維持する。

JSONの11方式heldout結果と英語稿tableを機械照合し、correct数、accuracy、mean optional blocksの全33値が一致。Pareto SVG存在確認PASS。比較テスト5/5 PASS。初回の照合ワンショットはWindows既定文字コードでUTF-8資料を開けず停止したため、UTF-8指定で再実行してPASS。ファイル変更はない。

照合を再現可能にする`verify_q15_manuscript_table.py`を追加し、RUN8 JSONのQ15/core/weights identity、validation-only tuning、11行のcorrect/accuracy/blocks/checks、Pareto図と主張範囲を検査。`py -3.11 -B .../verify_q15_manuscript_table.py`: PASS。作成時に見つかったJSON構造の参照違いと図中表記の相違は期待値側を修正し、保存値・図自体は変更していない。

最終状態書にH/T/D/C/U形式の仮説別判定を追記。UCI primaryの5% cycle削減と1 pp非劣性は未評価、既存360-image bootstrapの非劣性はinconclusive、optional-block比較はoffline exploratory、Exit非単調性は観測heldout上で確認、有限work証拠は形式scopeに限定、physical timing/WCETはblockedと分離した。データ露出、writer cluster、preregistration timeline、cold boot、formal timing signoffは未解決のまま。

Git diffでCRLFがwhitespaceとして検出されたため、新規生成されたテキストCSV/logの行末をLFへ正規化した（セル・数値・JSON値は変更なし）。前RUNのcompiler `stdout_sha256` は生成直後の標準出力bytesを指す。確定RUN8はC runtimeのstdin/stdoutをbinaryにして標準出力CSVを直接一致させた。
