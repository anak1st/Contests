#pragma once

#include <algorithm>
#include <vector>

constexpr double inf = 1e9;

template <typename T> 
std::vector<T> Dijkstra(int start, T val, const std::vector<std::vector<T>> &G) {
    int n = G.size();
    std::vector<T> d(n, inf);
    d[start] = val;
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
            // d[j] = std::min(d[j], std::max(d[k], g[k][j]));
        }
    }
    return d;
}
