# RTNN リポジトリ取り違え監査・移植記録

監査日: 2026-11-14 JST  
正本: `https://github.com/Unjuno/resource-conditioned-neural-computation`  
誤接続元: `https://github.com/kardaneh/RTNN`  
監査クローン: `C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114`  
ブランチ: `codex/de0-cv-c1-c2-audit-20261114`（未commit・未push）

## 保全と初期状態

誤接続元のGitルートは `C:\Users\junny\OneDrive\ドキュメント\ChatGPT\RTNN`、originは `https://github.com/kardaneh/RTNN.git`、branch `codex/stage-c2-jtag-20261111`、HEAD `48f2e81d87a710ac89b3bcf8ef36f71440d1e6c9`。作業前の全体statusは11,709 paths（staged 883、unstaged 6、untracked 9,491、ignored 1,335）。C1 subtreeは146 paths、C2 subtreeは1,603 paths。作業中にこのツリーを変更していない。reset/clean/delete、履歴変更、origin変更、commit、push、mergeは実施していない。

正本は別ディレクトリに新規cloneし、`.git`を混ぜていない。clone直後のmain HEADは `ea903d3b76c4cb50732c3f9c72c8ed2084c2cb23`。同じHEADの独立ブランチ上でのみ変更した。C:空き容量は開始前に464 GBを確認した。

構造比較では、誤接続元に965 tracked files、正本に276 tracked filesがあり、上位構造も異なる。共通パス名は `.gitignore` と `LICENSE` の2件だけで、両ファイルとも内容は一致しない。誤接続元の汎用 `src/`・`tests/`・Python package一式をRTNN研究の正本とみなす根拠はなく、移植していない。

## ハッシュ照合

| 対象 | SHA-256 | 照合結果 |
|---|---|---|
| Stage 2元ZIP（誤接続元の保存物） | `7f5c666514729b0d5f776904ec5662187271beb90f30d4c33231b7b92b4c5507` | 入力ファイルを確認。ZIP自体は元場所に保持 |
| 正本の凍結Ibex Simple-System ZIP | `9150b0763e5d7b7c305441befdb4161ccf95612edd924b525f8388e06d9a86b0` | Stage 2 ZIP内の同梱ZIPとbyte-identical |
| 正本凍結ELF / BIN | `234a7f46cf227a11f5d97f3c778cbb0c4ed4f7067f8994bcca86c4b08ff4e742` / `266ecb70c723b2164f6fe9039f27d4cb49c4d7271d4aca0cf69f2692cdfdf7a1` | 正本ZIPのmanifestと一致。Ibex commit `7b5df75a041affe56e8c235260f98a09b3319008` |
| seed-63 Q15生成重みヘッダー | `961a76b7e220bf2f665e7c04ab62063600aa2e7eccf3403d80ea730bc993ad9f` | Stage 2 ZIP、C2 J2候補、正本の凍結artifactすべて一致 |
| C2J2実験ELF / BIN | `625daf8cc194f1bc7d48eefff0f07939c5e0988bb07fc8a3e7efad7e613a15fd` / `379ab1ad0444d28ff2bf2172f837ac0aa01c64fc948aba93a7615c3e4d63659c` | 候補firmware manifestと一致。正本Simple-System ELF/BINとは別物で、混同していない |
| C2J2 frozen cases CSV | `52b7fdae7c465fd4b6409876e258e00fbaad5656e93ad3b9fb79f2f8741aec5d` | build ID `43324a32`の候補版を採用。旧host CSV（別build ID `43324a31`）はC2J2入力に採用していない |
| C2J2最終D101 SOF | `5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6` | D101最終Quartus記録・42件実機run manifestと一致 |
| C2開発ツリー mailbox RTL | `91c06dfc6d6d32cf3b234619c201443474aeae3c3db0cb9ad3b52619c48ba163` | `rtl/`の移植元。final D101 flatから見えるcapture-pending改訂を含まない |
| CDC capture-delay候補 mailbox / flat | `363a0f3bd601f9c3f2f53d635e1da54887e6754cda2fc4774b43c3fb969fb96f` / `b3bc4d6217c296694b84b410c5ce3dd9400fcd753a137cb01c56806ecfb2b562` | final D101 flat `fdfcdf...`と別revision。候補証跡として保存 |
| 実機42件結果CSV | `4dd49ea8024b76bcfda00a1b7963df5485ef727a7721cbf7fec83a964356487e` | 物理run manifestと一致 |
| C2 fixed-Ibex dependency list | `4c06223e8d9b601716fac77f54854854b2ba029cfbd5cd79a75df29873962a80` | 146 source graphとして記録。単純globで代用していない |
| CDC回帰flat RTL（先行build） | `f8994351de4a20e74bd8726f48bb94e759f9b7a142c100a66cf73392f5d4adf2` | 最終Quartus flat RTLとは異なる |
| 最終Quartus flat RTL | `fdfcdf037eb55225e3e6eef06b01fc92e608951c54ece946461408131f2e5ca7` | 最終D101 SOFのbuild inputsとしてQuartus記録に記載 |
| C1成功SOF | `a5ee8af78b05e1875d1f0fb2da4789e5d9debb6e96b5af78f5078749ea084a79` | C1 manifest 145/145照合済み |
| C1/C2 fixed Ibex flat RTL | `8634e8a73623d74635f93daa1c1a34d30fb5d1dbb7aa30f66411b9cf58621b38` | C1 source SHA記録とC2 `rtl/ibex_flat.v`で一致 |

