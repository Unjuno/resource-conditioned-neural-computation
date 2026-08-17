import argparse, math
from pathlib import Path


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--points', type=int, default=257)
    ap.add_argument('--lo', type=float, default=-8.0)
    ap.add_argument('--hi', type=float, default=8.0)
    ap.add_argument('--out', default='realtime_nn_activation_lut_generated.h')
    a = ap.parse_args()

    if a.points < 2:
        raise SystemExit('--points must be >= 2')

    step = (a.hi - a.lo) / (a.points - 1)
    tanh_values = []
    gelu_values = []
    for i in range(a.points):
        x = a.lo + step * i
        tanh_values.append(math.tanh(x))
        gelu_values.append(0.5 * x * (1.0 + math.erf(x / math.sqrt(2.0))))

    with Path(a.out).open('w') as f:
        f.write('#ifndef RT_ACT_LUT_GENERATED_H\n#define RT_ACT_LUT_GENERATED_H\n')
        f.write(f'#define ACT_LUT_N {a.points}\n')
        f.write(f'#define ACT_LUT_LO ({a.lo:.9g}f)\n')
        f.write(f'#define ACT_LUT_HI ({a.hi:.9g}f)\n')
        f.write(f'#define ACT_LUT_STEP ({step:.9g}f)\n')
        for name, values in [('TANH_LUT', tanh_values), ('GELU_LUT', gelu_values)]:
            f.write(f'static const float {name}[ACT_LUT_N] = {{\n')
            for i, value in enumerate(values):
                s = format(value, '.9g')
                if 'e' not in s and '.' not in s:
                    s += '.0'
                f.write(s + 'f,')
                if (i + 1) % 8 == 0:
                    f.write('\n')
            f.write('\n};\n')
        f.write('#endif\n')

    print(f'generated {a.out}: {a.points} points per activation, {2 * a.points * 4} bytes of float32 table data')


if __name__ == '__main__':
    main()
