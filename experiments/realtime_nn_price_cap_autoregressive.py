import argparse, itertools, json, math, random, statistics, time
from pathlib import Path
import torch
import torch.nn as nn
import torch.nn.functional as F

torch.set_num_threads(1)
try: torch.set_num_interop_threads(1)
except RuntimeError: pass

PROMPT=4; OUT=4; T=8; H=24; FF=48; BLOCKS=6; DEPTHS=[0,2,4,6]
PRICES=[0.,.1,.2,.3,.4,.5,.8,1.0,1.3,1.5,2.0]
UTILITY=torch.tensor([1.0,.8,.5,.2])
PROMPTS=torch.tensor(list(itertools.product([0,1], repeat=PROMPT)),dtype=torch.long)
SEQ=torch.cat([PROMPTS,torch.flip(PROMPTS,[1])],1)
POS=torch.tensor([3,4,5,6])

class CausalLocalBlock(nn.Module):
    def __init__(self):
        super().__init__(); self.n1=nn.LayerNorm(H); self.q=nn.Linear(H,H); self.k=nn.Linear(H,H); self.v=nn.Linear(H,H); self.o=nn.Linear(H,H); self.n2=nn.LayerNorm(H); self.a=nn.Linear(H,FF); self.b=nn.Linear(FF,H)
    def forward(self,h):
        x=self.n1(h);q=self.q(x);k=self.k(x);v=self.v(x)
        kp=torch.cat([k[:,:1],k[:,:-1]],1);vp=torch.cat([v[:,:1],v[:,:-1]],1)
        sc=torch.stack([(q*k).sum(-1),(q*kp).sum(-1)],-1)/math.sqrt(H);att=torch.softmax(sc,-1);ctx=att[...,0,None]*v+att[...,1,None]*vp
        h=h+self.o(ctx); return h+0.25*self.b(F.gelu(self.a(self.n2(h))))

class TinyRealtimeAutoreg(nn.Module):
    def __init__(self,price_visible=True):
        super().__init__(); self.price_visible=price_visible
        self.emb=nn.Embedding(2,H); self.pos=nn.Parameter(torch.randn(T,H)*.02); self.blocks=nn.ModuleList([CausalLocalBlock() for _ in range(BLOCKS)]); self.head=nn.Linear(H,2); self.controller=nn.Sequential(nn.Linear(2,24),nn.Tanh(),nn.Linear(24,len(DEPTHS)))
    def base(self,x): return self.emb(x)+self.pos[:x.shape[1]][None]
    def logits_depth(self,x,d):
        h=self.base(x)
        for i in range(d): h=self.blocks[i](h)
        return self.head(h)
    def dense_equiv_logits(self,x,d):
        h=self.base(x); chosen=h if d==0 else None
        for i,b in enumerate(self.blocks,1):
            h=b(h)
            if i==d: chosen=h
        return self.head(chosen)
    def all_depth_logits(self,x): return torch.stack([self.logits_depth(x,d) for d in DEPTHS],1)
    def controller_logits(self,price,cap):
        p=torch.as_tensor(price,dtype=torch.float32);p=p[None] if p.ndim==0 else p
        c=torch.as_tensor(cap,dtype=torch.float32);c=c[None] if c.ndim==0 else c
        if c.numel()==1 and p.numel()>1:c=c.expand_as(p)
        inp=torch.stack([torch.log1p(p),c/BLOCKS],1)
        if not self.price_visible: inp[:,0]=0
        return self.controller(inp)
    @torch.no_grad()
    def choose_depth(self,price,cap=6):
        z=self.controller_logits(torch.tensor([price]),torch.tensor([cap]))[0].clone()
        for i,d in enumerate(DEPTHS):
            if d>cap: z[i]=-1e9
        return DEPTHS[int(z.argmax())]

def per_position_ce(z):
    return F.cross_entropy(z[:,POS].reshape(-1,2),SEQ[:,POS+1].reshape(-1),reduction='none').view(len(SEQ),OUT).mean(0)
def mean_ce(z): return per_position_ce(z).mean()
def raw_teacher_acc(z): return float((z[:,POS].argmax(-1)==SEQ[:,POS+1]).float().mean())
def discounted_teacher_acc(z):
    hit=(z[:,POS].argmax(-1)==SEQ[:,POS+1]).float(); return float((hit*UTILITY[None]).sum()/(len(SEQ)*UTILITY.sum()))

def train(seed,price_visible=True,steps=900):
    torch.manual_seed(seed);random.seed(seed);m=TinyRealtimeAutoreg(price_visible);capparams=[p for n,p in m.named_parameters() if not n.startswith('controller.')];opt=torch.optim.AdamW(capparams,lr=2e-3,weight_decay=1e-5)
    for _ in range(steps):
        z=m.all_depth_logits(SEQ);loss=sum(mean_ce(z[:,i]) for i in range(len(DEPTHS)))/len(DEPTHS);opt.zero_grad();loss.backward();torch.nn.utils.clip_grad_norm_(capparams,5);opt.step()
    with torch.no_grad():
        z=m.all_depth_logits(SEQ); util_ce=[]
        for i in range(len(DEPTHS)):
            c=per_position_ce(z[:,i]); util_ce.append(float((c*UTILITY).sum()/UTILITY.sum()))
        util_ce=torch.tensor(util_ce); d=torch.tensor(DEPTHS,dtype=torch.float32);prices=torch.linspace(0,2,401);pp=[];cc=[];tt=[]
        for cap in DEPTHS:
            energy=util_ce[None,:]+prices[:,None]*d[None,:]/BLOCKS;energy[:,d>cap]=1e6;pp.append(prices);cc.append(torch.full_like(prices,float(cap)));tt.append(energy.argmin(1))
        pp=torch.cat(pp);cc=torch.cat(cc);tt=torch.cat(tt)
    optc=torch.optim.AdamW(m.controller.parameters(),lr=5e-3)
    for _ in range(1000):
        loss=F.cross_entropy(m.controller_logits(pp,cc),tt);optc.zero_grad();loss.backward();optc.step()
    return m.eval(),util_ce

