import argparse
import json
import re
import shutil
import statistics
import subprocess
import tempfile
from pathlib import Path

import numpy as np

import export_realtime_nn_q4_certified_header as cert
import realtime_nn_q4_baremetal_link_audit as bare
import realtime_nn_q4_branchless_audit as branch_audit

ROOT = Path(__file__).resolve().parents[1]
EXP = ROOT / "experiments"
INSN_RE = re.compile(r"^\s*[0-9a-f]+:\s", re.M)

ALIAS_CHECK_C = r'''
#include <stdio.h>
#include "realtime_nn_q4_i8_core.h"
static RTNNQ4I8Workspace W;
int main(void){
    if(!rtnn_q4_i8_init()) return 2;
    for(int c=0;c<RTNN_CLASS_COUNT;c++) for(int x=0;x<512;x++){
        RTNNQ4I8Result a=rtnn_q4_i8_infer(&W,(uint16_t)x,(uint8_t)c);
        RTNNQ4I8Result b=rtnn_q4_i8_infer(&W,(uint16_t)(x|0xFE00u),(uint8_t)c);
        if(a.logit0!=b.logit0||a.logit1!=b.logit1) return 3;
    }
    puts("high_bits_alias_low9=1"); return 0;
}
'''

BENCH_C = r'''
#define _POSIX_C_SOURCE 200809L
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "realtime_nn_q4_i8_core.h"
static RTNNQ4I8Workspace W; static volatile int32_t sink;
static int cmp(const void*a,const void*b){double x=*(const double*)a,y=*(const double*)b;return(x>y)-(x<y);}
static double us(struct timespec a,struct timespec b){return(b.tv_sec-a.tv_sec)*1e6+(b.tv_nsec-a.tv_nsec)/1e3;}
int main(int argc,char**argv){int reps=argc>1?atoi(argv[1]):1200;if(!rtnn_q4_i8_init())return 2;uint32_t rng=1;
for(int c=0;c<RTNN_CLASS_COUNT;c++){for(int i=0;i<500;i++){rng=rng*1664525u+1013904223u;sink+=rtnn_q4_i8_infer(&W,(uint16_t)(rng&511u),(uint8_t)c).logit0;}
double*v=malloc((size_t)reps*sizeof(double));if(!v)return 3;for(int i=0;i<reps;i++){rng=rng*1664525u+1013904223u;struct timespec a,b;clock_gettime(CLOCK_MONOTONIC,&a);RTNNQ4I8Result z=rtnn_q4_i8_infer(&W,(uint16_t)(rng&511u),(uint8_t)c);clock_gettime(CLOCK_MONOTONIC,&b);sink+=z.logit0;v[i]=us(a,b);}qsort(v,(size_t)reps,sizeof(double),cmp);printf("c=%d p50=%.3f p95=%.3f\n",c,v[reps/2],v[(int)(reps*.95)]);free(v);}return sink==123456789;}
'''


def run(cmd, check=True):
    return subprocess.run(cmd, check=check, text=True, capture_output=True)


def parse_bench(text):
    rows={}
    for line in text.splitlines():
        m=re.match(r"c=(\d+) p50=([0-9.]+) p95=([0-9.]+)",line)
        if m: rows[int(m.group(1))]={"p50_us":float(m.group(2)),"p95_us":float(m.group(3))}
    return rows


