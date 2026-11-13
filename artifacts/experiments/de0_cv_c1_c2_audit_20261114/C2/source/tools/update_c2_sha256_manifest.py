#!/usr/bin/env python3
"""Regenerate the C2 content SHA-256 manifest (the manifest does not hash itself)."""
from __future__ import annotations
import hashlib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
MANIFEST = ROOT / "C2_SHA256SUMS.txt"

def main() -> int:
    paths = sorted(
        (p for p in ROOT.rglob("*") if p.is_file() and p != MANIFEST),
        key=lambda p: p.relative_to(ROOT).as_posix(),
    )
    rows = []
    for path in paths:
        digest = hashlib.sha256(path.read_bytes()).hexdigest()
        rows.append(f"{digest}  {path.relative_to(ROOT).as_posix()}")
    MANIFEST.write_text("\n".join(rows) + "\n", encoding="ascii", newline="\n")
    print(f"C2_SHA256_MANIFEST entries={len(rows)} path={MANIFEST}")
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
