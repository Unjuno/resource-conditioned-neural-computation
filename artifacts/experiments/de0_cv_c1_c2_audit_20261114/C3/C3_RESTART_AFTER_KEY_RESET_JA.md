> **実行済み:** この手順は2026-11-15に実施され、KEY0 reset後の20/20 replayと独立監査がPASSしました。履歴手順として保持します。結果は[C3_CURRENT_STATUS_20261115_POST_KEY_RESET_JA.md](C3_CURRENT_STATUS_20261115_POST_KEY_RESET_JA.md)と[run record](evidence/PHYSICAL_C3_V2_20261115/KEY_RESET_REPLAY/C3V2_TENINPUT_KEY_RESET_REPLAY_20261115_RUN2/RUN_RECORD_JA.md)にあります。

# C3 v2 実機試験の再開手順 — KEY reset後

> **履歴手順:** 2026-11-15にユーザー申告のKEY[0] press/release後、RUN5の20/20 replay、独立監査、reset gate生成まで完了しました。最新結果は[C3_CURRENT_STATUS_20261115_POST_KEY_RESET_RUN5_JA.md](C3_CURRENT_STATUS_20261115_POST_KEY_RESET_RUN5_JA.md)と[RUN5 record](evidence/PHYSICAL_C3_V2_20261115/KEY_RESET_REPLAY/C3V2_TENINPUT_KEY_RESET_REPLAY_20261115_RUN5/RUN_RECORD_JA.md)を参照してください。以下は再実行用の手順の履歴であり、現在の未完了状態を示しません。

## 今回済みの準備

* C3 v2 build `43334531`の保存済み42件とpilot SESSION1 20件をオフラインで独立監査済み。
* 次の操作は行っていない: JTAGアクセス、KEY操作、SOF再設定、電源断、配線変更。
* reset gate JSONは未生成。SESSION1をKEY-reset結果として流用できない。
* 先にC3 v2 identity read-only checkerをQuartus STPの`--self-test`で検証済み。通常モードはbuild/statusのread-only scanだけを行う。

## 0. PC側の準備（短いASCII path）

PowerShellで正しいrepository rootから実行。Quartus STPは既存runで使ったASCII CWDに移す。下記はステージcopyとhash照合だけで、JTAGには接続しない。

```powershell
$repo = (Get-Location).Path
$c3 = Join-Path $repo 'artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3'
$prep = Join-Path $c3 'evidence/PHYSICAL_C3_V2_20261115/TENINPUT_PILOT_SESSION1'
$src = Join-Path $c3 'source'
$stage = Join-Path $env:TEMP 'rtnn-c3v2-key-reset-20261115'
if (Test-Path -LiteralPath $stage) { throw "既存stageを上書きしない: $stage" }
New-Item -ItemType Directory -Path $stage | Out-Null
Copy-Item (Join-Path $prep 'cases.csv') $stage
Copy-Item (Join-Path $prep 'binding.json') $stage
Copy-Item (Join-Path $src 'measurement_protocol_v2_43334531_20261115/run_c3_measurement_v2.tcl') $stage
Copy-Item (Join-Path $src 'check_c3_v2_loaded_build.tcl') $stage
Copy-Item (Join-Path $src 'audit_c3_v2_jtag_results.ps1') $stage
Copy-Item (Join-Path $src 'create_key_reset_replay_gate.py') $stage
Get-FileHash (Join-Path $stage 'cases.csv'), (Join-Path $stage 'binding.json') -Algorithm SHA256
```

このASCII stage directoryは、PowerShell監査、Python独立監査、gate生成、後続runnerのhash参照がすべて終わるまで保持する。途中で削除・移動・内容変更しない。既存stageの内容を再利用せず、新runには新しい空のstage名を使う。

期待SHA: `cases.csv`=`e9639c0fea350e813b3d8c04ed3cc7c814fd6efacdc930e6c12f14ddf5b1becd`; `binding.json`=`bab047cc34dfb059e5647d0a88af9906510b9c45b31300d009d459e06d6f4d44`. 一致しなければそこで停止。

