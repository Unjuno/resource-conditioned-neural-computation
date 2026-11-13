# RTNN Stage C2 JTAG測定 — 設計境界とゲート状況

成果物ID: `RTNN-C2-JTAG-20261111`
作業ブランチ: `codex/stage-c2-jtag-20261111`

## 最新判定（2026-11-13、exact-node D101 disposition候補）

現行候補は **C2J2 / build ID `43324a32`**。ホスト入口は`host/Invoke-C2J2JtagExperiment.ps1`。使用する凍結CSVは`evidence/c2j2_candidate_20261112/host/c2_cases.csv`で、旧C2J1用の`host/c2_cases.csv`とは区別する。

| ゲート | 状態 |
|---|---|
| C1証跡 | 保全。145件照合PASSは既存監査記録を参照。C2の証明には流用しない。 |
| C2J2 native/sv2v SoC | PASS（既存RTL simulation、各42件・負例7・reset replay 2）。 |
| PC制御・保存結果の独立監査 | PASS（2026-11-13 host mock）。1件→少数→42件の選択、生の失敗応答、CRC/ID/cycle/成果物整合性を検証。 |
| Fresh C2J2 exact-disposition A&S / Fitter / Assembler | PASS（Quartus flow exit 0、392 warnings、対象 `5CEBA4F23C7`、SOF生成）。候補成果物とフルログは`evidence/quartus_d101_exact_disposition_20261113/`。SOF SHA-256 `5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6`。実験qualification時にSRAMへ設定済み（Flash/CFM未操作）。 |
| C2 post-fit Design Assistant | PASS（個別Disposition付き）。0 error、0 warning、0 High violation、341 information-only。グローバルD101/D102/D103はOn。生レポートで確認した801個のD101ノードだけを完全列挙し局所Off。未抑制801件の生レポートは`evidence/quartus_d101_raw_unwaived_20261113/`に保全。 |
| C2 STA / CDC timing | BLOCKED（board timing signoff）。4コーナーのsetup/holdと800 request / 384 response net-delay経路は正の余裕。`report_max_skew`は4コーナーともpathなし。STAはsetup/hold未完全制約を明記し、JTAG TDI/TMS/TDOとLEDR I/Oが未制約。詳細は`evidence/quartus_d101_exact_disposition_20261113/`。 |
| C2J2 実機JTAG qualification | PASS（2026-11-13、凍結42件すべて予測/Exit/cycle検証、cap違反・timeout・欠損0。SRAM再設定後case 2を完全再現）。外部I/O timing signoffや実TCK周波数の証明とは区別。証跡は`evidence/physical_empirical_after_user_scope_20261113/`。 |
| WSLの最新起動／Linux Quartus | WSL2とUbuntu-24.04の起動を再起動後に確認。Ubuntu-22.04は起動timeout。Linux Quartus配布物は公式MyAltera認証が必要で未入手。 |
| C2 SOF生成 / 実機1件 / 実機42件 / 実機reset再現性 | PASS（候補SOF SHAを照合後、USB-Blaster/JTAGでFPGA SRAMへ設定。single/subset/42件、実測Ibex `mcycle`、SRAM再設定後case 2 replay）。Flash/CFM未操作。 |
| 論文campaign定義 | 読み取り専用照合PASS。360入力・13 schedule・予定24,840行、測定はNOT_RUN。 |

今回のJTAGホスト修正・実機42件・再現試験は`evidence/physical_empirical_after_user_scope_20261113/RUN_RECORD_JA.md`、再実行手順は`host/README_C2J2_JTAG_JA.md`、360入力への移行条件は`PAPER_CAMPAIGN_TRANSITION_JA.md`に記録した。ローカル変更は未commit/未push。下記の日付付き過去記録は当時の状態を残す。最新ゲート表を優先し、古いNOT_RUN記述を現状として読まないこと。

WSLの復旧試行と次の作業位置は`RESUME_AFTER_WINDOWS_RESTART_20261113_JA.md`。Windows再起動は未実施で、事前確認が必要。

## 不変条件

- C1の元RTL、SOF、ログ、145件の証跡は読み取り専用で保全する。
- frozen seed-63 Q15、参照データ、Ibexの設定・RAM latencyは変更しない。
- 通信にはVirtual JTAGとSoC内MMIOメールボックスのみを使う。物理UARTもSoC内UARTも使わない。
- 実測前のcycle数を予測・代用しない。mcycle差分はサイクルとして保存し、絶対時間へ変換しない。
- FPGAにはSTAおよびRTLゲート通過後にSOFをSRAM設定する。Flash/CFMは操作しない。

## 方式

TCK側Virtual-JTAG DRは固定長要求（要求sequence、input ID、mode、budget、64 pixel bytes、payload CRC）をCapture/Shift/Updateで受け取る。要求メールボックスはTCK側で安定保持し、toggle同期と2段同期器を通してCLOCK_50側へ通知する。CPUはMMIOから要求を取得し、sequence、CRC、凍結テストベクトルの画素を検査してから既存Q15 runnerを起動する。

CPUの`mcycle`測定区間は、要求・モデル・入力の検証が終わった後、budget ceiling/deadline admissionの計算前に始まり、Q15推論・entropy早期終了・予測選択(argmax)が終わった後に終了する。したがってpolicy admissionとargmaxのCPUコストを含み、wire decode/CRC、MMIO要求コピー、JTAG待ち、応答符号化・転送は含まない。この同じ境界を全modeで使い、方式全体の計算サイクルとして記録する。測定中はホストがJTAGの入力/応答メモリーを変更せず、計算終了後にCPUが応答語をまとめて書き、commitを最後に行う。JTAG側はDONE後に応答をsnapshotして読み出す。READY/BUSY/DONE/ERROR、応答sequence一致、build IDを必須条件にする。

JTAG scan経路とCLOCK_50間は bundled-data toggle CDCとし、データ本体は同期完了まで保持する。応答も同じ保持・toggle方式で戻す。JTAG読出しは推論後のみ許すため、CPU実行中のRAM競合を避ける。

## 42件ベクトル

`host/c2_cases.csv`は既存Stage 2参照結果と固定heldout入力から生成した候補で、21固定＋21 adaptive。生成時に凍結ログとCSVを照合した。旧Simple-Systemのcycle数は機能参照の来歴情報としてのみ扱い、FPGA期待サイクルには使わない。JTAG要求形式へ接続する前に、各ケースへ64 byte画素列とCRCを結合し、参照ラベル・exit・予測値を再検算する。

JTAGの実機要求は100 byte（32 byteの要求frame＋64 byte画素＋4 byte画素CRC、800 bit）に固定する。Virtual-JTAG側はUpdateDRを受理した時点でTCK内pendingを立て、CLOCK_50側のBUSY同期が戻るまで次の要求を拒否する（BUSYの往復同期遅延による二重投入を防ぐ）。SoC結果は12 wordのstaging領域とwritten maskで全word更新を確認し、最後のCOMMITだけで原子的に公開する。ホストtimeout後は協調resetまでmailboxを隔離し、遅延した前要求の応答が次要求へ混入しないようにする。

42件は凍結入力ID 0/24/57それぞれについて、fixed exit 0..6とadaptive cap class 0..6を実行する構成。adaptiveの期待値は既存frozen referenceから再検算した。旧E2E transcriptと現在の予算capでadmitted値が異なるケースはsequence 27/34/41で、旧値6に対して現在のcapは5。実行exitと予測は全件一致。参照を都合よく6へ変更しない。

## ゲート記録（現時点）

