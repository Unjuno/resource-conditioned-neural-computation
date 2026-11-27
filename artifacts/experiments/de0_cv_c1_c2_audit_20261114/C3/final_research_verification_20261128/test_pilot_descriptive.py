import csv,sys,tempfile,unittest
from pathlib import Path
ROOT=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT))
from analyze_pilot_descriptive import analyze
RUN=ROOT.parent/"external_validation_20261122"/"build"/"physical_pilot_RUN4_complete_20261126"
class PilotDescriptiveTests(unittest.TestCase):
 def test_saved_run4_descriptive_only(self):
  x=analyze(RUN/"physical_results.csv")
  self.assertEqual(x["classification"],"ENGINEERING_PILOT_DESCRIPTIVE_ONLY")
  self.assertEqual((x["case_count"],x["image_count"],x["adaptive_faster_count"]),(20,10,8))
  self.assertEqual(x["adaptive_slower_input_ids"],[519,667])
 def test_missing_case_rejected(self):
  with (RUN/"physical_results.csv").open(encoding="utf-8",newline="") as f:rows=list(csv.DictReader(f))
  with tempfile.TemporaryDirectory() as td:
   p=Path(td)/"short.csv"
   with p.open("w",encoding="utf-8",newline="") as f:w=csv.DictWriter(f,fieldnames=rows[0].keys());w.writeheader();w.writerows(rows[:-1])
   with self.assertRaises(ValueError):analyze(p)
 def test_reference_mismatch_rejected(self):
  with (RUN/"physical_results.csv").open(encoding="utf-8",newline="") as f:rows=list(csv.DictReader(f))
  rows[0]["reference_prediction"]=str((int(rows[0]["reference_prediction"])+1)%10)
  with tempfile.TemporaryDirectory() as td:
   p=Path(td)/"tamper.csv"
   with p.open("w",encoding="utf-8",newline="") as f:w=csv.DictWriter(f,fieldnames=rows[0].keys());w.writeheader();w.writerows(rows)
   with self.assertRaises(ValueError):analyze(p)
if __name__=="__main__":unittest.main(verbosity=2)
