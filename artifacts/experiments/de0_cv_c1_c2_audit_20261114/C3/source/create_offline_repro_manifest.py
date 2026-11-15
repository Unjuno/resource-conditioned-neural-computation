#!/usr/bin/env python3
"""Write SHA-256 inventory for the 2026-11-15 board-free C3 preparation."""
from __future__ import annotations

import argparse
import hashlib
from pathlib import Path


def digest(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--c3-root", required=True, type=Path)
    parser.add_argument("--verify", action="store_true", help="verify existing manifest without writing")
    args = parser.parse_args()
    c3 = args.c3_root.resolve()
    repo = c3.parents[3]
    manifest = c3 / "OFFLINE_REPRO_20261115" / "SHA256SUMS.txt"
    targets = [
        c3 / "OFFLINE_REPRO_20261115",
        c3 / "C3_CURRENT_STATUS_20261115_OFFLINE_REPRO_JA.md",
        c3 / "C3_CURRENT_STATUS_20261115_JA.md",
        c3 / "C3_RESTART_AFTER_KEY_RESET_JA.md",
        c3 / "C3_FULL_CAMPAIGN_RUN_RECORD_JA.md",
        c3 / "source" / "audit_saved_c3_v2_runs.py",
        c3 / "source" / "test_audit_saved_c3_v2_runs.py",
        c3 / "source" / "create_key_reset_replay_gate.py",
        c3 / "source" / "check_c3_v2_loaded_build.tcl",
        c3 / "source" / "normalize_native_source_paths.py",
        c3 / "source" / "reanalyze_c2j2_frozen_campaign.py",
        c3 / "source" / "audit_c3_v2_gate_b_saved_reports.py",
        c3 / "source" / "audit_c3_v2_d102_protocol.py",
        c3 / "source" / "audit_c3_gate_b_evidence.py",
        c3 / "source" / "audit_c3_v2_ucp_disposition.py",
        c3 / "source" / "audit_terasic_system_cd_timing_assets.py",
        c3 / "evidence" / "JTAG_CONTROLLER_PACKAGE_RECHECK_20261115",
        c3 / "source" / "create_offline_repro_manifest.py",
        c3 / "evidence" / "GATE_B_C3V2_AUDIT_20261115",
        c3 / "evidence" / "GATE_B_D102_SELECTOR_RECHECK_20261115",
        c3 / "evidence" / "C3_GATE_B_EVIDENCE_AUDIT_20261115_FINAL",
        c3 / "evidence" / "C3_GATE_B_EVIDENCE_AUDIT_20261115_CURRENT_HEAD",
        c3 / "campaign" / "analysis" / "C3_C2J2_INDEPENDENT_REAUDIT_20261115",
        c3 / "campaign" / "analysis" / "C3_C2J2_INDEPENDENT_REAUDIT_20261115_RETRY01",
        c3 / "campaign" / "analysis" / "C3_C2J2_INDEPENDENT_REAUDIT_20261115_RETRY03",
        c3 / "campaign" / "analysis" / "C3_C2J2_INDEPENDENT_REAUDIT_20261115_RETRY04",
        c3 / "campaign" / "analysis" / "C3_C2J2_INDEPENDENT_REAUDIT_20261115_RETRY05",
        repo / "README.md",
    ]
    files: set[Path] = set()
    for target in targets:
        if not target.exists():
            raise SystemExit(f"missing manifest target: {target}")
        if target.is_file():
            files.add(target.resolve())
        else:
            files.update(
                p.resolve()
                for p in target.rglob("*")
                if p.is_file()
                and "__pycache__" not in p.parts
                and not (p.parent.resolve() == manifest.parent.resolve() and p.name.startswith("manifest_generation_"))
            )
    files.discard(manifest.resolve())
    lines = ["# SHA-256 manifest for offline C3 preparation, 2026-11-15", "# Paths are relative to repository root; manifest excludes itself."]
    for path in sorted(files, key=lambda p: p.relative_to(repo).as_posix().casefold()):
        lines.append(f"{digest(path)}  {path.relative_to(repo).as_posix()}")
    expected = "\n".join(lines) + "\n"
    if args.verify:
        if not manifest.is_file() or manifest.read_text(encoding="utf-8") != expected:
            raise SystemExit("FAIL_MANIFEST_VERIFICATION")
        print(f"PASS_MANIFEST_VERIFIED files={len(files)} path={manifest}")
    else:
        manifest.parent.mkdir(parents=True, exist_ok=True)
        manifest.write_text(expected, encoding="utf-8", newline="\n")
        print(f"PASS_MANIFEST files={len(files)} path={manifest}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
