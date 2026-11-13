# C2J2 JTAG実験入口と再実行

2026-11-13現在、C2J2固定Ibex/Q15のnative・sv2v SoC回帰、Quartus Fitter/Assembler/post-fit STA/DAは各証跡の記録どおりPASS。ただし外部JTAG timing signoffは未完了で、TDI/TMS/TDOの遅延・実TCK周波数は未確定。ユーザーの明示指示に基づく実験的qualificationとして候補SOFをSRAMへ設定し、single、subset 3件、凍結42件、reset replayを実施した。全42件とreplayはPASS。これはboard-level timing signoffとは区別する。生証跡と未解決事項は`evidence/physical_empirical_after_user_scope_20261113/RUN_RECORD_JA.md`および`C2_DESIGN_AND_GATE_STATUS_JA.md`を参照。

実験的qualificationは完了済み。外部JTAG timing signoffをPASSへ読み替えないこと。再実行は同じSOF SHA/build ID・USB-Blaster/IDCODEを照合し、`.sof`のSRAM設定だけを行う。POF/JIC、Flash/CFMは使わない。

Quartus 25.1 `quartus_stp_tcl`は、このOneDriveの日本語絶対パスをTcl引数/cwdに渡すと`package "fil_test" isn't loaded statically`で終了した。ホスト入口は、対象リポジトリを指すASCII junction `C:\rtnn_c2_20261113`経由でTcl/CSV/output pathsを渡し、Quartus `bin64`をprocess cwdにする。スクリプトがjunction targetを検証する。別PCではjunction pathをそのPCのASCII aliasへ変更し、そのtargetがリポジトリrootであることを確認する。

response DRの読出しは384 bitのゼロを同時にshift-inしてUpdateDRを発生させる。単にTDO値を読むだけではmailbox response-consume handshakeが進まずDONEのまま残る。ホストは各応答後にREADY復帰を待つ。

## 使用する入口

`Invoke-C2J2JtagExperiment.ps1`を使用する。これは`evidence/c2j2_candidate_20261112/host/c2_cases.csv`のSHA-256を固定し、build ID `43324a32`を検査する。

- 凍結42ケースCSV SHA-256: `52b7fdae7c465fd4b6409876e258e00fbaad5656e93ad3b9fb79f2f8741aec5d`
- モデルID: `52544e4e`。要求は100 byte/800 bit、応答は48 byte/384 bit。
- 入力IDは0・24・57。固定21件と適応21件。期待値を書き換えず、`-CaseSequences`で既存行だけを選ぶ。
- `host_vjtag_q15_20.tcl`と`host_vjtag_q15_c2.tcl`は以前の256-bitコマンド／UART経路の試行記録であり、このC2J2入口には接続しない。`host/c2_cases.csv`も旧C2J1用なのでC2J2へ手渡ししない。

次の`$c2`はリポジトリルートをcwdにしたPowerShellで設定する。

```powershell
$c2 = Join-Path (Get-Location) 'de0cv_setup/stage3_experiments/ibex_csa_2026-11-03/c2_jtag_measurement_20261111'
```

SOFも基板も不要な検査だけなら、次を実行できる。`ValidateOnly`はSOFを開かず、JTAGへアクセスしない。

```powershell
& "$c2/host/Invoke-C2J2JtagExperiment.ps1" `
  -SofPath 'NOT_USED.sof' -ExperimentId C2J2_VALIDATE `
  -OutputDirectory 'NOT_USED' -CaseSequences 2,27,34 -ValidateOnly
```

## 実機ゲート通過後の順序

1. 正式なC2J2 SOFとコンパイル入力、RTL回帰、Fitter/STA/DAのSHAを照合する。必要timing条件が解決済みであること、または明示承認された実験的qualificationであることを記録する。ProgrammerによるSRAM設定のコマンド、SOF SHA-256、USB-BlasterとIDCODE `02B050DD`を記録する。C1 SOFには上書き保存しない。Flash/CFM用POF/JICは使用しない。
2. C2のVirtual-JTAG build IDを読み、READYであることを確認して1件を実行する。
3. 固定と適応の3件を実行する。
4. 全42件を実行する。reset後に別の実験IDで再実行し、予測・Exit・サイクルを比較する。

各実験の前に協調resetを完了させる。物理topではKEY[0]がSoCとTCK側の両方をresetし、解除は各クロックで同期する。1件試験と次の試験でsequenceを再使用するため、途中のresetを省略しない。電源を切った場合はSRAMのSOFが失われるので、同じ検証済みSOFの再設定が必要。

実行例のSOFパスは置換が必要。未生成のファイルを実在するとみなさない。毎回新しい出力ディレクトリを指定する。

