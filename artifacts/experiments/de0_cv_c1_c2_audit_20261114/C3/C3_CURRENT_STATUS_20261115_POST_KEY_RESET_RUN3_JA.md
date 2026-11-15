# RTNN Stage C3 — 現在地 2026-11-15（KEY-reset RUN3後）

この文書が最新statusです。過去のstatusは実施時点の履歴として保持しています。

## Repository / 保全

- Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
- Branch: `codex/stage-c3-jtag-pilot-20261114`
- HEAD: `b332ba02ab992227140998a1d67513c690ae17cf`
- originは正しいUnjuno repository。開始時の既存差分と827件以上の旧証跡を保全。
- 今回追加した実験証拠・記録はローカル未commit。commit/push/PR/mergeなし。旧`kardaneh/RTnn`作業ツリーには書き込んでいない。

## Gate status

| Gate | Status | Evidence / boundary |
|---|---|---|
| B-SIGNOFF | **BLOCKED** | DE0-CV board revisionに対応した内蔵JTAG TCK/TDI/TMS/TDO外部タイミングと必要な外部I/O制約が未確定。正式STA signoff、WCET、hard deadlineを主張しない。 |
| B-EMPIRICAL | **PASS_LIMITED** | C3 v2 build `43334531`上の限定経験的評価。正式signoffの代替ではない。 |
| C3 v2 KEY[0] reset replay RUN3 | **PASS 20/20** | 利用者がKEY[0]の押下・解放を確認。Read-only identity、PowerShell監査、Python独立監査、gate生成PASS。結果は新experiment IDで保存。 |
| 既存C3 v2 frozen campaign | **PASS 24,840/24,840 (historical run)** | 13 scheduleの保存結果。RUN3では再実行していない。1台・同一build・独立cold boot未確認のEMPIRICAL_ONLYデータ。 |
| native RTL rebuild | **PASS_CURRENT_WSL; PORTABILITY LIMITED** | Ubuntu 24.04環境、146-source graphとIbex commit/hashで回帰PASS。Ibex依存はclean repository checkoutに同梱されない。 |
| 旧C2J2精度非劣性 | **INCONCLUSIVE** | 非劣性marginを満たす証拠なし。 |

## Gate B current-worktree revalidation

現在の作業ツリーから保存済みSTA/CDC/UCP監査器を再実行し、3/3がexit 0でした。4 cornerの保存済み constrained top-20 setup/hold slackはすべて正、16 D102は未抑制、TDI/TMS/TDOの外部タイミングは未制約です。別途公式資料を確認しましたが、Cyclone V endpoint requirementsと一般EPM240値はあっても、DE0-CVの搭載EPM240 speed grade・controller launch/capture・PCB path min/maxは特定されません。したがって **B-SIGNOFF BLOCKED** を維持します。詳細・JSON・実行ログ・input/output SHA: [Gate B revalidation](evidence/GATE_B_REVALIDATION_CURRENT_WORKTREE_20261115/RUN_RECORD_JA.md)。
## 今回のreset実験

- read-only JTAG identity: USB-Blaster USB-0、IDCODE `0x02B050DD`、build `43334531`、READY `0x08`。
- 固定`primary_01` 20-sequence replay: 20/20、予測・Exit・CRC・応答ID・64-bit cycle検査の違反0。
- `mcycle` delta range: 565,954–2,082,594 cycles。絶対時間には換算していない。
- PowerShell audit: PASS。独立Python audit: `PASS_SAVED_PHYSICAL_EVIDENCE_AUDIT`。
- reset gate SHA-256: `777e7cd18eca46f381454402993d82806508bee24921c0f9ba7ee275769e087b`。
- KEY[0]操作は操作者申告であり電気的reset telemetryではない。電源再投入、SOF再設定、Flash/CFM変更はしていない。
- 詳細、生ログ、CSV/JSON、監査結果、manifest: [RUN3 evidence](evidence/PHYSICAL_C3_V2_20261115/KEY_RESET_REPLAY/C3V2_TENINPUT_KEY_RESET_REPLAY_20261115_RUN3/RUN_RECORD_JA.md)。

Quartus STP runnerのoffline Tcl regressionは修復後に再実行し、attempt14でexit 0・0 Quartus errors/warnings。attempt12（誤ったbinding-root）を含む全試行ログを保持。最終ログ: [attempt14](evidence/C3_MEASUREMENT_V2_RUNNER_RESET_GATE_20261115/attempt14_quartus_stp_tcl.log)。

## 次工程

保存済み24,840行の独立統計監査と図表再生成を進められる。C3 v2 physical campaignはすでに完了した履歴であり、今回のKEY-reset RUN3はそれと別run。B-SIGNOFFは外部JTAG timingが仕様と基板revisionに結び付くまでBLOCKEDのまま。ユーザーやTerasicへの問い合わせは未送信。