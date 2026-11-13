# Gate B isolated Quartus reproduction — additional run record

日時: 2026-11-14 JST
正本repo: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
Branch: `codex/stage-c3-repro-timing-20261114`
実行cwd: `D:\RTNN_C3_GateB_STA_rebuild_20261114`
元入力: `artifacts/experiments/de0_cv_c1_c2_audit_20261114/C2/evidence/quartus_d101/`

## 再現コマンドと環境

```powershell
& 'C:\altera_lite\25.1std\quartus\bin64\quartus_sh.exe' --flow compile rtnn_c2
& 'C:\altera_lite\25.1std\quartus\bin64\quartus_sta.exe' -t c3_mtbf_detail_20261114.tcl
```

Quartus Prime Lite 25.1std.0 Build 1129。実行前に保存済みexact-node構成のQSF、SDC、flat RTL、top RTLをscratchへ複製しhash一致を確認した。QSF `9d270c2f...`, SDC `8ba18e98...`, flat RTL `fdfcdf03...`, top RTL `639e5811...`。QuartusはD:の新規隔離先で実行し、元証拠の成果物を上書きしていない。

## 結果

* Full compile exit 0、Fitter/Assembler/STAを実行。Quartus logは392 warnings、0 errors。全warningは `quartus_compile_rerun.log` に保存。特にWarning 292013（LogicLockのsubscription licenseなし）と15714（不完全I/O assignment）が残る。pass statusだけでなく既存のタイミング・I/O制約限界をGate B判定へ反映する。
* 再生成SOF SHA-256 `15bdd8462f1a2c6fbad92b0ca0df7b2007790aa1d91e275fd6244bbcbc53132`。実機42件に対応づけられたSOF SHA `5aa5be2e...` と不一致のため別buildである。今回の再生成SOFは未書込み。
* `report_metastability -nchains 1000` exit 0。全392 chain詳細報告（31,751,098 bytes）をscratch内 `c3_mtbf_all_chains.rpt` に保存。SHA-256 `00120db779ae93c5aaf3bc083bbaFD8259cdf2c3ffda5cdd9920ca328faef038`。抽出chain summary CSVは392行、SHA-256 `d11668beeaffde1744313c0275412473550ac5e20221174be7734d082fdc8656`。
* summaryでは9/392がMTBF計算済み、383/392（0.977）がNot CalculatedかつDesign MTBFに未包含。未計算行は`response_words_q[...]`から`rsp_hold_tck_q[...]`へのpayload経路で、詳細は自動識別されてpayload hold、shift register、SLD hub TDOまでを同一chainに含めている。これはQuartusの分類結果であり、payload CDCのMTBFまたはbundled-data保持保証ではない。9件のcalculated chainがあることも残り383件の保証に広げない。
* full compile log SHA-256 `9553fbe238581b4a28b341f64f120bc548ee980fa0ccfbd05394defd488e9f76`; Fitter report `38a7cceab8498f5d289d100a5cd664200f500ed957d9e6f16585575054919e31`; STA report `cbf4b2dd08377340b4039e411b6a6c83fbb84260e0e61f532f11889b9b1e0e9d`.

## 判定と保全

再現compileの実行成功はPASS。Gate B全体はBLOCKEDのまま。JTAG external timing/TDO capture assumptions、未制約I/O、async group cutによるcross-clock setup/hold・skew未確認、response-side firmware source-hold条件が未解決。383 payload auto-chainsは独立したscalar synchronizerとしてMTBF対象に扱わず、bundle capture envelopeの別監査結果として記録した。C3の実機書込み、42ケース再確認、360入力campaignはNOT_RUN。Flash/CFMに対する操作なし。

31.7 MBの生metastability report、392行summary、fit/STA/compile生ログ、生成物は上記D:隔離run領域に保全し、Gitには数十MBのquartus report/cacheを追加しない。`compile_reproduction_command.txt`とTcl、exit sentinel、hashは同ディレクトリにある。隔離run領域を削除・移動していない。


## Bundled-data audit script rerun

`audit_bundled_capture_envelope.py` was run from the repository root against the exact flat RTL and four-corner path data, with the preserved full Quartus report and 392-row summary as independent hash inputs. Command:

```powershell
python artifacts/experiments/de0_cv_c1_c2_audit_20261114/C2/evidence/audit_bundled_capture_envelope.py --mtbf-summary artifacts/experiments/de0_cv_c1_c2_audit_20261114/C2/evidence/mtbf_chain_summary_392_20261114.csv --mtbf-report D:\RTNN_C3_GateB_STA_rebuild_20261114\c3_mtbf_all_chains.rpt --output artifacts/experiments/de0_cv_c1_c2_audit_20261114/C2/evidence/bundled_capture_envelope_audit_20261114.json
```

Exit 0; JSON result `PASS_BUNDLE_ENVELOPE_ONLY`, while overall Gate B remains `BLOCKED`. The audit verifies all 392 summary rows (9 calculated/included, 383 uncalculated response-payload auto chains), all four corners and 800/384 endpoints, exact flat RTL SHA, full report SHA, and summary SHA. The first attempt exited 1 because the preexisting summary digest in this run record and the new script constant had a transcription error; the raw CSV's independently recomputed digest is `d11668beeaffde1744313c0275412473550ac5e20221174be7734d082fdc8656`. The failure note is retained at `D:\RTNN_C3_GateB_STA_rebuild_20261114\bundle_envelope_audit_initial_failure.txt`; no RTL, Quartus inputs, or board state changed.

The JSON is a bundle-envelope check only. Its difference values are explicitly not STA slack, and it does not resolve board-level JTAG timing, the SLD asynchronous clock-group cut, or the firmware response-source hold assumption.
