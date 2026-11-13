#!/usr/bin/env python3
"""Bind the frozen legacy 42 rows to the verified Stage 2 Q15 references."""
from __future__ import annotations
import argparse, csv, hashlib, json, math, struct, sys, zlib
from pathlib import Path

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[4]
STAGE2 = REPO / 'de0cv_setup/verified_inputs_2026-11-03/stage2_work/fpga/de0_cv'
LEGACY = STAGE2 / 'tests/fixtures/known_good_sim_uart.log'

def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()

def generate(stage2: Path, outdir: Path, build_id: int = 0x43324A31) -> dict:
    sys.path.insert(0, str(stage2 / 'tools'))
    from capture_audit import audit
    raw = (stage2 / 'tests/fixtures/known_good_sim_uart.log').read_bytes()
    ref = json.loads((stage2 / 'quartus/preflight_reference.json').read_text())
    # Strictly validate the original 3 x 7 CERT + 3 x 7 E2E transcript.
    audit(raw, ref)
    dataset = json.loads((stage2 / 'generated/heldout360.json').read_text())
    heldout = {int(x['input_id']): x for x in dataset['records']}
    host_path = stage2 / 'evidence/native_q15_firmware/host_actual_q15_firmware.csv'
    host_rows = list(csv.DictReader(host_path.open(newline='')))
    host = {(int(r['input_id']), int(r['mode']), int(r['param'])): r for r in host_rows}
    verdict = json.loads((stage2 / 'evidence/native_q15_firmware/native_firmware_verdict.json').read_text())
    if verdict.get('status') != 'NATIVE_Q15_FIRMWARE_MATCHES_PINNED_MODEL':
        raise ValueError('native frozen-Q15 reference gate is not PASS')
    if verdict.get('q15_predictions_sha256') != '03eb958cfa8b4fd2f71a95fb47dbca512820c237c281473817bba685b92c743e':
        raise ValueError('unexpected pinned Q15 predictions digest')

    # The old frozen transcript identifies vectors by test_index. Confirm exact
    # 64-byte pixels in the frozen 360-input set; do not infer IDs by ordering.
    slots = {int(v['slot']): v for v in ref['vectors']}
    ids = {}
    for slot, v in slots.items():
        match = [r for r in dataset['records'] if r['pixels_u8_64'] == v['input_u8_64']]
        if len(match) != 1:
            raise ValueError(f'frozen vector mapping is not unique for slot {slot}')
        iid = int(match[0]['input_id'])
        if iid != int(v['test_index']):
            raise ValueError(f'legacy test_index to input_id differs for slot {slot}: {iid}')
        ids[slot] = iid

    # Legacy budget class 0..6 maps to the existing 21-point Q16 sweep at the
    # first parameter index whose integer exit cap reaches that class.
    budget_index = [(k * 20 + 5) // 6 for k in range(7)]
    budget_q16 = [round(i * 65535 / 20) for i in budget_index]
    rows = []
    lines = []
    seq = 0
    for line in raw.decode('ascii').splitlines():
        p = line.split(',')
        if p[0] == 'CERT':
            _, slot_s, test_s, cls_s, legacy_cycles_s, legacy_pred_s = p
            slot, test, cls = map(int, (slot_s, test_s, cls_s))
            iid = ids[slot]
            if test != iid:
                raise ValueError(f'legacy slot/test index mismatch: {slot}/{test}')
            source = host[(iid, 1, cls)]
            current = tuple(int(source[k]) for k in ('admitted_exit','executed_exit','prediction','stop_reason'))
            if current[:2] != (cls, cls) or current[2] != int(legacy_pred_s) or current[2] != int(slots[slot]['expected_fixed_class_prediction'][cls]):
                raise ValueError(f'fixed Q15 reference disagrees at slot={slot} exit={cls}')
            seq += 1
            row = dict(seq=seq, case_kind='CERT', slot=slot, test_index=test, input_id=iid,
                       mode=1, parameter_index=cls, fixed_exit=cls, budget_q16=65535,
                       expected_admitted=current[0], expected_executed=current[1],
                       expected_prediction=current[2], expected_label=int(heldout[iid]['label']),
                       expected_stop=current[3], legacy_prediction=int(legacy_pred_s),
                       legacy_exit=cls, legacy_admitted='', legacy_cycles_not_fpga=int(legacy_cycles_s))
        elif p[0] == 'E2E':
            _, slot_s, test_s, cls_s, legacy_admitted_s, legacy_exec_s, legacy_cycles_s, legacy_pred_s = p
            slot, test, cls = map(int, (slot_s, test_s, cls_s))
            iid = ids[slot]
            if test != iid:
                raise ValueError(f'legacy slot/test index mismatch: {slot}/{test}')
            idx = budget_index[cls]
            source = host[(iid, 3, idx)]
            current = tuple(int(source[k]) for k in ('admitted_exit','executed_exit','prediction','stop_reason'))
            wanted_cap = (budget_q16[cls] * 6) // 65535
            if current[0] != wanted_cap or current[1] > min(wanted_cap, 5):
                raise ValueError(f'adaptive Q15 cap reference invalid at slot={slot} budget_class={cls}')
            # Legacy software-cycle values are retained as provenance only.
            seq += 1
            row = dict(seq=seq, case_kind='E2E', slot=slot, test_index=test, input_id=iid,
                       mode=3, parameter_index=idx, fixed_exit=0, budget_q16=budget_q16[cls],
                       expected_admitted=current[0], expected_executed=current[1],
                       expected_prediction=current[2], expected_label=int(heldout[iid]['label']),
                       expected_stop=current[3], legacy_prediction=int(legacy_pred_s),
                       legacy_exit=int(legacy_exec_s), legacy_admitted=int(legacy_admitted_s),
                       legacy_cycles_not_fpga=int(legacy_cycles_s))
        else:
            continue
        # Materialize the exact 100-byte JTAG request: frozen 32-byte RTNQ
        # wire frame + 64 pixel bytes + little-endian IEEE CRC-32. Firmware
        # must independently validate both frame CRC and pixel CRC/content.
        pixels = bytes(heldout[iid]['pixels_u8_64'])
        if len(pixels) != 64 or any(x < 0 or x > 255 for x in pixels):
            raise ValueError(f'invalid frozen pixel vector for input_id={iid}')
        request = bytearray(32)
        request[:8] = bytes((ord('R'), ord('T'), ord('N'), ord('Q'), 1,
                             row['mode'], row['fixed_exit'], 0))
        struct.pack_into('<IHHIII', request, 8, row['seq'], iid,
                         row['budget_q16'], 0, 0x52544e4e, build_id)
        struct.pack_into('<I', request, 28, zlib.crc32(request[:28]))
        payload_crc = zlib.crc32(pixels)
        row.update(request_frame_hex=request.hex(), pixels_u8_64_hex=pixels.hex(),
                   payload_crc32=f'{payload_crc:08x}',
                   jtag_request_100b_hex=(request + pixels + struct.pack('<I', payload_crc)).hex(),
                   jtag_request_bytes=100, jtag_request_bits=800,
                   model_id='52544e4e', build_id=f'{build_id:08x}', deadline_cycles=0)
        rows.append(row)
        lines.append(','.join(str(v) for v in (row['mode'],row['fixed_exit'],row['seq'],row['input_id'],row['budget_q16'],row['expected_admitted'],row['expected_executed'],row['expected_prediction'],row['expected_label'],row['expected_stop'])))
    if len(rows) != 42 or [r['case_kind'] for r in rows].count('CERT') != 21 or [r['case_kind'] for r in rows].count('E2E') != 21:
        raise ValueError(f'expected exactly 21 CERT + 21 E2E rows, got {len(rows)}')
    outdir.mkdir(parents=True, exist_ok=True)
    csv_path = outdir / 'c2_cases.csv'
    with csv_path.open('w', newline='', encoding='utf-8') as f:
        w = csv.DictWriter(f, fieldnames=list(rows[0])); w.writeheader(); w.writerows(rows)
    (outdir / 'c2_cases_sim.csv').write_text('\n'.join(lines)+'\n', encoding='ascii')
    source_paths = [stage2/'tests/fixtures/known_good_sim_uart.log', stage2/'quartus/preflight_reference.json',
                    stage2/'generated/heldout360.json', host_path,
                    stage2/'evidence/native_q15_firmware/native_firmware_verdict.json']
    result = {'status':'C2_CASES_GENERATED_FROM_FROZEN_REFERENCES', 'count':len(rows),
              'build_id':f'{build_id:08x}',
              'cert_cases':21, 'adaptive_budget_cases':21, 'input_ids':sorted(set(ids.values())),
              'adaptive_budget_indices':budget_index, 'adaptive_budget_q16':budget_q16,
              'legacy_cycles_used_as_fpga_expectation':False,
              'source_sha256':{p.name:sha(p) for p in source_paths},
              'c2_cases_csv_sha256':sha(csv_path), 'simulation_case_file_sha256':sha(outdir/'c2_cases_sim.csv')}
    (outdir/'c2_case_manifest.json').write_text(json.dumps(result,indent=2)+'\n', encoding='utf-8')
    return result

if __name__ == '__main__':
    ap=argparse.ArgumentParser()
    ap.add_argument('--stage2-root',type=Path,default=STAGE2)
    ap.add_argument('--outdir',type=Path,default=HERE.parent/'host')
    ap.add_argument('--build-id',type=lambda value:int(value,0),default=0x43324A31,
                    help='32-bit protocol build ID (default: legacy C2J1 0x43324a31)')
    args=ap.parse_args()
    if not 0 <= args.build_id <= 0xffffffff:
        ap.error('--build-id must fit in 32 bits')
    print(json.dumps(generate(args.stage2_root,args.outdir,args.build_id),indent=2))
