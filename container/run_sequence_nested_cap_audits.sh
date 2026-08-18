#!/bin/sh
set -eu
SEEDS="${SEEDS:-5}"
STEPS="${STEPS:-400}"
POLICY_STEPS="${POLICY_STEPS:-1200}"
python experiments/realtime_nn_sequence_nested_routing.py --seeds "$SEEDS" --steps "$STEPS" --out results/realtime_nn_sequence_nested_routing_results.json
python experiments/realtime_nn_sequence_cap_preference.py --classes coarse --seeds "$SEEDS" --steps "$STEPS" --policy-steps "$POLICY_STEPS" --out results/realtime_nn_sequence_cap_preference_coarse_results.json
python experiments/realtime_nn_sequence_cap_preference.py --classes fine --seeds "$SEEDS" --steps "$STEPS" --policy-steps "$POLICY_STEPS" --out results/realtime_nn_sequence_cap_preference_fine_results.json
