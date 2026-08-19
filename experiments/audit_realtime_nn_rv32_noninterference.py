#!/usr/bin/env python3
"""Binary-level input/control-flow noninterference audit for the Q15 RTNN.

Scope: RV32IM fixed-class certification path. Input bytes are marked tainted.
The interpreter propagates taint through registers and memory. The audit fails if
input-derived data reaches a conditional branch condition or indirect control-flow
target. Input-derived memory addresses are reported separately because the pinned
Ibex Simple System uses deterministic address-independent one-cycle RAM.

This is a custom executable audit, not a mechanically verified WCET theorem.
"""
import argparse, csv, hashlib, json, re, subprocess
from collections import Counter
from pathlib import Path

RAM_LO = 0x00100000
RAM_HI = 0x00200000
RET_SENTINEL = 0xDEADBEE0


def sx(x, bits):
    m = 1 << (bits - 1)
    return (x ^ m) - m


def u32(x): return x & 0xFFFFFFFF

def s32(x): return sx(x & 0xFFFFFFFF, 32)


def sha256_file(path):
    h = hashlib.sha256()
    with open(path, 'rb') as f:
        for b in iter(lambda: f.read(1 << 20), b''):
            h.update(b)
    return h.hexdigest()


def parse_symbols(elf, objdump='llvm-objdump'):
    out = subprocess.check_output([objdump, '-t', str(elf)], text=True)
    syms = {}
    for line in out.splitlines():
        m = re.match(r'^([0-9a-fA-F]+)\s+\w\s+\w\s+\S+\s+[0-9a-fA-F]+\s+(.+)$', line.strip())
        if m:
            syms[m.group(2).strip()] = int(m.group(1), 16)
    return syms


