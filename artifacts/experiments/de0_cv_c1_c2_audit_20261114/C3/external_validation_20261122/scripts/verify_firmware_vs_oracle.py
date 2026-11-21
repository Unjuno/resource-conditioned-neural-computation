import csv,sys
from pathlib import Path
got=list(csv.DictReader(Path(sys.argv[1]).open(encoding='utf-8',newline='')))
ref=list(csv.DictReader(Path(sys.argv[2]).open(encoding='utf-8',newline='')))
keys=('input_id','mode','prediction','admitted_exit','executed_exit','stop_reason')
if len(got)!=len(ref):raise SystemExit(f'row count mismatch {len(got)} vs {len(ref)}')
for i,(a,b) in enumerate(zip(got,ref),1):
    for k in keys:
        if a[k]!=b[k]:raise SystemExit(f'row {i} field {k}: firmware={a[k]} oracle={b[k]}')
    if a['status']!='0' or a['label']!='-1':raise SystemExit(f'row {i} status/label invalid')
print(f'FIRMWARE_API_ORACLE_MATCH_SOFTWARE_ONLY rows={len(got)}')
