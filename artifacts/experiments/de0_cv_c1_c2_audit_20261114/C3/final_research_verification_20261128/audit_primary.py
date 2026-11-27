#!/usr/bin/env python3
"""Fail-closed independent audit of C3 primary schedules and saved physical runs."""
import argparse,csv,hashlib,json,re,sys,zlib
from pathlib import Path
PKG=Path(__file__).resolve().parents[1]/"external_validation_20261122"
BUILD,BINDING,MODEL="45585631","45585632","52544e4e"
SOF="5e333e9377b7188a394d04b93b98833d91afb2cd53eca8d976e6aa715dfa00c4"
ELF="4673f6a8b90493c15c327ed3be1167e0fcf3ff2be60292dcb12a1391124a0c2e"
N=3813
def need(ok,msg):
 if not ok: raise ValueError(msg)
def sha(b): return hashlib.sha256(b).hexdigest()
def fsha(p): return sha(p.read_bytes())
def rcsv(p):
 with Path(p).open(encoding="utf-8-sig",newline="") as f:return list(csv.DictReader(f))
def expected(package):
 m=rcsv(package/"data/primary_manifest.csv"); raw=(package/"data/primary_inputs.bin").read_bytes()
 need(len(m)==N and len(raw)==64*N,"frozen primary manifest/input size mismatch")
 audit=json.loads((package/"data/dataset_audit.json").read_text(encoding="utf-8-sig"))
 tra=bytes.fromhex(audit["optdigits_tra_sha256"])
 pilot={x["input_id"] for x in rcsv(package/"data/pilot_manifest.csv")}
 need(len(pilot)==10 and not pilot.intersection({x["input_id"] for x in m}),"pilot/primary overlap")
 o=rcsv(package/"build/cpu_oracle_attempt1/oracle_primary.csv")
 need(len(o)==2*N,"frozen CPU oracle row count mismatch")
 by={(x["input_id"],x["mode"]):x for x in o}; need(len(by)==len(o),"duplicate oracle keys")
 oracle_ord={x["input_id"]:str(i+1) for i,x in enumerate(m)}
 imgs=[]
 for i,x in enumerate(m):
  px=raw[64*i:64*(i+1)]
  need(len(px)==64 and max(px)<=16 and sha(px)==x["pixel_sha256"],"frozen primary pixel/hash mismatch")
  imgs.append((x,px))
 imgs.sort(key=lambda x:bytes.fromhex(x[0]["pixel_sha256"]))
 out=[]
 for x,px in imgs:
  ordinal=oracle_ord[x["input_id"]]
  seed=b"RTNN-EXTVAL-MODE-ORDER-v1\0"+tra+int(x["input_id"]).to_bytes(4,"little")
  modes=("adaptive","fixed2") if hashlib.sha256(seed).digest()[0]&128 else ("fixed2","adaptive")
  for mode in modes:
   ref=by.get((ordinal,mode)); need(ref and ref["cap_violation"]=="0","oracle lookup/cap failure")
   out.append((x,px,mode,ref))
 return out
def audit_schedule(rows,package,sequence_start):
 ex=expected(package); need(len(rows)==2*N,"case count must equal 7,626")
 ids=set(); pairs=set(); exp=set(); sess=set()
 for i,(r,(m,px,mode,o)) in enumerate(zip(rows,ex)):
  seq=sequence_start+i
  need(int(r["sequence"])==seq,"sequence must be contiguous and preserve frozen row order")
  need(r["input_id"]==m["input_id"] and r["mode"]==mode,"frozen input/mode order mismatch")
  need(r["pixels_hex"]==px.hex() and r["pixels_sha256"]==sha(px)==m["pixel_sha256"],"frozen pixel mismatch")
  need(r["teacher_label"]==m["label_host_only"],"host teacher label mismatch")
  need(int(r["payload_crc32"])==zlib.crc32(px)&0xffffffff,"pixel CRC mismatch")
  need((r["model_id"],r["build_id"],r["binding_id"])==(MODEL,BUILD,BINDING),"build identity mismatch")
  for cf,of in (("expected_prediction","prediction"),("expected_admitted_exit","admitted_exit"),("expected_executed_exit","executed_exit"),("expected_stop_reason","stop_reason")):
   need(str(r[cf])==str(o[of]),"CPU oracle mismatch: "+cf)
  need(r["expected_stop_reason"] in ("none","entropy","budget"),"invalid stop reason")
  ids.add(r["input_id"]); pairs.add((r["input_id"],mode)); exp.add(r["experiment_id"]); sess.add(r["session_id"])
 need(len(ids)==N and len(pairs)==2*N and len(exp)==len(sess)==1,"paired IDs or experiment/session mismatch")
 return {"classification":"SCHEDULE_ONLY","rows":len(rows),"unique_images":len(ids),"sequence_first":sequence_start,"sequence_last":sequence_start+len(rows)-1,"experiment_id":next(iter(exp)),"session_id":next(iter(sess))}
