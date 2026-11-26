# RUN3 failure record — 2026-11-26

- Experiment: `C3_EXTVAL_PILOT_20261126_RUN3`; session: `PILOT_SESSION_20261126_RUN3`.
- Preflight: PASS, 20 cases, exact new SOF hash and build identity.
- SRAM SOF remained the authorized build; no Flash/CFM/CPLD operation occurred.
- Runner opened the board and issued the first request (sequence 1, input ID 3660, adaptive), then observed mailbox ERROR before capturing a response. `completed_cases=0/20`; no pilot gate is eligible.
- RUN2 had already used sequence 1 successfully (its response was recovered after the runner scan-width exception). RUN3 reused sequence 1 on the same live FPGA/application session. Sequence reuse is the leading hypothesis; confirm in firmware/mailbox source and status before deciding a recovery.
- Failure logs and inputs/binding are preserved in this directory. Do not overwrite or treat RUN2/RUN3 as complete pilot data.
- No further request was sent after the error.
# RUN3 failure analysis — confirmed

The first RUN3 request reused sequence 1 after RUN2 had successfully executed sequence 1 on the same running firmware instance. `firmware/src/rtnn_external_main.c` keeps `last_seq` in `main()` and rejects `req.seq <= last_seq` with `RTNN_EXT_STATUS_BAD_REQUEST`; this branch was confirmed in source. The recovered response has response status 4, sequence 1, zero cycle start/end, valid CRC, and matching Build/Binding/Model IDs. Thus RUN3 did not perform inference. The protocol mailbox was returned to READY by reading the complete 480-bit response.

RUN4 preserved the frozen 10-image/mode set and used new monotonic transport sequences 2–21. No SOF reconfiguration or power cycle was used between runs.