| 工程 | 状態 | 根拠・制約 |
|---|---|---|
| C1全成果物ハッシュ監査 | PASS | 145/145一致、0欠落・不一致。`evidence/C1_READ_ONLY_AUDIT.txt`。 |
| Quartus/JTAG識別 | PASS（今回の読み取り専用確認） | Quartus Lite 25.1std.0 Build 1129、USB-Blaster `[USB-0]`、IDCODE `02B050DD` / `5CE(BA4|FA4)`を再確認。GPIOジャンパー取り外し後のread-only `jtagconfig -n`でもchainは見えるがSLD/Virtual-JTAG nodeは列挙されず。C2のmailbox read/write実機確認は未実施。証跡`evidence/current_jtag_after_gpio_remove_20261113/`。 |
| C1自己試験 | PASS（C1限定） | C1はSoC内UART loopback。C2要件のJTAG入力方式を検証した結果とは数えない。 |
| 42件機能参照生成 | PASS（host-side候補） | `host/c2_cases.csv`とmanifest。実機データではない。 |
| 100 byte JTAG request serialization | PASS（host-side） | 42件全件でRTNQ frame CRC、64-byte pixels、pixel CRC、sequence/model/build identityを検査。`tools/audit_c2_case_payloads.py`、exit 0。 |
| C2 mailbox native RTL単体 | PASS（限定） | Verilator 5.020でreset後READY、800-bit要求CDC、384-bit応答、799-bit malformed length ERROR。`evidence/mailbox_smoke_20261112/`。 |
| C2 mailbox sv2v regression | PASS（限定） | sv2v v0.0.13変換→同じtestbenchをVerilatorで実行、nativeと同じPASS。変換後lint警告0。SHA-256 manifest 18項目一致。 |
| C2 Virtual-JTAG→Ibex SoC RTL統合 | PASS（RTL simulation） | `sld_virtual_jtag`信号を模したscanからmailbox、SoC MMIO、固定Ibex、RV32 Q15 firmwareへ接続。UART不使用。実primitiveはQuartus elaborationで確認、実機scan未確認。 |
| SoC native RTL 42件 | PASS（RTL simulation） | Verilator 5.020で146-file graphをネイティブSVビルドし、42/42予測・label・exit一致、各mcycle>0、cap violation 0、reset後case 1再現。`evidence/soc_native_42case_20261112/`。mcycleはシミュレーション値で実機値ではない。 |
| SoC sv2v回帰 42件 | PASS（RTL simulation） | nativeと同一testbench/vectorsをsv2v flat上で42/42＋reset replay PASS。`evidence/soc_sim_sv2v_42case_20261112/`。 |
| mailbox/SoC負例 | PASS（限定） | 799-bit短縮scanをERRORにしCPUへ届けない。SoC bad-frame CRC→BAD_FRAME、duplicate sequence→BAD_REQUEST、busy中reset後READY/再推論はnativeとsv2v双方でPASS。unknown ID、host timeoutは未実施。 |
| Quartus 25.1 Lite device/A&S | FAIL（IP生成がDevice Guardで拒否） | Device `5CEBA4F23C7`とtopを選択、Ibex階層と`sld_virtual_jtag` debug fabricまで到達。`ip-generate.exe`の起動が拒否され`sld_hub:auto_hub`を展開できずexit 3。v2のOOMは別の過去試行。 |
| Quartus Fitter / 全コーナーSTA / Design Assistant（正式C2） | BLOCKED | 正式C2のVirtual-JTAG auto hub生成はDevice Guardで停止。別topのsynth-only診断ではFitter/STA/DAまで実行できたが、JTAG endpointと実ボードI/Oを除外しておりC2 signoffではない。修正版SDC監査でreset例外は認識され、入力未制約は0。診断topのLEDR出力3 pathは未制約のまま。証拠は `evidence/quartus_c2_synthonly_diag_20261112/`。 |
| 実機1件 / 42件 | NOT_RUN | C2 .sofは未生成・未書込み。C1 SRAM診断結果はC2結果に数えない。 |

## 固定Ibex provenanceとC2の差分

C2のFuseSoC由来source listは143 upstream SVにCSA overlayとclock-gate bypass overlayを加えた固定構成を使う。依存graphのSHA-256は`evidence/soc_sim_sv2v_42case_20261112/source_manifest.json`に記録した。C1 canonical flat (`8634e8a7...21b38`) とC2 sv2v flatを比較し、共通するfixed Ibex/prim 126 moduleはコメント・空白を除きすべて一致、欠落・差分0を確認した（`evidence/C2_FIXED_IBEX_MODULE_AUDIT.json`）。古いレビュー記述にあった「C2 listでclock-gate overlayが欠落」という懸念はこの監査で解消した。

UART-free endpointを新設し、TCK側scanからCDC mailbox、SoC MMIO、固定Ibex、凍結Q15 firmwareへ接続した。Quartus v3はtopとIntel `sld_virtual_jtag`を認識したが、Windows Device GuardがIP generatorを拒否してdebug hub elaborationに失敗。primitiveの実機動作は未確認。v2のOOMは別ログとして保持。
## 2026-11-12 C2 SoCシミュレーション結果（最終v4）

- Native SV最終v4: `evidence/soc_native_42case_20261112/` のcompile/run logsとCSV/JSON。最終ログはSHAマニフェスト参照。
- sv2v最終v4: `evidence/soc_sim_sv2v_42case_20261112/`。変換後flatは `rtl/sv2v/rtnn_de0_cv_soc_c2_flat.v`。
- 両方42/42の参照出力一致。`mcycle_sim`はIbex RTLのシミュレーションで観測した値。発振器実周波数・実機cycle数・時間の主張ではない。
- 変更は専用C2ディレクトリに限定し、凍結Q15とC1成果物は変更していない。

## 最終ゲート更新（2026-11-12）

最終v4のRTLテストベンチとソースで再実行し、nativeおよびsv2v双方で42/42ケース一致、Exit/予測/cap確認、シミュレーションmcycle取得、reset後case 1再現を確認した。これはRTLシミュレーションPASSであり、基板測定PASSではない。Quartus v3はDevice Guardが`ip-generate.exe`を拒否し、`sld_hub:auto_hub`を展開できずexit 3。Fitter・全corner STA・Design Assistant未実施。v2のOOM結果は `evidence/quartus_c2_v2_20261112/` に保存している。C2 SOF未生成のため、JTAG mailbox実機 read/write、単一入力、42件、実機cycleはすべてNOT_RUN。`host/run_c2_jtag.tcl`と`host/Invoke-C2JtagExperiment.ps1`は作成したが、実機実行はしていない。C1 SOF/Flashには触れていない。

SoC負例は不正frame CRC、重複sequence、busy中resetをnative/sv2v双方で検証した。未知model/build ID、pixel CRC mismatch、未知input、ホストtimeout/遅延応答の分離試験は未実施。Quartus MapのOOMを解消し、全corner STAを通過するまで実機試験へ進めない。

## 再実行

C1 manifest照合は次で再現できる（repository root、PowerShell）：

```powershell
$base = 'de0cv_setup/stage3_experiments/ibex_csa_2026-11-03/c1_autonomous_selftest_20261110'
foreach ($line in Get-Content "$base/ARTIFACT_SHA256SUMS_20261110.txt") {
  if ($line -match '^([0-9a-f]{64})\s+(.+)$') {
    $actual = (Get-FileHash -Algorithm SHA256 -LiteralPath (Join-Path $base $Matches[2])).Hash.ToLower()
    if ($actual -ne $Matches[1]) { throw "SHA mismatch: $($Matches[2])" }
  } else { throw "Malformed manifest line: $line" }
}
```

この文書は完了報告ではない。最小成功条件（42件全PASS＋各件のFPGA mcycle回収）に達していない。\n
## 2026-11-12追試：Quartus v3と現在のJTAG列挙

- C:空き容量は3.87 GiB、D:空き容量は2027.36 GiB。C:上の作業領域を使わず、同一入力ソースを `D:\rtnn_c2_quartus_v3_20261112` にコピーして再試行した。入力ファイルSHA-256は `evidence/quartus_c2_v3_20261112/INPUT_SHA256SUMS.txt` に保存。
- Quartus Lite 25.1std.0 Build 1129、Cyclone V `5CEBA4F23C7`、top `rtnn_de0_cv_c2_top`。A&SはIbex等の階層と `sld_virtual_jtag` のdebug fabricまで進んだが、Device Guardがベンダー `ip-generate.exe` の起動を拒否し、`sld_hub:auto_hub` の展開に失敗。Quartus終了コード3。今回の停止原因は前回v2のOOMとは異なる。D: v3のpeak virtual memoryは約5349 MB。
- Device Guardを迂回する変更は行っていない。Fitter、全corner STA、Design Assistant、SOF生成は未実行。C2 SOFは存在せず、実機書込みをしていない。
- 今回の読み取り専用JTAG列挙は `quartus_pgm -l` と `quartus_pgm -c 1 -a` がともにexit 0。USB-Blaster `[USB-0]` とIDCODE `02B050DD` / `5CE(BA4|FA4)` を確認。これはJTAGチェーン認識のみで、C2デザインの書込みやmailbox read/write・推論を確認したものではない。
- 生ログ、QSF/SDC、map reportと入力hashを `evidence/quartus_c2_v3_20261112/` に保存。v2のOOM証跡は別フォルダーで維持する。

### Quartus v3 warning分類

386件を生ログから集計し `evidence/quartus_c2_v3_20261112/QUARTUS_WARNING_SUMMARY.txt` に保存した。10036未使用信号89、10230幅切詰め4（未解決レビュー項目）、10335 `full_case`属性未認識216、10766 default付きcaseで属性無視76、12473 processor数の情報1。警告を抑制・合格扱いせず、Fitter未到達のため未監査項目を残す。

### ホストJTAGコーデックのローカル検証

