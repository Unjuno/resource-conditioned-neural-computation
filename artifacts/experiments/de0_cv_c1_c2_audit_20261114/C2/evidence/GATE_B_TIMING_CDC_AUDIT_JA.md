# Stage C3 Gate B — C2 timing / CDC / I/O audit

日時: 2026-11-14 JST
正本リポジトリ: `https://github.com/Unjuno/resource-conditioned-neural-computation`
ブランチ: `codex/stage-c3-repro-timing-20261114`
監査対象: C2J2 exact-node D101 disposition build (`build ID 43324a32`)
デバイス: Cyclone V `5CEBA4F23C7N`
Quartus: Prime Lite `25.1std.0 Build 1129` (Windows)

## 判定

**Gate B: BLOCKED。** 4コーナーで50 MHz / JTAG-domain分析と800/384-bit全payload endpointのmax-net-delay検査はpassしており、RTLの2FF＋capture-pending手順には最小3 destination cycleのbundle capture windowがある。詳細chain report上の383件MTBF未計算はpayload経路の自動分類で、実際のreset/control同期器9件は算定済みと判明した。Quartus JTAG cookbookに沿ったSLD hubのTCK非同期clock-group cutは、独立したJTAG/fabric clockを通常の位相同期setup/hold解析に混ぜない設計上の扱いである。内部CDCはheld-data handshake、全bit max-net-delay、2FF control synchronizerのMTBFで評価し、通常の同期clock間setup/holdや有効なskew reportがあるとは主張しない。DE0-CV onboard USB-BlasterのTDI/TMS/TDO外部遅延は未確定である。firmwareの応答source-hold条件は、build ID 43324a32のC main/SoC/mailbox各ソースをSHA照合し、Quartus RAM laneとの一致を確認した静的監査で支持された。ただしこれは物理CDC signoffの代替ではない。Gate B全体とboard-level timing signoffはなお成立していない。

根拠のない `set_input_delay` / `set_output_delay`、false path、クロック緩和は追加していない。保存済みのC2J2 SOF、QSF、SDC、RTLも変更していない。Gate Cは新C3構成では未実施である。

## 対象構成の同一性

この判定の対象は、C2J2 42ケース実機 run record が特定する exact-node D101 disposition 構成である。Gate Aにある `bundled_capture` の別QSF/SOF（SOF SHA-256 `878dd27e...`）を代用していない。

| 入力 | SHA-256 |
|---|---|
| `quartus_d101/rtnn_c2.qsf` | `9d270c2f57ca7f6ee1f68f4d525a685625a7cc5311b0a55ee363e23f823f675e` |
| `quartus_d101/rtnn_de0_cv_c2.sdc` | `8ba18e9829ebb9754278867948a1b0fffb360144738f1c3e45f1650592a87690` |
| `quartus_d101/rtnn_c2_soc_flat.v` | `fdfcdf037eb55225e3e6eef06b01fc92e608951c54ece946461408131f2e5ca7` |
| `quartus_d101/rtnn_c2.sof` | `5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6` |

SOFのSHAは過去のC2J2実機run recordとの同一性確認用であり、この監査ではFPGAへの書込みをしていない。C1、C2J2の既存記録は上書きしていない。

## 制約・STAの再確認

保存済みの `quartus_d101/rtnn_c2.sta.summary`、`c2_allcorners_ucp.rpt`、4コーナーのCDC path report、`c2_postfit_path_audit.json` と run record を照合した。これは保存済みのQuartus結果の再監査であり、今回Quartusを再実行した結果ではない。

