import sys,unittest
from pathlib import Path
sys.path.insert(0,str(Path(__file__).parent))
from stats_core import paired_ni_lower,paired_cycle_bootstrap
class StatsTests(unittest.TestCase):
 def test_ni_zero_difference_not_pass_for_tight_margin(self):
  r=paired_ni_lower([1]*60,[1]*60); self.assertFalse(r['numeric_pass']); self.assertEqual(r['n'],60)
 def test_ni_strong_adaptive_dominance(self):
  r=paired_ni_lower([0]*100,[1]*100); self.assertTrue(r['numeric_pass'])
 def test_cycle_bootstrap_deterministic(self):
  x=paired_cycle_bootstrap([100]*10,[80]*10,draws=1000); y=paired_cycle_bootstrap([100]*10,[80]*10,draws=1000)
  self.assertEqual(x,y); self.assertEqual(x['ratio_of_sums'],0.2); self.assertTrue(x['numeric_pass'])
 def test_bad_pairs_rejected(self):
  with self.assertRaises(ValueError): paired_cycle_bootstrap([1],[0])
  with self.assertRaises(ValueError): paired_ni_lower([1],[1,0])
if __name__=='__main__': unittest.main(verbosity=2)
