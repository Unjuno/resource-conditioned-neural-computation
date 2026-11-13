#!/usr/bin/env python3
"""Recheck C2 bundled-data capture latency against saved four-corner path data.

This is a protocol-envelope audit, not a replacement for cross-clock STA,
external JTAG I/O timing, or firmware source review.
"""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path


EXPECTED_FLAT_SHA256 = "fdfcdf037eb55225e3e6eef06b01fc92e608951c54ece946461408131f2e5ca7"
EXPECTED_MTBF_SUMMARY_SHA256 = "d11668beeaffde1744313c0275412473550ac5e20221174be7734d082fdc8656"
EXPECTED_MTBF_REPORT_SHA256 = "00120db779ae93c5aaf3bc083bbaFD8259cdf2c3ffda5cdd9920ca328faef038".lower()


def sha256(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def require(condition: bool, message: str) -> None:
    if not condition:
        raise ValueError(message)


def parse_mtbf_summary(path: Path) -> dict:
    require(sha256(path).casefold() == EXPECTED_MTBF_SUMMARY_SHA256.casefold(),
            "MTBF summary SHA-256 differs from the extracted run artifact")
    with path.open(encoding="utf-8-sig", newline="") as stream:
        lines = [line for line in stream if line.strip()]
    rows = []
    for line in lines:
        if not line.startswith(";"):
            continue
        cells = [cell.strip() for cell in line.strip().strip(";").split(";")]
        if len(cells) != 5 or cells[0] == "Source Node":
            continue
        rows.append({"source": cells[0], "destination": cells[1],
                     "worst_mtbf": cells[2], "typical_mtbf": cells[3],
                     "included": cells[4]})
    uncalculated = [row for row in rows if row["worst_mtbf"] == "Not Calculated"]
    calculated = [row for row in rows if row["worst_mtbf"] != "Not Calculated"]
    require(len(rows) == 392, f"expected 392 chain summary rows, got {len(rows)}")
    require(len(uncalculated) == 383, f"expected 383 uncalculated rows, got {len(uncalculated)}")
    require(len(calculated) == 9, f"expected 9 calculated rows, got {len(calculated)}")
    require(all(row["included"] == "No" for row in uncalculated),
            "an uncalculated chain is unexpectedly included in design MTBF")
    require(all(row["included"] == "Yes" for row in calculated),
            "a calculated chain is unexpectedly excluded from design MTBF")
    payload = [row for row in uncalculated
               if "response_words_q[" in row["source"]
               and "rsp_hold_tck_q[" in row["destination"]]
    require(len(payload) == 383,
            f"uncalculated rows not all response payload auto-chains: {len(payload)}")
    require(all("Greater than 1 Billion" in row["worst_mtbf"]
                for row in calculated), "unexpected calculated MTBF label")
    return {"chain_count": len(rows), "calculated_count": len(calculated),
            "uncalculated_count": len(uncalculated),
            "uncalculated_response_payload_auto_chains": len(payload),
            "calculated_included_in_design_mtbf": True}


def audit(evidence: Path, mtbf_summary: Path, mtbf_report: Path) -> dict:
    quartus = evidence / "quartus_d101"
    flat = quartus / "rtnn_c2_soc_flat.v"
    require(sha256(flat) == EXPECTED_FLAT_SHA256,
            "flat RTL SHA-256 differs from C2J2 build")
    rtl = flat.read_text(encoding="utf-8", errors="strict")
    required_fragments = [
        "req_sync1_sys_q <= req_toggle_tck_q;",
        "req_sync2_sys_q <= req_sync1_sys_q;",
        "if (req_sync2_sys_q != req_seen_sys_q)",
        "request_data_o <= req_hold_tck_q;",
        "req_ack_toggle_sys_q <= req_seen_sys_q;",
        "req_ack_sync2_tck_q == req_toggle_tck_q",
        "rsp_sync1_tck_q <= rsp_toggle_sys_q;",
        "rsp_sync2_tck_q <= rsp_sync1_tck_q;",
        "if (rsp_sync2_tck_q != rsp_seen_tck_q)",
        "rsp_hold_tck_q <= response_data_i;",
        "rsp_consume_sync2_sys_q <= rsp_consume_sync1_sys_q;",
    ]
    missing = [fragment for fragment in required_fragments if fragment not in rtl]
    require(not missing, "exact RTL handshake fragments missing: " + repr(missing))

    path_audit = json.loads((quartus / "c2_postfit_path_audit.json").read_text(encoding="utf-8"))
    require(path_audit["corner_count"] == 4, "expected four timing corners")
    request = sorted(path_audit["request"], key=lambda row: row["corner"])
    response = sorted(path_audit["response"], key=lambda row: row["corner"])
    require([row["path_count"] for row in request] == [800] * 4,
            "request path endpoint coverage is not 800/800 at all corners")
    require([row["path_count"] for row in response] == [384] * 4,
            "response path endpoint coverage is not 384/384 at all corners")
    require([row["corner"] for row in request] == [0, 1, 2, 3]
            and [row["corner"] for row in response] == [0, 1, 2, 3],
            "corner identity mismatch")
    require(all(row["max_path_delay_ns"] <= 16.0 for row in request),
            "request max-net-delay bound failed")
    require(all(row["max_path_delay_ns"] <= 24.0 for row in response),
            "response max-net-delay bound failed")

    n_cycles = 3
    t_sys_ns = 20.0
    t_tck_min_ns = 30.0
    request_worst_ns = max(row["max_path_delay_ns"] for row in request)
    response_worst_ns = max(row["max_path_delay_ns"] for row in response)
    request_capture_window_ns = n_cycles * t_sys_ns
    response_capture_window_ns = n_cycles * t_tck_min_ns
    require(request_worst_ns == 3.358 and response_worst_ns == 3.157,
            "worst path delay differs from signed C2J2 audit evidence")
    mtbf = parse_mtbf_summary(mtbf_summary)
    require(sha256(mtbf_report).casefold() == EXPECTED_MTBF_REPORT_SHA256,
            "full MTBF report SHA-256 differs from the isolated Quartus run")

    return {
        "audit": "C2_BUNDLED_DATA_CAPTURE_ENVELOPE",
        "status": "PASS_BUNDLE_ENVELOPE_ONLY",
        "build_id": "43324a32",
        "flat_rtl_sha256": sha256(flat),
        "mtbf_summary_sha256": sha256(mtbf_summary),
        "mtbf_full_report_sha256": EXPECTED_MTBF_REPORT_SHA256,
        "mtbf_summary": mtbf,
        "capture_cycle_count_min": n_cycles,
        "request": {
            "destination_period_ns": t_sys_ns,
            "capture_envelope_ns": request_capture_window_ns,
            "path_endpoints_each_corner": 800,
            "max_observed_net_delay_ns": request_worst_ns,
            "sd_c_max_net_delay_bound_ns": 16.0,
            "window_minus_observed_net_delay_ns_not_setup_slack": round(request_capture_window_ns-request_worst_ns, 3),
            "corner_values_ns": [row["max_path_delay_ns"] for row in request],
        },
        "response": {
            "destination_period_min_ns": t_tck_min_ns,
            "capture_envelope_ns": response_capture_window_ns,
            "path_endpoints_each_corner": 384,
            "max_observed_net_delay_ns": response_worst_ns,
            "sd_c_max_net_delay_bound_ns": 24.0,
            "window_minus_observed_net_delay_ns_not_setup_slack": round(response_capture_window_ns-response_worst_ns, 3),
            "corner_values_ns": [row["max_path_delay_ns"] for row in response],
        },
        "limitations": [
            "The reported difference is a protocol-envelope comparison, not STA setup slack.",
            "The comparison omits clock-to-Q, destination setup, clock uncertainty, and measured board TCK envelope.",
            "Response source stability before snapshot depends on firmware not rewriting response words before host consume; firmware C source is absent from this migrated audit tree.",
            "This does not close the embedded asynchronous clock-group cut or external TDI/TMS/TDO board timing.",
        ],
        "gate_b_overall": "BLOCKED",
    }


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--evidence", type=Path, default=Path(__file__).resolve().parent)
    parser.add_argument("--mtbf-summary", type=Path, required=True,
                        help="392-row summary extracted from the full Quartus report")
    parser.add_argument("--mtbf-report", type=Path, required=True,
                        help="full Quartus report used to verify the recorded report hash")
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    result = audit(args.evidence.resolve(), args.mtbf_summary.resolve(),
                   args.mtbf_report.resolve())
    serialized = json.dumps(result, indent=2) + "\n"
    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(serialized, encoding="utf-8", newline="\n")
    print(serialized, end="")
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (OSError, ValueError, KeyError, TypeError) as error:
        print(json.dumps({"status": "FAIL", "error": str(error)}, indent=2))
        raise SystemExit(1)
