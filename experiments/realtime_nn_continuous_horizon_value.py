import argparse,json,platform,statistics,sys,torch
import torch.nn as nn
import torch.nn.functional as F
from pathlib import Path
import realtime_nn_sequence_nested_routing as s

# External contract is continuous. Physical execution remains finite/analyzable.
s.KS=list(range(s.B+1))
FRACTIONS=[k/s.B for k in s.KS]
BUDGETS=[i/20 for i in range(21)]

class PreferredCompute(nn.Module):
    def __init__(self):
        super().__init__();self.net=nn.Sequential(nn.Linear(s.PROMPT,24),nn.Tanh(),nn.Linear(24,len(s.KS)))
    def forward(self,p):return self.net(p.float())

class ValuePredictor(nn.Module):
    def __init__(self,d):
        super().__init__();self.net=nn.Sequential(nn.Linear(d,32),nn.Tanh(),nn.Linear(32,16),nn.Tanh(),nn.Linear(16,1))
    def forward(self,x):return self.net(x).squeeze(-1)

def per_sample_ce(z):
    zz=z[:,s.POS];yy=s.SEQ[:,s.POS+1]
    return F.cross_entropy(zz.reshape(-1,2),yy.reshape(-1),reduction='none').view(len(s.PROMPTS),s.OUT).mean(1)

def train_post(seed,losses,steps):
    torch.manual_seed(10000+seed);p=PreferredCompute();opt=torch.optim.AdamW(p.parameters(),lr=1e-2,weight_decay=1e-5)
    cols=[torch.tensor([min(r,ci) for r in range(len(s.KS))]) for ci in range(len(s.KS))]
    for _ in range(steps):
        prob=torch.softmax(p(s.PROMPTS),1);loss=torch.stack([(prob*losses[:,c]).sum(1).mean() for c in cols]).mean()
        opt.zero_grad();loss.backward();opt.step()
    return p.eval()

@torch.no_grad()
def feature_prompt(prompt,k):
    return torch.cat([prompt.float(),torch.tensor([k/s.B])])

@torch.no_grad()
def feature_state(model,prompt,k):
    h=model.base(prompt[None]);m=model.hard_mask(prompt[None],k)[0]
    for i,b in enumerate(model.blocks):
        if m[i]>0:h=b(h)
    return torch.cat([h[0,-1],h[0].mean(0),torch.tensor([k/s.B])])

def examples(model,losses,mode,indices):
    xs=[];ys=[]
    for i in indices:
        p=s.PROMPTS[i]
        for ci,k in enumerate(s.KS[:-1]):
            x=feature_prompt(p,k) if mode=='prompt' else feature_state(model,p,k)
            # Horizon value: benefit of the best future class, not only the next class.
            y=float(losses[i,ci]-losses[i,ci+1:].min())
            xs.append(x);ys.append(y)
    return torch.stack(xs),torch.tensor(ys)

def fit_value(model,losses,mode,indices,seed,steps):
    x,y=examples(model,losses,mode,indices);scale=max(float(y.std()),0.05);yn=y/scale
    torch.manual_seed(20000+seed+(1000 if mode=='state' else 0));net=ValuePredictor(x.shape[1]);opt=torch.optim.AdamW(net.parameters(),lr=5e-3,weight_decay=1e-4)
    for _ in range(steps):
        loss=F.smooth_l1_loss(net(x),yn);opt.zero_grad();loss.backward();opt.step()
    return net.eval(),scale

def preferred_from_predictor(model,losses,mode,seed,steps,crossfit):
    pref=torch.zeros(len(s.PROMPTS),dtype=torch.long);sign_ok=total=0
    folds=4 if crossfit else 1
    for fold in range(folds):
        test=[i for i in range(len(s.PROMPTS)) if (not crossfit or i%4==fold)]
        train=[i for i in range(len(s.PROMPTS)) if (not crossfit or i%4!=fold)]
        net,scale=fit_value(model,losses,mode,train,seed*10+fold,steps)
        with torch.no_grad():
            for i in test:
                p=s.PROMPTS[i];chosen=0
                for ci,k in enumerate(s.KS[:-1]):
                    x=feature_prompt(p,k) if mode=='prompt' else feature_state(model,p,k)
                    v=float(net(x[None])[0])*scale;truth=float(losses[i,ci]-losses[i,ci+1:].min())
                    sign_ok+=int((v>0)==(truth>0));total+=1
                    if v>0:chosen=ci+1
                    else:break
                pref[i]=chosen
    return pref,sign_ok/total

def cap_index(b):
    idx=0
    for i,f in enumerate(FRACTIONS):
        if f<=b+1e-12:idx=i
    return idx

@torch.no_grad()
def generate(model,prompt,k):
    seq=prompt.tolist();out=[]
    for _ in range(s.OUT):
        z,_=model.forward_hard_one(torch.tensor([seq]),prompt[None],k);t=int(z[0,-1].argmax());seq.append(t);out.append(t)
    return out

