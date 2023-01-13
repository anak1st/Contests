#pragma once
#include "XCPC.h"

struct Timer {
    using Clock = std::chrono::high_resolution_clock;
    std::chrono::time_point<Clock> start, end;
    Timer() {
        std::cerr << "[Start]" << std::endl;
        start = Clock::now();
    }
    ~Timer() {
        end = Clock::now();
        std::chrono::duration<float> duration = end - start;
        float ms = duration.count() * 1000.0f;
        std::cerr << "[End] time took " << ms << "ms" << std::endl;
    }
};
