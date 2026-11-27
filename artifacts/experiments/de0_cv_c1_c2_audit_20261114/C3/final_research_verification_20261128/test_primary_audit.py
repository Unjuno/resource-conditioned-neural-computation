import sys,tempfile,unittest
from pathlib import Path
ROOT=Path(__file__).resolve().parent
PKG=ROOT.parent/"external_validation_20261122"
sys.path.insert(0,str(ROOT))
from audit_primary import audit_schedule,rcsv,raw_pairs,verify_manifest
class PrimaryAuditTests(unittest.TestCase):
 @classmethod
 def setUpClass(cls):
  cls.baseline=rcsv(PKG/"build/host_cases_primary_attempt2/cases.csv")
  cls.prepared=rcsv(ROOT/"primary_schedule_OFFLINE_TEMPLATE.csv")
 @staticmethod
 def reject(rows,start=1):
  with PrimaryAuditTests.assertRaises(PrimaryAuditTests(),ValueError):
   audit_schedule(rows,PKG,start)
 def test_frozen_existing_schedule(self):
  r=audit_schedule(self.baseline,PKG,1)
  self.assertEqual((r["rows"],r["unique_images"],r["sequence_last"]),(7626,3813,7626))
 def test_prepared_sequence_offset_schedule(self):
  r=audit_schedule(self.prepared,PKG,22)
  self.assertEqual((r["sequence_first"],r["sequence_last"]),(22,7647))
  self.assertTrue(r["experiment_id"].startswith("OFFLINE_"))
 def test_missing_row_rejected(self):
  self.reject(self.baseline[:-1])
 def test_duplicate_sequence_rejected(self):
  x=[dict(r) for r in self.baseline];x[1]["sequence"]=x[0]["sequence"];self.reject(x)
 def test_wrong_input_order_rejected(self):
  x=[dict(r) for r in self.baseline];x[0]["input_id"],x[2]["input_id"]=x[2]["input_id"],x[0]["input_id"];self.reject(x)
 def test_pixel_tamper_rejected(self):
  x=[dict(r) for r in self.baseline];x[0]["pixels_hex"]="ff"+x[0]["pixels_hex"][2:];self.reject(x)
 def test_teacher_label_tamper_rejected(self):
  x=[dict(r) for r in self.baseline];x[0]["teacher_label"]=str((int(x[0]["teacher_label"])+1)%10);self.reject(x)
 def test_oracle_tamper_rejected(self):
  x=[dict(r) for r in self.baseline];x[0]["expected_prediction"]=str((int(x[0]["expected_prediction"])+1)%10);self.reject(x)
 def test_crc_tamper_rejected(self):
  x=[dict(r) for r in self.baseline];x[0]["payload_crc32"]=str(int(x[0]["payload_crc32"])^1);self.reject(x)
 def test_wrong_build_rejected(self):
  x=[dict(r) for r in self.baseline];x[0]["build_id"]="43334531";self.reject(x)
 def test_raw_pilot_log_parses_without_device_access(self):
  req,rsp=raw_pairs(PKG/"build/physical_pilot_RUN4_complete_20261126/raw_jtag.log")
  self.assertEqual(len(req),20);self.assertEqual(sorted(req),list(range(2,22)));self.assertEqual(set(req),set(rsp))
 def test_raw_log_corruption_rejected(self):
  source=(PKG/"build/physical_pilot_RUN4_complete_20261126/raw_jtag.log").read_text(encoding="utf-8")
  line=next(x for x in source.splitlines() if x.startswith("response seq="))
  prefix,hexpart=line.split("raw_lsb_hex=",1);hexpart=("0" if hexpart[0]!="0" else "1")+hexpart[1:]
  altered=source.replace(line,prefix+"raw_lsb_hex="+hexpart,1)
  with tempfile.TemporaryDirectory() as td:
   p=Path(td)/"raw_jtag.log";p.write_text(altered,encoding="utf-8")
   with self.assertRaises(ValueError):raw_pairs(p)
 def test_manifest_path_traversal_rejected(self):
  with tempfile.TemporaryDirectory() as td:
   root=Path(td);outside=root.parent/"outside_rtnn_manifest_test.txt";outside.write_text("fixture",encoding="ascii")
   try:
    import hashlib
    h=hashlib.sha256(outside.read_bytes()).hexdigest()
    (root/"SHA256SUMS.txt").write_text(f"{h}  ../outside_rtnn_manifest_test.txt\n",encoding="ascii")
    with self.assertRaises(ValueError):verify_manifest(root,[])
   finally:outside.unlink(missing_ok=True)
 def test_manifest_duplicate_name_rejected(self):
  with tempfile.TemporaryDirectory() as td:
   root=Path(td);p=root/"x.txt";p.write_text("x",encoding="ascii")
   import hashlib
   h=hashlib.sha256(p.read_bytes()).hexdigest()
   (root/"SHA256SUMS.txt").write_text(f"{h}  x.txt\n{h}  x.txt\n",encoding="ascii")
   with self.assertRaises(ValueError):verify_manifest(root,["x.txt"])
if __name__=="__main__":unittest.main(verbosity=2)
