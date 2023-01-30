/**
 * @author: XiaFan
 * @date: 2023-01-30 14:41
 **/
#include <bits/stdc++.h>
using i64 = long long;

template <typename T> T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 k, q;
    std::cin >> k >> q;
    i64 n = power(2LL, k);

    auto dfs1 = [&](auto &&dfs1, i64 p, i64 l, i64 r, i64 x) -> i64 {
        // std::cerr << p << " " << l << " " << r << "\n";
        if (p == x) {
            return 1;
        }
        if (x < p) {
            return dfs1(dfs1, (l + p - 1) / 2, l, p - 1, x) + 1;
        } else {
            return dfs1(dfs1, (p + 1 + r) / 2, p + 1, r, x) + p - l + 1;
        }
    };

    auto dfs2 = [&](auto &&dfs2, i64 p, i64 l, i64 r, i64 x) -> i64 {
        // std::cerr << p << " " << l << " " << r << "\n";
        if (p == x) {
            return r - l + 1;
        }
        if (x < p) {
            return dfs2(dfs2, (l + p - 1) / 2, l, p - 1, x);
        } else {
            return dfs2(dfs2, (p + 1 + r) / 2, p + 1, r, x) + p - l;
        }
    };

    while (q--) {
        i64 x;
        std::cin >> x;
        i64 ans1 = dfs1(dfs1, n, 1, n, x);
        i64 ans2 = x;
        i64 ans3 = dfs2(dfs2, n, 1, n, x);
        std::cout << ans1 << " " << ans2 << " " << ans3 << "\n";
    }

    return 0;
}