| コーナー | setup最悪slack (ns) | hold最悪slack (ns) | request最大net delay (ns) | response最大net delay (ns) |
|---|---:|---:|---:|---:|
| Slow, 1100 mV, 85 C | +0.821 | +0.242 | 3.358 / 16 bound | 3.157 / 24 bound |
| Slow, 1100 mV, 0 C | +0.979 | +0.239 | 3.263 / 16 bound | 3.037 / 24 bound |
| Fast, 1100 mV, 85 C | +9.638 | +0.128 | 2.085 / 16 bound | 2.067 / 24 bound |
| Fast, 1100 mV, 0 C | +10.648 | +0.116 | 1.822 / 16 bound | 1.798 / 24 bound |

50 MHz `CLOCK_50` と、Quartus SLD hubの30 MHz modelである `altera_reserved_tck` が個別に解析されている。ただしSTAレポート中のHDL-embedded SLD hub制約には `set_clock_groups -asynchronous -group {altera_reserved_tck}` がある。このためTCKと他clock間の通常setup/hold解析は非同期group cutの対象である。Quartus JTAG cookbookもJTAG signalsを独立domainとして扱い、default fitter constraintでTCKを30 ns clockとして定義しasynchronous groupにする例を示す。従って表のworst setup/holdは全クロック間CDC signoffを意味しないが、このcut自体は独立クロック間のCDC方式に沿った意図的な扱いである。

SDCの `set_net_delay` はfalse pathではないが、このcutを解除する同期setup/hold制約でもない。指定されたmailbox payload経路の遅延上限だけを補助的に確認する。requestの16 nsは20 ns `CLOCK_50` 周期の0.8倍、responseの24 nsは30 ns JTAG最小周期の0.8倍として設定されている。Quartus path reportとPython監査は4コーナーそれぞれでrequest 800/800 endpoint、response 384/384 endpointを検査し、response payloadのsource collection 394個と384個のdestinationを区別している。これらは経路遅延と端点対応の根拠であり、clock-group cutを埋めるclock phase/skew解析ではない。

同じ保存済みSTAレポートのmetastability summaryは、各cornerで392 chain、うちMTBFを算出できない割合0.977を記録する。詳細再生成レポートで内訳を確認した結果、この383件は `response_words_q[...]` から `rsp_hold_tck_q[...]`、応答shift register、SLD hub TDOへ続くresponse payloadの自動識別chainだった。独立した1-bit synchronizerではないため、0.977という割合のみを「実際の同期器のMTBF coverage不足」と解釈するのは不適切である。残る9件は2つのreset-release chainと7つのscalar control/status toggle chainで、すべてMTBF算定済みかつQuartus Design MTBFに含まれる。Quartus表示 `>1e+09 years` はこの認識された同期器集合の結果であり、payload保持条件や基板外部JTAG timingを保証する値ではない。

2026-11-14に正確なC2J2 Quartus入力を別ディレクトリ `D:\RTNN_C3_GateB_STA_rebuild_20261114` へ複製し、Quartus Prime Lite 25.1std.0 Build 1129で `quartus_sh --flow compile rtnn_c2` を再実行した。QSF/SDC/flat RTLのhashは対象C2J2記録と一致したが、再生成SOFはSHA-256 `15bdd8462f1a2c6fbad92b0ca0df7b2007790aa1d91e275fd6244bbcbc53132` であり、過去の実機SOF `5aa5be2e...` と異なる。このため再生成物は別のbuild artifactであり、過去の42件実機測定に対応するSOFとは扱わない。Fitter/Assembler/STAはexit 0、compile logには392 warningsが記録された。コマンド、終了コード、全warning、build/fit/STA report SHA、再生成SOF SHAは `GATE_B_QUARTUS_REBUILD_RUN_RECORD_JA.md` と `GATE_B_QUARTUS_REBUILD_SHA256_20261114.txt` に残した。31.7 MBの詳細報告と全Quartus生ログ・一時生成物はD:の隔離run領域に保存し、working treeへはQuartus databaseを追加していない。

