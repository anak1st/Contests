#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

// Disjoint Set Union
struct DSU {
    std::vector<int> __f, __cntv;

    DSU(int n) : __f(n), __cntv(n, 1) {
        std::iota(__f.begin(), __f.end(), 0);
    }

    int find(int x) {
        if (__f[x] != x) {
            __f[x] = find(__f[x]);
        }
        return __f[x];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        __cntv[x] += __cntv[y];
        __f[y] = x;
        return true;
    }

    int cntv(int x) {
        return __cntv[find(x)];
    }
};

template <typename T>
struct edge {
    int a, b;
    T c;
    friend bool operator<(const edge &lhs, const edge &rhs) {
        return lhs.c < rhs.c;
    }
};

template <typename T>
int Kruskal(int n, std::vector<edge<T>> edges) {
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
