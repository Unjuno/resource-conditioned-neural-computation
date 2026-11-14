#!/usr/bin/env python3
"""Apply a narrowly scoped sv2v-to-Quartus compatibility rewrite."""
from __future__ import annotations
import argparse, hashlib, re
from pathlib import Path

EXPECTED_INPUT_SHA256 = "79dafafd592e0c6ef2910429513ede3199546bc7e13173cfc54820de24f0d2b5"
PATTERN = re.compile(rb"(?m)^([ \t]*)reg unused_scramble_inputs = (.+);$")

def sha(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()

def main() -> int:
    p = argparse.ArgumentParser()
    p.add_argument("--input", required=True, type=Path)
    p.add_argument("--output", required=True, type=Path)
    a = p.parse_args()
    if a.output.exists():
        raise SystemExit(f"refusing to overwrite {a.output}")
    data = a.input.read_bytes()
    before = sha(data)
    if before != EXPECTED_INPUT_SHA256:
        raise SystemExit(f"unexpected sv2v input SHA: {before}")
    matches = list(PATTERN.finditer(data))
    if len(matches) != 1:
        raise SystemExit(f"expected exactly one unused_scramble_inputs initializer, found {len(matches)}")
    if data.count(b"unused_scramble_inputs") != 1:
        raise SystemExit("unused_scramble_inputs has additional references; do not rewrite")
    m = matches[0]
    indent, expression = m.group(1), m.group(2)
    replacement = indent + b"wire unused_scramble_inputs;\n" + indent + b"assign unused_scramble_inputs = " + expression + b";"
    rewritten = data[:m.start()] + replacement + data[m.end():]
    a.output.parent.mkdir(parents=True, exist_ok=True)
    a.output.write_bytes(rewritten)
    print(f"status=PASS_SINGLE_UNUSED_SIGNAL_REWRITE input_sha256={before} output_sha256={sha(rewritten)}")
    print("rewrite=SV time-zero variable initialization to continuous wire assignment; signal has no reads")
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
