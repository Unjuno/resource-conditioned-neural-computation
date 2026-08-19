#include <stdint.h>
#include <stddef.h>

/*
 * Bit-precise software proof harness for the RTNN runtime contract.
 *
 * Scope:
 *   - continuous Q0.16 budget -> finite class lowering
 *   - RTL-derived timing binding -> deadline admission
 *   - arbitrary preferred compute -> effective execution ceiling
 *   - exp/GELU LUT index safety after the exact Q15 clamps
 *
 * This does not model the neural arithmetic or processor pipeline. Those are
 * covered by the exact-binary noninterference audit and pinned-Ibex RTL run.
 */

#define RTNN_CLASSES 7u
#define RTNN_POLICY_MAX_EXIT 5u
#define RTNN_MODEL_ID UINT32_C(0x52544e4e)
#define RTNN_BUILD_ID UINT32_C(0x52544c31)
#define RTNN_BAD_ID UINT32_C(0xa5a55a5a)
#define RTNN_FX_S INT32_C(32768)

/* Pinned-Ibex admission + adaptive maximum-work binding from the measured RTL run. */
static const uint32_t RTNN_TOTAL_UPPER[RTNN_CLASSES] = {
  UINT32_C(29843), UINT32_C(657454), UINT32_C(1285058),
  UINT32_C(1912662), UINT32_C(2540266), UINT32_C(3167870),
  UINT32_C(3167870)
};

extern uint16_t nondet_u16(void);
extern uint32_t nondet_u32(void);
extern uint8_t nondet_u8(void);

uint8_t rtnn_cbmc_budget_ceiling_q16(uint16_t b) {
  return (uint8_t)(((uint32_t)b * UINT32_C(6)) / UINT32_C(65535));
}

int8_t rtnn_cbmc_admit_total_cycles(uint32_t deadline,
                                    uint32_t model_id,
                                    uint32_t build_id) {
  if (model_id != RTNN_MODEL_ID || build_id != RTNN_BUILD_ID) return -1;
  int8_t best = -1;
  for (uint8_t c = 0; c < RTNN_CLASSES; ++c) {
    if (RTNN_TOTAL_UPPER[c] <= deadline) best = (int8_t)c;
  }
  return best;
}

static uint8_t min_u8(uint8_t a, uint8_t b) { return a < b ? a : b; }

/* Abstract the input-specific stopping result as any preferred exit 0..5. */
static uint8_t effective_exit(uint16_t bq, uint8_t deadline_class, uint8_t preferred) {
  uint8_t allowed = rtnn_cbmc_budget_ceiling_q16(bq);
  allowed = min_u8(allowed, deadline_class);
  allowed = min_u8(allowed, (uint8_t)RTNN_POLICY_MAX_EXIT);
  return min_u8(allowed, preferred);
}

void prove_budget_lowering(void) {
  uint16_t b0 = nondet_u16();
  uint16_t b1 = nondet_u16();
  __CPROVER_assume(b0 <= b1);

  uint8_t c0 = rtnn_cbmc_budget_ceiling_q16(b0);
  uint8_t c1 = rtnn_cbmc_budget_ceiling_q16(b1);

  __CPROVER_assert(c0 <= 6u, "budget class is in range");
  __CPROVER_assert(c1 <= 6u, "budget class is in range for larger budget");
  __CPROVER_assert(c0 <= c1, "budget lowering is monotone");

  /* c=floor(6*b/65535): the selected finite fraction never exceeds b. */
  __CPROVER_assert((uint32_t)c0 * UINT32_C(65535) <=
                   (uint32_t)b0 * UINT32_C(6),
                   "lowered class is fail-closed under the continuous budget");
  if (c0 < 6u) {
    __CPROVER_assert((uint32_t)(c0 + 1u) * UINT32_C(65535) >
                     (uint32_t)b0 * UINT32_C(6),
                     "lowering selects the greatest finite class that fits");
  }
}

