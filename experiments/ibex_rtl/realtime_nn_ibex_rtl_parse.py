import argparse, json, re
from pathlib import Path

EXPECTED=[[0,0,0,0,0,0,0],[1,2,1,1,1,2,2],[8,1,5,5,5,5,5],[0,0,0,0,0,0,0]]
ap=argparse.ArgumentParser(); ap.add_argument('--log',required=True); ap.add_argument('--static',required=True); ap.add_argument('--out',required=True); a=ap.parse_args()
text=Path(a.log).read_text(errors='replace')
m=re.search(r'RTNN_OVERHEAD,(\d+)',text)
if not m: raise SystemExit('missing RTNN_OVERHEAD')
over=int(m.group(1)); rows=[]
for line in text.splitlines():
    if line.startswith('RTNN,'):
        _,i,c,cy,p=line.split(','); rows.append((int(i),int(c),int(cy),int(p)))
if len(rows)!=28: raise SystemExit(f'expected 28 RTNN rows, got {len(rows)}')
static=json.loads(Path(a.static).read_text()); bounds=[x['counts']['cycle_envelope'] for x in static['classes']]
by={c:[] for c in range(7)}; pred_mismatch=0; exceed=[]
for i,c,cy,p in rows:
    if p!=EXPECTED[i][c]: pred_mismatch+=1
    adj=max(0,cy-over); by[c].append(adj)
    if adj>bounds[c]: exceed.append({'input':i,'class':c,'rtl_adjusted':adj,'static_envelope':bounds[c]})
classes=[]
for c in range(7):
    vals=by[c]; classes.append({'class':c,'rtl_cycles':vals,'min':min(vals),'max':max(vals),'spread':max(vals)-min(vals),'static_envelope':bounds[c],'slack_min':bounds[c]-max(vals)})
out={'measurement_overhead_cycles':over,'prediction_mismatches':pred_mismatch,'envelope_exceedances':exceed,'classes':classes,'rtl_input_cycle_identical':all(x['spread']==0 for x in classes)}
Path(a.out).write_text(json.dumps(out,indent=2)); print(json.dumps(out,indent=2))
if pred_mismatch or exceed: raise SystemExit(1)
