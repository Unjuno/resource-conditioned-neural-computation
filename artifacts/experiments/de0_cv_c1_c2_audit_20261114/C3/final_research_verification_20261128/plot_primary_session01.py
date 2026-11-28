#!/usr/bin/env python3
"""Regenerate descriptive SVG figures from one independently audited physical run."""
from __future__ import annotations

import argparse
import csv
import hashlib
import html
import json
import math
import sys
from collections import defaultdict
from pathlib import Path

HERE = Path(__file__).resolve().parent
PKG = HERE.parent / "external_validation_20261122"
DEFAULT_RUN = PKG / "build/physical_primary_3session_20261128/session_01/run"
DEFAULT_OUT = HERE / "primary_session01_figures_RUN1_20261128"
sys.path.insert(0, str(HERE))
import audit_primary  # noqa: E402

COLORS = {1: "#0072B2", 2: "#D55E00", 3: "#009E73", 4: "#CC79A7", 5: "#E69F00"}


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def qtile(values: list[int], q: float) -> float:
    xs = sorted(values)
    if not xs:
        raise ValueError("empty quantile input")
    pos = (len(xs) - 1) * q
    lo, hi = math.floor(pos), math.ceil(pos)
    return xs[lo] + (xs[hi] - xs[lo]) * (pos - lo)


def svg_header(title: str, subtitle: str) -> list[str]:
    return [
        '<svg xmlns="http://www.w3.org/2000/svg" width="1100" height="820" viewBox="0 0 1100 820">',
        '<rect width="100%" height="100%" fill="white"/>',
        '<style>text{font-family:Arial, sans-serif;fill:#202124}.axis{stroke:#333;stroke-width:1}.grid{stroke:#d9dfe5;stroke-width:1}.note{font-size:14px}.small{font-size:12px}</style>',
        f'<text x="550" y="38" text-anchor="middle" font-size="22" font-weight="bold">{html.escape(title)}</text>',
        f'<text x="550" y="62" text-anchor="middle" class="note">{html.escape(subtitle)}</text>',
    ]


def svg_scatter(rows: list[dict], reduction: dict) -> str:
    w, h, left, top, pw, ph = 1100, 820, 105, 105, 850, 570
    xmax = 2_800_000
    sx = lambda v: left + pw * v / xmax
    sy = lambda v: top + ph * (1 - v / xmax)
    lines = svg_header(
        "Physical primary session 01: paired inference cycles",
        "One empirical FPGA session · 3,813 paired images · mcycle start/end bracket inference only",
    )
    for tick in range(0, 2_800_001, 400_000):
        x, y = sx(tick), sy(tick)
        lines += [f'<line class="grid" x1="{left}" y1="{y:.2f}" x2="{left+pw}" y2="{y:.2f}"/>',
                  f'<line class="grid" x1="{x:.2f}" y1="{top}" x2="{x:.2f}" y2="{top+ph}"/>',
                  f'<text x="{left-12}" y="{y+4:.2f}" text-anchor="end" class="small">{tick/1e6:.1f}M</text>',
                  f'<text x="{x:.2f}" y="{top+ph+22}" text-anchor="middle" class="small">{tick/1e6:.1f}M</text>']
    lines += [f'<line class="axis" x1="{left}" y1="{top+ph}" x2="{left+pw}" y2="{top+ph}"/>',
              f'<line class="axis" x1="{left}" y1="{top}" x2="{left}" y2="{top+ph}"/>',
              f'<line x1="{sx(0)}" y1="{sy(0)}" x2="{sx(xmax)}" y2="{sy(xmax)}" stroke="#555" stroke-dasharray="8 6" stroke-width="2"/>']
    for row in rows:
        ex = int(row["adaptive_executed_exit"])
        lines.append(f'<circle cx="{sx(row["fixed2_cycles"]):.2f}" cy="{sy(row["adaptive_cycles"]):.2f}" r="2.1" fill="{COLORS[ex]}" fill-opacity="0.55"/>')
    lines += [f'<text x="{left+pw/2}" y="{top+ph+55}" text-anchor="middle" font-size="16">Fixed Exit 2 cycles (Ibex mcycle)</text>',
              f'<text x="27" y="{top+ph/2}" text-anchor="middle" font-size="16" transform="rotate(-90 27 {top+ph/2})">Adaptive cycles (Ibex mcycle)</text>']
    for i, ex in enumerate(sorted(COLORS)):
        x = left + 16 + i * 118
        lines += [f'<circle cx="{x}" cy="{top+ph+91}" r="5" fill="{COLORS[ex]}"/>',
                  f'<text x="{x+10}" y="{top+ph+96}" class="small">Adaptive Exit {ex}</text>']
    lo, hi = reduction["input_bootstrap_95_percentile"]
    lines += [f'<text x="{left+pw}" y="{top-20}" text-anchor="end" class="note">Observed paired saving {reduction["ratio_of_sums"]*100:.2f}% (input bootstrap 95% CI {lo*100:.2f}–{hi*100:.2f}%)</text>',
              '<text x="550" y="790" text-anchor="middle" class="note">Build 45585631 · SOF SHA-256 5e333e93…5dfa00c4 · exploratory, single session · COLD_BOOT_UNVERIFIED</text>',
              '</svg>']
    return "\n".join(lines)


