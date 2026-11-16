# RTNN C3 v2 追加査読監査・再現性実行記録（2026-11-17）

対象原本: Unjuno/resource-conditioned-neural-computation、論文専用ブランチ codex/c3v2-paper-evidence-20261117、開始commit b544a8ee79bdbd703db028b6d82d4eae892cd5e0。
実行環境: 別のLinuxクラウド端末で同専用ブランチを新しくclone。Python 3.12系（標準ライブラリ）、Git。Windows上のTerasic DE0-CVには接続していない。新しい実機測定、Flash/CFM操作、JTAG操作、Quartusビルド、SDC変更なし。

## 新規の確定所見

1. primary凍結行は10 primary schedule×720行=7,200、全て budget_q16 65535 (100%)、deadline_cycles 0。平均20.93395%の削減は「最大予算・固定Exit2との比較」のみ。
2. 凍結campaign metadataで prior_test_results_known=true、fixed2 comparator は previously_observed_comparator_not_test_blind_selection。独立した新規汎化実験・盲検比較と扱わない。
3. sklearn.datasets.load_digits の8×8 pixel/0–16/10 classes、360 IDの固定分割、モデル構造を原本と対照してMANUSCRIPT_DRAFT_EN.mdへ明記。BranchyNet DOI、MSDNet/SkipNet arXiv、scikit-learn JMLRの文献情報も一次資料と照合。
4. diagnostic fixed 2,520、diagnostic adaptive 7,560、diagnostic capped 7,560、計17,640要求を、凍結matrix・保存cases・実測CSVと照合。SHA/入力ID/expected Q15/Exit/cap/CRC/64bit mcycle検査で違反0。21個の予算水準ごとに各360入力が1回。診断図、精度/サイクル表、JSONを新規生成した。secondary analysisと明記。
5. clean Git checkoutから元のprimary解析11件と、新diagnostic検査4件の計15件テストを実行しPASS。両解析とも独立した出力dirへの2回実行でSHA256SUMSが完全一致。元の保存生CSVと旧C2J2のデータは変更していない。
6. pinned lowRISC/ibex commit 7b5df75a041affe56e8c235260f98a09b3319008 を別の一時場所に取得。原本native regressionの146-file SHAのうち141 upstream一致、4 project一致、1 project不一致。C2/source/ibex_integration/ibex_top_gate_bypass.svの期待SHA e1728fb66338b61a815a30062923698de7b6ff5e62d5c2bd3e996633254b3f50 に対し、Gitにある実ファイルSHAは1360b260617425c8e5ae3b9952940dcc39281b0b339210db5511cf811de93270。ハッシュはCRLF/LF変換で一致しない。詳細はSOURCE_REPRO_GAP_JA.md。Verilatorがこのクラウド端末にないためnative RTL再回帰は未実行。

## 結果判定

- 生データ再解析と図表: **PASS**
- 最大予算primary平均サイクル削減: **OBSERVED_EMPIRICAL_ONLY**
- 21水準budgetレスポンス: **PASS_SECONDARY_DESCRIPTIVE_ONLY**
- 1pp accuracy非劣性: **INCONCLUSIVE**
- 独立cold boot変動: **UNCERTAIN**
- source graph再構築: **BLOCKED_SOURCE_HASH_MISMATCH**（145/146照合）
- board-level JTAG/CDC timing/WCET: **BLOCKED / NOT_ESTABLISHED**
- 論文投稿・公開の著者最終承認: **PENDING**

元の論文パッケージSHA256SUMS_PAPER.txtは2026-11-17前版の履歴として保持し、新しい現行SHAはSHA256SUMS_PAPER_REVIEW.txtで照合する。実機証拠・凍結モデル・既存ログを上書きしていない。
