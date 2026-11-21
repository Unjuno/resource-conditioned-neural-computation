#!/usr/bin/env python3
"""Host-side request/binding/result checks for the new external-input build."""
from __future__ import annotations
import argparse, csv, hashlib, json, struct, sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
MODEL_ID=0x52544e4e; BUILD_ID=0x45585631; BINDING_ID=0x45585632
REQ_LEN=100; RSP_LEN=60
def sha(data:bytes)->str:return hashlib.sha256(data).hexdigest()
def crc32(data:bytes)->int:
    c=0xffffffff
    for b in data:
        c^=b
        for _ in range(8): c=(c>>1)^(0xedb88320 if c&1 else 0)
    return c^0xffffffff

def make_request(seq:int,input_id:int,mode:str,pixels:bytes)->bytes:
    if len(pixels)!=64 or any(x>16 for x in pixels): raise ValueError('pixel payload invalid')
    if not 1<=input_id<=3823 or seq<=0: raise ValueError('sequence/input ID invalid')
    if mode not in ('fixed2','adaptive'): raise ValueError('mode invalid')
    md=1 if mode=='fixed2' else 3; fx=2 if mode=='fixed2' else 0
    h=bytearray(32); h[:4]=b'RTNQ'; h[4:8]=bytes((2,md,fx,0))
    struct.pack_into('<IHHIII',h,8,seq,input_id,65535,0,MODEL_ID,BUILD_ID)
    struct.pack_into('<I',h,28,crc32(h[:28]))
    return bytes(h)+pixels+struct.pack('<I',crc32(pixels))

def decode_response(b:bytes)->dict:
    if len(b)!=RSP_LEN or b[:4]!=b'RTNR' or b[4]!=3: raise ValueError('response framing/version')
    if crc32(b[:56])!=struct.unpack_from('<I',b,56)[0]: raise ValueError('response CRC')
    u8=lambda i:b[i]
    vals=struct.unpack_from('<IHHI',b,8)
    seq,input_id,budget,payload_crc=vals
    start,end=struct.unpack_from('<QQ',b,24)
    model,build,binding,flags=struct.unpack_from('<IIII',b,40)
    signed=lambda x:x-256 if x>=128 else x
    return {'status':u8(5),'mode':u8(6),'stop_reason':u8(7),'seq':seq,'input_id':input_id,
      'budget_q16':budget,'payload_crc32':payload_crc,'admitted_exit':signed(u8(20)),
      'executed_exit':signed(u8(21)),'prediction':signed(u8(22)),'label':signed(u8(23)),
      'cycles_start':start,'cycles_end':end,'model_id':model,'build_id':build,'binding_id':binding,'flags':flags}

def verify_response(r:dict,case:dict,expected:dict,binding:dict)->int:
    checks={'status':0,'mode':1 if case['mode']=='fixed2' else 3,'seq':int(case['seq']),
      'input_id':int(case['input_id']),'budget_q16':65535,'payload_crc32':int(case['payload_crc32']),
      'model_id':MODEL_ID,'build_id':BUILD_ID,'binding_id':BINDING_ID,'label':-1,
      'prediction':int(expected['prediction']),'admitted_exit':int(expected['admitted_exit']),
      'executed_exit':int(expected['executed_exit'])}
    for k,v in checks.items():
        if r[k]!=v: raise ValueError(f'{k} mismatch: response={r[k]} expected={v}')
    if r['cycles_start']==0 or r['cycles_end']<=r['cycles_start'] or r['flags']!=1:
        raise ValueError('counter invalid/zero span/wrap or missing valid flag')
    if r['stop_reason'] != (0 if case['mode']=='fixed2' else (1 if expected['stop_reason']=='entropy' else 2)):
        raise ValueError('stop reason mismatch')
    if binding['sof_sha256']!=case['sof_sha256'] or binding['build_id']!='45585631':
        raise ValueError('SOF/build binding mismatch')
    return r['cycles_end']-r['cycles_start']

def make_cases(experiment_id:str,session_id:str,split:str,out:Path,oracle_dir:Path):
    if split not in ('pilot','primary'): raise ValueError('split must be pilot or primary')
    man=list(csv.DictReader((ROOT/'data'/f'{split}_manifest.csv').open(encoding='utf-8',newline='')))
    raw=(ROOT/'data'/f'{split}_inputs.bin').read_bytes()
    oracle_path=oracle_dir/f'oracle_{split}.csv'
    oracle=list(csv.DictReader(oracle_path.open(encoding='utf-8',newline='')))
    if len(raw)!=64*len(man) or len(oracle)!=2*len(man): raise ValueError('input/oracle row count mismatch')
    by={(int(r['input_id']),r['mode']):r for r in oracle}
    ordinal_by_input={int(r['input_id']):i+1 for i,r in enumerate(man)}
    for r in oracle:
        if r['cap_violation']!='0': raise ValueError('CPU oracle cap violation')
    out.mkdir(parents=True,exist_ok=False)
    with (out/'cases.csv').open('w',encoding='utf-8',newline='') as f:
        w=csv.writer(f,lineterminator='\n'); w.writerow(['experiment_id','session_id','sequence','input_id','mode','pixels_hex','pixels_sha256','teacher_label','expected_prediction','expected_admitted_exit','expected_executed_exit','expected_stop_reason','payload_crc32','model_id','build_id','binding_id'])
        sequence=0
        indexed=list(zip(man,(raw[i:i+64] for i in range(0,len(raw),64))))
        indexed.sort(key=lambda item:bytes.fromhex(item[0]['pixel_sha256']))
        tra_sha=bytes.fromhex(json.loads((ROOT/'data/dataset_audit.json').read_text())['optdigits_tra_sha256'])
        for ordinal,(row,pixels) in enumerate(indexed,1):
            order_material=b'RTNN-EXTVAL-MODE-ORDER-v1\0'+tra_sha+int(row['input_id']).to_bytes(4,'little')
            adaptive_first=(hashlib.sha256(order_material).digest()[0]&0x80)!=0
            modes=('adaptive','fixed2') if adaptive_first else ('fixed2','adaptive')
            for mode in modes:
                sequence+=1; ref=by[(ordinal_by_input[int(row['input_id'])],mode)]; crc=crc32(pixels)
                # Labels are host-only columns; make_request takes pixels/mode only.
                w.writerow([experiment_id,session_id,sequence,row['input_id'],mode,pixels.hex(),sha(pixels),row['label_host_only'],ref['prediction'],ref['admitted_exit'],ref['executed_exit'],ref['stop_reason'],crc,f'{MODEL_ID:08x}',f'{BUILD_ID:08x}',f'{BINDING_ID:08x}'])
    print(f'HOST_CASES_CREATED_NOT_PHYSICAL split={split} cases={2*len(man)}')

def main():
    p=argparse.ArgumentParser(); sub=p.add_subparsers(dest='cmd',required=True)
    c=sub.add_parser('cases'); c.add_argument('--experiment-id',required=True); c.add_argument('--session-id',required=True); c.add_argument('--split',choices=['pilot','primary'],required=True); c.add_argument('--out',type=Path,required=True); c.add_argument('--oracle-dir',type=Path,required=True)
    a=p.parse_args()
    if a.cmd=='cases': make_cases(a.experiment_id,a.session_id,a.split,a.out,a.oracle_dir)
if __name__=='__main__':main()
