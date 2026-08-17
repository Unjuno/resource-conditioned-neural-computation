import argparse, json, re
from pathlib import Path

Q_SCALE=32
C=32
F=128
BLOCKS=8


def parse_array(text,name):
    m=re.search(rf'static const int16_t {name}\[\d+\] = \{{(.*?)\}};',text,re.S)
    if not m:
        raise ValueError(f'missing array {name}')
    return [int(x) for x in re.findall(r'-?\d+',m.group(1))]


def audit(path):
    text=Path(path).read_text()
    weights=parse_array(text,'RTNN_QWEIGHTS')
    tanh=parse_array(text,'RTNN_QTANH')
    gelu=parse_array(text,'RTNN_QGELU')
    off=0
    def take(n):
        nonlocal off
        out=weights[off:off+n]
        off+=n
        return out
    emb=take(2*C)
    layers=[]
    for block in range(BLOCKS):
        cur=[]
        for out_n,in_n,name in ((C,C,'self'),(C,C,'neigh'),(F,C,'ff1'),(C,F,'ff2')):
            w=take(out_n*in_n); b=take(out_n)
            cur.append((out_n,in_n,name,w,b))
        layers.append(cur)
    head_w=take(2*C); head_b=take(2)
    if off != len(weights):
        raise ValueError('unexpected weight count')

    emb_abs=max(abs(x) for x in emb)
    tanh_abs=max(abs(x) for x in tanh)
    gelu_abs=max(abs(x) for x in gelu)
    rows=[]
    def linear_bound(name,out_n,in_n,w,b,input_abs):
        vals=[]
        for o in range(out_n):
            row=w[o*in_n:(o+1)*in_n]
            vals.append(abs(b[o])*Q_SCALE + sum(abs(v) for v in row)*input_abs)
        rows.append({'name':name,'input_abs_bound':input_abs,'max_accumulator_abs_bound':max(vals)})

    for block,cur in enumerate(layers):
        h_abs=emb_abs if block==0 else tanh_abs
        for out_n,in_n,name,w,b in cur:
            input_abs=h_abs if name in ('self','neigh') else tanh_abs if name=='ff1' else gelu_abs
            linear_bound(f'block{block}.{name}',out_n,in_n,w,b,input_abs)
    linear_bound('head.class0',2,C,head_w,head_b,emb_abs)
    linear_bound('head.after_blocks',2,C,head_w,head_b,tanh_abs)

    max_acc=max(r['max_accumulator_abs_bound'] for r in rows)
    max_postshift=(max_acc + 16)//32
    return {
        'header':str(path),
        'weight_count':len(weights),
        'embedding_abs_bound':emb_abs,
        'tanh_lut_abs_bound':tanh_abs,
        'gelu_lut_abs_bound':gelu_abs,
        'max_linear_accumulator_abs_bound':max_acc,
        'max_linear_postshift_abs_bound':max_postshift,
        'int32_limit':2**31-1,
        'int16_limit':32767,
        'int32_fraction':max_acc/(2**31-1),
        'int16_fraction':max_postshift/32767,
        'linear_rows':rows,
    }


def main():
    ap=argparse.ArgumentParser()
    ap.add_argument('headers',nargs='+')
    ap.add_argument('--out')
    a=ap.parse_args()
    result=[audit(p) for p in a.headers]
    text=json.dumps(result,indent=2)
    if a.out:
        Path(a.out).write_text(text)
    print(text)

if __name__=='__main__':
    main()
