#!/usr/bin/env python3
"""Create an isolated Quartus project with new firmware RAM and build ID."""
import argparse, hashlib, json, shutil
from pathlib import Path

HERE=Path(__file__).resolve().parents[1]
SOURCE=HERE.parent/'evidence'/'C3_MEASUREMENT_V2_QUARTUS_RETRY02_20261115'
BUILD='45585631'
FILES=['rtnn_c3_measurement_v2_quartus_flat.v','rtnn_de0_cv_c2_top.sv','rtnn_c2_global_buf.v','rtnn_c3_measurement_v2.sdc','rtnn_c3_measurement_v2.qsf','rtnn_c3_measurement_v2.qpf']
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--firmware-image',type=Path,required=True);p.add_argument('--out',type=Path,required=True);a=p.parse_args()
 if a.out.exists():raise SystemExit(f'refusing existing project directory: {a.out}')
 mf=json.loads((a.firmware_image/'external_firmware_manifest.json').read_text())
 if mf.get('build_id')!=BUILD or mf.get('status')!='RV32_IMAGE_BUILT_NOT_SIMULATED':raise SystemExit('firmware image/build identity mismatch')
 a.out.mkdir(parents=True)
 for n in FILES:shutil.copy2(SOURCE/n,a.out/n)
 rtl=a.out/FILES[0]; text=rtl.read_text(encoding='utf-8'); old="32'h43334531"; new=f"32'h{BUILD}"
 if text.count(old)!=1:raise SystemExit(f'expected exactly one old RTL build identity, found {text.count(old)}')
 rtl.write_text(text.replace(old,new),encoding='utf-8',newline='\n')
 qsf=a.out/'rtnn_c3_measurement_v2.qsf'; q=qsf.read_text(encoding='utf-8')
 q=q.replace("RTNN_C2_BUILD_ID=32'h43334531",f"RTNN_C2_BUILD_ID=32'h{BUILD}")
 if "RTNN_C2_BUILD_ID=32'h"+BUILD not in q:raise SystemExit('QSF build macro update failed')
 qsf.write_text(q,encoding='utf-8',newline='\n')
 for i in range(4):shutil.copy2(a.firmware_image/f'rtnn_ram_lane{i}.hex',a.out/f'rtnn_ram_lane{i}.hex')
 manifest={'schema':'rtnn-external-validation-quartus-project-v1','status':'PROJECT_INPUTS_PREPARED_NOT_COMPILED','build_id':BUILD,'device':'5CEBA4F23C7','top':'rtnn_de0_cv_c2_top','firmware_manifest_sha256':sha(a.firmware_image/'external_firmware_manifest.json'),'firmware_elf_sha256':mf['elf_sha256'],'firmware_bin_sha256':mf['bin_sha256'],'model_source_sha256':sha(HERE/'firmware/model/realtime_nn_real_sequence_fixed_core.c'),'model_weights_header_sha256':sha(HERE/'firmware/model/realtime_nn_real_sequence_fixed_weights_generated.h'),'project_input_sha256':{n:sha(a.out/n) for n in FILES+ [f'rtnn_ram_lane{i}.hex' for i in range(4)]},'changes':['patched exactly one generated flat RTL BUILD_ID literal 43334531->45585631','updated QSF build macro','replaced all four firmware RAM init lanes from new RV32 image'],'nonclaims':['No Quartus compile/fit/timing/physical pass implied.','Inherited SDC still has unresolved external JTAG timing; formal signoff remains blocked.']}
 (a.out/'project_manifest.json').write_text(json.dumps(manifest,indent=2)+'\n',encoding='utf-8')
 print('QUARTUS_PROJECT_INPUTS_PREPARED_NOT_COMPILED',a.out)
if __name__=='__main__':main()