C1には別の失敗attempt SOFもあり、SHA `82c98efc32b3396b2d7c74fc3f1fe5df6abdf4dd4005ff916383efb21b633ce1`。成功SOFと同一扱いしていない。Stage 2 manifestはseed-63/Q15 frozen imageを参照し、C2 generated weights headerも正本の同一Q15 hashと一致する。C2 build ID `43324a32`はwire protocol/build識別子であり、Q15モデルのSHAではない。

## 移植対象と分類

**移植したもの**はこのディレクトリのC1全146ファイル、C2のRTL/host/tests/tools、Quartus入力一式、固定ケース・request vectors、候補firmware bundle、CDC回帰と失敗証跡、D101/Fitter/STA成果物、実機JTAG全42件のpayload/log/結果、設計・実行記録。元のC1/C2ディレクトリはそのまま残した。最終flatに対する本監査の再回帰ログも追加した。

**移植していないもの**は誤接続元リポジトリ直下の別Python package一式、C2 root `firmware/`の別build由来 `rtnn_c2_experiment.elf/.bin`（ハッシュがJ2候補と不一致）、C2の重複一時build/object files。誤接続元のGit履歴・`.git`は取り込まず、C2全体manifestも他の未移植ファイルを参照するため正本側の完全manifestとはしていない。C1/C2の選定コピーは元ファイルとのSHA比較581/581一致。移植後に再実行したVerilatorの再現用`obj_dir`も保存対象に含めた。全835ファイル（約336 MB）のSHA-256を `SHA256SUMS_MIGRATED_20261114.txt` で照合し、835/835一致。

## C1/C2証跡の監査判定

