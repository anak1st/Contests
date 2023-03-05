#pragma once
#include "XCPC.h"

constexpr int N = 5000;
constexpr i64 inf = 4e18;
int n;
i64 G[N][N];

// O(n^2), n is the number of vertices
i64 Prime() {
    std::vector<bool> vis(n);
    std::vector<i64> d(n, inf);
    d[0] = 0;
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        int k = -1;
        for (int j = 0; j < n; j++) {
            if (vis[j]) continue;
            if (k == -1 || d[j] < d[k]) {
                k = j;
            }
        }
        vis[k] = true;
        ans += d[k];
        for (int j = 0; j < n; j++) {
            if (vis[j]) continue;
            if (d[j] > G[k][j]) {
                d[j] = G[k][j];
            }
        }
    }
    return ans;
}