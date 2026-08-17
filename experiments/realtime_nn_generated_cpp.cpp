#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <numeric>
#include <random>
#include <sched.h>
#include <signal.h>
#include <string>
#include <sys/wait.h>
#include <thread>
#include <vector>

constexpr int L = 9;
constexpr int C = 32;
constexpr int F = 128;
constexpr int K = 8;
constexpr int BLOCK_LINEAR_MACS = 92160;
constexpr int HEAD_LINEAR_MACS = 64;

struct BlockParams {
    const float *self_w, *self_b, *neigh_w, *neigh_b;
    const float *ff1_w, *ff1_b, *ff2_w, *ff2_b;
};

struct Model {
    std::vector<float> weights;
    const float* emb = nullptr;
    BlockParams blocks[K]{};
    const float* head_w = nullptr;
    const float* head_b = nullptr;

    const float* take(size_t& off, size_t n) {
        const float* p = weights.data() + off;
        off += n;
        return p;
    }

    bool load(const char* path) {
        std::ifstream f(path, std::ios::binary);
        uint32_t n = 0;
        f.read(reinterpret_cast<char*>(&n), sizeof(n));
        if (!f) return false;
        weights.resize(n);
        f.read(reinterpret_cast<char*>(weights.data()), n * sizeof(float));
        if (!f) return false;

        size_t o = 0;
        emb = take(o, 2 * C);
        for (int k = 0; k < K; ++k) {
            blocks[k].self_w = take(o, C * C);
            blocks[k].self_b = take(o, C);
            blocks[k].neigh_w = take(o, C * C);
            blocks[k].neigh_b = take(o, C);
            blocks[k].ff1_w = take(o, F * C);
            blocks[k].ff1_b = take(o, F);
            blocks[k].ff2_w = take(o, C * F);
            blocks[k].ff2_b = take(o, C);
        }
        head_w = take(o, 2 * C);
        head_b = take(o, 2);
        return o == weights.size();
    }
};

inline float gelu(float x) {
    return 0.5f * x * (1.0f + std::erf(x * 0.7071067811865475f));
}

inline void linear(const float* w, const float* bias, const float* x, float* y, int out, int in) {
    for (int o = 0; o < out; ++o) {
        float s = bias[o];
        const float* row = w + o * in;
        for (int i = 0; i < in; ++i) s += row[i] * x[i];
        y[o] = s;
    }
}

struct Result { float y0, y1; };

Result infer(const Model& m, uint16_t state, int depth) {
    alignas(64) float h[L][C], z[L][C], tmp[L][F], ff[L][C];
    for (int p = 0; p < L; ++p) {
        const int bit = (state >> p) & 1;
        std::memcpy(h[p], m.emb + bit * C, sizeof(float) * C);
    }

    // Physical conditional execution: blocks >= depth are never evaluated.
    for (int bi = 0; bi < depth; ++bi) {
        const auto& q = m.blocks[bi];
        for (int p = 0; p < L; ++p) {
            float self[C], neigh[C];
            linear(q.self_w, q.self_b, h[p], self, C, C);
            if (p < L - 1) linear(q.neigh_w, q.neigh_b, h[p + 1], neigh, C, C);
            else std::memcpy(neigh, q.neigh_b, sizeof(float) * C);
            for (int j = 0; j < C; ++j) z[p][j] = std::tanh(self[j] + neigh[j]);
            linear(q.ff1_w, q.ff1_b, z[p], tmp[p], F, C);
            for (int j = 0; j < F; ++j) tmp[p][j] = gelu(tmp[p][j]);
            linear(q.ff2_w, q.ff2_b, tmp[p], ff[p], C, F);
            for (int j = 0; j < C; ++j) h[p][j] = std::tanh(z[p][j] + 0.2f * ff[p][j]);
        }
    }

    float y[2];
    linear(m.head_w, m.head_b, h[0], y, 2, C);
    return {y[0], y[1]};
}

double quantile(std::vector<double> v, double p) {
    std::sort(v.begin(), v.end());
    size_t i = static_cast<size_t>(std::ceil(p * v.size())) - 1;
    if (i >= v.size()) i = v.size() - 1;
    return v[i];
}

bool pin_cpu(int cpu) {
    cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(cpu, &set);
    return sched_setaffinity(0, sizeof(set), &set) == 0;
}

pid_t start_same_cpu_busy_worker(int cpu) {
    pid_t p = fork();
    if (p == 0) {
        pin_cpu(cpu);
        volatile double x = 1.0;
        while (true) x = x * 1.0000001 + 0.0000001;
        _exit(0);
    }
    return p;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::fprintf(stderr, "usage: %s weights.bin [reps=5000] [busy=0|1] [cpu=0]\n", argv[0]);
        return 2;
    }
    const int reps = argc > 2 ? std::atoi(argv[2]) : 5000;
    const bool busy = argc > 3 ? std::atoi(argv[3]) != 0 : false;
    const int cpu = argc > 4 ? std::atoi(argv[4]) : 0;
    const bool affinity_ok = pin_cpu(cpu);

    Model m;
    if (!m.load(argv[1])) {
        std::fprintf(stderr, "weight load failed\n");
        return 3;
    }

    const int depths[5] = {0, 2, 4, 6, 8};
    std::printf("VERIFY affinity_ok=%d\n", affinity_ok ? 1 : 0);
    for (int d : depths) {
        int correct = 0;
        for (int s = 0; s < 512; ++s) {
            const auto r = infer(m, static_cast<uint16_t>(s), d);
            const int pred = r.y1 > r.y0;
            const int label = __builtin_popcount(static_cast<unsigned>(s)) >= 5;
            correct += pred == label;
        }
        std::printf("depth=%d acc=%.9f\n", d, correct / 512.0);
    }

    pid_t child = -1;
    if (busy) {
        child = start_same_cpu_busy_worker(cpu);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    std::mt19937 rng(12345);
    std::uniform_int_distribution<int> input_dist(0, 511);
    volatile double checksum = 0.0;
    std::printf("TIMING reps=%d busy=%d\n", reps, busy ? 1 : 0);

    for (int d : depths) {
        for (int i = 0; i < 1000; ++i) {
            const auto r = infer(m, static_cast<uint16_t>(input_dist(rng)), d);
            checksum += r.y0;
        }
        std::vector<double> us;
        us.reserve(reps);
        for (int i = 0; i < reps; ++i) {
            const auto state = static_cast<uint16_t>(input_dist(rng));
            const auto t0 = std::chrono::steady_clock::now();
            const auto r = infer(m, state, d);
            const auto t1 = std::chrono::steady_clock::now();
            checksum += r.y0;
            us.push_back(std::chrono::duration<double, std::micro>(t1 - t0).count());
        }
        const double mean = std::accumulate(us.begin(), us.end(), 0.0) / us.size();
        std::printf(
            "depth=%d macs=%d p50_us=%.6f p95_us=%.6f p99_us=%.6f mean_us=%.6f max_us=%.6f\n",
            d, HEAD_LINEAR_MACS + d * BLOCK_LINEAR_MACS,
            quantile(us, 0.50), quantile(us, 0.95), quantile(us, 0.99), mean,
            *std::max_element(us.begin(), us.end()));
    }

    if (child > 0) {
        kill(child, SIGTERM);
        waitpid(child, nullptr, 0);
    }
    std::fprintf(stderr, "checksum=%f\n", checksum);
    return 0;
}
