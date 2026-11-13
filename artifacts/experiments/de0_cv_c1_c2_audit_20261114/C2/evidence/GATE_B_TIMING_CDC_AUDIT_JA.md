# Stage C3 Gate B — C2 timing / CDC / I/O audit

日時: 2026-11-14 JST
正本リポジトリ: `https://github.com/Unjuno/resource-conditioned-neural-computation`
ブランチ: `codex/stage-c3-repro-timing-20261114`
監査対象: C2J2 exact-node D101 disposition build (`build ID 43324a32`)
デバイス: Cyclone V `5CEBA4F23C7N`
Quartus: Prime Lite `25.1std.0 Build 1129` (Windows)

## 判定

**Gate B: BLOCKED。** 保存済み結果では、同一clock group内の50 MHz / 30 MHz-model STAと、指定されたCDC payloadのmax-net-delay検査がpassしている。しかしSLD hubの非同期clock-group cut、Quartus MTBFが算出できない同期チェーンの割合、DE0-CV上のJTAG外部I/Oタイミング未制約が残り、CDC全体とboard-level timingのsignoff条件は成立していない。

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

50 MHz `CLOCK_50` と、Quartus SLD hubの30 MHz modelである `altera_reserved_tck` が個別に解析されている。ただしSTAレポート中のHDL-embedded SLD hub制約には `set_clock_groups -asynchronous -group {altera_reserved_tck}` がある。このためTCKと他clock間の通常setup/hold解析は非同期group cutの対象であり、表のworst setup/holdは全クロック間CDC signoffを意味しない。

SDCの `set_net_delay` はfalse pathではないが、このcutを解除する同期setup/hold制約でもない。指定されたmailbox payload経路の遅延上限だけを補助的に確認する。requestの16 nsは20 ns `CLOCK_50` 周期の0.8倍、responseの24 nsは30 ns JTAG最小周期の0.8倍として設定されている。Quartus path reportとPython監査は4コーナーそれぞれでrequest 800/800 endpoint、response 384/384 endpointを検査し、response payloadのsource collection 394個と384個のdestinationを区別している。これらは経路遅延と端点対応の根拠であり、clock-group cutを埋めるclock phase/skew解析ではない。

同じ保存済みSTAレポートのmetastability summaryは、各cornerで392 synchronizer chain、うちMTBFを算出できない割合0.977、worst available settling time 31.844–32.685 nsを記録する。Quartus表示のworst-case MTBF `1e+09 years`を、算出不能chainを含むdesign全CDCの保証値とは解釈しない。保存レポートは算出不能となった各chainの一覧・理由を十分に示していないため、coverage不足として残す。

保存済み4つの `report_max_skew` 出力は `Nothing to report.`。よって有効なskew値は存在せず、skew検証PASSとは扱わない。既存 `c2_postfit_path_audit.json` の `max_skew` false値は、その生成scriptが文字列 `No paths were found` のみを検出し、実出力の `Nothing to report.` と一致しなかった結果である。falseはskew検証成功の意味ではない。

ユーザーSDCの `KEY[0]` からreset release同期段へのfalse pathは、非同期assert・同期releaseのreset回路に限定されている。ユーザーSDC自体にはTCK crossing全体への `set_false_path` はないが、上記のSLD hub embedded asynchronous clock-group assignmentによるeffective cutがある。CDC payloadに対する `set_net_delay` は別途残っている。

## CDCとD101処置

保持データ付きtoggle handshakeの根拠は、保存済みRTL `quartus_d101/rtnn_c2_soc_flat.v`、mailbox source `c3_gate_a_recheck_20261114/rtnn_c2_vjtag_mailbox_final_candidate.sv`、`cdc_capture_regression/RUN_RECORD_JA.md`、Quartus DRC/path監査結果にある。

* requestはTCK側のUpdate-DRで800-bit payloadをhold registerへ固定し、request toggleのみをsys clockへ2段同期する。同期toggle検出後にcapture pendingを経てpayloadをsys側へ取り込む。acceptのackがTCKへ戻るまでhold payloadを更新しない。
* responseはsys側commitでpayloadを固定し、response toggleをTCKへ2段同期する。capture pendingの後に384-bit snapshotを取り込み、全bit scan/consume完了までresponseを保持する。
* native SystemVerilogとsv2vのVerilator回帰記録は42要求、reset replay 2件、negative/recovery 7件を含む。response capture edgeのsnapshot一致をprocedural assertionで確認した記録がある。これはRTL simulation evidenceであり、Gate Bの物理CDC証明ではない。
* exact-node buildのDesign Assistant監査JSONはD101 801対象（request 800、response 1 representative）とQSFの局所設定の一致を記録する。global D101/D102/D103はOnのまま。未waivedのraw D101 reportも別フォルダに保全されている。これは限定的な警告処置の記録であって、CDCメタスタビリティの形式証明ではない。

