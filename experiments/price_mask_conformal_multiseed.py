import math, json, time, statistics, random, os
from pathlib import Path
import torch
import torch.nn as nn
import torch.nn.functional as F

torch.set_num_threads(1)
try:
    os.sched_setaffinity(0,{0})
except Exception:
    pass

N_BITS=12
N_STATES=1<<N_BITS
DEVICE='cpu'

# ----- Task -----
def all_states():
    idx=torch.arange(N_STATES,dtype=torch.long)
    shifts=torch.arange(N_BITS,dtype=torch.long)
    bits=((idx[:,None]>>shifts)&1).float()
    y=(bits.sum(1)>= (N_BITS//2+1)).long()  # strict majority
    return idx,bits,y
ALL_IDX,ALL_BITS,ALL_Y=all_states()

def sample(n):
    idx=torch.randint(0,N_STATES,(n,))
    bits=ALL_BITS[idx]
    y=ALL_Y[idx]
    return idx,bits,y

# ----- Experts: lookup (memory-heavy) vs algorithmic deep MLP (compute-heavy) -----
class Lookup(nn.Module):
    def __init__(self):
        super().__init__()
        self.emb=nn.Embedding(N_STATES,2)
        with torch.no_grad():
            self.emb.weight.fill_(-8.)
            self.emb.weight[torch.arange(N_STATES),ALL_Y]=8.
        for p in self.parameters(): p.requires_grad_(False)
    def forward(self,idx,bits): return self.emb(idx)

class Algo(nn.Module):
    def __init__(self,w=32,depth=6):
        super().__init__()
        ls=[nn.Linear(N_BITS,w),nn.ReLU()]
        for _ in range(depth-2): ls += [nn.Linear(w,w),nn.ReLU()]
        ls += [nn.Linear(w,2)]
        self.net=nn.Sequential(*ls)
    def forward(self,idx,bits): return self.net(bits)

def train_algo(seed,steps=700):
    torch.manual_seed(seed); random.seed(seed)
    m=Algo(); opt=torch.optim.AdamW(m.parameters(),lr=3e-3,weight_decay=1e-5)
    for s in range(steps):
        idx,b,y=sample(256)
        loss=F.cross_entropy(m(idx,b),y)
        opt.zero_grad();loss.backward();opt.step()
    # short full-state polish if needed
    with torch.no_grad(): acc=(m(ALL_IDX,ALL_BITS).argmax(1)==ALL_Y).float().mean().item()
    if acc<0.999:
        opt=torch.optim.Adam(m.parameters(),lr=1e-3)
        for _ in range(250):
            sel=torch.randint(0,N_STATES,(512,));loss=F.cross_entropy(m(sel,ALL_BITS[sel]),ALL_Y[sel])
            opt.zero_grad();loss.backward();opt.step()
    return m.eval()

# ----- Router -----
class Router(nn.Module):
    def __init__(self,use_price=True):
        super().__init__(); self.use_price=use_price
        din=4 if use_price else 2
        self.net=nn.Sequential(nn.Linear(din,16),nn.Tanh(),nn.Linear(16,2))
    def logits(self,price,mask):
        # price is positive; log makes ratios transferable across scales
        if self.use_price:
            x=torch.cat([torch.log(price.clamp_min(1e-6)),mask],1)
        else:x=mask
        z=self.net(x)
        return z + (mask-1.0)*1e4
    def choose(self,price,mask): return self.logits(price,mask).argmax(1)

def expert_costs(lookup,algo):
    # normalized compute proxy: embedding lookup ~2 MAC-equivalent vs actual linear MAC count.
    lookup_params=sum(p.numel() for p in lookup.parameters())
    algo_params=sum(p.numel() for p in algo.parameters())
    # MAC count for linear layers
    mac_algo=0
    for mod in algo.modules():
        if isinstance(mod,nn.Linear): mac_algo += mod.in_features*mod.out_features
    mac_lookup=2
    comp=torch.tensor([mac_lookup,mac_algo],dtype=torch.float)
    mem=torch.tensor([lookup_params,algo_params],dtype=torch.float)
    C=torch.stack([comp/comp.max(),mem/mem.max()],1) # expert x [compute,memory]
    return C,{'params':[lookup_params,algo_params],'macs':[mac_lookup,mac_algo]}

def train_router(seed,C,use_price,steps=1000):
    torch.manual_seed(seed+1000+(0 if use_price else 500)); random.seed(seed+1000)
    r=Router(use_price);opt=torch.optim.Adam(r.parameters(),lr=6e-3)
    for s in range(steps):
        n=256
        if use_price:
            # log-uniform prices independently; broad enough to teach relative price.
            lp=(torch.rand(n,2)*6.-3.)
            p=torch.exp(lp)
        else:
            p=torch.ones(n,2)
        # random safe masks, including both-safe cases
        u=torch.rand(n)
        mask=torch.ones(n,2)
        mask[u<.15,1]=0
        mask[(u>=.15)&(u<.30),0]=0
        logits=r.logits(p,mask)
        prob=logits.softmax(1)
        ecost=(p[:,None,:]*C[None,:,:]).sum(2)
        loss=(prob*ecost).sum(1).mean() + 1e-3*(prob*torch.log(prob.clamp_min(1e-8))).sum(1).mean()
        opt.zero_grad();loss.backward();opt.step()
    return r.eval()

# ----- Timing -----
def qbound(xs,alpha=.01):
    ys=sorted(xs); n=len(ys)
    k=math.ceil((n+1)*(1-alpha))
    k=min(max(k,1),n)
    return ys[k-1]

def time_forced(router,experts,j,N=900):
    # Force availability to route j only, but include router execution end-to-end.
    mask=torch.zeros(1,2);mask[0,j]=1
    p=torch.tensor([[.1,.1]])
    idx,b,y=sample(1)
    for _ in range(100):
        router.choose(p,mask);experts[j](idx,b)
    xs=[]
    for _ in range(N):
        idx,b,y=sample(1)
        t=time.perf_counter_ns();router.choose(p,mask);experts[j](idx,b);xs.append((time.perf_counter_ns()-t)/1000.)
    xs.sort()
    return {'median':statistics.median(xs),'p95':xs[int(.95*(N-1))],'p99':xs[int(.99*(N-1))],'conf99':qbound(xs,.01)}

def calibrate_shared(rp,rc,experts):
    out=[]
    for j in range(2):
        a=time_forced(rp,experts,j);b=time_forced(rc,experts,j)
        out.append({'price':a,'control':b,
                    'shared_p99':max(a['p99'],b['p99']),
                    'shared_conf99':max(a['conf99'],b['conf99'])})
    return out

@torch.no_grad()
def eval_policy(router,experts,C,price,D,bounds,N=1200):
    safe=torch.tensor([[1. if bounds[j]<=D else 0. for j in range(2)]],dtype=torch.float)
    if safe.sum()==0: safe[0,int(torch.tensor(bounds).argmin())]=1.
    p=torch.tensor([price],dtype=torch.float)
    hist=[0,0];miss=0;correct=0;costs=[];times=[]
    for _ in range(N):
        idx,b,y=sample(1)
        t=time.perf_counter_ns();j=int(router.choose(p,safe)[0]);logits=experts[j](idx,b);us=(time.perf_counter_ns()-t)/1000.
        times.append(us); miss+= int(us>D);correct+=int(logits.argmax(1).item()==y.item());hist[j]+=1
        costs.append(float((p[0]*C[j]).sum()))
    return {'acc':correct/N,'miss':miss/N,'mean_us':statistics.mean(times),'p99_us':sorted(times)[int(.99*(N-1))],
            'hist':[h/N for h in hist],'resource_cost':statistics.mean(costs),'safe':safe[0].tolist()}

def route_sweep(router,C):
    rows=[]
    mask=torch.ones(1,2)
    for ratio in [0.04,.1,.25,.5,1,2,4,10,25]:
        # geometric mean ~0.1, varying ratio pc/pm
        pc=.1*math.sqrt(ratio);pm=.1/math.sqrt(ratio);p=torch.tensor([[pc,pm]])
        prob=router.logits(p,mask).softmax(1)[0]
        j=int(prob.argmax());cost=float((p[0]*C[j]).sum())
        rows.append({'ratio':ratio,'pc':pc,'pm':pm,'prob':prob.tolist(),'route':j,'cost':cost})
    return rows

def run_seed(seed):
    lookup=Lookup().eval();algo=train_algo(seed);experts=[lookup,algo]
    with torch.no_grad():
        a0=(lookup(ALL_IDX,ALL_BITS).argmax(1)==ALL_Y).float().mean().item();a1=(algo(ALL_IDX,ALL_BITS).argmax(1)==ALL_Y).float().mean().item()
    C,meta=expert_costs(lookup,algo)
    rp=train_router(seed,C,True);rc=train_router(seed,C,False)
    cal=calibrate_shared(rp,rc,experts)
    bounds99=[z['shared_p99'] for z in cal];boundsc=[z['shared_conf99'] for z in cal]
    # Use shared conformal bounds for final evaluation. Pick tight/loose/generous deadlines.
    lo=min(boundsc);hi=max(boundsc)
    Ds=sorted(set([round(lo*1.05,2),round(hi*1.05,2),round(hi*1.6,2)]))
    conds={'compute_expensive':[1.,.05],'memory_expensive':[.05,1.],'balanced':[.1,.1]}
    rows=[]
    for cn,p in conds.items():
        for D in Ds:
            rows.append({'policy':'price','cond':cn,'D':D,**eval_policy(rp,experts,C,p,D,boundsc)})
            rows.append({'policy':'control','cond':cn,'D':D,**eval_policy(rc,experts,C,p,D,boundsc)})
    return {'seed':seed,'expert_acc':[a0,a1],'C':C.tolist(),'meta':meta,'cal':cal,'bounds_conf99':boundsc,'deadlines':Ds,'rows':rows,'sweep':route_sweep(rp,C)}

def summarize(seeds):
    # Compare at generous deadline (both routes safe) and tight route class point.
    groups={}
    for s in seeds:
        for r in s['rows']:
            key=(r['policy'],r['cond'],'tight' if r['D']==s['deadlines'][0] else ('both' if r['D']==s['deadlines'][1] else 'generous'))
            groups.setdefault(key,[]).append(r)
    out={}
    for k,rs in groups.items():
        out['|'.join(k)]={m:statistics.mean([r[m] for r in rs]) for m in ['acc','miss','mean_us','resource_cost']}
        out['|'.join(k)]['hist']=[statistics.mean([r['hist'][j] for r in rs]) for j in range(2)]
    return out

def main():
    seeds=[]
    for seed in [0,1,2]:
        print('seed',seed,flush=True);s=run_seed(seed);seeds.append(s)
        print('acc',s['expert_acc'],'bounds',s['bounds_conf99'],'Ds',s['deadlines'],flush=True)
    out={'seeds':seeds,'summary':summarize(seeds)}
    
    out_path = Path(__file__).resolve().parents[1] / 'results' / 'price_mask_conformal_multiseed_results.json'
    out_path.parent.mkdir(parents=True, exist_ok=True)
    with open(out_path,'w') as f: json.dump(out,f,indent=2)
    print(json.dumps(out['summary'],indent=2))
if __name__=='__main__':main()
