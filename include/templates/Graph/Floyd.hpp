#pragma once

#include <algorithm>
#include <vector>

/**
 * @return std::vector<std::vector<int>> 
 *         shortest path's (from i to j) mid point (close to i)
 */
template <typename T>
std::vector<std::vector<int>> Floyd(std::vector<std::vector<T>>& G) {
    int n = G.size();
    std::vector<std::vector<int>> P(n, std::vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (G[i][j] != inf && i != j) {
                P[i][j] = j;
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (G[i][k] + G[k][j] < G[i][j]) {
                    G[i][j] = G[i][k] + G[k][j];
                    P[i][j] = P[i][k];
                }
            }
        }
    }

    return P;
}
