# RTNN Stage C3 現在地 — 2026-11-15

## 対象と履歴の保全

- Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
- Branch: `codex/stage-c3-jtag-pilot-20261114`
- 現在のHEAD: `c17c44e5556acc9c9e2d4fdbd114714c9c1ad804`
- 指示で報告された`9af7c44daa3f69ace0abefa899b12effefc5ae7b`は現在HEADの祖先。現在HEADの作業ツリーを継続し、checkout/reset/cleanはしていない。
- originは上記Unjunoリポジトリ。別所有者の`kardaneh/RTnn`作業場所には今回も書き込んでいない。
- 改訂計画は`c17c44e...`を基準にする。この報告とC3 v2追加証拠はローカル未コミットの作業ツリーに保存中。commit/push/PR/mergeは未実施。
- 827件の既存C1/C2証跡、C2J2実機ログ、旧SOFと過去の24,840件記録を上書きしていない。

## ゲート判定

| ゲート | 判定 | 根拠と境界 |
|---|---|---|
| B-SIGNOFF | **BLOCKED** | オンボードUSB-Blasterの実TCK周波数・duty、board/cable側TDI/TMS/TDO外部タイミング未確認。TimeQuestではJTAG外部I/Oに加え、推論経路外のLEDR[0/1/3]も未制約。全体の正式signoff・WCET・hard-deadlineは主張しない。 |
| B-EMPIRICAL | **PASS_LIMITED — SRAM-only pilot適格** | C3 v2 counter、同一buildのnative/sv2v/Quartus-flat回帰、Fitter、内部4-corner STA、CDC保持・captureレビュー、response/CRC/reference検査、host failure loggingを確認。適格性は次の物理pilotを許す範囲に限定。360 campaignの開始判定ではない。 |
| 旧C2J2 42件の保存結果 | **PASS（旧buildの履歴）** | 旧SOF/buildでの保存済み42/42記録。C3 v2実機結果へ読み替えない。 |
| C3 v2 42要求シミュレーション | **PASS** | native SystemVerilog、`sv2v`変換後、Quartus flatの各回帰で42要求、負例、reset再実行を確認。これは実機試験ではない。 |
| 凍結360 campaign host dry-run | **PASS_HOST_DRYRUN_NOT_PHYSICAL** | 13 schedules、24,840行、canonical SHA一致。 |
| C3 v2 campaign SOF binding audit | **PASS_HOST_BINDING_AUDIT_NOT_PHYSICAL** | 13 scheduleすべてで各CSVが元host dry-runとbyte一致。build/model/SOF SHA、各binding/case SHAを照合。物理取得0行。reset replay完了まで開始gateを保持。 |
| C3 v2実機42要求再確認 | **PASS 42/42** | 新SOFをSRAMへ設定し、ID 0/24/57、予測/Exit/CRC/要求応答ID/64-bit cycleを独立監査。旧buildの履歴42件と混同しない。 |
| 10入力pilot session 1 | **PASS 20/20** | `primary_01`から事前選定したID 1–10。各IDの固定Exit 2と同じIDのadaptive行。厳密JSON+CSV/raw監査PASS。 |
| 10入力pilot KEY-reset replay | **PENDING** | KEY[0]リセット後に同じ20要求を再実行する。今回は電源再投入しない。 |
| 360入力campaign | **NOT_RUN** | C3 v2 pilot後、SOF結合済みbindingを作成してから開始する。 |

Gate Bの一次TimeQuest/Design Assistant報告を今回読み直した監査記録は`evidence/C3_GATE_B_REAUDIT_20261115_JA.md`。4 cornerの内部STA値、16 D102 bundled-data警告、41 input paths/8 output pathsの未制約状態と、B-SIGNOFF/B-EMPIRICALの分離を記録している。