同じ再構築に対して `report_metastability -nchains 1000` を実行し、全392 chainの詳細を得た。9 chainは2つのreset-release chainと7つのscalar control/status chainでMTBF計算済み（`Included in Design MTBF: Yes`）。残る383 chainは `Not Calculated` / `Included in Design MTBF: No`。その全てはresponse payload source `response_words_q[...]` からJTAG-domain `rsp_hold_tck_q[...]` への自動識別chainとして列挙され、うち381 unique bit pairing（別途2件duplicate alias pathを含む）であった。詳細欄はpayload hold register、shift register、SLD hub TDOまでをchainとして連結する。これはデータ経路を自動検出したQuartus分類で、各payload bitが同期器chainであることを示さない。従ってMTBF summaryの0.977は実際のscalar synchronizerを未計算とする証拠ではなく、MTBF適用対象ではないbundled-data pathを含む分母である。payloadの正しさは別途、RTLのcapture遅延・source hold handshakeと4コーナーの全bit max-net-delayで評価する。再生成レポート全体は31,751,098 bytesでD:の隔離run領域に保存し、レポートSHA-256と抽出した392行chain summaryをrun recordに記録する。コマンド、終了コード、hash詳細は `GATE_B_QUARTUS_REBUILD_RUN_RECORD_JA.md` に保存した。

## Bundled-data capture envelope

build-id `43324a32` のexact flat RTLでは、request toggleをTCKから2段sys同期し、差分検出でcapture-pendingを立て、その次のsys edgeで800-bit busをcaptureする。responseはsys-side commit toggleを2段TCK同期し、差分検出の次のTCK edgeで384-bit busをcaptureする。いずれもsource toggle edgeからcaptureまで最低3つのdestination clock periodを置くRTLである。request source registerはackが往復してから次要求を許可する。応答source-hold条件は、対応するfirmware/SoC/mailbox sourceをSHA照合し、格納されたRAM imageとの一致とRTLのconsume gateを確認した。詳細は `firmware_response_hold_20261114/`。

四コーナーの既存 `set_net_delay` path reportはrequest 800/800、response 384/384のdestinationを網羅し、worst observed net delayはそれぞれ3.358 ns、3.157 ns（slow/85 C）以下だった。比較のための保守的なcapture envelopeを以下に示す。これはsetup slackではなく、最小3 destination periodsからreportされた最大net delayだけを差し引いた比較値であり、clock-to-Q/setup、clock uncertainty、TCK基板source envelopeを含まない。

| 変数 | 意味 | 値・単位 | 定義域・前提 |
|---|---|---:|---|
| `N` | toggle eventからcaptureまでの最小destination edge数 | 3 cycles | exact RTLの2FF同期、差分検出、pending capture順 |
| `Tsys` | sys clock period | 20 ns | QSF/SDCで50 MHz |
| `Ttck_min` | Cyclone V JTAGの最小TCK period | 30 ns | FPGA datasheet上の合法動作下限 |
| `Dreq_net` | request bundleで最悪のpost-fit max net delay | 3.358 ns | 4コーナー最大、800 endpoints |
| `Drsp_net` | response bundleで最悪のpost-fit max net delay | 3.157 ns | 4コーナー最大、384 endpoints |
| `Wreq`, `Wrsp` | capture envelopeからobserved net delayを除いた比較値 | 56.642 ns, 86.843 ns | `N*Tsys-Dreq_net`, `N*Ttck_min-Drsp_net`。setup slackではない |

ここで`N`は無次元cycle数、`Tsys`と`Ttck_min`および各`Dnet`は時間、`W`も時間である。両辺の次元はnsで一致する。なおSDCのrequest 16 ns / response 24 ns上限自体もそれぞれ60 ns / 90 nsの最小capture envelopeより短く、全destinationを指定している。これはbundled-data pathの大きなサイクル余裕を示すが、物理metastability解析やJTAG external I/O timingを代替しない。独立実行した `audit_bundled_capture_envelope.py` は、full reportと392行CSVのSHA、4コーナー全端点、exact flat RTLを照合し、`PASS_BUNDLE_ENVELOPE_ONLY` を出力した。CSV SHA-256は `d11668beeaffde1744313c0275412473550ac5e20221174be7734d082fdc8656`。再現コマンドと結果JSONは `GATE_B_QUARTUS_REBUILD_RUN_RECORD_JA.md` と `bundled_capture_envelope_audit_20261114.json` に保存した。

