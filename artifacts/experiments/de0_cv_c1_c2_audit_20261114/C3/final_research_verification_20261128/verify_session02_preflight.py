#!/usr/bin/env python3
"""Read-only SHA and pilot-binding recheck for the saved session-02 preflight."""
from __future__ import annotations

import argparse
import hashlib
import json
import sys
from datetime import datetime, timezone
from pathlib import Path


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--package", type=Path, required=True)
    ap.add_argument("--session-dir", type=Path, required=True)
    ap.add_argument("--output", type=Path, required=True)
    args = ap.parse_args()
    if args.output.exists():
        raise SystemExit(f"refusing to overwrite existing evidence: {args.output}")
    rec_path = args.session_dir / "offline_preflight_RUN1.json"
    cases = args.session_dir / "cases.csv"
    binding = args.session_dir / "binding_preflight.json"
    b = json.loads(binding.read_text(encoding="utf-8-sig"))
    rec = json.loads(rec_path.read_text(encoding="utf-8-sig"))
    runner = args.package / "host_v2_20261126/Invoke-ExternalValidation.ps1"
    gate = Path(b["pilot_gate_path"])
    actual = {
        "cases_csv_sha256": sha(cases),
        "binding_sha256": sha(binding),
        "runner_sha256": sha(runner),
        "pilot_gate_sha256": sha(gate),
    }
    for key, value in actual.items():
        if rec.get(key) != value:
            raise SystemExit(f"preflight SHA mismatch: {key}")
    if b.get("cases_csv_sha256") != actual["cases_csv_sha256"]:
        raise SystemExit("binding/cases SHA mismatch")
    if b.get("pilot_gate_sha256") != actual["pilot_gate_sha256"]:
        raise SystemExit("binding/pilot gate SHA mismatch")
    if not (rec.get("status") == "PREFLIGHT_ONLY" and rec.get("physical_jtag_started") is False
            and rec.get("quartus_started") is False and rec.get("output_directory_created") is False
            and rec.get("sof_programming_performed") is False and rec.get("flash_written") is False):
        raise SystemExit("preflight record indicates a physical action or non-preflight status")
    sys.path.insert(0, str(args.package))
    from safety_gates_v1_20261122.pilot_gate import verify_binding
    verify_binding(binding, cases)
    out = {
        "schema": "rtnn-session-preflight-offline-reverification-v1",
        "status": "PASS_OFFLINE_ONLY",
        "verification_time_utc": datetime.now(timezone.utc).isoformat(),
        "experiment_id": rec["experiment_id"],
        "session_id": rec["session_id"],
        "case_count": rec["case_count"],
        "sequence_range": rec["sequence_range"],
        "identity": {k: b[k] for k in ("build_id", "binding_id", "model_id", "sof_sha256", "firmware_elf_sha256")},
        "sha256": actual,
        "pilot_binding_validation": "PASS",
        "physical_jtag_started": False,
        "quartus_started": False,
        "output_directory_created": False,
        "operator_power_transition_confirmation": rec.get("operator_power_transition_confirmation"),
        "classification": "OFFLINE_PREFLIGHT_ONLY_NOT_PHYSICAL_RUN",
    }
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, indent=2) + "\n", encoding="utf-8", newline="\n")
    print(json.dumps(out, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
