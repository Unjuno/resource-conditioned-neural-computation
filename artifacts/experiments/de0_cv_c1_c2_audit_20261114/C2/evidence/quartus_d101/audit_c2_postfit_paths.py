import json, re, sys
from pathlib import Path
root = Path.cwd()
path_re = re.compile(r'^;\s*(\d+(?:\.\d+)?)\s*;\s*(.*?)\s*;\s*(.*?)\s*;\s*$')
summary_re = re.compile(r'^; set_net_delay\s*;\s*([0-9.]+)\s*;\s*([0-9.]+)\s*;\s*([0-9.]+)\s*;\s*(.*?)\s*;\s*(.*?)\s*;\s*max')
results = {"corner_count": 4, "request": [], "response": [], "net_delay": [], "errors": []}
for corner in range(4):
    for label, expected in (("req",800),("rsp",384)):
        file = root / f"c2_allcorners_path_{label}_{corner}.rpt"
        pairs=[]
        for line in file.read_text(errors="replace").splitlines():
            m=path_re.match(line)
            if m and "|" in m.group(2) and "|" in m.group(3):
                pairs.append((float(m.group(1)),m.group(2).strip(),m.group(3).strip()))
        if len(pairs)!=expected:
            results["errors"].append(f"{file.name}: {len(pairs)} paths, expected {expected}")
        srcs=[re.sub(r"~DUPLICATE.*$","",x[1]) for x in pairs]; dsts=[x[2] for x in pairs]
        if len(set(srcs))!=expected or len(set(dsts))!=expected:
            results["errors"].append(f"{file.name}: endpoint names not unique")
        if label=="req":
            for _,src,dst in pairs:
                sm=re.search(r"req_hold_tck_q\[(\d+)\]$",src); dm=re.search(r"request_data_o\[(\d+)\]$",dst)
                if not sm or not dm or sm.group(1)!=dm.group(1): results["errors"].append(f"{file.name}: request index mismatch: {src} -> {dst}")
        else:
            for _,src,dst in pairs:
                src=re.sub(r"~DUPLICATE.*$","",src); sm=re.search(r"response_words_q\[(\d+)\]\[(\d+)\]$",src); dm=re.search(r"rsp_hold_tck_q\[(\d+)\]$",dst)
                if not sm or not dm or int(dm.group(1))!=int(sm.group(1))*32+int(sm.group(2)):
                    results["errors"].append(f"{file.name}: response index mismatch: {src} -> {dst}")
        results["request" if label=="req" else "response"].append({"corner":corner,"path_count":len(pairs),"max_path_delay_ns":max((x[0] for x in pairs),default=None)})
    nd=(root/f"c2_allcorners_netdelay_{corner}.rpt").read_text(errors="replace")
    sums=[]
    for line in nd.splitlines():
        m=summary_re.match(line)
        if m: sums.append({"slack_ns":float(m.group(1)),"bound_ns":float(m.group(2)),"actual_ns":float(m.group(3)),"from":m.group(4).strip(),"to":m.group(5).strip()})
    if len(sums)!=2: results["errors"].append(f"netdelay corner {corner}: {len(sums)} group summaries, expected 2")
    for i,x in enumerate(sums):
        expected_bound=16.0 if i==0 else 24.0
        if x["bound_ns"]!=expected_bound or x["actual_ns"]>x["bound_ns"] or x["slack_ns"]<0:
            results["errors"].append(f"netdelay corner {corner}: bound/slack failure: {x}")
    results["net_delay"].append({"corner":corner,"groups":sums})
results["coverage_counts"]=(root/"c2_allcorners_coverage.txt").read_text().strip()
results["path_counts"]=(root/"c2_allcorners_count.txt").read_text().strip()
results["max_skew"]=["No paths were found" in (root/f"c2_allcorners_maxskew_{i}.rpt").read_text(errors="replace") for i in range(4)]
(root/"c2_postfit_path_audit.json").write_text(json.dumps(results,indent=2)+"\n",encoding="utf-8")
print(json.dumps(results,indent=2))
sys.exit(1 if results["errors"] else 0)