同監査記録へIntel Cyclone V Device Datasheet 683801 Table 56のFPGA TAP側JTAGタイミング値も追記した。TCK周期・pulse width・FPGA入力setup/hold・TDO clock-to-outputは公開仕様で分かったが、DE0-CV上のMAX II/FT245経路、基板revision別遅延、実際のTCK波形は別仕様のため、B-SIGNOFFは引き続きBLOCKED。Terasic向け未送信案はこの既知のFPGA値を除き、controller/board pathの仕様確認に絞った。

既存のC2 JTAG timing follow-upも再利用し、EPM240 speed grade −3/−4/−5と3.3-V LVTTL/10-pF条件の`tCO max` 4.3/5.6/6.9 nsを記録した。回路図と公開ZIPは搭載suffix、CPLD logic, TCK/data relative skew, board trace delayを確定しない。CPLD`tCO`単独から外部port delayを設定しない。

## C3 v2 hardware/software identity

新しいbuild ID / binding IDは`43334531`、model IDは`52544e4e`。requestは800 bit、responseは60 byte。旧C2J2 build `43324a32`と混同しない。

| artifact | SHA-256 |
|---|---|
| C3 v2 SOF（SRAMへ設定済み。Flash/CFM未変更） | `85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d` |
| C3 v2 ELF | `9cbf537bd9440deaf5c78abf6b204da9cbcd2fe3795acf444d733dbd581002b6` |
| C3 v2 BIN | `d55d2db36d835825b1e23d385f9e4c7555c9200c2f2656bbc4ec649530b2ae53` |
| C3 v2 flattened Quartus RTL | `7c0675a6b2862c6db68f8ec1c0ceb517161389e0a3a64c7cf3bd10f33c4e9bb1` |
| QSF | `fe3394f8f56091d816ada755b173b6ca3034845e61f5960d54257346028add79` |
| SDC (C3 v2 internal screening constraints) | `ceaaa6708f0ed8f6d2c1443b60d9511c51d21f96ddaf914117ee6a65410c82eb` |
| RAM lane 0 | `d22de6d6cb644dfdd2c5d5ef839faa46c94de975f879d1940336833912674867` |
| RAM lane 1 | `3dafca67ab769cd03b4185dd32b46744a5b69a1bc62672a13abd70db416684ff` |
| RAM lane 2 | `cb5e7db6eab396208d051f9fbf22409b9508a6ad3b5d3aa155399842249c7994` |
| RAM lane 3 | `39dacc63ae00262432842df91a343d4ee63d00192944d00509f65c569fa05711` |
| mailbox RTL snapshot | `7cc0cb69bfddf4309f3b95370ce7c0e06b99e235eb8204b40816f40ff0f719d1` |
| SoC RTL snapshot | `0902a2b9db68fbc27c4aa155b5fb43025a46529b519850c78e7386694d6d19af` |
| board wrapper snapshot | `c6d602e252f8e4f472cd79237f241becc9bdecb535d4ceba88d8bfbcecfe3265` |
| native source-list file | `4bddc5bd5e37cbd24015189d49e4a21677d570e5cb1c0a7c9dd503da30e6bfba` |
| frozen Q15 header from C2 audit | `961a76b7e220bf2f665e7c04ab62063600aa2e7eccf3403d80ea730bc993ad9f` |
| frozen Q15 prediction digest | `03eb958cfa8b4fd2f71a95fb47dbca512820c237c281473817bba685b92c743e` |
| 360 campaign canonical SHA | `d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc` |

The Q15 model/weights are frozen. The v2 changes add the measurement protocol and counter transport; they do not retrain or change model weights. Full manifests and generated-file hashes are under the evidence folders listed below.

## 実施した検証

