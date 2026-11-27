# 凍結Q15停止方式のオフライン比較

## 判定と対象

これは新規の外部画像測定ではなく、既存の `sklearn.load_digits` の検証359画像とheldout360画像に対して、固定Q15モデルの各Exitを再計算した探索的なソフトウェア解析である。UCI `optdigits.tra`、新しいDE0-CV実機入力、実測cycleは含まない。heldout画像は筆記者ID不明で、データ露出履歴も完全には確認できないため、母集団推論・非劣性・一般的性能優位の根拠にしない。

Q15 core SHA-256は `a6b2807bd4a60534c250fca3005322cf14ba0a92f6b16e28241109385efc6809`、生成重みヘッダーSHA-256は `961a76b7e220bf2f665e7c04ab62063600aa2e7eccf3403d80ea730bc993ad9f`。分析専用C helperはcoreの固定exp LUTと確率整数除算を使い、実機firmwareや重みを変更しない。

## 主な結果

固定Exitの全段階を含む比較は、heldout 360画像で次のとおり。Exit 6は診断用でadaptiveの許容上限Exit 5を越える。oracleは教師ラベルを使うため実行可能な方式ではない。

| 方式 | 正解 | 正解率 | 平均追加block数 | 平均判定確認回数 |
|---|---:|---:|---:|---:|
| 固定Exit 0 | 171/360 | 47.50% | 0.000 | 0.000 |
| 固定Exit 1 | 328/360 | 91.11% | 1.000 | 0.000 |
| 固定Exit 2 | 339/360 | 94.17% | 2.000 | 0.000 |
| 固定Exit 3 | 338/360 | 93.89% | 3.000 | 0.000 |
| 固定Exit 4 | 336/360 | 93.33% | 4.000 | 0.000 |
| 固定Exit 5 | 336/360 | 93.33% | 5.000 | 0.000 |
| 固定Exit 6（診断のみ） | 333/360 | 92.50% | 6.000 | 0.000 |
| 凍結entropy停止 | 339/360 | 94.17% | 1.358 | 2.339 |
| max-softmax（validation閾値） | 338/360 | 93.89% | 1.253 | 2.242 |
| top-2 margin（validation閾値） | 337/360 | 93.61% | 1.225 | 2.219 |
| 事後oracle（教師ラベル参照） | 344/360 | 95.56% | 0.750 | 該当なし |

全方式のaccuracy-versus-optional-block図は `q15_stopping_comparison_RUN8_20261128/STOPPING_PARETO_HELDOUT360.svg`。横軸のoptional block数はソフトウェア計算量の代理指標で、cycle、latency、energy、FPGA上のPareto frontierではない。

固定方式とのpaired image bootstrap（20,000反復、seed `20261128`）では、適応方式−固定2の正解率差95%区間はentropy `[-1.39, +1.39]` pp、max-softmax `[-1.67, +1.11]` pp、top-2 margin `[-1.94, +0.83]` ppで、いずれも0を含む。entropy停止の平均追加block差は `[-0.714, -0.564]` blocks/image、max-softmaxは `[-0.811, -0.678]`、top-2 marginは `[-0.833, -0.711]`。このbootstrapは画像行を再標本化し、未知の筆記者クラスタを扱わない探索的区間である。

凍結entropy停止ではheldout360件の終了Exitが1:263件、2:81件、3:7件、4:2件、5:7件だった。固定2と比べてentropyだけが誤分類した画像は3件、固定2だけが誤分類した画像も3件、両方式で誤分類18件、両方式で正解336件である。各入力の詳細は `q15_stopping_comparison_RUN8_20261128/ENTROPY_VS_FIXED2_HELDOUT360.csv` に保存した。

Exit間の正誤遷移も独立に再集計した。Exit 0→1では158件が誤りから正解へ移り1件が正解から誤りへ、Exit 1→2では14件改善・3件退行、Exit 2→3では3件改善・4件退行、Exit 3→4では改善0件・退行2件、Exit 4→5では1件ずつ、Exit 5→6では改善0件・退行3件だった。少なくとも一つのExitで正解し、その後の深いExitで誤りへ戻る画像は12/360件。これらは「深いExitなら常に分類結果が改善する」という前提への具体的反例であり、全入力表を `exit_counterexamples_RUN2_20261128/EXIT_ACCURACY_TRANSITIONS_HELDOUT360.csv` に保存した。Exit 6はモデル診断だけで、適応方針の上限Exit 5を越える。

## 解釈と限界

このデータではentropy停止と固定2の総正解数は同じで、entropy停止の平均追加block数は画像あたり0.642少なかった。ただし、その差をcycle削減、実行時間、エネルギー、WCETと読み替えることはできない。entropyの判定演算自体のCPU命令数やFPGA cycleも、この解析では測定していない。Q15 coreのExit別正解率はExit 0–6でheldout `47.50%, 91.11%, 94.17%, 93.89%, 93.33%, 93.33%, 92.50%`であり、深いExitが常に精度を高めるわけではない。

max-softmaxとmargin閾値はvalidation359件の最良固定Exit 0–5の正解率 `93.593%` を満たしながらblock数を最小化するよう選んだ分析専用の後付け規則であり、ファームウェアに実装済みではなく、確認的計画にも含まれない。retrospective oracleは教師ラベルを見て最初に正解するExitを選ぶため実装可能な方式ではない。

予測ラベルとentropy preferred Exitは既存凍結oracleに対して全360画像・全7 Exitで不一致0。確率ベクトルはQ15単位（合計目標32768、許容差±8）で確認した。thresholdのpaired正答率差区間はすべて0を含み、事前の1 pp非劣性条件もこの解析からは成立しない。外部画像primary、独立電源起動、正式タイミング保証の各ゲートは未変更である。

## 再実行

```powershell
python artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128/run_stopping_comparison.py `
  --zig <TEMPに展開したZig 0.17.1のzig.exe> `
  --sklearn-path <TEMPのscikit-learn 1.8.0環境> `
  --out-dir <新しい未使用の出力ディレクトリ>
python artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128/test_stopping_comparison.py -v
python artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128/analyze_exit_counterexamples.py `
  --run-dir artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128/q15_stopping_comparison_RUN8_20261128 `
  --out-dir <new-empty-output-directory>
python artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128/test_exit_counterexamples.py -v
```

結果、全Exit指標、compiler/raw-input hash、全入力の停止方式比較、SVG図は `q15_stopping_comparison_RUN8_20261128/` にある。完全な標準出力は `q15_stopping_comparison_RUN8_20261128/EXECUTION_STDOUT.json`。Exit間counterexampleは `exit_counterexamples_RUN2_20261128/` にある。`STOPPING_PARETO_HELDOUT360.svg` の横軸はoptional block数でありcycleではない。
