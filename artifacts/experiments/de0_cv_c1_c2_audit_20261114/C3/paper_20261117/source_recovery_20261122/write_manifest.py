#!/usr/bin/env python3
"""Write a deterministic SHA-256 manifest for the 2026-11-22 recovery evidence."""

from __future__ import annotations

import hashlib
from pathlib import Path

HERE = Path(__file__).resolve().parent
PAPER = HERE.parent
OUTPUT = PAPER / "SHA256SUMS_SOURCE_RECOVERY_20261122.txt"


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1 << 20), b""):
            digest.update(chunk)
    return digest.hexdigest()


def main() -> None:
    files = []
    for path in HERE.rglob("*"):
        if not path.is_file():
            continue
        if any(part.startswith("obj_v2_") for part in path.relative_to(HERE).parts):
            continue
        files.append(path)
    files += [
        PAPER / "audit_native_source_recovery.py",
        PAPER / "SOURCE_RECOVERY_ADDENDUM_20261122_JA.md",
        PAPER / "PAPER_REVIEW_STATUS_20261122_JA.md",
        PAPER / "README.md",
        PAPER / "PREPUBLICATION_CHECKLIST_JA.md",
        PAPER / "CLAIM_EVIDENCE_MATRIX.csv",
    ]
    lines = [f"{sha256(path)}  {path.relative_to(PAPER).as_posix()}" for path in sorted(set(files))]
    OUTPUT.write_text("\n".join(lines) + "\n", encoding="ascii", newline="\n")
    print(f"wrote {len(lines)} entries: {OUTPUT}")


if __name__ == "__main__":
    main()
