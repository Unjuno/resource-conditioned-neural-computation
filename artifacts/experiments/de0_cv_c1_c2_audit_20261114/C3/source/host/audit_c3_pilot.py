#!/usr/bin/env python3
"""Audit C3 physical pilot artifacts against its versioned frozen binding."""
from __future__ import annotations
import argparse, csv, hashlib, json, re, struct, zlib
from pathlib import Path

def sha(p: Path) -> str:
    return hashlib.sha256(p.read_bytes()).hexdigest()
def need(ok: bool, msg: str) -> None:
    if not ok: raise ValueError(msg)
def audit(a: argparse.Namespace) -> dict:
    binding=json.loads(a.binding.read_text(encoding="utf-8"))
    need(binding["schema"]=="rtnn-c3-jtag-pilot-binding-v1", "binding schema")
    need(binding["campaign_canonical_sha256"]=="d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc", "campaign identity")
    need(binding["frozen_campaign_modified"] is False, "frozen campaign modification flag")
    need(binding["pilot_case_csv_sha256"]==sha(a.cases), "case SHA")
    with a.cases.open(newline="",encoding="utf-8-sig") as f: refs=list(csv.DictReader(f))
    with (a.results/"c2_jtag_results.csv").open(newline="",encoding="utf-8-sig") as f: out=list(csv.DictReader(f))
    report=json.loads((a.results/"c2_jtag_results.json").read_text(encoding="utf-8-sig"))
    raw=(a.results/"c2_jtag_raw.log").read_text(encoding="utf-8-sig").splitlines()
    seqs=[int(r["seq"]) for r in refs]
    need(seqs==[1,2,3,4], "pilot sequence coverage")
    need(len(out)==len(report["cases"])==len(refs)==4, "pilot result count")
    need(report["schema"]=="rtnn-c2-jtag-results-v2" and report["status"]=="PASS", "runner status")
    need(report["experiment_id"]==a.experiment_id and report["sof_sha256"]==a.sof_sha256, "run identity")
    need(report["build_id"]==binding["build_id"] and report["expected_count"]==report["completed_count"]==4, "build/count")
    need(report["selected_sequences"]==seqs and report["scope"]=="subset", "selection")
    need(report["uart"] is False and report["flash_written"] is False, "transport/flash")
    reqs=[x for x in raw if x.startswith("REQUEST ")]; rsps=[x for x in raw if x.startswith("RESPONSE ")]
    need(len(reqs)==len(rsps)==4, "raw transaction count")
    for i,(ref,row,result) in enumerate(zip(refs,out,report["cases"])):
        seq=int(ref["seq"]); iid=int(ref["input_id"]); mode=int(ref["mode"])
        need(result["seq"]==seq and int(row["seq"])==seq, f"seq {seq}: output order")
        need(result["status"]==row["case_status"]=="PASS" and not result["error"] and not row["error"], f"seq {seq}: failed row")
        need(result["cycle_valid"] is True and row["cycle_valid"]=="1", f"seq {seq}: invalid cycles")
        cycles=result["cycles"]; need(type(cycles) is int and 0<cycles<=0xffffffff, f"seq {seq}: cycle range")
        wire=result["response_lsb_hex"]; need(bool(re.fullmatch(r"(?:0[xX])?[0-9a-fA-F]{1,96}",wire)), f"seq {seq}: wire format")
        payload=int(wire,16).to_bytes(48,"little")
        need(payload[:6]==b"RTNR\x01\x00", f"seq {seq}: protocol header")
        need(struct.unpack_from("<I",payload,44)[0]==zlib.crc32(payload[:44]), f"seq {seq}: response CRC")
        rseq,iid_r,budget,deadline=struct.unpack_from("<IHHI",payload,8)
        count,model,build=struct.unpack_from("<III",payload,24)
        expected=(int(ref["expected_admitted"]),int(ref["expected_executed"]),int(ref["expected_prediction"]),int(ref["expected_label"]))
        actual=tuple(payload[20:24])
        need((rseq,iid_r,budget,deadline)==(seq,iid,int(ref["budget_q16"]),0), f"seq {seq}: response identity/budget")
        need(payload[6]==mode and payload[7]==int(ref["expected_stop"]), f"seq {seq}: mode/stop")
        need(actual==expected and count==cycles, f"seq {seq}: output/cycle mismatch")
        need(model==0x52544e4e and build==int(binding["build_id"],16), f"seq {seq}: model/build identity")
        need(payload[21]<=payload[20], f"seq {seq}: cap violation")
        for key,value in {"input_id":iid,"mode":mode,"prediction":expected[2],"reference_label":expected[3],"admitted_exit":expected[0],"executed_exit":expected[1],"cycles":cycles,"expected_prediction":expected[2],"expected_admitted":expected[0],"expected_executed":expected[1],"response_seq":seq,"response_input_id":iid,"response_mode":mode,"response_label":expected[3],"reported_cycles":cycles}.items():
            need(result[key]==value and int(row[key])==value, f"seq {seq}: {key} mismatch")
        expected_req=bytes.fromhex(ref["jtag_request_100b_hex"])[::-1].hex()
        need(reqs[i]==f"REQUEST seq={seq} input_id={iid} mode={mode} request_lsb_hex={expected_req}", f"seq {seq}: raw request")
        need(rsps[i]==f"RESPONSE seq={seq} status=0x40 response_lsb_hex={wire}", f"seq {seq}: raw response")
    return {"status":"PASS_C3_PILOT_ARTIFACT_AUDIT","pilot_rows":4,"input_ids":[165,271],"experiment_id":a.experiment_id,"sof_sha256":a.sof_sha256,"campaign_canonical_sha256":binding["campaign_canonical_sha256"],"full_campaign_rows_counted":0,"timing_classification":"EMPIRICAL_ONLY_NO_WCET_OR_HARD_DEADLINE_CLAIM","hardware_provenance_verified_by_checker":False,"sha256":{p.name:sha(p) for p in [a.cases,a.binding,a.results/"c2_jtag_results.csv",a.results/"c2_jtag_results.json",a.results/"c2_jtag_raw.log"]}}
def main()->int:
    ap=argparse.ArgumentParser();ap.add_argument("--cases",type=Path,required=True);ap.add_argument("--binding",type=Path,required=True);ap.add_argument("--results",type=Path,required=True);ap.add_argument("--experiment-id",required=True);ap.add_argument("--sof-sha256",required=True);ap.add_argument("--out",type=Path,required=True);a=ap.parse_args()
    if a.out.exists(): ap.error("refusing to overwrite audit output")
    try: result=audit(a)
    except (ValueError,KeyError,OSError,TypeError,OverflowError) as e: result={"status":"FAIL_C3_PILOT_ARTIFACT_AUDIT","error":str(e),"hardware_provenance_verified_by_checker":False}
    a.out.write_text(json.dumps(result,indent=2)+"\n",encoding="utf-8");print(json.dumps(result));return 0 if result["status"]=="PASS_C3_PILOT_ARTIFACT_AUDIT" else 1
if __name__=="__main__": raise SystemExit(main())
