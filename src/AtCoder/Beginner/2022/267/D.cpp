/**
 * @author: XiaFan
 * @date: 09-05 19:28
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::vector dp(m + 1, std::vector<i64>(n + 1, -1e16));
    for (int i = 0; i <= n; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = std::max(dp[i][j], dp[i][j - 1]); 
            dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + i * a[j]); 
        }
    }

    std::cout << dp[m][n];

    return 0;
}