def svg_delta(rows: list[dict]) -> str:
    left, top, pw, ph = 130, 105, 840, 560
    groups: dict[int, list[int]] = defaultdict(list)
    for row in rows:
        groups[int(row["adaptive_executed_exit"])].append(row["adaptive_cycles"] - row["fixed2_cycles"])
    vals = [x for group in groups.values() for x in group]
    lo, hi = min(vals), max(vals)
    pad = max(80_000, (hi - lo) * 0.08)
    lo, hi = lo - pad, hi + pad
    sx = lambda i: left + (i - 0.5) * pw / 5
    sy = lambda v: top + ph * (1 - (v - lo) / (hi - lo))
    lines = svg_header(
        "Physical primary session 01: adaptive cycle delta by executed exit",
        "Delta = adaptive mcycle − fixed Exit 2 mcycle · positive values mean adaptive took longer",
    )
    for i in range(6):
        v = lo + (hi - lo) * i / 5
        y = sy(v)
        lines += [f'<line class="grid" x1="{left}" y1="{y:.2f}" x2="{left+pw}" y2="{y:.2f}"/>',
                  f'<text x="{left-14}" y="{y+4:.2f}" text-anchor="end" class="small">{v/1e6:.2f}M</text>']
    lines.append(f'<line x1="{left}" y1="{sy(0):.2f}" x2="{left+pw}" y2="{sy(0):.2f}" stroke="#555" stroke-dasharray="8 6" stroke-width="2"/>')
    for ex in sorted(groups):
        xs = groups[ex]
        x = sx(ex)
        q0, q1, med, q3, q4 = min(xs), qtile(xs, .25), qtile(xs, .5), qtile(xs, .75), max(xs)
        lines += [f'<line x1="{x}" y1="{sy(q0):.2f}" x2="{x}" y2="{sy(q4):.2f}" stroke="{COLORS[ex]}" stroke-width="2"/>',
                  f'<line x1="{x-13}" y1="{sy(q0):.2f}" x2="{x+13}" y2="{sy(q0):.2f}" stroke="{COLORS[ex]}" stroke-width="2"/>',
                  f'<line x1="{x-13}" y1="{sy(q4):.2f}" x2="{x+13}" y2="{sy(q4):.2f}" stroke="{COLORS[ex]}" stroke-width="2"/>',
                  f'<rect x="{x-34}" y="{sy(q3):.2f}" width="68" height="{max(1,sy(q1)-sy(q3)):.2f}" fill="{COLORS[ex]}" fill-opacity=".24" stroke="{COLORS[ex]}" stroke-width="2"/>',
                  f'<line x1="{x-34}" y1="{sy(med):.2f}" x2="{x+34}" y2="{sy(med):.2f}" stroke="{COLORS[ex]}" stroke-width="3"/>',
                  f'<text x="{x}" y="{top+ph+24}" text-anchor="middle" class="small">Exit {ex}</text>',
                  f'<text x="{x}" y="{top+ph+43}" text-anchor="middle" class="small">n={len(xs)}</text>']
    lines += [f'<line class="axis" x1="{left}" y1="{top+ph}" x2="{left+pw}" y2="{top+ph}"/>',
              f'<line class="axis" x1="{left}" y1="{top}" x2="{left}" y2="{top+ph}"/>',
              f'<text x="550" y="{top+ph+70}" text-anchor="middle" font-size="16">Adaptive executed exit</text>',
              f'<text x="30" y="{top+ph/2}" text-anchor="middle" font-size="15" transform="rotate(-90 30 {top+ph/2})">Paired cycle delta (mcycle)</text>',
              '<text x="550" y="790" text-anchor="middle" class="note">Single empirical session · build 45585631 · same 3,813 images · not a population or cold-boot estimate</text>',
              '</svg>']
    return "\n".join(lines)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--run-dir", type=Path, default=DEFAULT_RUN)
    ap.add_argument("--out-dir", type=Path, default=DEFAULT_OUT)
    ap.add_argument("--package", type=Path, default=PKG)
    args = ap.parse_args()
    audit = audit_primary.audit_run(args.run_dir, args.package)
    result_file = args.run_dir / "physical_results.csv"
    rows = list(csv.DictReader(result_file.open(encoding="utf-8-sig", newline="")))
    pairs: dict[str, dict[str, dict]] = defaultdict(dict)
    for row in rows:
        if row["mode"] in pairs[row["input_id"]]:
            raise ValueError(f"duplicate mode for input {row['input_id']}")
        pairs[row["input_id"]][row["mode"]] = row
    if len(pairs) != 3813 or any(set(x) != {"fixed2", "adaptive"} for x in pairs.values()):
        raise ValueError("expected 3,813 complete fixed2/adaptive pairs")
    joined = []
    for input_id in sorted(pairs, key=int):
        f, a = pairs[input_id]["fixed2"], pairs[input_id]["adaptive"]
        if f["teacher_label"] != a["teacher_label"]:
            raise ValueError("teacher label mismatch in pair")
        joined.append({
            "input_id": input_id,
            "teacher_label": int(f["teacher_label"]),
            "fixed2_cycles": int(f["cycles"]),
            "adaptive_cycles": int(a["cycles"]),
            "adaptive_executed_exit": int(a["executed_exit"]),
            "fixed2_correct": int(f["prediction"]) == int(f["teacher_label"]),
            "adaptive_correct": int(a["prediction"]) == int(a["teacher_label"]),
        })
    analysis = json.loads((args.run_dir / ".." / "analysis_single" / "analysis.json").resolve().read_text(encoding="utf-8"))
    reduction = analysis["cycles_by_session"][0]
    args.out_dir.mkdir(parents=True, exist_ok=False)
    with (args.out_dir / "paired_values.csv").open("w", encoding="utf-8", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=list(joined[0]), lineterminator="\n")
        writer.writeheader()
        writer.writerows(joined)
    (args.out_dir / "paired_cycles_scatter.svg").write_text(svg_scatter(joined, reduction), encoding="utf-8", newline="\n")
    (args.out_dir / "cycle_delta_by_exit.svg").write_text(svg_delta(joined), encoding="utf-8", newline="\n")
    metadata = {
        "schema": "rtnn-primary-session-figure-source-v1",
        "classification": "EMPIRICAL_ONLY_SINGLE_SESSION",
        "audit": audit,
        "input_result_sha256": sha(result_file),
        "analysis_sha256": sha((args.run_dir / ".." / "analysis_single" / "analysis.json").resolve()),
        "paired_rows": len(joined),
        "session_ids": sorted({r["session_id"] for r in rows}),
        "build_id": "45585631",
        "sof_sha256": audit_primary.SOF,
        "measurement_boundary": "64-bit Ibex mcycle start/end around inference; host/JTAG scan/wait excluded",
        "cold_boot": "COLD_BOOT_UNVERIFIED",
        "formal_timing_signoff": "BLOCKED_EXTERNAL_BOARD_TIMING",
        "figures": {
            "paired_cycles_scatter.svg": sha(args.out_dir / "paired_cycles_scatter.svg"),
            "cycle_delta_by_exit.svg": sha(args.out_dir / "cycle_delta_by_exit.svg"),
            "paired_values.csv": sha(args.out_dir / "paired_values.csv"),
        },
    }
    (args.out_dir / "figure_metadata.json").write_text(json.dumps(metadata, indent=2) + "\n", encoding="utf-8", newline="\n")
    sums = [f"{sha(p)}  {p.name}" for p in sorted(args.out_dir.iterdir()) if p.is_file() and p.name != "SHA256SUMS.txt"]
    (args.out_dir / "SHA256SUMS.txt").write_text("\n".join(sums) + "\n", encoding="ascii", newline="\n")
    print(json.dumps({"status": "PASS", "rows": len(joined), "output": str(args.out_dir), "cold_boot": metadata["cold_boot"], "classification": metadata["classification"]}, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
