# C3 Gate B 再監査 — 2026-11-15

## 対象と手順

- Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
- Branch / HEAD: `codex/stage-c3-jtag-pilot-20261114` / `c17c44e5556acc9c9e2d4fdbd114714c9c1ad804`
- Quartus project: C3 v2 build `43334531`, target Cyclone V `5CEBA4F23C7N`
- SDC SHA-256: `ceaaa6708f0ed8f6d2c1443b60d9511c51d21f96ddaf914117ee6a65410c82eb`
- Read-only audit sources: `C3_MEASUREMENT_V2_STA_RETRY03_20261115/` (four-corner TimeQuest reports), `C3_MEASUREMENT_V2_QUARTUS_RETRY02_20261115/rtnn_c3_measurement_v2.drc.rpt`, and `quartus_drc_postfit.log`.

No Quartus rebuild or board access was performed in this re-audit. The reports are those from the already recorded C3 v2 build and are not represented as newly generated results.

## Internal synchronous timing

The SDC defines `CLOCK_50` at 20.000 ns (50 MHz). Across the four recorded corners, each report found 20 setup and 20 hold paths with zero violations. Worst setup slack by corner was +1.803, +1.887, +10.027, and +11.154 ns. Worst hold slack was +0.259, +0.242, +0.134, and +0.124 ns. The worst reported setup and hold values are positive.

The design has two explicitly named false-path exceptions, both restricted to the external `KEY[0]` reset input and reset-release synchronizer registers (`rst_pipe_q` and `tck_reset_release_q`). There is no blanket false-path exception for Virtual-JTAG/TCK crossings.

## Bundled-data CDC screen and remaining warning

The SDC applies an internal maximum net-delay screen of 16.000 ns from the 800 request payload source registers to the request synchronizer's first stage, and from the response payload source registers to the response synchronizer's first stage. In the reports, request source/destination counts are 800/800 and response counts are 484 source / 480 destination registers. Maximum routed delay over the four corners is 3.323 ns for request and 3.633 ns for response. This 16 ns value is an internal engineering screen; it is not a board, cable, USB-Blaster, or Cyclone-V external JTAG specification.

Post-fit Design Assistant still reports 16 D102 bundled-data CDC structures. The warning has not been disabled or waived. The reviewed mailbox protocol holds each payload through synchronized acknowledgement/consume and the RTL regression checks capture-pending payload stability; that supports only the limited empirical pilot. It does not prove analog metastability behavior, MTBF, or a formal CDC timing bound.

## External timing: B-SIGNOFF remains blocked

TimeQuest's unconstrained-path summary reports:

| Category | Setup | Hold |
|---|---:|---:|
| Unconstrained input ports | 2 | 2 |
| Unconstrained input-port paths | 41 | 41 |
| Unconstrained output ports | 4 | 4 |
| Unconstrained output-port paths | 8 | 8 |

The inputs are `altera_reserved_tdi` and `altera_reserved_tms`; the outputs are `altera_reserved_tdo`, `LEDR[0]`, `LEDR[1]`, and `LEDR[3]`. Quartus lists no input/output delay for these ports. The LED outputs are board status indicators outside the inference measurement datapath, but they remain unconstrained and prevent claiming full-design signoff until their timing scope is explicitly closed. The report's `altera_reserved_tck` clock is 33.333 ns / 30 MHz; this is Quartus's internal generated clock representation and is **not** a measurement or guarantee of the physical onboard USB-Blaster TCK frequency, duty cycle, phase, or startup behavior.

The TDI/TMS launch relationship, TDO capture edge and setup/hold window at the onboard FT245BL/EPM240 controller, board/cable delay, and revision/assembly applicability remain unverified. Do not add guessed port delays or false paths. The spec-only Terasic inquiry is saved as an unsent draft in `TERASIC_SUPPORT_JTAG_TIMING_SPEC_REQUEST_C3_EN.md`; it does not request CPLD source disclosure.

### Public vendor-document check (2026-11-15)

Terasic's DE0-CV resource page lists User Manual v1.1.2 (2015-05-08), FAQ v2, and System CD v1.2.1 (2015-07-03). The manual copy reviewed describes an onboard USB-Blaster controller path containing FT245 and MAX II 240, distinguishes volatile `.sof` JTAG configuration from EPCS programming, and documents the board-level USB-Blaster port. The public manual does not provide the board/cable TCK waveform limits or external TDI/TMS/TDO timing model needed to close the current constraints. The exact PCB revision/assembly of the connected unit has not been read from a legible physical revision marking, so applicability cannot be narrowed to a revision. References: Terasic [DE0-CV Resources](https://www.terasic.com.tw/cgi-bin/page/archive.pl?CategoryNo=13&Language=English&No=921&PartNo=4); manual text available from the reviewed [DE0-CV User Manual PDF copy](https://mm.digikey.com/Volume0/opasdata/d220001/medias/docus/5740/DE0_CV_User_Manual_112.pdf). No support inquiry was sent.

