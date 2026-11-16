#!/usr/bin/env python3
"""Audit all 146 frozen native RTL source hashes against a separately pinned Ibex checkout.

Read-only: no synthesis, Quartus, board access, or silent source modification.
The public repository contains 5 project SV files; 141 are retrieved from
lowRISC/ibex commit 7b5df75a041affe56e8c235260f98a09b3319008.
"""
from __future__ import annotations
import argparse, hashlib, json, re, subprocess
from pathlib import Path
from reanalyze_c3v2_primary import C3, require

PINNED_COMMIT = "7b5df75a041affe56e8c235260f98a09b3319008"
EVIDENCE = C3 / "evidence/C3_MEASUREMENT_V2_RTL_REPRODUCE_20261115"
IBEX_PREFIX = "/opt/rtnn-tools/ibex/"
PROJECT_MARKER = "artifacts/experiments/de0_cv_c1_c2_audit_20261114/"

def sha(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for part in iter(lambda: f.read(1<<20), b""):
            h.update(part)
    return h.hexdigest()

def git(*args: str) -> str:
    r = subprocess.run(["git", *args], capture_output=True, text=True)
    require(r.returncode==0, f"git failed: {r.stderr.strip()}")
    return r.stdout.strip()

def main():
    p=argparse.ArgumentParser()
    p.add_argument("--ibex-root",type=Path,required=True)
    p.add_argument("--output-json",type=Path,required=True)
    args=p.parse_args()
    repo=C3.parents[3]
    ibex=args.ibex_root.resolve()
    require(ibex.is_dir() and (ibex / ".git").exists(),"missing external Ibex checkout")
    commit=git("-C",str(ibex),"rev-parse","HEAD")
    require(commit==PINNED_COMMIT,"Ibex commit differs from frozen evidence")
    manifest=EVIDENCE/"ibex_source_manifest.sha256"
    frozen_list=EVIDENCE/"native_sources_v2.txt"
    lines=frozen_list.read_text(encoding="utf-8").splitlines()
    entries=manifest.read_text(encoding="utf-8").splitlines()
    require(len(lines)==len(entries)==146,"source count mismatch")
    baseline=C3/"source/measurement_protocol_v2_43334531_20261115/native_source_list_baseline.txt"
    require(sha(baseline)=="4bddc5bd5e37cbd24015189d49e4a21677d570e5cb1c0a7c9dd503da30e6bfba","baseline source-list hash mismatch")
    baseline_lines=baseline.read_text(encoding="utf-8").splitlines()
    require(sha(frozen_list)=="61636721b1ccbd669b52f5ee2db57e600f6c8bbe00208ae2d92725dd050ac17f","reproduction source-list hash mismatch")
    require(lines[:144]==baseline_lines[:144],"unexpected changes in shared 144-source graph")
    require(len(lines)==len(baseline_lines)==146 and lines[144:]!=baseline_lines[144:],"expected C3 v2 two-source override missing")
    require(all("/C3/source/measurement_protocol_v2_43334531_20261115/" in x for x in lines[144:]),"C3 v2 source overrides not selected")
    outputs=[]
    for index,(source,entry) in enumerate(zip(lines,entries)):
        m=re.fullmatch(r"([a-f0-9]{64})  (.+)",entry)
        require(m is not None and source==m.group(2),f"source-manifest order/parse mismatch at entry {index}")
        if source.startswith(IBEX_PREFIX):
            new=ibex/source[len(IBEX_PREFIX):]
            kind="pinned_external_ibex"
        else:
            require(PROJECT_MARKER in source and source.startswith("/mnt/c/"),"unrecognized project source prefix")
            new=repo/PROJECT_MARKER/source.split(PROJECT_MARKER,1)[1]
            kind="repository_project"
        require(new.is_file(),f"missing pinned source: {new}")
        actual=sha(new)
        outputs.append({"index":index+1,"source_type":kind,"repo_relative":str(new.relative_to(repo)) if kind=="repository_project" else None,"ibex_relative":str(new.relative_to(ibex)) if kind=="pinned_external_ibex" else None,"sha256":actual,"expected_sha256":m.group(1),"hash_match":actual==m.group(1)})
    counts={"pinned_external_ibex":sum(x["source_type"]=="pinned_external_ibex" for x in outputs),
            "repository_project":sum(x["source_type"]=="repository_project" for x in outputs)}
    require(counts=={"pinned_external_ibex":141,"repository_project":5},"unexpected source graph partition")
    mismatches=[x for x in outputs if not x["hash_match"]]
    audit={"schema":"rtnn-c3v2-native-source-portability-check-v1","status":"PASS_SOURCE_HASHES_ONLY" if not mismatches else "BLOCKED_SOURCE_HASH_MISMATCH",
           "matched_sources":len(outputs)-len(mismatches),"mismatches":mismatches,
           "ibex_commit":commit,"ibex_origin":"https://github.com/lowRISC/ibex.git",
           "ibex_tree_clean":git("-C",str(ibex),"status","--porcelain")=="",
           "project_source_list_sha256":sha(frozen_list),"counts":counts,"files":outputs,
           "limitations":"Reproduces source identities using a pinned external checkout. Does not execute Verilator, Quartus, FPGA, or prove compiled artifact bit-identity."}
    require(not args.output_json.exists(),"refusing to overwrite output")
    args.output_json.parent.mkdir(parents=True,exist_ok=True)
    args.output_json.write_text(json.dumps(audit,ensure_ascii=False,sort_keys=True,indent=2)+"\n",encoding="utf-8")
    print(f"{audit['status']}: {audit['matched_sources']}/146 source hashes match (external Ibex 141, project 5); no build or hardware operation")
    if mismatches:
        raise SystemExit(2)

if __name__=="__main__":
    main()
