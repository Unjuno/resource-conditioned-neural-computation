#!/usr/bin/env python3
"""Validate and summarize the frozen C3 physical campaign without changing inputs."""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
import random
import statistics
from collections import defaultdict
from pathlib import Path

EXPECTED_ROWS = 24840
CAMPAIGN_FILE_SHA = "3d97a1cd87395e294299cacb617474367c89a9295355cd25fb1b4fa67464c936"
EXPECTED_SESSIONS = {
    "diagnostic_fixed": 2520,
    "diagnostic_adaptive": 7560,
    "diagnostic_capped": 7560,
    **{f"primary_{i:02d}": 720 for i in range(1, 11)},
}
SOF_SHA = "5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6"
CAMPAIGN_SHA = "d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc"


def sha(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for block in iter(lambda: f.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def canonical_sha(obj: object) -> str:
    raw = json.dumps(obj, sort_keys=True, separators=(",", ":"), allow_nan=False).encode()
    return hashlib.sha256(raw).hexdigest()


def percentile(sorted_values: list[float], q: float) -> float:
    if not sorted_values:
        raise ValueError("empty bootstrap distribution")
    pos = (len(sorted_values) - 1) * q
    lo = int(pos)
    hi = min(lo + 1, len(sorted_values) - 1)
    return sorted_values[lo] * (hi - pos) + sorted_values[hi] * (pos - lo)


def bootstrap_mean(values: list[float], seed: int, n: int = 5000) -> tuple[float, float, float]:
    rng = random.Random(seed)
    count = len(values)
    means = sorted(sum(values[rng.randrange(count)] for _ in range(count)) / count for _ in range(n))
    return statistics.mean(values), percentile(means, 0.025), percentile(means, 0.975)


def bootstrap_paired(fixed: list[float], adaptive: list[float], seed: int, n: int = 5000) -> dict:
    rng = random.Random(seed)
    count = len(fixed)
    diffs, fractions = [], []
    for _ in range(n):
        indices = [rng.randrange(count) for _ in range(count)]
        fmean = sum(fixed[i] for i in indices) / count
        amean = sum(adaptive[i] for i in indices) / count
        diffs.append(fmean - amean)
        fractions.append(100.0 * (fmean - amean) / fmean)
    diffs.sort(); fractions.sort()
    fmean = statistics.mean(fixed)
    amean = statistics.mean(adaptive)
    return {
        "fixed_mean": fmean,
        "adaptive_mean": amean,
        "mean_difference": fmean - amean,
        "mean_difference_ci": [percentile(diffs, 0.025), percentile(diffs, 0.975)],
        "saving_fraction_percent": 100.0 * (fmean - amean) / fmean,
        "saving_fraction_ci_percent": [percentile(fractions, 0.025), percentile(fractions, 0.975)],
    }


def read_json(path: Path) -> dict:
    return json.loads(path.read_text(encoding="utf-8-sig"))


def read_rows(path: Path) -> list[dict[str, str]]:
    with path.open(newline="", encoding="utf-8-sig") as f:
        return list(csv.DictReader(f))


def audit_session(c3: Path, session: str, nrows: int) -> tuple[list[dict], dict]:
    session_tag = {"diagnostic_fixed": "DIAGFIXED", "diagnostic_adaptive": "DIAGADAPTIVE",
                   "diagnostic_capped": "DIAGCAPPED"}.get(session, session.replace("_", "").upper())
    exp = f"C3_{session_tag}_FULL{nrows}_RUN1_20261114"
    run_dir = c3 / "campaign" / "results" / exp
    if not run_dir.is_dir():
        raise ValueError(f"missing run directory: {run_dir}")
    manifest = read_json(run_dir / "run_manifest.json")
    audit = read_json(run_dir / "result_audit.json")
    binding_path = c3 / "campaign" / "prepared" / session / "binding.json"
    binding = read_json(binding_path)
    cases_path = c3 / "campaign" / "prepared" / session / "cases.csv"
    result_path = run_dir / "merged" / "c2_jtag_results.csv"
    if not result_path.exists():
        result_path = run_dir / "c2_jtag_results.csv"

    if manifest.get("status") != "PASS_EMPIRICAL_SESSION":
        raise ValueError(f"{session}: run manifest status is not PASS")
    if audit.get("status") != "PASS_EMPIRICAL_SESSION_AUDIT":
        raise ValueError(f"{session}: result audit status is not PASS")
    if audit.get("rows") != nrows or binding.get("record_count") != nrows:
        raise ValueError(f"{session}: unexpected row count")
    if manifest.get("sof_sha256") != SOF_SHA or manifest.get("campaign_canonical_sha256") != CAMPAIGN_SHA:
        raise ValueError(f"{session}: physical SOF or campaign identity mismatch")
    if manifest.get("flash_written") or manifest.get("uart_used"):
        raise ValueError(f"{session}: UART/Flash invariant violated")
    if sha(cases_path) != manifest.get("case_csv_sha256"):
        raise ValueError(f"{session}: frozen cases SHA differs from manifest")
    if sha(cases_path) != binding.get("case_csv_sha256"):
        raise ValueError(f"{session}: frozen cases SHA differs from binding")
    if sha(binding_path) != manifest.get("binding_sha256"):
        raise ValueError(f"{session}: binding SHA differs from run manifest")
    if binding.get("schedule_canonical_sha256") != manifest.get("schedule_sha256"):
        raise ValueError(f"{session}: schedule identity differs from run manifest")
    if sha(cases_path) != audit.get("sha256", {}).get("cases.csv"):
        raise ValueError(f"{session}: frozen cases SHA differs from independent audit")

    expected = {int(r["seq"]): r for r in read_rows(cases_path)}
    actual = read_rows(result_path)
    if len(actual) != nrows or len(expected) != nrows:
        raise ValueError(f"{session}: results/cases count mismatch")
    for row in actual:
        seq = int(row["seq"])
        case = expected.get(seq)
        if case is None:
            raise ValueError(f"{session}: unexpected result seq {seq}")
        for got, key in (("input_id", "input_id"), ("mode", "mode")):
            if int(row[got]) != int(case[key]):
                raise ValueError(f"{session} seq {seq}: {got} mismatch")
        for got, key in (("expected_prediction", "expected_prediction"),
                         ("expected_admitted", "expected_admitted"),
                         ("expected_executed", "expected_executed")):
            if int(row[got]) != int(case[key]):
                raise ValueError(f"{session} seq {seq}: case binding {got} mismatch")
        if row["case_status"] != "PASS" or row["cycle_valid"] != "1" or row["response_crc_valid"] != "1":
            raise ValueError(f"{session} seq {seq}: status/cycle/CRC invalid")
        if int(row["prediction"]) != int(case["expected_prediction"]):
            raise ValueError(f"{session} seq {seq}: prediction differs from frozen Q15 reference")
        if int(row["admitted_exit"]) != int(case["expected_admitted"]):
            raise ValueError(f"{session} seq {seq}: admitted exit differs from frozen reference")
        if int(row["executed_exit"]) != int(case["expected_executed"]):
            raise ValueError(f"{session} seq {seq}: executed exit differs from frozen reference")
        if int(row["cycles"]) <= 0 or int(row["reported_cycles"]) != int(row["cycles"]):
            raise ValueError(f"{session} seq {seq}: invalid or inconsistent cycle counter")

    for rel, want in manifest.get("output_sha256", {}).items():
        path = run_dir / Path(rel.replace("/", str(Path().anchor or "/"))) if False else run_dir.joinpath(*rel.split("/"))
        if not path.is_file() or sha(path) != want:
            raise ValueError(f"{session}: manifest SHA mismatch {rel}")
    normalized = []
    for row in actual:
        normalized.append({
            "session_id": session,
            "experiment_id": row["experiment_id"],
            "seq": int(row["seq"]),
            "input_id": int(row["input_id"]),
            "mode": int(row["mode"]),
            "prediction": int(row["prediction"]),
            "reference_label": int(row["reference_label"]),
            "admitted_exit": int(row["admitted_exit"]),
            "executed_exit": int(row["executed_exit"]),
            "cycles": int(row["cycles"]),
            "sof_sha256": row["sof_sha256"],
            "build_id": row["build_id"],
            "case_status": row["case_status"],
        })
    return normalized, manifest


def main() -> int:
    p = argparse.ArgumentParser()
    p.add_argument("--c3-root", type=Path, required=True)
    p.add_argument("--out-dir", type=Path, required=True)
    args = p.parse_args()
    c3 = args.c3_root.resolve()
    out = args.out_dir.resolve()
    if out.exists():
        raise SystemExit(f"refusing to overwrite output: {out}")
    campaign = read_json(c3 / "frozen_inputs" / "paper" / "campaign" / "campaign.json")
    body = dict(campaign)
    stated = body.pop("campaign_sha256")
    campaign_path = c3 / "frozen_inputs" / "paper" / "campaign" / "campaign.json"
    if sha(campaign_path) != CAMPAIGN_FILE_SHA:
        raise SystemExit("frozen campaign file SHA mismatch")
    if canonical_sha(body) != CAMPAIGN_SHA or stated != CAMPAIGN_SHA:
        raise SystemExit("frozen campaign canonical SHA mismatch")
    if len(campaign["schedules"]) != 13 or sum(x["record_count"] for x in campaign["schedules"]) != EXPECTED_ROWS:
        raise SystemExit("campaign dimensions differ from frozen plan")
    schedule_root = campaign_path.parent
    for meta in campaign["schedules"]:
        schedule = read_json(schedule_root / meta["matrix"])
        if len(schedule["rows"]) != meta["record_count"] or canonical_sha(schedule["rows"]) != meta["schedule_sha256"]:
            raise SystemExit(f"frozen schedule identity mismatch: {meta['session_id']}")

    rows: list[dict] = []
    manifests: list[dict] = []
    session_table = []
    for meta in campaign["schedules"]:
        name = meta["session_id"]
        nrows = EXPECTED_SESSIONS.get(name)
        if nrows != meta["record_count"]:
            raise SystemExit(f"frozen session count mismatch: {name}")
        got, manifest = audit_session(c3, name, nrows)
        rows.extend(got)
        manifests.append(manifest)
        session_table.append({"session_id": name, "rows": len(got), "status": manifest["status"],
                              "board_power_session_id": manifest.get("board_power_session_id", "UNRECORDED"),
                              "cold_boot_confirmed": bool(manifest.get("cold_boot_confirmed", False)),
                              "run_manifest_sha256": sha(c3 / "campaign" / "results" / manifest["experiment_id"] / "run_manifest.json")})
    if len(rows) != EXPECTED_ROWS:
        raise SystemExit(f"only {len(rows)} of {EXPECTED_ROWS} planned rows validated")

    primary = [r for r in rows if r["session_id"].startswith("primary_")]
    paired_by_key: dict[tuple[int, str], dict[int, dict]] = defaultdict(dict)
    for r in primary:
        paired_by_key[(r["input_id"], r["session_id"])][r["mode"]] = r
    if len(paired_by_key) != 360 * 10 or any(set(v) != {1, 3} for v in paired_by_key.values()):
        raise SystemExit("primary schedule is not complete paired fixed2/adaptive data")
    fixed_by_input: dict[int, list[float]] = defaultdict(list)
    adaptive_by_input: dict[int, list[float]] = defaultdict(list)
    per_session = []
    for s in range(1, 11):
        session = f"primary_{s:02d}"
        pairs = []
        for iid in range(360):
            pair = paired_by_key[(iid, session)]
            fixed, adaptive = pair[1], pair[3]
            if fixed["executed_exit"] != 2:
                raise SystemExit(f"{session} input {iid}: comparator is not fixed Exit 2")
            pairs.append((fixed, adaptive))
            fixed_by_input[iid].append(fixed["cycles"])
            adaptive_by_input[iid].append(adaptive["cycles"])
        d = [f["cycles"] - a["cycles"] for f, a in pairs]
        fixed_cycles = [f["cycles"] for f, _ in pairs]
        adaptive_cycles = [a["cycles"] for _, a in pairs]
        per_session.append({"session_id": session, "input_pairs": 360,
                            "fixed2_mean_cycles": statistics.mean(fixed_cycles),
                            "adaptive_mean_cycles": statistics.mean(adaptive_cycles),
                            "mean_saving_cycles": statistics.mean(d),
                            "median_saving_cycles": statistics.median(d),
                            "adaptive_faster_inputs": sum(x > 0 for x in d),
                            "adaptive_slower_inputs": sum(x < 0 for x in d)})

    fixed_mean_by_input = [statistics.mean(fixed_by_input[i]) for i in range(360)]
    adaptive_mean_by_input = [statistics.mean(adaptive_by_input[i]) for i in range(360)]
    paired_boot = bootstrap_paired(fixed_mean_by_input, adaptive_mean_by_input, 63)

    accuracy_by_input: dict[int, dict[int, set[tuple[int, int]]]] = defaultdict(lambda: defaultdict(set))
    for r in primary:
        if (r["mode"] == 1 and r["executed_exit"] == 2) or r["mode"] == 3:
            accuracy_by_input[r["input_id"]][r["mode"]].add((r["prediction"], r["reference_label"]))
    if len(accuracy_by_input) != 360:
        raise SystemExit("primary accuracy inputs incomplete")
    acc_differences = []
    consistent = True
    for iid in sorted(accuracy_by_input):
        modes = accuracy_by_input[iid]
        fixed_pairs, adaptive_pairs = modes[1], modes[3]
        if len(fixed_pairs) != 1 or len(adaptive_pairs) != 1:
            consistent = False
        fp, label = next(iter(fixed_pairs))
        ap, label2 = next(iter(adaptive_pairs))
        if label != label2:
            raise SystemExit(f"input {iid}: inconsistent frozen label")
        acc_differences.append(float(int(ap == label) - int(fp == label)))
    accuracy_ci = bootstrap_mean(acc_differences, 63)
    fixed_correct = sum(1 for i in accuracy_by_input if next(iter(accuracy_by_input[i][1]))[0] == next(iter(accuracy_by_input[i][1]))[1])
    adaptive_correct = sum(1 for i in accuracy_by_input if next(iter(accuracy_by_input[i][3]))[0] == next(iter(accuracy_by_input[i][3]))[1])
    cold_boot_ids = {x["board_power_session_id"] for x in session_table if x["cold_boot_confirmed"]}
    boot_complete = len(cold_boot_ids) >= int(campaign["bootstrap"]["two_way"]["minimum_boot_sessions"])

    out.mkdir(parents=True)
    with (out / "all_24840_results.csv").open("w", newline="", encoding="utf-8") as f:
        fields = list(rows[0].keys())
        w = csv.DictWriter(f, fieldnames=fields, lineterminator="\n")
        w.writeheader(); w.writerows(rows)
    summary = {
        "schema": "rtnn-c3-campaign-analysis-v1",
        "status": "PASS_DATA_INTEGRITY_EMPIRICAL_ONLY",
        "campaign_canonical_sha256": CAMPAIGN_SHA,
        "campaign_file_sha256": CAMPAIGN_FILE_SHA,
        "planned_rows": EXPECTED_ROWS,
        "validated_rows": len(rows),
        "schedule_count": 13,
        "input_count": 360,
        "sessions": session_table,
        "primary_paired_sessions": per_session,
        "primary_paired_total": {
            "pairs": 3600,
            "mean_fixed2_cycles": paired_boot["fixed_mean"],
            "mean_adaptive_cycles": paired_boot["adaptive_mean"],
            "mean_fixed2_minus_adaptive_cycles": paired_boot["mean_difference"],
            "input_bootstrap_95pct_ci_cycles": paired_boot["mean_difference_ci"],
            "mean_reduction_percent_fixed2_denominator": paired_boot["saving_fraction_percent"],
            "input_bootstrap_95pct_ci_reduction_percent": paired_boot["saving_fraction_ci_percent"],
            "practical_5pct_point_threshold_met": paired_boot["saving_fraction_percent"] >= float(campaign["practical_mean_cycle_saving_fraction"]) * 100.0,
            "practical_5pct_ci_lower_bound_met": paired_boot["saving_fraction_ci_percent"][0] > float(campaign["practical_mean_cycle_saving_fraction"]) * 100.0,
            "bootstrap_seed": 63,
            "bootstrap_replicates": 5000,
            "bootstrap_unit": "input_id; mean over the 10 planned schedule sessions",
            "three_cold_boot_requirement_met": boot_complete,
            "speedup_claim_allowed": False,
            "limitation": "Frozen plan requires at least 3 confirmed cold-boot sessions for a speedup claim; current logs do not confirm any independent board power cycle. This interval is conditional on the observed board power-session history.",
        },
        "accuracy_noninferiority": {
            "independent_input_ids": 360,
            "fixed2_correct": fixed_correct,
            "adaptive_correct": adaptive_correct,
            "adaptive_minus_fixed2_percentage_points": 100.0 * accuracy_ci[0],
            "paired_input_bootstrap_95pct_ci_percentage_points": [100.0 * accuracy_ci[1], 100.0 * accuracy_ci[2]],
            "margin_percentage_points": 1.0,
            "bootstrap_seed": 63,
            "bootstrap_replicates": 5000,
            "predictions_consistent_across_sessions": consistent,
            "decision": "INCONCLUSIVE" if not (100.0 * accuracy_ci[1] > -1.0) else "PASS_NONINFERIORITY",
            "limitation": "Resampling unit is the 360 frozen independent input IDs; repeated hardware measurements are not counted as new inputs.",
        },
        "formal_timing_gate": "BLOCKED_EXTERNAL_JTAG_IO_AND_UNCONSTRAINED_PATHS",
        "wcet_or_hard_deadline_claimed": False,
        "run_manifest_sha256": {x["experiment_id"]: sha(c3 / "campaign" / "results" / x["experiment_id"] / "run_manifest.json") for x in manifests},
    }
    (out / "analysis.json").write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    sums = []
    for path in sorted(out.iterdir()):
        if path.is_file() and path.name != "SHA256SUMS.txt":
            sums.append(f"{sha(path)}  {path.name}")
    (out / "SHA256SUMS.txt").write_text("\n".join(sums) + "\n", encoding="ascii")
    print(json.dumps({"status": summary["status"], "validated_rows": len(rows),
                      "primary_mean_saving_cycles": paired_boot["mean_difference"], "speedup_claim_allowed": False,
                      "accuracy_decision": summary["accuracy_noninferiority"]["decision"],
                      "output": str(out)}, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
