#!/usr/bin/env python3
"""Run the frozen Q15 C core on validation/test splits and compare stop rules.

Thresholds are selected only on the reconstructed validation split. The saved
heldout360 Q15 per-exit predictions are used as an identity cross-check.
The displayed compute measure is optional-block count, not cycles.
"""
import argparse,csv,hashlib,json,math,statistics,subprocess,tempfile
from pathlib import Path

ROOT=Path(__file__).resolve().parent
PKG=ROOT.parent/"external_validation_20261122"
FROZEN=ROOT.parent/"frozen_inputs"
CORE=PKG/"firmware/model/realtime_nn_real_sequence_fixed_core.c"
WEIGHTS=PKG/"firmware/model/realtime_nn_real_sequence_fixed_weights_generated.h"
HEADER=PKG/"firmware/model/realtime_nn_real_sequence_fixed_core.h"
HARNESS=ROOT/"dump_q15_exit_metrics.c"
CORE_SHA="a6b2807bd4a60534c250fca3005322cf14ba0a92f6b16e28241109385efc6809"
WEIGHTS_SHA="961a76b7e220bf2f665e7c04ab62063600aa2e7eccf3403d80ea730bc993ad9f"
HELDOUT_SHA="eeba9000a918bcba911007e78905c5052fc743422f95cb314a0fc9f4ecdfb14c"
def sha(b):return hashlib.sha256(b).hexdigest()
def load_sets(sklearn_path):
 import sys
 sys.path.insert(0,str(sklearn_path))
 from sklearn.datasets import load_digits
 from sklearn.model_selection import train_test_split
 d=load_digits();x=d.images.reshape(-1,64).astype("uint8");y=d.target.astype(int);ix=list(range(len(x)))
 tr,tmp=train_test_split(ix,test_size=.4,random_state=123,stratify=y)
 va,te=train_test_split(tmp,test_size=.5,random_state=456,stratify=y[tmp])
 held=json.loads((FROZEN/"generated/heldout360.json").read_text(encoding="utf-8")); records=held["records"]
 if len(records)!=360 or sha((FROZEN/"generated/heldout360.json").read_bytes())!=HELDOUT_SHA:raise ValueError("frozen heldout360 identity mismatch")
 test_by={r["source_index"]:r for r in records}
 if len(test_by)!=360 or set(test_by)!=set(te):raise ValueError("reconstructed test split differs from frozen heldout split")
 for idx,r in test_by.items():
  if bytes(x[idx])!=bytes(r["pixels_u8_64"]) or int(y[idx])!=int(r["label"]):raise ValueError("heldout pixels/labels mismatch against sklearn reconstruction")
 val=[{"input_id":int(idx),"pixels":bytes(x[idx]),"label":int(y[idx])} for idx in va]
 test=[{"input_id":int(r["input_id"]),"pixels":bytes(r["pixels_u8_64"]),"label":int(r["label"])} for r in records]
 if set(i for i in tr).intersection(va) or set(i for i in tr).intersection(te) or set(va).intersection(te):raise ValueError("split overlap")
 return val,test,{"sklearn_version":__import__("sklearn").__version__,"train_count":len(tr),"validation_count":len(val),"test_count":len(test),"heldout360_sha256":HELDOUT_SHA,"split_seed_first":123,"split_seed_second":456,"split_status":"validation reconstructed; frozen test exact pixel/label membership verified"}
def parse_metrics(text,inputs):
 rows=list(csv.DictReader(text.splitlines()));
 if len(rows)!=7*len(inputs):raise ValueError("C harness did not emit seven exits per image")
 grouped={}
 for r in rows:
  iid=int(r["input_id"]);e=int(r["exit"]);key=(iid,e)
  if key in grouped or not 0<=e<=6:raise ValueError("duplicate/invalid Q15 metric row")
  c=int(r["max_probability_q15"]);m=int(r["top2_margin_q15"]);s=int(r["probability_sum_q15"])
  if not (0<=m<=c<=32768) or abs(s-32768)>8:raise ValueError("Q15 probabilities invalid or do not normalize")
  grouped[key]={"prediction":int(r["prediction"]),"maxp":c,"margin":m,"psum":s,"entropy_preferred_exit":int(r["entropy_preferred_exit"])}
 for i in range(1,len(inputs)+1):
  es=[grouped.get((i,e)) for e in range(7)]
  if any(x is None for x in es) or len({x["entropy_preferred_exit"] for x in es})!=1:raise ValueError("exit metrics missing or inconsistent")
 return grouped
