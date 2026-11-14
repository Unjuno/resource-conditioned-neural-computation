# RTNN C3 改訂ゲート監査 — B-SIGNOFF / B-EMPIRICAL

作成日: 2026-11-14 JST
Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
Branch: `codex/stage-c3-jtag-pilot-20261114`
監査開始HEAD: `9af7c44daa3f69ace0abefa899b12effefc5ae7b`
適用開始commit: `22b539c840b89bded63923d8d50e29924274ec1b`（詳細は`PLAN_REVISION_PROVENANCE_JA.md`）
作業cwd: `C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114`

## 判定

| Gate | 状態 | 内容 |
|---|---|---|
| B-SIGNOFF | **BLOCKED** | Board/cable経路の外部TDI/TMS/TDO timingと実TCK rate/dutyが不明。Quartus Timing Analyzerに外部JTAG I/O未制約が残る。WCET、hard deadline、board-wide signoffは主張しない。 |
| B-EMPIRICAL | **BLOCKED** | 現行responseは32-bit `mcycle` deltaのみを保存し、64-bit start/end値またはoverflow/reset flagを返さない。ホストがcounter truncationや測定区間中のcounter異常を排除できない。 |
| 13 frozen schedule host preparation | **PASS** | 13 scheduleを凍結identityとbindingのまま24,840 case rowsへ再生成。JTAG・FPGA・simulation cycle値は使っていない。 |
| 保存済みC2J2 42件 | **PASS（履歴のartifact audit）** | 保存済み実機runは42/42。今回の基板操作や再測定は行っていない。 |
| 改訂10入力pilot | **NOT_RUN** | B-EMPIRICALの適格性が成立しないため実機操作を保留。 |
| 24,840-row physical campaign | **PASS（過去のEMPIRICAL_ONLY run記録）** | 既存のrun recordを保全。今回の判定で遡及的に再分類・格上げしていない。 |

計画改訂の理由は、経験測定でもcounter wrap/resetの観測可能性を要件とする明示的な変更である。正式タイミング保証の代替ではない。改訂後のB-EMPIRICALは新たなpilotへ適用し、過去データを遡及評価しない。

## Repositoryと証拠の初期確認

