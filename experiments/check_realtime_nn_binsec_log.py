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
    ap.add_argument('--mode', choices=['control', 'full'], default='control')
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

    control_ok = (
        status == 'secure'
        and not incomplete
        and cf is not None and cf[0] == cf[1]
        and not control_leaks
    )

    if args.mode == 'control':
        decision = control_ok and mem is None
        expected_memory_leak = None
    else:
        expected_memory_leak = args.class_id >= 1
        memory_ok = mem is not None and (
            (mem[0] < mem[1] and bool(memory_leaks))
            if expected_memory_leak
            else (mem[0] == mem[1] and not memory_leaks)
        )
        # Generic full constant-time status may be insecure when the expected
        # LUT memory-address dependence is found. Control flow is judged
        # independently from that target-specific memory boundary.
        decision = (
            not incomplete
            and cf is not None and cf[0] == cf[1]
            and not control_leaks
            and memory_ok
            and status in ('secure', 'insecure')
        )

    out = {
        'class': args.class_id,
        'mode': args.mode,
        'decision': 'PASS_WITH_SCOPE' if decision else 'FAIL',
        'binsec_program_status': status,
        'exploration_incomplete': incomplete,
        'control_flow_checks_pass': cf,
        'memory_access_checks_pass': mem,
        'control_flow_leak_sites': control_leaks,
        'memory_access_leak_sites': memory_leaks,
        'expected_memory_address_dependence': expected_memory_leak,
        'interpretation': (
            'Independent BINSEC cross-check of the exact RTL-tested RV32 artifact. '
            'The all-class production audit checks neural-input independence of fixed-class control flow only. '
            'Known exp/GELU LUT address dependence remains a separate memory-model assumption.'
        )
    }
    Path(args.out).write_text(json.dumps(out, indent=2) + '\n')
    print(json.dumps(out, indent=2))
    raise SystemExit(0 if decision else 1)


if __name__ == '__main__':
    main()
