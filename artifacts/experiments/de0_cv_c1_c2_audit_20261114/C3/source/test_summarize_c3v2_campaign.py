#!/usr/bin/env python3
"""Regression test for C3 v2 campaign evidence paths on Windows."""
from pathlib import Path
import sys
import unittest

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import summarize_c3v2_campaign_20261115 as campaign_audit


class CampaignPathTests(unittest.TestCase):
    def test_long_saved_audit_path_is_openable(self):
        c3 = HERE.parent
        saved = (c3 / "evidence/PHYSICAL_C3_V2_20261115/FROZEN_CAMPAIGN"
                 / "C3V2_PRIMARY01_FULL720_RUN1_20261115/python_independent_audit.json")
        resolved = campaign_audit.fs_path(saved)
        self.assertTrue(resolved.is_file(), str(resolved))


if __name__ == "__main__":
    unittest.main(verbosity=2)
