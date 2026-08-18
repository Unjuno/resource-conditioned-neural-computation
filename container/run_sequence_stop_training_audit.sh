#!/bin/sh
set -eu
SEEDS=${SEEDS:-5}
STEPS=${STEPS:-400}
python experiments/realtime_nn_sequence_stop_training_audit.py \
  --seeds "$SEEDS" \
  --steps "$STEPS" \
  --baseline results/realtime_nn_sequence_cap_preference_results.json \
  --out results/realtime_nn_sequence_stop_training_audit_results_raw.json
