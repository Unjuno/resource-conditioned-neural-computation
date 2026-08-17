import argparse
import math
import sys
from pathlib import Path

import numpy as np

sys.path.insert(0, str(Path(__file__).resolve().parent))
import realtime_nn_budget_execution as budget_model

Q_FRAC = 4
Q_SCALE = 1 << Q_FRAC
LUT_POINTS = 257
LUT_LO = -8.0
LUT_HI = 8.0


def q8_exact(values):
    q = np.rint(np.asarray(values, dtype=np.float64) * Q_SCALE)
    if q.max() > 127 or q.min() < -128:
        raise ValueError(f"Q4 value exceeds int8 storage: [{q.min()}, {q.max()}]")
    return q.astype(np.int8)


def q8_saturating(values):
    q = np.rint(np.asarray(values, dtype=np.float64) * Q_SCALE)
    return np.clip(q, -128, 127).astype(np.int8)


def emit_array(handle, name, values):
    flat = np.asarray(values, dtype=np.int8).reshape(-1)
    handle.write(f"static const int8_t {name}[{len(flat)}] = {{\n")
    for i, value in enumerate(flat):
        handle.write(f"{int(value)},")
        if (i + 1) % 24 == 0:
            handle.write("\n")
    handle.write("\n};\n")


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--seed", type=int, default=0)
    parser.add_argument("--out", required=True)
    args = parser.parse_args()

    model = budget_model.train(args.seed).eval()
    values = []
    values.extend(q8_exact(model.emb.weight.detach().numpy()).reshape(-1).tolist())
    for block in model.blocks:
        for layer in (block.selfp, block.neigh, block.ff1, block.ff2):
            values.extend(q8_exact(layer.weight.detach().numpy()).reshape(-1).tolist())
            values.extend(q8_exact(layer.bias.detach().numpy()).reshape(-1).tolist())
    values.extend(q8_exact(model.head.weight.detach().numpy()).reshape(-1).tolist())
    values.extend(q8_exact(model.head.bias.detach().numpy()).reshape(-1).tolist())

    xs = np.linspace(LUT_LO, LUT_HI, LUT_POINTS)
    tanh_lut = q8_saturating(np.tanh(xs))
    gelu_lut = q8_saturating(0.5 * xs * (1.0 + np.vectorize(math.erf)(xs / math.sqrt(2.0))))

    out = Path(args.out)
    out.parent.mkdir(parents=True, exist_ok=True)
    with out.open("w") as handle:
        handle.write("#ifndef RTNN_Q4_I8_GENERATED_H\n#define RTNN_Q4_I8_GENERATED_H\n#include <stdint.h>\n")
        handle.write("#define RTNN_Q_SCALE 16\n")
        handle.write(f"#define RTNN_Q_WEIGHT_COUNT {len(values)}\n")
        handle.write(f"#define RTNN_Q_LUT_N {LUT_POINTS}\n")
        handle.write("#define RTNN_Q_LUT_LO (-128)\n#define RTNN_Q_LUT_HI 128\n")
        emit_array(handle, "RTNN_Q_WEIGHTS", values)
        emit_array(handle, "RTNN_Q_TANH", tanh_lut)
        emit_array(handle, "RTNN_Q_GELU", gelu_lut)
        handle.write("#endif\n")

    print(
        f"seed={args.seed} weight_min={min(values)} weight_max={max(values)} "
        f"weight_bytes={len(values)} lut_bytes={len(tanh_lut) + len(gelu_lut)}"
    )


if __name__ == "__main__":
    main()
