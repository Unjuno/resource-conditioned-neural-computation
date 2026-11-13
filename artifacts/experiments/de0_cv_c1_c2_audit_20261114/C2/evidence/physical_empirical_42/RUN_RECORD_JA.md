# RTNN C2J2 実機JTAG 42ケース run record

- 実施日時: 2026-11-13 JST
- Repository: `C:\Users\junny\OneDrive\ドキュメント\ChatGPT\RTNN`
- Branch/HEAD: `codex/stage-c2-jtag-20261111` / `48f2e81d87a710ac89b3bcf8ef36f71440d1e6c9`（作業中、未commit）
- 実験ID: `C2J2_HW_ALL42_RUN1_20261113`
- Scope: external JTAG I/O STAが未完了であることを明示し、formal timing signoffから区別する経験的qualification。ユーザー指示に基づき実施。

## 対象と固定データ

- Board FPGA: Terasic DE0-CV, Cyclone V `5CEBA4F23C7N`
- Cable/device: `USB-Blaster [USB-0]`; IDCODE `02B050DD`
- Quartus Prime Lite/STP/Programmer: `25.1std.0 Build 1129`
- Frozen C2J2 cases CSV: SHA-256 `52b7fdae7c465fd4b6409876e258e00fbaad5656e93ad3b9fb79f2f8741aec5d`; 42 cases; model ID `52544e4e`; build ID `43324a32`
- SOF: `../quartus_d101_exact_disposition_20261113/rtnn_c2.sof`; SHA-256 `5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6`
- No model weights, reference vectors, RTL, firmware, QSF, or SDC were modified for the host-side fixes.

## Commands and outcomes

Repository root was the PowerShell cwd unless otherwise specified.

1. Read-only chain detection: `C:\altera_lite\25.1std\quartus\bin64\jtagconfig.exe -n`; exit 0. Final output reports `USB-Blaster [USB-0]`, IDCODE `02B050DD`, and `Virtual JTAG #0`.
2. SRAM configuration: `quartus_pgm -c "USB-Blaster [USB-0]" -m JTAG -o "p;<absolute path to rtnn_c2.sof>"`; exit 0, one device configured, 0 errors/0 Quartus warnings. Repeated to reset between separate experiments. No `.pof`, `.jic`, erase, Flash, or CFM command.
3. Single case: `Invoke-C2J2JtagExperiment.ps1 -SofPath <rtnn_c2.sof> -ExperimentId C2J2_HW_SINGLE_SEQ2_ASCII_20261113 -OutputDirectory <evidence/.../single_seq2_ascii_alias> -CaseSequences 2`; exit 0. Prediction 3/reference frozen model output 3, admitted/executed Exit 1, cycle 482,034, valid CRC and response identity.
4. Subset: same entrypoint with `-CaseSequences 2,27,34`; after fix, exit 0, all three pass. Cycles: seq2 482,034; seq27 565,950; seq34 1,577,043.
5. Full frozen set: `Invoke-C2J2JtagExperiment.ps1 -SofPath <rtnn_c2.sof> -ExperimentId C2J2_HW_ALL42_RUN1_20261113 -OutputDirectory <evidence/.../all42_run1>`; exit 0, Quartus STP/Tcl exit 0, independent result auditor exit 0, `PASS_RUN_AND_ARTIFACT_AUDIT`, `scope=all_frozen_42`, 42/42 PASS.
6. Reset replay: SRAM-only reconfiguration followed by sequence 2 with experiment ID `C2J2_HW_RESET_REPLAY_SEQ2_20261113`; exit 0. Prediction/Exit/cycle exactly replayed: 3 / 1 / 482,034.

All programmer/Tcl stdout, exit codes, exact command records, raw scans, CSV/JSON, auditor output, and `run_manifest.json` are preserved in this directory. The final 42-case artifact hashes are listed by `all42_run1/run_manifest.json` and the local `SHA256SUMS.txt`.

## Result audit summary

- Frozen expected predictions mismatched: 0/42.
- Admitted/executed Exit mismatches: 0/42.
- Response sequence/input/mode mismatch: 0/42.
- Invalid response CRC: 0/42.
- Invalid/missing/zero cycle count: 0/42.
- Executed Exit above admitted cap: 0/42.
- Failed, timed out, or missing cases: 0/42.
- FPGA `mcycle` observed range: 20,146–2,791,485 cycles; median 1,031,300.5 cycles. No conversion to seconds was made.
- 18 predictions differ from the separately recorded ground-truth `reference_label`; all 42 match the frozen model `expected_prediction`. Labels and frozen model outputs are distinct fields; this does not represent a hardware mismatch.
- UART unused; GPIO loopback unused; Flash/CFM unchanged.

## Reproduced issues and fixes

### Quartus Tcl paths with Japanese characters

Passing a Tcl script/CSV/output absolute path containing `ドキュメント` reproduced Quartus STP/Tcl exit 3 with `package "fil_test" isn't loaded statically`. A minimal API probe using the repository-relative ASCII path succeeded. A Windows directory junction `C:\rtnn_c2_20261113` now targets this repository; Quartus Tcl paths use that ASCII alias, and the Quartus process cwd is `C:\altera_lite\25.1std\quartus\bin64`. The PowerShell runner validates alias type and target before use. Failure/success probes are `quartus_stp_tcl_arg_probe_fullpath.log` and `quartus_stp_tcl_arg_probe_junction.log`.

