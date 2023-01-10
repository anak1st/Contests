#pragma once
#include "XCPC.h"
#include "templates/DSU.hpp"

template <typename T> struct edge {
    int a, b;
    T c;
    friend bool operator<(const edge &lhs, const edge &rhs) { return lhs.c < rhs.c; }
};
template <typename T> int Kruskal(int n, std::vector<edge<T>> edges) {
    std::sort(edges.begin(), edges.end());
    DSU dsu(n);
    int ans = 0;
    for (auto &e : edges) {
        if (dsu.merge(e.a, e.v)) {
            ans += e.c;
        }
    }
    return ans;
}
