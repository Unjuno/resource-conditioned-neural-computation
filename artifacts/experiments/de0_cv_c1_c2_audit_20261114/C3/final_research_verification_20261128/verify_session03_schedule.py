#!/usr/bin/env python3
"""Offline-only integrity check of the prepared session-03 schedule and binding."""
from __future__ import annotations

import argparse
import hashlib
import json
import sys
from datetime import datetime, timezone
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import audit_primary  # noqa: E402


def sha(p: Path) -> str:
    return hashlib.sha256(p.read_bytes()).hexdigest()


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--package", type=Path, required=True)
    ap.add_argument("--session-dir", type=Path, required=True)
    ap.add_argument("--output", type=Path, required=True)
    args = ap.parse_args()
    if args.output.exists():
        raise SystemExit(f"refusing to overwrite existing evidence: {args.output}")
    cases_path = args.session_dir / "cases.csv"
    binding_path = args.session_dir / "binding_preflight.json"
    binding = json.loads(binding_path.read_text(encoding="utf-8-sig"))
    rows = audit_primary.rcsv(cases_path)
    sequence = int(binding["schedule_identity"]["first_sequence"])
    schedule_audit = audit_primary.audit_schedule(rows, args.package, sequence)
    if schedule_audit["sequence_last"] != 22899 or sequence != 15274:
        raise SystemExit("session-03 sequence range differs from the prepared campaign order")
    if (binding.get("split"), binding.get("classification"), binding.get("status")) != ("primary", "EMPIRICAL_ONLY", "PHYSICAL_ELIGIBLE"):
        raise SystemExit("session-03 binding identity/classification mismatch")
    if args.package.joinpath("host_v2_20261126/Invoke-ExternalValidation.ps1").is_file() is False:
        raise SystemExit("pinned physical runner missing")
    sys.path.insert(0, str(args.package))
    from safety_gates_v1_20261122.pilot_gate import verify_binding
    verify_binding(binding_path, cases_path)
    if (args.session_dir / "run").exists() or (args.session_dir / "physical_results.csv").exists() or (args.session_dir / "raw_jtag.log").exists():
        raise SystemExit("unexpected physical output exists; offline schedule check refuses to classify as pre-run")
    out = {
        "schema": "rtnn-session03-schedule-reverification-v1",
        "status": "PASS_OFFLINE_SCHEDULE_AND_BINDING_ONLY",
        "verification_time_utc": datetime.now(timezone.utc).isoformat(),
        "experiment_id": binding["experiment_id"],
        "session_id": binding["session_id"],
        "classification": "OFFLINE_ONLY_NOT_PHYSICAL_RUN",
        "schedule_audit": schedule_audit,
        "cases_sha256": sha(cases_path),
        "binding_sha256": sha(binding_path),
        "pilot_gate_sha256": binding["pilot_gate_sha256"],
        "runner_sha256": sha(args.package / "host_v2_20261126/Invoke-ExternalValidation.ps1"),
        "identity": {k: binding[k] for k in ("build_id", "binding_id", "model_id", "sof_sha256", "firmware_elf_sha256")},
        "sequence_range": [sequence, 22899],
        "must_wait_for_session_02_audit": True,
        "physical_jtag_started": False,
        "quartus_started": False,
        "sof_programming_performed": False,
        "flash_written": False,
    }
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, indent=2) + "\n", encoding="utf-8", newline="\n")
    print(json.dumps(out, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
