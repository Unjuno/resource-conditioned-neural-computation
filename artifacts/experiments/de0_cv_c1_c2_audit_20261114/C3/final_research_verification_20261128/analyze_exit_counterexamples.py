#!/usr/bin/env python3
"""Independent descriptive analysis of exit-to-exit correctness changes."""
import argparse
import csv
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent
FROZEN = ROOT.parent / "frozen_inputs" / "generated"
EXPECTED_INPUT_SHA = "eeba9000a918bcba911007e78905c5052fc743422f95cb314a0fc9f4ecdfb14c"


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--run-dir", type=Path, required=True)
    ap.add_argument("--out-dir", type=Path, required=True)
    args = ap.parse_args()
    if args.out_dir.exists():
        raise SystemExit("refusing to overwrite output directory")
    heldout_path = FROZEN / "heldout360.json"
    if sha(heldout_path) != EXPECTED_INPUT_SHA:
        raise SystemExit("frozen heldout input SHA mismatch")
    heldout = json.loads(heldout_path.read_text(encoding="utf-8"))["records"]
    oracle = json.loads((FROZEN / "frozen_q15_oracle.json").read_text(encoding="utf-8"))["predictions"]
    with (args.run_dir / "q15_heldout360_exit_metrics.csv").open(encoding="ascii", newline="") as f:
        raw = list(csv.DictReader(f))
    if len(heldout) != 360 or len(raw) != 360 * 7:
        raise SystemExit("heldout input or all-exit metric row count mismatch")
    metrics = {}
    for row in raw:
        key = (int(row["input_id"]) - 1, int(row["exit"]))
        if key in metrics or not 0 <= key[1] <= 6:
            raise SystemExit("duplicate or invalid all-exit row")
        metrics[key] = int(row["prediction"])
    incorrect = []
    for item in heldout:
        iid = int(item["input_id"])
        ref = oracle[str(iid)]["predictions"]
        for e in range(7):
            if metrics[(iid, e)] != int(ref[e]):
                incorrect.append((iid, e))
    if incorrect:
        raise SystemExit(f"frozen oracle mismatch: {incorrect[:5]}")
    correctness = {int(x["input_id"]): [int(metrics[(int(x["input_id"]), e)] == int(x["label"])) for e in range(7)] for x in heldout}
    counts = [sum(v[e] for v in correctness.values()) for e in range(7)]
    transitions = []
    for e in range(6):
        recovery = sum(v[e] == 0 and v[e + 1] == 1 for v in correctness.values())
        regression = sum(v[e] == 1 and v[e + 1] == 0 for v in correctness.values())
        stable = 360 - recovery - regression
        transitions.append({"from_exit": e, "to_exit": e + 1, "incorrect_to_correct": recovery, "correct_to_incorrect": regression, "same_correctness": stable})
    nonmonotonic = [iid for iid, v in correctness.items() if any(v[e] == 1 and any(z == 0 for z in v[e + 1:]) for e in range(7))]
    pilot_analysis = json.loads((args.run_dir / "STOPPING_COMPARISON.json").read_text(encoding="utf-8"))
    ent_hist = pilot_analysis["entropy_vs_fixed2_heldout360"]["executed_exit_histogram"]
    rows = []
    for item in heldout:
        iid = int(item["input_id"]); correct = correctness[iid]
        preds = [metrics[(iid, e)] for e in range(7)]
        first = next((e for e, c in enumerate(correct) if c), "none")
        rows.append([iid, int(item["label"]), *preds, *correct, first, int(iid in nonmonotonic)])
    args.out_dir.mkdir(parents=True)
    with (args.out_dir / "EXIT_ACCURACY_TRANSITIONS_HELDOUT360.csv").open("w", encoding="utf-8", newline="") as f:
        w = csv.writer(f, lineterminator="\n")
        w.writerow(["input_id", "teacher_label", *[f"prediction_exit_{e}" for e in range(7)], *[f"correct_exit_{e}" for e in range(7)], "first_correct_exit_0_to_6", "later_regression_after_any_correct"])
        w.writerows(rows)
    summary = {
        "schema": "rtnn-q15-exit-counterexamples-v1",
        "classification": "OFFLINE_DESCRIPTIVE_EXISTING_HELDOUT_NOT_NEW_EXTERNAL_EVALUATION",
        "inputs": {"count": 360, "sha256": EXPECTED_INPUT_SHA, "dataset": "existing sklearn.load_digits heldout split"},
        "source_metrics_csv_sha256": sha(args.run_dir / "q15_heldout360_exit_metrics.csv"),
        "frozen_oracle_all_exit_mismatches": 0,
        "per_exit": [{"exit": e, "correct": counts[e], "n": 360, "accuracy": counts[e] / 360} for e in range(7)],
        "adjacent_exit_correctness_transitions": transitions,
        "images_with_any_correct_then_later_incorrect_exit": len(nonmonotonic),
        "entropy_exit_histogram": ent_hist,
        "limits": ["Not physical cycles, latency, energy, or WCET.", "Existing test split and unknown writer clusters; no population inference.", "Exit 6 is analyzed as a model diagnostic; adaptive policy is capped at Exit 5."]
    }
    (args.out_dir / "EXIT_COUNTEREXAMPLES_SUMMARY.json").write_text(json.dumps(summary, indent=2) + "\n", encoding="utf-8", newline="")
    print(json.dumps({"status": "PASS_FROZEN_ORACLE_MATCH", "images": 360, "rows": len(rows), "mismatches": 0, "images_with_nonmonotonic_correctness": len(nonmonotonic), "transitions": transitions}, indent=2))


if __name__ == "__main__":
    main()
