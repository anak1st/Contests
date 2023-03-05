#pragma once
#include "XCPC.h"

// 0-1 knapsack problem
// a[i] = (w, v) means that we can choose one item with weight w and value v
int KP(int t, const std::vector<std::pair<int, int>> &a) {
    int n = a.size();
    std::vector<int> f(t + 1);
    for (auto [w, v] : a) {
        for (int i = t; i >= w; i--) {
            f[i] = std::max(f[i], f[i - w] + v);
        }
    }
    return f[t];
}

// bounded knapsack problem
// a[i] = (k, w) means that we can choose k items with weight w
int BKP_v2(int t, const std::vector<std::tuple<int, int, int>> &a) {
    int n = a.size();
    std::vector<std::pair<int, int>> b;
    for (auto [k, w, v] : a) {
        int x = 0;
        while (k) {
            int y = std::min(k, 1 << x);
            b.emplace_back(y * w, y * v);
            k -= y;
            x++;
        }
    }
    return KP(t, b);
}

// bounded knapsack problem
// a[i] = (k, w) means that we can choose k items with weight w
int BKP(int t, const std::vector<std::tuple<int, int, int>> &a) {
    int n = a.size();
    std::vector<int> f(t + 1);
    for (auto [k, w, v] : a) {
        for (int i = t; i >= w; i--) {
            for (int j = 1; j <= k && j * w <= i; j++) {
                f[i] = std::max(f[i], f[i - j * w] + j * v);
            }
        }
    }
    return f[t];
}