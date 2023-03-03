/**
 * @author: XiaFan
 * @date: 2023-02-27 23:52
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr i64 inf = 1e18;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::vector<i64> cold(k + 1), hot(k + 1);
    for (int i = 1; i <= k; i++) {
        std::cin >> cold[i];
    }
    for (int i = 1; i <= k; i++) {
        std::cin >> hot[i];
    }
    
    i64 sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += cold[a[i]];
    }
    // std::cerr << sum << "\n";

    std::vector<i64> change(k + 1);
    for (int i = 1; i <= k; i++) {
        change[i] = cold[i] - hot[i];
    }

    auto get = [&](int now, int prev) -> i64 {
        if (prev == now) {
            return change[now];
        } else {
            return 0LL;
        }
    };

    // 做完 i 个，另一个是 j  
    std::vector dp(n + 1, std::vector<i64>(k + 1, -inf));
    
    auto chmax = [](i64 &a, i64 b) {
        a = std::max(a, b);
    };

    dp[1][0] = get(a[1], 0);
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            chmax(dp[i][j], dp[i - 1][j] + get(a[i], a[i - 1]));
            chmax(dp[i][a[i - 1]], dp[i - 1][j] + get(a[i], j));
        }
    }
    
    i64 max = 0;
    for (int i = 0; i <= k; i++) {
        max = std::max(max, dp[n][i]);
    }
    std::cout << sum - max << "\n";
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