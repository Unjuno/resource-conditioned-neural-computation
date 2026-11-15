# OWON SDS1104 — DE0-CV JTAG計測の事前確認

確認日: 2026-11-15  
対象repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`  
branch: `codex/stage-c3-jtag-pilot-20261114`  
確認時HEAD: `143a4af545b49391b2413751918f7bb515277ae9`

## 現在確認できたこと

- ユーザー写真の計測器はOWON SDS1104。メーカー仕様は4チャンネル、100 MHz、最大1 GSa/s。
- WindowsのPnP一覧に`Oscilloscope`（`USB\VID_5345&PID_1234\25040601`）が現れており、スコープのUSBデバイス端子とPC間のUSB接続は列挙されている。
- 同デバイスはWindows Problem Code 28、Problem Status `0xC0000490`で、ドライバーが未導入／起動できず、PCソフトウェアからの波形転送・リモート制御は未確認。測定器の画面上での単体動作とは別の状態。
- 実施コマンド（PowerShell、cwdは上記repository）: `Get-PnpDevice -PresentOnly`および対象InstanceIdに対する`Get-PnpDeviceProperty`。読み取り専用。JTAG転送、SOF設定、信号プローブ接続はしていない。
- OWON Japan公式ダウンロードからSDS1104対応PCソフトZIPを取得し、隔離したTempディレクトリで展開・署名情報を読み取り確認した。ZIP SHA-256: `D7AB7470FF25FBAECC9F109CB60FAFDCE44A27B52D3FE3ACCC356B15D496E888`（85,559,689 bytes）。アーカイブ内に危険な絶対パス／親ディレクトリ参照はなかった。
- 同梱の`OWON_DSO_1.6.33.1.v20250929.exe`はAuthenticode `NotSigned`。USBドライバーは`VID_5345&PID_1234`向けlibusb系INFで、同梱`Instructions.txt`はドライバー用catalogを自己署名生成し、昇格権限でDPInstを実行すると記載する。PCソフトもドライバーも起動・導入していない。Windows署名保護を弱めたり、未署名アプリを実行したりしていない。

## 基板に触れないオシロ／プローブ自己確認

OWON公式マニュアルのFunction Inspectionは、scope front-panelのProbe Compensation出力を約5 Vpp/1 kHzとし、CH1へ10X設定のprobeを接続してprobe tipとground clipをその専用compensation terminalsへ付け、AutoSetで1 kHz/5 Vpp square waveを確認する手順を示す。CH2–CH4も同様に確認できる。これはscope/probeの基本動作確認で、DE0-CVのJTAG timingを測る試験ではない。

実施時はscope前面の`Probe Compensation`/GND端子だけを使い、probe switchとCH menuのattenuationを一致させる。DE0-CV、GPIO、J5には接続しない。このself-checkはこの記録作成時点で未実施。probeが手元にあるか、破損がないかも未確認。

OWON公式ページはSDS1104用マニュアル、PCソフトウェア、PC USBドライバー導入ガイドを配布している。PC接続はUSBデバイス端子を使うデータ／制御経路であり、それだけではオシロの入力チャンネルは基板信号を測定しない。

## PCドライバーなしの波形回収

公式ユーザーマニュアル（pp. 29–32）は、前面USB HostへUSBメモリーを挿し、`Utility → Function: Save → Type: Wave → Source: All → File Format: CSV → Storage: External`で表示中の全有効チャンネルを外部USBへ保存できると説明する。従ってPC側のUSB driver/softwareは波形ファイル回収の必須条件ではない。USBメモリーはUSB 2.0以下、FAT16/FAT32、最大64 GB、allocation unit 4 KB以下が指定されている。既存データ入りUSBのformatは行わない。

この方法で将来波形を得る場合は、CSVとともに画面写真、CH1–CH4の信号名、probe attenuation、vertical scale, timebase, trigger, acquisition mode、scope self-calibration/ambient stateを記録する。今はプローブ接続点が未確認なので、CSV取得・波形測定は未実施。

空のセットアップ・波形・不確かさ様式を[DE0-CV JTAG scope measurement log template](JTAG_SCOPE_MEASUREMENT_LOG_TEMPLATE_20261115_JA.md)に用意した。これは入力フォームのみで、物理波形やPASSを含まない。

## DE0-CV上の計測点について

DE0-CV回路図のUSB-Blasterシートでは、USB FIFOからEPM240 CPLDを経てCyclone Vの専用JTAG端点へ信号が接続される。基板写真に見える`J5 CPLD ISP`はCPLDのISP用ヘッダーで、Cyclone Vに向かうオンボードUSB-BlasterのJTAG出力を取り出す計測ヘッダーとしては記載されていない。GPIO0/1ヘッダーもこのJTAG経路ではない。

回路図Sheet 7にはBST_TCK経路上に`R41 0 Ω DNI`の部品位置が描かれている。ただし、これは専用test point指定ではなく、該当revisionの実装有無・基板上の実位置・露出状態を現物照合できていない。TDI/TMS/TDOに同等の明示test pointも確認できていない。よってR41 footprintを現時点で安全な測定端子と断定せず、GPIOへの配線、J5へのジャンパ、IC脚へのプローブ当てを案内・実施しない。QFPの隣接脚へ一般的なプローブを当てると滑って短絡させるおそれがあり、ユーザー操作による無加工計測の接続点として確認できていない。

OWON SDS1104公式マニュアルは、オシロを電源コードの保護接地へ接続してから入力端子を使うよう指示し、4チャンネルは電気的に絶縁されず共通GNDであると警告する（Safety Requirements, PDF pp. 5–7）。従ってGNDクリップを別々の電位へ接続する前提の計測は不可。今回、GNDクリップ・プローブ先端をDE0-CVへ接続していない。

## このオシロで分かる範囲

OWON公式仕様書は帯域100 MHz、入力立上り時間（typical）3.5 ns以下、リアルタイムsampling 1 GSa/s、sampling rate/relay time accuracy ±100 ppmを示す。Cyclone V公式JTAG端点仕様のTDI/TMS setup最小は1 ns/3 nsである。最大samplingでは1 nsあたり1 sampleであり、scope自身の入力立上りも最大3.5 ns仕様なので、TDIの1 ns setup marginをこの装置単独の観測から確証する測定不確かさ・閾値誤差の根拠がない。TMS 3 nsも、測定系のskew/threshold/time-interval uncertaintyを別途見積もらずに適合を証明できない。

従って本装置は、低周波/粗いTCK period・dutyや異常波形の探索には使える可能性があるが、JTAG setup/holdを含むformal signoffの単独根拠としての適格性は未成立。実際のTCK/TDI/TMS/TDOを安全に観測できた場合も、機器のsample interval・rise timeだけではなくprobe loading、channel-to-channel skew、threshold accuracy、voltage/temperature条件を測定不確かさに含める必要がある。

## Gate判定と次に必要なもの

- B-SIGNOFF: `BLOCKED_EXTERNAL_BOARD_TIMING`のまま。有限回の波形観測だけで、電圧・温度・個体差を含む正式保証やWCETを成立させない。
- B-EMPIRICAL: 既存の`PASS_LIMITED`を維持。SDS1104を接続しただけでは、新たなJTAG測定結果は得られていない。
- 今回のJTAG波形測定: `NOT_RUN`。TCK/TDI/TMS/TDO、エッジ時間、duty、相対skewの測定値はゼロ件。
- 安全に進めるには、回路図と基板revisionに照合済みの専用プローブパッド／安全なJTAGブレークアウト、または基板改造を行う熟練者の実装が必要。既存配線を切る・はんだ付けする作業は今回行っていない。
- PC波形取り込みを使う場合は、OWON公式ソフトとドライバーが必要。今回取得したソフト実行ファイルは署名なし、ドライバーは昇格・システム変更を伴うため、今回はどちらも起動・インストールしていない。スコープ本体へUSBメモリーを挿して保存する方法もメーカー資料上用意されているが、基板信号を安全に入力できることが先。

## 参照

- [OWON Japan SDS1104製品ページ（仕様・ダウンロード）](https://www.owon.co.jp/products/sds1104/)
- [OWON Japan ダウンロード（SDS1104マニュアル、PCソフト、USBドライバーガイド）](https://www.owon.co.jp/support/download/)
- [OWON SDS1104公式ユーザーマニュアル](https://www.owon.co.jp/download/01a0bfbf-8a50-7f36-bda2-e67fc75208c9/)
- [OWON SDS1104公式仕様書](https://www.owon.co.jp/download/01a0bfad-5ca7-7294-a1a3-1c37433030d8/)
- [Altera Cyclone V Device Datasheet — FPGA JTAG Configuration Timing](https://docs.altera.com/r/docs/683801/current/cyclone-v-device-datasheet/fpga-jtag-configuration-timing?contentId=tHclXha2uF6DJBsBSWaFRA) — device-endpoint timing; does not supply DE0-CV controller/board delays.
- [Terasic DE0-CV公式ボード資料ページ](https://www.terasic.com.tw/cgi-bin/page/archive.pl?CategoryNo=13&Language=English&No=921&PartNo=4)
- [DE0-CV revision 1.2.1 System CD schematic copy, Sheet 17 (USB Blaster)](https://edu-mmcs.sfedu.ru/pluginfile.php/19909/mod_folder/content/0/DE0-CV_v.1.2.1_SystemCD/Schematic/DE0-CV.pdf?forcedownload=1) — Terasic回路図の写し。公式サイト配布物とのバイト同一性はこの事前確認では検証していない。

この文書は接続準備の記録であり、波形測定、driver install、正式STA、Gate B signoffの証拠ではない。