Intel's Cyclone V Device Datasheet (683801, 2023-05-23), Table 56 "FPGA JTAG Configuration Timing", supplies the **FPGA-side** values: TCK period at least 30 ns; high and low times at least 14 ns each; TDI setup 1 ns; TMS setup 3 ns; JTAG hold 5 ns; and TDO clock-to-output at most 11 ns, with a voltage-step adjustment in footnote 76. Footnote 75's 167 ns TCK period applies only during volatile key programming when VCCBAT is 1.2–1.5 V; it is not generalized to this SOF/VJTAG measurement. The separate preceding HPS JTAG table is not the FPGA TAP table for this 5CEBA4F device. This narrows the remaining vendor question: DE0-CV revision/assembly-specific MAX II/FT245 controller edge relationships, TCK waveform/startup bounds, board propagation/skew and environmental conditions, plus a recommended SDC model. The FPGA datasheet values alone do not bound those board/controller paths or prove what the installed USB-Blaster emits. Reference: Intel [Cyclone V Device Datasheet, 683801](https://www.intel.com/programmable/technical-pdfs/683801.pdf), pp. 67–68 / Table 56 and footnotes 75–76.

The existing 2026-11-13 C2 JTAG timing follow-up is also applicable and was reused instead of repeating the System CD investigation. Its official MAX II Device Handbook lookup records EPM240 speed grades −3/−4/−5 and EPM240 `tCO` maxima 4.3/5.6/6.9 ns under 3.3-V LVTTL, maximum-drive/fast-slew, 10-pF conditions. The DE0-CV schematic identifies EPM240T100 but does not identify the fitted suffix. `tCO` is CPLD clock-to-output; it is not TCK-to-TDI/TMS relative skew and cannot by itself set Quartus port delays. The prior report SHA-256 is `db36400d9b3d3a9bc3013411902c41382b4e61fe5bfc81a84bbf9d92fd2b5fcb` at `C2/evidence/jtag_timing_research_20261113/JTAG_TIMING_RESEARCH_FOLLOWUP_20261113_JA.md`; the archive audit SHA-256 is `e995c7f034191170fb5b75b3df8e5cb402eb0e8c38d1e9129367aadb2e4b41df` at `C3/evidence/JTAG_CONTROLLER_PACKAGE_AUDIT_20261114/RUN_RECORD_JA.md`. Intel [MAX II Device Handbook](https://cdrdv2-public.intel.com/655094/max2_mii5v1.pdf), Tables 1-2 and 5-23. The prior measured/official-material conclusion remains that no board-specific `set_input_delay`/`set_output_delay` can be derived without the fitted grade, launch/capture behavior and board-path timing.

## Gate decision

- **B-SIGNOFF: BLOCKED.** External JTAG timing and unconstrained status LED outputs remain. Internal positive slack does not close this gate.
- **B-EMPIRICAL: PASS_LIMITED for the SRAM-only pilot on this exact C3 v2 build and board.** Internal synchronous checks and the documented structural CDC review support the finite pilot. The D102 rule remains visible; this is neither a replacement for B-SIGNOFF nor a timing/WCET/deadline guarantee.
- The previously recorded 42-request replay and first 20-request pilot session were independently re-audited from their raw logs and passed. The post-KEY-reset replay is still pending; the 24,840-row C3 v2 physical campaign remains NOT_RUN (0 rows).

The full source report hashes and per-run outputs remain in their referenced evidence directories. No historical campaign result was reclassified by this review.

## Machine-verifiable evidence index

The read-only checker `C3/source/audit_c3_gate_b_evidence.py` hashes the exact Quartus project inputs and outputs, SOF, ELF/BIN, RAM lanes, frozen Q15 header and host references, all 13 versioned SOF-bound campaign bindings, the four-corner TimeQuest reports, unconstrained-path summary and CDC route-delay summary. It verifies the per-file identities before summarizing the timing/CDC scope; it does not make unconstrained paths pass.

Execution bundle: `evidence/C3_GATE_B_EVIDENCE_AUDIT_20261115_FINAL/`. Python 3.11.9, exit 0; 59 source evidence files checked. The checker also hashes the three exact RTL snapshots and native source-list, and each campaign binding must match those source identities. All 13 bindings match the same build/model/reference/RAM/SOF identity and sum to 24,840 rows. Four corners each report 20 setup and 20 hold paths with zero reported violations and the recorded worst slack values. The tool preserves `B-SIGNOFF=BLOCKED`, `B-EMPIRICAL=PASS_LIMITED`, and a limitation that the STA result covers only the constrained/reported paths.

Output SHA-256: `gate_b_audit.json` = `324a2f14b69a85b7634c7f5ab4fe2f29306a0a7bde8d4fabc4181868e65319ad`. The final bundle contains the exact checker, JSON output, raw command log, exit code, and execution record. Its `SHA256SUMS.txt` independently covers those five files. The script's original command log, the preliminary 55-input audit, and earlier parser failures remain preserved in sibling evidence.



Final bundle manifest SHA-256: `3cd9716adc1e7796c22b52c2e8937ec006a58d0efd1c015668cc35d4c5086354`. The five entries in the manifest were rehashed and matched.
