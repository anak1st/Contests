/**
 * @author: XiaFan
 * @date: 2023-11-08 20:04
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    x2 -= x1;
    y2 -= y1;
    x3 -= x1;
    y3 -= y1;

    i64 ans = 1;
    if (x2 * x3 > 0) {
        ans += std::min(std::abs(x2), std::abs(x3));
    }
    if (y2 * y3 > 0) {
        ans += std::min(std::abs(y2), std::abs(y3));
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