Quartus付属`tclsh.exe`で、実験TclからJTAG呼出し前の純粋なcodec関数を抽出して検証した。バイト順pack/unpack、標準CRC-32チェックベクトル、little-endian u16/u32の5 assertionがexit 0でPASS。FPGA/JTAGアクセスはしていない。初回はテスト用wrapperの改行不足で失敗し、修正して再実行した。両経過は `evidence/host_codec_smoke_20261112/` に保存。
42行の凍結ケース表もTcl `lassign`の27列に合わせて監査した。request 100 byte/800 bit、model/build ID、sequence一意性、executed exit ≤ admitted exitを42行すべて確認。結果は `evidence/host_codec_smoke_20261112/HOST_CASE_TABLE_AUDIT.txt`。

### Device Guard拒否の根拠

Windows Code Integrityログの3077/3033と`Win32_DeviceGuard`を確認した。Code Integrity/UMCI enforcementはいずれも値2（Enforced）。Quartusが呼び出す `ip-generate.exe` はAuthenticode `NotSigned` で、SHA-256 `87a7d36360151c7933b2a8c3974ee9d04da05b7c29f47d9ca2af0861b9c616ab`。イベント3077はEnterprise signing level要件違反を記録し、ポリシーID `{0283ac0f-fff1-49ae-ada1-8a933130cad6}` を示す。IT確認用の構造化証跡と依頼要約は `evidence/quartus_c2_v3_20261112/DEVICE_GUARD_BLOCK_DETAILS.json` と `DEVICE_GUARD_IT_ESCALATION.txt`。ポリシー変更や回避はしていない。Microsoftの状態値説明では値2はEnforced。

### Host runner JSON回帰修正

全42件を通すQuartus Tcl APIモックで、完了時のJSONヘッダー出力が `extra characters after close-quote` で失敗する不具合を再現した。ヘッダーを専用関数で構築し、JSON末尾もTcl bodyを壊さない形で出力する最小修正を実施。修正後は42要求、CSV 42ケース、JSON PASS/42、request byte列一致を確認した。回帰testbenchは `tests/mock_c2_jtag_runner.tcl`。固定期待値を応答として返すmockであり、FPGAやJTAGの実動作、実測サイクルを検証したものではない。証跡の人工cycle値は1000..1041。
Host JTAG runnerのwrong build ID負例もmockで検証し、`deadbeef`を`43324a31`と不一致判定、入力要求0件、JSON `FAIL/count=0`を確認した。実機試験ではない。
ホストrunnerの失敗時raw log記録もtimeout負例で確認した。


### 現行作業ツリーでのホストモック再確認

2026-11-12に作業ツリーの現在の `host/run_c2_jtag.tcl` をQuartus付属 `tclsh.exe` で再実行した。normalは42要求・42行を受けてPASS、wrong build IDは要求送信前に拒否、BUSY固定は60000 poll後に要求1でtimeoutし、raw logにも理由が残ることを確認した。3シナリオすべてハーネス終了コード0。ログは `evidence/host_mock_runner_42case_20261112/current_source_*.log`。全シナリオはホストAPIモックで、JTAGアクセスなし。normal出力のcycle値は人工値であり、FPGA測定ではない。
### 現在の外部状態再確認

2026-11-12 08:02 UTCに読み取り専用で再確認した。Quartus Lite 25.1std.0 Build 1129、Code Integrity/UMCIはともにEnforced (2)、`ip-generate.exe`はNotSignedでSHA-256は `87a7d36360151c7933b2a8c3974ee9d04da05b7c29f47d9ca2af0861b9c616ab`。`quartus_pgm -l` と `quartus_pgm -c 1 -a` はexit 0、USB-Blaster `[USB-0]` とIDCODE `02B050DD` を確認した。JTAG read/writeやFPGA/Flash書込みはしていない。C2のFitter/STAを止めている条件は未解消。生のコマンド出力は `evidence/current_environment_recheck_20261112/`。
### ホスト失敗記録の改善と回帰

ソース確認で、ケーブル検出がcatch範囲外のためFAIL成果物が作られないこと、ケース送信後のtimeoutがraw logにしか残らずCSV/JSONに失敗ケースが出ないことを確認した。runnerを修正し、JTAG接続・case処理・応答検査の実行時失敗を構造化して保存する。タイムアウト要求はCSVに `TIMEOUT`、JSONに `cycles:null` と `cycle_valid:false` を出し、全体の記録行数と完了数を分ける。USB-Blaster未検出時もJSON/raw logを作る。

Quartus付属Tclshでnormal 42件、誤Build ID、BUSY timeout、USB-Blaster未検出の4モックを再実行し、全ハーネスexit 0。normalはJSON PASS/42、timeoutはJSON FAIL・記録1/完了0・cycles無効、未検出はJSON FAIL/0と理由付きraw logを確認。出力JSONの解析も成功。これはホスト制御のモック検証で、JTAG・FPGA上の計測ではない。ログは `evidence/host_failure_rows_20261112/`、テストは `tests/mock_c2_jtag_runner.tcl`。
追加で2件目timeoutを注入し、1件目PASSを残したまま2件目をTIMEOUTとしてCSV/JSON/raw logに記録し、`completed_count=1`、`count=2`となる部分失敗回帰を確認した。4つの基本シナリオと2件目timeout、CSV/JSONの文字列escape assertionはすべてホストモックPASS。最新ログは `evidence/host_failure_rows_20261112/*_v4.log`。テスト修正途中の構文エラー試行（`*_v3.log`）も失敗証跡として保持している。
### 凍結ケース入力のSHAゲート

PC起動ラッパーに、凍結済み `host/c2_cases.csv` のSHA-256が `7016910c20d47ce7c5487cfbec2490e2afcfb755d22f835b2038876e007ab2da` と一致することを、出力ディレクトリ作成およびQuartus STP起動前に検査するPowerShell gateを追加した。正規CSVはPASS、末尾を変更したコピーは別SHAで拒否。ダミー（SOFではない）ファイルと改変CSVを使ったラッパー試験でも、拒否時に出力ディレクトリが作られず、JTAG/STPに到達しないことを確認した。PowerShell AST parseもwrapper/helperとも0件。証跡は `evidence/host_case_integrity_20261112/`。実SOFや基板を使った試験ではない。
### サイクル差分境界と周回ホスト試験

`rtnn_fw_execute`の測定開始は要求decode/CRC/model/input検査後、budget ceiling・admission計算より前。終了はQ15 inferenceとargmax後、応答encode/MMIO公開前。したがってC2 `cycles`はbudget/admission + inference + argmaxのIbex `mcycle`差分であり、JTAG転送・入力検証・応答encodingは含まない。固定21件と適応21件は同じ境界を使う。deadline modeは今回の凍結42ケースに含まず、未校正binding設定で拒否される。

凍結Q15 core/weightsをリンクしたx86-64ホスト試験で、64-bit差分算術周回100と32-bit低位周回64を受理し、0差分と2^32差分をINTERNALとして0 cycleで拒否した。全ケースでcycle callbackを2回だけ呼ぶ。これはスクリプト時計値による差分演算の試験で、RISC-V CSR読出しのatomicity、実機カウンタ、50 MHz timing/実測は証明しない。ログ・入力hashは `evidence/cycle_measurement_host_20261112/`。
### RV32 ELFのcycle reader逆アセンブル監査

ビルド済み `firmware/rtnn_c2_experiment.elf` のSHAが最終manifestの値と一致することを確認し、ELF32/RISC-Vとして `machine_cycles` を逆アセンブルした。実命令列は `csrr mcycleh` → `csrr mcycle` → `csrr mcycleh` → high不一致時に先頭へbranch → return。high-low-highの安定読出し実装を生成済みELFでも確認した。これは命令列監査であり、実機CSR動作・実サイクル・STAを証明しない。証跡は `evidence/cycle_counter_elf_audit_20261112/`。
## 2026-11-12 negative regression expansion (v7)

C2 SoC testbench now also constructs malformed payload CRC, unknown frozen input ID, wrong model ID, and wrong build ID requests, recomputing the RTNQ header CRC after each intended field mutation. The fixed wire definition places model_id at byte 20 and build_id at byte 24. The SoC firmware returns BAD_REQUEST (4) for payload/input rejection and WRONG_ID (3) for model/build mismatch; those are well-formed RTNR responses, so the Virtual-JTAG mailbox ERROR bit is correctly not required. Mailbox ERROR remains for scan/protocol faults.

Native fixed-Ibex RTL and sv2v-flat RTL were rebuilt and rerun in separate v7 directories using Verilator 5.020. Both compile and simulation exit codes are 0. The independent log auditor confirms 42/42 frozen requests, two deterministic reset replays, mcycle_sim>0, prediction/label/admission/execution consistency, no cap violation, and all seven negative/reset scenarios PASS. Evidence and CSV/JSON are in `evidence/soc_native_42case_v7_20261112/` and `evidence/soc_sim_sv2v_42case_v7_20261112/`.

