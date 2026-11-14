#!/usr/bin/env bash
set -euo pipefail
if (($# != 1)); then echo 'usage: build_c3_measurement_v2.sh NEW_OUTPUT_DIRECTORY' >&2; exit 2; fi
src=$(cd "$(dirname "$0")" && pwd)
out=$1
[[ ! -e "$out" ]] || { echo "Refusing existing output destination: $out" >&2; exit 2; }
mkdir -p "$out"
for tool in clang ld.lld llvm-objcopy readelf sha256sum python3; do command -v "$tool" >/dev/null || { echo "Missing tool $tool" >&2; exit 2; }; done
flags=(--target=riscv32-unknown-elf -march=rv32im_zicsr -mabi=ilp32 -O2 -std=c11 -ffreestanding -fno-builtin -fno-pic -fno-pie -fuse-ld=lld -nostdlib -Wl,--no-relax -Wl,-T,"$src/firmware/rtnn_experiment.ld")
clang "${flags[@]}" -DC2_BUILD_ID=0x43334531 -I"$src/model" -I"$src/generated" -I"$src/firmware" \
 "$src/firmware/rtnn_experiment_start.S" "$src/model/realtime_nn_real_sequence_fixed_core.c" \
 "$src/firmware/rtnn_experiment_wire.c" "$src/firmware/rtnn_experiment_runner.c" \
 "$src/firmware/rtnn_c2_main.c" "$src/firmware/rtnn_freestanding_mem.c" \
 -o "$out/rtnn_c3_measurement_v2.elf" 2>&1 | tee "$out/compiler.log"
llvm-objcopy -O binary "$out/rtnn_c3_measurement_v2.elf" "$out/rtnn_c3_measurement_v2.bin"
python3 "$src/tools_build_b_image.py" --elf "$out/rtnn_c3_measurement_v2.elf" --bin "$out/rtnn_c3_measurement_v2.bin" --out-dir "$out" | tee "$out/build_b_image.log"
python3 - "$out" <<'PY'
import hashlib,json,sys
from pathlib import Path
out=Path(sys.argv[1])
words=(out/'rtnn_ram_words.hex').read_text().splitlines()
if len(words)!=65536 or any(len(w)!=8 for w in words): raise SystemExit('bad RAM words')
lanes=[bytearray() for _ in range(4)]
for w in words:
 v=int(w,16)
 for i in range(4):lanes[i].append((v>>(8*i))&255)
for i,data in enumerate(lanes):(out/f'rtnn_ram_lane{i}.hex').write_text(''.join(f'{b:02x}\n' for b in data),encoding='ascii')
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
m={'schema':'rtnn-c3-measurement-protocol-v2-build-v1','build_id':'43334531','binding_id':'43334531','response_protocol_version':2,'response_bytes':60,'request_bytes':100,'cycle_start_offset':24,'cycle_end_offset':32,'crc_offset':56,'elf_sha256':sha(out/'rtnn_c3_measurement_v2.elf'),'bin_sha256':sha(out/'rtnn_c3_measurement_v2.bin'),'ram_words_sha256':sha(out/'rtnn_ram_words.hex'),'ram_lane_sha256':{f'rtnn_ram_lane{i}.hex':sha(out/f'rtnn_ram_lane{i}.hex') for i in range(4)},'measurement_boundary':'64-bit Ibex mcycle sampled after request/pixel validation and immediately before admission/inference; end sampled after inference and argmax; JTAG transfer/response commit excluded','nonclaims':['not yet RTL-simulated','not synthesized or timed','not programmed to FPGA','not WCET or timing signoff']}
(out/'build_manifest.json').write_text(json.dumps(m,indent=2)+'\n')
print('C3_MEASUREMENT_V2_RV32_IMAGE_BUILT_NOT_SIMULATED',m['elf_sha256'])
PY
