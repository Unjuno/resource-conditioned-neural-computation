import unittest

from analyze_session01_diagnostics import summarize_rows


def row(input_id, mode, label, prediction, cycles, exit_id=1):
    return {
        "input_id": str(input_id), "mode": mode, "teacher_label": str(label),
        "prediction": str(prediction), "cycles": str(cycles),
        "admitted_exit": str(exit_id), "executed_exit": str(exit_id),
    }


class SessionDiagnosticsTests(unittest.TestCase):
    def setUp(self):
        self.rows = [
            row(1, "fixed2", 0, 0, 100, 2), row(1, "adaptive", 0, 1, 120, 1),
            row(2, "fixed2", 1, 0, 100, 2), row(2, "adaptive", 1, 1, 80, 3),
        ]

    def test_reports_paired_transitions_and_slow_cases(self):
        result = summarize_rows(self.rows, {"data_integrity": "PASS"}, expected_inputs=2)
        self.assertEqual(result["paired_correctness_transitions"], {
            "both_correct": 0, "fixed2_only_correct": 1,
            "adaptive_only_correct": 1, "both_wrong": 0,
        })
        self.assertEqual(result["adaptive_minus_fixed2_cycles"]["adaptive_slower_count"], 1)
        self.assertEqual(result["teacher_label_class_breakdown"]["0"]["fixed2_correct"], 1)
        self.assertEqual(result["teacher_label_class_breakdown"]["1"]["adaptive_correct"], 1)
        self.assertEqual(result["adaptive_exit_cycle_and_correctness_delta"]["1"]["adaptive_slower_count"], 1)

    def test_rejects_duplicate_input_mode(self):
        with self.assertRaisesRegex(ValueError, "duplicate input/mode"):
            summarize_rows(self.rows + [self.rows[0]], {"data_integrity": "PASS"}, expected_inputs=2)

    def test_rejects_missing_mode_pair(self):
        with self.assertRaisesRegex(ValueError, "incomplete mode pair"):
            summarize_rows(self.rows[:-1], {"data_integrity": "PASS"}, expected_inputs=2)


if __name__ == "__main__":
    unittest.main(verbosity=2)
