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

    std::vector<i64> change(k + 1);
    for (int i = 1; i <= k; i++) {
        change[i] = cold[i] - hot[i];
    }

    std::vector<i64> dp(k + 1, -inf);
    dp[0] = 0;

    i64 max = 0, add = 0;
    for (int i = 2; i <= n; i++) {
        // when choose a[i - 1]
        if (a[i] == a[i - 1]) {
            add += change[a[i]];
        }

        // when choose j where j == a[i]
        i64 val = std::max(max, dp[a[i]] + change[a[i]]);
        if (a[i] != a[i - 1])
            dp[a[i - 1]] = std::max(dp[a[i - 1]], val);
        max = std::max(max, val);
    }
    
    std::cout << sum - max - add << "\n";
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