- `git remote -v`: fetch/pushとも `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
- branch: `codex/stage-c3-jtag-pilot-20261114`
- HEAD: `9af7c44daa3f69ace0abefa899b12effefc5ae7b`
- 開始時working tree: clean
- C3 base manifest: 827/827 entries SHA-256一致（新しい検証scriptで再確認）
- 旧 `C:\Users\junny\OneDrive\ドキュメント\ChatGPT\RTNN` は変更していない

## Identity / frozen campaign

`C3/evidence/SOURCE_AND_JTAG_TIMING_AUDIT_JA.md`の既存crosswalkを照合した。基準SOFは`5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6`、ELFは`625daf8cc194f1bc7d48eefff0f07939c5e0988bb07fc8a3e7efad7e613a15fd`、model IDは`52544e4e`、build IDは`43324a32`。同crosswalkはQSF、board top、flat RTL、SDC、重みheader、4 RAM laneのSHAと実機応答IDを結び付ける。Gate Aの再構築SOFは異なる構成であり、今回の旧SOFと混同しない。

凍結campaign canonical SHA-256は`d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc`、campaign file SHAは`3d97a1cd87395e294299cacb617474367c89a9295355cd25fb1b4fa67464c936`、heldout dataset SHAは`eeba9000a918bcba911007e78905c5052fc743422f95cb314a0fc9f4ecdfb14c`、frozen oracle SHAは`4e1a3ddcabe1884b1607c77d19b10da8a86d53da3f4c060c30d7449635ec3cf4`、native Q15 host table SHAは`1f9b08987a9d7368b663f604eb1dce6e077073e099552532468509c846d6bdc8`。13 scheduleは360 unique IDs、予定合計24,840 rows。明示bindingは旧campaign期待buildとは別にC2J2 `43324a32`へ結び付いており、runnerはbuild/CRC/reference検査を無効化しない。

## B-EMPIRICAL criterion audit

| 条件 | 結果 | 根拠 / 限界 |
|---|---|---|
| SOF・ELF・model・RAM init・RTL・constraints traceability | PASS（identity追跡） | 下表と既存crosswalkでhash一致。これは現在のSV source graphをゼロから再構築できたことを意味しない。Gate Aのnative graph再現性問題は別に記録されている。 |
| 内部CLOCK_50 timing | PASS_LIMITED | 保存済みexact C2J2 Fitter/4-corner STAでsetup/hold slackは正。最悪値+0.821 ns / +0.116 ns。これは外部JTAG timingまたは全path signoffではない。 |
| CDC review / bundled data | PASS_LIMITED | 保存済み候補内部CDC STAは各cornerで800 request/384 response path、7 scalar synchronizer組を列挙。setup/hold、max-delay/skewに違反0。RTL mailboxはpayloadをhandshakeまで保持し、firmwareは推論終了後のresponse commitまでresponse wordsを変更せず、JTAGの次要求はconsume/READY後に限る。capture/holdの限定監査とRTL regressionはあるが、形式証明やアナログmetastabilityの無誤り証明ではない。 |
| 要求・応答ID、CRC、pixel/reference/Exit/cap検査 | PASS（既存実装・履歴run） | Tcl runnerは800-bit要求、build/model ID、384-bit response CRC、sequence/input/mode/budget/予測/Exit、capを検査する。失敗時はraw応答を保存してFAIL/TIMEOUT行に記録する。 |
| JTAG転送/wait/retryをcycle区間から除外 | PASS_LIMITED | firmware順序監査では要求のcopy/decode/CRC後に計測開始、推論/argmax後に計測終了、response MMIO commitはその後。hostは1要求ずつで、DONE後に応答をscanする。cycle境界は推論+admission+argmaxの範囲で、通信時間は含めない。 |
| counter wrap/reset | **BLOCKED** | hostはresponseの32-bit `cycles`だけを受け、`0 < cycles <= 0xffffffff`を確認する。この範囲判定は32-bit wire fieldでは自明であり、上位bit切捨てを検出しない。start/end `mcycle` samples、64-bit delta、overflow/reset flagはresponse schemaにない。resetで応答が途切れればtimeoutになるが、これは全てのcounter異常を検出する証拠ではない。 |
| failure/retry/missing preservation | PASS（runner behavior） | runnerはraw JTAG log、per-case status/error、chunk failures、timeouts、audit outputを保存する。既存の失敗runも上書きせず保存されている。 |

CRCはデータ整合性検査であり、timing guaranteeにも、全てのJTAG転送が無誤りである証明にも扱っていない。

### Counter拡張buildのソース可用性

現行C2 firmware manifest (`C2/evidence/candidate_firmware_build/c2_firmware_manifest.json`) は12個のsource hashを列挙する。記録済み旧作業ツリーの該当C2 firmware folderをread-onlyで調べた結果、`rtnn_c2_main.c`だけが存在してmanifest SHAと一致し、runner/wire/startup/linker/freestanding-memory/generated-heldout/frozen-weight/upstream-coreの残り11ファイルはそのfolder内に見つからなかった。manifest記録の旧Git commit `48f2e81d87a710ac89b3bcf8ef36f71440d1e6c9`から`rtnn_experiment_runner.c`を読み出す試みも「path does not exist」で失敗した。既存ファイルのコピーや変更はしていない。

このため、計測区間の開始・終了counterをresponseへ追加する新firmwareを現状の再現可能なsource一式からビルドできない。C2 ELFは残っているが、ELFを新しいcounter protocolへ安全に改造する方法にはならない。元source bundleが復元されるまでは、既存SOFでの改訂pilotも新SOF生成も行わない。これはformal timingの未確定とは別の再現性ブロッカーである。

### Hash crosswalk

| Artifact | SHA-256 |
|---|---|
| SRAM SOF | `5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6` |
| Firmware ELF | `625daf8cc194f1bc7d48eefff0f07939c5e0988bb07fc8a3e7efad7e613a15fd` |
| Quartus QSF | `9d270c2f57ca7f6ee1f68f4d525a685625a7cc5311b0a55ee363e23f823f675e` |
| Board top RTL | `639e58115cc2f249b7aceb9e89fd2670896c5810ea442c31836926ac3bed5d5a` |
| Quartus flat RTL | `fdfcdf037eb55225e3e6eef06b01fc92e608951c54ece946461408131f2e5ca7` |
| Original SDC | `8ba18e9829ebb9754278867948a1b0fffb360144738f1c3e45f1650592a87690` |
| Frozen Q15 header | `961a76b7e220bf2f665e7c04ab62063600aa2e7eccf3403d80ea730bc993ad9f` |
| RAM init lane 0 | `7704b387d02830327de288cfcced5d1a485c75b6f0cb838db1da4e87661f5f5a` |
| RAM init lane 1 | `8c98d35b71595a0fc6fb40be2177dbac3883b4439a5ae894355bd3c3288af1c6` |
| RAM init lane 2 | `8e8d201adf2f8e383d42bb116d75fa3e0fb6675d8bf96c694a8fc969547d5873` |
| RAM init lane 3 | `affa1411c8c1ea6c443b2b6729502b58b63a6561fcf3177c65d7f34e635e1d11` |
| Campaign canonical | `d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc` |

Dataset/oracle/host-Q15 file hashes are also recorded in the frozen preparation binding and dry-run summary.

## Existing 42-case record check

保存済み `C2/evidence/physical_empirical_42/` のrun manifestは`C2J2_HW_ALL42_RUN1_20261113`、42/42、Quartus STP/Tcl exit 0、result audit exit 0、SOF/build identity一致、Flash/CFM未書込みを記録する。保存済み独立artifact auditは`PASS_ARTIFACT_CONSISTENCY`、42 rows、SOF SHAとCSV/JSON/raw log SHAを照合する。checker自身はphysical provenanceを証明しないと明示しているため、run recordとProgrammer/JTAG raw logsを合わせて読む。今回、この保存済み42-case実機試験を再実行していない。

## Host-only 13-schedule dry-run

出力先: `C3/campaign/dry_runs/BEMPIRICAL_HOST_DRYRUN_20261114/`
runner: `C3/source/prepare_c3_campaign_session.py`
runner SHA-256: `1bb3d0a975c93070e215a2249a1507f9f368dd9c852239c3c99000169d4696bd`
result: **PASS_HOST_DRY_RUN**, 13/13 sessions, 24,840/24,840 rows.

ツール: Python 3.11.9 / PowerShell 7.6.9。各sessionの正確な起動引数・working directory・exit codeは`dry_run_summary.json`と各`<session>.prepare.log`に保存した。summary SHA-256は`950594fa56a7a5e4ddff180532451b0e99bba2c6464361c07c217558477a1834`、出力manifest SHA-256は`126776c717a6493ccd57e169ad30f6c99421a66b7de9e270c586c5263bc02fb9`。manifest内40ファイルを再検証し、40一致・欠落0・不一致0。

再実行時は既存runを上書きしない新しい出力IDを指定する。repo root PowerShellから13回、次の形式で実行する:

```powershell
python .\artifacts\experiments\de0_cv_c1_c2_audit_20261114\C3\source\prepare_c3_campaign_session.py --session <session_id> --out .\artifacts\experiments\de0_cv_c1_c2_audit_20261114\C3\campaign\dry_runs\<new_run_id>\<session_id>
```

`<session_id>`は`campaign.json`の13 schedule IDをそのまま使用する。runnerはすでに存在する出力directoryを拒否する。

| Frozen schedule | Rows | Modes | Unique input IDs | Exit |
|---|---:|---|---:|---:|
| diagnostic_fixed | 2,520 | mode 1: 2,520 | 360 | 0 |
| diagnostic_adaptive | 7,560 | mode 3: 7,560 | 360 | 0 |
| diagnostic_capped | 7,560 | mode 2: 7,560 | 360 | 0 |
| primary_01–primary_10 (each) | 720 | mode 1: 360; mode 3: 360 | 360 | 0 |

各出力にcases CSVとbinding JSONを保存し、各sessionごとにprepare logを保存した。全schedule file SHA、campaign canonical SHA、dataset/oracle/host Q15 SHA、model/build/SOF/ELF identityは既存prepare programで検査された。作成結果の詳細とSHA-256は隣接dry-run directoryの`dry_run_summary.json`と`SHA256SUMS.txt`にある。これはcase構成とreference bindingのhost-only検証であり、JTAG実行、RTL simulation、FPGA cycle測定ではない。

### 旧42件制約の確認

既存C2J2 runnerと42件成果物はそのまま保持した。C3の`prepare_c3_campaign_session.py`と`Invoke-C3JtagCampaignSession.ps1`はbindingの`record_count`で行数を検査する汎用runnerで、42件固定の上限はない。別の旧`audit_c3_pilot.py`には既存4件pilot用の4件assertionがあるが、360 campaignの監査入口ではない。従って、現段階で既存runnerを置換するversioned campaign runnerは追加していない。

証拠manifest再検査は`pwsh -NoProfile -File .\artifacts\experiments\de0_cv_c1_c2_audit_20261114\C3\evidence\B_EMPIRICAL_ELIGIBILITY_20261114\verify_bempirical_manifests.ps1`でexit 0。C3 baseline 827/827、保存済みC2J2 42-case evidence 138/138、新規host dry-run 40/40が一致。出力とexit codeは同フォルダの`verify_bempirical_manifests.log`と`.exitcode.txt`に保存した。`git diff --check`はexit 0（`.gitattributes`のGit改行変換warningのみ）。

## Next gate action

B-EMPIRICALを再評価するには、firmware/response schemaを新buildで拡張し、少なくとも開始・終了の安定した64-bit `mcycle`値または同等に検証可能な差分と明示overflow/reset状態を保存する必要がある。その場合、別build ID/SOFとしてnative/sv2v/負例回帰、Fitter、内部STA、CDC reviewをやり直す。既存SOFのPASSを新buildへ流用しない。改訂後の10入力は、0/24/57と旧pilot IDsを除く凍結360入力から、cycle結果を見ずに事前選択し、固定Exit 2/adaptiveの試行順とreset replayをbindingへ固定する。

## Board / destructive operations

今回の作業はhost-side read/prepareだけ。USB-Blaster操作、JTAG scan、SOF programming、SRAM/Flash/CFM変更はしていない。Terasicへの問い合わせも送っていない。

Terasic宛ての改訂質問案（送信していない）は隣接する`TERASIC_SUPPORT_TIMING_REQUEST_DRAFT_EN_C3REV_20261114.md`に保存した。宛先はTerasic公式support addressで、board revisionに対応するtiming specificationとSDC前提だけを尋ね、EPM240全sourceは要求していない。
