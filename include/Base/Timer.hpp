#pragma once

#include <chrono>
#include <iostream>

struct Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

    std::chrono::duration<float> duration;

    Timer() {
        std::cerr << "[Start Timer]" << std::endl;
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.0f;
        std::cerr << "[End Timer] timer took " << ms << "ms" << std::endl;
    }
};
