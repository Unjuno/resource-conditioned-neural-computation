#!/usr/bin/env python3
"""Independent read-only reaggregation of the historical C2J2 campaign.

This analyzer is deliberately pinned to build 43324a32 and the historical
SOF. It reads frozen schedules, heldout labels, the Q15 oracle, per-run case
CSV files, raw result CSV files, and run manifests. It never reads C3 v2
physical data and refuses any mixed build/SOF identity.

Only Python's standard library is required. SVG figures are emitted directly
so reproduction does not depend on matplotlib, browser state, or a GPU.
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import html
import json
import math
import platform
import random
import statistics
import sys
from collections import Counter, defaultdict
from pathlib import Path

OLD_BUILD_ID = "43324a32"
OLD_MODEL_ID = "52544e4e"
OLD_SOF_SHA256 = "5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6"
CAMPAIGN_CANONICAL_SHA256 = "d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc"
CAMPAIGN_FILE_SHA256 = "3d97a1cd87395e294299cacb617474367c89a9295355cd25fb1b4fa67464c936"
Q15_HEADER_SHA256 = "961a76b7e220bf2f665e7c04ab62063600aa2e7eccf3403d80ea730bc993ad9f"
HELDOUT_FILE_SHA256 = "eeba9000a918bcba911007e78905c5052fc743422f95cb314a0fc9f4ecdfb14c"
Q15_ORACLE_FILE_SHA256 = "4e1a3ddcabe1884b1607c77d19b10da8a86d53da3f4c060c30d7449635ec3cf4"
OLD_CYCLE_BOUNDARY = (
    "Ibex mcycle after request/model/pixel validation and before admission; "
    "through Q15 inference, entropy stop, and argmax. Excludes wire decode/CRC, "
    "MMIO request copy, JTAG wait, response encoding, and response transfer."
)
EXPECTED_COUNTS = {
    "diagnostic_fixed": 2520,
    "diagnostic_adaptive": 7560,
    "diagnostic_capped": 7560,
    **{f"primary_{i:02d}": 720 for i in range(1, 11)},
}
SESSION_TAGS = {
    "diagnostic_fixed": "DIAGFIXED",
    "diagnostic_adaptive": "DIAGADAPTIVE",
    "diagnostic_capped": "DIAGCAPPED",
    **{f"primary_{i:02d}": f"PRIMARY{i:02d}" for i in range(1, 11)},
}


def sha256(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for block in iter(lambda: f.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def canonical_sha(value: object) -> str:
    raw = json.dumps(value, sort_keys=True, separators=(",", ":"), allow_nan=False).encode()
    return hashlib.sha256(raw).hexdigest()


def load_json(path: Path) -> dict:
    return json.loads(path.read_text(encoding="utf-8-sig"))


def read_csv(path: Path) -> list[dict[str, str]]:
    with path.open("r", newline="", encoding="utf-8-sig") as f:
        return list(csv.DictReader(f))


def require(condition: bool, message: str) -> None:
    if not condition:
        raise ValueError(message)


def percentile(values: list[float], q: float) -> float:
    if not values:
        raise ValueError("percentile of empty values")
    pos = (len(values) - 1) * q
    lo = int(pos)
    hi = min(lo + 1, len(values) - 1)
    return values[lo] * (hi - pos) + values[hi] * (pos - lo)


def input_bootstrap(fixed_by_input: dict[int, list[int]], adaptive_by_input: dict[int, list[int]],
                    seed: int = 63, replicates: int = 5000) -> dict:
    ids = sorted(fixed_by_input)
    require(ids == list(range(360)), "primary inputs do not cover frozen IDs 0..359")
    fixed = [statistics.mean(fixed_by_input[i]) for i in ids]
    adaptive = [statistics.mean(adaptive_by_input[i]) for i in ids]
    rng = random.Random(seed)
    diffs: list[float] = []
    savings: list[float] = []
    n = len(ids)
    for _ in range(replicates):
        draw = [rng.randrange(n) for _ in range(n)]
        fm = sum(fixed[i] for i in draw) / n
        am = sum(adaptive[i] for i in draw) / n
        diffs.append(fm - am)
        savings.append(100.0 * (fm - am) / fm)
    diffs.sort()
    savings.sort()
    fm = statistics.mean(fixed)
    am = statistics.mean(adaptive)
    return {
        "bootstrap_seed": seed,
        "bootstrap_replicates": replicates,
        "resampling_unit": "360 independent input IDs; average the 10 planned primary schedules within each input",
        "pairs": 3600,
        "independent_input_ids": 360,
        "fixed2_mean_cycles": fm,
        "adaptive_mean_cycles": am,
        "fixed2_minus_adaptive_mean_cycles": fm - am,
        "fixed2_minus_adaptive_95pct_ci_cycles": [percentile(diffs, 0.025), percentile(diffs, 0.975)],
        "mean_cycle_reduction_percent": 100.0 * (fm - am) / fm,
        "reduction_95pct_ci_percent": [percentile(savings, 0.025), percentile(savings, 0.975)],
        "claim_status": "DESCRIPTIVE_ONLY_COLD_BOOT_INDEPENDENCE_UNCONFIRMED",
    }


def validate_campaign(c3: Path) -> tuple[dict, dict[str, dict], dict[int, dict]]:
    campaign_path = c3 / "frozen_inputs/paper/campaign/campaign.json"
    require(sha256(campaign_path) == CAMPAIGN_FILE_SHA256, "frozen campaign file SHA mismatch")
    campaign = load_json(campaign_path)
    body = dict(campaign)
    stated = body.pop("campaign_sha256", None)
    require(stated == CAMPAIGN_CANONICAL_SHA256, "frozen campaign declared canonical SHA mismatch")
    require(canonical_sha(body) == CAMPAIGN_CANONICAL_SHA256, "frozen campaign canonical SHA mismatch")
    require(len(campaign.get("schedules", [])) == 13, "frozen schedule count is not 13")
    schedule_root = campaign_path.parent
    schedules: dict[str, dict] = {}
    for meta in campaign["schedules"]:
        sid = meta["session_id"]
        require(meta["record_count"] == EXPECTED_COUNTS.get(sid), f"{sid}: frozen row count mismatch")
        schedule = load_json(schedule_root / meta["matrix"])
        require(len(schedule["rows"]) == meta["record_count"], f"{sid}: schedule row count mismatch")
        require(canonical_sha(schedule["rows"]) == meta["schedule_sha256"], f"{sid}: frozen schedule SHA mismatch")
        require(schedule.get("schedule_sha256") == meta["schedule_sha256"], f"{sid}: declared schedule SHA mismatch")
        seqs = [int(x["seq"]) for x in schedule["rows"]]
        require(seqs == list(range(1, meta["record_count"] + 1)), f"{sid}: frozen sequence gap/duplicate")
        schedules[sid] = schedule
    require(set(schedules) == set(EXPECTED_COUNTS), "frozen schedule names differ from the pinned 13")

    heldout_path = c3 / "frozen_inputs/generated/heldout360.json"
    require(sha256(heldout_path) == HELDOUT_FILE_SHA256, "frozen heldout input SHA mismatch")
    heldout = load_json(heldout_path)
    require(heldout.get("record_count") == 360, "frozen heldout input count mismatch")
    require(len(heldout.get("records", [])) == 360, "heldout record count mismatch")
    labels = {int(r["input_id"]): int(r["label"]) for r in heldout["records"]}
    require(set(labels) == set(range(360)), "heldout input IDs do not cover 0..359")
    oracle_path = c3 / "frozen_inputs/generated/frozen_q15_oracle.json"
    require(sha256(oracle_path) == Q15_ORACLE_FILE_SHA256, "frozen Q15 oracle SHA mismatch")
    oracle = load_json(oracle_path)
    require(oracle.get("record_count") == 360, "Q15 oracle input count mismatch")
    require(len(oracle.get("predictions", {})) == 360, "Q15 oracle predictions incomplete")
    header = c3 / "source/recovered_c2_firmware_43324a32_20261115/model/realtime_nn_real_sequence_fixed_weights_generated.h"
    require(sha256(header) == Q15_HEADER_SHA256, "frozen Q15 weight header SHA mismatch")
    return campaign, schedules, {i: {"label": labels[i], **oracle["predictions"][str(i)]} for i in range(360)}


def session_paths(c3: Path, session: str) -> tuple[Path, Path, Path, Path]:
    nrows = EXPECTED_COUNTS[session]
    exp = f"C3_{SESSION_TAGS[session]}_FULL{nrows}_RUN1_20261114"
    run_dir = c3 / "campaign/results" / exp
    # The original full frozen case CSV is preserved under campaign/prepared;
    # chunk_jobs/chunk_0001 contains only the first chunk, not the full schedule.
    cases = c3 / "campaign/prepared" / session / "cases.csv"
    result = run_dir / "merged/c2_jtag_results.csv"
    if not result.is_file():
        result = run_dir / "c2_jtag_results.csv"  # legacy primary_01 layout
    manifest = run_dir / "run_manifest.json"
    audit = run_dir / "result_audit.json"
    return run_dir, cases, result, manifest


def verify_output_manifest(run_dir: Path, manifest: dict) -> None:
    for rel, expected in manifest.get("output_sha256", {}).items():
        path = run_dir.joinpath(*rel.split("/"))
        require(path.is_file(), f"{run_dir.name}: missing manifested output {rel}")
        require(sha256(path) == expected, f"{run_dir.name}: output SHA mismatch {rel}")


def audit_session(c3: Path, session: str, schedule: dict, labels_oracle: dict[int, dict]) -> tuple[list[dict], dict]:
    expected_n = EXPECTED_COUNTS[session]
    run_dir, cases_path, result_path, manifest_path = session_paths(c3, session)
    audit_path = run_dir / "result_audit.json"
    require(run_dir.is_dir(), f"missing historical run directory {run_dir}")
    manifest = load_json(manifest_path)
    audit = load_json(audit_path)
    require(manifest.get("experiment_id") == run_dir.name, f"{session}: experiment ID mismatch")
    require(manifest.get("session_id") == session, f"{session}: manifest session mismatch")
    require(manifest.get("status") == "PASS_EMPIRICAL_SESSION", f"{session}: manifest is not PASS")
    require(audit.get("status") == "PASS_EMPIRICAL_SESSION_AUDIT", f"{session}: saved auditor is not PASS")
    require(manifest.get("build_id", "").lower() == OLD_BUILD_ID, f"{session}: mixed/non-C2J2 build identity")
    require(manifest.get("model_id", "").lower() == OLD_MODEL_ID, f"{session}: old model ID mismatch")
    require(manifest.get("sof_sha256") == OLD_SOF_SHA256, f"{session}: mixed/non-C2J2 SOF identity")
    require(manifest.get("campaign_canonical_sha256") == CAMPAIGN_CANONICAL_SHA256,
            f"{session}: campaign identity mismatch")
    require(manifest.get("uart_used") is False and manifest.get("flash_written") is False,
            f"{session}: UART/Flash invariant mismatch")
    require(manifest.get("status") == "PASS_EMPIRICAL_SESSION", f"{session}: result manifest status invalid")
    require(audit.get("rows") == expected_n and audit.get("experiment_id") == manifest["experiment_id"],
            f"{session}: saved audit count/identity mismatch")
    require(sha256(cases_path) == manifest.get("case_csv_sha256"), f"{session}: cases SHA differs from manifest")
    require(sha256(cases_path) == audit.get("sha256", {}).get("cases.csv"), f"{session}: cases SHA differs from auditor")
    verify_output_manifest(run_dir, manifest)

    # Independently verify all chunk case files and their sequence coverage.
    chunk_manifest_path = run_dir / "chunk_jobs/chunks.json"
    if chunk_manifest_path.is_file():
        chunk_manifest = load_json(chunk_manifest_path)
        require(chunk_manifest.get("full_cases_sha256") == manifest["case_csv_sha256"],
                f"{session}: chunk manifest full-case identity mismatch")
        require(chunk_manifest.get("full_row_count") == expected_n, f"{session}: chunk row count mismatch")
        chunk_sequences: list[int] = []
        for chunk in chunk_manifest.get("chunks", []):
            chunk_case = run_dir / "chunk_jobs" / chunk["case_file"]
            require(sha256(chunk_case) == chunk["case_sha256"], f"{session}: chunk case SHA mismatch {chunk['case_file']}")
            chunk_rows = read_csv(chunk_case)
            seqs = [int(row["seq"]) for row in chunk_rows]
            require(len(seqs) == chunk["count"], f"{session}: chunk row count mismatch {chunk['case_file']}")
            require(seqs == list(range(chunk["first_seq"], chunk["last_seq"] + 1)),
                    f"{session}: chunk sequence range mismatch {chunk['case_file']}")
            chunk_sequences.extend(seqs)
        require(chunk_sequences == list(range(1, expected_n + 1)), f"{session}: chunk sequences missing, duplicate, or reordered")
    else:
        # The first historical primary session predates chunking; its full case
        # CSV hash above and every sequence below are checked directly.
        require(session == "primary_01", f"{session}: chunk provenance is unexpectedly absent")

    cases = read_csv(cases_path)
    actual = read_csv(result_path)
    frozen_rows = schedule["rows"]
    require(len(cases) == expected_n and len(actual) == expected_n, f"{session}: expected/actual row count mismatch")
    require(audit.get("rows") == len(actual), f"{session}: audited row count mismatch")
    require(len({r.get("seq") for r in cases}) == expected_n, f"{session}: duplicate case sequence")
    require(len({r.get("seq") for r in actual}) == expected_n, f"{session}: duplicate/missing result sequence")
    require([int(r["seq"]) for r in cases] == list(range(1, expected_n + 1)), f"{session}: case sequence gap/order")
    require([int(r["seq"]) for r in actual] == list(range(1, expected_n + 1)), f"{session}: result sequence gap/order")
    normalized: list[dict] = []
    for idx, (frozen, case, row) in enumerate(zip(frozen_rows, cases, actual), start=1):
        iid = int(frozen["input_id"])
        mode = int(frozen["mode"])
        require(int(case["seq"]) == idx and int(row["seq"]) == idx, f"{session} seq {idx}: sequence mismatch")
        require(int(case["input_id"]) == iid and int(row["input_id"]) == iid, f"{session} seq {idx}: input ID differs from frozen schedule")
        require(int(case["mode"]) == mode and int(row["mode"]) == mode, f"{session} seq {idx}: mode differs from frozen schedule")
        for field in ("fixed_exit", "budget_q16", "deadline_cycles"):
            require(int(case[field]) == int(frozen[field]), f"{session} seq {idx}: {field} differs from frozen schedule")
        require(int(case["expected_label"]) == labels_oracle[iid]["label"], f"{session} seq {idx}: teacher label mismatch")
        expected_exec = int(case["expected_executed"])
        expected_prediction = int(labels_oracle[iid]["predictions"][expected_exec])
        require(int(case["expected_prediction"]) == expected_prediction,
                f"{session} seq {idx}: prepared expectation differs from frozen Q15 oracle")
        require(int(row["expected_prediction"]) == expected_prediction,
                f"{session} seq {idx}: raw result expectation differs from Q15 oracle")
        require(int(row["expected_admitted"]) == int(case["expected_admitted"]), f"{session} seq {idx}: admitted binding mismatch")
        require(int(row["expected_executed"]) == expected_exec, f"{session} seq {idx}: executed binding mismatch")
        require(row["case_status"] == "PASS" and row["error"] == "", f"{session} seq {idx}: failed/missing status")
        require(row["cycle_valid"] == "1" and int(row["cycles"]) > 0, f"{session} seq {idx}: invalid cycle counter")
        require(int(row["reported_cycles"]) == int(row["cycles"]), f"{session} seq {idx}: reported cycle mismatch")
        require(row["response_crc_valid"] == "1", f"{session} seq {idx}: CRC failure")
        require(int(row["response_seq"]) == idx and int(row["response_input_id"]) == iid and
                int(row["response_mode"]) == mode, f"{session} seq {idx}: response identity mismatch")
        # C2J2's original response schema did not carry model/build/binding
        # fields per row; those identities are pinned in run_manifest.json.
        # If a newer row schema contains these fields, validate them as well.
        for field, expected in (("response_model_id", OLD_MODEL_ID),
                                ("response_build_id", OLD_BUILD_ID),
                                ("response_binding_id", OLD_BUILD_ID)):
            if field in row:
                require(row[field].lower() == expected, f"{session} seq {idx}: {field} mismatch")
        require(int(row["prediction"]) == expected_prediction, f"{session} seq {idx}: prediction mismatch")
        require(int(row["reference_label"]) == labels_oracle[iid]["label"] and
                int(row["response_label"]) == labels_oracle[iid]["label"], f"{session} seq {idx}: label mismatch")
        require(int(row["admitted_exit"]) == int(case["expected_admitted"]), f"{session} seq {idx}: admitted Exit mismatch")
        require(int(row["executed_exit"]) == expected_exec, f"{session} seq {idx}: executed Exit mismatch")
        require(int(row["executed_exit"]) <= int(row["admitted_exit"]), f"{session} seq {idx}: cap violation")
        require(row["sof_sha256"] == OLD_SOF_SHA256 and row["build_id"].lower() == OLD_BUILD_ID,
                f"{session} seq {idx}: row identity differs from C2J2")
        require(row["experiment_id"] == manifest["experiment_id"], f"{session} seq {idx}: experiment ID mismatch")
        normalized.append({
            "session_id": session,
            "experiment_id": row["experiment_id"],
            "seq": idx,
            "input_id": iid,
            "mode": mode,
            "prediction": int(row["prediction"]),
            "reference_label": int(row["reference_label"]),
            "expected_prediction": expected_prediction,
            "admitted_exit": int(row["admitted_exit"]),
            "executed_exit": int(row["executed_exit"]),
            "cycles": int(row["cycles"]),
            "sof_sha256": row["sof_sha256"],
            "build_id": row["build_id"],
            "case_status": row["case_status"],
        })
    return normalized, manifest


def svg_text(x: float, y: float, value: str, size: int = 13, anchor: str = "middle", fill: str = "#222") -> str:
    return f'<text x="{x:.1f}" y="{y:.1f}" text-anchor="{anchor}" font-size="{size}" fill="{fill}">{html.escape(value)}</text>'


def svg_start(title: str, subtitle: str, w: int = 1100, h: int = 680) -> list[str]:
    meta = f"C2J2 empirical only | build={OLD_BUILD_ID} | SOF SHA-256={OLD_SOF_SHA256} | 360 independent inputs | 10 primary schedules (3,600 paired rows) | cycle boundary: {OLD_CYCLE_BOUNDARY}"
    return [f'<svg xmlns="http://www.w3.org/2000/svg" width="{w}" height="{h}" viewBox="0 0 {w} {h}">',
            '<rect width="100%" height="100%" fill="white"/>',
            '<style>text{font-family:Arial,"Noto Sans JP",sans-serif}.grid{stroke:#dddddd;stroke-width:1}.axis{stroke:#333;stroke-width:1.5}</style>',
            svg_text(w/2, 34, title, 23), svg_text(w/2, 60, subtitle, 14, fill="#555"),
            f'<metadata>{html.escape(meta)}</metadata>']


def svg_footer(lines: list[str], note: str, h: int = 680) -> None:
    lines.append(svg_text(22, h-42, note, 12, anchor="start", fill="#7a321e"))
    lines.append(svg_text(22, h-18, f"EMPIRICAL_ONLY; no cold-boot independence, accuracy noninferiority, WCET, or absolute-time claim. {OLD_CYCLE_BOUNDARY}", 10, anchor="start", fill="#444"))
    lines.append("</svg>")


def write_svg(path: Path, lines: list[str]) -> None:
    path.write_text("\n".join(lines) + "\n", encoding="utf-8", newline="\n")


def figure_paired_differences(path: Path, paired: list[dict]) -> None:
    w, h = 1100, 680
    lines = svg_start("Per-input paired cycle difference", "Fixed Exit 2 minus adaptive; positive values indicate fewer cycles for adaptive", w, h)
    x0, y0, pw, ph = 85, 100, 950, 470
    vals = [r["fixed2_minus_adaptive_mean_cycles"] for r in paired]
    lo, hi = min(vals), max(vals)
    pad = max(10000.0, (hi-lo)*0.04)
    lo -= pad; hi += pad
    for k in range(6):
        v = lo + (hi-lo)*k/5
        y = y0 + ph - ph*k/5
        lines.append(f'<line class="grid" x1="{x0}" y1="{y:.1f}" x2="{x0+pw}" y2="{y:.1f}"/>')
        lines.append(svg_text(x0-12, y+4, f"{v/1e6:.2f}", 12, "end"))
    zero_y = y0 + ph - (0-lo)/(hi-lo)*ph
    lines.append(f'<line x1="{x0}" y1="{zero_y:.1f}" x2="{x0+pw}" y2="{zero_y:.1f}" stroke="#d62728" stroke-width="2"/>')
    ordered = sorted(paired, key=lambda r: r["input_id"])
    points = []
    for idx, r in enumerate(ordered):
        x = x0 + idx/(len(ordered)-1)*pw
        y = y0 + ph - (r["fixed2_minus_adaptive_mean_cycles"]-lo)/(hi-lo)*ph
        color = "#2878b5" if r["fixed2_minus_adaptive_mean_cycles"] >= 0 else "#cc493c"
        points.append(f'<circle cx="{x:.2f}" cy="{y:.2f}" r="2.2" fill="{color}"/>')
    lines.extend(points)
    lines += [f'<line class="axis" x1="{x0}" y1="{y0+ph}" x2="{x0+pw}" y2="{y0+ph}"/>',
              f'<line class="axis" x1="{x0}" y1="{y0}" x2="{x0}" y2="{y0+ph}"/>',
              svg_text(x0+pw/2, y0+ph+30, "Frozen input ID (0–359)", 14),
              svg_text(24, y0+ph/2, "Cycle saving (millions of cycles)", 14)]
    faster = sum(v > 0 for v in vals); slower = sum(v < 0 for v in vals)
    svg_footer(lines, f"Adaptive faster: {faster}/360 inputs; adaptive slower: {slower}/360. Point is the mean over 10 planned schedules, not 10 independent inputs.", h)
    write_svg(path, lines)


def figure_cdf(path: Path, fixed: list[int], adaptive: list[int]) -> None:
    w, h = 1100, 680
    lines = svg_start("Empirical cycle-count distributions", "Primary fixed Exit 2 vs adaptive; empirical CDF over recorded rows", w, h)
    x0, y0, pw, ph = 85, 100, 950, 470
    lo, hi = min(min(fixed), min(adaptive)), max(max(fixed), max(adaptive))
    for k in range(6):
        cy = y0 + ph - ph*k/5
        lines.append(f'<line class="grid" x1="{x0}" y1="{cy:.1f}" x2="{x0+pw}" y2="{cy:.1f}"/>')
        lines.append(svg_text(x0-12, cy+4, f"{k*20}%", 12, "end"))
        cx = x0 + pw*k/5
        v = lo + (hi-lo)*k/5
        lines.append(f'<line class="grid" x1="{cx:.1f}" y1="{y0}" x2="{cx:.1f}" y2="{y0+ph}"/>')
        lines.append(svg_text(cx, y0+ph+20, f"{v/1e6:.1f}", 11))
    for values, color, name in ((fixed, "#2878b5", "Fixed Exit 2"), (adaptive, "#e07a26", "Adaptive")):
        seq = sorted(values)
        pts = []
        for i, value in enumerate(seq):
            x = x0 + (value-lo)/(hi-lo)*pw
            y = y0 + ph - (i+1)/len(seq)*ph
            pts.append(f"{x:.2f},{y:.2f}")
        lines.append(f'<polyline fill="none" stroke="{color}" stroke-width="3" points="{" ".join(pts)}"/>')
    lines += [svg_text(x0+pw/2, y0+ph+43, "Ibex mcycle delta (millions)", 14),
              svg_text(35, y0+ph/2, "Cumulative share", 14)]
    lines += [f'<line x1="780" y1="82" x2="815" y2="82" stroke="#2878b5" stroke-width="3"/>', svg_text(820, 87, "Fixed Exit 2", 13, "start"),
              f'<line x1="930" y1="82" x2="965" y2="82" stroke="#e07a26" stroke-width="3"/>', svg_text(970, 87, "Adaptive", 13, "start")]
    svg_footer(lines, "Rows are repeated over 10 schedules; independent accuracy denominator remains 360 IDs.", h)
    write_svg(path, lines)


def figure_exit_cycles(path: Path, primary_rows: list[dict]) -> None:
    w, h = 1100, 680
    lines = svg_start("Executed Exit vs inference cycles", "Points are primary C2J2 observations; horizontal jitter is visual only", w, h)
    x0, y0, pw, ph = 85, 100, 950, 470
    exit_vals = sorted({r["executed_exit"] for r in primary_rows})
    ylo = min(r["cycles"] for r in primary_rows); yhi = max(r["cycles"] for r in primary_rows)
    for k in range(6):
        v = ylo+(yhi-ylo)*k/5; y = y0+ph-ph*k/5
        lines.append(f'<line class="grid" x1="{x0}" y1="{y:.1f}" x2="{x0+pw}" y2="{y:.1f}"/>')
        lines.append(svg_text(x0-12,y+4,f"{v/1e6:.1f}",12,"end"))
    colors={1:"#2878b5",3:"#e07a26"}
    groups=defaultdict(list)
    for r in primary_rows:
        groups[(r["mode"],r["executed_exit"])].append(r["cycles"])
        cat=exit_vals.index(r["executed_exit"])
        # Deterministic small horizontal spread prevents total occlusion.
        jitter=((r["input_id"]*37+r["seq"]*13)%101-50)/200
        x=x0+(cat+jitter+0.5)/len(exit_vals)*pw
        y=y0+ph-(r["cycles"]-ylo)/(yhi-ylo)*ph
        lines.append(f'<circle cx="{x:.2f}" cy="{y:.2f}" r="1.5" fill="{colors.get(r["mode"],"#777")}" fill-opacity="0.30"/>')
    for mode,color,label,offset in ((1,"#2878b5","Fixed Exit 2",-8),(3,"#e07a26","Adaptive",8)):
        centers=[]
        for j, ex in enumerate(exit_vals):
            vals=groups[(mode,ex)]
            if not vals: continue
            x=x0+(j+0.5)/len(exit_vals)*pw+offset
            y=y0+ph-(statistics.mean(vals)-ylo)/(yhi-ylo)*ph
            centers.append((x,y))
            lines.append(f'<circle cx="{x:.2f}" cy="{y:.2f}" r="4" fill="{color}" stroke="white" stroke-width="1"/>')
        if centers:
            lines.append(f'<polyline fill="none" stroke="{color}" stroke-width="2" points="{" ".join(f"{x:.2f},{y:.2f}" for x,y in centers)}"/>')
    for j,ex in enumerate(exit_vals):
        x=x0+(j+0.5)/len(exit_vals)*pw
        lines.append(svg_text(x,y0+ph+20,str(ex),12))
    lines += [f'<line class="axis" x1="{x0}" y1="{y0+ph}" x2="{x0+pw}" y2="{y0+ph}"/>',
              f'<line class="axis" x1="{x0}" y1="{y0}" x2="{x0}" y2="{y0+ph}"/>',
              svg_text(x0+pw/2,y0+ph+42,"Executed Exit",14),svg_text(28,y0+ph/2,"Ibex cycles (millions)",14)]
    lines += [f'<circle cx="790" cy="80" r="4" fill="#2878b5"/>',svg_text(800,85,"Fixed Exit 2",13,"start"),f'<circle cx="930" cy="80" r="4" fill="#e07a26"/>',svg_text(940,85,"Adaptive",13,"start")]
    svg_footer(lines,"Reported executed Exit is checked against the frozen Q15 execution expectation; no samples were synthesized.",h)
    write_svg(path,lines)


def figure_accuracy_tradeoff(path: Path, fixed_cycles: list[int], adaptive_cycles: list[int], fixed_correct: int, adaptive_correct: int) -> None:
    w,h=900,620
    lines=svg_start("Accuracy vs cycle-count tradeoff","Teacher-label accuracy is distinct from agreement with the frozen Q15 prediction",w,h)
    x0,y0,pw,ph=110,100,700,400
    vals=[fixed_cycles,adaptive_cycles]
    xmin=min(map(statistics.mean,vals))*0.8; xmax=max(map(statistics.mean,vals))*1.15
    for k in range(6):
        y=y0+ph-ph*k/5; pct=k*20
        lines.append(f'<line class="grid" x1="{x0}" y1="{y:.1f}" x2="{x0+pw}" y2="{y:.1f}"/>')
        lines.append(svg_text(x0-12,y+4,f"{pct}%",12,"end"))
        x=x0+pw*k/5; cv=xmin+(xmax-xmin)*k/5
        lines.append(f'<line class="grid" x1="{x:.1f}" y1="{y0}" x2="{x:.1f}" y2="{y0+ph}"/>')
        lines.append(svg_text(x,y0+ph+20,f"{cv/1e6:.2f}",11))
    for label,cycles,correct,color in (("Fixed Exit 2",fixed_cycles,fixed_correct,"#2878b5"),("Adaptive",adaptive_cycles,adaptive_correct,"#e07a26")):
        mean=statistics.mean(cycles); acc=100*correct/360
        x=x0+(mean-xmin)/(xmax-xmin)*pw; y=y0+ph-acc/100*ph
        lines.append(f'<circle cx="{x:.2f}" cy="{y:.2f}" r="8" fill="{color}"/>')
        lines.append(svg_text(x+14,y-10,f"{label}: {correct}/360",13,"start",color))
    lines += [svg_text(x0+pw/2,y0+ph+42,"Mean cycles per recorded condition (millions)",14),svg_text(26,y0+ph/2,"Accuracy vs teacher labels",14)]
    svg_footer(lines,"Paired 360-input accuracy CI is ±1.389 percentage points; 1 pp noninferiority remains INCONCLUSIVE.",h)
    write_svg(path,lines)


def write_csv(path: Path, rows: list[dict], columns: list[str]) -> None:
    with path.open("w", newline="", encoding="utf-8") as f:
        writer=csv.DictWriter(f,fieldnames=columns,lineterminator="\n")
        writer.writeheader(); writer.writerows(rows)


def build_outputs(c3: Path, out: Path, all_rows: list[dict], manifests: dict[str, dict],
                  campaign: dict, schedules: dict[str, dict], q15: dict[int, dict]) -> dict:
    require(not out.exists(), f"refusing to overwrite existing output: {out}")
    out.mkdir(parents=True)
    by_session=defaultdict(list)
    for row in all_rows: by_session[row["session_id"]].append(row)
    primary=[r for r in all_rows if r["session_id"].startswith("primary_")]
    pairs: dict[tuple[int,str],dict[int,dict]]=defaultdict(dict)
    for r in primary:
        key=(r["input_id"],r["session_id"])
        require(r["mode"] not in pairs[key],f"duplicate paired mode {key} {r['mode']}")
        pairs[key][r["mode"]]=r
    require(len(pairs)==3600 and all(set(v)=={1,3} for v in pairs.values()),"primary fixed2/adaptive pairing incomplete")
    fixed_by_input=defaultdict(list); adaptive_by_input=defaultdict(list); paired=[]
    primary_flat=[]
    for (iid,session),mode_rows in sorted(pairs.items()):
        f,a=mode_rows[1],mode_rows[3]
        require(f["executed_exit"]==2,f"{session} input {iid}: fixed comparator is not Exit 2")
        fixed_by_input[iid].append(f["cycles"]); adaptive_by_input[iid].append(a["cycles"])
        primary_flat.extend([f,a])
    for iid in range(360):
        fs=fixed_by_input[iid]; ads=adaptive_by_input[iid]
        require(len(fs)==10 and len(ads)==10,f"input {iid}: expected ten fixed/adaptive repetitions")
        fmean=statistics.mean(fs); amean=statistics.mean(ads)
        paired.append({"input_id":iid,"fixed2_mean_cycles":fmean,"adaptive_mean_cycles":amean,
                       "fixed2_minus_adaptive_mean_cycles":fmean-amean,
                       "fixed2_median_cycles":statistics.median(fs),"adaptive_median_cycles":statistics.median(ads),
                       "fixed2_repeat_count":len(fs),"adaptive_repeat_count":len(ads),
                       "reference_label":q15[iid]["label"],
                       "fixed2_correct":int(next(r["prediction"] for r in primary if r["input_id"]==iid and r["mode"]==1)==q15[iid]["label"]),
                       "adaptive_correct":int(next(r["prediction"] for r in primary if r["input_id"]==iid and r["mode"]==3)==q15[iid]["label"])})
    fixed2=[r["cycles"] for r in primary_flat if r["mode"]==1]
    adaptive=[r["cycles"] for r in primary_flat if r["mode"]==3]
    input_deltas=[r["fixed2_minus_adaptive_mean_cycles"] for r in paired]
    exits=defaultdict(Counter)
    for r in primary_flat:
        exits[str(r["mode"])][str(r["executed_exit"])] += 1
    fixed_correct=sum(x["fixed2_correct"] for x in paired)
    adaptive_correct=sum(x["adaptive_correct"] for x in paired)
    accuracy_diff=[float(x["adaptive_correct"]-x["fixed2_correct"]) for x in paired]
    rng=random.Random(63); boot=[]
    for _ in range(5000):
        draw=[accuracy_diff[rng.randrange(360)] for _ in range(360)]
        boot.append(100*sum(draw)/360)
    boot.sort()
    speed=input_bootstrap(fixed_by_input,adaptive_by_input)
    expected_analysis=load_json(c3/"campaign/analysis/C3_FULL24840_RUN4_FINAL_20261114/analysis.json")
    require(expected_analysis.get("validated_rows")==len(all_rows)==24840,"existing analysis row count differs from independent data")
    require(expected_analysis.get("campaign_canonical_sha256")==CAMPAIGN_CANONICAL_SHA256,"existing analysis campaign identity mismatch")
    # Compare both saved aggregate exports row-by-row with the independent
    # concatenation, not just their summary statistics or stated SHA values.
    for aggregate_name in ("C3_FULL24840_RUN4_FINAL_20261114", "C3_FULL24840_RUN5_REPRO_20261114"):
        aggregate_path = c3 / "campaign/analysis" / aggregate_name / "all_24840_results.csv"
        aggregate = read_csv(aggregate_path)
        require(len(aggregate) == len(all_rows), f"{aggregate_name}: aggregate row count mismatch")
        for ix, (saved, rebuilt) in enumerate(zip(aggregate, all_rows), start=1):
            for field in ("session_id", "experiment_id", "seq", "input_id", "mode", "prediction",
                          "reference_label", "admitted_exit", "executed_exit", "cycles", "sof_sha256",
                          "build_id", "case_status"):
                require(str(saved[field]) == str(rebuilt[field]),
                        f"{aggregate_name} row {ix}: aggregate differs from independently joined raw data ({field})")
    existing=speed
    old=expected_analysis["primary_paired_total"]
    for field,new_value,old_field in (("fixed2_mean_cycles",existing["fixed2_mean_cycles"],"mean_fixed2_cycles"),
                                      ("adaptive_mean_cycles",existing["adaptive_mean_cycles"],"mean_adaptive_cycles"),
                                      ("fixed2_minus_adaptive_mean_cycles",existing["fixed2_minus_adaptive_mean_cycles"],"mean_fixed2_minus_adaptive_cycles")):
        require(math.isclose(new_value,float(old[old_field]),rel_tol=0,abs_tol=1e-7),f"independent {field} differs from existing analysis")
    session_summary=[]
    for sid in EXPECTED_COUNTS:
        rows=by_session[sid]
        session_summary.append({"session_id":sid,"experiment_id":manifests[sid]["experiment_id"],
                                "expected_rows":EXPECTED_COUNTS[sid],"raw_rows":len(rows),
                                "unique_seq":len({r["seq"] for r in rows}),"status":"PASS_REAGGREGATED",
                                "board_power_session_id":manifests[sid].get("board_power_session_id","UNRECORDED"),
                                "cold_boot_confirmed":bool(manifests[sid].get("cold_boot_confirmed",False))})
    slow=sorted(paired,key=lambda r:r["fixed2_minus_adaptive_mean_cycles"])[:20]
    fast=sorted(paired,key=lambda r:r["fixed2_minus_adaptive_mean_cycles"],reverse=True)[:20]
    write_csv(out/"primary_paired_by_input.csv",paired,list(paired[0]))
    write_csv(out/"adaptive_slowest_20_inputs.csv",slow,list(slow[0]))
    write_csv(out/"adaptive_fastest_20_inputs.csv",fast,list(fast[0]))
    write_csv(out/"primary_rows_for_figures.csv",primary_flat,list(primary_flat[0]))
    figure_paired_differences(out/"figure_01_paired_cycle_saving.svg",paired)
    figure_cdf(out/"figure_02_cycle_distribution_cdf.svg",fixed2,adaptive)
    figure_exit_cycles(out/"figure_03_executed_exit_vs_cycles.svg",primary_flat)
    figure_accuracy_tradeoff(out/"figure_04_accuracy_cycle_tradeoff.svg",fixed2,adaptive,fixed_correct,adaptive_correct)
    primary02_10=sum(len(by_session[f"primary_{i:02d}"]) for i in range(2,11))
    require(primary02_10==6480,"primary_02–primary_10 must contain 9 x 720 = 6,480 rows")
    summary={
        "schema":"rtnn-historical-c2j2-independent-reaggregation-v1",
        "status":"PASS_DATA_INTEGRITY_EMPIRICAL_ONLY",
        "data_class":"HISTORICAL_C2J2_PHYSICAL",
        "build_id":OLD_BUILD_ID,"model_id":OLD_MODEL_ID,"sof_sha256":OLD_SOF_SHA256,
        "campaign_canonical_sha256":CAMPAIGN_CANONICAL_SHA256,
        "campaign_file_sha256":CAMPAIGN_FILE_SHA256,
        "q15_weight_header_sha256":Q15_HEADER_SHA256,
        "measurement_boundary":OLD_CYCLE_BOUNDARY,
        "input_count_independent":360,"planned_rows":24840,"raw_rows_validated":len(all_rows),
        "schedule_count":13,"schedule_rows":session_summary,
        "primary_02_to_10_rows":primary02_10,
        "duplicates":0,"missing_or_extra_sequences":0,"response_identity_failures":0,
        "prediction_vs_frozen_q15_failures":0,"admitted_or_executed_exit_failures":0,
        "cap_violations":0,"crc_failures":0,"timeouts_traps_or_case_errors":0,
        "teacher_label_accuracy":{"fixed2_correct":fixed_correct,"adaptive_correct":adaptive_correct,
                                   "independent_input_ids":360,"paired_difference_percentage_points":100*statistics.mean(accuracy_diff),
                                   "paired_input_bootstrap_95pct_ci_percentage_points":[percentile(boot,0.025),percentile(boot,0.975)],
                                   "noninferiority_1pp":"INCONCLUSIVE"},
        "paired_cycle_summary_preregistered":{"bootstrap_seed":speed["bootstrap_seed"],"bootstrap_replicates":speed["bootstrap_replicates"],
                                               "bootstrap_unit":speed["resampling_unit"],"pairs":speed["pairs"],
                                               "mean_fixed2_cycles":speed["fixed2_mean_cycles"],"mean_adaptive_cycles":speed["adaptive_mean_cycles"],
                                               "mean_fixed2_minus_adaptive_cycles":speed["fixed2_minus_adaptive_mean_cycles"],
                                               "input_bootstrap_95pct_ci_cycles":speed["fixed2_minus_adaptive_95pct_ci_cycles"],
                                               "mean_reduction_percent":speed["mean_cycle_reduction_percent"],
                                               "input_bootstrap_95pct_ci_reduction_percent":speed["reduction_95pct_ci_percent"],
                                               "three_confirmed_independent_cold_boots":False,"speedup_claim":"NOT_CLAIMED"},
        "descriptive_cycle_distributions":{"row_unit":"3,600 repeated primary observations per mode; these are not independent input IDs",
                                           "fixed2":{"count":len(fixed2),"mean":statistics.mean(fixed2),"median":statistics.median(fixed2),
                                                     "p25":percentile(sorted(map(float,fixed2)),0.25),"p75":percentile(sorted(map(float,fixed2)),0.75)},
                                           "adaptive":{"count":len(adaptive),"mean":statistics.mean(adaptive),"median":statistics.median(adaptive),
                                                       "p25":percentile(sorted(map(float,adaptive)),0.25),"p75":percentile(sorted(map(float,adaptive)),0.75)},
                                           "per_input_mean_cycle_difference_median":statistics.median(input_deltas),
                                           "adaptive_faster_input_count":sum(x>0 for x in input_deltas),
                                           "adaptive_slower_input_count":sum(x<0 for x in input_deltas),
                                           "equal_input_count":sum(x==0 for x in input_deltas),
                                           "executed_exit_counts_by_mode":dict(exits)},
        "exploratory_analysis":{"slowest_20":"adaptive_slowest_20_inputs.csv","fastest_20":"adaptive_fastest_20_inputs.csv",
                                "all_primary_rows":"primary_rows_for_figures.csv"},
        "old_analysis_comparison":{"existing_run4_csv_sha256":sha256(c3/"campaign/analysis/C3_FULL24840_RUN4_FINAL_20261114/all_24840_results.csv"),
                                   "existing_run5_csv_sha256":sha256(c3/"campaign/analysis/C3_FULL24840_RUN5_REPRO_20261114/all_24840_results.csv"),
                                   "cycle_mean_results_match_existing_run4":True},
        "limitations":["Cold-boot independence for the historical 10 primary sessions is not established.",
                        "Accuracy noninferiority at a 1 percentage-point margin remains inconclusive.",
                        "Cycle reductions are descriptive empirical measurements, not a speedup guarantee.",
                        "No absolute time, ppm, WCET, or hard deadline is inferred."],
    }
    (out/"analysis.json").write_text(json.dumps(summary,indent=2,ensure_ascii=False)+"\n",encoding="utf-8",newline="\n")
    return summary


def main() -> int:
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8", errors="backslashreplace")
    parser=argparse.ArgumentParser()
    parser.add_argument("--c3-root",type=Path,required=True)
    parser.add_argument("--out-dir",type=Path,required=True)
    args=parser.parse_args()
    c3=args.c3_root.resolve(); out=args.out_dir.resolve()
    require(not out.exists(),f"refusing to overwrite existing output: {out}")
    campaign,schedules,q15=validate_campaign(c3)
    all_rows=[]; manifests={}
    for session in EXPECTED_COUNTS:
        rows,manifest=audit_session(c3,session,schedules[session],q15)
        all_rows.extend(rows); manifests[session]=manifest
    require(len(all_rows)==24840,"old C2J2 dataset row total mismatch")
    summary=build_outputs(c3,out,all_rows,manifests,campaign,schedules,q15)
    # Output file hashes include every delivered analysis artifact, never themselves.
    lines=[]
    for path in sorted(p for p in out.iterdir() if p.is_file() and p.name!="SHA256SUMS.txt"):
        lines.append(f"{sha256(path)}  {path.name}")
    (out/"SHA256SUMS.txt").write_text("\n".join(lines)+"\n",encoding="ascii",newline="\n")
    print(f"PASS: independently verified {summary['raw_rows_validated']}/24840 historical C2J2 rows across 13 schedules")
    print(f"primary_02–10={summary['primary_02_to_10_rows']} rows; 360 independent inputs; C3 v2 excluded")
    print(f"fixed2-adaptive mean={summary['paired_cycle_summary_preregistered']['mean_fixed2_minus_adaptive_cycles']:.2f} cycles; cold boot uncertain; accuracy NI inconclusive")
    print(f"output={out}")
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (OSError, ValueError, KeyError, json.JSONDecodeError, csv.Error) as exc:
        print(f"FAIL: {exc}",file=sys.stderr)
        raise SystemExit(1)
