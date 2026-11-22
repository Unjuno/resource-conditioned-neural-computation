#!/usr/bin/env python3
"""Create/verify evidence-consistency gates for a completed physical pilot.

This checks saved records; it cannot cryptographically prove that a board was
physically measured. Test fixtures are never accepted by production mode.
"""
from __future__ import annotations
import argparse, csv, hashlib, json, re, sys
from pathlib import Path

SCHEMA = "rtnn-extval-pilot-gate-v1"
BUILD, BINDING, MODEL = "45585631", "45585632", "52544e4e"
FILES = ("cases.csv", "binding.json", "run_external_validation.tcl", "launcher.log",
         "physical_results.csv", "raw_jtag.log", "run_status.json")

def sha(data: bytes) -> str: return hashlib.sha256(data).hexdigest()
def file_sha(p: Path) -> str: return sha(p.read_bytes())
def read_json(p: Path): return json.loads(p.read_text(encoding="utf-8-sig"))
def read_csv(p: Path):
    with p.open(encoding="utf-8-sig", newline="") as f: return list(csv.DictReader(f))
def need(ok, message):
    if not ok: raise ValueError(message)

def ensure_unique_experiment_id(root: Path, experiment_id: str, except_path: Path|None=None):
    need(bool(experiment_id),"experiment ID is empty")
    root=root.resolve(); skip=except_path.resolve() if except_path else None
    for name in ("run_status.json","binding.json"):
        for p in root.rglob(name):
            # A completed run deliberately stores the same experiment ID in
            # its binding and run_status. Exclude those associated files when
            # validating that binding, while still checking every other run.
            if skip and (p.resolve()==skip or p.parent.resolve()==skip.parent): continue
            try: found=read_json(p).get("experiment_id")
            except Exception: continue
            need(found!=experiment_id,f"experiment ID already recorded: {experiment_id}")

def decode_raw_response(hex_text: str) -> bytes:
    # Tcl xscan records the scan's hex in the same most-significant-byte-first
    # textual form consumed by xbytes; reverse byte order into protocol order.
    h = hex_text.strip().lower().removeprefix("0x")
    need(bool(re.fullmatch(r"[0-9a-f]{120}", h)), "bad raw response framing")
    return bytes.fromhex(h)[::-1]

def crc32(b: bytes) -> int: return __import__("zlib").crc32(b) & 0xffffffff
def u(b, offset, n): return int.from_bytes(b[offset:offset+n], "little")