class CPU:
    def __init__(self, binary, base=RAM_LO):
        self.mem = bytearray(RAM_HI - RAM_LO)
        data = Path(binary).read_bytes()
        off = base - RAM_LO
        if off < 0 or off + len(data) > len(self.mem):
            raise ValueError('binary does not fit modeled RAM')
        self.mem[off:off+len(data)] = data
        self.mt = bytearray(len(self.mem))
        self.r = [0] * 32
        self.t = [False] * 32
        self.pc = 0
        self.steps = 0
        self.trace_hash = hashlib.sha256()
        self.data_branches = []
        self.data_memaddrs = []
        self.data_indirect = []
        self.op_counts = Counter()

    def idx(self, a):
        if not RAM_LO <= a < RAM_HI:
            raise RuntimeError(f'address outside modeled RAM: {a:#x}')
        return a - RAM_LO

    def load(self, a, n, signed=False, addr_taint=False):
        i = self.idx(a)
        v = int.from_bytes(self.mem[i:i+n], 'little', signed=False)
        if signed: v = sx(v, n * 8)
        # A tainted address makes the selected value input-dependent even when
        # every table entry is individually public.
        ta = addr_taint or any(self.mt[i:i+n])
        return u32(v), ta

    def store(self, a, n, v, ta):
        i = self.idx(a)
        self.mem[i:i+n] = int(v & ((1 << (8*n)) - 1)).to_bytes(n, 'little')
        self.mt[i:i+n] = bytes([1 if ta else 0]) * n

    def wr(self, rd, v, ta=False):
        if rd:
            self.r[rd] = u32(v)
            self.t[rd] = bool(ta)

    def fetch(self):
        i = self.idx(self.pc)
        return int.from_bytes(self.mem[i:i+4], 'little')

    def step(self):
        pc = self.pc
        ins = self.fetch()
        self.trace_hash.update(pc.to_bytes(4, 'little'))
        self.steps += 1
        op = ins & 0x7F; rd = (ins >> 7) & 31; f3 = (ins >> 12) & 7
        rs1 = (ins >> 15) & 31; rs2 = (ins >> 20) & 31; f7 = (ins >> 25) & 0x7F
        a, ta = self.r[rs1], self.t[rs1]
        b, tb = self.r[rs2], self.t[rs2]
        nextpc = u32(pc + 4)

        if op == 0x37:  # LUI
            self.op_counts['lui'] += 1; self.wr(rd, ins & 0xFFFFF000)
        elif op == 0x17:  # AUIPC
            self.op_counts['auipc'] += 1; self.wr(rd, pc + (ins & 0xFFFFF000))
        elif op == 0x6F:  # JAL
            self.op_counts['jump'] += 1
            imm = ((ins>>31)&1)<<20 | ((ins>>12)&0xFF)<<12 | ((ins>>20)&1)<<11 | ((ins>>21)&0x3FF)<<1
            self.wr(rd, nextpc); nextpc = u32(pc + sx(imm, 21))
        elif op == 0x67:  # JALR
            self.op_counts['jump'] += 1
            imm = sx(ins >> 20, 12)
            if ta: self.data_indirect.append(pc)
            target = u32(a + imm) & ~1
            self.wr(rd, nextpc); nextpc = target
        elif op == 0x63:  # conditional branch
            self.op_counts['branch'] += 1
            imm = ((ins>>31)&1)<<12 | ((ins>>7)&1)<<11 | ((ins>>25)&0x3F)<<5 | ((ins>>8)&0xF)<<1
            imm = sx(imm, 13)
            if ta or tb: self.data_branches.append(pc)
            if f3 == 0: take = a == b
            elif f3 == 1: take = a != b
            elif f3 == 4: take = s32(a) < s32(b)
            elif f3 == 5: take = s32(a) >= s32(b)
            elif f3 == 6: take = a < b
            elif f3 == 7: take = a >= b
            else: raise RuntimeError(f'unsupported branch funct3={f3} at {pc:#x}')
            if take: nextpc = u32(pc + imm)
        elif op == 0x03:  # loads
            self.op_counts['load'] += 1
            imm = sx(ins >> 20, 12); addr = u32(a + imm)
            if ta: self.data_memaddrs.append(('load', pc))
            if f3 == 0: v, tv = self.load(addr, 1, True, ta)
            elif f3 == 1: v, tv = self.load(addr, 2, True, ta)
            elif f3 == 2: v, tv = self.load(addr, 4, False, ta)
            elif f3 == 4: v, tv = self.load(addr, 1, False, ta)
            elif f3 == 5: v, tv = self.load(addr, 2, False, ta)
            else: raise RuntimeError(f'unsupported load funct3={f3} at {pc:#x}')
            self.wr(rd, v, tv)
        elif op == 0x23:  # stores
            self.op_counts['store'] += 1
            imm = ((ins >> 25) << 5) | ((ins >> 7) & 0x1F); imm = sx(imm, 12)
            addr = u32(a + imm)
            if ta: self.data_memaddrs.append(('store', pc))
            n = {0:1, 1:2, 2:4}.get(f3)
            if n is None: raise RuntimeError(f'unsupported store funct3={f3} at {pc:#x}')
            self.store(addr, n, b, tb)
        elif op == 0x13:  # OP-IMM
            self.op_counts['alu'] += 1
            imm = sx(ins >> 20, 12)
            if f3 == 0: v = a + imm
            elif f3 == 2: v = int(s32(a) < imm)
            elif f3 == 3: v = int(a < u32(imm))
            elif f3 == 4: v = a ^ u32(imm)
            elif f3 == 6: v = a | u32(imm)
            elif f3 == 7: v = a & u32(imm)
            elif f3 == 1: v = a << ((ins >> 20) & 31)
            elif f3 == 5:
                sh = (ins >> 20) & 31
                v = s32(a) >> sh if ((ins >> 30) & 1) else a >> sh
            else: raise RuntimeError(f'unsupported op-imm funct3={f3} at {pc:#x}')
            self.wr(rd, v, ta)
        elif op == 0x33:  # OP / M-extension
            dep = ta or tb
            if f7 == 1:
                if f3 == 0: self.op_counts['mul'] += 1; v = a * b
                elif f3 == 1: self.op_counts['mul_high'] += 1; v = (s32(a) * s32(b)) >> 32
                elif f3 == 2: self.op_counts['mul_high'] += 1; v = (s32(a) * b) >> 32
                elif f3 == 3: self.op_counts['mul_high'] += 1; v = (a * b) >> 32
                elif f3 == 4:
                    self.op_counts['div'] += 1
                    aa, bb = s32(a), s32(b)
                    if b == 0: v = 0xffffffff
                    elif aa == -2147483648 and bb == -1: v = aa
                    else: v = int(aa / bb)
                elif f3 == 5:
                    self.op_counts['div'] += 1
                    v = 0xffffffff if b == 0 else a // b
                elif f3 == 6:
                    self.op_counts['div'] += 1
                    aa, bb = s32(a), s32(b)
                    if b == 0: v = aa
                    elif aa == -2147483648 and bb == -1: v = 0
                    else: v = aa - int(aa / bb) * bb
                elif f3 == 7:
                    self.op_counts['div'] += 1
                    v = a if b == 0 else a % b
                else: raise RuntimeError(f'unsupported M funct3={f3} at {pc:#x}')
            else:
                self.op_counts['alu'] += 1
                if f3 == 0: v = a - b if f7 == 0x20 else a + b
                elif f3 == 1: v = a << (b & 31)
                elif f3 == 2: v = int(s32(a) < s32(b))
                elif f3 == 3: v = int(a < b)
                elif f3 == 4: v = a ^ b
                elif f3 == 5: v = s32(a) >> (b & 31) if f7 == 0x20 else a >> (b & 31)
                elif f3 == 6: v = a | b
                elif f3 == 7: v = a & b
                else: raise RuntimeError(f'unsupported OP funct3={f3} at {pc:#x}')
            self.wr(rd, v, dep)
        elif op == 0x73:
            raise RuntimeError(f'CSR/system instruction encountered inside audited function at {pc:#x}')
        else:
            raise RuntimeError(f'unsupported opcode {op:#x} at {pc:#x} ins={ins:#x}')

        self.r[0] = 0; self.t[0] = False; self.pc = nextpc


