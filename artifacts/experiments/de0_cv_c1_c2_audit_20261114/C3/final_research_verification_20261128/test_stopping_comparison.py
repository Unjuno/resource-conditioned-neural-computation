import csv
import hashlib
import json
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parent
RUN = ROOT / "q15_stopping_comparison_RUN8_20261128"


class StoppingComparisonArtifactTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.result = json.loads((RUN / "STOPPING_COMPARISON.json").read_text(encoding="utf-8"))

    def test_scope_and_frozen_q15_identity(self):
        self.assertEqual(self.result["classification"], "OFFLINE_Q15_HELDOUT_ANALYSIS_NOT_NEW_EXTERNAL_EVALUATION")
        self.assertEqual(self.result["source"]["dataset"], "sklearn.load_digits")
        self.assertEqual(self.result["source"]["test_count"], 360)
        self.assertEqual(self.result["crosscheck"]["heldout_all_exit_prediction_mismatches_vs_frozen_q15_oracle"], 0)
        self.assertEqual(self.result["crosscheck"]["entropy_preferred_exit_mismatches"], 0)

    def test_q15_metric_rows_complete_and_normalized(self):
        for name, expected in (("q15_validation_exit_metrics.csv", 359 * 7), ("q15_heldout360_exit_metrics.csv", 360 * 7)):
            with (RUN / name).open(encoding="ascii", newline="") as f:
                rows = list(csv.DictReader(f))
            self.assertEqual(len(rows), expected)
            self.assertEqual(len({(r["input_id"], r["exit"]) for r in rows}), expected)
            self.assertTrue(all(abs(int(r["probability_sum_q15"]) - 32768) <= 8 for r in rows))

    def test_saved_csv_is_exact_binary_stdout(self):
        record = json.loads((RUN / "COMPILER_RECORD.json").read_text(encoding="utf-8"))
        for split, name in (("validation_compile", "q15_validation_exit_metrics.csv"), ("heldout_compile", "q15_heldout360_exit_metrics.csv")):
            self.assertEqual(hashlib.sha256((RUN / name).read_bytes()).hexdigest(), record[split]["stdout_sha256"])

    def test_entropy_counterexamples_are_retained(self):
        metrics = self.result["entropy_vs_fixed2_heldout360"]
        self.assertEqual(metrics["adaptive_wrong_fixed2_correct"], 3)
        self.assertEqual(metrics["adaptive_correct_fixed2_wrong"], 3)
        with (RUN / "ENTROPY_VS_FIXED2_HELDOUT360.csv").open(encoding="utf-8", newline="") as f:
            rows = list(csv.DictReader(f))
        self.assertEqual(len(rows), 360)
        self.assertEqual(sum(int(r["entropy_correct"]) == 0 and int(r["fixed2_correct"]) == 1 for r in rows), 3)

    def test_no_cycles_or_confirmatory_claims(self):
        self.assertIn("no cycle", self.result["timing_scope"].lower())
        paired = self.result["paired_input_bootstrap_vs_fixed2"]["heldout360"]
        for row in paired.values():
            lo, hi = row["paired_accuracy_difference_method_minus_fixed2"]
            self.assertLessEqual(lo, 0.0)
            self.assertGreaterEqual(hi, 0.0)
            self.assertIn("no writer clustering", row["unit"])


if __name__ == "__main__":
    unittest.main()
