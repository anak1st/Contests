/**
 * @author: XiaFan
 * @date: 2023-01-30 14:07
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;
    std::vector<i64> w(N + 1), v(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> w[i] >> v[i];
    }

    auto run_dp = [&](int n, int m, int x) -> i64 {
        std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];
                if (i != x && j >= w[i]) {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
                }
            }
        }
        return dp[n][m];
    };

    i64 max = run_dp(N, M, 0);
    // std::cerr << "max: " << max << "\n";
    for (int i = 1; i <= N; i++) {
        // std::cerr << run_dp(N, M, i) << "\n";
        if (run_dp(N, M, i) < max) {
            std::cout << 0 << "\n";
        } else {
            std::cout << max - (run_dp(N, M - w[i], i) + v[i]) + 1 << "\n";
        }
    }

    return 0;
}