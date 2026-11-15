#!/usr/bin/env python3
"""Offline tests for strict C3 v2 saved-run auditing; never writes physical data."""
from __future__ import annotations

import copy
import shutil
import sys
import tempfile
import unittest
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import audit_saved_c3_v2_runs as audit
import create_key_reset_replay_gate as gate_tool


class SavedRunAuditTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.c3 = HERE.parent
        cls.root = cls.c3 / "evidence/PHYSICAL_C3_V2_20261115"
        cls.runs = {
            "replay42": {
                "json": cls.root / "C2J2_REPLAY_RUN2_PASS/C3V2_C2J2_REPLAY_RUN2_20261115/c2_jtag_results.json",
                "csv": cls.root / "C2J2_REPLAY_RUN2_PASS/C3V2_C2J2_REPLAY_RUN2_20261115/c2_jtag_results.csv",
                "cases": cls.root / "C2J2_REPLAY_RUN2_PASS/prepared_input/cases.csv",
                "binding": cls.root / "C2J2_REPLAY_RUN2_PASS/prepared_input/binding.json",
                "raw": cls.root / "C2J2_REPLAY_RUN2_PASS/C3V2_C2J2_REPLAY_RUN2_20261115/c2_jtag_raw.log",
                "experiment": "C3V2_C2J2_REPLAY_RUN2_20261115",
            },
            "pilot20": {
                "json": cls.root / "TENINPUT_PILOT_SESSION1/C3V2_TENINPUT_PILOT_SESSION1_20261115/c2_jtag_results.json",
                "csv": cls.root / "TENINPUT_PILOT_SESSION1/C3V2_TENINPUT_PILOT_SESSION1_20261115/c2_jtag_results.csv",
                "cases": cls.root / "TENINPUT_PILOT_SESSION1/cases.csv",
                "binding": cls.root / "TENINPUT_PILOT_SESSION1/binding.json",
                "raw": cls.root / "TENINPUT_PILOT_SESSION1/C3V2_TENINPUT_PILOT_SESSION1_20261115/c2_jtag_raw.log",
                "experiment": "C3V2_TENINPUT_PILOT_SESSION1_20261115",
            },
        }

    def loaded(self, key="pilot20"):
        p = self.runs[key]
        result, binding = audit.read_json(p["json"]), audit.read_json(p["binding"])
        result_rows, case_rows = audit.read_csv(p["csv"]), audit.read_csv(p["cases"])
        ident = audit.audit_identity(result, binding, audit.sha(p["cases"]), audit.sha(p["binding"]), p["experiment"])
        return result, binding, result_rows, case_rows, ident

    def test_saved_42_physical_record_audits(self):
        p = self.runs["replay42"]
        result = audit.audit_files(p["json"], p["csv"], p["cases"], p["binding"], p["raw"], p["experiment"])
        self.assertEqual((result["status"], result["data_class"], result["response_count"]),
                         ("PASS_SAVED_PHYSICAL_EVIDENCE_AUDIT", "SAVED_PHYSICAL_EVIDENCE_NOT_NEW_MEASUREMENT", 42))
        self.assertEqual(result["unique_input_ids"], [0, 24, 57])

    def test_saved_20_pilot_physical_record_audits(self):
        p = self.runs["pilot20"]
        result = audit.audit_files(p["json"], p["csv"], p["cases"], p["binding"], p["raw"], p["experiment"])
        self.assertEqual(result["response_count"], 20)
        self.assertEqual(result["unique_input_ids"], list(range(1, 11)))

    def mutate_and_reject(self, mutation, message):
        result, binding, csv_rows, cases, ident = self.loaded()
        result, csv_rows = copy.deepcopy(result), copy.deepcopy(csv_rows)
        mutation(result, csv_rows)
        with self.assertRaisesRegex(ValueError, message):
            audit.audit_rows(result, csv_rows, cases, binding, ident)

    def test_duplicate_sequence_rejected(self):
        self.mutate_and_reject(lambda r, c: (r["cases"][1].update(seq=49), c[1].update(seq="49")), "sequence")

    def test_missing_sequence_rejected(self):
        self.mutate_and_reject(lambda r, c: (r["cases"].pop(), c.pop()), "row count")

    def test_uint64_overflow_rejected(self):
        self.mutate_and_reject(lambda r, c: r["cases"][0].update(cycles_start=1 << 64), "uint64")

    def test_nonmonotonic_start_end_rejected(self):
        self.mutate_and_reject(lambda r, c: r["cases"][0].update(cycles_end=r["cases"][0]["cycles_start"]), "nonmonotonic")

    def test_start_end_delta_mismatch_rejected(self):
        self.mutate_and_reject(lambda r, c: r["cases"][0].update(cycles_end=r["cases"][0]["cycles_end"] + 1), "delta mismatch")

    def test_crc_mismatch_rejected(self):
        self.mutate_and_reject(lambda r, c: (r["cases"][0].update(response_crc_valid=False), c[0].update(response_crc_valid="0")), "CRC")

    def test_response_id_mismatch_rejected(self):
        self.mutate_and_reject(lambda r, c: (r["cases"][0].update(response_input_id=999), c[0].update(response_input_id="999")), "identity")

    def test_cross_build_aggregation_rejected(self):
        identity = {"build_id": audit.BUILD, "sof_sha256": audit.SOF, "model_id": audit.MODEL,
                    "schedule_canonical_sha256": "frozen-A"}
        other = {**identity, "build_id": "43324a32", "sof_sha256": "5aa5be2e"}
        with self.assertRaisesRegex(ValueError, "different build/SOF/model/schedule"):
            audit.require_single_build([identity, other])

    def test_windows_extended_length_path_is_normalized_inside_evidence_root(self):
        sample = self.runs["replay42"]["json"]
        resolved = str(sample.resolve())
        if not resolved.startswith("\\\\?\\"):
            resolved = "\\\\?\\" + resolved
        self.assertTrue(audit.is_allowed_evidence_path(Path(resolved), self.root))
    def test_mock_or_synthetic_path_cannot_enter_physical_cli(self):
        with tempfile_context() as temp:
            mock = temp / "mock" / "made_up.csv"
            mock.parent.mkdir()
            mock.write_text("synthetic", encoding="ascii")
            self.assertFalse(audit.is_allowed_evidence_path(mock, self.root))

    def test_existing_pre_reset_pilot_cannot_make_reset_gate(self):
        p = self.runs["pilot20"]
        result = audit.read_json(p["json"])
        with self.assertRaisesRegex(ValueError, "not a new KEY-reset replay"):
            gate_tool.prepare_gate(result, {}, p["json"], p["json"], operator_confirmed_key0=True)

    def test_key_reset_gate_uses_portable_relative_evidence_paths(self):
        run_dir = Path.cwd().parent / "evidence" / "PHYSICAL_C3_V2_20261115" / "KEY_RESET_REPLAY" / "C3V2_TENINPUT_KEY_RESET_REPLAY_20261115_RUN2"
        with tempfile.TemporaryDirectory(prefix="rtnn-c3-gate-test-") as temp:
            copied = Path(temp)
            for name in ("c2_jtag_results.json", "c2_jtag_results.csv", "c2_jtag_raw.log",
                         "C3V2_TENINPUT_KEY_RESET_REPLAY_20261115_RUN2.independent_audit.json"):
                shutil.copy2(run_dir / name, copied / name)
            result_path = copied / "c2_jtag_results.json"
            audit_path = copied / "C3V2_TENINPUT_KEY_RESET_REPLAY_20261115_RUN2.independent_audit.json"
            result = audit.read_json(result_path)
            audit_report = audit.read_json(audit_path)
            gate = gate_tool.prepare_gate(result, audit_report, result_path, audit_path, operator_confirmed_key0=True)
            self.assertEqual(result_path.name, gate["result_json_path"])
            self.assertEqual(audit_path.name, gate["audit_report_path"])
            self.assertNotIn("\\\\", gate["result_json_path"])

    def test_identity_check_source_has_no_virtual_jtag_write_or_programmer_call(self):
        source = (HERE / "check_c3_v2_loaded_build.tcl").read_text(encoding="utf-8")
        self.assertNotIn("quartus_pgm", source)
        self.assertNotIn("-dr_value", source)
        self.assertIn("device_virtual_dr_shift -instance_index $instance -length $bits -value_in_hex", source)


class tempfile_context:
    """Tiny context wrapper to keep test fixtures outside the repository."""
    def __enter__(self):
        import tempfile
        self._tmp = tempfile.TemporaryDirectory(prefix="rtnn-c3-v2-test-")
        return Path(self._tmp.name)
    def __exit__(self, *exc):
        self._tmp.cleanup()


if __name__ == "__main__":
    unittest.main(verbosity=2)






