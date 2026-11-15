> **履歴snapshot:** この文書は基板を触らずに行った解析時点の記録です。KEY0 reset replayは後日PASSしました。現行判定は[C3_CURRENT_STATUS_20261115_POST_KEY_RESET_RUN3_JA.md](C3_CURRENT_STATUS_20261115_POST_KEY_RESET_RUN3_JA.md)と[evidence run record](evidence/PHYSICAL_C3_V2_20261115/KEY_RESET_REPLAY/C3V2_TENINPUT_KEY_RESET_REPLAY_20261115_RUN3/RUN_RECORD_JA.md)を参照してください。`PENDING_HUMAN_ACTION`は当時の状態です。

# RTNN Stage C3 現在地 — 基板なし解析更新 2026-11-15

## Repositoryと今回の範囲

* Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
* Branch: `codex/stage-c3-jtag-pilot-20261114`
* HEAD at start: `b332ba02ab992227140998a1d67513c690ae17cf`; originは正しいUnjuno repository。今回read-only `git ls-remote`で専用remote branchも同じHEADと確認。
* 開始時worktreeはclean。今回の成果はローカル未commit。push/PR/mergeなし。
* 基板に接続せず、JTAGアクセス、KEY操作、SOF書込み、電源/配線変更なし。
* 旧`C3_CURRENT_STATUS_20261115_JA.md`は前回時点の履歴snapshotとして保管。このファイルが現行status。

## 最新ゲート

| 工程 | 状態 | 根拠 |
|---|---|---|
| B-SIGNOFF | **BLOCKED** | 外部JTAG path timing未確定。保存済みSTAは内部制約範囲の結果。 |
| B-EMPIRICAL | **PASS_LIMITED** | 前回C3 v2 build `43334531`の限定pilot適格判定。今回の独立監査はこれを格上げしていない。 |
| B保存レポート再監査 | **内部経路LIMITED PASS / signoff BLOCKED** | 4 corner、req 800/800・rsp 480/480各cornerのroute index、16 ns内部screen、UCP、D102と警告を独立再集計。別作業領域へ318ファイルをSHA一致で複製してQuartus STAのみを再実行し、response selector 484件の内訳を480 logical bits＋4 `~DUPLICATE` fitter registersとして照合。各cornerで480 bit indexを一意にroute。Altera Timing Analyzer Cookbookも照合したがDE0-CV内蔵Blaster外部遅延は未確定。LEDR/UCP/Fitter警告は保持。[Gate B監査](evidence/GATE_B_C3V2_AUDIT_20261115/GATE_B_AUDIT_JA.md)、[D102 selector再照合記録](evidence/GATE_B_D102_SELECTOR_RECHECK_20261115/RUN_RECORD_JA.md)。B-SIGNOFFは外部JTAG I/O timing未制約でBLOCKED。 |
| Gate B 59-source evidence audit | **PASS_FOR_REPORTED_EVIDENCE_ONLY / B-SIGNOFF BLOCKED** | 親commit `c17c44e`で行われた保存監査を、現在のHEAD `b332ba0`から同一監査器で再実行。59ファイル、13 binding、24,840 frozen rows、4 setup/hold corner、16 D102を再照合し、同じ未制約TDI/TMS/TDO・LEDRを確認。[現HEAD再監査](evidence/C3_GATE_B_EVIDENCE_AUDIT_20261115_CURRENT_HEAD/RUN_RECORD_JA.md)。 |
| bundled-data source hold sequence | **LIMITED — fixed firmware sequenceのみ** | requestはsync ACKまで、responseはcommit後のfirmware pollとhost consumeまで保持する経路をRTL・firmware・42-case TB assertions・4-corner route reportで対応付け。[詳細](evidence/GATE_B_C3V2_AUDIT_20261115/BUNDLED_DATA_HOLD_SEQUENCE_20261115_JA.md)。SoC response MMIOはcommit後の任意CPU書込みをハードウェアでlockしないため、この保持は固定firmwareの動作に依存する。finite simulationでありformal proofではない。 |
| 未制約I/O disposition・status chronology | **分類明確化、UCP/signoff状態変更なし** | TDI/TMS/TDOは外部JTAG timing不足の機能端点。LEDR[0/1/3]は基板表示LEDで外部同期receiverなしだが、UCP件数とFitter drive/slew警告は残す。11/14 manual reviewのB-EMPIRICAL blocked記述はHEAD `efe93a6`当時の記録。後続C3 v2 64-bit response buildのpilot適格性`PASS_LIMITED`とは範囲が異なる。native 146-source graph再buildは未解決。[再照合記録](evidence/GATE_B_C3V2_AUDIT_20261115/UCP_AND_STATUS_CHRONOLOGY_RECHECK_20261115_JA.md)。 |
| Altera公式JTAGガイド再確認 | **追加根拠、signoff BLOCKED維持** | Quartusの公式ガイドは実際のJTAG setup/deviceに基づくI/O delayを要求するが、対象は別製品USB-Blaster IIIで、DE0-CV内蔵経路の値ではない。TDO例の方向もそのまま転用しない。[再確認記録](evidence/GATE_B_C3V2_AUDIT_20261115/OFFICIAL_GUIDANCE_RECHECK_20261115_JA.md)。 |
| Terasic System CD retained ZIP再検査 | **PASS — archive identity / timing asset未検出（検査範囲限定）** | 保管ZIPのSHA-256とZIP CRC、1,089 member、選択PDF/SOF/DLLを照合。6 QSF/QPFはCyclone V device、86 Verilog・75 SystemVerilog等のテキストproject/source scanでEPM240/MAX II/USB-Blaster語を検出せず。scanはbinary reverse engineeringをしない。[記録](evidence/JTAG_CONTROLLER_PACKAGE_RECHECK_20261115/RUN_RECORD_JA.md)。 |
| 旧C2J2 24,840行 | **再集計PASS / EMPIRICAL_ONLY** | build `43324a32`, SOF `5aa5be2e...`; 13/13 schedule、24,840/24,840行、保存RUN4/RUN5結合集計と行単位一致。primary_02–10は6,480行。 |
| C3 v2保存42件 | **再監査PASS** | experiment `C3V2_C2J2_REPLAY_RUN2_20261115`; build `43334531`, SOF `85c5fd08...`; 42/42。 |
| C3 v2 pilot SESSION1 | **再監査PASS** | experiment `C3V2_TENINPUT_PILOT_SESSION1_20261115`; 20/20。KEY reset前session。 |
| C3 v2 KEY-reset replay | **PENDING_HUMAN_ACTION** | 今回未実施。gate未生成。 |
| 新C3 v2 24,840行物理campaign | **NOT_RUN (0 rows)** | reset replay gate未成立。旧C2J2実測を流用しない。 |
| 旧C2J2 accuracy非劣性 | **INCONCLUSIVE** | 339/360 each; paired 95% interval ±1.389 pp; 事前1 pp margin未達。 |
| 旧C2J2速度仮説 | **未主張** | 差のinput bootstrapは条件付き記述値。cold-boot独立性要件が不足。 |
| native 146-source再build可能性 | **NOT_REPRODUCIBLE_YET** | 保存source listの141 Ibex依存が古い`/opt/rtnn-tools/ibex`を指し、正本repo内に存在せず依存commit/SHAが不明。 |

