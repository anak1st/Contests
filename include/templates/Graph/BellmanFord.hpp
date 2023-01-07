#pragma once

#include <algorithm>
#include <vector>

constexpr int inf = 1e9;

template <typename T> struct edge {
    int a, b;
    T c;
    friend bool operator<(const edge &lhs, const edge &rhs) { return lhs.c < rhs.c; }
};
template <typename T> bool BellmanFord(int n, int start, T val, std::vector<edge<T>> E) {
    std::vector<T> d(n, inf);
    d[start] = val;
    int m = e.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            auto [a, b, c] = E[j];
            d[a] = std::min(d[a], d[b] + c);
        }
    }
    for (int j = 0; j < m; j++) {
        auto [a, b, c] = E[j];
        if (d[a] > d[b] + c) {
            return true;
        }
    }
    return false;
}
