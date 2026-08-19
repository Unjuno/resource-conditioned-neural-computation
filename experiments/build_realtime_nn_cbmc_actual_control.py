#!/usr/bin/env python3
import argparse
import hashlib
import json
from pathlib import Path

FUNCTIONS = [
    "rtnn_fixed_budget_ceiling_q16",
    "rtnn_fixed_infer_budget",
    "rtnn_fixed_certify_class",
]


def extract_function(src: str, name: str) -> str:
    marker = name + "("
    pos = src.find(marker)
    if pos < 0:
        raise SystemExit(f"missing function {name}")
    # Walk backward to the prior newline, preserving the deployed return type.
    start = src.rfind("\n", 0, pos) + 1
    brace = src.find("{", pos)
    if brace < 0:
        raise SystemExit(f"missing body for {name}")
    depth = 0
    end = None
    for i in range(brace, len(src)):
        ch = src[i]
        if ch == "{":
            depth += 1
        elif ch == "}":
            depth -= 1
            if depth == 0:
                end = i + 1
                break
    if end is None:
        raise SystemExit(f"unterminated body for {name}")
    return src[start:end].strip() + "\n"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--core", default="experiments/realtime_nn_real_sequence_fixed_core.c")
    ap.add_argument("--out", required=True)
    ap.add_argument("--meta", required=True)
    a = ap.parse_args()

    src = Path(a.core).read_text()
    extracted = {name: extract_function(src, name) for name in FUNCTIONS}

    preamble = r'''#include <stdint.h>
#include <stddef.h>

#define RTNN_FX_POLICY_MAX_EXIT 5u
/* The numeric threshold is deliberately abstracted: entropy10() is nondeterministic,
   so every possible continue/stop outcome is included in the proof. */
#define RTNN_FX_POLICY_TAU_Q 0

typedef struct { uint32_t opaque; } RTNNFixedWorkspace;
extern uint16_t nondet_u16(void);
extern uint8_t nondet_u8(void);
extern int32_t nondet_i32(void);

static uint8_t g_block_calls;
static uint8_t g_order_violation;

static void init_state(RTNNFixedWorkspace *w, const uint8_t p[64]) {
  (void)w; (void)p;
}
static void finish(const RTNNFixedWorkspace *w, uint8_t e, int32_t z[10]) {
  (void)w; (void)e; (void)z;
}
static int32_t entropy10(const int32_t z[10]) {
  (void)z;
  return nondet_i32();
}
static void run_block(RTNNFixedWorkspace *w, int bi) {
  (void)w;
  if ((uint8_t)bi != g_block_calls) g_order_violation = 1u;
  ++g_block_calls;
}
'''

    proofs = r'''
static uint8_t expected_allowed(uint16_t b, uint8_t deadline) {
  uint8_t allowed = rtnn_fixed_budget_ceiling_q16(b);
  if (deadline > 6u) deadline = 0u;
  if (deadline < allowed) allowed = deadline;
  if (RTNN_FX_POLICY_MAX_EXIT < allowed) allowed = RTNN_FX_POLICY_MAX_EXIT;
  return allowed;
}

void prove_actual_budget_lowering(void) {
  uint16_t b0 = nondet_u16();
  uint16_t b1 = nondet_u16();
  __CPROVER_assume(b0 <= b1);
  uint8_t c0 = rtnn_fixed_budget_ceiling_q16(b0);
  uint8_t c1 = rtnn_fixed_budget_ceiling_q16(b1);
  __CPROVER_assert(c0 <= 6u, "actual budget lowering stays in class range");
  __CPROVER_assert(c0 <= c1, "actual budget lowering is monotone");
  __CPROVER_assert((uint32_t)c0 * UINT32_C(65535) <= (uint32_t)b0 * UINT32_C(6),
                   "actual budget lowering is fail-closed");
  if (c0 < 6u)
    __CPROVER_assert((uint32_t)(c0 + 1u) * UINT32_C(65535) > (uint32_t)b0 * UINT32_C(6),
                     "actual budget lowering selects greatest fitting class");
}

void prove_actual_infer_budget_caps(void) {
  RTNNFixedWorkspace w;
  uint8_t p[64];
  int32_t z[10];
  uint16_t b = nondet_u16();
  uint8_t deadline = nondet_u8();
  uint8_t executed = 255u;
  uint8_t allowed = expected_allowed(b, deadline);
  g_block_calls = 0u;
  g_order_violation = 0u;

  rtnn_fixed_infer_budget(&w, p, b, deadline, z, &executed);

  __CPROVER_assert(g_order_violation == 0u, "actual adaptive blocks execute in canonical nested order");
  __CPROVER_assert(g_block_calls <= allowed, "actual adaptive run_block calls never exceed effective ceiling");
  __CPROVER_assert(executed == g_block_calls, "reported executed exit equals physical run_block call count");
  __CPROVER_assert(executed <= rtnn_fixed_budget_ceiling_q16(b), "reported execution never exceeds budget ceiling");
  if (deadline > 6u)
    __CPROVER_assert(executed == 0u, "invalid deadline class fails closed to zero physical blocks");
}

void prove_actual_infer_budget_null_executed(void) {
  RTNNFixedWorkspace w;
  uint8_t p[64];
  int32_t z[10];
  uint16_t b = nondet_u16();
  uint8_t deadline = nondet_u8();
  uint8_t allowed = expected_allowed(b, deadline);
  g_block_calls = 0u;
  g_order_violation = 0u;

  rtnn_fixed_infer_budget(&w, p, b, deadline, z, (uint8_t *)0);

  __CPROVER_assert(g_order_violation == 0u, "NULL-executed adaptive path keeps canonical block order");
  __CPROVER_assert(g_block_calls <= allowed, "NULL-executed adaptive path still respects effective ceiling");
}

void prove_actual_certify_class_work(void) {
  RTNNFixedWorkspace w;
  uint8_t p[64];
  int32_t z[10];
  uint8_t cls_in = nondet_u8();
  uint8_t expected = cls_in;
  if (expected > 6u) expected = 0u;
  if (RTNN_FX_POLICY_MAX_EXIT < expected) expected = RTNN_FX_POLICY_MAX_EXIT;
  g_block_calls = 0u;
  g_order_violation = 0u;

  rtnn_fixed_certify_class(&w, p, cls_in, z);

  __CPROVER_assert(g_order_violation == 0u, "certification path executes canonical nested order");
  __CPROVER_assert(g_block_calls == expected, "certification path executes exactly normalized maximum-work class");
}

int main(void) { return 0; }
'''

    rendered = preamble + "\n".join(extracted[name] for name in FUNCTIONS) + proofs
    Path(a.out).write_text(rendered)
    meta = {
        "core_path": a.core,
        "core_sha256": hashlib.sha256(src.encode()).hexdigest(),
        "functions": {
            name: {
                "sha256": hashlib.sha256(extracted[name].encode()).hexdigest(),
                "bytes": len(extracted[name].encode()),
            }
            for name in FUNCTIONS
        },
        "proof_source_sha256": hashlib.sha256(rendered.encode()).hexdigest(),
        "method": "exact function bodies mechanically extracted from deployed core; numerical kernels replaced by nondeterministic stubs only for control-flow/call-count proof"
    }
    Path(a.meta).write_text(json.dumps(meta, indent=2) + "\n")
    print(json.dumps(meta, indent=2))


if __name__ == "__main__":
    main()
