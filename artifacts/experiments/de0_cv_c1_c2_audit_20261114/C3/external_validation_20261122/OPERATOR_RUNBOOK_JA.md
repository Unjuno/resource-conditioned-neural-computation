# 後日の実機評価手順（今回未実行）

> **2026-11-28 primary準備の追記（旧手順より優先）:** 成功済みの実行器は`host_v2_20261126/`です。本文中の旧`host/`コマンドは過去の手順記録であり、primary実行に使わないでください。primary binding作成とPowerShell/Tclのpreflightは、凍結3,813入力・7,626要求、各画素SHA・ラベル・CPU oracle・実行順、pilot gate、実行済みraw JTAGログから得たsequence履歴を照合します。primary用case CSVは既存の`build/host_cases_primary_attempt2/cases.csv`を直接実行せず、実験ID/session IDを新しくし、sequenceを記録済み最大値より後から連番にした別出力として準備してください。保存済みログの最大sequenceは21のため、次の未使用値は少なくとも22です。検証器が記録済みraw logを読めない、sequence履歴が不正、またはbindingにschedule identityがない場合は停止します。今回、primaryを開始していません。

成功版のSHA-256（2026-11-28の作業開始時点）:

* `host_v2_20261126/Invoke-ExternalValidation.ps1`: `477f7de64cc4da7892a82d0dd48764d5f3a88329a8f5c234241a93c080777f8b`
* `host_v2_20261126/run_external_validation.tcl`: `587c6b5014cbd1edfd01a20048090c38350dd62ab9872c046be9459be9c51514`

この追記を含む変更後はコード・runbookのcommit SHAを記録し、上記のrunner SHAは履歴値として扱います。物理実行時はコピー後に移動前後のSHA一致を再確認してください。

> **最新版ゲート追記 (2026-11-22):** primary実行は、20件のphysical pilot結果から独立監査で生成した `rtnn-extval-pilot-gate-v1` がない限り開始できない。旧版手順の「pilot適格後にprimary」もこの機械検証が必須。offline/simulation fixtureや`OFFLINE` sessionは使用不可。詳しくは `safety_gates_v1_20261122/FINAL_GATE_STATUS_JA.md` と `PILOT_GATE_SCHEMA.md` を参照。
> **事前登録時系列の注意 (2026-11-23):** preregistrationのSHAは維持されているが、oracle/firmware予測より先に固定されたことを示す独立・改ざん耐性ある時刻証拠がない。現状、今後の評価は探索的として扱い、確認的な母集団主張はしない。

この手順は、作成済みの新SOF、limited empirical audit、およびpilot bindingに対して、ユーザーが明示的に物理操作を許可した後だけ利用する。bindingは`EMPIRICAL_ONLY`で、正式signoffを意味しない。B-SIGNOFFは別ゲートであり、本手順で解除されない。現時点では基板へ何も送らない。

## 事前ファイル

使用する実体は`build/rv32_attempt2/rtnn_external_validation.elf`と同じ場所の4 RAM lane、`build/quartus_external_attempt2/rtnn_c3_measurement_v2.sof`、`build/prepared_pilot_cases_attempt1/cases.csv`、`build/cpu_oracle_attempt1/oracle_pilot.csv`、`build/quartus_external_attempt2/quartus_audit.json`、`build/bindings/pilot_run1_binding.json`。すべてのSHAをbindingと照合する。`build/bindings/pilot_binding.json`はOFFLINE session IDのため無効化済みであり使わない。既存C3 v2のSOF/ELF/測定値を代用しない。

## 1. 新buildの身元確認

リポジトリの正しいbranchとHEAD、Quartus版、デバイスIDCODE、ケースCSV SHA、Build ID `45585631`、Binding ID `45585632`、model ID `52544e4e`、SOF SHAを読み取り専用で確認する。基板電源や配線を変更しない。JTAG識別値やbindingが期待と異なれば中止する。

## 2. 書込み許可後のSRAM設定

現時点の指示では新SOF書込みは未許可。将来、ユーザーが明示的に許可した場合だけ、Quartus Programmerで対象がDE0-CVのCyclone V SRAM設定であることを二重確認し、SOFのみをSRAMへ設定する。Flash/CFM、EPM240/CPLD、I/O電圧、外部クロック、配線は変更しない。書込み前後で対象デバイスとファイルSHAを記録する。

