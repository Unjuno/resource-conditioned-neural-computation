from __future__ import annotations
import random

def paired_ni_lower(fixed_correct, adaptive_correct, alpha_each=0.025):
    """Bonferroni exact bound for p(adapt correct/fixed wrong)-p(reverse)."""
    if len(fixed_correct)!=len(adaptive_correct) or not fixed_correct:
        raise ValueError('paired nonempty vectors required')
    if any(x not in (0,1) for x in fixed_correct+adaptive_correct): raise ValueError('correctness must be binary')
    try:
        from scipy.stats import beta
    except ImportError as e:
        raise RuntimeError('SciPy required for exact Clopper-Pearson interval') from e
    n=len(fixed_correct); p10=p01=0
    for f,a in zip(fixed_correct,adaptive_correct):
        if f not in (0,1) or a not in (0,1): raise ValueError('correctness must be binary')
        p10 += int(a==1 and f==0); p01 += int(a==0 and f==1)
    low=0.0 if p10==0 else float(beta.ppf(alpha_each,p10,n-p10+1))
    high=1.0 if p01==n else float(beta.ppf(1-alpha_each,p01+1,n-p01))
    return {'n':n,'adaptive_only_correct':p10,'fixed_only_correct':p01,
            'lower_p10':low,'upper_p01':high,'lower_difference':low-high,
            'margin':-0.01,'numeric_pass':low-high>-0.01,'alpha_each':alpha_each}

def paired_cycle_bootstrap(fixed_cycles, adaptive_cycles, draws=10000, seed=20261122):
    if len(fixed_cycles)!=len(adaptive_cycles) or not fixed_cycles: raise ValueError('paired nonempty vectors required')
    if any(f<=0 or a<=0 for f,a in zip(fixed_cycles,adaptive_cycles)): raise ValueError('cycles must be positive')
    n=len(fixed_cycles); R=(sum(fixed_cycles)-sum(adaptive_cycles))/sum(fixed_cycles)
    rng=random.Random(seed); vals=[]
    for _ in range(draws):
        ix=[rng.randrange(n) for _ in range(n)]
        den=sum(fixed_cycles[i] for i in ix)
        vals.append((den-sum(adaptive_cycles[i] for i in ix))/den)
    vals.sort()
    lo=vals[int(0.025*(draws-1))]; hi=vals[int(0.975*(draws-1))]
    return {'n_images':n,'draws':draws,'seed':seed,'fixed_mean':sum(fixed_cycles)/n,
            'adaptive_mean':sum(adaptive_cycles)/n,'mean_cycle_saving':sum(fixed_cycles)/n-sum(adaptive_cycles)/n,
            'median_cycle_saving':sorted([f-a for f,a in zip(fixed_cycles,adaptive_cycles)])[n//2],
            'ratio_of_sums':R,'input_bootstrap_95_percentile':[lo,hi],
            'numeric_pass':R>=0.05 and lo>0.05}
