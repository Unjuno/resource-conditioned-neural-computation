#!/usr/bin/env python3
"""Post-hoc descriptive diagnostics for one independently audited primary run."""
from __future__ import annotations

import argparse
import csv
import json
import statistics
import sys
from collections import Counter, defaultdict
from pathlib import Path

HERE = Path(__file__).resolve().parent
C3 = HERE.parent
PACKAGE = C3 / "external_validation_20261122"
sys.path.insert(0, str(HERE))
from audit_primary import audit_run  # noqa: E402


def quantile(values: list[int], q: float) -> float:
    ordered = sorted(values)
    if not ordered:
        raise ValueError("empty cycle sample")
    pos = (len(ordered) - 1) * q
    lo = int(pos)
    hi = min(lo + 1, len(ordered) - 1)
    return ordered[lo] + (ordered[hi] - ordered[lo]) * (pos - lo)


def summarize_rows(rows: list[dict[str, str]], audit: dict, expected_inputs: int = 3813) -> dict:
    by: dict[tuple[str, str], dict[str, str]] = {}
    for row in rows:
        key = (row["input_id"], row["mode"])
        if key in by:
            raise ValueError(f"duplicate input/mode row: {key}")
        by[key] = row
    input_ids = sorted({input_id for input_id, _ in by}, key=int)
    for input_id in input_ids:
        if (input_id, "fixed2") not in by or (input_id, "adaptive") not in by:
            raise ValueError(f"incomplete mode pair for input {input_id}")
    if len(input_ids) != expected_inputs or len(by) != 2 * expected_inputs:
        raise ValueError(f"expected exactly {expected_inputs} paired inputs / {2 * expected_inputs} rows")

    pairs = [(by[(i, "fixed2")], by[(i, "adaptive")]) for i in input_ids]
    modes = {}
    for mode in ("fixed2", "adaptive"):
        selected = [by[(i, mode)] for i in input_ids]
        cycles = [int(row["cycles"]) for row in selected]
        correct = [int(row["prediction"]) == int(row["teacher_label"]) for row in selected]
        modes[mode] = {
            "n": len(selected),
            "teacher_correct": sum(correct),
            "teacher_accuracy": sum(correct) / len(correct),
            "cycles": {
                "mean": statistics.mean(cycles),
                "median": statistics.median(cycles),
                "p90": quantile(cycles, 0.90),
                "p95": quantile(cycles, 0.95),
                "max": max(cycles),
            },
            "admitted_exit_counts": dict(sorted(Counter(int(r["admitted_exit"]) for r in selected).items())),
            "executed_exit_counts": dict(sorted(Counter(int(r["executed_exit"]) for r in selected).items())),
        }

    correctness = Counter()
    deltas = []
    adaptive_slower = []
    deltas_by_exit: dict[int, list[int]] = defaultdict(list)
    correctness_by_exit: dict[int, Counter] = defaultdict(Counter)
    by_class: dict[str, dict] = {}
    by_adaptive_exit: dict[int, list[dict]] = defaultdict(list)
    for fixed, adaptive in pairs:
        f_ok = int(fixed["prediction"]) == int(fixed["teacher_label"])
        a_ok = int(adaptive["prediction"]) == int(adaptive["teacher_label"])
        correctness[(f_ok, a_ok)] += 1
        delta = int(adaptive["cycles"]) - int(fixed["cycles"])
        deltas.append(delta)
        exit_id = int(adaptive["executed_exit"])
        deltas_by_exit[exit_id].append(delta)
        correctness_by_exit[exit_id][(f_ok, a_ok)] += 1
        if delta > 0:
            adaptive_slower.append({"input_id": int(fixed["input_id"]), "teacher_label": int(fixed["teacher_label"]), "delta_cycles": delta, "adaptive_executed_exit": int(adaptive["executed_exit"]), "fixed2_correct": f_ok, "adaptive_correct": a_ok})
        by_adaptive_exit[int(adaptive["executed_exit"])].append(adaptive)

    for label in range(10):
        label_pairs = [(f, a) for f, a in pairs if int(f["teacher_label"]) == label]
        if not label_pairs:
            by_class[str(label)] = {"n": 0, "fixed2_correct": 0, "adaptive_correct": 0}
            continue
        f_ok = sum(int(f["prediction"]) == label for f, _ in label_pairs)
        a_ok = sum(int(a["prediction"]) == label for _, a in label_pairs)
        by_class[str(label)] = {
            "n": len(label_pairs),
            "fixed2_correct": f_ok,
            "fixed2_accuracy": f_ok / len(label_pairs),
            "adaptive_correct": a_ok,
            "adaptive_accuracy": a_ok / len(label_pairs),
        }

    adaptive_exit_summary = {}
    for exit_id, selected in sorted(by_adaptive_exit.items()):
        cycles = [int(row["cycles"]) for row in selected]
        adaptive_exit_summary[str(exit_id)] = {
            "n": len(selected),
            "teacher_correct": sum(int(r["prediction"]) == int(r["teacher_label"]) for r in selected),
            "mean_cycles": statistics.mean(cycles),
            "median_cycles": statistics.median(cycles),
        }
    exit_delta_summary = {}
    for exit_id, values in sorted(deltas_by_exit.items()):
        transitions = correctness_by_exit[exit_id]
        exit_delta_summary[str(exit_id)] = {
            "n": len(values),
            "mean_adaptive_minus_fixed2_cycles": statistics.mean(values),
            "min_adaptive_minus_fixed2_cycles": min(values),
            "max_adaptive_minus_fixed2_cycles": max(values),
            "adaptive_slower_count": sum(value > 0 for value in values),
            "paired_correctness_transitions": {
                "both_correct": transitions[(True, True)],
                "fixed2_only_correct": transitions[(True, False)],
                "adaptive_only_correct": transitions[(False, True)],
                "both_wrong": transitions[(False, False)],
            },
        }
    adaptive_slower.sort(key=lambda row: (-row["delta_cycles"], row["input_id"]))
    return {
        "schema": "rtnn-primary-session-descriptive-diagnostics-v1",
        "classification": "POST_HOC_DESCRIPTIVE_EMPIRICAL_ONLY",
        "audit": audit,
        "modes": modes,
        "paired_correctness_transitions": {
            "both_correct": correctness[(True, True)],
            "fixed2_only_correct": correctness[(True, False)],
            "adaptive_only_correct": correctness[(False, True)],
            "both_wrong": correctness[(False, False)],
        },
        "adaptive_minus_fixed2_cycles": {
            "mean": statistics.mean(deltas),
            "median": statistics.median(deltas),
            "adaptive_slower_count": len(adaptive_slower),
            "adaptive_slower_fraction": len(adaptive_slower) / len(deltas),
            "slowest_20_inputs": adaptive_slower[:20],
        },
        "teacher_label_class_breakdown": by_class,
        "adaptive_executed_exit_breakdown": adaptive_exit_summary,
        "adaptive_exit_cycle_and_correctness_delta": exit_delta_summary,
        "interpretation_limits": [
            "Post-hoc descriptive analysis of one session; no between-session variance estimate.",
            "Image-level summaries do not account for unknown writer clustering or prior exposure.",
            "Teacher labels assess classification accuracy; CPU Q15 oracle agreement is separately checked by the raw-run audit.",
            "Mode-level correctness changes do not by themselves establish that extra computation caused the change.",
            "No WCET, absolute-time, formal-timing, or population inference claim is made.",
        ],
    }


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--run-dir", type=Path, required=True)
    parser.add_argument("--out", type=Path, required=True)
    args = parser.parse_args()
    if args.out.exists():
        print("refusing to overwrite diagnostics output", file=sys.stderr)
        return 2
    audit = audit_run(args.run_dir, PACKAGE)
    with (args.run_dir / "physical_results.csv").open(encoding="utf-8-sig", newline="") as stream:
        rows = list(csv.DictReader(stream))
    result = summarize_rows(rows, audit)
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_bytes((json.dumps(result, indent=2) + "\n").encode("utf-8"))
    print(json.dumps({"classification": result["classification"], "audit": audit, "paired_correctness_transitions": result["paired_correctness_transitions"], "adaptive_minus_fixed2_cycles": {k: v for k, v in result["adaptive_minus_fixed2_cycles"].items() if k != "slowest_20_inputs"}}, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
