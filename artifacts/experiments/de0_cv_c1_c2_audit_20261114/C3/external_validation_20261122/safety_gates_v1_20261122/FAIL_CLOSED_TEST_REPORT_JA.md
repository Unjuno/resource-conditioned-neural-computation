# Fail-closed test report

日時: 2026-11-22 (Asia/Tokyo)

## 実行

```text
python safety_gates_v1_20261122/test_safety_gates.py
Ran 21 tests — OK
python safety_gates_v1_20261122/test_runner_preflight.py
Ran 4 tests — OK
python scripts/test_external_host.py
Ran 5 tests — OK
python scripts/test_physical_audit_fail_closed.py
Ran 2 tests — OK
```

正のfixtureは一時ディレクトリ内で、`fixture_only=true`を含む。検証関数のテスト専用引数で整合性を確認しただけで、production CLIにはfixture bypassがなく、production modeでfixtureを使ってgateを生成できない。

検査した拒否条件：未完了・mock・旧build、手書きPASS、不正JSON、改ざん/欠落したrawログ、raw CRC/framing異常、CSV予測改ざん、pilot/primary混在、20件未満、binding/SOF mismatch、primary gateなし、primary case件数変更、session名だけ、KEY0/SOF再設定、operator申告のみ、USB状態不明、rail波形SHA不一致、同一波形SHAのsession再利用。

PowerShell wrapperはgateの検証に失敗するとQuartusプロセスを起動せず、出力先も作らないことをsentinel試験で確認した。primary binding生成もgateなしで停止した。

Quartus STP Tclのdirect invocation試験は非0終了し、物理出力を作らなかった。Tclソース順序もgate verifier → `package require ::quartus::jtag` → `get_hardware_names`であることを検査した。Quartus STP 25.1の終了時に内部の `fil_test` package loader診断が出るため、ログ上の拒否メッセージそのものは安定したassertionに使っていない。JTAG APIの呼出し・デバイスopenは実施していない。

## 判定

* `PILOT_GATE_IMPLEMENTATION_PASS`
* `PRIMARY_RUNNER_FAIL_CLOSED_PASS` — PowerShell実行、Tcl直接起動、binding作成の入口を個別に拒否確認。
* `POWER_EVIDENCE_CLASSIFICATION_PASS`
* `PHYSICAL_DATA_AUDIT_FAIL_CLOSED_PASS` — fixture/raw recordsの構造監査。実測のPASSではない。
* `OFFLINE_INTEGRATION_PASS` — 32/32 across new gate unit tests, PowerShell/Tcl/binding preflight, and existing host/audit regression tests.
* `PHYSICAL_PILOT_NOT_RUN`
* `FORMAL_TIMING_SIGNOFF_BLOCKED`
