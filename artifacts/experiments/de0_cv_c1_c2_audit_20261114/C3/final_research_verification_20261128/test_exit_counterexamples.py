import json
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parent
OUT = ROOT / "exit_counterexamples_RUN2_20261128"


class ExitCounterexampleTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.summary = json.loads((OUT / "EXIT_COUNTEREXAMPLES_SUMMARY.json").read_text(encoding="utf-8"))

    def test_complete_exit_transition_matrix(self):
        self.assertEqual(self.summary["frozen_oracle_all_exit_mismatches"], 0)
        self.assertEqual(len(self.summary["adjacent_exit_correctness_transitions"]), 6)
        for row in self.summary["adjacent_exit_correctness_transitions"]:
            self.assertEqual(row["incorrect_to_correct"] + row["correct_to_incorrect"] + row["same_correctness"], 360)

    def test_later_exit_regression_is_not_hidden(self):
        self.assertEqual(self.summary["images_with_any_correct_then_later_incorrect_exit"], 12)
        self.assertEqual(self.summary["per_exit"][5]["correct"], 336)
        self.assertEqual(self.summary["per_exit"][6]["correct"], 333)

    def test_scope_does_not_claim_physical_performance(self):
        self.assertIn("OFFLINE_DESCRIPTIVE", self.summary["classification"])
        self.assertTrue(any("WCET" in item for item in self.summary["limits"]))


if __name__ == "__main__":
    unittest.main()
