import csv,hashlib,json,os,subprocess,tempfile,unittest,zlib
from pathlib import Path
import sys
HERE=Path(__file__).resolve().parent
PKG=HERE.parent
sys.path.insert(0,str(HERE))
from pilot_gate import audit_run,verify_binding,verify_gate,ensure_unique_experiment_id,validate_primary_schedule
from power_session import classify,SCHEMA
sys.path.insert(0,str(PKG/'scripts'))
from audit_and_analyze import load_run

def sha(b): return hashlib.sha256(b).hexdigest()
def putjson(p,x): p.write_text(json.dumps(x,indent=2)+'\n',encoding='utf-8')
def crc(b): return zlib.crc32(b)&0xffffffff
def build_fixture(td):
    d=Path(td); base=PKG/'build'
    with (base/'host_cases_pilot_attempt2/cases.csv').open(newline='',encoding='utf-8') as f: cases=list(csv.DictReader(f))
    oracle=PKG/'build/cpu_oracle_attempt1/oracle_pilot.csv'
    for i,r in enumerate(cases,1): r['experiment_id']='FIXTURE_ONLY';r['session_id']='FIXTURE_SESSION';r['sequence']=str(i)
    cp=d/'cases.csv'
    with cp.open('w',newline='',encoding='utf-8') as f:
        w=csv.DictWriter(f,fieldnames=cases[0].keys());w.writeheader();w.writerows(cases)
    binding={'status':'PHYSICAL_ELIGIBLE','classification':'EMPIRICAL_ONLY','split':'pilot','experiment_id':'FIXTURE_ONLY','session_id':'FIXTURE_SESSION','cases_csv_sha256':sha(cp.read_bytes()),'sof_sha256':'5e333e9377b7188a394d04b93b98833d91afb2cd53eca8d976e6aa715dfa00c4','firmware_elf_sha256':'4673f6a8b90493c15c327ed3be1167e0fcf3ff2be60292dcb12a1391124a0c2e','model_id':'52544e4e','build_id':'45585631','binding_id':'45585632'}
    putjson(d/'binding.json',binding)
    header='experiment_id,session_id,sequence,input_id,mode,teacher_label,reference_prediction,prediction,expected_admitted_exit,admitted_exit,expected_executed_exit,executed_exit,expected_stop_reason,stop_reason,cycles_start,cycles_end,cycles,payload_crc32,request_crc_ok,response_crc_ok,model_id,build_id,binding_id,sof_sha256,status,error\n'
    results=[header]; logs=[]
    for c in cases:
        px=bytes.fromhex(c['pixels_hex']); mode=1 if c['mode']=='fixed2' else 3; seq=int(c['sequence']); iid=int(c['input_id']); start=100000+seq*1000; end=start+500
        req=bytearray(b'RTNQ\x02'+bytes([mode,2 if mode==1 else 0,0])); req+=seq.to_bytes(4,'little')+iid.to_bytes(2,'little')+(65535).to_bytes(2,'little')+bytes(4)+bytes.fromhex(c['model_id'])[::-1]+bytes.fromhex(c['build_id'])[::-1]
        # The Tcl wire constants are encoded little-endian.
        req[20:24]=bytes.fromhex('52544e4e')[::-1];req[24:28]=bytes.fromhex('45585631')[::-1]
        req+=crc(req).to_bytes(4,'little')+px+crc(px).to_bytes(4,'little')
        logs.append(f"request seq={seq} input_id={iid} mode={c['mode']} request_lsb_hex={req[::-1].hex()}\n")
        b=bytearray(60);b[:5]=b'RTNR\x03';stop={'none':0,'entropy':1,'budget':2}[c['expected_stop_reason']]
        b[5:8]=bytes([0,mode,stop]);b[8:12]=seq.to_bytes(4,'little');b[12:14]=iid.to_bytes(2,'little');b[16:20]=int(c['payload_crc32']).to_bytes(4,'little')
        b[20:24]=bytes([int(c['expected_admitted_exit']),int(c['expected_executed_exit']),int(c['expected_prediction']),255]);b[24:32]=start.to_bytes(8,'little');b[32:40]=end.to_bytes(8,'little')
        b[40:44]=bytes.fromhex('52544e4e')[::-1];b[44:48]=bytes.fromhex('45585631')[::-1];b[48:52]=bytes.fromhex('45585632')[::-1];b[52]=1;b[56:60]=crc(b[:56]).to_bytes(4,'little')
        logs.append(f"response seq={seq} raw_lsb_hex={b[::-1].hex()}\n")
        results.append(f"FIXTURE_ONLY,FIXTURE_SESSION,{seq},{iid},{c['mode']},{c['teacher_label']},{c['expected_prediction']},{c['expected_prediction']},{c['expected_admitted_exit']},{c['expected_admitted_exit']},{c['expected_executed_exit']},{c['expected_executed_exit']},{c['expected_stop_reason']},{stop},{start},{end},500,{c['payload_crc32']},1,1,52544e4e,45585631,45585632,5e333e9377b7188a394d04b93b98833d91afb2cd53eca8d976e6aa715dfa00c4,PASS,\n")
    (d/'physical_results.csv').write_text(''.join(results),encoding='utf-8');(d/'raw_jtag.log').write_text(''.join(logs),encoding='utf-8')
    (d/'run_external_validation.tcl').write_text('# fixture only\n');(d/'launcher.log').write_text('fixture only\n')
    status={'schema':'rtnn-external-validation-physical-v1','status':'COMPLETE','run_source':'quartus_stp_virtual_jtag','mock':False,'hardware_opened':True,'cycles_source':'Ibex_mcycle','experiment_id':'FIXTURE_ONLY','session_id':'FIXTURE_SESSION','sof_sha256':binding['sof_sha256'],'build_id':'45585631','model_id':'52544e4e','binding_id':'45585632','uart_used':False,'flash_written':False,'sof_programming_performed':False,'completed_cases':20,'expected_cases':20,'cases_csv_sha256':sha(cp.read_bytes()),'fixture_only':True}
    putjson(d/'run_status.json',status)
    files=('cases.csv','binding.json','run_external_validation.tcl','launcher.log','physical_results.csv','raw_jtag.log','run_status.json')
    (d/'SHA256SUMS.txt').write_text(''.join(f"{sha((d/n).read_bytes())}  {n}\n" for n in files),encoding='ascii')
    return d,oracle,PKG/'data/pilot_manifest.csv',PKG/'data/primary_manifest.csv'

