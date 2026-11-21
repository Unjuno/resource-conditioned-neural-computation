#!/usr/bin/env python3
"""Fail-closed audit and preregistered analysis of new physical primary runs."""
import argparse,csv,hashlib,json,statistics,sys
from pathlib import Path
from stats_core import paired_ni_lower,paired_cycle_bootstrap
ROOT=Path(__file__).resolve().parents[1]
def sha(b):return hashlib.sha256(b).hexdigest()
def readcsv(p):
    with p.open(encoding='utf-8',newline='') as f:return list(csv.DictReader(f))
def load_run(run_dir, expected_split):
    status=json.loads((run_dir/'run_status.json').read_text())
    if status.get('schema')!='rtnn-external-validation-physical-v1' or status.get('status')!='COMPLETE': raise ValueError('not a complete physical runner result')
    if status.get('run_source')!='quartus_stp_virtual_jtag' or status.get('mock') is not False or status.get('hardware_opened') is not True or status.get('cycles_source')!='Ibex_mcycle': raise ValueError('result is not an actual USB-Blaster Virtual-JTAG acquisition')
    if status.get('build_id')!='45585631' or status.get('model_id')!='52544e4e' or status.get('binding_id')!='45585632': raise ValueError('wrong build family')
    # Reject mocks, stale builds, or incomplete acquisitions before touching
    # run CSVs; tests intentionally provide only the status envelope.
    cases=readcsv(run_dir/'cases.csv'); results=readcsv(run_dir/'physical_results.csv')
    sums={}
    for line in (run_dir/'SHA256SUMS.txt').read_text(encoding='ascii').splitlines():
        digest,name=line.split(None,1); sums[name.strip()]=digest.lower()
    for name,digest in sums.items():
        if not (run_dir/name).is_file() or sha((run_dir/name).read_bytes())!=digest: raise ValueError(f'run SHA manifest mismatch: {name}')
    for required in ('cases.csv','binding.json','run_external_validation.tcl','launcher.log','physical_results.csv','raw_jtag.log','run_status.json'):
        if required not in sums: raise ValueError(f'SHA manifest missing {required}')
    if status.get('uart_used') or status.get('flash_written') or status.get('sof_programming_performed'): raise ValueError('unexpected side effect flags')
    if len(cases)!=len(results) or len(results)!=int(status.get('expected_cases',-1)) or int(status.get('completed_cases',-1))!=len(results): raise ValueError('missing/extra result rows')
    if sha((run_dir/'cases.csv').read_bytes())!=status.get('cases_csv_sha256'): raise ValueError('cases CSV SHA mismatch')
    bind=json.loads((run_dir/'binding.json').read_text(encoding='utf-8-sig'))
    if bind.get('status')!='PHYSICAL_ELIGIBLE' or bind.get('cases_csv_sha256')!=status.get('cases_csv_sha256') or bind.get('sof_sha256')!=status.get('sof_sha256'): raise ValueError('binding file does not match run')
    ids=set(); seqs=set(); joined={}
    for c,r in zip(cases,results):
        if r['status']!='PASS': raise ValueError('failed physical case present')
        if c['experiment_id']!=status['experiment_id'] or c['session_id']!=status['session_id'] or r['experiment_id']!=status['experiment_id'] or r['session_id']!=status['session_id']: raise ValueError('experiment/session mismatch')
        if r['sof_sha256']!=status['sof_sha256'] or c['build_id']!='45585631' or c['binding_id']!='45585632' or c['model_id']!='52544e4e': raise ValueError('identity mismatch')
        seq=int(c['sequence']); iid=int(c['input_id']); mode=c['mode']
        if seq in seqs: raise ValueError('duplicate sequence')
        seqs.add(seq); ids.add(iid)
        if mode not in ('fixed2','adaptive') or len(bytes.fromhex(c['pixels_hex']))!=64 or sha(bytes.fromhex(c['pixels_hex']))!=c['pixels_sha256']: raise ValueError('pixel hash/mode invalid')
        if any(int(x)>16 for x in bytes.fromhex(c['pixels_hex'])): raise ValueError('pixel out of range')
        if int(r['request_crc_ok'])!=1 or int(r['response_crc_ok'])!=1: raise ValueError('request/response CRC failure')
        if r['sequence']!=c['sequence'] or r['input_id']!=c['input_id'] or r['mode']!=mode: raise ValueError('response sequence/input/mode mismatch')
        for rk,ck in [('prediction','expected_prediction'),('admitted_exit','expected_admitted_exit'),('executed_exit','expected_executed_exit')]:
            if r[rk]!=c[ck]: raise ValueError(f'{rk} differs from CPU frozen reference')
        stop_word={'0':'none','1':'entropy','2':'budget'}.get(r['stop_reason'],'invalid')
        if stop_word!=c['expected_stop_reason']: raise ValueError('stop_reason differs from CPU frozen reference')
        start=int(r['cycles_start']); end=int(r['cycles_end']); cy=int(r['cycles'])
        if start<=0 or end<=start or end-start!=cy: raise ValueError('counter zero-span/regression/delta mismatch')
        k=(iid,mode)
        if k in joined: raise ValueError('duplicate input/mode')
        joined[k]={'cycles':cy,'prediction':int(r['prediction']),'label':int(c['teacher_label']),
                   'reference':int(c['expected_prediction']),'exit':int(r['executed_exit'])}
    expected=len(ids)*2
    if len(results)!=expected or len(joined)!=expected: raise ValueError('input/mode pairing incomplete')
    if expected_split=='pilot' and len(ids)!=10: raise ValueError('pilot must have exactly ten images')
    if expected_split=='primary' and len(ids)!=3813: raise ValueError('primary full run must have exactly 3813 images')
    return {'status':status,'ids':ids,'rows':joined,'cases_sha256':sha((run_dir/'cases.csv').read_bytes())}

