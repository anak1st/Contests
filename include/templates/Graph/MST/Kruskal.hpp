#pragma once
#include "XCPC.h"
#include "templates/DataStructure/DSU.hpp"

struct edge {
    int a, b;
    i64 c;
    friend bool operator<(const edge &lhs, const edge &rhs) {
        return lhs.c < rhs.c;
    }
};
// O(mlogm), m is the number of edges
i64 Kruskal(int n, std::vector<edge> edges) {
    std::sort(edges.begin(), edges.end());
    DSU dsu(n);
    i64 ans = 0;
    for (auto &[a, b, c] : edges) {
        if (dsu.merge(a, b)) {
            ans += c;
        }
    }
    return ans;
}
