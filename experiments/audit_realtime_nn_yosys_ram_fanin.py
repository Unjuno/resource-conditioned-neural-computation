#!/usr/bin/env python3
import argparse
import json
from pathlib import Path


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--json", required=True)
    ap.add_argument("--out", required=True)
    a = ap.parse_args()

    design = json.loads(Path(a.json).read_text())
    if "ram_2p" not in design["modules"]:
        raise SystemExit(f"ram_2p missing; modules={list(design['modules'])}")
    m = design["modules"]["ram_2p"]

    ports = m["ports"]
    cells = m["cells"]
    target_bits = ports["a_rvalid_o"]["bits"]
    if len(target_bits) != 1:
        raise SystemExit("a_rvalid_o is not one bit")
    target = target_bits[0]

    drivers = {}
    for cname, cell in cells.items():
        dirs = cell.get("port_directions", {})
        for pname, bits in cell.get("connections", {}).items():
            if dirs.get(pname) == "output":
                for bit in bits:
                    if isinstance(bit, int):
                        drivers.setdefault(bit, []).append((cname, pname, cell))

    ds = drivers.get(target, [])
    if len(ds) != 1:
        raise SystemExit(f"expected one driver for a_rvalid_o, got {[(x[0],x[1]) for x in ds]}")
    cname, qport, cell = ds[0]
    ctype = cell["type"]
    if ctype not in ("$adff", "$adffe"):
        raise SystemExit(f"a_rvalid_o driver is not async-reset FF: {ctype}")

    conn = cell["connections"]
    d_bits = conn.get("D", [])
    clk_bits = conn.get("CLK", [])
    arst_bits = conn.get("ARST", [])
    if d_bits != ports["a_req_i"]["bits"]:
        raise SystemExit(f"FF D is not exactly a_req_i: {d_bits} vs {ports['a_req_i']['bits']}")
    if clk_bits != ports["clk_i"]["bits"]:
        raise SystemExit("FF clock is not exactly clk_i")
    if arst_bits != ports["rst_ni"]["bits"]:
        raise SystemExit("FF async reset is not exactly rst_ni")

    # Generic transitive fan-in to ensure address bits do not reach the target.
    primary_by_bit = {}
    for pname, p in ports.items():
        if p["direction"] == "input":
            for bit in p["bits"]:
                if isinstance(bit, int):
                    primary_by_bit.setdefault(bit, set()).add(pname)

    visiting = set()
    memo = {}
    def cone(bit):
        if not isinstance(bit, int):
            return set()
        if bit in memo:
            return memo[bit]
        if bit in visiting:
            return set()
        visiting.add(bit)
        out = set(primary_by_bit.get(bit, set()))
        for _, _, c in drivers.get(bit, []):
            dirs = c.get("port_directions", {})
            for pname, bits in c.get("connections", {}).items():
                if dirs.get(pname) == "input":
                    for b in bits:
                        out |= cone(b)
        visiting.remove(bit)
        memo[bit] = out
        return out

    fanin = sorted(cone(target))
    forbidden = [x for x in fanin if "addr" in x]
    if forbidden:
        raise SystemExit(f"address signal reached a_rvalid_o fanin: {forbidden}")
    if "a_req_i" not in fanin or "clk_i" not in fanin or "rst_ni" not in fanin:
        raise SystemExit(f"expected request/clock/reset in response-valid cone, got {fanin}")

    params = cell.get("parameters", {})
    arst_value = params.get("ARST_VALUE")
    result = {
        "decision": "PASS",
        "module": "ram_2p",
        "target": "a_rvalid_o",
        "driver_cell": cname,
        "driver_type": ctype,
        "q_port": qport,
        "d_is_exact_a_req_i": True,
        "clock_is_exact_clk_i": True,
        "async_reset_is_exact_rst_ni": True,
        "async_reset_value": arst_value,
        "primary_input_fanin": fanin,
        "address_signals_in_fanin": forbidden,
        "address_independent_response_valid": True,
        "interpretation": "The synthesized control netlist for pinned ram_2p drives a_rvalid_o with one async-reset FF whose D input is exactly a_req_i. No address bit is in the response-valid transitive fan-in. With reset deasserted, a data-port request is therefore reflected in response-valid on the next active clock independently of the requested RAM address."
    }
    Path(a.out).write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
