#!/usr/bin/env python3
"""Frozen diagnostic resource-budget analysis from saved C3 v2 physical CSVs.

Does not alter original data or reclassify exploratory comparisons as primary.
All budget modes run on one DE0-CV build and an unverified power session.
Requires Python 3.10+ standard library.
"""
from __future__ import annotations
import argparse
import csv
import hashlib
import json
import statistics
from collections import Counter, defaultdict
from pathlib import Path
from reanalyze_c3v2_primary import C3V2_DIR, C3, CAMPAIGN_SHA, NEW_SOF, MODEL_ID, require, sha, validate_row, svg_start, svg_end, write_svg

MATRIX = C3 / "frozen_inputs/paper/campaign/schedules"
GROUPS = [
    ("diagnostic_fixed", "C3V2_DIAGFIXED_FULL2520_RUN2_20261115", 2520, 1),
    ("diagnostic_adaptive", "C3V2_DIAGADAPTIVE_FULL7560_RUN1_20261115", 7560, 3),
    ("diagnostic_capped", "C3V2_DIAGCAPPED_FULL7560_RUN1_20261115", 7560, 2),
]

def rows(path: Path) -> list[dict]:
    with path.open(encoding="utf-8-sig", newline="") as fh:
        reader = csv.DictReader(fh)
        require(reader.fieldnames and len(set(reader.fieldnames)) == len(reader.fieldnames), "CSV headers invalid")
        return list(reader)

def load_diagnostic(schedule: str, folder: str, expected: int, mode: int, aggregate_entry: dict) -> tuple[dict, list[dict]]:
    frozen_path = MATRIX / f"{schedule}.json"
    frozen = json.loads(frozen_path.read_text(encoding="utf-8"))
    require(len(frozen["rows"]) == expected and frozen["record_count"] == expected, "frozen row count")
    exp = {int(x["seq"]): x for x in frozen["rows"]}
    require(len(exp) == expected, "duplicate frozen sequence")
    out = C3V2_DIR / folder
    result_path = out / "results/c2_jtag_results.csv"
    cases_path = out / "input/cases.csv"
    require(sha(result_path) == aggregate_entry["results_csv_sha256"],"result sha differs from saved audit")
    require(sha(cases_path) == aggregate_entry["cases_sha256"],"cases sha differs from saved audit")
    result, cases = rows(result_path), rows(cases_path)
    require(len(result) == len(cases) == expected, "result/cases rows mismatch")
    require(all(r["schedule_canonical_sha256"] == frozen["schedule_sha256"] for r in result), "frozen schedule digest mismatch")
    by_case={int(x["seq"]):x for x in cases}
    require(set(by_case)==set(exp),"case sequences differ from frozen matrix")
    seen=set()
    enriched=[]
    for row in result:
        require(row["case_status"]=="PASS" and row["cycle_valid"]=="1" and row["response_crc_valid"]=="1","failed row")
        require(row["build_id"]=="43334531" and row["response_build_id"]=="43334531" and row["sof_sha256"]==NEW_SOF,"build or SOF mismatch")
        require(row["campaign_canonical_sha256"]==CAMPAIGN_SHA,"campaign mismatch")
        require(row["response_model_id"]==MODEL_ID and row["response_binding_id"]=="43334531","response identity mismatch")
        require(row["counter_status"]=="0" and row["response_flags"]=="1","counter status mismatch")
        seq=int(row["seq"])
        require(seq not in seen and seq in exp,"duplicate/unknown seq");seen.add(seq)
        case=by_case[seq];f=exp[seq]
        for key in ("input_id","mode","budget_q16","fixed_exit","deadline_cycles"):
            require(int(case[key])==int(f[key]),f"case versus frozen {key} mismatch")
        for key in ("input_id","mode"):
            require(int(row[key])==int(f[key]),f"response {key} mismatch")
        require(int(row["mode"])==mode,"wrong mode")
        require(int(row["response_seq"])==seq and int(row["response_input_id"])==int(f["input_id"]) and int(row["response_mode"])==mode,"response identity invalid")
        require(int(row["prediction"])==int(row["expected_prediction"]) and int(row["executed_exit"])==int(row["expected_executed"]) and int(row["admitted_exit"])==int(row["expected_admitted"]),"reference mismatch")
        start,end=int(row["cycles_start"]),int(row["cycles_end"])
        require(0<=start<end<2**64 and end-start==int(row["cycles"])==int(row["reported_cycles"]),"mcycle delta invalid")
        require(int(row["executed_exit"])<=int(row["admitted_exit"]),"cap violation")
        enriched.append({
            "input_id":int(row["input_id"]), "budget_q16":int(case["budget_q16"]), "fixed_exit":int(case["fixed_exit"]),
            "executed_exit":int(row["executed_exit"]), "admitted_exit":int(row["admitted_exit"]),
            "prediction":int(row["prediction"]), "label":int(row["reference_label"]), "cycles":int(row["cycles"]),
            "mode":mode, "schedule":schedule
        })
    require(len(seen)==expected,"missing sequences")
    return {"schedule":schedule, "file":str(result_path.relative_to(C3)), "rows":expected,
            "csv_sha256":sha(result_path)}, enriched

