import argparse, math
from pathlib import Path
import torch
import realtime_nn_budget_execution as b

Q=5
SCALE=1<<Q


def emit_array(f,name,vals,ctype='int16_t',per=16):
    f.write(f'static const {ctype} {name}[{len(vals)}] = {{\n')
    for i,v in enumerate(vals):
        f.write(str(int(v))+',')
        if (i+1)%per==0:
            f.write('\n')
    f.write('\n};\n')


def quantize_i16(t):
    q=torch.round(t.detach().cpu().float().reshape(-1)*SCALE).to(torch.int32)
    if int(q.min()) < -32768 or int(q.max()) > 32767:
        raise ValueError('Q5 tensor does not fit int16')
    return q.to(torch.int16).tolist()


def main():
    ap=argparse.ArgumentParser()
    ap.add_argument('--seed',type=int,default=0)
    ap.add_argument('--out-dir',default='.')
    a=ap.parse_args()
    m=b.train(a.seed).eval()
    vals=[]
    def add(t):
        vals.extend(quantize_i16(t))
    add(m.emb.weight)
    for blk in m.blocks:
        for layer in (blk.selfp,blk.neigh,blk.ff1,blk.ff2):
            add(layer.weight); add(layer.bias)
    add(m.head.weight); add(m.head.bias)
    xs=torch.linspace(-8,8,257,dtype=torch.float64)
    tanh=quantize_i16(torch.tanh(xs))
    gelu=quantize_i16(0.5*xs*(1+torch.erf(xs/math.sqrt(2))))
    out=Path(a.out_dir); out.mkdir(parents=True,exist_ok=True)
    with (out/'realtime_nn_fixed_q5_generated.h').open('w') as f:
        f.write('#ifndef RTNN_Q5_GENERATED_H\n#define RTNN_Q5_GENERATED_H\n#include <stdint.h>\n')
        f.write(f'#define RTNN_Q {Q}\n#define RTNN_SCALE {SCALE}\n#define RTNN_WEIGHT_COUNT {len(vals)}\n')
        emit_array(f,'RTNN_QWEIGHTS',vals)
        emit_array(f,'RTNN_QTANH',tanh)
        emit_array(f,'RTNN_QGELU',gelu)
        f.write('#endif\n')
    print({'seed':a.seed,'weights':len(vals),'weight_bytes':2*len(vals),'lut_bytes':2*(len(tanh)+len(gelu))})

if __name__=='__main__':
    main()
