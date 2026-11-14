#!/usr/bin/env python3
"""Create immutable physical bindings for all frozen schedules for C3 v2 SOF.

This prepares inputs only. It does not start Quartus STP or label any physical
campaign row as measured. The ten-input/reset pilot remains the run gate.
"""
from __future__ import annotations
import argparse, csv, hashlib, json, shutil
from pathlib import Path

CAMPAIGN = "d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc"
SOF = "85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d"
BUILD = "43334531"
EXPECTED = {
    "diagnostic_fixed": (2520, {"1":2520}),
    "diagnostic_adaptive": (7560, {"3":7560}),
    "diagnostic_capped": (7560, {"2":7560}),
    **{f"primary_{i:02d}": (720, {"1":360,"3":360}) for i in range(1,11)},
}

def sha(p: Path) -> str: return hashlib.sha256(p.read_bytes()).hexdigest()
def main() -> int:
    ap=argparse.ArgumentParser()
    ap.add_argument("--dryrun-root",type=Path,required=True)
    ap.add_argument("--out",type=Path,required=True)
    a=ap.parse_args()
    if a.out.exists(): raise SystemExit(f"refuse existing output: {a.out}")
    a.out.mkdir(parents=True)
    sessions=[]
    for name,(want_count,want_modes) in EXPECTED.items():
        src=a.dryrun_root/name
        case_src=src/"cases.csv"; bind_src=src/"binding.json"
        if not case_src.is_file() or not bind_src.is_file(): raise SystemExit(f"missing frozen host prep for {name}")
        binding=json.loads(bind_src.read_text(encoding="utf-8-sig"))
        if binding.get("session_id")!=name or binding.get("build_id")!=BUILD or binding.get("binding_id")!=BUILD:
            raise SystemExit(f"binding identity mismatch: {name}")
        if binding.get("campaign_canonical_sha256")!=CAMPAIGN or binding.get("frozen_schedule_modified") is not False:
            raise SystemExit(f"campaign/schedule freeze mismatch: {name}")
        if binding.get("sof_sha256") is not None or binding.get("measurement_eligible") is not False:
            raise SystemExit(f"input is not original unbound host dry-run: {name}")
        if sha(case_src)!=binding.get("case_csv_sha256"): raise SystemExit(f"case CSV SHA mismatch: {name}")
        rows=list(csv.DictReader(case_src.open(newline="",encoding="utf-8-sig")))
        modes={}
        ids=set()
        for row in rows:
            modes[row["mode"]]=modes.get(row["mode"],0)+1
            ids.add(int(row["input_id"]))
            if row["build_id"].lower()!=BUILD or row["binding_id"].lower()!=BUILD or row["model_id"].lower()!="52544e4e":
                raise SystemExit(f"row build/model/binding mismatch: {name}/{row['seq']}")
        if len(rows)!=want_count or modes!=want_modes or len(ids)!=360:
            raise SystemExit(f"frozen schedule shape mismatch: {name}: rows={len(rows)}, modes={modes}, ids={len(ids)}")
        dst=a.out/name; dst.mkdir()
        case_dst=dst/"cases.csv"; shutil.copyfile(case_src,case_dst)
        binding["sof_sha256"]=SOF
        binding["sof_binding_status"]="C3_V2_QUARTUS_SOF_SHA_BOUND_NOT_PROGRAMMED_OR_CAMPAIGN_NOT_STARTED"
        binding["measurement_eligible"]=True
        binding["eligibility_basis"]="B_EMPIRICAL_PASS_LIMITED_C3_V2_SINGLE_BOARD_PILOT_ONLY"
        binding["campaign_start_gate"]="WAIT_FOR_TEN_INPUT_KEY_RESET_REPLAY_PASS"
        binding["physical_run_status"]="NOT_RUN"
        binding["physical_cycles_present"]=False
        binding["timing_classification"]="EMPIRICAL_ONLY"
        binding["wcet_or_hard_deadline_claimed"]=False
        binding["case_csv_sha256"]=sha(case_dst)
        bind_dst=dst/"binding.json"; bind_dst.write_text(json.dumps(binding,indent=2)+"\n",encoding="utf-8")
        sessions.append({"session_id":name,"rows":len(rows),"modes":modes,"unique_input_ids":len(ids),"schedule_sha256":binding["schedule_canonical_sha256"],"case_csv_sha256":sha(case_dst),"binding_sha256":sha(bind_dst),"sof_sha256":SOF,"physical_run_status":"NOT_RUN"})
    if len(sessions)!=13 or sum(x["rows"] for x in sessions)!=24840: raise SystemExit("campaign dimensions changed")
    manifest={"schema":"rtnn-c3-v2-physical-campaign-binding-manifest-v1","status":"PASS_HOST_BINDING_PREP_NOT_PHYSICAL","campaign_canonical_sha256":CAMPAIGN,"build_id":BUILD,"model_id":"52544e4e","sof_sha256":SOF,"schedule_count":len(sessions),"total_rows":sum(x["rows"] for x in sessions),"all_unique_accuracy_inputs":360,"campaign_gate":"NOT_STARTED_WAITING_TEN_INPUT_KEY_RESET_REPLAY_PASS","timing_classification":"EMPIRICAL_ONLY","wcet_or_hard_deadline_claimed":False,"sessions":sessions}
    (a.out/"binding_manifest.json").write_text(json.dumps(manifest,indent=2)+"\n",encoding="utf-8")
    print(json.dumps({"status":manifest["status"],"schedule_count":len(sessions),"total_rows":manifest["total_rows"],"sof_sha256":SOF,"campaign_gate":manifest["campaign_gate"]},indent=2))
    return 0
if __name__=="__main__": raise SystemExit(main())
