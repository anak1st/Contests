/**
 * @author: XiaFan
 * @date: 09-11 14:31
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> b[i];
    }
    int m = 10 * 100 * 100;
    std::vector dp(n + 1, std::vector<int>(2 * m + 2, -m));
    dp[0][m] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 2 * m; j++) {
            dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
            if (j - a[i] + b[i] * k >= 0) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - a[i] + b[i] * k] + a[i]);
            }
        }
    }
    
    if (dp[n][m] == 0) {
        std::cout << "-1\n";
    } else {
        std::cout << dp[n][m] << "\n";
    }
    
    return 0;
}