## 今回の成果

独立再集計・論文図表・入力ごとの遅い/速い表は[解析報告](OFFLINE_REPRO_20261115/ANALYSIS_AND_REPRODUCIBILITY_REPORT_JA.md)と`campaign/analysis/C3_C2J2_INDEPENDENT_REAUDIT_20261115_RETRY05/`。primary paired cycle差、分布、Exit-cycle、教師ラベルaccuracy-cycleのSVGを旧C2J2保存データから再生成した。C3 v2の本測定図は作っていない。C3 v2の保存Quartus/STAレポートも[独立監査記録](evidence/GATE_B_C3V2_AUDIT_20261115/GATE_B_AUDIT_JA.md)の通り再パースしたが、外部JTAG I/Oは未制約のためsignoffはBLOCKEDのまま。今回のoffline reports、コード、ログ、全再集計試行のhashは[`SHA256SUMS.txt`](OFFLINE_REPRO_20261115/SHA256SUMS.txt)に記録。

C3 v2の厳密な保存結果checker、13件の負例・再現性test、reset gate作成器は`source/`に追加。テストと実行ログ、2本の独立監査JSON、source path mappingは`OFFLINE_REPRO_20261115/`。Quartus STP 25.1 Build1129でidentity Tclの自己試験を実行しexit 0。`--self-test`分岐でJTAG APIは呼ばず、基板アクセス0回。

旧`C3_FULL_CAMPAIGN_RUN_RECORD_JA.md`の`primary_02–primary_10=7,200`行は9×720から**6,480**へ訂正。変更は報告文だけで、元CSV/JSON/raw logは不変。総数24,840は全データから確認。

## 次の必要作業

ユーザーがDE0-CVの前へ戻った後、[KEY reset後の実機再開手順](C3_RESTART_AFTER_KEY_RESET_JA.md)を使う。手順はread-only build ID/READY確認 → 人がKEY[0]を押して離す → 同じ20 caseを新experiment IDで実行 → PowerShellとPythonで独立監査 → 実結果SHAからだけreset gate JSON生成 → gate後に凍結campaign、の順。

KEY reset、SOF SRAM再設定、完全電源断は異なる操作として記録する。gate作成器は既存pilotのexperiment IDではgateを作れない。外部JTAG保証、cold-boot不確実性、1 pp精度非劣性をPASSにはしない。

