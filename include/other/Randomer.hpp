#pragma once

#include <iostream>
#include <random>

template <typename T>
class Randomer {
private:
    unsigned int seed;
    std::mt19937 engine;
    std::uniform_int_distribution<T> distribution;

public:
    Randomer(T min, T max)
    : seed(std::random_device()()), engine(seed), distribution(min, max) {}

    T operator()() { return distribution(engine); }
};
