#pragma once
#include "XCPC.h"

// ! all the range is [l, r)
struct Info {
    i64 sum, min, max;
    bool skip;
    Info(int x = 0) : sum(x), min(sum), max(sum), skip(false) {}
    friend Info operator+(const Info &a, const Info &b) {
        Info c;
        c.sum = a.sum + b.sum;
        c.min = std::min(a.min, b.min);
        c.max = std::max(a.max, b.max);
        return c;
    }
};
struct SegTree {
    const int n;
    const std::plus<Info> merge;
    std::vector<Info> info;
    constexpr int ls(int p) const { return 2 * p + 0; }
    constexpr int rs(int p) const { return 2 * p + 1; }
    SegTree(int n) : n(n), merge(std::plus<Info>()), info(4 << std::__lg(n)) {}
    SegTree(std::vector<Info> init) : SegTree(init.size()) {
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init[l];
                return;
            }
            int m = (l + r) / 2;
            build(ls(p), l, m);
            build(rs(p), m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = merge(info[ls(p)], info[rs(p)]);
    }
    void range_modify(int p, int l, int r, int x, int y, const Info &v) {
        if (l >= y || r <= x || info[p].skip) {
            return;
        }
        if (x <= l && r <= y && r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        range_modify(ls(p), l, m, x, y, v);
        range_modify(rs(p), m, r, x, y, v);
        pull(p);
    }
    /// @brief modify for [l, r)
    void range_modify(int l, int r, const Info &v) {
        range_modify(1, 0, n, l, r, v);
    }
    Info range_query(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (x <= l && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return merge(range_query(ls(p), l, m, x, y), 
                     range_query(rs(p), m, r, x, y));
    }
    /// @brief query for [l, r)
    Info range_query(int l, int r) {
        return range_query(1, 0, n, l, r);
    }
};
