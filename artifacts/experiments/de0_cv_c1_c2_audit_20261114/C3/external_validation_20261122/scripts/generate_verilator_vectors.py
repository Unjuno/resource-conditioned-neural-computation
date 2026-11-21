#!/usr/bin/env python3
import csv,sys
from pathlib import Path
src=Path(sys.argv[1]); out=Path(sys.argv[2]); rows=list(csv.DictReader((src/'cases.csv').open(encoding='utf-8',newline='')))
if len(rows)!=20:raise SystemExit('Verilator pilot vectors must contain the frozen 20 cases')
req=[]; exp=[]
for r in rows:
    pixels=bytes.fromhex(r['pixels_hex']); header=bytearray(32);header[:4]=b'RTNQ';mode=1 if r['mode']=='fixed2' else 3;fx=2 if mode==1 else 0;header[4:8]=bytes((2,mode,fx,0))
    import struct,zlib
    struct.pack_into('<IHHIII',header,8,int(r['sequence']),int(r['input_id']),65535,0,0x52544e4e,0x45585631)
    struct.pack_into('<I',header,28,zlib.crc32(header[:28]))
    wire=bytes(header)+pixels+struct.pack('<I',zlib.crc32(pixels))
    req.append(f'{int.from_bytes(wire,"little"):0200x}')
    fields=[int(r['sequence']),int(r['input_id']),mode,int(r['expected_admitted_exit']),int(r['expected_executed_exit']),int(r['expected_prediction']),255,65535,{'none':0,'entropy':1,'budget':2}[r['expected_stop_reason']],zlib.crc32(pixels)]
    value=fields[0]|(fields[1]<<32)|(fields[2]<<64)|(fields[3]<<96)|(fields[4]<<128)|(fields[5]<<160)|(fields[6]<<192)|(fields[7]<<224)|(fields[8]<<240)|(fields[9]<<272)
    exp.append(f'{value:076x}')
out.mkdir(parents=True,exist_ok=False);(out/'external_requests.hex').write_text('\n'.join(req)+'\n',encoding='ascii');(out/'external_expected.hex').write_text('\n'.join(exp)+'\n',encoding='ascii')
print(f'VERILATOR_DYNAMIC_VECTORS_CREATED_NOT_PHYSICAL cases={len(rows)}')
