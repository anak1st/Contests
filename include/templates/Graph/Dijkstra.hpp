#pragma once
#include "XCPC.h"

constexpr double inf = 1e9;
constexpr int N = 5000;
int n;
i64 G[N][N];

template <typename T>
std::vector<T> Dijkstra() {
    std::vector<T> d(n, inf);
    d[0] = 0;
    std::vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        int k = -1;
        for (int j = 0; j < n; j++) {
            if (vis[j]) continue;
            if (k == -1 || d[j] < d[k]) {
                k = j;
            }
        }
        vis[k] = true;
        for (int j = 0; j < n; j++) {
            if (vis[j]) continue;
            d[j] = std::min(d[j], d[k] + G[k][j]);
        }
    }
    return d;
}
