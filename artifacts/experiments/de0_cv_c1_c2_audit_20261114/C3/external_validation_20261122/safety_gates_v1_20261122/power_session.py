#!/usr/bin/env python3
"""Conservative classifier for operator/reset/power-session records."""
import argparse, csv, hashlib, json, sys
from datetime import datetime
from pathlib import Path

SCHEMA="rtnn-extval-power-session-evidence-v1"
KINDS={"LOGICAL_KEY_RESET_ONLY","SOF_RECONFIGURATION_ONLY","OPERATOR_ATTESTED_POWER_CYCLE_RAIL_UNVERIFIED","FULL_RAIL_POWER_CYCLE_EVIDENCE_VERIFIED","POWER_SESSION_UNKNOWN"}
def sha(p): return hashlib.sha256(p.read_bytes()).hexdigest()
def utc_time(value):
    try:
        t=datetime.fromisoformat(str(value).replace("Z","+00:00"))
        return t if t.tzinfo is not None and t.utcoffset().total_seconds()==0 else None
    except Exception: return None
def check_waveform(path):
    with path.open(encoding="utf-8-sig",newline="") as f:
        reader=csv.DictReader(f); names=set(reader.fieldnames or ())
        if not {"time_s","voltage_v"}.issubset(names): return None
        rows=[(float(r["time_s"]),float(r["voltage_v"])) for r in reader]
    if len(rows)<2 or any(not (0<=v<100 and t>=0) for t,v in rows): return None
    if any(rows[i][0]>=rows[i+1][0] for i in range(len(rows)-1)): return None
    first=next((i for i,(_,v) in enumerate(rows) if v<=0.1),None)
    powered_before=first is not None and any(v>=0.5 for _,v in rows[:first])
    low=rows[-1][0]-rows[first][0] if first is not None and all(v<=0.1 for _,v in rows[first:]) else 0.0
    return {"min":min(v for _,v in rows),"max":max(v for _,v in rows),"low_duration":low,"powered_before_drop":powered_before}
def classify(r, base: Path):
    if r.get("schema")!=SCHEMA or r.get("event_kind") not in KINDS: return "POWER_SESSION_UNKNOWN"
    kind=r["event_kind"]
    if kind=="POWER_SESSION_UNKNOWN": return "POWER_SESSION_UNKNOWN"
    if kind!="FULL_RAIL_POWER_CYCLE_EVIDENCE_VERIFIED": return "COLD_BOOT_UNVERIFIED"
    # Full classification requires instrument data, demonstrable rail loss,
    # all power paths accounted for, and stable identity before/after. Operator
    # attestation alone cannot satisfy these machine-checkable fields.
    measurements=r.get("rail_measurements",[])
    rail_names=[]; measures_ok=bool(measurements)
    for ev in measurements:
        path=(base/ev.get("path","missing")).resolve()
        wave=check_waveform(path) if path.is_file() else None
        valid=(ev.get("instrument") and ev.get("channel") and ev.get("rail_name") and
               path.is_file() and sha(path)==ev.get("sha256") and wave is not None and
               wave["min"]<=0.1 and wave["powered_before_drop"] and wave["low_duration"]>=1.0)
        measures_ok=measures_ok and bool(valid); rail_names.append(ev.get("rail_name"))
    identity_keys=("jtag_idcode","build_id","binding_id","model_id","sof_sha256")
    expected_identity={"jtag_idcode":r.get("jtag_idcode"),"build_id":r.get("build_id"),"binding_id":r.get("binding_id"),"model_id":r.get("model_id"),"sof_sha256":r.get("sof_sha256")}
    identities=(all(expected_identity[k] for k in identity_keys) and r.get("before_identity")==expected_identity and r.get("after_identity")==expected_identity)
    inventory=r.get("power_path_inventory",[])
    operation=utc_time(r.get("operation_time_utc")); recorded=utc_time(r.get("recorded_time_utc"))
    required=(r.get("board_identity") and r.get("build_id")=="45585631" and r.get("binding_id")=="45585632" and r.get("model_id")=="52544e4e" and len(r.get("sof_sha256",""))==64 and identities and
              r.get("power_target")=="all_board_power_inputs_and_fpga_rails" and
              r.get("all_power_inputs_enumerated") is True and set(inventory)==set(rail_names) and
              r.get("usb_blaster_power_state")=="physically_disconnected_during_rail_decay" and
              bool(rail_names) and len(set(rail_names))==len(rail_names) and measures_ok and
              r.get("experiment_id") and r.get("session_id") and r.get("previous_session_id") and
              r.get("operator_action") and r.get("power_state_method") and r.get("measurement_uncertainty") and
              isinstance(r.get("unknown_items"),list) and not r.get("unknown_items") and operation is not None and recorded is not None and recorded>=operation and
              r.get("before_identity") and r.get("after_identity"))
    return "FULL_RAIL_POWER_CYCLE_EVIDENCE_VERIFIED" if required else "COLD_BOOT_UNVERIFIED"

def audit_sessions(paths, expected_sessions, board_identity, build_id, sof_sha256, expected_experiments=None):
    records=[]; classes=[]; record_hashes=[]; measurement_hashes=[]
    for raw in paths:
        p=Path(raw); r=json.loads(p.read_text(encoding="utf-8-sig")); records.append(r)
        record_hashes.append(sha(p)); classes.append(classify(r,p.parent))
        for m in r.get("rail_measurements",[]): measurement_hashes.append(m.get("sha256"))
    ids=[r.get("session_id") for r in records]
    relations=all(r.get("previous_session_id")==("BASELINE_PRE_CAMPAIGN" if i==0 else expected_sessions[i-1]) for i,r in enumerate(records)) if len(records)==len(expected_sessions) else False
    experiments=all(r.get("experiment_id")==expected_experiments[i] for i,r in enumerate(records)) if expected_experiments is not None and len(records)==len(expected_experiments) else expected_experiments is None
    valid=(len(records)>=3 and len(set(ids))==len(ids) and ids==list(expected_sessions) and relations and experiments and
           all(c=="FULL_RAIL_POWER_CYCLE_EVIDENCE_VERIFIED" for c in classes) and
           len(set(record_hashes))==len(record_hashes) and len(set(measurement_hashes))==len(measurement_hashes) and
           all(r.get("board_identity")==board_identity and r.get("build_id")==build_id and r.get("sof_sha256")==sof_sha256 for r in records))
    return {"classification":"PASS_INDEPENDENT_COLD_BOOTS" if valid else "COLD_BOOT_UNVERIFIED",
            "session_ids":ids,"record_sha256":record_hashes,"measurement_sha256":measurement_hashes,
            "individual_classifications":classes}
def main():
    ap=argparse.ArgumentParser();ap.add_argument("record",type=Path);a=ap.parse_args()
    try:
        r=json.loads(a.record.read_text(encoding="utf-8-sig")); result=classify(r,a.record.parent)
        print(json.dumps({"schema":SCHEMA,"session_id":r.get("session_id"),"classification":result,"cold_boot":"PASS" if result=="FULL_RAIL_POWER_CYCLE_EVIDENCE_VERIFIED" else "COLD_BOOT_UNVERIFIED","evidence_sha256":sha(a.record)},indent=2))
        return 0 if result!="POWER_SESSION_UNKNOWN" else 2
    except Exception as e: print(f"POWER_EVIDENCE_INVALID: {e}",file=sys.stderr);return 2
if __name__=="__main__":raise SystemExit(main())
