#!/bin/sh
set -eu
SEEDS="${SEEDS:-5}"
STEPS="${STEPS:-400}"
PRED_STEPS="${PRED_STEPS:-250}"
POST_STEPS="${POST_STEPS:-1200}"
mkdir -p results
python experiments/realtime_nn_continuous_horizon_value.py \
  --seeds "$SEEDS" --steps "$STEPS" --pred-steps "$PRED_STEPS" --post-steps "$POST_STEPS" \
  --out results/realtime_nn_continuous_horizon_value_results.json
