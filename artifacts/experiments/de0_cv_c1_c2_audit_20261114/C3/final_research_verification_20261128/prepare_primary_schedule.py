#!/usr/bin/env python3
"""Create an offline-only primary schedule; this does not create a physical binding."""
import argparse,csv,hashlib,json
from pathlib import Path
from audit_primary import PKG,audit_schedule,fsha,rcsv
def main():
 ap=argparse.ArgumentParser()
 ap.add_argument("--package",type=Path,default=PKG)
 ap.add_argument("--source-cases",type=Path)
 ap.add_argument("--out",type=Path,required=True)
 ap.add_argument("--experiment-id",default="OFFLINE_PREPARATION_ONLY_20261128")
 ap.add_argument("--session-id",default="OFFLINE_NOT_A_POWER_SESSION")
 ap.add_argument("--sequence-start",type=int,default=22)
 a=ap.parse_args()
 source=a.source_cases or a.package/"build/host_cases_primary_attempt2/cases.csv"
 audit_schedule(rcsv(source),a.package,1)
 rows=rcsv(source)
 for i,r in enumerate(rows):
  r["experiment_id"]=a.experiment_id;r["session_id"]=a.session_id;r["sequence"]=str(a.sequence_start+i)
 audit_schedule(rows,a.package,a.sequence_start)
 if a.out.exists(): raise SystemExit("refusing existing output")
 a.out.parent.mkdir(parents=True,exist_ok=True)
 with a.out.open("w",encoding="utf-8",newline="") as f:
  w=csv.DictWriter(f,fieldnames=list(rows[0]),lineterminator="\n");w.writeheader();w.writerows(rows)
 meta={"schema":"rtnn-extval-primary-offline-preparation-v1","classification":"NOT_PHYSICAL_NOT_BOUND",
       "experiment_id":a.experiment_id,"session_id":a.session_id,"rows":len(rows),
       "sequence_first":a.sequence_start,"sequence_last":a.sequence_start+len(rows)-1,
       "source_cases_sha256":fsha(source),"prepared_cases_sha256":fsha(a.out),
       "frozen_input_mode_order_preserved":True,"highest_recorded_pilot_sequence":21,
       "sequence_reuse_avoided":a.sequence_start>21,"binding_created":False,"physical_authorized":False}
 mp=a.out.with_suffix(".metadata.json")
 if mp.exists(): raise SystemExit("refusing existing metadata output")
 mp.write_text(json.dumps(meta,indent=2)+"\n",encoding="utf-8")
 print(json.dumps(meta,indent=2))
if __name__=="__main__":main()
