/**
 * @author: XiaFan
 * @date: 04-18 15:33
 **/
#include <bits/stdc++.h>

typedef long long i64;
typedef unsigned long long u64;

void solve() {
    double maxp;
    int n;
    std::cin >> maxp >> n;
    std::vector<int> v(n + 1);
    std::vector<double> p(n + 1);

    int maxv = 0;
    for(int i = 1; i <= n; i++) {
        std::cin >> v[i] >> p[i];
        maxv += v[i];
    }

    std::vector<std::vector<double>> dp(n + 1, std::vector<double>(maxv + 1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= maxv; j++) {
            if(j >= v[i]) {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - v[i]] * (1 - p[i]));
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= maxv; i++) {
        if(dp[n][i] >= (1 - maxp)) {
            ans = i;
        }
    }
    std::cout << ans << "\n";
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