/**
 * @author: XiaFan
 * @date: 2023-10-19 12:52
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 a, b, c;
    std::cin >> a >> b >> c;

    i64 ans = b * c;
    for (i64 i = 0; i < 40; i++) {
        i64 num = 1LL << i;
        ans = std::min(ans, a * i + b * ((c + num - 1) / num));
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