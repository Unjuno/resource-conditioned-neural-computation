#!/usr/bin/env python3
import argparse
import hashlib
import json
import re
import struct
import subprocess
from pathlib import Path

EXPECTED_ELF_SHA = "234a7f46cf227a11f5d97f3c778cbb0c4ed4f7067f8994bcca86c4b08ff4e742"
EXPECTED_BIN_SHA = "266ecb70c723b2164f6fe9039f27d4cb49c4d7271d4aca0cf69f2692cdfdf7a1"
RAM_BASE = 0x00100000
RAM_SIZE = 0x00100000
RAM_END_EXCLUSIVE = RAM_BASE + RAM_SIZE
EXPECTED_LUTS = {
    "fx_gelu_lut": 4097 * 4,
    "fx_exp_lut": 8193 * 4,
}
EXPECTED_INPUT_INDEXED_LOAD_SITES = [0x1002EC, 0x1002F0, 0x10152C, 0x101530]
IBEX_COMMIT = "7b5df75a041affe56e8c235260f98a09b3319008"
DEVICE_MAP = {
    "Ram": (0x00100000, 0xFFF00000),
    "SimCtrl": (0x00020000, 0xFFFFFC00),
    "Timer": (0x00030000, 0xFFFFFC00),
}


def sha256(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def symbols(elf: Path):
    text = subprocess.check_output(["readelf", "-sW", str(elf)], text=True)
    out = {}
    for line in text.splitlines():
        m = re.match(r"\s*\d+:\s+([0-9a-fA-F]+)\s+(\d+)\s+OBJECT\s+\w+\s+\w+\s+\d+\s+(\S+)$", line)
        if m:
            out[m.group(3)] = {"addr": int(m.group(1), 16), "size": int(m.group(2))}
    return out


def load_segments(elf: Path):
    data = elf.read_bytes()
    if data[:4] != b"\x7fELF" or data[4] != 1 or data[5] != 1:
        raise SystemExit("expected little-endian ELF32")
    e_phoff = struct.unpack_from("<I", data, 28)[0]
    e_phentsize = struct.unpack_from("<H", data, 42)[0]
    e_phnum = struct.unpack_from("<H", data, 44)[0]
    segs = []
    for i in range(e_phnum):
        o = e_phoff + i * e_phentsize
        p_type, p_offset, p_vaddr, p_paddr, p_filesz, p_memsz, p_flags, p_align = struct.unpack_from("<IIIIIIII", data, o)
        if p_type == 1:
            segs.append({"offset": p_offset, "vaddr": p_vaddr, "filesz": p_filesz, "memsz": p_memsz})
    return data, segs


def word_at_vaddr(elf: Path, addr: int) -> int:
    data, segs = load_segments(elf)
    for s in segs:
        if s["vaddr"] <= addr and addr + 4 <= s["vaddr"] + s["filesz"]:
            off = s["offset"] + addr - s["vaddr"]
            return struct.unpack_from("<I", data, off)[0]
    raise SystemExit(f"address {addr:#x} is not in a file-backed LOAD segment")


def decode_lw(word: int):
    opcode = word & 0x7F
    funct3 = (word >> 12) & 7
    return {
        "word": f"0x{word:08x}",
        "opcode": opcode,
        "funct3": funct3,
        "rd": (word >> 7) & 31,
        "rs1": (word >> 15) & 31,
        "imm12": (word >> 20) & 0xFFF,
        "is_lw": opcode == 0x03 and funct3 == 0x2,
    }


def require_text(path: Path, snippets):
    text = path.read_text()
    missing = [s for s in snippets if s not in text]
    if missing:
        raise SystemExit(f"{path}: missing pinned structural snippets: {missing}")
    return text


def devices_for(addr: int):
    return [name for name, (base, mask) in DEVICE_MAP.items() if (addr & mask) == base]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--elf", required=True)
    ap.add_argument("--bin", required=True)
    ap.add_argument("--noninterference", default="results/realtime_nn_rv32_noninterference_results.json")
    ap.add_argument("--ram-rtl", required=True)
    ap.add_argument("--bus-rtl", required=True)
    ap.add_argument("--system-rtl", required=True)
    ap.add_argument("--out", required=True)
    a = ap.parse_args()

    elf, binary = Path(a.elf), Path(a.bin)
    if sha256(elf) != EXPECTED_ELF_SHA:
        raise SystemExit("ELF SHA mismatch")
    if sha256(binary) != EXPECTED_BIN_SHA:
        raise SystemExit("binary SHA mismatch")

    syms = symbols(elf)
    lut_results = {}
    all_lut_word_addrs = []
    for name, expected_size in EXPECTED_LUTS.items():
        if name not in syms:
            raise SystemExit(f"missing symbol {name}")
        s = syms[name]
        if s["size"] != expected_size:
            raise SystemExit(f"{name}: size {s['size']} != {expected_size}")
        lo = s["addr"]
        hi = lo + s["size"] - 1
        ok = RAM_BASE <= lo <= hi < RAM_END_EXCLUSIVE and lo % 4 == 0 and s["size"] % 4 == 0
        if not ok:
            raise SystemExit(f"{name}: range outside aligned RAM: {lo:#x}..{hi:#x}")
        words = list(range(lo, lo + s["size"], 4))
        all_lut_word_addrs.extend(words)
        lut_results[name] = {
            "base": f"0x{lo:08x}",
            "size_bytes": s["size"],
            "word_count": len(words),
            "last_word": f"0x{words[-1]:08x}",
            "last_byte": f"0x{hi:08x}",
            "entirely_inside_ram": True,
            "word_aligned": True,
        }

    # Exact exhaustive bus decode for every legal word address in both LUTs.
    bad_decode = []
    for addr in all_lut_word_addrs:
        matches = devices_for(addr)
        if matches != ["Ram"]:
            bad_decode.append({"addr": f"0x{addr:08x}", "matches": matches})
    if bad_decode:
        raise SystemExit(f"LUT bus decode is not uniquely RAM: first={bad_decode[:3]}")

    ni = json.loads(Path(a.noninterference).read_text())
    sites = sorted(int(x, 16) for x in ni["all_data_dependent_memory_load_sites"])
    if sites != EXPECTED_INPUT_INDEXED_LOAD_SITES:
        raise SystemExit(f"input-indexed load sites changed: {[hex(x) for x in sites]}")
    if ni["all_data_dependent_memory_store_sites"]:
        raise SystemExit("unexpected input-indexed store sites")

    load_decodes = {}
    for addr in sites:
        d = decode_lw(word_at_vaddr(elf, addr))
        if not d["is_lw"]:
            raise SystemExit(f"{addr:#x} is no longer a 32-bit LW: {d}")
        load_decodes[f"0x{addr:08x}"] = d

    ram = Path(a.ram_rtl)
    bus = Path(a.bus_rtl)
    system = Path(a.system_rtl)
    require_text(ram, [
        "Dual-port RAM with 1 cycle read/write delay",
        "a_rvalid_o <= a_req_i;",
        "assign b_rvalid_d = (BExtraDelay == 0) ? b_req_i : b_rvalid_q[BExtraDelay-1];",
    ])
    require_text(bus, [
        "All devices (slaves) must respond in the next cycle after the request.",
        "host_gnt_o[host_sel_req] = host_req_i[host_sel_req];",
        "device_sel_resp <= device_sel_req;",
        "host_sel_resp <= host_sel_req;",
        "host_rvalid_o[host] = device_rvalid_i[device_sel_resp] | decode_err_resp;",
        "device_req_o[device]   = host_req_i[host_sel_req];",
        "device_addr_o[device]  = host_addr_i[host_sel_req];",
    ])
    require_text(system, [
        "localparam int NrDevices = 3;",
        "localparam int NrHosts = 1;",
        "assign cfg_device_addr_base[Ram] = 32'h100000;",
        "assign cfg_device_addr_mask[Ram] = ~32'hFFFFF; // 1 MB",
        "assign cfg_device_addr_base[SimCtrl] = 32'h20000;",
        "assign cfg_device_addr_mask[SimCtrl] = ~32'h3FF; // 1 kB",
        "assign cfg_device_addr_base[Timer] = 32'h30000;",
        "assign cfg_device_addr_mask[Timer] = ~32'h3FF; // 1 kB",
        ".Depth(1024*1024/4)",
        ".a_req_i     (device_req[Ram])",
        ".a_addr_i    (device_addr[Ram])",
        ".a_rvalid_o  (device_rvalid[Ram])",
    ])

    out = {
        "experiment": "exact RTNN LUT-address to pinned Ibex deterministic-RAM timing audit",
        "decision": "PASS_WITH_SCOPE",
        "artifact": {
            "elf_sha256": EXPECTED_ELF_SHA,
            "binary_sha256": EXPECTED_BIN_SHA,
        },
        "ibex_commit": IBEX_COMMIT,
        "ram_region": {
            "base": f"0x{RAM_BASE:08x}",
            "end_exclusive": f"0x{RAM_END_EXCLUSIVE:08x}",
            "size_bytes": RAM_SIZE,
        },
        "device_map": {
            name: {"base": f"0x{base:08x}", "mask": f"0x{mask:08x}"}
            for name, (base, mask) in DEVICE_MAP.items()
        },
        "lut_ranges": lut_results,
        "lut_word_addresses_exhaustively_checked": len(all_lut_word_addrs),
        "lut_words_uniquely_decode_to_ram": len(all_lut_word_addrs),
        "lut_decode_failures": bad_decode,
        "input_indexed_load_sites": load_decodes,
        "input_indexed_store_sites": [],
        "structural_checks": {
            "ram_data_response_valid_is_registered_from_request": True,
            "ram_documented_one_cycle_read_write_delay": True,
            "simple_system_single_data_host": True,
            "simple_system_has_three_devices_with_pinned_maps": True,
            "all_legal_lut_word_addresses_uniquely_decode_to_ram": True,
            "simple_system_data_port_wires_bus_ram_request_address_and_response": True,
            "bus_request_to_selected_ram_is_combinational": True,
            "bus_response_selection_is_registered_for_next_cycle": True,
            "bus_host_response_uses_selected_device_rvalid": True,
            "bus_contract_requires_next_cycle_device_response": True,
        },
        "composed_lut_read_response_latency_cycles": 1,
        "interpretation": "Every neural-input-indexed load in the exact RTL-tested binary is an aligned LW into one of two finite LUTs fully resident in the pinned Simple System 1MiB RAM. Every one of the 12,290 legal LUT word addresses uniquely decodes to Ram and not SimCtrl/Timer. The bus forwards the one host request/address to the selected RAM, registers the selected device for the response cycle, and returns that device's rvalid. In pinned ram_2p, the data-port response-valid is a one-cycle register of the request and its synthesized fan-in has no address bit. Thus LUT read response timing is one cycle and address independent within this exact Simple System memory model.",
        "nonclaims": [
            "This does not prove constant latency for caches, external SDRAM, arbitration fabrics, or DE0-CV memory; those require target-specific evidence.",
            "This does not prove data values are address-independent; only response timing is claimed address-independent under the pinned RAM model.",
            "The composed timing statement depends on the exact one-host Simple System bus/device map and pinned ram_2p RTL; another integration requires re-analysis.",
        ],
    }
    Path(a.out).write_text(json.dumps(out, indent=2) + "\n")
    print(json.dumps(out, indent=2))


if __name__ == "__main__":
    main()
