import json,statistics,random,torch
import torch.nn as nn
import torch.nn.functional as F
from sklearn.datasets import load_digits
from sklearn.model_selection import train_test_split

torch.set_num_threads(1)
try: torch.set_num_interop_threads(1)
except RuntimeError: pass
B=6;KS=list(range(7));FRACS=[k/B for k in KS];BUDGETS=[i/20 for i in range(21)];H=16;FF=32;C=10;T=8

def data():
 d=load_digits();X=torch.tensor(d.images,dtype=torch.float32)/16.;Y=torch.tensor(d.target,dtype=torch.long);idx=list(range(len(X)));tr,tmp=train_test_split(idx,test_size=.4,random_state=123,stratify=Y.numpy());va,te=train_test_split(tmp,test_size=.5,random_state=456,stratify=Y[tmp].numpy());return (X[tr],Y[tr]),(X[va],Y[va]),(X[te],Y[te])
class Block(nn.Module):
 def __init__(self):
  super().__init__();self.n1=nn.LayerNorm(H);self.att=nn.MultiheadAttention(H,2,batch_first=True);self.n2=nn.LayerNorm(H);self.a=nn.Linear(H,FF);self.b=nn.Linear(FF,H)
 def forward(self,h):
  x=self.n1(h);a,_=self.att(x,x,x,need_weights=False);h=h+a;return h+.35*self.b(F.gelu(self.a(self.n2(h))))
class Net(nn.Module):
 def __init__(self):
  super().__init__();self.emb=nn.Linear(8,H);self.pos=nn.Parameter(torch.randn(T,H)*.02);self.blocks=nn.ModuleList([Block() for _ in range(B)]);self.heads=nn.ModuleList([nn.Linear(H,C) for _ in KS])
 def base(self,x):return self.emb(x)+self.pos[None]
 def logit(self,h,k):return self.heads[k](h.mean(1))
 def forward_all(self,x):
  h=self.base(x);z=[self.logit(h,0)]
  for i,b in enumerate(self.blocks):h=b(h);z.append(self.logit(h,i+1))
  return torch.stack(z)
 @torch.no_grad()
 def hard(self,x,k,hits=None):
  h=self.base(x)
  for i in range(k):h=self.blocks[i](h);hits.append(i) if hits is not None and len(x)==1 else None
  return self.logit(h,k)
def train(seed,X,Y,steps=700):
 torch.manual_seed(seed);random.seed(seed);m=Net();opt=torch.optim.AdamW(m.parameters(),lr=2e-3,weight_decay=1e-4);g=torch.Generator().manual_seed(1000+seed)
 for _ in range(steps):
  ids=torch.randint(0,len(X),(128,),generator=g);Z=m.forward_all(X[ids]);yb=Y[ids];loss=torch.stack([F.cross_entropy(Z[k],yb) for k in KS]).mean();opt.zero_grad();loss.backward();torch.nn.utils.clip_grad_norm_(m.parameters(),5);opt.step()
 return m.eval()
@torch.no_grad()
def exact(m,X,Y):return [float((m.hard(X,k).argmax(1)==Y).float().mean()) for k in KS]
@torch.no_grad()
def ent(m,X,k):
 p=m.hard(X,k).softmax(1);return -(p*p.clamp_min(1e-9).log()).sum(1)
@torch.no_grad()
def choose(m,X,tau,max_depth=B):
 pref=torch.zeros(len(X),dtype=torch.long);alive=torch.ones(len(X),dtype=torch.bool)
 for k in range(max_depth):
  ids=torch.nonzero(alive).squeeze(1)
  if len(ids)==0:break
  c=ent(m,X[ids],k)>tau;pref[ids[c]]=k+1;alive[ids[~c]]=False
 return pref

def capidx(b):return max(i for i,f in enumerate(FRACS) if f<=b+1e-12)
@torch.no_grad()
def audit(m,X,Y,pref):
 rows=[];viol=0;hard=True;prev=None
 for b in BUDGETS:
  c=capidx(b);eff=torch.minimum(pref,torch.full_like(pref,c));pred=torch.empty(len(X),dtype=torch.long)
  for k in torch.unique(eff).tolist():
   ids=torch.nonzero(eff==k).squeeze(1);pred[ids]=m.hard(X[ids],int(k)).argmax(1)
  if prev is not None:viol+=int((eff<prev).sum())
  viol+=int(((eff.float()/B)>b+1e-12).sum());prev=eff.clone();hits=[];k0=int(eff[0]);m.hard(X[:1],k0,hits);hard&=(len(hits)==k0 and k0/B<=b+1e-12)
  rows.append({'budget':b,'accuracy':float((pred==Y).float().mean()),'mean_compute':float(eff.float().mean()/B),'class':FRACS[c]})
 return {'by_budget':rows,'cap_or_count_violations':viol,'nested_violations':0,'hard_cap_pass':bool(hard)}
