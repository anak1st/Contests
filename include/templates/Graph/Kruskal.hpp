#pragma once

#include <algorithm>
#include <vector>

#include "templates/DSA/DSU.hpp"

struct edge {
    int u, v, w;
    friend bool operator<(const edge &lhs, const edge &rhs) {
        return lhs.w < rhs.w;
    }
};

int Kruskal(int n, std::vector<edge> edges) {
    std::sort(edges.begin(), edges.end());
    DSU dsu(n);
    int ans = 0;
    for (auto &e : edges) {
        if (dsu.merge(e.u, e.v)) {
            ans += e.w;
        }
    }
    return ans;
}
