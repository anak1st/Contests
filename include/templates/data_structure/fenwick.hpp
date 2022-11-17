#pragma once

#include <cassert>
#include <vector>

// Fenwick Tree
template <typename T>
class fenwick {
private:
    int n;
    std::vector<T> a;

    int lowbit(int x) { return x & -x; }

public:
    fenwick(int size) : n(size), a(n) {}

    fenwick(const std::vector<T> &v) : n(int(v.size())), a(n) {
        for (int i = 0; i < n; i++) {
            modify(i, v[i]);
        }
    }

    void modify(int pos, T val) {
        for (int i = pos + 1; i <= n; i += lowbit(i)) {
            a[i - 1] += val;
        }
    }

    T sum(int pos) {
        T val = 0;
        for (int i = pos + 1; i >= 1; i -= lowbit(i)) {
            val += a[i - 1];
        }
        return val;
    }

    T sum(int left, int right) {
        if (left > 0) {
            return sum(right) - sum(left - 1);
        } else {
            return sum(right);
        }
    }
};