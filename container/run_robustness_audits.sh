#!/bin/sh
set -eu
python experiments/realtime_nn_incremental_refinement.py \
  --seeds "${INC_SEEDS:-10}" --steps "${STEPS:-800}" \
  --out results/realtime_nn_incremental_refinement_results.json
python experiments/realtime_nn_batch_order_robustness.py \
  --model-seeds "${MODEL_SEEDS:-0,1,2}" \
  --batch-seeds "${BATCH_SEEDS:-100,101,102}" \
  --steps "${STEPS:-800}" \
  --out results/realtime_nn_batch_order_robustness_results.json
