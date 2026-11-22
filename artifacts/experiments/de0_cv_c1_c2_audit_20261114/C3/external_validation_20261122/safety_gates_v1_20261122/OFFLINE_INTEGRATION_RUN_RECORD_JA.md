# Offline integration run record

作業対象は正しいRTNN repoの`codex/external-validation-20261122`、開始HEAD `bd18c421d8a865eb85b32f3bfc8f445c4412bfeb`。originは `Unjuno/resource-conditioned-neural-computation`。

実行コマンド:

```powershell
python .\safety_gates_v1_20261122\test_safety_gates.py
python .\safety_gates_v1_20261122\test_runner_preflight.py
```

結果はそれぞれ21/21、4/4 PASS。既存の `test_external_host.py` は5/5、`test_physical_audit_fail_closed.py` は2/2 PASS。合計32 tests PASS。後者2 suiteでは実Quartus STP Tcl 25.1 processを用いたgate欠落経路のみ。実験基板、JTAG API、SOF/Flash、KEY0、電源にはアクセスしていない。PowerShellでは起動sentinelが作成されず、出力先も作成されなかった。Tcl source order assertionはpilot validatorがJTAG packageロードとhardware discoveryより前であることを検査した。

保存済みphysical pilotは存在しない。`build/host_cases_pilot_attempt2/cases.csv`は`OFFLINE` sessionの準備caseであり、production pilot gateの生成元として拒否される。テストfixtureはtemporary directory内だけで使い、production CLIのfixture bypassはない。

`DATA_EXPOSURE_REVIEW_JA.md`の検索は `git log --all -S'optdigits.tra'` とextvalパッケージ以外の追跡ソース検索で行った。`sklearn.load_digits`利用は過去ソースにある一方、`optdigits.tra`追跡使用は見つからない。未記録利用とwriter clusterは未解決。

時系列監査ではlocked prereg文書のローカル時刻03:57、CPU oracle CSVの時刻04:06、firmware prediction CSVの時刻04:24を確認した。これは同一PC上の編集可能なfilesystem metadataであり、先行固定を独立に証明しない。関連ファイルを含むGit commitは05:53のため、確認的事前登録の順序は未検証とし、将来の評価は探索的扱いを維持する。

この記録はオフラインの構造検証に限る。記録されたphysical JTAGログの自己申告欄も暗号学的な物理証明ではない。
