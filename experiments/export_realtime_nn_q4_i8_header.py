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

    # The production Q4 core performs unchecked direct LUT indexing. Therefore
    # every production header must be generated through the exhaustive finite-
    # domain range certificate. This local import avoids a module-level cycle:
    # the certified exporter reuses q8_exact/q8_saturating/emit_array above.
    from export_realtime_nn_q4_certified_header import export_certified

    result = export_certified(args.seed, args.out)
    print(
        f"seed={args.seed} certified=1 effective_states={result['effective_input_states']} "
        f"ranges={result['ranges']} weight_count={result['weight_count']}"
    )


if __name__ == "__main__":
    main()
