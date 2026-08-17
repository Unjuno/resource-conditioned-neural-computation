import json,os,random,time,statistics,math
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
import torch, torch.nn.functional as F
import sys
sys.path.insert(0,str(Path(__file__).resolve().parent))
import realtime_nn_budget_execution as b

ALL=list(range(9))
BAYES=[0.63671875,0.63671875,0.71484375,0.71484375,0.78515625,0.78515625,0.86328125,0.86328125,1.0]

def all_outputs(m,x):
    h=m.emb(x); out=[m.head(h[:,0])]
    for blk in m.blocks:
        h=blk(h); out.append(m.head(h[:,0]))
    return out

def train(seed,steps=180):
    torch.manual_seed(seed); random.seed(seed); m=b.RealTimeBudgetNN(); opt=torch.optim.AdamW(m.parameters(),lr=3e-3,weight_decay=1e-6)
    w=torch.tensor([.06,.06,.08,.08,.10,.10,.12,.12,.28])
    for _ in range(steps):
        outs=all_outputs(m,b.X); loss=sum(float(w[d])*F.cross_entropy(outs[d],b.Y) for d in ALL)
        opt.zero_grad();loss.backward();opt.step()
    return m.eval()

@torch.no_grad()
def infer(m,x,d):
    h=m.emb(x)
    for i in range(d):h=m.blocks[i](h)
    return m.head(h[:,0])

def latency(m,d,reps=100):
    x=b.X[:1];v=[]
    with torch.inference_mode():
        for _ in range(70):infer(m,x,d)
        for _ in range(reps):
            t=time.perf_counter_ns();infer(m,x,d);v.append((time.perf_counter_ns()-t)/1000.)
    v.sort();return {'median_us':statistics.median(v),'p95_us':v[math.ceil(.95*len(v))-1]}

def run(seed):
    m=train(seed);acc={};tim={}
    with torch.inference_mode():
        for d in ALL:acc[str(d)]=float((infer(m,b.X,d).argmax(1)==b.Y).float().mean())
    for d in ALL:tim[str(d)]=latency(m,d)
    return {'seed':seed,'accuracy':acc,'timing':tim,'checks':{
        'accuracy_nondecreasing':all(acc[str(d)]<=acc[str(d+1)]+1e-12 for d in range(8)),
        'median_latency_strictly_increasing':all(tim[str(d)]['median_us']<tim[str(d+1)]['median_us'] for d in range(8)),
        'all_classes_near_bayes':all(acc[str(d)]>=BAYES[d]-.01 for d in ALL)}}

@torch.no_grad()
def posthoc_control(seed):
    m=b.train(seed); acc={}
    for d in ALL: acc[str(d)]=float((infer(m,b.X,d).argmax(1)==b.Y).float().mean())
    return {'seed':seed,'accuracy':acc}

def main():
    import argparse
    ap=argparse.ArgumentParser();ap.add_argument('--seed',type=int);a=ap.parse_args()
    try:os.sched_setaffinity(0,{min(os.sched_getaffinity(0))})
    except:pass
    seeds=[a.seed] if a.seed is not None else list(range(3));rows=[];post=[]
    for s in seeds:
        r=run(s);rows.append(r);post.append(posthoc_control(s));print('seed',s,r['checks'],r['accuracy'],flush=True)
    agg={'accuracy':{str(d):statistics.mean(r['accuracy'][str(d)] for r in rows) for d in ALL},
         'median_us':{str(d):statistics.mean(r['timing'][str(d)]['median_us'] for r in rows) for d in ALL},
         'all_seeds_accuracy_nondecreasing':all(r['checks']['accuracy_nondecreasing'] for r in rows),
         'all_seeds_latency_increasing':all(r['checks']['median_latency_strictly_increasing'] for r in rows),
         'all_seeds_near_bayes':all(r['checks']['all_classes_near_bayes'] for r in rows)}
    postagg={'mean_accuracy':{str(d):statistics.mean(r['accuracy'][str(d)] for r in post) for d in ALL},'all_odd_depths_nondegrading':all(all(r['accuracy'][str(d)]>=r['accuracy'][str(d-1)] for d in [1,3,5,7]) for r in post)}
    out={'setup':{'task':'9-bit majority complete domain','classes':'all depths 0..8 trained jointly','posthoc_control':'original direct model trained only at 0/2/4/6/8 then evaluated at all depths','purpose':'execution-class granularity / capability audit','boundary':'Linux/PyTorch central timing; not WCET'},'fine_grained':{'seeds':rows,'aggregate':agg},'posthoc_control':{'seeds':post,'aggregate':postagg}}
    op=str(ROOT/'results'/'realtime_nn_fine_grained_classes_results.json') if a.seed is None else str(ROOT/'results'/f'realtime_nn_fine_grained_seed{a.seed}.json');Path(op).write_text(json.dumps(out,indent=2));print(json.dumps(agg,indent=2))
if __name__=='__main__':main()
