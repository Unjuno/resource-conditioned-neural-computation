#!/usr/bin/env python3
"""Verify every file named by the pre-existing C3 evidence SHA manifest."""
from __future__ import annotations
import argparse, hashlib, os
from pathlib import Path

def long_path(path: Path) -> Path:
    """Use the Win32 extended-length prefix for paths beyond MAX_PATH."""
    if os.name != "nt":
        return path
    absolute = str(path.absolute())
    if absolute.startswith("\\\\?\\"):
        return path
    if absolute.startswith("\\\\"):
        return Path("\\\\?\\UNC\\" + absolute[2:])
    return Path("\\\\?\\" + absolute)

def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--c3-root", type=Path, required=True)
    args = parser.parse_args()
    root = args.c3_root.resolve()
    manifest = root / "C3_SHA256SUMS.txt"
    entries = []
    for number, line in enumerate(manifest.read_text(encoding="utf-8-sig").splitlines(), 1):
        if not line.strip():
            continue
        try:
            expected, rel = line.split("  ", 1)
        except ValueError as exc:
            raise SystemExit(f"malformed manifest line {number}") from exc
        path = long_path(root / rel.replace("/", "\\"))
        if not path.is_file():
            raise SystemExit(f"missing file at line {number}: {rel}")
        actual = hashlib.sha256(path.read_bytes()).hexdigest()
        if actual.lower() != expected.lower():
            raise SystemExit(f"SHA-256 mismatch at line {number}: {rel}")
        entries.append(rel)
    if not entries:
        raise SystemExit("empty preservation manifest")
    print(f"PASS_PRESERVED_MANIFEST entries={len(entries)}")
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
