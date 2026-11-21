# 新規画像用build・回帰記録

対象branch `codex/external-validation-20261122`、開始HEAD `a5f2805ff9ff95c1dc237057bf661886abd98e8f`。build outputsはこのpackageの`build/`に隔離し、過去実験を変更していない。

依頼にあった`RTNN_external_validation_preparation_20261122.zip`は作業環境で見つからなかったため展開せず、同梱とされる18件の既存テストも再実行していない。リポジトリ内に独立実装し、このpackageで現存する11 unit testsを新規実行した。

## 入力・model・firmware identity

- UCI `optdigits.tra`: 3,823画像、8×8 pixel、値0–16、ラベル0–9。原本SHA-256 `e1b683cc211604fe8fd8c4417e6a69f31380e0c61d4af22e93cc21e9257ffedd`。
- 1,797のsklearn `load_digits`画像との画素完全一致はtrain原本内0件。UCI test原本と`load_digits`の一致は検出済みであり、独立確認用dataとして扱わない。
- 工学pilot 10画像、20 mode cases。主要候補3,813画像、7,626 mode cases。teacher labelはhost側のみ。
- frozen Q15 core SHA-256 `a6b2807bd4a60534c250fca3005322cf14ba0a92f6b16e28241109385efc6809`、weight header SHA-256 `961a76b7e220bf2f665e7c04ab62063600aa2e7eccf3403d80ea730bc993ad9f`。
- Build ID `45585631`、binding ID `45585632`、model ID `52544e4e`。
- ELF SHA-256 `4673f6a8b90493c15c327ed3be1167e0fcf3ff2be60292dcb12a1391124a0c2e`、BIN SHA-256 `f3b02ab923f9c19f9eebb265d08e997a57365dd9dffdea9de4bfc408eaa02cb7`。

## 実行した検証

1. RV32 firmware: Ubuntu clang/LLD 18.1.3でbuild。RAM lane imageを生成。
2. software API対oracle: pilot 20 + primary 7,626 = 7,646 cases一致。
3. Quartus-flat Verilator: 20動的入力要求、reset replay、bad header/payload CRC、pixel range、invalid ID、wrong model/build ID、duplicate sequence、799-bit short requestの8 negative case PASS。別mailbox testでpartial response非公開・commit後公開とshort request拒否PASS。
4. native SystemVerilog: frozen 146-source graphを使用。Verilator 5.020。20要求、reset replay、同じ8 negative case PASS。mailbox commit guardもPASS。
5. sv2v: sv2v 0.0.13で変換後Verilator 5.020。上記と同じ20要求、reset replay、8 negative case、mailbox commit guard PASS。
6. Python host/statistics/fail-closed: Python 3.11、11 unit tests PASS。13 scripts `py_compile` PASS。PowerShell parser PASS。Quartus STP Tcl `info complete` syntax-only PASS（runner本文はsource/evalせず、JTAG APIも実行していない）。

simulationのcycleはRTLシミュレーション値であり、実機cycleとして使わない。最終ログは`build/native_sv2v_pilot_attempt3/`、`build/quartus_external_attempt1/rtl_pilot_attempt4/`、`build/firmware_api_attempt2/`にある。初回runnerはhost vector directoryの重複作成で停止し、初回ログを残した。追加commit-guard testの最初のQuartus-flat attemptはtestbench literal幅で停止し、ログを残した。修正後の別attemptは成功した。

## ツール

| ツール | 版 | 用途 |
|---|---|---|
| Quartus Prime Lite | 25.1std.0 Build 1129 | Synthesis/Fitter/Assembler/STA/DRC |
| Verilator | 5.020 | native・sv2v・Quartus-flat RTL simulation |
| sv2v | 0.0.13 | SV conversion |
| Ubuntu clang / LLD | 18.1.3 | RV32 firmware |
| Python | 3.11 (Windows); 3.12 (WSL) | generators/tests |

## 主要ログ・実行コマンド

WSLからnativeとsv2vを実行:

```bash
bash artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/external_validation_20261122/scripts/run_native_sv2v_pilot_regression.sh native_sv2v_pilot_attempt2
```

Quartus flat simulation:

```bash
bash artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/external_validation_20261122/scripts/run_rtl_pilot_regression.sh rtl_pilot_attempt2
```

Python tests:

```powershell
$env:PYTHONPATH = Join-Path $env:TEMP 'rtnn_sklearn_1_8_0'
py -3.11 -m unittest discover -s artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/external_validation_20261122/scripts -p 'test_*.py' -v
```

RV32/API, generated image manifests, source graph and Quartus evidence are all under this package's `build/`. The initial software manifest deliberately retains its `BUILT_NOT_SIMULATED` creation-time label; later RTL simulation evidence is recorded separately here and is not retroactively written into the old manifest.

