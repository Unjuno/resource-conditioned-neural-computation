#!/usr/bin/env python3
"""Analyze only a run that passes the independent raw-JTAG audit."""
import argparse,csv,json,statistics,sys
from pathlib import Path
PKG=Path(__file__).resolve().parents[1]/"external_validation_20261122"
sys.path.insert(0,str(Path(__file__).resolve().parent));sys.path.insert(0,str(PKG/"scripts"))
from audit_primary import audit_run
from stats_core import paired_ni_lower,paired_cycle_bootstrap
def summarize(run,draws=10000,seed=20261122):
 audit=audit_run(run,PKG)
 with (Path(run)/"physical_results.csv").open(encoding="utf-8-sig",newline="") as f:rows=list(csv.DictReader(f))
 by={(r["input_id"],r["mode"]):r for r in rows}
 if len(by)!=7626:raise ValueError("paired result keys incomplete/duplicated")
 ordered=sorted({r["input_id"] for r in rows},key=int)
 fixed=[by[(i,"fixed2")] for i in ordered];adapt=[by[(i,"adaptive")] for i in ordered]
 fc=[int(r["cycles"]) for r in fixed];ac=[int(r["cycles"]) for r in adapt]
 fy=[int(r["prediction"])==int(r["teacher_label"]) for r in fixed];ay=[int(r["prediction"])==int(r["teacher_label"]) for r in adapt]
 ni=paired_ni_lower([int(x) for x in fy],[int(x) for x in ay])
 cyc=paired_cycle_bootstrap(fc,ac,draws=draws,seed=seed)
 return {"schema":"rtnn-audited-primary-analysis-v1","classification":"EXPLORATORY_EMPIRICAL_ONLY","audit":audit,"input_count":len(ordered),"teacher_label_accuracy":{"fixed2_correct":sum(fy),"adaptive_correct":sum(ay),"paired_noninferiority_numeric":ni,"interpretation":"numeric bound only; writer dependence and data exposure eligibility remain unresolved"},"cycles":cyc,"adaptive_slower_inputs":sum(a>f for f,a in zip(fc,ac)),"session_count":1,"session_variation":"NOT_ESTIMABLE_FROM_ONE_SESSION","population_inference_eligibility":"INELIGIBLE_DATA_EXPOSURE_WRITER_CLUSTER_UNKNOWN","power_session_evidence":"COLD_BOOT_UNVERIFIED","formal_timing_signoff":"BLOCKED_EXTERNAL_BOARD_TIMING","limitations":["Teacher labels are distinct from CPU Q15 implementation references; audit checks the latter.","Numeric paired intervals do not establish population inference without independent-image assumptions.","One primary session cannot estimate between-session variability.","No WCET/hard-deadline or general physical timing claim."]}
def main():
 ap=argparse.ArgumentParser();ap.add_argument("--run-dir",type=Path,required=True);ap.add_argument("--out",type=Path,required=True);a=ap.parse_args()
 if a.out.exists():raise SystemExit("refusing to overwrite output")
 x=summarize(a.run_dir);a.out.parent.mkdir(parents=True,exist_ok=True);a.out.write_text(json.dumps(x,indent=2)+"\n",encoding="utf-8");print(json.dumps({k:v for k,v in x.items() if k not in ("audit","teacher_label_accuracy","cycles")},indent=2))
if __name__=="__main__":main()
