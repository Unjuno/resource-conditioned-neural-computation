#!/usr/bin/env python3
"""Recompute a descriptive accuracy/cycle Pareto frontier from saved C3 v2 CSVs.

The frontier is exploratory, uses the same 360 frozen inputs, and is not a
confirmatory comparison or an independent-session uncertainty analysis.
Only Python's standard library is required.
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
import statistics
from collections import Counter, defaultdict
from pathlib import Path
from xml.sax.saxutils import escape

PAPER = Path(__file__).resolve().parent
C3 = PAPER.parent
CAMPAIGN = C3 / "evidence/PHYSICAL_C3_V2_20261115/FROZEN_CAMPAIGN"
ANALYSIS = PAPER / "diagnostic_run1/analysis.json"
EXPECTED_BUILD = "43334531"
EXPECTED_SOF = "85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d"
EXPECTED_CAMPAIGN = "d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc"
GROUPS = {
    "diagnostic_fixed": ("C3V2_DIAGFIXED_FULL2520_RUN2_20261115", 2520, 1),
    "diagnostic_adaptive": ("C3V2_DIAGADAPTIVE_FULL7560_RUN1_20261115", 7560, 3),
    "diagnostic_capped": ("C3V2_DIAGCAPPED_FULL7560_RUN1_20261115", 7560, 2),
}


def sha256(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(1024 * 1024), b""):
            h.update(chunk)
    return h.hexdigest()


def check(ok: bool, message: str) -> None:
    if not ok:
        raise ValueError(message)


def summarize_rows(rows: list[dict[str, str]], cases: list[dict[str, str]], kind: str, mode: int) -> list[dict]:
    grouped: dict[int, list[dict[str, str]]] = defaultdict(list)
    seen: set[tuple[int, int]] = set()
    cases_by_seq = {int(row["seq"]): row for row in cases}
    check(len(cases_by_seq) == len(cases) == len(rows), f"{kind}: missing/duplicate case sequence")
    for row in rows:
        check(row.get("case_status") == "PASS", f"{kind}: non-PASS row")
        check(row.get("cycle_valid") == "1" and row.get("response_crc_valid") == "1", f"{kind}: invalid cycle/CRC")
        check(row.get("build_id") == EXPECTED_BUILD and row.get("response_build_id") == EXPECTED_BUILD, f"{kind}: build mismatch")
        check(row.get("sof_sha256") == EXPECTED_SOF, f"{kind}: SOF mismatch")
        check(row.get("campaign_canonical_sha256") == EXPECTED_CAMPAIGN, f"{kind}: campaign mismatch")
        check(int(row["mode"]) == mode and int(row["response_mode"]) == mode, f"{kind}: mode mismatch")
        check(row["seq"] == row["response_seq"] and row["input_id"] == row["response_input_id"], f"{kind}: response identity mismatch")
        check(row["prediction"] == row["expected_prediction"], f"{kind}: frozen prediction mismatch")
        check(row["counter_status"] == "0" and row["response_flags"] == "1", f"{kind}: counter status/flags")
        start, end, cycles = int(row["cycles_start"]), int(row["cycles_end"]), int(row["cycles"])
        check(0 <= start < end < 2**64 and end - start == cycles == int(row["reported_cycles"]), f"{kind}: mcycle interval mismatch")
        executed, admitted = int(row["executed_exit"]), int(row["admitted_exit"])
        check(0 <= executed <= admitted <= 6, f"{kind}: cap violation")
        check(int(row["input_id"]) in range(360), f"{kind}: input ID out of range")
        seq = int(row["seq"])
        check(seq in cases_by_seq, f"{kind}: missing case sequence {seq}")
        case = cases_by_seq[seq]
        check(int(case["input_id"]) == int(row["input_id"]) and int(case["mode"]) == mode, f"{kind}: case/result identity mismatch")
        parameter = int(case["fixed_exit"]) if kind == "diagnostic_fixed" else int(case["budget_q16"])
        key = (int(row["input_id"]), parameter)
        check(key not in seen, f"{kind}: duplicate input/condition {key}")
        seen.add(key)
        grouped[parameter].append(row)

    expected_conditions = range(7) if kind == "diagnostic_fixed" else sorted({int(r["budget_q16"]) for r in cases})
    if kind != "diagnostic_fixed":
        check(len(expected_conditions) == 21 and expected_conditions[0] == 0 and expected_conditions[-1] == 65535, f"{kind}: wrong budget grid")
    points = []
    for parameter in expected_conditions:
        sample = grouped[parameter]
        check(len(sample) == 360 and {int(r["input_id"]) for r in sample} == set(range(360)), f"{kind}/{parameter}: missing IDs")
        cycles = [int(r["cycles"]) for r in sample]
        correct = sum(int(r["prediction"]) == int(r["reference_label"]) for r in sample)
        points.append({
            "kind": kind,
            "condition": f"fixed_exit={parameter}" if kind == "diagnostic_fixed" else f"budget_q16={parameter}",
            "fixed_exit": parameter if kind == "diagnostic_fixed" else None,
            "budget_q16": parameter if kind != "diagnostic_fixed" else None,
            "rows": len(sample),
            "unique_input_ids": 360,
            "correct": correct,
            "accuracy_percent": 100.0 * correct / 360,
            "mean_cycles": statistics.mean(cycles),
            "median_cycles": statistics.median(cycles),
            "executed_exit_distribution": dict(sorted(Counter(int(r["executed_exit"]) for r in sample).items())),
        })
    return points


def svg(points: list[dict], frontier: list[dict]) -> str:
    w, h, left, right, top, bottom = 1120, 710, 100, 1050, 70, 560
    xmax = 3_000_000
    xmin, ymin, ymax = 0, 40, 100
    x = lambda v: left + (right - left) * v / xmax
    y = lambda v: bottom - (bottom - top) * (v - ymin) / (ymax - ymin)
    colors = {"diagnostic_fixed": "#3274a1", "diagnostic_adaptive": "#138a72", "diagnostic_capped": "#cc6a3d"}
    out = [f'<svg xmlns="http://www.w3.org/2000/svg" width="{w}" height="{h}" viewBox="0 0 {w} {h}">',
           '<rect width="100%" height="100%" fill="white"/>',
           '<text x="100" y="34" font-family="Arial,sans-serif" font-size="22" font-weight="bold">C3 v2 empirical Pareto view (exploratory)</text>']
    for val in range(0, 3_000_001, 500_000):
        xx = x(val)
        out += [f'<line x1="{xx:.1f}" y1="{top}" x2="{xx:.1f}" y2="{bottom}" stroke="#e4e8ec"/>',
                f'<text x="{xx:.1f}" y="{bottom+25}" text-anchor="middle" font-family="Arial" font-size="13">{val/1e6:.1f}M</text>']
    for val in range(40, 101, 10):
        yy = y(val)
        out += [f'<line x1="{left}" y1="{yy:.1f}" x2="{right}" y2="{yy:.1f}" stroke="#e4e8ec"/>',
                f'<text x="{left-12}" y="{yy+5:.1f}" text-anchor="end" font-family="Arial" font-size="13">{val}%</text>']
    for p in points:
        out.append(f'<circle cx="{x(p["mean_cycles"]):.2f}" cy="{y(p["accuracy_percent"]):.2f}" r="4" fill="{colors[p["kind"]]}" fill-opacity="0.52"/>')
    for p in frontier:
        cx, cy = x(p["mean_cycles"]), y(p["accuracy_percent"])
        out += [f'<circle cx="{cx:.2f}" cy="{cy:.2f}" r="8" fill="none" stroke="#111" stroke-width="2"/>',
                f'<text x="{cx+11:.2f}" y="{cy-10:.2f}" font-family="Arial" font-size="13" fill="#111">{escape(p["label"])}</text>']
    legend = [("fixed", colors["diagnostic_fixed"]), ("adaptive", colors["diagnostic_adaptive"]), ("capped", colors["diagnostic_capped"])]
    for i, (label, color) in enumerate(legend):
        xx = 790 + i * 105
        out += [f'<circle cx="{xx}" cy="605" r="5" fill="{color}"/><text x="{xx+11}" y="610" font-family="Arial" font-size="14">{label}</text>']
    out += [f'<text x="{(left+right)/2}" y="652" text-anchor="middle" font-family="Arial" font-size="16">Mean observed FPGA mcycle (cycles)</text>',
            f'<text x="23" y="{(top+bottom)/2}" transform="rotate(-90 23 {(top+bottom)/2})" text-anchor="middle" font-family="Arial" font-size="16">Accuracy against frozen labels (%)</text>',
            '<text x="100" y="590" font-family="Arial" font-size="11" fill="#515b66">Build 43334531 | SOF SHA-256 85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d | empirical FPGA mcycle</text>',
            '<text x="100" y="612" font-family="Arial" font-size="11" fill="#515b66">360 frozen input IDs; one observation per mode/condition; one unverified board/session context; exploratory secondary diagnostics.</text>',
            '<text x="100" y="634" font-family="Arial" font-size="11" fill="#515b66">Boundary: start after request/pixel validation before admission/inference; end after inference/argmax; JTAG scan and response transfer excluded.</text>',
            '<text x="100" y="656" font-family="Arial" font-size="11" fill="#515b66">Not a preregistered inferential comparison, independent boot analysis, deadline guarantee, or generalization claim.</text>',
            '<text x="100" y="678" font-family="Arial" font-size="11" fill="#515b66">Accuracy is against frozen labels; the 49 settings are not 49 independent input samples.</text>',
            '</svg>']
    return "\n".join(out) + "\n"


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--out-dir", type=Path, required=True)
    args = ap.parse_args()
    check(not args.out_dir.exists(), f"refusing to overwrite: {args.out_dir}")
    baseline = json.loads(ANALYSIS.read_text(encoding="utf-8"))
    check(baseline["schema"] == "rtnn-c3v2-diagnostic-budget-analysis-v1", "diagnostic schema mismatch")
    check(baseline["source_build"] == EXPECTED_BUILD and baseline["source_sof_sha256"] == EXPECTED_SOF, "build/SOF mismatch")
    check(baseline["source_campaign_sha256"] == EXPECTED_CAMPAIGN and baseline["diagnostic_rows"] == 17640, "campaign/row count mismatch")
    manifest = {entry["schedule"]: entry for entry in baseline["diagnostic_schedules"]}
    all_points = []
    csv_inputs = []
    for kind, (run, expected_rows, mode) in GROUPS.items():
        path = CAMPAIGN / run / "results/c2_jtag_results.csv"
        check(path.is_file(), f"missing raw CSV {path}")
        digest = sha256(path)
        check(digest == manifest[kind]["csv_sha256"], f"saved audit SHA mismatch: {kind}")
        with path.open(newline="", encoding="utf-8-sig") as f:
            rows = list(csv.DictReader(f))
        check(len(rows) == expected_rows == manifest[kind]["rows"], f"wrong raw row count: {kind}")
        cases_path = CAMPAIGN / run / "input/cases.csv"
        check(cases_path.is_file(), f"missing frozen case manifest {cases_path}")
        with cases_path.open(newline="", encoding="utf-8-sig") as f:
            cases = list(csv.DictReader(f))
        check(len(cases) == expected_rows, f"wrong case-manifest row count: {kind}")
        points = summarize_rows(rows, cases, kind, mode)
        all_points.extend(points)
        csv_inputs.append({"path": path.relative_to(C3).as_posix(), "rows": len(rows), "sha256": digest,
                           "cases_path": cases_path.relative_to(C3).as_posix(), "cases_sha256": sha256(cases_path)})
    check(len(all_points) == 49, "expected 7 fixed + 21 adaptive + 21 capped points")

    # Collapse conditions with exactly equal measured metrics, then derive the
    # standard minimize-cycles / maximize-accuracy frontier.
    coordinate_groups: dict[tuple[float, float], list[dict]] = defaultdict(list)
    for p in all_points:
        coordinate_groups[(p["mean_cycles"], p["accuracy_percent"])].append(p)
    unique = []
    for (cycles, accuracy), members in coordinate_groups.items():
        unique.append({"mean_cycles": cycles, "accuracy_percent": accuracy, "conditions": [m["condition"] for m in members], "kinds": sorted({m["kind"] for m in members})})
    front = []
    for p in unique:
        dominated = any(q["accuracy_percent"] >= p["accuracy_percent"] and q["mean_cycles"] <= p["mean_cycles"] and (q["accuracy_percent"] > p["accuracy_percent"] or q["mean_cycles"] < p["mean_cycles"]) for q in unique)
        p["pareto_frontier"] = not dominated
        if not dominated:
            front.append(p)
    front.sort(key=lambda p: p["mean_cycles"])
    frontier_for_svg = [{**p, "label": ", ".join(p["conditions"])} for p in front]

    rows_csv = ["point_id,kind,condition,correct,accuracy_percent,mean_cycles,median_cycles,pareto_frontier,dominated_by"]
    for i, p in enumerate(all_points):
        dominators = [j for j, q in enumerate(all_points) if q["accuracy_percent"] >= p["accuracy_percent"] and q["mean_cycles"] <= p["mean_cycles"] and (q["accuracy_percent"] > p["accuracy_percent"] or q["mean_cycles"] < p["mean_cycles"])]
        dom = "|".join(f"p{j+1:02d}" for j in dominators)
        rows_csv.append(",".join([f"p{i+1:02d}", p["kind"], p["condition"], str(p["correct"]), f'{p["accuracy_percent"]:.9f}', f'{p["mean_cycles"]:.9f}', f'{p["median_cycles"]:.9f}', "true" if not dominators else "false", dom]))
    out = {
        "schema": "rtnn-c3v2-exploratory-pareto-v1",
        "classification": "SECONDARY_EXPLORATORY_EMPIRICAL_ONLY",
        "objective": {"cycles": "minimize", "accuracy_percent": "maximize", "accuracy_reference": "frozen ground-truth labels"},
        "identity": {"build_id": EXPECTED_BUILD, "sof_sha256": EXPECTED_SOF, "campaign_sha256": EXPECTED_CAMPAIGN},
        "data": {"raw_rows": 17640, "unique_input_ids": 360, "conditions": len(all_points), "same_input_set_for_every_condition": True, "cold_boot_independent": False, "confirmatory": False},
        "source_csvs": csv_inputs,
        "pareto_frontier_unique_coordinates": front,
        "all_points": all_points,
        "interpretation": "Post-hoc 2D descriptive frontier over saved fixed/adaptive/capped diagnostics; it is not a preregistered test, does not establish generalization, and does not replace the maximum-budget primary contrast.",
    }
    args.out_dir.mkdir(parents=True)
    (args.out_dir / "PARETO_ANALYSIS.json").write_text(json.dumps(out, indent=2, ensure_ascii=False, sort_keys=True) + "\n", encoding="utf-8")
    (args.out_dir / "PARETO_POINTS.csv").write_text("\n".join(rows_csv) + "\n", encoding="utf-8")
    (args.out_dir / "PARETO_FRONTIER.svg").write_text(svg(all_points, frontier_for_svg), encoding="utf-8")
    checksums = []
    for path in sorted(args.out_dir.iterdir()):
        if path.is_file() and path.name != "SHA256SUMS.txt":
            checksums.append(f"{sha256(path)}  {path.name}")
    (args.out_dir / "SHA256SUMS.txt").write_text("\n".join(checksums) + "\n", encoding="utf-8")
    print(f"PASS raw_rows=17640 conditions=49 frontier_unique={len(front)} build={EXPECTED_BUILD} input_ids=360")
    for p in front:
        print(f"FRONTIER accuracy={p['accuracy_percent']:.6f}% mean_cycles={p['mean_cycles']:.3f} conditions={';'.join(p['conditions'])}")


if __name__ == "__main__":
    main()
