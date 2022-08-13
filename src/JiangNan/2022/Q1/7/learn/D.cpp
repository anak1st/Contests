/**
 * @author: XiaFan
 * @date: 04-18 14:50
 **/
#include <bits/stdc++.h>

typedef long long i64;
typedef unsigned long long u64;

void solve() {
    int e, f;
    std::cin >> e >> f;
    int m = f - e;
    int n;
    std::cin >> n;
    std::vector<int> p(n + 1), w(n + 1);
    for(int i = 1; i <= n; i++) {
        std::cin >> p[i] >> w[i];
    }

    std::vector<int> dp(m + 1, 1e9);
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            for(int k = 0; j - k * w[i] >= 0; k++) {
                dp[j] = std::min(dp[j], dp[j - k * w[i]] + k * p[i]);
            }
        }
    }

    if(dp[m] >= 1e9) {
        std::cout << "This is impossible.\n";
    } else {
        std::cout << "The minimum amount of money in the piggy-bank is " << dp[m] << ".\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}