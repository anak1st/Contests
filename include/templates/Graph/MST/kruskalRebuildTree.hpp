#pragma once
#include "XCPC.h"

std::pair<std::vector<int>, std::vector<int>> kruskalRebuildTree(
    int n, std::vector<std::array<int, 3>> edges) {
    std::vector<int> f(2 * n);
    std::iota(f.begin(), f.end(), 0);
    std::function<int(int)> find = [&](int x) {
        if (x != f[x]) f[x] = find(f[x]);
        return f[x];
    };

    std::sort(edges.begin(), edges.end(), [](auto a, auto b) { return a[2] < b[2]; });

    std::vector<int> v(n + 1);
    std::vector<int> p(2 * n);
    for (auto [x, y, w] : edges) {
        x = find(x);
        y = find(y);
        if (x == y) continue;

        f[x] = f[y] = v.size();
        p[x] = p[y] = v.size();
        v.push_back(w);
    }

    p.resize(v.size());
    return {v, p};
}