def audit_run(run: Path, oracle: Path, pilot_manifest: Path, primary_manifest: Path,
              *, fixture_ok=False):
    status=read_json(run/"run_status.json")
    need(status.get("schema")=="rtnn-external-validation-physical-v1" and status.get("status")=="COMPLETE", "pilot run is not COMPLETE")
    need(status.get("run_source")=="quartus_stp_virtual_jtag" and status.get("mock") is False and status.get("hardware_opened") is True and status.get("cycles_source")=="Ibex_mcycle", "not a logged physical JTAG acquisition")
    need(not status.get("fixture_only", False) or fixture_ok, "test fixture cannot create a production pilot gate")
    need(status.get("build_id")==BUILD and status.get("binding_id")==BINDING and status.get("model_id")==MODEL, "wrong pilot build identity")
    need(status.get("expected_cases")==20 and status.get("completed_cases")==20, "pilot must complete exactly 20 cases")
    need(status.get("uart_used") is False and status.get("flash_written") is False and status.get("sof_programming_performed") is False, "unexpected side effect flags")
    sums={}
    for line in (run/"SHA256SUMS.txt").read_text(encoding="ascii").splitlines():
        digest,name=line.split(None,1); sums[name.strip()]=digest.lower()
    for name in FILES:
        need(name in sums and (run/name).is_file() and file_sha(run/name)==sums[name], f"missing or changed run artifact: {name}")
    cases=read_csv(run/"cases.csv"); results=read_csv(run/"physical_results.csv"); oracle_rows=read_csv(oracle)
    binding=read_json(run/"binding.json")
    need(binding.get("split")=="pilot" and binding.get("experiment_id")==status.get("experiment_id") and binding.get("cases_csv_sha256")==file_sha(run/"cases.csv"), "pilot binding mismatch")
    need(binding.get("sof_sha256")==status.get("sof_sha256") and binding.get("firmware_elf_sha256")=="4673f6a8b90493c15c327ed3be1167e0fcf3ff2be60292dcb12a1391124a0c2e", "pilot SOF/ELF mismatch")
    need(binding.get("model_id")==MODEL and binding.get("build_id")==BUILD and binding.get("binding_id")==BINDING,"pilot binding identity mismatch")
    need(status.get("cases_csv_sha256")==file_sha(run/"cases.csv"), "run status cases SHA mismatch")
    need(len(cases)==20 and len(results)==20, "pilot case/result row count mismatch")
    pilot_ids={r["input_id"] for r in read_csv(pilot_manifest)}
    primary_ids={r["input_id"] for r in read_csv(primary_manifest)}
    need(len(pilot_ids)==10 and pilot_ids.isdisjoint(primary_ids), "pilot/primary manifests overlap or malformed")
    pilot_rows={r["input_id"]:r for r in read_csv(pilot_manifest)}
    expected={(iid,m) for iid in pilot_ids for m in ("fixed2","adaptive")}
    seen=set(); raw_responses={}; raw_requests={}; current_seq=None
    for line in (run/"raw_jtag.log").read_text(encoding="utf-8-sig").splitlines():
        m=re.fullmatch(r"request seq=(\d+) input_id=(\d+) mode=(fixed2|adaptive) request_lsb_hex=([0-9a-fA-F]+)",line)
        if m:
            current_seq=int(m.group(1)); req=bytes.fromhex(m.group(4))[::-1]
            need(len(req)==100 and req[:5]==b"RTNQ\x02", "raw request malformed")
            need(crc32(req[:28])==u(req,28,4) and crc32(req[32:96])==u(req,96,4), "raw request CRC mismatch")
            need(u(req,8,4)==current_seq and u(req,12,2)==int(m.group(2)), "raw request ID mismatch")
            need((req[5]==1 and m.group(3)=="fixed2") or (req[5]==3 and m.group(3)=="adaptive"),"raw request mode mismatch")
            need(u(req,20,4)==int(MODEL,16) and u(req,24,4)==int(BUILD,16),"raw request model/build mismatch")
            raw_requests[current_seq]=req
            continue
        m=re.fullmatch(r"response seq=(\d+) raw_lsb_hex=([0-9a-fA-F]+)",line)
        if m:
            seq=int(m.group(1)); b=decode_raw_response(m.group(2)); need(seq==current_seq, "raw response sequence mismatch")
            need(b[:5]==b"RTNR\x03" and u(b,56,4)==crc32(b[:56]), "raw response version/CRC mismatch")
            raw_responses[seq]=b
    need(len(raw_responses)==20 and len(raw_requests)==20 and set(raw_responses)==set(raw_requests), "raw log does not contain 20 unique request/response pairs")
    need(len(oracle_rows)==20, "independent CPU oracle must contain 20 rows")
    # The CPU-oracle CLI numbers the ten selected images 1..10 in frozen
    # manifest order; host cases use original source-row IDs. Join through the
    # immutable manifest order rather than assuming the identifiers coincide.
    oracle_id={r["input_id"]:str(i) for i,r in enumerate(read_csv(pilot_manifest),1)}
    oracle_by={(r["input_id"],r["mode"]):r for r in oracle_rows}
    result_by={}
    for c,r in zip(cases,results):
        k=(c["input_id"],c["mode"]); seq=int(c["sequence"])
        need(k in expected and k not in seen, "wrong/duplicate pilot input-mode")
        seen.add(k); b=raw_responses.get(seq); need(b is not None, "missing raw response for case")
        need(c["experiment_id"]==status["experiment_id"] and c["session_id"]==status["session_id"],"case experiment/session mismatch")
        need(c["pixels_sha256"]==pilot_rows[c["input_id"]]["pixel_sha256"], "pilot pixels differ from frozen manifest")
        need(int(c["teacher_label"])==int(pilot_rows[c["input_id"]]["label_host_only"]),"host teacher label differs from frozen pilot manifest")
        req=raw_requests.get(seq); need(req is not None and req[32:96].hex()==c["pixels_hex"] and u(req,96,4)==int(c["payload_crc32"]),"raw request payload differs from case")
        need(r.get("status")=="PASS" and r.get("sequence")==c["sequence"] and r.get("input_id")==c["input_id"] and r.get("mode")==c["mode"], "result/case identity mismatch")
        need(r.get("sof_sha256")==status.get("sof_sha256"), "result SOF mismatch")
        need(r.get("reference_prediction")==c["expected_prediction"] and r.get("stop_reason")=={"none":"0","entropy":"1","budget":"2"}[c["expected_stop_reason"]],"result reference or stop reason mismatch")
        vals={"prediction":u(b,22,1),"admitted_exit":u(b,20,1),"executed_exit":u(b,21,1),"cycles_start":u(b,24,8),"cycles_end":u(b,32,8),"sequence":u(b,8,4),"input_id":u(b,12,2),"payload_crc32":u(b,16,4),"model_id":u(b,40,4),"build_id":u(b,44,4),"binding_id":u(b,48,4)}
        need(b[5]==0 and b[6]==(1 if c["mode"]=="fixed2" else 3) and b[7]=={"none":0,"entropy":1,"budget":2}[c["expected_stop_reason"]] and b[23]==255 and b[52]==1,"raw response status/mode/exit/counter flag mismatch")
        need(vals["sequence"]==seq and vals["input_id"]==int(c["input_id"]) and vals["payload_crc32"]==int(c["payload_crc32"]), "raw response does not match request")
        need(vals["model_id"]==int(MODEL,16) and vals["build_id"]==int(BUILD,16) and vals["binding_id"]==int(BINDING,16), "raw response identity mismatch")
        need(vals["cycles_start"]>0 and vals["cycles_end"]>vals["cycles_start"] and vals["cycles_end"]-vals["cycles_start"]==int(r["cycles"]), "raw counter/results mismatch")
        for field in ("prediction","admitted_exit","executed_exit","cycles_start","cycles_end"):
            need(int(r[field])==vals[field], f"raw response/CSV {field} mismatch")
        for field in ("admitted_exit","executed_exit"):
            need(r["expected_"+field]==c["expected_"+field],f"CSV expected {field} differs from frozen case")
        need(r["reference_prediction"]==c["expected_prediction"],"CSV reference prediction differs from frozen case")
        oid=oracle_id.get(c["input_id"]); o=oracle_by.get((oid,c["mode"])) if oid else None
        need(o is not None, "oracle missing pilot case via manifest order")
        for rf,of in (("prediction","prediction"),("admitted_exit","admitted_exit"),("executed_exit","executed_exit")):
            need(int(r[rf])==int(o[of])==int(c["expected_"+rf]), f"CPU oracle mismatch: {rf}")
        need(int(r["request_crc_ok"])==1 and int(r["response_crc_ok"])==1, "CSV CRC failure")
        result_by[k]=True
    need(seen==expected, "pilot input/mode set incomplete")
    return {"experiment_id":status["experiment_id"],"session_id":status["session_id"],"sof_sha256":status["sof_sha256"],"firmware_elf_sha256":binding["firmware_elf_sha256"],"build_id":BUILD,"binding_id":BINDING,"model_id":MODEL,"case_count":20,"pilot_attempt_recorded":True,"hardware_opened_log_claim":True,"pilot_input_ids":sorted(map(int,pilot_ids)),"cases_sha256":file_sha(run/"cases.csv"),"binding_sha256":file_sha(run/"binding.json"),"raw_log_sha256":file_sha(run/"raw_jtag.log"),"results_sha256":file_sha(run/"physical_results.csv"),"run_status_sha256":file_sha(run/"run_status.json"),"oracle_sha256":file_sha(oracle),"pilot_manifest_sha256":file_sha(pilot_manifest),"primary_manifest_sha256":file_sha(primary_manifest),"evidence_paths":{**{n:str((run/n).resolve()) for n in FILES},"oracle.csv":str(oracle.resolve()),"pilot_manifest.csv":str(pilot_manifest.resolve()),"primary_manifest.csv":str(primary_manifest.resolve())},"audit":"PILOT_AUDIT_PASS","classification":"EMPIRICAL_ONLY","limitations":["Consistency of saved logs is not cryptographic proof of physical acquisition.","Operator authorization is recorded separately and is not inferred from execution records."]}

