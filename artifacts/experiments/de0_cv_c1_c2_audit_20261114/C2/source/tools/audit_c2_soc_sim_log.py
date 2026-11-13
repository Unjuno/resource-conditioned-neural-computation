#!/usr/bin/env python3
"""Audit the 42-request UART-free fixed-Ibex Verilator run; never labels it FPGA data."""
import argparse
import csv
import hashlib
import json
import re
from pathlib import Path

CASE = re.compile(
    r"C2_SOC_CASE_PASS index=(\d+) seq=(\d+) input=(\d+) mode=(\d+) "
    r"pred=(\d+) label=(\d+) admitted=(\d+) executed=(\d+) mcycle=(\d+)"
)

def sha(path): return hashlib.sha256(path.read_bytes()).hexdigest()

def audit(log_path: Path, cases_path: Path, out_dir: Path) -> dict:
    raw = log_path.read_text(encoding="utf-8")
    case_rows = list(csv.DictReader(cases_path.open(newline="", encoding="utf-8")))
    expected = {int(r["seq"]): r for r in case_rows}
    build_ids = {r["build_id"].lower() for r in case_rows}
    if len(build_ids) != 1 or not re.fullmatch(r"[0-9a-f]{8}", next(iter(build_ids), "")):
        raise ValueError(f"case CSV must use exactly one valid 32-bit build ID: {sorted(build_ids)}")
    build_id = next(iter(build_ids))
    found=[]
    for m in CASE.finditer(raw):
        keys=("index","seq","input_id","mode","prediction","label","admitted","executed","mcycle")
        found.append({k:int(v) for k,v in zip(keys,m.groups())})
    if len(expected)!=42: raise ValueError(f"case CSV has {len(expected)} rows")
    if len(found)!=44: raise ValueError(f"expected 42 cases plus two reset replays, got {len(found)}")
    primary=found[:42]; replay=found[42]
    if [r["seq"] for r in primary] != list(range(1,43)):
        raise ValueError("sequence coverage/order mismatch")
    for row in primary:
        ref=expected[row["seq"]]
        compare={"input_id":"input_id","mode":"mode","prediction":"expected_prediction",
                 "label":"expected_label","admitted":"expected_admitted","executed":"expected_executed"}
        for actual, field in compare.items():
            if row[actual] != int(ref[field]):
                raise ValueError(f"seq={row['seq']} {actual}={row[actual]} expected {ref[field]}")
        if row["mcycle"]<=0: raise ValueError(f"seq={row['seq']} nonpositive simulated mcycle")
        if row["executed"]>row["admitted"]: raise ValueError(f"seq={row['seq']} cap violation")
    for replay in found[42:]:
        if replay["seq"]!=1 or replay["input_id"]!=0 or replay["prediction"]!=int(expected[1]["expected_prediction"]):
            raise ValueError("reset replay did not reproduce input 0 result")
        if replay["mcycle"]!=primary[0]["mcycle"]: raise ValueError("reset replay cycle count differs")
    for marker in ("C2_SOC_NEGATIVE_PASS tag=bad_frame_crc response_status=2",
                   "C2_SOC_NEGATIVE_PASS tag=bad_payload_crc response_status=4",
                   "C2_SOC_NEGATIVE_PASS tag=duplicate_sequence response_status=4",
                   "C2_SOC_NEGATIVE_PASS tag=unknown_input_id response_status=4",
                   "C2_SOC_NEGATIVE_PASS tag=unknown_model_id response_status=3",
                   "C2_SOC_NEGATIVE_PASS tag=unknown_build_id response_status=3",
                   "negatives=bad_crc,duplicate,busy_reset,payload_crc,unknown_input,unknown_model,unknown_build"):
        if marker not in raw: raise ValueError(f"negative/reset test marker absent: {marker}")
    if "C2_FIXED_IBEX_Q15_SOC_PASS cases=42 reset_recovery=PASS" not in raw:
        raise ValueError("SoC regression PASS marker absent")
    if "Fatal" in raw or "ERROR" in raw: raise ValueError("failure marker appears in raw simulation log")
    out_dir.mkdir(parents=True,exist_ok=True)
    fields=["build_id","seq","input_id","mode","prediction","reference_label","admitted_exit","executed_exit",
            "mcycle_sim","cycle_source","case_status"]
    with (out_dir/"c2_soc_sim_results.csv").open("w",newline="",encoding="utf-8") as f:
        w=csv.DictWriter(f,fieldnames=fields); w.writeheader()
        for row in primary:
            ref=expected[row["seq"]]
            w.writerow({"build_id":build_id,"seq":row["seq"],"input_id":row["input_id"],"mode":row["mode"],
                        "prediction":row["prediction"],"reference_label":int(ref["expected_label"]),
                        "admitted_exit":row["admitted"],"executed_exit":row["executed"],
                        "mcycle_sim":row["mcycle"],"cycle_source":"Verilator fixed-Ibex RTL mcycle",
                        "case_status":"PASS_RTL_SIM_ONLY"})
    result={"status":"PASS_RTL_SIMULATION_ONLY","build_id":build_id,"count":42,"reset_replays":2,
            "negative_cases":{"bad_frame_crc":"PASS_BAD_FRAME","bad_payload_crc":"PASS_BAD_REQUEST",
                              "duplicate_sequence":"PASS_BAD_REQUEST","unknown_input_id":"PASS_BAD_REQUEST",
                              "unknown_model_id":"PASS_WRONG_ID","unknown_build_id":"PASS_WRONG_ID",
                              "busy_reset":"PASS_RESET_RECOVERY"},
            "hardware_measurements":False,"cycle_source":"Ibex mcycle observed in Verilator RTL simulation",
            "cases":primary,"reset_replay_cases":found[42:],
            "input_log_sha256":sha(log_path),"frozen_cases_sha256":sha(cases_path),
            "results_csv_sha256":sha(out_dir/"c2_soc_sim_results.csv"),
            "nonclaims":["no physical FPGA JTAG test","simulated mcycle is not a board measurement","no oscillator frequency claim"]}
    (out_dir/"c2_soc_sim_results.json").write_text(json.dumps(result,indent=2)+"\n",encoding="utf-8")
    (out_dir/"audit.txt").write_text("C2_SOC_42_CASE_RTL_SIM_PASS cases=42 reset_replay=PASS hardware_measurements=0\n",encoding="ascii")
    return result

if __name__=="__main__":
    p=argparse.ArgumentParser()
    p.add_argument("--log",type=Path,required=True)
    p.add_argument("--cases",type=Path,default=Path(__file__).resolve().parents[1]/"host/c2_cases.csv")
    p.add_argument("--out",type=Path,required=True)
    a=p.parse_args()
    print(json.dumps(audit(a.log,a.cases,a.out),indent=2))
