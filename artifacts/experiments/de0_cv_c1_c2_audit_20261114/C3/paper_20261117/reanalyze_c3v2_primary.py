#!/usr/bin/env python3
"""Read-only, stdlib-only, exact-build C3 v2 primary analysis.

Never treats ten schedule repeats as independent inputs or independent cold boots.
Explicitly distinguishes C2J2 and C3 v2 by build ID and SOF digest.
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import html
import json
import random
import statistics
import xml.etree.ElementTree as ET
from collections import Counter, defaultdict
from pathlib import Path

C3 = Path(__file__).resolve().parent.parent
C3V2_DIR = C3 / "evidence/PHYSICAL_C3_V2_20261115/FROZEN_CAMPAIGN"
C2J2_DIR = C3 / "campaign/results"
CAMPAIGN_SHA = "d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc"
NEW_SOF = "85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d"
OLD_SOF = "5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6"
MODEL_ID = "52544e4e"
B = 5000
SEED = 63

def require(condition: bool, message: str) -> None:
    if not condition:
        raise ValueError(message)

def sha(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as handle:
        for chunk in iter(lambda: handle.read(1 << 20), b""):
            digest.update(chunk)
    return digest.hexdigest()

def dec(row: dict[str, str], key: str) -> int:
    require(key in row and row[key] != "", f"missing {key}")
    value = int(row[key])
    return value

def validate_row(row: dict[str, str], build: str, sof: str, new: bool) -> None:
    require(row["case_status"] == "PASS", "non-PASS request")
    require(row["build_id"] == build and row["sof_sha256"] == sof, "wrong build/SOF")
    require(row["response_crc_valid"] == "1" and row["cycle_valid"] == "1", "CRC/cycle invalid")
    require(dec(row, "response_seq") == dec(row, "seq"), "sequence mismatch")
    require(dec(row, "response_input_id") == dec(row, "input_id"), "input ID mismatch")
    require(dec(row, "response_mode") == dec(row, "mode"), "mode mismatch")
    require(dec(row, "prediction") == dec(row, "expected_prediction"), "Q15 mismatch")
    require(dec(row, "admitted_exit") == dec(row, "expected_admitted"), "admission mismatch")
    require(dec(row, "executed_exit") == dec(row, "expected_executed"), "executed exit mismatch")
    require(dec(row, "cycles") > 0, "zero cycles")
    require(0 <= dec(row, "input_id") < 360, "input outside frozen 360")
    require(dec(row, "mode") in (1, 3), "unexpected primary mode")
    if new:
        require(row["campaign_canonical_sha256"] == CAMPAIGN_SHA, "campaign mismatch")
        require(row["binding_id"] == build, "binding ID mismatch")
        require(row["response_build_id"] == build and row["response_model_id"] == MODEL_ID, "response build/model mismatch")
        require(row["response_binding_id"] == build, "response binding mismatch")
        require(row["counter_status"] == "0" and row["response_flags"] == "1", "counter/flags invalid")
        start, end = dec(row, "cycles_start"), dec(row, "cycles_end")
        require(0 <= start < end < (1 << 64), "counter monotonicity/uint64 invalid")
        require(end - start == dec(row, "cycles") == dec(row, "reported_cycles"), "mcycle interval mismatch")

def load_rows(path: Path, build: str, sof: str, new: bool, expected_sha: str | None = None) -> dict[tuple[int, int], dict[str, str]]:
    require(path.is_file(), f"missing source {path}")
    if expected_sha is not None:
        require(sha(path) == expected_sha, f"source SHA mismatch: {path}")
    with path.open(newline="", encoding="utf-8-sig") as handle:
        reader = csv.DictReader(handle)
        require(reader.fieldnames is not None and len(set(reader.fieldnames)) == len(reader.fieldnames), "duplicate/missing header")
        rows = list(reader)
    require(len(rows) == 720, f"primary must contain exactly 720 rows: {path}")
    pairs: dict[tuple[int, int], dict[str, str]] = {}
    seq: set[int] = set()
    for row in rows:
        validate_row(row, build, sof, new)
        s = dec(row, "seq")
        require(s not in seq, "duplicate sequence")
        seq.add(s)
        key = dec(row, "input_id"), dec(row, "mode")
        require(key not in pairs, "duplicate input/mode pair")
        pairs[key] = row
    require(seq == set(range(1, 721)), "sequence range mismatch")
    require(set(pairs) == {(i, m) for i in range(360) for m in (1, 3)}, "primary 360 x 2 coverage mismatch")
    return pairs

def percentile(a: list[float], q: float) -> float:
    a = sorted(a)
    p = (len(a) - 1) * q
    lo = int(p)
    hi = min(lo + 1, len(a) - 1)
    return a[lo] * (hi - p) + a[hi] * (p - lo)

def bootstrap(items: list[dict], n: int = B, seed: int = SEED) -> dict:
    rng = random.Random(seed)
    savings, reductions = [], []
    for _ in range(n):
        draw = [items[rng.randrange(len(items))] for _ in range(len(items))]
        fm = statistics.mean(x["fixed_mean"] for x in draw)
        am = statistics.mean(x["adaptive_mean"] for x in draw)
        savings.append(fm - am)
        reductions.append(100 * (fm - am) / fm)
    return {"seed": seed, "replicates": n, "resampling_unit": "360 distinct input IDs",
            "saving_95pct_ci": [percentile(savings, .025), percentile(savings, .975)],
            "reduction_percent_95pct_ci": [percentile(reductions, .025), percentile(reductions, .975)]}

def accuracy_bootstrap(items: list[dict], n: int = B, seed: int = SEED) -> dict:
    rng = random.Random(seed)
    vals = []
    for _ in range(n):
        d = [items[rng.randrange(len(items))] for _ in range(len(items))]
        vals.append(100 * statistics.mean((x["adaptive_correct"] - x["fixed_correct"]) for x in d))
    return {"seed": seed, "replicates": n,
            "difference_pp_95pct_ci": [percentile(vals, .025), percentile(vals, .975)]}

def write_svg(out: Path, lines: list[str]) -> None:
    out.write_text("\n".join(lines) + "\n", encoding="utf-8")
    ET.parse(out)

def svg_start(title: str, subtitle: str) -> list[str]:
    return ['<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 1100 670" role="img">',
            '<rect width="1100" height="670" fill="#ffffff"/>',
            f'<title>{html.escape(title)}</title>',
            f'<text x="68" y="59" font-family="Arial,sans-serif" font-size="26" font-weight="bold" fill="#1c2938">{html.escape(title)}</text>',
            f'<text x="68" y="88" font-family="Arial,sans-serif" font-size="16" fill="#5e6876">{html.escape(subtitle)}</text>']

def svg_end() -> list[str]:
    return ['<text x="68" y="643" font-family="Arial,sans-serif" font-size="13" fill="#4f5867">DE0-CV | C3 v2 build 43334531 | 360 frozen inputs | one unverified power session | EMPIRICAL_ONLY</text>',
            '<text x="68" y="661" font-family="Arial,sans-serif" font-size="12" fill="#8a3641">Not cold-boot/generalization evidence. No FPGA JTAG signoff, WCET, or 1 pp noninferiority claim.</text>',
            '</svg>']

def make_figure_paired(items: list[dict], out: Path) -> None:
    values = sorted((x["saving_cycles"] for x in items))
    L, R, T, H = 88, 1035, 140, 425
    ymin, ymax = -1750000, 500000
    y = lambda v: T + H * (ymax - v) / (ymax - ymin)
    x = lambda i: L + (R - L) * i / 359
    lines = svg_start("Paired FPGA cycle saving by input", "Sorted 360 unique inputs; fixed Exit 2 minus adaptive, positive means adaptive is faster.")
    for t in [-1500000, -1000000, -500000, 0, 500000]:
        yy = y(t)
        lines += [f'<line x1="{L}" y1="{yy:.2f}" x2="{R}" y2="{yy:.2f}" stroke="#d9e0e6"/>',
                  f'<text x="77" y="{yy+5:.2f}" text-anchor="end" font-family="Arial" font-size="13" fill="#465363">{t/1e6:g}M</text>']
    lines += [f'<line x1="{L}" y1="{y(0):.2f}" x2="{R}" y2="{y(0):.2f}" stroke="#101d2d" stroke-width="2"/>']
    for i, v in enumerate(values):
        lines += [f'<line x1="{x(i):.2f}" y1="{y(0):.2f}" x2="{x(i):.2f}" y2="{y(v):.2f}" stroke="{"#116c76" if v>0 else "#b0564f"}" stroke-width="1.5" opacity="0.86"/>']
    lines += ['<text x="555" y="597" text-anchor="middle" font-family="Arial" font-size="15" fill="#465363">Input rank (sorted by cycle saving)</text>',
              '<text x="100" y="123" font-family="Arial" font-size="14" fill="#465363">Saving (millions of Ibex cycles)</text>']
    write_svg(out, lines + svg_end())

def make_figure_exit(items: list[dict], out: Path) -> None:
    groups = defaultdict(list)
    for x in items:
        groups[x["adaptive_exit"]].append(x)
    L, R, T, H = 95, 1035, 150, 415
    maxv = 2800000
    y = lambda v: T + H * (maxv - v) / maxv
    fixed = statistics.mean(x["fixed_mean"] for x in items)
    lines = svg_start("Adaptive cycles by executed exit", "Each bar is the mean across distinct input IDs with that exit; line is fixed Exit 2 mean.")
    for t in [0, 500000, 1000000, 1500000, 2000000, 2500000]:
        yy=y(t);lines += [f'<line x1="{L}" y1="{yy:.1f}" x2="{R}" y2="{yy:.1f}" stroke="#e1e6eb"/>',
                           f'<text x="83" y="{yy+5:.1f}" text-anchor="end" font-family="Arial" font-size="13" fill="#465363">{t/1e6:g}M</text>']
    for j,ex in enumerate(sorted(groups)):
        xs=L+70+j*175; m=statistics.mean(x["adaptive_mean"] for x in groups[ex])
        lines += [f'<rect x="{xs}" y="{y(m):.2f}" width="110" height="{T+H-y(m):.2f}" fill="#196f7b"/>',
                  f'<text x="{xs+55}" y="{y(m)-8:.2f}" text-anchor="middle" font-family="Arial" font-size="14" fill="#193c48">{m/1e6:.3f}M</text>',
                  f'<text x="{xs+55}" y="588" text-anchor="middle" font-family="Arial" font-size="15" fill="#465363">Exit {ex}</text>',
                  f'<text x="{xs+55}" y="608" text-anchor="middle" font-family="Arial" font-size="13" fill="#65717f">n={len(groups[ex])}</text>']
    lines += [f'<line x1="{L}" y1="{y(fixed):.2f}" x2="{R}" y2="{y(fixed):.2f}" stroke="#a74d42" stroke-width="3" stroke-dasharray="9,5"/>',
              f'<text x="{R}" y="{y(fixed)-7:.2f}" text-anchor="end" font-family="Arial" font-size="14" fill="#a74d42">Fixed2 baseline: {fixed:.1f} cycles</text>']
    write_svg(out,lines+svg_end())

def main() -> None:
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--out-dir", required=True, type=Path)
    args=parser.parse_args()
    require(not args.out_dir.exists(), "refusing to overwrite existing output directory")
    aggregate=json.loads((C3V2_DIR/"C3V2_CAMPAIGN_AGGREGATE_AUDIT_20261115.json").read_text(encoding="utf-8"))
    require(aggregate["status"]=="PASS" and aggregate["rows"]==24840 and aggregate["schedule_count"]==13, "aggregate gate incomplete")
    require(aggregate["campaign_sha256"]==CAMPAIGN_SHA and aggregate["all_runs_empirical_only"], "frozen campaign/claim status mismatch")
    require(all(r["build_id"]=="43334531" and r["sof_sha256"]==NEW_SOF and not r["cold_boot_confirmed"] for r in aggregate["runs"]), "mixed identity or cold boot mislabeled")
    require(sum(r["rows"] for r in aggregate["runs"])==24840, "13-schedule count error")
    audit_by_schedule={r["schedule_id"]:r for r in aggregate["runs"]}
    new_runs=[]; old_runs=[]; sessions=[]; five_cycle=Counter()
    for i in range(1,11):
        sid=f"primary_{i:02d}"
        name=f"C3V2_PRIMARY{i:02d}_FULL720_RUN1_20261115"
        new_path=C3V2_DIR/name/"results/c2_jtag_results.csv"
        old_path=C2J2_DIR/f"C3_PRIMARY{i:02d}_FULL720_RUN1_20261114"/("c2_jtag_results.csv" if i==1 else "merged/c2_jtag_results.csv")
        expected=audit_by_schedule[sid]
        require(expected["rows"]==720, f"{sid}: wrong expected rows")
        new=load_rows(new_path,"43334531",NEW_SOF,True,expected["results_csv_sha256"])
        old=load_rows(old_path,"43324a32",OLD_SOF,False)
        for key,n in new.items():
            o=old[key]
            require(n["prediction"]==o["prediction"] and n["executed_exit"]==o["executed_exit"] and n["admitted_exit"]==o["admitted_exit"] and n["reference_label"]==o["reference_label"], "build-to-build prediction/work mismatch")
            five_cycle[dec(n,"cycles")-dec(o,"cycles")]+=1
        new_runs.append(new);old_runs.append(old)
        f=[dec(v,"cycles") for (idx,mode),v in new.items() if mode==1]
        a=[dec(v,"cycles") for (idx,mode),v in new.items() if mode==3]
        sessions.append({"schedule":sid,"rows":720,"fixed2_mean_cycles":statistics.mean(f),"adaptive_mean_cycles":statistics.mean(a),
                         "cycle_saving_mean":statistics.mean(f)-statistics.mean(a),"source_csv_sha256":sha(new_path)})
    ids=[]
    for idx in range(360):
        fr=[dec(run[idx,1],"cycles") for run in new_runs]
        ar=[dec(run[idx,3],"cycles") for run in new_runs]
        f=new_runs[0][idx,1]; a=new_runs[0][idx,3]
        require(all(run[idx,1]["prediction"]==f["prediction"] and run[idx,3]["prediction"]==a["prediction"] for run in new_runs), "prediction varies over schedules")
        require(all(run[idx,3]["executed_exit"]==a["executed_exit"] for run in new_runs), "adaptive exit varies over schedules")
        ids.append({"input_id":idx,"fixed_mean":statistics.mean(fr),"adaptive_mean":statistics.mean(ar),
                    "saving_cycles":statistics.mean(fr)-statistics.mean(ar),
                    "fixed_prediction":dec(f,"prediction"),"adaptive_prediction":dec(a,"prediction"),
                    "reference_label":dec(f,"reference_label"),"adaptive_exit":dec(a,"executed_exit"),
                    "fixed_correct":int(f["prediction"]==f["reference_label"]),
                    "adaptive_correct":int(a["prediction"]==a["reference_label"]),
                    "identical_cycles_all_10":len(set(fr))==1 and len(set(ar))==1})
    fmean=statistics.mean(x["fixed_mean"] for x in ids)
    amean=statistics.mean(x["adaptive_mean"] for x in ids)
    acc={"both_correct":0,"fixed_only_correct":0,"adaptive_only_correct":0,"both_wrong":0}
    for x in ids:
        k="both_correct" if x["fixed_correct"] and x["adaptive_correct"] else ("fixed_only_correct" if x["fixed_correct"] else ("adaptive_only_correct" if x["adaptive_correct"] else "both_wrong"))
        acc[k]+=1
    exits={str(ex):{"unique_inputs":sum(x["adaptive_exit"]==ex for x in ids),
                    "mean_adaptive_cycles":statistics.mean(x["adaptive_mean"] for x in ids if x["adaptive_exit"]==ex)}
           for ex in sorted({x["adaptive_exit"] for x in ids})}
    report={
        "schema":"rtnn-c3v2-paper-analysis-v1",
        "analysis_kind":"saved FPGA experimental data; no new JTAG or Quartus run",
        "source_branch":"codex/stage-c3-jtag-pilot-20261114",
        "source_build":{"c3v2_build_id":"43334531","c3v2_sof_sha256":NEW_SOF,"c2j2_build_id":"43324a32","c2j2_sof_sha256":OLD_SOF},
        "source_frozen_campaign_sha256":CAMPAIGN_SHA,
        "board":"Terasic DE0-CV, Cyclone V 5CEBA4F23C7N, Ibex mcycle counter",
        "planned_full_campaign":{"schedules":13,"rows":24840,"status":"PASS_SAVED_EVIDENCE_EMPIRICAL_ONLY"},
        "primary":{"schedules":10,"unique_inputs":360,"pairs":3600,"rows":7200,"all_inputs_identical_cycle_counts_in_10_schedules":sum(x["identical_cycles_all_10"] for x in ids),
                   "fixed2_mean_cycles":fmean,"adaptive_mean_cycles":amean,"fixed2_minus_adaptive_mean_cycles":fmean-amean,
                   "mean_cycle_reduction_percent":100*(fmean-amean)/fmean,
                   "adaptive_faster_input_ids":sum(x["saving_cycles"]>0 for x in ids),
                   "adaptive_slower_input_ids":sum(x["saving_cycles"]<0 for x in ids),
                   "bootstrap_input_only":bootstrap(ids)},
        "accuracy":{"fixed2_correct":sum(x["fixed_correct"] for x in ids),"adaptive_correct":sum(x["adaptive_correct"] for x in ids),
                    "paired_contingency":acc,"bootstrap_input_only":accuracy_bootstrap(ids),
                    "noninferiority_margin_percentage_points":1.0,"noninferiority_decision":"INCONCLUSIVE"},
        "adaptive_executed_exit_by_input":exits,
        "c2j2_to_c3v2":{"paired_rows":sum(five_cycle.values()),"delta_mcycle_histogram":dict(sorted(five_cycle.items())),
                       "functional_mismatches":0,"interpretation":"observational constant counter offset; compiler/measurement-boundary attribution not proven"},
        "data_limitations":["one board; independent cold boot not verified","ten schedule repeats are not independent power sessions",
                            "95% bootstrap intervals cover input sampling only, not board/build/power-session uncertainty",
                            "FPGA external JTAG I/O timing not signed off; 16 D102 CDC warnings retained",
                            "cycle counts are not calibrated seconds or WCET bounds","1 percentage-point accuracy noninferiority not established"],
        "session_summary":sessions
    }
    args.out_dir.mkdir(parents=True,exist_ok=False)
    out=args.out_dir
    (out/"analysis.json").write_text(json.dumps(report,ensure_ascii=False,indent=2,sort_keys=True)+"\n",encoding="utf-8")
    with (out/"input_level.csv").open("w",newline="",encoding="utf-8") as f:
        writer=csv.DictWriter(f,fieldnames=list(ids[0]),lineterminator="\n");writer.writeheader();writer.writerows(ids)
    with (out/"primary_sessions.csv").open("w",newline="",encoding="utf-8") as f:
        writer=csv.DictWriter(f,fieldnames=list(sessions[0]),lineterminator="\n");writer.writeheader();writer.writerows(sessions)
    make_figure_paired(ids,out/"figure_01_paired_cycle_saving.svg")
    make_figure_exit(ids,out/"figure_02_exit_cycles.svg")
    files=sorted(p for p in out.iterdir() if p.is_file())
    (out/"SHA256SUMS.txt").write_text("".join(f"{sha(p)}  {p.name}\n" for p in files),encoding="utf-8")
    print(f"PASS: C3v2 13/13 24840 rows; primary 360 IDs x 10; +5 cycle shift {sum(five_cycle.values())} pairs; output {out}")
    print(json.dumps({"fixed2":fmean,"adaptive":amean,"saving":fmean-amean,"reduction_percent":100*(fmean-amean)/fmean,
                      "bootstrap_ci_percent":report["primary"]["bootstrap_input_only"]["reduction_percent_95pct_ci"],
                      "accuracy":acc,"all_10_identical":report["primary"]["all_inputs_identical_cycle_counts_in_10_schedules"]},indent=2))
if __name__=="__main__":
    main()