def decode_hex_le(h,n):
 h=h.strip().lower().removeprefix("0x"); need(bool(re.fullmatch("[0-9a-f]+",h)) and len(h)==2*n,"raw JTAG frame malformed")
 return bytes.fromhex(h)[::-1]
def u(b,o,n):return int.from_bytes(b[o:o+n],"little")
def s8(x):return x-256 if x>=128 else x
def raw_pairs(path):
 req={};rsp={};last=None
 for line in path.read_text(encoding="utf-8-sig").splitlines():
  m=re.fullmatch(r"request seq=(\d+) input_id=(\d+) mode=(fixed2|adaptive) request_lsb_hex=([0-9a-fA-F]+)",line)
  if m:
   seq=int(m[1]);b=decode_hex_le(m[4],100)
   need(b[:5]==b"RTNQ\x02" and zlib.crc32(b[:28])&0xffffffff==u(b,28,4) and zlib.crc32(b[32:96])&0xffffffff==u(b,96,4),"request framing/CRC error")
   need(u(b,8,4)==seq and u(b,12,2)==int(m[2]) and (b[5],b[6])==((1,2) if m[3]=="fixed2" else (3,0)),"request line/header mismatch")
   need(b[7]==0 and u(b,14,2)==65535 and u(b,16,4)==0 and u(b,20,4)==int(MODEL,16) and u(b,24,4)==int(BUILD,16),"request config/identity mismatch")
   need(seq not in req,"duplicate raw request");req[seq]=b;last=seq;continue
  m=re.fullmatch(r"response seq=(\d+) raw_lsb_hex=([0-9a-fA-F]+)",line)
  if m:
   seq=int(m[1]);b=decode_hex_le(m[2],60)
   need(seq==last and seq in req and b[:5]==b"RTNR\x03" and zlib.crc32(b[:56])&0xffffffff==u(b,56,4),"response framing/order/CRC error")
   need(seq not in rsp,"duplicate raw response");rsp[seq]=b
 need(set(req)==set(rsp),"missing/extra raw request-response pair")
 return req,rsp
def verify_manifest(run,required):
 run=Path(run);sums={}
 for line in (run/"SHA256SUMS.txt").read_text(encoding="ascii").splitlines():
  h,n=line.split(None,1);n=n.strip();p=Path(n)
  need(not p.is_absolute() and ".." not in p.parts and len(p.parts)==1,"unsafe SHA manifest path")
  need(n not in sums,"duplicate SHA manifest path")
  sums[n]=h.lower();need((run/n).is_file() and fsha(run/n)==h.lower(),"SHA256 manifest mismatch: "+n)
 need(all(x in sums for x in required),"SHA manifest incomplete")
 return sums
