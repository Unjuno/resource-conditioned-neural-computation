#include "realtime_nn_q4_i8_core.h"
#include "realtime_nn_q4_i8_generated.h"

#ifndef RTNN_Q_LUT_RANGE_CERTIFIED
#error "Q4 production core requires a generated LUT-range certificate"
#endif

#define RTNN_Q_ABS_STORAGE_BOUND 128
#define RTNN_MAX_RAW_LINEAR_ACC (RTNN_F * RTNN_Q_ABS_STORAGE_BOUND * RTNN_Q_ABS_STORAGE_BOUND)
#define RTNN_MAX_POSTSHIFT_F2 ((RTNN_MAX_RAW_LINEAR_ACC >> 4) + RTNN_Q_ABS_STORAGE_BOUND + 1)
#define RTNN_BLOCK_LINEAR_MACS \
    ((RTNN_L * RTNN_C * RTNN_C) + \
     ((RTNN_L - 1) * RTNN_C * RTNN_C) + \
     (RTNN_L * RTNN_F * RTNN_C) + \
     (RTNN_L * RTNN_C * RTNN_F))
#define RTNN_HEAD_LINEAR_MACS (2u * RTNN_C)
#define RTNN_BLOCK_LUT_CALLS 1728u

_Static_assert(sizeof(RTNNQ4I8Workspace) == RTNN_Q4_I8_WORKSPACE_BYTES, "workspace changed");
_Static_assert(RTNN_MAX_RAW_LINEAR_ACC == 2097152, "unexpected accumulator bound");
_Static_assert(RTNN_MAX_RAW_LINEAR_ACC < INT32_MAX, "int32 accumulator is insufficient");
_Static_assert((RTNN_MAX_POSTSHIFT_F2 * 3) < INT32_MAX, "residual multiply can overflow int32");
_Static_assert(RTNN_BLOCK_LINEAR_MACS == 91136u, "unexpected block MAC count");
_Static_assert(RTNN_Q_CERT_EFFECTIVE_INPUT_BITS == RTNN_L, "certificate input width mismatch");
_Static_assert(RTNN_Q_CERT_EFFECTIVE_INPUT_STATES == (1u << RTNN_L), "certificate state count mismatch");
_Static_assert(RTNN_Q_CERT_TANH_PRE_MIN >= RTNN_Q_LUT_LO, "certified tanh input below LUT");
_Static_assert(RTNN_Q_CERT_TANH_PRE_MAX <= RTNN_Q_LUT_HI, "certified tanh input above LUT");
_Static_assert(RTNN_Q_CERT_GELU_PRE_MIN >= RTNN_Q_LUT_LO, "certified GELU input below LUT");
_Static_assert(RTNN_Q_CERT_GELU_PRE_MAX <= RTNN_Q_LUT_HI, "certified GELU input above LUT");
_Static_assert(RTNN_Q_CERT_RESIDUAL_PRE_MIN >= RTNN_Q_LUT_LO, "certified residual input below LUT");
_Static_assert(RTNN_Q_CERT_RESIDUAL_PRE_MAX <= RTNN_Q_LUT_HI, "certified residual input above LUT");

typedef struct {
    const int8_t *sw, *sb, *nw, *nb, *f1w, *f1b, *f2w, *f2b;
} Block;

typedef struct {
    const int8_t* emb;
    Block block[RTNN_BLOCKS];
    const int8_t* hw;
    const int8_t* hb;
} Model;

static Model M;

static const RTNNQ4I8ExecutionClass CLASSES[RTNN_CLASS_COUNT] = {
    {0, 0, RTNN_HEAD_LINEAR_MACS, 0u},
    {1, 2, RTNN_HEAD_LINEAR_MACS + 2u * RTNN_BLOCK_LINEAR_MACS, 2u * RTNN_BLOCK_LUT_CALLS},
    {2, 4, RTNN_HEAD_LINEAR_MACS + 4u * RTNN_BLOCK_LINEAR_MACS, 4u * RTNN_BLOCK_LUT_CALLS},
    {3, 6, RTNN_HEAD_LINEAR_MACS + 6u * RTNN_BLOCK_LINEAR_MACS, 6u * RTNN_BLOCK_LUT_CALLS},
    {4, 8, RTNN_HEAD_LINEAR_MACS + 8u * RTNN_BLOCK_LINEAR_MACS, 8u * RTNN_BLOCK_LUT_CALLS}
};

static const int8_t* take(unsigned long* offset, unsigned long n) {
    const int8_t* p = RTNN_Q_WEIGHTS + *offset;
    *offset += n;
    return p;
}

