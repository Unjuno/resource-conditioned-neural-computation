"""Audit direct preferred-compute training against the post-trained cap-policy baseline.

This experiment keeps the same causal sequence task, nested block ranking, and finite
caps as realtime_nn_sequence_cap_preference.py. It tests whether the stopping policy
can be trained concurrently with capability learning without losing the frontier.
Training-time sparse execution is not claimed: all exact-class losses are evaluated.
"""
import argparse, json, random, statistics
from pathlib import Path
import torch
import torch.nn as nn
import torch.nn.functional as F
import realtime_nn_sequence_nested_routing as s

KS=[0,2,4,6]
s.KS=KS[:]

class StopNet(nn.Module):
    def __init__(self):
        super().__init__(); self.net=nn.Sequential(nn.Linear(s.PROMPT,24),nn.Tanh(),nn.Linear(24,len(KS)))
    def forward(self,prompt): return self.net(prompt.float())

def per_sample_ce(z):
    return F.cross_entropy(z[:,s.POS].reshape(-1,2),s.SEQ[:,s.POS+1].reshape(-1),reduction='none').view(len(s.PROMPTS),s.OUT).mean(1)

def costs(model,tau):
    Z=model.forward_joint(s.SEQ,s.PROMPTS,tau)
    return torch.stack([per_sample_ce(Z[i]) for i in range(len(KS))],1)

def cap_probs(pref,ci):
    q=torch.zeros_like(pref)
    if ci: q[:,:ci]=pref[:,:ci]
    q[:,ci]=pref[:,ci:].sum(1)
    return q

def train(seed,method,steps=400):
    torch.manual_seed(seed); random.seed(seed); model=s.Net('input'); policy=StopNet()
    if method in ('st','soft'):
        opt=torch.optim.AdamW(list(model.parameters())+list(policy.parameters()),lr=2e-3,weight_decay=1e-5)
        for st in range(steps):
            f=st/max(1,steps-1); tau=max(.3,1-.7*f); temp=1.0*(1-f)+.25*f; c=costs(model,tau)
            prob=torch.softmax(policy(s.PROMPTS)/temp,1)
            if method=='st':
                hard=F.one_hot(prob.argmax(1),num_classes=len(KS)).float(); pref=hard+(prob-prob.detach())
            else: pref=prob
            loss=torch.stack([(cap_probs(pref,ci)*c).sum(1).mean() for ci in range(len(KS))]).mean()
            opt.zero_grad(); loss.backward(); torch.nn.utils.clip_grad_norm_(list(model.parameters())+list(policy.parameters()),5); opt.step()
    elif method=='decoupled':
        om=torch.optim.AdamW(model.parameters(),lr=2e-3,weight_decay=1e-5); op=torch.optim.AdamW(policy.parameters(),lr=1e-2,weight_decay=1e-5)
        for st in range(steps):
            f=st/max(1,steps-1); tau=max(.3,1-.7*f); c=costs(model,tau); lm=c.mean(); om.zero_grad(); lm.backward(); torch.nn.utils.clip_grad_norm_(model.parameters(),5); om.step()
            dc=c.detach(); prob=torch.softmax(policy(s.PROMPTS),1); lp=torch.stack([(cap_probs(prob,ci)*dc).sum(1).mean() for ci in range(len(KS))]).mean(); op.zero_grad(); lp.backward(); op.step()
    else: raise ValueError(method)
    return model.eval(),policy.eval()

@torch.no_grad()
def generate(model,prompt,k):
    seq=prompt.tolist(); out=[]
    for _ in range(s.OUT):
        z,_=model.forward_hard_one(torch.tensor([seq]),prompt[None],k); t=int(z[0,-1].argmax()); seq.append(t); out.append(t)
    return out

