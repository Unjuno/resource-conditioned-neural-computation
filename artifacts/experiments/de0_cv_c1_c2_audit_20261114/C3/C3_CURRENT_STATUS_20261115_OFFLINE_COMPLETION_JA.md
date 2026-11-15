# RTNN Stage C3 — オフライン再集計・再現性作業の現在地

更新日: 2026-11-15  
Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`  
Branch: `codex/stage-c3-jtag-pilot-20261114`  
今回確認したHEAD: `143a4af545b49391b2413751918f7bb515277ae9`  

この更新では基板、JTAG、SOF、電源、配線を操作していない。push・commit・PR・mergeも行っていない。履歴の異なる結果は統合せず、保存済み記録と今回の再集計を区別する。

## ゲートと実験状況

| 項目 | 判定 | 範囲 |
|---|---|---|
| B-SIGNOFF | **BLOCKED_EXTERNAL_BOARD_TIMING** | オンボードUSB-Blasterのboard-level外部JTAG timingは未確定。WCET、hard deadline、正式signoffは主張しない。 |
| B-EMPIRICAL | **PASS_LIMITED** | build `43334531`の既存経験測定条件に限る。B-SIGNOFFの代替ではない。 |
| C2J2保存campaign再集計 | **PASS 24,840/24,840** | build `43324a32`、SOF `5aa5be2e…c37e6`、frozen campaign SHA `d6c98f59…a8dc`。旧構成の履歴データだけを検査。 |
| C3 v2 KEY0 RUN5 | **保存済みPASS 20/20** | `C3V2_TENINPUT_KEY_RESET_REPLAY_20261115_RUN5`。以前のrun recordと独立監査がある。今回KEY0操作・再測定・gate生成はしていない。 |
| C3 v2 full campaign | **保存済みPASS 24,840/24,840** | 13/13 scheduleの過去の保存実機記録とaggregate auditが存在する。今回新規取得した行は0。run recordは1つの未確認電源sessionとし、`EMPIRICAL_ONLY`に限定。 |
| 今回の実機操作 | **NOT_RUN (意図どおり)** | 基板不在のオフライン作業。 |
| 精度非劣性・速度優位 | **INCONCLUSIVE / NOT_CLAIMED** | 旧C2J2では1 pp精度非劣性はINCONCLUSIVE。cold-boot独立性も未確立で、速度優位は主張しない。 |

依頼文に記載された「KEY0 replay=PENDING_OPERATOR、C3 v2 full campaign=NOT_RUN」は、保存済みRUN5と13-schedule campaignの後の状態としては一致しない。これらの履歴ファイルは書き換えず、今回の作業で実機を再試験していないことを区別して記録した。現在の過去実験snapshotは[RUN5後status](C3_CURRENT_STATUS_20261115_POST_KEY_RESET_RUN5_JA.md)、full campaignの記録は[run record](evidence/PHYSICAL_C3_V2_20261115/FROZEN_CAMPAIGN/RUN_RECORD_JA.md)。

追加でFTDI公式FT245BL FIFO datasheetを確認し、同ICのparallel-bus timingをDE0-CVのJTAG端点timingと切り分けた。FIFO timingはEPM240が生成するTCK/TDI/TMS/TDOの周波数・phase・relative delayを決定しないため、B-SIGNOFFはBLOCKEDのまま。 [適用範囲監査](evidence/FT245BL_JTAG_TIMING_SCOPE_AUDIT_20261115_JA.md)。

HEAD `143a4af545b49391b2413751918f7bb515277ae9`から、Gate Bの保存証拠59入力を再監査した。13 binding/24,840行identity、4 corner setup/hold、internal CDC route、UCP、D102を照合。保存されたtiming reportの20 path/corner/checkには違反0だが、TDI/TMS 41入力pathとTDO等8出力pathが未制約のまま、D102 16件も残る。判定はB-SIGNOFF=BLOCKED、B-EMPIRICAL=PASS_LIMITED。 [HEAD 143a4af audit record](evidence/C3_GATE_B_EVIDENCE_AUDIT_20261115_HEAD143A4AF/RUN_RECORD_JA.md)。これは保存済みQuartus報告の再照合で、新規Quartus STA実行ではない。

追加の保存report auditでも4 cornerすべてのbundled-data route coverageをbit indexごとに再検査し、request 800/800、response 480/480を確認した。保存STA全体のworst setupはslow 85°C cornerで+1.803 ns、worst holdはfast 0°C cornerで+0.124 ns。これらの値は制約済み内部path reportの範囲だけであり、16 ns net-delayは経験的screen値。Design Assistant D102 16件は未抑制、警告件数も維持。 [機械監査JSON](gate_b_saved_report_audit_HEAD143A4AF_REPRO2.json)、[現HEADの実行記録](OFFLINE_RESEARCH_COMPLETION_20261115/GATE_B_SAVED_REPORT_REAUDIT_HEAD143A4AF_JA.md)、[実行ログ](OFFLINE_RESEARCH_COMPLETION_20261115/gate_b_saved_report_audit_HEAD143A4AF_REPRO2.log)。B-SIGNOFFをPASSへ変更する根拠ではない。

現HEADでC3 v2 top RTL・QSF・SDC・TimeQuest未制約パス報告を直接照合した端点別判定は[Gate B I/O対応表](evidence/GATE_B_CURRENT_HEAD_IO_DISPOSITION_20261115_JA.md)。TDI/TMSとTDOの外部相対timing仕様が不足し、LED出力のUCPもfalse pathで除外していない。保存レポートには入力2 port/41 path、出力4 port/8 pathが示される。これは保存物の照合であり、Quartus再実行ではない。

同じGate B対応表に、保存post-fit DRCのD102 16構造を追加で対応付けた。要求bus 1構造と応答bus側の報告node 15個が、各々のbus synchronizerへ向かう警告である。これは構造警告で、単独では機能故障の断定にならないが、未処置のまま正式CDC証明とも見なさない。

## SDS1104計測器接続の事前確認（実測なし）

OWON SDS1104がPCのUSB deviceとしてPnPに現れる一方、Windows Problem Code 28でUSB driver未導入状態。OWON公式配布ZIP（SHA-256 `D7AB7470FF25FBAECC9F109CB60FAFDCE44A27B52D3FE3ACCC356B15D496E888`）をTempに取得・隔離展開し、main PC software EXEがAuthenticode `NotSigned`、driver package instructionsが昇格権限と自己署名catalog生成を記載することをread-only確認した。実行・driver install・Windows security設定変更はしていない。

OWON公式仕様は100 MHz、1 GSa/s、typical input rise time ≤3.5 ns。Cyclone V dedicated JTAG minimum TDI/TMS setupは1/3 ns。従って、TCK周期/dutyやgross waveform anomalyの探索には利用し得るが、このSDS1104単独では1 ns TDI setupを確証する測定不確かさ根拠が足りず、3 ns TMSもchannel skew/threshold/time-interval uncertainty評価なしに適合証明とできない。

Terasic DE0-CV v1.2.1 System CDのschematicについて、別配布元にあるPDF写し（document title block Rev C, 2015-07-03; SHA-256 `3D41F88C3D03D72263CA776065345FE95548D10E0ABE56E0C0653FA2F0E6021C`）を画面で再照合した。Sheet 7にはBST_TCK経路の`R41 0 Ω DNI`があるが、dedicated test pointではない。現物revision、R41 footprintの実装・露出状態、TDI/TMS/TDOの接続場所は未確認。J5はCPLD ISP、GPIOはJTAG計測点でない。SDS1104の4 channel groundは共通かつprotective earth接続であり、board ground/measurement pointを確定するまでprobe/GND clipを接続しない。

判定: scope USB detection PASS、PC waveform control NOT_READY、JTAG waveform capture NOT_RUN、B-SIGNOFF BLOCKEDを維持。OWON公式manualには前面USB HostにUSB memoryを接続して4chをCSV保存する手順があるため、PC driverはwaveform file回収の必須条件ではない。またscope前面のProbe Compensation出力（5 Vpp/1 kHz）と同梱probeによる基板に触れないfunction check手順を確認したが、実施していない。USB storage要件、probe self-check手順は[OWON/SDS1104 JTAG計測事前確認](evidence/OWON_SDS1104_JTAG_CAPTURE_PREFLIGHT_20261115_JA.md)、空のscope計測ログ様式は[JTAG_SCOPE_MEASUREMENT_LOG_TEMPLATE](evidence/JTAG_SCOPE_MEASUREMENT_LOG_TEMPLATE_20261115_JA.md)に記録した。scope install/driverや基板操作を行った証拠ではない。

応答source selectorの保存数484と論理payload bit数480の差は、旧HEAD `b332ba02...`で実施されたSTA-only再照合により、4つのQuartus `~DUPLICATE` fitter instanceとして説明済みである。その監査の入力SHA-256 11件は現在HEADでも一致し、route reportは4 cornerすべてで480論理bitをcoverageする。保存`report_max_skew`はデータなしのため、net-delay spreadをmax-skew PASSとは扱わない。応答word保持は固定firmwareの順序に依存し、SoC RTL自体はcommit後の応答wordをwrite-lockしない点も記録した。詳細とhashは[Gate B対応表](evidence/GATE_B_CURRENT_HEAD_IO_DISPOSITION_20261115_JA.md)。

Terasic公式System CDの配布ZIP（1,089 entries、SHA-256 `ed4ac9cf4ae3d6ce27e6f2e66d42745b0a55fc2cc883b07069363d9947db942e`）とWaybackの2025年directory snapshotを調べた。ZIPにmanual、board schematic、Cyclone V資料、FPGA demo、Control Panel binariesは含まれるが、EPM240 onboard Blasterの独立source/projectまたは必要なboard-level JTAG timing specificationは見当たらなかった。Wayback CDXのexact ZIP URLはsnapshotなし。公開物調査の方法・SHA・代替経路は[公開アーカイブ調査記録](evidence/GATE_B_PUBLIC_ARCHIVE_AND_ALTERNATIVES_20261115_JA.md)。

## 旧C2J2 — 独立再集計結果

`reanalyze_c2j2_frozen_campaign.py`を生CSV/JSONとfrozen schedulesに対して再実行した。

| Schedule | 期待行 | 再集計行 | 判定 |
|---|---:|---:|---|
| diagnostic_fixed | 2,520 | 2,520 | PASS |
| diagnostic_adaptive | 7,560 | 7,560 | PASS |
| diagnostic_capped | 7,560 | 7,560 | PASS |
| primary_01 | 720 | 720 | PASS |
| primary_02–primary_10 | 6,480 | 6,480 | PASS |
| 合計 | **24,840** | **24,840** | **PASS** |

欠損・重複・余分なsequence、応答identity、凍結Q15予測、admitted/executed Exit、cap、CRC、timeout、trap、case errorはいずれも0件。全体は360独立入力、13 scheduleである。旧campaignの`primary_02–primary_10=7,200`表記は9×720=**6,480**の算術誤りであり、履歴のrun recordに訂正注記を保全した。測定CSV/JSON/raw logは変更していない。

primary 10 scheduleの対応比較は3,600組だが、統計単位は独立入力ID 360件。入力IDごとに10 scheduleを平均し、seed 63、5,000回のpercentile bootstrapを行った。

| 指標 | 観測値 |
|---|---:|
| fixed2 平均 | 943,924.77 cycles |
| adaptive 平均 | 746,322.99 cycles |
| fixed2 − adaptive 平均差 | 197,601.77 cycles |
| 入力単位bootstrap 95% CI | 158,616.47–235,071.07 cycles |
| fixed2比の観測削減率 | 20.934%（95% CI 16.804–24.904%） |
| adaptiveが速い／遅い入力 | 263／97（360 ID） |
| 正解数 fixed2／adaptive | 339/360 ／ 339/360 |
| 精度差のpaired 95% CI | −1.389～+1.389 percentage points |

cycle数はIbexの`mcycle`カウントで、単位はcycle（カウント）である。Hz校正値がないため秒、ppmへ換算しない。bootstrap区間は360入力単位の不確かさで、電源session／cold-boot間の不確かさを表さない。したがって削減率はこの保存条件下の記述統計であり、速度優位・一般化・deadline保証を示さない。教師ラベル精度の1 pp非劣性は**INCONCLUSIVE**のまま。

Exit別の対応解析では、adaptive Exit 1は2,630観測で平均565,950.62 cycles、対応fixed2平均943,924.79 cycles。Exit 2–5はそれぞれ平均1,071,496.64、1,577,043.14、2,082,589.00、2,547,936.71 cyclesで、対応fixed2より遅い方向だった。これは実行Exitによる層別の記述であり、入力画像特徴の因果説明ではない。

再集計と図表: [RUN2 analysis](campaign/analysis/C3_C2J2_OFFLINE_COMPLETION_RUN2_20261115/analysis.json)。出力には全primary rows、入力別paired CSV、最速/最遅入力表、4 SVG、SHA manifestを含む。Exit・session追加表: [session/Exit analysis](OFFLINE_RESEARCH_COMPLETION_20261115/c2j2_session_exit_summary_retry01/analysis.json)。詳細報告・実行履歴は[offline completion report](OFFLINE_RESEARCH_COMPLETION_20261115/REPORT_JA.md)。

## C3 v2 保存結果checker

保存済み42件、10入力pilot 20件、過去のKEY-reset RUN5 20件は、各々のbuild/SOF/model/binding identityを保った個別のsaved-evidence auditであり、新規実験ではない。RUN5のreset gateは過去に生成・保存済み。C2J2 build `43324a32`とC3 v2 build `43334531`は同一runに集約しない。

追加したfail-closed境界テストでは、uint64 wrap、CRC field欠落、旧build identity、physical root内の`mock/` pathを確認した。最初の再現でcheckerがphysical evidence配下の`mock/`を許可したため、path classifierを最小修正し、禁止ディレクトリ名（mock/synthetic/fixtureの複数形を含む）を拒否するようにした。4 focused testsとPython compile checkはPASS。全ての既存13 testsは今回重複実行していない。

修正版C3 campaign aggregate checkerは、Windows長パスによる最初の失敗を保存した上で、extended-length pathを使う修正後に、保存済み13/13 schedule・24,840/24,840行を独立検査してPASSした。過去ログ・失敗試行は削除せず同フォルダに残す。

## 人手・外部依存と次工程

* 正式board-level timing signoffには、DE0-CV revisionに適用されるオンボードUSB-BlasterのTCK波形・board/cable経路遅延仕様または適切な測定が必要。既存のTerasic宛て文案は未送信。
* 保存済みC3 v2 full campaignはすでに存在するため、同じ13 scheduleを重ねて実行する前に、過去runの目的と再試験要否を明示する。今回の作業ではJTAGに触れていない。
* 新たな実機試験を行う場合は、対象buildのread-only identity確認、ユーザー操作が必要なreset、別experiment IDでの再実行、独立auditの順にする。KEY reset・SOF SRAM再設定・完全power-offは別操作。Flash/CFMは変更しない。
* 実機再開用の短い手順は[C3_OFFLINE_RESUME_GUIDE_JA.md](C3_OFFLINE_RESUME_GUIDE_JA.md)。過去のreset実施手順は[KEY reset runbook](C3_RESTART_AFTER_KEY_RESET_JA.md)。

## この作業の逐次チェックポイント

1. **対象保全 — PASS:** originが正しいUnjuno repo、専用branch/HEADを確認。別の`RTNN`フォルダはkardaneh originなので読み取り確認以外の書込み対象にしなかった。
2. **旧実測再集計 — PASS:** 全24,840行、13 schedule、360独立入力を再検算し、図表・CSV・JSON・manifestを生成。
3. **新C3 v2 checker強化 — PASS:** 再現したmock path混入穴を修正し、focused regression 4件を通過。
4. **現状・再開手順 — PASS:** 過去の保存済みPASSと今回のNOT_RUNを分離して記録。B-SIGNOFFは外部依存のためBLOCKEDのまま。

このオフライン準備タスクは完了したが、C3全体のformal signoff/論文主張は未完了である。作業はローカル未commitで、remote更新はしていない。
