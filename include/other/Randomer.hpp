#pragma once
#include "XCPC.h"

struct Gen {
    unsigned int seed;
    std::mt19937 engine;
    Gen() : seed{std::random_device{}()}, engine(seed) {}
};
template <typename T>
struct Randomer {
    Gen G;
    std::uniform_int_distribution<T> distribution;
    Randomer(T min, T max) : distribution(min, max) {}
    T operator()() { return distribution(G.engine); }
};


std::mt19937_64 rng64(std::chrono::steady_clock::now().time_since_epoch().count());
i64 mt_rand(i64 max) {
    return rng64() % max;
}