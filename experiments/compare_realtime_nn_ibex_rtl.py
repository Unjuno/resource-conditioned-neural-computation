import argparse
import json
from pathlib import Path


def parse_host(path):
    pred = {}
    pref = {}
    for line in Path(path).read_text().splitlines():
        p = line.strip().split(',')
        if not p or p[0] != 'HOST':
            continue
        if p[1] == 'PREF':
            pref[int(p[2])] = int(p[4])
        elif p[1] == 'PRED':
            pred[(int(p[2]), int(p[3]))] = int(p[4])
    return pred, pref


def parse_rtl(path):
    cert, e2e, overhead = [], [], {}
    for line in Path(path).read_text().splitlines():
        p = line.strip().split(',')
        if not p:
            continue
        if p[0] == 'OVERHEAD' and len(p) >= 3:
            overhead[p[1]] = int(p[2])
        elif p[0] == 'CERT' and len(p) >= 6:
            cert.append({'slot': int(p[1]), 'test_index': int(p[2]), 'class': int(p[3]), 'cycles': int(p[4]), 'pred': int(p[5])})
        elif p[0] == 'E2E' and len(p) >= 8:
            e2e.append({'slot': int(p[1]), 'test_index': int(p[2]), 'class': int(p[3]), 'admitted': int(p[4]), 'executed': int(p[5]), 'cycles': int(p[6]), 'pred': int(p[7])})
    return cert, e2e, overhead


def exceed(rows, bounds):
    out = []
    for x in rows:
        lim = int(bounds[x['class']])
        if x['cycles'] > lim:
            out.append({**x, 'bound': lim, 'excess': x['cycles'] - lim})
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--host', required=True)
    ap.add_argument('--rtl', required=True)
    ap.add_argument('--old-conditional-results', default='results/realtime_nn_fixed_time_target_results.json')
    ap.add_argument('--rtl-binding', default='results/realtime_nn_ibex_rtl_timing_binding.json')
    ap.add_argument('--out', default='results/realtime_nn_ibex_rtl_validation_results.json')
    a = ap.parse_args()
    host_pred, host_pref = parse_host(a.host)
    cert, e2e, overhead = parse_rtl(a.rtl)

    old = json.loads(Path(a.old_conditional_results).read_text())
    old_classes = old['rv32_instruction_envelope']['classes']
    old_cert = [int(x['certification_path_cycles']) for x in old_classes]
    old_total = [int(x['total_with_admission_cycles']) for x in old_classes]
    binding = json.loads(Path(a.rtl_binding).read_text())
    new_cert = [int(x) for x in binding['rtl_derived_certification_upper_cycles']]
    new_total = [int(x) for x in binding['rtl_derived_total_upper_cycles']]

    cert_pred_mismatch = 0
    for x in cert:
        exp = host_pred.get((x['slot'], x['class']))
        cert_pred_mismatch += int(exp is None or exp != x['pred'])

    by_class = {}
    for c in range(7):
        vals = [x['cycles'] for x in cert if x['class'] == c]
        by_class[str(c)] = {
            'cycles': vals,
            'range': (max(vals) - min(vals)) if vals else None,
            'three_inputs_identical': len(vals) == len(host_pref) == 3 and max(vals) == min(vals) if vals else False,
        }
    all_class_cycle_identical = all(v['three_inputs_identical'] for v in by_class.values())

    e2e_pred_mismatch = 0
    e2e_execution_mismatch = 0
    e2e_admission_unsafe = 0
    for x in e2e:
        pref = host_pref.get(x['slot'])
        exp_exec = min(x['class'], 5, pref if pref is not None else 255)
        e2e_execution_mismatch += int(x['executed'] != exp_exec)
        # Equal timing bounds for classes 5 and 6 permit admission label 6 at
        # the class-5 deadline. The continuous budget still caps execution.
        e2e_admission_unsafe += int(x['admitted'] < x['class'])
        exp_pred = host_pred.get((x['slot'], x['executed']))
        e2e_pred_mismatch += int(exp_pred is None or exp_pred != x['pred'])

    old_cert_exceed = exceed(cert, old_cert)
    old_e2e_exceed = exceed(e2e, old_total)
    new_cert_exceed = exceed(cert, new_cert)
    new_e2e_exceed = exceed(e2e, new_total)

    expected_cert_cases = len(host_pref) * 7
    expected_e2e_cases = len(host_pref) * 7
    decision = 'PASS' if (
        len(cert) == expected_cert_cases
        and cert_pred_mismatch == 0 and all_class_cycle_identical
        and len(e2e) == expected_e2e_cases
        and e2e_pred_mismatch == 0 and e2e_execution_mismatch == 0
        and e2e_admission_unsafe == 0
        and not new_cert_exceed and not new_e2e_exceed
        and bool(old_cert_exceed) and bool(old_e2e_exceed)
    ) else 'FAIL'

    out = {
        'decision': decision,
        'old_conditional_model_decision': 'FAIL' if old_cert_exceed or old_e2e_exceed else 'PASS',
        'revised_rtl_binding_decision': 'PASS' if not new_cert_exceed and not new_e2e_exceed else 'FAIL',
        'host_preferred_by_slot': host_pref,
        'rtl_overhead_diagnostics': overhead,
        'certification_cases': len(cert),
        'certification_prediction_mismatches': cert_pred_mismatch,
        'all_class_cycle_data_independence': by_class,
        'all_class_cycle_counts_identical': all_class_cycle_identical,
        'old_certification_bound_exceedance_count': len(old_cert_exceed),
        'old_runtime_bound_exceedance_count': len(old_e2e_exceed),
        'revised_certification_bound_exceedances': new_cert_exceed,
        'revised_runtime_bound_exceedances': new_e2e_exceed,
        'e2e_cases': len(e2e),
        'e2e_prediction_mismatches': e2e_pred_mismatch,
        'e2e_execution_mismatches': e2e_execution_mismatch,
        'e2e_unsafe_admission_count': e2e_admission_unsafe,
        'revised_certification_bounds': new_cert,
        'revised_runtime_bounds': new_total,
        'certification_rows': cert,
        'e2e_rows': e2e,
        'nonclaims': [
            'The old arithmetic RTNN-IBEX-DIT-v1 table is falsified by pinned RTL.',
            'A PASS validates the revised table for the pinned Ibex RTL Simple System configuration only.',
            'No FPGA/ASIC silicon WCET or production hard-real-time certification is claimed.'
        ]
    }
    Path(a.out).parent.mkdir(parents=True, exist_ok=True)
    Path(a.out).write_text(json.dumps(out, indent=2))
    print(json.dumps(out, indent=2))
    raise SystemExit(0 if decision == 'PASS' else 1)


if __name__ == '__main__':
    main()
