#!/usr/bin/env python3
"""Bind one unchanged frozen campaign schedule to the audited C2J2 image."""
from __future__ import annotations
import argparse, csv, hashlib, json, math, struct, zlib
from pathlib import Path

CAMPAIGN_FILE_SHA = "3d97a1cd87395e294299cacb617474367c89a9295355cd25fb1b4fa67464c936"
CAMPAIGN_CANON_SHA = "d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc"
DATASET_FILE_SHA = "eeba9000a918bcba911007e78905c5052fc743422f95cb314a0fc9f4ecdfb14c"
ORACLE_FILE_SHA = "4e1a3ddcabe1884b1607c77d19b10da8a86d53da3f4c060c30d7449635ec3cf4"
HOST_FILE_SHA = "1f9b08987a9d7368b663f604eb1dce6e077073e099552532468509c846d6bdc8"
FW_VERDICT_SHA = "81f35dab218a8aed82b635a85f4390ead3bf4aa3e00f0e535fce10e3f935483d"
Q15_DIGEST = "03eb958cfa8b4fd2f71a95fb47dbca512820c237c281473817bba685b92c743e"
SOF_SHA = "5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6"
ELF_SHA = "625daf8cc194f1bc7d48eefff0f07939c5e0988bb07fc8a3e7efad7e613a15fd"
BUILD_ID = 0x43324A32
MODEL_ID = 0x52544E4E
FIELDS = ["seq","case_kind","slot","test_index","input_id","mode","parameter_index","fixed_exit","budget_q16","expected_admitted","expected_executed","expected_prediction","expected_label","expected_stop","legacy_prediction","legacy_exit","legacy_admitted","legacy_cycles_not_fpga","request_frame_hex","pixels_u8_64_hex","payload_crc32","jtag_request_100b_hex","jtag_request_bytes","jtag_request_bits","model_id","build_id","deadline_cycles"]

def sha(b: bytes) -> str: return hashlib.sha256(b).hexdigest()
def canon(v: object) -> str: return sha(json.dumps(v,sort_keys=True,separators=(",",":"),allow_nan=False).encode())
def load(p: Path): return json.loads(p.read_text(encoding="utf-8"))
def budget_cap(b: int) -> int: return (b*6)//65535
def frame(seq:int,iid:int,mode:int,fixed:int,budget:int)->bytes:
    b=bytearray(32); b[:8]=bytes((82,84,78,81,1,mode,fixed,0))
    struct.pack_into("<IHHIII",b,8,seq,iid,budget,0,MODEL_ID,BUILD_ID)
    struct.pack_into("<I",b,28,zlib.crc32(b[:28])); return bytes(b)