def refresh_hashes(run):
    names=('cases.csv','binding.json','run_external_validation.tcl','launcher.log','physical_results.csv','raw_jtag.log','run_status.json')
    (run/'SHA256SUMS.txt').write_text(''.join(f"{sha((run/n).read_bytes())}  {n}\n" for n in names),encoding='ascii')

class GateTest(unittest.TestCase):
    def test_primary_schedule_binds_pixels_labels_oracle_order_and_sequences(self):
        source=PKG/'build/host_cases_primary_attempt2/cases.csv'
        with source.open(newline='',encoding='utf-8') as f: rows=list(csv.DictReader(f))
        for i,r in enumerate(rows,22): r['sequence']=str(i)
        evidence=validate_primary_schedule(rows)
        self.assertEqual(evidence['first_sequence'],22)
        self.assertEqual(evidence['last_sequence'],7647)
        for field,value in [('pixels_hex','00'*64),('teacher_label','9'),('expected_prediction','9')]:
            changed=[dict(r) for r in rows];changed[0][field]=value
            with self.assertRaises(ValueError): validate_primary_schedule(changed)
        reordered=[dict(r) for r in rows];reordered[0],reordered[1]=reordered[1],reordered[0]
        with self.assertRaisesRegex(ValueError,'execution order'): validate_primary_schedule(reordered)
        noncontiguous=[dict(r) for r in rows];noncontiguous[1]['sequence']='24'
        with self.assertRaisesRegex(ValueError,'contiguous'): validate_primary_schedule(noncontiguous)
        reused=[dict(r) for r in rows];reused[0]['sequence']='21'
        with self.assertRaisesRegex(ValueError,'after the recorded pilot'): validate_primary_schedule(reused)

    def test_completed_run_sequence_audit_allows_later_runs_but_rejects_overlap(self):
        with (PKG/'build/host_cases_primary_attempt2/cases.csv').open(newline='',encoding='utf-8') as f: rows=list(csv.DictReader(f))
        for i,r in enumerate(rows,22): r['sequence']=str(i)
        with tempfile.TemporaryDirectory(dir=PKG/'build',prefix='test_primary_seq_history_') as td:
            base=Path(td);run=base/'current';later=base/'later';run.mkdir();later.mkdir()
            (run/'run_status.json').write_text('{"status":"COMPLETE"}',encoding='utf-8')
            (later/'raw_jtag.log').write_text('request seq=9000 input_id=1 mode=fixed2 request_lsb_hex=aa\n',encoding='ascii')
            # A later session may have higher sequence numbers when an older
            # completed run is audited; only collisions are rejected here.
            evidence=validate_primary_schedule(rows,exclude_run=run)
            self.assertEqual(evidence['first_sequence'],22)
            (later/'raw_jtag.log').write_text('request seq=22 input_id=1 mode=fixed2 request_lsb_hex=aa\n',encoding='ascii')
            with self.assertRaisesRegex(ValueError,'overlaps another recorded run'):
                validate_primary_schedule(rows,exclude_run=run)

    def test_complete_fixture_audits_only_in_test_context(self):
        with tempfile.TemporaryDirectory() as td:
            run,oracle,pilot,primary=build_fixture(td)
            self.assertEqual(audit_run(run,oracle,pilot,primary,fixture_ok=True)['audit'],'PILOT_AUDIT_PASS')
            with self.assertRaisesRegex(ValueError,'fixture cannot create'):
                audit_run(run,oracle,pilot,primary)
    def test_handwritten_pass_missing_evidence_rejected(self):
        with tempfile.TemporaryDirectory() as td:
            p=Path(td)/'gate.json';putjson(p,{'schema':'rtnn-extval-pilot-gate-v1','audit':'PILOT_AUDIT_PASS','classification':'EMPIRICAL_ONLY','case_count':20})
            with self.assertRaises(ValueError):verify_gate(p)
    def test_missing_or_malformed_gate_rejected(self):
        with tempfile.TemporaryDirectory() as td:
            p=Path(td)/'bad.json';p.write_text('{not json',encoding='utf-8')
            with self.assertRaises(Exception):verify_gate(p)
            with self.assertRaises(Exception):verify_gate(Path(td)/'missing.json')
    def test_experiment_id_reuse_rejected(self):
        with tempfile.TemporaryDirectory() as td:
            root=Path(td);putjson(root/'binding.json',{'experiment_id':'ALREADY_USED'})
            with self.assertRaisesRegex(ValueError,'already recorded'):
                ensure_unique_experiment_id(root,'ALREADY_USED')
            run=root/'run';run.mkdir();putjson(run/'binding.json',{'experiment_id':'THIS_RUN'});putjson(run/'run_status.json',{'experiment_id':'THIS_RUN'})
            ensure_unique_experiment_id(root,'THIS_RUN',run/'binding.json')
    def test_raw_log_change_breaks_manifest(self):
        with tempfile.TemporaryDirectory() as td:
            run,oracle,pilot,primary=build_fixture(td);(run/'raw_jtag.log').write_text('tampered')
            with self.assertRaisesRegex(ValueError,'changed run artifact'):
                audit_run(run,oracle,pilot,primary,fixture_ok=True)
    def test_response_crc_and_counter_tampering_rejected(self):
        with tempfile.TemporaryDirectory() as td:
            run,oracle,pilot,primary=build_fixture(td)
            p=run/'raw_jtag.log';text=p.read_text();line=next(x for x in text.splitlines() if x.startswith('response seq=1 '))
            raw=line.split('raw_lsb_hex=')[1];changed=('0' if raw[0]!='0' else '1')+raw[1:]
            p.write_text(text.replace(raw,changed,1),encoding='utf-8');refresh_hashes(run)
            with self.assertRaisesRegex(ValueError,'response version/CRC mismatch'):
                audit_run(run,oracle,pilot,primary,fixture_ok=True)
        with tempfile.TemporaryDirectory() as td:
            run,oracle,pilot,primary=build_fixture(td)
            p=run/'physical_results.csv';lines=p.read_text().splitlines();cells=lines[1].split(',');cells[16]=str(int(cells[16])+1);lines[1]=','.join(cells);p.write_text('\n'.join(lines)+'\n');refresh_hashes(run)
            with self.assertRaisesRegex(ValueError,'raw counter/results mismatch'):
                audit_run(run,oracle,pilot,primary,fixture_ok=True)
    def test_truncated_case_rejected(self):
        with tempfile.TemporaryDirectory() as td:
            run,oracle,pilot,primary=build_fixture(td);(run/'cases.csv').write_text('\n'.join((run/'cases.csv').read_text().splitlines()[:-1])+'\n')
            with self.assertRaisesRegex(ValueError,'changed run artifact'):
                audit_run(run,oracle,pilot,primary,fixture_ok=True)
    def test_primary_binding_without_gate_rejected(self):
        with tempfile.TemporaryDirectory() as td:
            p=Path(td)/'binding.json';putjson(p,{'split':'primary','status':'PHYSICAL_ELIGIBLE','experiment_id':'PRIMARY_GATE_MISSING_TEST'})
            with self.assertRaisesRegex(ValueError,'gate missing'):verify_binding(p)
    def test_primary_audit_rejects_before_reading_result_tables(self):
        with tempfile.TemporaryDirectory() as td:
            d=Path(td);putjson(d/'run_status.json',{'schema':'rtnn-external-validation-physical-v1','status':'COMPLETE','run_source':'quartus_stp_virtual_jtag','mock':False,'hardware_opened':True,'cycles_source':'Ibex_mcycle','experiment_id':'PRIMARY_AUDIT_TEST','build_id':'45585631','model_id':'52544e4e','binding_id':'45585632','cases_csv_sha256':'x','sof_sha256':'a'*64})
            putjson(d/'binding.json',{'status':'PHYSICAL_ELIGIBLE','split':'primary','experiment_id':'PRIMARY_AUDIT_TEST','cases_csv_sha256':'x','sof_sha256':'a'*64})
            with self.assertRaisesRegex(ValueError,'primary pilot gate missing'):
                load_run(d,'primary')
    def test_primary_case_count_must_be_exact(self):
        with tempfile.TemporaryDirectory() as td:
            p=Path(td)/'binding.json';cases=PKG/'build/host_cases_primary_attempt2/cases.csv'
            putjson(p,{'split':'primary','status':'PHYSICAL_ELIGIBLE','cases_csv_sha256':sha(cases.read_bytes()),'case_count':7})
            with self.assertRaisesRegex(ValueError,'case count mismatch'):
                verify_binding(p,cases)
    def test_gate_recomputes_raw_response_and_sof_binding(self):
        with tempfile.TemporaryDirectory() as td:
            run,oracle,pilot,primary=build_fixture(td)
            g={'schema':'rtnn-extval-pilot-gate-v1',**audit_run(run,oracle,pilot,primary,fixture_ok=True),'operator_authorization':'recorded','operator_authorization_is_not_execution_proof':True}
            gate=Path(td)/'gate.json';putjson(gate,g)
            pb={'split':'primary','experiment_id':'FIXTURE_PRIMARY_BINDING','pilot_gate_path':str(gate),'pilot_gate_sha256':sha(gate.read_bytes()),'sof_sha256':g['sof_sha256'],'build_id':g['build_id'],'binding_id':g['binding_id'],'model_id':g['model_id'],'input_manifest_sha256':sha(primary.read_bytes())}
            bind=Path(td)/'primary_binding.json';putjson(bind,pb)
            self.assertEqual(verify_binding(bind,fixture_ok=True)['audit'],'PILOT_AUDIT_PASS')
            pb['sof_sha256']='a'*64;putjson(bind,pb)
            with self.assertRaisesRegex(ValueError,'sof_sha256 differs'):verify_binding(bind,fixture_ok=True)
    def test_gate_cannot_be_reused_for_another_binding_or_tampered_evidence(self):
        with tempfile.TemporaryDirectory() as td:
            run,oracle,pilot,primary=build_fixture(td)
            g={'schema':'rtnn-extval-pilot-gate-v1',**audit_run(run,oracle,pilot,primary,fixture_ok=True),'operator_authorization':'not_recorded','operator_authorization_is_not_execution_proof':True}
            gate=Path(td)/'gate.json';putjson(gate,g)
            pb={'split':'primary','experiment_id':'FIXTURE_PRIMARY_REUSE','pilot_gate_path':str(gate),'pilot_gate_sha256':sha(gate.read_bytes()),'sof_sha256':g['sof_sha256'],'build_id':g['build_id'],'binding_id':g['binding_id'],'model_id':g['model_id'],'input_manifest_sha256':sha(primary.read_bytes())}
            bind=Path(td)/'primary_binding.json';putjson(bind,pb)
            self.assertEqual(verify_binding(bind,fixture_ok=True)['audit'],'PILOT_AUDIT_PASS')
            pb['build_id']='OLD_BUILD';putjson(bind,pb)
            with self.assertRaisesRegex(ValueError,'build_id differs'):verify_binding(bind,fixture_ok=True)
            pb['build_id']=g['build_id'];pb['pilot_gate_sha256']='0'*64;putjson(bind,pb)
            with self.assertRaisesRegex(ValueError,'SHA mismatch'):verify_binding(bind,fixture_ok=True)
            pb['pilot_gate_sha256']=sha(gate.read_bytes());putjson(bind,pb)
            (run/'raw_jtag.log').write_text('tampered after gate')
            with self.assertRaisesRegex(ValueError,'changed run artifact'):verify_binding(bind,fixture_ok=True)
    def test_mock_failed_old_build_and_corrupt_crc_rejected(self):
        with tempfile.TemporaryDirectory() as td:
            run,oracle,pilot,primary=build_fixture(td)
            status=json.loads((run/'run_status.json').read_text());status['mock']=True;putjson(run/'run_status.json',status);refresh_hashes(run)
            with self.assertRaisesRegex(ValueError,'not a logged physical'):audit_run(run,oracle,pilot,primary,fixture_ok=True)
        with tempfile.TemporaryDirectory() as td:
            run,oracle,pilot,primary=build_fixture(td)
            status=json.loads((run/'run_status.json').read_text());status['status']='FAILED';putjson(run/'run_status.json',status);refresh_hashes(run)
            with self.assertRaisesRegex(ValueError,'not COMPLETE'):audit_run(run,oracle,pilot,primary,fixture_ok=True)
        with tempfile.TemporaryDirectory() as td:
            run,oracle,pilot,primary=build_fixture(td)
            status=json.loads((run/'run_status.json').read_text());status['build_id']='43334531';putjson(run/'run_status.json',status);refresh_hashes(run)
            with self.assertRaisesRegex(ValueError,'wrong pilot build'):audit_run(run,oracle,pilot,primary,fixture_ok=True)
        with tempfile.TemporaryDirectory() as td:
            run,oracle,pilot,primary=build_fixture(td)
            text=(run/'raw_jtag.log').read_text();(run/'raw_jtag.log').write_text(text.replace('raw_lsb_hex=','raw_lsb_hex=f',1));refresh_hashes(run)
            with self.assertRaisesRegex(ValueError,'bad raw response framing'):audit_run(run,oracle,pilot,primary,fixture_ok=True)
    def test_failed_case_cannot_be_promoted_to_pass(self):
        with tempfile.TemporaryDirectory() as td:
            run,oracle,pilot,primary=build_fixture(td)
            p=run/'physical_results.csv';lines=p.read_text().splitlines();cells=lines[1].split(',');cells[24]='FAIL';lines[1]=','.join(cells);p.write_text('\n'.join(lines)+'\n');refresh_hashes(run)
            with self.assertRaisesRegex(ValueError,'result/case identity mismatch|status'):
                audit_run(run,oracle,pilot,primary,fixture_ok=True)
    def test_changed_predictions_and_split_mixing_rejected(self):
        with tempfile.TemporaryDirectory() as td:
            run,oracle,pilot,primary=build_fixture(td)
            p=run/'physical_results.csv';lines=p.read_text().splitlines();cells=lines[1].split(',');cells[7]=str((int(cells[7])+1)%10);lines[1]=','.join(cells);p.write_text('\n'.join(lines)+'\n');refresh_hashes(run)
            with self.assertRaisesRegex(ValueError,'raw response/CSV prediction mismatch|CPU oracle mismatch'):audit_run(run,oracle,pilot,primary,fixture_ok=True)
        with tempfile.TemporaryDirectory() as td:
            run,oracle,pilot,primary=build_fixture(td)
            p=run/'cases.csv';lines=p.read_text().splitlines();cells=lines[1].split(',');cells[3]='1';lines[1]=','.join(cells);p.write_text('\n'.join(lines)+'\n');refresh_hashes(run)
            status=json.loads((run/'run_status.json').read_text());status['cases_csv_sha256']=sha(p.read_bytes());putjson(run/'run_status.json',status);refresh_hashes(run)
            with self.assertRaisesRegex(ValueError,'pilot binding mismatch'):audit_run(run,oracle,pilot,primary,fixture_ok=True)
