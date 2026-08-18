import argparse, itertools, json, math, random, statistics, time
from pathlib import Path
import torch
import torch.nn as nn
import torch.nn.functional as F

torch.set_num_threads(1)
try: torch.set_num_interop_threads(1)
except RuntimeError: pass

L=5; H=32; FF=64; B=4; NOPS=8
X=torch.tensor([[float((s>>i)&1) for i in range(L)] for s in range(1<<L)])
Y=torch.stack([X[:,0], *[(X[:,0]!=X[:,j]).float() for j in range(1,L)]],1)
TARGET_W=torch.tensor([.4,1.,.9,.8,.7])
PRICES=[0.,.05,.1,.2,.3,.5,.8,1.,1.5]
CAPS=[0,2,4,6,8]
MASKS=[tuple(x) for x in itertools.product([0,1], repeat=NOPS)]

class Attn(nn.Module):
    def __init__(self):
        super().__init__(); self.n=nn.LayerNorm(H); self.q=nn.Linear(H,H); self.k=nn.Linear(H,H); self.v=nn.Linear(H,H); self.o=nn.Linear(H,H)
    def forward(self,h):
        x=self.n(h);q=self.q(x);k=self.k(x);v=self.v(x)
        kr=torch.cat([k[:,1:],k[:,-1:]],1);vr=torch.cat([v[:,1:],v[:,-1:]],1)
        sc=torch.stack([(q*k).sum(-1),(q*kr).sum(-1)],-1)/math.sqrt(H)
        a=torch.softmax(sc,-1);ctx=a[...,0,None]*v+a[...,1,None]*vr
        return h+self.o(ctx)
class MLP(nn.Module):
    def __init__(self):
        super().__init__(); self.n=nn.LayerNorm(H);self.a=nn.Linear(H,FF);self.b=nn.Linear(FF,H)
    def forward(self,h): return h+0.3*self.b(F.gelu(self.a(self.n(h))))
class Block(nn.Module):
    def __init__(self): super().__init__();self.attn=Attn();self.mlp=MLP()
class Net(nn.Module):
    def __init__(self,price_visible=True):
        super().__init__();self.price_visible=price_visible;self.emb=nn.Embedding(2,H);self.pos=nn.Parameter(torch.randn(L,H)*.02);self.blocks=nn.ModuleList([Block() for _ in range(B)]);self.head=nn.Linear(H,L);self.ctrl=nn.Sequential(nn.Linear(2,32),nn.Tanh(),nn.Linear(32,NOPS))
    def base(self,x):return self.emb(x.long())+self.pos[None]
    def physical(self,x,mask):
        h=self.base(x)
        for i,b in enumerate(self.blocks):
            if mask[2*i]:h=b.attn(h)
            if mask[2*i+1]:h=b.mlp(h)
        return self.head(h[:,0])
    def dense_equiv(self,x,mask):
        h=self.base(x)
        for i,b in enumerate(self.blocks):
            a=b.attn(h)
            if mask[2*i]:h=a
            m=b.mlp(h)
            if mask[2*i+1]:h=m
        return self.head(h[:,0])
    def ctrl_logits(self,price,cap):
        p=torch.as_tensor(price,dtype=torch.float32);p=p[None] if p.ndim==0 else p
        c=torch.as_tensor(cap,dtype=torch.float32);c=c[None] if c.ndim==0 else c
        if c.numel()==1 and p.numel()>1:c=c.expand_as(p)
        z=torch.stack([torch.log1p(p),c/NOPS],1)
        if not self.price_visible:z[:,0]=0
        return self.ctrl(z)
    @torch.no_grad()
    def choose_mask(self,price,cap=8):
        logits=self.ctrl_logits(torch.tensor([price]),torch.tensor([cap]))[0]
        ids=[i for i in range(NOPS) if logits[i]>0]
        if len(ids)>cap: ids=sorted(ids,key=lambda i:float(logits[i]),reverse=True)[:cap]
        return tuple(int(i in ids) for i in range(NOPS))

def task_loss(z):return ((F.binary_cross_entropy_with_logits(z,Y,reduction='none')*TARGET_W).sum(1)/TARGET_W.sum()).mean()
def weighted_acc(z):
    p=(z>0).float();return float((((p==Y).float()*TARGET_W).sum(1)/TARGET_W.sum()).mean())
def comp(mask): return {'attn':sum(mask[0::2]),'mlp':sum(mask[1::2]),'ops':sum(mask)}