1. **Native SV SoC regression — PASS.** Verilator 5.020, `--binary --timing`; 42 cases, negative protocol checks and reset recovery; `run_v2_42.exitcode=0`, `run_v2_guard.exitcode=0`. Earlier failed attempts (including source availability and runtime failures) are preserved under the earlier `RETRY*` evidence folders; RETRY06 is the passing run. Simulator warnings remain in compile logs and have not been blanket-suppressed.
2. **sv2v SoC regression — PASS.** sv2v 0.0.12 with `-D SYNTHESIS=1`; conversion, 42 cases, negative checks and reset recovery all exit 0. Prior failed conversion attempts remain saved. Warnings were retained.
3. **Quartus-flat SoC regression — PASS.** Same generated flat RTL that feeds the C3 v2 Quartus project; 42 cases, negative checks and reset recovery exit 0.
4. **Counter/host validation — PASS.** 64-bit start/end monotonicity and zero-span rejection; valid low-32-bit wrap with increasing 64-bit counter; 64-bit decrease rejected. Firmware reads `mcycle` with RV32 high-low-high sampling. Measurement starts after request/pixel validation and immediately before admission/inference; end is sampled after inference and argmax. JTAG scan, host wait/retry and response commit lie outside that cycle interval. Reset/interruption is retained as timeout/missing response; there is no separate asynchronous hardware-reset flag in the response.
5. **Quartus — PASS for build/Fitter/Assembler, limited internal STA.** Quartus Prime Lite 25.1std.0 Build 1129, target 5CEBA4F23C7N; full compile exit 0. Fitter and Assembler succeeded. The post-fit DRC still reports 16 D102 bundled-data CDC warnings; they remain visible and are not waived. Other warnings are enumerated in `warning_counts.txt`.
6. **Four-corner internal STA — PASS within constraints.** `CLOCK_50` 50 MHz. Setup worst slack +1.803 ns (slow 1100 mV/85 C); hold worst slack +0.124 ns (fast 1100 mV/0 C). Request bus: 800 source/destination bits; response bus: 480 first-stage destination bits (484 source register bits in netlist report). Worst route delay among reported corners: 3.323 ns request and 3.633 ns response. The 16 ns `set_net_delay` is an internal engineering screen; it is not a Terasic JTAG timing specification. `report_max_skew` has no paths across the asynchronous groups. Quartus's 30 MHz `altera_reserved_tck` is an internal generated constraint, not a measured USB-Blaster TCK guarantee.
7. **Unconstrained I/O remains.** TimeQuest identifies external JTAG TDI/TMS and TDO plus selected LED outputs as unconstrained. This is why B-SIGNOFF is BLOCKED even though the internal synchronous core path checks pass.
8. **Frozen campaign dry-run and SOF binding audit — PASS, host only.** 13 schedule files, 24,840 rows, 360 unique inputs; campaign canonical SHA unchanged. The host dry-run report SHA is checked; all bound case CSVs byte-match the verified host outputs; each SOF-bound binding is compared field-for-field with its unbound predecessor, allowing only the recorded C3 v2 SOF/eligibility/gate metadata changes. The bindings name the SOF SHA, build and model. The campaign gate remains closed until ten-input KEY-reset replay passes. Physical campaign rows remain zero; no mock/simulation cycle values were exported as physical measurements.
9. **Full-schedule Quartus STP runner — PASS, host Tcl test only.** The original pilot runner required every selected sequence as a command-line list; the 7,560-row schedules would exceed the Windows command-line limit. A separate C3 campaign runner accepts `ALL` only for complete frozen bindings, derives sequences from the binding, and checks all case CSV sequence rows before any JTAG access. Quartus STP Tcl 25.1 Build 1129 tested all 13 actual bindings (24,840 rows), plus the 20-row pilot subset and negative sequence/scope cases; exit 0, 0 Quartus errors/warnings. The startup TBBmalloc compatibility notice remains in the log. Runner SHA-256: `f7678c43560b24842e08ba3a0d8b66eb3abbb206173e840538f394a3f96fa7eb`; test SHA-256: `935ffdb3bd753b74ed8a4bb751f1b90934861950b3f297202213e2d39ebf3683`. Test log: `C3_MEASUREMENT_V2_PHYSICAL_PREP_20261115/campaign_runner_tcl_test_retry03.log`. No JTAG hardware was accessed by this Tcl unit test.

