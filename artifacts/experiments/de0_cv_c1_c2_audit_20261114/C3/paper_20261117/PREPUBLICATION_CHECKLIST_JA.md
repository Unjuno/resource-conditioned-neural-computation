# 技術査読用・投稿前チェックリスト

判定ラベル：**REVIEW_READY_LIMITED**。技術査読用の限定されたケーススタディとしてレビュー可能。投稿・出版準備完了や新規アルゴリズム性を意味しない。

## 保存データで確認済み

- [x] 正しいRTNNリポジトリの保存証拠を入力とする。作業ブランチとbuild identityは実行記録・manifestに記載。
- [x] 旧C2J2とC3 v2をbuild単位で分離し、元のCSV・入力・期待値・スケジュールを変更しない。
- [x] C3 v2 24,840行・13 schedule、診断17,640行・49条件を独立再集計。
- [x] 360個の入力IDを統計単位とし、条件反復を独立画像や独立bootとして数えない。
- [x] 入力別Pareto表、固定Exit 2対応差、budget正答数の非単調区間を生成し、run3/run4の出力manifest一致を確認。
- [x] UCI入力データの帰属・CC BY 4.0を明記。図1–3は保存CSVから生成したオリジナルSVGとして出典と再生成経路を記載。
- [x] 主要結論を限定：20.934%は保存された特定build/session上の探索的観測。1 pp非劣性はINCONCLUSIVE。
- [x] 先行研究レビューは対象を明記したfocused reviewとし、world-firstや新規アルゴリズムを主張しない。
- [x] `python -m pytest -q test_reanalyze_c3v2_primary.py test_budget_diagnostics.py test_pareto_frontier_v2_outputs.py`：19 passed。
- [x] `git diff --check`で空白エラーなし。

## 投稿前に人が確定する項目

- [ ] 投稿先・記事種別・テンプレート・語数制限を選び、原稿をその形式に整える。
- [ ] 著者順、所属、資金、利益相反、謝辞、著者全員の同意を確認する。
- [ ] 全書誌情報、DOI、各リンク、引用形式を投稿先要件に照らして最終確認する。
- [ ] 投稿先のデータ・コード・ライセンス・補足資料ポリシーに適合する公開形態を決める。
- [x] 146-source native graphの欠落hashをbyte-exact variantで解決し、公開branchのfresh cloneからnative Verilator回帰を再現（[`CLEAN_CLONE_REGRESSION_RUN_RECORD_20261122_JA.md`](CLEAN_CLONE_REGRESSION_RUN_RECORD_20261122_JA.md)）。Ibexは固定外部checkoutを要する。Quartus/SOF同一性と実機タイミングsignoffは未証明。
- [ ] B-SIGNOFFの外部JTAG timing不足、CDC D102、冷起動不確かさ、WCET未確立を本文と査読回答で保持する。
- [ ] 新しい確認的性能・精度主張が必要なら、事前登録した独立評価キャンペーンを別途実施する。

## 使ってよい／使ってはいけない表現

使える表現は、保存された特定DE0-CV/Cyclone V・Ibex・Q15 build/sessionに限定した経験的観測と、入力ID単位の記述統計である。世界初、アルゴリズム新規性、一般的な速度優位、精度非劣性、正式タイミング保証、WCET、未校正の絶対時間は結論に含めない。

チェック実行記録は`FINAL_REVIEW_ADDENDUM_20261121_V2_JA.md`、ファイル同一性は`SHA256SUMS_PAPER_REVIEW_20261121_V2.txt`を参照。
