import importlib.util,json,statistics,torch
from pathlib import Path
BASE = Path(__file__).resolve().parent
spec=importlib.util.spec_from_file_location('m',str(BASE/'price_mask_conformal_multiseed.py'));m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)

@torch.no_grad()
def ev(router,C,router_price,actual_price,N=3000):
    mask=torch.ones(1,2);rp=torch.tensor([router_price],dtype=torch.float);ap=torch.tensor(actual_price,dtype=torch.float)
    # deterministic router here, so histogram is stable; still sample to match interface
    j=int(router.choose(rp,mask)[0]);cost=float((ap*C[j]).sum())
    return {'route':j,'hist':[1.0 if q==j else 0.0 for q in range(2)],'resource_cost':cost}

def main():
    rows=[]
    envs={'compute_expensive':[1.,.05],'footprint_expensive':[.05,1.]}
    for seed in [0,1,2]:
        lookup=m.Lookup().eval();algo=m.train_algo(seed);C,_=m.expert_costs(lookup,algo);r=m.train_router(seed,C,True)
        for name,p in envs.items():
            other=envs['footprint_expensive' if name=='compute_expensive' else 'compute_expensive']
            for signal,rp in [('true',p),('swapped',other),('constant',[.1,.1])]:
                rows.append({'seed':seed,'env':name,'signal':signal,**ev(r,C,rp,p)})
    summary={}
    for env in envs:
        for sig in ['true','swapped','constant']:
            rs=[z for z in rows if z['env']==env and z['signal']==sig]
            summary[f'{env}|{sig}']={'mean_cost':statistics.mean(z['resource_cost'] for z in rs),'routes':[z['route'] for z in rs]}
    out_path = BASE.parent / 'results' / 'price_negative_control_results.json'
    out_path.parent.mkdir(parents=True, exist_ok=True)
    json.dump({'rows':rows,'summary':summary},open(out_path,'w'),indent=2)
    print(json.dumps(summary,indent=2))
if __name__=='__main__':main()
