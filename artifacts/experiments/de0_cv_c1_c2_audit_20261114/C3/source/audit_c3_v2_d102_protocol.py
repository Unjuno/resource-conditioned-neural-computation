#!/usr/bin/env python3
"""Cross-check saved C3 v2 D102 structures against RTL, TB, and route reports.

This is a static offline audit of retained build evidence. It is not formal CDC
verification, a Quartus run, or a timing signoff.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import re
from collections import Counter
from pathlib import Path

from audit_c3_v2_gate_b_saved_reports import report_paths


EXPECTED_BUILD = "43334531"
EXPECTED_SOF = "85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d"
EXPECTED_FLAT_SHA = "7c0675a6b2862c6db68f8ec1c0ceb517161389e0a3a64c7cf3bd10f33c4e9bb1"


def sha256(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def require(ok: bool, message: str) -> None:
    if not ok:
        raise ValueError(message)


def parse_d102(path: Path) -> list[dict[str, object]]:
    lines = path.read_text(encoding="utf-8-sig", errors="replace").splitlines()
    structures: list[dict[str, object]] = []
    current: dict[str, object] | None = None
    for line in lines:
        fields = [field.strip() for field in line.split(";")]
        cell = fields[1] if len(fields) > 1 else ""
        if cell.startswith("Rule D102:") and "Structure" in cell:
            match = re.search(r"Structure\s+(\d+)", cell)
            require(match is not None, f"unparseable D102 structure row: {line}")
            current = {"structure": int(match.group(1))}
            structures.append(current)
        elif current is not None and len(fields) > 2:
            if fields[1].startswith("Source node(s)"):
                current["source"] = fields[2]
            elif fields[1].startswith("Synchronizer node(s)"):
                current["synchronizer"] = fields[2]
    require(len(structures) == 16, f"expected 16 D102 structures, got {len(structures)}")
    require([s["structure"] for s in structures] == list(range(1, 17)), "D102 structure numbering is incomplete or duplicated")
    require(all("source" in s and "synchronizer" in s for s in structures), "D102 entry lacks source or synchronizer")
    return structures


def audit_selector_recheck(root: Path) -> dict[str, object]:
    exit_path = root / "quartus_sta_retry01.exitcode"
    log_path = root / "quartus_sta_retry01.log"
    source_path = root / "d102_response_source_collection_names.txt"
    destination_path = root / "d102_response_destination_collection_names.txt"
    copy_check = (root / "copy_hash_compare.txt").read_text(encoding="ascii").strip()
    require(exit_path.read_text(encoding="ascii").strip() == "0", "selector recheck Quartus exit was not zero")
    log = log_path.read_text(encoding="utf-8-sig", errors="replace")
    require("Version 25.1std.0 Build 1129" in log and "Quartus Prime Timing Analyzer was successful." in log,
            "selector recheck Quartus version/success record missing")
    require("0 errors, 1 warning" in log, "selector recheck Quartus terminal summary changed")
    require(copy_check.startswith("PASS_COPY_IDENTICAL files=318 "), "working project copy was not hash-identical")
    require((root / "d102_selector_recheck_corner_count.txt").read_text(encoding="ascii").strip() == "corner_count=4",
            "selector recheck did not complete four corners")

    name_re = re.compile(r"^rtnn_de0_cv_soc_c2:u_soc\|response_words_q\[(\d+)\]\[(\d+)\](~DUPLICATE)?$")
    source_lines = source_path.read_text(encoding="utf-8-sig", errors="replace").splitlines()
    require(source_lines and source_lines[0] == "response_source_count=484", "response source collection count changed")
    source_names = source_lines[1:]
    source_coords: list[tuple[int, int]] = []
    duplicate_coords: list[tuple[int, int]] = []
    for name in source_names:
        match = name_re.fullmatch(name)
        require(match is not None, f"unexpected response source register name: {name}")
        coordinate = (int(match.group(1)), int(match.group(2)))
        require(0 <= coordinate[0] < 15 and 0 <= coordinate[1] < 32, f"response source index out of range: {name}")
        source_coords.append(coordinate)
        if match.group(3):
            duplicate_coords.append(coordinate)
    logical_coords = {(word, bit) for word in range(15) for bit in range(32)}
    counts = Counter(source_coords)
    expected_duplicate_coords = {(1, 15), (2, 13), (2, 22), (2, 23)}
    require(len(source_names) == 484 and set(source_coords) == logical_coords and len(counts) == 480,
            "484 source names do not collapse to the complete 480 logical response bits")
    require(set(duplicate_coords) == expected_duplicate_coords and len(duplicate_coords) == 4,
            f"unexpected Quartus duplicate-register identities: {duplicate_coords}")
    require(all(counts[coordinate] == (2 if coordinate in expected_duplicate_coords else 1)
                for coordinate in logical_coords), "duplicate source is not paired with exactly one logical response bit")

    destination_lines = destination_path.read_text(encoding="utf-8-sig", errors="replace").splitlines()
    require(destination_lines and destination_lines[0] == "response_destination_count=480", "response destination collection count changed")
    destination_names = destination_lines[1:]
    destination_re = re.compile(r"^rtnn_c2_vjtag_mailbox:u_mailbox\|rsp_bus_sync1_tck_q\[(\d+)\]$")
    destinations = []
    for name in destination_names:
        match = destination_re.fullmatch(name)
        require(match is not None, f"unexpected response destination register name: {name}")
        destinations.append(int(match.group(1)))
    require(len(destinations) == 480 and set(destinations) == set(range(480)), "destination names are not all unique response bits")

    corner_results = []
    for corner in range(4):
        path = root / f"d102_response_paths_{corner}.rpt"
        pairs = []
        duplicate_sources = []
        for line in path.read_text(encoding="utf-8-sig", errors="replace").splitlines():
            fields = [field.strip() for field in line.split(";")]
            if len(fields) < 4:
                continue
            try:
                delay = float(fields[1])
            except ValueError:
                continue
            source, destination = fields[2], fields[3]
            sm = name_re.fullmatch(source)
            dm = destination_re.fullmatch(destination)
            require(sm is not None and dm is not None, f"unrecognized route endpoint: {source} -> {destination}")
            word, bit = int(sm.group(1)), int(sm.group(2))
            destination_bit = int(dm.group(1))
            require(word * 32 + bit == destination_bit, f"route bit mismatch: {source} -> {destination}")
            pairs.append(((word, bit), destination_bit, delay))
            if sm.group(3):
                duplicate_sources.append((word, bit))
        require(len(pairs) == 480 and {p[0] for p in pairs} == logical_coords and
                {p[1] for p in pairs} == set(range(480)), f"corner {corner} response routes do not cover all 480 unique bits")
        require(len({p[0] for p in pairs}) == 480 and len({p[1] for p in pairs}) == 480,
                f"corner {corner} response route report contains duplicate logical endpoints")
        require(set(duplicate_sources) == {(2, 22), (2, 23)},
                f"corner {corner} chose unexpected duplicate instances: {duplicate_sources}")
        corner_results.append({
            "corner": corner,
            "logical_response_bits_routed": len(pairs),
            "duplicate_register_sources_used_by_route_report": [list(x) for x in sorted(duplicate_sources)],
            "min_route_delay_ns": min(p[2] for p in pairs),
            "max_route_delay_ns": max(p[2] for p in pairs),
            "report_sha256": sha256(path),
        })
    return {
        "quartus_version": "25.1std.0 Build 1129",
        "timing_analyzer_exit_code": 0,
        "copied_project_file_count": 318,
        "copied_project_bytes": 75367201,
        "response_source_collection_entries": 484,
        "response_unique_logical_coordinates": 480,
        "quartus_duplicate_instances": [
            {"logical_word_bit": list(coordinate), "instance_name": f"response_words_q[{coordinate[0]}][{coordinate[1]}]~DUPLICATE"}
            for coordinate in sorted(expected_duplicate_coords)
        ],
        "response_destination_registers": 480,
        "four_corner_path_reports": corner_results,
        "disposition": "RECONCILED: 484 fitted register instances = 480 logical payload bits + 4 Quartus duplicate instances; each corner routes every logical bit to its matching synchronizer bit exactly once.",
        "sta_scope": "STA-only recheck on a SHA-verified copy of the previously fitted project; no synthesis, Fitter, Assembler, new SOF, or board operation.",
    }


def audit(c3: Path, selector_recheck: Path | None = None) -> dict[str, object]:
    evidence = c3 / "evidence"
    build = evidence / "C3_MEASUREMENT_V2_QUARTUS_RETRY02_20261115"
    sta = evidence / "C3_MEASUREMENT_V2_STA_RETRY03_20261115"
    flat = build / "rtnn_c3_measurement_v2_quartus_flat.v"
    drc = build / "rtnn_c3_measurement_v2.drc.rpt"
    qsf = build / "rtnn_c3_measurement_v2.qsf"
    tb = evidence / "C3_MEASUREMENT_V2_QUARTUS_FLAT_REGRESSION_RETRY01_20261115" / "tb_rtnn_c2_soc_42.sv"
    sof = build / "rtnn_c3_measurement_v2.sof"
    for path in (flat, drc, qsf, tb, sof):
        require(path.is_file(), f"required saved evidence missing: {path}")
    require(sha256(flat) == EXPECTED_FLAT_SHA, "flat RTL SHA does not match audited build")
    manifest = (build / "artifact_sha256.txt").read_text(encoding="utf-8-sig", errors="replace")
    require(EXPECTED_SOF in manifest and sha256(sof) == EXPECTED_SOF, "SOF identity mismatch")

    structures = parse_d102(drc)
    req = [s for s in structures if "req_hold_tck_q" in str(s["source"])]
    rsp = [s for s in structures if "response_words_q[" in str(s["source"])]
    require(len(req) == 1, f"expected one request D102 bus, got {len(req)}")
    require(len(rsp) == 15, f"expected fifteen response-word D102 buses, got {len(rsp)}")
    require(req[0]["synchronizer"].endswith("req_bus_sync1_sys_q"), "request D102 does not terminate at expected first stage")
    require(all(s["synchronizer"].endswith("rsp_bus_sync1_tck_q") for s in rsp), "response D102 does not terminate at expected first stage")
    words = sorted(int(re.search(r"response_words_q\[(\d+)\]", str(s["source"])).group(1)) for s in rsp)
    require(words == list(range(15)), f"response D102 words incomplete or duplicated: {words}")

    rtl = flat.read_text(encoding="utf-8", errors="replace")
    checks = {
        "request_payload_800": "reg [799:0] req_hold_tck_q;" in rtl and "req_bus_sync1_sys_q <= req_hold_tck_q;" in rtl,
        "response_payload_480": "reg [31:0] response_words_q [0:14];" in rtl and "rsp_bus_sync1_tck_q <= response_data_i;" in rtl,
        "request_hold_until_ack": "req_ack_sync1_tck_q <= req_ack_toggle_sys_q;" in rtl and "req_ack_sync2_tck_q <= req_ack_sync1_tck_q;" in rtl and "if (req_ack_sync2_tck_q == req_toggle_tck_q)" in rtl,
        "request_capture_pending": "if (req_capture_pending_sys_q)" in rtl and "request_data_o <= req_bus_sync2_sys_q;" in rtl and "req_capture_pending_sys_q <= 1'b1;" in rtl,
        "response_toggle_after_soc_commit": "if (response_commit_i && busy_sys_q)" in rtl and "rsp_toggle_sys_q <= ~rsp_toggle_sys_q;" in rtl,
        "response_capture_pending": "if (rsp_capture_pending_tck_q)" in rtl and "rsp_hold_tck_q <= rsp_bus_sync2_tck_q;" in rtl and "rsp_capture_pending_tck_q <= 1'b1;" in rtl,
        "new_request_waits_for_previous_response": "!response_pending_tck_q" in rtl and "rsp_consume_sync2_sys_q == rsp_toggle_sys_q" in rtl,
    }
    require(all(checks.values()), f"RTL protocol signature missing: {[k for k, v in checks.items() if not v]}")

    tb_text = tb.read_text(encoding="utf-8", errors="replace")
    assertions = {
        "request_stable_until_ack": "CDC request bundle changed before CLOCK_50 acknowledgement" in tb_text,
        "request_capture_matches_source": "CDC request bundle mismatch at CLOCK_50 capture" in tb_text,
        "response_stable_before_capture": "CDC response bundle changed before TCK capture" in tb_text,
        "response_capture_matches_source": "CDC response bundle mismatch at TCK capture" in tb_text,
        "response_stable_until_consume": "CDC response bundle changed before JTAG response consumption" in tb_text,
    }
    require(all(assertions.values()), f"finite RTL regression lacks CDC assertion(s): {[k for k, v in assertions.items() if not v]}")

    drc_text = drc.read_text(encoding="utf-8-sig", errors="replace")
    qsf_text = qsf.read_text(encoding="utf-8-sig", errors="replace")
    require("D101" not in qsf_text and "D102" not in qsf_text, "QSF unexpectedly suppresses D101/D102")
    drc_counts = {}
    for line in drc_text.splitlines():
        fields = [field.strip() for field in line.split(";")]
        if len(fields) >= 3 and fields[1] in ("Total Medium Violations", "- Rule D102"):
            try:
                drc_counts[fields[1]] = int(fields[2])
            except ValueError:
                pass
    require(drc_counts == {"Total Medium Violations": 16, "- Rule D102": 16},
            f"D102 warning count changed: {drc_counts}")

    route_coverage = {}
    for bus, count, prefix in (("request", 800, "req"), ("response", 480, "rsp")):
        per_corner = []
        for corner in range(4):
            paths = report_paths(sta / f"c3_v2_retry03_path_{prefix}_{corner}.rpt", bus)
            require(len(paths) == count, f"{bus} corner {corner} route coverage {len(paths)}/{count}")
            per_corner.append({"corner": corner, "unique_bit_paths": len(paths), "report_sha256": sha256(sta / f"c3_v2_retry03_path_{prefix}_{corner}.rpt")})
        route_coverage[bus] = per_corner

    selector_count_text = (sta / "c3_v2_retry03_path_coverage.txt").read_text(encoding="ascii")
    mismatch = "request_source=800 request_sync1_destination=800 response_source=484 response_sync1_destination=480" in selector_count_text
    require(mismatch, "saved response selector-count discrepancy changed; review before interpreting")
    recheck = audit_selector_recheck(selector_recheck) if selector_recheck else None
    return {
        "schema": "rtnn-c3-v2-d102-protocol-audit-v1",
        "status": ("D102_SELECTOR_COUNT_RECONCILED_NOT_FORMAL_CDC_PROOF_B_SIGNOFF_BLOCKED" if recheck else
                   "STATIC_STRUCTURE_MATCHED_D102_UNWAIVED_FINITE_RTL_CHECKS_PRESENT_NOT_FORMAL_CDC_PROOF"),
        "data_class": ("SAVED_RTL_DRC_PLUS_QUARTUS_STA_ONLY_RECHECK_ON_HASH_VERIFIED_COPY_NO_HARDWARE" if recheck else
                       "SAVED_RTL_DRC_AND_ROUTE_REPORT_AUDIT_NOT_NEW_QUARTUS_OR_HARDWARE_RUN"),
        "build_id": EXPECTED_BUILD,
        "sof_sha256": sha256(sof),
        "flat_rtl_sha256": sha256(flat),
        "drc_sha256": sha256(drc),
        "testbench_sha256": sha256(tb),
        "d102_count": len(structures),
        "d102_mapping": structures,
        "four_corner_route_coverage": route_coverage,
        "rtl_protocol_signatures": checks,
        "finite_rtl_testbench_assertions": assertions,
        "d102_suppressed": False,
        "selector_count_reconciliation": (recheck if recheck else {
            "request_source": 800, "request_first_stage": 800, "response_source": 484, "response_first_stage": 480,
            "disposition": "UNRESOLVED_WITHOUT_SELECTOR_RECHECK; do not infer full 484-to-480 equivalence"}),
        "limitations": [
            "A finite 42-case RTL regression and textual protocol signatures do not prove all CDC traces or analog metastability behavior.",
            "D102 remains enabled and unwaived; external JTAG TDI/TMS/TDO timing is unconstrained, so B-SIGNOFF remains BLOCKED.",
            "This checker reads saved RTL and reports only; it does not invoke Quartus, JTAG, or the DE0-CV."
        ],
    }


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--c3-root", required=True, type=Path)
    parser.add_argument("--selector-recheck-root", type=Path,
                        help="optional evidence from a Quartus STA-only rerun on a hash-verified project copy")
    parser.add_argument("--output-json", required=True, type=Path)
    args = parser.parse_args()
    result = audit(args.c3_root.resolve(), args.selector_recheck_root.resolve() if args.selector_recheck_root else None)
    args.output_json.parent.mkdir(parents=True, exist_ok=True)
    args.output_json.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8", newline="\n")
    print(f"PASS_D102_AUDIT structures=16 request=800 response=480 routes=4corners selector_recheck={'reconciled' if args.selector_recheck_root else 'not_provided'}")
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (OSError, ValueError, KeyError, TypeError, AttributeError) as exc:
        raise SystemExit(f"FAIL_STATIC_D102_AUDIT: {exc}")