The v5/v6 failed attempts are preserved outside the repository under D:\\rtnn_c2_jtag_20261112; failures exposed a testbench status interpretation error and then incorrect testbench field offsets. These were corrected based on the frozen wire header and the full v7 regression. No expected model outputs or assertions were weakened. This remains RTL simulation evidence only; Quartus Fitter/STA and all physical JTAG measurement gates remain blocked/not run as recorded above.
| SoC native + sv2v regression v7 | PASS (RTL simulation only) | 42 frozen cases × 2, reset replay 2, payload CRC/unknown input/model/build/duplicate/bad-frame/busy-reset negatives all PASS. CSV/JSON and raw logs under `evidence/soc_native_42case_v7_20261112/` and `evidence/soc_sim_sv2v_42case_v7_20261112/`. Cycles are simulated Ibex `mcycle`, not board measurements. |

## Quartus診断（JTAG endpoint除外、C2 signoff対象外）

Device Guardに遮られる`ip-generate.exe`経路の影響を分離するため、D:の一時プロジェクトで固定Ibex/Q15 SoCと同じRAM imageを保ち、topだけを変形した合成・配置診断を実行した。`sld_virtual_jtag`/mailboxを定数入力に置き換えたため、PCから入力できずJTAG試験に使えない。

Quartus Lite 25.1でA&S PASS（5,524 logic cells、2,097,152 RAM bits、3 DSP、385 warnings）、Fitter PASS（2,831 ALMs、2,602 registers、256/308 RAM blocks、3 DSP、4 warnings）、post-fit Design Assistant PASS（0 warnings）となった。仮topの全6 pinsにexact pin locationがなく、Critical Warning 169085とincomplete I/O assignmentがある。

Timing AnalyzerはCLOCK_50=20 nsを解析し、slow 85C setup/hold +0.933/+0.250 ns、slow 0C +0.934/+0.237 ns、fast 85C +9.349/+0.134 ns、fast 0C +10.499/+0.124 ns。Unconstrained Paths Summaryではoutput LEDR[0], LEDR[1], LEDR[3]がsetup/holdとも未制約。JTAG TCK/CDC logicもこのtopにはないため、STAは診断のみでC2 timing PASSに数えない。

診断SOF SHA-256=`73096e28bce19826a4af5b4a1d177770d2533b291c8d45eeb7d9a47c735ec5ac`。書込みはしていない。このSOFをDE0-CVに設定しないこと。正式C2 A&S/Fitter/STA/Design Assistantと実機42件は引き続きBLOCKED/NOT_RUN。

### STA制約監査の訂正（2026-11-12）

18:00 UTC頃に保存した最初の追加監査 (`report_sdc.rpt`、`report_exceptions.rpt`、`ucp.rpt`) は、Tclで`create_timing_netlist`の後にSDCを明示的に`read_sdc`していなかった。このためQuartusが仮の1 ns clockをderiveし、例外なし・KEY[0]入力3 path未制約という誤った診断になった。これらのファイルは失敗した監査手順の証拠として保持し、STA結論には使わない。

修正版は`create_timing_netlist` → `read_sdc rtnn_de0_cv_c2.sdc` → `update_timing_netlist`の順に実行し、同じnetlistから`report_sdc`、`report_exceptions`、`report_ucp`を取得した。コマンドは `quartus_sta.exe -t report_sta_audit.tcl`、cwdは `D:\rtnn_c2_quartus_v4_synthonly_20261112`、終了コード0。Quartus 25.1のレポートは`CLOCK_50` period 20.000 ns、`set_false_path`（`KEY[0]`→`rst_pipe_q[2:0]`）を表示し、Unconstrained Input Ports/Pathsはいずれも0だった。`report_exceptions`は当該reset pathを「Paths will not be analyzed」と示し、直接のsetup/hold timing reportもNo pathsだった。これはSDCに記述した非同期reset例外が認識されたことを示す。

診断topのLEDR[0]、LEDR[1]、LEDR[3]はsetup/holdとも引き続き未制約（各3 output paths）。このsynth-only仮topにはVirtual-JTAG/TCKと実ボードI/O割当てがなく、出力遅延制約も与えていないため、このレポートだけではC2全体のタイミング条件を満たしたとは判定できない。C2正式topのFitter・全corner STA・Design Assistantは引き続きBLOCKED/NOT_RUN。

正式C2 v3の残存`db`も調べたが、Fitter成功データベースはなく、compiler `.cnf`データのみだった。`quartus_sta.exe rtnn_c2 -c rtnn_c2`を`D:\rtnn_c2_quartus_v3_20261112`から実行すると、Quartusは「Fitter failed or was not run」としてexit 3。したがって正式C2の部分データからSTA結果を得ることもできなかった。コマンド記録とログは `evidence/quartus_c2_v3_20261112/quartus_sta_partial_db_probe_v2.log`。前の試行で使った不正な`--read_settings_files`引数のエラーも保存している。

## 現在のJTAG列挙（2026-11-12 18:12 JST）

読み取り専用で `quartus_pgm.exe -l` と `quartus_pgm.exe -c 1 -a` を実行し、ともにexit 0。`USB-Blaster [USB-0]`とIDCODE `02B050DD`（Cyclone V `5CE(BA4|FA4)`）を確認した。これはケーブルとFPGAのJTAG列挙確認のみであり、現在ロード中のSOFやC2 Virtual-JTAG read/writeを検証していない。プログラミング操作は行っていない。生ログは `evidence/current_jtag_readonly_20261112/`。

## 2026-11-12 現行ホストrunner mock再確認

現在の`host/run_c2_jtag.tcl`と凍結`host/c2_cases.csv`をQuartus付属Tcl 8.6.1で再実行した。normal 42件、誤build ID、初回timeout、2件目timeout、USB-Blaster未検出の5 mockシナリオがすべてハーネスexit 0。normalは42要求・CSV 43行・JSON PASS/42。2件目timeoutでは先行PASSを保持し、失敗行をTIMEOUT・`cycle_valid=false`で記録した。wrong-build/no-hardwareは要求送信前に拒否。

SOF SHA入力はmock用placeholder（64個の`a`文字）、返却cycle値1000..1041は人工値である。実JTAG・FPGA・Q15推論・実測cycleを検証していない。コマンド・各出力・source hashesは `evidence/current_host_mock_recheck_20261112/`。

## 2026-11-12再確認：Ubuntu 22.04上でのC2実再実行

WindowsのDevice GuardでQuartus正式C2のIP生成が停止する問題から独立して、Altera Lite 25.1の公式対応OSであるUbuntu 22.04をD:へ新規追加した。既存Ubuntu 24.04は移動・変更しておらず、再起動も不要だった。保存先は `D:\WSL\Ubuntu-22.04\ext4.vhdx`。インストール時と実行後の空き容量、tool path/version/hashは `evidence/current_wsl22_recheck_20261112/toolchain/TOOLCHAIN.json` に記録。

| 工程 | 最新結果 | 根拠 |
|---|---|---|
| Ubuntu 22.04 + Linuxビルドツール | PASS | Verilator 5.020、sv2v v0.0.13、Clang/LLD 18.1.8、GCC 11.4、Git 2.34.1、Make 4.3、readelfを導入。smoke compile/run PASS。 |
| C2 RV32 firmware rebuild | PASS | 固定モデル/weight gate通過。ELF `0e7b97fbe45fd78f1e6dd99d97e3c81e86369081d07469be90215a2993d8b818`、BIN `a5d46ebee3fd638fc51e59e0d49964b8cf5eda4ea284db2077f269b12a1ddd31`、RAM word/lane 5ファイルすべて既存C2成果物とSHA-256一致。 |
| 固定Ibex依存graph | PASS | commit `7b5df75a041affe56e8c235260f98a09b3319008`、source list 146件。全ソースのSHA-256を再記録。 |
| Native SV SoC 42ケース | PASS（RTL simのみ） | compile/run exit 0、42/42参照結果、2 reset replay、bad frame/payload CRC・unknown input/model/build・duplicate sequence・busy resetの7検査を独立チェッカーでPASS。Ibex `mcycle`はシミュレーション値。 |
| sv2v SoC 42ケース | PASS（RTL simのみ） | sv2v再変換flat SHA-256 `636653e389ed27e2b75e7be8203664d7cc3bab3233d9e977d74e8bf9656e28be` は追跡中のflat RTLと一致。Nativeと同じtestbench/入力/検査がPASS。 |
| JTAG mailbox単体 | PASS（RTL simのみ） | 800-bit request、384-bit response、malformed length rejection。Nativeとsv2v双方。 |
| Quartus Linux install/Fitter | NOT_RUN | Quartus Linux配布物がローカルにない。Altera download flowはアカウント認証を要求する。Windows Quartus 25.1は既存のまま。 |
| Windows正式C2 A&S/Fitter/STA/DA | BLOCKED | Windows Code Integrityが未署名 `ip-generate.exe` を拒否。Device Guard回避なし。 |
| C2 SOF・実機JTAG read/write・実機1件/42件 | NOT_RUN | 正式C2 SOFなし。ボードSRAM/Flashへ今回書込みなし。 |