def run_cert(binary, entry, cls, input_addr=None, synthetic_seed=0):
    c = CPU(binary)
    c.pc = entry; c.r[1] = RET_SENTINEL; c.r[2] = 0x001D0000
    workspace, out = 0x001C0000, 0x001B0000
    if input_addr is None:
        input_addr = 0x001E0000
        for i in range(64):
            c.store(input_addr+i, 1, (i*37 + synthetic_seed*13) & 0xFF, True)
    else:
        for i in range(64): c.mt[c.idx(input_addr+i)] = 1
    c.r[10] = workspace; c.r[11] = input_addr; c.r[12] = cls; c.r[13] = out
    while c.pc != RET_SENTINEL:
        if c.steps > 10_000_000: raise RuntimeError('instruction limit exceeded')
        c.step()
    z = []
    for i in range(10):
        v, _ = c.load(out + 4*i, 4)
        z.append(s32(v))
    return c, z


def run_infer(binary, entry, input_addr, bq=65535, deadline=5):
    c = CPU(binary)
    c.pc = entry; c.r[1] = RET_SENTINEL; c.r[2] = 0x001D0000
    workspace, out, executed = 0x001C0000, 0x001B0000, 0x001AFF00
    for i in range(64): c.mt[c.idx(input_addr+i)] = 1
    c.r[10] = workspace; c.r[11] = input_addr; c.r[12] = bq; c.r[13] = deadline; c.r[14] = out; c.r[15] = executed
    while c.pc != RET_SENTINEL:
        if c.steps > 10_000_000: raise RuntimeError('instruction limit exceeded')
        c.step()
    ex, _ = c.load(executed, 1)
    return c, ex


def exhaustive_lut_range_audit():
    S = 32768
    exp_min, exp_max = 1 << 30, -1
    for xc in range(-32*S, 1):
        off = xc - (-32*S); i = off >> 7; r = off & 127; top = i >> 13
        i -= top; r += top << 7
        exp_min = min(exp_min, i); exp_max = max(exp_max, i+1)
    gelu_min, gelu_max = 1 << 30, -1
    for xc in range(-8*S, 8*S+1):
        off = xc - (-8*S); i = off >> 7; r = off & 127; top = i >> 12
        i -= top; r += top << 7
        gelu_min = min(gelu_min, i); gelu_max = max(gelu_max, i+1)
    return {
        'exp_lut_length': 8193, 'exp_index_min': exp_min, 'exp_index_max': exp_max,
        'exp_in_bounds': 0 <= exp_min and exp_max < 8193,
        'gelu_lut_length': 4097, 'gelu_index_min': gelu_min, 'gelu_index_max': gelu_max,
        'gelu_in_bounds': 0 <= gelu_min and gelu_max < 4097,
    }


def enc_i(imm, rs1, f3, rd, op=0x13):
    return ((imm & 0xFFF) << 20) | ((rs1 & 31) << 15) | ((f3 & 7) << 12) | ((rd & 31) << 7) | op


def enc_b(imm, rs1, rs2, f3):
    x = imm & 0x1FFF
    return (((x >> 12) & 1) << 31) | (((x >> 5) & 0x3F) << 25) | ((rs2 & 31) << 20) | ((rs1 & 31) << 15) | ((f3 & 7) << 12) | (((x >> 1) & 0xF) << 8) | (((x >> 11) & 1) << 7) | 0x63


