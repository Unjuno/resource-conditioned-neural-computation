# 解析系の準備状況

## 現在の位置付け

このディレクトリにある`oracle_*`、`host_cases_*`、Verilator出力はオフライン参照値またはシミュレーションであり、実機観測データではない。実機解析は`host/Invoke-ExternalValidation.ps1 -ExecutePhysical`を明示して実行した取得物だけを受け入れる設計だが、今回そのコマンドは実行していない。

## 再現コマンド

リポジトリルートから次を実行する。統計テストにSciPyが必要。

```powershell
$p = 'artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/external_validation_20261122'
$env:PYTHONPATH = Join-Path $env:TEMP 'rtnn_sklearn_1_8_0'
python "$p/scripts/test_external_host.py"
python "$p/scripts/test_stats_core.py"
python "$p/scripts/test_physical_audit_fail_closed.py"
python "$p/scripts/external_host.py" cases --help
```

CPU oracleとfirmware APIのソフトウェア比較は、それぞれの`run_cpu_oracle.sh`と`run_firmware_api_regression.sh`を使う。Quartus-flat、native SystemVerilog、sv2v後のpilot regressionは`run_rtl_pilot_regression.sh`と`run_native_sv2v_pilot_regression.sh`で異なるattempt名に実行する。Quartus build用プロジェクト生成は`make_quartus_project.py --out <新しいASCIIパス>`で行う。

## 主解析

`audit_and_analyze.py --runs <session1> <session2> <session3> --out <新規出力dir>`は、各sessionの生CSV・status・binding・SHA manifestを照合してから解析する。3セッション、各session 3,813画像×2方式、同一SOF/build/model/binding、sequence・input・CRC・pixel SHA・予測・Exit・64-bit counter差分が成立しないと主解析へ進まない。旧C2J2およびmockのrun envelopeは拒否される。出力ディレクトリは既存時に上書きしない。

非劣性は画像ペアのdiscordant率から片側Clopper–Pearson限界を計算し、alpha=0.025ずつのBonferroni下限が−1 ppを超えることを数値条件とする。UCIに行単位の筆記者IDがないため、画像独立性は確認できず、母集団の確認的主張は別途INCONCLUSIVEを維持する。サイクル削減は画像単位bootstrap（10,000反復、seed 20261122）で、入力標本の不確かさのみを表す。セッションごとの推定も別々に出し、3 sessionでもボード・起動母集団の強い推論は行わない。

教師ラベルは正解率計算専用であり、Q15参照予測との一致検査と分ける。統計解析は実機runが存在するまで実行しない。合成データのテスト結果を実測結果へ読み替えない。

## 設計感度（実測ではない）

`scripts/planning_sensitivity.py`は登録済みpaired Clopper–Pearson/Bonferroni gateの数値通過確率を、3,813画像と明示した仮定discordance ratesで厳密列挙する。出力`build/planning_sensitivity_attempt1/ni_sensitivity.csv`はplanning-onlyであり、モデル・UCI結果を読み込まない。

| 仮定 | adaptive-only correct p10 | fixed-only correct p01 | delta | 数値gate通過確率 |
|---|---:|---:|---:|---:|
| 等率0.5% | 0.5% | 0.5% | 0 pp | 99.899% |
| 等率1% | 1% | 1% | 0 pp | 92.927% |
| adaptive +0.5 pp | 1% | 0.5% | +0.5 pp | 99.9999% |
| adaptive −0.5 pp | 0.5% | 1% | −0.5 pp | 37.707% |
| margin境界 | 1% | 2% | −1 pp | 0.272% |
| adaptive −1.5 pp | 0.5% | 2% | −1.5 pp | 0.00014% |

各値は画像ペア独立という仮定下の数値gate感度であり、writer cluster不明を解消しない。これは検出力保証でも観測性能でもない。

## 未確認

* Tcl runnerのQuartus STPでのJTAG API動作。本文は実行していない。文法完結性だけをsafe checkerで確認済み。
* 物理Pilot run record。SOF/hashを結び付けたpilot bindingとPowerShell preflightは作成・確認済みだが、基板アクセスを含む実行は未実施。
* 新buildを用いた物理pilot、reset後replay、3独立電源session。
* 確認的本測定と実データ統計。
* 外部JTAG timing signoffとWCET。

native 146-source graphはIbex `/opt/rtnn-tools/ibex` commit `7b5df75a041affe56e8c235260f98a09b3319008` に依存する。正確なsource list/hashは`build/native_source_graph_attempt1/`に保存した。Ibex全sourceをこのpackageに複製していないため、別PCからnative回帰を再現する場合は同commitを取得し、manifestのhash照合が必要。