Verilator compile warningはNative 136件、sv2v-flat 208件。全warning logを保存し、`WARNING_REVIEW.txt`で種類・既知の文脈・未解決レビュー項目を記録した。`-Wno-fatal`で警告を隠したり、期待値・assertion・RTLを変更したりしていない。RAMの4 byte lane blocking assignmentは、同一クロックのread captureでsame-port new-data semanticsを保つ記述として意図的に保持している。sv2v flatのUNOPTFLAT 3件は未解決レビュー項目として残し、Quartus signoffの代替にしない。

詳細なコマンド/cwd/終了コード、エラー修正経過、生ログ、入力・出力SHAは `evidence/current_wsl22_recheck_20261112/`。この再実行はC2のホスト/RTL再現性を強化するが、実機JTAG推論・実サイクル・Fitter/STA gateは満たさない。

### 2026-11-12 19:09 JST：JTAG live read-only probe

`quartus_pgm -c 1 --auto` (Quartus Prime Lite 25.1std.0 Build 1129) detected USB-Blaster [USB-0] and Cyclone V IDCODE `02B050DD` (`5CE(BA4|FA4)`), exit 0. `jtagconfig -n` also exited 0 but listed no SLD/Virtual-JTAG nodes. Thus the cable/device chain is present, but the currently configured FPGA exposes no discoverable Virtual-JTAG endpoint; the loaded SOF is not identified. No memory/mailbox operation was attempted and no SRAM/Flash write occurred. Evidence: `evidence/current_jtag_live_20261112_1909/`.

## 2026-11-12：JTAG mailbox protocol hardening and full RTL regression

The follow-up audit found four real protocol defects. Each was reproduced with an assertion failure before changing RTL; the original failing logs and test snapshots are kept beside the passing reruns in `evidence/current_c2_hardening_20261112/`.

| Defect found | Minimal RTL correction | Regression result |
|---|---|---|
| An empty response scan toggled the consume handshake and could clear a later DONE response. | Only toggle consume when a response was actually pending. | Native and sv2v mailbox tests PASS; empty scan is a no-op and a subsequent DONE remains readable. |
| A syntactically valid request could be accepted while sticky ERROR was set. | Gate request acceptance while synchronized sticky or newly detected protocol error is active. | Native and sv2v mailbox tests PASS; post-error request is fail-stopped. |
| TCK reset deassertion was asynchronous. | Add a two-stage TCK-domain reset-release synchronizer with asynchronous assertion. | Included and exercised by native and sv2v mailbox regressions. |
| Response commit could publish a result after writing only part of one or more words. | Track all 48 byte lanes and accept commit only after every byte has been written; clear the mask after commit. | Production SoC response-stager test PASS for partial reject, full commit, and empty recommit reject. |

The fixed response-write guard test was driven through the production SoC bus path, using the full fixed-Ibex source graph and frozen RAM images. The pre-fix test failed specifically because partial byte lanes were accepted; after the fix, compile and run both exited 0. The testbench is `tests/tb_rtnn_c2_response_write_guard.sv`.

| Gate | Result | Evidence and limits |
|---|---|---|
| Mailbox isolated RTL, native SystemVerilog | PASS | 800-bit request / 384-bit response; empty-scan no-op, exact length, malformed-length ERROR and fail-stop. Compile/run exit 0. |
| Mailbox isolated RTL, sv2v | PASS | Same protocol checks after sv2v conversion. Compile/run exit 0. |
| Production response RAM commit guard | PASS | Partial byte write rejected, complete 48-byte result committed, empty recommit rejected. Compile/run exit 0. |
| Fixed-Ibex + frozen Q15 SoC, native RTL | PASS (simulation only) | All 42 frozen cases, two reset replays and seven negative/recovery checks passed. Independent audit also passed. |
| Same fixed-Ibex SoC after sv2v | PASS (simulation only) | Same cases and checks passed. Native and sv2v result CSVs are byte-identical; SHA-256 `91e782930b995095ac4cdb5cc84d4ac95864f669488544b7f16e8c39548b5653`. |
| Warnings | REVIEWED / OPEN ITEMS | Native full-SoC build: 136 warnings. sv2v full-SoC build: 208 warnings, including 3 UNOPTFLAT items. Full logs and warning classes are retained; `-Wno-fatal` did not hide them. No Quartus signoff is inferred. |
| Quartus official C2 compile | BLOCKED | Windows Device Guard blocked unsigned `ip-generate.exe` while generating `sld_hub:auto_hub`. No policy bypass was attempted. |
| Fitter / all-corner STA / post-fit Design Assistant | NOT_RUN | Formal C2 compilation did not reach these stages. The earlier synth-only diagnostic excludes the JTAG endpoint and is not a signoff substitute. |
| C2 SOF / board read-write / physical single case / physical 42 cases | NOT_RUN | No C2 SOF was generated or loaded; no FPGA SRAM or Flash write occurred. Current read-only JTAG enumeration sees the cable and Cyclone V, but `jtagconfig -n` lists no Virtual-JTAG node. |

The 42-case `mcycle` values are Verilator fixed-Ibex simulation values, not physical measurements. No hardware prediction, board cycle count, or absolute execution-time result is claimed. The frozen `host/c2_cases.csv` and frozen model/reference data were not changed. Current C2 source build tag remains `43324a31` (`C2J1`); because no C2 SOF has been emitted, a new versioned build tag must be assigned and its derived request vectors regenerated before a future physical image is approved. The frozen case source must remain immutable.

Reproduction commands, cwd, tool versions, input/source/output hashes, raw logs, independent CSV/JSON audits and failed-before-fix regressions are recorded in `evidence/current_c2_hardening_20261112/`. The current follow-up manifest is `evidence/C2_HARDENING_RUN_MANIFEST_20261112.json`; it supersedes the earlier native/sv2v flat hash in `evidence/C2_FINAL_RUN_MANIFEST.json` for the hardened RTL only.

## 2026-11-12 C2J2 reset-fix candidate follow-up

C2J2 was derived as a separate build (`RTNN-C2-JTAG-20261112-C2J2`, build ID `43324a32`). The frozen C2J1 case table and C1 evidence remain unchanged. The derived 42-case table SHA-256 is `52b7fdae7c465fd4b6409876e258e00fbaad5656e93ad3b9fb79f2f8741aec5d`; its inputs, labels, exits, caps, and request payloads were checked against C2J1.

The first C2J2 Quartus Analysis & Synthesis exposed a real TCK-domain reset coding error (Quartus Error 10200): a reset-release condition appeared in a sequential `if` without being present in the asynchronous event control. Quartus inferred latches and could not elaborate the mailbox. The RTL now separates asynchronous reset assertion (`!trst_ni`) from the synchronized reset-release branch. Native and sv2v mailbox tests pass after the change, and the mailbox/SoC no longer reports those latch or Error 10200 diagnostics.

The corrected C2J2 project elaborated the Virtual-JTAG primitive, mailbox, and SoC, then stopped at automatic `sld_hub:auto_hub` generation because Windows Code Integrity rejected the unsigned Quartus `ip-generate.exe` (Error 112002 / 12154, compile exit 3). The log contains 386 warnings: 216 unrecognized synthesis attributes, 76 ignored `full_case` attributes with explicit defaults, 89 unused-signal warnings, 4 assignment-width truncations, and 1 processor-count notice. The full warning/error log is retained. No policy change or bypass was attempted.

The fixed-Ibex/Q15 SoC passed 42/42 C2J2 requests in both native RTL and the sv2v-flat regression, with two reset replays and the seven negative/recovery checks; independent audits passed. Native and converted result CSVs match at SHA-256 `dd15b0f87e059c7279392ae4e59a647c63f78db5a278572ae34d8046d9cd002e`. These `mcycle` values are simulator observations only.

| Gate | C2J2 result |
|---|---|
| Host payload and fixed references | PASS |
| Clang/LLD RV32 image build | PASS |
| Mailbox native and sv2v RTL | PASS |
| Fixed-Ibex/Q15 native 42-case RTL | PASS (simulation only) |
| Same SoC after sv2v, 42 cases | PASS (simulation only) |
| Quartus Analysis & Synthesis | BLOCKED by Code Integrity at unsigned `ip-generate.exe` |
| Fitter / all-corner STA / Design Assistant | NOT_RUN |
| New C2 SOF | NOT_GENERATED |
| Physical single input / 42-case JTAG experiment | NOT_RUN |
| FPGA Flash / CFM | NOT_TOUCHED |