@torch.no_grad()
def generate_one(m,prompt,d,dense=False):
    seq=prompt.tolist(); target=list(reversed(seq));gen=[];times=[]
    for _ in range(OUT):
        x=torch.tensor([seq],dtype=torch.long);t=time.perf_counter_ns();z=m.dense_equiv_logits(x,d) if dense else m.logits_depth(x,d);times.append((time.perf_counter_ns()-t)/1000.0);tok=int(z[0,-1].argmax());seq.append(tok);gen.append(tok)
    return gen,target,times

@torch.no_grad()
def generation_audit(m,d,dense=False,repeats=3):
    token=exact=0;step=[];total=[]
    for p in PROMPTS:
        gen,tgt,_=generate_one(m,p,d,dense);token+=sum(a==b for a,b in zip(gen,tgt));exact+=int(gen==tgt)
    for _ in range(repeats):
        for p in PROMPTS:
            t0=time.perf_counter_ns();_,_,ts=generate_one(m,p,d,dense);total.append((time.perf_counter_ns()-t0)/1000.0);step.extend(ts)
    return {'token_accuracy':token/(len(PROMPTS)*OUT),'exact_sequence_rate':exact/len(PROMPTS),'median_per_token_us':statistics.median(step),'median_generation_us':statistics.median(total)}

def run(seed,mode='aware',steps=900):
    m,util_ce=train(seed,mode=='aware',steps)
    with torch.no_grad(): z=m.all_depth_logits(SEQ)
    fixed={}
    for i,d in enumerate(DEPTHS):
        hard=generation_audit(m,d,False); dense=generation_audit(m,d,True)
        fixed[str(d)]={'teacher_token_accuracy':raw_teacher_acc(z[:,i]),'discounted_teacher_accuracy':discounted_teacher_acc(z[:,i]),'equal_token_ce':float(mean_ce(z[:,i])),'discounted_ce':float(util_ce[i]),**hard,'dense_median_per_token_us':dense['median_per_token_us'],'dense_median_generation_us':dense['median_generation_us']}
    sweep={};oracle=[];agree=0
    for p in PRICES:
        d=m.choose_depth(p,6); g=generation_audit(m,d); energy=[float(util_ce[i]+p*DEPTHS[i]/BLOCKS) for i in range(len(DEPTHS))]; od=DEPTHS[min(range(len(DEPTHS)),key=lambda i:energy[i])];agree+=int(d==od);oracle.append({'price':p,'oracle_depth':od,'chosen_depth':d});sweep[str(p)]={'depth':d,**g,'dense_median_per_token_us':fixed[str(d)]['dense_median_per_token_us'],'dense_median_generation_us':fixed[str(d)]['dense_median_generation_us']}
    caps=[]
    for cap in DEPTHS:
        for p in [.1,.3,.6,1.0,1.5]:
            d=m.choose_depth(p,cap);caps.append({'cap':cap,'price':p,'depth':d,'within_cap':d<=cap})
    out={'seed':seed,'mode':mode,'fixed_depth':fixed,'price_sweep':sweep,'loss_oracle':{'agreement_count':agree,'total':len(PRICES),'rows':oracle},'hard_cap_audit':caps}
    if mode=='aware':
        mismatch=0; hooks=[]
        with torch.no_grad():
            for p in [0,.2,.4,.5,.8,1.3]:
                d=m.choose_depth(p,6)
                for prompt in PROMPTS:
                    a,_,_=generate_one(m,prompt,d,False);b,_,_=generate_one(m,prompt,d,True);mismatch+=int(a!=b)
            prompt=PROMPTS[11]
            for p in [0,.2,.4,.5,.8,1.3]:
                d=m.choose_depth(p,6);hits=[];hs=[b.register_forward_hook(lambda mod,inp,out,j=j:hits.append(j)) for j,b in enumerate(m.blocks)]
                try: gen,tgt,_=generate_one(m,prompt,d,False)
                finally:
                    for h in hs:h.remove()
                hooks.append({'price':p,'depth':d,'hook_calls':len(hits),'expected_hook_calls':d*OUT,'generated':gen,'target':tgt})
        out['dense_equivalence']={'generation_mismatches':mismatch,'cases':len(PROMPTS)*6}
        out['same_prompt_counterfactual']=hooks
    return out

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--seed',type=int,default=0);ap.add_argument('--mode',choices=['aware','blind'],default='aware');ap.add_argument('--steps',type=int,default=900);ap.add_argument('--out');a=ap.parse_args();r=run(a.seed,a.mode,a.steps)
    if a.out:Path(a.out).write_text(json.dumps(r,indent=2))
    print(json.dumps(r,indent=2))
if __name__=='__main__':main()
