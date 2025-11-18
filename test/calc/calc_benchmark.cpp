#include <benchmark/benchmark.h>

#include <random>

#include "calc/calc.h"

static void BM_naive_deduplicate(benchmark::State &state) {
    static std::vector<std::string> input;
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<char> char_dist('a', 'z');

    for (auto _ : state) {
        state.PauseTiming();
        for (int i = 0; i < 10000; ++i) {
            std::string str;
            for (int j = 0; j < 10; ++j) {
                str += char_dist(rng);
            }
            input.push_back(str);
        }
        state.ResumeTiming();
        auto ret = naive_deduplicate(input);
        benchmark::DoNotOptimize(ret);
    }
}
// Register the function as a benchmark
// Define another benchmark
static void BM_deduplicate(benchmark::State &state) {
    static std::vector<std::string> input;
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<char> char_dist('a', 'z');

    int N = state.range(0);

    for (auto _ : state) {
        state.PauseTiming();
        for (int i = 0; i < N; ++i) {
            std::string str;
            for (int j = 0; j < 10; ++j) {
                str += char_dist(rng);
            }
            input.push_back(str);
        }
        state.ResumeTiming();
        auto ret = deduplicate(input);
        benchmark::DoNotOptimize(ret);
    }
    state.SetComplexityN(N);
}

BENCHMARK(BM_naive_deduplicate)
    ->RangeMultiplier(2)
    ->Range(1 << 4, 1 << 12)
    ->Complexity()
    ->Unit(benchmark::kMillisecond);

BENCHMARK(BM_deduplicate)
    ->RangeMultiplier(2)
    ->Range(1 << 4, 1 << 12)
    ->Complexity()
    ->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();
