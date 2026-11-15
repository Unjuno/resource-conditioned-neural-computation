# C3 v2 Gate B 保存済みQuartus/STA証拠の独立監査

監査日: 2026-11-15  
判定: **内部経路レビューは限定的に確認。B-SIGNOFFはBLOCKED。**  
データ分類: 保存済み成果物の再解析。今回Quartusを起動していない。

## 対象identity

正しいリポジトリのC3 v2 build `43334531`、Quartus Prime Lite 25.1std.0 Build 1129、Cyclone V `5CEBA4F23C7N`を対象にした。元のbuild出力は `D:\rtnn-c3-measurement-v2-quartus-retry02`、リポジトリ内の保全コピーは `C3/evidence/C3_MEASUREMENT_V2_QUARTUS_RETRY02_20261115/`、STA再試行03は `C3/evidence/C3_MEASUREMENT_V2_STA_RETRY03_20261115/`。

| 成果物 | SHA-256 |
|---|---|
| SOF | `85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d` |
| QSF | `0d1f4e375c12526acab789112882defe903c2044009ea051ad4a2537eddbdebe` |
| SDC | `ceaaa6708f0ed8f6d2c1443b60d9511c51d21f96ddaf914117ee6a65410c82eb` |
| Quartus flat RTL | `7c0675a6b2862c6db68f8ec1c0ceb517161389e0a3a64c7cf3bd10f33c4e9bb1` |

保存されたartifact manifestの対象4ファイルは再計算SHAと一致した。QSFのbuild ID、対象deviceも一致する。STAログは4 operating corners、Quartus成功・exit 0を記録する。ただし、ここで再実行したのは下記Pythonのレポート検査であり、Quartus compileやSTAを再実行したわけではない。

## 独立して照合した結果

| 項目 | 保存ログとの照合 |
|---|---|
| Corner 0 `7_slow_1100mv_85c` | 報告された上位20 setup/hold pathで0違反、worst slack +1.803 / +0.259 ns |
| Corner 1 `7_slow_1100mv_0c` | 報告された上位20 setup/hold pathで0違反、+1.887 / +0.242 ns |
| Corner 2 `MIN_fast_1100mv_85c` | 報告された上位20 setup/hold pathで0違反、+10.027 / +0.134 ns |
| Corner 3 `MIN_fast_1100mv_0c` | 報告された上位20 setup/hold pathで0違反、+11.154 / +0.124 ns |
| Request bundled-data route | 4 cornerすべて800/800 index一意。最大route delay 3.323, 3.186, 2.183, 1.891 ns |
| Response bundled-data route | 4 cornerすべて480/480 index一意。最大route delay 3.633, 3.521, 2.373, 2.050 ns |
| `set_net_delay`画面値 | request/response双方16 ns。観測最大route delayは上記画面値未満。これはSDC内の経験的screenで、外部仕様から導出した保証値ではない |
| Unconstrained paths | clocks 0、illegal clocks 0。ただしTDI/TMS入力2 ports・各setup/hold 41 paths、TDOとLEDR[0/1/3]出力4 ports・各setup/hold 8 pathsが未制約 |
| Design Assistant | Critical 0、High 0、Medium D102 16。D101/D102のQSF抑制指定なし |

TimeQuestの`altera_reserved_tck` 30 MHzはHDL/IPに埋め込まれたモデル上のclockであり、DE0-CV USB-Blasterの実出力を測定した値でも、Terasicのboard/cable timing保証でもない。現行SDCにはTDI/TMS `set_input_delay`、TDO `set_output_delay`がない。Cyclone Vのdedicated JTAG pin要求だけでは、基板上のUSB-Blaster/MAX II/配線経路の外部遅延を定められない。

