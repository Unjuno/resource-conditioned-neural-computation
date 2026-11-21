import json,sys,tempfile,unittest
from pathlib import Path
sys.path.insert(0,str(Path(__file__).parent))
from audit_and_analyze import load_run
class PhysicalGateTests(unittest.TestCase):
 def test_mock_data_is_rejected_before_csv_import(self):
  with tempfile.TemporaryDirectory() as td:
   p=Path(td);(p/'run_status.json').write_text(json.dumps({'schema':'rtnn-external-validation-physical-v1','status':'COMPLETE','run_source':'mock','mock':True,'hardware_opened':False,'cycles_source':'synthetic'}))
   with self.assertRaisesRegex(ValueError,'actual USB-Blaster'):load_run(p,'primary')
 def test_old_build_is_rejected(self):
  with tempfile.TemporaryDirectory() as td:
   p=Path(td);(p/'run_status.json').write_text(json.dumps({'schema':'rtnn-external-validation-physical-v1','status':'COMPLETE','run_source':'quartus_stp_virtual_jtag','mock':False,'hardware_opened':True,'cycles_source':'Ibex_mcycle','build_id':'43334531'}))
   with self.assertRaisesRegex(ValueError,'wrong build family'):load_run(p,'primary')
if __name__=='__main__':unittest.main(verbosity=2)
