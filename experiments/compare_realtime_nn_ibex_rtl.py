import argparse
import json
from pathlib import Path

ALLOWANCE = 64  # measurement CSR/caller envelope, not part of the neural bound


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


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--host', required=True)
    ap.add_argument('--rtl', required=True)
    ap.add_argument('--conditional-results', default='results/realtime_nn_fixed_time_target_results.json')
    ap.add_argument('--out', default='results/realtime_nn_ibex_rtl_validation_results.json')
    a = ap.parse_args()
    host_pred, host_pref = parse_host(a.host)
    cert, e2e, overhead = parse_rtl(a.rtl)
    old = json.loads(Path(a.conditional_results).read_text())
    classes = old['rv32_instruction_envelope']['classes']
    cert_bound = {int(x['class']): int(x['certification_path_cycles']) for x in classes}
    total_bound = {int(x['class']): int(x['total_with_admission_cycles']) for x in classes}

    pred_mismatch = 0
    cert_exceed = []
    for x in cert:
        exp = host_pred.get((x['slot'], x['class']))
        pred_mismatch += int(exp is None or exp != x['pred'])
        lim = cert_bound[x['class']] + ALLOWANCE
        if x['cycles'] > lim:
            cert_exceed.append({**x, 'conditional_bound': cert_bound[x['class']], 'limit_with_measurement_allowance': lim})

    e2e_pred_mismatch = 0
    e2e_path_mismatch = 0
    e2e_exceed = []
    for x in e2e:
        exp_exec = min(x['class'], 5)
        e2e_path_mismatch += int(x['admitted'] != x['class'] or x['executed'] != exp_exec)
        exp_pred = host_pred.get((x['slot'], x['executed']))
        e2e_pred_mismatch += int(exp_pred is None or exp_pred != x['pred'])
        lim = total_bound[x['class']] + ALLOWANCE
        if x['cycles'] > lim:
            e2e_exceed.append({**x, 'conditional_bound': total_bound[x['class']], 'limit_with_measurement_allowance': lim})

    anchors = {}
    for c in (0, 3, 5):
        vals = [x['cycles'] for x in cert if x['class'] == c]
        anchors[str(c)] = {'cycles': vals, 'range': (max(vals) - min(vals)) if vals else None}
    anchor_data_independent = all(v['range'] == 0 for v in anchors.values())

    # Formal seed-63 precondition for the no-stop E2E sample.
    worst_pref_ok = host_pref.get(2) == 5
    decision = 'PASS' if (
        cert and len(e2e) == 7 and pred_mismatch == 0 and e2e_pred_mismatch == 0
        and e2e_path_mismatch == 0 and not cert_exceed and not e2e_exceed
        and anchor_data_independent and worst_pref_ok
    ) else 'FAIL'
    out = {
        'decision': decision,
        'measurement_allowance_cycles': ALLOWANCE,
        'host_preferred_by_slot': host_pref,
        'worst_path_sample_slot2_prefers_exit5': worst_pref_ok,
        'rtl_overhead_diagnostics': overhead,
        'certification_cases': len(cert),
        'certification_prediction_mismatches': pred_mismatch,
        'certification_bound_exceedances': cert_exceed,
        'anchor_class_cycle_data_independence': anchors,
        'anchor_cycle_counts_identical': anchor_data_independent,
        'e2e_cases': len(e2e),
        'e2e_prediction_mismatches': e2e_pred_mismatch,
        'e2e_admission_or_execution_mismatches': e2e_path_mismatch,
        'e2e_bound_exceedances': e2e_exceed,
        'certification_rows': cert,
        'e2e_rows': e2e,
        'nonclaim': 'A PASS validates the conditional table against the pinned Ibex RTL Simple System configuration. It is not a silicon/FPGA production WCET certificate.'
    }
    Path(a.out).parent.mkdir(parents=True, exist_ok=True)
    Path(a.out).write_text(json.dumps(out, indent=2))
    print(json.dumps(out, indent=2))


if __name__ == '__main__':
    main()
