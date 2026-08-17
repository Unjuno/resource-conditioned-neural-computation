import argparse, hashlib, json, re, shutil, subprocess, tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

HASH_TEST = r'''
#include <stdint.h>
#include <stdio.h>
#include "realtime_nn_fixed_q5_core.h"
static RTNNQ5Workspace W;
static uint64_t h=UINT64_C(1469598103934665603);
static void add16(int16_t x){uint16_t u=(uint16_t)x;h^=(uint8_t)u;h*=UINT64_C(1099511628211);h^=(uint8_t)(u>>8);h*=UINT64_C(1099511628211);}
int main(void){if(!rtnn_q5_init())return 2;for(int c=0;c<5;c++)for(int s=0;s<512;s++){RTNNQ5Result r=rtnn_q5_infer(&W,(uint16_t)s,(uint8_t)c);add16(r.logit0);add16(r.logit1);}printf("%016llx\n",(unsigned long long)h);return 0;}
'''


def run(cmd):
    return subprocess.check_output(cmd, text=True)


def main():
    ap=argparse.ArgumentParser()
    ap.add_argument('--seed',type=int,default=0)
    ap.add_argument('--out',default=str(ROOT/'results'/'realtime_nn_compiler_matrix_results.json'))
    a=ap.parse_args()
    compilers=[c for c in ('gcc','clang') if shutil.which(c)]
    opts=('O0','O1','O2','O3','Os')
    rows=[]
    with tempfile.TemporaryDirectory(prefix='rtnn-compiler-') as td:
        t=Path(td)
        subprocess.check_call(['python',str(ROOT/'experiments'/'export_realtime_nn_fixed_q5.py'),'--seed',str(a.seed),'--out-dir',str(t)])
        (t/'hash_test.c').write_text(HASH_TEST)
        for cc in compilers:
            for opt in opts:
                obj=t/f'{cc}_{opt}.o'; exe=t/f'{cc}_{opt}'
                subprocess.check_call([cc,f'-{opt}','-std=c11','-ffreestanding','-fno-builtin','-fno-stack-protector',f'-I{t}',f'-I{ROOT / "experiments"}','-c',str(ROOT/'experiments'/'realtime_nn_fixed_q5_core.c'),'-o',str(obj)])
                undef=[x for x in run(['nm','-u',str(obj)]).splitlines() if x.strip()]
                dis=run(['objdump','-d',str(obj)])
                mn=[]
                for line in dis.splitlines():
                    m=re.search(r'\t([a-z][a-z0-9.]*)\s',line)
                    if m: mn.append(m.group(1))
                cond=sum(1 for x in mn if x.startswith('j') and x not in ('jmp','jmpq'))
                div=sum(1 for x in mn if x.startswith('div') or x.startswith('idiv'))
                size=run(['size',str(obj)]).splitlines()[-1].split()
                subprocess.check_call([cc,f'-{opt}','-std=c11',f'-I{t}',f'-I{ROOT / "experiments"}',str(t/'hash_test.c'),str(obj),'-o',str(exe)])
                output_hash=run([str(exe)]).strip()
                rows.append({
                    'compiler':cc,'optimization':opt,'undefined_external_symbols':len(undef),
                    'conditional_jump_count':cond,'div_or_idiv_instruction_count':div,
                    'text_bytes':int(size[0]),'data_bytes':int(size[1]),'bss_bytes':int(size[2]),
                    'functional_output_hash':output_hash,
                    'object_sha256':hashlib.sha256(obj.read_bytes()).hexdigest(),
                })
    out={
        'setup':{'seed':a.seed,'compilers':compilers,'optimizations':list(opts),'note':'Host x86_64 compiler/code-generation audit; not WCET.'},
        'rows':rows,
        'aggregate':{
            'build_count':len(rows),
            'unique_object_hashes':len({r['object_sha256'] for r in rows}),
            'unique_functional_output_hashes':len({r['functional_output_hash'] for r in rows}),
            'all_zero_undefined_external_symbols':all(r['undefined_external_symbols']==0 for r in rows),
            'all_zero_div_or_idiv':all(r['div_or_idiv_instruction_count']==0 for r in rows),
            'conditional_jump_min':min(r['conditional_jump_count'] for r in rows),
            'conditional_jump_max':max(r['conditional_jump_count'] for r in rows),
            'text_bytes_min':min(r['text_bytes'] for r in rows),
            'text_bytes_max':max(r['text_bytes'] for r in rows),
        },
        'interpretation':'Functionally identical RTNN source/manifest can compile to different machine-code objects; timing certification must therefore be bound to a certified build identity, not only the neural work manifest.'
    }
    Path(a.out).write_text(json.dumps(out,indent=2))
    print(json.dumps(out['aggregate'],indent=2))

if __name__=='__main__': main()
