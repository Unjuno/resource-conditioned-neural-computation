#include <stdint.h>
#include <stddef.h>
#include "realtime_nn_real_sequence_fixed_timing_contract.h"

/* Bit-precise software proof harness for the RTNN runtime contract. */
#define RTNN_CLASSES 7u
#define RTNN_POLICY_MAX_EXIT 5u
#define RTNN_MODEL_ID UINT32_C(0x52544e4e)
#define RTNN_BUILD_ID UINT32_C(0x52544c31)
#define RTNN_BAD_ID UINT32_C(0xa5a55a5a)
#define RTNN_FX_S INT32_C(32768)

static const RTNNFixedConditionalTimingBinding RTNN_BINDING = {
  RTNN_MODEL_ID, RTNN_BUILD_ID,
  { UINT32_C(29843), UINT32_C(657454), UINT32_C(1285058),
    UINT32_C(1912662), UINT32_C(2540266), UINT32_C(3167870),
    UINT32_C(3167870) }
};

extern uint16_t nondet_u16(void);
extern uint32_t nondet_u32(void);
extern uint8_t nondet_u8(void);

/* Exact formula used by rtnn_fixed_budget_ceiling_q16 in the deployed core. */
uint8_t rtnn_cbmc_budget_ceiling_q16(uint16_t b) {
  return (uint8_t)(((uint32_t)b * UINT32_C(6)) / UINT32_C(65535));
}

static uint8_t min_u8(uint8_t a, uint8_t b) { return a < b ? a : b; }
static uint8_t effective_exit(uint16_t bq, uint8_t deadline_class, uint8_t preferred) {
  uint8_t allowed = rtnn_cbmc_budget_ceiling_q16(bq);
  allowed = min_u8(allowed, deadline_class);
  allowed = min_u8(allowed, (uint8_t)RTNN_POLICY_MAX_EXIT);
  return min_u8(allowed, preferred);
}

void prove_budget_lowering(void) {
  uint16_t b0 = nondet_u16(), b1 = nondet_u16();
  __CPROVER_assume(b0 <= b1);
  uint8_t c0 = rtnn_cbmc_budget_ceiling_q16(b0);
  uint8_t c1 = rtnn_cbmc_budget_ceiling_q16(b1);
  __CPROVER_assert(c0 <= 6u, "budget class is in range");
  __CPROVER_assert(c1 <= 6u, "larger-budget class is in range");
  __CPROVER_assert(c0 <= c1, "budget lowering is monotone");
  __CPROVER_assert((uint32_t)c0 * UINT32_C(65535) <= (uint32_t)b0 * UINT32_C(6),
                   "lowered class is fail-closed under continuous budget");
  if (c0 < 6u)
    __CPROVER_assert((uint32_t)(c0 + 1u) * UINT32_C(65535) > (uint32_t)b0 * UINT32_C(6),
                     "lowering selects greatest finite class that fits");
}

void prove_deadline_admission(void) {
  uint32_t d = nondet_u32();
  int8_t a = rtnn_fixed_admit_total_cycles(d, RTNN_MODEL_ID, RTNN_BUILD_ID, &RTNN_BINDING);
  __CPROVER_assert(rtnn_fixed_admit_total_cycles(d, RTNN_BAD_ID, RTNN_BUILD_ID, &RTNN_BINDING) == -1,
                   "wrong model identity fails closed");
  __CPROVER_assert(rtnn_fixed_admit_total_cycles(d, RTNN_MODEL_ID, RTNN_BAD_ID, &RTNN_BINDING) == -1,
                   "wrong build identity fails closed");
  __CPROVER_assert(rtnn_fixed_admit_total_cycles(d, RTNN_MODEL_ID, RTNN_BUILD_ID,
                   (const RTNNFixedConditionalTimingBinding *)0) == -1,
                   "null binding fails closed");
  if (a < 0) {
    __CPROVER_assert(d < RTNN_BINDING.total_upper_cycles[0],
                     "no class admitted exactly when class zero does not fit");
  } else {
    __CPROVER_assert(a <= 6, "admitted class is in range");
    __CPROVER_assert(RTNN_BINDING.total_upper_cycles[(uint8_t)a] <= d,
                     "admitted class timing binding fits deadline");
    for (uint8_t c = (uint8_t)a + 1u; c < RTNN_CLASSES; ++c)
      __CPROVER_assert(RTNN_BINDING.total_upper_cycles[c] > d,
                       "admission chooses greatest class that fits");
  }
}

/*
 * Arbitrary partial-certification table. A symbolic probe class k makes each
 * assertion universal over k without duplicating a second seven-element
 * assertion loop, while the actual repository admission implementation still
 * scans all seven entries.
 */
