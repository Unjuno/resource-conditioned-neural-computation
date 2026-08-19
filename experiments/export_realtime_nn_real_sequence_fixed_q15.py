import argparse, hashlib, json, math
from pathlib import Path
import numpy as np
import torch
import realtime_nn_real_sequence_generalization as r

Q=15; S=1<<Q; PQ=17; PS=1<<PQ

def arr(t): return t.detach().cpu().float().contiguous().numpy()
def q15(a): return np.rint(np.asarray(a,dtype=np.float64)*S).astype(np.int64)
def write_arr(f,name,a,ctype='int32_t'):
    a=np.asarray(a).reshape(-1); f.write(f'static const {ctype} {name}[{len(a)}] = {{\n')
    for i,x in enumerate(a):
        f.write(str(int(x))+',')
        if (i+1)%16==0: f.write('\n')
    f.write('\n};\n')

def main():
    ap=argparse.ArgumentParser(); ap.add_argument('--seed',type=int,default=63); ap.add_argument('--steps',type=int,default=700); ap.add_argument('--outdir',default='/tmp/rtnn_real_sequence_fixed'); a=ap.parse_args()
    od=Path(a.outdir); od.mkdir(parents=True,exist_ok=True)
    tr,va,te=r.data(); m=r.train(a.seed,*tr,a.steps); tau,_,_,max_exit=r.tune(m,*va); tau_q=int(round(tau*S))
    tensors={'emb_w':arr(m.emb.weight),'emb_b':arr(m.emb.bias),'pos':arr(m.pos)}
    for bi,b in enumerate(m.blocks):
        items=[('n1_w',b.n1.weight),('n1_b',b.n1.bias),('att_in_w',b.att.in_proj_weight),('att_in_b',b.att.in_proj_bias),('att_out_w',b.att.out_proj.weight),('att_out_b',b.att.out_proj.bias),('n2_w',b.n2.weight),('n2_b',b.n2.bias),('a_w',b.a.weight),('a_b',b.a.bias),('b_w',b.b.weight),('b_b',b.b.bias)]
        for n,t in items: tensors[f'b{bi}_{n}']=arr(t)
    for k,h in enumerate(m.heads): tensors[f'h{k}_w']=arr(h.weight); tensors[f'h{k}_b']=arr(h.bias)
    exp=np.rint(np.exp(np.linspace(-32.,0.,8193))*PS).astype(np.int64)
    xs=np.linspace(-8.,8.,4097); gel=np.rint((.5*xs*(1+np.vectorize(math.erf)(xs/math.sqrt(2.))))*S).astype(np.int64)
    out=od/'realtime_nn_real_sequence_fixed_weights_generated.h'
    with out.open('w') as f:
        f.write('#ifndef RTNN_REAL_SEQUENCE_FIXED_WEIGHTS_GENERATED_H\n#define RTNN_REAL_SEQUENCE_FIXED_WEIGHTS_GENERATED_H\n#include <stdint.h>\n')
        f.write(f'#define RTNN_FX_Q {Q}\n#define RTNN_FX_S {S}\n#define RTNN_FX_PQ {PQ}\n#define RTNN_FX_PS {PS}\n#define RTNN_FX_POLICY_MAX_EXIT {max_exit}\n#define RTNN_FX_POLICY_TAU_Q {tau_q}\n')
        for k,t in tensors.items(): write_arr(f,k,q15(t))
        write_arr(f,'fx_exp_lut',exp,'uint32_t'); write_arr(f,'fx_gelu_lut',gel); f.write('#endif\n')
    h=hashlib.sha256(); h.update(b'RTNN-Q15-v1'); h.update(bytes([a.seed,Q,PQ,max_exit])); h.update(int(tau_q).to_bytes(4,'little',signed=True))
    for k,t in tensors.items(): h.update(k.encode()+b'\0'); h.update(q15(t).astype('<i4').tobytes())
    h.update(b'exp\0'+exp.astype('<u4').tobytes()); h.update(b'gelu\0'+gel.astype('<i4').tobytes()); canonical=h.hexdigest()
    meta={'seed':a.seed,'q':Q,'probability_q':PQ,'float_tau':tau,'tau_q':tau_q,'tau_q_real':tau_q/S,'max_exit':max_exit,'canonical_model_sha256':canonical,'model_id_u32':'0x'+canonical[:8],'generated_header_sha256':hashlib.sha256(out.read_bytes()).hexdigest()}
    (od/'realtime_nn_real_sequence_fixed_meta.json').write_text(json.dumps(meta,indent=2)); print(json.dumps(meta,indent=2))
if __name__=='__main__': main()
