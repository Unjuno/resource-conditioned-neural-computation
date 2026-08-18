import argparse
import json
import math
from pathlib import Path

import numpy as np

import export_realtime_nn_q4_i8_header as base

LUT_LO = -128
LUT_HI = 128


def round_q4(values):
    values = np.asarray(values, dtype=np.int64)
    return np.where(values >= 0, (values + 8) // 16, -((-values + 8) // 16))


def linear_q4(x, weight, bias):
    raw = x.astype(np.int64) @ weight.astype(np.int64).T
    return round_q4(raw) + bias.astype(np.int64)


def quantize_model(model):
    q = {"emb": base.q8_exact(model.emb.weight.detach().cpu().numpy()), "blocks": []}
    for block in model.blocks:
        item = {}
        for name, layer in (
            ("self", block.selfp),
            ("neigh", block.neigh),
            ("ff1", block.ff1),
            ("ff2", block.ff2),
        ):
            item[name] = (
                base.q8_exact(layer.weight.detach().cpu().numpy()),
                base.q8_exact(layer.bias.detach().cpu().numpy()),
            )
        q["blocks"].append(item)
    q["head"] = (
        base.q8_exact(model.head.weight.detach().cpu().numpy()),
        base.q8_exact(model.head.bias.detach().cpu().numpy()),
    )
    return q


def activation_luts():
    xs = np.linspace(base.LUT_LO, base.LUT_HI, base.LUT_POINTS)
    tanh_lut = base.q8_saturating(np.tanh(xs))
    gelu_lut = base.q8_saturating(
        0.5 * xs * (1.0 + np.vectorize(math.erf)(xs / math.sqrt(2.0)))
    )
    return tanh_lut, gelu_lut


def certify_quantized(q, certificate_lo=LUT_LO, certificate_hi=LUT_HI):
    """Exhaustively certify all effective 9-bit inputs consumed by this toy core."""
    states = np.arange(1 << base.budget_model.L, dtype=np.uint16)
    shifts = np.arange(base.budget_model.L, dtype=np.uint16)
    bits = ((states[:, None] >> shifts) & 1).astype(np.int64)
    h = q["emb"][bits].astype(np.int64)
    tanh_lut, gelu_lut = activation_luts()

    ranges = {
        "tanh_pre": [10**9, -10**9],
        "gelu_pre": [10**9, -10**9],
        "residual_tanh_pre": [10**9, -10**9],
    }

    def observe(name, values):
        ranges[name][0] = min(ranges[name][0], int(values.min()))
        ranges[name][1] = max(ranges[name][1], int(values.max()))

    for block in q["blocks"]:
        self_w, self_b = block["self"]
        neigh_w, neigh_b = block["neigh"]
        ff1_w, ff1_b = block["ff1"]
        ff2_w, ff2_b = block["ff2"]

        self_out = linear_q4(h, self_w, self_b)
        neigh_out = np.empty_like(self_out)
        neigh_out[:, :-1] = linear_q4(h[:, 1:], neigh_w, neigh_b)
        neigh_out[:, -1] = neigh_b.astype(np.int64)

        tanh_pre = self_out + neigh_out
        observe("tanh_pre", tanh_pre)
        z = tanh_lut[np.clip(tanh_pre, LUT_LO, LUT_HI) - LUT_LO].astype(np.int64)

        gelu_pre = linear_q4(z, ff1_w, ff1_b)
        observe("gelu_pre", gelu_pre)
        tmp = gelu_lut[np.clip(gelu_pre, LUT_LO, LUT_HI) - LUT_LO].astype(np.int64)

        ff2 = linear_q4(tmp, ff2_w, ff2_b)
        residual_pre = z + round_q4(ff2 * 3)
        observe("residual_tanh_pre", residual_pre)
        h = tanh_lut[np.clip(residual_pre, LUT_LO, LUT_HI) - LUT_LO].astype(np.int64)

    failures = {
        name: bounds
        for name, bounds in ranges.items()
        if bounds[0] < certificate_lo or bounds[1] > certificate_hi
    }
    if failures:
        raise ValueError(
            f"Q4 LUT range certificate failed for [{certificate_lo}, {certificate_hi}]: {failures}"
        )
    return ranges


def flattened_weights(q):
    values = list(q["emb"].reshape(-1))
    for block in q["blocks"]:
        for name in ("self", "neigh", "ff1", "ff2"):
            weight, bias = block[name]
            values.extend(weight.reshape(-1))
            values.extend(bias.reshape(-1))
    weight, bias = q["head"]
    values.extend(weight.reshape(-1))
    values.extend(bias.reshape(-1))
    return np.asarray(values, dtype=np.int8)


def export_certified(seed, out_path):
    model = base.budget_model.train(seed).eval()
    q = quantize_model(model)
    ranges = certify_quantized(q)
    values = flattened_weights(q)
    tanh_lut, gelu_lut = activation_luts()

    out = Path(out_path)
    out.parent.mkdir(parents=True, exist_ok=True)
    with out.open("w") as handle:
        handle.write(
            "#ifndef RTNN_Q4_I8_GENERATED_H\n#define RTNN_Q4_I8_GENERATED_H\n#include <stdint.h>\n"
        )
        handle.write("#define RTNN_Q_SCALE 16\n")
        handle.write(f"#define RTNN_Q_WEIGHT_COUNT {len(values)}\n")
        handle.write(f"#define RTNN_Q_LUT_N {base.LUT_POINTS}\n")
        handle.write("#define RTNN_Q_LUT_LO (-128)\n#define RTNN_Q_LUT_HI 128\n")
        handle.write("#define RTNN_Q_LUT_RANGE_CERTIFIED 1\n")
        handle.write(f"#define RTNN_Q_CERT_EFFECTIVE_INPUT_BITS {base.budget_model.L}\n")
        handle.write(f"#define RTNN_Q_CERT_EFFECTIVE_INPUT_STATES {1 << base.budget_model.L}\n")
        handle.write(f"#define RTNN_Q_CERT_TANH_PRE_MIN ({ranges['tanh_pre'][0]})\n")
        handle.write(f"#define RTNN_Q_CERT_TANH_PRE_MAX ({ranges['tanh_pre'][1]})\n")
        handle.write(f"#define RTNN_Q_CERT_GELU_PRE_MIN ({ranges['gelu_pre'][0]})\n")
        handle.write(f"#define RTNN_Q_CERT_GELU_PRE_MAX ({ranges['gelu_pre'][1]})\n")
        handle.write(
            f"#define RTNN_Q_CERT_RESIDUAL_PRE_MIN ({ranges['residual_tanh_pre'][0]})\n"
        )
        handle.write(
            f"#define RTNN_Q_CERT_RESIDUAL_PRE_MAX ({ranges['residual_tanh_pre'][1]})\n"
        )
        base.emit_array(handle, "RTNN_Q_WEIGHTS", values)
        base.emit_array(handle, "RTNN_Q_TANH", tanh_lut)
        base.emit_array(handle, "RTNN_Q_GELU", gelu_lut)
        handle.write("#endif\n")

    return {
        "seed": seed,
        "effective_input_bits": base.budget_model.L,
        "effective_input_states": 1 << base.budget_model.L,
        "ranges": ranges,
        "certificate_domain": [LUT_LO, LUT_HI],
        "weight_count": len(values),
    }


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--seed", type=int, default=0)
    parser.add_argument("--out", required=True)
    args = parser.parse_args()
    print(json.dumps(export_certified(args.seed, args.out), indent=2))


if __name__ == "__main__":
    main()
