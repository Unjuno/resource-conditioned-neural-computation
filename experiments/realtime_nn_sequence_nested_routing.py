import argparse,itertools,json,math,random,statistics,time
import torch
import torch.nn as nn
import torch.nn.functional as F

torch.set_num_threads(1)
try: torch.set_num_interop_threads(1)
except RuntimeError: pass
PROMPT=5; OUT=4; T=9; H=24; FF=48; B=6; KS=[0,2,4,6]
PROMPTS=torch.tensor(list(itertools.product([0,1], repeat=PROMPT)),dtype=torch.long)
def target_for(p):
    mode=int(p[0]); d=[int(x) for x in p[1:]]
    if mode==0:return list(reversed(d))
    return [d[0]^d[1],d[1]^d[2],d[2]^d[3],d[3]^d[0]]
TARGETS=torch.tensor([target_for(p) for p in PROMPTS],dtype=torch.long)
SEQ=torch.cat([PROMPTS,TARGETS],1); POS=torch.arange(PROMPT-1,T-1)
class Block(nn.Module):
    def __init__(self):
        super().__init__();self.n1=nn.LayerNorm(H);self.q=nn.Linear(H,H);self.k=nn.Linear(H,H);self.v=nn.Linear(H,H);self.o=nn.Linear(H,H);self.n2=nn.LayerNorm(H);self.a=nn.Linear(H,FF);self.b=nn.Linear(FF,H)
    def forward(self,h):
        x=self.n1(h);q=self.q(x);k=self.k(x);v=self.v(x);kp=torch.cat([k[:,:1],k[:,:-1]],1);vp=torch.cat([v[:,:1],v[:,:-1]],1)
        sc=torch.stack([(q*k).sum(-1),(q*kp).sum(-1)],-1)/math.sqrt(H);att=torch.softmax(sc,-1);ctx=att[...,0,None]*v+att[...,1,None]*vp
        h=h+self.o(ctx);return h+.25*self.b(F.gelu(self.a(self.n2(h))))
class Net(nn.Module):
    def __init__(self,policy):
        super().__init__();self.policy=policy;self.emb=nn.Embedding(2,H);self.pos=nn.Parameter(torch.randn(T,H)*.02);self.blocks=nn.ModuleList([Block() for _ in range(B)]);self.head=nn.Linear(H,2)
        if policy=='input':self.ctrl=nn.Sequential(nn.Linear(PROMPT*H,48),nn.Tanh(),nn.Linear(48,B))
        elif policy=='global':self.score=nn.Parameter(torch.zeros(B))
    def base(self,x):return self.emb(x)+self.pos[:x.shape[1]][None]
    def scores(self,prompt):
        if self.policy=='global':return self.score[None].expand(prompt.size(0),-1)
        h=self.base(prompt)[:,:PROMPT].reshape(prompt.size(0),-1);return self.ctrl(h)
    def masks(self,prompt,tau=.3,train=False):
        n=prompt.size(0); out=[]
        sc=None if self.policy=='prefix' else self.scores(prompt)
        for k in KS:
            if self.policy=='prefix':
                hard=torch.zeros(n,B);hard[:,:k]=1
            elif k==0:hard=torch.zeros_like(sc)
            else:
                ids=sc.topk(k,1).indices;hard=torch.zeros_like(sc);hard.scatter_(1,ids,1.)
            if train and self.policy!='prefix' and k not in (0,B):
                soft=torch.softmax(sc/tau,1)*k; hard=hard+(soft-soft.detach())
            out.append(hard)
        return torch.stack(out,0)
    def forward_joint(self,x,prompt,tau):
        n=x.size(0); K=len(KS); h=self.base(x)[None].expand(K,-1,-1,-1).contiguous().view(K*n,x.size(1),H)
        gates=self.masks(prompt,tau,True).view(K*n,B)
        for i,b in enumerate(self.blocks):
            bh=b(h);h=h+gates[:,i,None,None]*(bh-h)
        return self.head(h).view(K,n,x.size(1),2)
    @torch.no_grad()
    def hard_mask(self,prompt,k):return self.masks(prompt,train=False)[KS.index(k)]
    @torch.no_grad()
    def forward_hard_one(self,x,prompt,k,hits=None):
        h=self.base(x);m=self.hard_mask(prompt,k)[0]
        for i,b in enumerate(self.blocks):
            if m[i]>0:
                if hits is not None:hits.append(i)
                h=b(h)
        return self.head(h),m

def loss_logits(z):return F.cross_entropy(z[:,POS].reshape(-1,2),SEQ[:,POS+1].reshape(-1))
def train(seed,policy,steps=400):
    torch.manual_seed(seed);random.seed(seed);m=Net(policy);opt=torch.optim.AdamW(m.parameters(),lr=2e-3,weight_decay=1e-5)
    for st in range(steps):
        tau=max(.3,1-st/steps*.7);Z=m.forward_joint(SEQ,PROMPTS,tau);loss=torch.stack([loss_logits(Z[i]) for i in range(len(KS))]).mean();opt.zero_grad();loss.backward();torch.nn.utils.clip_grad_norm_(m.parameters(),5);opt.step()
    return m.eval()
@torch.no_grad()
def generate(m,prompt,k):
    seq=prompt.tolist();out=[]
    for _ in range(OUT):
        z,_=m.forward_hard_one(torch.tensor([seq]),prompt[None],k);tok=int(z[0,-1].argmax());seq.append(tok);out.append(tok)
    return out
