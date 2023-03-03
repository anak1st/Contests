#pragma once
#include "XCPC.h"

// Simulated Annealing
// F -> to the min
double SimulatedA(double begin, std::function<double(double)> F) {
    double T = 200, eps = 1e-15, k = 0.998;
    double L = 1, R = 1e9;
    double ans = begin;
    while (T > eps) {
        double now = ans + (rand() * 2 - RAND_MAX) * T;
        now = std::clamp(now, L, R);
        double dE = F(now) - F(ans);
        if (dE < 0) {
            ans = now;
        } else if (exp(-dE / T) * RAND_MAX > rand()) {
            ans = now;
        }
        T *= k;
    }
    return ans;
}