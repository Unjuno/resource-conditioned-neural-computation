# RTNN Stage C3 — 現在地 2026-11-15（KEY-reset RUN4後）

この文書が最新statusです。RUN3以前の記録は各時点の履歴として保持します。

## Repository / 保全

- Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
- Branch: `codex/stage-c3-jtag-pilot-20261114`
- HEAD: `b332ba02ab992227140998a1d67513c690ae17cf`
- originは正しいUnjuno repository。既存差分と実験証跡を保全。今回の追加記録は未commit。commit/push/PR/mergeなし。

## Gate status

| Gate | Status | Evidence / boundary |
|---|---|---|
| B-SIGNOFF | **BLOCKED** | 基板revisionに対応するUSB-Blaster/JTAG外部TCK/TDI/TMS/TDO timingが未確定。formal timing signoff、WCET、hard deadlineは主張しない。 |
| B-EMPIRICAL | **PASS_LIMITED** | C3 v2 build `43334531`の経験的適格性に限定。正式signoffの代替ではない。 |
| C3 v2 KEY[0] reset replay RUN4 | **PASS 20/20** | build identityのread-only照合、PowerShell監査、独立Python監査、reset gate生成PASS。利用者の押下・解放申告でありreset電気telemetryではない。 |
| C3 v2 frozen campaign | **PASS 24,840/24,840 (prior run)** | 13/13 frozen schedulesの保存済み実測。今回のRUN4では再実行していない。1台・連続電源sessionでのEMPIRICAL_ONLY。 |
| native RTL rebuild | **PASS_CURRENT_WSL; PORTABILITY LIMITED** | pinned Ibex sourceを使った現行WSL回帰PASS。clean checkoutには依存RTL一式が含まれず、自己完結再現性に制限。 |
| CDC mailbox phase stress | **PASS 38/38 finite simulations** | nativeとQuartus-flat mailboxを各19 phase/period条件、32取引ずつ実行。警告0。アナログmetastability/MTBFまたはSTAの証明ではない。 |
| 精度非劣性 | **INCONCLUSIVE** | 事前の1 percentage-point marginを満たす証拠なし。 |

## RUN4 reset replay

- Read-only JTAG identity: USB-Blaster USB-0、IDCODE `0x02B050DD`、build `43334531`、READY `0x08`。
- `primary_01`の固定20 sequenceを新experiment IDで再実行。予測/reference/Exit/cap/CRC/ID/64-bit `mcycle`検査の違反0。
- cycles: min `565,954`、median `943,929`、max `2,082,594`。
- Gate SHA-256: `7970851b4b8b53723977ddd7eb76d216bc3f364e2c20ba189524e2b404cd1c10`。
- SOF再設定、電源断、Flash/CFM書込み、配線またはclock変更なし。
- 完全記録、生CSV/JSON/raw log、失敗した監査呼出し、gate、SHA manifest: [RUN4 evidence](evidence/PHYSICAL_C3_V2_20261115/KEY_RESET_REPLAY/C3V2_TENINPUT_KEY_RESET_REPLAY_20261115_RUN4/RUN_RECORD_JA.md)。

## 残る課題

追加CDC phase stressは有限のdigital simulationを広げたが、D102は未抑制。B-SIGNOFFは外部JTAG timing資料または適切な測定がないためBLOCKEDのまま。4 cornerの保存STA、UCP分類、未解決I/Oの監査結果と今回のsimulation範囲は[Gate B CDC phase stress record](evidence/GATE_B_CDC_PHASE_STRESS_20261115/RUN_RECORD_JA.md)を参照。既存の24,840件キャンペーンはC3 v2としてすでに完了しており、今回その値を再測定値として数えていない。外部timing保証、独立cold-boot感度、accuracy non-inferiority、WCET/hard deadlineは未成立または未評価。
