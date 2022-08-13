#pragma once

#include <algorithm>
#include <vector>

#include "graph/base.hpp"

constexpr int inf = 1e9;

template <typename T> 
bool BellmanFord(int n, int start, T val, std::vector<edge<T>> e) {
    std::vector<T> d(n, inf);
    d[start] = val;
    int m = e.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            auto [a, b, c] = e[j];
            d[a] = std::min(d[a], d[b] + c);
        }
    }
    for (int j = 0; j < m; j++) {
        auto [a, b, c] = e[j];
        if (d[a] > d[b] + c) {
            return true;
        }
    }
    return false;
}
