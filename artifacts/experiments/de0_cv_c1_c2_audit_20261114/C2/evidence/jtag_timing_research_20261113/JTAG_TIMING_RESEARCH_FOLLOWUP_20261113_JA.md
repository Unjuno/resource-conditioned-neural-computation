# C2 JTAG timing調査の追加確認

日時: 2026-11-13 JST
対象: C2J2 build `43324a32` / Cyclone V `5CEBA4F23C7N`
作業: 公式資料の読み取りと、既存Quartus STAレポートの再確認。RTL、QSF、SDC、基板設定は変更していない。

## 追加で確かめたこと

- Terasic公式DE0-CV回路図のUSB Blasterシート（17/17）は、FT245BL U5、MAX II `EPM240T100` U13、24 MHz発振器を示す。FPGA側のJTAG線は同CPLD経由である。回路図の部品表記にspeed grade suffixはなく、CPLDロジック内容・出力位相・JTAG線のPCB配線長も掲載されていない。
- 再取得済み公式System CD ZIPのread-only inventoryでも、回路図とControlPanel SOF/DLLはあるがMAX II CPLD sourceやPCB CAD layoutは見つからなかった。絞り込みコマンド: `tar -tf D:\DE0-CV_v1.2.1_SystemCD_official_20261113.zip | Select-String '(?i)(\.pcbdoc|\.brd|\.pcb|\.dsn|\.pdc|\.edf|usb.?blaster|\.qar$|\.qpf$|\.qsf$)'`。列挙されたQuartus projectはFPGA demo用で、CPLD source/layoutではない。
- Intel公式MAX II Device Handbookは、通常のMAX II EPM240にspeed grade `-3/-4/-5`があるとする。3.3-V LVTTL、最大drive、fast slew、10 pF条件で、EPM240 `tCO` は各gradeで最大4.3/5.6/6.9 ns。`tCO`はCPLD内global clockから出力端子までの仕様値であり、TCK対TDI/TMSの実測skewそのものではない。
- C2J2のpost-fit STAは、Intel SLD hub由来の`altera_reserved_tck`を30 MHz（周期33.333 ns）でclock化している。STAのunconstrained inputは`altera_reserved_tdi`と`altera_reserved_tms`、unconstrained outputは`altera_reserved_tdo`および使用LEDである。つまりFPGA内TCK同期回路の一部は解析されている一方、外部からTDI/TMSへ届くmin/max遅延、TDO出力要件、LED外部遅延は未モデル化のまま。
- IntelのQuartus Timing Analyzer CookbookのJTAG例は、JTAGデバッグ信号が設計に含まれるとTCK/TMS/TDI/TDOがunconstrainedとして報告され得ること、TDI/TMS/TDOには対象ケーブル・構成に合う外部遅延が必要なこと、TDIはTCK falling edgeでlaunchされる例を明記する。同資料の数値例はUSB-Blaster I/II用で、DE0-CVのオンボードFT245BL/EPM240回路にそのまま流用できない。現レポートの33.333 nsはSLD Hub HDL内の30 MHz clock modelであり、DE0-CV上の実TCK周波数や外部data delayの測定値を示さない。
- Terasic USB-Blaster revB manualは単体UBT cableをUSB-Blaster I/6 MHz、AUB2をUSB-Blaster II/24 MHzとする。DE0-CV公式回路図は内蔵USB-BlasterをFT245BL/EPM240 circuitと特定するが、実TCK frequency/dutyをboard-specificに記載しない。Quartus `jtagconfig --getparam 1 JtagClock`と`JtagClockAutoAdjust`は両方`No parameter named ...`でexit 4となった。よって一般USB-Blaster Iの6 MHzをDE0-CV実機の測定/保証値とは扱わない。
- この追加資料により、CPLD device familyと公称worst speed gradeの範囲は限定できた。ただしオンボードUSB-Blaster CPLDのprogrammed logic、実搭載suffix、TCKとTDI/TMSのlaunch phase、board trace skew/loadが特定できず、`set_input_delay`/`set_output_delay`を一意または保守的に定義する根拠は揃わなかった。tCO最大値をそのままFPGA入力delayに置くのは、clockとdataの相対経路を表さないため採用しない。

## 判定と次のゲート

JTAG I/Oの静的タイミングは引き続きBLOCKED。ここで推測したI/O delayやfalse pathを追加してSTA PASSにはしない。次に必要なのは、(a) Terasicが提供する当該board revisionのCPLD設計とPCB timing資料、または (b) TCK/TDI/TMS/TDOの実測と校正・probe位置・帯域/立上り誤差を記録した測定記録、およびI/O負荷の仕様である。物理基板からのCPLD marking確認はspeed suffixだけを補える可能性があり、programmed logicとskew資料の代替にはならない。

この調査の間、USB-Blaster/JTAGのprogramming操作はしていない。C2 SOFは未書込み、Flash/CFM未操作、JTAG実機推論は未実施。

## 参照資料

- Terasic公式DE0-CV System CD index: https://download.terasic.com/downloads/cd-rom/de0-cv/
- Terasic official schematic copy archived in `de0cv_setup/system_cd/Schematic/DE0-CV.pdf`; the official archive copy SHA-256 is recorded in `JTAG_TIMING_RESEARCH_20261113.md`.
- Intel official [MAX II Device Handbook](https://cdrdv2-public.intel.com/655094/max2_mii5v1.pdf), speed-grade offerings and EPM240 external I/O timing table 5-23.
- Intel official [Quartus Prime Timing Analyzer Cookbook — JTAG Signals](https://docs.altera.com/r/docs/683081/22.2/quartus-prime-timing-analyzer-cookbook/jtag-signals?contentId=HqsgrDMGTE4REitNdjYy5w), including the distinct USB-Blaster I/II timing examples.
- Terasic official [USB-Blaster revB Manual](https://www.terasic.com.tw/wiki/Terasic_USB_Blaster_revB_Manual), FAQ 2 (single UBT/AUB2 cable frequency only; not a DE0-CV onboard frequency guarantee).
- Intel/Altera official [JTAG timing constraint guidance](https://docs.altera.com/r/docs/864466/current/usb-blaster-iii-fpga-development-cable-user-guide/creating-jtag-timing-constraints-in-quartus-prime-software) says min/max I/O delays depend on the particular board and cable setup; the USB-Blaster III numeric example is not used for this board.
- Intel official [Cyclone V FPGA JTAG configuration timing](https://docs.altera.com/r/docs/683801/current/cyclone-v-device-datasheet/fpga-jtag-configuration-timing?contentId=tHclXha2uF6DJBsBSWaFRA).
- Quartus record: `evidence/quartus_d101_exact_disposition_20261113/rtnn_c2.sta.rpt` and `RUN_RECORD_JA.md`.
- 未送信のTerasic問い合わせ文案: `evidence/TERASIC_JTAG_TIMING_SUPPORT_REQUEST_DRAFT_JA.md`。

## 実行記録

- 作業cwd: repository root `C:\Users\junny\OneDrive\ドキュメント\ChatGPT\RTNN`
- 読み取りコマンド: PowerShell `Get-Content` / `rg` over the preserved C2J2 STA reports and Intel/Terasic sources; official source lookup used web search/open.
- ローカルコマンド終了コード: 0 for file reads/searches; a preliminary PDF-text extraction attempt returned 1 because Python module `fitz` is not installed. No installation was attempted; the already archived schematic and official indexed page were sufficient for this review.
- 出力: 本記録。既存RTL/SDC/build/SOF/board stateに変更なし。
