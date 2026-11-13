# Terasic向け USB-Blaster/JTAG timing仕様照会（送信前ドラフト）

このファイルは問い合わせ文案のみ。メールは送信していない。

## 件名

DE0-CV onboard USB-BlasterのCyclone V JTAG timing制約について

## 本文

Terasicサポートご担当者様

DE0-CV基板（Cyclone V `5CEBA4F23C7N`）上に、Quartus Prime Lite 25.1で合成したVirtual JTAGアクセス機能を実装し、JTAGからFPGA内部のIbex/Q15実験入力を与える設計を検証しています。DE0-CV System CDの回路図では、オンボードUSB-BlasterはFT245BL U5とMAX II EPM240T100 U13を経由してFPGAのJTAG信号へ接続されています。

Quartus Timing Analyzerで、FPGA側JTAG TCKは解析されていますが、TDI/TMS入力とTDO出力の外部delayが未制約と報告されます。IntelのJTAG timing cookbookにあるUSB-Blaster I/IIの例は、DE0-CV内蔵FT245BL/EPM240回路と同一である根拠がなく、数値を転用していません。以下の仕様・資料をご提供いただけますでしょうか。

1. DE0-CV board revisionごとのオンボードEPM240T100の完全な注文型番（speed grade/temperature suffixを含む）。
2. オンボードUSB-Blaster用MAX II CPLDの正式な設計ファイルまたは、FPGA側TCK/TDI/TMS/TDOのlaunch/capture位相・出力遅延の保証範囲。
3. FPGA側JTAG端子までのTCK/TDI/TMS/TDO PCB trace遅延、または最大相対skewの仕様値（対応するboard revision）。
4. DE0-CV内蔵USB-BlasterでQuartusから利用されるTCK周波数設定と、許容duty-cycle範囲。
5. 上記内蔵回路に対して推奨されるQuartus SDC（`create_clock`、TDI/TMS `set_input_delay -min/-max`、TDO `set_output_delay -min/-max`）があれば、その根拠資料。

目的は、実搭載回路に即したSTA制約を設定してから、FPGA SRAMへの一時SOF設定とJTAG通信試験を行うことです。EPCS64/Flash/CFMへの書込みは行いません。対象基板のsilkscreen revisionとserial numberは、返信前にこちらで確認して追記します。

よろしくお願いいたします。

## 作成根拠

Terasic公式回路図はCPLDを`EPM240T100`までしか特定せず、完全型番とtiming値を示していない。Intelの公式MAX II表の`tCO`はCPLD単体のclock-to-outputで、TCKとTDI/TMSの相対skewやboard trace遅延ではない。IntelのQuartus JTAG制約例はUSB-Blaster I/IIやUSB-Blaster IIIの別構成の値を使用しているため、そのままDE0-CVへ転用しない。