従ってCDCの根拠は、RTL上のheld-data/toggle/ack protocol、4コーナーの端点対応付きmax-net-delay監査、native/sv2vの機能回帰、D101の個別warning dispositionで構成される。Quartusのclock-group cutを考慮した完全なphase/skew・metastability解析があるとは主張しない。

再監査したsaved evidence上では、Fitter、Assembler、Timing Analyzer、post-fit Design Assistantの各実行と補助監査は終了コード0。Quartus compileには392 warningsが残り、warning inventoryは `quartus_d101/QUARTUS_WARNING_REVIEW_JA.md` にある。0 warningsと主張しない。

## 未制約JTAG I/Oと公式根拠

exact-node STAのunconstrained summaryは、input 2 ports / 41 paths（`altera_reserved_tdi`, `altera_reserved_tms`）、output 4 ports / 8 paths（`LEDR[0]`, `LEDR[1]`, `LEDR[3]`, `altera_reserved_tdo`）を示す。LEDRは人が見るstatus出力で同期capture endpointは提示されていないが、I/O electrical assignment warningは残る。JTAG TDI/TMS/TDOは外部遅延・受信タイミングが不明であり、未制約のまま正当なboard-level timing signoffとは言えない。

Terasic DE0-CV回路図はオンボードUSB-Blaster経路にFT245BL U5、MAX II EPM240T100 U13を示すが、CPLD logic image、実搭載speed suffix、PCB上のTCK/data相対遅延・負荷を示さない。一般USB-Blaster I/IIの数値をこの基板のFT245/EPM240経路へ流用しない。Quartus内の `altera_reserved_tck` 30 MHzはSLD hubのモデル値であり、実ボードで測定したTCK値ではない。

quartus資料のJTAG cookbookは、JTAG pathがunconstrainedとして報告され得ることと、TCK/TMS/TDI/TDOの制約値を対象chain/cable構成に応じて決める例を示す。Cyclone V FPGAのdedicated JTAG pin電気・タイミング要件だけでは、ボード上CPLDからFPGAへ届く相対遅延とCPLD側TDO capture要件を確定できない。保存されたFPGA pin窓（TDI -15.682～+4.747 ns、TMS -15.989～+3.325 ns）はfalling-edge launch仮定かつ0-delay STA baselineから逆算した必要条件で、board delayの実測値ではない。TDO output delayも未確定である。

追加調査の生資料を `jtag_timing_research_20261113/` へ複製した。旧ローカルworktreeは読み取り専用のまま、移動・削除・origin変更をしていない。内側の63件SHA manifestはコピー前後で全件一致、manifest自身のSHA-256は `f0b558dea10db382fa4728f55eb44fac469201041c04a7fe202633a49d1f400b`。転送したのは3説明文書と専用研究フォルダのみ（67 files、7,765,409 bytes）。Quartusの巨大な一時DBは含めていない。

Gate Bを解除するには、対象board revisionに対してTCK/TDI/TMS間のmin/max相対遅延とTDO受信条件を保証するTerasic timing envelope、またはCPLD実装・PCB情報から同等の数値を導出する資料が必要。代替として、適切なprobe・校正・帯域・load・edge定義を記録したTCK/TDI/TMS/TDO実測が必要である。CPLD部品markingやFPGAのJTAG datasheet値だけでは実装済み回路の相対遅延を確定できない。未送信の問い合わせ文案は同フォルダにある。

## 次ゲート

| Gate | 状態 | 理由 |
|---|---|---|
| A — SV source reproducibility | PASS (限定) | recovered source identityと記録済み回帰の範囲。exact physical C2J2 SOFの再ビルド同一性を主張しない。|
| B — timing / CDC / I/O | **BLOCKED** | FPGA内clock・net-delay検査は保存記録上pass。一方、board JTAG external timingとTDO captureが未確定。|
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
