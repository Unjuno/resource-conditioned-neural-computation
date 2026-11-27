# 実行記録 — 2026-11-28

## 対象と保全

- 正repo: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
- branch: `codex/external-validation-20261122`
- start HEAD: `6ab7cdd31d2eae71ef8b1defc87a1abc69982ff7`
- tracked worktree clean。既存未追跡 `external_validation_20261122/build/physical_pilot_RUN2_preparation/` は保全。
- 旧 `kardaneh/RTnn` cwdは使用せず、書き込んでいない。
- 物理操作、JTAG、SOF/Flash、KEY0、電源、配線、oscilloscope操作なし。
- 既存SOF・ELFを再ハッシュし、SHA-256がそれぞれ `5e333e9377b7188a394d04b93b98833d91afb2cd53eca8d976e6aa715dfa00c4`、`4673f6a8b90493c15c327ed3be1167e0fcf3ff2be60292dcb12a1391124a0c2e` と一致。Q15 weight header hashはbuild manifest記載 `961a76b7e220bf2f665e7c04ab62063600aa2e7eccf3403d80ea730bc993ad9f`。

## 実行コマンドと結果

1. `py -3.11 -B artifacts/.../C3/final_research_verification_20261128/audit_primary.py schedule --cases artifacts/.../external_validation_20261122/build/host_cases_primary_attempt2/cases.csv --sequence-start 1` — 7,626件/3,813画像を凍結schedule監査。PASS。
2. `prepare_primary_schedule.py`で同じscheduleをoffline templateとしてsequence 22から再採番。metadataに `NOT_PHYSICAL_NOT_BOUND`, `binding_created=false`, `physical_authorized=false` を記録。
3. `test_primary_audit.py` — 14/14 PASS（不足・重複・順序・pixel・label・oracle・CRC・build・raw log・manifest traversal拒否を含む）。
4. `test_pilot_descriptive.py` — 3/3 PASS。RUN4の保存CSVを読むだけで検証。
5. `analyze_pilot_descriptive.py --results .../physical_pilot_RUN4_complete_20261126/physical_results.csv --out .../PILOT_DESCRIPTIVE_REANALYSIS.json` — 記述値を新dirへ出力。元RUN4は変更なし。
6. `safety_gates_v1_20261122/test_runner_preflight.py` — 4/4 PASS。PowerShell gate前拒否、Tcl gate前拒否、pilot preflight、primary binding拒否。
7. `host_v2_20261126/test_mock_runtime.py` — 1/1 PASS。Quartus STP mockのみ。production auditはmock outputを拒否。
8. `scripts/test_stats_core.py` — 初回SciPy import unavailable。その後 `PYTHONPATH=$env:TEMP/rtnn_sklearn_1_8_0` で4/4 PASS。
9. `scripts/test_physical_audit_fail_closed.py` — 2/2 PASS。
10. `test_primary_analysis.py` — offline schedule準備とphysical-run不足拒否の2テスト。
11. `PILOT_GATE_VALIDATOR.py --verify-gate .../pilot_gate_RUN4_20261126.json` — 実際のgate証拠を再読込し、`PILOT_AUDIT_PASS`、`EMPIRICAL_ONLY`。操作者申告は実行証明でない旨も確認。
12. `wsl.exe -d Ubuntu-22.04 -- bash ...` — `ERROR_NO_SUCH_DEVICE`でext4.vhdx mount失敗。起動状態変更やWSL再起動は行わず。
13. ツール探索 — Quartus Prime Lite 25.1 STPあり。C compiler（clang/gcc/MSVC）はPATHと標準位置で確認できず。実機操作なし。
14. `SHA256SUMS.txt` — 新規成果物を相対pathでhash。manifest自身は自己参照を避けるため除外。

途中、存在しない `test_audit_and_analyze.py` を指定したコマンドが一度失敗。既存コードへの影響なし。SciPyの環境エラーも依存パス指定後に解消している。

同様に `test_primary_analysis.py` の最初の実行で監査器のpackage import path不備を検出。package rootをsys.pathに追加するよう直し、その後2/2 PASS。新しく検出した問題と修正を含むfinal test countは30/30 PASS。

## 実験ファイルの境界

`primary_schedule_OFFLINE_TEMPLATE.csv` は凍結manifestからの予定表であり、実験binding・承認・実機結果ではない。RUN4 raw/CSV、旧C2J2/旧C3成果物は変更しない。mockは既存テストの一時ディレクトリ内に隔離された。

## 再現コマンド

PowerShell repository rootから:

```powershell
$d = 'artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128'
py -3.11 -B "$d/test_primary_audit.py"
py -3.11 -B "$d/test_pilot_descriptive.py"
py -3.11 -B "$d/test_primary_analysis.py"
py -3.11 -B 'artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/external_validation_20261122/safety_gates_v1_20261122/test_runner_preflight.py'
py -3.11 -B 'artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/external_validation_20261122/host_v2_20261126/test_mock_runtime.py'
$env:PYTHONPATH = Join-Path $env:TEMP 'rtnn_sklearn_1_8_0'
py -3.11 -B 'artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/external_validation_20261122/scripts/test_stats_core.py'
Remove-Item Env:PYTHONPATH
py -3.11 -B 'artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/external_validation_20261122/scripts/test_physical_audit_fail_closed.py'
```
