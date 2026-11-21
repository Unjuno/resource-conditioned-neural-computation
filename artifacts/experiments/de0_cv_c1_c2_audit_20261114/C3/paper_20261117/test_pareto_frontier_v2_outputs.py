"""Integrity checks for the archived v2 input-level diagnostic outputs."""

import csv
import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parent
RUN3 = ROOT / "pareto_input_audit_run3"
RUN4 = ROOT / "pareto_input_audit_run4"


def read_csv(path):
    with path.open(newline="", encoding="utf-8") as handle:
        return list(csv.DictReader(handle))


def test_v2_output_cardinalities_and_identity():
    level = read_csv(RUN3 / "PARETO_INPUT_LEVEL.csv")
    pairs = read_csv(RUN3 / "PARETO_FIXED2_PAIRWISE.csv")
    nonmonotonic = read_csv(RUN3 / "PARETO_BUDGET_ACCURACY_NONMONOTONIC.csv")
    points = read_csv(RUN3 / "PARETO_POINTS.csv")
    assert (len(level), len(pairs), len(nonmonotonic), len(points)) == (
        17_640, 7_560, 36, 49
    )
    keys = [(row["kind"], row["condition"], row["input_id"]) for row in level]
    assert len(keys) == len(set(keys))
    analysis = json.loads((RUN3 / "PARETO_ANALYSIS.json").read_text(encoding="utf-8"))
    assert analysis["classification"] == "SECONDARY_EXPLORATORY_EMPIRICAL_ONLY"
    assert analysis["data"]["unique_input_ids"] == 360
    assert analysis["data"]["cold_boot_independent"] is False


def test_every_fixed2_pair_is_recomputed_from_input_rows():
    level = read_csv(RUN3 / "PARETO_INPUT_LEVEL.csv")
    index = {(row["kind"], row["condition"], int(row["input_id"])): row for row in level}
    pairs = read_csv(RUN3 / "PARETO_FIXED2_PAIRWISE.csv")
    seen = set()
    for pair in pairs:
        budget = pair["budget_q16"]
        input_id = int(pair["input_id"])
        key = (budget, input_id)
        assert key not in seen
        seen.add(key)
        adaptive = index[("diagnostic_adaptive", f"budget_q16={budget}", input_id)]
        fixed = index[("diagnostic_fixed", "fixed_exit=2", input_id)]
        delta = int(adaptive["cycles"]) - int(fixed["cycles"])
        assert int(pair["adaptive_cycles"]) == int(adaptive["cycles"])
        assert int(pair["fixed2_cycles"]) == int(fixed["cycles"])
        assert int(pair["adaptive_minus_fixed2_cycles"]) == delta
    assert len(seen) == 21 * 360


def test_final_runs_have_identical_output_manifests():
    manifest3 = (RUN3 / "SHA256SUMS.txt").read_bytes()
    manifest4 = (RUN4 / "SHA256SUMS.txt").read_bytes()
    assert manifest3 == manifest4
    for line in manifest3.decode("ascii").splitlines():
        expected, name = line.split("  ", 1)
        actual = hashlib.sha256((RUN3 / name).read_bytes()).hexdigest()
        assert actual == expected, name


def test_v2_budget_anomalies_preserve_input_id_lists():
    rows = read_csv(RUN3 / "PARETO_BUDGET_ACCURACY_NONMONOTONIC.csv")
    by_kind = {}
    for row in rows:
        by_kind.setdefault(row["kind"], []).append(row)
        assert int(row["higher_budget_q16"]) > int(row["lower_budget_q16"])
        assert int(row["higher_correct"]) <= int(row["lower_correct"])
    assert set(by_kind) == {"diagnostic_adaptive", "diagnostic_capped"}
    assert len(by_kind["diagnostic_adaptive"]) == 18
    assert len(by_kind["diagnostic_capped"]) == 18
