# 実機pilot最終状態 — 2026-11-26

## 完了判定

- **PHYSICAL_PILOT_PASS:** PASS — RUN4 20/20。
- **INDEPENDENT_PILOT_AUDIT:** PASS — raw request/response、ケースCSV、CPU oracleを照合。
- **PILOT_GATE_VALIDATED:** PASS — gateを生成し独立validatorで再検証。
- **PRIMARY_CAMPAIGN:** NOT_RUN。自動移行していない。
- **B-SIGNOFF / FORMAL_TIMING_SIGNOFF:** BLOCKED_EXTERNAL_BOARD_TIMINGのまま。
- **COLD_BOOT:** UNVERIFIED。今回、電源断は行っておらず、RUN2–RUN4は同一の連続した電源epoch。
- **DATA_EXPOSURE:** UNCERTAIN。過去の未記録使用を排除できない。
- **WRITER_CLUSTER:** UNKNOWN。行単位writer IDがない。
- **PREREGISTRATION_TIMELINE:** UNVERIFIED。

## 完了run identity

Repository `https://github.com/Unjuno/resource-conditioned-neural-computation`、branch `codex/external-validation-20261122`、開始HEAD `b8c7e0a54b545bf75591497adcfc6ff4aabbbbf3`。

Experiment `C3_EXTVAL_PILOT_20261126_RUN4`, session `BOARD_POWER_EPOCH_20261126_CURRENT`, Build `45585631`, Binding `45585632`, Model `52544e4e`。

SOF SHA-256 `5e333e9377b7188a394d04b93b98833d91afb2cd53eca8d976e6aa715dfa00c4`; ELF SHA-256 `4673f6a8b90493c15c327ed3be1167e0fcf3ff2be60292dcb12a1391124a0c2e`; preregistration SHA-256 `5005c80c6d2d8eefbf87dd4dfdb4c91e26adb7960a3e5b1f04a977fdaee3b33b`.

20/20応答は凍結CPU oracleに一致。fixed2の教師ラベル正答10/10、adaptive 10/10。cycle中央値はfixed2 943,906、adaptive 565,923。adaptiveが長い画像はID 519、667。n=10の工学pilotであり、速度・精度の一般化主張には使わない。

Gate: `build/pilot_gate_RUN4_20261126.json`; independent result: `INDEPENDENT_PILOT_AUDIT.json`; raw data: `raw_jtag.log`, `physical_results.csv`, `cases.csv`, `run_status.json`。

RUN1、RUN2、RUN3の失敗・部分取得ログを保持。RUN2の1件は応答回収・照合したが完了pilotとして数えず、RUN3のsequence重複はfirmwareに拒否された。完了データはRUN4のみ。

## 変更・運用状態

C3測定firmware、SOF、ELF、凍結モデル、入力・参照値、元runnerソースには変更なし。CRC幅とTcl wrapperの修正は`host_v2_20261126/`の版管理された別コピーを使用。build/run証拠は無視対象または未追跡の成果物として保存。commit/push/PR/mergeは未実施。

次の操作者タスクは、主張を絞った論文執筆（推奨A）か、計画変更amendment後にB/Cを明示選択すること。primary実行はまだ許可されていない。
