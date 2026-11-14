#!/usr/bin/env python3
"""Rebind the frozen C2 42-case RTL vectors to the separate v2 build ID."""
import argparse, csv, hashlib, json, struct, zlib
from pathlib import Path

BUILD_ID=0x43334531
EXPECTED_OLD_BUILD='43324a31'

def sha(p): return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--cases',type=Path,required=True);p.add_argument('--out',type=Path,required=True);a=p.parse_args()
 if a.out.exists(): raise SystemExit(f'refuse existing output: {a.out}')
 a.out.mkdir(parents=True)
 rows=list(csv.DictReader(a.cases.open(newline='',encoding='utf-8-sig')))
 if len(rows)!=42: raise SystemExit(f'frozen C2 regression source must contain 42 cases, got {len(rows)}')
 reqs=[];expected=[]
 for row in rows:
  if row['build_id'].lower()!=EXPECTED_OLD_BUILD: raise SystemExit('unexpected frozen C2 source build ID')
  payload=bytearray.fromhex(row['jtag_request_100b_hex'])
  if len(payload)!=100 or payload[:4]!=b'RTNQ' or payload[4]!=1: raise SystemExit(f"bad frozen request seq={row['seq']}")
  if payload[32:96].hex()!=row['pixels_u8_64_hex'] or struct.unpack_from('<I',payload,96)[0]!=zlib.crc32(payload[32:96]): raise SystemExit('frozen input/pixel CRC mismatch')
  struct.pack_into('<I',payload,24,BUILD_ID)
  struct.pack_into('<I',payload,28,zlib.crc32(payload[:28]))
  reqs.append(payload[::-1].hex())
  vals=[int(row[k]) for k in ('seq','input_id','mode','expected_admitted','expected_executed','expected_prediction','expected_label','budget_q16','expected_stop')]
  expected.append(struct.pack('<9I',*vals)[::-1].hex())
 (a.out/'c2_requests.hex').write_text('\n'.join(reqs)+'\n',encoding='ascii')
 (a.out/'c2_expected.hex').write_text('\n'.join(expected)+'\n',encoding='ascii')
 m={'schema':'rtnn-c3-protocol-v2-soc-regression-vectors-v1','case_count':42,'frozen_cases_sha256':sha(a.cases),'source_frozen_build_id':EXPECTED_OLD_BUILD,'simulation_build_id':f'{BUILD_ID:08x}','requests_sha256':sha(a.out/'c2_requests.hex'),'expected_sha256':sha(a.out/'c2_expected.hex'),'rebind_scope':'Only RTNQ build_id and corresponding RTNQ header CRC changed; frozen input, pixel CRC, case order, all expected values remain from original C2 case CSV. Simulation only.'}
 (a.out/'vector_manifest.json').write_text(json.dumps(m,indent=2)+'\n',encoding='utf-8')
 print('V2_SOC_VECTORS_READY cases=42',m['requests_sha256'],m['expected_sha256'])
if __name__=='__main__':main()
