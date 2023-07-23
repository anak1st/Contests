/**
 * @author: XiaFan
 * @date: 2023-07-21 13:57
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> b[i];
    }
    std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(3, 0));
    // 有盖子
    // 0 盖子不动
    // 1 盖子向前移
    // 2 盖子向后移

    // 不拥有盖子
    // 0 盖子不动
    // 1 获得前面的盖子

    for (int i = 1; i <= n; i++) {
        if (b[i]) {
            if (b[i - 1]) {
                dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]) + a[i];
                dp[i][1] = dp[i - 1][1] + a[i - 1];
                dp[i][2] = std::max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] + a[i]});
            } else {
                dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]) + a[i];
                dp[i][1] = dp[i - 1][0] + a[i - 1];
                dp[i][2] = std::max(dp[i - 1][0], dp[i - 1][1]);
            }
        } else {
            if (b[i - 1]) {
                dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = dp[i - 1][2] + a[i];
            } else {
                dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     std::cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << '\n';
    // }

    std::cout << std::max({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
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