The build manifest, source graph, case table, firmware, run logs, compile warnings, audit CSV/JSON and both failed and corrected Quartus logs are in `evidence/c2j2_candidate_20261112/`. The full current ledger is `evidence/c2j2_candidate_20261112/C2J2_RUN_MANIFEST.json`. C2J2 does not satisfy the minimum physical-success gate yet.

## 公式Linux版Quartusの代替経路

WindowsのCode Integrity状態は未変更のまま保全した。追加の読み取り専用確認で、Smart App Controlの`VerifiedAndReputablePolicyState=1`、Quartus `ip-generate.exe`の`NotSigned`、SHA-256 `87a7d36360151c7933b2a8c3974ee9d04da05b7c29f47d9ca2af0861b9c616ab`を確認した。Microsoftの案内に個別アプリ例外はないため、保護の全面停止や実行ファイルの差し替えは試さない。

代替としてAltera公式Quartus Lite 25.1 Build 1129 Linux版を確認した。公式OS表はUbuntu 22.04を対応対象としており、既存Ubuntu 22.04 WSL distroは`D:\WSL\Ubuntu-22.04`にある。D:の空きは約2.02 TiB、C:の空きは約3.74 GiB。Quartus LinuxとCyclone V device supportはローカルに未導入で、Altera公式ダウンロードはcustomer sign-inを要求する。インストーラーの未認証ダウンロードは確認できなかった。保存先候補 `D:\rtnn_quartus_lite_25_1_linux` を作成した。

公式Linux配布のBuild 1129本体とCyclone V supportの公開SHA-1、WSLでの動作確認の順序は `evidence/c2j2_candidate_20261112/LINUX_QUARTUS_ALTERNATIVE.md` に記録した。Linux Quartus、最小Virtual-JTAGコンパイル、C2J2 A&S/Fitter/全corner STA/Design Assistant、SOF生成、実機試験はいずれも未実施。公式のOS対応表はWSL2自体の認証を意味しない。Windows ProgrammerへSOFを渡す場合、SHA照合を行い、JTAG USBをWSLから使えるとは仮定しない。

2026-11-12の再確認で`D:\rtnn_quartus_lite_25_1_linux`は空のまま。Altera公式Windows Lite 25.1ページにはCritical Issues and Patchesへのリンクがあるが、今回の参照ではリンク先が404へ転送され内容を確認できなかった。Pro 25.1.1からLite/Cyclone V向け修正を推定しない。詳細は `evidence/c2j2_candidate_20261112/LINUX_QUARTUS_RECHECK_20261112.txt`。公式SHA-1照合・SHA-256記録用に `tools/Verify-QuartusLinuxPayloads.ps1` を追加し、PowerShell AST parseと不足ファイル時のfail-closed動作はPASS。正式ファイルのハッシュ照合は未実施で、C2ゲート状態は変わっていない。

同日、現在のC2J2ソースからVerilator 5.020でmailbox native/sv2v単体と固定Ibex/Q15 SoC native/sv2v 42ケースを別の空D:ビルド領域へ再ビルドした。mailbox双方PASS。SoC双方42/42・7負例・2 reset replay PASS、native/sv2vの結果CSV SHA-256は同一の`dd15b0f87e059c7279392ae4e59a647c63f78db5a278572ae34d8046d9cd002e`。サイクル値はRTL simulationの`mcycle`であり、実機計測ではない。警告136件(native)、208件(sv2v)を分類して全件生ログを保存。詳細と再実行コマンドは`evidence/c2j2_candidate_20261112/current_soc_retest_20261112/RUN_RECORD.md`および`current_mailbox_rerun_20261112/RUN_RECORD.md`。

2026-11-12の読み取り専用再確認でQuartus Lite 25.1 Build 1129、USB-Blaster、JTAG IDCODE `02B050DD`を検出した。IDCODE表示は`5CE(BA4|FA4)`でパッケージまでは確定しない。C2 QSFの選択デバイスは`5CEBA4F23C7`、ビルドIDは`43324a32`。現在のFPGAからC2 Virtual-JTAGノードは列挙されず、SOFロード・SRAM/Flash書込み・推論は行っていない。コマンドと生ログは`evidence/jtag_readonly_recheck_20261112/`。Quartus起動時に非致命のTBB allocator通知あり。

ホスト側の版取り違えを防ぐため`host/Invoke-C2J2JtagExperiment.ps1`を追加した。既存汎用入口の既定はC2J1表（build `43324a31`）のため、新入口はC2J2の固定CSV SHA-256 `52b7fdae7c465fd4b6409876e258e00fbaad5656e93ad3b9fb79f2f8741aec5d`、build ID `43324a32`、42連番を固定検査する。`-ValidateOnly`、正しいSHA受入、誤ったSHA拒否がPASSし、Quartus/JTAG/基板アクセスなし。詳細は`evidence/c2j2_candidate_20261112/current_entrypoint_validation_20261112/RUN_RECORD.md`。

ゴール再開後の独立D:領域でQuartus Lite 25.1 Build 1129 C2J2 compileを再実行した。C2 top、sld_virtual_jtag、SoCのelaboration後、Windows Code Integrity下で`ip-generate.exe`を起動できずError 112002、`sld_hub:auto_hub` Error 12154でA&Sがexit 3、386 warnings。Peak virtual memory 5349 MB。Fitter/STA/DA/SOFは未実施。実行中の監視用PowerShell起動はCoreCLR Out of MemoryとなったがQuartusは継続し、22:09:19に上記エラーで終了。ログと入力hashは`evidence/quartus_retry_after_resume_20261112/`。

Windowsイベントログで原因を直接照合した。2026-11-12 22:09:17のCode Integrity event 3077/3033がQuartus ip-generate.exeをEnterprise signing-level/policy要件未達として拒否。実体はAuthenticode NotSigned、SHA-256 `87a7d36360151c7933b2a8c3974ee9d04da05b7c29f47d9ca2af0861b9c616ab`。証跡は`evidence/quartus_retry_after_resume_20261112/CODE_INTEGRITY_EVENTS.txt`。policy変更・実行ファイル変更はしていない。

C2 cycle差分の境界/overflowテストをUbuntu 22.04 (WSL2)・Clang 14でも再実行しexit 0。uint64 wrap=100、低位32-bit wrap=64を受理し、zero deltaと2^32超過をINTERNAL/cycles=0にすること、全試験でclock callbackをちょうど2回読むことを確認した。これはscripted host callbackで、Ibex CSR/FPGA/JTAG実測ではない。入力SHA・実行ファイル・生ログは`evidence/current_cycle_boundary_recheck_20261112/`。

C2J2固定42ケースでQuartus付属Tclsh 8.6.1のhost runnerモック回帰を再実行。normal、bad-build、timeout、timeout-second、no-hardwareの5シナリオが全てharness exit 0。正常系は42要求・JSON PASS/42、負例はbuild mismatch前要求0、1件目/2件目timeout、無ケーブル要求0。JSONを独立監査し正常42行PASS、負例4件FAILを確認した。cycle値1000–1041およびSOF SHAは合成値。JTAG実機・SOF・Flashは未操作。詳細は`evidence/current_host_mock_recheck_resume_20261112/RUN_RECORD.md`。

## 現行リポジトリ・Quartusゲート再確認（2026-11-12）

ステージ済み変更はC2配下550パスのみで、コミット・pushなし。C2 SHA-256マニフェスト657件は再照合し全件一致した。`git diff --cached --check -- <C2>`はexit 2。3,751行の全文を`evidence/current_repo_gate_recheck_20261112/git_diff_cached_check.log`へ保存した。主な指摘はVerilator生成C++/Make、Quartus生成report/log、およびテンプレート・RTL末尾の空白で、機能試験の結果ではない。生成証跡を変更して警告を隠す処理はしていない。

C:空き8.69 GiB、D:空き1,990.72 GiB。D:のQuartus Linux staging先は空。Ubuntu-22.04 WSL2のPATH確認と`/opt`・`/usr/local`・`/home`限定検索ではQuartus実行ファイルを検出しなかった。Altera公式Lite 25.1ページはCyclone V support package名・公開SHA-1を掲載するが、ダウンロードはログイン必須。Critical Issues and Patchesのリンクは現環境で404へ転送し、署名済み修正は入手できなかった。Windows Code Integrityが未署名`ip-generate.exe`（SHA-256 `87a7d36360151c7933b2a8c3974ee9d04da05b7c29f47d9ca2af0861b9c616ab`）を拒否するゲートは変わらず、A&S後のFitter/STA/DA/SOFおよび実機測定は未実施。`evidence/current_repo_gate_recheck_20261112/`に記録した。