保存済み4つの `report_max_skew` 出力は `Nothing to report.`。よって有効なskew値は存在せず、skew検証PASSとは扱わない。既存 `c2_postfit_path_audit.json` の `max_skew` false値は、その生成scriptが文字列 `No paths were found` のみを検出し、実出力の `Nothing to report.` と一致しなかった結果である。falseはskew検証成功の意味ではない。

ユーザーSDCの `KEY[0]` からreset release同期段へのfalse pathは、非同期assert・同期releaseのreset回路に限定されている。ユーザーSDC自体にはTCK crossing全体への `set_false_path` はないが、上記のSLD hub embedded asynchronous clock-group assignmentによるeffective cutがある。CDC payloadに対する `set_net_delay` は別途残っている。

## CDCとD101処置

保持データ付きtoggle handshakeの根拠は、保存済みRTL `quartus_d101/rtnn_c2_soc_flat.v`、mailbox source `c3_gate_a_recheck_20261114/rtnn_c2_vjtag_mailbox_final_candidate.sv`、`cdc_capture_regression/RUN_RECORD_JA.md`、Quartus DRC/path監査結果に加え、SHA固定したfirmware/SoC source hold監査 `firmware_response_hold_20261114/` にある。

* requestはTCK側のUpdate-DRで800-bit payloadをhold registerへ固定し、request toggleのみをsys clockへ2段同期する。同期toggle検出後にcapture pendingを経てpayloadをsys側へ取り込む。acceptのackがTCKへ戻るまでhold payloadを更新しない。
* responseはsys側commitでpayloadを固定し、response toggleをTCKへ2段同期する。capture pendingの後に384-bit snapshotを取り込み、全bit scan/consume完了までresponseを保持する。SHA照合したC2 firmwareは48-byte全word書込みの後にcommitし、mailboxは前responseのconsume完了まで新要求を受付けない。4つのfirmware RAM laneとQuartus RAM laneもhash一致するため、この静的source-hold所見はbuild ID 43324a32の格納firmwareに結び付く。
* native SystemVerilogとsv2vのVerilator回帰記録は42要求、reset replay 2件、negative/recovery 7件を含む。response capture edgeのsnapshot一致をprocedural assertionで確認した記録がある。これはRTL simulation evidenceであり、Gate Bの物理CDC証明ではない。
* exact-node buildのDesign Assistant監査JSONはD101 801対象（request 800、response 1 representative）とQSFの局所設定の一致を記録する。global D101/D102/D103はOnのまま。未waivedのraw D101 reportも別フォルダに保全されている。これは限定的な警告処置の記録であって、CDCメタスタビリティの形式証明ではない。

従ってCDCの根拠は、RTL上のheld-data/toggle/ack protocol、4コーナーの全端点max-net-delay監査、protocol capture envelope、native/sv2vの機能回帰、9 scalar synchronizerのMTBFレポート、D101の個別warning dispositionで構成される。request-side hold/ackとresponse-side source stabilityは、exact flat RTL、SHA照合したcapture-pending mailbox、manifest SHAと4 RAM laneが一致するfirmware sourceを併せて確認した。新要求はresponse pending/busy/done中に禁止され、consume後にDONEが同期解除される。ただしこの静的プロトコル監査は形式証明やアナログmetastability解析ではない。Quartusのclock-group cutを考慮した通常のcross-clock phase/skew・setup/hold解析が成立したとは主張しない。

