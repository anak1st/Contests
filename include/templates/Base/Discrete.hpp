#pragma once
#include <bits/stdc++.h>

using i64 = long long;

void Discrete(std::vector<int> &a) {
    std::vector<int> b(a);
    std::sort(b.begin(), b.end());
    b.erase(std::unique(b.begin(), b.end()), b.end());
    for (auto &x : a) {
        x = std::lower_bound(b.begin(), b.end(), x) - b.begin();
    }
}