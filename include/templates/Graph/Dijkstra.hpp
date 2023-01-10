#pragma once
#include "XCPC.h"

constexpr double inf = 1e9;
/**
 * @return std::pair<std::vector<T>,  // distance
 *         std::vector<int>>          // midpoint
 */
template <typename T>
std::pair<std::vector<T>, std::vector<int>> Dijkstra(const std::vector<std::vector<T>> &G,
                                                     int s) {
    int n = G.size();
    std::vector<T> d(n, inf);
    std::vector<int> from(n, -1);
    d[s] = 0;
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
            if (d[j] > d[k] + G[k][j]) {
                d[j] = d[k] + G[k][j];
                from[j] = k;
            }
        }
    }
    return {d, from};
}
