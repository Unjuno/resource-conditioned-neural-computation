#!/usr/bin/env python3
"""Check that the integrated Q15 table matches the saved RUN8 analysis."""
from __future__ import annotations

import json
import math
from pathlib import Path


ROOT = Path(__file__).resolve().parent
RUN = ROOT / "q15_stopping_comparison_RUN8_20261128"
PAPER = ROOT / "MANUSCRIPT_EN_DRAFT_20261128B.md"
REPORT = RUN / "STOPPING_COMPARISON.json"
PLOT = RUN / "STOPPING_PARETO_HELDOUT360.svg"

EXPECTED = {
    "Fixed Exit 0": "fixed_exit_0",
    "Fixed Exit 1": "fixed_exit_1",
    "Fixed Exit 2": "fixed_exit_2",
    "Fixed Exit 3": "fixed_exit_3",
    "Fixed Exit 4": "fixed_exit_4",
    "Fixed Exit 5": "fixed_exit_5",
    "Fixed Exit 6 (diagnostic only)": "fixed_exit_6",
    "Frozen entropy": "frozen_entropy_policy",
    "Validation-selected max-softmax": "max_softmax_q15",
    "Validation-selected top-two margin": "top2_probability_margin_q15",
    "Retrospective first-correct-exit oracle": "retrospective_oracle_first_correct",
}


def main() -> None:
    report = json.loads(REPORT.read_text(encoding="utf-8"))
    paper = PAPER.read_text(encoding="utf-8")
    methods = {item["method"]: item for item in report["methods"]}
    assert set(methods) == set(EXPECTED.values()), "RUN8 method set changed"
    assert report["identity"]["core_sha256"] == "a6b2807bd4a60534c250fca3005322cf14ba0a92f6b16e28241109385efc6809"
    assert report["identity"]["weights_header_sha256"] == "961a76b7e220bf2f665e7c04ab62063600aa2e7eccf3403d80ea730bc993ad9f"
    assert report["source"]["test_count"] == 360
    assert report["source"]["validation_count"] == 359
    assert report["calibration"]["threshold_selection"].find("no heldout labels") >= 0
    assert methods["max_softmax_q15"]["tuned_on"] == "validation_only"
    assert methods["top2_probability_margin_q15"]["tuned_on"] == "validation_only"

    section = paper.split("### 4.2 Frozen-Q15 offline stopping comparison", 1)[1]
    section = section.split("### 4.3 Dynamic-input FPGA pilot", 1)[0]
    rows: dict[str, list[str]] = {}
    for line in section.splitlines():
        if not line.startswith("| "):
            continue
        cells = [part.strip() for part in line.strip("|").split("|")]
        if len(cells) == 5 and cells[0] in EXPECTED:
            assert cells[0] not in rows, f"duplicate table row: {cells[0]}"
            rows[cells[0]] = cells

    assert set(rows) == set(EXPECTED), "paper table method rows differ from expected"
    for label, method_name in EXPECTED.items():
        item = methods[method_name]["heldout360"]
        cells = rows[label]
        assert int(cells[1]) == item["correct"], f"correct count differs: {label}"
        assert math.isclose(
            float(cells[2].removesuffix("%")),
            100 * item["accuracy"],
            abs_tol=0.006,
        ), f"accuracy differs: {label}"
        assert math.isclose(
            float(cells[3]), item["mean_optional_blocks"], abs_tol=0.001
        ), f"optional-block count differs: {label}"
        if method_name == "retrospective_oracle_first_correct":
            assert cells[4] == "Not applicable"
        else:
            assert math.isclose(
                float(cells[4]), item["mean_decision_checks"], abs_tol=0.001
            ), f"decision-check count differs: {label}"

    assert PLOT.is_file(), "missing saved Pareto plot"
    plot = PLOT.read_text(encoding="utf-8")
    assert "optional block" in plot.lower()
    assert "Previously held-out sklearn split" in plot
    assert "does not estimate FPGA cycles or UCI external performance" in plot
    assert "![Exploratory heldout accuracy versus mean optional blocks" in paper
    assert "not a cycle, latency, energy, or FPGA Pareto result" in paper
    assert "uses the true label and is not implementable" in paper
    print("PASS: manuscript table 11/11 rows match RUN8; Pareto plot and scope labels verified")


if __name__ == "__main__":
    main()