def negative_control_detects_tainted_branch():
    # lbu x5,0(x11); beq x5,x0,+8; addi x6,x0,1; jalr x0,0(x1)
    c = CPU.__new__(CPU)
    c.mem = bytearray(RAM_HI - RAM_LO); c.mt = bytearray(len(c.mem))
    c.r = [0] * 32; c.t = [False] * 32; c.pc = RAM_LO; c.steps = 0
    c.trace_hash = hashlib.sha256(); c.data_branches=[]; c.data_memaddrs=[]; c.data_indirect=[]; c.op_counts=Counter()
    prog = [enc_i(0,11,4,5,0x03), enc_b(8,5,0,0), enc_i(1,0,0,6), enc_i(0,1,0,0,0x67)]
    for i, ins in enumerate(prog): c.mem[i*4:i*4+4] = ins.to_bytes(4,'little')
    inp = 0x00110000; c.mem[c.idx(inp)] = 7; c.mt[c.idx(inp)] = 1
    c.r[11] = inp; c.r[1] = RET_SENTINEL
    while c.pc != RET_SENTINEL: c.step()
    return len(c.data_branches) == 1 and c.data_branches[0] == RAM_LO + 4


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--elf', required=True)
    ap.add_argument('--bin', required=True)
    ap.add_argument('--expected-elf-sha', default='')
    ap.add_argument('--expected-bin-sha', default='')
    ap.add_argument('--host-csv')
    ap.add_argument('--objdump', default='llvm-objdump')
    ap.add_argument('--out', default='results/realtime_nn_rv32_noninterference_results.json')
    a = ap.parse_args()
    syms = parse_symbols(a.elf, a.objdump)
    entry = syms['rtnn_fixed_certify_class']
    vec_addr = syms.get('RTNN_RTL_X')
    elf_sha, bin_sha = sha256_file(a.elf), sha256_file(a.bin)
    if a.expected_elf_sha and elf_sha != a.expected_elf_sha:
        raise SystemExit('ELF SHA mismatch: refusing to audit a different certification build')
    if a.expected_bin_sha and bin_sha != a.expected_bin_sha:
        raise SystemExit('binary SHA mismatch: refusing to audit a different certification build')

    classes = []
    for cls in range(7):
        c, _ = run_cert(a.bin, entry, cls)
        classes.append({
            'class': cls,
            'retired_instruction_model_steps': c.steps,
            'data_dependent_conditional_branch_events': len(c.data_branches),
            'data_dependent_conditional_branch_sites': sorted(hex(x) for x in set(c.data_branches)),
            'data_dependent_indirect_control_events': len(c.data_indirect),
            'data_dependent_indirect_control_sites': sorted(hex(x) for x in set(c.data_indirect)),
            'data_dependent_memory_address_events': len(c.data_memaddrs),
            'data_dependent_memory_load_sites': sorted(hex(pc) for kind, pc in set(c.data_memaddrs) if kind == 'load'),
            'data_dependent_memory_store_sites': sorted(hex(pc) for kind, pc in set(c.data_memaddrs) if kind == 'store'),
            'hardware_div_rem_instructions': c.op_counts.get('div', 0),
            'pc_trace_sha256': c.trace_hash.hexdigest(),
            'instruction_categories': dict(c.op_counts),
        })

    ref = {}
    if a.host_csv:
        for row in csv.reader(open(a.host_csv)):
            if row and row[0] == 'HOST' and row[1] == 'PRED':
                ref[(int(row[2]), int(row[3]))] = int(row[4])
    prediction_mismatches = []
    exact_vector_cases = 0
    interpreter_reference_cases = [(0,0),(0,5),(1,0),(1,3),(2,0),(2,5)]
    if vec_addr is not None and ref:
        for slot, cls in interpreter_reference_cases:
            c, z = run_cert(a.bin, entry, cls, input_addr=vec_addr + slot*64)
            pred = max(range(10), key=lambda i: z[i])
            exact_vector_cases += 1
            if pred != ref[(slot, cls)]:
                prediction_mismatches.append({'slot':slot,'class':cls,'got':pred,'expected':ref[(slot,cls)]})

    infer_entry = syms['rtnn_fixed_infer_budget']
    adaptive = []
    adaptive_execution_mismatches = []
    for slot in range(3):
        c, executed = run_infer(a.bin, infer_entry, vec_addr + slot*64)
        expected_exec = None
        if a.host_csv:
            for row in csv.reader(open(a.host_csv)):
                if row and row[0] == 'HOST' and row[1] == 'PREF' and int(row[2]) == slot:
                    expected_exec = int(row[4]); break
        if expected_exec is not None and executed != expected_exec:
            adaptive_execution_mismatches.append({'slot':slot,'got':executed,'expected':expected_exec})
        adaptive.append({
            'slot': slot, 'executed_exit': executed, 'expected_preferred_exit': expected_exec,
            'retired_instruction_model_steps': c.steps,
            'input_dependent_branch_events': len(c.data_branches),
            'input_dependent_branch_sites': sorted(hex(x) for x in set(c.data_branches)),
            'input_dependent_indirect_control_events': len(c.data_indirect),
            'input_dependent_memory_load_sites': sorted(hex(pc) for kind, pc in set(c.data_memaddrs) if kind == 'load'),
            'input_dependent_memory_store_sites': sorted(hex(pc) for kind, pc in set(c.data_memaddrs) if kind == 'store'),
            'hardware_div_rem_instructions': c.op_counts.get('div', 0),
        })

    lut = exhaustive_lut_range_audit()
    negative_control_pass = negative_control_detects_tainted_branch()
    no_data_control = all(x['data_dependent_conditional_branch_events'] == 0 and x['data_dependent_indirect_control_events'] == 0 for x in classes)
    memory_load_sites = sorted({s for x in classes for s in x['data_dependent_memory_load_sites']})
    memory_store_sites = sorted({s for x in classes for s in x['data_dependent_memory_store_sites']})
    fixed_no_div = all(x['hardware_div_rem_instructions'] == 0 for x in classes)
    adaptive_branch_sites = sorted({s for x in adaptive for s in x['input_dependent_branch_sites']})
    adaptive_only_one_control_site = len(adaptive_branch_sites) == 1 and all(x['input_dependent_indirect_control_events'] == 0 for x in adaptive)
    decision = 'PASS_WITH_SCOPE' if (
        no_data_control and fixed_no_div and not memory_store_sites and not prediction_mismatches and
        adaptive_only_one_control_site and not adaptive_execution_mismatches and negative_control_pass and
        lut['exp_in_bounds'] and lut['gelu_in_bounds']
    ) else 'FAIL'
    out = {
        'experiment': 'exact-RV32-binary input/control-flow noninterference audit',
        'decision': decision,
        'scope': 'custom taint interpreter over the exact pinned-RTL certification binary; proves no detected input-tainted branch/indirect-control dependence in fixed-class paths, conditional on interpreter correctness; not a formal WCET theorem',
        'artifact': {'elf_sha256':elf_sha,'binary_sha256':bin_sha,'entry_rtnn_fixed_certify_class':hex(entry),'vector_symbol_address':hex(vec_addr) if vec_addr else None},
        'classes': classes,
        'all_classes_zero_data_dependent_control_flow': no_data_control,
        'all_data_dependent_memory_load_sites': memory_load_sites,
        'all_data_dependent_memory_store_sites': memory_store_sites,
        'fixed_classes_zero_hardware_div_rem': fixed_no_div,
        'memory_address_interpretation': 'data-dependent addresses are LUT lookups; the pinned Simple System RAM has address-independent deterministic response, but this assumption must be revalidated for caches/external memories',
        'exact_embedded_vector_prediction_cases': exact_vector_cases,
        'exact_embedded_vector_prediction_mismatches': prediction_mismatches,
        'adaptive_path_audit': adaptive,
        'adaptive_execution_mismatches': adaptive_execution_mismatches,
        'adaptive_unique_input_dependent_control_sites': adaptive_branch_sites,
        'lut_index_exhaustive_audit': lut,
        'taint_analyzer_negative_control_detects_known_input_branch': negative_control_pass,
        'nonclaims': [
            'The custom taint interpreter is not a formally verified analyzer.',
            'Data-dependent LUT addresses remain; only control-flow noninterference is established by this audit.',
            'The result does not establish FPGA/ASIC/silicon WCET or timing under address-dependent memory latency.',
            'The adaptive early-stop path intentionally contains input-dependent stopping control flow; the audited fixed-class certification path is the maximum-work reference.'
        ]
    }
    Path(a.out).parent.mkdir(parents=True, exist_ok=True)
    Path(a.out).write_text(json.dumps(out, indent=2))
    print(json.dumps(out, indent=2))
    raise SystemExit(0 if decision == 'PASS_WITH_SCOPE' else 1)


if __name__ == '__main__': main()
