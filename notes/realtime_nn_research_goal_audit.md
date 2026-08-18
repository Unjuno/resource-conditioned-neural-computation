# RTNN research-goal audit: generalization, continuous freestanding contract, and timing boundary

## Goal status

| Goal | Decision | Evidence |
|---|---|---|
| A. Budget changes physical computation of one fixed NN | PASS | existing depth/width/expert/sequence audits |
| B. Generalizable adaptive computation on unseen real samples | PASS with boundary | 5/5 formal seeds on held-out real digit row-sequences; chronological CO2 shift remains FAIL |
| C1. Continuous `b in [0,1]` -> finite freestanding max-work envelope | PASS | exhaustive Q0.16 property audit + freestanding build |
| C2. Maximum-work manifest and build-bound deadline contract | PASS | manifest + identity checks + partial-certification properties |
| C3. Defensible hard timing/WCET on concrete target | UNCERTAIN | unavailable in current environment; Linux empirical maxima fail held-out stability |
| C4. Deadline-admission demonstrator | PASS as interface/empirical demo | explicit bounds compose with budget/preferred class; not a hard-RT proof |

## Real independent-test generalization

A real sequence experiment uses `sklearn.datasets.load_digits` as 8 row tokens. The model has six optional self-attention/MLP blocks and one exit at every depth. Train/validation/test are fixed stratified 60/20/20 splits. Validation chooses the maximum useful depth, then an entropy threshold may stop earlier. Test labels are not used to tune the policy.

Formal seeds 60--64:

- 0% exit accuracy: 49.61%
- best exact-depth mean: 93.56%
- validation-selected-depth test accuracy: 93.44%
- adaptive policy test accuracy: **93.56%**
- adaptive mean physical compute: **20.23%**
- capability gain from 0% to useful compute: **+43.83 pp**
- cap/count violations: 0
- physical hard-cap audit: PASS
- passing seeds: 5/5

Decision: **PASS** for independent held-out real-sequence generalization.

### Temporal distribution-shift boundary

On chronological weekly atmospheric CO2 forecasting/classification, a validation-tuned entropy stopping policy achieved 69.08% mean test accuracy versus 70.11% full-depth, with 6.29% mean compute. The -1.03 pp gap narrowly misses the preregistered -1 pp boundary and only 3/5 seeds pass. Depth utility also shifts between validation and later test periods.

Decision: **FAIL / unresolved temporal nonstationarity**. This is not folded into the independent-sample PASS.

## Continuous freestanding contract

External normalized budget is encoded as unsigned Q0.16. The existing 0/2/4/6/8-block freestanding core is exposed as 0%, 25%, 50%, 75%, and 100% maximum-work classes.

The runtime computes:

```text
budget_class = largest finite fraction <= b
policy_class = min(budget_class, preferred_max_class)
deadline_class = highest explicitly certified class fitting remaining deadline
effective_class = min(policy_class, deadline_class)
```

Invalid preferred classes fail closed to class 0.

Exhaustive/property audit:

- all 65,536 Q0.16 budget values
- 16,777,216 budget x uint8 preferred-class combinations
- 655,360 deadline/budget/preferred composition cases
- all properties PASS
- undefined external symbols in freestanding contract object: 0
- contract stack use: 8 bytes/function in this GCC build

The regenerated neural core exactly reproduces Python seed-0 finite-domain accuracies 63.67%, 71.48%, 78.52%, 86.33%, 100%, and invalid class 255 exactly matches class 0.

## Maximum-work manifest

The manifest records normalized fraction/Q16 value, maximum blocks, exact maximum linear MACs, activation-LUT calls, residual operations, linear outputs, workspace bytes, and allowed canonical nested block IDs. Timing bounds are deliberately absent from the target-independent manifest.

## Controlled target timing result

The exact neural object was pinned to one available Linux CPU per run and timed with `RDTSCP`. Median cycles scale approximately with physical work, but observed maxima are dominated by scheduler/preemption events. Across three runs, maximum cycles are not even class-monotone; examples include about 17.7M cycles for class 3 in one run and about 16.7M for class 4 in another.

A separate calibration/held-out experiment showed that an observed calibration maximum can be exceeded later. Multiplying the empirical envelope by 2x or even 4x did not eliminate all held-out exceedances across runs.

Therefore:

> **measurement maximum x arbitrary safety factor is not promoted to a certified hard timing bound.**

The environment has no WCET analysis tool or bare-metal target timing model, and `SCHED_FIFO` is not permitted. Thus the hard timing portion of Goal C is **UNCERTAIN**, not PASS.

## Deadline admission

The interface itself remains valid: explicit per-class bounds are identity-bound to manifest and deployed build; uncertified classes are never inferred from neighboring classes or work counts. The combined continuous-budget/preferred/deadline property tests pass. An empirical timing table can drive a demonstrator, but it is labeled empirical only.

## Next hard-real-time requirement

To move C3 from UNCERTAIN to PASS, run the same finite-class binary on a concrete time-predictable target or with a defensible WCET/static timing analyzer under fixed compiler, memory/cache, interrupt, DMA, and scheduling assumptions. No additional Linux percentile or observed-maximum experiment can substitute for that evidence.
