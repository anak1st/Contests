/**
 * @author: XiaFan
 * @date: 2023-01-16 22:10
 **/
#include <bits/stdc++.h>
#include <debug/vector>
using i64 = long long;

template <class Info, class Merge = std::plus<Info>> struct SegTree {
    const int n;
    const Merge merge;
    __gnu_debug::vector<Info> info;
    constexpr int ls(int p) const { return 2 * p;     }
    constexpr int rs(int p) const { return 2 * p + 1; }
    SegTree(int n) : n(n), merge(Merge()), info(4 << std::__lg(n)) {}
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
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(ls(p), l, m, x, v);
        } else {
            modify(rs(p), m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    // void rangeModify(int p, int l, int r, int x, int y, const Info &v) {
    //     if (l >= y || r <= x) {
    //         return;
    //     }
    //     if (x <= l && r <= y && r - l == 1) {
    //         info[p] = v;
    //         return;
    //     }
    //     int m = (l + r) / 2;
    //     rangeModify(ls(p), l, m, x, y, v);
    //     rangeModify(rs(p), m, r, x, y, v);
    //     pull(p);
    // }
    // void rangeModify(int l, int r, const Info &v) {
    //     rangeModify(1, 0, n, l, r, v);
    // }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (x <= l && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return merge(rangeQuery(ls(p), l, m, x, y), 
                     rangeQuery(rs(p), m, r, x, y));
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
};
struct Info {
    int sum;
    int min, max;
    Info(int x = 0) : sum(x), min(sum), max(sum) {}
    friend Info operator+(const Info &a, const Info &b) {
        Info c;
        c.sum = a.sum + b.sum;
        c.min = std::min(a.min, b.min);
        c.max = std::max(a.max, b.max);
        return c;
    }
};


void solve() {
    int n;
    std::cin >> n;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 10;
    std::vector<Info> init(n);
    for (int i = 0; i < n; ++i) {
        init[i] = Info(1);
    }
    SegTree<Info> seg(init);
    std::cout << seg.rangeQuery(0, n).sum << std::endl;

    return 0;
}