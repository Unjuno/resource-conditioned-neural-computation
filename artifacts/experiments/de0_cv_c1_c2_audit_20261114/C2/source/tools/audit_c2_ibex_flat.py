#!/usr/bin/env python3
"""Compare fixed-Ibex module bodies in the C1 and C2 sv2v flat netlists."""
from __future__ import annotations

import argparse
import hashlib
import json
import re
from pathlib import Path

MODULE = re.compile(r"\bmodule\s+(?:automatic\s+)?([A-Za-z_$][\w$]*)\b(.*?)\bendmodule\b", re.S)


def digest(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def modules(path: Path) -> dict[str, str]:
    text = path.read_text(encoding="utf-8", errors="strict")
    text = re.sub(r"/\*.*?\*/|//[^\n]*", "", text, flags=re.S)
    return {name: re.sub(r"\s+", "", body) for name, body in MODULE.findall(text)}


def main() -> int:
    p = argparse.ArgumentParser()
    p.add_argument("--c1", required=True, type=Path)
    p.add_argument("--c2", required=True, type=Path)
    p.add_argument("--out", required=True, type=Path)
    a = p.parse_args()
    left, right = modules(a.c1), modules(a.c2)
    shared = sorted(name for name in left.keys() & right.keys() if name.startswith(("ibex_", "prim_")))
    missing = sorted(name for name in left if name.startswith(("ibex_", "prim_")) and name not in right)
    changed = [name for name in shared if left[name] != right[name]]
    result = {
        "status": "PASS_FIXED_IBEX_MODULES_MATCH" if len(shared) >= 120 and not missing and not changed else "FAIL",
        "c1_path": str(a.c1), "c1_sha256": digest(a.c1),
        "c2_path": str(a.c2), "c2_sha256": digest(a.c2),
        "matching_fixed_ibex_and_prim_modules": len(shared),
        "missing_modules": missing, "changed_modules": changed,
        "normalization": "comments and whitespace removed; module token text otherwise compared byte-for-byte",
    }
    a.out.parent.mkdir(parents=True, exist_ok=True)
    a.out.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(result, indent=2))
    return 0 if result["status"].startswith("PASS") else 1


if __name__ == "__main__":
    raise SystemExit(main())
