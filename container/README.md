# CPU container reproduction

The main-line PyTorch experiments can be reproduced without host Python dependencies by building the experiment-specific CPU images from the repository root.

| Dockerfile | Purpose | Default output |
|---|---|---|
| `container/Dockerfile.cpu` | continuous-budget nested/free ordering audit | `results/realtime_nn_continuous_budget_ordering_results.json` |
| `container/Dockerfile.joint_budget.cpu` | joint all-execution-class training audit | `results/realtime_nn_joint_budget_training_results.json` |
| `container/Dockerfile.robustness.cpu` | incremental-refinement negative control + minibatch-order robustness | two corresponding result JSON files |
| `container/Dockerfile.sequence_nested.cpu` | sequence nested non-prefix routing + coarse/fine budget-as-cap audits | three sequence result JSON files |
| `container/Dockerfile.sequence_stop.cpu` | direct/online preferred-compute training audit against the post-trained sequence baseline | `results/realtime_nn_sequence_stop_training_audit_results_raw.json` |

Example:

```bash
docker build -f container/Dockerfile.sequence_nested.cpu -t rtnn-sequence-cap .
docker run --rm -v "$PWD/results:/workspace/results" rtnn-sequence-cap
```

For the stopping-policy audit:

```bash
docker build -f container/Dockerfile.sequence_stop.cpu -t rtnn-sequence-stop .
docker run --rm -v "$PWD/results:/workspace/results" rtnn-sequence-stop
```

Environment variables allow shorter smoke runs. For the sequence images, use for example `SEEDS=1 STEPS=40`; the cap-policy image also accepts `POLICY_STEPS`. The robustness image supports controls such as `INC_SEEDS`, `MODEL_SEEDS`, and `BATCH_SEEDS`.

These containers reproduce Linux/PyTorch functional experiments. They do **not** constitute an RTOS, WCET, or hard-real-time environment.
