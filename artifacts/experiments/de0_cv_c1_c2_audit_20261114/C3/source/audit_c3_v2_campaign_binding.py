#!/usr/bin/env python3
"""Audit immutable C3 v2 SOF-bound copies of all frozen campaign schedules."""
from __future__ import annotations
import argparse, csv, hashlib, json
from pathlib import Path

CAMPAIGN = "d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc"
SOF = "85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d"
BUILD = "43334531"
MODEL = "52544e4e"
EXPECTED = {
    "diagnostic_fixed": (2520, {"1": 2520}),
    "diagnostic_adaptive": (7560, {"3": 7560}),
    "diagnostic_capped": (7560, {"2": 7560}),
    **{f"primary_{i:02d}": (720, {"1": 360, "3": 360}) for i in range(1, 11)},
}

def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()

def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--bound-root", type=Path, required=True)
    ap.add_argument("--dryrun-root", type=Path, required=True)
    args = ap.parse_args()
    root = args.bound_root
    manifest = json.loads((root / "binding_manifest.json").read_text(encoding="utf-8"))
    dryrun_report_path = args.dryrun_root / "host_dryrun_report.json"
    dryrun_report = json.loads(dryrun_report_path.read_text(encoding="utf-8"))
    report_hash_line = (args.dryrun_root / "host_dryrun_report.sha256").read_text(encoding="utf-8").split()
    assert report_hash_line == [sha(dryrun_report_path), "host_dryrun_report.json"]
    assert dryrun_report["status"] == "PASS_HOST_DRYRUN_NOT_PHYSICAL"
    assert dryrun_report["schedule_count"] == 13 and dryrun_report["total_rows"] == 24840
    assert dryrun_report["campaign_canonical_sha256"] == CAMPAIGN
    assert dryrun_report["sof_sha256"] is None
    dryrun_sessions = {item["session"]: item for item in dryrun_report["sessions"]}
    assert manifest["status"] == "PASS_HOST_BINDING_PREP_NOT_PHYSICAL"
    assert manifest["campaign_canonical_sha256"] == CAMPAIGN
    assert manifest["sof_sha256"] == SOF and manifest["build_id"] == BUILD and manifest["model_id"] == MODEL
    assert manifest["schedule_count"] == 13 and manifest["total_rows"] == 24840
    assert manifest["all_unique_accuracy_inputs"] == 360
    assert manifest["campaign_gate"] == "NOT_STARTED_WAITING_TEN_INPUT_KEY_RESET_REPLAY_PASS"
    assert manifest["timing_classification"] == "EMPIRICAL_ONLY" and not manifest["wcet_or_hard_deadline_claimed"]
    assert len(manifest["sessions"]) == 13
    total = 0
    for session in manifest["sessions"]:
        name = session["session_id"]
        assert name in EXPECTED
        want_rows, want_modes = EXPECTED[name]
        case_path = root / name / "cases.csv"
        binding_path = root / name / "binding.json"
        source_case = args.dryrun_root / name / "cases.csv"
        source_binding_path = args.dryrun_root / name / "binding.json"
        binding = json.loads(binding_path.read_text(encoding="utf-8"))
        source_binding = json.loads(source_binding_path.read_text(encoding="utf-8"))
        rows = list(csv.DictReader(case_path.open(newline="", encoding="utf-8-sig")))
        modes: dict[str, int] = {}
        ids: set[int] = set()
        for row in rows:
            modes[row["mode"]] = modes.get(row["mode"], 0) + 1
            ids.add(int(row["input_id"]))
            assert row["build_id"].lower() == BUILD and row["binding_id"].lower() == BUILD
            assert row["model_id"].lower() == MODEL
        assert len(rows) == want_rows and modes == want_modes and len(ids) == 360
        assert case_path.read_bytes() == source_case.read_bytes(), f"frozen case bytes changed: {name}"
        original_summary = dryrun_sessions[name]
        assert original_summary["status"] == "PASS_CASES_BOUND_TO_FROZEN_SCHEDULE"
        assert original_summary["cases_sha256"] == sha(source_case)
        assert original_summary["binding_sha256"] == sha(source_binding_path)
        assert original_summary["sof_sha256"] is None and original_summary["measurement_eligible"] is False
        assert sha(case_path) == session["case_csv_sha256"] == binding["case_csv_sha256"]
        assert sha(binding_path) == session["binding_sha256"]
        assert binding["schedule_canonical_sha256"] == session["schedule_sha256"]
        assert binding["campaign_canonical_sha256"] == CAMPAIGN
        allowed_overrides = {
            "sof_sha256": SOF,
            "sof_binding_status": "C3_V2_QUARTUS_SOF_SHA_BOUND_NOT_PROGRAMMED_OR_CAMPAIGN_NOT_STARTED",
            "measurement_eligible": True,
            "eligibility_basis": "B_EMPIRICAL_PASS_LIMITED_C3_V2_SINGLE_BOARD_PILOT_ONLY",
            "campaign_start_gate": "WAIT_FOR_TEN_INPUT_KEY_RESET_REPLAY_PASS",
            "physical_run_status": "NOT_RUN",
            "physical_cycles_present": False,
            "timing_classification": "EMPIRICAL_ONLY",
            "wcet_or_hard_deadline_claimed": False,
        }
        expected_binding = dict(source_binding)
        expected_binding.update(allowed_overrides)
        assert binding == expected_binding, f"binding contains an unapproved change: {name}"
        assert binding["sof_sha256"] == SOF and binding["measurement_eligible"] is True
        assert binding["physical_run_status"] == "NOT_RUN" and binding["physical_cycles_present"] is False
        assert binding["campaign_start_gate"] == "WAIT_FOR_TEN_INPUT_KEY_RESET_REPLAY_PASS"
        total += len(rows)
    assert total == 24840
    print(json.dumps({"status": "PASS_HOST_BINDING_AUDIT_NOT_PHYSICAL", "schedules": 13,
                      "rows": total, "unique_accuracy_inputs": 360, "campaign_sha256": CAMPAIGN,
                      "sof_sha256": SOF, "physical_runs": 0}, indent=2))
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
