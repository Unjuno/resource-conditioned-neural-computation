# Gate B JTAG端点・データシート条件クロスウォーク

日時: 2026-11-14 JST  
基準: 正本リポジトリ `Unjuno/resource-conditioned-neural-computation`、ブランチ `codex/stage-c3-jtag-pilot-20261114`、Quartus Prime Lite 25.1std.0 Build 1129、既存C2 post-fit netlist。

## Cyclone Vデバイス側の公式条件

Intel Cyclone V Device Datasheet の「FPGA JTAG Configuration Timing」表56に示された条件を転記する。時間単位はns。

| 記号 | 意味 | データシート条件 |
|---|---|---:|
| tJCP | TCK周期 | min 30（ただしVCCBAT 1.2–1.5 Vでvolatile key programming時はmin 167） |
| tJCH | TCK high幅 | min 14 |
| tJCL | TCK low幅 | min 14 |
| tJPSU(TDI) | TDI setup | min 1 |
| tJPSU(TMS) | TMS setup | min 3 |
| tJPH | JTAG port hold | min 5 |
| tJPCO | JTAG port clock-to-output | max 11。TDO I/O bank VCCIOが3.0 Vから下がるごとに1 ns加算 |
| tJPZX / tJPXZ | TDO high-Z切替時間 | max 14、同じVCCIO adder規則 |

この表はCyclone V端子で必要なデバイス条件であり、DE0-CVオンボードUSB-Blaster出力のTCK/TDI/TMS相対位相、EPM240出力遅延、PCB相対skew、実際のTCK duty-cycleを与えない。従って、このデータだけから正当なQuartus `set_input_delay` / `set_output_delay`値は決まらない。特にVCCIO adderについて、JTAG TDOの該当電源条件を確認できる資料もこの照合では得ていない。

## 現行ネットリスト上の残存端点

元のSDCを維持し、LEDR[0], LEDR[1], LEDR[3]だけを診断Tcl内で非同期のLED負荷として除外した後の4コーナーUCPレポートを確認した。

- 未制約入力: `altera_reserved_tdi`, `altera_reserved_tms`。合計41入力ポート経路。TDIの中には `rtnn_c2_vjtag_mailbox:u_mailbox|req_shift_tck_q[799]` があり、実験要求データの取り込みそのものに到達する。
- 未制約出力: `altera_reserved_tdo`。5出力ポート経路。送信元には同期FFとSLD JTAG hubのTDOがある。
- 未制約クロックは0だが、Quartusはsetup/hold fully constrainedではないと報告。
- TDI/TMSはJTAG TCKと同期して動く信号であり、これらを一律にfalse pathにするのはVirtual JTAGの実機データ転送経路を制約解析から外すため不適切。

## 根拠不足として残る値

| 必要な設定根拠 | 現時点の状態 |
|---|---|
| 内蔵USB-BlasterのFPGA端子での最小/最大TCK period・high/low幅 | Terasic回路図はFT245BL、MAX II EPM240T100、24 MHz発振器の存在を示すが、JTAG出力分周・波形・保証値を示さない |
| FPGA端子でのTDI/TMS遷移時刻とTCKの相対最小/最大skew | CPLDロジック/プログラム、出力タイミングとboard trace差の資料なし |
| TDOを読む側の実際のcapture edge/setup/hold | 内蔵USB-Blaster側の実装とサンプリング窓が不明 |
| TDOの該当電源条件と負荷 | TDOのVCCIO adderと出力負荷を確定できない |
| Quartus 25.1での実使用TCK設定 | `jtagconfig --getparam 1 JtagClock` は “No parameter named JtagClock” で終了4。実周波数は取得できていない |

IntelのQuartus CookbookにはUSB-Blaster I/II等を想定した数値例があるが、TerasicのDE0-CVオンボードFT245BL/EPM240経路と同一の根拠がないので転用しない。基板上のJTAG通信が過去に成功した事実は機能的資格確認であり、全コーナーSTA用外部遅延の保証ではない。

## Gate判定と必要な一次証拠

Gate BはBLOCKEDのまま。必要なのは、対象基板revisionに一致するTerasicのCPLD設計/保証タイミングとPCB遅延、またはTCK/TDI/TMS/TDOを同一プローブ基準で捕捉した十分な帯域・校正情報付き測定（さらにTDO受信側のcapture窓）である。それらから入力・出力遅延のmin/maxとクロック条件を導き、元SDCとは別の候補SDCで4コーナーSTAと全例外/未制約経路を再監査する。観測だけで未確認の全コーナー保証を置き換えない。

### 一次資料

- Intel, [Cyclone V Device Datasheet — FPGA JTAG Configuration Timing](https://docs.altera.com/r/docs/683801/current/cyclone-v-device-datasheet/fpga-jtag-configuration-timing?contentId=tHclXha2uF6DJBsBSWaFRA), Table 56 と footnotes 75/76。
- Intel, [Quartus Prime Timing Analyzer Cookbook — JTAG Signals](https://docs.altera.com/r/docs/683081/22.2/quartus-prime-timing-analyzer-cookbook/jtag-signals?contentId=HqsgrDMGTE4REitNdjYy5w)。外部TCK/TDI/TMS/TDOの値は設定固有であること、入力データとTCKの立上り/立下り関係を明示。
- Terasic, [DE0-CV official System CD archive](https://download.terasic.com/downloads/cd-rom/de0-cv/)。オンボードUSB-Blaster回路図の参照元。先行読取専用調査では回路図とサンプル一式からMAX II CPLDのRTL/PCB CAD/FPGA端子タイミングを特定できなかった。

## 再現コマンドと保存場所

UCPの原本は `led_endpoint_diagnostic_20261114/ucp_*.rpt`、経路分類とfalse-pathの範囲は `led_endpoint_diagnostic_20261114/led_endpoint_diagnostic.tcl` および `led_endpoint_diagnostic_20261114/led_path_counts.txt`。同期器段間経路は `sync_stage1_to_stage2_20261114/` に保存。どちらも元SDCを変更せず、後者はQuartus CLIのASCII作業パスから読み取り専用実行した。
