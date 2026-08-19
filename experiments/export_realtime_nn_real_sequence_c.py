import argparse, hashlib, json, math
from pathlib import Path
import numpy as np
import torch
import realtime_nn_real_sequence_generalization as r

def cf(x):
    s=format(float(np.float32(x)),'.9g')
    if 'e' not in s and '.' not in s: s+='.'+'0'
    return s+'f'
def write_arr(f,name,a):
    a=np.asarray(a,dtype=np.float32).reshape(-1);f.write(f'static const float {name}[{len(a)}] = {{\n')
    for i,x in enumerate(a):
        f.write(cf(x)+',')
        if (i+1)%8==0:f.write('\n')
    f.write('\n};\n')
def arr(t):return t.detach().cpu().float().contiguous().numpy()

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--seed',type=int,default=63);ap.add_argument('--steps',type=int,default=700);ap.add_argument('--outdir',default='/tmp/rtnn_real_sequence');a=ap.parse_args()
    od=Path(a.outdir);od.mkdir(parents=True,exist_ok=True);tr,va,te=r.data();m=r.train(a.seed,*tr,a.steps);tau,v,ev,max_exit=r.tune(m,*va);pref=r.choose(m,te[0],tau,max_exit)
    with torch.no_grad():z=m.forward_all(te[0]).cpu().numpy();pred=z.argmax(-1)
    tensors={'emb_w':arr(m.emb.weight),'emb_b':arr(m.emb.bias),'pos':arr(m.pos)}
    for bi,b in enumerate(m.blocks):
        items=[('n1_w',b.n1.weight),('n1_b',b.n1.bias),('att_in_w',b.att.in_proj_weight),('att_in_b',b.att.in_proj_bias),('att_out_w',b.att.out_proj.weight),('att_out_b',b.att.out_proj.bias),('n2_w',b.n2.weight),('n2_b',b.n2.bias),('a_w',b.a.weight),('a_b',b.a.bias),('b_w',b.b.weight),('b_b',b.b.bias)]
        for n,t in items:tensors[f'b{bi}_{n}']=arr(t)
    for k,h in enumerate(m.heads):tensors[f'h{k}_w']=arr(h.weight);tensors[f'h{k}_b']=arr(h.bias)
    with (od/'realtime_nn_real_sequence_weights_generated.h').open('w') as f:
        f.write('#ifndef RTNN_REAL_SEQUENCE_WEIGHTS_GENERATED_H\n#define RTNN_REAL_SEQUENCE_WEIGHTS_GENERATED_H\n')
        for k,t in tensors.items():write_arr(f,k,t)
        en=8193;lo=-32.;step=32/(en-1);f.write(f'#define RTNN_EXP_N {en}\n#define RTNN_EXP_LO ({cf(lo)})\n#define RTNN_EXP_STEP ({cf(step)})\n');write_arr(f,'rtnn_exp_lut',[math.exp(lo+i*step) for i in range(en)])
        gn=4097;glo=-8.;ghi=8.;gs=(ghi-glo)/(gn-1);f.write(f'#define RTNN_GELU_N {gn}\n#define RTNN_GELU_LO ({cf(glo)})\n#define RTNN_GELU_HI ({cf(ghi)})\n#define RTNN_GELU_STEP ({cf(gs)})\n');write_arr(f,'rtnn_gelu_lut',[.5*x*(1+math.erf(x/math.sqrt(2))) for x in [glo+i*gs for i in range(gn)]]);f.write('#endif\n')
    with (od/'realtime_nn_real_sequence_policy_generated.h').open('w') as f:f.write(f'#ifndef RTNN_REAL_SEQUENCE_POLICY_GENERATED_H\n#define RTNN_REAL_SEQUENCE_POLICY_GENERATED_H\n#define RTNN_REAL_SEQUENCE_POLICY_TAU {cf(tau)}\n#define RTNN_REAL_SEQUENCE_POLICY_MAX_EXIT {max_exit}u\n#endif\n')
    q=np.rint(te[0].cpu().numpy()*16).astype(np.uint8)
    with (od/'realtime_nn_real_sequence_test_generated.h').open('w') as f:
        f.write('#ifndef RTNN_REAL_SEQUENCE_TEST_GENERATED_H\n#define RTNN_REAL_SEQUENCE_TEST_GENERATED_H\n#include <stdint.h>\n#define RTNN_TEST_N 360\nstatic const uint8_t RTNN_TEST_X[RTNN_TEST_N][64]={\n')
        for row in q:f.write('{'+','.join(map(str,row.reshape(-1).tolist()))+'},\n')
        f.write('};\nstatic const uint8_t RTNN_TEST_Y[RTNN_TEST_N]={'+','.join(map(str,te[1].cpu().numpy().tolist()))+'};\nstatic const uint8_t RTNN_REF_PRED[7][RTNN_TEST_N]={\n')
        for p in pred:f.write('{'+','.join(map(str,p.tolist()))+'},\n')
        f.write('};\nstatic const uint8_t RTNN_REF_PREF[RTNN_TEST_N]={'+','.join(map(str,pref.cpu().numpy().tolist()))+'};\n#endif\n')
    classes=[]
    for k in range(7):
        d=min(k,max_exit);classes.append({'class':k,'fraction':k/6,'capability_max_blocks':k,'deployed_policy_max_blocks':d,'max_head_calls':d+1,'max_total_float_macs':1184+18592*d,'max_attention_exp_lut_calls':128*d,'max_entropy_exp_lut_calls':10*d,'max_gelu_lut_calls':256*d,'max_rsqrt_calls':16*d})
    man={'schema':'rtnn-real-sequence-max-work-v1','model':'sklearn digits / 8 row tokens / 6 optional attention+MLP blocks','seed':a.seed,'external_budget':'Q0.16 b in [0,1]','policy':{'max_exit':max_exit,'entropy_tau':tau},'workspace_bytes':4608,'heap_allocations':0,'file_io':0,'libm_calls':0,'classes':classes,'target_timing_bounds':None}
    canon=json.dumps(man,sort_keys=True,separators=(',',':')).encode();sha=hashlib.sha256(canon).hexdigest();man['canonical_sha256_without_sha_field']=sha;man['manifest_id_u64']='0x'+sha[:16];(od/'realtime_nn_real_sequence_max_work_manifest.json').write_text(json.dumps(man,indent=2))
    with (od/'realtime_nn_real_sequence_identity_generated.h').open('w') as f:f.write(f'#ifndef RTNN_REAL_SEQUENCE_IDENTITY_GENERATED_H\n#define RTNN_REAL_SEQUENCE_IDENTITY_GENERATED_H\n#include <stdint.h>\n#define RTNN_REAL_SEQUENCE_MANIFEST_ID UINT64_C(0x{sha[:16]})\n#define RTNN_REAL_SEQUENCE_MODEL_SEED {a.seed}u\n#endif\n')
    pa=r.eval_pref_full(m,*te,pref);print(json.dumps({'seed':a.seed,'tau':tau,'max_exit':max_exit,'test_exact':[float((pred[k]==te[1].cpu().numpy()).mean()) for k in range(7)],'test_policy':pa,'manifest_sha256':sha,'outdir':str(od)},indent=2))
if __name__=='__main__':main()
