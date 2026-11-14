Subject: DE0-CV onboard USB-Blaster (FT245BL + EPM240T100) JTAG timing data

Hello Terasic Support,

I am characterizing JTAG timing for a DE0-CV using its onboard USB-Blaster. The DE0-CV v1.2.1 System CD schematic identifies the onboard path as FT245BL to EPM240T100 (24 MHz reference) to the Cyclone V 5CEBA4F23C7N. The System CD I audited contains the Control Panel SOF and host DLLs, but no EPM240 project/source or separately identified onboard USB-Blaster programming image.

Could you provide or confirm:
1. The EPM240T100 project/source or the exact programmed image/version used for the onboard USB-Blaster.
2. TCK frequency range, high/low-time or duty-cycle bounds, and whether Quartus/JTAG Server can change or query the onboard TCK rate.
3. At the Cyclone V pins, the worst-case TDI/TMS input arrival/setup/hold relative to TCK, and the TDO capture edge/window at the EPM240.
4. Applicable board trace/translator delays and any recommended Quartus SDC virtual-clock/input-delay/output-delay constraints.
5. Whether these values vary by DE0-CV PCB revision or assembly, and how to identify the revision.

I will use the response only to constrain and verify the actual DE0-CV onboard path; I will not transfer USB-Blaster II/III timing values to it. I can provide the board serial number and PCB revision after confirming them.

Regards,
[Name]