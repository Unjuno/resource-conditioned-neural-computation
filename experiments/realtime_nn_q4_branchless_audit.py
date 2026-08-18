import argparse, json, re, shutil, subprocess, sys, tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
EXP = ROOT / "experiments"
TARGETS = {
    "cortex_m0": ["--target=armv6m-none-eabi", "-mcpu=cortex-m0", "-mthumb"],
    "cortex_m4_soft": ["--target=armv7em-none-eabi", "-mcpu=cortex-m4", "-mthumb", "-mfloat-abi=soft"],
    "rv32im": ["--target=riscv32-unknown-elf", "-march=rv32im", "-mabi=ilp32"],
}
ARM_BRANCH = re.compile(r"\b(?:beq|bne|bge|bgt|ble|blt|bhi|bls|bcc|bcs|bmi|bpl|bvs|bvc|cbz|cbnz)\b", re.I)
RV_BRANCH = re.compile(r"\b(?:beq|bne|blt|bge|bltu|bgeu|beqz|bnez|blez|bgez|bltz|bgtz)\b", re.I)

CHECK_C = r'''
#include <stdio.h>
#include "realtime_nn_q4_i8_core.h"
static RTNNQ4I8Workspace W;
static int label(unsigned x){int n=0;for(int i=0;i<9;i++)n+=(x>>i)&1u;return n>=5;}
int main(void){if(!rtnn_q4_i8_init())return 2;for(int c=0;c<5;c++){int ok=0;long long sum=0;for(int x=0;x<512;x++){RTNNQ4I8Result r=rtnn_q4_i8_infer(&W,(uint16_t)x,(uint8_t)c);ok+=((r.logit1>r.logit0)==label((unsigned)x));sum+=(long long)r.logit0*31+r.logit1;}printf("c=%d acc=%.9f checksum=%lld\n",c,ok/512.0,sum);}return 0;}
'''

def run(cmd):
    return subprocess.run(cmd, check=True, text=True, capture_output=True)

def main():
    ap=argparse.ArgumentParser(); ap.add_argument('--out',default=str(ROOT/'results'/'realtime_nn_q4_branchless_results.json')); a=ap.parse_args()
    clang=shutil.which('clang'); objdump=shutil.which('llvm-objdump'); gcc=shutil.which('gcc'); nm=shutil.which('nm'); size=shutil.which('llvm-size') or shutil.which('size')
    if not all((clang,objdump,gcc,nm,size)): raise SystemExit('requires clang, llvm-objdump, gcc, nm, size')
    with tempfile.TemporaryDirectory(prefix='rtnn_branchless_') as td:
        td=Path(td); (td/'check.c').write_text(CHECK_C)
        seed_rows=[]
        for seed in range(3):
            gen=td/'realtime_nn_q4_i8_generated.h'
            run([sys.executable,str(EXP/'export_realtime_nn_q4_i8_header.py'),'--seed',str(seed),'--out',str(gen)])
            outs={}
            for name,src in [('original',EXP/'realtime_nn_q4_i8_core.c'),('branchless',EXP/'realtime_nn_q4_i8_branchless_core.c')]:
                obj=td/f'{name}_{seed}.o'; exe=td/f'{name}_{seed}'
                run([gcc,'-O2','-std=c11','-ffreestanding','-fno-builtin',f'-I{td}',f'-I{EXP}','-c',str(src),'-o',str(obj)])
                run([gcc,'-O2','-std=c11',f'-I{td}',f'-I{EXP}',str(td/'check.c'),str(obj),'-o',str(exe)])
                outs[name]=run([str(exe)]).stdout
            seed_rows.append({'seed':seed,'bit_exact_checksum_output_match':outs['original']==outs['branchless'],'stdout':outs['branchless'].strip().splitlines()})

        run([sys.executable,str(EXP/'export_realtime_nn_q4_i8_header.py'),'--seed','0','--out',str(td/'realtime_nn_q4_i8_generated.h')])
        targets={}
        for target,flags in TARGETS.items():
            tr={}
            for name,src in [('original',EXP/'realtime_nn_q4_i8_core.c'),('branchless',EXP/'realtime_nn_q4_i8_branchless_core.c')]:
                obj=td/f'{target}_{name}.o'
                run([clang,*flags,'-O2','-std=c11','-ffreestanding','-fno-builtin',f'-I{td}',f'-I{EXP}','-c',str(src),'-o',str(obj)])
                dis=run([objdump,'-d',str(obj)]).stdout
                pat=RV_BRANCH if target=='rv32im' else ARM_BRANCH
                undefined=[x for x in run([nm,'-u',str(obj)]).stdout.splitlines() if x.strip()]
                fields=run([size,str(obj)]).stdout.splitlines()[-1].split()
                tr[name]={'conditional_branch_sites':len(pat.findall(dis)),'text_bytes':int(fields[0]),'undefined_symbol_count':len(undefined)}
            targets[target]=tr
        out={'setup':{'compiler':run([clang,'--version']).stdout.splitlines()[0],'seeds':3,'timing_claim':False},'seed_functional_audit':seed_rows,'targets':targets,'aggregate':{'all_3_seeds_exact_output_match':all(x['bit_exact_checksum_output_match'] for x in seed_rows),'all_targets_helper_free':all(v[k]['undefined_symbol_count']==0 for v in targets.values() for k in ('original','branchless')),'branch_site_reduction':{t:targets[t]['original']['conditional_branch_sites']-targets[t]['branchless']['conditional_branch_sites'] for t in targets}},'interpretation':{'supported':'Replacing activation-value-dependent Q4 rounding/clamp branches with bitwise branchless arithmetic preserves full-domain outputs in three seeds and reduces compiled conditional-branch sites on Cortex-M0, Cortex-M4 soft-float, and RV32IM with this Clang build.','not_supported':['cycle-count invariance','WCET','hardware execution','universal compiler behavior']}}
        Path(a.out).write_text(json.dumps(out,indent=2)); print(json.dumps(out['aggregate'],indent=2))
if __name__=='__main__': main()
