# On-board USB-Blaster設計資料の配布物監査（2026-11-14）

* 目録作成時刻: 2026-11-14 20:48:55 +09:00

## 取得・照合

* Official source: Terasic DE0-CV System CD archive, `DE0-CV_v.1.2.1_SystemCD.zip`.
* Download URL: https://download.terasic.com/downloads/cd-rom/de0-cv/DE0-CV_v.1.2.1_SystemCD.zip
* Archive SHA-256: `ed4ac9cf4ae3d6ce27e6f2e66d42745b0a55fc2cc883b07069363d9947db942e`; size 66,908,883 bytes.
* ZIP integrity: Python 3.11.9 `zipfile.testzip()` = PASS; 1,089 entries. Archive and members were inspected only; no EXE, DLL, SOF, POF, or JIC was run or programmed.
* Full selected-member inventory and hashes: `archive_inventory.json`.

The archive has `Tools/ControlPanel/DE0CV_ControlPanel.sof` and three Terasic JTAG/download DLLs. It has no member whose path contains `EPM240`, `CPLD`, `USBBlaster`, or `USB_Blaster`; it has no POF/JIC under `Tools/ControlPanel`. Its only POF/JIC members are under `Demonstrations/DE0_CV_Default`. That demo QSF selects Cyclone V `5CEBA4F23C7` and EPCS64, so these are FPGA/configuration-demo artifacts, not a disclosed onboard USB-Blaster EPM240 design image.

The archived schematic member `Schematic/DE0-CV.pdf` has SHA-256 `3d41f88c3d03d72263ca776065345fe95548d10e0abe56e0c0653fa2f0e6021c`. Sheet 17 labels the onboard path with FT245BL, EPM240T100, a 24 MHz oscillator, and `Blaster TO FPGA`. The System CD therefore identifies the relevant controller architecture but does not disclose its CPLD RTL/project, programmed image, or pin-level JTAG timing budget.

## Applicability of public cable documents

Altera's archived USB-Blaster Download Cable User Guide block diagram specifies a discrete cable containing `EPM7064AETC44`. The DE0-CV's integrated FT245BL/EPM240T100 circuit is different hardware, so that guide is not a valid source for the onboard TCK frequency, duty cycle, edge phase, output delays, or the TDO capture window. USB-Blaster II/III and Intel FPGA Download Cable timing examples are also different cable generations and are not substituted.

Official separate-cable guide: https://www.intel.com/content/dam/support/us/en/programmable/support-resources/bulk-container/pdfs/literature/ug/archives/ug-usb-blstr-15.1.pdf

## Gate B impact

The Cyclone V endpoint requirements and board schematic's 3.3 V JTAG rail are known, but the external path into/out of this FPGA is not bounded. TDI/TMS `set_input_delay`, TDO `set_output_delay`, and JTAG virtual-clock period/duty must not be filled with values from another cable or guessed. Gate B remains **BLOCKED**; this archive audit does not authorize or perform a new SOF fit or board write. To close this gap, obtain Terasic's EPM240 implementation/timing characterization or measure the actual TCK/TDI/TMS/TDO waveforms and board path with suitable instrumentation.

## Reproduction

* CWD: `C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114`
* Download: `Invoke-WebRequest -Uri <official ZIP URL> -OutFile D:\RTNN_C3_external_docs_20261114\DE0-CV_v.1.2.1_SystemCD.zip`
* Inventory: Python 3.11.9 `zipfile.ZipFile.testzip`, list members, SHA-256 selected members; see `archive_inventory.json`.
* Downloaded archive retained outside the repository at `D:\RTNN_C3_external_docs_20261114\DE0-CV_v.1.2.1_SystemCD.zip`; it is not committed.