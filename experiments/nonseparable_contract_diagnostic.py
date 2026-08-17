"""Non-separable runtime-contract diagnostic for resource-conditioned routing.

Tests whether a simple global price contract survives stage-local hardware cost changes,
and whether supplying route-local calibration information helps on held-out profiles.
This is a frozen-capability routing/interface diagnostic. Exact analytic scheduling remains
an oracle when route costs are known.
"""
import argparse, json, random, time
from pathlib import Path
import torch
import torch.nn as nn
import torch.nn.functional as F
import searchspace_robustness as s

torch.set_num_threads(1)
ROOT=Path(__file__).resolve().parents[1]
DEFAULT_OUT=ROOT/'results'/'nonseparable_contract_diagnostic_results.json'
CFG=s.CONFIGS['s4_hom']; TOPOS=s.topos(CFG); TIDX=torch.tensor(TOPOS,dtype=torch.long)
BASE=s.BASE_COST; TRAIN_ANCHORS=s.ANCHORS; APS=torch.stack([s.price(r) for r in TRAIN_ANCHORS])


def make_profile(seed,sigma=.32):
    g=torch.Generator().manual_seed(10000+seed)
    z=torch.randn(CFG.stages,2,generator=g)*sigma
    z=z-z.mean(0,keepdim=True)
    return torch.exp(z)


def contract_features(ps,profiles,blind=False):
    zp=torch.log(ps.clamp_min(1e-8)); zp=zp-zp.mean(1,keepdim=True)
    zc=torch.log(profiles.clamp_min(1e-8)); zc=zc-zc.mean(1,keepdim=True); zc=zc.reshape(ps.size(0),-1)
    if blind: zc=torch.zeros_like(zc)
    return torch.cat([zp,zc],1)


def build_conditions(profile_ids):
    ps=[]; prof=[]
    for pid in profile_ids:
        q=make_profile(pid)
        for p in APS: ps.append(p); prof.append(q)
    return torch.stack(ps),torch.stack(prof)


def condition_costs(ps,profiles):
    opbase=BASE[TIDX]
    route_resource=(opbase[None,:,:,:]*profiles[:,None,:,:]).sum(2)
    return (route_resource*ps[:,None,:]).sum(-1)


def train_capability(seed=0,steps=1600):
    torch.manual_seed(seed); random.seed(seed); m=s.Net(CFG)
    opt=torch.optim.AdamW(m.parameters(),lr=2e-3,weight_decay=1e-6)
    for step in range(steps): s.capability_step(m,opt,CFG,step)
    return m.eval(),s.full_accs(m,TOPOS)


class FlatPolicy(nn.Module):
    def __init__(self,blind=False):
        super().__init__(); self.blind=blind
        self.net=nn.Sequential(nn.Linear(10,96),nn.Tanh(),nn.Linear(96,96),nn.Tanh(),nn.Linear(96,len(TOPOS)))
    def logits(self,p,profile): return self.net(contract_features(p,profile,self.blind))
    @torch.no_grad()
    def topology(self,p,profile): return TOPOS[int(self.logits(p,profile).argmax(1)[0])]


def train_flat(acc,n_profiles,router_seed,blind=False,steps=1800):
    feasible=(acc==1.0).float(); ps,profiles=build_conditions(range(n_profiles)); costs=condition_costs(ps,profiles)
    torch.manual_seed(8000+router_seed+(100 if blind else 0)); r=FlatPolicy(blind); opt=torch.optim.AdamW(r.parameters(),lr=2.5e-3,weight_decay=1e-6)
    for step in range(steps):
        lp=F.log_softmax(r.logits(ps,profiles),-1); q=lp.exp(); ent=-(q*lp).sum(1).mean()
        loss=(q*(costs+3.0*(1-feasible)[None,:])).sum(1).mean()-.02*max(0,1-step/700)*ent
        opt.zero_grad(); loss.backward(); opt.step()
    return r.eval()


def route_cost(t,p,profile):
    c=torch.zeros(2)
    for stage,op in enumerate(t): c += BASE[op]*profile[stage]
    return float((c*p).sum())


@torch.no_grad()
def evaluate(policy,acc,profile_ids,swap=False):
    valid=[t for t,a in zip(TOPOS,acc) if a==1.0]; dense=[10**(-2+4*i/199) for i in range(200)]
    total=hard=optimal=0; regret=0.; used=set(); ids=list(profile_ids)
    for i,pid in enumerate(ids):
        true_profile=make_profile(pid); observed=make_profile(ids[(i+1)%len(ids)]) if swap else true_profile
        for ratio in dense:
            p=s.price(ratio); t=policy.topology(p.view(1,2),observed.view(1,CFG.stages,2)); used.add(t)
            hard+=int(float(acc[TOPOS.index(t)])==1.0)
            best=min(route_cost(v,p,true_profile) for v in valid); c=route_cost(t,p,true_profile)
            optimal+=int(c<=best+1e-7); regret+=max(0.,c-best); total+=1
    return {'hard_accuracy':hard/total,'tie_optimal_cost_rate':optimal/total,'mean_regret':regret/total,'num_routes':len(used)}


