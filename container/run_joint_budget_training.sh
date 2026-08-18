#!/bin/sh
set -eu
python experiments/realtime_nn_joint_budget_training.py \
  --seeds "${SEEDS:-3}" \
  --steps "${STEPS:-800}" \
  --out results/realtime_nn_joint_budget_training_results.json
