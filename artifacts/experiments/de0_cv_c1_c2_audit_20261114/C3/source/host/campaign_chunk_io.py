#!/usr/bin/env python3
"""Split and aggregate campaign session CSV/JTAG artifacts without row edits."""
from __future__ import annotations
import argparse,csv,hashlib,json
from pathlib import Path

def sha(p:Path)->str:return hashlib.sha256(p.read_bytes()).hexdigest()
def split(a):
    rows=list(csv.DictReader(a.cases.open(newline="",encoding="utf-8-sig")))
    if not rows:raise ValueError("empty case file")
    if a.out.exists():raise ValueError(f"refusing to overwrite {a.out}")
    seqs=[int(r["seq"]) for r in rows]
    if seqs!=list(range(1,len(rows)+1)):raise ValueError("case sequences must be complete and ordered from 1")
    a.out.mkdir(parents=True)
    items=[]
    names=list(rows[0])
    for start in range(0,len(rows),a.chunk_size):
        group=rows[start:start+a.chunk_size]; index=start//a.chunk_size+1
        folder=a.out/f"chunk_{index:04d}"; inp=folder/"input"; result=folder/"results"; inp.mkdir(parents=True);result.mkdir()
        cf=inp/"cases.csv"
        with cf.open("w",newline="",encoding="utf-8") as f:
            w=csv.DictWriter(f,fieldnames=names,lineterminator="\n");w.writeheader();w.writerows(group)
        item={"index":index,"count":len(group),"first_seq":int(group[0]["seq"]),"last_seq":int(group[-1]["seq"]),"sequences":",".join(r["seq"] for r in group),"case_file":str(cf.relative_to(a.out)).replace("\\","/"),"case_sha256":sha(cf),"result_dir":str(result.relative_to(a.out)).replace("\\","/")}
        items.append(item)
    manifest={"schema":"rtnn-c3-campaign-chunks-v1","full_cases_sha256":sha(a.cases),"full_row_count":len(rows),"chunk_size":a.chunk_size,"chunks":items}
    (a.out/"chunks.json").write_text(json.dumps(manifest,indent=2)+"\n",encoding="utf-8")
    print(json.dumps({"status":"PASS_SPLIT","rows":len(rows),"chunks":len(items),"full_cases_sha256":manifest["full_cases_sha256"]},indent=2))

def aggregate(a):
    chunks=json.loads((a.chunks/"chunks.json").read_text(encoding="utf-8")); csv_rows=[]; raw_lines=[]; reports=[]; failures=[]
    for c in chunks["chunks"]:
        d=a.chunks/c["result_dir"]; rp=d/"c2_jtag_results.json"; cp=d/"c2_jtag_results.csv"; lp=d/"c2_jtag_raw.log"
        if not (rp.is_file() and cp.is_file() and lp.is_file()):failures.append(f"chunk {c['index']}: missing one or more result files");continue
        try:r=json.loads(rp.read_text(encoding="utf-8-sig"))
        except Exception as e:failures.append(f"chunk {c['index']}: invalid JSON: {e}");continue
        reports.append(r)
        if r.get("status")!="PASS" or r.get("expected_count")!=c["count"] or r.get("completed_count")!=c["count"]:failures.append(f"chunk {c['index']}: runner status/count failure")
        if r.get("selected_sequences")!=[int(x) for x in c["sequences"].split(",")]:failures.append(f"chunk {c['index']}: sequence list mismatch")
        with cp.open(newline="",encoding="utf-8-sig") as f:
            rr=list(csv.DictReader(f))
            if not csv_rows:csv_rows.append(list(rr[0].keys()) if rr else [])
            csv_rows.extend([[x[k] for k in csv_rows[0]] for x in rr])
        raw_lines.extend(lp.read_text(encoding="utf-8-sig").splitlines())
    if a.out.exists():raise ValueError(f"refusing to overwrite {a.out}")
    a.out.mkdir(parents=True)
    if not csv_rows:raise ValueError("no chunk result CSV rows")
    with (a.out/"c2_jtag_results.csv").open("w",newline="",encoding="utf-8") as f:
        w=csv.writer(f,lineterminator="\n");w.writerow(csv_rows[0]);w.writerows(csv_rows[1:])
    (a.out/"c2_jtag_raw.log").write_text("\n".join(raw_lines)+"\n",encoding="utf-8")
    cases=[]; selections=[]
    for r in reports:cases.extend(r.get("cases",[]));selections.extend(r.get("selected_sequences",[]))
    complete=(not failures and len(reports)==len(chunks["chunks"]) and len(cases)==chunks["full_row_count"] and selections==list(range(1,chunks["full_row_count"]+1)))
    first=reports[0] if reports else {}
    report={"schema":"rtnn-c2-jtag-results-v2","experiment_id":first.get("experiment_id",""),"sof_sha256":first.get("sof_sha256",""),"build_id":first.get("build_id",""),"cycle_source":"Ibex mcycle delta read from FPGA via Virtual-JTAG","uart":False,"flash_written":False,"status":"PASS" if complete else "FAIL","count":len(cases),"completed_count":sum(int(r.get("completed_count",0)) for r in reports),"expected_count":chunks["full_row_count"],"selected_sequences":selections,"scope":"subset","cases":cases,"chunk_count":len(chunks["chunks"]),"chunk_failures":failures}
    (a.out/"c2_jtag_results.json").write_text(json.dumps(report,indent=2)+"\n",encoding="utf-8")
    print(json.dumps({"status":"PASS_AGGREGATE" if complete else "FAIL_AGGREGATE","rows":len(cases),"chunks":len(reports),"failures":failures},indent=2))
    return 0 if complete else 1

def main():
    p=argparse.ArgumentParser();s=p.add_subparsers(dest="cmd",required=True)
    q=s.add_parser("split");q.add_argument("--cases",type=Path,required=True);q.add_argument("--out",type=Path,required=True);q.add_argument("--chunk-size",type=int,default=400)
    q=s.add_parser("aggregate");q.add_argument("--chunks",type=Path,required=True);q.add_argument("--out",type=Path,required=True)
    a=p.parse_args()
    if a.cmd=="split":
        if a.chunk_size<1 or a.chunk_size>1000:p.error("chunk size must be 1..1000")
        split(a);return 0
    return aggregate(a)
if __name__=="__main__":raise SystemExit(main())
