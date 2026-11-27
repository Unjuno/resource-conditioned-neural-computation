# Primary測定前監査の強化 — RUN1 (2026-11-28)

## 判定

**OFFLINE_PRIMARY_GUARD_PASS_LIMITED / PHYSICAL_PRIMARY_NOT_RUN**。primary開始ゲートにあったcase内容の検証不足を補った。実機、JTAG、SOF、Flash、電源、KEY、配線には触れていない。primaryの規模選択と物理実行許可は保留中。

## 開始時の対象

- Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
- Branch: `codex/external-validation-20261122`
- HEAD: `bd168ff3e6f1357eb41601d29ec232240637eab2`
- 使用runner: `host_v2_20261126/`。旧`host/`のTcl SHAは`cc3ee768...`、成功版Tclは`587c6b50...`で異なり、旧版には成功版に含まれる複数修正がない。手順書の誤誘導を追記で訂正した。
- 未追跡の`build/physical_pilot_RUN2_preparation/`は変更・stageせず保全。

## 実装

1. `safety_gates_v1_20261122/pilot_gate.py`
   - primaryの7,626行を既存case順テンプレートと照合。
   - 3,813画像の固定manifest、連結pixel bytes、教師ラベル、SHAを行ごとに照合。
   - `oracle_primary.csv` の prediction、admitted/executed Exit、stop reason、cap violation 0をmode・入力ごとに照合。
   - payload CRC、sequence連番、開始値、保存済みraw JTAG logsから読める最大sequenceを検査。保存ログにある最大観測値21より後を使い、最初の利用可能値22からのscheduleを正常系fixtureで確認。
   - malformedな過去request行があれば履歴不明として停止。primary bindingには入力・oracle・順序・sequenceの` schedule_identity`を必須化。完了runの再監査では後続session sequenceを許容し、他runとの重複だけを拒否する。新規schedule作成では保存済み最大sequenceより後を要求する。
2. `scripts/create_physical_binding.py`
   - binding作成前に上記のprimary schedule validatorを実行し、検証identityをbindingへ格納。
3. `scripts/prepare_primary_execution.py`
   - offline順序templateから新しいexperiment/session IDと明示sequence startを使い、7,626件のcase CSVを新規生成するCLIを追加。既存出力は拒否。これは物理runデータを作らない。
4. `scripts/audit_and_analyze.py`
   - primary auditでraw JTAG request/responseを復号し、frame、CRC、mode/budget/deadline、sequence、画素、model/build/binding、prediction/Exit、mcycle start/end/deltaとCSVを全件照合。
5. `test_safety_gates.py`, `test_runner_preflight.py`, `test_physical_audit_fail_closed.py`
   - pixel/label/oracle/order/sequence改変、used sequence、上書き、raw frame欠損・CRC破損を追加で拒否する。
6. `OPERATOR_RUNBOOK_JA.md`
   - 成功版`host_v2_20261126`を使うこと、古いtemplateを直接実行しないこと、次sequence履歴を再確認することを追記。旧手順は歴史記録として残す。

## 検証

実行コマンド（作業ディレクトリは`external_validation_20261122/`）:

```text
python -m unittest safety_gates_v1_20261122.test_safety_gates safety_gates_v1_20261122.test_runner_preflight scripts.test_physical_audit_fail_closed host_v2_20261126.test_mock_runtime -v
```

**35/35 PASS**。内訳: pilot/power gate 23、PowerShell/Tcl/binding/schedule preflight 7、raw primary audit fail-closed 4、host_v2 mock protocol 1。production pilot gateをprimary bindingへ結合し、CPU oracleケース改変をprimary preflightが拒否する正常/負例も確認。直接Tcl testはpilot gate verifier呼出しがJTAG package load・device discoveryより前であることも確認。Mock runtimeはoffline fixtureだけで、実機測定ではない。

`python -m py_compile` も`pilot_gate.py`、`create_physical_binding.py`、`audit_and_analyze.py`でPASS。生pilot RUN4ログをraw parserの形式fixtureとして再照合し、20 request/20 responseを確認。さらに隔離した合成protocol fixtureでprimary 7,626 request/response全件をparserへ通した。mock dataは`load_run`へ渡しておらず、物理結果に昇格していない。

テストログはこのdirectoryの`offline_tests_pass.log`に保存。途中の失敗試行2件も`offline_tests_initial_failed.log`と`offline_tests_final.log`として保持し、最初の失敗は出力パス配置、次は同パス残存とWindows subprocess encodingのテストハーネス問題だった。修正後の最終一式は35/35 PASS。

## 範囲と残る条件

- 検証はtracked local source/logを信頼境界としてcase integrityを確認する。ファイル一式を改ざんしてSHAも再計算した攻撃者や物理取得の真実性を暗号学的に証明するものではない。
- `host_v2`自身のPS/Tclを変更せず、preflight経路が共有するPython validatorを強化した。PSとdirect Tclの結合テストを実行した。
- primary case CSV/bindingをproduction出力先へ作成していない。選択scope・experiment ID・live board identityを確定していないため。
- 1-session amendmentは未承認/未固定。元の3-session preregistrationも維持。
- `DATA_EXPOSURE_UNCERTAIN`、`WRITER_CLUSTER_UNKNOWN`、`PREREGISTRATION_TIMELINE_UNVERIFIED`、`COLD_BOOT_UNVERIFIED`、`FORMAL_TIMING_SIGNOFF_BLOCKED`は維持。

## 不変条件

C1/C2/C3過去証拠、既存実機RUN4、SOF、ELF、Q15 weight、frozen dataset/manifest/oracleは変更していない。今回の変更はrunner前段の監査とオフラインテスト・runbookに限定。


## SHA manifest

`SHA256SUMS.txt` lists 25 modified/added source, tests, run records, logs, and protected build/data identities (SOF, ELF, Q15 weights, pilot gate, frozen primary manifest/input/oracle/order). Each listed entry was rehashed from the repository root. The manifest does not hash itself.
