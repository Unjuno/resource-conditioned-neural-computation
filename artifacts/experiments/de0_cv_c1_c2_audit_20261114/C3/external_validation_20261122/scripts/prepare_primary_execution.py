#!/usr/bin/env python3
"""Prepare a fresh primary case CSV from the immutable offline order template."""
import argparse,csv,re,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'safety_gates_v1_20261122'))
from pilot_gate import ensure_unique_experiment_id,validate_primary_schedule

def prepare(experiment_id,session_id,sequence_start,out):
    if not re.fullmatch(r'[A-Z0-9][A-Z0-9_-]{7,80}',experiment_id) or experiment_id.startswith(('OFFLINE','FIXTURE')):
        raise ValueError('experiment ID must be a new non-fixture uppercase ID')
    if not re.fullmatch(r'[A-Z0-9][A-Z0-9_-]{2,80}',session_id) or session_id.startswith(('OFFLINE','FIXTURE')):
        raise ValueError('session ID must be a non-fixture uppercase ID')
    out=Path(out)
    if out.exists(): raise FileExistsError(f'refusing existing output: {out}')
    ensure_unique_experiment_id(ROOT,experiment_id)
    template=ROOT/'build'/'host_cases_primary_attempt2'/'cases.csv'
    with template.open(encoding='utf-8',newline='') as f:
        reader=csv.DictReader(f);fields=reader.fieldnames;rows=list(reader)
    for i,row in enumerate(rows):
        row['experiment_id']=experiment_id;row['session_id']=session_id;row['sequence']=str(sequence_start+i)
    evidence=validate_primary_schedule(rows)
    out.parent.mkdir(parents=True,exist_ok=True)
    with out.open('x',encoding='utf-8',newline='') as f:
        writer=csv.DictWriter(f,fieldnames=fields);writer.writeheader();writer.writerows(rows)
    return {'status':'PREPARED_OFFLINE_ONLY','path':str(out.resolve()),'experiment_id':experiment_id,'session_id':session_id,'case_count':len(rows),'sequence_start':evidence['first_sequence'],'sequence_end':evidence['last_sequence'],'schedule_identity':evidence}

def main():
    p=argparse.ArgumentParser();p.add_argument('--experiment-id',required=True);p.add_argument('--session-id',required=True);p.add_argument('--sequence-start',required=True,type=int);p.add_argument('--out',required=True,type=Path);a=p.parse_args()
    import json
    try: print(json.dumps(prepare(a.experiment_id,a.session_id,a.sequence_start,a.out),indent=2))
    except (ValueError,FileExistsError,KeyError,TypeError) as e: raise SystemExit(str(e))
if __name__=='__main__':main()
