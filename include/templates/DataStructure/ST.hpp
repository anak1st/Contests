#pragma once
#include "XCPC.h"

// Sparse Table
template <typename T, class F = std::function<T(const T &, const T &)>> 
struct ST {
    int n;
    std::vector<std::vector<T>> mat;
    F func;
    ST(const std::vector<T> &a, const F &f) : n(int(a.size())), func(f) {
        assert(n > 0);
        int t = std::__lg(n);
        mat.resize(t + 1);
        mat[0] = a;
        for (int i = 1; i <= t; i++) {
            int m = n - (1 << i) + 1;
            mat[i].resize(m);
            for (int j = 0; j < m; j++) {
                mat[i][j] = func(mat[i - 1][j], mat[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    // [from, to]
    T get(int from, int to) const {
        assert(0 <= from && from <= to && to < n);
        int lg = std::__lg(to - from + 1);
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};