void prove_deadline_admission(void) {
  uint32_t d = nondet_u32();
  int8_t a = rtnn_cbmc_admit_total_cycles(d, RTNN_MODEL_ID, RTNN_BUILD_ID);

  __CPROVER_assert(rtnn_cbmc_admit_total_cycles(d, RTNN_BAD_ID, RTNN_BUILD_ID) == -1,
                   "wrong model identity fails closed");
  __CPROVER_assert(rtnn_cbmc_admit_total_cycles(d, RTNN_MODEL_ID, RTNN_BAD_ID) == -1,
                   "wrong build identity fails closed");

  if (a < 0) {
    __CPROVER_assert(d < RTNN_TOTAL_UPPER[0],
                     "no class is admitted exactly when class zero does not fit");
  } else {
    __CPROVER_assert(a <= 6, "admitted class is in range");
    __CPROVER_assert(RTNN_TOTAL_UPPER[(uint8_t)a] <= d,
                     "admitted class timing binding fits the deadline");
    for (uint8_t c = (uint8_t)a + 1u; c < RTNN_CLASSES; ++c) {
      __CPROVER_assert(RTNN_TOTAL_UPPER[c] > d,
                       "admission chooses the greatest class that fits");
    }
  }
}

void prove_effective_execution_safety(void) {
  uint16_t bq = nondet_u16();
  uint32_t d = nondet_u32();
  uint8_t preferred = nondet_u8();
  __CPROVER_assume(preferred <= RTNN_POLICY_MAX_EXIT);

  int8_t admitted = rtnn_cbmc_admit_total_cycles(d, RTNN_MODEL_ID, RTNN_BUILD_ID);
  if (admitted >= 0) {
    uint8_t budget_class = rtnn_cbmc_budget_ceiling_q16(bq);
    uint8_t e = effective_exit(bq, (uint8_t)admitted, preferred);

    __CPROVER_assert(e <= budget_class, "execution never exceeds budget ceiling");
    __CPROVER_assert(e <= (uint8_t)admitted, "execution never exceeds deadline ceiling");
    __CPROVER_assert(e <= preferred, "execution never exceeds preferred useful compute");
    __CPROVER_assert(e <= RTNN_POLICY_MAX_EXIT, "execution never exceeds deployed policy maximum");
    __CPROVER_assert(RTNN_TOTAL_UPPER[e] <= RTNN_TOTAL_UPPER[(uint8_t)admitted],
                     "executed class is no slower than the admitted class binding");
    __CPROVER_assert(RTNN_TOTAL_UPPER[e] <= d,
                     "executed class timing binding remains within deadline");
  }
}

static uint32_t ct_mask32(uint32_t c) { return 0u - (c & 1u); }
static int32_t ct_select_i32(uint32_t m, int32_t t, int32_t f) {
  return (int32_t)(((uint32_t)t & m) | ((uint32_t)f & ~m));
}

static uint32_t exp_lut_high_index(int32_t x) {
  const int32_t lo = -32 * RTNN_FX_S;
  const int32_t step = RTNN_FX_S / 256;
  uint32_t mhi = ct_mask32((uint32_t)(x > 0));
  int32_t xc = ct_select_i32(mhi, 0, x);
  uint32_t mlo = ct_mask32((uint32_t)(xc < lo));
  xc = ct_select_i32(mlo, lo, xc);
  uint32_t off = (uint32_t)(xc - lo);
  uint32_t i = off >> 7;
  uint32_t r = off & 127u;
  uint32_t top = i >> 13;
  i -= top;
  r += top << 7;
  (void)step; (void)r;
  return i + 1u;
}

static uint32_t gelu_lut_high_index(int32_t x) {
  const int32_t lo = -8 * RTNN_FX_S;
  const int32_t hi = 8 * RTNN_FX_S;
  const int32_t step = RTNN_FX_S / 256;
  uint32_t mhi = ct_mask32((uint32_t)(x > hi));
  int32_t xc = ct_select_i32(mhi, hi, x);
  uint32_t mlo = ct_mask32((uint32_t)(xc < lo));
  xc = ct_select_i32(mlo, lo, xc);
  uint32_t off = (uint32_t)(xc - lo);
  uint32_t i = off >> 7;
  uint32_t r = off & 127u;
  uint32_t top = i >> 12;
  i -= top;
  r += top << 7;
  (void)step; (void)r;
  return i + 1u;
}

void prove_lut_index_bounds(void) {
  int32_t x0 = (int32_t)nondet_u32();
  int32_t x1 = (int32_t)nondet_u32();
  uint32_t ei = exp_lut_high_index(x0);
  uint32_t gi = gelu_lut_high_index(x1);
  __CPROVER_assert(ei <= 8192u, "exp LUT high interpolation index is in fx_exp_lut[8193]");
  __CPROVER_assert(gi <= 4096u, "GELU LUT high interpolation index is in fx_gelu_lut[4097]");
}

/* CBMC is invoked per proof function; main only keeps the file ordinary-C parsable. */
int main(void) { return 0; }
