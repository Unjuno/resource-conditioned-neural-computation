#!/usr/bin/env python3
"""Exact image-independent sensitivity for the preregistered paired NI rule.

This is design sensitivity only. Scenario probabilities are assumptions, not
estimated from the new dataset or any RTNN prediction output.
"""
import argparse
import csv
import json
from pathlib import Path

import numpy as np
from scipy.stats import beta, binom

SCENARIOS = [
    ("equal_discordance_0p5pct", 0.005, 0.005),
    ("equal_discordance_1pct", 0.010, 0.010),
    ("adaptive_better_0p5pp", 0.010, 0.005),
    ("adaptive_worse_0p5pp", 0.005, 0.010),
    ("boundary_adaptive_worse_1pp", 0.010, 0.020),
    ("adaptive_worse_1p5pp", 0.005, 0.020),
]


def exact_power(n: int, p10: float, p01: float, margin: float = 0.01,
               alpha_each: float = 0.025) -> float:
    if n < 1 or p10 < 0 or p01 < 0 or p10 + p01 > 1:
        raise ValueError("invalid n or discordance probabilities")
    x = np.arange(n + 1)
    lower10 = np.zeros(n + 1, dtype=float)
    mask = x > 0
    lower10[mask] = beta.ppf(alpha_each, x[mask], n - x[mask] + 1)
    y = np.arange(n + 1)
    upper01 = np.ones(n + 1, dtype=float)
    mask_y = y < n
    upper01[mask_y] = beta.ppf(1 - alpha_each, y[mask_y] + 1, n - y[mask_y])
    # The registered numerical rule is strict: lower(p10)-upper(p01)>-margin.
    max_y = np.searchsorted(upper01, lower10 + margin, side="left") - 1
    px = binom.pmf(x, n, p10)
    conditional_p01 = p01 / (1 - p10) if p10 < 1 else 0.0
    conditional = np.zeros(n + 1, dtype=float)
    valid = max_y >= 0
    remaining = n - x[valid]
    conditional[valid] = binom.cdf(np.minimum(max_y[valid], remaining), remaining,
                                   conditional_p01)
    return float(np.dot(px, conditional))


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--n", type=int, default=3813)
    parser.add_argument("--csv", type=Path, required=True)
    parser.add_argument("--json", type=Path, required=True)
    args = parser.parse_args()
    if args.csv.exists() or args.json.exists():
        raise SystemExit("refusing to overwrite planning outputs")
    rows = []
    for name, p10, p01 in SCENARIOS:
        rows.append({"scenario": name, "n_independent_images": args.n,
                     "assumed_p10_adaptive_only_correct": p10,
                     "assumed_p01_fixed_only_correct": p01,
                     "assumed_delta_percentage_points": 100 * (p10 - p01),
                     "exact_numeric_gate_pass_probability": exact_power(args.n, p10, p01),
                     "alpha_per_bound": 0.025, "noninferiority_margin_percentage_points": -1.0})
    args.csv.parent.mkdir(parents=True, exist_ok=True)
    with args.csv.open("w", newline="", encoding="utf-8") as f:
        writer = csv.DictWriter(f, fieldnames=list(rows[0]))
        writer.writeheader(); writer.writerows(rows)
    payload = {"schema": "rtnn-external-ni-design-sensitivity-v1",
               "classification": "PLANNING_ONLY_NOT_OBSERVED_DATA",
               "method": "Exact multinomial enumeration via X~Binomial(n,p10), Y|X~Binomial(n-X,p01/(1-p10)); paired Bonferroni Clopper-Pearson numerical gate.",
               "assumptions": ["image pairs are independent", "discordance probabilities are fixed scenario inputs", "power is not a guarantee and does not resolve unknown writer clustering", "no RTNN outcome data were read"],
               "n": args.n, "scenarios": rows}
    args.json.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")
    print(f"DESIGN_SENSITIVITY_WRITTEN_NOT_OBSERVED n={args.n} scenarios={len(rows)}")


if __name__ == "__main__":
    main()
