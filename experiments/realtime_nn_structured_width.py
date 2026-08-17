import argparse, array, json, math, random, statistics, struct, time
from pathlib import Path
import torch
import torch.nn as nn
import torch.nn.functional as F

torch.set_num_threads(1)
try: torch.set_num_interop_threads(1)
except RuntimeError: pass

L=9; N=1<<L; C=32; K=8
CLASSES=[(0,8),(2,8),(4,16),(6,24),(8,32)]
IDX=torch.arange(N,dtype=torch.long); SH=torch.arange(L,dtype=torch.long)
X=((IDX[:,None]>>SH)&1).long(); Y=(X.sum(1)>=5).long()

class SlimBlock(nn.Module):
    def __init__(self):
        super().__init__()
        self.sw=nn.Parameter(torch.empty(C,C)); self.sb=nn.Parameter(torch.zeros(C))
        self.nw=nn.Parameter(torch.empty(C,C)); self.nb=nn.Parameter(torch.zeros(C))
        self.f1w=nn.Parameter(torch.empty(4*C,C)); self.f1b=nn.Parameter(torch.zeros(4*C))
        self.f2w=nn.Parameter(torch.empty(C,4*C)); self.f2b=nn.Parameter(torch.zeros(C))
        for p in (self.sw,self.nw,self.f1w,self.f2w): nn.init.kaiming_uniform_(p,a=math.sqrt(5))
    def forward_width(self,h,w):
        nb=torch.zeros_like(h); nb[:,:-1]=h[:,1:]
        z=torch.tanh(F.linear(h,self.sw[:w,:w],self.sb[:w])+F.linear(nb,self.nw[:w,:w],self.nb[:w]))
        f=F.gelu(F.linear(z,self.f1w[:4*w,:w],self.f1b[:4*w]))
        f=F.linear(f,self.f2w[:w,:4*w],self.f2b[:w])
        return torch.tanh(z+0.2*f)

class StructuredWidthRTNN(nn.Module):
    def __init__(self):
        super().__init__(); self.emb=nn.Embedding(2,C); self.blocks=nn.ModuleList([SlimBlock() for _ in range(K)])
        self.hw=nn.Parameter(torch.empty(2,C)); self.hb=nn.Parameter(torch.zeros(2)); nn.init.kaiming_uniform_(self.hw,a=math.sqrt(5))
    def forward_class(self,x,ci):
        d,w=CLASSES[ci]; h=self.emb(x)[:,:,:w]
        for i in range(d): h=self.blocks[i].forward_width(h,w)
        return F.linear(h[:,0],self.hw[:,:w],self.hb)
    def dense_width_mask(self,x,ci):
        d,w=CLASSES[ci]; h=self.emb(x).clone(); h[:,:,w:]=0
        for i in range(d):
            q=self.blocks[i]; nb=torch.zeros_like(h); nb[:,:-1]=h[:,1:]
            z=torch.tanh(F.linear(h,q.sw,q.sb)+F.linear(nb,q.nw,q.nb)); z[:,:,w:]=0
            f=F.gelu(F.linear(z,q.f1w,q.f1b)); f[:,:,4*w:]=0
            f=F.linear(f,q.f2w,q.f2b); f[:,:,w:]=0
            h=torch.tanh(z+0.2*f); h[:,:,w:]=0
        return F.linear(h[:,0],self.hw,self.hb)

def train(seed,steps=160):
    torch.manual_seed(seed); random.seed(seed); m=StructuredWidthRTNN(); opt=torch.optim.AdamW(m.parameters(),lr=3e-3,weight_decay=1e-6)
    weights=(.08,.12,.20,.25,.35)
    for _ in range(steps):
        loss=sum(weights[i]*F.cross_entropy(m.forward_class(X,i),Y) for i in range(5))
        opt.zero_grad();loss.backward();opt.step()
    return m.eval()

def exact_macs(d,w): return d*89*w*w+2*w

def dense_macs(d): return d*89*C*C+2*C

def export_binary(m,path):
    vals=[]
    def add(t): vals.extend(t.detach().cpu().float().contiguous().view(-1).tolist())
    add(m.emb.weight)
    for q in m.blocks:
        for t in (q.sw,q.sb,q.nw,q.nb,q.f1w,q.f1b,q.f2w,q.f2b): add(t)
    add(m.hw); add(m.hb)
    with open(path,'wb') as f: f.write(struct.pack('<I',len(vals))); array.array('f',vals).tofile(f)
    return len(vals)

def time_one(m,ci,dense,reps=300):
    xx=X[341:342]; fn=m.dense_width_mask if dense else m.forward_class
    with torch.inference_mode():
        for _ in range(50): fn(xx,ci)
        v=[]
        for _ in range(reps):
            t=time.perf_counter_ns();fn(xx,ci);v.append((time.perf_counter_ns()-t)/1000)
    return statistics.median(v)

def run_seed(seed,steps,reps):
    m=train(seed,steps); acc=[]; dif=[]
    with torch.inference_mode():
        for i in range(5):
            a=m.forward_class(X,i); b=m.dense_width_mask(X,i)
            acc.append(float((a.argmax(1)==Y).float().mean())); dif.append(float((a-b).abs().max()))
    med=[time_one(m,i,False,reps) for i in range(5)]
    return {'seed':seed,'accuracy':acc,'hard_dense_output_max_abs_diff':dif,'slim_p50_us':med,'strict_slim_p50_order':all(med[i]<med[i+1] for i in range(4))}

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--seed',type=int);ap.add_argument('--seeds',type=int,default=3);ap.add_argument('--steps',type=int,default=160);ap.add_argument('--reps',type=int,default=300);ap.add_argument('--export');ap.add_argument('--out',default=str(Path(__file__).resolve().parents[1]/'results'/'realtime_nn_structured_width_results.json'));a=ap.parse_args()
    ids=[a.seed] if a.seed is not None else list(range(a.seeds)); rows=[]
    for s in ids:
        m=train(s,a.steps) if a.export and len(ids)==1 else None
        if m is not None:
            n=export_binary(m,a.export); print('exported',n,'float32 values',a.export)
        r=run_seed(s,a.steps,a.reps);rows.append(r);print('seed',s,r,flush=True)
    out={'setup':{'task':'9-bit majority complete 512-state domain','max_width':C,'classes':[{'class':i,'depth':d,'active_width':w,'slim_linear_macs':exact_macs(d,w),'dense_width_mask_linear_macs':dense_macs(d)} for i,(d,w) in enumerate(CLASSES)],'training':'all structured width/depth classes jointly trained in one maximum-width parameter set','physical_width':'slim path slices input and weight tensors before linear operations; dense control computes max width and zeros inactive channels afterward'},'python_seeds':rows}
    Path(a.out).write_text(json.dumps(out,indent=2))

if __name__=='__main__':main()