def audit_run(run,package=PKG):
 sys.path.insert(0,str(package))
 from safety_gates_v1_20261122.pilot_gate import verify_binding
 run=Path(run);st=json.loads((run/"run_status.json").read_text(encoding="utf-8-sig"))
 need(st.get("schema")=="rtnn-external-validation-physical-v1" and st.get("status")=="COMPLETE","run not COMPLETE")
 need(st.get("run_source")=="quartus_stp_virtual_jtag" and st.get("mock") is False and st.get("hardware_opened") is True and st.get("cycles_source")=="Ibex_mcycle","not recorded physical JTAG/mcycle")
 need(str(st.get("build_id"))==BUILD and str(st.get("binding_id"))==BINDING and str(st.get("model_id"))==MODEL and st.get("sof_sha256")==SOF,"run identity mismatch")
 need(st.get("expected_cases")==7626 and st.get("completed_cases")==7626,"expected 7,626 complete cases")
 need(st.get("uart_used") is False and st.get("flash_written") is False and st.get("sof_programming_performed") is False,"unexpected side effect")
 bp=run/"binding.json";b=json.loads(bp.read_text(encoding="utf-8-sig"))
 need(b.get("split")=="primary" and b.get("classification")=="EMPIRICAL_ONLY" and b.get("experiment_id")==st.get("experiment_id") and b.get("session_id")==st.get("session_id"),"binding/run mismatch")
 need(b.get("sof_sha256")==SOF and b.get("firmware_elf_sha256")==ELF and str(b.get("build_id"))==BUILD and str(b.get("binding_id"))==BINDING and str(b.get("model_id"))==MODEL,"binding identity mismatch")
 need(st.get("cases_csv_sha256")==fsha(run/"cases.csv") and st.get("binding_sha256")==fsha(bp),"run cases/binding SHA mismatch")
 required=("cases.csv","binding.json","run_external_validation.tcl","launcher.log","physical_results.csv","raw_jtag.log","run_status.json")
 verify_manifest(run,required)
 sys.path.insert(0,str(package));verify_binding(bp,run/"cases.csv")
 cases=rcsv(run/"cases.csv");results=rcsv(run/"physical_results.csv");need(len(cases)==len(results)==7626,"case/result count mismatch")
 first=int(cases[0]["sequence"]);need(first>21,"sequence reuses previously observed pilot range")
 audit_schedule(cases,package,first);req,rsp=raw_pairs(run/"raw_jtag.log")
 need(set(req)=={int(c["sequence"]) for c in cases}==set(rsp),"raw sequence set mismatch")
 for c,r in zip(cases,results):
  seq=int(c["sequence"]);q=req[seq];z=rsp[seq];px=bytes.fromhex(c["pixels_hex"])
  need(q[32:96]==px and u(q,96,4)==int(c["payload_crc32"]) and u(q,12,2)==int(c["input_id"]),"raw request/case mismatch")
  stop={"none":0,"entropy":1,"budget":2}[c["expected_stop_reason"]];mode=1 if c["mode"]=="fixed2" else 3
  need(z[5]==0 and z[6]==mode and z[7]==stop and u(z,8,4)==seq and u(z,12,2)==int(c["input_id"]) and u(z,14,2)==65535 and u(z,16,4)==int(c["payload_crc32"]),"raw response ID/mode/CRC mismatch")
  need((s8(z[20]),s8(z[21]),s8(z[22]),s8(z[23]))==(int(c["expected_admitted_exit"]),int(c["expected_executed_exit"]),int(c["expected_prediction"]),-1),"response oracle/exit/label mismatch")
  start,end=u(z,24,8),u(z,32,8)
  need(u(z,40,4)==int(MODEL,16) and u(z,44,4)==int(BUILD,16) and u(z,48,4)==int(BINDING,16) and u(z,52,4)==1 and start>0 and end>start,"response identity/counter invalid")
  want={"status":"PASS","experiment_id":st["experiment_id"],"session_id":st["session_id"],"sequence":c["sequence"],"input_id":c["input_id"],"mode":c["mode"],"reference_prediction":c["expected_prediction"],"prediction":str(s8(z[22])),"admitted_exit":str(s8(z[20])),"executed_exit":str(s8(z[21])),"stop_reason":str(z[7]),"cycles_start":str(start),"cycles_end":str(end),"cycles":str(end-start),"payload_crc32":c["payload_crc32"],"request_crc_ok":"1","response_crc_ok":"1","model_id":MODEL,"build_id":BUILD,"binding_id":BINDING,"sof_sha256":SOF}
  for k,v in want.items():need(r.get(k)==v,f"raw/case/result mismatch {k} sequence={seq}")
 return {"classification":"EMPIRICAL_ONLY","data_integrity":"PASS","raw_pairs":len(req),"primary_images":N,"paired_requests":7626,"sequence_first":first,"sequence_last":int(cases[-1]["sequence"]),"cases_sha256":fsha(run/"cases.csv"),"raw_log_sha256":fsha(run/"raw_jtag.log"),"pilot_gate_verified":True,"cold_boot":"COLD_BOOT_UNVERIFIED","formal_timing_signoff":"BLOCKED_EXTERNAL_BOARD_TIMING"}
def main():
 ap=argparse.ArgumentParser();ap.add_argument("--package",type=Path,default=PKG);sub=ap.add_subparsers(dest="cmd",required=True)
 s=sub.add_parser("schedule");s.add_argument("--cases",type=Path,required=True);s.add_argument("--sequence-start",type=int,required=True)
 r=sub.add_parser("run");r.add_argument("--run-dir",type=Path,required=True);a=ap.parse_args()
 try: print(json.dumps(audit_schedule(rcsv(a.cases),a.package,a.sequence_start) if a.cmd=="schedule" else audit_run(a.run_dir,a.package),indent=2))
 except Exception as e:print(f"PRIMARY_AUDIT_REJECTED: {e}",file=sys.stderr);return 2
 return 0
if __name__=="__main__":raise SystemExit(main())