現行JTAG接続の読み取り専用再確認（2026-11-12）ではUSB-Blaster `[USB-0]`とIDCODE `02B050DD`を検出した。C2 Virtual-JTAG nodeは列挙されず、SOF・SRAM・Flash/CFMの操作も推論も行っていない。実行出力と`jtagconfig.exe` SHA-256を`evidence/jtag_readonly_recheck_resume_20261112/`に保存した。

C2J2実機runner入口の現行再確認（2026-11-12）は`-ValidateOnly`でexit 0。凍結CSV SHA、42件、連番1–42、build ID `43324a32`、全payload 100 bytes/800 bitsを検査した。SOFパスは未解決sentinelを指定したが、ValidateOnlyはSOF解決・Quartus・JTAGより前に終了し、ハードウェアアクセスなし。したがってSOF未生成・実機未試験の状態は変わらない。コマンド・出力・入口スクリプトhashは`evidence/current_entrypoint_recheck_20261112/`。

Quartus Virtual-JTAG依存の限定ソース確認（2026-11-12）では、C2 topが`sld_virtual_jtag`を直接使用し、Quartus付属`sld_virtual_jtag_basic.v`がSLD_HUB信号インターフェースを定義することを確認した。C2J2ログの`sld_hub:auto_hub`生成はJTAG endpointに関係する。確認範囲で自動Hubを省略し同機能を保つ公式設定は見つからず、機能を失う疑似迂回は加えていない。入力ファイルhashと調査範囲は`evidence/quartus_vjtag_hub_dependency_20261112/`。


Altera公式Quartus 25.1公開資料の再調査（2026-11-12）では、Error 112002/ip-generate.exeのCode Integrity拒否に対するLite向け修正版や、Virtual-JTAGを保ったままauto_hubを省く設定は特定できなかった。公開release noteは既存Standard版へのpatch一覧とKnowledge Base参照を示すが、Standardの修正をLiteへ適用できる根拠にはならない。Knowledge Baseへの現行リンクは取得環境で利用不能だったため「修正なし」とは断定しない。公式Linux Lite 25.1 Build 1129とCyclone V supportは配布ページにあるがサインインが必要で、ローカルには未配置。出典と限定事項は`evidence/official_quartus_patch_research_20261112/RESEARCH.md`。

## 2026-11-13 追記：Virtual-JTAG TCK global routing candidate

前記のCDC制約付き候補を基に、物理topのVirtual-JTAG TCKをCyclone V `global` primitiveへ通すQuartus候補を一時領域で作成し、Quartus Prime Lite 25.1std.0 Build 1129でA&Sを再実行した。Fitter reportはTCKをGCLK5 global networkへ配置し、TCK clock-enable fanoutにCLKCTRL_G2を使用。post-fit Design AssistantからC105が消えた。A&Sはexit 0、393 warnings、対象device `5CEBA4F23C7`、SOF生成。4コーナーのsummary setup/holdは正で、request 800/800・response 384/384の指定net-delay pathsもbound内だった。

ただしDesign AssistantのD101=801は残存する。通常STAの`report_max_skew`は生成SLD async clock-groupにより対象パスがなく、clock-groupを診断用に除去した別レポート（4,736 paths、violation 0）はsignoff根拠ではない。TDI/TMS/TDOおよびLEDRのI/O制約も未解決。よってC2 STA/CDCとDAゲートはBLOCKEDのまま。この候補のglobal bufferはまだ追跡RTL/QSFへ統合しておらず、候補SOFも未書込み。Flash/CFMは操作していない。候補の全65ファイルは`evidence/quartus_globalprimitive_20261113/`に保存し、SHA-256の照合不一致は0件。malformed newlineによる最初の失敗ログ（exit 130）も保存した。

2026-11-13の再現用global-TCK project `quartus_c2_globaltck/`を追加し、`set_max_skew`行を除いたSDCで同一のquartus compileを再実行した。A&S/Fitter/Assemblerはexit 0。現行証跡`evidence/quartus_globaltck_repro_20261113/`の61項目はSHA照合不一致0。全4コーナーのnet-delay/Path coverageとUCP、CPLD経由JTAGの公式timing調査は同フォルダと`evidence/JTAG_TIMING_RESEARCH_20261113.md`を参照。DA gateと実機 gate は引き続き未通過。




## 2026-11-13追加確認：未抑制post-fit DAと抑制指定の失敗

C2 direct-capture候補を元QSFのSHA-256が一致するクリーンな外部作業領域で再ビルドした。Quartus Prime Lite 25.1std.0 Build 1129、device `5CEBA4F23C7`。Full compileはexit 0、392 warnings。post-fit Design Assistantも実行自体はexit 0だが、未抑制の生レポートはHigh D101=801（内訳は要求payload 800構造と応答側の代表構造1）、D102=0、D103=0。Information-only 341（T101=291、T102=50）。この結果はDA PASSではなく、D101 dispositionの未解決ゲートとして記録する。

D101を要求・応答payloadに限定する二つの`DISABLE_DA_RULE`指定を試した。値と`-to`の順序を変えた両試行ともQuartus DRCが`tokenize_ruleid_string`でaccess violation、exit 2。suppressionを含む設定での合格扱いはしない。未抑制の`.drc.rpt`、失敗ログ、QSF、候補SOFとSHA-256は`evidence/quartus_d101_raw_unwaived_20261113/`に保存した。

同クリーンビルドの4コーナーsetup/holdはすべて報告上正（slow85 +0.821/+0.242 ns、slow0 +0.979/+0.239 ns、fast85 +9.638/+0.128 ns、fast0 +10.648/+0.116 ns）。ただしQuartusはsetup/holdがfully constrainedではないと明記し、外部I/O制約も未完了。したがってTiming signoffはBLOCKED。SOF生成はPASSだが、RTL/CDC・DA・I/O timingの実機ゲートが未通過のため、C2 SOF書込み・実機1件・42件・実測cycleはNOT_RUNのまま。Flash/CFMは未操作。

同日、GPIOジャンパーを外した状態の読み取り専用 `jtagconfig -n` を再実行した。Quartusは`USB-Blaster [USB-0]`とFPGA IDCODE `02B050DD / 5CE(BA4|FA4)`をexit 0で検出。SOF書込みやJTAG DR/IRのscanは行っていない。C2 Virtual-JTAG nodeの実機確認はC2 SOF未ロードのため未実施。コマンド・cwd・出力・SHA-256は`evidence/jtag_readonly_after_gpio_removed_20261113/`。

## 2026-11-13 21:10 JST: exact per-node D101 disposition and fresh full Quartus run

This section supersedes the earlier 2026-11-13 note that Quartus Lite could not accept any scoped D101 disposition. The earlier wildcard suppression probes did crash Quartus Lite. A later trial using the documented `DISABLE_DA_RULE` syntax with an exact quoted node and `-entity rtnn_c2_vjtag_mailbox` succeeded; applying it to all 801 enumerated structures also succeeded. Wildcards are not used.

A fresh independent build at `D:\rtnn_c2_d101_disposition_20261113` used the clean baseline project plus exactly 801 generated node-level D101 settings. Full compile, Fitter, Assembler, and Timing Analyzer exited 0; 392 warnings were retained with an ID/count inventory. Post-fit Design Assistant exited 0 with 0 errors, 0 warnings, 0 High violations, and 341 information-only items. Global D101/D102/D103 remain On; 801 local D101 assignments are Off: 800 request payload structures and one response representative. The raw unwaived report still records all 801 original D101 findings in `evidence/quartus_d101_raw_unwaived_20261113/`.

The same final fit was audited at all four corners: 800/800 request paths and 384/384 response paths per corner, with exact source/destination bit-index mapping. Maximum request net delay was 3.358/3.263/2.085/1.822 ns against 16 ns bounds; maximum response delay was 3.157/3.037/2.067/1.798 ns against 24 ns bounds. All reported net-delay slacks are positive. `report_max_skew` found no paths and is not counted as a passing check.

The final STA still reports setup/hold requirements are not fully constrained. JTAG TDI/TMS/TDO and LED output I/O paths remain unconstrained, so board-level timing signoff is BLOCKED. The candidate SOF (`SHA-256 5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6`) is preserved only and was not programmed. No SRAM or Flash/CFM write occurred. Current JTAG evidence is read-only cable/IDCODE enumeration; C2 Virtual-JTAG mailbox read/write remains untested.

Full project inputs, SOF, logs, DRC/Fitter/STA reports, exact assignment list, and all-corner audit are preserved in `evidence/quartus_d101_exact_disposition_20261113/`. The run record lists commands, versions, warning IDs, source hashes, and limits. This disposition does not turn unconstrained I/O into a timing pass.

