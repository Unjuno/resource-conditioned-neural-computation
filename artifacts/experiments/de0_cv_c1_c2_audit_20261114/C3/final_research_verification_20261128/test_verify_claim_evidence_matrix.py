import csv
import tempfile
import unittest
from pathlib import Path

from verify_claim_evidence_matrix import validate


class ClaimEvidenceMatrixTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.root = Path(self.temp.name)
        self.matrix = self.root / "matrix.csv"
        (self.root / "evidence.md").write_text("evidence\n", encoding="utf-8")

    def tearDown(self):
        self.temp.cleanup()

    def write_matrix(self, evidence, claim_id="C1", status="PASS_WITH_SCOPE"):
        with self.matrix.open("w", encoding="utf-8", newline="") as stream:
            writer = csv.DictWriter(
                stream,
                fieldnames=["claim_id", "claim", "evidence", "status", "allowed_wording", "not_supported"],
            )
            writer.writeheader()
            writer.writerow({
                "claim_id": claim_id,
                "claim": "test",
                "evidence": evidence,
                "status": status,
                "allowed_wording": "bounded",
                "not_supported": "generalization",
            })

    def test_resolves_repo_relative_evidence(self):
        self.write_matrix("evidence.md")
        self.assertEqual(validate(self.matrix, self.root), [])

    def test_rejects_prose_as_evidence_path(self):
        self.write_matrix("Gate B signoff unresolved")
        self.assertTrue(any("evidence file missing" in e for e in validate(self.matrix, self.root)))

    def test_rejects_missing_evidence_file(self):
        self.write_matrix("missing.md")
        self.assertTrue(any("evidence file missing" in e for e in validate(self.matrix, self.root)))

    def test_rejects_repository_escape(self):
        self.write_matrix("../outside.md")
        self.assertTrue(any("escapes repository" in e for e in validate(self.matrix, self.root)))

    def test_preserves_evidence_bounded_claim_statuses(self):
        for claim_id, expected in (("C6", "OBSERVED_EMPIRICAL_ONLY"), ("C7", "INELIGIBLE"), ("C8", "BLOCKED")):
            with self.subTest(claim_id=claim_id):
                self.write_matrix("evidence.md", claim_id=claim_id, status="PASS")
                errors = validate(self.matrix, self.root)
                self.assertTrue(any(f"status must remain {expected}" in e for e in errors))


if __name__ == "__main__":
    unittest.main(verbosity=2)
