import argparse
import math
from pathlib import Path


def c_float(value: float) -> str:
    text = format(value, '.9g')
    if 'e' not in text and '.' not in text:
        text += '.0'
    return text + 'f'


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument('--points', type=int, default=257)
    ap.add_argument('--lo', type=float, default=-8.0)
    ap.add_argument('--hi', type=float, default=8.0)
    ap.add_argument('--out', default='realtime_nn_activation_lut_generated.h')
    args = ap.parse_args()
    if args.points < 2 or args.hi <= args.lo:
        raise SystemExit('invalid LUT geometry')

    step = (args.hi - args.lo) / (args.points - 1)
    funcs = (
        ('TANH_LUT', math.tanh),
        ('GELU_LUT', lambda x: 0.5 * x * (1.0 + math.erf(x / math.sqrt(2.0)))),
    )

    out = Path(args.out)
    with out.open('w') as f:
        f.write('#ifndef RT_ACT_LUT_GENERATED_H\n#define RT_ACT_LUT_GENERATED_H\n')
        f.write(f'#define ACT_LUT_N {args.points}\n')
        f.write(f'#define ACT_LUT_LO ({c_float(args.lo)})\n')
        f.write(f'#define ACT_LUT_HI ({c_float(args.hi)})\n')
        f.write(f'#define ACT_LUT_STEP ({c_float(step)})\n')
        for name, fn in funcs:
            f.write(f'static const float {name}[ACT_LUT_N] = {{\n')
            for i in range(args.points):
                x = args.lo + step * i
                f.write(c_float(fn(x)) + ',')
                if (i + 1) % 8 == 0:
                    f.write('\n')
            f.write('\n};\n')
        f.write('#endif\n')
    print(f'generated {out}: {args.points} points per activation, domain [{args.lo}, {args.hi}]')


if __name__ == '__main__':
    main()