def verify_gate(gate_path: Path, binding_path: Path|None=None, *, fixture_ok=False):
    g=read_json(gate_path); need(g.get("schema")==SCHEMA and g.get("audit")=="PILOT_AUDIT_PASS", "invalid pilot gate schema/status")
    need(g.get("classification")=="EMPIRICAL_ONLY" and g.get("case_count")==20, "invalid pilot gate scope")
    paths=g.get("evidence_paths",{}); run=Path(paths.get("cases.csv","")).parent
    need(all(n in paths for n in (*FILES,"oracle.csv","pilot_manifest.csv","primary_manifest.csv")),"pilot gate evidence path set incomplete")
    for n,p in paths.items(): need(Path(p).is_file(),f"pilot evidence missing: {n}")
    recomputed=audit_run(run,Path(paths["oracle.csv"]),Path(paths["pilot_manifest.csv"]),Path(paths["primary_manifest.csv"]),fixture_ok=fixture_ok)
    for k,v in recomputed.items(): need(g.get(k)==v,f"pilot gate audit no longer matches evidence: {k}")
    if binding_path:
        b=read_json(binding_path); need(b.get("split")=="primary", "runner binding is not primary")
        need(b.get("pilot_gate_sha256")==file_sha(gate_path), "primary binding pilot gate SHA mismatch")
        for k in ("sof_sha256","build_id","binding_id","model_id"):
            need(str(b.get(k))==str(g.get(k)), f"primary binding {k} differs from pilot gate")
    return g

