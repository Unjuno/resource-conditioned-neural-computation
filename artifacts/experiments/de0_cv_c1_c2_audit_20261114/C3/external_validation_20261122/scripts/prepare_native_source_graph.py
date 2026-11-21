#!/usr/bin/env python3
"""Resolve the preserved 146-source C3 graph using hashed local snapshots."""
import argparse, hashlib, json, subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
AUDIT = ROOT.parent / "paper_20261117" / "source_recovery_20261122" / "NATIVE_SOURCE_RECOVERY_AUDIT.json"
PAPER = ROOT.parent / "paper_20261117" / "source_recovery_20261122"
C3SRC = ROOT.parent / "source" / "measurement_protocol_v2_43334531_20261115"
LOCAL = {
    123: PAPER / "ibex_multdiv_fast.csa.sv",
    143: PAPER / "ibex_top_gate_bypass.sv",
    144: PAPER / "rtnn_de0_cv_ram.sv",
    145: C3SRC / "rtnn_de0_cv_soc_c2.sv",
    146: C3SRC / "rtnn_c2_vjtag_mailbox.sv",
}

def digest(path: Path) -> str:
    h=hashlib.sha256()
    with path.open("rb") as f:
        for chunk in iter(lambda:f.read(1024*1024),b""): h.update(chunk)
    return h.hexdigest()

def main():
    ap=argparse.ArgumentParser(); ap.add_argument("--out",type=Path,required=True); a=ap.parse_args()
    if a.out.exists(): raise SystemExit(f"refusing existing source graph output: {a.out}")
    audit=json.loads(AUDIT.read_text(encoding="utf-8")); entries=audit["files"]
    if len(entries)!=146: raise SystemExit(f"unexpected source count {len(entries)}")
    a.out.mkdir(parents=True)
    resolved=[]; records=[]
    for e in entries:
        idx=e["index"]
        p=LOCAL[idx] if idx in LOCAL else Path(e["resolved_path"])
        if not p.is_file(): raise SystemExit(f"missing source {idx}: {p}")
        actual=digest(p); expected=e["expected_sha256"]
        if actual!=expected: raise SystemExit(f"source hash mismatch {idx}: {p}; {actual} != {expected}")
        resolved.append(str(p.resolve()))
        records.append({"index":idx,"source_type":e["source_type"],"path":str(p.resolve()),"sha256":actual})
    ibex=Path("/opt/rtnn-tools/ibex")
    commit=subprocess.check_output(["git","-C",str(ibex),"rev-parse","HEAD"],text=True).strip()
    if commit!="7b5df75a041affe56e8c235260f98a09b3319008": raise SystemExit(f"unexpected Ibex HEAD {commit}")
    listing=a.out/"native_sources.list"; listing.write_text("\n".join(resolved)+"\n",encoding="utf-8")
    manifest={"schema":"rtnn-external-validation-native-graph-v1","source_count":len(records),"source_list_sha256":digest(listing),"ibex_root":"/opt/rtnn-tools/ibex","ibex_commit":commit,"sources":records}
    (a.out/"native_source_manifest.json").write_text(json.dumps(manifest,indent=2)+"\n",encoding="utf-8")
    print(f"NATIVE_SOURCE_GRAPH_READY count={len(records)} ibex={commit} list_sha256={manifest['source_list_sha256']}")

if __name__=="__main__": main()
