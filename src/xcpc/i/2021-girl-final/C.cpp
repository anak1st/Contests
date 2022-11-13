/**
 * @author: XiaFan
 * @date: 10-17 19:18
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> c(n + 1), w(n + 1), cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> c[i];
        cnt[c[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> w[i];
    }

    std::vector<std::vector<int>> G(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        std::cin >> u >> v;
        G[u].push_back(v);
    }

    std::vector<int> id(n + 1, -1);
    int max_bit = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > 1) {
            id[i] = max_bit;
            max_bit++;
        }
    }

    int max_num = 1 << max_bit;
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(max_num));

    auto update = [&](int i, int j, int s) {
        int C = c[i];  // Company
        int sid = id[C];
        if (sid == -1)
            dp[i][s] = std::max(dp[i][s], dp[j][s] + w[C]);
        else {
            std::bitset<18> S(s);
            if (S[sid]) {
                dp[i][s] = std::max(dp[i][s], dp[j][s]);
            } else {
                S[sid] = true;
                int next_s = S.to_ulong();
                dp[i][next_s] = std::max(dp[i][next_s], dp[j][s] + w[C]);
            }
        }
    };

    update(1, 0, 0);

    for (int i = 1; i <= n; ++i) {
        for (int s = 0; s < max_num; s++) {
            for (int j : G[i]) {
                update(j, i, s);
            }
        }
        int ans = 0;
        for (int s = 0; s < max_num; s++) {
            ans = std::max(ans, dp[i][s]);
        }
        std::cout << ans << "\n";
    }

    return 0;
}