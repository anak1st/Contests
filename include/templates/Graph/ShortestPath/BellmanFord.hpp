#pragma once
#include "XCPC.h"

constexpr int inf = 1e9;
struct edge {
    int a, b;
    i64 c;
    friend bool operator<(const edge &lhs, const edge &rhs) {
        return lhs.c < rhs.c;
    }
};
// return true if there is a negative cycle
bool BellmanFord(int n, std::vector<edge> E) {
    std::vector<i64> d(n, inf);
    d[0] = 0;
    int m = E.size();
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
