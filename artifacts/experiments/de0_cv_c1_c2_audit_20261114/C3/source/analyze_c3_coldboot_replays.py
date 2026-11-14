#!/usr/bin/env python3
"""Audit three cold-boot primary_01 replays and run the frozen crossed bootstrap."""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
import random
import statistics
from collections import defaultdict
from pathlib import Path

SOF_SHA = "5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6"
CAMPAIGN_SHA = "d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc"
RUN_IDS = [f"C3_PRIMARY01_COLD_BOOT_REPLAY0{i}_20261114" for i in range(1, 4)]


def sha(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for block in iter(lambda: f.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def rows(path: Path) -> list[dict[str, str]]:
    with path.open(newline="", encoding="utf-8-sig") as f:
        return list(csv.DictReader(f))


def percentile(v: list[float], q: float) -> float:
    k = (len(v) - 1) * q
    i = int(k); j = min(i + 1, len(v) - 1)
    return v[i] * (j - k) + v[j] * (k - i)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--c3-root", type=Path, required=True)
    ap.add_argument("--out-dir", type=Path, required=True)
    args = ap.parse_args()
    c3, out = args.c3_root.resolve(), args.out_dir.resolve()
    if out.exists():
        raise SystemExit(f"refusing to overwrite: {out}")

    base_cases = c3 / "campaign" / "prepared" / "primary_01" / "cases.csv"
    base_binding = json.loads((base_cases.parent / "binding.json").read_text(encoding="utf-8-sig"))
    if len(rows(base_cases)) != 720 or base_binding["schedule_canonical_sha256"] != "73d37a9bf03a263a01663f5bf2d74695b93493c0660309ac39ad9dba97b414c9":
        raise SystemExit("primary_01 frozen schedule mismatch")
    expected = {int(x["seq"]): x for x in rows(base_cases)}
    boot_data: dict[str, dict[int, dict[int, dict]]] = {}
    manifests = []
    combined = []
    power_ids = set()
    for run_id in RUN_IDS:
        d = c3 / "campaign" / "results" / run_id
        manifest = json.loads((d / "run_manifest.json").read_text(encoding="utf-8-sig"))
        audit = json.loads((d / "result_audit.json").read_text(encoding="utf-8-sig"))
        if manifest.get("status") != "PASS_EMPIRICAL_SESSION" or audit.get("status") != "PASS_EMPIRICAL_SESSION_AUDIT":
            raise SystemExit(f"{run_id}: run/audit not PASS")
        if manifest.get("cold_boot_confirmed") is not True:
            raise SystemExit(f"{run_id}: cold boot not confirmed")
        boot = manifest.get("board_power_session_id")
        if not boot or boot in power_ids:
            raise SystemExit(f"{run_id}: missing/duplicate board power session")
        power_ids.add(boot)
        if manifest.get("sof_sha256") != SOF_SHA or manifest.get("campaign_canonical_sha256") != CAMPAIGN_SHA or manifest.get("schedule_sha256") != base_binding["schedule_canonical_sha256"]:
            raise SystemExit(f"{run_id}: build/campaign/schedule identity mismatch")
        if manifest.get("uart_used") or manifest.get("flash_written") or manifest.get("sof_programming_performed"):
            # The C3 runner never programs SOF; separate recorded SRAM load occurs before each run.
            raise SystemExit(f"{run_id}: unexpected UART/Flash/SOF operation in experiment session")
        result_path = d / "merged" / "c2_jtag_results.csv"
        actual = rows(result_path)
        if len(actual) != 720 or audit.get("rows") != 720:
            raise SystemExit(f"{run_id}: row count mismatch")
        by_input: dict[int, dict[int, dict]] = defaultdict(dict)
        seen_seq: set[int] = set()
        for r in actual:
            seq = int(r["seq"]); case = expected.get(seq)
            if seq in seen_seq:
                raise SystemExit(f"{run_id} seq {seq}: duplicate result row")
            seen_seq.add(seq)
            if case is None or int(r["input_id"]) != int(case["input_id"]) or int(r["mode"]) != int(case["mode"]):
                raise SystemExit(f"{run_id} seq {seq}: frozen sequence/input/mode mismatch")
            if r["experiment_id"] != run_id or r["sof_sha256"] != SOF_SHA:
                raise SystemExit(f"{run_id} seq {seq}: result/build identity mismatch")
            if r["case_status"] != "PASS" or r["cycle_valid"] != "1" or r["response_crc_valid"] != "1":
                raise SystemExit(f"{run_id} seq {seq}: cycle/status/CRC failure")
            if (int(r["prediction"]) != int(case["expected_prediction"])
                    or int(r["reference_label"]) != int(case["expected_label"])
                    or int(r["executed_exit"]) != int(case["expected_executed"])):
                raise SystemExit(f"{run_id} seq {seq}: frozen Q15/exit mismatch")
            r2 = dict(r)
            for key in ("seq", "input_id", "mode", "prediction", "reference_label", "executed_exit", "cycles"):
                r2[key] = int(r[key])
            by_input[int(r["input_id"])][int(r["mode"])] = r2
            combined.append({"board_power_session_id": boot, **{k: r2[k] for k in ("experiment_id", "seq", "input_id", "mode", "prediction", "reference_label", "executed_exit", "cycles", "sof_sha256", "build_id", "case_status")}})
        if len(by_input) != 360 or any(set(m) != {1, 3} for m in by_input.values()):
            raise SystemExit(f"{run_id}: fixed/adaptive pairs incomplete")
        if seen_seq != set(expected):
            raise SystemExit(f"{run_id}: missing frozen sequence rows")
        boot_data[boot] = by_input
        manifests.append({"experiment_id": run_id, "board_power_session_id": boot,
                          "cold_boot_confirmed": True,
                          "run_manifest_sha256": sha(d / "run_manifest.json"),
                          "result_audit_sha256": sha(d / "result_audit.json"),
                          "results_sha256": sha(result_path), "rows": 720})

    boots = sorted(boot_data)
    if len(boots) < 3:
        raise SystemExit("frozen plan requires at least three independent cold boots")
    input_ids = sorted(next(iter(boot_data.values())).keys())
    diff = {iid: [boot_data[b][iid][1]["cycles"] - boot_data[b][iid][3]["cycles"] for b in boots] for iid in input_ids}
    fixed = {iid: [boot_data[b][iid][1]["cycles"] for b in boots] for iid in input_ids}
    adaptive = {iid: [boot_data[b][iid][3]["cycles"] for b in boots] for iid in input_ids}
    dmean = statistics.mean(x for iid in input_ids for x in diff[iid])
    fmean = statistics.mean(x for iid in input_ids for x in fixed[iid])
    amean = statistics.mean(x for iid in input_ids for x in adaptive[iid])

    # Crossed nonparametric bootstrap: inputs resampled with seed 63; independent
    # boot sessions resampled with the frozen seed offset 104729.
    rng_i = random.Random(63)
    rng_b = random.Random(104729)
    diffs, fractions = [], []
    for _ in range(5000):
        picked_i = [input_ids[rng_i.randrange(len(input_ids))] for _ in input_ids]
        picked_b = [boots[rng_b.randrange(len(boots))] for _ in boots]
        ds, fs, ads = [], [], []
        for iid in picked_i:
            for b in picked_b:
                ds.append(boot_data[b][iid][1]["cycles"] - boot_data[b][iid][3]["cycles"])
                fs.append(boot_data[b][iid][1]["cycles"])
                ads.append(boot_data[b][iid][3]["cycles"])
        fm, am = statistics.mean(fs), statistics.mean(ads)
        diffs.append(statistics.mean(ds))
        fractions.append(100.0 * (fm - am) / fm)
    diffs.sort(); fractions.sort()

    # Accuracy uses the 360 independent IDs once, never the repeated measurements as n.
    accuracy_diff = []
    fixed_correct = adaptive_correct = 0
    prediction_consistent = True
    for iid in input_ids:
        fixed_pairs = {(boot_data[b][iid][1]["prediction"], boot_data[b][iid][1]["reference_label"]) for b in boots}
        adaptive_pairs = {(boot_data[b][iid][3]["prediction"], boot_data[b][iid][3]["reference_label"]) for b in boots}
        if len(fixed_pairs) != 1 or len(adaptive_pairs) != 1:
            prediction_consistent = False
        fp, lab = next(iter(fixed_pairs)); apred, alab = next(iter(adaptive_pairs))
        if lab != alab:
            raise SystemExit(f"input {iid}: label mismatch across modes")
        fixed_correct += fp == lab; adaptive_correct += apred == lab
        accuracy_diff.append(float((apred == lab) - (fp == lab)))
    rng_acc = random.Random(63)
    acc_means = sorted(sum(accuracy_diff[rng_acc.randrange(360)] for _ in range(360)) / 360 for _ in range(5000))
    accuracy_ci = [100.0 * percentile(acc_means, 0.025), 100.0 * percentile(acc_means, 0.975)]
    saving_ci = [percentile(diffs, 0.025), percentile(diffs, 0.975)]
    fraction_ci = [percentile(fractions, 0.025), percentile(fractions, 0.975)]
    out.mkdir(parents=True)
    with (out / "coldboot_replays_2160.csv").open("w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=list(combined[0]), lineterminator="\n")
        w.writeheader(); w.writerows(combined)
    summary = {
        "schema": "rtnn-c3-coldboot-replay-analysis-v1",
        "status": "PASS_CROSSED_EMPIRICAL_BOOTSTRAP",
        "classification": "SUPPLEMENTAL_COLD_BOOT_SENSITIVITY; original 24,840-row campaign unchanged",
        "frozen_session": "primary_01",
        "frozen_schedule_sha256": base_binding["schedule_canonical_sha256"],
        "confirmed_cold_boots": len(boots),
        "boot_sessions": manifests,
        "rows": len(combined),
        "input_ids": len(input_ids),
        "paired_fixed2_adaptive": len(input_ids) * len(boots),
        "primary_cycles": {"fixed2_mean": fmean, "adaptive_mean": amean,
                           "mean_saving_cycles": dmean,
                           "crossed_bootstrap_95pct_ci_cycles": saving_ci,
                           "mean_saving_percent_fixed2": 100.0 * (fmean - amean) / fmean,
                           "crossed_bootstrap_95pct_ci_percent": fraction_ci,
                           "bootstrap_replicates": 5000, "input_seed": 63,
                           "boot_seed": 104729,
                           "unit": "input_id crossed with independent board cold_boot_session_id",
                           "minimum_boot_requirement_met": len(boots) >= 3,
                           "practical_5pct_point_threshold_met": 100.0 * (fmean - amean) / fmean >= 5.0,
                           "practical_5pct_ci_lower_bound_met": fraction_ci[0] > 5.0},
        "accuracy_noninferiority": {"independent_input_ids": 360,
                                    "fixed2_correct": fixed_correct,
                                    "adaptive_correct": adaptive_correct,
                                    "adaptive_minus_fixed2_pp": 100.0 * statistics.mean(accuracy_diff),
                                    "paired_input_bootstrap_95pct_ci_pp": accuracy_ci,
                                    "noninferiority_margin_pp": 1.0,
                                    "decision": "INCONCLUSIVE" if accuracy_ci[0] <= -1.0 else "PASS_NONINFERIORITY",
                                    "predictions_consistent_across_boots": prediction_consistent},
        "speedup_claim_allowed": bool(len(boots) >= 3 and fraction_ci[0] > 5.0
                                       and prediction_consistent),
        "formal_timing_gate": "BLOCKED_EXTERNAL_JTAG_IO_AND_UNCONSTRAINED_PATHS",
        "wcet_or_hard_deadline_claimed": False,
    }
    (out / "analysis.json").write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    checks = [f"{sha(x)}  {x.name}" for x in sorted(out.iterdir()) if x.is_file() and x.name != "SHA256SUMS.txt"]
    (out / "SHA256SUMS.txt").write_text("\n".join(checks) + "\n", encoding="ascii")
    print(json.dumps({"status": summary["status"], "rows": len(combined),
                      "boots": len(boots), "mean_saving_cycles": dmean,
                      "speedup_claim_allowed": summary["speedup_claim_allowed"],
                      "accuracy_decision": summary["accuracy_noninferiority"]["decision"],
                      "output": str(out)}, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
