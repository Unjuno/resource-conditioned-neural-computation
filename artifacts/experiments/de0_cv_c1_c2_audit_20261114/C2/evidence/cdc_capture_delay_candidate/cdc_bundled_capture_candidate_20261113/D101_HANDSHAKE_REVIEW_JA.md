# C2 bundled-data CDC / D101 disposition review

Date: 2026-11-13  
Scope: `RTNN-C2-JTAG-20261111`, experimental direct-capture mailbox candidate only.

## Architecture and finding

The request and response payload buses are transferred by a toggle handshake (one outstanding request/response at a time), not by synchronizing each payload bit through two flip-flops. Each payload source is held stable until the destination-domain capture and returned acknowledgement/consume. The request/acknowledge and response/consume control toggles use two-stage synchronizers. The receiving domain waits for the synchronized toggle to be observed and then waits one additional full local clock before capturing the held payload.

The raw Quartus Prime Lite 25.1 Design Assistant report for the direct-capture candidate reports D101=801 and D102=0. The D101 structures in that report are the request payload source bits plus the response payload bundle representative; they are associated with the bundled payload paths, while the toggle control paths are separate. The report is preserved unmodified with the Quartus run. D101 is not re-described as a per-bit synchronizer PASS.

Altera's D101 rule guidance says that multi-bit data may use a handshake that guarantees the bus is stable when sampled; only REQ/ACK need synchronization, and the data-bit violation may be ignored for such a handshake. This is the documented technical rationale for reviewing a narrowly scoped disposition, not for globally turning off D101. Until the DA finding can be dispositioned in a supported way, the raw D101 result remains an open gate. See [Altera D101 rule guidance](https://resources.altera.com/quartushelp/15.1/verify/da/comp_file_rules_synch_no.htm).

## Evidence already available

- Native Verilator regression of the 42-case fixed-Ibex/Q15 SoC: 42/42 reference matches, reset replay, and seven negative cases passed. The candidate testbench includes source-stability guards for request and response buses and compares the captured bus with its stable source at the delayed capture edge.
- The sv2v regression passed 42/42 and the same public-port output checks. The sv2v-only testbench copy omits two hierarchical checks of private capture-pending signals because those signals are not part of the converted module's public interface; the native testbench keeps both private edge checks.
- Post-fit direct-capture net-delay report: request 800 source-to-destination paths and response 384 paths. Request worst actual delay 3.358 ns under a 16.000 ns bound; response worst actual delay 3.157 ns under a 24.000 ns bound.
- Independent response-path map audit: 384 unique source bits map to 384 unique destination bits by `source = response_words_q[word][bit]`, `destination = rsp_hold_tck_q[word*32+bit]`; missing and mismatched indices are both zero. Request path report contains 800 paths and uses identical source/destination bit indices.
- Normal four-corner setup/hold reports for the direct-capture candidate are positive. These results do not close the remaining board-I/O timing requirements or constitute final signoff.

## Required disposition controls

1. Preserve the unmodified Design Assistant report showing the original D101 findings.
2. Preserve all raw D101 findings. Two local DISABLE_DA_RULE forms were tested on 2026-11-13 and both crashed Quartus Lite 25.1 in its suppression parser; no accepted suppression or DA PASS is claimed. Revisit only with a Quartus-supported version/path, keep the scope limited to these bundled-data buses, and compare every remaining finding against the unmodified report.
3. Keep the generated asynchronous clock-group assignment and the explicit source-to-capture `set_net_delay` constraints. Do not add a blanket false path or claim that Quartus Lite `set_max_skew` passed when it reported no paths.
4. Require positive post-fit setup/hold in all four operating corners, exact complete net-delay coverage for all payload bits, a successful capture/bus-stability regression, and review of remaining Design Assistant findings before considering this candidate for a later gate.

## 2026-11-13 raw DRC and scoped-suppression follow-up

A clean project copied the original QSF and source files into `evidence/quartus_d101_raw_unwaived_20261113/`; QSF SHA-256 matches the tracked candidate. Full Quartus Lite 25.1 compilation completed with exit 0 and emitted a SOF. The unmodified post-fit DRC completed with exit 0 and reports 801 High D101 structures, zero D102, zero D103, and 341 information-only items (T101=291, T102=50). The report names 800 `req_hold_tck_q` source-bit structures plus one `response_words_q[11][31]` response structure representative. This raw count remains visible; the architecture review does not convert it into a DA PASS.

Two narrowly scoped `DISABLE_DA_RULE D101` probes crashed Quartus Lite 25.1 Build 1129 in `DRC_ASSG_MANAGER::tokenize_ruleid_string` / `preprocess_rule_suppression`, exit 2. The second probe used the official value-after-`-to` syntax; it failed the same way. Both logs and the probe fragments are preserved. No suppression is active in the clean QSF and no finding is hidden.

The clean run's four-corner setup/hold values were positive (slow 85 C +0.821/+0.242 ns; slow 0 C +0.979/+0.239 ns; fast 85 C +9.638/+0.128 ns; fast 0 C +10.648/+0.116 ns). Quartus explicitly says setup and hold are not fully constrained, so these are not timing signoff. See `evidence/quartus_d101_raw_unwaived_20261113/RUN_RECORD_JA.md` for commands, hashes, reports, and warning totals.

Altera's D101 guidance documents the stable-bus handshake rationale: https://resources.altera.com/quartushelp/15.1/verify/da/comp_file_rules_synch_no.htm. The raw DA gate remains unresolved because the tool's scoped suppression path crashes. No C2 SOF was sent to the board; SRAM and Flash/CFM remain untouched.



## 2026-11-13 exact-node disposition update

The preceding note about failed suppression probes is historical and is superseded for the fresh disposition candidate. Quartus Lite crashed on wildcard and malformed probes, but accepted the documented exact-node syntax when both the quoted target and entity were supplied. All 801 D101 nodes were individually enumerated (request `req_hold_tck_q[0..799]` and response representative `response_words_q[11][31]`) and set Off in the Design Assistant assignment table; the global D101 rule remains On. Post-fit Design Assistant then reported zero High violations, zero warnings, and 341 information-only messages. The unwaived report remains separately preserved with the original 801 High findings, so the suppression is auditable and limited to the documented stable bundled-data handshake.

The fresh exact-disposition full build passed Fitter and four-corner internal timing checks. Its path audit covers 800 request and 384 response data paths in each corner, with positive configured net-delay slack. `report_max_skew` still reports no paths. Timing Analyzer still identifies unconstrained setup/hold I/O including JTAG and LED pins; no board-level signoff is claimed. The candidate SOF was not programmed. See `evidence/quartus_d101_exact_disposition_20261113/` for complete inputs and results.
