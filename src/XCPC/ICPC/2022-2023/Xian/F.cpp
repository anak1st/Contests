/**
 * @author: XiaFan
 * @date: 2023-10-19 12:27
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 n, c1, c2;
    std::cin >> n >> c1 >> c2;
    i64 ans = 0;
    for (i64 i = 1; i <= n; i++) {
        i64 tmp = 3 * std::min(c1, c2);
        std::string s;
        std::cin >> s;
        if (s[0] == s[1] || s[1] == s[2] || s[0] == s[2]) {
            tmp = std::min({tmp, 2 * c2, c1 + c2});
        }
        ans += tmp;
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}