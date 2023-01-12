#pragma once
#include "XCPC.h"

// Sparse Table
template <typename T, class F = std::function<T(const T &, const T &)>> struct ST {
    int n;
    std::vector<std::vector<T>> mat;
    F fn;
    ST(const std::vector<T> &a, const F &f) : n(int(a.size())), fn(f) {
        init();
    }
    void init() {
        int max_log = 32 - clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int i = 1; i < max_log; i++) {
            int m = n - (1 << i) + 1;
            mat[i].resize(m);
            for (int j = 0; j < m; j++) {
                mat[i][j] = fn(mat[i - 1][j], mat[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    T get(int from, int to) const {
        // assert(0 <= from && from <= to && to < n);
        int lg = 32 - clz(to - from + 1) - 1;
        return fn(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};
