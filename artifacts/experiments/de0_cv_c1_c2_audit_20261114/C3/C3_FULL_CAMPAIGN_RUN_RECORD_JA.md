# RTNN Stage C3 全13 schedule 実機測定記録

実施日: 2026-11-14 JST  
正本: [Unjuno/resource-conditioned-neural-computation](https://github.com/Unjuno/resource-conditioned-neural-computation)  
作業ブランチ: `codex/stage-c3-jtag-pilot-20261114`  
測定中のHEAD: `2a7231c8bf0ec2e81f00b307f54123db5dc0dab6`  
Quartus: Prime Lite 25.1std.0 Build 1129, Windows  
基板: Terasic DE0-CV / Cyclone V 5CEBA4F23C7N  

## 証拠・構成identity

保存済みC2J2実機構成と照合したidentityを使用した。キャンペーン中にSOFを再programせず、JTAG Virtual JTAGのユーザー計測系だけでデータを送受信した。

| 項目 | identity |
|---|---|
| Physical SOF SHA-256 | `5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6` |
| Firmware ELF SHA-256 | `625daf8cc194f1bc7d48eefff0f07939c5e0988bb07fc8a3e7efad7e613a15fd` |
| Q15 header SHA-256 | `961a76b7e220bf2f665e7c04ab62063600aa2e7eccf3403d80ea730bc993ad9f` |
| Build ID / model ID | `43324a32` / `52544e4e` |
| JTAG IDCODE / design hash | `02B050DD` / `DF2731CF973C3275CFE6` |
| Frozen campaign canonical SHA-256 | `d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc` |

解析用Pythonは3.11.9。30個の保存済みQuartus STP logを走査し、各logの報告は0 error / 0 warning（そのログのスクリプト処理範囲のみ）。コマンド・cwd・終了コード・tool結果は`evidence/TOOL_WARNING_AUDIT_20261114.txt`に保存した。これはQuartus Fitter/STA signoffとは別の確認である。

SOF、flat RTL、QSF/SDC、source graph、ELF、RAM lane和JTAGの履歴照合は[ソースと外部JTAGタイミング監査](evidence/SOURCE_AND_JTAG_TIMING_AUDIT_JA.md)にある。Gate Aの再構築SOFは今回の実機SOFと異なる構成なので使用していない。

## 全scheduleの実機ゲート

凍結入力360件、13 scheduleの行とSHAを変えず、予定24,840要求を完了した。全13実験manifestと独立結果監査は成功し、出力ファイルSHAは各run manifestで照合した。

| 凍結session | 実験ID | 行数 | 結果 |
|---|---|---:|---|
| diagnostic_fixed | `C3_DIAGFIXED_FULL2520_RUN1_20261114` | 2,520 | PASS |
| diagnostic_adaptive | `C3_DIAGADAPTIVE_FULL7560_RUN1_20261114` | 7,560 | PASS |
| diagnostic_capped | `C3_DIAGCAPPED_FULL7560_RUN1_20261114` | 7,560 | PASS |
| primary_01 | `C3_PRIMARY01_FULL720_RUN1_20261114` | 720 | PASS |
| primary_02–primary_10 | 各`C3_PRIMARYnn_FULL720_RUN1_20261114` | 7,200 | PASS |
| 合計 | 13 session | **24,840** | **PASS_EMPIRICAL_DATA** |

結果CSVを凍結case行とsequence/input/mode/期待予測/期待Exitで再照合した。全要求に有効な正の`Ibex_mcycle_delta`と一致する応答cycleがあり、予測不一致0、cap違反0、timeout/trap 0、CRC/要求応答ID identity違反0。UART未使用、Flash/CFM未書込み。正解数を集計する独立入力IDは360件のままで、24,840回の反復を新しい入力標本として数えていない。

測定時点でprimary_02–primary_10の各manifestにはPowerShell runner、Tcl、auditor、chunk helperのSHAを記録した。primary_01と3つのdiagnostic sessionは同じsource-SHA欄を持たない過去形式manifestであり、後から当時のrunner hashを補作していない。これらの生ログ、出力、case bindingと独立結果監査は保存済みだが、再実行script provenanceは後続sessionより弱い。

各runのchunk生ログ、結合結果、`result_audit.json`、`run_manifest.json`、`SHA256SUMS.txt`は`campaign/results/`に保存した。全行を結合したCSVと最終解析JSONは`campaign/analysis/C3_FULL24840_RUN4_FINAL_20261114/`にあり、独立再実行`RUN5_REPRO`のSHA manifestはRUN4と一致した。集計CSV SHA-256:

`f8651f29f42febe85a3c83a3ae245c0bcea56caadafc1fe9b7dd11a1f77277cf`

## 経験的な対応比較

事前凍結されたprimary 10 scheduleについて、同じ360 input IDごとのfixed Exit 2とadaptiveの組を合計3,600対で比較した。10 scheduleをinput ID内で平均し、frozen planどおり5,000回、seed 63でinput ID単位のpercentile bootstrapを行った。

| 指標 | 結果 |
|---|---:|
| fixed Exit 2 平均 | 943,924.77 cycles |
| adaptive 平均 | 746,322.99 cycles |
| fixed2 − adaptive | 197,601.77 cycles |
| 差の95% input-bootstrap CI | [158,616.47, 235,071.07] cycles |
| fixed2平均に対する平均削減率 | 20.934% |
| 削減率の95% input-bootstrap CI | [16.804%, 24.904%] |
| 事前設定5% point / CI下限 | 両方満たす（条件付き） |

ただしrun manifestには3つ以上の**確認済み独立cold boot**が記録されていない。primary_02–10は`POWER_SESSION_UNCONFIRMED_20261114`, `cold_boot_confirmed=false`として保存した。primary_01と診断runにはpower session記録がない。よって凍結planで速度主張に必須の3 boot two-way bootstrapは成立せず、上記区間は実測したpower historyに条件付けた記述値に限る。**速度優位は主張しない。**

ユーザーは追加のcold bootを実施できると回答した。今回のprimary_02–10をcold bootとして後付け分類せず、条件を満たす場合はprimary_01/02/03の凍結case列を使った追加replayを新experiment IDで作る。既存13 scheduleの行や結果を上書き・変更しない。cold boot後は揮発SOFが失われるため、同一SOF SHAを照合してFPGA SRAMだけに設定し、Flash/CFMへ書かない。追加replayとtwo-way再解析はこの記録時点では未実施。

分類精度はadaptive 339/360、fixed Exit 2も339/360。適応−固定差は0.000 percentage pointsだが、360入力を単位としたpaired 95% bootstrap区間は−1.389から+1.389 pointsで、事前の1-point非劣性幅を確立できない。判定は**INCONCLUSIVE**。反復scheduleは独立評価入力数を増やしていない。

このキャンペーンは既存の凍結評価セットに対する経験的再現測定である。新規汎化、精度優位、hard real-time deadlineは検証していない。実測値はdevice cycle countであり、未校正の絶対時間・周波数・ppmへ換算しない。

## タイミング保証ゲートと公式資料

内部STA/CDCの保存済みC2結果は限定範囲でPASS（4 corner setup/hold正、worst setup +0.821 ns、worst hold +0.116 ns、要求/応答bundled data path記録あり）。しかしQuartusはsetup/holdがfully constrainedでないと報告し、JTAG TDI/TMS/TDOやLEDR等の未制約pathが残る。`report_max_skew`には該当pathがなく、CDC全体のformal proofにも数えない。したがって正式なboard-level timing gateは**BLOCKED**。

Altera Cyclone V datasheet Table 56の端点条件（TCK period min 30 ns、high/low min 14 ns、TDI/TMS setup 1/3 ns、hold 5 ns、TDO clock-to-output max 11 ns）は公式資料から照合済み。ただしこの値はTerasic board、USB-Blaster回路・USB/target cableの遅延を含まない。Quartus 25.1std.0を確認し`jtagconfig --getparam 1 JtagClock`を読み取り専用実行したところ、exit 4 `No parameter named JtagClock`であり、実際のTCK周波数は確認できなかった。Cable III/Download Cable IIの設定値は今回検出された`USB-Blaster [USB-0]`へ流用しない。query証拠は`evidence/JTAG_EXTERNAL_TIMING_READONLY_20261114/`。

一次資料:

* [Altera Cyclone V Device Datasheet: FPGA JTAG Configuration Timing](https://docs.altera.com/r/docs/683801/current/cyclone-v-device-datasheet/fpga-jtag-configuration-timing?contentId=tHclXha2uF6DJBsBSWaFRA)
* [Altera Cyclone V Handbook: I/O Voltage for JTAG Operation](https://docs.altera.com/r/docs/683375/current/cyclone-v-device-handbook-volume-1-device-interfaces-and-integration/i/o-voltage-for-jtag-operation)
* [Terasic DE0-CV official board page and documents](https://www.terasic.com.tw/cgi-bin/page/archive.pl?CategoryNo=13&Language=English&No=921&PartNo=4)
* [Altera USB-Blaster III JTAG timing method](https://docs.altera.com/r/docs/864466/current/usb-blaster-iii-fpga-development-cable-user-guide/creating-jtag-timing-constraints-in-quartus-prime-software) — method reference only; this is not the cable identified on this DE0-CV.

No false path was added, no timing requirement relaxed, and no hard-deadline/WCET claim is made.

## 保存・再実行

* frozen case preparation: `python C3/source/prepare_c3_campaign_session.py --session <frozen-session> --out C3/campaign/prepared/<frozen-session>`。既存outputがある場合は新しい出力IDを使う。
* physical JTAG runner: `C3/source/host/Invoke-C3JtagCampaignSession.ps1`。このrunnerは既存SOF SHA、JTAG ID/design hashを検査し、STP user pathのみ実行する。`.sof`書込みやFlash機能を実行しない。
* full aggregate validation: `python C3/source/analyze_c3_campaign.py --c3-root C3 --out-dir C3/campaign/analysis/<new-run-id>`。既存out-dirは上書きせず、新しいIDを使う。
* all empirical rows and analysis: `campaign/analysis/C3_FULL24840_RUN4_FINAL_20261114/`。再現実行のSHA照合は`C3_FULL24840_RUN5_REPRO_20261114/SHA256SUMS.txt`。

次の統計速度ゲートには、追跡可能な少なくとも3 independent board power-session IDを含む計画済み再測定が必要である。タイミング保証には対象実機CableのTCKおよび外部経路遅延、I/O制約と全path signoffが別途必要となる。

## 追補：primary_01 3独立cold-boot感度再測定（2026-11-14）

凍結された`primary_01` 720条件を、3回の確認済み電源off/on後に同一のC2J2 SOFで再測定した。experiment IDは`C3_PRIMARY01_COLD_BOOT_REPLAY01/02/03_20261114`、board power session IDは`C3_BOOT01/02/03_20261114`。各回のJTAG IDCODEは`02B050DD`、design hashは`DF2731CF973C3275CFE6`、SOF SHA-256は`5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6`。設定はFPGA SRAMのみで、Flash/CFMに書込みなし。全回でユーザーが基板LED全消灯と電源再投入を確認した。10秒以上の待ち時間は依頼したがCodex側で独立計時していない。

各回720/720件を監査PASS。合計2,160行、360独立input ID、各bootの固定2/adaptive pairは360組。予測とExitは全bootで入力ごとに一貫。timeout、trap、CRC/identity fault、cycle invalid、Q15予測/Exit不一致は0。測定は`EMPIRICAL_ONLY`であり、STA/WCET/hard deadline保証を意味しない。

5,000回のinput×boot crossed bootstrap（input seed 63、boot seed 104729）では、固定2−adaptiveの平均差197,601.77 cycles、95% CI [158,616.47,235,071.07]。固定2比の平均削減率20.934%、95% CI [16.804%,24.904%]。この結果はprimary_01だけの補足cold-boot感度解析で、13 schedule全体のcold-boot反復ではない。主キャンペーンの24,840 planned rowsは変更していない。分類精度は固定2/adaptiveとも339/360で、paired差0.000 percentage point、独立360入力bootstrap 95% CI [−1.389,+1.389] pp。事前の1 pp非劣性条件は引き続きINCONCLUSIVEであり、速度差だけを分類品質の維持と合わせて主張しない。

解析コード：`C3/source/analyze_c3_coldboot_replays.py`。決定論的解析出力は`C3/campaign/analysis/C3_PRIMARY01_3COLD_BOOT_SENSITIVITY_RERUN3_20261114/`と`...RERUN4_20261114/`。後者は重複・欠落seq、実験/SOF identity、reference-label alignmentの追加検査後の結果。補正経緯は`C3/campaign/analysis/C3_COLD_BOOT_ANALYSIS_CORRECTION_NOTE_20261114/CORRECTION.md`、bootごとの物理操作/JTAG証拠は`C3/evidence/cold_boot_replays/`。各回の全raw CSV/JSON・manifest・監査は該当する`C3/campaign/results/C3_PRIMARY01_COLD_BOOT_REPLAY*_20261114/`。

補足：初期の作業計画にある「最低3 cold boot未達」は本追試前の状態だった。今回のprimary_01に限る3 boot測定でboot数条件を満たしたが、キャンペーン全13 scheduleを3 bootで再測定したわけではない。従って全campaignのcold-boot感度を証明したとはしない。
