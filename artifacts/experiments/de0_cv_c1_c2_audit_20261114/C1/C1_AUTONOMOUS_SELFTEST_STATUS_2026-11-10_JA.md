# C1 自律実機自己試験 追加記録（2026-11-10）

## 判定

Quartus ROM修正版のビルド、最新詳細STA、SoC RTL自己試験、SRAM-onlyのFPGA設定、実機Q15自己試験のLEDR出力境界scan、および基板上のLEDR目視確認はPASS。

この追加bitstreamは通常のUARTヘッダーを使わず、SoC内UART TX/RX loopbackから固定Ibexで凍結Q15ファームウェアへ20要求を送り、応答を独立期待値checkerで検査する診断用トップ。KEY[0]はreset。外部PC UART、連続稼働、基板クロックの実周波数計測、論文campaignの代替ではない。GPIOは設計ポートにせず、Fitter reportでは未使用ユーザーI/Oは`RESERVED_INPUT_WITH_WEAK_PULLUP`（内部弱pull-up付きtri-state input）。動作中にGPIO配線を差し替える必要はない。

## ゲート

| 工程 | 状態 | 根拠 |
|---|---|---|
| checker単体 | PASS | 正常応答とCRC/予測/実行数/sequence/build ID/deadline/transport/bus fault/halted/idle/done等のnegative testを実行。`checker_run2.log`。 |
| Verilator SoC simulation | PASS | 固定Ibex + C1 SoC + RAM + Q15 firmwareを実行。20 request/responseを検証し、KEY reset後に同じ20件を再実行。`C1_AUTONOMOUS_SELFTEST_ALL_PASS runs=2 cases_per_run=20 reset_recovery=PASS LEDR=1000`。新規wrapper/checker/packet engineのVerilator警告0。既存Ibex flat RTLの`UNOPTFLAT` 3件はログに保持。 |
| sv2v converted selftest regression | PASS（warning review attached） | sv2v v0.0.13 + Verilator 5.020で同じnative testbenchを変換後に再実行。20 request/response×2、reset recovery PASS。warning 119件を分類し、固定Ibex由来UNOPTFLAT 3件と変換後の幅warningを保持。 |
| Quartus full compile / device / Fitter | PASS | Quartus Prime Lite 25.1std.0 Build 1129、Cyclone V `5CEBA4F23C7`。Fitter successful、3370 registers、6 user ports、256/308 RAM blocks。 |
| post-fit Design Assistant | PASS（information-onlyのみ） | `quartus_drc --post_fit=on` exit 0。critical/high/medium violations 0、information-only 338（T101=288、T102=50）。reportを保存。 |
| 詳細STA | PASS（内部クロック範囲） | 全slow/fast、85C/0C cornerでsetup/hold/recovery/removal/MPW正、TNS=0。worst setup +0.916 ns、worst hold +0.122 ns。最新critical pathはIbex instruction readからregister-file FF、9 logic levels。unconstrained clocks/ports/paths=0、loops=0、latches=0。 |
| 物理SRAM設定 | PASS | 2026-11-10 15:16 JST、Quartus Programmer `-c "USB-Blaster [USB-0]" -m JTAG -o "p;D:\\rtnn_de0cv_c1_autonomous_selftest_20261110\\quartus\\rtnn_de0_cv.sof@1"` exit 0。device index 1、JTAG ID `02B050DD`、5CEBA4F23、configuration succeeded、0 errors/0 warnings。SOF SHA-256 `a5ee8af78b05e1875d1f0fb2da4789e5d9debb6e96b5af78f5078749ea084a79`。`.pof`/`.jic`/CFM/Flash/eraseなし。再書込み後JTAG chain/IDCODE再確認もPASS。command/log/exitを`jtag_readback/`へ保存。 |
| 実機Q15自己試験（FPGA上の固定Ibex） | PASS（境界scan＋目視） | post-config BSDLの出力cellをSAMPLE/PRELOADで取得。LEDR3/Y3 cell 77=1、LEDR2/W2 cell 68=0、LEDR1/AA1 cell 71=0、LEDR0/AA2 cell 74=0、すなわち`1000`。取得前後IDCODEは`02B050DD`一致。2026-11-11に利用者がLEDR3だけ点灯を目視確認し、JTAG値と一致。Terasic DE0-CV manual p.24でもLED pin highは点灯。証跡`jtag_readback/sample_postconfig_leds*`と`user_ledr_confirmation_20261111.txt`。 |

JTAG follow-up read-only scan（2026-11-10 15:15 JST）でUSB-Blaster [USB-0] / IDCODE 02B050DD / device 5CE(BA4|FA4)を確認。再ロード後のsample scanはcapture前後とも同じIDCODE。

## 20要求内容

