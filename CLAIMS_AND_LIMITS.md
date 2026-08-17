# Claims and limits

## Strongest supported mechanism statement

> In supplied toy architectures, one fixed neural network can receive a runtime-admitted work budget, physically execute only budget-compliant internal computation, and produce a reproducible quality/work/median-latency trade-off. Useful admissible computation can be selected by a learned controller, including a tested case trained from task loss alone.

This is **not** a hard-real-time/WCET claim.

## Supported direct evidence

### Physical budget execution

Across three seeds:

- one fixed NN physically executes `0/2/4/6/8` optional blocks as budget increases;
- hooks verify inactive blocks are not called;
- mean accuracy increases **63.67% → 100%**;
- hard-skip median latency increases **10.53 us → 375.82 us** and is strictly monotonic in 3/3 seeds;
- dense logical masking executes all blocks and does not obtain the speedup.

### Learned selection under a hard work cap

The runtime admits `k ∈ {1,2,4,8}` expert calls. Hard top-k structurally prevents budget violation.

At `k=4`, the explicitly supervised learned controller reaches **100%** accuracy versus **78.18%** for fixed prefix. Controller overhead is included in timing.

With empirical P95 deadline admission, an intermediate `k≈4` regime gives learned on-time-correct **98.46%** versus **76.00%** for prefix at similar miss rates.

Learned control is not universally better: tight/full-budget regimes can favor simpler policies, and an external analytic relevance oracle remains a strong baseline.

### Task-loss-only selection

A second learned controller removes relevance labels, relevance auxiliary loss, capability warmup, and expert freezing.

Three-seed mean result:

| k | task-loss learned | fixed prefix | analytic oracle | useful-selection fraction |
|---:|---:|---:|---:|---:|
| 1 | 69.04% | 67.66% | 69.09% | 100% |
| 2 | **81.27%** | 71.37% | 81.80% | 100% |
| 4 | **100.00%** | 78.74% | 100.00% | 100% |
| 8 | 99.82% | 99.82% | 99.82% | 50% |

Learned hard-skip median latency is strictly monotonic in 3/3 seeds and hard work-cap compliance passes in 3/3 seeds.

This supports task-loss-only useful-computation selection **inside a supplied fixed search space**. It does not establish unconstrained self-organized architecture discovery.

## Runtime machine-state timing boundary

The hypothesis

```text
coarse machine state → one empirical P95 timing table → admitted budget
```

is **not supported on ordinary Linux** by the newest audit.

Two model seeds were repeatedly calibrated under idle, periodic same-core load, and continuous same-core busy load. Budgets were randomly interleaved; each state was measured six times.

Maximum repeated empirical-P95 coefficient of variation:

- idle: **0.321**;
- periodic load: **0.092**;
- continuous same-core busy load: **0.990**.

Under the same continuous-busy state:

- seed 0, `B=.5` P95 ranges **551 us → 4.30 ms**;
- seed 1, `B=.25` ranges **233 us → 4.16 ms**;
- seed 1, `B=.5` ranges **561 us → 4.29 ms**.

A larger continuous-busy probe shows the cause is a scheduler/preemption mixture:

| budget | median | P95 | fraction >4 ms |
|---:|---:|---:|---:|
| .25 | 103 us | 381 us | 3.00% |
| .50 | 189 us | **8.38 ms** | **6.94%** |
| .75 | 279 us | 8.49 ms | 9.22% |
| 1.00 | 378 us | 8.63 ms | 11.72% |

When preemption probability crosses the 5% boundary, empirical P95 jumps from the fast mode into the preempted mode. Therefore a categorical state-aware P95 table can be discontinuous and run-to-run unstable even though the NN execution class is unchanged.

The initial exploratory result suggesting that load-specific P95 recalibration reliably rescued deadline misses was contradicted by an independent repeat and is **not promoted**.

## Timing interpretation

Lower neural budgets still shorten nominal execution and can reduce the observed exposure window for scheduler interference. But the NN cannot solve uncontrolled scheduling interference by itself.

Hard-real-time deployment requires a controlled timing substrate and defensible assumptions, for example:

- RTOS scheduling isolation / CPU reservation;
- bounded-priority interference analysis;
- statically analyzable generated inference code;
- time-predictable hardware/runtime;
- formal/static WCET or an accepted probabilistic real-time model with explicit assumptions.

Empirical Linux P95/P99 is not WCET.

## Current open questions

1. Under a controlled RTOS/time-predictable scheduler, can deadline + bounded interference be mapped to a safe admitted NN work budget?
2. Can useful internal computation be made less analytically exposed than the current key/query toy?
3. Can structured finer-grained physical activation preserve predictable execution classes?
4. Later, does the same systems principle transfer to sequence models without making scale itself the objective?

## Secondary diagnostics

Older router/topology experiments remain useful for capability forgetting, shortcut collapse, feasibility-vs-price separation, non-separable resource-contract failures, optimization sensitivity, and timing-tail instability. They are secondary to:

```text
budget → physical activation → work → latency → deadline
```

## Explicitly not claimed

1. Hard real-time guarantees or WCET bounds.
2. A production Real-Time NN or Real-Time LM.
3. Stable machine-state→P95 admission on ordinary Linux.
4. Joule-level energy savings or measured memory-bandwidth reduction.
5. Universal learned-policy superiority over fixed policies or external schedulers.
6. Necessity of a learned controller when useful-computation information is analytically available.
7. General/unconstrained self-organized architecture discovery.
8. Arbitrary hardware portability.
9. LLM-scale generalization.
10. Novelty of LUT neurons/networks, dynamic routing, NAS, or runtime subnetwork switching.

## Direction lock

Before promoting a new main-line experiment, ask:

> Does it test the physical chain `budget → activation → work → latency → deadline`, or a concrete runtime condition required to make that chain real-time safe?

If not, it belongs under secondary diagnostics.
