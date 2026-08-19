import argparse
from pathlib import Path
import numpy as np
import realtime_nn_real_sequence_generalization as r

# These held-out indices span deployed preferred exits for formal seed 63:
# index 0 -> exit 1, index 24 -> exit 3, index 57 -> exit 5.
DEFAULT_INDICES = [0, 24, 57]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--outdir', default='/tmp/rtnn_ibex_rtl')
    ap.add_argument('--indices', default=','.join(map(str, DEFAULT_INDICES)))
    a = ap.parse_args()
    indices = [int(x) for x in a.indices.split(',') if x]
    _, _, te = r.data()
    q = np.rint(te[0].cpu().numpy() * 16).astype(np.uint8)
    y = te[1].cpu().numpy().astype(np.uint8)
    out = Path(a.outdir)
    out.mkdir(parents=True, exist_ok=True)
    p = out / 'realtime_nn_ibex_rtl_vectors_generated.h'
    with p.open('w') as f:
        f.write('#ifndef RTNN_IBEX_RTL_VECTORS_GENERATED_H\n#define RTNN_IBEX_RTL_VECTORS_GENERATED_H\n#include <stdint.h>\n')
        f.write(f'#define RTNN_RTL_VECTOR_N {len(indices)}u\n')
        f.write('static const uint16_t RTNN_RTL_TEST_INDEX[RTNN_RTL_VECTOR_N]={' + ','.join(map(str, indices)) + '};\n')
        f.write('static const uint8_t RTNN_RTL_LABEL[RTNN_RTL_VECTOR_N]={' + ','.join(str(int(y[i])) for i in indices) + '};\n')
        f.write('static const uint8_t RTNN_RTL_X[RTNN_RTL_VECTOR_N][64]={\n')
        for i in indices:
            f.write('{' + ','.join(map(str, q[i].reshape(-1).tolist())) + '},\n')
        f.write('};\n#endif\n')
    print(p)


if __name__ == '__main__':
    main()
