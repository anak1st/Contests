#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    std::string tencent = "tencent";
    std::vector<std::vector<i64>> dp(n, std::vector<i64>(m));
    for (int t = 0; t < tencent.length(); t++) {
        std::vector<std::vector<i64>> ndp(n, std::vector<i64>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i][j] == tencent[t]) {
                    if (t == 0) {
                        ndp[i][j] = 1;
                    } else {
                        if (i > 0      && s[i - 1][j] == tencent[t - 1]) ndp[i][j] += dp[i - 1][j];
                        if (i + 1 < n  && s[i + 1][j] == tencent[t - 1]) ndp[i][j] += dp[i + 1][j];
                        if (j > 0      && s[i][j - 1] == tencent[t - 1]) ndp[i][j] += dp[i][j - 1];
                        if (j + 1 < m  && s[i][j + 1] == tencent[t - 1]) ndp[i][j] += dp[i][j + 1];
                    }
                }
            }
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         std::cerr << ndp[i][j] << " ";
        //     }
        //     std::cerr << '\n';
        // }
        dp = ndp;
    }
    
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += dp[i][j];
        }
    }
    std::cout << ans;

    return 0;
}