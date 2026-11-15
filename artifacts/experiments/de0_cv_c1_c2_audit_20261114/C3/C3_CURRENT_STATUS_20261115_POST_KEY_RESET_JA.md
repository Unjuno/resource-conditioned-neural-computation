> **履歴snapshot:** RUN2後のstatusです。最新の追加KEY-reset replayは[C3_CURRENT_STATUS_20261115_POST_KEY_RESET_RUN3_JA.md](C3_CURRENT_STATUS_20261115_POST_KEY_RESET_RUN3_JA.md)と[RUN3 evidence](evidence/PHYSICAL_C3_V2_20261115/KEY_RESET_REPLAY/C3V2_TENINPUT_KEY_RESET_REPLAY_20261115_RUN3/RUN_RECORD_JA.md)を参照してください。

# RTNN Stage C3 現在地 — 2026-11-15 KEY-reset replay・凍結campaign後

## 作業対象

- Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
- Branch: `codex/stage-c3-jtag-pilot-20261114`
- HEAD: `b332ba02ab992227140998a1d67513c690ae17cf`（この作業中、コミット・pushなし）
- origin/remote branchは同じリポジトリ・HEADであることをread-only確認。既存の未コミット変更は保持。

## 最新ゲート

| 項目 | 状態 | 説明 |
|---|---|---|
| B-SIGNOFF | **BLOCKED** | ボードrevisionに対応するJTAG外部TCK/TDI/TMS/TDO制約と未制約I/Oの正式処置は未確定。WCET、hard deadline、正式STA signoffは主張しない。 |
| B-EMPIRICAL | **PASS_LIMITED** | C3 v2 SRAM-only pilotの範囲に限定。正式signoffの代替ではない。 |
| C3 v2 read-only identity | **PASS** | USB-Blaster USB-0、Cyclone V IDCODE `0x02B050DD`、build ID `43334531`、READY `0x08`。FPGAからSOF SHAを読み戻したものではない。 |
| KEY0 reset replay | **PASS 20/20** | 操作者がKEY0押下・解放を確認後、凍結20 sequenceを再実行。PowerShellと独立Python監査PASS。 |
| C3 v2凍結物理campaign | **PASS 24,840/24,840** | 診断3 schedule（17,640行）とprimary_01–10（7,200行）を13/13実行。全runのPowerShell・独立Python監査と集計SHA監査がPASS。旧C2J2とは別データ。 |
| native 146-source rebuild | **PASS_CURRENT_WSL; PORTABILITY LIMITED** | 2026-11-15にUbuntu 24.04で新規compile/run。146/146 source pathが存在し、Ibex commit `7b5df75a041affe56e8c235260f98a09b3319008`と全source SHAを記録。C3 regressionと負例・reset回復PASS。Ibex RTLはrepo外`/opt/rtnn-tools/ibex`にあり、clean checkout単独では未再現。 |

Reset replay evidence: [`RUN_RECORD_JA.md`](evidence/PHYSICAL_C3_V2_20261115/KEY_RESET_REPLAY/C3V2_TENINPUT_KEY_RESET_REPLAY_20261115_RUN2/RUN_RECORD_JA.md). 生JSON/CSV/raw log、binding、case list、独立監査、gateとSHA-256 manifestは同じrun directoryにある。

Frozen campaign aggregate: [`C3V2_CAMPAIGN_AGGREGATE_AUDIT_20261115.json`](evidence/PHYSICAL_C3_V2_20261115/FROZEN_CAMPAIGN/C3V2_CAMPAIGN_AGGREGATE_AUDIT_20261115.json). 13 scheduleの期待行数・生CSV/JSON件数・build/SOF/model identity・run SHA-256 manifestを独立照合した。各scheduleのrun record、raw JTAG log、CSV/JSON、binding、cases、ゲート、監査ログ、SHA-256 manifestは各run directoryに保存。

24,840件は一台のDE0-CV、同一C3 v2 build、同じ未確認の連続電源セッション内で取得したEMPIRICAL_ONLYの測定である。KEY0押下・解放はreset replayの前に操作者が申告した1回であり、20要求のreplay後、監査済みreset gateをcampaign runnerで各scheduleの開始条件として再利用した。各schedule直前の独立したKEY0操作や電気的reset telemetryは記録していない。独立cold bootの反復も確認されていない。測定は固定された凍結スケジュールの観測結果で、これだけから速度優位・精度非劣性・母集団性能を主張しない。旧C2J2 campaignの24,840行とは結合しない。

Native RTL rebuild evidence: [`RUN_RECORD_JA.md`](evidence/C3_MEASUREMENT_V2_RTL_REPRODUCE_20261115/RUN_RECORD_JA.md). The new run used the fixed 146-source graph on the current WSL installation; it does not make the Git checkout self-contained.

結果は1台・1buildでの経験的観測である。20要求のmcycle差分は565,954–2,082,594、中央値943,929。未校正の絶対時間、母集団性能、速度優位、精度非劣性を示さない。KEY操作は操作者申告であり電気的reset telemetryではない。

## 次工程

次は新C3 v2の24,840行に限定した再現可能な統計・ペア比較を別途監査し、独立cold-boot反復が未確認である制約を維持して解析する。B-SIGNOFFはBLOCKEDのまま。正式なJTAG外部タイミング資料が得られない限り、WCET・hard deadline・正式STA signoffを主張しない。