int rtnn_q4_i8_init(void) {
    unsigned long o = 0;
    M.emb = take(&o, 2 * RTNN_C);
    for (int k = 0; k < RTNN_BLOCKS; ++k) {
        Block* q = &M.block[k];
        q->sw = take(&o, RTNN_C * RTNN_C); q->sb = take(&o, RTNN_C);
        q->nw = take(&o, RTNN_C * RTNN_C); q->nb = take(&o, RTNN_C);
        q->f1w = take(&o, RTNN_F * RTNN_C); q->f1b = take(&o, RTNN_F);
        q->f2w = take(&o, RTNN_C * RTNN_F); q->f2b = take(&o, RTNN_C);
    }
    M.hw = take(&o, 2 * RTNN_C);
    M.hb = take(&o, 2);
    return o == RTNN_Q_WEIGHT_COUNT;
}

static inline int32_t round_q4(int32_t x) {
    uint32_t ux = (uint32_t)x;
    uint32_t sign = ux >> 31;
    uint32_t mask = 0u - sign;
    uint32_t mag = (ux ^ mask) + sign;
    uint32_t q = (mag + 8u) >> 4;
    return (int32_t)((q ^ mask) + sign);
}

static inline int8_t lut_direct(const int8_t* table, int32_t x) {
    return table[x - RTNN_Q_LUT_LO];
}

static void linear_q4(
    const int8_t* w, const int8_t* b, const int8_t* x, int32_t* y, int out, int in
) {
    for (int o = 0; o < out; ++o) {
        int32_t acc = 0;
        for (int i = 0; i < in; ++i) {
            acc += (int32_t)w[o * in + i] * (int32_t)x[i];
        }
        y[o] = round_q4(acc) + (int32_t)b[o];
    }
}

static void copy_i8(int8_t* dst, const int8_t* src, int n) {
    for (int i = 0; i < n; ++i) dst[i] = src[i];
}

static void init_state(RTNNQ4I8Workspace* s, uint16_t state) {
    for (int p = 0; p < RTNN_L; ++p) {
        int bit = (state >> p) & 1;
        copy_i8(s->h[p], M.emb + bit * RTNN_C, RTNN_C);
    }
}

static void run_block(RTNNQ4I8Workspace* s, int bi) {
    const Block* q = &M.block[bi];
    for (int p = 0; p < RTNN_L; ++p) {
        linear_q4(q->sw, q->sb, s->h[p], s->a, RTNN_C, RTNN_C);
        if (p < RTNN_L - 1) {
            linear_q4(q->nw, q->nb, s->h[p + 1], s->n, RTNN_C, RTNN_C);
        } else {
            for (int j = 0; j < RTNN_C; ++j) s->n[j] = q->nb[j];
        }
        for (int j = 0; j < RTNN_C; ++j) {
            s->z[p][j] = lut_direct(RTNN_Q_TANH, s->a[j] + s->n[j]);
        }
        linear_q4(q->f1w, q->f1b, s->z[p], s->pre, RTNN_F, RTNN_C);
        for (int j = 0; j < RTNN_F; ++j) {
            s->tmp[p][j] = lut_direct(RTNN_Q_GELU, s->pre[j]);
        }
        linear_q4(q->f2w, q->f2b, s->tmp[p], s->out, RTNN_C, RTNN_F);
        for (int j = 0; j < RTNN_C; ++j) {
            s->ff[p][j] = s->out[j];
            s->h[p][j] = lut_direct(
                RTNN_Q_TANH,
                (int32_t)s->z[p][j] + round_q4(s->out[j] * 3)
            );
        }
    }
}

static RTNNQ4I8Result finish(const RTNNQ4I8Workspace* s) {
    int32_t y[2];
    linear_q4(M.hw, M.hb, s->h[0], y, 2, RTNN_C);
    RTNNQ4I8Result r = {y[0], y[1]};
    return r;
}

static RTNNQ4I8Result infer_depth(RTNNQ4I8Workspace* s, uint16_t x, int depth) {
    init_state(s, x);
    for (int i = 0; i < depth; ++i) run_block(s, i);
    return finish(s);
}

RTNNQ4I8Result rtnn_q4_i8_infer(RTNNQ4I8Workspace* s, uint16_t x, uint8_t c) {
    switch (c) {
        case 0: return infer_depth(s, x, 0);
        case 1: return infer_depth(s, x, 2);
        case 2: return infer_depth(s, x, 4);
        case 3: return infer_depth(s, x, 6);
        case 4: return infer_depth(s, x, 8);
        default: return infer_depth(s, x, 0);
    }
}

const RTNNQ4I8ExecutionClass* rtnn_q4_i8_execution_classes(void) {
    return CLASSES;
}
