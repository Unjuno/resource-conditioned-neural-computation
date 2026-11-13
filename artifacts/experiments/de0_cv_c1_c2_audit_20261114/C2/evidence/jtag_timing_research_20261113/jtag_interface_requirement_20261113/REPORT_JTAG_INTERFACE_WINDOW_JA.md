# C2J2 post-fit JTAG interface window（外部仕様との照合用）

日時: 2026-11-13 JST  
Quartus Prime Lite 25.1std.0 Build 1129  
Target: Cyclone V `5CEBA4F23C7N`, build `43324a32`  
分析DB: `D:\rtnn_c2_d101_disposition_20261113`（Fitter後）

## 目的と限定

Terasic資料から得られないUSB-Blaster CPLD/配線の遅延を推測で補う代わりに、Quartusのpost-fit timing netlistからFPGA側が外部JTAG入力へ要求する相対タイミング窓を逆算した。Quartus JTAGクロックは既存SLD Hub modelの30 MHz（周期33.333 ns、rise 0 ns / fall 16.667 ns）を使用した。

これは**実基板のSTA PASSでも実測値でもない**。TDI/TMSのlaunchをTCK falling edgeとする前提で、分析用Tclだけに`set_input_delay -min 0 -max 0 -clock_fall`を設定してsetup/hold slackを調べた。C2プロジェクトSDC/QSFは変更していない。実際のon-board CPLDが同じ位相で信号を出すか、線路skewがこの窓に入るかは未確認である。TDO受信側のcapture edge/setup/holdはCPLD実装が不明なためここでは数値化していない。

## 外部が満たすべきFPGA側の入力窓

TDIから全JTAG receiver registerまで10 path、TMSから31 pathを`-npaths 1000`で全列挙した。各cornerで0入力遅延モデルにsetup/hold違反はなかった。0-delay基準からのworst slackは、外部入力遅延を追加できるsetup側上限と、外部入力が基準より早く到着できるhold側の余裕を表す。

| Pin | Corner | setup margin at min=0 (ns) | hold margin at max=0 (ns) |
|---|---|---:|---:|
| TDI | slow 1100 mV, 85 C | 4.747 | 15.732 |
| TDI | slow 1100 mV, 0 C | 5.322 | 15.682 |
| TDI | fast 1100 mV, 85 C | 8.188 | 16.208 |
| TDI | fast 1100 mV, 0 C | 9.292 | 16.201 |
| TMS | slow 1100 mV, 85 C | 3.325 | 16.022 |
| TMS | slow 1100 mV, 0 C | 3.959 | 15.989 |
| TMS | fast 1100 mV, 85 C | 7.371 | 16.342 |
| TMS | fast 1100 mV, 0 C | 8.576 | 16.338 |

全4 cornerの最悪値をまとめると、 falling-edge sourceという仮定下でFPGA pinに届く遅延は次の窓を満たす必要がある。

| Pin | `set_input_delay -min` lower bound (ns) | `set_input_delay -max` upper bound (ns) | Critical endpoint |
|---|---:|---:|---|
| TDI | -15.682 | +4.747 | `sld_hub` / JTAG receiver fanout; request shift endpoint単独はsetup margin 10.634 ns |
| TMS | -15.989 | +3.325 | `sld_jtag_hub|irf_reg[1][1]` |

Variables and calculation:

| Variable | Meaning | SI unit | Type / range |
|---|---|---|---|
| `S_setup` | Zero-external-delay baselineでのpost-fit setup slack | s (report converted to ns) | nonnegative in the four reported corners |
| `S_hold` | Zero-external-delay baselineでのpost-fit hold slack | s (report converted to ns) | nonnegative in the four reported corners |
| `Dmax` | TCK falling edgeからFPGA input pinまでの最大相対遅延 | s | require `Dmax <= min_corner(S_setup)` |
| `Dmin` | 同じ基準に対する最小相対遅延 | s | require `Dmin >= -min_corner(S_hold)` |

次元は全て時間（秒）で一致する。表はns表示へ換算した値で、整数化していない。

TMSが30 MHzモデルで最も厳しく、FPGA pinにおけるfalling-edge相対遅延のsetup側余裕は3.325 nsだった。これはboard delay 3.325 nsという測定結果ではない。オンボード経路がこの窓を満たすかはTerasic仕様または校正した測定で照合が必要。実TCKが30 MHz以外、TDI/TMS launch edgeが異なる場合は窓を再計算する。

## TDOとreport_path

既存post-fit netlistのregister-to-`altera_reserved_tdo` datapath delayは、4 cornerで4.456 / 4.279 / 2.674 / 2.459 nsだった。これはFPGA内部のregisterからTDO portまでのdelayだけで、FPGA pinのTDO clock-to-output、board trace、EPM240 input setup/hold、受信edge/phaseを含まない。従ってTDO `set_output_delay`値は導けず、TDO interface timingは未解決のまま。

## 再現コマンドと結果

実行cwd: `D:\rtnn_c2_d101_disposition_20261113`  
実行コマンド: `C:\altera_lite\25.1std\quartus\bin64\quartus_sta.exe -t jtag_all_input_path_count_20261113.tcl`  
終了コード: 0。4 corner全てでTDI 10 setup/10 hold、TMS 31 setup/31 holdを列挙。Quartus Warning 12473（使用可能CPU数の情報/性能警告）1件、Error 0件。  
0-delay baseline Tcl: `jtag_zero_external_input_baseline_20261113.tcl`。詳細path count Tcl/log/exit codeと各cornerのraw `.rpt` を同じフォルダに保管。

先行query `jtag_interface_timing_detail_20261113.tcl` は実際のinput delayを設定せず`report_timing`を行い、setup/hold pathを返さなかった（Quartusコマンド自体はexit 0）。このため0-delay分析専用モデルをTcl内だけに加えてwindowを算出した。先行失敗/空レポートも消さずに保存した。

入力hashはfinal build run recordに記録される。

- QSF: `9d270c2f57ca7f6ee1f68f4d525a685625a7cc5311b0a55ee363e23f823f675e`
- SDC: `8ba18e9829ebb9754278867948a1b0fffb360144738f1c3e45f1650592a87690`
- Candidate SOF: `5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6`（未書込み）

## Gate判定

この報告により、Terasic回答または実測を照合するためのFPGA側TDI/TMS窓を得た。外部回路timingを証明していないためJTAG STA / board timing gateはBLOCKED。TDO timingも未確定。SOFはSRAMへ未設定、Flash/CFM未操作、実機single input/42-case/cycle measurementはNOT_RUN。
