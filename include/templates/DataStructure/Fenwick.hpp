#pragma once
#include "XCPC.h"

// Fenwick Tree
template <typename T> struct Fenwick {
    int n;
    std::vector<T> a;
    Fenwick(int size) : n(size), a(n) {}
    Fenwick(std::vector<T> &v) : n(v.size()), a(n) {
        for (int i = 0; i < n; i++) {
            add(i, v[i]);
        }
    }
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    // sum of [0, r]
    T sum(int r) {
        T ans = 0;
        for (int i = r + 1; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    // sum of [l, r]
    T sum_range(int l, int r) {
        if (l == 0) {
            return sum(r);
        } else {
            return sum(r) - sum(l - 1);
        }
    }
};