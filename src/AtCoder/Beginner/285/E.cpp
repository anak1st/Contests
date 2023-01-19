/**
 * @author: XiaFan
 * @date: 2023-01-17 15:47
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr i64 inf = 1e15;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<i64> a(n + 1), pref(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        pref[i] = pref[i - 1] + a[(i + 1) / 2];
    }
    // dp[i][j] 表示前 i 天，连续工作 j 天的最大收益
    std::vector dp(n + 1, std::vector<i64>(n + 1, -inf));
    dp[1][0] = 0; // 第一天休息
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1]);               // 工作
            dp[i][0] = std::max(dp[i][0], dp[i - 1][j - 1] + pref[j - 1]); // 休息
        }
    }
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans = std::max(ans, dp[n][i] + pref[i]); // 第二周第一天休息
    }
    std::cout << ans << "\n";

    return 0;
}
