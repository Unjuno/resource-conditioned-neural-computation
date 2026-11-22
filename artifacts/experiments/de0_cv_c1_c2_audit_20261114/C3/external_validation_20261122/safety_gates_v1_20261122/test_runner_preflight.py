import hashlib,json,subprocess,tempfile,unittest
from pathlib import Path
PKG=Path(__file__).resolve().parent.parent
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
        ps=PKG/'host/Invoke-ExternalValidation.ps1'
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
        ps=PKG/'host/Invoke-ExternalValidation.ps1'
        p=subprocess.run(['pwsh','-NoProfile','-File',str(ps),'-CaseCsv',str(pilot_cases),'-BindingJson',str(binding),'-OutputDirectory',str(out)],capture_output=True,text=True,encoding='utf-8',errors='replace',timeout=30)
        self.assertEqual(p.returncode,0,p.stdout+p.stderr);self.assertIn('PREFLIGHT_ONLY',p.stdout);self.assertFalse(out.exists())
        out.mkdir();marker=out/'preserve.txt';marker.write_text('do not overwrite',encoding='ascii')
        p=subprocess.run(['pwsh','-NoProfile','-File',str(ps),'-CaseCsv',str(pilot_cases),'-BindingJson',str(binding),'-OutputDirectory',str(out)],capture_output=True,text=True,encoding='utf-8',errors='replace',timeout=30)
        self.assertNotEqual(p.returncode,0);self.assertEqual(marker.read_text(encoding='ascii'),'do not overwrite')
    @unittest.skipUnless(TCL_EXE.is_file(),'Quartus STP Tcl not installed at configured path')
    def test_direct_tcl_rejects_before_jtag_discovery(self):
        tcl=PKG/'host/run_external_validation.tcl'
        p=subprocess.run([str(TCL_EXE),'-t',str(tcl),str(self.cases),str(self.out),str(self.binding)],cwd=self.d,capture_output=True,text=True,encoding='utf-8',errors='replace',timeout=60)
        self.assertNotEqual(p.returncode,0)
        source=tcl.read_text(encoding='utf-8')
        self.assertLess(source.index('--verify-binding'),source.index('package require ::quartus::jtag'))
        self.assertLess(source.index('package require ::quartus::jtag'),source.index('get_hardware_names'))
        self.assertFalse(self.out.exists())

if __name__=='__main__':unittest.main(verbosity=2)