def run(out:Path, session:str, selected_sequences:list[int]|None=None)->dict:
    base=Path(__file__).resolve().parents[1]
    frozen=base/"frozen_inputs"; c2=base.parent/"C2"
    campaign_path=frozen/"paper/campaign/campaign.json"; campaign_bytes=campaign_path.read_bytes()
    if sha(campaign_bytes)!=CAMPAIGN_FILE_SHA: raise ValueError("campaign file SHA mismatch")
    campaign=json.loads(campaign_bytes); body=dict(campaign); stated=body.pop("campaign_sha256")
    if canon(body)!=CAMPAIGN_CANON_SHA or stated!=CAMPAIGN_CANON_SHA: raise ValueError("campaign canonical SHA mismatch")
    if campaign["unique_accuracy_inputs"]!=360 or sum(x["record_count"] for x in campaign["schedules"])!=24840: raise ValueError("campaign dimensions changed")
    meta=next((x for x in campaign["schedules"] if x["session_id"]==session),None)
    if meta is None: raise ValueError(f"unknown frozen session {session}")
    sched_path=frozen/"paper/campaign"/meta["matrix"]; schedule=load(sched_path)
    if len(schedule["rows"])!=meta["record_count"] or canon(schedule["rows"])!=meta["schedule_sha256"]: raise ValueError("selected frozen schedule identity mismatch")
    for x in campaign["schedules"]:
        s=load(frozen/"paper/campaign"/x["matrix"])
        if len(s["rows"])!=x["record_count"] or canon(s["rows"])!=x["schedule_sha256"]: raise ValueError(f"frozen schedule mismatch {x['session_id']}")
    dataset_path=frozen/"generated/heldout360.json"; oracle_path=frozen/"generated/frozen_q15_oracle.json"
    host_path=frozen/"evidence/native_q15_firmware/host_actual_q15_firmware.csv"; verdict_path=frozen/"evidence/native_q15_firmware/native_firmware_verdict.json"
    for p,want in ((dataset_path,DATASET_FILE_SHA),(oracle_path,ORACLE_FILE_SHA),(host_path,HOST_FILE_SHA),(verdict_path,FW_VERDICT_SHA)):
        if sha(p.read_bytes())!=want: raise ValueError(f"frozen reference SHA mismatch: {p.name}")
    dataset=load(dataset_path); oracle=load(oracle_path); verdict=load(verdict_path)
    if len(dataset["records"])!=360 or dataset["dataset_sha256"]!=campaign["dataset_sha256"] or oracle["dataset_sha256"]!=dataset["dataset_sha256"]: raise ValueError("dataset/oracle identity mismatch")
    if verdict["status"]!="NATIVE_Q15_FIRMWARE_MATCHES_PINNED_MODEL" or verdict["q15_predictions_sha256"]!=Q15_DIGEST: raise ValueError("pinned model verdict mismatch")
    inputs={int(x["input_id"]):x for x in dataset["records"]}
    refs=list(csv.DictReader(host_path.open(newline="",encoding="utf-8-sig")))
    host={(int(x["input_id"]),int(x["mode"]),int(x["param"])):x for x in refs}
    expected_budgets=[round(i*65535/20) for i in range(21)]
    if sorted(set(int(x["budget_q16"]) for x in load(frozen/"paper/campaign/schedules/diagnostic_adaptive.json")["rows"]))!=expected_budgets: raise ValueError("adaptive budget mapping differs from firmware parameterization")
    fw=load(c2/"evidence/candidate_firmware_build/c2_firmware_manifest.json")
    sof=c2/"evidence/quartus_d101/rtnn_c2.sof"
    elf=c2/"evidence/candidate_firmware_build/rtnn_c2_experiment.elf"
    if fw["build_id"]!="43324a32" or fw["model_id"]!="52544e4e" or fw["elf_sha256"]!=ELF_SHA or sha(elf.read_bytes())!=ELF_SHA or sha(sof.read_bytes())!=SOF_SHA: raise ValueError("physical image/firmware identity mismatch")
    all_schedule_rows=schedule["rows"]
    if selected_sequences is None:
        selected_sequences=[int(r["seq"]) for r in all_schedule_rows]
    if len(selected_sequences)!=len(set(selected_sequences)) or selected_sequences!=sorted(selected_sequences): raise ValueError("selected sequences must be unique and increasing")
    frozen_by_seq={int(r["seq"]):r for r in all_schedule_rows}
    if any(seq not in frozen_by_seq for seq in selected_sequences): raise ValueError("selected sequence is absent from frozen schedule")
    rows=[]
    for r in (frozen_by_seq[seq] for seq in selected_sequences):
        seq,iid,mode=int(r["seq"]),int(r["input_id"]),int(r["mode"]); budget=int(r["budget_q16"]); fixed=int(r["fixed_exit"]); deadline=int(r["deadline_cycles"])
        if iid not in inputs or len(inputs[iid]["pixels_u8_64"])!=64: raise ValueError(f"invalid frozen input {iid}")
        pixels=bytes(inputs[iid]["pixels_u8_64"]); label=int(inputs[iid]["label"])
        if mode==1:
            ref=host[(iid,1,fixed)]; admit=exe= int(ref["executed_exit"]); pred=int(ref["prediction"]); stop=int(ref["stop_reason"]); param=fixed
            if int(ref["admitted_exit"])!=admit: raise ValueError("fixed reference exit mismatch")
        elif mode==3:
            param=expected_budgets.index(budget); ref=host[(iid,3,param)]
            admit=int(ref["admitted_exit"]); exe=int(ref["executed_exit"]); pred=int(ref["prediction"]); stop=int(ref["stop_reason"])
        elif mode==2:
            # C2J2 runner's mode 2 is RTNN_MODE_CAPPED: fixed inference to
            # floor(budget_q16*6/65535); reference is the pinned oracle's
            # already-validated fixed-exit prediction, never a new label.
            param=budget_cap(budget); admit=exe=param; pred=int(oracle["predictions"][str(iid)]["predictions"][param]); stop=0
            fixed=0
            fixed_ref=host[(iid,1,param)]
            if int(fixed_ref["prediction"])!=pred or int(fixed_ref["executed_exit"])!=param: raise ValueError(f"capped mode derivation disagrees with frozen fixed oracle: input={iid} exit={param}")
        else: raise ValueError(f"unsupported frozen mode {mode}")
        if mode!=2 and int(r.get("deadline_cycles",0))!=0: raise ValueError("deadline-bound mode is outside the empirical campaign binding")
        f=frame(seq,iid,mode,fixed,budget); payload=f+pixels+struct.pack("<I",zlib.crc32(pixels))
        rows.append({"seq":seq,"case_kind":"C3_FROZEN_CAMPAIGN","slot":0,"test_index":iid,"input_id":iid,"mode":mode,"parameter_index":param,"fixed_exit":fixed,"budget_q16":budget,"expected_admitted":admit,"expected_executed":exe,"expected_prediction":pred,"expected_label":label,"expected_stop":stop,"legacy_prediction":"","legacy_exit":"","legacy_admitted":"","legacy_cycles_not_fpga":"","request_frame_hex":f.hex(),"pixels_u8_64_hex":pixels.hex(),"payload_crc32":f"{zlib.crc32(pixels):08x}","jtag_request_100b_hex":payload.hex(),"jtag_request_bytes":100,"jtag_request_bits":800,"model_id":"52544e4e","build_id":"43324a32","deadline_cycles":deadline})
    out.mkdir(parents=True,exist_ok=False)
    casefile=out/"cases.csv"
    with casefile.open("w",newline="",encoding="utf-8") as f:
        w=csv.DictWriter(f,fieldnames=FIELDS,lineterminator="\n");w.writeheader();w.writerows(rows)
    binding={"schema":"rtnn-c3-campaign-session-binding-v1","session_id":session,"purpose":meta["purpose"],"record_count":len(rows),"full_schedule_record_count":meta["record_count"],"selected_schedule_sequences":selected_sequences,"session_scope":"FULL_FROZEN_SCHEDULE" if len(rows)==meta["record_count"] else "FROZEN_SCHEDULE_SUBSET_NOT_COUNTED_AS_COMPLETE_SESSION","schedule_file":meta["matrix"],"schedule_canonical_sha256":meta["schedule_sha256"],"campaign_canonical_sha256":CAMPAIGN_CANON_SHA,"campaign_file_sha256":CAMPAIGN_FILE_SHA,"dataset_file_sha256":DATASET_FILE_SHA,"oracle_file_sha256":ORACLE_FILE_SHA,"host_q15_file_sha256":HOST_FILE_SHA,"sof_sha256":SOF_SHA,"firmware_elf_sha256":ELF_SHA,"firmware_manifest_sha256":sha((c2/"evidence/candidate_firmware_build/c2_firmware_manifest.json").read_bytes()),"build_id":"43324a32","model_id":"52544e4e","case_csv_sha256":sha(casefile.read_bytes()),"mode_semantics":{"1":"fixed_exit_from_frozen_schedule","2":"capped_fixed_exit=floor(budget_q16*6/65535); reference derived from pinned fixed-exit oracle and cross-checked to native Q15 firmware table","3":"adaptive_budget; reference from pinned native Q15 firmware table"},"frozen_schedule_modified":False,"measurement_scope":campaign["measurement_scope"],"timing_classification":"EMPIRICAL_ONLY","wcet_or_hard_deadline_claimed":False}
    (out/"binding.json").write_text(json.dumps(binding,indent=2)+"\n",encoding="utf-8")
    return {"status":"PASS_CASES_BOUND_TO_FROZEN_SCHEDULE","session":session,"rows":len(rows),"modes":dict(__import__('collections').Counter(str(x['mode']) for x in rows)),"cases_sha256":binding["case_csv_sha256"],"schedule_sha256":meta["schedule_sha256"],"mode2_rows":sum(x["mode"]==2 for x in rows)}

def main():
    p=argparse.ArgumentParser();p.add_argument("--session",required=True);p.add_argument("--out",type=Path,required=True);p.add_argument("--sequences",help="optional comma-separated increasing subset; full session by default");a=p.parse_args()
    selected=None
    if a.sequences:
        try:selected=[int(x) for x in a.sequences.split(",")]
        except ValueError:p.error("sequences must be comma-separated integers")
    try: r=run(a.out,a.session,selected); print(json.dumps(r,indent=2)); return 0
    except Exception as e: print(json.dumps({"status":"FAIL_PREPARE","error":str(e)},indent=2)); return 1
if __name__=="__main__": raise SystemExit(main())
