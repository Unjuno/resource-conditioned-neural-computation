import json,sys,tempfile,unittest,shutil,csv,zlib
from pathlib import Path
sys.path.insert(0,str(Path(__file__).parent))
from audit_and_analyze import load_run,audit_raw_jtag,readcsv
class PhysicalGateTests(unittest.TestCase):
 def test_raw_jtag_decoder_handles_full_7626_case_fixture(self):
  # Synthetic protocol fixture stresses the complete primary row count only;
  # it is never submitted to load_run or accepted as physical evidence.
  from pilot_gate import validate_primary_schedule
  pkg=Path(__file__).resolve().parents[1]
  with (pkg/'build/host_cases_primary_attempt2/cases.csv').open(newline='',encoding='utf-8') as f: cases=list(csv.DictReader(f))
  exp='SYNTHETIC_PRIMARY_PARSER_FIXTURE';session='SYNTHETIC_SESSION';sof='5e333e9377b7188a394d04b93b98833d91afb2cd53eca8d976e6aa715dfa00c4'
  for i,c in enumerate(cases,22): c['experiment_id']=exp;c['session_id']=session;c['sequence']=str(i)
  validate_primary_schedule(cases)
  crc=lambda b:zlib.crc32(b)&0xffffffff
  results=[]
  with tempfile.TemporaryDirectory() as td:
   run=Path(td)
   with (run/'raw_jtag.log').open('w',encoding='ascii',newline='\n') as log:
    log.write(f'hardware=USB-Blaster [synthetic] device=@synthetic experiment={exp} session={session} sof_sha256={sof} uart=false flash_written=false sof_programming=false\n')
    for c in cases:
     seq=int(c['sequence']);iid=int(c['input_id']);mode=1 if c['mode']=='fixed2' else 3;pixels=bytes.fromhex(c['pixels_hex']);pcrc=crc(pixels)
     req=bytearray(b'RTNQ\x02'+bytes((mode,2 if mode==1 else 0,0)))+bytearray(seq.to_bytes(4,'little')+iid.to_bytes(2,'little')+(65535).to_bytes(2,'little')+bytes(4)+bytes.fromhex('52544e4e')[::-1]+bytes.fromhex('45585631')[::-1])
     req+=crc(req[:28]).to_bytes(4,'little')+pixels+pcrc.to_bytes(4,'little')
     start=100000+seq*1000;end=start+500;stop={'none':0,'entropy':1,'budget':2}[c['expected_stop_reason']]
     rsp=bytearray(60);rsp[:5]=b'RTNR\x03';rsp[5:8]=bytes((0,mode,stop));rsp[8:12]=seq.to_bytes(4,'little');rsp[12:14]=iid.to_bytes(2,'little');rsp[16:20]=pcrc.to_bytes(4,'little');rsp[20:24]=bytes((int(c['expected_admitted_exit']),int(c['expected_executed_exit']),int(c['expected_prediction']),255));rsp[24:32]=start.to_bytes(8,'little');rsp[32:40]=end.to_bytes(8,'little');rsp[40:44]=bytes.fromhex('52544e4e')[::-1];rsp[44:48]=bytes.fromhex('45585631')[::-1];rsp[48:52]=bytes.fromhex('45585632')[::-1];rsp[52]=1;rsp[56:60]=crc(rsp[:56]).to_bytes(4,'little')
     log.write(f"request seq={seq} input_id={iid} mode={c['mode']} request_lsb_hex={req[::-1].hex()}\n")
     log.write(f"response seq={seq} raw_lsb_hex={rsp[::-1].hex()}\n")
     results.append({'payload_crc32':str(pcrc),'request_crc_ok':'1','response_crc_ok':'1','prediction':c['expected_prediction'],'admitted_exit':c['expected_admitted_exit'],'executed_exit':c['expected_executed_exit'],'cycles_start':str(start),'cycles_end':str(end),'cycles':'500'})
   status={'experiment_id':exp,'session_id':session,'sof_sha256':sof}
   audited=audit_raw_jtag(run,cases,results,status)
   self.assertEqual(audited['request_frames'],7626);self.assertEqual(audited['response_frames'],7626)
 def test_raw_jtag_decoder_matches_saved_pilot_protocol_frames(self):
  # Protocol parser regression only; this reuses the preserved pilot as a
  # parser fixture and does not promote it to a primary campaign result.
  run=Path(__file__).resolve().parents[1]/'build/physical_pilot_RUN4_complete_20261126'
  cases=readcsv(run/'cases.csv');results=readcsv(run/'physical_results.csv')
  status=json.loads((run/'run_status.json').read_text(encoding='utf-8-sig'))
  audit=audit_raw_jtag(run,cases,results,status)
  self.assertEqual(audit['request_frames'],20);self.assertEqual(audit['response_frames'],20)
 def test_raw_jtag_decoder_rejects_missing_or_corrupt_response(self):
  source=Path(__file__).resolve().parents[1]/'build/physical_pilot_RUN4_complete_20261126'
  cases=readcsv(source/'cases.csv');results=readcsv(source/'physical_results.csv')
  status=json.loads((source/'run_status.json').read_text(encoding='utf-8-sig'))
  with tempfile.TemporaryDirectory() as td:
   run=Path(td);shutil.copyfile(source/'raw_jtag.log',run/'raw_jtag.log')
   p=run/'raw_jtag.log';p.write_text('\n'.join(x for x in p.read_text().splitlines() if not x.startswith('response seq=2 '))+'\n',encoding='utf-8')
   with self.assertRaisesRegex(ValueError,'count mismatch'):audit_raw_jtag(run,cases,results,status)
  with tempfile.TemporaryDirectory() as td:
   run=Path(td);shutil.copyfile(source/'raw_jtag.log',run/'raw_jtag.log')
   p=run/'raw_jtag.log';text=p.read_text();line=next(x for x in text.splitlines() if x.startswith('response seq=2 '));raw=line.split('raw_lsb_hex=')[1];bad=('0' if raw[0]!='0' else '1')+raw[1:];p.write_text(text.replace(raw,bad,1),encoding='utf-8')
   with self.assertRaisesRegex(ValueError,'response framing/CRC'):audit_raw_jtag(run,cases,results,status)
  with tempfile.TemporaryDirectory() as td:
   run=Path(td);shutil.copyfile(source/'raw_jtag.log',run/'raw_jtag.log')
   p=run/'raw_jtag.log';p.write_text(p.read_text()+'request seq=999 malformed\n',encoding='utf-8')
   with self.assertRaisesRegex(ValueError,'malformed raw JTAG'):audit_raw_jtag(run,cases,results,status)
 def test_mock_data_is_rejected_before_csv_import(self):
  with tempfile.TemporaryDirectory() as td:
   p=Path(td);(p/'run_status.json').write_text(json.dumps({'schema':'rtnn-external-validation-physical-v1','status':'COMPLETE','run_source':'mock','mock':True,'hardware_opened':False,'cycles_source':'synthetic'}))
   with self.assertRaisesRegex(ValueError,'actual USB-Blaster'):load_run(p,'primary')
 def test_old_build_is_rejected(self):
  with tempfile.TemporaryDirectory() as td:
   p=Path(td);(p/'run_status.json').write_text(json.dumps({'schema':'rtnn-external-validation-physical-v1','status':'COMPLETE','run_source':'quartus_stp_virtual_jtag','mock':False,'hardware_opened':True,'cycles_source':'Ibex_mcycle','build_id':'43334531'}))
   with self.assertRaisesRegex(ValueError,'wrong build family'):load_run(p,'primary')
if __name__=='__main__':unittest.main(verbosity=2)
