#!/usr/bin/env python3
"""Verify a saved SHA-256 project manifest against a specific build directory."""
from __future__ import annotations

import argparse
import hashlib
from pathlib import Path


def digest(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for block in iter(lambda: f.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def main() -> int:
    p = argparse.ArgumentParser()
    p.add_argument("--manifest", required=True, type=Path)
    p.add_argument("--project-root", required=True, type=Path)
    args = p.parse_args()
    entries = []
    for line in args.manifest.read_text(encoding="ascii").splitlines():
        if not line.strip():
            continue
        expected, relative = line.split("  ", 1)
        entries.append((expected, relative))
    if not entries:
        raise SystemExit("FAIL_EMPTY_MANIFEST")
    failures = []
    for expected, relative in entries:
        path = args.project_root / Path(relative)
        if not path.is_file():
            failures.append(f"MISSING {relative}")
        elif digest(path) != expected:
            failures.append(f"HASH_MISMATCH {relative}")
    if failures:
        print("\n".join(failures))
        print(f"FAIL_PROJECT_MANIFEST entries={len(entries)} failures={len(failures)}")
        return 1
    print(f"PASS_PROJECT_MANIFEST entries={len(entries)} root={args.project_root}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
