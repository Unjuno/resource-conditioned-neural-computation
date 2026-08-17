import json, math, random, time
from pathlib import Path
import torch
import torch.nn.functional as F
import joint_parity_correlated_curriculum as b

torch.set_num_threads(1)

def ar_sample(router,p):
    # p: [B,2], sample correlated hard topology and return log-prob.
    h=router.h(router.feat(p))
    l0=router.s0(h); d0=torch.distributions.Categorical(logits=l0); a=d0.sample(); lp=d0.log_prob(a)
    o0=F.one_hot(a,3).float()
    l1=router.s1(torch.cat([h,o0],1)); d1=torch.distributions.Categorical(logits=l1); c=d1.sample(); lp=lp+d1.log_prob(c)
    o1=F.one_hot(c,3).float()
    l2=router.s2(torch.cat([h,o0,o1],1)); d2=torch.distributions.Categorical(logits=l2); e=d2.sample(); lp=lp+d2.log_prob(e)
    topo=torch.stack([a,c,e],1)
    ent=d0.entropy()+d1.entropy()+d2.entropy()
    return topo,lp,ent

def topo_tuple(row): return tuple(int(x) for x in row.tolist())

def sampled_probe_minacc(m,n=64):
    sel=torch.randint(0,b.N,(n,))
    vals=[]
    with torch.no_grad():
        for t in b.SINGLES:
            vals.append(float((m.forward_topology(sel,b.BITS[sel],t).argmax(1)==b.Y[sel]).float().mean()))
    return min(vals)

def train(seed,total_steps=1800,gate_threshold=1.0,K=4,calib_n=64):
    torch.manual_seed(seed); random.seed(seed)
    m=b.Net(); r=b.ARRouter(True)
    mop=torch.optim.AdamW(m.parameters(),lr=2e-3,weight_decay=1e-6)
    rop=torch.optim.AdamW(r.parameters(),lr=2.5e-3,weight_decay=1e-6)
    router_on=False; activated=None
    baseline=torch.zeros(len(b.ANCHORS)); base_init=torch.zeros(len(b.ANCHORS),dtype=torch.bool)
    for step in range(total_steps):
        if step%50==0 and not router_on:
            if sampled_probe_minacc(m,calib_n)>=gate_threshold:
                router_on=True; activated=step
        b.capability_step(m,mop,step,None)
        if router_on:
            ps=b.APS.repeat_interleave(K,0); topo,lp,ent=ar_sample(r,ps)
            rewards=[]
            with torch.no_grad():
                for i in range(ps.size(0)):
                    t=topo_tuple(topo[i]); sel=torch.randint(0,b.N,(calib_n,))
                    ok=float((m.forward_topology(sel,b.BITS[sel],t).argmax(1)==b.Y[sel]).float().mean())
                    feasible=(ok==1.0)
                    c=float((b.OP_COST[list(t)].sum(0)*ps[i]).sum())
                    rewards.append(c+(0.0 if feasible else 3.0))
            val=torch.tensor(rewards)
            anchor_ids=torch.arange(len(b.ANCHORS)).repeat_interleave(K)
            adv=torch.empty_like(val)
            for a in range(len(b.ANCHORS)):
                mask=anchor_ids==a; mean=float(val[mask].mean())
                if not base_init[a]: baseline[a]=mean; base_init[a]=True
                else: baseline[a]=0.92*baseline[a]+0.08*mean
                adv[mask]=val[mask]-baseline[a]
            loss=(adv.detach()*lp).mean()-0.015*ent.mean()
            rop.zero_grad(); loss.backward(); torch.nn.utils.clip_grad_norm_(r.parameters(),5.0); rop.step()
    return m.eval(),r.eval(),activated

ROOT=Path(__file__).resolve().parents[1]
DEFAULT_OUT=ROOT/'results'/'sampled_joint_parity_policy_results.json'

def suite(out=DEFAULT_OUT,seeds=5):
    rows=[]
    for s in range(seeds):
        t=time.time(); m,r,a=train(s); v=b.evaluate(m,r); v['router_activated_at']=a; v['seconds']=time.time()-t; rows.append(v)
        print(s,'act',a,'acc',v['hard_accuracy'],'opt',v['tie_optimal_cost_rate'],'routes',v['num_routes'],'regret',v['mean_regret'],flush=True)
    agg={'mean_hard_accuracy':sum(v['hard_accuracy'] for v in rows)/seeds,'min_hard_accuracy':min(v['hard_accuracy'] for v in rows),'mean_tie_optimal_cost_rate':sum(v['tie_optimal_cost_rate'] for v in rows)/seeds,'min_tie_optimal_cost_rate':min(v['tie_optimal_cost_rate'] for v in rows),'mean_regret':sum(v['mean_regret'] for v in rows)/seeds,'seeds_multiple_routes':sum(v['num_routes']>1 for v in rows),'seeds_all_probes_perfect':sum(min(v['probe_accs'].values())==1.0 for v in rows)}
    R={'setup':{'task':'4-bit parity','complete_topology_enumeration_in_router_training':False,'full_domain_feasibility_in_router_training':False,'router':'autoregressive sampled policy gradient','samples_per_anchor':4,'calibration_states_per_sample':64,'capability_freeze':False,'boundary':'Uses binary feasibility on sampled calibration minibatches and known proxy cost. Full 256-state domain is used only for final evaluation.'},'seeds':rows,'aggregate':agg}
    Path(out).write_text(json.dumps(R,indent=2)); print(json.dumps(agg,indent=2)); return R

if __name__=='__main__': suite()
