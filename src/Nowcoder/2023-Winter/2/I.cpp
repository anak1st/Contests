/**
 * @author: XiaFan
 * @date: 2023-01-18 16:28
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr i64 inf = 1e17;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> x(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }
    i64 a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::vector<i64> v(6);
    for (int i = 1; i <= 5; i++) {
        std::cin >> v[i];
    }

    auto calc = [&](i64 h) -> i64 {
        i64 res = 0;
        for (auto xi : x) {
            xi += h;
            if (xi < a) {
                res += v[1];
            } else if (xi < b) {
                res += v[2];
            } else if (xi < c) {
                res += v[3];
            } else if (xi <= d) {
                res += v[4];
            } else {
                res += v[5];
            }
        }
        return res;
    };

    auto get_next = [&](i64 h, i64 xi) -> i64 {
        xi += h;
        if (xi > d) {
            return xi - d;
        } else if (xi > c - 1) {
            return xi - (c - 1);
        } else if (xi > b - 1) {
            return xi - (b - 1);
        } else if (xi > a - 1) {
            return xi - (a - 1);
        }
        return inf;
    };

    i64 h = 1e10;
    i64 ans = -1e17;
    while (h > -inf) {
        ans = std::max(ans, calc(h));
        i64 mv = inf;
        for (auto xi : x) {
            mv = std::min(mv, get_next(h, xi));
        }
        if (mv == inf || mv == 0) {
            break;
        }
        h -= mv;
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}