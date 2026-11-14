# Cold boot 3/3後のユーザー確認済みJTAG照会（読み取り専用）

* 実行時刻: 2026-11-14 20:34:57 +09:00
* Repository branch/HEAD: recorded in `COMMANDS_AND_STATUS.txt`.
* User confirmed DC power cycle 3/3 and all LEDs off before power-on.
* USB-Blaster USB-B remained connected as instructed; this does not prove that all FPGA supply rails lost power.
* Quartus Prime Lite version and exit code are in `quartus_version.log`.
* `jtagconfig -n` output and exit code are in `jtagconfig_n.log`.
* Detected USB-Blaster `[USB-0]`, Cyclone V IDCODE `02B050DD`, Virtual JTAG node `00406E00`, design hash `DF2731CF973C3275CFE6`.
* PASS: JTAG chain and design-identity readback.
* UNCERTAIN: independent cold boot / full FPGA rail discharge. The same design hash after DC off/on without a SOF write does not identify whether power remained or the design was restored from nonvolatile configuration.
* No SOF programming, Flash/CFM write, or experiment request was performed.
