# RTNN Stage C3 — 現在地 2026-11-15（KEY-reset RUN5後）

この文書はRUN5時点の最新実験status snapshotです。後続のリポジトリ公開記録は[REPOSITORY_UPDATE_AUDIT_20261115.md](REPOSITORY_UPDATE_AUDIT_20261115.md)を参照してください。過去statusと実験run recordは当時の記録として残しています。

## Repository / 保全

- Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
- Branch: `codex/stage-c3-jtag-pilot-20261114`
- HEAD: `b332ba02ab992227140998a1d67513c690ae17cf`
- このsnapshot作成時点で正しいoriginとremote HEADをread-onlyで照合し、未コミット差分・証跡を保全。公開前だった。以後のcommit/push状態はrepository update auditを参照。

## Gate status

| Gate / work | Status | Evidence / boundary |
|---|---|---|
| B-SIGNOFF | **BLOCKED** | DE0-CV搭載USB-Blaster/JTAGのboard-level TCK/TDI/TMS/TDO timingが未確定。未制約外部I/OとD102が残る。WCET・hard deadlineは主張しない。 |
| B-EMPIRICAL | **PASS_LIMITED** | C3 v2 build `43334531`と特定の基板・経験的計測条件に限定。正式timing signoffではない。 |
| KEY[0] reset replay RUN5 | **PASS 20/20** | ユーザーがKEY[0]を押して離したと申告。read-only JTAGでbuild/READYを確認後、固定20 sequenceを実行。PowerShell監査・独立Python監査・reset gate生成がPASS。電気reset telemetryではない。 |
| C3 v2 frozen campaign | **PASS 24,840/24,840 (saved run)** | 13/13 frozen schedulesの保存済み実測と独立auditがPASS。RUN5の20行はキャンペーンに合算していない。結果は`EMPIRICAL_ONLY`。 |
| CDC mailbox phase stress | **PASS 38/38 finite simulations** | native RTLとQuartus flat RTL各19条件、計1,216 request/response。Verilator warning/errorなし。有限zero-delay simulationであり、metastability/MTBF/PCB timingの証明ではない。 |
| Accuracy non-inferiority | **INCONCLUSIVE** | 事前の1 percentage-point margin成立を示す独立入力証拠が不足。 |
| Cold-boot sensitivity | **UNCERTAIN / NOT_ESTABLISHED** | USB-B接続状態などから完全電源断を独立に確認できていない過去sessionをcold bootとして扱わない。 |

## RUN5 — reset後の20要求

- build `43334531`, SOF SHA-256 `85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d`。
- USB-Blaster USB-0、IDCODE `0x02B050DD`、READY `0x08`を確認。
- `primary_01`の入力ID 1–10について固定2/adaptiveの20件を再実行。prediction/reference、Exit/cap、request/response identity、CRC、64-bit mcycle intervalの違反0。
- cycle delta範囲 `565,954`–`2,082,594` cycles。絶対時間への換算なし。
- reset gate SHA-256 `c562fb9dfd40b41b532541794bba7104e791e67ac6884c1008f72bc508780a27`。
- 証跡と再実行記録: [RUN5 record](evidence/PHYSICAL_C3_V2_20261115/KEY_RESET_REPLAY/C3V2_TENINPUT_KEY_RESET_REPLAY_20261115_RUN5/RUN_RECORD_JA.md)。

## 既存キャンペーンと次の判断

保存済みC3 v2 campaign aggregate auditは13 schedules・24,840行をPASSとしている。基板に再接続した今回のRUN5は20件のreset replayであり、新しい24,840行データではない。従ってキャンペーンの取得行数は24,840のまま。過去の失敗・再試行・成功データは既存run単位で保存され、RUN5と混ぜていない。

CDC phase stressのsource、実行script、全試行log、phase matrix、input hash、manifestは[phase stress record](evidence/GATE_B_CDC_PHASE_STRESS_20261115/RUN_RECORD_JA.md)にある。D102 bundled-data警告は未抑制で残し、16 ns net-delay条件は経験的routing screenとしてのみ扱う。

公式公開資料の再照合では、DE0-CV資料はオンボードUSB-Blasterの搭載を示す一方、外部JTAG遅延・TCK波形は示さない。USB-Blaster IIIのタイミング表は対象製品が異なるため適用していない。[公式資料適用範囲の記録](evidence/GATE_B_REVALIDATION_CURRENT_WORKTREE_20261115/OFFICIAL_JTAG_TIMING_SOURCE_AUDIT_20261115.md)。

論文で記載可能なのは、対象build・基板・保存条件における経験的機能一致とcycle観測値まで。board-level timing保証、hard deadline/WCET、絶対実行時間、cold-boot感度、速度優位、1 pp精度非劣性は今回の結果から主張できない。
