# C3 v2 KEY-reset replay —実機run record

- 実験ID: `C3V2_TENINPUT_KEY_RESET_REPLAY_20261115_RUN2`
- 日付: 2026-11-15 (Asia/Tokyo)
- Board/device: Terasic DE0-CV / Cyclone V `0x02B050DD`
- 接続: USB-Blaster `USB-0`
- Quartus STP: Prime Lite 25.1std.0 Build 1129
- build/binding ID: `43334531`
- 結果で照合したSOF SHA-256: `85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d`
- モデルID: `52544e4e`
- schedule: `primary_01` frozen subset, 20 requests, 10 input IDs (1–10)
- reset: operator confirmed KEY[0] press-and-release after read-only identity/READY check. No SOF reconfiguration, DC power cycle, Flash/CFM write, wiring change, or voltage/clock change was performed for this run.

## 実行・判定

1. `check_c3_v2_loaded_build.tcl` をQuartus STPで実行。USB-Blaster、IDCODE、build ID、mailbox READYをread-onlyで確認。終了コード0、`PASS READ_ONLY_IDENTITY`。FPGAからSOF hashを読み出したわけではない。
2. 人がKEY[0]を押して離した後、凍結sequence `49,50,141,142,209,210,277,278,325,326,379,380,431,432,487,488,559,560,719,720` を既存C3 v2 runnerで実行。Quartus STP終了コード0、20要求完了。
3. PowerShell post-audit: exit 0, `PASS`; 20/20、sequence/order、build/model、予測・Exit、応答ID、CRC、cycle validity、scope/cable検査の違反0。
4. `audit_saved_c3_v2_runs.py`による独立Python監査: `PASS_SAVED_PHYSICAL_EVIDENCE_AUDIT`。
5. `create_key_reset_replay_gate.py`は実測JSON・PowerShell audit・SHAと操作者確認を検査し、reset gateを作成。gate SHA-256: `80e841815718d326014a36d5651af792bce539e1d1f857f315ab68a6c6425c2c`。

Observed FPGA `mcycle` delta: min 565,954; median 943,929; max 2,082,594 cycles. These are empirical counts for this board/build and measured boundary; they are not calibrated absolute time or a WCET/deadline guarantee.

## 解釈と限界

このrunはKEY reset後にC3 v2 mailbox/推論経路が同じ20要求で再びREADYとなり、凍結参照値と一致したことを示す。電気的なreset波形を直接計測した証拠ではなく、KEY押下・解放は操作者の申告としてgateに記録した。B-SIGNOFFは引き続きBLOCKED。B-EMPIRICALの限定的なpilot判定を正式タイミング保証へ格上げしない。360入力campaignは本runでは実施していない。

## 再現コマンド

Working directory for Quartus STP: `C:\altera_lite\25.1std\quartus\bin64` (ASCII path).

```powershell
$stage = Join-Path $env:TEMP 'rtnn-c3v2-key-reset-20261115-run2'
$runId = 'C3V2_TENINPUT_KEY_RESET_REPLAY_20261115_RUN2'
$seq = '49,50,141,142,209,210,277,278,325,326,379,380,431,432,487,488,559,560,719,720'
& 'C:\altera_lite\25.1std\quartus\bin64\quartus_stp_tcl.exe' -t (Join-Path $stage 'run_c3_measurement_v2.tcl') (Join-Path $stage 'cases.csv') (Join-Path $stage 'binding.json') (Join-Path $stage $runId) '85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d' $runId $seq
```

The retained Quartus STP log/exit code, `c2_jtag_raw.log`, result JSON/CSV, case/binding copies, both audit JSON files, post-run read-only identity log/exit code, and reset gate are in this directory. `SHA256SUMS.txt` records their hashes. No commit or push was made.

