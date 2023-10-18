/**
 * @author: XiaFan
 * @date: 2023-09-30 23:41
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    n %= m;

    int gcd = std::gcd(n, m);
    int ans = gcd;
    n /= gcd;
    m /= gcd;

    std::cout << n << " " << m << " " << ans << '\n';

    if (__builtin_popcount(m) != 1) {
        std::cout << -1 << '\n';
        return;
    }
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