# Quartus Prime Lite 25.1 — C2J2 exact-node D101 disposition candidate

Date: 2026-11-13 JST
Build tag: RTNN-C2-JTAG-20261111-C2J2; build ID 43324a32
Device: Cyclone V 5CEBA4F23C7
Quartus: Prime Lite 25.1std.0 Build 1129, Windows
Build cwd: D:\rtnn_c2_d101_disposition_20261113
Evidence folder: evidence/quartus_d101_exact_disposition_20261113

## Commands and outcomes

| Command | Exit | Result |
|---|---:|---|
| quartus_sh --flow compile rtnn_c2 | 0 | Analysis and Synthesis, Fitter, Assembler, and Timing Analyzer completed. SOF emitted but not programmed. The run reported 392 warnings. |
| quartus_drc rtnn_c2 --post_fit=on | 0 | Design Assistant reported 0 errors, 0 warnings, 0 High violations, and 341 information-only messages (T101=291, T102=50). Global D101, D102, and D103 remain On. Exactly 801 individually enumerated D101 nodes are locally Off: 800 request bits and one response representative. |
| quartus_sta -t allcorners_cdc_audit_disposition.tcl | 0 | Four corners; 800/800 request and 384/384 response data paths per corner. The source/destination index audit passed. All configured net-delay checks have positive slack. report_max_skew found no paths and is not a pass. |
| audit_c2_postfit_paths.py | 0 | Path counts, complete bit-index maps, and net-delay bounds passed for all four corners. |
| audit_d101_exact_disposition.py | 0 | All 801 QSF node settings match the DRC local-Off list and the expected 800 request plus one response target. Global rules remain enabled. |

The D101 assignments use Altera's documented DISABLE_DA_RULE setting with exact targets and source entities. Wildcard attempts crashed Quartus Lite and are not used. The clean unwaived DRC with 801 raw High D101 findings is preserved separately in evidence/quartus_d101_raw_unwaived_20261113. The raw report remains visible. This candidate applies only per-node disposition to the held-stable bundled-data handshake; it does not globally disable D101. Altera's D101 handshake guidance says the payload may remain stable while only REQ/ACK control signals are synchronized. Official references: https://docs.altera.com/r/docs/d815780/current/quartus-prime-standard-edition-settings-file-reference-manual/disable_da_rule?contentId=2Uif3wp_bJFY~DNb6VAPPQ and https://resources.altera.com/quartushelp/15.1/verify/da/comp_file_rules_synch_no.htm.

## Fitter and timing

Fitter completed successfully. Utilization: 4,034/18,480 ALMs (22%), 6,293 registers, 2,097,152/3,153,920 block-memory bits (66%), 256/308 RAM blocks (83%), and 3/66 DSP blocks.

Setup/hold slack by corner, in ns: slow 1100 mV 85 C +0.821/+0.242; slow 1100 mV 0 C +0.979/+0.239; fast 1100 mV 85 C +9.638/+0.128; fast 1100 mV 0 C +10.648/+0.116.

Request paths have maximum actual net delays 3.358, 3.263, 2.085, and 1.822 ns against a 16 ns bound. Response paths have maximum actual net delays 3.157, 3.037, 2.067, and 1.798 ns against a 24 ns bound. The full four-corner path audit is in c2_postfit_path_audit.json.

Timing Analyzer explicitly says setup and hold requirements are not fully constrained. Its unconstrained I/O report includes JTAG TDI/TMS/TDO and LED outputs. Therefore Fitter and internal checks passed, but board-level timing signoff is BLOCKED. No false path was added to obtain a pass. This SOF is evidence only and does not authorize SRAM configuration yet.

## Warning review

All 392 warnings are retained in the compile log and classified in QUARTUS_WARNING_REVIEW_JA.md. Counts: 10335=216, 10036=89, 10766=76, 10230=4, 12473=3, 13024=1, 13410=1, 15714=1, and 292013=1. The review calls out the incomplete LED drive/slew assignments and ignored synthesis attributes; no warning was hidden.

The first version of audit_d101_exact_disposition.py incorrectly required every D101 target to belong to the mailbox entity. It failed because the single response representative belongs to the SoC entity. The script was corrected to check request and response source entities separately; the corrected audit exits 0. The initial failed audit log and exit code are retained.

## SHA-256

- Exact-disposition QSF: 9d270c2f57ca7f6ee1f68f4d525a685625a7cc5311b0a55ee363e23f823f675e
- Clean unwaived baseline QSF: 6dfde92473708e4697c869d423c1c532f1c5dd27fc27749cb0b293a73d9527d1
- Flat SoC RTL: fdfcdf037eb55225e3e6eef06b01fc92e608951c54ece946461408131f2e5ca7
- Physical top: 639e58115cc2f249b7aceb9e89fd2670896c5810ea442c31836926ac3bed5d5a
- SDC: 8ba18e9829ebb9754278867948a1b0fffb360144738f1c3e45f1650592a87690
- Global TCK buffer: 98d4ac6fc5b541197efc046e647af0537f68a42789b3c8fce4872ae60e125a5a
- SOF: 5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6

RAM lane image hashes, full reports, source files, scripts, and all logs are covered by SHA256SUMS.txt.

No C2 programming, SRAM write, or Flash/CFM operation occurred. JTAG evidence remains read-only cable and IDCODE enumeration; the C2 mailbox scan/write/read test and physical one-case/42-case runs are NOT_RUN.
