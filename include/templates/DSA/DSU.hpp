// from jiangly
#pragma once

#include <numeric>
#include <vector>

// Disjoint Set Union
class DSU {
private:
    std::vector<int> f, s;

public:
    DSU(int n) : f(n), s(n, 1) {
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
        s[x] += s[y];
        f[y] = x;
        return true;
    }

    int size(int x) {
        return s[find(x)];
    }
};