```powershell
$sof = 'D:\VERIFIED_C2J2_BUILD\output_files\rtnn_c2.sof'
& "$c2/host/Invoke-C2J2JtagExperiment.ps1" -SofPath $sof `
  -ExperimentId C2J2_HW_SINGLE_001 -CaseSequences 2 `
  -OutputDirectory 'D:\rtnn_c2_measurements\single_001'

# 協調reset後
& "$c2/host/Invoke-C2J2JtagExperiment.ps1" -SofPath $sof `
  -ExperimentId C2J2_HW_SUBSET_001 -CaseSequences 2,27,34 `
  -OutputDirectory 'D:\rtnn_c2_measurements\subset_001'

# 協調reset後。CaseSequencesを省略すると凍結42件すべて
& "$c2/host/Invoke-C2J2JtagExperiment.ps1" -SofPath $sof `
  -ExperimentId C2J2_HW_ALL42_001 `
  -OutputDirectory 'D:\rtnn_c2_measurements\all42_001'
```

この入口はSOFのハッシュを記録するが、SOF設定もFlash操作も自動実行しない。build ID一致だけではSOFのビット同一性を証明できないため、直前のSRAM設定記録が別途必要。複数のUSB-BlasterやCyclone Vが見える場合は、最初のものを勝手に選ばずFAILにする。

## 結果の読み方

| ファイル | 内容 |
|---|---|
| `c2_jtag_raw.log` | 選択sequence、対象、送信800 bit、受信384 bit、失敗理由。応答の検証前に生応答を保存する。 |
| `c2_jtag_results.csv` / `.json` | 入力・mode・予測・参照label・admitted/実行Exit・cycle・要求/応答ID・CRC判定・実験/SOF/build ID。 |
| `quartus_stp_tcl.log` | 実際のホスト制御出力。 |
| `result_audit.json` / `.log` | Pythonによる独立したCRC・要求・期待値・cycle・CSV/JSON/raw間の照合。 |
| `run_manifest.json` | 実行引数・cwd・実行プログラム/スクリプトSHA・終了コード・結果SHA。 |

`prediction`などは受信した観測値、`expected_*`は凍結参照値。timeout時など未受信の観測値はJSONのnull/CSVの空欄とし、期待値で埋めない。失敗応答に含まれるcycleは`reported_cycles`に残るが、`cycle_valid=false`、採用する`cycles=null`となる。

`executed_exit`は0から6で、この凍結モデルでは実行したTransformerブロック数と同じ値。coreの`rtnn_fixed_infer_exit`は`i < e`の範囲で`run_block`を呼び、adaptiveは1ブロックごとに`e`を増やして返す。Exit 0は初期状態のheadで、ブロックを実行しない。core SHA-256は`a6b2807bd4a60534c250fca3005322cf14ba0a92f6b16e28241109385efc6809`。ここでいうブロック数には入力初期化やexit headを含めない。

cycle境界は入力検証後・admission前からQ15推論とargmax完了まで。JTAG転送・応答符号化は含めない。0または32-bitを超える差分はfirmwareが拒否する。実発振周波数未測定なので、cycleから高精度な絶対時間やppmを主張しない。

JSON schemaは`rtnn-c2-jtag-results-v2`。`scope=subset`のPASSは全42件PASSを意味しない。全件判定には`scope=all_frozen_42`、`expected_count=count=completed_count=42`と独立検査PASSが必要。さらに実機の書込み・読出し記録、reset再現性、同一ビルドのタイミング証拠を合わせる。ホストmockにも同じ整合性検査を使うため、`PASS_ARTIFACT_CONSISTENCY`単独は実機証明にならない。

## ホスト回帰の再実行

次は模擬応答でのホストテスト。返却cycleは人工値であり、FPGA測定ではない。

```powershell
$out = 'D:\rtnn_c2_host_retest_NEW'
$cases = "$c2/evidence/c2j2_candidate_20261112/host/c2_cases.csv"
python "$c2/tests/check_c2_host_observations.py" `
  --tclsh 'C:\altera_lite\25.1std\quartus\bin64\tclsh.exe' `
  --runner "$c2/host/run_c2_jtag.tcl" --cases $cases --out "$out/runner"
python "$c2/tests/check_c2_result_auditor.py" `
  --fixtures "$out/runner" --cases $cases --out "$out/auditor"
& "$c2/tests/test_c2_host_pipeline.ps1" `
  -FixtureDirectory "$out/runner" -OutputDirectory "$out/pipeline"
& "$c2/tests/test_c2_j2_host_entrypoint.ps1"
```
