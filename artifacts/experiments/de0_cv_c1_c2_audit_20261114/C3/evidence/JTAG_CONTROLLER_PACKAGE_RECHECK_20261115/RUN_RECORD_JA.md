# Terasic DE0-CV System CD archive recheck — 2026-11-15

- Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
- Branch/HEAD: `codex/stage-c3-jtag-pilot-20261114` / `b332ba02ab992227140998a1d67513c690ae17cf`
- CWD: `C:\Users\junny\OneDrive\ドキュメント\ChatGPT\RTNN` (all repo inputs and outputs passed by absolute path).
- Shell/tool: PowerShell 7.6.9; Python 3.11.9.
- Purpose: verify the retained official System CD archive identity and search its project/source files for any previously unrecorded onboard USB-Blaster/CPLD design or device project that could supply timing inputs.

## Input identity

- Official archive URL: `https://download.terasic.com/downloads/cd-rom/de0-cv/DE0-CV_v.1.2.1_SystemCD.zip`
- Retained local archive: `D:\RTNN_C3_external_docs_20261114\DE0-CV_v.1.2.1_SystemCD.zip`
- Size: 66,908,883 bytes
- SHA-256: `ed4ac9cf4ae3d6ce27e6f2e66d42745b0a55fc2cc883b07069363d9947db942e`
- Baseline selected-member inventory: `../JTAG_CONTROLLER_PACKAGE_AUDIT_20261114/archive_inventory.json`

## Execution and correction record

The initial checker attempt exited 1 after matching the archive hash, ZIP CRC, member count and selected files. Its parser selected only two of three recorded default-demo QSF assignments because it omitted `USE_CONFIGURATION_DEVICE`. The preserved failure is `OFFLINE_REPRO_20261115/terasic_archive_recheck_20261115.log` with exit `1`. Read-only inspection of the QSF in the ZIP confirmed the missing third line; the audit parser was corrected and the failed attempt was not overwritten.

Retry02 (`system_cd_timing_assets_audit_retry02.json`) exited 0 and verified the 1,089 member names, ZIP test, archive identity, selected schematic/ControlPanel/DLL hashes, ControlPanel SOF member and POF/JIC location. Retry03 extended the check to content-scan project/source members with extensions `.qar`, `.qsf`, `.qpf`, `.sdc`, `.v`, `.sv`, `.vhd`, `.vhdl`; it exited 0. Counts: 6 QSF, 6 QPF, 10 SDC, 86 Verilog, 75 SystemVerilog, 1 VHDL, 14 SOF, 2 POF and 1 JIC. Project `DEVICE` declarations found were only `5CEBA4F23C7`. The text scan found no `EPM240`, `MAX II`, or `USB-Blaster` term in those project/source files. POF/JIC files are confined to `Demonstrations/DE0_CV_Default`; the ControlPanel tool directory has the FPGA-side `DE0CV_ControlPanel.sof`.

The scan supports a scoped conclusion: this retained package does not identify a source/project/image for the onboard EPM240 USB-Blaster or a board-specific TCK/TDI/TMS/TDO timing envelope. It does not reverse-engineer SOF/POF/DLL binaries or exclude differently encoded/obfuscated content. No archive member was extracted to disk or executed, and no Quartus, USB-Blaster, JTAG, FPGA, Flash, KEY, or power operation was performed.

## Reproduction

PowerShell variables expanded to these absolute paths:

```powershell
python -m py_compile "<repo>\artifacts\experiments\de0_cv_c1_c2_audit_20261114\C3\source\audit_terasic_system_cd_timing_assets.py"
python "<repo>\artifacts\experiments\de0_cv_c1_c2_audit_20261114\C3\source\audit_terasic_system_cd_timing_assets.py" --archive "D:\RTNN_C3_external_docs_20261114\DE0-CV_v.1.2.1_SystemCD.zip" --inventory-json "<repo>\artifacts\experiments\de0_cv_c1_c2_audit_20261114\C3\evidence\JTAG_CONTROLLER_PACKAGE_AUDIT_20261114\archive_inventory.json" --output-json "<repo>\artifacts\experiments\de0_cv_c1_c2_audit_20261114\C3\evidence\JTAG_CONTROLLER_PACKAGE_RECHECK_20261115\system_cd_timing_assets_audit_retry03.json"
```

`<repo>` is `C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114`. Retry03 stdout and exit are preserved under `OFFLINE_REPRO_20261115/`. Script, run record and successful JSON hashes are in this directory's `SHA256SUMS.txt`.

### Final schema-label retry04

The content-scan JSON schema status was narrowed from a broad phrase to `ARCHIVE_IDENTITY_PASS_NO_CONTROLLER_TIMING_IN_SCANNED_PROJECT_SOURCES`, making the content-scan scope explicit. Retry04 regenerated the final JSON from the retained archive after `py_compile` exit 0; command and output are saved as `OFFLINE_REPRO_20261115/terasic_archive_recheck_retry04.log` and `.exitcode`. Exit 0, ZIP/SHA/member/device/source-scan results unchanged. Earlier retry01 failure and retry02/retry03 artifacts remain preserved.
