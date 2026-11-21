# 論文準備・最新状態（2026-11-22）

## 判定

**REVIEW_READY_LIMITED**。保存データに基づく限定的な技術査読用ケーススタディであり、投稿承認・出版準備完了を示さない。

| 項目 | 状態 | 現在の根拠・範囲 |
|---|---|---|
| 24,840要求／13 scheduleの保存実測データ再集計 | PASS（保存証拠の範囲） | 2026-11-21の独立解析記録 |
| 146-source source identity | PASS（公開branchのfresh clone） | commit `6e07b86` を新規cloneし、141 pinned Ibex + 5 byte-exact project sourcesの146/146 hash照合 |
| ネイティブVerilator回帰 | PASS（fresh clone） | 42要求、reset recovery、negative cases、response write guard。詳細はclean-clone run record |
| 固定2対adaptive cycle差 | OBSERVED / EXPLORATORY | 20.934%; 1 board/build/session、比較器は先行結果を見て選択 |
| 1 pp accuracy noninferiority | INCONCLUSIVE | 339/360ずつ正解、差の95%区間−1.389～+1.389 pp |
| B-EMPIRICAL | PASS_LIMITED | 既存の適格性範囲のみ |
| B-SIGNOFF | BLOCKED_EXTERNAL_BOARD_TIMING | 外部JTAGタイミング資料不足、CDC/D102のopen finding継続 |
| C3 v2 KEY0 reset replay | PENDING_OPERATOR | 物理操作後に新実験IDで実行する必要あり |
| C3 v2 full campaign | NOT_RUN | 今回は実施していない |
| Quartus/SOF bit identity | NOT_ESTABLISHED | native RTL回帰からは推論しない |
| WCET / hard deadline | NOT_ESTABLISHED | 正式な上界とsignoffなし |

## ソース再現性の意味

2026-11-21時点の145/146記録は、その時点の公開checkout監査として正しい。2026-11-22に五つのproject source byte variantsを正しいUnjuno audit worktreeから回収して公開branchへ保存し、commit `6e07b86` をfresh cloneした環境で、追跡済み準備スクリプトを使った146/146 hash照合とnative Verilator回帰に成功した。この結果はmapped native graphの公開branchからの再現を示す。Ibex依存は別途pinしたcheckoutを要し、Quartusで同一SOFを作れることや基板のタイミング保証は示さない。詳細は[`SOURCE_RECOVERY_ADDENDUM_20261122_JA.md`](SOURCE_RECOVERY_ADDENDUM_20261122_JA.md)と[`CLEAN_CLONE_REGRESSION_RUN_RECORD_20261122_JA.md`](CLEAN_CLONE_REGRESSION_RUN_RECORD_20261122_JA.md)。

## 論文での主張範囲

記載できるのは、凍結build/board/sessionで観測されたmcycle、保存された入力単位の解析、source-mapped native regressionの範囲である。広く一般化した速度優位、精度非劣性、アルゴリズム新規性、独立cold-boot変動、絶対時間、WCET、hard deadlineは主張しない。追加の実機操作や投稿判断は別途必要。

最新成果SHA一覧は[`SHA256SUMS_SOURCE_RECOVERY_20261122.txt`](SHA256SUMS_SOURCE_RECOVERY_20261122.txt)。履歴的な2026-11-21文書と失敗ログは書き換えず保持している。