## 1. JTAG接続とロードbuildのread-only確認

Quartus STP 25.1 Build 1129があることを確認し、**Quartus STPのCWDをASCII path**にする。ローカルinstallのbin pathは`C:\altera_lite\25.1std\quartus\bin64`を確認済み。

```powershell
$quartusBin = 'C:\altera_lite\25.1std\quartus\bin64'
Set-Location $quartusBin
& .\quartus_stp_tcl.exe -t (Join-Path $stage 'check_c3_v2_loaded_build.tcl')
```

期待結果はUSB-Blaster、IDCODE `0x02B050DD`、build ID `0x43334531`（表示ID `43334531`）、mailbox READY bit。check TclはIR/DRを読み取り、DRへ値を書き込まない。**SOFのSHAをFPGAから読み戻す機能ではない**ため、build IDはbitstream hashの代替ではない。USB-Blaster/5CE/build/READYが一つでも合わないか、checkerがERROR/timeoutなら、KEYを押さず停止してログを保存。

この確認とKEY resetは別操作。KEYを押す前に現在のPC接続先と基板を視認する。SOFの再設定が必要になった場合は、保存済みSOFのSHAを照合しSRAM-onlyで行う別手順にする。今回のKEY replay手順では自動再設定しない。

## 2. 実機のKEY[0]を押して離す

build/read-only identity確認がPASSした後、ユーザーがDE0-CVのKEY[0]を一度押して離す。押した瞬間と解放後を実際に見て確認する。Codexからは操作しない。KEY[0] resetは、FPGAへのSOF再設定・基板の完全電源断と同じ扱いにしない。

## 3. 同じ20要求を新しいexperiment IDで再実行

Quartus STPのCWDは引き続き`C:\altera_lite\25.1std\quartus\bin64`。PowerShellは`$stage`へ戻り、出力先が未作成であることを確認する。sequenceは固定済みbinding内の20件を明示する。

```powershell
Set-Location $stage
$runId = 'C3V2_TENINPUT_KEY_RESET_REPLAY_20261115_RUN1'
$out = Join-Path $stage $runId
if ((Test-Path -LiteralPath $out) -or (Test-Path -LiteralPath (Join-Path $stage "$runId.quartus.log")) -or (Test-Path -LiteralPath (Join-Path $stage "$runId.audit.exitcode"))) { throw "このrun IDは既に使われています。結果を上書きせず、未使用の新しいrun IDを選んでください: $runId" }
$seq = '49,50,141,142,209,210,277,278,325,326,379,380,431,432,487,488,559,560,719,720'
& "$quartusBin\quartus_stp_tcl.exe" -t (Join-Path $stage 'run_c3_measurement_v2.tcl') `
  (Join-Path $stage 'cases.csv') (Join-Path $stage 'binding.json') $out `
  '85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d' $runId $seq *> (Join-Path $stage "$runId.quartus.log")
$runExit = $LASTEXITCODE
Set-Content (Join-Path $stage "$runId.quartus.exitcode") $runExit -NoNewline
```

runnerはJTAGを開いた後、最初にCyclone Vとbuild IDを照合し、READYを確認してから最初の要求を送る。途中で失敗しても出力フォルダ・raw log・partial CSV/JSONを保存し、再実行で上書きしない。失敗時はgateを作らない。

## 4. 独立監査後にreset gate証拠を作る

まず既存PowerShell auditorを実行し、期待列20件とscope subsetを指定する。

```powershell
$resultDir = Join-Path $stage $runId
$auditOut = Join-Path $stage "$runId.independent_audit.json"
powershell.exe -NoProfile -ExecutionPolicy Bypass -File (Join-Path $stage 'audit_c3_v2_jtag_results.ps1') `
  -RunDirectory $resultDir -ExpectedRows 20 `
  -ExpectedSofSha256 85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d `
  -ExpectedBuildId 43334531 -ExpectedModelId 52544e4e `
  -ExpectedSequenceCsv $seq -ExpectedScope subset > $auditOut
$auditExit = $LASTEXITCODE
Set-Content (Join-Path $stage "$runId.audit.exitcode") $auditExit -NoNewline
```

