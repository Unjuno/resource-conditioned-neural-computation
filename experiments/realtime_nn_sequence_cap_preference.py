import argparse,json,statistics,torch
import torch.nn as nn
import torch.nn.functional as F
import realtime_nn_sequence_nested_routing as s

COARSE=[0,2,4,6]
FINE=list(range(s.B+1))

class PreferredCompute(nn.Module):
    def __init__(self):
        super().__init__();self.net=nn.Sequential(nn.Linear(s.PROMPT,24),nn.Tanh(),nn.Linear(24,len(s.KS)))
    def forward(self,prompt):return self.net(prompt.float())

def per_sample_ce(z):
    zz=z[:,s.POS];yy=s.SEQ[:,s.POS+1]
    return F.cross_entropy(zz.reshape(-1,2),yy.reshape(-1),reduction='none').view(len(s.PROMPTS),s.OUT).mean(1)

def train_policy(seed,steps=400,policy_steps=1200):
    model=s.train(seed,'input',steps)
    with torch.no_grad():
        Z=model.forward_joint(s.SEQ,s.PROMPTS,.3)
        losses=torch.stack([per_sample_ce(Z[i]) for i in range(len(s.KS))],1)
    torch.manual_seed(10000+seed);policy=PreferredCompute();opt=torch.optim.AdamW(policy.parameters(),lr=1e-2,weight_decay=1e-5)
    for _ in range(policy_steps):
        prob=torch.softmax(policy(s.PROMPTS),1);terms=[]
        for ci in range(len(s.KS)):
            cols=torch.tensor([min(r,ci) for r in range(len(s.KS))]);cost=losses[:,cols]
            terms.append((prob*cost).sum(1).mean())
        loss=torch.stack(terms).mean();opt.zero_grad();loss.backward();opt.step()
    return model.eval(),policy.eval(),losses

@torch.no_grad()
def audit_cap(model,policy,losses):
    pref_idx=policy(s.PROMPTS).argmax(1);by={};dists={};nested=capmono=0;physical_ok=True
    for ci,cap in enumerate(s.KS):
        eff_idx=torch.minimum(pref_idx,torch.full_like(pref_idx,ci));eff_k=torch.tensor(s.KS)[eff_idx]
        tok=exact=teacher_hits=0;teacher_ce=0.;routes=set()
        for i,prompt in enumerate(s.PROMPTS):
            k=int(eff_k[i]);seq=prompt.tolist();gen=[]
            for _ in range(s.OUT):
                z,_=model.forward_hard_one(torch.tensor([seq]),prompt[None],k);t=int(z[0,-1].argmax());seq.append(t);gen.append(t)
            tgt=s.TARGETS[i].tolist();tok+=sum(a==b for a,b in zip(gen,tgt));exact+=int(gen==tgt);teacher_ce+=float(losses[i,eff_idx[i]])
            z,_=model.forward_hard_one(s.SEQ[i:i+1],prompt[None],k);teacher_hits+=int((z[:,s.POS].argmax(-1)==s.SEQ[i:i+1,s.POS+1]).sum())
            routes.add(tuple(torch.nonzero(model.hard_mask(prompt[None],k)[0]).squeeze(1).tolist()))
        dists[str(cap)]={str(k):int((eff_k==k).sum()) for k in s.KS if int((eff_k==k).sum())}
        by[str(cap)]={'token_acc':tok/(len(s.PROMPTS)*s.OUT),'exact':exact/len(s.PROMPTS),'teacher_token_acc':teacher_hits/(len(s.PROMPTS)*s.OUT),'teacher_ce':teacher_ce/len(s.PROMPTS),'mean_effective_blocks':float(eff_k.float().mean()),'routes':len(routes)}
    for i,prompt in enumerate(s.PROMPTS):
        prev=set();prev_k=-1
        for ci,cap in enumerate(s.KS):
            k=s.KS[min(int(pref_idx[i]),ci)];capmono+=int(k>cap or k<prev_k);cur=set(torch.nonzero(model.hard_mask(prompt[None],k)[0]).squeeze(1).tolist())
            if ci:nested+=int(not prev.issubset(cur))
            prev=cur;prev_k=k
    prompt=s.PROMPTS[7]
    traces=[]
    for ci,cap in enumerate(s.KS):
        k=s.KS[min(int(pref_idx[7]),ci)];hits=[];model.forward_hard_one(prompt[None],prompt[None],k,hits);physical_ok &= (len(hits)==k and k<=cap);traces.append({'cap':cap,'effective_k':k,'hits':hits})
    return {'by_cap':by,'count_distributions':dists,'preferred_distribution':{str(k):int((torch.tensor(s.KS)[pref_idx]==k).sum()) for k in s.KS if int((torch.tensor(s.KS)[pref_idx]==k).sum())},'nested_violations':nested,'cap_or_count_monotonic_violations':capmono,'hard_cap_pass':bool(physical_ok),'hard_traces':traces}

