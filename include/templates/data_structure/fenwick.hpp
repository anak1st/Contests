#pragma once

#include <cassert>
#include <vector>

// Fenwick Tree
template <typename T> class fenwick {
private:
    int n;
    std::vector<T> a;

    int lowbit(int x) {
        return x & -x;
    }

    T sum(int pos) {
        if (pos < 0) {
            return 0;
        }
        T val = 0;
        for (int i = pos + 1; i >= 1; i -= lowbit(i)) {
            val += a[i - 1];
        }
        return val;
    }

public:
    fenwick(int size) 
    : n(size), a(n) 
    {}

    fenwick(const std::vector<T> &v) 
    : n(int(v.size())), a(n) 
    {
        for (int i = 0; i < n; i++) {
            add(i, v[i]);
        }
    }

    void add(int pos, T val) {
        for (int i = pos + 1; i <= n; i += lowbit(i)) {
            a[i - 1] += val;
        }
    }

    T sum(int left, int right) {
        return sum(right) - sum(left - 1);
    }
};