@torch.no_grad()
def audit(model,pref):
    rows=[];nested=capviol=0;hard=True;prev_sets=[set() for _ in s.PROMPTS];prev_k=[-1]*len(s.PROMPTS)
    for b in BUDGETS:
        ci=cap_index(b);eff_idx=torch.minimum(pref,torch.full_like(pref,ci));eff=torch.tensor(s.KS)[eff_idx];tok=exact=0
        for i,p in enumerate(s.PROMPTS):
            k=int(eff[i]);g=generate(model,p,k);t=s.TARGETS[i].tolist();tok+=sum(a==bb for a,bb in zip(g,t));exact+=int(g==t)
            cur=set(torch.nonzero(model.hard_mask(p[None],k)[0]).squeeze(1).tolist())
            if prev_k[i]>=0:nested+=int(not prev_sets[i].issubset(cur))
            capviol+=int(k/s.B>b+1e-12 or k<prev_k[i]);prev_sets[i]=cur;prev_k[i]=k
        hits=[];rk=int(eff[7]);model.forward_hard_one(s.PROMPTS[7:8],s.PROMPTS[7:8],rk,hits);hard&=(len(hits)==rk and rk/s.B<=b+1e-12)
        rows.append({'budget':b,'budget_pct':100*b,'admitted_class_fraction':s.KS[ci]/s.B,'token_acc':tok/(len(s.PROMPTS)*s.OUT),'exact':exact/len(s.PROMPTS),'mean_effective_compute':float(eff.float().mean()/s.B)})
    return {'by_budget':rows,'nested_violations':nested,'cap_or_count_violations':capviol,'hard_cap_pass':bool(hard)}

def one_seed(seed,steps,pred_steps,post_steps):
    model=s.train(seed,'input',steps)
    with torch.no_grad():
        z=model.forward_joint(s.SEQ,s.PROMPTS,.3);losses=torch.stack([per_sample_ce(z[i]) for i in range(len(s.KS))],1)
    post=train_post(seed,losses,post_steps);methods={'post':post(s.PROMPTS).argmax(1)};sign={}
    for mode in ['prompt','state']:
        for crossfit in [False,True]:
            name=f'{mode}_'+('crossfit' if crossfit else 'fullfit');methods[name],sign[name]=preferred_from_predictor(model,losses,mode,seed,pred_steps,crossfit)
    return {'seed':seed,'sign_accuracy':sign,'preferred_distribution_fraction':{n:{str(s.KS[j]/s.B):int((p==j).sum()) for j in range(len(s.KS)) if int((p==j).sum())} for n,p in methods.items()},'audits':{n:audit(model,p) for n,p in methods.items()}}

def aggregate(rows):
    names=['post','prompt_fullfit','state_fullfit','prompt_crossfit','state_crossfit'];out={}
    for n in names:
        full=[r['audits'][n]['by_budget'][-1] for r in rows]
        out[n]={'full_budget':{'token_acc':statistics.mean(x['token_acc'] for x in full),'exact':statistics.mean(x['exact'] for x in full),'mean_effective_compute':statistics.mean(x['mean_effective_compute'] for x in full)},'nested_violations':sum(r['audits'][n]['nested_violations'] for r in rows),'cap_or_count_violations':sum(r['audits'][n]['cap_or_count_violations'] for r in rows),'all_hard_cap_pass':all(r['audits'][n]['hard_cap_pass'] for r in rows)}
    base=out['post']['full_budget']
    for n in names[1:]:
        x=out[n]['full_budget'];v={'token_pp':100*(x['token_acc']-base['token_acc']),'exact_pp':100*(x['exact']-base['exact']),'mean_compute_pct_points':100*(x['mean_effective_compute']-base['mean_effective_compute'])};out[n]['vs_post']=v
        out[n]['decision']='PASS' if v['token_pp']>=-1 and v['exact_pp']>=-2 and v['mean_compute_pct_points']<=100*.25/s.B and out[n]['nested_violations']==0 and out[n]['cap_or_count_violations']==0 and out[n]['all_hard_cap_pass'] else 'FAIL'
    out['sign_accuracy']={k:statistics.mean(r['sign_accuracy'][k] for r in rows) for k in rows[0]['sign_accuracy']}
    out['hypotheses']={'primary':{'H':'continuous external budget plus stable-frontier hidden-state horizon value preserves the quality/work frontier','decision':out['state_fullfit']['decision']},'heldout_prompt':{'H':'the state horizon-value predictor generalizes under 4-fold prompt cross-fitting','decision':out['state_crossfit']['decision']}}
    return out

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--seed',type=int);ap.add_argument('--seeds',type=int,default=5);ap.add_argument('--steps',type=int,default=400);ap.add_argument('--pred-steps',type=int,default=250);ap.add_argument('--post-steps',type=int,default=1200);ap.add_argument('--out',default='results/realtime_nn_continuous_horizon_value_results.json');a=ap.parse_args()
    seeds=[a.seed] if a.seed is not None else list(range(a.seeds));rows=[]
    for seed in seeds:
        r=one_seed(seed,a.steps,a.pred_steps,a.post_steps);rows.append(r);print('seed',seed,{n:r['audits'][n]['by_budget'][-1] for n in ['post','state_fullfit','state_crossfit']},flush=True)
    result={'setup':{'external_budget':'continuous normalized b in [0,1]','budget_grid':BUDGETS,'physical_classes_fraction':FRACTIONS,'lowering':'largest finite physical class <= b','capability_steps':a.steps,'predictor_steps':a.pred_steps,'post_policy_steps':a.post_steps,'seeds':len(seeds),'environment':{'python':sys.version.split()[0],'torch':torch.__version__,'platform':platform.machine(),'torch_threads':torch.get_num_threads()}},'seeds':rows,'aggregate':aggregate(rows),'nonclaims':['continuous external budget does not mean continuous machine instruction count','no held-out-prompt generalization claim if cross-fit fails','no real-data generalization','no WCET or hard-real-time claim']}
    Path(a.out).parent.mkdir(parents=True,exist_ok=True);Path(a.out).write_text(json.dumps(result,indent=2));print(json.dumps(result['aggregate'],indent=2))
if __name__=='__main__':main()
