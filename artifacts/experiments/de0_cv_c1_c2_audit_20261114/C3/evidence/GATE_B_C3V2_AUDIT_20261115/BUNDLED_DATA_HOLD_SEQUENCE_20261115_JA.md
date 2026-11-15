# C3 v2 bundled-data hold/capture sequence audit

確認日: 2026-11-15  
対象: C3 v2 build `43334531`, Quartus Prime Lite 25.1std.0 Build 1129  
分類: source/保存済みpost-fit STA/既存有限回帰の照合。今回は再compile・simulation・JTAG操作なし。

## Identity

| file | SHA-256 |
|---|---|
| `source/measurement_protocol_v2_43334531_20261115/rtnn_c2_vjtag_mailbox.sv` | `7cc0cb69bfddf4309f3b95370ce7c0e06b99e235eb8204b40816f40ff0f719d1` |
| `source/measurement_protocol_v2_43334531_20261115/rtnn_de0_cv_soc_c2.sv` | `0902a2b9db68fbc27c4aa155b5fb43025a46529b519850c78e7386694d6d19af` |
| `source/measurement_protocol_v2_43334531_20261115/firmware/rtnn_c2_main.c` | `fc08bd04460135655e067143ef4cfdfe01a08f64539e2612201e20ad19f826ef` |
| `source/measurement_protocol_v2_43334531_20261115/tb_rtnn_c2_soc_42.sv` | `17908038fde678f4f5ac3c9c0c0e0fcb638b792028ad976633a0feb427f894dc` |
| C3 v2 SDC, Quartus RETRY02 | `ceaaa6708f0ed8f6d2c1443b60d9511c51d21f96ddaf914117ee6a65410c82eb` |
| `C3_MEASUREMENT_V2_STA_RETRY03_20261115/cdc_bus_path_delay_summary.txt` | `b8780599d319d786530d703cd97f2a7c233c4af93094753bb3e88716dda5a64a` |

## RTL handshake sequence

The RTL and firmware describe these two transfers:

1. **Request publication, TCK → CLOCK_50.** An accepted 800-bit `UpdateDR` copies the completed shift register to `req_hold_tck_q` and flips `req_toggle_tck_q` (mailbox lines 164–171). The held bus and toggle pass through two CLOCK_50 registers. The synchronized toggle sets `req_capture_pending_sys_q`; one later CLOCK_50 edge copies `req_bus_sync2_sys_q` into `request_data_o` (lines 209–224). Firmware copies the full request before writing `C2_REQ_ACK` (firmware lines 73–85). The ack returns through two TCK synchronizer stages; `pending_tck_q` clears only after the synchronized ack equals the published toggle (mailbox lines 111–123, 226–229). The request source register is not rewritten on ack; it is only assigned on reset or a later valid request publication.
2. **Response publication, CLOCK_50 → TCK.** Firmware writes all 60 response bytes, then writes the final commit word (firmware lines 42–49). The SoC checks the complete-byte mask and matching request sequence, raises its registered `jtag_response_commit_o`, and does not change response bytes as part of the commit itself (SoC lines 54–65, 116–128). The mailbox sees that registered pulse, flips `rsp_toggle_sys_q`, and exposes `response_data_i` through two TCK-domain synchronizer registers. After the synchronized toggle is observed, `rsp_capture_pending_tck_q` adds a further TCK edge before copying `rsp_bus_sync2_tck_q` into `rsp_hold_tck_q` (mailbox lines 109–132 and 230–240). Firmware then returns to its status-poll loop and does not write another response until a later request (firmware lines 70–74, 120–121). The TCK interface blocks another request while response-pending/DONE/error state is active; a complete 480-bit response scan clears `response_pending_tck_q` and toggles consume (mailbox lines 134–147, 164–184).

The existing `tb_rtnn_c2_soc_42.sv` has simulation guards for request stability until synchronized ack, response stability from commit through TCK capture and through response consumption, and exact payload equality at both capture points (lines 42–115). These assertions were exercised by the recorded finite regression; they are not a formal proof over every clock phase, reset interleaving, or metastability outcome.

**Hold-property boundary:** request storage is naturally retained by the mailbox until a later accepted submission. Response-word storage is not independently write-locked in the SoC once commit is published; the source registers can change if the CPU performs more response MMIO writes. For this measured fixed firmware, `store_response()` commits last and `main()` then returns to the status-poll loop; the mailbox will not present another request until the host has consumed the response. Thus the expected source hold follows from this firmware/mailbox protocol. It is not an RTL-enforced invariant against arbitrary or faulty CPU writes after commit. The existing response guard tests the current valid firmware sequence, not that fault-injection case. This limitation remains explicit and is not waived by the route report.

## Post-fit routed data evidence

The exact C3 v2 STA RETRY03 `path_coverage` and four-corner net-delay reports cover 800 request source/destination bits and 480 logical response destination bits. The original source selector count of 484 is reconciled separately as 480 logical payload coordinates plus 4 Quartus `~DUPLICATE` fitter instances; no 4 extra logical response bits are asserted. The SDC limits each covered source-Q to first-synchronizer-D routed net to 16 ns. Saved reports show:

| Corner | Request routed net max | Response routed net max | Request max–min spread | Response max–min spread |
|---:|---:|---:|---:|---:|
| 0 | 3.323 ns | 3.633 ns | 2.696 ns | 3.007 ns |
| 1 | 3.186 ns | 3.521 ns | 2.561 ns | 2.897 ns |
| 2 | 2.183 ns | 2.373 ns | 1.886 ns | 2.076 ns |
| 3 | 1.891 ns | 2.050 ns | 1.613 ns | 1.772 ns |

The max-minus-min figures summarize the listed routed-net delays; they are **not** a Quartus `report_max_skew` result. The saved `report_max_skew` files say “Nothing to report.” The 16 ns value is explicitly an empirical routing screen, not a vendor-derived CDC guarantee. The screen covers internal routed net delay to the first payload synchronizer stage; it does not cover external USB-Blaster TCK/TDI/TMS/TDO timing, metastability MTBF, or all possible RTL traces. D102 remains 16 and unwaived.

## Gate disposition

This audit confirms that source, finite regression assertions, and saved post-fit route indices describe a consistent hold/ack/capture/consume protocol. It does not turn finite simulation into formal CDC proof, and it does not close the remaining external JTAG I/O timing paths. B-SIGNOFF remains **BLOCKED**; no `set_input_delay`, `set_output_delay`, false path, or timing waiver was added.
