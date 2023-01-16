/**
 * @author: XiaFan
 * @date: 2023-01-16 14:34
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::fixed << std::setprecision(20);

    int n, m;
    std::cin >> n >> m;
    std::vector dp(n + 2, std::vector<double>(m + 2));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= j; k++) { // 之前已经分配数量
                if (k == m) {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][m]);
                } else {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][k] + 1.0 * (j - k) / (m - k));
                }
            }
        }
    }

    std::cout << *std::max_element(dp[n].begin(), dp[n].end());

    return 0;
}