再監査したsaved evidence上では、Fitter、Assembler、Timing Analyzer、post-fit Design Assistantの各実行と補助監査は終了コード0。Quartus compileには392 warningsが残り、warning inventoryは `quartus_d101/QUARTUS_WARNING_REVIEW_JA.md` にある。0 warningsと主張しない。

## 未制約JTAG I/Oと公式根拠

exact-node STAのunconstrained summaryは、input 2 ports / 41 paths（`altera_reserved_tdi`, `altera_reserved_tms`）、output 4 ports / 8 paths（`LEDR[0]`, `LEDR[1]`, `LEDR[3]`, `altera_reserved_tdo`）を示す。LEDRは人が見るstatus出力で同期capture endpointは提示されていないが、I/O electrical assignment warningは残る。JTAG TDI/TMS/TDOは基板内USB-Blaster/FPGA間の外部遅延・受信条件が不明であり、未制約のまま正当なboard-level timing signoffとは言えない。

Terasic DE0-CV回路図はオンボードUSB-Blaster経路にFT245BL U5、MAX II EPM240T100 U13を示すが、CPLD logic image、実搭載speed suffix、PCB上のTCK/data相対遅延・負荷を示さない。一般USB-Blaster I/IIの数値をこの基板のFT245/EPM240経路へ流用しない。Quartus内の `altera_reserved_tck` 30 MHzはSLD hubのモデル値であり、実ボードで測定したTCK値ではない。

quartus資料のJTAG cookbookは、JTAG pathがunconstrainedとして報告され得ることと、TCK/TMS/TDI/TDOの制約値を対象chain/cable構成に応じて決める例を示す。Cyclone V FPGAのdedicated JTAG pin電気・タイミング要件だけでは、ボード上CPLDからFPGAへ届く相対遅延とCPLD側TDO capture要件を確定できない。保存されたFPGA pin窓（TDI -15.682～+4.747 ns、TMS -15.989～+3.325 ns）はfalling-edge launch仮定かつ0-delay STA baselineから逆算した必要条件で、board delayの実測値ではない。TDO output delayも未確定である。

追加調査の生資料を `jtag_timing_research_20261113/` へ複製した。旧ローカルworktreeは読み取り専用のまま、移動・削除・origin変更をしていない。内側の63件SHA manifestはコピー前後で全件一致、manifest自身のSHA-256は `f0b558dea10db382fa4728f55eb44fac469201041c04a7fe202633a49d1f400b`。転送したのは3説明文書と専用研究フォルダのみ（67 files、7,765,409 bytes）。Quartusの巨大な一時DBは含めていない。

Gate Bを解除する残項目は、対象board revisionのオンボードUSB-Blaster経路に対するTCK/TDI/TMSのmin/max相対遅延とTDO受信条件である。Terasic timing envelope、CPLD実装・PCB情報から導いた同等値、またはprobe・校正・帯域・load・edgeを記録した4信号の実測が必要。CPLD部品markingやFPGAのJTAG datasheet値だけでは実装済み回路の相対遅延を確定できない。未送信の問い合わせ文案は同フォルダにある。

## Firmware response source-hold audit

旧作業ツリーを読み取り専用で限定検索し、C2 firmwareとSoC sourceを特定した。各source SHAはcandidate firmware manifestおよび回収済み146-source graphと一致する。対象3 sourceは `firmware_response_hold_20261114/` にbyte-preservingで保存した。firmware image manifestとQuartus exact-flat RAM lane 4本のhashが全て一致し、source所見をbuild ID `43324a32`へ結び付けた。

静的監査結果 `firmware_response_hold_20261114_audit.json` は `PASS_STATIC_IDENTITY_AND_PROTOCOL_ORDER`。mainはrequest copy後にACKし、推論後response wordを書いて最後にcommitする。mailboxは前response pending/busy/done中の次要求を拒否し、384-bit response scan後だけconsume toggleを出し、sys側はconsume同期後にDONEを解除する。この結果、応答source-holdのfirmware条件は本buildについて支持され、Gate BのBLOCKED理由から外した。監査は静的source/identity checkであり、形式証明や物理CDC signoffではない。

