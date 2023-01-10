/**
 * @author: XiaFan
 * @date: 11-20 12:25
 **/
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 x, y, z;
    std::cin >> x >> y >> z;
    long double ans = std::min(1.0L, 1.0L * x / (z * y));
    std::cout << std::fixed << std::setprecision(15) << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}