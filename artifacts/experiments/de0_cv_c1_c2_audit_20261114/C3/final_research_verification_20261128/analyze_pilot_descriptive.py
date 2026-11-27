#!/usr/bin/env python3
"""Read-only descriptive reanalysis; output is explicitly pilot-only."""
import argparse,csv,json,statistics
from pathlib import Path
def analyze(path):
 with Path(path).open(encoding="utf-8-sig",newline="") as f:rows=list(csv.DictReader(f))
 if len(rows)!=20 or any(r.get("status")!="PASS" for r in rows):raise ValueError("requires exactly 20 saved PASS rows")
 fixed={r["input_id"]:r for r in rows if r["mode"]=="fixed2"};adaptive={r["input_id"]:r for r in rows if r["mode"]=="adaptive"}
 if len(fixed)!=10 or len(adaptive)!=10 or set(fixed)!=set(adaptive):raise ValueError("pilot input pairing incomplete")
 if len({r["experiment_id"] for r in rows})!=1 or len({r["session_id"] for r in rows})!=1:raise ValueError("mixed pilot identities")
 paired=[]
 for iid in sorted(fixed,key=int):
  f,a=fixed[iid],adaptive[iid];fc,ac=int(f["cycles"]),int(a["cycles"])
  if fc<=0 or ac<=0:raise ValueError("nonpositive cycle count")
  if f["prediction"]!=f["reference_prediction"] or a["prediction"]!=a["reference_prediction"]:raise ValueError("Q15 reference mismatch")
  paired.append({"input_id":int(iid),"fixed2_cycles":fc,"adaptive_cycles":ac,"adaptive_minus_fixed2_cycles":ac-fc,"fixed2_teacher_correct":f["prediction"]==f["teacher_label"],"adaptive_teacher_correct":a["prediction"]==a["teacher_label"]})
 fc=[x["fixed2_cycles"] for x in paired];ac=[x["adaptive_cycles"] for x in paired];saving=(sum(fc)-sum(ac))/sum(fc)
 return {"classification":"ENGINEERING_PILOT_DESCRIPTIVE_ONLY","experiment_id":rows[0]["experiment_id"],"session_id":rows[0]["session_id"],"case_count":20,"image_count":10,"cycles":{"fixed2_mean":statistics.mean(fc),"fixed2_median":statistics.median(fc),"adaptive_mean":statistics.mean(ac),"adaptive_median":statistics.median(ac),"paired_ratio_of_sums_saving":saving},"paired_teacher_correct":{"fixed2":sum(x["fixed2_teacher_correct"] for x in paired),"adaptive":sum(x["adaptive_teacher_correct"] for x in paired)},"adaptive_faster_count":sum(x["adaptive_minus_fixed2_cycles"]<0 for x in paired),"adaptive_slower_input_ids":[x["input_id"] for x in paired if x["adaptive_minus_fixed2_cycles"]>0],"paired":paired,"limitations":["Selected 10-image engineering pilot only; no population estimate.","One continuous board power epoch; cold boot independence unverified.","No noninferiority or general speed superiority claim.","Empirical consistency is not a proof of physical acquisition or formal timing."]}
def main():
 ap=argparse.ArgumentParser();ap.add_argument("--results",type=Path,required=True);ap.add_argument("--out",type=Path,required=True);a=ap.parse_args()
 if a.out.exists():raise SystemExit("refusing to overwrite output")
 obj=analyze(a.results);a.out.parent.mkdir(parents=True,exist_ok=True);a.out.write_text(json.dumps(obj,indent=2)+"\n",encoding="utf-8");print(json.dumps({k:v for k,v in obj.items() if k!="paired"},indent=2))
if __name__=="__main__":main()
