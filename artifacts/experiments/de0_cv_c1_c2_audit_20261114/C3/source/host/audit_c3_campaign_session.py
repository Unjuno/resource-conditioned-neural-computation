#!/usr/bin/env python3
"""Independently audit one physical C3 frozen-campaign session."""
from __future__ import annotations
import argparse,csv,hashlib,json,re,struct,zlib
from pathlib import Path

def sha(p:Path)->str:return hashlib.sha256(p.read_bytes()).hexdigest()
def require(ok:bool,msg:str):
    if not ok:raise ValueError(msg)
def audit(a):
    binding=json.loads(a.binding.read_text(encoding="utf-8-sig")); report=json.loads((a.results/"c2_jtag_results.json").read_text(encoding="utf-8-sig"))
    require(binding["schema"]=="rtnn-c3-campaign-session-binding-v1","binding schema")
    require(binding["campaign_canonical_sha256"]=="d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc","campaign SHA")
    require(binding["frozen_schedule_modified"] is False,"schedule mutation flag")
    require(sha(a.cases)==binding["case_csv_sha256"],"case CSV SHA")
    refs=list(csv.DictReader(a.cases.open(newline="",encoding="utf-8-sig")))
    outputs=list(csv.DictReader((a.results/"c2_jtag_results.csv").open(newline="",encoding="utf-8-sig")))
    raw=(a.results/"c2_jtag_raw.log").read_text(encoding="utf-8-sig").splitlines()
    n=binding["record_count"]; seqs=list(range(1,n+1))
    require(len(refs)==len(outputs)==len(report["cases"])==n,"row count")
    require([int(x["seq"]) for x in refs]==seqs,"case sequence coverage")
    require(report["schema"]=="rtnn-c2-jtag-results-v2" and report["status"]=="PASS","runner status")
    require(report["experiment_id"]==a.experiment_id and report["sof_sha256"]==binding["sof_sha256"],"run identity")
    require(report["build_id"]==binding["build_id"] and report["expected_count"]==report["completed_count"]==n,"count/build")
    require(report["selected_sequences"]==seqs and report["scope"]=="subset","sequence selection")
    require(report["uart"] is False and report["flash_written"] is False,"transport/Flash policy")
    reqs=[x for x in raw if x.startswith("REQUEST ")]; rsps=[x for x in raw if x.startswith("RESPONSE ")]
    require(len(reqs)==len(rsps)==n,"raw transaction count")
    mode_counts={}
    for i,(ref,out,res) in enumerate(zip(refs,outputs,report["cases"])):
        seq=int(ref["seq"]); iid=int(ref["input_id"]); mode=int(ref["mode"]); mode_counts[str(mode)]=mode_counts.get(str(mode),0)+1
        require(int(out["seq"])==seq==int(res["seq"]),f"seq {seq}: order")
        require(out["case_status"]==res["status"]=="PASS" and not out["error"] and not res["error"],f"seq {seq}: status")
        cycles=int(out["cycles"]); require(out["cycle_valid"]=="1" and res["cycle_valid"] is True and cycles==res["cycles"] and 0<cycles<=0xffffffff,f"seq {seq}: cycle")
        wire=out["response_lsb_hex"]; require(re.fullmatch(r"(?:0[xX])?[0-9a-fA-F]{1,96}",wire) is not None,f"seq {seq}: response hex")
        payload=int(wire,16).to_bytes(48,"little")
        require(payload[:6]==b"RTNR\x01\x00",f"seq {seq}: response header")
        require(struct.unpack_from("<I",payload,44)[0]==zlib.crc32(payload[:44]),f"seq {seq}: CRC")
        rseq,rid,budget,deadline=struct.unpack_from("<IHHI",payload,8); c,model,build=struct.unpack_from("<III",payload,24)
        expected=(int(ref["expected_admitted"]),int(ref["expected_executed"]),int(ref["expected_prediction"]),int(ref["expected_label"]))
        actual=tuple(payload[20:24])
        require((rseq,rid,budget,deadline)==(seq,iid,int(ref["budget_q16"]),int(ref["deadline_cycles"])),f"seq {seq}: request identity")
        require(payload[6]==mode and payload[7]==int(ref["expected_stop"]),f"seq {seq}: mode/stop")
        require(actual==expected and c==cycles,f"seq {seq}: output/cycle equality")
        require(model==0x52544e4e and build==int(binding["build_id"],16),f"seq {seq}: model/build")
        require(payload[21]<=payload[20],f"seq {seq}: cap violation")
        req=bytes.fromhex(ref["jtag_request_100b_hex"])[::-1].hex()
        require(reqs[i]==f"REQUEST seq={seq} input_id={iid} mode={mode} request_lsb_hex={req}",f"seq {seq}: raw input")
        require(rsps[i]==f"RESPONSE seq={seq} status=0x40 response_lsb_hex={wire}",f"seq {seq}: raw output")
        for key,val in (("prediction",expected[2]),("reference_label",expected[3]),("admitted_exit",expected[0]),("executed_exit",expected[1]),("response_seq",seq),("response_input_id",iid),("response_mode",mode),("response_label",expected[3]),("reported_cycles",cycles)):
            require(int(out[key])==val and res[key]==val,f"seq {seq}: {key}")
    return {"schema":"rtnn-c3-campaign-session-audit-v1","status":"PASS_EMPIRICAL_SESSION_AUDIT","session_id":binding["session_id"],"experiment_id":a.experiment_id,"rows":n,"mode_counts":mode_counts,"unique_input_ids":len({int(x['input_id']) for x in refs}),"all_cycles_valid":True,"functional_mismatches":0,"cap_violations":0,"timeouts":0,"crc_or_identity_faults":0,"uart_used":False,"flash_written":False,"timing_classification":"EMPIRICAL_ONLY_NO_WCET_OR_HARD_DEADLINE_CLAIM","sha256":{"cases.csv":sha(a.cases),"binding.json":sha(a.binding),"results.csv":sha(a.results/"c2_jtag_results.csv"),"results.json":sha(a.results/"c2_jtag_results.json"),"raw.log":sha(a.results/"c2_jtag_raw.log")}}
def main():
    p=argparse.ArgumentParser();p.add_argument('--cases',type=Path,required=True);p.add_argument('--binding',type=Path,required=True);p.add_argument('--results',type=Path,required=True);p.add_argument('--experiment-id',required=True);p.add_argument('--out',type=Path,required=True);a=p.parse_args()
    if a.out.exists():p.error('refusing to overwrite audit output')
    try:r=audit(a)
    except Exception as e:r={"status":"FAIL_EMPIRICAL_SESSION_AUDIT","error":str(e)}
    a.out.write_text(json.dumps(r,indent=2)+"\n",encoding='utf-8');print(json.dumps(r));return 0 if r.get('status')=='PASS_EMPIRICAL_SESSION_AUDIT' else 1
if __name__=='__main__':raise SystemExit(main())
