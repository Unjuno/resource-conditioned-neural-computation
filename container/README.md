# CPU container reproduction

The main-line PyTorch experiments can be reproduced without host Python dependencies by building the experiment-specific CPU images from the repository root.

| Dockerfile | Purpose | Default output |
|---|---|---|
| `container/Dockerfile.cpu` | continuous-budget nested/free ordering audit | `results/realtime_nn_continuous_budget_ordering_results.json` |
| `container/Dockerfile.joint_budget.cpu` | joint all-execution-class training audit | `results/realtime_nn_joint_budget_training_results.json` |
| `container/Dockerfile.robustness.cpu` | incremental-refinement negative control + minibatch-order robustness | two corresponding result JSON files |

Example:

```bash
docker build -f container/Dockerfile.robustness.cpu -t rtnn-robustness .
docker run --rm -v "$PWD/results:/workspace/results" rtnn-robustness
```

Environment variables allow shorter smoke runs, for example `INC_SEEDS=2`, `STEPS=200`, or a smaller `MODEL_SEEDS`/`BATCH_SEEDS` grid.

These containers reproduce Linux/PyTorch functional experiments. They do **not** constitute an RTOS, WCET, or hard-real-time environment.