@torch.no_grad()
def audit(model,policy):
    pref_idx=policy(s.PROMPTS).argmax(1); by={}; nested=count_bad=0; physical=True
    for ci,cap in enumerate(KS):
        eff_idx=torch.minimum(pref_idx,torch.full_like(pref_idx,ci)); eff_k=torch.tensor(KS)[eff_idx]; tok=exact=0; routes=set()
        for i,p in enumerate(s.PROMPTS):
            k=int(eff_k[i]); g=generate(model,p,k); t=s.TARGETS[i].tolist(); tok+=sum(a==b for a,b in zip(g,t)); exact+=int(g==t); routes.add(tuple(torch.nonzero(model.hard_mask(p[None],k)[0]).squeeze(1).tolist()))
        by[str(cap)]={'token_acc':tok/(len(s.PROMPTS)*s.OUT),'exact':exact/len(s.PROMPTS),'mean_effective_blocks':float(eff_k.float().mean()),'routes':len(routes)}
    for i,p in enumerate(s.PROMPTS):
        prev=set(); prev_k=-1
        for ci,cap in enumerate(KS):
            k=KS[min(int(pref_idx[i]),ci)]; count_bad+=int(k>cap or k<prev_k); cur=set(torch.nonzero(model.hard_mask(p[None],k)[0]).squeeze(1).tolist())
            if ci: nested+=int(not prev.issubset(cur))
            prev=cur; prev_k=k
    for ci,cap in enumerate(KS):
        k=KS[min(int(pref_idx[7]),ci)]; hits=[]; model.forward_hard_one(s.PROMPTS[7:8],s.PROMPTS[7:8],k,hits); physical &= len(hits)==k and k<=cap
    return {'by_cap':by,'preferred_distribution':{str(KS[j]):int((pref_idx==j).sum()) for j in range(len(KS)) if int((pref_idx==j).sum())},'nested_violations':nested,'cap_or_count_monotonic_violations':count_bad,'hard_cap_pass':bool(physical)}

def aggregate(rows,baseline):
    out={}
    for method in ['st','soft','decoupled']:
        rr=[r[method] for r in rows]; out[method]={'mean_by_cap':{str(k):{q:statistics.mean(x['by_cap'][str(k)][q] for x in rr) for q in ['token_acc','exact','mean_effective_blocks','routes']} for k in KS},'nested_violations':sum(x['nested_violations'] for x in rr),'cap_or_count_monotonic_violations':sum(x['cap_or_count_monotonic_violations'] for x in rr),'all_hard_cap_pass':all(x['hard_cap_pass'] for x in rr)}
        b=baseline['coarse']['aggregate']['mean_by_cap']['6']; m=out[method]['mean_by_cap']['6']; out[method]['vs_post_full']={'token_pp':100*(m['token_acc']-b['token_acc']),'exact_pp':100*(m['exact']-b['exact']),'mean_blocks_delta':m['mean_effective_blocks']-b['mean_effective_blocks']}
        c=out[method]['vs_post_full']; ok=out[method]['nested_violations']==0 and out[method]['cap_or_count_monotonic_violations']==0 and out[method]['all_hard_cap_pass'] and c['token_pp']>=-1 and c['exact_pp']>=-2 and c['mean_blocks_delta']<=.25
        out[method]['decision']='PASS' if ok else 'FAIL'
    return out

def main():
    ap=argparse.ArgumentParser(); ap.add_argument('--seeds',type=int,default=5); ap.add_argument('--steps',type=int,default=400); ap.add_argument('--baseline',default='../results/realtime_nn_sequence_cap_preference_results.json'); ap.add_argument('--out'); a=ap.parse_args(); baseline=json.loads(Path(a.baseline).read_text()); rows=[]
    for seed in range(a.seeds):
        row={'seed':seed}
        for method in ['st','soft','decoupled']:
            m,p=train(seed,method,a.steps); row[method]=audit(m,p)
        rows.append(row); print('seed',seed,{m:row[m]['preferred_distribution'] for m in ['st','soft','decoupled']},flush=True)
    result={'setup':{'classes':KS,'steps':a.steps,'methods':{'st':'hard preferred-class forward with straight-through policy gradient; capability and stop jointly optimized','soft':'relaxed preferred-class probabilities; capability and stop jointly optimized; hard argmax at inference','decoupled':'online two-optimizer training: capability gets uniform all-class task loss; stop gets detached current counterfactual class losses'},'PASS':'full-cap token gap >= -1 pp, exact gap >= -2 pp, mean work delta <= +0.25 block, zero cap/nested violations'},'seeds':rows,'aggregate':aggregate(rows,baseline)}
    if a.out: Path(a.out).parent.mkdir(parents=True,exist_ok=True); Path(a.out).write_text(json.dumps(result,indent=2))
    print(json.dumps(result['aggregate'],indent=2))
if __name__=='__main__': main()
