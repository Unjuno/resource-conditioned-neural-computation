# C3 external validation physical pilot — 2026-11-26

状態: **PHYSICAL_PILOT_PASS / PILOT_GATE_VALIDATED / PRIMARY_NOT_RUN**。正しいリポジトリの `codex/external-validation-20261122` に保存したpilot証拠の案内です。

## 完了run

- Experiment: `C3_EXTVAL_PILOT_20261126_RUN4`
- 10 frozen pilot images × fixed2/adaptive = 20/20 PASS、CPU Q15 oracle一致
- SOF SHA-256: `5e333e9377b7188a394d04b93b98833d91afb2cd53eca8d976e6aa715dfa00c4`
- Gate: `artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/external_validation_20261122/build/pilot_gate_RUN4_20261126.json`
- 完了記録とraw data: `.../build/physical_pilot_RUN4_complete_20261126/`
- 失敗試行・応答回復・修正runner記録も各versionedディレクトリに保全。成功扱いにはしていない。
- SHA-256一覧: `.../build/physical_pilot_DELIVERY_SHA256SUMS.txt`

## 限界

実験はEMPIRICAL_ONLY。cold boot、正式な外部JTAGタイミング保証、データの過去使用、writer clusterは未確定。primary 3,813画像キャンペーンは未実行。速度優位、精度非劣性、WCET、hard deadlineは主張しない。