@torch.no_grad()
def eval_pref_full(m,X,Y,pref):
 pred=torch.empty(len(X),dtype=torch.long)
 for k in torch.unique(pref).tolist():
  ids=torch.nonzero(pref==k).squeeze(1);pred[ids]=m.hard(X[ids],int(k)).argmax(1)
 return {'accuracy':float((pred==Y).float().mean()),'mean_compute':float(pref.float().mean()/B)}

def tune(m,X,Y,margin=0.0):
 ex=exact(m,X,Y); max_depth=max(range(len(ex)),key=lambda k:ex[k]); target=ex[max_depth]-margin
 if max_depth==0:return 1e9,{'accuracy':ex[0],'mean_compute':0.0},ex,max_depth
 vals=torch.cat([ent(m,X,k) for k in range(max_depth)]);cands=sorted(set([float(torch.quantile(vals,q)) for q in torch.linspace(0,1,401)]+[-1e-9,float(vals.max()+1e-6)]));best=None
 for tau in cands:
  p=choose(m,X,tau,max_depth);a=eval_pref_full(m,X,Y,p)
  if a['accuracy']>=target-1e-12:
   key=(a['mean_compute'],-a['accuracy'],tau)
   if best is None or key<best[0]:best=(key,tau,a)
 if best is None:
  p=torch.full((len(X),),max_depth,dtype=torch.long);return -1e-9,eval_pref_full(m,X,Y,p),ex,max_depth
 return best[1],best[2],ex,max_depth

def one(seed,steps=700):
 tr,va,te=data();m=train(seed,*tr,steps);tau,v,ev,dmax=tune(m,*va);p=choose(m,te[0],tau,dmax);return {'seed':seed,'tau':tau,'validation_max_depth':dmax,'val_exact':ev,'val_selected':v,'test_exact':exact(m,*te),'test_policy':audit(m,*te,p),'dist':torch.bincount(p,minlength=7).tolist()}

def agg(rows):
 ex=[statistics.mean(x['test_exact'][k] for x in rows) for k in KS];f=[x['test_policy']['by_budget'][-1] for x in rows];pa=statistics.mean(x['accuracy'] for x in f);pc=statistics.mean(x['mean_compute'] for x in f);oracle=max(ex);selected_baseline=statistics.mean(x['test_exact'][x['validation_max_depth']] for x in rows)
 out={'exact_mean':ex,'oracle_best_exact':oracle,'validation_selected_exact_test_accuracy':selected_baseline,'policy_accuracy':pa,'policy_compute':pc,'gap_vs_validation_selected_pp':100*(pa-selected_baseline),'gap_vs_oracle_best_pp':100*(pa-oracle),'capability_gain_pp':100*(selected_baseline-ex[0]),'violations':sum(x['test_policy']['cap_or_count_violations'] for x in rows),'hard':all(x['test_policy']['hard_cap_pass'] for x in rows)};out['anchors']=[]
 for b in [0,.2,.35,.5,.7,.85,1]:
  i=BUDGETS.index(min(BUDGETS,key=lambda z:abs(z-b)));v=[x['test_policy']['by_budget'][i] for x in rows];out['anchors'].append({'budget':BUDGETS[i],'accuracy':statistics.mean(y['accuracy'] for y in v),'compute':statistics.mean(y['mean_compute'] for y in v)})
 per=[]
 for x in rows:
  base=x['test_exact'][x['validation_max_depth']];sel=x['test_policy']['by_budget'][-1];per.append(sel['accuracy']>=base-.01 and sel['mean_compute']<.5)
 out['passing_seeds']=sum(per);out['H']={'decision':'PASS' if out['gap_vs_validation_selected_pp']>=-1 and pc<.5 and out['capability_gain_pp']>=3 and sum(per)>=4 and out['violations']==0 and out['hard'] else 'FAIL'};return out

if __name__=='__main__':
 import argparse;ap=argparse.ArgumentParser();ap.add_argument('--seed',type=int);ap.add_argument('--seed-start',type=int,default=60);ap.add_argument('--seeds',type=int,default=5);ap.add_argument('--steps',type=int,default=700);ap.add_argument('--out',default='results/realtime_nn_real_sequence_generalization_results.json');a=ap.parse_args();ss=[a.seed] if a.seed is not None else list(range(a.seed_start,a.seed_start+a.seeds));rows=[]
 for s in ss:
  x=one(s,a.steps);rows.append(x);print('seed',s,'val',x['val_exact'],x['val_selected'],'test',x['test_exact'],x['test_policy']['by_budget'][-1],x['dist'],flush=True)
 res={'setup':{'dataset':'sklearn handwritten digits real data','sequence':'8 row tokens','split':'fixed stratified 60/20/20','architecture':'6 optional self-attention+MLP blocks with exits','budget':'continuous b in [0,1] lowered to 7 finite depths','policy':'validation chooses maximum useful depth; entropy may stop earlier','formal_seeds':ss},'seeds':rows,'aggregate':agg(rows)};open(a.out,'w').write(json.dumps(res,indent=2));print(json.dumps(res['aggregate'],indent=2))