/**
 * @author: XiaFan
 * @date: 10-11 23:35
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    if (n == 1) {
        std::cout << "No\n";
        return;
    }

    std::vector<bool> dp(n + 1);
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        int len = a[i];
        if (i - len - 1 >= 0) {
            dp[i] = std::max(dp[i], dp[i - len - 1]);
        }
        if (i + len <= n) {
            dp[i + len] = std::max(dp[i + len], dp[i - 1]);
        }
    }
    if (dp[n]) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    
    return 0;
}