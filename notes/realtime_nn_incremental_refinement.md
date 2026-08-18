# Incremental output-refinement audit

## Question

After joint all-execution-class training largely removed the utility regression of nested physical execution, does changing the output composition from shared hidden-state accumulation to additive per-expert logit corrections remove the remaining rare high-budget regressions?

This is a **comparative falsification test**. It is not enough for the additive model to look good in isolation; it must improve on the matched shared-state baseline.

## Controlled setup

Both policies use the same 8-slot task, 8 physical experts, beta-independent learned ranking, nested top-k execution, and joint task-loss training across all 8 execution classes on every optimizer update.

- `shared`: selected expert hidden vectors are summed and passed through one shared classifier head.
- `additive`: every selected expert emits a two-logit correction; selected corrections are summed directly into the output.

At inference, class `k` physically calls exactly `k` selected experts. Forward hooks audit this property. The ranking is independent of budget, so the selected set at class `k` must be a subset of class `k+1`.

## H / T / D / C / U

**H:** additive logit-evidence refinement reduces residual high-budget utility regression relative to the matched shared-state baseline without materially reducing intermediate quality.

**T:** 10 model seeds, 800 optimizer updates, batch 256, all 8 execution classes included in every update. Test domain: 2,000 fixed examples. Physical hard-cap hooks and nested-set audits are run for each seed.

**D:** PASS requires the additive model to have (1) more strict-monotonic seeds than shared, (2) lower mean maximum adjacent accuracy drop, (3) `k=4` mean accuracy no more than 1 percentage point below shared, (4) zero nestedness violations, and (5) all hard-cap hook checks passing.

**C:** if additive is no better or worse, the remaining regression is not solved merely by moving addition from hidden space to logit space; joint training is the more important intervention.

**U:** finite synthetic task, 10 seeds, one optimizer/hyperparameter setting, 0.05 percentage-point test-set resolution, CPU/PyTorch backend. No timing/WCET conclusion is drawn.

## Result

| metric | shared | additive |
|---|---:|---:|
| strict monotonic seeds | **9/10** | **9/10** |
| mean max adjacent drop | **0.0050 pp** | 0.0100 pp |
| worst observed adjacent drop | **0.0500 pp** | 0.1000 pp |
| mean accuracy at `k=4` | 100% | 100% |
| mean accuracy at `k=8` | 99.995% | 99.990% |
| nested violations | 0 | 0 |
| hard-cap audit | PASS | PASS |

**Decision: FAIL.**

The additive parameterization does not outperform the shared-state baseline. In fact its mean and worst residual regression are slightly larger. The practical conclusion is therefore negative: **do not add this mechanism to the RTNN design merely to obtain utility monotonicity.**

An earlier absolute-threshold decision rule would have labelled additive as PASS because 9/10 seeds were monotonic and the mean drop was small. That rule was inadequate for a comparative hypothesis. The stored result uses the corrected comparative criterion.

## Interpretation

The dominant intervention remains joint all-class training. Once every execution class is trained on every update, both output parameterizations are nearly monotonic. The extra additive architecture is not justified by this evidence.

## Environment

Recorded run: x86-64 Linux container, AMD EPYC 7763 virtual CPU, Python 3.13.5, PyTorch 2.10.0+cpu, one PyTorch intra-op thread. Docker is a reproduction wrapper, not the measured target. No WCET or hard-real-time claim.
