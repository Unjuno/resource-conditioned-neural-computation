#!/usr/bin/env python3
"""Bind a prepared primary/pilot case file to an actually compiled new SOF."""
import argparse,csv,hashlib,json,sys
from pathlib import Path
GATES=Path(__file__).resolve().parents[1]/'safety_gates_v1_20261122'
sys.path.insert(0,str(GATES))
from pilot_gate import verify_gate,ensure_unique_experiment_id
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--sof',type=Path,required=True);ap.add_argument('--firmware-manifest',type=Path,required=True);ap.add_argument('--quartus-audit',type=Path,required=True);ap.add_argument('--cases',type=Path,required=True);ap.add_argument('--split',choices=['pilot','primary'],required=True);ap.add_argument('--pilot-gate',type=Path);ap.add_argument('--out',type=Path,required=True);a=ap.parse_args()
 if a.out.exists():raise SystemExit('refusing existing binding output')
 fw=json.loads(a.firmware_manifest.read_text()); qa=json.loads(a.quartus_audit.read_text())
 if fw.get('status')!='RV32_IMAGE_BUILT_NOT_SIMULATED' or fw.get('build_id')!='45585631':raise SystemExit('new firmware identity/status mismatch')
 if qa.get('status')!='EMPIRICAL_BUILD_ELIGIBLE' or qa.get('external_jtag_timing')!='BLOCKED':raise SystemExit('Quartus/STA/CDC audit does not allow empirical build use')
 if not a.sof.is_file() or qa.get('sof_sha256')!=sha(a.sof):raise SystemExit('SOF does not match audited Quartus output')
 gate=None
 if a.split=='primary':
  if not a.pilot_gate:raise SystemExit('primary binding requires an independently validated pilot gate')
  gate=verify_gate(a.pilot_gate)
  if gate.get('sof_sha256')!=sha(a.sof) or gate.get('build_id')!=fw.get('build_id') or gate.get('firmware_elf_sha256')!=fw.get('elf_sha256'):raise SystemExit('pilot gate build/SOF/ELF differs from primary binding')
 elif a.pilot_gate:raise SystemExit('pilot binding must not consume a previous pilot gate')
 rows=list(csv.DictReader(a.cases.open(encoding='utf-8',newline=''))); expected={'pilot':20,'primary':7626}[a.split]
 if len(rows)!=expected:raise SystemExit(f'wrong {a.split} case count: {len(rows)} expected {expected}')
 if a.split=='primary':
  try:ensure_unique_experiment_id(Path(__file__).resolve().parents[1],rows[0]['experiment_id'])
  except ValueError as e:raise SystemExit(str(e))
 manifest=Path(__file__).resolve().parents[1]/'data'/f'{a.split}_manifest.csv'
 manifest_ids={r['input_id'] for r in csv.DictReader(manifest.open(encoding='utf-8',newline=''))}
 case_ids={r['input_id'] for r in rows}
 if case_ids!=manifest_ids or len(case_ids)*2!=expected:raise SystemExit(f'{a.split} case IDs do not match frozen manifest')
 seen=set()
 for r in rows:
  if r['model_id']!='52544e4e' or r['build_id']!='45585631' or r['binding_id']!='45585632':raise SystemExit('mixed case identity')
  if r['mode'] not in ('fixed2','adaptive') or len(bytes.fromhex(r['pixels_hex']))!=64:raise SystemExit('invalid mode/payload')
  if hashlib.sha256(bytes.fromhex(r['pixels_hex'])).hexdigest()!=r['pixels_sha256']:raise SystemExit('pixel SHA mismatch')
  k=(r['input_id'],r['mode'])
  if k in seen:raise SystemExit('duplicate input/mode')
  seen.add(k)
 b={'schema':'rtnn-external-validation-binding-v1','status':'PHYSICAL_ELIGIBLE','classification':'EMPIRICAL_ONLY','split':a.split,'experiment_id':rows[0]['experiment_id'],'session_id':rows[0]['session_id'],'case_count':len(rows),'cases_csv_sha256':sha(a.cases),'sof_sha256':sha(a.sof),'sof_path':str(a.sof.resolve()),'firmware_manifest_sha256':sha(a.firmware_manifest),'firmware_elf_sha256':fw['elf_sha256'],'firmware_bin_sha256':fw['bin_sha256'],'quartus_audit_sha256':sha(a.quartus_audit),'model_id':'52544e4e','model_core_sha256':fw['model_core_sha256'],'model_weights_header_sha256':fw['model_weights_header_sha256'],'build_id':'45585631','binding_id':'45585632','input_manifest_sha256':sha(Path(__file__).resolve().parents[1]/'data'/f'{a.split}_manifest.csv'),'preregistration_sha256':sha(Path(__file__).resolve().parents[1]/'PREREGISTRATION_LOCKED_JA.md'),'pilot_gate_path':str(a.pilot_gate.resolve()) if gate else None,'pilot_gate_sha256':sha(a.pilot_gate) if gate else None,'board':'Terasic DE0-CV / 5CEBA4F23C7','timing_classification':'EMPIRICAL_ONLY','external_jtag_timing':'BLOCKED','flash_written':False,'sof_programming_performed':False,'uart_used':False}
 a.out.parent.mkdir(parents=True,exist_ok=True);a.out.write_text(json.dumps(b,indent=2)+'\n',encoding='utf-8');print('PHYSICAL_BINDING_READY_EMPIRICAL_ONLY',sha(a.out))
if __name__=='__main__':main()
