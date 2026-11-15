# オフライン研究準備 — 実行・監査報告

実施日: 2026-11-15（JST）  
Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`  
Branch: `codex/stage-c3-jtag-pilot-20261114`  
確認HEAD: `143a4af545b49391b2413751918f7bb515277ae9`  
Python: 3.11.9  

## 実施範囲と保全

最初に現在のorigin、branch、HEAD、作業差分を確認した。Codexの作業cwdは旧`RTNN`フォルダで、originが`https://github.com/kardaneh/RTNN.git`だったため、そこでの書込みは行わなかった。親ディレクトリ直下の候補だけをread-onlyで照合し、正しいUnjuno repositoryの専用branchに切り替えて続行した。旧作業ツリーの既存差分・多数の未追跡成果物には触れていない。

正しいrepository側には開始時点ですでにoffline解析途中の変更があった。これらを保全したまま、追加したcheckerの小さな修正・テスト・報告を未commitで保存している。既存のstaged/unstaged/untracked変更を一括整理・stageしていない。commit、push、PR、mergeは行っていない。

基板不在のオフライン作業のみ。JTAG、SOF、KEY0、電源、配線の操作は0回。Flash/CFMも変更していない。

## 成果1 — 旧C2J2の独立再集計

再実行コマンド（repository rootをcwdとして実行）:

```powershell
python artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/source/reanalyze_c2j2_frozen_campaign.py --c3-root artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3 --out-dir artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/campaign/analysis/C3_C2J2_OFFLINE_COMPLETION_RUN2_20261115
```

終了コード: **0**。判定: `PASS_DATA_INTEGRITY_EMPIRICAL_ONLY`。旧C2J2の13 schedule、24,840/24,840行、360独立input IDを生データから再確認した。重複・欠損/余分sequence、応答identity、Q15参照予測、Exit/cap、CRC、timeout/trap/case errorはすべて0。

`primary_02`から`primary_10`は9×720=**6,480行**。旧記録の7,200行は算術誤記であり、履歴ファイルに訂正注記が既にある。生CSV/JSON/raw logは書き換えていない。

主解析は入力IDごとに10 primary scheduleを平均し、独立単位360 ID、percentile bootstrap 5,000回（seed 63）で対応差を区間推定した。fixed2平均943,924.77 cycles、adaptive平均746,322.99、差197,601.77 cycles、95% CI [158,616.47, 235,071.07]、観測削減率20.934%（95% CI [16.804%, 24.904%]）。adaptiveは263入力で速く、97入力で遅かった。これは保存条件下の経験的記述値である。独立cold bootは確認されていないため速度優位とは結論しない。

教師ラベル正解数はfixed2/adaptiveとも339/360。対応accuracy差95% CIは[−1.389,+1.389] percentage pointsであり、事前1 pp非劣性は**INCONCLUSIVE**。反復回数は独立入力標本数を増やさない。

生成物:

* `../campaign/analysis/C3_C2J2_OFFLINE_COMPLETION_RUN2_20261115/analysis.json`
* 入力別paired表、全primary行CSV、最速/最遅20入力
* `figure_01_paired_cycle_saving.svg` — 入力別paired差
* `figure_02_cycle_distribution_cdf.svg` — cycle分布
* `figure_03_executed_exit_vs_cycles.svg` — 実行Exit別cycle
* `figure_04_accuracy_cycle_tradeoff.svg` — 教師ラベル正解数とcycle
* `../campaign/analysis/C3_C2J2_OFFLINE_COMPLETION_RUN2_20261115/SHA256SUMS.txt`

Exit別の追加分析で、Exit 1は263入力・2,630 paired観測でadaptive平均565,950.62 cycles、対応fixed2平均943,924.79 cycles。Exit 2–5はadaptive平均が対応fixed2より大きかった。これはExitによる観測層別で、画像特徴による因果説明ではない。10 scheduleのcycle要約は一致したが、run recordの電源独立性は確立されず、session bootstrapとして解釈しない。[RUN2 analysis](../campaign/analysis/C3_C2J2_OFFLINE_COMPLETION_RUN2_20261115/analysis.json)と[session/Exit analysis](c2j2_session_exit_summary_retry01/analysis.json)を参照。

