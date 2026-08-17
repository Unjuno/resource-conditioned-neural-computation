#include "realtime_nn_core.h"
#include "realtime_nn_weights_generated.h"
#include "realtime_nn_activation_lut_generated.h"

#define BLOCK_MACS 92160u
#define HEAD_MACS 64u
#define BLOCK_LUT_CALLS 1728u

_Static_assert(sizeof(RTNNWorkspace) == RTNN_WORKSPACE_BYTES, "RTNN workspace size changed");

typedef struct {
    const float *sw, *sb, *nw, *nb, *f1w, *f1b, *f2w, *f2b;
} Block;

typedef struct {
    const float* emb;
    Block block[RTNN_BLOCKS];
    const float* hw;
    const float* hb;
} Model;

static Model M;

static const RTNNExecutionClass CLASSES[RTNN_CLASS_COUNT] = {
    {0, 0, 64u, 0u},
    {1, 2, 184384u, 3456u},
    {2, 4, 368704u, 6912u},
    {3, 6, 553024u, 10368u},
    {4, 8, 737344u, 13824u}
};

static const float* take(unsigned long* offset, unsigned long count) {
    const float* p = RT_WEIGHTS + *offset;
    *offset += count;
    return p;
}

int rtnn_init(void) {
    unsigned long o = 0;
    M.emb = take(&o, 2 * RTNN_C);
    for (int k = 0; k < RTNN_BLOCKS; ++k) {
        M.block[k].sw = take(&o, RTNN_C * RTNN_C);
        M.block[k].sb = take(&o, RTNN_C);
        M.block[k].nw = take(&o, RTNN_C * RTNN_C);
        M.block[k].nb = take(&o, RTNN_C);
        M.block[k].f1w = take(&o, RTNN_F * RTNN_C);
        M.block[k].f1b = take(&o, RTNN_F);
        M.block[k].f2w = take(&o, RTNN_C * RTNN_F);
        M.block[k].f2b = take(&o, RTNN_C);
    }
    M.hw = take(&o, 2 * RTNN_C);
    M.hb = take(&o, 2);
    return o == RT_WEIGHT_COUNT;
}

static inline float lut(const float* table, float x) {
    if (x <= ACT_LUT_LO) return table[0];
    if (x >= ACT_LUT_HI) return table[ACT_LUT_N - 1];
    const float u = (x - ACT_LUT_LO) / ACT_LUT_STEP;
    const int i = (int)u;
    const float f = u - (float)i;
    return table[i] + f * (table[i + 1] - table[i]);
}

static inline float rt_tanh(float x) { return lut(TANH_LUT, x); }
static inline float rt_gelu(float x) { return lut(GELU_LUT, x); }

static inline void lin(const float* w, const float* b, const float* x, float* y, int out, int in) {
    for (int o = 0; o < out; ++o) {
        float s = b[o];
        for (int i = 0; i < in; ++i) s += w[o * in + i] * x[i];
        y[o] = s;
    }
}

static void copy_c(float* dst, const float* src) {
    for (int j = 0; j < RTNN_C; ++j) dst[j] = src[j];
}

static void init_state(RTNNWorkspace* s, uint16_t state) {
    for (int p = 0; p < RTNN_L; ++p) {
        const int bit = (state >> p) & 1;
        copy_c(s->h[p], M.emb + bit * RTNN_C);
    }
}

static void run_block(RTNNWorkspace* s, int bi) {
    const Block* q = &M.block[bi];
    for (int p = 0; p < RTNN_L; ++p) {
        float a[RTNN_C], n[RTNN_C];
        lin(q->sw, q->sb, s->h[p], a, RTNN_C, RTNN_C);
        if (p < RTNN_L - 1) lin(q->nw, q->nb, s->h[p + 1], n, RTNN_C, RTNN_C);
        else copy_c(n, q->nb);
        for (int j = 0; j < RTNN_C; ++j) s->z[p][j] = rt_tanh(a[j] + n[j]);
        lin(q->f1w, q->f1b, s->z[p], s->tmp[p], RTNN_F, RTNN_C);
        for (int j = 0; j < RTNN_F; ++j) s->tmp[p][j] = rt_gelu(s->tmp[p][j]);
        lin(q->f2w, q->f2b, s->tmp[p], s->ff[p], RTNN_C, RTNN_F);
        for (int j = 0; j < RTNN_C; ++j) s->h[p][j] = rt_tanh(s->z[p][j] + 0.2f * s->ff[p][j]);
    }
}

static RTNNResult finish(const RTNNWorkspace* s) {
    float y[2];
    lin(M.hw, M.hb, s->h[0], y, 2, RTNN_C);
    RTNNResult r = {y[0], y[1]};
    return r;
}

static RTNNResult d0(RTNNWorkspace* s, uint16_t x) {
    init_state(s, x);
    return finish(s);
}
static RTNNResult d2(RTNNWorkspace* s, uint16_t x) {
    init_state(s, x);
    run_block(s, 0); run_block(s, 1);
    return finish(s);
}
static RTNNResult d4(RTNNWorkspace* s, uint16_t x) {
    init_state(s, x);
    run_block(s, 0); run_block(s, 1); run_block(s, 2); run_block(s, 3);
    return finish(s);
}
static RTNNResult d6(RTNNWorkspace* s, uint16_t x) {
    init_state(s, x);
    run_block(s, 0); run_block(s, 1); run_block(s, 2); run_block(s, 3);
    run_block(s, 4); run_block(s, 5);
    return finish(s);
}
static RTNNResult d8(RTNNWorkspace* s, uint16_t x) {
    init_state(s, x);
    run_block(s, 0); run_block(s, 1); run_block(s, 2); run_block(s, 3);
    run_block(s, 4); run_block(s, 5); run_block(s, 6); run_block(s, 7);
    return finish(s);
}

RTNNResult rtnn_infer(RTNNWorkspace* s, uint16_t x, uint8_t c) {
    switch (c) {
        case 0: return d0(s, x);
        case 1: return d2(s, x);
        case 2: return d4(s, x);
        case 3: return d6(s, x);
        case 4: return d8(s, x);
        default: return d0(s, x); /* fail closed: never increase work */
    }
}

const RTNNExecutionClass* rtnn_execution_classes(void) {
    return CLASSES;
}
