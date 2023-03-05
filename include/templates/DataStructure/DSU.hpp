#pragma once
#include "XCPC.h"

// Disjoint Set Union
struct DSU {
    int n;
    std::vector<int> f, cntv;
    DSU(int size) : n(size), f(n), cntv(n, 1) {
        std::iota(f.begin(), f.end(), 0);
    }
    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) {
            return false;
        }
        cntv[x] += cntv[y];
        f[y] = x;
        return true;
    }
    int cnt_v(int x) {
        return cntv[find(x)];
    }
};