| 工程 | 判定 | 監査結果と限界 |
|---|---|---|
| C1 artifact integrity | PASS | SHA manifest 145/145一致。成功SOF SHAを特定 |
| C1 self-test | PASS（保存済み記録） | 固定Ibex/Q15、20要求を2回、reset復帰、native/sv2v、Quartus/Fitter/DA、内部STA、SRAM-only設定、LEDR=1000のJTAG/ユーザー確認記録。個体CLOCK_50 ppm、他ロット一般化、連続運転保証ではない |
| 固定Q15/Ibex provenance | PASS（artifact identity） | seed-63 Q15 header hash一致、Ibex commit一致、C2 dependency graph 146 sources。C2専用ELFは正本Simple-System ELFと異なるbuild |
| C2入力と正本reference照合 | PASS | 42行すべての64 pixel値、教師label、実行classに対する期待predictionを正本 `de0_cv_preflight_vectors.json` と比較。3 unique inputs、42/42一致 |
| C2 native/sv2v先行回帰 | PASS（先行flatのみ） | 42件、reset replay、negative tests。flat hash `F899...`。最終Quartus flat `fdfcdf...`とは異なるため最終SOFの回帰とは当初みなさない |
| C2 exact final Quartus-flat regression（本監査で実施） | PASS | Quartus flat `fdfcdf...`をVerilator 5.020でコンパイル・実行。42 frozen cases、2 reset replay、7 negative/reset条件を独立checkerで照合。compile/run/audit各exit 0。結果CSV SHA `dd15b0f87e059c7279392ae4e59a647c63f78db5a278572ae34d8046d9cd002e`。これはVerilog flat inputに対するSoC回帰であり、最終SystemVerilog sourceをFuseSoCから再展開するnative regressionとは区別する |
| C2 assertion初回再現 | FAIL（testbench sampling point） | 変更前testbenchは `req_sync2 != req_seen`を検出した直後に、まだcapture pendingのrequest_dataが取り込み済みと比較し、`CDC request bundle mismatch at CLOCK_50 capture`で終了（compile 0 / run 134）。最終flat RTLには`req_capture_pending_sys_q`があり、次のCLOCK_50 edgeでcaptureする。assertionを削除せず実際のcapture-pending edgeで比較するよう、本監査用testbench copyのみ修正し再実行。production RTL、期待値、凍結データは変更なし。元の失敗logを保存 |
| C2 native 146-source SystemVerilog回帰 | BLOCKED（source revision不一致） | 固定146-entry source listをremapし、native compileを試行。移植した`rtl/rtnn_c2_vjtag_mailbox.sv`（hash `91c06d...`）にfinal flat RTLが持つ`req_capture_pending_sys_q` / `rsp_capture_pending_tck_q`が存在せず、capture-edge testbenchとのcompileでexit 1。これはnative regression PASSではない。隣接するCDC capture-delay candidateも保存したが、そのcandidate flat hashは`B3BC...`でD101 final flat `FDFCDF...`と異なる。最終SOF由来の元SystemVerilog source setを一意に確定できるまでnative-source gateはBLOCKED |
| C2 physical JTAG, 42 cases | PASS（経験的、単一board/build） | 保存済みprogrammer/Tcl/JTAGログとrun recordを併せて監査。IDCODE `02B050DD`、SRAM-only SOF、42/42 frozen cases、一致予測・Exit・応答ID/CRC、cycle値非ゼロ、cap violation/timeout/missing 0。独立結果checker exit 0（出力 `physical_empirical_42/independent_audit_20261114.json`、checker自身はhardware provenance=falseと明記）。cycle range 20,146–2,791,485、median 1,031,300.5 cycles。シミュレーションcycleやabsolute secondsではない |
| C2 Quartus Fitter/Assembler | PASS（build内） | Lite 25.1std.0 Build 1129、Cyclone V `5CEBA4F23C7`、Fitter/Assembler完了。SOFは実機run recordでSRAMに設定、Flash/CFMは不使用 |
| C2 Design Assistant / D101 | PASS with exact local disposition | D101 global rule有効。held-stable bundled-data handshake上の対象801 nodeだけを個別local-Offとして記録、監査scriptと一致。raw unwaived D101報告と392 warningsを保存。警告無視の合格ではない |
| C2 STA board signoff | BLOCKED | 4-corner internal setup/holdおよびnet-delay監査値は正。Quartus自身がsetup/hold fully constrainedではないと報告し、JTAG TDI/TMS/TDO外部delay等が未拘束。内蔵クロック結果を完全なboard timing signoffと呼ばない |
| 360入力/13 schedule論文campaign | NOT_RUN | この監査の移植範囲外。既存campaign plan/hashは変更していない |

C2 hardware run audit JSON単独は自身でhardware provenanceを証明しない旨を明記する。そのため物理判定はJSONだけでなく、同じexperiment/build/SOFを結ぶProgrammerログ、JTAG scan/Tcl生ログ、run recordを根拠とする。42ケースのうち18 predictionがground-truth labelと異なるが、全42件でfrozen Q15 expected predictionと一致する。これは推論器不一致ではなく分類正解率の観測であり、42独立入力でもない（固定された3画像×複数mode/class）。

## 本監査の再実行

