/**
 * @author: XiaFan
 * @date: 2023-02-20 19:21
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr i64 inf = 1e18;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, h;
    std::cin >> n >> h;
    std::vector<i64> x(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }

    std::vector dp(n, std::vector<i64>(n, inf));

    for (int i = 0; i < n; i++) {
        dp[i][i] = h;
    }

    auto fun = [&](int l, int r) -> i64 {
        return std::max(0LL, h - (x[r] - x[l] - 1) / 2);
    };

    for (int l = n - 1; l >= 0; l--) {
        for (int r = l + 1; r < n; r++) {
            for (int k = l; k < r; k++) {
                dp[l][r] = std::min(dp[l][r], dp[l][k] + dp[k + 1][r] - fun(l, r));
            }
        }
    }
    std::cout << dp[0][n - 1];

    return 0;
}