@torch.no_grad()
def audit(m):
    by={};route_samples={}
    for k in KS:
        tok=ex=0;routes=set()
        for i,p in enumerate(PROMPTS):
            g=generate(m,p,k);t=TARGETS[i].tolist();tok+=sum(a==b for a,b in zip(g,t));ex+=int(g==t);routes.add(tuple(torch.nonzero(m.hard_mask(p[None],k)[0]).squeeze(1).tolist()))
        by[str(k)]={'token_acc':tok/(len(PROMPTS)*OUT),'exact':ex/len(PROMPTS),'routes':len(routes)};route_samples[str(k)]=sorted([list(r) for r in routes])
    viol=comps=0
    for p in PROMPTS:
        prev=set()
        for k in KS:
            cur=set(torch.nonzero(m.hard_mask(p[None],k)[0]).squeeze(1).tolist())
            if k!=0:comps+=1;viol+=int(not prev.issubset(cur))
            prev=cur
    cap=True;traces=[]
    for k in KS:
        hits=[];m.forward_hard_one(PROMPTS[7:8],PROMPTS[7:8],k,hits);cap &= len(hits)==k;traces.append({'k':k,'hits':hits})
    return {'by_k':by,'route_samples':route_samples,'nested_violations':viol,'nested_comparisons':comps,'hard_cap_pass':bool(cap),'hard_traces':traces}
def aggregate(rows):
    out={}
    for policy in ['prefix','global','input']:
        prs=[x[policy] for x in rows]
        out[policy]={
            'mean_by_k': {str(k): {
                'token_acc': statistics.mean(r['by_k'][str(k)]['token_acc'] for r in prs),
                'exact': statistics.mean(r['by_k'][str(k)]['exact'] for r in prs),
                'routes': statistics.mean(r['by_k'][str(k)]['routes'] for r in prs),
            } for k in KS},
            'nested_violations': sum(r['nested_violations'] for r in prs),
            'all_hard_cap_pass': all(r['hard_cap_pass'] for r in prs),
        }
        monos=[]
        for r in prs:
            vals=[r['by_k'][str(k)]['token_acc'] for k in KS]
            drops=[max(0.0,100*(vals[i]-vals[i+1])) for i in range(len(vals)-1)]
            monos.append({'strict':all(vals[i]<=vals[i+1]+1e-12 for i in range(len(vals)-1)),'max_drop_pp':max(drops)})
        out[policy]['quality_monotonicity']={
            'strict_seeds':sum(x['strict'] for x in monos),
            'total_seeds':len(monos),
            'mean_max_drop_pp':statistics.mean(x['max_drop_pp'] for x in monos),
            'worst_drop_pp':max(x['max_drop_pp'] for x in monos),
        }
    def gap(base,k,metric):
        return 100*statistics.mean(x['input']['by_k'][str(k)][metric]-x[base]['by_k'][str(k)][metric] for x in rows)
    out['comparisons']={
        'input_minus_prefix_token_pp':{str(k):gap('prefix',k,'token_acc') for k in KS},
        'input_minus_prefix_exact_pp':{str(k):gap('prefix',k,'exact') for k in KS},
        'input_minus_global_token_pp':{str(k):gap('global',k,'token_acc') for k in KS},
    }
    c=out['comparisons']; inp=out['input']
    passed=(c['input_minus_prefix_token_pp']['2']>=5 and c['input_minus_prefix_token_pp']['4']>=5 and c['input_minus_global_token_pp']['4']>=5 and c['input_minus_prefix_token_pp']['6']>=-2 and inp['nested_violations']==0 and inp['all_hard_cap_pass'] and inp['mean_by_k']['2']['routes']>=2 and inp['mean_by_k']['4']['routes']>=2)
    out['hypothesis']={
        'H':'Input-dependent, budget-independent block ranking with nested top-k physical execution improves intermediate autoregressive quality over fixed prefix/global ordering at the same hard work class.',
        'PASS_conditions':{'k2_input_minus_prefix_token_pp_min':5.0,'k4_input_minus_prefix_token_pp_min':5.0,'k4_input_minus_global_token_pp_min':5.0,'k6_input_minus_prefix_token_pp_min':-2.0,'nested_violations':0,'hard_cap':True,'mean_route_count_k2_k4_min':2.0},
        'decision':'PASS' if passed else 'FAIL'
    }
    out['stronger_quality_monotonicity_hypothesis']={
        'H':'Forcing exact admitted work k makes generation token accuracy non-decreasing with k in every seed.',
        'decision':'PASS' if inp['quality_monotonicity']['strict_seeds']==len(rows) else 'FAIL'
    }
    return out

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--seed',type=int);ap.add_argument('--seeds',type=int,default=5);ap.add_argument('--steps',type=int,default=400);ap.add_argument('--out');a=ap.parse_args()
    seed_list=[a.seed] if a.seed is not None else list(range(a.seeds));rows=[]
    for seed in seed_list:
        row={'seed':seed}
        for policy in ['prefix','global','input']:
            m=train(seed,policy,a.steps);row[policy]=audit(m)
        rows.append(row);print('seed',seed,{p:{k:v for k,v in row[p]['by_k'].items()} for p in ['prefix','global','input']},flush=True)
    result={'setup':{'task':'5-bit prompt: mode bit + 4 data bits; mode 0 generates reversed data, mode 1 generates cyclic adjacent XORs','blocks':B,'classes':KS,'training':'task-loss-only joint training of all exact execution classes each update','input_policy':'budget-independent prompt-conditioned block ranking; selected blocks execute in canonical block order','environment':{'torch_threads':1}},'seeds':rows,'aggregate':aggregate(rows)}
    if a.out:
        from pathlib import Path;Path(a.out).parent.mkdir(parents=True,exist_ok=True);Path(a.out).write_text(json.dumps(result,indent=2))
    print(json.dumps(result['aggregate'],indent=2))
if __name__=='__main__':main()
