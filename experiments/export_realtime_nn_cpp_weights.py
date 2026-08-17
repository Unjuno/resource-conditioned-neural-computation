import argparse, array, json, struct
from pathlib import Path
import torch
import realtime_nn_budget_execution as b


def append(vals, tensor):
    vals.extend(tensor.detach().cpu().float().contiguous().view(-1).tolist())


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--seed', type=int, default=0)
    ap.add_argument('--out', default=str(Path(__file__).resolve().parents[1] / 'results' / 'realtime_nn_weights.bin'))
    a = ap.parse_args()

    m = b.train(a.seed).eval()
    vals = []
    append(vals, m.emb.weight)
    for blk in m.blocks:
        for layer in (blk.selfp, blk.neigh, blk.ff1, blk.ff2):
            append(vals, layer.weight)
            append(vals, layer.bias)
    append(vals, m.head.weight)
    append(vals, m.head.bias)

    out = Path(a.out)
    out.parent.mkdir(parents=True, exist_ok=True)
    with out.open('wb') as f:
        f.write(struct.pack('<I', len(vals)))
        array.array('f', vals).tofile(f)

    hard = getattr(m, 'hard', None)
    if hard is None:
        hard = m.hard_budget
    with torch.no_grad():
        acc = {str(budget): float((hard(b.X, budget).argmax(1) == b.Y).float().mean()) for budget in b.BUDGETS}

    print(json.dumps({'seed': a.seed, 'float_count': len(vals), 'bytes': 4 + 4 * len(vals), 'accuracy': acc, 'out': str(out)}, indent=2))


if __name__ == '__main__':
    main()
