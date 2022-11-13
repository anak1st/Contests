#pragma once

#include <chrono>
#include <iostream>

struct timer {
    using Clock = std::chrono::high_resolution_clock;
    std::chrono::time_point<Clock> start, end;
    std::chrono::duration<float> duration;

    timer() {
        std::cerr << "[Start]" << std::endl;
        start = Clock::now();
    }

    ~timer() {
        end = Clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.0f;
        std::cerr << "[End] time took " << ms << "ms" << std::endl;
    }
};