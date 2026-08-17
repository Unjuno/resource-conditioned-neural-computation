# Execution-class granularity audit for the direct Real-Time NN

## Question

Can a runtime add finer admitted compute classes to the same conditional network after training, or must every class that may be used at runtime be capability-trained in advance?

This audit stays on the direct 9-bit-majority Real-Time NN. The network has one shared parameter set, eight optional local-information-propagation blocks, and one shared classifier head. A class at depth `d` physically executes exactly the first `d` optional blocks.

## Post-hoc class insertion fails

The original direct model was trained only at depths `0 / 2 / 4 / 6 / 8`. Evaluating the same frozen weights at untrained intermediate depths produces severe failures across three seeds.

Mean full-domain accuracy over three seeds:

| depth | trained class? | mean accuracy |
|---:|:---:|---:|
| 0 | yes | 63.67% |
| 1 | no | 54.56% |
| 2 | yes | 71.48% |
| 3 | no | 53.26% |
| 4 | yes | 78.52% |
| 5 | no | 43.23% |
| 6 | yes | 86.33% |
| 7 | no | 34.11% |
| 8 | yes | 100.00% |

Thus an execution class is not automatically valid merely because its work count lies between two trained classes. Runtime-admissible conditional circuits need capability coverage.

## Training all classes restores capability

A second model uses the same architecture but includes all depths `0..8` in the joint task objective from the start. Across three seeds, every class reaches the Bayes-optimal accuracy permitted by its receptive field:

| depth | mean accuracy | mean median latency |
|---:|---:|---:|
| 0 | 63.67% | 11.72 us |
| 1 | 63.67% | 57.63 us |
| 2 | 71.48% | 102.97 us |
| 3 | 71.48% | 146.23 us |
| 4 | 78.52% | 189.77 us |
| 5 | 78.52% | 237.90 us |
| 6 | 86.33% | 284.47 us |
| 7 | 86.33% | 332.68 us |
| 8 | 100.00% | 374.22 us |

For all three seeds:

- accuracy is non-decreasing with admitted depth;
- median latency is strictly increasing with executed depth;
- every class is within one percentage point of the theoretical Bayes optimum for the information visible at that depth.

## Pareto consequence

More execution classes are not automatically useful. On this task, depths `1 / 3 / 5 / 7` have the same accuracy as `0 / 2 / 4 / 6` respectively but higher latency. They are therefore dominated on the measured quality-latency frontier.

The runtime interface should expose **validated Pareto-useful execution classes**, not every syntactically possible activation level.

This suggests a systems rule:

> a Real-Time NN execution class is part of the deployable contract only after both capability and timing have been validated for that class.

## Timing boundary

The medians are stable enough to establish central ordering in this toy. P95/P99 remain contaminated by ordinary Linux scheduling/interference and are not treated as WCET or hard-real-time evidence.

## Supported conclusion

The direct Real-Time NN can support finer physical compute classes if those classes are included in capability training. Post-hoc intermediate activation states can be invalid even when neighboring execution classes work. Runtime class granularity is therefore a co-design variable between training and scheduling, not just a runtime knob.
