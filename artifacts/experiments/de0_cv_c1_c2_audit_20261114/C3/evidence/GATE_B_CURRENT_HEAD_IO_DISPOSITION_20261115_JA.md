# Gate B — 現HEADのSDC・未制約I/O対応表

監査日: 2026-11-15 JST  
Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`  
Branch/HEAD: `codex/stage-c3-jtag-pilot-20261114` / `143a4af545b49391b2413751918f7bb515277ae9`  
対象: C3 v2 build `43334531`、DE0-CV / Cyclone V `5CEBA4F23C7N`  
実施範囲: 保存済みQSF・SDC・top RTL・TimeQuest UCP reportの読み取り照合。Quartus再実行、制約変更、JTAG/基板操作なし。

## 入力とハッシュ

| 保存ファイル | SHA-256 |
|---|---|
| `source/measurement_protocol_v2_43334531_20261115/rtnn_de0_cv_c2_top.sv` | `c6d602e252f8e4f472cd79237f241becc9bdecb535d4ceba88d8bfbcecfe3265` |
| `source/measurement_protocol_v2_43334531_20261115/rtnn_c2_vjtag_mailbox.sv` | `7cc0cb69bfddf4309f3b95370ce7c0e06b99e235eb8204b40816f40ff0f719d1` |
| `source/measurement_protocol_v2_43334531_20261115/rtnn_de0_cv_soc_c2.sv` | `0902a2b9db68fbc27c4aa155b5fb43025a46529b519850c78e7386694d6d19af` |
| `evidence/C3_MEASUREMENT_V2_QUARTUS_RETRY02_20261115/rtnn_c3_measurement_v2.qsf` | `0d1f4e375c12526acab789112882defe903c2044009ea051ad4a2537eddbdebe` |
| `evidence/C3_MEASUREMENT_V2_QUARTUS_RETRY02_20261115/rtnn_c3_measurement_v2.sdc` | `ceaaa6708f0ed8f6d2c1443b60d9511c51d21f96ddaf914117ee6a65410c82eb` |
| `evidence/C3_MEASUREMENT_V2_STA_RETRY03_20261115/c3_v2_retry03_unconstrained_paths.rpt` | `d6b1ef57a80ae1bc6ec35d696775bde44e63445c05da0a325ea126fb303f6028` |

## 端点ごとの判定

| 端点 | 保存証拠から分かる用途 | 今の扱い |
|---|---|---|
| `altera_reserved_tdi`, `altera_reserved_tms` | Dedicated JTAG入力。UCP reportは2入力port、41 setup/hold pathを示す。 | 外部コントローラと基板経路のTCK周期/duty、起動条件、launch edge、相対min/max遅延がない。I/O delayやfalse pathを推定で追加せず、B-SIGNOFF blockerとして残す。 |
| `altera_reserved_tdo` | Dedicated JTAG出力。 | 外部capture edge、controller setup/hold、board/cable delayが不明。UCPのまま残し、B-SIGNOFF blockerとする。 |
| `LEDR[0]`, `[1]`, `[3]` | top RTLは`{bus_fault, halted, response_commit, heartbeat_q[25]}`。QSFでそれぞれ`PIN_Y3`, `PIN_AA1`, `PIN_AA2`。 | 基板上の表示用LEDで、外部同期受信器に対するsetup/hold要件は定義されていない。UCP・Fitterの電気属性警告を保持し、false pathで隠さない。 |

保存reportの合計は、setup/hold reportそれぞれで入力2 port・41 path、出力4 port・8 path。出力portはTDOとLEDR 3本であり、LEDの扱いはTDOのcapture条件不足を解消しない。したがって「全I/O制約済み」ではない。

同じbuildの`rtnn_c3_measurement_v2.drc.rpt`（SHA-256 `0b22b4b3a14fbc8a920a69731cc1f73acd7d29ed4b3a35713ac17b76a45e20c0`）を解析し、D102の16構造を対応付けた。Structure 2は`req_hold_tck_q`から`req_bus_sync1_sys_q`への要求bus構造。Structure 1と3–16は`response_words_q[0..14]`の15個の報告source nodeで、すべて`rsp_bus_sync1_tck_q`をsynchronizer nodeとして示す。つまり保存DRCは一方向の単一CDCだけでなく、要求・応答の両方にbundled busのalignment warningを出している。実際のprotocolはデータ保持とcapture/ackを使うため、この警告だけで誤データを断定できない一方、警告は未処置であり、有限シミュレーション・route screenも形式的なCDC証明やMTBF保証ではない。保持の成立根拠と警告処置を監査できる資料が揃うまでは、D102を未解決として残す。

RTLの状態遷移との静的照合では、要求側はTCKの`UpdateDR`で`req_hold_tck_q`を更新してtoggleし、sys側でtoggleを2段同期した後に`req_capture_pending_sys_q`を立て、次サイクルに`req_bus_sync2_sys_q`を`request_data_o`へ捕捉する。データ保持は`request_accept_i`まで継続し、その受理時にack toggleを返す。応答側はSoCが15個の`response_words_q`を更新した後にcommit toggleを出し、TCK側でtoggleを2段同期してからcapture-pending経由で同期bus snapshotを`rsp_hold_tck_q`へ取る。ただしSoC RTLはcommit後の応答wordを独立にwrite-lockしない。応答保持は、固定firmwareが全応答byteを書いてcommitした後に新しい要求までresponse MMIOを書かない制御に依存する。保存済みtestbench assertionsはこの正規firmware sequenceの要求・応答安定性とcapture値一致を検査している。これらはRTL/firmware上の条件確認であり、任意のCPU書込み、全phase/reset interleaving、metastability MTBF、実配置での外部JTAG timingを証明しない。

## 484 selectorから480論理bitへの再照合

STA collectionは応答sourceを484 fitted register instanceとして報告したが、保存済みSTA-only再照合で4個がQuartusの`~DUPLICATE` fitter instance、残る480個がlogical payload coordinateであることを識別し、4 cornerのroute reportで各480 logical bitが対応するfirst-stage bitへ1回ずつ到達することを確認済み。これはbuild `43334531`の同一QSF/SDC/flat-RTL/reportsをhash照合した過去のSTA-only runであり、本作業ではselector recheckを再実行していない。根拠は`evidence/GATE_B_REVALIDATION_CURRENT_WORKTREE_20261115/d102_cdc_audit.json`（SHA-256 `2fec69be51023a4ceb270473689b7cfa46310df50c79b152c1c804d4b6da0d32`）、その`INPUT_SHA256.txt`（11/11件を現在も照合済み）、`SHA256SUMS.txt`（manifest SHA-256 `06b112b8bcf8564268e3cfb12b76f02ae1c0eb638bf989b4afdb9ea14d51151e`、全出力照合PASS）。記録作成時のHEADは`b332ba02ab992227140998a1d67513c690ae17cf`だが、列挙された11入力はすべて現在のHEADでもhash一致した。従って484/480の差は説明済みで、追加の4つの論理payload bitを意味しない。保存`report_max_skew`は“Nothing to report”であり、net-delay max/minのspreadをmax-skew制約結果とは呼ばない。route max delayはrequest/responseの4 cornerでそれぞれ3.323/3.633、3.186/3.521、2.183/2.373、1.891/2.050 ns。16 ns制約は経験的routing screenに留める。

## D102の資料上の意味と限界

Intelの旧Design Assistant handbookはD102を、非同期domain間で同期化されたmulti-bit dataがreceiverで揃わない可能性を示すMedium ruleと説明し、REQ/ACK handshakeがbus全体をsample時に安定させる設計ではdata bit自体の個別同期は不要と説明している。今回のRTLはhandshakeの形とhold意図を持つため、この警告だけから機能不良とは結論しない。一方、同説明は当該配置のreview・waiverを自動承認するものではなく、現行build reportで16件は未waive。保存された`set_net_delay` route coverageは該当経路の配線遅延screenを示すが、到着skewの全条件、非同期captureの安全性、CDC formal/MTBFを代替しない。最新版Quartus ProのTiming Analyzer文書はCDC pathに適切な制約を要し、`set_net_delay`と`set_max_skew`は異なる量を制約すると説明する。Quartus LiteへPro専用機能や制約挙動をそのまま当てはめたとは扱わない。

参考（rule説明と版の範囲を区別）:

* [Intel Quartus II Handbook 9.1, Design Assistant rule D102](https://cdrdv2-public.intel.com/653805/quartusii_handbook_9_1.pdf) — D102の一般的な意図の説明。現行Liteの仕様書とは扱わない。
* [Intel Quartus Prime Pro 25.1, Constraining CDC Paths](https://www.intel.com/content/www/us/en/docs/programmable/683243/25-1/constraining-cdc-paths.html) — CDC経路制約の方法論。Pro専用の制約順位・機能は今回のLite buildへ無検証で外挿しない。

SDCは`CLOCK_50`に20.000 ns clock、clock uncertainty導出、KEY reset同期段への限定false path、request/response bundled-dataの16.000 ns `set_net_delay -max`を記述する。TDI/TMSの`set_input_delay`とTDOの`set_output_delay`はない。16 ns値は内部CDC経路の配置後screenであり、USB-Blasterまたはボードの外部timing保証ではない。

## ゲート判定

* `B-SIGNOFF = BLOCKED_EXTERNAL_BOARD_TIMING_AND_UNCONSTRAINED_IO`。
* `B-EMPIRICAL = PASS_LIMITED`は既存C3 v2 buildと保存済み経験試験の範囲に限定。
* この読み取り照合は新しいSTA結果ではなく、正式signoffやWCET/hard deadline保証を成立させない。
* 次にsignoffを進めるために必要な外部証拠は、当該基板revisionのオンボードUSB-BlasterについてのTCK周期・duty/startup、TDI/TMS launchと相対min/max、TDO capture/setup/hold、電圧・温度条件を示す仕様または適切な測定結果。取得までは同じ資料を再検索せず、このゲートを維持する。

先行する詳細表: `evidence/GATE_B_C3V2_AUDIT_20261115/UCP_AND_STATUS_CHRONOLOGY_RECHECK_20261115_JA.md`。現HEADでの機械監査: `evidence/C3_GATE_B_EVIDENCE_AUDIT_20261115_HEAD143A4AF/RUN_RECORD_JA.md`。
