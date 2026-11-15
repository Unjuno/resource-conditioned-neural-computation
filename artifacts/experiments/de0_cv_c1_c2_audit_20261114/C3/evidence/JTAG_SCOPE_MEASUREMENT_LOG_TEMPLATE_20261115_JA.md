# DE0-CV オンボードJTAG 波形測定ログ様式

状態: **TEMPLATE_ONLY / NOT_RUN**  
用途: C3 Gate Bの実測証拠収集用。未記入欄は測定値を意味しない。  
現状: 安全な測定点、実基板revision、SDS1104/probe self-checkが未確認。プローブ接続はまだ行わない。

## A. セットアップ identity

|項目|記入値|単位／書式|
|---|---|---|
|Experiment ID||一意文字列|
|Board model / PCB revision||文字列|
|Board serial / lot||文字列。読取不能なら`UNKNOWN`|
|FPGA device||文字列|
|C3 build ID||hex string|
|SOF SHA-256||64 hex chars|
|FPGA configuration method||SRAM/JTAG等|
|SDS1104 serial||文字列|
|Scope firmware / date-time||文字列 / ISO-8601 + timezone|
|Scope self-calibration date / ambient||ISO-8601 / °C|
|Probe model / serial / attenuation||文字列 / 10X等|
|Probe compensation self-check||PASS/FAIL/NOT_RUN; measured 1 kHz/5 Vpp if observed|
|Board supply source / measured voltage||型式 / V|
|Ambient near board||°C|
|JTAG stimulus/session||Quartus operation, TCK setting evidence, session ID|

## B. 接続・取得条件

接続点は、revision-specific schematic/現物写真の相互照合後に記入する。GPIO/J5をJTAG測定点として扱わない。`R41`の表記だけでは露出テスト点と判断しない。

|Channel|信号|基板上接続箇所の根拠|Probe attenuation|Vertical scale (V/div)|Probe/cable ID|
|---|---|---|---:|---:|---|
|CH1|TCK|||||
|CH2|TDI|||||
|CH3|TMS|||||
|CH4|TDO|||||

|取得条件|値|単位／書式|
|---|---|---|
|Sample rate||Sa/s|
|Record length||samples/channel|
|Timebase||s/div|
|Trigger source / edge / level||CH / rising-falling / V|
|Acquisition mode||normal/peak detect/average等|
|Scope bandwidth limit||MHz or OFF|
|Probe ground reference||場所。全ch共通ground条件を確認|
|Channel deskew / compensation||適用値または`NOT_APPLIED`|
|Threshold definition||V and method (e.g., 50% edge crossing)|
|USB export file / SHA-256||filename / 64 hex chars|
|Screen image / SHA-256||filename / 64 hex chars|

## C. 測定値（各JTAG burst/runごと）

|Burst ID|JTAG operation|TCK edges counted|TCK period min/median/max (ns)|High min (ns)|Low min (ns)|Duty min/max (%)|TDI setup min (ns)|TDI hold min (ns)|TMS setup min (ns)|TMS hold min (ns)|TDO valid / clock-to-output max (ns)|Timeout/error|
|---|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
|||||||||||||

Setup/hold and output delay measurements must use the device-datasheet-defined active/capture edges. Store enough contiguous waveform around every measured edge and retain raw CSV/BMP; summary measurements alone are insufficient for audit.

## D. Measurement uncertainty and disposition

|Contributor|Value / range|Unit|Evidence source / method|
|---|---:|---|---|
|Scope time interval accuracy||ns or ppm||
|Sample interval / interpolation||ns||
|Scope input rise-time / bandwidth||ns / MHz||
|Probe bandwidth / loading||MHz / pF||
|Channel-to-channel skew||ns||
|Threshold / noise contribution||ns||
|Ground lead / connection effect||description||
|VCCIO / voltage dependence||V / ns||
|Repeatability across captures||ns||
|Combined uncertainty model||ns; equation and assumptions||

|Disposition|Value|
|---|---|
|Measured TCK period against `tJCP` (min 30 ns)|NOT_EVALUATED|
|Measured high/low widths against `tJCH/tJCL` (min 14 ns each)|NOT_EVALUATED|
|TDI setup / TMS setup against `tJPSU` (min 1 / 3 ns)|NOT_EVALUATED|
|TDI/TMS hold against `tJPH` (min 5 ns)|NOT_EVALUATED|
|TDO against `tJPCO` (max 11 ns plus VCCIO-dependent increment)|NOT_EVALUATED|
|Observed board-specific result|NOT_RUN|
|Formal Gate B-SIGNOFF|BLOCKED_EXTERNAL_BOARD_TIMING|

Cyclone V endpoint limits are from Table 56 of the [Altera device datasheet](https://docs.altera.com/r/docs/683801/current/cyclone-v-device-datasheet/fpga-jtag-configuration-timing?contentId=tHclXha2uF6DJBsBSWaFRA). The TCK 30 ns minimum has a 167 ns exception for volatile key programming when VCCBAT is 1.2–1.5 V; classify the actual operation before applying limits. `tJPCO` requires a +1 ns increment per VCCIO step below 3.0 V. Do not score a result until applicable board voltage and measurement uncertainty are supported.

The SDS1104's published 1 GSa/s and typical ≤3.5 ns input rise time do not alone provide a defensible uncertainty bound for the 1 ns TDI setup limit. A waveform observation cannot establish corner/lot-wide guarantee, MTBF, WCET, or hard deadline.
