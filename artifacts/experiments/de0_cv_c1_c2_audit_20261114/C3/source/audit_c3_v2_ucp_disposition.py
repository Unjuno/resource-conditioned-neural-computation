#!/usr/bin/env python3
"""Recheck C3 v2 unconstrained-port roles without running Quartus or hardware."""
from __future__ import annotations

import argparse
import hashlib
import json
import re
import subprocess
from pathlib import Path


EXPECTED = {
    "rtnn_de0_cv_c2_top.sv": "c6d602e252f8e4f472cd79237f241becc9bdecb535d4ceba88d8bfbcecfe3265",
    "rtnn_c3_measurement_v2.qsf": "0d1f4e375c12526acab789112882defe903c2044009ea051ad4a2537eddbdebe",
    "rtnn_c3_measurement_v2.sdc": "ceaaa6708f0ed8f6d2c1443b60d9511c51d21f96ddaf914117ee6a65410c82eb",
    "c3_v2_retry03_unconstrained_paths.rpt": "d6b1ef57a80ae1bc6ec35d696775bde44e63445c05da0a325ea126fb303f6028",
}


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def need(condition: bool, message: str) -> None:
    if not condition:
        raise ValueError(message)


def git(repo: Path, *args: str) -> str:
    return subprocess.check_output(["git", "-C", str(repo), *args], text=True).strip()


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--c3-root", type=Path, required=True)
    parser.add_argument("--output-json", type=Path, required=True)
    args = parser.parse_args()
    c3 = args.c3_root.resolve()
    repo = c3.parents[3]
    out = args.output_json.resolve()
    need(not out.exists(), f"refusing to overwrite {out}")

    top = c3 / "source/measurement_protocol_v2_43334531_20261115/rtnn_de0_cv_c2_top.sv"
    qsf = c3 / "evidence/C3_MEASUREMENT_V2_QUARTUS_RETRY02_20261115/rtnn_c3_measurement_v2.qsf"
    sdc = qsf.with_name("rtnn_c3_measurement_v2.sdc")
    ucp = c3 / "evidence/C3_MEASUREMENT_V2_STA_RETRY03_20261115/c3_v2_retry03_unconstrained_paths.rpt"
    manual = c3 / "evidence/TERASIC_USER_MANUAL_TIMING_REVIEW_20261114_JA.md"
    old_gate = c3 / "evidence/B_EMPIRICAL_ELIGIBILITY_20261114/B_EMPIRICAL_ELIGIBILITY_20261114_JA.md"
    latest = c3 / "C3_CURRENT_STATUS_20261115_JA.md"
    current_audit = c3 / "evidence/C3_GATE_B_EVIDENCE_AUDIT_20261115_CURRENT_HEAD/gate_b_audit.json"

    paths = {p.name: p for p in (top, qsf, sdc, ucp)}
    hashes = {name: sha(path) for name, path in paths.items()}
    for name, value in EXPECTED.items():
        need(hashes[name] == value, f"identity mismatch: {name}")

    top_text, qsf_text, sdc_text, ucp_text = (p.read_text(encoding="utf-8", errors="replace") for p in (top, qsf, sdc, ucp))
    need("assign LEDR = {bus_fault, halted, response_commit, heartbeat_q[25]};" in top_text,
         "LEDR semantic mapping changed")
    for signal, pin in (("LEDR[0]", "PIN_AA2"), ("LEDR[1]", "PIN_AA1"), ("LEDR[3]", "PIN_Y3")):
        need(f"set_location_assignment {pin} -to {signal}" in qsf_text, f"QSF LED pin mismatch: {signal}")
    for port in ("altera_reserved_tdi", "altera_reserved_tms", "altera_reserved_tdo",
                 "LEDR[0]", "LEDR[1]", "LEDR[3]"):
        need(port in ucp_text, f"unconstrained port missing: {port}")
    need(re.search(r"Unconstrained Input Ports\s*;\s*2\s*;\s*2", ucp_text) is not None,
         "unconstrained input count changed")
    need(re.search(r"Unconstrained Input Port Paths\s*;\s*41\s*;\s*41", ucp_text) is not None,
         "unconstrained input path count changed")
    need(re.search(r"Unconstrained Output Ports\s*;\s*4\s*;\s*4", ucp_text) is not None,
         "unconstrained output count changed")
    need(re.search(r"Unconstrained Output Port Paths\s*;\s*8\s*;\s*8", ucp_text) is not None,
         "unconstrained output path count changed")
    need(not re.search(r"(?im)^\s*set_input_delay\b", sdc_text), "unexpected input delay was added")
    need(not re.search(r"(?im)^\s*set_output_delay\b", sdc_text), "unexpected output delay was added")
    need("set_false_path -from [get_ports {KEY[0]}]" in sdc_text, "reset exception identity changed")
    need("set_net_delay" in sdc_text and sdc_text.count("-max 16.000") == 2,
         "bundled-data screen changed")

    manual_text = manual.read_text(encoding="utf-8", errors="replace")
    old_gate_text = old_gate.read_text(encoding="utf-8", errors="replace")
    latest_text = latest.read_text(encoding="utf-8", errors="replace")
    need("That gate remains blocked" in manual_text and "B-EMPIRICAL | **BLOCKED**" in old_gate_text,
         "historical eligibility snapshot changed")
    need("B-EMPIRICAL | **PASS_LIMITED" in latest_text and "64-bit start/end" in latest_text,
         "current C3 v2 status evidence missing")
    audit = json.loads(current_audit.read_text(encoding="utf-8"))
    need(audit["classification"]["B_SIGNOFF"] == "BLOCKED_EXTERNAL_JTAG_TIMING_AND_UNCONSTRAINED_IO",
         "current Gate B signoff classification changed")
    need(audit["classification"]["B_EMPIRICAL"].startswith("PASS_LIMITED"),
         "current empirical gate classification changed")

    result = {
        "schema": "rtnn-c3-v2-ucp-disposition-audit-v1",
        "status": "LED_INDICATOR_PORTS_CLASSIFIED; EXTERNAL_JTAG_TIMING_STILL_BLOCKED",
        "data_class": "STATIC_SOURCE_AND_SAVED_REPORT_RECHECK_NOT_QUARTUS_RUN",
        "repository": git(repo, "remote", "get-url", "origin"),
        "branch": git(repo, "branch", "--show-current"),
        "head": git(repo, "rev-parse", "HEAD"),
        "build_id": "43334531",
        "unconstrained": {
            "inputs": {"ports": 2, "paths_each_setup_hold": 41,
                       "names": ["altera_reserved_tdi", "altera_reserved_tms"],
                       "disposition": "FUNCTIONAL_EXTERNAL_JTAG_INPUTS; BOARD/CABLE MIN/MAX TIMING REQUIRED"},
            "outputs": {"ports": 4, "paths_each_setup_hold": 8,
                        "names": ["altera_reserved_tdo", "LEDR[0]", "LEDR[1]", "LEDR[3]"]},
            "tdo": "FUNCTIONAL_EXTERNAL_JTAG_OUTPUT; CAPTURE EDGE/SETUP/HOLD REQUIRED",
            "leds": {
                "LEDR[0]": {"pin": "PIN_AA2", "function": "heartbeat_q[25]", "timing": "ONBOARD_INDICATOR_NO_EXTERNAL_SYNCHRONOUS_RECEIVER"},
                "LEDR[1]": {"pin": "PIN_AA1", "function": "response_commit", "timing": "ONBOARD_INDICATOR_NO_EXTERNAL_SYNCHRONOUS_RECEIVER"},
                "LEDR[3]": {"pin": "PIN_Y3", "function": "bus_fault", "timing": "ONBOARD_INDICATOR_NO_EXTERNAL_SYNCHRONOUS_RECEIVER"},
                "warning_policy": "UCP entries and Fitter drive/slew warnings retained; no false path added",
            },
        },
        "sdc": {"input_delay_tdi_tms": False, "output_delay_tdo": False,
                "reset_false_paths_only": True, "internal_net_delay_screens": 2,
                "screen_limit_ns": 16.0,
                "tck_note": "altera_reserved_tck 33.333 ns is Quartus embedded model, not board/cable measurement or guarantee"},
        "gate_classification": audit["classification"],
        "status_chronology": {
            "old_snapshot": "C2-era B-EMPIRICAL BLOCKED; 32-bit cycle response/source reproducibility issues",
            "current_scope": "C3 v2 build 43334531 SRAM-only pilot eligibility PASS_LIMITED",
            "still_unresolved": "native 146-source rebuild dependency identity and external JTAG timing signoff",
        },
        "input_sha256": hashes,
        "quartus_or_hardware_run": False,
        "formal_cdc_proof": False,
    }
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print("PASS: LED/JTAG UCP roles and status chronology matched preserved RTL/QSF/SDC/STA identities")
    print("B-SIGNOFF=BLOCKED; B-EMPIRICAL=PASS_LIMITED; no Quartus or hardware access")
    print(f"output={out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
