#!/usr/bin/env python3
"""Create the full-campaign interlock only from a real, audited KEY-reset replay.

This tool is intentionally not run as part of board-free preparation.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import sys
from pathlib import Path

BUILD = "43334531"
SOF = "85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d"
SEQUENCES = [49, 50, 141, 142, 209, 210, 277, 278, 325, 326, 379, 380, 431, 432, 487, 488, 559, 560, 719, 720]


def sha(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for block in iter(lambda: f.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def need(value: bool, message: str) -> None:
    if not value:
        raise ValueError(message)


def prepare_gate(result: dict, audit: dict, result_path: Path, audit_path: Path,
                 operator_confirmed_key0: bool) -> dict:
    need(operator_confirmed_key0, "operator must attest the physical KEY[0] press-and-release")
    need(result.get("schema") == "rtnn-c3-jtag-results-v2" and result.get("status") == "PASS",
         "reset result JSON is not a passing C3 v2 run")
    exp = result.get("experiment_id", "")
    need(exp.startswith("C3V2_TENINPUT_KEY_RESET_REPLAY_"), "result is not a new KEY-reset replay experiment")
    need(result.get("build_id") == BUILD and result.get("binding_id") == BUILD and result.get("sof_sha256") == SOF,
         "reset result build/SOF identity mismatch")
    need(result.get("count") == 20 and result.get("completed_count") == 20 and result.get("expected_count") == 20,
         "reset result is not 20/20 complete")
    need(result.get("selected_sequences") == SEQUENCES, "reset result sequence list differs from frozen pilot subset")
    need(len(result.get("cases", [])) == 20 and all(c.get("status") == "PASS" for c in result["cases"]),
         "reset result contains failed/incomplete case")
    need(audit.get("schema") == "rtnn-c3-v2-jtag-post-audit-v1" and audit.get("status") == "PASS",
         "independent PowerShell post-audit is not PASS")
    need(audit.get("experiment_id") == exp and audit.get("build_id") == BUILD and audit.get("sof_sha256") == SOF,
         "independent audit identity mismatch")
    need(audit.get("response_count") == 20 and audit.get("results_json_sha256") == sha(result_path),
         "independent audit row count/result SHA mismatch")
    need(audit.get("results_csv_sha256") == sha(result_path.with_name("c2_jtag_results.csv")),
         "independent audit CSV SHA mismatch")
    need(audit.get("raw_log_sha256") == sha(result_path.with_name("c2_jtag_raw.log")),
         "independent audit raw log SHA mismatch")
    bad = audit.get("bad", {})
    need(bool(bad) and all(v is False or (type(v) is int and v == 0) for v in bad.values()),
         "independent audit reports one or more failures")
    need(result_path.parent.resolve() == audit_path.parent.resolve(), "reset result and audit must share a directory")
    return {
        "schema": "rtnn-c3-key-reset-replay-gate-v1", "status": "PASS", "audit_status": "PASS",
        "reset_action": "KEY0_PRESS_RELEASE", "user_attested": True,
        "sof_sha256": SOF, "build_id": BUILD, "response_count": 20,
        "experiment_id": exp, "selected_sequences": SEQUENCES,
        "result_json_path": result_path.name, "audit_report_path": audit_path.name,
        "result_json_sha256": sha(result_path), "audit_report_sha256": sha(audit_path),
        "evidence_scope": "operator_attested_KEY0_action_plus_independent_data_audit; not electrical reset telemetry"
    }


def main() -> int:
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8", errors="backslashreplace")
    p = argparse.ArgumentParser()
    p.add_argument("--result-json", type=Path, required=True)
    p.add_argument("--audit-json", type=Path, required=True)
    p.add_argument("--output", type=Path, required=True)
    p.add_argument("--operator-confirmed-key0-press-release", action="store_true",
                   help="set only after a human directly performed KEY[0] press and release after the loaded build was checked")
    a = p.parse_args()
    need(not a.output.exists(), "refusing to overwrite existing gate evidence")
    result = json.loads(a.result_json.read_text(encoding="utf-8-sig"))
    audit = json.loads(a.audit_json.read_text(encoding="utf-8-sig"))
    gate = prepare_gate(result, audit, a.result_json, a.audit_json, a.operator_confirmed_key0_press_release)
    a.output.parent.mkdir(parents=True, exist_ok=True)
    a.output.write_text(json.dumps(gate, indent=2) + "\n", encoding="utf-8", newline="\n")
    print(f"PASS: created reset gate from {gate['experiment_id']}; gate SHA-256={sha(a.output)}")
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (OSError, ValueError, KeyError, TypeError, json.JSONDecodeError) as e:
        print(f"FAIL: {e}", file=sys.stderr)
        raise SystemExit(1)


