/**
 * @author: XiaFan
 * @date: 2023-03-11 19:32
 **/
#include <bits/stdc++.h>
using i64 = long long;

// ! all the range is [l, r)
struct Info {
    i64 sum, min, max;
    bool skip;
    i64 cnt;
    Info(int x = 0) : sum(x), min(sum), max(sum), skip(false), cnt(0) {}
    friend Info operator+(const Info &a, const Info &b) {
        Info c;
        c.sum = a.sum + b.sum;
        c.min = std::min(a.min, b.min);
        c.max = std::max(a.max, b.max);
        c.cnt = a.cnt + b.cnt;
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
    void range_modify(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x || info[p].max < 10) {
            return;
        }
        if (x <= l && r <= y && r - l == 1) {
            assert(info[p].sum >= 10);
            i64 d = (info[p].sum + 2) / 3;
            info[p] = Info(info[p].sum - d);
            if (info[p].sum < 100) {
                info[p].cnt = 1;
            }

            return;
        }
        int m = (l + r) / 2;
        range_modify(ls(p), l, m, x, y);
        range_modify(rs(p), m, r, x, y);
        pull(p);
    }
    /// @brief modify for [l, r)
    void range_modify(int l, int r) {
        range_modify(1, 0, n, l, r);
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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<Info> init(n);
    for (int i = 0; i < n; ++i) {
        i64 x;
        std::cin >> x;
        init[i] = Info(x);
        if (x < 100) {
            init[i].cnt = 1;
        }
    }
    SegTree tree(init);

    while (m--) {
        int op, l, r;
        std::cin >> op >> l >> r;
        l--, r--;
        if (op == 1) {
            tree.range_modify(l, r + 1);
        } else if (op == 2) {
            std::cout << tree.range_query(l, r + 1).cnt << '\n';
        } else {
            std::cout << tree.range_query(l, r + 1).sum << '\n';
        }
    }

    return 0;
}