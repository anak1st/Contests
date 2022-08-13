#pragma once

#include <cassert>
#include <iostream>
#include <vector>

template <typename T> class FenwickTree {
private:
    int n;
    std::vector<T> a;

    int lowbit(int x) {
        return x & -x;
    }

    T sum(int pos) {
        T val = 0;
        pos++;
        for (int i = pos; i > 0; i -= lowbit(i)) {
            val += a[i - 1];
        }
        return val;
    }

public:
    FenwickTree(int size) : n(size), a(n) {}

    FenwickTree(const std::vector<T> &v) : n(int(v.size())), a(n) {
        for (int i = 0; i < n; i++) {
            add(i, v[i]);
        }
    }

    void add(int pos, T val) {
        pos++;
        for (int i = pos; i <= n; i += lowbit(i)) {
            a[i - 1] += val;
        }
    }

    T sum(int left, int right) {
        assert(0 <= left && left <= right && right < n);
        if (left == 0) {
            return sum(right);
        } else {
            return sum(right) - sum(left - 1);
        }
    }
};
