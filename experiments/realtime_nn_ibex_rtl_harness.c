#include <stdint.h>
#include "realtime_nn_real_sequence_fixed_core.h"
#include "realtime_nn_real_sequence_fixed_timing_contract.h"
#include "realtime_nn_ibex_rtl_vectors_generated.h"

#define SIM_OUT  (*(volatile uint32_t *)UINT32_C(0x00020000))
#define SIM_HALT (*(volatile uint32_t *)UINT32_C(0x00020008))
#define HARNESS_MODEL_ID UINT32_C(0x52544e4e)
#define HARNESS_BUILD_ID UINT32_C(0x52544c31)

/* Measured on the final expanded pinned-RTL harness shape. Class 6 shares
   the class-5 envelope because deployed policy max_exit=5. */
static const uint32_t RTL_TOTAL[7] = {
  29843u, 657454u, 1285058u, 1912662u, 2540266u, 3167870u, 3167870u
};
static const RTNNFixedConditionalTimingBinding BINDING = {
  HARNESS_MODEL_ID, HARNESS_BUILD_ID,
  {29843u, 657454u, 1285058u, 1912662u, 2540266u, 3167870u, 3167870u}
};

static RTNNFixedWorkspace W;
static int32_t Z[10];

static void putc_r(char c) { SIM_OUT = (uint32_t)(uint8_t)c; }
static void puts_r(const char *s) { while (*s) putc_r(*s++); }
static void putu_r(uint32_t x) {
  char b[10]; unsigned n = 0;
  if (!x) { putc_r('0'); return; }
  while (x) { b[n++] = (char)('0' + (x % 10u)); x /= 10u; }
  while (n) putc_r(b[--n]);
}
static void puti_r(int32_t x) { if (x < 0) { putc_r('-'); putu_r((uint32_t)(-x)); } else putu_r((uint32_t)x); }
static void comma(void) { putc_r(','); }
static void nl(void) { putc_r('\n'); }

static inline uint32_t read_mcycle32(void) {
  uint32_t v;
  __asm__ volatile ("csrr %0, mcycle" : "=r"(v) :: "memory");
  return v;
}
__attribute__((noinline)) static void empty_call(void) { __asm__ volatile ("" ::: "memory"); }

static int argmax10(const int32_t z[10]) {
  int b = 0;
  for (int i = 1; i < 10; ++i) if (z[i] > z[b]) b = i;
  return b;
}
static uint16_t budget_for_class(uint8_t c) {
  return (uint16_t)(((uint32_t)c * 65535u + 5u) / 6u);
}
static uint32_t measure_one_overhead(void) {
  uint32_t a = read_mcycle32(); empty_call(); uint32_t b = read_mcycle32(); return b - a;
}
static uint32_t measure_two_overhead(void) {
  uint32_t a = read_mcycle32(); empty_call(); empty_call(); uint32_t b = read_mcycle32(); return b - a;
}
static void print_overhead(const char *name, uint32_t v) {
  puts_r("OVERHEAD,"); puts_r(name); comma(); putu_r(v); nl();
}
static void print_cert(uint32_t slot, uint8_t cls, uint32_t raw, int pred) {
  puts_r("CERT,"); putu_r(slot); comma(); putu_r(RTNN_RTL_TEST_INDEX[slot]); comma(); putu_r(cls); comma(); putu_r(raw); comma(); puti_r(pred); nl();
}
static void print_e2e(uint32_t slot, uint8_t cls, int8_t admitted, uint8_t executed, uint32_t raw, int pred) {
  puts_r("E2E,"); putu_r(slot); comma(); putu_r(RTNN_RTL_TEST_INDEX[slot]); comma(); putu_r(cls); comma(); puti_r(admitted); comma(); putu_r(executed); comma(); putu_r(raw); comma(); puti_r(pred); nl();
}

int main(void) {
  uint32_t oh1 = measure_one_overhead();
  uint32_t oh2 = measure_two_overhead();
  print_overhead("ONE", oh1);
  print_overhead("TWO", oh2);

  /* Reconfirm fixed-class cycle independence on three held-out inputs. */
  for (uint8_t c = 0; c < 7; ++c) {
    uint32_t a = read_mcycle32();
    rtnn_fixed_certify_class(&W, RTNN_RTL_X[0], c, Z);
    uint32_t b = read_mcycle32();
    print_cert(0, c, b - a, argmax10(Z));
  }
  for (uint32_t slot = 1; slot < RTNN_RTL_VECTOR_N; ++slot) {
    const uint8_t anchor[3] = {0u, 3u, 5u};
    for (unsigned j = 0; j < 3; ++j) {
      uint8_t c = anchor[j];
      uint32_t a = read_mcycle32();
      rtnn_fixed_certify_class(&W, RTNN_RTL_X[slot], c, Z);
      uint32_t b = read_mcycle32();
      print_cert(slot, c, b - a, argmax10(Z));
    }
  }

  /* Exercise the real admission + adaptive inference path for all three
     preferred-depth regimes and all seven external budget classes. */
  for (uint32_t slot = 0; slot < RTNN_RTL_VECTOR_N; ++slot) {
    for (uint8_t c = 0; c < 7; ++c) {
      uint16_t bq = budget_for_class(c);
      uint8_t executed = 255u;
      uint32_t a = read_mcycle32();
      int8_t admitted = rtnn_fixed_admit_total_cycles(RTL_TOTAL[c], HARNESS_MODEL_ID, HARNESS_BUILD_ID, &BINDING);
      rtnn_fixed_infer_budget(&W, RTNN_RTL_X[slot], bq,
                              admitted < 0 ? 0u : (uint8_t)admitted, Z, &executed);
      uint32_t b = read_mcycle32();
      print_e2e(slot, c, admitted, executed, b - a, argmax10(Z));
    }
  }

  puts_r("DONE\n");
  SIM_HALT = 1u;
  for (;;) { }
}
