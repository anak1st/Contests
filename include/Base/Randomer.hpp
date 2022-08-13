#pragma once

#include <iostream>
#include <random>

template <typename T> class Randomer {
private:
    unsigned int seed;
    std::mt19937 engine;
    std::uniform_int_distribution<T> distribution;

public:
    Randomer(T min, T max) : 
      seed(std::random_device()()), 
      engine(seed), d
      istribution(min, max) {}

    T operator()() {
        // cerr << seed << "\n";
        return distribution(engine);
    }
};
