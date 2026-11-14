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
| primary_01 3電源サイクル追試 | PASS_EMPIRICAL_DATA / UNCERTAIN_COLD_BOOT | 凍結caseを各720件、計2,160件測定し、run単位の結果監査はPASS。だが電源断中もUSB-Blaster USB-Bを接続したままで、FPGA railが実際に落ちた証拠がない。3つの独立cold bootとは確認できない。 |
| 3セッション交差cycle解析 | PASS_NUMERIC_REPRODUCIBILITY / UNCERTAIN_INDEPENDENCE | 5,000回 crossed bootstrapの数値は再現。ただしpower sessionの独立cold boot性が未確認のため、cold-boot感度・独立boot変動の結論はUNCERTAIN。 |
| accuracy非劣性（1 pp margin） | INCONCLUSIVE | 360独立入力で固定2/adaptiveとも339/360。対応差0.000 pp、95% CI [−1.389,+1.389] pp。測定反復を標本数に加えず、1 pp非劣性は確立していない。 |
| 内部STA/CDC記録 | PASS_LIMITED | C2 exact-dispositionの4-corner slackは正。request/response pathは限定範囲で確認。完全board timing signoffを意味しない。 |
| 外部JTAG/全board timing signoff | BLOCKED | 公式device端点spec取得済み。対象board/cable path delayと実TCK不明、Quartus未制約I/Oも残る。 |
| WCET/hard deadline | NOT_ESTABLISHED | 実測cycleから時間上界またはdeadline保証を推定していない。 |

3つのprimary_01 replay experiment IDは`C3_PRIMARY01_COLD_BOOT_REPLAY01/02/03_20261114`。各回720件のデータと監査は保存済みで、ユーザーはDC電源のoff/onとLED全消灯を確認した。一方、指示によりUSB-Blaster USB-Bを接続したままだった。DE0-CV回路図ではUSB VBUS (`VCC5_USB`) も基板の5V電源網へ入るため、この操作だけではFPGA railの完全な電源断を確認できない。さらに今回の3回目のDC再投入後に読み取り専用`jtagconfig -n`でVirtual JTAG nodeとdesign hashが見えた。現象の原因（完全な電源断後の不揮発起動か、railが維持されたか）は未確定。したがってこれらは**確認済み3独立cold boot**として扱わず、3つの電源サイクルセッションに条件付けた経験値とする。10秒待機も独立計時していない。保存済みの2,160行とbootstrap数値は変更せず、cold-boot独立性に関する推論はUNCERTAINへ訂正する。詳細は`evidence/physical_post_coldboot3_readonly_20261114/RUN_RECORD_JA.md`。

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

### Gate B 再ビルド監査（2026-11-14）

C2の保存済みQuartus入力（QSF/SDC/flat RTL/board top/global buffer/4 RAM lane、各SHA一致）をDドライブの隔離作業領域でQuartus Prime Lite 25.1std.0 Build 1129に再投入した。フルcompile exit 0、Fitter成功、全4コーナーの内部CLOCK_50 setup/hold slackは正、Design Assistantの局所D101処置監査は801件を照合してPASS。request 800/800・response 384/384の保持バス経路も既存net-delay上限内だった。

