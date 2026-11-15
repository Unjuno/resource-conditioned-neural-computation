#!/usr/bin/env python3
"""Map the preserved 146-source C3 baseline list without changing its hash."""
from __future__ import annotations
import argparse, hashlib, json
from pathlib import Path

BASELINE_SHA = "4bddc5bd5e37cbd24015189d49e4a21677d570e5cb1c0a7c9dd503da30e6bfba"
OLD_REPO_PREFIX = "/mnt/c/Users/junny/OneDrive/ドキュメント/ChatGPT/resource-conditioned-neural-computation-audit-20261114/"
IBEX_PREFIX = "/opt/rtnn-tools/ibex/"

def sha(path: Path) -> str:
    h=hashlib.sha256()
    with path.open("rb") as f:
        for b in iter(lambda:f.read(1024*1024),b""): h.update(b)
    return h.hexdigest()

def main():
    p=argparse.ArgumentParser()
    p.add_argument("--repo-root",type=Path,required=True)
    p.add_argument("--source-list",type=Path,required=True)
    p.add_argument("--out-dir",type=Path,required=True)
    a=p.parse_args(); root=a.repo_root.resolve(); src=a.source_list.resolve(); out=a.out_dir.resolve()
    if sha(src)!=BASELINE_SHA: raise SystemExit("FAIL: preserved native source list SHA mismatch")
    if out.exists() and any(out.iterdir()): raise SystemExit("FAIL: refusing to overwrite nonempty output directory")
    out.mkdir(parents=True,exist_ok=True)
    entries=[]
    for i,line in enumerate(src.read_text(encoding="utf-8-sig").splitlines(),1):
        path=line.strip()
        if path.startswith(OLD_REPO_PREFIX):
            rel=path[len(OLD_REPO_PREFIX):]
            local=root.joinpath(*rel.split("/"))
            entries.append({"index":i,"original_path":path,"mapping_kind":"REPO_RELATIVE",
                            "normalized_path":rel,"exists_in_repository":local.is_file(),
                            "sha256":sha(local) if local.is_file() else None})
        elif path.startswith(IBEX_PREFIX):
            rel=path[len(IBEX_PREFIX):]
            local=root.joinpath("vendor/ibex",*rel.split("/"))
            entries.append({"index":i,"original_path":path,"mapping_kind":"EXTERNAL_IBEX_DEPENDENCY",
                            "normalized_path":"${IBEX_ROOT}/"+rel,"exists_in_repository":local.is_file(),
                            "repository_candidate":str(local.relative_to(root)).replace("\\","/"),
                            "sha256":sha(local) if local.is_file() else None})
        else:
            entries.append({"index":i,"original_path":path,"mapping_kind":"UNMAPPED_EXTERNAL_PATH",
                            "normalized_path":None,"exists_in_repository":False,"sha256":None})
    if len(entries)!=146: raise SystemExit(f"FAIL: expected 146 source entries, got {len(entries)}")
    mapping={"schema":"rtnn-c3-native-source-list-path-map-v1","source_list_sha256":BASELINE_SHA,
             "mapping_only_not_build_equivalence":True,"entry_count":len(entries),
             "repository_entries_present":sum(e["exists_in_repository"] for e in entries if e["mapping_kind"]=="REPO_RELATIVE"),
             "repository_entries_missing":sum(not e["exists_in_repository"] for e in entries if e["mapping_kind"]=="REPO_RELATIVE"),
             "external_ibex_entry_count":sum(e["mapping_kind"]=="EXTERNAL_IBEX_DEPENDENCY" for e in entries),
             "external_ibex_available_in_repository":sum(e["exists_in_repository"] for e in entries if e["mapping_kind"]=="EXTERNAL_IBEX_DEPENDENCY"),
             "entries":entries}
    (out/"native_source_list_path_map.json").write_text(json.dumps(mapping,indent=2,ensure_ascii=False)+"\n",encoding="utf-8",newline="\n")
    with (out/"native_source_list_normalized.tsv").open("w",encoding="utf-8",newline="\n") as f:
        f.write("index\tkind\tnormalized_path\texists\tsha256\n")
        for e in entries: f.write(f"{e['index']}\t{e['mapping_kind']}\t{e['normalized_path'] or ''}\t{str(e['exists_in_repository']).lower()}\t{e['sha256'] or ''}\n")
    print(f"PASS_MAP_ONLY entries={len(entries)} baseline_sha256={BASELINE_SHA} repo_files={mapping['repository_entries_present']} external_ibex_present={mapping['external_ibex_available_in_repository']}/{mapping['external_ibex_entry_count']}")
if __name__=="__main__": main()
