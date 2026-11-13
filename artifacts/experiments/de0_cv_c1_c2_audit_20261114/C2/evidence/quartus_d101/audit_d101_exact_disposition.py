import json,re,sys
from pathlib import Path
root=Path.cwd()
qsf=(root/'rtnn_c2.qsf').read_text(errors='replace')
drc=(root/'rtnn_c2.drc.rpt').read_text(errors='replace')
assign_re=re.compile(r'set_instance_assignment\s+-name\s+DISABLE_DA_RULE\s+-to\s+"([^"]+)"\s+-entity\s+(\S+)\s+(D\d+)\s*$',re.M)
assign=assign_re.findall(qsf)
off_re=re.compile(r'; Rule D101:.*?; Off\s+;\s*([^;]+?)\s*;',re.S)
off=[x.strip() for x in off_re.findall(drc)]
req={f'req_hold_tck_q[{i}]' for i in range(800)}
expected=req|{'response_words_q[11][31]'}
targets={a for a,e,r in assign}
offset=set(off)
checks={
 'assignment_count_801':len(assign)==801,
 'assignment_targets_unique':len(targets)==801,
 'assignment_entities_match_source_domains':all(e==('rtnn_c2_vjtag_mailbox' if a.startswith('req_hold_tck_q[') else 'rtnn_de0_cv_soc_c2') for a,e,r in assign),
 'all_assignment_rule_D101':all(r=='D101' for a,e,r in assign),
 'expected_target_set':targets==expected,
 'drc_local_off_count_801':len(off)==801,
 'drc_local_off_unique':len(offset)==801,
 'drc_off_matches_qsf':offset==targets,
 'global_D101_on':re.search(r'; Rule D101:.*?; On\s+;',drc) is not None,
 'global_D102_on':re.search(r'; Rule D102:.*?; On\s+;',drc) is not None,
 'global_D103_on':re.search(r'; Rule D103:.*?; On\s+;',drc) is not None,
 'zero_high_violations':re.search(r'; Total High Violations\s*;\s*0\s*;',drc) is not None,
 'zero_DRC_errors_and_warnings':'Design Assistant was successful. 0 errors, 0 warnings' in (root/'quartus_drc_d101_exact_disposition.log').read_text(errors='replace'),
}
result={'checks':checks,'assignment_count':len(assign),'drc_local_off_count':len(off),'request_node_count':sum(x.startswith('req_hold_tck_q[') for x in targets),'response_node_count':sum(x.startswith('response_words_q[') for x in targets),'all_pass':all(checks.values())}
(root/'d101_exact_disposition_audit.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(result,indent=2))
sys.exit(0 if result['all_pass'] else 1)