def analyze(run_dirs,out):
    runs=[load_run(Path(d),'primary') for d in run_dirs]
    sessions=[r['status']['session_id'] for r in runs]
    if len(set(sessions))!=len(sessions): raise ValueError('duplicate power session ID')
    if any(r['ids']!=runs[0]['ids'] for r in runs[1:]): raise ValueError('session input sets differ')
    identity={(r['status']['sof_sha256'],r['status']['build_id'],r['status']['model_id'],r['status']['binding_id']) for r in runs}
    if len(identity)!=1: raise ValueError('mixed build/SOF/model identity')
    base=runs[0]; ids=sorted(base['ids'])
    for r in runs[1:]:
        for iid in ids:
            for mode in ('fixed2','adaptive'):
                a=base['rows'][(iid,mode)]; b=r['rows'][(iid,mode)]
                if (a['prediction'],a['reference'],a['label'],a['exit'])!=(b['prediction'],b['reference'],b['label'],b['exit']):
                    raise ValueError('cross-session function/exit mismatch')
    f=[base['rows'][(i,'fixed2')] for i in ids]; a=[base['rows'][(i,'adaptive')] for i in ids]
    f_ok=[int(x['prediction']==x['label']) for x in f]; a_ok=[int(x['prediction']==x['label']) for x in a]
    ni=paired_ni_lower(f_ok,a_ok); per_session=[]
    for r in runs:
        ff=[r['rows'][(i,'fixed2')]['cycles'] for i in ids]; aa=[r['rows'][(i,'adaptive')]['cycles'] for i in ids]
        per_session.append({'session_id':r['status']['session_id'],**paired_cycle_bootstrap(ff,aa)})
    slower=[{'input_id':i,'fixed2_cycles':base['rows'][(i,'fixed2')]['cycles'],'adaptive_cycles':base['rows'][(i,'adaptive')]['cycles'],'difference_adaptive_minus_fixed':base['rows'][(i,'adaptive')]['cycles']-base['rows'][(i,'fixed2')]['cycles'],'fixed2_correct':f_ok[j],'adaptive_correct':a_ok[j]} for j,i in enumerate(ids) if base['rows'][(i,'adaptive')]['cycles']>base['rows'][(i,'fixed2')]['cycles']]
    slower.sort(key=lambda x:x['difference_adaptive_minus_fixed'],reverse=True)
    result={'schema':'rtnn-external-confirmatory-analysis-v1','classification':'EMPIRICAL_ONLY','data_integrity':'PASS','identity':{'sof_sha256':runs[0]['status']['sof_sha256'],'build_id':'45585631','model_id':'52544e4e','binding_id':'45585632'},'inputs':len(ids),'sessions':[{'session_id':r['status']['session_id'],'experiment_id':r['status']['experiment_id'],'cases_csv_sha256':r['cases_sha256']} for r in runs],'accuracy':{'fixed2_correct':sum(f_ok),'adaptive_correct':sum(a_ok),'fixed2_rate':sum(f_ok)/len(ids),'adaptive_rate':sum(a_ok)/len(ids),'paired_noninferiority':ni,'population_gate':'INCONCLUSIVE_WRITER_CLUSTER_UNKNOWN'},'cycles_by_session':per_session,'slow_adaptive_count':len(slower),'slow_adaptive_fraction':len(slower)/len(ids),'slow_adaptive_top20':slower[:20],'session_reproducibility':'PASS_FUNCTIONAL' if len(runs)>=3 else 'NOT_ESTABLISHED','cycle_target_gate':'PASS' if len(runs)>=3 and all(x['numeric_pass'] for x in per_session) else 'NOT_PASS_OR_INSUFFICIENT_SESSIONS','nonclaims':['No writer IDs; image-independence assumption unresolved.','No absolute time, ppm, WCET, or hard-deadline claim.','Cycle bootstrap reflects input sampling, not a population distribution over boards/sessions.']}
    out=Path(out); out.mkdir(parents=True,exist_ok=False); (out/'analysis.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(result,indent=2))

def main():
    p=argparse.ArgumentParser(); p.add_argument('--runs',nargs='+',required=True); p.add_argument('--out',required=True); a=p.parse_args(); analyze(a.runs,a.out)
if __name__=='__main__':main()