- Verilator回帰cwd: `C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114\artifacts\experiments\de0_cv_c1_c2_audit_20261114\C2\evidence\final_quartus_flat_regression_20261114`
- WSL: `Ubuntu-24.04`; `verilator --version` = `Verilator 5.020 2024-01-01 rev (Debian 5.020-1)`。
- command: `bash run_final_flat.sh` (original, unmodified CDC assertion) → compile exit 0, run exit 134; raw `compile.log`, `run.log`, exitcodes retained.
- command: `bash run_capture_edge.sh` (assertion timing fix in separate testbench copy only) → compile exit 0, run exit 0; warnings retained in `compile_capture_edge.log` (211 Verilator warnings, `-Wno-fatal` used): ASCRANGE 1, BLKSEQ 4, DECLFILENAME 2, PINCONNECTEMPTY 80, SYNCASYNCNET 2, UNOPTFLAT 3, UNUSEDPARAM 23, UNUSEDSIGNAL 3, WIDTHEXPAND 91, WIDTHTRUNC 2. Complete `run_capture_edge.log` contains final `C2_FIXED_IBEX_Q15_SOC_PASS` marker.
- Native source graph attempt: `bash run_native_source_graph.sh` → source-presence check 0, source count 146, compile exit 1, run NOT_RUN. Compiler log records missing `req_capture_pending_sys_q` and `rsp_capture_pending_tck_q` members in the older source mailbox. It is preserved at `C2/evidence/final_source_regression_20261114/` and is not counted as an RTL functional failure or PASS.
- audit cwd: correct repo root; command: `python artifacts/experiments/de0_cv_c1_c2_audit_20261114/C2/source/tools/audit_c2_soc_sim_log.py --log artifacts/experiments/de0_cv_c1_c2_audit_20261114/C2/evidence/final_quartus_flat_regression_20261114/run_capture_edge.log --cases artifacts/experiments/de0_cv_c1_c2_audit_20261114/C2/vectors/c2j2_cases.csv --out artifacts/experiments/de0_cv_c1_c2_audit_20261114/C2/evidence/final_quartus_flat_regression_20261114/audit_outputs` → exit 0, `PASS_RTL_SIMULATION_ONLY`, build `43324a32`, 42 cases, 2 reset replay, 7 negative/reset.
- physical artifact audit cwd: correct repo root; saved checker `C2/source/tools/audit_c2_jtag_results.py`, input expected-case hash `52b7...`, SOF hash `5aa5...`, experiment `C2J2_HW_ALL42_RUN1_20261113` → exit 0, `PASS_ARTIFACT_CONSISTENCY`, 42 rows. This checks the result artifacts against frozen cases but explicitly does not prove physical provenance; use the adjacent Programmer/JTAG logs and run record for that.
- Q15 preflight cross-check: `python artifacts/experiments/de0_cv_c1_c2_audit_20261114/audit_preflight_crosscheck.py` → exit 0, 42 rows / 3 unique inputs / zero pixel, label, or expected-prediction mismatches. Output `preflight_crosscheck.json`.
- Existing recorded tool versions: Quartus Prime Lite 25.1std.0 Build 1129; candidate firmware Clang/LLD 18.1.8; physical record Python 3.11.9 / PowerShell 7.6.9; fixed Ibex commit above. Current shell Git 2.55.0.3. The in-WSL `sv2v` is v0.0.13; the exact-final-flat run compiled already-converted Verilog, while the earlier separate sv2v log used hash F899.

## 変更・Git状態

正本側のtracked変更はREADME、EXPERIMENT_INDEX、`notes/realtime_nn_de0_cv_next_stage.md`の3文書。監査/成果物は `artifacts/experiments/de0_cv_c1_c2_audit_20261114/` 新規追加。変更前後の文書差分はこのbranchの `git diff`、成果物全体のSHA-256は隣接manifestで確認できる。未stage・未commit・未push。既存mainも誤接続元のorigin/履歴も変更していない。

## 次に残る作業

1. 実際のC2 SystemVerilog sourceから146-source graphを再構築し、正確なD101 final source revisionsでnative simulationを回す（本監査はfinal Quartus flat Verilogと同じ入力を回帰済み）。
2. C2のJTAG外部delay/TCK条件を適切に確定し、全I/O制約を含むboard timing signoffを行う。
3. DE0-CV個体CLOCK_50周波数と固定/adaptive全classの測定境界を計測し、別実験IDで対象固有の7-class deadline tableを作る。
4. Final D101 Quartus flatと一致するSystemVerilog source snapshot/source listを特定・固定してからnative regressionを完了する。
5. 360入力campaignへ進む前に、既存13 schedule/24,840予定行/campaign SHAを正本の計画と照合する。今回の42件から論文上の性能優位性を主張しない。

再実行入口は上記のPowerShell/WSLスクリプトと保存済みQuartus手順、C1/C2 run recordを参照する。FPGA Flash/CFMには書き込んでいない。
