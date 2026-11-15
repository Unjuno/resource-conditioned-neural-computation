# 現HEADのGate B保存レポート再監査

実施日: 2026-11-15 JST  
Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`  
Branch / HEAD: `codex/stage-c3-jtag-pilot-20261114` / `143a4af545b49391b2413751918f7bb515277ae9`  
cwd: repository root `C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114`  
Python: 3.11.9  
Quartus evidence identity: 25.1std.0 Build 1129; C3 v2 build `43334531`; SOF SHA-256 `85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d`

## コマンドと結果

```powershell
python artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/source/audit_c3_v2_gate_b_saved_reports.py --c3-root artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3 --output-json artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/gate_b_saved_report_audit_HEAD143A4AF_REPRO2.json
```

終了コード: **0**。分類: `INTERNAL_REPORTS_REAUDITED_EXTERNAL_IO_SIGNOFF_BLOCKED`。これは保存済みreportとそのSHAを読み取るauditで、新たなQuartus compile/STA runではない。

## 確認結果

* 保存artifact manifestの10入力のidentity一致、Quartus 25.1std.0 Build 1129、SOF/QSF/SDC/flat RTL SHAを確認。
* 4 cornerの各setup/hold reportで20 reported paths、0 reported violations。corner別worst slackはJSONに保存。
* Request bundled-data route coverage: 800/800 bit index、4 corner全て。
* Response bundled-data route coverage: 480/480 bit index、4 corner全て。
* 16 ns `set_net_delay`は内部screenで、外部保証値としては扱わない。
* UCP: TDI/TMS 2 input ports、各setup/hold report 41 paths。TDOとLEDR[0/1/3] 4 output ports、各8 paths。UCPは未解消。
* Design Assistant: critical 0、high 0、medium D102 16。QSF上のD101/D102抑制なし。
* 警告code件数は監査JSONに保持。警告が解消または機能無害と証明された扱いにはしていない。

保存済みbuild全体のworst setupはslow 1100 mV/85 °C cornerで+1.803 ns。worst holdはfast 1100 mV/0 °C cornerで+0.124 ns。どちらもそのレポートが評価した制約済み内部pathの結果に限られる。30 MHz `altera_reserved_tck`はQuartus/IP内モデルで実波形ではない。

B-SIGNOFFは**BLOCKED_EXTERNAL_JTAG_TIMING_AND_UNCONSTRAINED_IO**、B-EMPIRICALは**PASS_LIMITED**のまま。DE0-CV onboard USB-BlasterのTCK period/duty、TDI/TMS phase/relative delay、TDO capture条件、board/controller delayの根拠は得られていない。

機械結果: [`gate_b_saved_report_audit_HEAD143A4AF_REPRO2.json`](../gate_b_saved_report_audit_HEAD143A4AF_REPRO2.json)。SHA-256: `506c6370c17504f9d01bf425186b2e025028f4ba879df12aabe3f7f7a3e9ae95`。別cwdからの先行実行JSONとbyte-identicalで、cwd依存の差がないことも確認した。ログと終了コードは隣接する`gate_b_saved_report_audit_HEAD143A4AF_REPRO2.log`および`.exitcode`。