class PowerEvidenceTest(unittest.TestCase):
    def base(self,kind):return {'schema':SCHEMA,'event_kind':kind,'session_id':'S1','experiment_id':'E','previous_session_id':'BASELINE_PRE_CAMPAIGN','board_identity':'DE0-CV-1','build_id':'45585631','sof_sha256':'a'*64,'operator_action':'operator action recorded','power_state_method':'scope rail trace','measurement_uncertainty':'scope/probe tolerance recorded','unknown_items':[],'operation_time_utc':'2026-11-22T00:00:00Z','recorded_time_utc':'2026-11-22T00:00:05Z'}
    def test_three_names_or_operator_claim_never_prove_rail(self):
        with tempfile.TemporaryDirectory() as td:
            for kind in ('LOGICAL_KEY_RESET_ONLY','SOF_RECONFIGURATION_ONLY','OPERATOR_ATTESTED_POWER_CYCLE_RAIL_UNVERIFIED','POWER_SESSION_UNKNOWN'):
                self.assertEqual(classify(self.base(kind),Path(td)),'POWER_SESSION_UNKNOWN' if kind=='POWER_SESSION_UNKNOWN' else 'COLD_BOOT_UNVERIFIED')
    def test_attestation_only_full_claim_downgrades(self):
        with tempfile.TemporaryDirectory() as td:
            r=self.base('FULL_RAIL_POWER_CYCLE_EVIDENCE_VERIFIED');r['operator_attestation']='I power cycled';r['usb_blaster_power_state']='unknown'
            self.assertEqual(classify(r,Path(td)),'COLD_BOOT_UNVERIFIED')
    def test_scope_record_requires_hashed_data_and_all_power_paths(self):
        with tempfile.TemporaryDirectory() as td:
            p=Path(td)/'wave.csv';p.write_text('time_s,voltage_v\n0,5.0\n0.2,1.2\n0.4,0.05\n1.5,0.02\n')
            r=self.base('FULL_RAIL_POWER_CYCLE_EVIDENCE_VERIFIED');r.update(power_target='all_board_power_inputs_and_fpga_rails',usb_blaster_power_state='physically_disconnected_during_rail_decay',before_identity='same',after_identity='same')
            ident={'jtag_idcode':'02b050dd','build_id':'45585631','binding_id':'45585632','model_id':'52544e4e','sof_sha256':'a'*64}
            r.update(operation_time_utc='2026-11-22T00:00:00Z',recorded_time_utc='2026-11-22T00:00:05Z',before_identity=ident,after_identity=ident,jtag_idcode='02b050dd',binding_id='45585632',model_id='52544e4e',all_power_inputs_enumerated=True,power_path_inventory=['board_input'])
            r['rail_measurements']=[{'instrument':'scope','channel':'CH1','rail_name':'board_input','path':'wave.csv','sha256':sha(p.read_bytes())}]
            self.assertEqual(classify(r,Path(td)),'FULL_RAIL_POWER_CYCLE_EVIDENCE_VERIFIED')
            r['usb_blaster_power_state']='unknown';self.assertEqual(classify(r,Path(td)),'COLD_BOOT_UNVERIFIED')
            r['usb_blaster_power_state']='physically_disconnected_during_rail_decay';r['unknown_items']=['unverified power path']
            self.assertEqual(classify(r,Path(td)),'COLD_BOOT_UNVERIFIED')
            r['unknown_items']=[];r.pop('operator_action')
            self.assertEqual(classify(r,Path(td)),'COLD_BOOT_UNVERIFIED')
            r['operator_action']='recorded';r['recorded_time_utc']='2026-11-21T23:59:00Z'
            self.assertEqual(classify(r,Path(td)),'COLD_BOOT_UNVERIFIED')
    def test_reused_scope_file_across_three_session_names_is_not_independent(self):
        from power_session import audit_sessions
        with tempfile.TemporaryDirectory() as td:
            d=Path(td);wave=d/'wave.csv';wave.write_text('time_s,voltage_v\n0,5\n0.2,1\n0.4,0.01\n1.5,0.01\n')
            paths=[]
            for i in range(1,4):
                r=self.base('FULL_RAIL_POWER_CYCLE_EVIDENCE_VERIFIED')
                ident={'jtag_idcode':'02b050dd','build_id':'45585631','binding_id':'45585632','model_id':'52544e4e','sof_sha256':'a'*64}
                r.update(session_id=f'S{i}',previous_session_id='BASELINE_PRE_CAMPAIGN' if i==1 else f'S{i-1}',power_target='all_board_power_inputs_and_fpga_rails',usb_blaster_power_state='physically_disconnected_during_rail_decay',before_identity=ident,after_identity=ident,jtag_idcode='02b050dd',binding_id='45585632',model_id='52544e4e',all_power_inputs_enumerated=True,power_path_inventory=['board_dc_input'],operation_time_utc=f'2026-11-22T00:00:0{i}Z',recorded_time_utc=f'2026-11-22T00:00:1{i}Z')
                r['rail_measurements']=[{'instrument':'scope','channel':'CH1','rail_name':'board_dc_input','path':'wave.csv','sha256':sha(wave.read_bytes())}]
                p=d/f'S{i}.json';putjson(p,r);paths.append(p)
            a=audit_sessions(paths,['S1','S2','S3'],'DE0-CV-1','45585631','a'*64)
            self.assertEqual(a['classification'],'COLD_BOOT_UNVERIFIED')
    def test_power_identity_usb_and_experiment_mismatch_are_not_independent(self):
        from power_session import audit_sessions
        with tempfile.TemporaryDirectory() as td:
            d=Path(td);paths=[]
            for i in range(1,4):
                wave=d/f'w{i}.csv';wave.write_text('time_s,voltage_v\n0,5\n0.2,0.01\n1.5,0.01\n')
                r=self.base('FULL_RAIL_POWER_CYCLE_EVIDENCE_VERIFIED');ident={'jtag_idcode':'02b050dd','build_id':'45585631','binding_id':'45585632','model_id':'52544e4e','sof_sha256':'a'*64}
                r.update(session_id=f'S{i}',experiment_id=f'E{i}',previous_session_id='BASELINE_PRE_CAMPAIGN' if i==1 else f'S{i-1}',power_target='all_board_power_inputs_and_fpga_rails',usb_blaster_power_state='physically_disconnected_during_rail_decay',before_identity=ident,after_identity=ident,jtag_idcode='02b050dd',binding_id='45585632',model_id='52544e4e',all_power_inputs_enumerated=True,power_path_inventory=[f'rail{i}'],operation_time_utc=f'2026-11-22T00:00:0{i}Z',recorded_time_utc=f'2026-11-22T00:00:1{i}Z')
                r['rail_measurements']=[{'instrument':'scope','channel':'CH1','rail_name':f'rail{i}','path':wave.name,'sha256':sha(wave.read_bytes())}]
                p=d/f'S{i}.json';putjson(p,r);paths.append(p)
            a=audit_sessions(paths,['S1','S2','S3'],'DE0-CV-1','45585631','a'*64,['E1','WRONG','E3'])
            self.assertEqual(a['classification'],'COLD_BOOT_UNVERIFIED')
            r=json.loads(paths[1].read_text());r['experiment_id']='E2';r['usb_blaster_power_state']='unknown';putjson(paths[1],r)
            a=audit_sessions(paths,['S1','S2','S3'],'DE0-CV-1','45585631','a'*64,['E1','E2','E3'])
            self.assertEqual(a['classification'],'COLD_BOOT_UNVERIFIED')
            r['usb_blaster_power_state']='physically_disconnected_during_rail_decay';putjson(paths[1],r)
            r3=json.loads(paths[2].read_text());r3['board_identity']='OTHER-BOARD';putjson(paths[2],r3)
            a=audit_sessions(paths,['S1','S2','S3'],'DE0-CV-1','45585631','a'*64,['E1','E2','E3'])
            self.assertEqual(a['classification'],'COLD_BOOT_UNVERIFIED')
            r3['board_identity']='DE0-CV-1';r3['sof_sha256']='b'*64;putjson(paths[2],r3)
            a=audit_sessions(paths,['S1','S2','S3'],'DE0-CV-1','45585631','a'*64,['E1','E2','E3'])
            self.assertEqual(a['classification'],'COLD_BOOT_UNVERIFIED')
    def test_wave_hash_mismatch_fails(self):
        with tempfile.TemporaryDirectory() as td:
            p=Path(td)/'wave.csv';p.write_text('time_s,voltage_v\n0,5\n0.2,1\n0.4,0.01\n1.5,0.01\n')
            r=self.base('FULL_RAIL_POWER_CYCLE_EVIDENCE_VERIFIED');ident={'jtag_idcode':'02b050dd','build_id':'45585631','binding_id':'45585632','model_id':'52544e4e','sof_sha256':'a'*64};r.update(power_target='all_board_power_inputs_and_fpga_rails',usb_blaster_power_state='physically_disconnected_during_rail_decay',before_identity=ident,after_identity=ident,jtag_idcode='02b050dd',binding_id='45585632',model_id='52544e4e',all_power_inputs_enumerated=True,power_path_inventory=['input'],operation_time_utc='t',recorded_time_utc='t')
            r['rail_measurements']=[{'instrument':'scope','channel':'CH1','rail_name':'input','path':'wave.csv','sha256':'0'*64}]
            self.assertEqual(classify(r,Path(td)),'COLD_BOOT_UNVERIFIED')

if __name__=='__main__':unittest.main(verbosity=2)
