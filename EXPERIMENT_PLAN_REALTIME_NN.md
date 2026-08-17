# Experiment plan: direct Real-Time NN mechanism

## Objective

Test the intended mechanism directly:

> With one fixed neural network and the same task input, changing only an admitted compute/time/resource budget changes which internal computation is physically executed, and this changes measured inference latency in a predictable direction.

The experiment is not primarily a router benchmark. Any gate/router is only an implementation mechanism.

## Phase 1 — Budget-conditioned block execution

Build one small fixed-parameter network with a sequence of optional compute blocks.

A budget input `B` conditions binary block gates:

```text
input x
  ↓
shared stem
  ↓
block 1 ─ gate g1(B, x)
block 2 ─ gate g2(B, x)
...
block K ─ gate gK(B, x)
  ↓
shared head
```

The implementation must use control flow so `gk = 0` skips the block entirely.

### Required measurements per inference

- budget `B`;
- fixed input ID;
- active block mask;
- execution-hook trace;
- executed block count;
- executed MAC/operation proxy;
- end-to-end latency;
- output / task score.

### Counterfactual test

For every held-out input `x`, run the same frozen model at multiple budgets:

`B_low < B_mid < B_high`.

Primary acceptance criteria:

1. activation pattern changes with budget for a substantial fraction of inputs;
2. inactive blocks are not executed;
3. executed work is ordered or at least calibratable by budget;
4. median latency is ordered in the same direction;
5. the latency distributions are sufficiently separated to define useful execution classes;
6. task quality does not collapse at the smallest useful budget.

A useful first target is:

```text
B_low  → fewest executed blocks → lowest latency
B_mid  → intermediate blocks    → intermediate latency
B_high → most executed blocks   → highest latency
```

This is a mechanism target, not a hard-real-time guarantee.

## Phase 2 — Finer activation granularity

Only after Phase 1 works, test whether the same principle survives finer-grained conditional execution:

- groups of channels;
- expert/module groups;
- structured neuron groups;
- residual sub-blocks.

Do not use unstructured zero masks that leave the dense kernel unchanged. The inactive structure must correspond to skipped physical work.

Compare:

- block-level control overhead;
- group/channel-level control overhead;
- achieved compute reduction;
- measured latency reduction;
- timing variance.

The aim is to find an activation granularity that is both useful for quality and predictable enough for runtime timing classes.

## Phase 3 — Deadline-to-budget runtime

Once budget → work → latency is calibrated, add a minimal runtime layer:

```text
deadline D
current machine state S
calibrated timing table/model
        ↓
admitted budget B
        ↓
same NN
```

For each request, record:

- deadline;
- admitted budget;
- selected activation trace;
- predicted latency;
- actual latency;
- deadline hit/miss;
- task quality.

Compare against:

1. always-small fixed network/execution level;
2. always-large fixed level;
3. external fixed execution-class scheduler;
4. budget-conditioned same-network execution.

The comparison should separate:

- quality at matched miss rate;
- miss rate at matched quality;
- runtime overhead;
- timing predictability.

## Phase 4 — Timing guarantee boundary

Ordinary Linux/PyTorch measurements are suitable only for mechanism and soft/probabilistic timing studies.

A later hard-real-time experiment requires one of:

- statically analyzable generated code;
- a time-predictable embedded target;
- controlled RTOS scheduling and interference model;
- formal/static WCET or an accepted equivalent.

Do not infer WCET from median/P95/P99 Linux measurements.

## Baselines

The minimum baseline set is:

- fixed smallest execution level;
- fixed largest execution level;
- external scheduler choosing among the same execution classes;
- same-network budget-conditioned execution;
- budget-blind matched control if a learned gate is used.

Router architecture comparisons are optional and secondary. They are justified only if the gate/controller overhead or stability materially changes actual latency/deadline performance.

## Primary plots / tables

The main paper-quality figures should be systems figures, not router-oracle figures:

1. **budget vs active compute**;
2. **budget vs measured latency distribution**;
3. **active compute vs latency**;
4. **budget vs quality**;
5. **deadline vs miss rate / quality**;
6. same-input activation traces at low/mid/high budget.

## Falsification criteria

The Real-Time NN interpretation is weakened or falsified if:

- budget changes masks but not actual executed work;
- work changes but wall-clock latency does not improve because control overhead dominates;
- latency classes overlap so strongly that runtime admission is not useful;
- only separate prebuilt models, rather than one parameterized network, can achieve the trade-off;
- an external scheduler over identical internal execution classes is strictly simpler with no loss and the neural conditioning adds no functional value;
- budget-conditioned execution destroys task capability at useful low-latency levels.

Negative results should be retained.

## Direction rule

Do not expand router/NAS experiments unless they answer a concrete failure discovered in this direct budget/activation/latency chain.