def train(seed,price_visible=True,steps=2600):
    torch.manual_seed(seed);random.seed(seed);m=Net(price_visible);cap_params=[p for n,p in m.named_parameters() if not n.startswith('ctrl.')];opt=torch.optim.AdamW(cap_params,lr=2e-3,weight_decay=1e-5)
    for st in range(steps):
        if st%5==0: mask=(1,)*NOPS
        else:
            p=random.choice([.25,.5,.75]);mask=tuple(int(random.random()<p) for _ in range(NOPS))
        z=m.physical(X,mask);l=task_loss(z);opt.zero_grad();l.backward();torch.nn.utils.clip_grad_norm_(cap_params,5);opt.step()
    rows=[]
    with torch.no_grad():
        for mask in MASKS:
            z=m.physical(X,mask);rows.append({'mask':mask,'ce':float(task_loss(z)),'acc':weighted_acc(z),'ops':sum(mask),'attn':sum(mask[0::2]),'mlp':sum(mask[1::2])})
    pp=[];cc=[];targets=[]
    for cap in range(NOPS+1):
        for i in range(401):
            price=1.6*i/400
            allowed=[r for r in rows if r['ops']<=cap]
            best=min(allowed,key=lambda r:r['ce']+price*r['ops']/NOPS)
            pp.append(price);cc.append(cap);targets.append(best['mask'])
    pp=torch.tensor(pp);cc=torch.tensor(cc);targets=torch.tensor(targets,dtype=torch.float32)
    optc=torch.optim.AdamW(m.ctrl.parameters(),lr=5e-3)
    for _ in range(4000):
        logit=m.ctrl_logits(pp,cc);loss=F.binary_cross_entropy_with_logits(logit,targets);optc.zero_grad();loss.backward();optc.step()
    return m.eval(),rows

def audit(seed,mode='aware',steps=2600,timing_reps=80):
    m,rows=train(seed,mode=='aware',steps)
    def oracle(price,cap):return min([r for r in rows if r['ops']<=cap],key=lambda r:r['ce']+price*r['ops']/NOPS)
    sweep={};agree=0
    with torch.no_grad():
        for p in PRICES:
            mask=m.choose_mask(p,8);z=m.physical(X,mask);o=oracle(p,8);agree+=int(mask==o['mask']);sweep[str(p)]={'mask':list(mask),'composition':comp(mask),'accuracy':weighted_acc(z),'oracle_mask':list(o['mask']),'oracle_composition':{'attn':o['attn'],'mlp':o['mlp'],'ops':o['ops']}}
    capcheck=[]
    for cap in CAPS:
        for p in [.05,.2,.5,.8,1.2]:
            mask=m.choose_mask(p,cap);capcheck.append({'cap':cap,'price':p,'mask':list(mask),'ops':sum(mask),'within_cap':sum(mask)<=cap})
    out={'seed':seed,'mode':mode,'full_accuracy':next(r['acc'] for r in rows if r['mask']==(1,)*NOPS),'price_sweep':sweep,'oracle_agreement':{'count':agree,'total':len(PRICES)},'hard_cap_audit':capcheck}
    if mode=='aware':
        rng=random.Random(100+seed);tim={};mismatch=0;md=0.;hooks=[]
        for p in PRICES:
            mask=m.choose_mask(p,8);hard=[];dense=[]
            for _ in range(10):
                j=rng.randrange(len(X));m.physical(X[j:j+1],mask);m.dense_equiv(X[j:j+1],mask)
            for _ in range(timing_reps):
                j=rng.randrange(len(X));t=time.perf_counter_ns();a=m.physical(X[j:j+1],mask);hard.append((time.perf_counter_ns()-t)/1000);t=time.perf_counter_ns();b=m.dense_equiv(X[j:j+1],mask);dense.append((time.perf_counter_ns()-t)/1000);mismatch+=int(int(a.argmax(1))!=int(b.argmax(1)));md=max(md,float((a-b).abs().max().detach()))
            tim[str(p)]={'composition':comp(mask),'hard_median_us':statistics.median(hard),'dense_median_us':statistics.median(dense)}
        j=17
        for p in [0,.1,.2,.5,.8,1.5]:
            hits=[];hs=[]
            for bi,b in enumerate(m.blocks):
                hs.append(b.attn.register_forward_hook(lambda mod,inp,out,bi=bi:hits.append(f'A{bi}')));hs.append(b.mlp.register_forward_hook(lambda mod,inp,out,bi=bi:hits.append(f'M{bi}')))
            mask=m.choose_mask(p,8)
            try:m.physical(X[j:j+1],mask)
            finally:[h.remove() for h in hs]
            hooks.append({'price':p,'mask':list(mask),'hook_trace':hits})
        out['timing']=tim;out['dense_equivalence']={'prediction_mismatches':mismatch,'max_logit_abs_diff':md};out['same_input_hooks']=hooks
    return out

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--seed',type=int,default=0);ap.add_argument('--mode',choices=['aware','blind'],default='aware');ap.add_argument('--steps',type=int,default=2600);ap.add_argument('--timing-reps',type=int,default=80);ap.add_argument('--out');a=ap.parse_args();r=audit(a.seed,a.mode,a.steps,a.timing_reps)
    if a.out:Path(a.out).write_text(json.dumps(r,indent=2))
    print(json.dumps(r,indent=2))
if __name__=='__main__':main()