一方、Timing Analyzerはsetup/holdがfully constrainedではないと再報告し、TDI/TMS入力2ポート・41 path、TDO/LEDR出力4ポート・8 pathが未制約。TDIからuser RTLの`req_shift_tck_q[799]`へのpathも含まれ、reserved名だけを根拠に除外できない。元SDCの全corner max-skew reportは`Nothing to report.`。20 ns `set_max_skew`と40/60 ns `set_max_delay`は元のSLD asynchronous clock group下ではQuartusがpathなしとした。診断専用Tclで全clock groupを一時除去し、7本のscalar CDCを受信同期器第1段だけfalse path、束データに40/60 ns max-delayを与えると、request 800/800・response 384/384 pathが4 cornerすべて0違反（最悪slack +32.704 ns / +57.933 ns以上）。同じ診断条件でprotocol capture windowを上限としたmax-skewも4 cornerで0違反、最大Quartus報告skew 3.528 ns / 3.330 nsだった。Lite Legacy analyzerでは`set_data_delay`もUnsupported。全clock group除去は他CDC経路の扱いを変え、通常max-delayのクロック関係も実機の任意phaseを直接証明しないため、これらは候補診断に限りGate B signoffではない。source updateから第3 destination edgeまでの最短時間は任意phaseにより3周期でなく2周期（40/60 ns）と訂正した。route-only差分はSTA slackではない。`report_metastability`は392 chainを報告し、9 reset/scalar-control chainはMTBF計算対象、383は自動グループ化されたresponse payload path（381 unique pairing＋2 alias）だった。capture envelopeとfirmware source-holdの限定監査はPASSしたが、setup/hold/uncertainty/ACKの全CDC証明ではない。再生成SOF SHA `995633cf…` は実機で測定した旧SOF `5aa5be2e…` と一致せず、候補SOFは実機へ書いていない。したがってGate BはBLOCKED、当該再生成SOFのGate C/DはNOT_RUN。詳細なコマンド、warning分類、全reportとSHAは`evidence/GATE_B_EXACT_REBUILD_20261114/`。

### 3回目の電源再投入後のJTAG読取り（2026-11-14）

ユーザー確認後、変更操作をせず`jtagconfig -n`を実行。USB-BlasterとIDCODE `02B050DD`に加え、Virtual JTAG node `00406E00`とdesign hash `DF2731CF973C3275CFE6`が見えた。接続とデザイン識別子の読取りはPASS。ただし直前のDC off/onではUSB-Bを接続したままであり、Terasicの配布回路図はUSB VBUS (`VCC5_USB`) を基板5V電源回路へ接続している。このJTAG照会だけでは完全なFPGA rail電源断の有無や構成元を判別できない。cold-boot独立性はUNCERTAINとして、SRAM保持やFlash未変更の新証拠には使わない。詳細は`evidence/physical_post_coldboot3_readonly_20261114/RUN_RECORD_JA.md`。Quartus起動時のTBBmalloc警告も同記録に残した。
### Gate B内部CDC候補SDCの全交差確認（2026-11-14追補）

専用ブランチの後続監査で、C2 fitted databaseのSDCを複製した候補SDCを隔離QSFから読み込み、STAを再実行した。候補QSFは元QSFからSDC_FILE一行だけを置換。重複登録で発生した初回のCLOCK_50重複警告は候補SDC単独参照へ直し、最終実行で解消した。候補SDCでは唯一のSLD TCK/CLOCK_50 clock groupを除き、7 scalar同期器の第1段のみ個別false path、held request/response busへ40/60 ns max-delay・max-skewを設定した。

ここで以前の「clock groupを全除去すると他CDC経路も変わる」という懸念を、現post-fit clock/path inventoryで絞り込めた。対象グラフにはclockが2個、該当groupは1個だけである。候補制約後に両方向の全clock-to-clock setup pathを列挙し、4コーナー全てでTCK→CLOCK_50はrequest 800本、CLOCK_50→TCKはresponse 384本のみ。他の内部clock crossing pathはゼロ。7組のstage1→stage2は各corner setup/holdとも1経路、計28 setup + 28 hold。最小setup slack +18.856 ns、最小hold slack +0.255 ns、違反0。要求/応答のmax-delayも全4コーナー違反0。max-skewの32 path records/コーナーも違反0で、最大skewは要求3.528 ns、応答3.330 ns以下。

これは内部CDCポリシーを網羅した候補SDCの限定STA結果で、先の限定診断より強い。元C2 SDC、RTL、実機SOFは変更していない。候補SDCではFitterを再実行しておらず、外部JTAGのTDI/TMS 2入力port・41 path、TDO 1出力port・5 pathが未制約のためQuartusはsetup/hold fully constrainedではないと報告する。ゆえに内部CDC候補監査はPASS_LIMITED、Gate B全体はBLOCKED、Gate Cは未実施のまま。生レポート、QSF/SDC/source SHA、初回重複警告と修正後の実行ログは`evidence/GATE_B_EXACT_REBUILD_20261114/candidate_internal_cdc_policy_20261114/`。