## 2026-11-13追加：JTAG外部遅延の公式仕様を絞り込み

Terasic公式回路図でオンボードUSB-BlasterのFT245BLとEPM240T100経路を再確認し、Intel公式MAX II handbookのEPM240対応speed grade（-3/-4/-5）と3.3-V LVTTL/10 pF条件のtCO max（4.3/5.6/6.9 ns）を確認した。tCOはCPLDのclock-to-output仕様であり、FPGAへ到着するTCKとTDI/TMSの相対skewではない。回路図/CD資料にCPLDロジック、実搭載suffix、board trace delayは見つからず、既存STAでもTDI/TMS/TDOのI/O遅延が未制約。数値を代入する根拠は得られなかったためSDCを変更せず、JTAG I/O timingと基板書込みはBLOCKEDのまま。詳細は`evidence/JTAG_TIMING_RESEARCH_FOLLOWUP_20261113_JA.md`。

Quartus post-fit DBから、falling-edge launchかつ解析用外部遅延0 nsを置いた場合の入力要求窓を4 cornerで逆算した。30 MHz SLD clock modelでTDIは相対遅延`[-15.682, +4.747] ns`、TMSは`[-15.989, +3.325] ns`がFPGA側worst-case窓。各cornerでTDI全10 path、TMS全31 pathを列挙した。これはon-board USB-Blasterの実timingではなく、board-level signoffにもならない。TDO receiver timingは引き続き不明。生レポート/Tclは`evidence/jtag_interface_requirement_20261113/`。外部タイミングを未確定のまま実験的に42件へ進む方法は完全timing signoffと異なるため、今回指定された「安全ゲート通過後」の条件を変える明示承認がない限り、C2 SOFは書き込まない。

2026-11-13の再開後、`jtagconfig.exe -n`をexit 0で再実行し、USB-Blaster/IDCODE `02B050DD`を確認したがVirtual-JTAG nodeは列挙されなかった。build ID/loaded SOFはこの照会からは判定できず、JTAG chain enumeration以外の通信、設定、Flash書込みはしていない。固定C2J2 runnerのfresh `-ValidateOnly`もexit 0（42-case SHA、build `43324a32`、payload audit PASS、sequence 2/27/34、hardware_access=none）。生証跡は`evidence/resume_gate_recheck_20261113/`。外部JTAG timingが未確定のため実機ゲート判定は変わらない。

## 2026-11-13 22:28 JST: C2J2 実機42件 qualification PASS

外部JTAG I/O timingが未確定であることをformal signoffと分離し、ユーザーの実験継続指示の下で実機qualificationを行った。Cyclone V `5CEBA4F23C7N`、USB-Blaster `USB-0`、JTAG IDCODE `02B050DD`。`quartus_pgm`でcandidate `.sof`のみをFPGA SRAMへ設定し、Flash/CFMは操作していない。最終`jtagconfig -n`は`Virtual JTAG #0`も表示した。

C2J2 build ID `43324a32`、SOF SHA-256 `5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6`、凍結42ケースCSV SHA-256 `52b7fdae7c465fd4b6409876e258e00fbaad5656e93ad3b9fb79f2f8741aec5d`。最終run `C2J2_HW_ALL42_RUN1_20261113`はQuartus STP/Tcl exit 0、result auditor exit 0、42/42 PASS。予測は凍結`expected_prediction`・Exit・CRC/応答IDと全件一致。すべて有効なFPGA Ibex `mcycle`値、実行cap違反0、timeout0、欠損0。cycle範囲20,146–2,791,485、中央値1,031,300.5。サイクル値を時間へ換算していない。

SRAM再設定によるreset replayはcase 2でPASSし、prediction 3、Exit 1、cycle 482,034が最初のsingle runと完全一致。固定とadaptiveを含むsequence 2/27/34もPASS。`reference_label`は教師ラベルとして別記録し、凍結モデル出力`expected_prediction`とは別の値である。42件中18件は予測が教師ラベルと異なるが、いずれも凍結seed-63モデルの期待出力とは一致している。これは実装不一致やcap違反ではなく、その既存モデルの分類結果である。

### 不具合の再現と最小修正

1. Quartus STP/Tclへ日本語を含むrepository絶対パスを渡すと`package "fil_test" isn't loaded statically`でexit 3となることを再現した。ASCII junction `C:\rtnn_c2_20261113`をrepository rootへ作り、Quartus process cwdをQuartus `bin64`へ変更して解消。ログは`quartus_stp_tcl_arg_probe_fullpath.log`と成功した`quartus_stp_tcl_arg_probe_junction.log`。
2. 1要求後に応答384 bitをTDO read-only shiftしただけではDONEが0x40のままで、次要求seq 27がERROR 0xC0になった。個別seq 27はSRAM再設定後PASSし、入力ベクトル不良ではないことを確認。IR_RESPONSE読出しに384 bitのゼロを`-dr_value`としてshift-inし、UpdateDRを発生させるとstatusがREADY 0x08へ復帰した。ホストTclは応答後READYを確認して次要求へ進むよう修正。3-case、42-case、reset replayを再実行してPASS。
3. READY待ちだけを追加しDR consumeを行わない試行は完了しなかったため、診断終了コードをPASSに数えない。プロセス停止、partialログ、後続の修正/成功ログをこのフォルダに保全。

### 変更と再実行

変更はホスト制御2ファイルのみ。`host/Invoke-C2JtagExperiment.ps1`はASCII aliasとQuartus cwdを検証し、`host/run_c2_jtag.tcl`は応答UpdateDRとREADY待ちを実行する。RTL、firmware、凍結Q15、case table、QSF/SDCはこの実機対応で変更していない。SOFは既存の全Quartus buildの出力を使用し、host-only変更後に再合成していない。

repository rootから、毎回新しい`OutputDirectory`と`ExperimentId`を使って再実行する。ProgrammingはSRAM専用コマンドである。

```powershell
$c2 = Join-Path (Get-Location) 'de0cv_setup/stage3_experiments/ibex_csa_2026-11-03/c2_jtag_measurement_20261111'
$sof = Join-Path $c2 'evidence/quartus_d101_exact_disposition_20261113/rtnn_c2.sof'
$pgm = 'C:\altera_lite\25.1std\quartus\bin64\quartus_pgm.exe'
& $pgm -c 'USB-Blaster [USB-0]' -m JTAG -o "p;$sof"
& "$c2/host/Invoke-C2J2JtagExperiment.ps1" -SofPath $sof `
  -ExperimentId C2J2_HW_ALL42_NEW -OutputDirectory (Join-Path $c2 'evidence/NEW_RUN_DIRECTORY')
```

Quartus Prime Lite/STP/Programmer 25.1std.0 Build 1129。成功Programmer/STP runは0 error/0 Quartus warning。起動時の`TBBmalloc: skip allocation functions replacement in ucrtbase.dll: unknown prologue for function _msize` noticeも生ログに残した。USB-Blaster、case table、SOF、host scripts、native/sv2v/Quartus STAの上流証跡、各試行ログとCSV/JSONは同folder内manifestで照合できる。

### 残る限界

実験的qualificationはPASSだが、C2 post-fit STAはsetup/hold fully constrainedでないと報告している。TDI/TMS/TDO外部遅延、基板launch/capture skew、実TCK周波数は未測定で、board-level JTAG timing signoffはBLOCKED。今回の42成功はこのボードとこのQuartus/cable条件で機能した経験的結果であり、全PVT/全基板lot保証、ppm、絶対実行時間の根拠ではない。詳細は`JTAG_TIMING_RESEARCH_FOLLOWUP_20261113_JA.md`。

Flash/CFM未操作。コミット・pushなし。


## 2026-11-13 追記：実機42件qualification後の最終確認

- C2J2の凍結42件は実機JTAGで全件PASS済み。run ID `C2J2_HW_ALL42_RUN1_20261113`。詳細、生ログ、CSV/JSON、reset replayは`evidence/physical_empirical_after_user_scope_20261113/RUN_RECORD_JA.md`を参照。
- 実機 qualification と形式的JTAG board timing signoffは別ゲート。後者は外部TDI/TMS/TDO遅延、実TCK、基板skewが未確定のためBLOCKEDのまま。
- 最終PowerShell AST parse PASS。C2J2固定入口のValidateOnly（sequence 2/27/34、build `43324a32`、凍結CSV SHA一致、payload監査PASS）はexit 0、hardware_access=none。記録は`evidence/physical_empirical_after_user_scope_20261113/validate_only_final_20261113/`。
- Flash/CFM未操作。コミット・pushなし。論文用360入力campaignは次段階で、今回の42件qualificationに含まない。
