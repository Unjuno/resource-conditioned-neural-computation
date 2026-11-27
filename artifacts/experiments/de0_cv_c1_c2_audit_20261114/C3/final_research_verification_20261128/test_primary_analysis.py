import sys,unittest
from pathlib import Path
ROOT=Path(__file__).resolve().parent;sys.path.insert(0,str(ROOT))
from analyze_audited_primary import PKG
from audit_primary import audit_schedule,rcsv
class PrimaryReadinessTests(unittest.TestCase):
 def test_frozen_primary_schedule_precheck(self):
  rows=rcsv(PKG/"build/host_cases_primary_attempt2/cases.csv")
  x=audit_schedule(rows,PKG,1)
  self.assertEqual((x["rows"],x["unique_images"]),(7626,3813))
 def test_physical_analysis_is_not_called_on_schedule_only(self):
  from analyze_audited_primary import summarize
  with self.assertRaises((FileNotFoundError,ValueError,KeyError)):
   summarize(ROOT/"primary_schedule_OFFLINE_TEMPLATE.csv")
if __name__=="__main__":unittest.main(verbosity=2)