未制約出力のうち`LEDR[0]`, `[1]`, `[3]`はQSFでFPGAのuser LEDへ接続し、RTL上はheartbeat、JTAG応答commit、bus-faultの状態表示に使う。[DE0-CV User Manual](https://www.terasic.com.tw/cgi-bin/page/archive.pl?CategoryNo=163&Language=English&No=921&PartNo=4)はLEDをboard上の表示器として列挙し、外部同期受信デバイスではない。したがってこの3本は外部setup/holdを要する機能データ出力ではなく、人間向け非同期のstatus表示と分類する。ただしTimeQuest UCPカウントとFitterのdrive/slew未指定警告はそのまま可視化し、false pathや合否変更は追加していない。外部JTAG端点TDI/TMS/TDOは機能上必要な通信経路であり、このLED分類では解消されず、signoff blockerとして残る。

2026-11-15の追加静的再照合で、同じ3 LED portとTDI/TMS/TDOをtop RTL・QSF・SDC・TimeQuest UCP reportへ結び直し、保存file hashesと最新status chronologyを機械検査した。LEDはUCP一覧から削除せず、JTAG入力2/41 paths・出力4/8 pathsの報告値も変えていない。C2時代のB-EMPIRICAL BLOCKED記録とC3 v2 build `43334531`のpilot適格`PASS_LIMITED`はbuild/gate scopeが異なる。native 146-source rebuildは依然`NOT_REPRODUCIBLE_YET`。[UCP disposition audit](ucp_disposition_audit_retry01.json)、[再照合記録](UCP_AND_STATUS_CHRONOLOGY_RECHECK_20261115_JA.md)。

AlteraのCyclone V FPGA JTAG入力・出力タイミング表は [Cyclone V Device Datasheet, FPGA JTAG Configuration Timing](https://docs.altera.com/r/docs/683801/current/cyclone-v-device-datasheet/fpga-jtag-configuration-timing?contentId=tHclXha2uF6DJBsBSWaFRA) を参照。仕様表の値はFPGA端点の条件であり、DE0-CV経路全体の制約を補うものではない。

追加でAltera公式 [Quartus Prime Timing Analyzer Cookbook — JTAG Signals](https://docs.altera.com/r/docs/683081/22.2/quartus-prime-timing-analyzer-cookbook/jtag-signals?contentId=HqsgrDMGTE4REitNdjYy5w) を照合した。同cookbookの例はUSB-Blaster IのTCK periodを166.666 ns（6 MHz）とし、USB-Blaster IIを別の24/16 MHz値として扱う。一方、同じ例のTDI/TMS/TDOケーブル遅延定数や波形説明はUSB-Blaster II経路に依存し、同cookbook自身もcable/header traceをユーザーが設定する構造である。DE0-CV回路図の内蔵FT245BL＋EPM240T100 USB-BlasterはUSB-Blaster IIIやIIとは別構成で、cookbookの6 MHz例も本個体のTCK実測や最大値保証ではない。従ってこの資料はSDC値をそのまま移植する根拠にはならず、正しい外部仕様または本個体の測定がまだ必要。

2026-11-15に、Altera公式の[USB-Blaster III timing constraints](https://docs.altera.com/r/docs/864466/current/usb-blaster-iii-fpga-development-cable-user-guide/jtag-timing-constraints-and-waveforms)と[Quartus JTAG constraint procedure](https://docs.altera.com/r/docs/864466/current/usb-blaster-iii-fpga-development-cable-user-guide/creating-jtag-timing-constraints-in-quartus-prime-software)も再確認した。procedureは実際のJTAG setup/device特性に対応したvirtual TCKとmin/max I/O delayが必要とする。波形・数値はUSB-Blaster III向けで、本基板のFT245BL/EPM240T100内蔵経路に適用できない。TDOはtarget perspectiveの出力だが、同ページのTDO例は`set_input_delay`を示すため方向が整合しない。この例を転記せず、実際のポート方向とタイミング視点を確認してから制約する。今回、board-specific値は取得できなかった。追加照合の記録は[`OFFICIAL_GUIDANCE_RECHECK_20261115_JA.md`](OFFICIAL_GUIDANCE_RECHECK_20261115_JA.md)。

## CDC・警告の扱い

当初の保存route report監査ではrequest 800 destination bitとresponse 480 destination bitの対応を確認したが、selector-countのresponse source 484対first-stage destination 480は未解明として残した。その後のSTA-only再実行でsource collection名を全列挙した結果、480 unique logical `(word,bit)` coordinateと4つの`~DUPLICATE` fitter registerに分解できた。各cornerの600-path上限reportは480個の全logical coordinateを対応するdestination indexへ一意にrouteしている。詳細は本節の追加照合と`GATE_B_D102_SELECTOR_RECHECK_20261115`の保存ログを参照。

RTLレビュー上は、request側はsource payloadを同期ACKまで保持し、受信側はtoggle同期後にcapture-pending cycleを挟んでpayloadを捕捉する。response側もpayload commit後にtoggleし、consumeまで保持してからcaptureする。既存RTL回帰はhold-before-ackとcapture payloadを検査する。ただし、これらはCDC形式検証、MTBF証明、全PVT/board timing保証ではない。QuartusのD102 16件は未解決警告のまま扱う。

このhold sequenceの詳細なsource/firmware/testbench/post-fit report対応を[`BUNDLED_DATA_HOLD_SEQUENCE_20261115_JA.md`](BUNDLED_DATA_HOLD_SEQUENCE_20261115_JA.md)に追記した。固定firmwareはresponse commit後にstatus-pollへ戻り、次要求はhost consume後までmailboxが受け付けないため、測定対象sequenceではpayload保持を有限simulationとpost-fit routingで確認できる。一方、SoC側response MMIO storage自体はcommit中の追加CPU書込みをハードウェアで禁止していない。現行firmwareが書かないことに依存するため、この確認を任意のfaulty firmware向けRTL invariantやformal CDC proofとは扱わない。4-corner `set_net_delay` reportは16 ns上限内の実routeを示すが、`report_max_skew`は全cornerで出力なし。観測route delayのmax-min差をformal max-skew制約として読み替えない。

保存compile warning count:

| Quartus warning code | 件数 | この監査での扱い |
|---|---:|---|
| 10036 | 89 | unused assigned signals。多くはflattened Ibex由来だが全件意味確認はしていない |
| 10230 | 4 | 32-bitから6/1/1/7-bitへのtruncation。該当行2894, 2912, 2913, 3717を確認。今回意味的に無害とは認定していない |
| 10335 | 216 | synthesis属性`full_case`/`parallel_case`未認識 |
| 10766 | 76 | 明示defaultを持つcaseで`full_case`属性を無視 |
| 12473 | 3 | “maximum of one processor”関係のcompile warning |
| 13024 / 13410 | 1 / 1 | LEDR[2] GND固定に関するwarning |
| 15714 | 1 | incomplete I/O assignments。FitterはLEDR出力drive/slew設定不足を報告 |
| 292013 | 1 | LogicLockはsubscription版のみ利用可能というwarning |

Warning countと分類は保存ログの棚卸しで、警告の解消や機能無害性の証明を意味しない。特にtruncationと未指定I/O属性は未解決のまま報告する。

### D102 16構造のsource/destination再照合（2026-11-15追記）

保存されたpost-fit Design Assistant reportの16構造を、flat RTL、回帰testbench、4 cornerのroute reportへ独立に対応付けた。再現スクリプトは`C3/source/audit_c3_v2_d102_protocol.py`、JSON出力は`d102_protocol_audit_retry02.json`。Retry01は件数行の空白書式を過剰に固定した監査器の不具合でexit 1となり、失敗ログを保存した。修正版Retry02はexit 0。どちらもQuartus/JTAG/基板を呼び出さない保存資料監査である。

| D102 source | source幅 | synchronizer第1段 | 4 corner route index |
|---|---:|---|---:|
| `req_hold_tck_q` | 800 bit | `req_bus_sync1_sys_q` | 800/800 各corner |
| `response_words_q[0]`〜`[14]`（15語） | 15×32 = 480 bit | `rsp_bus_sync1_tck_q` | 480/480 各corner |

flat RTLと42-case testbenchには、request payloadをACKまで保持する検査、CLOCK_50側capture一致、response commit後の保持、TCK側capture一致、およびJTAG消費までの保持検査がある。これは有限simulationで観測したプロトコル条件であり、全phase/全traceの形式証明、アナログmetastability/MTBF、PVT全域保証ではない。D102は16件ともreportに残り、QSF suppressionsは確認されなかった。

Quartus STA-onlyの追加再実行（2026-11-15）で、元runのresponse selector 484件を新たに列挙し、`~DUPLICATE`付きの4つが論理response bitの複製レジスタであることを照合した。source collectionは480 unique `(word,bit)` coordinatesと4追加instanceからなる。4追加instanceは`response_words_q[1][15]`、`[2][13]`、`[2][22]`、`[2][23]`。4 corner各々で`-npaths 600`を指定して再出力し、実際に480 pathを報告、全480論理座標から同期1段目の同じbit indexへの一意な経路を確認した。各cornerのresponse route reportでは`[2][22]`・`[2][23]`のduplicate instanceが選ばれ、他の2 duplicateは同じ論理bitの通常instanceが選ばれた。従って484対480は**480論理bit＋4 fitter duplicate instances**として説明できた。生ファイルと監査JSONは[`GATE_B_D102_SELECTOR_RECHECK_20261115`](../GATE_B_D102_SELECTOR_RECHECK_20261115/)に保存。

この再解析は保存SOF、QSF、SDC、flat RTL、既存Fitter DBと318 file project copyのidentityを保ち、その複製に対するTiming Analyzerのみを再実行した。Synthesis、Fitter、Assembler、SOF生成、基板操作はしていない。D102は16件とも残り、抑制していない。有限RTL simulationと配線route表は全CDC traceの形式証明、analog metastability/MTBF、外部JTAG timingの保証ではない。外部TDI/TMS/TDO timingは未制約なのでB-SIGNOFFはBLOCKEDのまま。

再現コマンド（repository root、Python 3.11.9）:

```powershell
python artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/source/audit_c3_v2_d102_protocol.py --c3-root artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3 --selector-recheck-root artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/GATE_B_D102_SELECTOR_RECHECK_20261115 --output-json artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/GATE_B_D102_SELECTOR_RECHECK_20261115/<NEW_ID>.json
```

上書きを避けるため、新しい出力IDを使用する。今回の保存出力は`GATE_B_D102_SELECTOR_RECHECK_20261115/d102_protocol_audit_retry03.json`（終了コード0、SHA-256 `2fec69be51023a4ceb270473689b7cfa46310df50c79b152c1c804d4b6da0d32`）。

## 判定と次に必要なもの

* **B-SIGNOFF: BLOCKED。** 未制約TDI/TMS/TDOに適用する、board revisionおよび実際のUSB-Blaster経路に合う外部タイミング仕様がない。公式Cookbook内のUSB-Blaster I 6 MHz例とUSB-Blaster II遅延定数は参考資料だが、本DE0-CV内蔵経路の仕様ではない。上記の内部4-corner reportだけでfull setup/hold signoffとはしない。
* **内部経路証拠: LIMITED PASS。** 保存結果に基づく上位path、bundled-data route index coverage、16 ns screen内route、clock reportを独立集計できた。これは保存レポート監査であり、新規build/runではない。
* **B-EMPIRICAL: 本監査では格上げなし。** 先行する限定pilot適格判定はその範囲に留める。今回の静的報告監査はKEY-reset replayのpending gateも変更しない。
* **禁止する主張:** 完全なboard-level timing signoff、JTAG経路保証、WCET、hard deadline。今回の数値から未校正の実時間を導かない。

2026-11-15に保管済みの公式Terasic System CD ZIPも再ハッシュし、ZIP integrity、1,089 member、選択PDF/SOF/DLL hashを照合した。`.qsf/.qpf/.sdc/.v/.sv/.vhd/.vhdl/.qar`のproject/source text scanではCyclone V以外のdevice assignmentやEPM240/MAX II/USB-Blaster controller termを検出しなかった。これは名前・テキストで調べられる範囲の否定証拠であり、SOF/POF/DLLのbinary reverse engineeringではない。新しい外部JTAG timing値は得られず、BLOCKEDの理由は継続する。[archive recheck](../JTAG_CONTROLLER_PACKAGE_RECHECK_20261115/RUN_RECORD_JA.md)。

### B-SIGNOFFを再開するために必要な証拠

仕様資料の再検索を繰り返さず、次のどちらかの新証拠が得られた時点で再開する。Terasic宛ての既存照会案は `evidence/B_EMPIRICAL_ELIGIBILITY_20261114/TERASIC_SUPPORT_TIMING_REQUEST_DRAFT_EN_C3REV_20261114.md`（未送信）にあり、必要な項目は次の通り。

| 対象 | 現在わかっていること | Gateを閉じるための証拠 |
|---|---|---|
| 実装・適用範囲 | System CD schematicはFT245BL→EPM240T100→Cyclone V経路。今回の個体に適用するPCB revisionは未確認。 | 対象revisionを識別し、そのrevisionに適用する公式controller/board timing特性または検証済みcharacterizationを取得。 |
| TCK | Cyclone V端点は`period >=30 ns`, `high/low >=14 ns`。Altera Cookbookの6 MHzはUSB-Blaster Iの例で、DE0-CV内蔵TCK測定値ではない。board実TCK queryも未取得。 | controllerが保証するmin/max period、high/low（duty）、idle/startup、使用条件。実測で代替する場合は測定系の校正・帯域・probe/loadingと観測条件を記録し、主張範囲をこの個体・観測条件に限定。 |
| TDI/TMS→Cyclone V | FPGA端点setup/hold値は既知。controller launch edgeとboard相対遅延は不明。 | FPGA pinでのTCK基準min/max arrival（またはcontroller/trace budget）とlaunch/capture edge。これからSDCのfall/rise指定とmin/max入力遅延を根拠付きで作る。 |
| Cyclone V TDO→controller | Cyclone V tCO仕様は既知だが、EPM240側capture edge/window/setup/holdとboard skewは不明。 | EPM240受信タイミングとboard path budget、または実際のcapture余裕を示す検証済みcharacterization。これからTDOの出力遅延min/max・基準edgeを設定。 |
| 内部CDC・I/O・STA | 本監査は保存route reportのindexと16 ns内screenを確認。D102=16は残る。外部JTAG I/Oが未制約。 | 根拠が追跡可能なSDCで対象JTAG I/Oを制約し、UCPを再確認。D102のpayload hold/capture/ACK・capture pending・全必要routeを再レビューし、抑制せず個別Dispositionを残す。変更後のFitter、4-corner STA、Design Assistantとhashを同一build identityで保存。 |

外部値を取得できても、既存SDCへ仮値を追記するだけではPASSにしない。新しい制約を使う場合は、同一RTL/SOF buildのsource/config identityを固定した再ビルドと、全必要reportの独立検査が必要。controllerまたはboard PVT保証がない単一個体の実測だけなら、その限定した経験的範囲を明記し、一般的・全条件のsignoffへ拡張しない。

## 再現コマンド

Working directory: repository root  
Python: system `python` (version recorded by the local shell; this script uses only the standard library)  
Quartus/JTAG: 今回は未起動・未接続。

```powershell
$c3 = (Resolve-Path 'artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3').Path
$out = Join-Path $c3 'evidence/GATE_B_C3V2_AUDIT_20261115/audit_reproduced.json'
python (Join-Path $c3 'source/audit_c3_v2_gate_b_saved_reports.py') --c3-root $c3 --output-json $out
```

保存された反復ログでは、retry01/02/03/04は監査器の実装不備を発見し、それぞれ非0で保全。retry05は旧スキーマで成功、retry06は入力manifest識別情報を含む最新スキーマで成功し、exit 0。失敗試行のログを成功試行で上書きしていない。最新のJSONは`audit_retry06.json`、標準出力/終了コードは同名の`.log`/`.exitcode`。実行環境はPython 3.11.9。
