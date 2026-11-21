# 最終レビュー追補 v2（2026-11-21）

## 対象・保全

- Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
- Branch: `codex/c3v2-paper-evidence-20261117`
- 今回の開始HEAD: `9b0e4266f5371f99db70aac414ba4725c75c446b`
- originのfetch/push先は上記Unjunoリポジトリ。旧`kardaneh/RTnn`は触れていない。
- 既存C1/C2/C3証拠、過去のmanifest、中間解析出力は上書き・削除していない。
- 基板/JTAG/SOF/Quartus、電源・配線操作、外部問い合わせは未実施。

## 今回の追加作業

- `analyze_pareto_frontier_v2.py`で入力別・fixed2対応差・budget非単調性を出力する診断解析を追加。v1スクリプトは保持。
- 最終出力`pareto_input_audit_run3/`と`run4/`で17,640入力条件、7,560 paired rows、36非単調区間、49 Pareto条件を確認。両SHA manifestは一致（SHA-256 `A7B24919DA8839D1FE2AF2F7822BCABEE6A384603A2CBB1C2B6966CBF9A33250`）。run1/run2も中間履歴として保全。
- 特定の凍結360入力でadaptiveが遅い97件を実行Exit別に集計。最大budget時はExit 2:81、Exit 3:7、Exit 4:2、Exit 5:7。これは事後的な説明であり、因果解釈ではない。
- 隣接予算正答数の非単調区間を入力IDレベルで記録。探索的診断で、一般的因果主張ではない。
- UCI Optical Recognition of Handwritten DigitsのCC BY 4.0帰属を原稿に追加。図1–3を保存CSV由来のオリジナル図として明示。
- `PREPUBLICATION_CHECKLIST_JA.md`を追加し、技術査読可能範囲と投稿前の人手確認を分離。

## 実行・検証

作業ディレクトリは`artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/paper_20261117/`。

```powershell
python -m pytest -q test_reanalyze_c3v2_primary.py test_budget_diagnostics.py
python analyze_pareto_frontier_v2.py --out-dir pareto_input_audit_run3
python analyze_pareto_frontier_v2.py --out-dir pareto_input_audit_run4
python -m pytest -q test_reanalyze_c3v2_primary.py test_budget_diagnostics.py test_pareto_frontier_v2_outputs.py
git diff --check
```

結果：旧テスト **15 passed**、追補のv2静的出力検査を含む最終テスト **19 passed**。run3/run4の7出力SHA manifestは一致。各runの行数は`PARETO_INPUT_LEVEL.csv` 17,640、`PARETO_FIXED2_PAIRWISE.csv` 7,560、`PARETO_BUDGET_ACCURACY_NONMONOTONIC.csv` 36、`PARETO_POINTS.csv` 49。run3 manifest自体のSHA-256は`A7B24919DA8839D1FE2AF2F7822BCABEE6A384603A2CBB1C2B6966CBF9A33250`。

開始時点の元レビュー記録にHEAD不一致があったため、当追補では開始HEADを記録し、旧run recordを遡及改変しない。新しい結果の完全なSHA-256一覧は`SHA256SUMS_PAPER_REVIEW_20261121_V2.txt`。

## 判定と限界

**REVIEW_READY_LIMITED**：技術査読用の限定ケーススタディとして一式を確認可能。投稿先書式、最終書誌照合、著者・共著者承認、公開ライセンス適合、146-source完全再構築は未完了。

- B-SIGNOFF: `BLOCKED_EXTERNAL_BOARD_TIMING`。外部タイミング・CDC D102未解決のまま。
- B-EMPIRICAL: `PASS_LIMITED`（既存適格性範囲）。
- C3 v2 KEY0 reset replay: `PENDING_OPERATOR`。
- C3 v2 full campaign: `NOT_RUN`。
- 保存済み24,840行と診断17,640行は再解析結果であり、新測定ではない。
- 20.934% cycle差は特定build/sessionの記述的観測。1 pp精度非劣性は`INCONCLUSIVE`。cold-boot変動は`UNCERTAIN`。
- 早期終了/entropy/FPGA動的推論のworld-first、新規アルゴリズム性、一般的速度優位、hard deadline、WCET、正式タイミング保証は主張しない。

## Git操作

今回の追補作成時点では未commit・未push。pushの依頼を受けた後に実行したGit操作は、会話の最終報告に記録する。