0..6: 7 deadline admission classes。7..13: 7 budget-cap classes（literal ROM `{0,10923,21845,32768,43690,54613,65535}`）。14..15: deadline reject。16: IID0 entropy stop。17..19: entropy threshold -1/equal/+1 boundary。全応答でmagic/version/mode/status/stop/sequence/input/budget/deadline/admitted/executed/prediction/label/cycles/model/build/binding/flags/CRC、UART idle/error、Ibex halted/bus faultを検査する。正常推論cycleはゼロでなくdeadline以下、拒否は0 cycles・拒否sentinelを要求。期待値は固定reference tableと契約値を使い、失敗を隠すためのassertion/期待値変更はしていない。

Quartusでcritical pathだったcap→budgetの除算式を、数式と一致する7-entry literal ROMへ最小修正。前回STA failログは`quartus_attempt1_budget_divider_timing_fail/`へ保持。修正版を再シミュレーションし、Fitter+STAを再実行してからSRAM設定した。

## STA / SDCの限定

この診断トップにUART外部I/Oはない。STAは基板の`CLOCK_50`を50 MHzと仮定した内部同期経路の評価で、個体発振器のppm測定、外部UART electrical timing、完成したボードsignoffではない。`check_timing.rpt`はKEY[0]入力delayなし1件、LEDR[3:0]出力delayなし4件を報告する。LEDには診断用max/min delay制約があるためunconstrained path reportは0だが、外部受信デバイスのtiming signoffを意味しない。reset synchronizer以外への根拠のないfalse pathは追加していない。

Quartus compileは0 errors / 380 warnings（10335×212, 10036×89, 10766×74, 10230×4, 292013×1）。attribute / unused object /既存RTL warningを保存。警告を隠していない。Fitter/Timing Analyzer/Design Assistantは成功。

## 再実行と根拠ファイル

- Simulation: `run_soc_sim.sh`; CWD `/mnt/d/rtnn_de0cv_c1_autonomous_selftest_20261110/sim`; Verilator `--binary --timing`; compile/run logsは`sim_run_attempt3/`。
- Quartus: CWD `D:\rtnn_de0cv_c1_autonomous_selftest_20261110\quartus`; `quartus_sh.exe --flow compile rtnn_de0_cv`; exit 0。詳細report再生成は`quartus_sta.exe -t timing_review.tcl`; exit 0。
- Bitstream SRAM設定: `quartus_pgm.exe -c "USB-Blaster [USB-0]" -m JTAG -o "p;D:\rtnn_de0cv_c1_autonomous_selftest_20261110\quartus\rtnn_de0_cv.sof@1"`; exit 0。
- Quartus出力、最新STA各種、Fitter pin report、SOF、simulationログ、programmer/JTAGログ、各SHA256 manifestは本ディレクトリ以下に保存。
- `source_sha256.txt`にflat Ibex、SoC、checker、packet engine、testbench SHA-256を記録。Quartus、native simulation、sv2v retryのtop/checker/packet engine/flat Ibex/RAM lane SHA一致。native/sv2v testbenchとQ15 oracle SHA一致。Quartusで使ったflat Ibex SHAは従来C1 flat SoCと一致。
- repositoryのtracked source変更なし。commit/push/PRなし。旧失敗ログや元資材を削除していない。

## 実機post-config境界scan（2026-11-10 15:20 JST）

- Quartus 25.1std.0 EDA Netlist Writerで`--bsdl_type=POST_CONFIG`を明示し、`5CEBA4F23C7_post.bsd`を生成。`BOUNDARY_LENGTH=864`。QSF/ SOFは変更なし。既定の`quartus_eda --board_boundary_scan`はpre-config BSDLになるため使わない。
- JTAG APIはSAMPLE/PRELOAD IR=5、DR長864。読み出し前後にIDCODE IR=6を実行し、両方`02B050DD`。Quartusのhelp説明にはbit順の文言不一致があるが、IDCODE値との照合とpost-config BSDL cell番号で復号。EXTESTは使用していない。SAMPLEだけでFPGA設定・RAM/Flashを書き換えない。
- 復号した出力cells: Y3/LEDR3 cell77=1、W2/LEDR2 cell68=0、AA1/LEDR1 cell71=0、AA2/LEDR0 cell74=0。結果は`1000`で、checkerが全20応答後に出すPASS markerと一致。Terasic DE0-CV User Manual 1.1.2 p.24はLED pin highで点灯と記載（[manual PDF](https://mm.digikey.com/Volume0/opasdata/d220001/medias/docus/5740/DE0_CV_User_Manual_112.pdf)）。境界cellの読戻しに加えて、2026-11-11に利用者がLEDR3のみ点灯（`1000`）を目視確認し、実機表示もPASSと照合した。
- 最初のBSDL生成試行はQSF末尾改行なしで一時行が連結しexit 3。次試行はexit 0だが`--bsdl_type`未指定でpre-configのまま。各ログを保存し、QSFはSHA-256 `f0e0c58cd54aed4ee4e1a20efbfd19130819dca0963ed5e5e9ee8ddadd179655`に復元、SOF SHAも不変を確認。正しいpost-config生成はexit0/0warning。

