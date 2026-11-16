#!/usr/bin/env python3
"""Independent diagnostic-budget guards; no physical device access."""
import json
import unittest
from pathlib import Path
import analyze_budget_diagnostics as mod

class BudgetEvidenceTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.aggregate=json.loads((mod.C3V2_DIR/"C3V2_CAMPAIGN_AGGREGATE_AUDIT_20261115.json").read_text())
        cls.byname={e["schedule_id"]:e for e in cls.aggregate["runs"]}

    def test_adaptive_21_budget_full_360(self):
        meta, rows=mod.load_diagnostic("diagnostic_adaptive","C3V2_DIAGADAPTIVE_FULL7560_RUN1_20261115",7560,3,self.byname["diagnostic_adaptive"])
        self.assertEqual(len(rows),7560)
        budgets={r["budget_q16"] for r in rows}
        self.assertEqual(len(budgets),21)
        self.assertEqual(min(budgets),0)
        self.assertEqual(max(budgets),65535)
        for b in budgets:
            cohort=[x for x in rows if x["budget_q16"]==b]
            self.assertEqual(len(cohort),360)
            self.assertEqual(set(x["input_id"] for x in cohort),set(range(360)))
        self.assertTrue(all(r["executed_exit"]<=r["admitted_exit"] for r in rows))

    def test_capped_21_budget_full_360(self):
        meta, rows=mod.load_diagnostic("diagnostic_capped","C3V2_DIAGCAPPED_FULL7560_RUN1_20261115",7560,2,self.byname["diagnostic_capped"])
        self.assertEqual(len(rows),7560)
        self.assertEqual(len(set(x["budget_q16"] for x in rows)),21)
        self.assertTrue(all(r["executed_exit"]<=r["admitted_exit"] for r in rows))

    def test_wrong_hash_rejected(self):
        record=dict(self.byname["diagnostic_fixed"])
        record["results_csv_sha256"]="0"*64
        with self.assertRaisesRegex(ValueError,"result sha"):
            mod.load_diagnostic("diagnostic_fixed","C3V2_DIAGFIXED_FULL2520_RUN2_20261115",2520,1,record)

    def test_normalized_budget_ranges(self):
        self.assertEqual(mod.summary([{"input_id":i,"cycles":100,"prediction":3,"label":3,"executed_exit":0} for i in range(360)],"diagnostic_capped",0)["correct"],360)

if __name__=="__main__":
    unittest.main(verbosity=2)
