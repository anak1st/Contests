// from jiangly
#pragma once

#include <numeric>
#include <vector>

// Disjoint Set Union
struct DSU {
    std::vector<int> f, cnt_v;

    DSU(int n) : f(n), cnt_v(n, 1) {
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
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        cnt_v[x] += cnt_v[y];
        f[y] = x;
        return true;
    }
};
