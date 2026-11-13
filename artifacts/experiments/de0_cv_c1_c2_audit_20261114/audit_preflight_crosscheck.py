import csv
import json
from pathlib import Path

here = Path(__file__).resolve().parent
repo = here.parents[2]
cases_path = here / "C2" / "vectors" / "c2j2_cases.csv"
reference_path = repo / "artifacts" / "certification" / "de0_cv_preflight_vectors.json"
rows = list(csv.DictReader(cases_path.open(newline="", encoding="utf-8")))
reference = json.loads(reference_path.read_text(encoding="utf-8"))
vectors = {v["test_index"]: v for v in reference["vectors"]}
errors = []
for row in rows:
    index = int(row["test_index"])
    vector = vectors.get(index)
    if vector is None:
        errors.append({"seq": int(row["seq"]), "error": "unknown_test_index"})
        continue
    pixels = list(bytes.fromhex(row["pixels_u8_64_hex"]))
    expected_prediction = vector["expected_fixed_class_prediction"][int(row["expected_executed"])]
    for field, actual, expected in (
        ("pixels", pixels, vector["input_u8_64"]),
        ("label", int(row["expected_label"]), vector["label"]),
        ("prediction", int(row["expected_prediction"]), expected_prediction),
    ):
        if actual != expected:
            errors.append({"seq": int(row["seq"]), "field": field, "actual": actual, "expected": expected})
result = {
    "status": "PASS" if len(rows) == 42 and not errors else "FAIL",
    "case_count": len(rows),
    "unique_test_indices": sorted({int(row["test_index"]) for row in rows}),
    "checked_fields_per_case": ["pixels", "label", "expected_prediction_at_expected_executed_class"],
    "mismatch_count": len(errors),
    "mismatches": errors,
}
(here / "preflight_crosscheck.json").write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
print(json.dumps(result))
if result["status"] != "PASS":
    raise SystemExit(1)