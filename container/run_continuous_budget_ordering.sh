#!/bin/sh
set -eu
python experiments/realtime_nn_continuous_budget_ordering.py \
  --seeds "${SEEDS:-3}" \
  --steps "${STEPS:-800}" \
  --timing-reps "${TIMING_REPS:-5}" \
  --out results/realtime_nn_continuous_budget_ordering_results.json
