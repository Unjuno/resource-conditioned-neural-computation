# 保存済みC3 v2実測のPareto解析

## 対象と再現方法

Build `43334531`、SOF SHA-256 `85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d`、campaign SHA-256 `d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc` の保存済みdiagnostic CSVだけを使用した。3つのCSV（fixed 2,520行、adaptive 7,560行、capped 7,560行）についてSHA、identity、CRC、prediction、cap、64-bit mcycle区間、入力IDと条件の重複・欠損をスクリプトで検査した。全条件に同じ360凍結入力が1回ずつ含まれる。

再実行：

```powershell
python .\analyze_pareto_frontier.py --out-dir .\pareto_final_run1
python .\analyze_pareto_frontier.py --out-dir .\pareto_final_run2
```

2出力の`SHA256SUMS.txt`は一致した。入力別点表、機械可読JSON、SVG図は各run directoryに保存される。既存のprimary検定や元CSVは変更していない。

## 結果

サイクルを小さく、凍結教師ラベルに対するaccuracyを高くする49条件（fixed 7、adaptive 21、capped 21）を比較した。非支配点は重複する同一座標を統合すると3点だった。

| Pareto点 | 条件 | Accuracy | 平均cycle |
|---|---|---:|---:|
| 1 | 固定Exit 0 | 47.500% (171/360) | 20,152.911 |
| 2 | 固定Exit 1 | 91.111% (328/360) | 482,039.636 |
| 3 | adaptive予算Q0.16=22,937 / 26,214 / 29,491 | 94.444% (340/360) | 691,343.072 |

この同一sample上では、固定Exit 2とすべてのcapped条件は少なくとも1条件に支配された。最大予算adaptive条件も、より低い予算で同じか高いaccuracyかつ少ないcycleを得たdiagnostic条件に支配された。これは予算曲線とトレードオフを記述する探索的結果であり、一次の事前登録済みfixed2対adaptive比較を置き換えない。

診断入力IDは学習データから独立した360-IDの凍結集合ではあるが、今回の複数条件・比較対象・Pareto点は同じ評価集合に基づく。さらに、固定Exit 2 comparatorの選択には過去のtest結果が知られていた。したがってPareto前線の最大accuracy点や選択後の速度を新しい汎化性能・独立確認と解釈してはならない。統計上の360入力を独立標本として扱う推論であって、独立cold-boot変動を表さない。

![C3 v2 exploratory Pareto frontier](pareto_final_run1/PARETO_FRONTIER.svg)

## 位置付け

これは経験的・探索的なPareto記述である。精度非劣性はINCONCLUSIVE、cold-boot感度はUNCERTAIN、正式タイミング保証とWCETは未成立のまま維持する。時間単位はibex `mcycle` countで、校正済み秒やppmを推定しない。