def write_bin(path,items):Path(path).write_bytes(b"".join(x["pixels"] for x in items))
def run_c(zig,items,tag,out_csv):
 with tempfile.TemporaryDirectory(prefix="rtnn_q15_stopping_") as td:
  td=Path(td);exe=td/"q15_all_exit_metrics.exe";raw=td/(tag+".bin");write_bin(raw,items)
  cmd=[str(zig),"cc","-std=c11","-O2","-I",str(PKG/"firmware/model"),str(CORE),str(HARNESS),"-o",str(exe)]
  c=subprocess.run(cmd,cwd=ROOT,capture_output=True,text=True,timeout=600)
  if c.returncode:raise RuntimeError("Zig C build failed: "+c.stdout+"\n"+c.stderr)
  proc=subprocess.run([str(exe)],input=raw.read_bytes(),capture_output=True,timeout=600)
  if proc.returncode:raise RuntimeError(f"Q15 harness failed {tag} rc={proc.returncode}: {proc.stderr.decode(errors='replace')}")
  txt=proc.stdout.decode("ascii")
  Path(out_csv).write_text(txt,encoding="ascii",newline="")
  return parse_metrics(txt,items),{"command":cmd,"zig_version":subprocess.run([str(zig),"version"],capture_output=True,text=True,check=True).stdout.strip(),"compiler_sha256":sha(Path(zig).read_bytes()),"executable_sha256":sha(exe.read_bytes()),"raw_input_sha256":sha(raw.read_bytes()),"stdout_sha256":sha(proc.stdout),"exit_code":proc.returncode,"rows":7*len(items)}
def by_image(metrics,items):return {item["input_id"]:{e:metrics[(n,e)] for e in range(7)} for n,item in enumerate(items,1)}
def policy_metrics(images,items,chosen,count_checks=False):
 correct=blocks=checks=0
 for item in items:
  e=chosen[item["input_id"]];r=images[item["input_id"]][e]
  correct+=int(r["prediction"]==item["label"]);blocks+=e
  if count_checks:checks+=min(e+1,5)
 n=len(items);return {"n":n,"correct":correct,"accuracy":correct/n,"mean_optional_blocks":blocks/n,"mean_decision_checks":checks/n}
def apply_threshold(images,items,key,tau,max_exit=5):
 chosen={}
 for item in items:
  img=images[item["input_id"]];e=next((k for k in range(max_exit) if img[k][key]>=tau),max_exit);chosen[item["input_id"]]=e
 return chosen
def select_threshold(images,items,key,target,max_exit=5):
 values=sorted({images[i["input_id"]][e][key] for i in items for e in range(max_exit)})
 candidates=values+[values[-1]+1]
 feasible=[]
 for tau in candidates:
  chosen=apply_threshold(images,items,key,tau,max_exit);m=policy_metrics(images,items,chosen,True)
  if m["accuracy"]+1e-12>=target:feasible.append((m["mean_optional_blocks"],-m["accuracy"],tau,m))
 if not feasible:raise ValueError("no validation threshold reaches the validation target")
 return min(feasible,key=lambda x:(x[0],x[1],x[2]))[2:]
def fixed_choice(images,items,e):return {x["input_id"]:e for x in items}
def entropy_choice(images,items):return {x["input_id"]:images[x["input_id"]][0]["entropy_preferred_exit"] for x in items}
def oracle_choice(images,items,max_exit=5):
 out={}
 for x in items:
  img=images[x["input_id"]];out[x["input_id"]]=next((e for e in range(max_exit+1) if img[e]["prediction"]==x["label"]),max_exit)
 return out
def paired_bootstrap(images,items,chosen,reference,reps=20000,seed=20261128):
 import random
 rng=random.Random(seed);dacc=[];dblocks=[]
 for _ in range(reps):
  sa=sb=0
  for _j in items:
   item=items[rng.randrange(len(items))];iid=item["input_id"]
   a=images[iid][chosen[iid]]["prediction"];b=images[iid][reference[iid]]["prediction"]
   sa+=int(a==item["label"])-int(b==item["label"])
   sb+=chosen[iid]-reference[iid]
  dacc.append(sa/len(items));dblocks.append(sb/len(items))
 def ci(v):
  v.sort();return [v[int(.025*(len(v)-1))],v[int(.975*(len(v)-1))]]
 return {"replicates":reps,"seed":seed,"paired_accuracy_difference_method_minus_fixed2":ci(dacc),"paired_mean_optional_block_difference_method_minus_fixed2":ci(dblocks),"unit":"image resampled with replacement; no writer clustering; exploratory only"}
