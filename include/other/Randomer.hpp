#pragma once
#include <bits/stdc++.h>

using i64 = long long;

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


std::mt19937 e{std::random_device{}()};
int my_rand(int min, int max) {
    std::uniform_int_distribution<int> d(min, max);
    return d(e);
}