#pragma once
#include "XCPC.h"

struct Gen {
    unsigned int seed;
    std::mt19937 engine;
    Gen() : seed{std::random_device{}()}, engine(seed) {}
};
template <typename T> struct Randomer {
    Gen G;
    std::uniform_int_distribution<T> distribution;
    Randomer(T min, T max) : distribution(min, max) {}
    T operator()() {
        return distribution(G.engine);
    }
};
