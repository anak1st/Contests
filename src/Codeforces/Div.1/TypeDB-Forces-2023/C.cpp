/**
 * @author: XiaFan
 * @date: 2023-01-30 09:50
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr i64 inf = 1e18;

void solve() {
    int n;
    i64 s;
    std::cin >> n >> s;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    auto get_max = [&](int i) -> i64 {
        if (i == 0 || i == n - 1) {
            return a[i];
        } else {
            if (a[i] <= s) {
                return a[i];
            } else if (a[i] <= 2 * s) {
                return s;
            } else {
                return a[i] - s;
            }
        }
    };
    auto get_min = [&](int i) -> i64 {
        if (i == 0 || i == n - 1) {
            return a[i];
        } else {
            if (a[i] <= s) {
                return 0;
            } else if (a[i] <= 2 * s) {
                return a[i] - s;
            } else {
                return s;
            }
        }
    };

    std::vector dp(n, std::vector<i64>(2, -inf));
    dp[0][0] = 0;
    dp[0][1] = 0;  

    for (int i = 1; i < n; i++) {
        dp[i][0] = std::min(dp[i - 1][0] + get_max(i - 1) * get_min(i), 
                            dp[i - 1][1] + get_min(i - 1) * get_min(i));
        dp[i][1] = std::min(dp[i - 1][0] + get_max(i - 1) * get_max(i), 
                            dp[i - 1][1] + get_min(i - 1) * get_max(i));
    }
    i64 ans = std::min(dp[n - 1][0], dp[n - 1][1]);
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}