#!/usr/bin/env python3
"""Descriptive summary for the frozen 10-image external validation pilot."""
import csv,json,statistics
from pathlib import Path
root=Path(__file__).resolve().parent
rows=list(csv.DictReader((root/'physical_results.csv').open(encoding='utf-8',newline='')))
fixed={r['input_id']:r for r in rows if r['mode']=='fixed2'}
adaptive={r['input_id']:r for r in rows if r['mode']=='adaptive'}
if len(rows)!=20 or len(fixed)!=10 or set(fixed)!=set(adaptive): raise SystemExit('pilot rows/pairs incomplete')
paired=[]
for iid in sorted(fixed,key=int):
 f,a=fixed[iid],adaptive[iid]; fc,ac=int(f['cycles']),int(a['cycles'])
 paired.append({'input_id':int(iid),'fixed2_cycles':fc,'adaptive_cycles':ac,'adaptive_minus_fixed2_cycles':ac-fc,'fixed2_teacher_correct':int(f['prediction'])==int(f['teacher_label']),'adaptive_teacher_correct':int(a['prediction'])==int(a['teacher_label'])})
allc=[int(r['cycles']) for r in rows]; fc=[int(r['cycles']) for r in fixed.values()]; ac=[int(r['cycles']) for r in adaptive.values()]
summary={'classification':'ENGINEERING_PILOT_DESCRIPTIVE_ONLY','experiment_id':rows[0]['experiment_id'],'session_id':rows[0]['session_id'],'case_count':len(rows),'input_count':10,'all_status_pass':all(r['status']=='PASS' for r in rows),'all_reference_predictions_match':all(r['prediction']==r['reference_prediction'] for r in rows),'teacher_accuracy_counts':{'fixed2_correct':sum(x['fixed2_teacher_correct'] for x in paired),'adaptive_correct':sum(x['adaptive_teacher_correct'] for x in paired)},'cycles':{'all':{'min':min(allc),'median':statistics.median(allc),'max':max(allc)},'fixed2':{'min':min(fc),'median':statistics.median(fc),'max':max(fc)},'adaptive':{'min':min(ac),'median':statistics.median(ac),'max':max(ac)}},'paired_inputs':paired,'adaptive_slower_input_ids':[x['input_id'] for x in paired if x['adaptive_minus_fixed2_cycles']>0],'limitations':['Only the preregistered 10-image engineering pilot.','No claim of population accuracy noninferiority or general speed advantage.','One live board power epoch; independent cold boots unverified.','Formal external JTAG timing signoff remains blocked.']}
(root/'PILOT_SUMMARY.json').write_text(json.dumps(summary,indent=2)+'\n',encoding='utf-8')
with (root/'PILOT_PAIRED_CYCLES.csv').open('w',encoding='utf-8',newline='') as f:
 w=csv.DictWriter(f,fieldnames=list(paired[0]),lineterminator='\n');w.writeheader();w.writerows(paired)
print(json.dumps({'cases':len(rows),'images':len(fixed),'adaptive_slower':summary['adaptive_slower_input_ids'],'fixed_median':statistics.median(fc),'adaptive_median':statistics.median(ac)},indent=2))
