# 実機パイロット事前照合 — 2026-11-26

## 結果

非物理preflightは `PREFLIGHT_ONLY` で終了した。20要求、pilot用10入力×`fixed2`/`adaptive`の組合せ、primaryとの入力重複なし、出力先未作成を確認した。runner出力は `physical_jtag_started=false`。JTAG通信、基板操作、SOF設定は行っていない。

| 項目 | 照合値 |
|---|---|
| Repository / branch | `Unjuno/resource-conditioned-neural-computation` / `codex/external-validation-20261122` |
| HEAD | `b8c7e0a54b545bf75591497adcfc6ff4aabbbbf3` |
| Board target | Terasic DE0-CV / Cyclone V `5CEBA4F23C7` |
| Build / Binding / Model ID | `45585631` / `45585632` / `52544e4e` |
| SOF SHA-256 | `5e333e9377b7188a394d04b93b98833d91afb2cd53eca8d976e6aa715dfa00c4` |
| ELF SHA-256 | `4673f6a8b90493c15c327ed3be1167e0fcf3ff2be60292dcb12a1391124a0c2e` |
| Preregistration SHA-256 | `5005c80c6d2d8eefbf87dd4dfdb4c91e26adb7960a3e5b1f04a977fdaee3b33b` |
| Pilot case CSV SHA-256 | `26259e278370cbf98377abad3e4ce5612645dec26f4ea1482a23b0774077eb37` |
| Pilot experiment / session | `C3_EXTVAL_PILOT_20261122_RUN1` / `PILOT_SESSION_01` |
| Pilot cases | 20 rows, 10 distinct IDs: `57, 277, 321, 519, 525, 667, 921, 1673, 3660, 3689` |
| Primary overlap | 0 IDs (primary CSV: 7,626 rows) |

Preflight command (物理実行フラグなし):

```powershell
pwsh -NoProfile -File "$p\host\Invoke-ExternalValidation.ps1" `
  -CaseCsv "$p\build\prepared_pilot_cases_attempt1\cases.csv" `
  -BindingJson "$p\build\bindings\pilot_run1_binding.json" `
  -OutputDirectory "$p\build\physical_pilot_RUN1"
```

runner結果: `status=PREFLIGHT_ONLY`, `case_count=20`, 上記CSV/SOF SHAと実験IDが一致、`physical_jtag_started=false`、exit code `0`。pilot出力先 `build/physical_pilot_RUN1` は未作成である。

## 停止理由

実機でのSRAM設定・測定は、ユーザーが基板の前で明示許可するまで行わない。今回、その許可と実機実施を確認していない。`pilot_run1_binding.json`は手順どおり選んだが、`pilot_binding.json`（OFFLINE用）は使用していない。

この照合はホスト上のファイルidentityを確認しただけで、基板にロード済みのSOFや物理JTAG接続を証明しない。
