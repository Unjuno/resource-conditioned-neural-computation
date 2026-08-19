import argparse, hashlib, json, sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import realtime_nn_rv32_cycle_envelope as rv

# Keep emulator scratch outside the linked Simple System image.
rv.WS=0x180000; rv.INP=0x182000; rv.OUT=0x183000; rv.STACK=0x1ff000

SAMPLES=[
[0,0,5,13,9,1,0,0,0,0,13,15,10,15,5,0,0,3,15,2,0,11,8,0,0,4,12,0,0,8,8,0,0,5,8,0,0,9,8,0,0,4,11,0,1,12,7,0,0,2,14,5,10,12,0,0,0,0,6,13,10,0,0,0],
[0,0,0,12,13,5,0,0,0,0,4,16,16,13,0,0,0,0,0,9,13,16,2,0,0,0,0,3,16,12,0,0,0,0,0,3,16,8,0,0,0,0,0,6,16,4,0,0,0,0,2,15,16,15,8,0,0,0,1,13,16,16,11,0],
[0,0,5,15,12,0,0,0,0,3,15,8,14,0,0,0,0,2,13,0,14,0,0,0,0,5,12,8,16,4,0,0,0,4,15,16,16,16,7,0,0,0,3,8,10,12,8,0,0,0,3,12,2,13,4,0,0,0,5,14,14,5,0,0],
[0,0,0,3,14,5,0,0,0,0,2,15,14,15,1,0,0,0,8,13,2,14,3,0,0,1,16,8,0,11,8,0,0,4,16,5,0,8,8,0,0,4,16,3,0,10,7,0,0,2,14,9,9,15,1,0,0,0,1,13,16,7,0,0]
]

def main():
    ap=argparse.ArgumentParser(); ap.add_argument('elf'); ap.add_argument('--out',required=True); a=ap.parse_args()
    base,syms=rv.load_elf(Path(a.elf)); rows=[]
    for cls in range(7):
        runs=[rv.emulate(base,syms,p,cls) for p in SAMPLES]
        keys=['inst','branch','jump','load','store','mul','mul_high','cycle_envelope']
        same=all(all(x[0][k]==runs[0][0][k] for k in keys) for x in runs)
        if not same: raise SystemExit(f'class {cls}: input-dependent dynamic machine-code counts')
        rows.append({'class':cls,'counts':{k:runs[0][0][k] for k in keys},'four_input_counts_identical':True})
    out={'elf_sha256':hashlib.sha256(Path(a.elf).read_bytes()).hexdigest(),'model':'RTNN-IBEX pinned-RTL precheck','classes':rows}
    Path(a.out).write_text(json.dumps(out,indent=2)); print(json.dumps(out,indent=2))
if __name__=='__main__': main()
