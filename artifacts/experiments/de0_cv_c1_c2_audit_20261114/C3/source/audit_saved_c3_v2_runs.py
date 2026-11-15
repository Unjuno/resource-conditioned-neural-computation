#!/usr/bin/env python3
"""Strict offline audit of preserved C3 v2 physical-result bundles.

This tool never talks to JTAG. The CLI accepts only saved evidence located
under the C3 v2 physical evidence tree and reports SAVED_PHYSICAL_EVIDENCE;
unit-test fixtures call the pure validation functions and cannot be exported.
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
import os
import sys
from pathlib import Path

BUILD = "43334531"
MODEL = "52544e4e"
SOF = "85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d"
CAMPAIGN = "d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc"
U64_MAX = (1 << 64) - 1


def sha(path: Path) -> str:
    h = hashlib.sha256()
    with fs_path(path).open("rb") as f:
        for block in iter(lambda: f.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def read_json(path: Path) -> dict:
    return json.loads(fs_path(path).read_text(encoding="utf-8-sig"))


def read_csv(path: Path) -> list[dict[str, str]]:
    with fs_path(path).open("r", encoding="utf-8-sig", newline="") as f:
        return list(csv.DictReader(f))


def need(ok: bool, why: str) -> None:
    if not ok:
        raise ValueError(why)


def fs_path(path: Path) -> Path:
    """Use Win32 extended paths for preserved OneDrive evidence > MAX_PATH."""
    path = Path(path)
    value = str(path.resolve()) if not str(path).startswith("\\\\?\\") else str(path)
    if os.name == "nt" and len(value) >= 248 and not value.startswith("\\\\?\\"):
        return Path("\\\\?\\" + value)
    return Path(value)


def uint64(v: object, field: str) -> int:
    # Reject bool (a Python int subclass), floats, signs, and out-of-range values.
    need(type(v) is int, f"{field}: expected integer")
    need(0 <= v <= U64_MAX, f"{field}: outside uint64 range")
    return v


def audit_identity(results: dict, binding: dict, case_sha: str, binding_sha: str,
                   expected_experiment: str | None = None) -> dict:
    need(results.get("schema") == "rtnn-c3-jtag-results-v2", "result schema mismatch")
    need(results.get("status") == "PASS", "saved result status is not PASS")
    need(results.get("timing_classification") == "EMPIRICAL_ONLY", "timing class mismatch")
    need(results.get("wcet_or_hard_deadline_claimed") is False, "unsupported timing claim bit")
    need(results.get("uart") is False and results.get("flash_written") is False, "UART/Flash invariant mismatch")
    need(results.get("build_id") == BUILD and results.get("binding_id") == BUILD, "result is not C3 v2 build")
    need(binding.get("build_id") == BUILD and binding.get("binding_id") == BUILD, "binding is not C3 v2 build")
    need(results.get("sof_sha256") == SOF and binding.get("sof_sha256") == SOF, "SOF identity mismatch")
    need(binding.get("model_id") == MODEL and results.get("campaign_canonical_sha256") == CAMPAIGN and
         binding.get("campaign_canonical_sha256") == CAMPAIGN, "model/campaign identity mismatch")
    need(binding.get("case_csv_sha256") == case_sha, "case CSV is not the bound case file")
    need(results.get("binding_sha256") == binding_sha, "result binding SHA mismatch")
    need(results.get("experiment_id"), "missing result experiment ID")
    if expected_experiment is not None:
        need(results["experiment_id"] == expected_experiment, "experiment ID mismatch")
    need(binding.get("timing_classification") == "EMPIRICAL_ONLY" and
         binding.get("wcet_or_hard_deadline_claimed") is False, "binding timing claim mismatch")
    return {"experiment_id": results["experiment_id"], "build_id": BUILD,
            "sof_sha256": SOF, "model_id": MODEL,
            "schedule_id": results.get("schedule_id"),
            "schedule_canonical_sha256": results.get("schedule_canonical_sha256"),
            "binding_sha256": binding_sha, "case_csv_sha256": case_sha}


def audit_rows(results: dict, csv_rows: list[dict[str, str]], case_rows: list[dict[str, str]],
               binding: dict, expected_identity: dict) -> dict:
    n = int(binding["record_count"])
    sequences = [int(x) for x in binding["selected_schedule_sequences"]]
    need(len(sequences) == n and len(set(sequences)) == n, "binding sequence count/duplicate")
    need(results.get("count") == n and results.get("completed_count") == n and
         results.get("expected_count") == n, "JSON row counts mismatch binding")
    need(results.get("selected_sequences") == sequences, "JSON selected sequence list differs from binding")
    need(len(results.get("cases", [])) == n and len(csv_rows) == n and len(case_rows) == n,
         "JSON/CSV/case row count mismatch")
    for name, rows in (("JSON", results["cases"]), ("CSV", csv_rows), ("case", case_rows)):
        seqs = [int(r["seq"]) for r in rows]
        need(seqs == sequences, f"{name} has missing, duplicate, extra, or reordered sequences")

    checked = []
    for index, (j, c, case) in enumerate(zip(results["cases"], csv_rows, case_rows)):
        seq = sequences[index]
        # Case files and the two result formats are cross-checked field by field.
        for field in ("seq", "input_id", "mode", "prediction", "reference_label", "admitted_exit",
                      "executed_exit", "cycles", "expected_prediction", "expected_admitted", "expected_executed",
                      "response_seq", "response_input_id", "response_mode", "response_label",
                      "response_model_id", "response_build_id", "response_binding_id", "reported_cycles"):
            if field in j and field in c:
                need(str(j[field]).lower() == str(c[field]).lower(), f"seq {seq}: JSON/CSV field mismatch {field}")
        for field in ("seq", "input_id", "mode", "expected_prediction", "expected_admitted", "expected_executed"):
            need(int(c[field]) == int(case[field]), f"seq {seq}: result differs from frozen case {field}")
        need(c["experiment_id"] == expected_identity["experiment_id"], f"seq {seq}: CSV experiment ID mismatch")
        for field, expected in (("sof_sha256", SOF), ("build_id", BUILD), ("binding_id", BUILD),
                                ("response_model_id", MODEL), ("response_build_id", BUILD),
                                ("response_binding_id", BUILD)):
            if field in j:
                need(str(j[field]).lower() == expected.lower(), f"seq {seq}: {field} identity mismatch")
            if field in c:
                need(str(c[field]).lower() == expected.lower(), f"seq {seq}: CSV {field} identity mismatch")
        for field in ("seq", "input_id", "mode", "prediction", "reference_label", "admitted_exit",
                      "executed_exit", "response_seq", "response_input_id", "response_mode", "response_label",
                      "expected_prediction", "expected_admitted", "expected_executed"):
            need(int(j[field]) == int(c[field]), f"seq {seq}: JSON/CSV numeric mismatch {field}")
        need(j["seq"] == seq and j["response_seq"] == seq, f"seq {seq}: response sequence mismatch")
        need(j["input_id"] == j["response_input_id"] and j["mode"] == j["response_mode"],
             f"seq {seq}: response request identity mismatch")
        need(j["prediction"] == j["expected_prediction"], f"seq {seq}: frozen Q15 prediction mismatch")
        need(j["response_label"] == j["reference_label"], f"seq {seq}: label field mismatch")
        need(j["admitted_exit"] == j["expected_admitted"] and j["executed_exit"] == j["expected_executed"],
             f"seq {seq}: executed/admitted Exit differs from bound expectation")
        need(j["executed_exit"] <= j["admitted_exit"], f"seq {seq}: cap violation")
        need(j["status"] == "PASS" and j["error"] in (None, ""), f"seq {seq}: status/error failure")
        need(j["cycle_valid"] is True and c["cycle_valid"] == "1" and c["counter_status"] == "0",
             f"seq {seq}: invalid cycle status")
        need(j["response_crc_valid"] is True and c["response_crc_valid"] == "1", f"seq {seq}: CRC failure")
        start = uint64(j["cycles_start"], f"seq {seq} cycles_start")
        end = uint64(j["cycles_end"], f"seq {seq} cycles_end")
        delta = uint64(j["cycles"], f"seq {seq} cycles")
        need(end > start and delta > 0, f"seq {seq}: nonmonotonic or zero cycle interval")
        need(end - start == delta and delta == j["reported_cycles"] == int(c["cycles"]) == int(c["reported_cycles"]),
             f"seq {seq}: 64-bit cycle delta mismatch")
        need(int(c["cycles_start"]) == start and int(c["cycles_end"]) == end,
             f"seq {seq}: JSON/CSV start/end mismatch")
        need(c["case_status"] == "PASS" and c["error"] == "", f"seq {seq}: CSV status/error failure")
        need(c["response_lsb_hex"] == j["response_lsb_hex"], f"seq {seq}: raw response bytes differ JSON/CSV")
        checked.append({"seq": seq, "input_id": j["input_id"], "mode": j["mode"],
                        "prediction": j["prediction"], "executed_exit": j["executed_exit"],
                        "cycles_start": start, "cycles_end": end, "cycles": delta})
    return {"responses": checked, "response_count": n,
            "unique_input_ids": sorted({r["input_id"] for r in checked}),
            "cycle_min": min(r["cycles"] for r in checked),
            "cycle_max": max(r["cycles"] for r in checked)}


def audit_raw_log(raw_path: Path, result: dict, binding: dict) -> str:
    raw = fs_path(raw_path).read_text(encoding="utf-8-sig")
    lines = raw.splitlines()
    need(len(lines) >= 3, "raw JTAG log is incomplete")
    header, selected, hardware = lines[:3]
    for token in (f"experiment_id={result['experiment_id']}", f"sof_sha256={SOF}",
                  f"build_id={BUILD}", f"binding_id={BUILD}",
                  f"binding_sha256={result['binding_sha256']}", f"campaign_canonical_sha256={CAMPAIGN}",
                  "interface=USB-Blaster/Virtual-JTAG", "uart=none", "flash=untouched"):
        need(token in header, f"raw log identity/equipment marker missing: {token}")
    seqs = [int(x) for x in binding["selected_schedule_sequences"]]
    need(f"selected_sequences={','.join(map(str, seqs))}" in selected and f"expected_count={len(seqs)}" in selected,
         "raw log selected sequence list differs from binding")
    need("hardware=USB-Blaster" in hardware and "device=@1:" in hardware and "5CE" in hardware and "0x02B050DD" in hardware,
         "raw log does not identify expected JTAG device")
    expected = ",".join(map(str, seqs))
    def key_values(line: str) -> dict[str, str]:
        out = {}
        for token in line.split()[1:]:
            if "=" in token:
                k, v = token.split("=", 1)
                out[k] = v
        return out
    for kind in ("REQUEST", "RESPONSE", "PASS"):
        selected_lines = [line for line in lines if line.startswith(kind + " ")]
        got = [key_values(line).get("seq", "") for line in selected_lines]
        need(got == list(map(str, seqs)), f"raw log {kind} rows missing/duplicate/reordered")
        for line, json_case in zip(selected_lines, result["cases"]):
            values = key_values(line)
            if kind in {"REQUEST", "PASS"}:
                need(values.get("input_id") == str(json_case["input_id"]) and
                     values.get("mode") == str(json_case["mode"]),
                     f"raw log {kind} seq {json_case['seq']} input/mode differs from result")
            if kind in {"RESPONSE", "PASS"}:
                need(values.get("response_lsb_hex") == json_case["response_lsb_hex"],
                     f"raw log {kind} seq {json_case['seq']} response bytes differ from result")
    ready_lines = [line for line in lines if line.startswith("READY_AFTER_RESPONSE ")]
    need([key_values(line).get("seq", "") for line in ready_lines] == list(map(str, seqs)),
         "raw log READY_AFTER_RESPONSE rows missing/duplicate/reordered")
    return sha(raw_path)


def require_single_build(audits: list[dict]) -> None:
    ids = {(x["build_id"], x["sof_sha256"], x["model_id"], x["schedule_canonical_sha256"])
           for x in audits}
    need(len(ids) <= 1, "refusing to combine runs with different build/SOF/model/schedule identities")


def _canonical_evidence_path(path: Path) -> Path:
    resolved = str(path.resolve())
    if resolved.startswith("\\\\?\\UNC\\"):
        resolved = "\\\\" + resolved[8:]
    elif resolved.startswith("\\\\?\\"):
        resolved = resolved[4:]
    return Path(resolved)


def is_allowed_evidence_path(path: Path, evidence_root: Path) -> bool:
    candidate = _canonical_evidence_path(path)
    root = _canonical_evidence_path(evidence_root)
    try:
        candidate.relative_to(root)
        return True
    except ValueError:
        return False


def audit_files(result_json: Path, result_csv: Path, cases_csv: Path, binding_path: Path, raw_log: Path,
                expected_experiment: str | None = None) -> dict:
    results, binding = read_json(result_json), read_json(binding_path)
    case_sha, binding_sha = sha(cases_csv), sha(binding_path)
    identity = audit_identity(results, binding, case_sha, binding_sha, expected_experiment)
    checked = audit_rows(results, read_csv(result_csv), read_csv(cases_csv), binding, identity)
    raw_sha = audit_raw_log(raw_log, results, binding)
    return {"schema": "rtnn-c3-v2-saved-run-independent-audit-v1",
            "status": "PASS_SAVED_PHYSICAL_EVIDENCE_AUDIT",
            "data_class": "SAVED_PHYSICAL_EVIDENCE_NOT_NEW_MEASUREMENT",
            **identity, **checked,
            "sha256": {"results_json": sha(result_json), "results_csv": sha(result_csv),
                       "cases_csv": case_sha, "binding_json": binding_sha, "raw_log": raw_sha}}


def main() -> int:
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8", errors="backslashreplace")
    p = argparse.ArgumentParser()
    p.add_argument("--result-json", type=Path, required=True)
    p.add_argument("--result-csv", type=Path, required=True)
    p.add_argument("--cases-csv", type=Path, required=True)
    p.add_argument("--binding-json", type=Path, required=True)
    p.add_argument("--raw-log", type=Path, required=True)
    p.add_argument("--expected-experiment")
    p.add_argument("--output-json", type=Path)
    a = p.parse_args()
    root = Path(__file__).resolve().parents[1] / "evidence/PHYSICAL_C3_V2_20261115"
    paths = [a.result_json.resolve(), a.result_csv.resolve(), a.cases_csv.resolve(), a.binding_json.resolve(), a.raw_log.resolve()]
    need(all(is_allowed_evidence_path(x, root) for x in paths), "CLI refuses paths outside saved C3 v2 physical evidence tree")
    report = audit_files(*paths, a.expected_experiment)
    if a.output_json:
        fs_path(a.output_json).write_text(json.dumps(report, indent=2, ensure_ascii=False) + "\n", encoding="utf-8", newline="\n")
    print(json.dumps(report, indent=2, ensure_ascii=False))
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (OSError, ValueError, KeyError, TypeError, json.JSONDecodeError, csv.Error) as e:
        print(f"FAIL: {e}", file=sys.stderr)
        raise SystemExit(1)


