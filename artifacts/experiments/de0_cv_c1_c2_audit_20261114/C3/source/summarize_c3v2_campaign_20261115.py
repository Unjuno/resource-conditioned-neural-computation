#!/usr/bin/env python3
"""Validate archived C3 v2 physical campaign runs without mixing C2J2 data."""
from __future__ import annotations
import argparse, csv, hashlib, json, statistics
from pathlib import Path

EXPECTED = {
    "diagnostic_fixed": ("C3V2_DIAGFIXED_FULL2520_RUN2_20261115", 2520),
    "diagnostic_adaptive": ("C3V2_DIAGADAPTIVE_FULL7560_RUN1_20261115", 7560),
    "diagnostic_capped": ("C3V2_DIAGCAPPED_FULL7560_RUN1_20261115", 7560),
    **{f"primary_{i:02d}": (f"C3V2_PRIMARY{i:02d}_FULL720_RUN1_20261115", 720) for i in range(1, 11)},
}

def sha(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(1024 * 1024), b""):
            h.update(chunk)
    return h.hexdigest()

def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--campaign-dir", required=True, type=Path)
    ap.add_argument("--output-json", required=True, type=Path)
    args = ap.parse_args()
    out=[]
    errors=[]
    for schedule, (run_id, expected_rows) in EXPECTED.items():
        d=args.campaign_dir/run_id
        try:
            meta=json.loads((d/"run_metadata.json").read_text(encoding="utf-8-sig"))
            audit=json.loads((d/"python_independent_audit.json").read_text(encoding="utf-8-sig"))
            rows=audit["responses"]
            cases=list(csv.DictReader((d/"input"/"cases.csv").open(encoding="utf-8-sig", newline="")))
            csvrows=list(csv.DictReader((d/"results"/"c2_jtag_results.csv").open(encoding="utf-8-sig", newline="")))
            if meta["experiment_id"] != run_id or audit["experiment_id"] != run_id: errors.append(f"{run_id}: experiment identity mismatch")
            if meta["schedule_id"] != schedule or audit["schedule_id"] != schedule: errors.append(f"{run_id}: schedule identity mismatch")
            if audit["status"] != "PASS_SAVED_PHYSICAL_EVIDENCE_AUDIT": errors.append(f"{run_id}: audit not PASS")
            if len(rows) != expected_rows or len(cases) != expected_rows or len(csvrows) != expected_rows: errors.append(f"{run_id}: row count mismatch responses={len(rows)} cases={len(cases)} csv={len(csvrows)} expected={expected_rows}")
            for k in ("build_id", "sof_sha256", "model_id"):
                if str(meta[k]).lower() != str(audit[k]).lower(): errors.append(f"{run_id}: {k} mismatch")
            if meta["cold_boot_confirmed"] is not False or meta["timing_classification"] != "EMPIRICAL_ONLY": errors.append(f"{run_id}: cold-boot/timing classification invalid")
            cycles=[int(r["cycles"]) for r in rows]
            out.append({"schedule_id":schedule,"experiment_id":run_id,"rows":len(rows),"audit":audit["status"],"build_id":meta["build_id"],"sof_sha256":meta["sof_sha256"],"model_id":meta["model_id"],"cold_boot_confirmed":meta["cold_boot_confirmed"],"power_session_id":meta["power_session_id"],"cycles_min":min(cycles),"cycles_median":statistics.median(cycles),"cycles_max":max(cycles),"results_csv_sha256":sha(d/"results"/"c2_jtag_results.csv"),"results_json_sha256":sha(d/"results"/"c2_jtag_results.json"),"cases_sha256":sha(d/"input"/"cases.csv"),"binding_sha256":sha(d/"input"/"binding.json")})
            manifest=d/"SHA256SUMS.txt"
            if not manifest.exists(): errors.append(f"{run_id}: missing SHA256SUMS.txt")
            else:
                for line in manifest.read_text(encoding="ascii").splitlines():
                    expected, rel=line.split("  ",1)
                    p=d/Path(rel)
                    if not p.is_file() or sha(p) != expected: errors.append(f"{run_id}: checksum mismatch {rel}")
        except Exception as e:
            errors.append(f"{run_id}: {type(e).__name__}: {e}")
    total=sum(x["rows"] for x in out)
    result={"schema":"rtnn-c3-v2-physical-campaign-aggregate-audit-v1","data_class":"SAVED_PHYSICAL_EVIDENCE_NOT_NEW_MEASUREMENT","status":"PASS" if not errors and len(out)==13 and total==24840 else "FAIL","campaign_sha256":"d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc","schedule_count":len(out),"expected_schedule_count":13,"rows":total,"expected_rows":24840,"all_runs_empirical_only":all(x.get("cold_boot_confirmed") is False for x in out),"runs":out,"errors":errors}
    args.output_json.parent.mkdir(parents=True,exist_ok=True)
    args.output_json.write_text(json.dumps(result,indent=2)+"\n",encoding="utf-8")
    print(f"{result['status']} schedules={len(out)}/13 rows={total}/24840 errors={len(errors)}")
    for e in errors: print("ERROR",e)
    return 0 if result["status"]=="PASS" else 1
if __name__=="__main__": raise SystemExit(main())
