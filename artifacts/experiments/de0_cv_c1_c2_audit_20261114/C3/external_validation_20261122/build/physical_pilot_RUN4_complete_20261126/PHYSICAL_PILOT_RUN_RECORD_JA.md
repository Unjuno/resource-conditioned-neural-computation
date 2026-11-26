# 実機pilot run record — 2026-11-26

## 完了したRUN4

`C3_EXTVAL_PILOT_20261126_RUN4` / `BOARD_POWER_EPOCH_20261126_CURRENT` で、凍結pilotの10入力×2 mode、計20要求を実行。Quartus STP Virtual-JTAG runnerのstatusは`COMPLETE`、20/20。UART、Flash、CFMは使用・変更していない。

各raw request/responseについて、独立gate監査がframe長、CRC、要求sequence、入力ID・画素、画素SHA、payload CRC、mode、Build/Model/Binding ID、prediction、admitted/executed Exit、stop reason、64-bit mcycle start/end/deltaをケースCSVおよびCPU oracleと照合し、`PILOT_AUDIT_PASS`。生成gateは独立validatorで再検証済み。

- SOF SHA: `5e333e9377b7188a394d04b93b98833d91afb2cd53eca8d976e6aa715dfa00c4`
- ELF SHA: `4673f6a8b90493c15c327ed3be1167e0fcf3ff2be60292dcb12a1391124a0c2e`
- Pilot IDs: `57, 277, 321, 519, 525, 667, 921, 1673, 3660, 3689`
- 予測: 20/20が凍結CPU Q15参照と一致。
- 教師ラベルとの一致: fixed2 10/10、adaptive 10/10（10件の工学pilotに限る）。
- Cycle: fixed2 median 943,906; adaptive median 565,923。adaptiveは8/10入力で少ないが、ID 519・667では各127,563 cycles多い。この小標本から一般的な速度優位は主張しない。
- RUN4全ケースcycle範囲: 565,921–1,071,469。
- 実行後のread-only status: `READY=1, pending=0, busy=0, done=0, error=0`。

## 保存した失敗試行と回復データ

- RUN1: runnerのTcl CRC式構文エラーで0要求。試行ログを保持。
- RUN2: seq=1 adaptive要求は実行されたが、480-bit応答scanに384-bitの入力値を渡したrunner不具合で停止。応答は後から正しい480-bit scanで回収し、CRC・要求画像・参照出力・Build identity・counterを照合。1件のみの回収結果で、20件runのPASSには算入しない。
- RUN3: 同じライブFPGAでseq=1を再使用し、firmwareの単調増加sequence規則により`BAD_REQUEST`(response status 4)、mcycleは0で拒否された。エラー応答を回収して状態をREADYへ戻した。
- RUN4: RUN2で処理済みのseq=1より後の2–21を使用し、20件完了。

RUN1–RUN3の履歴・rawログは各 `build/physical_pilot_attempt*_failed_20261126/` に保管し、削除・成功扱いしていない。RUN2の回収応答は`recovered_response_audit.json`、RUN3のエラー応答は`error_response_recovery_success.log`に保管。

このrunの位置づけは`EMPIRICAL_ONLY`。1つの連続した基板電源epochでのpilotであり、独立cold boot、母集団精度非劣性、一般的な速度優位、外部JTAG timing signoff、WCET、hard deadlineを示さない。
