# DE0-CV JTAG専用電源とTDO遅延条件の照合（2026-11-14）

## 確認できた範囲

1. Cyclone VのTDI/TDO/TMS/TCK専用JTAG pinはbank 3Aの`VCCPD`で給電される。Altera Handbookの「I/O Voltage for JTAG Operation」は3.3/3.0/2.5 Vを列挙する。
2. Terasic DE0-CV System CD v1.2.1の回路図（FPGA power sheet、8/17）では`VCCPD3A`が`VCCIO_PD_3P3`につながり、0-ohm resistor R117/R118が`VCC3P3`と同ネットを接続する。したがって、この回路図版のTDOは3.3 V系である。
3. Altera Cyclone V Datasheet Table 56は`tJPCO`（JTAG TCKからTDO出力まで）のbase maxを11 nsとし、footnoteは3.0 V未満の電圧stepごとに1 nsを加える。上記回路図版の3.3 Vにはdown-step adderは適用されず、端点specは11 ns maxとなる。TDI setup 1 ns、TMS setup 3 ns、JTAG hold 5 ns、TCK period min 30 ns/high・low min 14 nsも同表にある。

## 適用限界

* この結果はDE0-CV System CD v1.2.1回路図の回路条件。ユーザー基板のPCB revisionとR117/R118実装を写真・電圧測定で個体確認してはいない。
* 11 nsはCyclone V pinの端点specであり、DE0-CV上のEPM240経路、基板配線、USB-Blaster回路、USB/host経路の遅延を含まない。
* TCKの実周波数・duty・phase、TDI/TMSのFPGA pin到着時刻、TDOをEPM240側が捕捉するwindowは依然不明。したがってQuartus `set_input_delay` / `set_output_delay`値は推定で埋めない。
* 既存STAのunconstrained TDI/TMS/TDOは未解決であり、Gate Bは**BLOCKED**。Fitter再実行、設計変更、Gate C SOF書込みはこの照合では行っていない。
* USB-Blaster USB-Bを接続したままDC電源を切った操作は、基板回路図上のUSB 5V経路により、完全なFPGA rail power-offを証明しない。JTAG照会で同じdesign hashが見えたことも独立cold bootの証拠にはしない。

## 出典

* Altera Cyclone V Device Handbook, “I/O Voltage for JTAG Operation”: https://docs.altera.com/r/docs/683375/current/cyclone-v-device-handbook-volume-1-device-interfaces-and-integration/i/o-voltage-for-jtag-operation
* Altera Cyclone V Device Datasheet, Table 56 “FPGA JTAG Timing Parameters and Values”: https://docs.altera.com/r/docs/683801/current/cyclone-v-device-datasheet/fpga-jtag-configuration-timing?contentId=tHclXha2uF6DJBsBSWaFRA
* Terasic official DE0-CV System CD archive (v1.2.1 ZIP): https://download.terasic.com/downloads/cd-rom/de0-cv/
* DE0-CV v1.2.1 schematic PDF copy, sheet 8/17; used to read the named nets and R117/R118: https://edu.mmcs.sfedu.ru/pluginfile.php/19909/mod_folder/content/0/DE0-CV_v.1.2.1_SystemCD/Schematic/DE0-CV.pdf?forcedownload=1