/**
 * @author: XiaFan
 * @date: 04-18 12:28
 **/
#include <bits/stdc++.h>

typedef long long i64;
typedef unsigned long long u64;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
    std::vector<int> dp(m + 1, -1e9);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            std::cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        if(i == 1) {
            dp[1] = a[i][1];
        } else {
            for(int j = 1; j <= m; j++) {
                dp[j] += a[i][j];
            }
        }

        for(int j = 1; j <= m; j++) {
            int next = j + 1;
            if(next <= m) {
                dp[next] = std::max(dp[next], dp[j] + a[i][next]);
            }
            for(int k = 2; j * k <= m; k++) {
                next = j * k;
                dp[next] = std::max(dp[next], dp[j] + a[i][next]);
            }
        }
    }

    std::cout << dp[m] << "\n";
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