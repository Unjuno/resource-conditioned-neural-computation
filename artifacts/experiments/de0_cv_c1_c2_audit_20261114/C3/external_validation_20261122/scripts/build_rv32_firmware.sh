#!/usr/bin/env bash
set -euo pipefail
here=$(cd "$(dirname "$0")/.." && pwd)
out=${1:?usage: build_rv32_firmware.sh NEW_OUTPUT_DIRECTORY}
[[ ! -e "$out" ]] || { echo "refusing existing output: $out" >&2; exit 2; }
for tool in clang ld.lld llvm-objcopy readelf sha256sum python3; do command -v "$tool" >/dev/null || { echo "missing tool: $tool" >&2; exit 2; }; done
mkdir -p "$out"
python3 - "$here/firmware/model" <<'PY'
import hashlib,sys
from pathlib import Path
p=Path(sys.argv[1]); expected={
 'realtime_nn_real_sequence_fixed_weights_generated.h':'961a76b7e220bf2f665e7c04ab62063600aa2e7eccf3403d80ea730bc993ad9f',
 'realtime_nn_real_sequence_fixed_core.c':'a6b2807bd4a60534c250fca3005322cf14ba0a92f6b16e28241109385efc6809',}
for name,want in expected.items():
 got=hashlib.sha256((p/name).read_bytes()).hexdigest()
 if got!=want: raise SystemExit(f'FROZEN_MODEL_SHA_MISMATCH {name} expected={want} actual={got}')
print('FROZEN_MODEL_SHA_PASS',len(expected))
PY
flags=(--target=riscv32-unknown-elf -march=rv32im_zicsr -mabi=ilp32 -O2 -std=c11
       -ffreestanding -fno-builtin -fno-pic -fno-pie -fuse-ld=lld -nostdlib
       -Wl,--no-relax -Wl,-T,"$here/firmware/src/rtnn_experiment.ld")
clang "${flags[@]}" -I"$here/firmware/model" -I"$here/firmware/src" \
  "$here/firmware/src/rtnn_experiment_start.S" \
  "$here/firmware/model/realtime_nn_real_sequence_fixed_core.c" \
  "$here/firmware/src/rtnn_external_wire.c" \
  "$here/firmware/src/rtnn_external_runner.c" \
  "$here/firmware/src/rtnn_external_main.c" \
  "$here/firmware/src/rtnn_freestanding_mem.c" \
  -o "$out/rtnn_external_validation.elf" 2>&1 | tee "$out/compiler.log"
llvm-objcopy -O binary "$out/rtnn_external_validation.elf" "$out/rtnn_external_validation.bin"
python3 "$here/firmware/tools/build_b_image.py" --elf "$out/rtnn_external_validation.elf" \
  --bin "$out/rtnn_external_validation.bin" --out-dir "$out" | tee "$out/image.log"
python3 - "$out" <<'PY'
import hashlib,json,sys
from pathlib import Path
p=Path(sys.argv[1]); words=(p/'rtnn_ram_words.hex').read_text().splitlines()
if len(words)!=65536 or any(len(x)!=8 for x in words): raise SystemExit('bad RAM image')
lanes=[bytearray() for _ in range(4)]
for word in words:
    n=int(word,16)
    for lane in range(4): lanes[lane].append((n>>(lane*8))&255)
def sha(x): return hashlib.sha256(x).hexdigest()
lane_sha={}
for i,b in enumerate(lanes):
    data=''.join(f'{x:02x}\n' for x in b).encode('ascii')
    (p/f'rtnn_ram_lane{i}.hex').write_bytes(data); lane_sha[f'rtnn_ram_lane{i}.hex']=sha(data)
manifest=json.loads((p/'fpga_b_image_manifest.json').read_text())
manifest.update(schema='rtnn-external-validation-rv32-v1',build_id='45585631',binding_id='45585632',model_id='52544e4e',
                lane_sha256=lane_sha,firmware_sources=['rtnn_external_main.c','rtnn_external_runner.c','rtnn_external_wire.c','realtime_nn_real_sequence_fixed_core.c'],
                model_core_sha256=hashlib.sha256((p.parents[1]/'firmware/model/realtime_nn_real_sequence_fixed_core.c').read_bytes()).hexdigest(),
                model_weights_header_sha256=hashlib.sha256((p.parents[1]/'firmware/model/realtime_nn_real_sequence_fixed_weights_generated.h').read_bytes()).hexdigest(),
                compiler=__import__('subprocess').check_output(['clang','--version'],text=True).splitlines()[0],
                linker=__import__('subprocess').check_output(['ld.lld','--version'],text=True).splitlines()[0],
                status='RV32_IMAGE_BUILT_NOT_SIMULATED',nonclaims=['No FPGA simulation, Quartus compilation, timing signoff, or physical test implied by ELF/image creation.'])
(p/'external_firmware_manifest.json').write_text(json.dumps(manifest,indent=2)+'\n',encoding='utf-8')
print('RV32_IMAGE_BUILT_NOT_SIMULATED',manifest['elf_sha256'])
PY