## 3. pilot 10画像

まず次のpreflightだけを行う。現在のpreflightは`PREFLIGHT_ONLY`, 20 cases, `physical_jtag_started=false`を確認済み。

```powershell
$p='artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/external_validation_20261122'
pwsh -NoProfile -File "$p/host/Invoke-ExternalValidation.ps1" `
  -CaseCsv "$p/build/prepared_pilot_cases_attempt1/cases.csv" `
  -BindingJson "$p/build/bindings/pilot_run1_binding.json" `
  -OutputDirectory "$p/build/physical_pilot_RUN1"
```

identity・binding・case SHA・出力先を監査した後、ユーザーが基板の前にいて物理実行を許可した場合だけ同じコマンドに`-ExecutePhysical`を加える。`data/pilot_manifest.csv`の10 IDについてfixed2/adaptive各1要求を実行する。sequenceは同じ実験session内で単調増加させる。

全要求のraw JTAG request/response、応答ID、CRC、pixel payload CRC、Q15予測、教師ラベルとの正答、admitted/executed Exit、cap、mcycle start/end/delta、status、timeout/trapを保存する。失敗・timeout・再試行を消さない。runのSHA manifestとCPU参照を独立監査し、不一致が一つでもあれば停止する。

## 4. pilot結果後の判断

pilot全20要求が新buildと固定oracleに一致しても、これは工学的pilotであり性能・精度の確認的結論ではない。異常なしを独立監査してから、primary実行を別途開始する。pilot IDはprimaryから永久除外する。

## 5. primary session

事前登録に固定された3,813画像×2方式×3 sessionを全件実行する。各sessionは別実験ID・session IDとし、独立電源sessionを名乗る場合はUSB-Blaster等を含む全FPGA電源が遮断された根拠を記録する。KEY0論理resetは電源断ではない。USB逆給電を除外できない場合`COLD_BOOT_UNVERIFIED`と記録する。Codexから電源遮断を代行・推定しない。

測定境界はCPUの推論関数直前・直後の64-bit `mcycle`。JTAG転送、host wait、retryは区間外。予測・Exit・CRC・counter・identity異常でただちに停止し、失敗データを保全する。3 sessionをすべて完了後、独立監査を通ったrunディレクトリのみを解析器へ渡す。

## 今回の扱い

この手順書は準備物である。PowerShell preflightは成功した。TclはQuartus STPの`info complete`で文法完結性だけを確認した。JTAG API実行、物理JTAG runner、SOF書込み、基板リセット・電源操作は今回実行していない。

## 最新版: pilotゲートを作成しprimaryへ進む

physical pilot runが終了し、独立監査で20/20全件一致した場合だけ、production gateを作成する。現時点では実機pilotがないので実行しない。

```powershell
$p='artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/external_validation_20261122'
python "$p/safety_gates_v1_20261122/PILOT_GATE_CREATOR.py" `
  --run-dir "$p/build/physical_pilot_RUN1" `
  --oracle "$p/build/cpu_oracle_attempt1/oracle_pilot.csv" `
  --pilot-manifest "$p/data/pilot_manifest.csv" `
  --primary-manifest "$p/data/primary_manifest.csv" `
  --operator-authorization recorded `
  --out "$p/build/pilot_gate_RUN1.json"
```

次に、既存SOF/ELF/Quartus監査を保ったprimary bindingを新規出力先へ作るとき、`--pilot-gate "$p/build/pilot_gate_RUN1.json"`を指定する。`create_physical_binding.py`、PowerShell runner、Tcl runner、primary auditの全入口でgateを再検証する。Tcl直起動もPython validatorに失敗すればJTAG packageをロードしない。

電源再投入の証拠は各session別に `safety_gates_v1_20261122/POWER_SESSION_EVIDENCE_SCHEMA.md` に沿って記録する。KEY0だけ、SOF reloadだけ、または申告だけではcold bootに数えず、機能データは`EMPIRICAL_ONLY / COLD_BOOT_UNVERIFIED`として別に保全・解析する。
