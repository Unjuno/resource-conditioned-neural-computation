# 実機パイロット最終状態（現時点）

判定: `PHYSICAL_PILOT_BLOCKED_OPERATOR_APPROVAL_PENDING`

* ホストidentityとケース構成: 照合済み。
* 非物理preflight: PASS (`PREFLIGHT_ONLY`, 20 cases, exit 0)。
* 実機SOF設定: NOT_RUN。
* 実機pilot: NOT_RUN (0/20)。
* 独立pilot監査: NOT_RUN。
* production pilot gate: 未生成。
* primary実験: NOT_RUN、実行しない。
* 正式timing signoff: `FORMAL_TIMING_SIGNOFF_BLOCKED`を維持。

### 次に必要なこと

操作者がDE0-CVの前にいる状態で、予定SOFをSRAM限定で設定し、凍結pilot 20要求だけを実行する明示的許可を出す。その後も、基板ID/Build ID/READYを確認してからrunnerを実行する。primary実行の承認は含まれない。

### 後続記録（2026-11-26）

このファイルはユーザー承認前のpreflight時点を記録した履歴スナップショットであり、現在状態ではない。その後、明示承認を受けてSOFをSRAM設定し、RUN4でpilot 20/20を完了、独立auditとgate検証がPASSした。最新状態は `../physical_pilot_RUN4_complete_20261126/FINAL_PHYSICAL_STATUS_JA.md` を参照。primaryは未実施。
