#pragma once
#include "XCPC.h"

constexpr double inf = 1e9;
constexpr int N = 5000;
int n;
i64 g[N][N];

void Floyd() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}