PowerShell exitが0で監査JSONのstatusがPASSでも、別Python checkerで結果JSON/CSV/frozen case/binding/raw logを確認する。証跡をまず`C3/evidence/PHYSICAL_C3_V2_20261115/KEY_RESET_REPLAY/<runId>/`へ新規保存し、コピー後SHAを再照合する。そこから`audit_saved_c3_v2_runs.py`で独立再監査する。

両監査がPASSしたら、raw output、cases、binding、PowerShell監査JSONを正しいevidence treeへ新しいrun IDで保管し、SHA一致を確認してPython独立checkerも実行する。次の例ではコピー元の保存や元ファイルの編集をしない。

```powershell
$archive = Join-Path $c3 "evidence/PHYSICAL_C3_V2_20261115/KEY_RESET_REPLAY/$runId"
if (Test-Path -LiteralPath $archive) { throw "既存証跡を上書きしない: $archive" }
New-Item -ItemType Directory -Path $archive | Out-Null
Copy-Item (Join-Path $resultDir 'c2_jtag_results.json'), (Join-Path $resultDir 'c2_jtag_results.csv'), `
  (Join-Path $resultDir 'c2_jtag_raw.log') -Destination $archive
Copy-Item (Join-Path $stage 'cases.csv'), (Join-Path $stage 'binding.json'), $auditOut -Destination $archive
Get-FileHash (Join-Path $archive 'c2_jtag_results.json'), (Join-Path $archive 'c2_jtag_results.csv'), `
  (Join-Path $archive 'c2_jtag_raw.log'), (Join-Path $archive 'cases.csv'), (Join-Path $archive 'binding.json') -Algorithm SHA256
python (Join-Path $c3 'source/audit_saved_c3_v2_runs.py') `
  --result-json (Join-Path $archive 'c2_jtag_results.json') `
  --result-csv (Join-Path $archive 'c2_jtag_results.csv') `
  --cases-csv (Join-Path $archive 'cases.csv') `
  --binding-json (Join-Path $archive 'binding.json') `
  --raw-log (Join-Path $archive 'c2_jtag_raw.log') `
  --expected-experiment $runId `
  --output-json (Join-Path $archive 'python_independent_audit.json')
```

Python独立監査のexit 0を確認し、そのJSONを読んでから、ユーザーがKEY[0]の実押下・解放を確認した場合だけgateを作る。フラグは人間が実際に操作した場合に限って指定する。

```powershell
python (Join-Path $stage 'create_key_reset_replay_gate.py') `
  --result-json (Join-Path $resultDir 'c2_jtag_results.json') `
  --audit-json $auditOut `
  --output (Join-Path $stage 'key_reset_replay_gate.json') `
  --operator-confirmed-key0-press-release
```

作成器はrun IDのreset replay prefix、20 sequence、build/SOF、PowerShell監査statusとresults/raw/CSV SHAを検査し、既存ファイルを上書きしない。以前のSESSION1の20件、42件、mockデータからgateを作れないことはテスト済み。gateは人間の操作申告と監査結果を紐付ける証拠であって、電気的reset pin波形の測定ではない。

## 5. 条件成立後にだけcampaignへ進む

gate JSONのSHAと20件結果を独立にレビューし、`run_c3_campaign_v2.tcl`の完全schedule用runnerへgateを渡す。スケジュールは既存13本・24,840行の凍結bindingから変更しない。SOF、ELF、model、binding、campaign SHAの不一致、timing/CRC/ID/予測/cap異常、欠損・timeoutなら直ちに停止して失敗証拠を保存。全結果は`EMPIRICAL_ONLY`であり、B-SIGNOFF、WCET、hard deadlineをPASSにしない。

KEY reset、SOFのSRAM再設定、完全電源断は異なるイベントとして各run記録へ記載する。今回の準備ではいずれも実施していない。

