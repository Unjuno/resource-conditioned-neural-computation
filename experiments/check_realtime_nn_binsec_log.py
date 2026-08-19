#!/usr/bin/env python3
import argparse
import json
import re
from pathlib import Path


def pair(text, label):
    m = re.search(rf"(\d+)\s*/\s*(\d+)\s+{re.escape(label)} checks pass", text)
    return None if m is None else (int(m.group(1)), int(m.group(2)))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--log', required=True)
    ap.add_argument('--class-id', type=int, required=True)
    ap.add_argument('--out', required=True)
    args = ap.parse_args()
    text = Path(args.log).read_text(errors='replace')
    cf = pair(text, 'control flow')
    mem = pair(text, 'memory access')
    status_m = re.search(r"Program status is\s*:\s*(secure|insecure|unknown)", text)
    status = status_m.group(1) if status_m else None
    control_leaks = sorted(set(re.findall(r"Instruction\s+(0x[0-9a-fA-F]+)\s+has control flow leak", text)))
    memory_leaks = sorted(set(re.findall(r"Instruction\s+(0x[0-9a-fA-F]+)\s+has memory access leak", text)))
    incomplete = 'Exploration is incomplete' in text

    # Class 0 never executes an optional block and should have neither
    # control-flow nor LUT-address dependence. Classes >=1 are expected to
    # retain data-dependent exp/GELU LUT addresses, while control flow must
    # remain independent of neural input.
    expected_memory_leak = args.class_id >= 1
    decision = (
        status is not None
        and not incomplete
        and cf is not None and cf[0] == cf[1]
        and not control_leaks
        and mem is not None
        and ((mem[0] < mem[1] and bool(memory_leaks)) if expected_memory_leak else (mem[0] == mem[1] and not memory_leaks))
    )
    out = {
        'class': args.class_id,
        'decision': 'PASS_WITH_SCOPE' if decision else 'FAIL',
        'binsec_program_status': status,
        'exploration_incomplete': incomplete,
        'control_flow_checks_pass': cf,
        'memory_access_checks_pass': mem,
        'control_flow_leak_sites': control_leaks,
        'memory_access_leak_sites': memory_leaks,
        'expected_memory_address_dependence': expected_memory_leak,
        'interpretation': (
            'Independent BINSEC cross-check: fixed-class neural input must not alter control flow. '
            'Input-dependent LUT addresses are expected for nonzero classes and are target-timing benign only under the pinned deterministic RAM model.'
        )
    }
    Path(args.out).write_text(json.dumps(out, indent=2) + '\n')
    print(json.dumps(out, indent=2))
    raise SystemExit(0 if decision else 1)


if __name__ == '__main__':
    main()
