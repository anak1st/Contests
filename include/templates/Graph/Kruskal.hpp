#pragma once
#include "XCPC.h"
#include "templates/DataStructure/DSU.hpp"

struct edge {
    int a, b;
    int c;
    friend bool operator<(const edge &lhs, const edge &rhs) {
        return lhs.c < rhs.c;
    }
};
int Kruskal(int n, std::vector<edge> edges) {
    std::sort(edges.begin(), edges.end());
    DSU dsu(n);
    int ans = 0;
    for (auto &[a, b, c] : edges) {
        if (dsu.merge(a, b)) {
            ans += c;
        }
    }
    return ans;
}