### Response-consume/update handshake

Initial seq2 completed, but an IR_RESPONSE read without a shifted input value left DONE at `0x40`; the next seq27 produced mailbox ERROR `0xC0`, and the response RAM still held seq2. Reconfigured and ran seq27 alone: PASS, which isolated the failure to repeated-request handling. A diagnostic response read that shifted 384 zero bits into IR_RESPONSE caused DONE to clear and READY `0x08` to return. `host/run_c2_jtag.tcl` now supplies those zeros on the response DR scan and waits for READY after each response. The corrected 3-case and 42-case runs pass.

An earlier experiment that added READY polling but did not issue response UpdateDR stayed in the poll until stopped after about a minute. It is retained as an incomplete diagnostic run, not counted as PASS. Other failed attempts and their logs remain in this directory.

## Timing and performance limits

The JTAG empirical experiment passed on this physical board, but Quartus STA still reports setup/hold not fully constrained and does not contain the board/cable external TDI/TMS/TDO delays. Actual onboard TCK and board launch/capture skew were not measured. Therefore formal board-level timing signoff remains BLOCKED. `mcycle` values are FPGA cycle counts only; no absolute runtime, oscillator tolerance, or all-lot guarantee is claimed.

## Changed source files

- `host/Invoke-C2JtagExperiment.ps1`: validate/use ASCII junction paths and ASCII Quartus cwd.
- `host/run_c2_jtag.tcl`: response DR zero-fill to issue UpdateDR, then wait for mailbox READY.

No RTL recompile was required for these host-only fixes. Source changes are uncommitted and unpushed.

## Tool/source SHA-256

- `jtagconfig.exe`: `e7a5b511735a9a824249ccdfd88b10cabb4860a87442bc59ec6ad668e6c0b01f`
- `quartus_pgm.exe`: `10266336f31f75ef5abed3054dd572266966cb87956b9abe5c6bdf599ec28c46`
- `quartus_stp_tcl.exe`: `79d33bbb250a7684865c3efce13cc80f7ee3373b8c1a8e1c397b3e76a6388ce7`
- `host/Invoke-C2JtagExperiment.ps1`: `b6220ece903a9d56fc89423636c4cad8ad7dca10a45da4078870c71d9577fb2a`
- `host/run_c2_jtag.tcl`: `4154eaeb04155962c14c89af82ef6051ef13f808d69e2ed0524556678b050612`
- `host/Invoke-C2J2JtagExperiment.ps1`: `4e9503a7e6afb7699e2c4a9a08ebad26f3396ed09f3c6f51dba94c23de9035c6`
- Frozen CSV: `52b7fdae7c465fd4b6409876e258e00fbaad5656e93ad3b9fb79f2f8741aec5d`
- Candidate SOF: `5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6`
- Fitted QSF: `9d270c2f57ca7f6ee1f68f4d525a685625a7cc5311b0a55ee363e23f823f675e`
- Fitted SDC: `8ba18e9829ebb9754278867948a1b0fffb360144738f1c3e45f1650592a87690`
- Quartus flat SoC RTL: `fdfcdf037eb55225e3e6eef06b01fc92e608951c54ece946461408131f2e5ca7`
- Python 3.11.9; PowerShell 7.6.9; Quartus 25.1std.0 Build 1129.

## 最終追記：入口検証とソース識別子

物理qualification後に、変更済み`host/Invoke-C2JtagExperiment.ps1`をPowerShell ASTで再解析し、構文エラー0を確認した。C2J2固定入口の`-ValidateOnly -CaseSequences 2,27,34`を再実行しexit 0。凍結CSV SHA-256 `52b7fdae7c465fd4b6409876e258e00fbaad5656e93ad3b9fb79f2f8741aec5d`、build `43324a32`、payload audit PASS、3 sequence選択を確認し、hardware_access=none。ログは`validate_only_final_20261113/`。

Quartusへ渡すパス変換を確認した。repository内はASCII junction経由、外部ASCIIパスは絶対パス、外部日本語パスは拒否する。物理42件run自体は既にこの入口・junctionで完了している。

最終host/source SHA-256:
- `host/Invoke-C2JtagExperiment.ps1`: `b6220ece903a9d56fc89423636c4cad8ad7dca10a45da4078870c71d9577fb2a`
- `host/run_c2_jtag.tcl`: `4154eaeb04155962c14c89af82ef6051ef13f808d69e2ed0524556678b050612`
- `host/Invoke-C2J2JtagExperiment.ps1`: `4e9503a7e6afb7699e2c4a9a08ebad26f3396ed09f3c6f51dba94c23de9035c6`

これらは実機の42件・reset replay記録と併せて読んでください。`result_audit.json`単独は物理接続の証明ではなく、物理provenanceはProgrammer/JTAGの生ログとこのrun recordで確認します。
