# Official JTAG timing source audit — 2026-11-15

## Question

Can public official timing values be used to constrain the DE0-CV's actual onboard USB-Blaster path for Gate B-SIGNOFF?

## Evidence checked

1. Terasic's official DE0-CV product/resource page identifies the board as using an **on-board USB Blaster with a standard Type-B USB connector** and currently links the DE0-CV CD-ROM v1.2.1 dated 2015-07-03. The page does not provide TCK period/duty or TDI/TMS/TDO controller-to-FPGA timing limits.
   - <https://www.terasic.com.tw/cgi-bin/page/archive.pl?CategoryNo=163&Language=English&No=921&PartNo=4>
2. Altera's USB-Blaster III guide describes timing constraints for the **USB-Blaster III cable**. Its timing table gives values for that specific cable and expressly frames them as target-device timing at the cable's maximum operating capability. It does not identify the DE0-CV onboard implementation as USB-Blaster III.
   - <https://docs.altera.com/r/docs/864466/current/usb-blaster-iii-fpga-development-cable-user-guide/jtag-timing-constraints-and-waveforms>
   - <https://docs.altera.com/r/docs/864466/current/usb-blaster-iii-fpga-development-cable-user-guide/creating-jtag-timing-constraints-in-quartus-prime-software>
3. Cyclone V device timing data describes the FPGA endpoint requirements, not the DE0-CV's onboard host controller, controller launch/capture edges, or PCB/cable path.
   - <https://docs.altera.com/r/docs/683801/current/cyclone-v-device-datasheet/fpga-jtag-configuration-timing?contentId=tHclXha2uF6DJBsBSWaFRA>
4. The current-worktree package audit of the Terasic System CD found no source/model/timing report for the onboard EPM240 controller. The package is the 2015 release already hashed in the companion package audit; that same ZIP was not downloaded or searched again in this check.

## Conclusion

The public materials establish board family, onboard USB-Blaster presence, and Cyclone V endpoint requirements. They do **not** establish the actual DE0-CV controller waveform or external delays at the FPGA pins. USB-Blaster III cable values are not transferred to the board's onboard USB-Blaster. Therefore no defensible TCK virtual clock period/duty or TDI/TMS/TDO min/max external delay can be derived from these pages. Do not insert guessed `set_input_delay`, `set_output_delay`, or a blanket false path.

## Unsent vendor request

Ask Terasic to identify, for the exact DE0-CV PCB revision and onboard USB-Blaster path:

- whether its prior DE0-CV System CD/schematic matches that board revision and the controller/CPLD part plus speed grade;
- supported TCK period and minimum high/low time, including startup/slow-clock behavior;
- TDI and TMS launch edge plus minimum/maximum setup and hold at the Cyclone V pins relative to TCK;
- TDO capture edge and min/max setup/hold or controller-side capture timing, including path skew;
- voltage and temperature conditions and recommended Quartus SDC constraints or an equivalent interface timing specification.

This request was prepared as a question list only. It was not sent.

## Gate decision

`B-SIGNOFF = BLOCKED`. The saved internal STA, routed bundled-data checks, and finite RTL CDC phase stress remain useful evidence but cannot replace this missing external-interface timing contract. `B-EMPIRICAL` remains limited to the measured DE0-CV/build and carries no WCET or hard-deadline claim.
