#!/usr/bin/env python3
"""Focused adversarial tests; no FPGA, JTAG, Quartus or downloads."""
import csv
import unittest
import sys
import tempfile
from unittest.mock import patch
from copy import deepcopy
import reanalyze_c3v2_primary as a

class EvidenceGuardTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.source = a.C3V2_DIR / "C3V2_PRIMARY01_FULL720_RUN1_20261115/results/c2_jtag_results.csv"
        with cls.source.open(newline="", encoding="utf-8") as f:
            cls.good = next(csv.DictReader(f))

    def edited(self, key, value):
        x = deepcopy(self.good)
        x[key] = value
        return x

    def test_known_real_row_passes(self):
        a.validate_row(self.good, "43334531", a.NEW_SOF, True)

    def test_bad_build_fails(self):
        with self.assertRaisesRegex(ValueError, "build/SOF"):
            a.validate_row(self.edited("build_id", "43324a32"), "43334531", a.NEW_SOF, True)

    def test_wrong_sof_fails(self):
        with self.assertRaisesRegex(ValueError, "build/SOF"):
            a.validate_row(self.edited("sof_sha256", a.OLD_SOF), "43334531", a.NEW_SOF, True)

    def test_crc_fails(self):
        with self.assertRaisesRegex(ValueError, "CRC/cycle"):
            a.validate_row(self.edited("response_crc_valid", "0"), "43334531", a.NEW_SOF, True)

    def test_counter_equal_fails(self):
        with self.assertRaisesRegex(ValueError, "counter monotonicity"):
            a.validate_row(self.edited("cycles_end", self.good["cycles_start"]), "43334531", a.NEW_SOF, True)

    def test_counter_wrap_64_fails(self):
        with self.assertRaisesRegex(ValueError, "counter monotonicity"):
            a.validate_row(self.edited("cycles_end", str(2**64)), "43334531", a.NEW_SOF, True)

    def test_counter_inconsistent_delta_fails(self):
        with self.assertRaisesRegex(ValueError, "interval mismatch"):
            a.validate_row(self.edited("cycles", "1"), "43334531", a.NEW_SOF, True)

    def test_prediction_mismatch_fails(self):
        with self.assertRaisesRegex(ValueError, "Q15"):
            a.validate_row(self.edited("expected_prediction", "99"), "43334531", a.NEW_SOF, True)

    def test_wrong_exit_fails(self):
        with self.assertRaisesRegex(ValueError, "executed exit"):
            a.validate_row(self.edited("executed_exit", "6"), "43334531", a.NEW_SOF, True)

    def test_reject_wrong_csv_digest(self):
        with self.assertRaisesRegex(ValueError, "SHA mismatch"):
            a.load_rows(self.source, "43334531", a.NEW_SOF, True, "0"*64)

    def test_refuse_overwrite_existing_output(self):
        with tempfile.TemporaryDirectory() as existing:
            with patch.object(sys, "argv", ["reanalyze", "--out-dir", existing]):
                with self.assertRaisesRegex(ValueError, "refusing to overwrite"):
                    a.main()

if __name__ == "__main__":
    unittest.main(verbosity=2)
