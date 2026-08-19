#include <stdio.h>
#include <stdint.h>
#include "realtime_nn_real_sequence_fixed_core.h"
#include "realtime_nn_ibex_rtl_vectors_generated.h"

static int argmax10(const int32_t z[10]) {
  int b = 0;
  for (int i = 1; i < 10; ++i) if (z[i] > z[b]) b = i;
  return b;
}

int main(void) {
  RTNNFixedWorkspace w;
  int32_t z[10];
  for (uint32_t n = 0; n < RTNN_RTL_VECTOR_N; ++n) {
    uint8_t pref = rtnn_fixed_preferred_exit(&w, RTNN_RTL_X[n]);
    printf("HOST,PREF,%u,%u,%u\n", (unsigned)n,
           (unsigned)RTNN_RTL_TEST_INDEX[n], (unsigned)pref);
    for (uint8_t c = 0; c < 7; ++c) {
      rtnn_fixed_certify_class(&w, RTNN_RTL_X[n], c, z);
      printf("HOST,PRED,%u,%u,%d\n", (unsigned)n, (unsigned)c, argmax10(z));
    }
  }
  return 0;
}
