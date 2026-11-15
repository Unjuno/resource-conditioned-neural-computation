#!/usr/bin/env python3
"""Summarize C2J2 primary-session and executed-exit cycle structure.

Input must be the primary_rows_for_figures.csv emitted by the pinned,
read-only historical C2J2 reaggregator. This tool does not read C3 v2 data.
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
import statistics
from collections import Counter, defaultdict
from pathlib import Path

BUILD = "43324a32"
SOF = "5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6"
SESSIONS = [f"primary_{i:02d}" for i in range(1, 11)]
INPUT_IDS = list(range(360))


def sha256(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for block in iter(lambda: f.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def percentile(values: list[int], p: float) -> float:
    ordered = sorted(values)
    pos = (len(ordered) - 1) * p
    lo = int(pos)
    hi = min(lo + 1, len(ordered) - 1)
    return ordered[lo] * (hi - pos) + ordered[hi] * (pos - lo)


def load_rows(path: Path) -> list[dict]:
    with path.open("r", encoding="utf-8-sig", newline="") as f:
        raw = list(csv.DictReader(f))
    if len(raw) != 7200:
        raise ValueError(f"expected 7,200 primary rows, got {len(raw)}")
    rows = []
    seen = set()
    for r in raw:
        sid = r["session_id"]
        iid, mode, seq = int(r["input_id"]), int(r["mode"]), int(r["seq"])
        cycles, ex = int(r["cycles"]), int(r["executed_exit"])
        key = (sid, seq)
        if key in seen:
            raise ValueError(f"duplicate sequence {key}")
        seen.add(key)
        if sid not in SESSIONS or iid not in INPUT_IDS or mode not in (1, 3):
            raise ValueError(f"unexpected primary row identity {key} input={iid} mode={mode}")
        if r["build_id"].lower() != BUILD or r["sof_sha256"].lower() != SOF:
            raise ValueError(f"mixed/non-C2J2 identity at {key}")
        if r["case_status"] != "PASS" or cycles <= 0:
            raise ValueError(f"invalid status/cycle at {key}")
        if mode == 1 and ex != 2:
            raise ValueError(f"fixed comparator is not executed Exit 2 at {key}")
        if mode == 3 and not 1 <= ex <= 7:
            raise ValueError(f"invalid adaptive executed Exit at {key}")
        rows.append({**r, "session_id": sid, "experiment_id": r["experiment_id"],
                     "input_id": iid, "mode": mode, "seq": seq,
                     "cycles": cycles, "executed_exit": ex,
                     "prediction": int(r["prediction"]),
                     "reference_label": int(r["reference_label"])})

    by_pair: dict[tuple[str, int], dict[int, dict]] = defaultdict(dict)
    for r in rows:
        key = (r["session_id"], r["input_id"])
        if r["mode"] in by_pair[key]:
            raise ValueError(f"duplicate paired mode {key} mode={r['mode']}")
        by_pair[key][r["mode"]] = r
    expected = {(s, i) for s in SESSIONS for i in INPUT_IDS}
    if set(by_pair) != expected or any(set(v) != {1, 3} for v in by_pair.values()):
        raise ValueError("primary sessions do not contain one fixed2/adaptive row for every input")
    if len(rows) != 10 * 360 * 2:
        raise ValueError("primary row count inconsistent with 10 schedules x 360 inputs x 2 modes")
    return rows


def summarize(rows: list[dict], source_sha: str) -> dict:
    by_session: dict[str, list[dict]] = defaultdict(list)
    by_id: dict[int, dict[int, list[dict]]] = defaultdict(lambda: {1: [], 3: []})
    paired = []
    for r in rows:
        by_session[r["session_id"]].append(r)
        by_id[r["input_id"]][r["mode"]].append(r)
    pair_map = {(r["session_id"], r["input_id"], r["mode"]): r for r in rows}
    for sid in SESSIONS:
        for iid in INPUT_IDS:
            fixed = pair_map[(sid, iid, 1)]
            adaptive = pair_map[(sid, iid, 3)]
            if fixed["reference_label"] != adaptive["reference_label"]:
                raise ValueError(f"label mismatch within pair {sid}/{iid}")
            paired.append({"session_id": sid, "input_id": iid,
                           "fixed_cycles": fixed["cycles"], "adaptive_cycles": adaptive["cycles"],
                           "saving_cycles": fixed["cycles"] - adaptive["cycles"],
                           "adaptive_exit": adaptive["executed_exit"]})

    session_rows = []
    for sid in SESSIONS:
        ps = [p for p in paired if p["session_id"] == sid]
        fixed = [p["fixed_cycles"] for p in ps]
        adaptive = [p["adaptive_cycles"] for p in ps]
        saving = [p["saving_cycles"] for p in ps]
        rows_s = by_session[sid]
        predictions = {(r["input_id"], r["mode"]): r["prediction"] for r in rows_s}
        labels = {r["input_id"]: r["reference_label"] for r in rows_s}
        exit_counts = Counter(str(p["adaptive_exit"]) for p in ps)
        session_rows.append({
            "session_id": sid,
            "experiment_id": rows_s[0]["experiment_id"],
            "row_count": len(rows_s), "paired_input_count": len(ps),
            "fixed2_mean_cycles": statistics.mean(fixed),
            "adaptive_mean_cycles": statistics.mean(adaptive),
            "mean_fixed2_minus_adaptive_cycles": statistics.mean(saving),
            "mean_cycle_reduction_percent": 100 * sum(saving) / sum(fixed),
            "fixed2_median_cycles": statistics.median(fixed),
            "adaptive_median_cycles": statistics.median(adaptive),
            "fixed2_correct_of_360": sum(predictions[(i, 1)] == labels[i] for i in INPUT_IDS),
            "adaptive_correct_of_360": sum(predictions[(i, 3)] == labels[i] for i in INPUT_IDS),
            "adaptive_executed_exit_counts": json.dumps(dict(sorted(exit_counts.items(), key=lambda kv: int(kv[0]))), separators=(",", ":")),
            "boot_independence": "NOT_ESTABLISHED_FROM_RUN_RECORDS",
        })

    by_exit: dict[int, list[dict]] = defaultdict(list)
    for p in paired:
        by_exit[p["adaptive_exit"]].append(p)
    exit_rows = []
    for ex in sorted(by_exit):
        ps = by_exit[ex]
        cyc = [p["adaptive_cycles"] for p in ps]
        fixed = [p["fixed_cycles"] for p in ps]
        delta = [p["saving_cycles"] for p in ps]
        exit_rows.append({
            "adaptive_executed_exit": ex,
            "pair_observations": len(ps),
            "unique_input_ids": len({p["input_id"] for p in ps}),
            "adaptive_mean_cycles": statistics.mean(cyc),
            "adaptive_median_cycles": statistics.median(cyc),
            "adaptive_p25_cycles": percentile(cyc, .25),
            "adaptive_p75_cycles": percentile(cyc, .75),
            "paired_fixed2_mean_cycles": statistics.mean(fixed),
            "mean_fixed2_minus_adaptive_cycles": statistics.mean(delta),
            "adaptive_faster_pair_count": sum(x > 0 for x in delta),
            "adaptive_slower_pair_count": sum(x < 0 for x in delta),
        })

    input_rows = []
    for iid in INPUT_IDS:
        fixed = by_id[iid][1]
        adaptive = by_id[iid][3]
        labels = {r["reference_label"] for r in fixed + adaptive}
        fixed_preds = {r["prediction"] for r in fixed}
        adaptive_preds = {r["prediction"] for r in adaptive}
        if len(labels) != 1 or len(fixed_preds) != 1 or len(adaptive_preds) != 1:
            raise ValueError(f"reference/prediction varies across repeated rows for input {iid}")
        fcycles = [r["cycles"] for r in fixed]
        acycles = [r["cycles"] for r in adaptive]
        exits = Counter(str(r["executed_exit"]) for r in adaptive)
        input_rows.append({
            "input_id": iid,
            "reference_label": next(iter(labels)),
            "fixed2_prediction": next(iter(fixed_preds)),
            "adaptive_prediction": next(iter(adaptive_preds)),
            "fixed2_correct": int(next(iter(fixed_preds)) == next(iter(labels))),
            "adaptive_correct": int(next(iter(adaptive_preds)) == next(iter(labels))),
            "fixed2_mean_cycles": statistics.mean(fcycles),
            "adaptive_mean_cycles": statistics.mean(acycles),
            "fixed2_minus_adaptive_mean_cycles": statistics.mean(fcycles) - statistics.mean(acycles),
            "adaptive_executed_exit_counts": json.dumps(dict(sorted(exits.items(), key=lambda kv: int(kv[0]))), separators=(",", ":")),
            "adaptive_exit_unique_count": len(exits),
        })
    input_rows.sort(key=lambda r: r["fixed2_minus_adaptive_mean_cycles"])

    return {
        "schema": "rtnn-c2j2-primary-cycle-structure-v1",
        "status": "PASS_REAGGREGATED_FROM_VALIDATED_PRIMARY_ROWS",
        "data_class": "HISTORICAL_C2J2_PHYSICAL_EMPIRICAL_ONLY",
        "build_id": BUILD, "sof_sha256": SOF,
        "source_primary_rows_sha256": source_sha,
        "row_count": len(rows), "primary_session_count": len(SESSIONS),
        "independent_input_id_count": 360, "paired_primary_observations": len(paired),
        "session_boot_independence": "NOT_ESTABLISHED; schedule sessions are not treated as independent cold boots",
        "slow_input_interpretation": "Adaptive slowdowns are stratified by measured executed Exit. No causal claim about raw image features is made by this summary.",
        "primary_session_summary": session_rows,
        "adaptive_exit_paired_summary": exit_rows,
        "adaptive_faster_input_count": sum(r["fixed2_minus_adaptive_mean_cycles"] > 0 for r in input_rows),
        "adaptive_slower_input_count": sum(r["fixed2_minus_adaptive_mean_cycles"] < 0 for r in input_rows),
        "input_extremes": {
            "slowest_adaptive": input_rows[:20],
            "fastest_adaptive": list(reversed(input_rows[-20:])),
        },
        "claims": {
            "observed_cycle_reduction_is_empirical_only": True,
            "formal_speed_superiority": "NOT_CLAIMED",
            "accuracy_noninferiority_1pp": "INCONCLUSIVE",
            "absolute_time_or_ppm": "NOT_ESTABLISHED",
        },
    }


def write_csv(path: Path, rows: list[dict]) -> None:
    if not rows:
        raise ValueError(f"refusing to write empty table {path.name}")
    columns = list(rows[0])
    with path.open("w", encoding="utf-8", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=columns, lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--primary-rows", required=True, type=Path)
    ap.add_argument("--output-dir", required=True, type=Path)
    args = ap.parse_args()
    source = args.primary_rows.resolve()
    out = args.output_dir.resolve()
    if out.exists():
        raise FileExistsError(f"refusing to overwrite {out}")
    rows = load_rows(source)
    summary = summarize(rows, sha256(source))
    out.mkdir(parents=True)
    sessions = summary["primary_session_summary"]
    exits = summary["adaptive_exit_paired_summary"]
    # Full input table is emitted separately from the compact extremes stored in JSON.
    input_table = []
    by_id = defaultdict(list)
    for r in rows:
        by_id[r["input_id"]].append(r)
    for iid in INPUT_IDS:
        group = by_id[iid]
        f = [r for r in group if r["mode"] == 1]
        a = [r for r in group if r["mode"] == 3]
        label = group[0]["reference_label"]
        exit_counts = Counter(str(r["executed_exit"]) for r in a)
        fmean, amean = statistics.mean(r["cycles"] for r in f), statistics.mean(r["cycles"] for r in a)
        input_table.append({
            "input_id": iid, "reference_label": label,
            "fixed2_prediction": f[0]["prediction"], "adaptive_prediction": a[0]["prediction"],
            "fixed2_correct": int(f[0]["prediction"] == label), "adaptive_correct": int(a[0]["prediction"] == label),
            "fixed2_mean_cycles": fmean, "adaptive_mean_cycles": amean,
            "fixed2_minus_adaptive_mean_cycles": fmean - amean,
            "adaptive_executed_exit_counts": json.dumps(dict(sorted(exit_counts.items(), key=lambda kv: int(kv[0]))), separators=(",", ":")),
            "adaptive_exit_unique_count": len(exit_counts),
        })
    input_table.sort(key=lambda r: r["fixed2_minus_adaptive_mean_cycles"])
    write_csv(out / "primary_session_summary.csv", sessions)
    write_csv(out / "adaptive_exit_paired_summary.csv", exits)
    write_csv(out / "adaptive_slow_fast_input_profile.csv", input_table)
    (out / "analysis.json").write_text(json.dumps(summary, indent=2, ensure_ascii=False) + "\n", encoding="utf-8", newline="\n")
    manifest = []
    for p in sorted(out.iterdir()):
        if p.is_file() and p.name != "SHA256SUMS.txt":
            manifest.append(f"{sha256(p)}  {p.name}")
    (out / "SHA256SUMS.txt").write_text("\n".join(manifest) + "\n", encoding="ascii", newline="\n")
    print(f"PASS: 7,200 paired primary rows; 360 inputs; 10 sessions; {len(exits)} adaptive Exit strata")
    print(f"adaptive faster/slower inputs={summary['adaptive_faster_input_count']}/{summary['adaptive_slower_input_count']}; cold-boot independence not established")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
