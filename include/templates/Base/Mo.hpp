#pragma once
#include <bits/stdc++.h>

using i64 = long long;


void solve(int n, std::vector<std::tuple<int, int, int>> Q) {
    auto add = [&](int x) -> void {
        
    };

    auto del = [&](int x) -> void {
        
    };

    int BLOCK_SIZE = int(ceil(pow(n, 0.5)));
    std::sort(Q.begin(), Q.end(), [&](const auto &a, const auto &b) -> bool {
        auto [al, ar, am] = a;
        auto [bl, br, bm] = b;
        if (al / BLOCK_SIZE != bl / BLOCK_SIZE) return al < bl;
        if (al / BLOCK_SIZE & 1) return ar < br;
        return ar > br;
    });
    int l = 0, r = -1;
    for (auto [ql, qr, qm] : Q) {
        while (l > ql) add(--l);
        while (r < qr) add(++r);
        while (l < ql) del(l++);
        while (r > qr) del(r--);

        // ans
    }
}