## 次ゲート

| Gate | 状態 | 理由 |
|---|---|---|
| A — SV source reproducibility | PASS (限定) | recovered source identityと記録済み回帰の範囲。exact physical C2J2 SOFの再ビルド同一性を主張しない。|
| B — timing / CDC / I/O | **BLOCKED** | Bundle path bound、scalar sync MTBF、静的firmware source-hold根拠は得た。board内JTAG TDI/TMS/TDO外部timing envelopeが未確定。TCK/fabricの非同期関係は意図的にcutし、内部CDCはprotocol/max-delay/MTBFで別評価した。|
| C — 新C3構成の実機42件 | NOT_RUN | Gate B成立前。以前のC2J2 42件記録をC3再試験に代用しない。|
| D — 360入力 campaign | NOT_RUN | 新C3 identityの確定後に実施する。|
| E — 統計解析 | NOT_RUN | 360入力実測campaignが未実施。|
| F — FPGA deadline/WCET | NOT_RUN | RTL固有の上界分析が未着手。|

## 実施記録

* Gate B対象の読み取りcwd: repository root `C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114`。
* 既存Git状態: originは上記正本、branch `codex/stage-c3-repro-timing-20261114`、監査開始HEAD `0bf7421f1ee3358b31ddeb51195a770d8180ac5e`、開始時worktree clean。
* 再確認: PowerShell `Get-FileHash`、`Get-Content`、`Select-String` で保存済み構成、STA/DRC audit JSON、report、run recordを確認。
* 新規証拠コピー: 誤った旧worktree側の調査フォルダを読み取り専用で参照し、PowerShell `Copy-Item` で67ファイルだけ複製。内側SHA manifest検証: 63件、mismatch 0、終了コード0。
* 公式仕様の再確認: Altera documentation web search（2026-11-14 JST）。参照先は下記。
* Quartus再実行、基板書込み、Flash/CFM操作、commit、push、PR、mergeは行っていない。

## 参照資料

* [Quartus Prime Timing Analyzer Cookbook — JTAG Signals](https://docs.altera.com/r/docs/683081/22.2/quartus-prime-timing-analyzer-cookbook/jtag-signals?contentId=HqsgrDMGTE4REitNdjYy5w)
* [Cyclone V Device Datasheet — FPGA JTAG Configuration Timing](https://docs.altera.com/r/docs/683801/current/cyclone-v-device-datasheet/fpga-jtag-configuration-timing?contentId=tHclXha2uF6DJBsBSWaFRA)
* [Cyclone V Device Handbook — I/O Voltage for JTAG Operation](https://docs.altera.com/r/docs/683375/current/cyclone-v-device-handbook-volume-1-device-interfaces-and-integration/i/o-voltage-for-jtag-operation?contentId=~1Gc7noolGTbpSQrK~nXBQ)
* [USB-Blaster III FPGA Development Cable User Guide — Creating JTAG Timing Constraints](https://docs.altera.com/r/docs/864466/current/usb-blaster-iii-fpga-development-cable-user-guide/creating-jtag-timing-constraints-in-quartus-prime-software)
* [Terasic DE0-CV System CD index](https://download.terasic.com/downloads/cd-rom/de0-cv/)
* 対象構成の一次ログ/レポート: `quartus_d101/RUN_RECORD_JA.md`, `quartus_d101/rtnn_c2.sta.rpt`, `quartus_d101/c2_allcorners_ucp.rpt`, `quartus_d101/c2_postfit_path_audit.json`, `quartus_d101/d101_exact_disposition_audit.json`。
* CDC RTL simulation記録: `cdc_capture_regression/RUN_RECORD_JA.md`。
* 追加のJTAG timing一次調査コピー: `jtag_timing_research_20261113/`。
