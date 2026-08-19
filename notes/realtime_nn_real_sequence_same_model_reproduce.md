# Reproduce the same-model real-sequence C audit

Generated model headers are build artifacts and are not committed.

```bash
OUT=/tmp/rtnn_real_sequence
rm -rf "$OUT"
mkdir -p "$OUT"

python experiments/export_realtime_nn_real_sequence_c.py --seed 63 --outdir "$OUT"

gcc -O2 -std=c11 -Iexperiments -I"$OUT" \
  experiments/realtime_nn_real_sequence_core.c \
  experiments/realtime_nn_real_sequence_core_test.c \
  -o "$OUT/core_test"
"$OUT/core_test"

gcc -O2 -std=c11 -Iexperiments -I"$OUT" \
  experiments/realtime_nn_real_sequence_core.c \
  experiments/realtime_nn_real_sequence_runtime_contract.c \
  experiments/realtime_nn_real_sequence_runtime_contract_test.c \
  -o "$OUT/contract_test"
"$OUT/contract_test"

gcc -O2 -std=c11 -ffreestanding -fno-builtin -Iexperiments -I"$OUT" \
  -c experiments/realtime_nn_real_sequence_core.c -o "$OUT/core.o"
gcc -O2 -std=c11 -ffreestanding -fno-builtin -Iexperiments -I"$OUT" \
  -c experiments/realtime_nn_real_sequence_runtime_contract.c -o "$OUT/contract.o"
gcc -r "$OUT/core.o" "$OUT/contract.o" -o "$OUT/combined.o"
nm -u "$OUT/combined.o"
```

For the five-seed lowering audit, repeat export/compile/test for seeds `60 61 62 63 64`.

The x86 `RDTSCP` timing and empirical RTOS demonstrators are diagnostics only:

```bash
gcc -O2 -std=c11 -Iexperiments -I"$OUT" \
  experiments/realtime_nn_real_sequence_core.c \
  experiments/realtime_nn_real_sequence_timing_x86.c \
  -o "$OUT/timing"
"$OUT/timing"

gcc -O2 -std=c11 -Iexperiments -I"$OUT" \
  experiments/realtime_nn_real_sequence_core.c \
  experiments/realtime_nn_real_sequence_runtime_contract.c \
  experiments/realtime_nn_real_sequence_empirical_rtos_demo.c \
  -o "$OUT/empirical_demo"
"$OUT/empirical_demo"
```

Do not interpret Linux P99 or observed maxima as WCET.
