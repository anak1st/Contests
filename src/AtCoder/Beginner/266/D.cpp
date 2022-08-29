/**
 * @author: XiaFan
 * @date: 08-27 20:00
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr i64 P = 998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<std::array<int, 3>> a(n + 1);
    a[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        auto &[t, x, s] = a[i];
        std::cin >> t >> x >> s;
    }

    std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(5, -1e12));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 4; j++) {
            dp[i][j] = dp[i - 1][j];
            auto [t, x, s] = a[i];
            auto [pt, px, ps] = a[i - 1];
            for (int k = 0; k <= 4; k++) {
                if (pt + std::abs(j - k) <= t) {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][k]);
                }
            }
            if (j == x) {
                dp[i][j] += s;
            }
        }
    }

    i64 ans = 0;
    for (int i = 0; i <= 4; i++) {
        ans = std::max(ans, dp[n][i]);
    }

    std::cout << ans;
    return 0;
}