def verify_binding(binding_path: Path, cases_path: Path|None=None, *, fixture_ok=False):
    b=read_json(binding_path); need(b.get("split") in ("pilot","primary"),"binding split invalid")
    if cases_path:
        need(cases_path.is_file(),"binding cases file missing")
        need(file_sha(cases_path)==b.get("cases_csv_sha256"),"binding/cases SHA mismatch")
        rows=read_csv(cases_path); expected=20 if b["split"]=="pilot" else 7626
        need(len(rows)==expected==int(b.get("case_count",-1)),"binding/case count mismatch")
        seen=set(); ids=set()
        for r in rows:
            need(r.get("experiment_id")==b.get("experiment_id") and r.get("session_id")==b.get("session_id"),"case experiment/session mismatch")
            need(r.get("model_id")==MODEL and r.get("build_id")==BUILD and r.get("binding_id")==BINDING,"case identity mismatch")
            key=(r.get("input_id"),r.get("mode")); need(key not in seen and key[1] in ("fixed2","adaptive"),"case duplicate or invalid mode")
            seen.add(key); ids.add(key[0])
            pixels=bytes.fromhex(r["pixels_hex"]); need(len(pixels)==64 and max(pixels)<=16 and sha(pixels)==r.get("pixels_sha256"),"case payload invalid")
        need(len(seen)==expected and len(ids)*2==expected,"case pairing invalid")
    if b["split"]=="primary":
        if not fixture_ok:
            ensure_unique_experiment_id(Path(__file__).resolve().parents[1],str(b.get("experiment_id","")),binding_path)
        gp=Path(b.get("pilot_gate_path") or ""); need(gp.is_file(),"primary pilot gate missing")
        need(file_sha(gp)==b.get("pilot_gate_sha256"),"primary pilot gate SHA mismatch")
        g=verify_gate(gp,binding_path,fixture_ok=fixture_ok)
        root=Path(__file__).resolve().parents[1]
        primary_manifest=root/"data"/"primary_manifest.csv"
        need(file_sha(primary_manifest)==b.get("input_manifest_sha256"),"primary input manifest SHA mismatch")
        if cases_path:
            manifest_ids={r["input_id"] for r in read_csv(primary_manifest)}
            need(ids==manifest_ids,"primary case input IDs differ from frozen manifest")
        return g
    return {"audit":"PILOT_BINDING_PREFLIGHT_OK"}

def main():
    ap=argparse.ArgumentParser(); ap.add_argument("--create",action="store_true"); ap.add_argument("--run-dir",type=Path); ap.add_argument("--oracle",type=Path); ap.add_argument("--pilot-manifest",type=Path); ap.add_argument("--primary-manifest",type=Path); ap.add_argument("--operator-authorization",choices=["recorded","not_recorded"],default="not_recorded"); ap.add_argument("--out",type=Path); ap.add_argument("--verify-gate",type=Path); ap.add_argument("--binding",type=Path); ap.add_argument("--verify-binding",type=Path); ap.add_argument("--cases",type=Path)
    a=ap.parse_args()
    try:
        if a.create:
            for x in (a.run_dir,a.oracle,a.pilot_manifest,a.primary_manifest,a.out): need(x is not None,"create requires run-dir/oracle/manifests/out")
            need(not a.out.exists(),"refusing gate overwrite")
            g={"schema":SCHEMA,**audit_run(a.run_dir,a.oracle,a.pilot_manifest,a.primary_manifest),"operator_authorization":a.operator_authorization,"operator_authorization_is_not_execution_proof":True}
            a.out.parent.mkdir(parents=True,exist_ok=True); a.out.write_text(json.dumps(g,indent=2)+"\n",encoding="utf-8"); print("PILOT_GATE_CREATED",file_sha(a.out))
        elif a.verify_gate: print(json.dumps(verify_gate(a.verify_gate,a.binding),indent=2))
        elif a.verify_binding: print(json.dumps(verify_binding(a.verify_binding,a.cases),indent=2))
        else: raise ValueError("choose --create or --verify-gate")
    except Exception as e: print(f"PILOT_GATE_REJECTED: {e}",file=sys.stderr); return 2
    return 0
if __name__=="__main__": raise SystemExit(main())
