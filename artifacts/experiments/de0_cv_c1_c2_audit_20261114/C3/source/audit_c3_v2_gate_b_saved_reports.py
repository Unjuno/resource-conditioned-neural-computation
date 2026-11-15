#!/usr/bin/env python3
"""Independently audit retained C3 v2 Quartus/STA report coverage (no tool launch)."""
from __future__ import annotations

import argparse
import hashlib
import json
import re
from pathlib import Path


QUARTUS_VERSION = "25.1std.0 Build 1129"
EXPECTED_SOF = "85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d"
EXPECTED_BUILD = "43334531"


def need(condition: bool, message: str) -> None:
    if not condition:
        raise ValueError(message)


def sha(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def manifest(path: Path) -> dict[str, str]:
    result = {}
    for line in path.read_text(encoding="utf-8-sig").splitlines():
        match = re.match(r"^([0-9a-fA-F]{64})\s+\*?(.+)$", line.strip())
        if match:
            result[Path(match.group(2)).name] = match.group(1).lower()
    return result


def report_paths(path: Path, bus: str) -> dict[int, float]:
    text = path.read_text(encoding="utf-8-sig", errors="replace")
    found: dict[int, float] = {}
    for line in text.splitlines():
        fields = [field.strip() for field in line.split(";")]
        if len(fields) < 4:
            continue
        try:
            delay = float(fields[1])
        except ValueError:
            continue
        source, dest = fields[2], fields[3]
        if bus == "request":
            src = re.search(r"req_hold_tck_q\[(\d+)\]", source)
            dst = re.search(r"req_bus_sync1_sys_q\[(\d+)\]", dest)
            if not src or not dst:
                continue
            si, di = int(src.group(1)), int(dst.group(1))
            need(si == di and 0 <= si < 800, f"request path index mismatch: {source} -> {dest}")
            index = si
        else:
            src = re.search(r"response_words_q\[(\d+)\]\[(\d+)\]", source)
            dst = re.search(r"rsp_bus_sync1_tck_q\[(\d+)\]", dest)
            if not src or not dst:
                continue
            word, bit, di = int(src.group(1)), int(src.group(2)), int(dst.group(1))
            need(0 <= word < 15 and 0 <= bit < 32 and di == word * 32 + bit,
                 f"response path bit mapping mismatch: {source} -> {dest}")
            index = di
        need(index not in found, f"duplicate {bus} route for bit {index}")
        found[index] = delay
    count = 800 if bus == "request" else 480
    need(set(found) == set(range(count)), f"{bus} route coverage {len(found)}/{count}; missing/extra bits")
    return found


def audit(c3: Path) -> dict:
    ev = c3 / "evidence"
    build = ev / "C3_MEASUREMENT_V2_QUARTUS_RETRY02_20261115"
    sta = ev / "C3_MEASUREMENT_V2_STA_RETRY03_20261115"
    qsf, sdc = build / "rtnn_c3_measurement_v2.qsf", build / "rtnn_c3_measurement_v2.sdc"
    flat, sof = build / "rtnn_c3_measurement_v2_quartus_flat.v", build / "rtnn_c3_measurement_v2.sof"
    inputs, artifacts = manifest(build / "input_sha256.txt"), manifest(build / "artifact_sha256.txt")
    for name, path, hashes in (
        ("qsf", qsf, artifacts), ("sdc", sdc, artifacts), ("flat_rtl", flat, artifacts),
        ("sof", sof, artifacts),
    ):
        expected_name = {"flat_rtl": "rtnn_c3_measurement_v2_quartus_flat.v"}.get(name, path.name)
        need(hashes.get(expected_name) == sha(path), f"artifact manifest SHA mismatch: {name}")
    need(sha(sof) == EXPECTED_SOF, "SOF SHA differs from saved C3 v2 experiment identity")
    need("43334531" in qsf.read_text(encoding="utf-8-sig"), "QSF build ID mismatch")
    need("set_instance_assignment -name DISABLE_DA_RULE" not in qsf.read_text(encoding="utf-8-sig"),
         "unexpected Design Assistant rule suppression in C3 v2 QSF")
    need("set_input_delay" not in sdc.read_text(encoding="utf-8-sig") and
         "set_output_delay" not in sdc.read_text(encoding="utf-8-sig"),
         "external I/O delay unexpectedly present; review this audit script")
    sdc_text = sdc.read_text(encoding="utf-8-sig")
    need("create_clock -name CLOCK_50 -period 20.000" in sdc_text, "missing 50 MHz system clock")
    need(len(re.findall(r"set_net_delay .* -max 16\.000", sdc_text)) == 2,
         "expected two declared empirical-only bundled-data route limits")

    sta_log = (sta / "quartus_sta.log").read_text(encoding="utf-8-sig", errors="replace")
    need(QUARTUS_VERSION in sta_log, "Quartus STA version differs")
    need("Quartus Prime Timing Analyzer was successful. 0 errors, 1 warning" in sta_log,
         "saved Timing Analyzer run did not end with recorded success")
    need((sta / "exitcode.txt").read_text(encoding="ascii").strip() == "0", "saved STA exit code is not 0")
    corners = {}
    matches = list(re.finditer(r"^CORNER (\d+) (.+)$", sta_log, flags=re.M))
    need(len(matches) == 4, f"expected four operating corners, found {len(matches)}")
    for i, match in enumerate(matches):
        end = matches[i + 1].start() if i + 1 < len(matches) else len(sta_log)
        section = sta_log[match.start():end]
        setup = re.search(r"Found 20 setup paths \((\d+) violated\)\.\s+Worst case slack is ([0-9.]+)", section)
        hold = re.search(r"Found 20 hold paths \((\d+) violated\)\.\s+Worst case slack is ([0-9.]+)", section)
        need(setup and hold, f"corner {match.group(1)} missing setup/hold summary")
        need(int(setup.group(1)) == 0 and int(hold.group(1)) == 0, f"corner {match.group(1)} has violations")
        corners[match.group(1)] = {
            "operating_condition": match.group(2), "reported_20_path_setup_slack_ns": float(setup.group(2)),
            "reported_20_path_hold_slack_ns": float(hold.group(2)),
        }

    route = {}
    for bus in ("request", "response"):
        count = 800 if bus == "request" else 480
        per_corner = []
        for corner in range(4):
            values = report_paths(sta / f"c3_v2_retry03_path_{'req' if bus == 'request' else 'rsp'}_{corner}.rpt", bus)
            need(len(values) == count, f"corner {corner} incomplete {bus} route report")
            per_corner.append({"corner": corner, "bit_paths": len(values), "min_reported_route_delay_ns": min(values.values()),
                               "max_reported_route_delay_ns": max(values.values())})
        route[bus] = per_corner
    coverage = (sta / "c3_v2_retry03_path_coverage.txt").read_text(encoding="ascii")
    need("request_source=800 request_sync1_destination=800 response_source=484 response_sync1_destination=480" in coverage,
         "saved selector-count evidence changed")

    net_delays = {}
    for corner in range(4):
        text = (sta / f"c3_v2_retry03_netdelay_{corner}.rpt").read_text(encoding="utf-8-sig", errors="replace")
        rows = []
        for line in text.splitlines():
            fields = [f.strip() for f in line.split(";")]
            if len(fields) > 6 and fields[1] == "--":
                try:
                    required, actual = float(fields[3]), float(fields[4])
                except ValueError:
                    continue
                rows.append((required, actual))
        need(len(rows) == 4, f"corner {corner} missing detailed constrained net paths")
        need(all(required == 16.0 and actual < required for required, actual in rows),
             f"corner {corner} exceeds declared 16 ns screen")
        net_delays[str(corner)] = {"declared_screen_ns": 16.0, "worst_observed_bus_route_ns": max(x[1] for x in rows)}

    ucp = (sta / "c3_v2_retry03_unconstrained_paths.rpt").read_text(encoding="utf-8-sig", errors="replace")
    expected_ucp_counts = {
        "Unconstrained Input Ports": (2, 2), "Unconstrained Input Port Paths": (41, 41),
        "Unconstrained Output Ports": (4, 4), "Unconstrained Output Port Paths": (8, 8),
        "Unconstrained Clocks": (0, 0), "Illegal Clocks": (0, 0),
    }
    for label, expected in expected_ucp_counts.items():
        line = next((x for x in ucp.splitlines() if label in x and x.strip().startswith(";")), "")
        nums = re.findall(r"\d+", line.split(label, 1)[-1]) if line else []
        need(tuple(map(int, nums[-2:])) == expected, f"unconstrained path count mismatch for {label}: {line}")
    for port in ("altera_reserved_tdi", "altera_reserved_tms", "altera_reserved_tdo", "LEDR[0]", "LEDR[1]", "LEDR[3]"):
        need(port in ucp, f"expected unconstrained endpoint absent: {port}")

    drc = (build / "rtnn_c3_measurement_v2.drc.rpt").read_text(encoding="utf-8-sig", errors="replace")
    for label, count in (("Total Critical Violations", 0), ("Total High Violations", 0),
                         ("Total Medium Violations", 16), ("- Rule D102", 16)):
        line = next((x for x in drc.splitlines() if label in x), "")
        nums = re.findall(r"\d+", line)
        need(nums and int(nums[-1]) == count, f"Design Assistant count mismatch for {label}: {line}")
    need("Rule D101: Data bits are not synchronized" in drc, "D101 rule setting not found for review")
    need("Rule D102: Multiple data bits" in drc, "D102 rule setting not found for review")
    need("D101" not in qsf.read_text(encoding="utf-8-sig") and
         "D102" not in qsf.read_text(encoding="utf-8-sig"),
         "unexpected D101/D102 suppression in QSF")
    warnings = (build / "warning_counts.txt").read_text(encoding="utf-8-sig").splitlines()
    warning_counts = {line.split("=", 1)[0]: int(line.split("=", 1)[1]) for line in warnings if "=" in line}
    return {
        "schema": "rtnn-c3-v2-gate-b-saved-report-audit-v1", "status": "INTERNAL_REPORTS_REAUDITED_EXTERNAL_IO_SIGNOFF_BLOCKED",
        "data_class": "SAVED_STATIC_TIMING_REPORT_AUDIT_NOT_NEW_QUARTUS_RUN",
        "quartus_version": QUARTUS_VERSION, "build_id": EXPECTED_BUILD,
        "sof_sha256": sha(sof), "qsf_sha256": sha(qsf), "sdc_sha256": sha(sdc), "flat_rtl_sha256": sha(flat),
        "input_manifest_sha256": sha(build / "input_sha256.txt"),
        "input_manifest_record_count": sum(1 for line in (build / "input_sha256.txt").read_text(encoding="utf-8-sig").splitlines()
                                           if re.match(r"^SHA256\s+[0-9a-fA-F]{64}\s+", line)),
        "artifact_manifest_matches": True,
        "corner_count": 4, "corners": corners, "bundled_data_route_coverage": route,
        "bundled_data_net_delay_screen": net_delays,
        "unconstrained_endpoints": {"input_ports": ["altera_reserved_tdi", "altera_reserved_tms"],
            "input_paths_each_setup_hold": 41,
            "output_ports": ["altera_reserved_tdo", "LEDR[0]", "LEDR[1]", "LEDR[3]"],
            "output_paths_each_setup_hold": 8, "unconstrained_clocks": 0},
        "design_assistant": {"critical": 0, "high": 0, "medium_d102": 16,
            "d101_d102_suppressed_in_qsf": False},
        "warning_counts_by_code": warning_counts,
        "limitations": ["The 30 MHz altera_reserved_tck clock is HDL/IP-embedded; it is not a measurement or vendor guarantee for the DE0-CV onboard USB-Blaster output.",
            "TDI/TMS input delay and TDO output delay are absent; Cyclone V pin requirements alone do not establish board/cable timing.",
            "The 16 ns bundled-data net-delay constraint is explicitly an empirical screening threshold, not an externally derived signoff value.",
            "The reports do not constitute fully constrained board-level setup/hold signoff or WCET evidence."],
    }


def main() -> int:
    p = argparse.ArgumentParser()
    p.add_argument("--c3-root", required=True, type=Path)
    p.add_argument("--output-json", type=Path, required=True)
    args = p.parse_args()
    result = audit(args.c3_root.resolve())
    args.output_json.parent.mkdir(parents=True, exist_ok=True)
    args.output_json.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8", newline="\n")
    print(f"PASS_REAUDIT_INTERNAL_STA_AND_CDC coverage=4corners request=800/800 response=480/480; UCP remains; output={args.output_json}")
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (OSError, ValueError, KeyError, TypeError) as exc:
        raise SystemExit(f"FAIL_GATE_B_SAVED_REPORT_AUDIT: {exc}")
