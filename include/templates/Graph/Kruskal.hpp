#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

// Disjoint Set Union
struct DSU {
    std::vector<int> _f, _cntv;
    DSU(int n) : _f(n), _cntv(n, 1) { std::iota(_f.begin(), _f.end(), 0); }
    int find(int x) {
        if (_f[x] != x) _f[x] = find(_f[x]);
        return _f[x];
    }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        _cntv[x] += _cntv[y];
        _f[y] = x;
        return true;
    }
    int cntv(int x) { return _cntv[find(x)]; }
};

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
