#!/usr/bin/env python3
"""Check saved JTAG results against frozen cases. Does not establish hardware provenance."""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
from pathlib import Path
import re
import struct
import zlib


def digest(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def require(condition: bool, reason: str) -> None:
    if not condition:
        raise ValueError(reason)


def audit(args: argparse.Namespace) -> dict:
    require(digest(args.cases) == args.expected_cases_sha256, "frozen case SHA-256 mismatch")
    with args.cases.open(newline="", encoding="utf-8-sig") as f:
        source_rows = list(csv.DictReader(f))
    reference = {int(row["seq"]): row for row in source_rows}
    require(len(source_rows) == 42 and set(reference) == set(range(1, 43)), "invalid frozen sequence set")
    selected = list(range(1, 43)) if args.sequences == "ALL" else [int(s) for s in args.sequences.split(",")]
    require(bool(selected) and len(set(selected)) == len(selected) and set(selected) <= set(reference),
            "invalid sequence selection")
    builds = {row["build_id"] for row in source_rows}
    require(len(builds) == 1, "mixed reference build IDs")
    build = next(iter(builds))
    result_path = args.results / "c2_jtag_results.json"
    csv_path = args.results / "c2_jtag_results.csv"
    raw_path = args.results / "c2_jtag_raw.log"
    report = json.loads(result_path.read_text(encoding="utf-8-sig"))
    with csv_path.open(newline="", encoding="utf-8-sig") as f:
        csv_rows = list(csv.DictReader(f))
    raw_lines = raw_path.read_text(encoding="utf-8-sig").splitlines()
    require(report["schema"] == "rtnn-c2-jtag-results-v2", "unsupported result schema")
    require(report["experiment_id"] == args.experiment_id, "experiment identity mismatch")
    require(report["sof_sha256"] == args.sof_sha256 and report["build_id"] == build, "SOF/build identity mismatch")
    require(report["status"] == "PASS", "runner did not report PASS")
    require(report["uart"] is False and report["flash_written"] is False, "transport/Flash contract mismatch")
    expected_scope = "all_frozen_42" if selected == list(range(1, 43)) else "subset"
    require(report["scope"] == expected_scope and report["selected_sequences"] == selected, "selection/scope mismatch")
    require(report["expected_count"] == report["count"] == report["completed_count"] == len(selected), "count mismatch")
    require(len(report["cases"]) == len(csv_rows) == len(selected), "row count mismatch")
    request_lines = [line for line in raw_lines if line.startswith("REQUEST ")]
    response_lines = [line for line in raw_lines if line.startswith("RESPONSE ")]
    require(len(request_lines) == len(response_lines) == len(selected), "raw transaction count mismatch")
    for index, seq in enumerate(selected):
        r, row, ref = report["cases"][index], csv_rows[index], reference[seq]
        require(r["seq"] == seq and int(row["seq"]) == seq, f"seq={seq} row order mismatch")
        require(r["status"] == row["case_status"] == "PASS" and not r["error"] and not row["error"], f"seq={seq} failed case")
        require(r["cycle_valid"] is True and row["cycle_valid"] == "1", f"seq={seq} invalid cycles")
        require(type(r["cycles"]) is int and 0 < r["cycles"] <= 0xffffffff, f"seq={seq} cycle range")
        wire = r["response_lsb_hex"]
        require(bool(re.fullmatch(r"(?:0[xX])?[0-9a-fA-F]{1,96}", wire)), f"seq={seq} wire format")
        payload = int(wire, 16).to_bytes(48, "little")
        require(payload[:4] == b"RTNR" and payload[4] == 1 and payload[5] == 0, f"seq={seq} protocol header")
        require(struct.unpack_from("<I", payload, 44)[0] == zlib.crc32(payload[:44]), f"seq={seq} wire CRC")
        require(r["response_crc_valid"] is True and row["response_crc_valid"] == "1", f"seq={seq} CRC flag")
        response_seq, input_id, budget, deadline = struct.unpack_from("<IHHI", payload, 8)
        cycles, model_id, build_id = struct.unpack_from("<III", payload, 24)
        require((response_seq, input_id, budget, deadline) ==
                (seq, int(ref["input_id"]), int(ref["budget_q16"]), int(ref["deadline_cycles"])), f"seq={seq} response identity/budget")
        require(model_id == 0x52544e4e and build_id == int(build, 16), f"seq={seq} response model/build")
        require(payload[6] == int(ref["mode"]) and payload[7] == int(ref["expected_stop"]), f"seq={seq} mode/stop")
        require(list(payload[20:24]) == [int(ref[k]) for k in (
            "expected_admitted", "expected_executed", "expected_prediction", "expected_label")], f"seq={seq} frozen output")
        require(payload[21] <= payload[20], f"seq={seq} cap violation")
        observations = {
            "input_id": input_id, "mode": payload[6], "reference_label": int(ref["expected_label"]),
            "response_seq": response_seq, "response_input_id": input_id, "response_mode": payload[6],
            "response_label": payload[23], "admitted_exit": payload[20], "executed_exit": payload[21],
            "prediction": payload[22], "cycles": cycles, "reported_cycles": cycles,
            "expected_prediction": int(ref["expected_prediction"]), "expected_admitted": int(ref["expected_admitted"]),
            "expected_executed": int(ref["expected_executed"]),
        }
        for key, value in observations.items():
            require(r[key] == value and int(row[key]) == value, f"seq={seq} CSV/JSON/wire mismatch: {key}")
        require(row["experiment_id"] == args.experiment_id and row["sof_sha256"] == args.sof_sha256 and
                row["build_id"] == build and row["response_lsb_hex"] == wire, f"seq={seq} CSV identity")
        request_wire = bytes.fromhex(ref["jtag_request_100b_hex"])[::-1].hex()
        require(request_lines[index] == f"REQUEST seq={seq} input_id={input_id} mode={payload[6]} request_lsb_hex={request_wire}",
                f"seq={seq} raw request mismatch")
        require(bool(re.fullmatch(rf"RESPONSE seq={seq} status=0x[0-9a-f]{{2}} response_lsb_hex={re.escape(wire)}", response_lines[index])),
                f"seq={seq} raw response mismatch")
    return {"status": "PASS_ARTIFACT_CONSISTENCY", "scope": expected_scope, "count": len(selected),
            "selected_sequences": selected, "experiment_id": args.experiment_id, "sof_sha256": args.sof_sha256,
            "build_id": build, "hardware_provenance_verified_by_this_checker": False,
            "note": "Physical provenance requires the actual programming/JTAG run record; mock fixtures can also pass this consistency check.",
            "input_sha256": {p.name: digest(p) for p in (args.cases, result_path, csv_path, raw_path)}}


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--cases", type=Path, required=True)
    ap.add_argument("--expected-cases-sha256", required=True)
    ap.add_argument("--results", type=Path, required=True)
    ap.add_argument("--sof-sha256", required=True)
    ap.add_argument("--experiment-id", required=True)
    ap.add_argument("--sequences", default="ALL")
    ap.add_argument("--out", type=Path, required=True)
    args = ap.parse_args()
    if args.out.exists():
        ap.error("refusing to overwrite audit receipt")
    try:
        require(bool(re.fullmatch(r"[0-9a-f]{64}", args.sof_sha256)), "invalid SOF SHA-256")
        result = audit(args)
    except (ValueError, KeyError, OSError, TypeError, OverflowError) as exc:
        result = {"status": "FAIL_ARTIFACT_CONSISTENCY", "error": str(exc),
                  "hardware_provenance_verified_by_this_checker": False}
    args.out.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(result))
    return 0 if result["status"] == "PASS_ARTIFACT_CONSISTENCY" else 1


if __name__ == "__main__":
    raise SystemExit(main())