def summary(group: list[dict], kind: str, budget: int) -> dict:
    require(len(group)==360 and {x["input_id"] for x in group}==set(range(360)),f"missing unique IDs for {kind} / {budget}")
    d={"kind":kind,"fixed_exit":budget if kind=="diagnostic_fixed" else None,
       "budget_q16":None if kind=="diagnostic_fixed" else budget,
       "budget_fraction":None if kind=="diagnostic_fixed" else budget/65535,
       "rows":len(group),"mean_cycles":statistics.mean(x["cycles"] for x in group),
       "median_cycles":statistics.median(x["cycles"] for x in group),
       "correct":sum(x["prediction"]==x["label"] for x in group),
       "accuracy_percent":100*sum(x["prediction"]==x["label"] for x in group)/len(group),
       "mean_executed_exit":statistics.mean(x["executed_exit"] for x in group),
       "exit_distribution":dict(sorted(Counter(x["executed_exit"] for x in group).items()))}
    return d

def budget_svg(budget_lines: list[dict], outfile: Path) -> None:
    left, right, top, height = 106, 1000, 152, 388
    ymax=3e6
    x=lambda b:left+(right-left)*b/65535
    y=lambda v:top+height*(1-v/ymax)
    line=svg_start("Resource-budget diagnostics on C3 v2", "21 frozen Q0.16 budgets x 360 inputs per mode; mean observed FPGA mcycle, no cold-boot independence.")
    for val in [0,500000,1000000,1500000,2000000,2500000,3000000]:
        yy=y(val)
        line += [f'<line x1="{left}" x2="{right}" y1="{yy:.2f}" y2="{yy:.2f}" stroke="#dfe4e9"/>',
                 f'<text x="{left-12}" y="{yy+5:.2f}" text-anchor="end" font-family="Arial" font-size="14" fill="#475462">{val/1e6:.1f}M</text>']
    for mode,color in [("diagnostic_adaptive","#11747c"),("diagnostic_capped","#bb6747")]:
        pairs=sorted((z for z in budget_lines if z["kind"]==mode),key=lambda t:t["budget_q16"])
        points=" ".join(f'{x(p["budget_q16"]):.2f},{y(p["mean_cycles"]):.2f}' for p in pairs)
        line += [f'<polyline points="{points}" fill="none" stroke="{color}" stroke-width="4" stroke-linecap="round"/>']
        for p in pairs:
            line += [f'<circle cx="{x(p["budget_q16"]):.2f}" cy="{y(p["mean_cycles"]):.2f}" r="3.3" fill="{color}"/>']
    for frac in [0,.2,.4,.6,.8,1]:
        xx=left+(right-left)*frac
        line += [f'<text x="{xx:.2f}" y="{top+height+27}" text-anchor="middle" font-family="Arial" font-size="14" fill="#465363">{frac:.1f}</text>']
    line += [
      '<text x="552" y="606" text-anchor="middle" font-family="Arial" font-size="16" fill="#465363">Normalized admitted budget (Q0.16 / 65535)</text>',
      '<rect x="680" y="105" width="20" height="5" fill="#11747c"/><text x="707" y="112" font-family="Arial" font-size="15" fill="#465363">adaptive</text>',
      '<rect x="820" y="105" width="20" height="5" fill="#bb6747"/><text x="847" y="112" font-family="Arial" font-size="15" fill="#465363">capped</text>']
    write_svg(outfile,line+svg_end())

