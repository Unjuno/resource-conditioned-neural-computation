# RTNN 最終研究検証 — 2026-11-28

## 判定

* primary予定表: **PASS_OFFLINE_ONLY** — 凍結manifest・pixel bytes/SHA・host-only label・Q15 oracle・mode順・CRC・identityを7,626行すべて照合。これは実機データではない。
* 保存済みRUN4 pilot: **PASS_LIMITED_FUNCTIONAL_EVIDENCE** — 今回 `PILOT_GATE_VALIDATOR.py --verify-gate` を保存gateに対して再実行し、20要求、10画像、oracle一致を再検証。raw応答も新しい監査器で再デコードし、pair/counter/CRC/ID/framingを独立点検した。
* PowerShell/Tcl fail-closed: **PASS_OFFLINE** — primary gateなしのPowerShell起動、binding作成、Tcl直接起動は機器検出前に拒否する既存試験がPASS。Tcl runtime mockは隔離tempでのみ20件を完走し、production監査ではmock拒否。
* 新しいprimary実機評価: **NOT_RUN** — primaryを実行する承認は今回確認できていない。過去のSRAM＋pilot許可はprimaryに及ばない。
* 主張適格性: `DATA_EXPOSURE_UNCERTAIN`; `WRITER_CLUSTER_UNKNOWN`; `PREREGISTRATION_TIMELINE_UNVERIFIED`; `COLD_BOOT_UNVERIFIED`; `FORMAL_TIMING_SIGNOFF_BLOCKED` を維持。
* 停止方式比較（confidence/margin/entropy/oracle）の新しい同一Q15再計算: **BLOCKED_TOOLCHAIN/LOGIT_ARTIFACT**。host Q15 oracle保存物は実行された出力だけで、全exit logitsを含まない。C compilerが見つからず、WSLはext4.vhdx mount時 `ERROR_NO_SUCH_DEVICE`。浮動小数や別モデルで代用していない。

## pilot保存値の記述的再集計

RUN4の既存`physical_results.csv`のみから再生成: fixed2/adaptive各10件で教師ラベル正解は各10/10、adaptiveのcycleが少ない入力8/10、ID 519・667では各127,563 cycle多い。fixed2中央値943,906、adaptive中央値565,923、ratio-of-sums記述削減率29.33%。選択pilot 10入力・単一電源epochの記述値であり、信頼区間・非劣性・一般的速度優位を示さない。実機の新しい操作は一切実行していない。

## 新規成果

このディレクトリに独立primary/raw JTAG監査器、schedule generator、負例テスト、pilot再集計器、primary post-run解析器、1-session exploratory amendment草稿、形式証拠対応表、英語論文addendum、claim-evidence matrixを保存した。オフライン予定表はsequence 22–7647。sequence 2–21はRUN4、RUN2/3の失敗ログはsequence 1を使った記録に基づく。これは現在FPGA状態の読み出しではないため、実機前にsequence状態確認が必要。

## 実行した検証

* `py -3.11 -B .../test_primary_audit.py`: 14/14 PASS。
* `py -3.11 -B .../test_pilot_descriptive.py`: 3/3 PASS。
* `py -3.11 -B .../test_primary_analysis.py`: 2/2 PASS（offline scheduleとphysical-run欠落拒否）。
* `py -3.11 -B .../safety_gates_v1_20261122/test_runner_preflight.py`: 4/4 PASS。
* `py -3.11 -B .../host_v2_20261126/test_mock_runtime.py`: 1/1 PASS、Quartus STP mock runtime。
* `PYTHONPATH=$env:TEMP/rtnn_sklearn_1_8_0 py -3.11 -B .../scripts/test_stats_core.py`: 4/4 PASS。
* `py -3.11 -B .../scripts/test_physical_audit_fail_closed.py`: 2/2 PASS。
* 合計30/30テストPASS。RUN4 gate validatorも独立再検証PASS。

最初のstats-core実行ではSciPyが既定Python環境に無く2件が環境エラーになった。保存済みSciPy依存環境をPYTHONPATHで指定して再実行し4/4 PASS。存在しないテストファイル名を誤って指定した1コマンドもあり、ファイルを変更せず停止。詳細は`RUN_RECORD_JA.md`。

## 残る人手作業

1. primaryを実施するかどうか、規模（提案1 session exploratory）と明示承認を決める。
2. その決定前にamendmentをレビューし、primary結果を見る前に署名/時刻/SHA/適用commitを固定する。
3. 実機の新build・mailbox状態・次sequenceをread-onlyで確認し、許可されたら新しいprimary bindingを作る。
4. 7,626件を実機で実行してから`audit_primary.py run`、続いて`analyze_audited_primary.py`を実行。mockは不可。
5. alternate stopping rule比較をする場合、同一Q15の全exit integer logitsとコンパイラ実行可能環境を用意し、validationで閾値を決める。
6. writer ID/データ来歴、外部JTAG timing仕様、正式STA/WCETは別の証拠を入手しない限り未確定。

この時点ではprimary性能結果や確認的仮説の最終判定を報告できない。研究報告は、既存のソフトウェア/RTL scope内の形式・測定証拠と、10画像pilotの限定機能デモに限定する。
