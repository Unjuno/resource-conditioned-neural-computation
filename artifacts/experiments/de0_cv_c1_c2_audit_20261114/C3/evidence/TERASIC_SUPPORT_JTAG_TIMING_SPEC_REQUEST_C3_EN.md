# Unsent Terasic timing specification request — C3

**Status: draft only. Do not send without the user's separate instruction.**

Subject: DE0-CV onboard USB-Blaster JTAG timing specifications by board revision

Hello Terasic Support,

I am preparing timing constraints for the onboard USB-Blaster path on a Terasic DE0-CV populated with a Cyclone V 5CEBA4F23C7N. Intel's Cyclone V Device Datasheet (683801, Table 56) already gives FPGA-side JTAG timing. I am seeking only the missing DE0-CV controller/board-path specifications applicable to the PCB revision and assembly, or the revision-specific document containing them.

For the onboard path, please confirm:

1. The onboard USB-Blaster controller's TCK period/frequency range, minimum high and low pulse widths or duty-cycle bounds, and startup/reset conditions that affect TCK or JTAG sampling.
2. The controller's TDI/TMS launch edge and the minimum/maximum relative propagation delay from the controller outputs to the Cyclone V pins (including the DE0-CV board path and any applicable USB cable/controller timing).
3. The controller's TDO capture edge and input setup/hold requirements, including the FPGA-to-controller path delay and sampling margin.
4. The applicable controller/FPGA I/O voltage and operating-temperature conditions for these board-path values.
5. Recommended Quartus SDC constraints, or an equivalent timing model, for the onboard controller/board TCK/TDI/TMS/TDO path. The FPGA-side setup/hold and TDO clock-to-output values are available in the Intel datasheet; the request is for controller and board-path values needed to apply them.

Please also indicate how to identify the relevant DE0-CV PCB revision and whether the timing values vary by revision or assembly. If available, please confirm the fitted EPM240T100 speed/temperature-grade suffix for each affected board revision. I am not requesting disclosure of the CPLD design source; revision-applicable guaranteed timing limits or an equivalent timing specification are sufficient.

Regards,
[Name]