def main():
    ap=argparse.ArgumentParser(); ap.add_argument('--out',default=str(ROOT/'results'/'realtime_nn_q4_lut_certificate_results.json')); ap.add_argument('--timing-reps',type=int,default=1200); ap.add_argument('--timing-rounds',type=int,default=3); a=ap.parse_args()
    gcc=shutil.which('gcc'); clang=shutil.which('clang'); objdump=shutil.which('llvm-objdump'); objcopy=shutil.which('llvm-objcopy'); size=shutil.which('llvm-size') or shutil.which('size'); nm=shutil.which('nm')
    if not all((gcc,clang,objdump,objcopy,size,nm)): raise SystemExit('requires gcc, clang, llvm-objdump, llvm-objcopy, nm, size')

    with tempfile.TemporaryDirectory(prefix='rtnn_q4_cert_') as td0:
        td=Path(td0); (td/'check.c').write_text(branch_audit.CHECK_C); (td/'alias.c').write_text(ALIAS_CHECK_C); (td/'bench.c').write_text(BENCH_C); (td/'probe.c').write_text(bare.PROBE); (td/'arm.ld').write_text(bare.ARM_LD); (td/'rv.ld').write_text(bare.RV_LD)
        sources={
            'production':EXP/'realtime_nn_q4_i8_clamped_reference_core.c',
            'branchless_clamp':EXP/'realtime_nn_q4_i8_branchless_core.c',
            'certified_direct':EXP/'realtime_nn_q4_i8_certified_core.c',
        }

        seed_rows=[]
        for seed in range(3):
            gen=td/'realtime_nn_q4_i8_generated.h'; certificate=cert.export_certified(seed,gen); outputs={}
            for name,src in sources.items():
                obj=td/f'{name}_{seed}.o'; exe=td/f'{name}_{seed}'
                run([gcc,'-O2','-std=c11','-ffreestanding','-fno-builtin',f'-I{td}',f'-I{EXP}','-c',str(src),'-o',str(obj)])
                run([gcc,'-O2','-std=c11',f'-I{td}',f'-I{EXP}',str(td/'check.c'),str(obj),'-o',str(exe)]); outputs[name]=run([str(exe)]).stdout
            obj=td/f'alias_{seed}.o'; exe=td/f'alias_{seed}'
            run([gcc,'-O2','-std=c11','-ffreestanding','-fno-builtin',f'-I{td}',f'-I{EXP}','-c',str(sources['certified_direct']),'-o',str(obj)]); run([gcc,'-O2','-std=c11',f'-I{td}',f'-I{EXP}',str(td/'alias.c'),str(obj),'-o',str(exe)])
            seed_rows.append({'seed':seed,'certificate':certificate,'all_three_variants_exact_output_match':len(set(outputs.values()))==1,'high_input_bits_alias_to_low9':'high_bits_alias_low9=1' in run([str(exe)]).stdout,'stdout':outputs['certified_direct'].strip().splitlines()})

        q=cert.quantize_model(cert.base.budget_model.train(0).eval()); w,b=q['blocks'][0]['ff1']; b=b.copy(); b[:]=np.int8(127); q['blocks'][0]['ff1']=(w,b); negative_ok=False; negative_error=None
        try: cert.certify_quantized(q)
        except ValueError as exc: negative_ok=True; negative_error=str(exc)

        cert.export_certified(0,td/'realtime_nn_q4_i8_generated.h'); targets={}
        for target,flags in branch_audit.TARGETS.items():
            tr={}
            for name,src in sources.items():
                obj=td/f'{target}_{name}.o'; run([clang,*flags,'-O2','-std=c11','-ffreestanding','-fno-builtin',f'-I{td}',f'-I{EXP}','-c',str(src),'-o',str(obj)]); dis=run([objdump,'-d',str(obj)]).stdout; pat=branch_audit.RV_BRANCH if target=='rv32im' else branch_audit.ARM_BRANCH; undefined=[x for x in run([nm,'-u',str(obj)],check=False).stdout.splitlines() if x.strip()]; fields=run([size,str(obj)]).stdout.splitlines()[-1].split(); tr[name]={'conditional_branch_sites':len(pat.findall(dis)),'static_instruction_sites':len(INSN_RE.findall(dis)),'text_bytes':int(fields[0]),'undefined_symbol_count':len(undefined)}
            targets[target]=tr

        baremetal={}
        for target,(flags,ldname) in bare.TARGETS.items():
            elf=td/f'cert_{target}.elf'; proc=run([clang,*flags,'-O2','-std=c11','-ffreestanding','-fno-builtin','-nostdlib','-fuse-ld=lld',f'-I{td}',f'-I{EXP}',str(sources['certified_direct']),str(td/'probe.c'),f'-Wl,-T,{td/ldname}','-Wl,--gc-sections','-Wl,--build-id=none','-o',str(elf)],check=False)
            if proc.returncode: baremetal[target]={'link_ok':False,'requires_mul_helper':'__mulsi3' in proc.stderr}; continue
            undefined=[x for x in run([nm,'-u',str(elf)],check=False).stdout.splitlines() if x.strip()]; raw=td/f'cert_{target}.bin'; run([objcopy,'-O','binary',str(elf),str(raw)]); fields=run([size,str(elf)]).stdout.splitlines()[-1].split(); baremetal[target]={'link_ok':True,'undefined_symbol_count':len(undefined),'binary_bytes':raw.stat().st_size,'sections_bytes':{'text':int(fields[0]),'data':int(fields[1]),'bss':int(fields[2])}}

        timing_exe={}
        for name in ('branchless_clamp','certified_direct'):
            obj=td/f'timing_{name}.o'; exe=td/f'timing_{name}'; run([gcc,'-O2','-std=c11','-ffreestanding','-fno-builtin',f'-I{td}',f'-I{EXP}','-c',str(sources[name]),'-o',str(obj)]); run([gcc,'-O2','-std=c11',f'-I{td}',f'-I{EXP}',str(td/'bench.c'),str(obj),'-o',str(exe)]); timing_exe[name]=exe
        timing_rows={k:[] for k in timing_exe}
        for name in ['branchless_clamp','certified_direct']*a.timing_rounds: timing_rows[name].append(parse_bench(run([str(timing_exe[name]),str(a.timing_reps)]).stdout))
        timing_summary={name:{str(c):{'median_of_p50_us':statistics.median(r[c]['p50_us'] for r in rows),'median_of_p95_us':statistics.median(r[c]['p95_us'] for r in rows)} for c in range(5)} for name,rows in timing_rows.items()}

        out={'setup':{'seeds':3,'historical_production_source':'realtime_nn_q4_i8_clamped_reference_core.c','effective_input_bits':9,'effective_input_states':512,'api_input_bits':16,'certificate_scope':'all distinct low-9-bit states consumed by the core; upper input bits are ignored','timing_boundary':'host timing is secondary/nonportable; no WCET claim'},'seed_audit':seed_rows,'negative_certificate_test':{'pass':negative_ok,'error':negative_error},'targets':targets,'baremetal':baremetal,'host_seed0_alternating_timing':timing_summary,'aggregate':{'all_seeds_exact_output_match':all(x['all_three_variants_exact_output_match'] for x in seed_rows),'all_seeds_high_bits_alias':all(x['high_input_bits_alias_to_low9'] for x in seed_rows),'negative_certificate_rejects_unsafe_weights':negative_ok,'helper_free_certified_targets':[t for t,v in targets.items() if v['certified_direct']['undefined_symbol_count']==0],'rv32i_still_requires_mul_helper':(not baremetal['rv32i_negative'].get('link_ok')) and baremetal['rv32i_negative'].get('requires_mul_helper',False)},'interpretation':{'supported':'For this finite-input Q4 toy, the generated weight header can carry an exhaustive model-specific certificate proving every reachable activation-LUT index is in range. A certified direct-index core is bit-exact to the historical clamped and branchless-clamp variants in three seeds and can omit runtime LUT clamp logic.','not_supported':['a general proof for arbitrary neural inputs/models','WCET or constant cycles','hardware/RTOS execution','target-independent speedup']}}
        Path(a.out).write_text(json.dumps(out,indent=2)); print(json.dumps(out['aggregate'],indent=2))

if __name__=='__main__': main()
