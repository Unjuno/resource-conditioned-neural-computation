#!/usr/bin/env python3
"""Focused regressions for previously uncovered C3 v2 audit boundaries."""
from __future__ import annotations

import copy
import sys
import unittest
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import audit_saved_c3_v2_runs as audit


class ContractGapTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        root = HERE.parent / "evidence/PHYSICAL_C3_V2_20261115"
        cls.bundle = {
            "json": root / "TENINPUT_PILOT_SESSION1/C3V2_TENINPUT_PILOT_SESSION1_20261115/c2_jtag_results.json",
            "csv": root / "TENINPUT_PILOT_SESSION1/C3V2_TENINPUT_PILOT_SESSION1_20261115/c2_jtag_results.csv",
            "cases": root / "TENINPUT_PILOT_SESSION1/cases.csv",
            "binding": root / "TENINPUT_PILOT_SESSION1/binding.json",
        }
        cls.result = audit.read_json(cls.bundle["json"])
        cls.binding = audit.read_json(cls.bundle["binding"])
        cls.csv_rows = audit.read_csv(cls.bundle["csv"])
        cls.case_rows = audit.read_csv(cls.bundle["cases"])
        cls.identity = audit.audit_identity(
            cls.result, cls.binding, audit.sha(cls.bundle["cases"]),
            audit.sha(cls.bundle["binding"]), "C3V2_TENINPUT_PILOT_SESSION1_20261115")
        cls.evidence_root = root

    def test_uint64_counter_wrap_is_rejected(self):
        result = copy.deepcopy(self.result)
        csv_rows = copy.deepcopy(self.csv_rows)
        result["cases"][0]["cycles_start"] = audit.U64_MAX - 1
        result["cases"][0]["cycles_end"] = 4
        csv_rows[0]["cycles_start"] = str(audit.U64_MAX - 1)
        csv_rows[0]["cycles_end"] = "4"
        with self.assertRaisesRegex(ValueError, "nonmonotonic"):
            audit.audit_rows(result, csv_rows, self.case_rows, self.binding, self.identity)

    def test_missing_crc_field_is_rejected(self):
        result = copy.deepcopy(self.result)
        csv_rows = copy.deepcopy(self.csv_rows)
        result["cases"][0].pop("response_crc_valid")
        csv_rows[0].pop("response_crc_valid")
        with self.assertRaises(KeyError):
            audit.audit_rows(result, csv_rows, self.case_rows, self.binding, self.identity)

    def test_old_build_identity_is_rejected_by_c3_auditor(self):
        result = copy.deepcopy(self.result)
        result["build_id"] = "43324a32"
        with self.assertRaisesRegex(ValueError, "not C3 v2 build"):
            audit.audit_identity(result, self.binding, audit.sha(self.bundle["cases"]),
                                 audit.sha(self.bundle["binding"]))

    def test_mock_directory_inside_physical_root_is_rejected(self):
        mock = self.evidence_root / "mock" / "synthetic_run" / "results.json"
        self.assertFalse(audit.is_allowed_evidence_path(mock, self.evidence_root))


if __name__ == "__main__":
    unittest.main(verbosity=2)
