# 研究用C3 v2独立再解析・実行記録

日付: 2026-11-17（JST）  
正本: `Unjuno/resource-conditioned-neural-computation`  
起点: `codex/stage-c3-jtag-pilot-20261114` HEAD `c13335d38c6ce478ad4a026f607ebf5890dc799b`  
成果ブランチ（隔離）: `codex/c3v2-paper-evidence-20261117`

## 操作範囲

公開済み研究リポジトリをクラウド上のLinux環境に新規cloneして、そこに保存された結果だけを解析した。接続されているリモート端末はWindowsのDE0-CVホストと別環境であり、当該端末からFPGA/Quartus/JTAG/KEY0/電源/Flashにはアクセスしていない。過去の24,840件実機データは新しい測定として数えない。元の作業ブランチと`main`は変更しない。

使用ツール: Python3標準ライブラリ、Git。OS上の追加統計ライブラリ・ネットワーク学習データ・モデル変更なし。

## 完了した検証

1. 保存済みC3 v2 aggregate audit（13/13、24,840/24,840）を独立コマンドで再実行し、`PASS schedules=13/13 rows=24840/24840 errors=0`。
2. `reanalyze_c3v2_primary.py` で、C3 v2 primary 10件のCSV SHAと計7200行の内容を監査した。ID/モード/予測/Exit/CRC/64ビットmcycle差分の不一致0、入力360個が各primaryに全列挙。
3. 別buildの旧C2J2 primary 10 CSVも対応付け、7200/7200条件でC3 v2−C2J2のcycle差が**+5**、予測/Exit変更0と確認。
4. 入力ID単位のpaired bootstrapを事前記録済みの方式（Python `random.Random(63)`、5000回、linear percentile）で実行。統計の独立単位は360入力で、10反復は同じinput内で平均。
5. `python3 -m unittest discover -s .../paper_20261117 -p test_reanalyze_c3v2_primary.py -v` を実行し**11/11 PASS**。負例はbuild/SOF/CRC/Exit/Q15/counter/CSV digestの不一致を意図的に検出。
6. 別々の未使用出力dir `generated_run1` と `generated_run2` に対して同じスクリプトを実行し、両者の`SHA256SUMS.txt`が**byte-identical**。新図SVG2件はXMLパーサで形式確認。
7. 英語論文ドラフト、日本語判定、再現用READMEを作成し、原論文DOI/arXivと実験証拠へのリンクを付けた。

## 結果・制約

fixed2平均943,929.7667 cycles、adaptive平均746,327.9944 cycles、差197,601.7722 cycles、削減率20.93395%。入力ブートストラップ95%区間[16.80384%,24.90345%]は独立電源セッション変動を含まない。分類正答は両方式339/360。paired accuracy差95%区間[-1.38889,+1.38889]ppは事前1pp非劣性を確立しない。

全360入力について同一入力・同一modeのcycle値は10 primary scheduleで一致した。この反復を独立cold bootと誤認してはならない。B-SIGNOFFはオンボードJTAG外部タイミングとD102未解決のためBLOCKEDであり、WCET/hard deadline/校正済み秒数を主張しない。

**未実施:** 現物測定、新SOF生成、独立cold boot、実機TCK波形、IBEX/コンパイラを跨ぐ5-cycle差の機械語レベル因果同定、論文の外部査読・投稿。
