import argparse, math, struct
from pathlib import Path
Q=7; SCALE=1<<Q

def q16(x):
    q=round(float(x)*SCALE)
    if q < -32768 or q > 32767: raise ValueError(f'Q7 value out of int16 range: {q}')
    return int(q)

def emit(f,name,vals,per=16):
    f.write(f'static const int16_t {name}[{len(vals)}] = {{\n')
    for i,v in enumerate(vals):
        f.write(str(v)+',')
        if (i+1)%per==0: f.write('\n')
    f.write('\n};\n')

def main():
    ap=argparse.ArgumentParser(); ap.add_argument('float_binary'); ap.add_argument('--out',default='realtime_nn_structured_width_q7_generated.h'); a=ap.parse_args()
    raw=Path(a.float_binary).read_bytes(); n=struct.unpack_from('<I',raw,0)[0]; vals=struct.unpack_from(f'<{n}f',raw,4)
    qweights=[q16(x) for x in vals]; xs=[-8.0+16.0*i/256.0 for i in range(257)]
    tanh=[q16(math.tanh(x)) for x in xs]; gelu=[q16(.5*x*(1+math.erf(x/math.sqrt(2)))) for x in xs]
    with open(a.out,'w') as f:
        f.write('#ifndef RTNN_SW_Q7_GENERATED_H\n#define RTNN_SW_Q7_GENERATED_H\n#include <stdint.h>\n#define RTNN_SW_Q 7\n#define RTNN_SW_SCALE 128\n')
        f.write(f'#define RTNN_SW_WEIGHT_COUNT {n}\n'); emit(f,'RTNN_SW_QWEIGHTS',qweights); emit(f,'RTNN_SW_QTANH',tanh); emit(f,'RTNN_SW_QGELU',gelu); f.write('#endif\n')
    print({'weight_count':n,'weight_bytes':2*n,'lut_bytes':1028,'max_weight_abs':max(abs(x) for x in qweights)})
if __name__=='__main__': main()
