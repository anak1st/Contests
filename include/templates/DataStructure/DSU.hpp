#pragma once
#include "XCPC.h"

// Disjoint Set Union
struct DSU {
    int n;
    std::vector<int> f, _cntv;
    DSU(int size) : n(size), f(n), _cntv(n, 1) {
        std::iota(f.begin(), f.end(), 0);
    }
    int find(int x) {
        if (f[x] != x) {
            f[x] = find(f[x]);
        }
        return f[x];
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) {
            return false;
        }
        _cntv[x] += _cntv[y];
        f[y] = x;
        return true;
    }
    int cntv(int x) {
        return _cntv[find(x)];
    }
};
