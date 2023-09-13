/**
 * @author: XiaFan
 * @date: 2023-09-05 19:25
 */
#include <bits/stdc++.h>

using i64 = long long;

std::array<i64, 3> exgcd(i64 a, i64 b) {
    if (b == 0) {
        return {a, 1, 0};
    }
    auto [g, x, y] = exgcd(b, a % b);
    return {g, y, x - a / b * y};
}

void solve() {
    i64 a, b, x;
    std::cin >> a >> b >> x;

    if (a < b) {
        std::swap(a, b);
    }

    auto res = exgcd(a, b);
    i64 g = res[0], p = res[1], q = res[2];
    if (x % g != 0) {
        std::cout << -1 << '\n';
        return;
    }
    a /= g;
    b /= g;
    p *= x / g;
    q *= x / g;

    auto fun = [&](i64 k) -> i64 {
        i64 tp = p + k * b;
        i64 tq = q - k * a;
        return std::max(2 * (tp + tq), 2 * std::abs(tp - tq) - 1);
    };

    i64 left = -1e9, right = 1e9;
    while (right - left > 1) {
        i64 lmid = (left + right) / 2;
        i64 rmid = (left + right) / 2 + 1;
        if (fun(lmid) <= fun(rmid)) {
            right = lmid;
        } else {
            left = rmid;
        }
    }

    i64 k = left;
    p += k * b;
    q -= k * a;
    i64 ans = 1e18;
    for (i64 i = -10; i <= 10; i++) {
        ans = std::min(ans, (i64)fun(i));
    }

    std::cout << ans << '\n';
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