10. **Full-campaign reset gate interlock — PASS, host Tcl test only.** Review found that the original `ALL` command could bypass the README's required KEY-reset replay. Every complete frozen schedule now requires an evidence-backed gate JSON, including all three diagnostic and ten primary schedules; ten-input pilot subsets can still run before and after reset. It verifies the exact C3 v2 SOF/build, 20 frozen sequence IDs, reset replay result identity/status, independent audit identity/status, and both referenced SHA-256 values before output creation or JTAG access. Offline tests cover valid evidence, missing gate rejection, changed-result SHA rejection, and direct full primary/diagnostic invocation stopping before JTAG. All 13 frozen bindings/24,840 rows were rechecked in Quartus STP 25.1 Build1129; exit 0, 0 Quartus errors/warnings. TBBmalloc compatibility notice remains. KEY-reset evidence has not been produced and the full-campaign gate remains closed. Test log: `C3_MEASUREMENT_V2_RUNNER_RESET_GATE_20261115/attempt11_quartus_stp_tcl.log`.
11. **Gate B evidence consistency audit — PASS, read-only.** A reproducible Python audit hashed 59 preserved build/timing/model/reference/binding inputs; it checked all 13 versioned campaign bindings against the same SOF, ELF, model/reference, RAM lanes, build and frozen campaign/schedule identities. It parsed all four setup/hold reports (20 reported paths each; 0 reported violations), verified the SDC's two reset-only exceptions and two internal 16 ns screens, confirmed the 16 D102 warnings remain, and confirmed TimeQuest's unconstrained I/O counts/ports. Result: B-SIGNOFF remains **BLOCKED** and B-EMPIRICAL remains **PASS_LIMITED**. The report does not claim all paths are constrained or close external timing. Evidence: `evidence/C3_GATE_B_EVIDENCE_AUDIT_20261115_FINAL/`.

The initial runner and test were preserved before adding a fail-closed campaign gate; their hashes remain `f7678c43560b24842e08ba3a0d8b66eb3abbb206173e840538f394a3f96fa7eb` and `935ffdb3bd753b74ed8a4bb751f1b90934861950b3f297202213e2d39ebf3683`. The final reset-gate test is `C3_MEASUREMENT_V2_RUNNER_RESET_GATE_20261115/attempt11_quartus_stp_tcl.log`; the current source manifest verifies 3/3 files and has SHA-256 `2c27410465eedf1257b8f488164538755c7ac24f6880d68966968d764538aae5`. The gate evidence manifest verifies 26/26 files and has SHA-256 `54431b1345078e0d500751fbb4027ad2c1ef83431e3b83d43546042692033cde`.

## Empirical pilot eligibility rationale

The one new material blocker in the previous B-EMPIRICAL audit was the old 32-bit-only cycle response. C3 v2 now transports stable 64-bit start/end samples and the host rejects `end <= start`; a 64-bit decrease, zero span and wrapped 32-bit low word were tested. Request/response sequence, input, mode, model/build/binding IDs, CRC, prediction, admitted/executed Exit, cap and flags remain checked. Failed requests and raw response data are written before final status handling.

The CDC D102 rule still reports that Quartus cannot prove bit alignment for 16 asynchronous bundled-data structures. The mailbox RTL review confirms request payload is held through synchronized acknowledgement and response payload is committed before the response toggle, held until consume, and captured after synchronized toggle plus a capture-pending cycle. New SDC selectors now point at the actual first-stage bus registers; 800 request and 480 response paths are enumerated in all four corners. The RTL regression checks hold-before-ack, capture-pending payload equality, response stability until consume, and repeated responses. This is a documented structural/manual disposition for a finite empirical pilot, **not a waiver, CDC formal proof, MTBF guarantee, or external JTAG timing signoff**. If the board pilot shows an identity, CRC, reference, timeout, response or counter anomaly, stop and preserve it.

This bounded review was used only for an SRAM-loaded empirical pilot on this build and board. The new-build 42-case replay and ten-input first session passed. The reset replay remains pending before starting the 24,840-row campaign.

## 次に実行する順序