def main() -> None:
    ap=argparse.ArgumentParser()
    ap.add_argument("--out-dir",type=Path,required=True)
    args=ap.parse_args()
    require(not args.out_dir.exists(), "refusing to overwrite output")
    ag=json.loads((C3V2_DIR/"C3V2_CAMPAIGN_AGGREGATE_AUDIT_20261115.json").read_text())
    require(ag["status"]=="PASS" and ag["schedule_count"]==13 and ag["rows"]==24840,"aggregate status mismatch")
    meta={x["schedule_id"]:x for x in ag["runs"]}
    all_records, files=[],[]
    for schedule,folder,n,mode in GROUPS:
        file_info, rec=load_diagnostic(schedule,folder,n,mode,meta[schedule])
        all_records.extend(rec);files.append(file_info)
    require(len(all_records)==17640,"diagnostic total rows mismatch")
    require(all(x["label"] in range(10) and x["prediction"] in range(10) for x in all_records),"labels out of range")
    by_kind=defaultdict(list)
    for r in all_records:
        by_kind[r["schedule"]].append(r)
    fixed=by_kind["diagnostic_fixed"]
    fixed_byexit={e:[x for x in fixed if x["fixed_exit"]==e] for e in range(7)}
    fixed_summary=[summary(records,"diagnostic_fixed",e) for e,records in fixed_byexit.items()]
    detail=[]
    for kind in ("diagnostic_adaptive","diagnostic_capped"):
        bset=sorted({r["budget_q16"] for r in by_kind[kind]})
        require(len(bset)==21 and bset[0]==0 and bset[-1]==65535,"budget grid mismatch")
        for b in bset:
            detail.append(summary([z for z in by_kind[kind] if z["budget_q16"]==b],kind,b))
    # All expected paired mode/budget cases exactly once
    for kind in ("diagnostic_adaptive","diagnostic_capped"):
        grid=Counter((r["input_id"],r["budget_q16"]) for r in by_kind[kind])
        require(len(grid)==360*21 and all(v==1 for v in grid.values()),"duplicate/missing budget input pairs")
    report={
      "schema":"rtnn-c3v2-diagnostic-budget-analysis-v1",
      "classification":"SECONDARY_DIAGNOSTIC_EMPIRICAL_ONLY",
      "source_build":"43334531","source_sof_sha256":NEW_SOF,
      "source_campaign_sha256":CAMPAIGN_SHA,
      "diagnostic_rows":17640,"unique_input_ids":360,
      "diagnostic_schedules":files,
      "fixed_exit_levels":fixed_summary,
      "budget_grid":detail,
      "interpretation":"budget sweep measured on same board and power-session context; descriptive secondary analyses only; no independent deadlines, cold boots or WCET guarantees"
    }
    args.out_dir.mkdir(parents=True)
    (args.out_dir/"analysis.json").write_text(json.dumps(report,indent=2,ensure_ascii=False,sort_keys=True)+"\n",encoding="utf-8")
    with (args.out_dir/"budget_summary.csv").open("w",encoding="utf-8",newline="") as file:
        cols=["kind","fixed_exit","budget_q16","budget_fraction","rows","mean_cycles","median_cycles","correct","accuracy_percent","mean_executed_exit","exit_distribution"]
        writer=csv.DictWriter(file,fieldnames=cols,lineterminator="\n")
        writer.writeheader()
        for row in fixed_summary+detail:
            record={k:row[k] for k in cols}
            record["exit_distribution"]=json.dumps(record["exit_distribution"],sort_keys=True)
            writer.writerow(record)
    budget_svg(detail,args.out_dir/"figure_03_budget_vs_cycles.svg")
    outs=sorted(p for p in args.out_dir.iterdir() if p.is_file())
    (args.out_dir/"SHA256SUMS.txt").write_text("".join(f"{sha(p)}  {p.name}\n" for p in outs),encoding="utf-8")
    print("PASS diagnostic_fixed=2520 diagnostic_adaptive=7560 diagnostic_capped=7560, 21 budgets, 360 unique IDs, 0 status/identity/cycle/cap exceptions")
    for k in ("diagnostic_adaptive","diagnostic_capped"):
        vals=sorted((x for x in detail if x["kind"]==k),key=lambda x:x["budget_q16"])
        print(k,"lowest/mid/high",[(v["budget_q16"],round(v["mean_cycles"],2),v["correct"],round(v["mean_executed_exit"],3)) for v in [vals[0],vals[10],vals[-1]]])

if __name__=="__main__":
    main()
