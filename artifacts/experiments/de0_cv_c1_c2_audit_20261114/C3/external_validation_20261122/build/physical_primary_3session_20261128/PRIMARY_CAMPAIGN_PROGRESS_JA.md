# C3 外部画像 primary キャンペーン進捗

更新: 2026-11-28 JST。全結果は`EMPIRICAL_ONLY`。

## 実施済み

- 対象: DE0-CV Cyclone V `5CEBA4F23C7`、USB-Blaster、Build ID `45585631`、Binding ID `45585632`、Model ID `52544e4e`。
- SOF SHA-256: `5e333e9377b7188a394d04b93b98833d91afb2cd53eca8d976e6aa715dfa00c4`。ELF SHA-256: `4673f6a8b90493c15c327ed3be1167e0fcf3ff2be60292dcb12a1391124a0c2e`。
- Pilot RUN4 gateを独立validatorで再検証。read-only JTAG identityはIDCODE `02B050DD`、Build ID `45585631`、READY=1、BUSY=0、ERROR=0。
- Session 01: `C3_EXTVAL_PRIMARY_20261128_S01`、7,626/7,626要求完了。raw要求・応答7,626組。独立監査`load_run(..., 'primary')` PASS、予測/oracle不一致0、CRC異常0、失敗0。
- SRAMへのSOF再設定は行わず、すでに動作していた同一Build IDを確認して測定。Flash/CFM/CPLD、UART、配線、電圧、クロックは変更していない。

## Session 01 の単独参考集計

- fixed2: 正解3,482/3,813（91.319%）、平均943,905.78 cycles、中央値943,906。
- adaptive: 正解3,485/3,813（91.398%）、平均759,704.67 cycles、中央値565,923。
- 対応平均cycle削減率19.515%。入力単位bootstrap（10,000 draws, seed 20261122）95%区間18.106%–20.871%。adaptiveのcycleが大きい入力929/3,813。
- 片側非劣性数値の下限は−0.639 percentage points、事前指定margin −1 ppに対する数値判定はPASS。ただしこれは1 sessionの数値結果に限る。
- 3-session cycle gateは未判定。独立電源sessionの適格性、筆記者クラスタ、過去データ使用、事前登録の先行時刻、外部JTAGタイミングは未解決。母集団への精度非劣性・速度優位は主張しない。

## 残り

- Session 02: 7,626件。今回のoffline preflightを再実行して`PREFLIGHT_ONLY`、pilot gate独立照合PASS、identity/case SHA/sequence range一致を確認。記録は`session_02/offline_preflight_RUN1.json`。JTAG/Quartus未起動、出力先未作成。開始前に操作者の電源状態回答とread-only ID/build/READY照合が必要。
- Session 02 read-only pre-run check (2026-11-28 11:03 JST): USB-Blaster `[USB-0]`, IDCODE `02B050DD`, Build ID `45585631`, mailbox `READY=1/BUSY=0/ERROR=0`; host SOF SHA matched. Full record: `../../../final_research_verification_20261128/SESSION02_READ_ONLY_IDENTITY.json`. No request was sent and no RAM/SOF/Flash write occurred. This snapshot does not resolve the pending operator power-transition confirmation.
- Session 03: 7,626件。凍結cases/bindingをオフライン再検査し、7,626行・sequence 15274–22899・pilot gateを照合。結果は`../../../final_research_verification_20261128/session03_schedule_reverification_RUN1.json`。これは事前schedule監査のみで、session 03のJTAG測定はSession 02完了監査後に実施する。
- 予定総数22,878件中、現在7,626件取得（1/3 session）。cold boot証拠は未取得。Session 01の電源履歴は`POWER_SESSION_UNKNOWN`/`COLD_BOOT_UNVERIFIED`。
- session間は一件ずつ監査し、異常時は停止してログを保持する。セッションIDだけで独立cold bootとは認定しない。
