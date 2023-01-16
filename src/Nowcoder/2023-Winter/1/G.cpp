/**
 * @author: XiaFan
 * @date: 2023-01-16 15:46
 **/
#include <bits/stdc++.h>
using i64 = long long;

double fun(double x) {
    return std::round(10.0 * std::sqrt(x));
}

template <class Info, class Merge = std::plus<Info>> struct SegTree {
    const int n;
    const Merge merge;
    std::vector<Info> info;
    SegTree(int n) : n(n), merge(Merge()), info(4 << std::__lg(n)) {}
    SegTree(std::vector<Info> init) : SegTree(init.size()) {
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p,     l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = merge(info[2 * p], info[2 * p + 1]);
    }

    void rangeModify(int p, int l, int r, int x, int y, int k) {
        if (l >= y || r <= x) {
            return;
        }
        if (info[p].skip) {
            return;
        }
        if (x <= l && r <= y && r - l == 1) {
            for (int i = 0; i < k; i++) {
                info[p].sum = fun(info[p].sum);
                info[p].min = info[p].sum;
                info[p].max = info[p].sum;
                if (info[p].sum == fun(info[p].sum)) {
                    info[p].skip = true;
                    break;
                }
            }
            return;
        }
        int m = (l + r) / 2;
        rangeModify(2 * p,     l, m, x, y, k);
        rangeModify(2 * p + 1, m, r, x, y, k);
        pull(p);
    }
    void rangeModify(int l, int r, int k) {
        rangeModify(1, 0, n, l, r, k);
    }

    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (x <= l && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return merge(rangeQuery(2 * p,     l, m, x, y), 
                     rangeQuery(2 * p + 1, m, r, x, y));
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
};
struct Info {
    i64 sum;
    i64 min, max;
    bool skip;
    Info(int x = 0) : sum(x), min(sum), max(sum), skip(false) {}
};
Info operator+(const Info &a, const Info &b) {
    Info c;
    c.sum = a.sum + b.sum;
    c.min = std::min(a.min, b.min);
    c.max = std::max(a.max, b.max);
    c.skip = a.skip && b.skip;
    return c;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<Info> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a[i] = Info(x);
    }
    SegTree<Info> seg(a);

    while (m--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int l, r, k;
            std::cin >> l >> r >> k;
            seg.rangeModify(l - 1, r, k);
        } else {
            std::cout << seg.rangeQuery(0, n).sum << "\n";
        }
    }

    return 0;
}