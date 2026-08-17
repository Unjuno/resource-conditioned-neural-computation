import argparse, struct
from pathlib import Path


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('binary_weights', help='binary file produced by export_realtime_nn_cpp_weights.py')
    ap.add_argument('--out', default='realtime_nn_weights_generated.h')
    a = ap.parse_args()

    raw = Path(a.binary_weights).read_bytes()
    count = struct.unpack_from('<I', raw, 0)[0]
    values = struct.unpack_from(f'<{count}f', raw, 4)

    out = Path(a.out)
    with out.open('w') as f:
        f.write('#ifndef RT_WEIGHTS_GENERATED_H\n#define RT_WEIGHTS_GENERATED_H\n#include <stddef.h>\n')
        f.write(f'#define RT_WEIGHT_COUNT {count}\nstatic const float RT_WEIGHTS[RT_WEIGHT_COUNT] = {{\n')
        for i, value in enumerate(values):
            s = format(value, '.9g')  # enough digits to round-trip float32
            if 'e' not in s and '.' not in s:
                s += '.0'
            f.write(s + 'f')
            f.write(',\n' if (i + 1) % 8 == 0 else ',')
        f.write('\n};\n#endif\n')

    print(f'generated {out}: {count} float32 weights ({count * 4} bytes of model data)')


if __name__ == '__main__':
    main()