void prove_partial_certification_fail_closed(void) {
  RTNNFixedConditionalTimingBinding b;
  b.model_id = RTNN_MODEL_ID;
  b.build_id = RTNN_BUILD_ID;
  for (uint8_t c = 0; c < RTNN_CLASSES; ++c) b.total_upper_cycles[c] = nondet_u32();
  uint32_t d = nondet_u32();
  uint8_t k = nondet_u8();
  __CPROVER_assume(k < RTNN_CLASSES);

  int8_t a = rtnn_fixed_admit_total_cycles(d, RTNN_MODEL_ID, RTNN_BUILD_ID, &b);
  if (a < 0) {
    __CPROVER_assert(b.total_upper_cycles[k] == RTNN_FIXED_BOUND_INVALID ||
                     b.total_upper_cycles[k] > d,
                     "no-admission implies arbitrary certified class k does not fit");
  } else {
    __CPROVER_assert(a <= 6, "partial-certification admission is in range");
    __CPROVER_assert(b.total_upper_cycles[(uint8_t)a] != RTNN_FIXED_BOUND_INVALID,
                     "admitted class is certified");
    __CPROVER_assert(b.total_upper_cycles[(uint8_t)a] <= d,
                     "admitted certified class fits deadline");
    if (k > (uint8_t)a)
      __CPROVER_assert(b.total_upper_cycles[k] == RTNN_FIXED_BOUND_INVALID ||
                       b.total_upper_cycles[k] > d,
                       "arbitrary higher certified class k does not also fit");
  }
}

void prove_effective_execution_safety(void) {
  uint16_t bq = nondet_u16();
  uint32_t d = nondet_u32();
  uint8_t preferred = nondet_u8();
  __CPROVER_assume(preferred <= RTNN_POLICY_MAX_EXIT);
  int8_t admitted = rtnn_fixed_admit_total_cycles(d, RTNN_MODEL_ID, RTNN_BUILD_ID, &RTNN_BINDING);
  if (admitted >= 0) {
    uint8_t budget_class = rtnn_cbmc_budget_ceiling_q16(bq);
    uint8_t e = effective_exit(bq, (uint8_t)admitted, preferred);
    __CPROVER_assert(e <= budget_class, "execution never exceeds budget ceiling");
    __CPROVER_assert(e <= (uint8_t)admitted, "execution never exceeds deadline ceiling");
    __CPROVER_assert(e <= preferred, "execution never exceeds preferred useful compute");
    __CPROVER_assert(e <= RTNN_POLICY_MAX_EXIT, "execution never exceeds policy maximum");
    __CPROVER_assert(RTNN_BINDING.total_upper_cycles[e] <= RTNN_BINDING.total_upper_cycles[(uint8_t)admitted],
                     "executed class no slower than admitted binding");
    __CPROVER_assert(RTNN_BINDING.total_upper_cycles[e] <= d,
                     "executed class timing binding stays within deadline");
  }
}

static uint32_t ct_mask32(uint32_t c) { return 0u - (c & 1u); }
static int32_t ct_select_i32(uint32_t m, int32_t t, int32_t f) {
  return (int32_t)(((uint32_t)t & m) | ((uint32_t)f & ~m));
}
static uint32_t exp_lut_high_index(int32_t x) {
  const int32_t lo = -32 * RTNN_FX_S;
  uint32_t mhi = ct_mask32((uint32_t)(x > 0));
  int32_t xc = ct_select_i32(mhi, 0, x);
  uint32_t mlo = ct_mask32((uint32_t)(xc < lo));
  xc = ct_select_i32(mlo, lo, xc);
  uint32_t i = (uint32_t)(xc - lo) >> 7;
  i -= i >> 13;
  return i + 1u;
}
static uint32_t gelu_lut_high_index(int32_t x) {
  const int32_t lo = -8 * RTNN_FX_S, hi = 8 * RTNN_FX_S;
  uint32_t mhi = ct_mask32((uint32_t)(x > hi));
  int32_t xc = ct_select_i32(mhi, hi, x);
  uint32_t mlo = ct_mask32((uint32_t)(xc < lo));
  xc = ct_select_i32(mlo, lo, xc);
  uint32_t i = (uint32_t)(xc - lo) >> 7;
  i -= i >> 12;
  return i + 1u;
}
void prove_lut_index_bounds(void) {
  int32_t x0 = (int32_t)nondet_u32(), x1 = (int32_t)nondet_u32();
  __CPROVER_assert(exp_lut_high_index(x0) <= 8192u,
                   "exp LUT high interpolation index is in fx_exp_lut[8193]");
  __CPROVER_assert(gelu_lut_high_index(x1) <= 4096u,
                   "GELU LUT high interpolation index is in fx_gelu_lut[4097]");
}

int main(void) { return 0; }
