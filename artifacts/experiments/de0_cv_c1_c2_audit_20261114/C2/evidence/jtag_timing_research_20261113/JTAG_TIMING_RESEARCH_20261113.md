# DE0-CV / Cyclone V JTAG timing research (2026-11-13)

## Primary references

- Altera Cyclone V Device Datasheet, “FPGA JTAG Configuration Timing”: https://docs.altera.com/r/docs/683801/current/cyclone-v-device-datasheet/fpga-jtag-configuration-timing?contentId=tHclXha2uF6DJBsBSWaFRA
- Altera Cyclone V Device Handbook, “I/O Voltage for JTAG Operation”: https://docs.altera.com/r/docs/683375/current/cyclone-v-device-handbook-volume-1-device-interfaces-and-integration/i/o-voltage-for-jtag-operation?contentId=~1Gc7noolGTbpSQrK~nXBQ
- Terasic DE0-CV System CD schematic is locally archived at `de0cv_setup/system_cd/Schematic/DE0-CV.pdf` (USB Blaster sheet 17); board USB-Blaster path contains FT245BL and MAX II EPM240T100 CPLD before the FPGA `BST_TCK/TMS/TDI/TDO` nets.
- Terasic's official [DE0-CV System CD index](https://download.terasic.com/downloads/cd-rom/de0-cv/) links `DE0-CV_v.1.2.1_SystemCD.zip`. The archive downloaded from that official host on 2026-11-13 has SHA-256 `ed4ac9cf4ae3d6ce27e6f2e66d42745b0a55fc2cc883b07069363d9947db942e`; its `Schematic/DE0-CV.pdf` is byte-identical to the repository copy (SHA-256 `3d41f88c3d03d72263ca776065345fe95548d10e0abe56e0c0653fa2f0e6021c`). The official archive contains the schematic and a ControlPanel SOF, but no MAX II USB-Blaster CPLD source or timing data.
- Altera's [JTAG timing constraints guide](https://docs.altera.com/r/docs/683081/22.2/quartus-prime-timing-analyzer-cookbook/jtag-signals?contentId=HqsgrDMGTE4REitNdjYy5w) provides separate timing models for USB-Blaster II-driven signals and says to customize PCB trace delays. Its example cable/driver values describe that cable model; they do not specify the DE0-CV's on-board FT245BL-to-EPM240 implementation. The [current Altera JTAG constraint guidance](https://docs.altera.com/r/docs/864466/current/usb-blaster-iii-fpga-development-cable-user-guide/creating-jtag-timing-constraints-in-quartus-prime-software) likewise says external board/cable min/max delays depend on the specific setup.

## Device timing values

The Cyclone V datasheet's FPGA JTAG timing table gives minimum TCK period 30 ns, minimum high and low times 14 ns, TDI setup 1 ns, TMS setup 3 ns, JTAG input hold 5 ns, and TDO clock-to-output maximum 11 ns (with a 1 ns adder per VCCIO voltage step below 3.0 V). A footnote raises the minimum period to 167 ns for the specified volatile-key programming condition at VCCBAT 1.2–1.5 V.

These are device-interface specifications. They are **not** the DE0-CV onboard USB-Blaster CPLD output delays or measured TCK/data skew. The reference to HPS JTAG timing would be inapplicable; only the FPGA JTAG configuration timing table is relevant here. A generic USB-Blaster II cable example also cannot substitute for the board's on-board FT245BL/EPM240 path.

## What this establishes and what remains unknown

The official numbers give the FPGA-side electrical timing requirements. The official Terasic board schematic establishes that the on-board USB-Blaster uses an FT245BL and an EPM240T100 CPLD to drive the FPGA JTAG path. The reviewed schematic material does not specify the actual EPM240 speed grade, CPLD output timing for the fitted board revision, PCB trace delay/skew, or the Quartus cable's exact TCK duty-cycle/data phase at this board. The official System CD's included ControlPanel SOF and Windows DLLs do not expose the CPLD's fitted logic or provide those timing parameters.

Therefore we cannot derive defensible `set_input_delay`/`set_output_delay` values for the board JTAG path from the FPGA timing table alone. Do not assume a generic standalone USB-Blaster cable launch/capture model, and do not insert guessed delays. Resolve this with a source specifying the fitted MAX II part/speed grade and interface timing, or with board-specific TCK/TDI/TMS/TDO measurements and a documented measurement method. Until then the C2 JTAG I/O timing gate remains BLOCKED.

## Consequence for current C2 candidate

The current SDC retains only the explicit 50 MHz clock, reset synchronization exceptions, and supplementary bundled-data `set_net_delay` bounds. It has no invented JTAG port delays or blanket false paths. The report's positive core slack and passing targeted net delays do not close the external JTAG I/O timing or bundled CDC signoff.