class ProfileAR(nn.Module):
    def __init__(self):
        super().__init__(); self.h=nn.Sequential(nn.Linear(10,40),nn.Tanh(),nn.Linear(40,32),nn.Tanh())
        self.heads=nn.ModuleList([nn.Linear(32,3)]+[nn.Sequential(nn.Linear(32+3*i,32),nn.Tanh(),nn.Linear(32,3)) for i in range(1,CFG.stages)])
    def logprob_topologies(self,p,profile):
        B=p.size(0); T=len(TOPOS); h=self.h(contract_features(p,profile,False)); total=torch.zeros(B,T); idx=TIDX
        for stage in range(CFG.stages):
            hh=h[:,None,:].expand(B,T,32)
            if stage:
                hist=[F.one_hot(idx[:,j],3).float()[None,:,:].expand(B,T,3) for j in range(stage)]
                inp=torch.cat([hh]+hist,-1).reshape(B*T,32+3*stage)
            else: inp=hh.reshape(B*T,32)
            lp=F.log_softmax(self.heads[stage](inp).view(B,T,3),-1)
            total += lp.gather(2,idx[:,stage][None,:,None].expand(B,T,1)).squeeze(2)
        return total
    @torch.no_grad()
    def topology(self,p,profile):
        h=self.h(contract_features(p,profile,False)); hist=[]; out=[]
        for stage in range(CFG.stages):
            inp=torch.cat([h]+hist,1) if hist else h; a=self.heads[stage](inp).argmax(1); out.append(int(a[0])); hist.append(F.one_hot(a,3).float())
        return tuple(out)


def train_ar_minibatch(acc,steps=1200,batch=64):
    feasible=(acc==1.0).float(); ps,profiles=build_conditions(range(256)); costs=condition_costs(ps,profiles)
    torch.manual_seed(16000); r=ProfileAR(); opt=torch.optim.AdamW(r.parameters(),lr=3e-3,weight_decay=1e-6)
    for step in range(steps):
        ix=torch.randint(0,ps.size(0),(batch,)); pp=ps[ix]; pr=profiles[ix]; cc=costs[ix]
        lp=r.logprob_topologies(pp,pr); q=lp.exp(); ent=-(q*lp).sum(1).mean()
        loss=(q*(cc+3.0*(1-feasible)[None,:])).sum(1).mean()-.025*max(0,1-step/max(1,steps*.4))*ent
        opt.zero_grad(); loss.backward(); torch.nn.utils.clip_grad_norm_(r.parameters(),5.); opt.step()
    return r.eval()


def suite(out_path=DEFAULT_OUT):
    _,acc=train_capability(0); hold=list(range(1000,1020)); result={'setup':{
        'task':'4-bit parity; capability frozen only for this interface diagnostic',
        'hardware_profile':'stage-local 2D multiplicative cost calibration normalized to geometric mean 1 per resource',
        'aware_contract':'relative global log price + relative stage-local log calibration',
        'boundary':'flat policy enumerates 81 routes as output classes; analytic scheduler with exact costs remains oracle.'}}
    curve=[]
    for n in [8,32,64,128,256]:
        r=train_flat(acc,n,0,False); curve.append({'n_profiles':n,'aware':evaluate(r,acc,hold,False),'swapped':evaluate(r,acc,hold,True)})
        print('coverage',n,curve[-1]['aware']['tie_optimal_cost_rate'],flush=True)
    result['coverage_seed0']=curve
    rows=[]
    for seed in range(3):
        aware=train_flat(acc,256,seed,False); blind=train_flat(acc,256,seed,True)
        rows.append({'seed':seed,'aware':evaluate(aware,acc,hold,False),'swapped':evaluate(aware,acc,hold,True),'blind':evaluate(blind,acc,hold,False)})
    result['n256_three_seed']=rows
    result['n256_aggregate']={
        'aware_mean_optimal':sum(x['aware']['tie_optimal_cost_rate'] for x in rows)/3,
        'aware_min_optimal':min(x['aware']['tie_optimal_cost_rate'] for x in rows),
        'swap_mean_optimal':sum(x['swapped']['tie_optimal_cost_rate'] for x in rows)/3,
        'blind_mean_optimal':sum(x['blind']['tie_optimal_cost_rate'] for x in rows)/3,
        'aware_mean_regret':sum(x['aware']['mean_regret'] for x in rows)/3,
        'blind_mean_regret':sum(x['blind']['mean_regret'] for x in rows)/3,
    }
    ar=train_ar_minibatch(acc); result['autoregressive_1200_step_diagnostic']=evaluate(ar,acc,hold,False)
    Path(out_path).write_text(json.dumps(result,indent=2)); return result

if __name__=='__main__':
    ap=argparse.ArgumentParser();ap.add_argument('--suite',action='store_true');ap.add_argument('--out',default=str(DEFAULT_OUT));a=ap.parse_args()
    if a.suite: print(json.dumps(suite(a.out),indent=2))
    else:
        _,acc=train_capability(0);r=train_flat(acc,32,0,False,steps=300);print(json.dumps(evaluate(r,acc,range(1000,1005)),indent=2))
