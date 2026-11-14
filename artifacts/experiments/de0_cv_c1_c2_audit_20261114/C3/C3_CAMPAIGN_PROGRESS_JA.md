# RTNN Stage C3 実機キャンペーン進捗

更新: 2026-11-14 JST  
正本: `https://github.com/Unjuno/resource-conditioned-neural-computation`  
作業ブランチ: `codex/stage-c3-jtag-pilot-20261114`  
測定時HEAD: campaign本体 `bd65b37758654a0166e50790a5c00e4cc3f7ee7a`。cold-boot追試は同じ専用ブランチの未commit作業ツリーで実施。

## ゲート状況

| 工程 | 状態 | 結果 |
|---|---|---|
| C1/C2証拠・SOF/source/firmware対応 | PASS | 実機SOF `5aa5be2e…`、ELF `625daf8c…`、build/model IDとQSF/SDC/4 RAM laneを照合。詳細は`evidence/SOURCE_AND_JTAG_TIMING_AUDIT_JA.md`。 |
| 凍結campaign | PASS | 360 input IDs、13 schedule、canonical SHA `d6c98f59…`, 24,840予定行。schedule変更なし。 |
| 新規IDパイロット | PASS_EMPIRICAL | ID 165/271で4要求、Q15出力・CRC・応答ID・mcycle一致。 |
| mode 2 capped probe | PASS_EMPIRICAL | frozen seq1–4の部分probe成功。24,840行へは加算しない。 |
| 13全schedule実機測定 | PASS_EMPIRICAL_DATA | 24,840/24,840行、13/13 runと独立監査PASS。prediction/Exit/cap/CRC/ID/timeout違反0、全件cycle有効。UART未使用、Flash/CFM未書込み。 |
| 経験的対応比較 | PASS_DESCRIPTIVE_ONLY | 3,600 paired primary observations。条件付きcycle差は+197,601.77 cycles、95% input bootstrap CI [158,616.47, 235,071.07]。削減率20.934%、95% CI [16.804%,24.904%]。 |
| primary_01 cold-boot追試 | PASS_EMPIRICAL | 3回のユーザー確認済み電源断・再投入後、同一SOFをSRAMへ再設定。primary_01を3 boot各720件、計2,160件再測定。boot ID・SOF/build/input/schedule・全応答を照合。 |
| cold-boot交差cycle解析 | PASS_EMPIRICAL | input×3 bootの5,000回 crossed bootstrapで固定2−適応差197,601.77 cycles、95% CI [158,616.47,235,071.07]。削減率20.934%、95% CI [16.804%,24.904%]。primary_01に限定された補足感度解析であり、13 schedule全体のboot再現試験ではない。 |
| accuracy非劣性（1 pp margin） | INCONCLUSIVE | 360独立入力で固定2/adaptiveとも339/360。対応差0.000 pp、95% CI [−1.389,+1.389] pp。測定反復を標本数に加えず、1 pp非劣性は確立していない。 |
| 内部STA/CDC記録 | PASS_LIMITED | C2 exact-dispositionの4-corner slackは正。request/response pathは限定範囲で確認。完全board timing signoffを意味しない。 |
| 外部JTAG/全board timing signoff | BLOCKED | 公式device端点spec取得済み。対象board/cable path delayと実TCK不明、Quartus未制約I/Oも残る。 |
| WCET/hard deadline | NOT_ESTABLISHED | 実測cycleから時間上界またはdeadline保証を推定していない。 |

3 cold-boot replayのexperiment IDは`C3_PRIMARY01_COLD_BOOT_REPLAY01/02/03_20261114`。ユーザーが各回でLED全消灯と電源再投入を確認。10秒待機は依頼したが実測タイマーで検証していない。毎回JTAG IDCODE `02B050DD`、SOF SHA `5aa5be2e…`、設計hash `DF2731CF973C3275CFE6`を照合し、FPGA SRAMだけに設定。Flash/CFMは未変更。証拠は`evidence/cold_boot_replays/`、run結果は`campaign/results/`、2,160行の結合データと解析は`campaign/analysis/C3_PRIMARY01_3COLD_BOOT_SENSITIVITY_RERUN4_20261114/`。RERUN3とRERUN4の決定論的結果・manifestを比較する。

完全な値、全13 run ID、入力/結果SHA、コマンド、解析定義は[`C3_FULL_CAMPAIGN_RUN_RECORD_JA.md`](C3_FULL_CAMPAIGN_RUN_RECORD_JA.md)。解析CSV/JSONは`campaign/analysis/C3_FULL24840_RUN4_FINAL_20261114/`。独立再集計RUN5のSHA manifestはRUN4と一致した。

## タイミング外部資料

* [Altera Cyclone V FPGA JTAG Configuration Timing, Table 56](https://docs.altera.com/r/docs/683801/current/cyclone-v-device-datasheet/fpga-jtag-configuration-timing?contentId=tHclXha2uF6DJBsBSWaFRA)
* [Altera Cyclone V Handbook: I/O Voltage for JTAG](https://docs.altera.com/r/docs/683375/current/cyclone-v-device-handbook-volume-1-device-interfaces-and-integration/i/o-voltage-for-jtag-operation)
* [Terasic DE0-CV official board/documents](https://www.terasic.com.tw/cgi-bin/page/archive.pl?CategoryNo=13&Language=English&No=921&PartNo=4)

Quartus Prime Lite 25.1std.0 Build 1129で`jtagconfig --getparam 1 JtagClock`はexit 4、`No parameter named JtagClock`。TCK変更はしていない。端点specにCable/board propagation delayは含まれないため、正式signoffはBLOCKEDのまま。queryのコマンド・ログ・SHAは`evidence/JTAG_EXTERNAL_TIMING_READONLY_20261114/`。

## 再実行と保全

* `python C3/source/prepare_c3_campaign_session.py --session <frozen-session> --out C3/campaign/prepared/<frozen-session>`
* `C3/source/host/Invoke-C3JtagCampaignSession.ps1` — JTAG identity照合後、Virtual JTAG user pathのみ。SOF programming/Flashを呼ばない。
* `python C3/source/analyze_c3_campaign.py --c3-root C3 --out-dir C3/campaign/analysis/<new-run-id>` — 凍結campaign、run監査、全データSHAを再検査しCSV/JSONを作る。

失敗した準備・分割試行のログは個別のrun directoryに残す。途中失敗のデータをplanned rowへ算入しない。経験的実測、内部STA、board timing保証、統計速度判定は別ゲートで報告する。