## 成果2 — C3 v2保存証拠監査とcheckerの穴修正

保存済み42要求、SESSION1の20要求、過去のKEY-reset RUN5の20要求を各build identityのまま個別監査した結果は、`OFFLINE_RESEARCH_COMPLETION_20261115/`内の各audit JSON/logに保存されている。これらは過去の実機試験記録の独立auditで、新規測定ではない。

新規focused regressionは4項目: uint64 wrap拒否、missing CRC field拒否、旧C2J2 build identity拒否、physical evidence root内mock path拒否。修正前は前3件が通った一方、root内`mock/`の許可テストが失敗し、混入防止の穴を再現した。`audit_saved_c3_v2_runs.py`のevidence path判定を最小変更し、relative pathに`mock(s)`/`synthetic(s)`/`fixture(s)` directory componentがある場合拒否する。

修正後は **4/4 PASS、終了コード0**。Python compile checkも終了コード0。既存の13件テストは重複実行していない。修正前・修正後のログと終了コードはoffline evidence folderに保存した。

## 成果3 — 保存済みC3 v2 campaign aggregateの再確認

修正後のコマンド（repository root cwd）:

```powershell
python artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/source/summarize_c3v2_campaign_20261115.py --campaign-dir artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/PHYSICAL_C3_V2_20261115/FROZEN_CAMPAIGN --output-json artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/OFFLINE_RESEARCH_COMPLETION_20261115/c3v2_saved_campaign_aggregate_audit_retry02.json
```

Aggregate audit: **13/13 schedules、24,840/24,840 rows、0 errors、終了コード0**。最初はWindowsの長い保存パスでfile openに失敗した。checkerにextended-length path対応を加え、`Path.is_file()`検査も同経路で行う修正後に再実行成功。失敗出力は残し、原生のrun evidenceは変更していない。

これは**以前に保存されたC3 v2実機campaign**の検証であり、今回の新しい測定ではない。run recordは一連の測定を1つの連続・cold-boot未確認電源sessionとして記録する。C2J2とはbuildが違うため、行・cycleを混ぜていない。

## 統計・計測上の意味と限界

| 記号 | 意味・単位 | 定義域・型 |
|---|---|---|
| `C_fixed2`, `C_adapt` | Ibex `mcycle`差分、cycle count（整数カウント） | 同一input ID・同一保存sessionの正の整数 |
| `D_i` | 入力iの対応cycle差、cycle count | 入力iについて10 scheduleの平均を取った `C_fixed2 − C_adapt` |
| `r` | 観測平均削減率、無次元 | `mean(D_i)/mean(C_fixed2_i)`、対象360 IDの範囲 |
| `CI95` | input-bootstrap percentile interval | 独立単位を360 input IDとし、反復scheduleはID内で平均 |
| `accuracy difference` | 適応−固定の正解率差、percentage points | 教師ラベルと照合した360 ID、対応bootstrap |

dimension check: `cycle − cycle = cycle`; `cycle/cycle = 1`; accuracy proportion difference is dimensionless and displayed in percentage points. `mcycle`値から秒へ変換するには校正済みclock frequencyが必要だが、これを今回測定していない。そのため秒、ppm、WCET、hard deadline、正式timing signoffは結果から主張できない。外部JTAG timingも未確定で、B-SIGNOFFはBLOCKEDのまま。

## 逐次チェックポイントとコマンド証拠

| Checkpoint | 判定 | 再現・保存 |
|---|---|---|
| 正しいrepo/branchを選び旧RTNN treeを保全 | PASS | origin確認。kardaneh treeへの書込みなし。 |
| C2J2生データ再集計・図表 | PASS | 上記`reanalyze_c2j2_frozen_campaign.py`、analysis `RUN2`。 |
| C2J2 session/Exit層別 | PASS | `summarize_c2j2_cycle_structure.py --primary-rows .../primary_rows_for_figures.csv --output-dir .../c2j2_session_exit_summary_retry01`、終了コード0。 |
| C3 v2追加fail-closed tests | PASS | `python .../C3/source/test_audit_c3v2_contract_gaps.py`、4 tests、終了コード0。 |
| Python syntax compile | PASS | `python -m py_compile`（checker, focused test, C2 summary, C3 aggregate script）、終了コード0。 |
| 保存済みC3 v2 13 schedule aggregate | PASS_SAVED_EVIDENCE | [`c3v2_saved_campaign_aggregate_audit_retry02.json`](c3v2_saved_campaign_aggregate_audit_retry02.json)、13/13、24,840行、終了コード0。 |
| 今回の実機測定 | NOT_RUN | 実機操作なし。 |

