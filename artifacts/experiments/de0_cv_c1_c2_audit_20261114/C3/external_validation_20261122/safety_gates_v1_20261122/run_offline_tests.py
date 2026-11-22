#!/usr/bin/env python3
"""Run and preserve this offline gate/regression suite with exit codes."""
import datetime, json, subprocess, sys
from pathlib import Path
HERE=Path(__file__).resolve().parent; PKG=HERE.parent
commands=[
    [sys.executable,str(PKG/'scripts/test_external_host.py')],
    [sys.executable,str(PKG/'scripts/test_physical_audit_fail_closed.py')],
    [sys.executable,str(HERE/'test_safety_gates.py')],
    [sys.executable,str(HERE/'test_runner_preflight.py')],
]
logs=[]; results=[]
for cmd in commands:
    p=subprocess.run(cmd,cwd=PKG,capture_output=True,text=True,encoding='utf-8',errors='replace')
    results.append({'command':cmd,'exit_code':p.returncode})
    logs.append('$ '+' '.join(cmd)+f'\nEXIT_CODE={p.returncode}\n--- stdout ---\n{p.stdout}--- stderr ---\n{p.stderr}\n')
(HERE/'OFFLINE_TEST_RUN.log').write_text('\n'.join(logs).rstrip()+'\n',encoding='utf-8')
report={'schema':'rtnn-extval-offline-test-run-v1','timestamp_local':datetime.datetime.now().astimezone().isoformat(),'run_class':'OFFLINE_ONLY_NO_HARDWARE','results':results,'total_exit_code':max((x['exit_code'] for x in results),default=0)}
(HERE/'OFFLINE_TEST_EXIT_CODES.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
print(json.dumps(report,indent=2))
raise SystemExit(report['total_exit_code'])
