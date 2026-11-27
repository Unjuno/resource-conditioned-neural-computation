import hashlib,json,subprocess,tempfile,unittest,csv
from pathlib import Path
PKG=Path(__file__).resolve().parent.parent
import sys
sys.path.insert(0,str(PKG/'safety_gates_v1_20261122'))
from pilot_gate import verify_binding,validate_primary_schedule
TCL_EXE=Path(r'C:\altera_lite\25.1std\quartus\bin64\quartus_stp_tcl.exe')
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()

class PreflightIntegration(unittest.TestCase):
    def setUp(self):
        self.temp=tempfile.TemporaryDirectory();self.d=Path(self.temp.name)
        self.cases=PKG/'build/host_cases_primary_attempt2/cases.csv'
        self.binding=self.d/'primary.json';self.out=self.d/'must_not_start'
        rows=self.cases.read_text(encoding='utf-8').splitlines(); header=rows[0]; first=rows[1].split(',')
        b={'schema':'rtnn-external-validation-binding-v1','status':'PHYSICAL_ELIGIBLE','classification':'EMPIRICAL_ONLY','split':'primary','experiment_id':first[0],'session_id':first[1],'case_count':7626,'cases_csv_sha256':sha(self.cases),'sof_sha256':'5e333e9377b7188a394d04b93b98833d91afb2cd53eca8d976e6aa715dfa00c4','build_id':'45585631','binding_id':'45585632','model_id':'52544e4e','external_jtag_timing':'BLOCKED'}
        self.binding.write_text(json.dumps(b),encoding='utf-8')
    def tearDown(self):self.temp.cleanup()
    def test_powershell_rejects_before_quartus_launch(self):
        sentinel=self.d/'quartus_was_started.txt'; fake=self.d/'quartus-stp-fake.exe';fake.write_text('sentinel',encoding='ascii')
        ps=PKG/'host_v2_20261126/Invoke-ExternalValidation.ps1'
        p=subprocess.run(['pwsh','-NoProfile','-File',str(ps),'-CaseCsv',str(self.cases),'-BindingJson',str(self.binding),'-OutputDirectory',str(self.out),'-QuartusStpTcl',str(sentinel),'-ExecutePhysical'],capture_output=True,text=True,encoding='utf-8',errors='replace',timeout=30)
        self.assertNotEqual(p.returncode,0);self.assertFalse(sentinel.exists());self.assertFalse(self.out.exists())
        self.assertIn('Primary run requires a pilot gate',p.stdout+p.stderr)
    def test_binding_generator_rejects_primary_without_pilot_gate(self):
        script=PKG/'scripts/create_physical_binding.py';out=self.d/'primary_binding.json'
        p=subprocess.run(['python',str(script),'--sof',str(PKG/'build/quartus_external_attempt2/rtnn_c3_measurement_v2.sof'),'--firmware-manifest',str(PKG/'build/rv32_attempt2/external_firmware_manifest.json'),'--quartus-audit',str(PKG/'build/quartus_external_attempt2/quartus_audit.json'),'--cases',str(self.cases),'--split','primary','--out',str(out)],capture_output=True,text=True,encoding='utf-8',errors='replace',timeout=30)
        self.assertNotEqual(p.returncode,0);self.assertIn('requires an independently validated pilot gate',p.stdout+p.stderr);self.assertFalse(out.exists())
    def test_pilot_binding_preflight_does_not_require_a_pilot_gate(self):
        script=PKG/'scripts/create_physical_binding.py';binding=self.d/'pilot_binding.json';out=self.d/'pilot_output'
        pilot_cases=PKG/'build/host_cases_pilot_attempt2/cases.csv'
        p=subprocess.run(['python',str(script),'--sof',str(PKG/'build/quartus_external_attempt2/rtnn_c3_measurement_v2.sof'),'--firmware-manifest',str(PKG/'build/rv32_attempt2/external_firmware_manifest.json'),'--quartus-audit',str(PKG/'build/quartus_external_attempt2/quartus_audit.json'),'--cases',str(pilot_cases),'--split','pilot','--out',str(binding)],capture_output=True,text=True,encoding='utf-8',errors='replace',timeout=30)
        self.assertEqual(p.returncode,0,p.stdout+p.stderr);self.assertTrue(binding.is_file())
        ps=PKG/'host_v2_20261126/Invoke-ExternalValidation.ps1'
        p=subprocess.run(['pwsh','-NoProfile','-File',str(ps),'-CaseCsv',str(pilot_cases),'-BindingJson',str(binding),'-OutputDirectory',str(out)],capture_output=True,text=True,encoding='utf-8',errors='replace',timeout=30)
        self.assertEqual(p.returncode,0,p.stdout+p.stderr);self.assertIn('PREFLIGHT_ONLY',p.stdout);self.assertFalse(out.exists())
        out.mkdir();marker=out/'preserve.txt';marker.write_text('do not overwrite',encoding='ascii')
        p=subprocess.run(['pwsh','-NoProfile','-File',str(ps),'-CaseCsv',str(pilot_cases),'-BindingJson',str(binding),'-OutputDirectory',str(out)],capture_output=True,text=True,encoding='utf-8',errors='replace',timeout=30)
        self.assertNotEqual(p.returncode,0);self.assertEqual(marker.read_text(encoding='ascii'),'do not overwrite')

    def test_primary_schedule_generator_rejects_used_sequence_and_preserves_output(self):
        script=PKG/'scripts/prepare_primary_execution.py'
        out=self.d/'primary_cases.csv'
        common=['python',str(script),'--experiment-id','EXTVAL_PRIMARY_TEST_20261128','--session-id','SESSION_TEST_20261128','--out',str(out)]
        p=subprocess.run(common+['--sequence-start','21'],capture_output=True,text=True,encoding='utf-8',errors='replace',timeout=30)
        self.assertNotEqual(p.returncode,0);self.assertIn('after the recorded pilot',(p.stdout or '')+(p.stderr or ''));self.assertFalse(out.exists())
        p=subprocess.run(common+['--sequence-start','22'],capture_output=True,text=True,encoding='utf-8',errors='replace',timeout=30)
        self.assertEqual(p.returncode,0,p.stdout+p.stderr);self.assertTrue(out.is_file())
        with out.open(newline='',encoding='utf-8') as f: rows=list(csv.DictReader(f))
        self.assertEqual(len(rows),7626);self.assertEqual(rows[0]['sequence'],'22');self.assertEqual(rows[-1]['sequence'],'7647')
        p=subprocess.run(common+['--sequence-start','22'],capture_output=True,text=True,encoding='utf-8',errors='replace',timeout=30)
        self.assertNotEqual(p.returncode,0);self.assertIn('refusing existing output',(p.stdout or '')+(p.stderr or ''))

    def test_primary_binding_preflight_checks_each_frozen_case_before_jtag(self):
        template=PKG/'build/host_cases_primary_attempt2/cases.csv'
        with template.open(newline='',encoding='utf-8') as f: rows=list(csv.DictReader(f));fields=rows[0].keys()
        experiment='GATE_INTEGRATION_PRIMARY_20261128';session='GATE_SESSION_20261128'
        for i,r in enumerate(rows,22): r.update(experiment_id=experiment,session_id=session,sequence=str(i))
        cases=self.d/'primary_cases.csv'
        with cases.open('w',newline='',encoding='utf-8') as f:
            w=csv.DictWriter(f,fieldnames=fields);w.writeheader();w.writerows(rows)
        gate=PKG/'build/pilot_gate_RUN4_20261126.json'
        self.assertTrue(gate.is_file())
        binding={
          'schema':'rtnn-external-validation-binding-v1','status':'PHYSICAL_ELIGIBLE','classification':'EMPIRICAL_ONLY','split':'primary',
          'experiment_id':experiment,'session_id':session,'case_count':7626,'cases_csv_sha256':sha(cases),
          'sof_sha256':'5e333e9377b7188a394d04b93b98833d91afb2cd53eca8d976e6aa715dfa00c4','build_id':'45585631','binding_id':'45585632','model_id':'52544e4e',
          'input_manifest_sha256':sha(PKG/'data/primary_manifest.csv'),'pilot_gate_path':str(gate.resolve()),'pilot_gate_sha256':sha(gate),
          'schedule_identity':validate_primary_schedule(rows)
        }
        binding_path=self.d/'primary_binding.json';binding_path.write_text(json.dumps(binding),encoding='utf-8')
        self.assertEqual(verify_binding(binding_path,cases)['audit'],'PILOT_AUDIT_PASS')
        generated=self.d/'generated_primary_binding.json'
        command=['python',str(PKG/'scripts/create_physical_binding.py'),'--sof',str(PKG/'build/quartus_external_attempt2/rtnn_c3_measurement_v2.sof'),'--firmware-manifest',str(PKG/'build/rv32_attempt2/external_firmware_manifest.json'),'--quartus-audit',str(PKG/'build/quartus_external_attempt2/quartus_audit.json'),'--cases',str(cases),'--split','primary','--pilot-gate',str(gate),'--out',str(generated)]
        p=subprocess.run(command,capture_output=True,text=True,encoding='utf-8',errors='replace',timeout=30)
        self.assertEqual(p.returncode,0,(p.stdout or '')+(p.stderr or ''))
        self.assertEqual(verify_binding(generated,cases)['audit'],'PILOT_AUDIT_PASS')
        rows[0]['expected_prediction']=str((int(rows[0]['expected_prediction'])+1)%10)
        with cases.open('w',newline='',encoding='utf-8') as f:
            w=csv.DictWriter(f,fieldnames=fields);w.writeheader();w.writerows(rows)
        binding['cases_csv_sha256']=sha(cases);binding_path.write_text(json.dumps(binding),encoding='utf-8')
        with self.assertRaisesRegex(ValueError,'expected_prediction differs from CPU oracle'):
            verify_binding(binding_path,cases)
    @unittest.skipUnless(TCL_EXE.is_file(),'Quartus STP Tcl not installed at configured path')
    def test_direct_tcl_rejects_before_jtag_discovery(self):
        tcl=PKG/'host_v2_20261126/run_external_validation.tcl'
        p=subprocess.run([str(TCL_EXE),'-t',str(tcl),str(self.cases),str(self.out),str(self.binding)],cwd=self.d,capture_output=True,text=True,encoding='utf-8',errors='replace',timeout=60)
        self.assertNotEqual(p.returncode,0)
        source=tcl.read_text(encoding='utf-8')
        self.assertLess(source.index('--verify-binding'),source.index('package require ::quartus::jtag'))
        self.assertLess(source.index('package require ::quartus::jtag'),source.index('get_hardware_names'))
        self.assertFalse(self.out.exists())

if __name__=='__main__':unittest.main(verbosity=2)
