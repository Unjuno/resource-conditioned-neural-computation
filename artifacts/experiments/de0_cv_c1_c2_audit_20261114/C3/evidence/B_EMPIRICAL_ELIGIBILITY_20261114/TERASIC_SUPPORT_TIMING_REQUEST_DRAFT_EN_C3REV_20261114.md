# Draft only — not sent

**To:** `support@terasic.com`
**Subject:** DE0-CV onboard USB-Blaster: board-revision-specific JTAG timing specification

Hello Terasic Support,

I am validating the external JTAG timing for a Terasic DE0-CV with Cyclone V `5CEBA4F23C7N` and its onboard USB-Blaster. The DE0-CV System CD v1.2.1 schematic identifies the onboard USB path as FT245BL → EPM240T100 → Cyclone V. I can provide the board serial number, PCB revision, and Quartus version once confirmed.

For the applicable DE0-CV board revision and onboard cable implementation, could you provide or confirm the following timing specifications, or point me to an official document that contains them?

1. The TCK period range, minimum high/low pulse widths or duty-cycle bounds, idle/startup behavior, and whether Quartus Programmer/JTAG Server can query or set the onboard TCK rate.
2. At the Cyclone V JTAG pins, the minimum and maximum TDI/TMS arrival times relative to TCK, including launch/capture edge, setup, and hold requirements.
3. For TDO, the capture edge/window used by the onboard controller and the relevant setup/hold requirements at its receiving device.
4. Board-level path/translator delay bounds and any specified variation by PCB revision, assembly, voltage, or temperature.
5. A recommended Quartus SDC constraint method or equivalent timing budget for this exact onboard path, including virtual-clock, input-delay, and output-delay assumptions.
6. How to identify the applicable PCB revision and whether the published data covers the fitted EPM240 implementation on that revision.

I am requesting the applicable interface timing specification and constraint assumptions only; I do not need the complete EPM240 design source. I will not substitute timing values from USB-Blaster II/III or another standalone cable for the DE0-CV onboard circuit.

Thank you,

[Name]

## Suggested attachments (not yet attached)

- DE0-CV board serial/PCB-revision photo after confirming it.
- Relevant DE0-CV System CD v1.2.1 schematic pages showing the Cyclone V JTAG power connection and onboard USB-Blaster path.
- A short extract of the C2J2 Quartus timing report identifying the unconstrained TDI/TMS/TDO paths, plus the current SDC.
