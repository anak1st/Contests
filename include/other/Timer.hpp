#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <iostream>

struct Timer {
    using clock = std::chrono::high_resolution_clock;
    std::chrono::time_point<clock> start, end;
    std::chrono::duration<float> duration;

    Timer() {
        std::cerr << "[Start]" << std::endl;
        start = clock::now();
    }

    ~Timer() {
        end = clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.0f;
        std::cerr << "[End] time took " << ms << "ms" << std::endl;
    }
};

#endif