def main():
 ap=argparse.ArgumentParser();ap.add_argument("--zig",type=Path,required=True);ap.add_argument("--sklearn-path",type=Path,required=True);ap.add_argument("--out-dir",type=Path,required=True);a=ap.parse_args()
 if a.out_dir.exists():raise SystemExit("refusing to overwrite output directory")
 if sha(CORE.read_bytes())!=CORE_SHA or sha(WEIGHTS.read_bytes())!=WEIGHTS_SHA:raise SystemExit("frozen Q15 core/weights SHA mismatch")
 val,test,split=load_sets(a.sklearn_path)
 a.out_dir.mkdir(parents=True)
 vm,vc=run_c(a.zig,val,"validation",a.out_dir/"q15_validation_exit_metrics.csv")
 tm,tc=run_c(a.zig,test,"heldout360",a.out_dir/"q15_heldout360_exit_metrics.csv")
 vi,ti=by_image(vm,val),by_image(tm,test)
 oracle=json.loads((FROZEN/"generated/frozen_q15_oracle.json").read_text(encoding="utf-8"))["predictions"]
 mism=[]
 for iid,x in enumerate(test):
  ref=oracle[str(x["input_id"])]
  for e in range(7):
   if ti[x["input_id"]][e]["prediction"]!=ref["predictions"][e]:mism.append((x["input_id"],e))
  if ti[x["input_id"]][0]["entropy_preferred_exit"]!=ref["preferred_exit"]:mism.append((x["input_id"],"preferred"))
 if mism:raise SystemExit(f"Q15 outputs differ from frozen oracle, sample={mism[:5]}")
 val_acc={e:sum(vi[x["input_id"]][e]["prediction"]==x["label"] for x in val)/len(val) for e in range(6)}
 target=max(val_acc.values())
 conf_tau,conf_val=select_threshold(vi,val,"maxp",target)
 margin_tau,margin_val=select_threshold(vi,val,"margin",target)
 methods=[];choices={}
 for e in range(7):
  name=f"fixed_exit_{e}";cv=fixed_choice(vi,val,e);ct=fixed_choice(ti,test,e);choices[name]={"validation":cv,"heldout360":ct}
  methods.append({"method":name,"threshold":None,"validation":policy_metrics(vi,val,cv),"heldout360":policy_metrics(ti,test,ct),"tuned_on":"none"})
 for name,key,tau,mv in (("max_softmax_q15","maxp",conf_tau,conf_val),("top2_probability_margin_q15","margin",margin_tau,margin_val)):
  cv=apply_threshold(vi,val,key,tau);ct=apply_threshold(ti,test,key,tau);choices[name]={"validation":cv,"heldout360":ct}
  methods.append({"method":name,"threshold_q15":tau,"validation":policy_metrics(vi,val,cv,True),"heldout360":policy_metrics(ti,test,ct,True),"tuned_on":"validation_only"})
 cv=entropy_choice(vi,val);ct=entropy_choice(ti,test);choices["frozen_entropy_policy"]={"validation":cv,"heldout360":ct}
 methods.append({"method":"frozen_entropy_policy","threshold_q15":18520,"validation":policy_metrics(vi,val,cv,True),"heldout360":policy_metrics(ti,test,ct,True),"tuned_on":"frozen_model_policy"})
 cv=oracle_choice(vi,val);ct=oracle_choice(ti,test);choices["retrospective_oracle_first_correct"]={"validation":cv,"heldout360":ct}
 methods.append({"method":"retrospective_oracle_first_correct","threshold":None,"validation":policy_metrics(vi,val,cv),"heldout360":policy_metrics(ti,test,ct),"tuned_on":"teacher_label_hindsight_not_deployable"})
 # Validate the frozen policy ceiling against the model's recorded maximum.
 if max(x[0]["entropy_preferred_exit"] for x in ti.values())>5:raise SystemExit("entropy policy exceeded frozen max exit")
 ent=choices["frozen_entropy_policy"]["heldout360"];fx2=choices["fixed_exit_2"]["heldout360"]
 entropy_exit_hist={str(e):sum(1 for iid in ent if ent[iid]==e) for e in range(6)}
 entropy_vs_fixed2={"same_prediction_different_exit":0,"adaptive_wrong_fixed2_correct":0,"adaptive_correct_fixed2_wrong":0,"both_wrong":0,"both_correct":0}
 for item in test:
  iid=item["input_id"];ea=ti[iid][ent[iid]]["prediction"];ef=ti[iid][fx2[iid]]["prediction"];ca=ea==item["label"];cf=ef==item["label"]
  entropy_vs_fixed2["same_prediction_different_exit"]+=int(ea==ef and ent[iid]!=2)
  entropy_vs_fixed2["adaptive_wrong_fixed2_correct"]+=int(not ca and cf)
  entropy_vs_fixed2["adaptive_correct_fixed2_wrong"]+=int(ca and not cf)
  entropy_vs_fixed2["both_wrong"]+=int(not ca and not cf);entropy_vs_fixed2["both_correct"]+=int(ca and cf)
 result={"schema":"rtnn-frozen-q15-stopping-comparison-v1","classification":"OFFLINE_Q15_HELDOUT_ANALYSIS_NOT_NEW_EXTERNAL_EVALUATION","identity":{"model_id":"seed63_frozen_q15","core_sha256":CORE_SHA,"weights_header_sha256":WEIGHTS_SHA},"source":{"dataset":"sklearn.load_digits","heldout360_sha256":HELDOUT_SHA,**split},"calibration":{"validation_target_accuracy":target,"validation_accuracy_fixed_exits_0_to_5":val_acc,"max_softmax_threshold_q15":conf_tau,"max_softmax_validation":conf_val,"top2_margin_threshold_q15":margin_tau,"top2_margin_validation":margin_val,"threshold_selection":"minimum mean optional blocks subject to validation accuracy at least the best fixed exit 0..5 on validation; no heldout labels used for threshold selection"},"methods":methods,"entropy_vs_fixed2_heldout360":{"executed_exit_histogram":entropy_exit_hist,**entropy_vs_fixed2},"paired_input_bootstrap_vs_fixed2":{"heldout360":{m["method"]:paired_bootstrap(ti,test,choices[m["method"]]["heldout360"],choices["fixed_exit_2"]["heldout360"]) for m in methods if m["method"] in ("frozen_entropy_policy","max_softmax_q15","top2_probability_margin_q15")}},"crosscheck":{"heldout_all_exit_prediction_mismatches_vs_frozen_q15_oracle":0,"entropy_preferred_exit_mismatches":0,"q15_probability_sum_tolerance_units":8},"timing_scope":"CPU Q15 arithmetic is evaluated as optional-block count; decision-check count is reported only for adaptive decision policies. No cycle, energy, WCET, or FPGA timing inference.","limits":["This is the previously held-out sklearn test split, not the new UCI optdigits primary set.","Confidence/margin analysis helper computes Q15 probabilities from the frozen exp LUT and integer divider; it is analysis-only and does not alter deployed firmware.","Oracle uses held-out teacher labels and is an unattainable retrospective lower-work reference.","Cycle costs and decision-rule instruction overhead are not measured by this analysis.","Image bootstrap assumes exchangeable independent rows and cannot account for unknown writer clusters."]}
 (a.out_dir/"STOPPING_COMPARISON.json").write_text(json.dumps(result,indent=2)+"\n",encoding="utf-8",newline="")
 with (a.out_dir/"STOPPING_COMPARISON.csv").open("w",encoding="utf-8",newline="") as f:
  w=csv.writer(f,lineterminator="\n");w.writerow(["method","split","n","correct","accuracy","mean_optional_blocks","mean_decision_checks","threshold_q15"])
  for m in methods:
   for split_name in ("validation","heldout360"):
    x=m[split_name];w.writerow([m["method"],split_name,x["n"],x["correct"],f"{x['accuracy']:.8f}",f"{x['mean_optional_blocks']:.8f}",f"{x['mean_decision_checks']:.8f}",m.get("threshold_q15","")])
 with (a.out_dir/"STOPPING_PER_IMAGE.csv").open("w",encoding="utf-8",newline="") as f:
  w=csv.writer(f,lineterminator="\n");w.writerow(["split","input_id","label","method","executed_exit","prediction","correct","max_probability_q15","top2_margin_q15"])
  for split_name,items,images in (("validation",val,vi),("heldout360",test,ti)):
   for item in items:
    iid=item["input_id"]
    for m in methods:
     e=choices[m["method"]][split_name][iid];r=images[iid][e]
     w.writerow([split_name,iid,item["label"],m["method"],e,r["prediction"],int(r["prediction"]==item["label"]),r["maxp"],r["margin"]])
 with (a.out_dir/"ENTROPY_VS_FIXED2_HELDOUT360.csv").open("w",encoding="utf-8",newline="") as f:
  w=csv.writer(f,lineterminator="\n");w.writerow(["input_id","label","entropy_exit","entropy_prediction","entropy_correct","fixed2_prediction","fixed2_correct","optional_blocks_saved_vs_fixed2"])
  for item in test:
   iid=item["input_id"];e=ent[iid];pa=ti[iid][e]["prediction"];pf=ti[iid][2]["prediction"]
   w.writerow([iid,item["label"],e,pa,int(pa==item["label"]),pf,int(pf==item["label"]),2-e])
 # Small self-contained SVG: accuracy against optional block count on the frozen heldout split.
 svg=['<svg xmlns="http://www.w3.org/2000/svg" width="900" height="560" viewBox="0 0 900 560">','<rect width="100%" height="100%" fill="white"/>','<text x="450" y="28" text-anchor="middle" font-family="sans-serif" font-size="18">Frozen Q15 stopping comparison (heldout360; offline only)</text>']
 x0,y0,wid,hei=90,470,710,390
 for k in range(7):
  x=x0+wid*k/6;svg.append(f'<line x1="{x:.1f}" y1="{y0-hei}" x2="{x:.1f}" y2="{y0}" stroke="#dddddd"/>');svg.append(f'<text x="{x:.1f}" y="{y0+22}" text-anchor="middle" font-family="sans-serif" font-size="12">{k}</text>')
 for pct in range(40,101,10):
  y=y0-hei*(pct-40)/60;svg.append(f'<line x1="{x0}" y1="{y:.1f}" x2="{x0+wid}" y2="{y:.1f}" stroke="#dddddd"/>');svg.append(f'<text x="{x0-12}" y="{y+4:.1f}" text-anchor="end" font-family="sans-serif" font-size="12">{pct}%</text>')
 svg.append(f'<line x1="{x0}" y1="{y0-hei}" x2="{x0}" y2="{y0}" stroke="black"/><line x1="{x0}" y1="{y0}" x2="{x0+wid}" y2="{y0}" stroke="black"/>')
 svg.append(f'<text x="{x0+wid/2}" y="{y0+50}" text-anchor="middle" font-family="sans-serif" font-size="14">Mean optional blocks (not cycles)</text>');svg.append(f'<text transform="translate(25 {y0-hei/2}) rotate(-90)" text-anchor="middle" font-family="sans-serif" font-size="14">Accuracy</text>')
 for m in methods:
  z=m["heldout360"];x=x0+wid*z["mean_optional_blocks"]/6;y=y0-hei*(z["accuracy"]-.4)/.6;color="#d55e00" if m["method"].startswith("fixed_exit") else ("#0072b2" if m["method"]=="frozen_entropy_policy" else "#009e73")
  svg.append(f'<circle cx="{x:.1f}" cy="{y:.1f}" r="5" fill="{color}"/><text x="{x+7:.1f}" y="{y-6:.1f}" font-family="sans-serif" font-size="10">{m["method"]}</text>')
 svg.extend(['<text x="90" y="535" font-family="sans-serif" font-size="11">Previously held-out sklearn split; 360 images; does not estimate FPGA cycles or UCI external performance.</text>','</svg>'])
 (a.out_dir/"STOPPING_PARETO_HELDOUT360.svg").write_text("\n".join(svg)+"\n",encoding="utf-8",newline="")
 (a.out_dir/"COMPILER_RECORD.json").write_text(json.dumps({"validation_compile":vc,"heldout_compile":tc},indent=2)+"\n",encoding="utf-8",newline="")
 print(json.dumps({"status":"PASS_Q15_ORACLE_MATCH","method_count":len(methods),"validation_target":target,"thresholds":{"max_probability_q15":conf_tau,"top2_margin_q15":margin_tau},"heldout":[{"method":m["method"],"accuracy":m["heldout360"]["accuracy"],"mean_optional_blocks":m["heldout360"]["mean_optional_blocks"],"mean_decision_checks":m["heldout360"]["mean_decision_checks"]} for m in methods]},indent=2))
if __name__=="__main__":main()