実行ログ、終了コード、audit JSONは`OFFLINE_RESEARCH_COMPLETION_20261115/`に保持。成果物SHAはこのディレクトリの`SHA256SUMS.txt`と個々の解析dirのmanifestで確認できる。作成環境はWindows PowerShell、Python 3.11.9。日本語OneDriveの長パス問題を避けるため、C3 v2 aggregatorはWin32 extended pathでアクセスする。

## 研究上の判定

この保存データから記載できるのは、対象board/build/model/measurement boundaryにおける経験的機能一致とcycle観測、入力単位の記述統計まで。性能優位、独立cold-boot感度、1 pp精度非劣性、絶対時間、WCET、hard deadline、board-level timing signoffは証明されていない。C3全体のGoalはB-SIGNOFFの外部仕様不足を残すため完了ではない。

## 再開後のGate B進捗 — 外部部品仕様の適用範囲

公式FTDI [FT245BL datasheet](https://ftdichip.com/wp-content/uploads/2020/08/DS_FT245BL.pdf)のFIFO parallel-bus表で、read data-validはRD# active後20–50 ns（30 pF条件）、write data setupはWR# inactive前にminimum 20 nsと確認した。これらはUSB FIFOとEPM240間のIC bus timingであり、EPM240が生成するDE0-CV JTAG TCK period/duty、TDI/TMS対TCK relative skew、TDO capture setup/holdを与えない。 [適用範囲監査](../evidence/FT245BL_JTAG_TIMING_SCOPE_AUDIT_20261115_JA.md)。

そのため今回もB-SIGNOFFはBLOCKEDのまま。新たな数値をSDC/QSF/RTLへ転記せず、STA/Quartusを再実行せず、同じSystem CD ZIPを再走査していない。次の技術的に意味のある工程は対象基板revisionのcontroller timing回答または適切な帯域・閾値で取得したTCK/TDI/TMS/TDO波形とrelative-delay測定である。

## 現HEADからの内部STA/CDC保存report再照合

HEAD `143a4af545b49391b2413751918f7bb515277ae9`で二つの保存証拠auditを実行した。第一は59入力、13 binding、24,840凍結行、4 corner、UCP、16 D102を再照合し`B-SIGNOFF=BLOCKED; B-EMPIRICAL=PASS_LIMITED`を確認。詳細は[HEAD 143a4af audit record](../evidence/C3_GATE_B_EVIDENCE_AUDIT_20261115_HEAD143A4AF/RUN_RECORD_JA.md)と[機械結果](../evidence/C3_GATE_B_EVIDENCE_AUDIT_20261115_HEAD143A4AF/gate_b_audit.json)。

第二のparserはbit-index単位に各cornerの保存CDC routeを確認し、request 800/800、response 480/480のcoverageをPASS。20-path setup/hold reportは保存値と一致し違反0。D102 16件、未制約TDI/TMS 41 path、TDO等8 output path、警告code件数は残る。JSONは`gate_b_saved_report_audit_HEAD143A4AF_REPRO2.json`（SHA-256 `506c6370c17504f9d01bf425186b2e025028f4ba879df12aabe3f7f7a3e9ae95`）、再現記録は[GATE B saved report reaudit](GATE_B_SAVED_REPORT_REAUDIT_HEAD143A4AF_JA.md)。同じparserの一度目の実行と正しいrepository cwdからの再実行JSONはbyte-identical。これは保存reportの再解析で、新しいQuartus STA/Fitter runではない。

saved report parserの全結果が内部制約・報告範囲のみに限られ、外部TAPの遅延・波形情報は増えないため、Gate B全体をPASSにする根拠はない。新build、constraint変更、現物測定、メーカー回答のどれも今回発生していない。