1. 完了: SHA-256 `85c5...1f2d`とUSB-Blaster/Cyclone V JTAG chainを確認。
2. 完了: C3 v2 SOFをFPGA SRAMだけに設定。Flash/CFMとオンボードEPM240は未変更。
3. 完了: 既存C2J2 42要求をbuild `43334531`へ明示再結合して42/42実機再確認。
4. 完了: `primary_01`のID 1–10を選び、固定Exit 2と同じIDのadaptiveを実行。session 1は20/20 PASS。
5. 次: ボードのKEY[0]を一度押して離し、同じ20要求を再実行してreset後結果を監査する。現時点ではこの再実行は未実施で、Campaign runnerも実行を拒否する。
6. 完了（準備のみ）: 凍結13 scheduleのSOF SHA結合済みbindingを作成・独立監査。全CSVはhost dry-runとbyte一致し、bindingはNOT_RUNのまま。
7. 完了（準備のみ）: 凍結13 scheduleのSOF結合済みbindingを独立監査し、完全schedule用runnerを実binding 13件でTcl検証。物理取得は0行。
8. reset replay PASSと独立監査の後: 証跡JSONを作り、凍結13 scheduleの物理campaignを始める。外部タイミング資料が得られるまで結果分類は`EMPIRICAL_ONLY`。

前回確認されたcold bootsはこのC3 v2 runのboot IDとして流用していない。今回の42件とpilot session 1は同一の新しいC3 v2 SRAM configuration sessionである。

## 再現用証跡

正本 evidence root:

`artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/`

実機記録は`PHYSICAL_C3_V2_20261115/`、host準備は`C3_MEASUREMENT_V2_PHYSICAL_PREP_20261115/`に保存している。reset replay用runner/case bindingはすでに用意済みだが、リセット後の実行はまだ行っていない。campaign SOF binding SHAマニフェストは`campaign_sof_bound_v2/SHA256SUMS.txt`、binding auditは`campaign_binding_audit_v2.log`、全schedule runner testは`campaign_runner_tcl_test_retry03.log`、runner source manifest照合は`campaign_runner_source_manifest_verify.log`に保存している。

- `C3_MEASUREMENT_V2_RTL_RETRY06_20261115/`
- `C3_MEASUREMENT_V2_SV2V_RETRY02_20261115/`
- `C3_MEASUREMENT_V2_QUARTUS_FLAT_REGRESSION_RETRY01_20261115/`
- `C3_MEASUREMENT_V2_QUARTUS_RETRY02_20261115/`
- `C3_MEASUREMENT_V2_STA_RETRY03_20261115/`
- `C3_MEASUREMENT_V2_CAMPAIGN_HOST_DRYRUN_20261115/`
- `C3_RUNNER_COUNTER_TEST_RETRY01_20261115/`

既存のC3 physical evidence SHAマニフェスト照合PASS。827件の既存C1/C2証跡も旧SHAマニフェスト全件を検証しPASS。C3 v2の42要求とpilot session 1を生ログから再監査し、どちらもPASS（42件/20件、違反0）を再確認した。ログは`evidence/PHYSICAL_C3_V2_20261115/CURRENT_STATE_REAUDIT_20261115/`にある。Pythonの初回全件監査は266文字パスでMAX_PATHに当たり失敗したため、その試行を保存し、拡張長パス対応後に827/827 PASSを得た。PowerShellでも827/827 PASSを独立確認。

Terasic向けのC3仕様照会案（未送信）は`evidence/TERASIC_SUPPORT_JTAG_TIMING_SPEC_REQUEST_C3_EN.md`。CPLDソース公開は求めない。既存の旧案は827件の履歴マニフェストと一致する原本のまま保持するため、今回の照会には使わず、新しいC3案だけを使う。

実際のrunnerコマンド、working directory、tool version、終了コード、全artifact SHAは各folder内のcommand/runログ、`*.exitcode`、`input_sha256.txt`、`artifact_sha256.txt`に保存した。Quartusの大きな一時ビルドは`D:\rtnn-c3-measurement-v2-quartus-retry02`にあり、再現に必要な入力と主要出力はrepository内証拠folderへ保全した。