def aggregate(rows):
    caps=[str(k) for k in s.KS];mean={c:{'token_acc':statistics.mean(r['cap']['by_cap'][c]['token_acc'] for r in rows),'exact':statistics.mean(r['cap']['by_cap'][c]['exact'] for r in rows),'teacher_ce':statistics.mean(r['cap']['by_cap'][c]['teacher_ce'] for r in rows),'mean_effective_blocks':statistics.mean(r['cap']['by_cap'][c]['mean_effective_blocks'] for r in rows)} for c in caps}
    token_mono=exact_mono=0
    for r in rows:
        tv=[r['cap']['by_cap'][c]['token_acc'] for c in caps];ev=[r['cap']['by_cap'][c]['exact'] for c in caps]
        token_mono+=int(all(tv[i]<=tv[i+1]+1e-12 for i in range(len(tv)-1)));exact_mono+=int(all(ev[i]<=ev[i+1]+1e-12 for i in range(len(ev)-1)))
    out={'mean_by_cap':mean,'strict_token_monotonic_seeds':token_mono,'strict_exact_monotonic_seeds':exact_mono,'total_seeds':len(rows),'nested_violations':sum(r['cap']['nested_violations'] for r in rows),'cap_or_count_monotonic_violations':sum(r['cap']['cap_or_count_monotonic_violations'] for r in rows),'all_hard_cap_pass':all(r['cap']['hard_cap_pass'] for r in rows)}
    if s.KS==COARSE:
        forced_full=statistics.mean(r['forced']['by_k']['6']['token_acc'] for r in rows);forced_exact=statistics.mean(r['forced']['by_k']['6']['exact'] for r in rows)
        out['full_cap_vs_forced_exact_k6']={'token_accuracy_pp':100*(mean['6']['token_acc']-forced_full),'exact_sequence_pp':100*(mean['6']['exact']-forced_exact),'mean_blocks_saved':6-mean['6']['mean_effective_blocks']}
        passed=(token_mono==len(rows) and exact_mono==len(rows) and out['nested_violations']==0 and out['cap_or_count_monotonic_violations']==0 and out['all_hard_cap_pass'] and out['full_cap_vs_forced_exact_k6']['token_accuracy_pp']>=0 and out['full_cap_vs_forced_exact_k6']['mean_blocks_saved']>0)
        out['hypothesis']={'H':'Treating runtime budget as a hard cap and learning an input-specific preferred computation level from task loss removes forced-extra-work regressions while using no more than the admitted work.','decision':'PASS' if passed else 'FAIL'}
    return out

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--classes',choices=['coarse','fine'],default='coarse');ap.add_argument('--seed',type=int);ap.add_argument('--seeds',type=int,default=5);ap.add_argument('--steps',type=int,default=400);ap.add_argument('--policy-steps',type=int,default=1200);ap.add_argument('--out');a=ap.parse_args()
    s.KS=COARSE[:] if a.classes=='coarse' else FINE[:]
    seeds=[a.seed] if a.seed is not None else list(range(a.seeds));rows=[]
    for seed in seeds:
        model,policy,losses=train_policy(seed,a.steps,a.policy_steps);row={'seed':seed,'forced':s.audit(model),'cap':audit_cap(model,policy,losses)};rows.append(row);print('seed',seed,row['cap']['by_cap'],row['cap']['preferred_distribution'],flush=True)
    result={'setup':{'classes':s.KS,'budget_semantics':'cap, not exact required work','effective_work':'min(input-specific preferred computation, admitted cap)','preferred_policy_training':'post-train from per-input task CE only; no relevance/path labels','steps':a.steps,'policy_steps':a.policy_steps},'seeds':rows,'aggregate':aggregate(rows)}
    if a.out:
        from pathlib import Path;Path(a.out).parent.mkdir(parents=True,exist_ok=True);Path(a.out).write_text(json.dumps(result,indent=2))
    print(json.dumps(result['aggregate'],indent=2))
if __name__=='__main__':main()
