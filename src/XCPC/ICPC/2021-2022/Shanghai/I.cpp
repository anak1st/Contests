/**
 * @author: XiaFan
 * @date: 2023-11-02 16:11
 */
#include <bits/stdc++.h>

using i64 = long long;

i64 __dp[100 + 1][100 * 13 * 2 * 2 + 1][100 + 1];

int base;

i64 &dp(int i, int j, int k) { 
    return __dp[i][j + base][k]; 
}
i64 chmax(i64 &a, i64 b) { 
    return a = std::max(a, b); 
}

constexpr i64 inf = 1e18;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> v(n), t(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i] >> t[i];
    }
    int t_sum = std::accumulate(t.begin(), t.end(), 0);
    base = 2 * t_sum;

    int min = - t_sum * 2;
    int max = t_sum * 2;

    for (int i = 0; i <= n; i++) {
        for (int j = min; j <= max; j++) {
            for (int l = 0; l <= k; l++) {
                dp(i, j, l) = -inf;
            }
        }
    }
    
    dp(0, 0, 0) = 0;

    for (int i = 0; i < n; i++) {
        for (int j = min; j <= max; j++) {
            for (int l = 0; l <= k; l++) {
                chmax(dp(i + 1, j, l), dp(i, j, l));

                if (j + t[i] <= max)
                    chmax(dp(i + 1, j + t[i], l), dp(i, j, l) + v[i]);
                if (j - t[i] >= min)
                    chmax(dp(i + 1, j - t[i], l), dp(i, j, l) + v[i]);

                if (l + 1 <= k) {
                    if (j + 2 * t[i] <= max)
                        chmax(dp(i + 1, j + 2 * t[i], l + 1), dp(i, j, l) + v[i]);
                    if (j - 2 * t[i] >= min)
                        chmax(dp(i + 1, j - 2 * t[i], l + 1), dp(i, j, l) + v[i]);
                }
            }
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int l = 0; l <= k; l++) {
    //         std::cerr << dp(i, 0, l) << " \n"[l == k];
    //     }
    // }

    i64 ans = 0;
    for (int i = 0; i <= k; i++) {
        chmax(ans, dp(n, 0, i));
    }
    std::cout << ans << '\n';

    return 0;
}