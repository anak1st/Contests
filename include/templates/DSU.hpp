#pragma once
#include "templates/XCPC.h"

// Disjoint Set Union
struct DSU {
    std::vector<int> f, v;
    DSU(int n) : f(n), v(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        v[x] += v[y];
        f[y] = x;
        return true;
    }
    int cntv(int x) { return v[find(x)]; }
};
