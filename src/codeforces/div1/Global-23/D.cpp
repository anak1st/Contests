/**
 * @author: XiaFan
 * @date: 10-20 19:21
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int x;
        std::cin >> x;
        x--;
        adj[x].push_back(i);
    }
    std::vector<int> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    std::vector<std::array<int, 2>> f(n);
    std::vector<std::array<i64, 2>> dp(n);
    std::function<void (int)> dfs = [&](int x) {
        int child = adj[x].size();
        for (auto y : adj[x]) {
            f[y][0] = floor(1.0 * f[x][0] / child);
            f[y][1] = ceil (1.0 * f[x][1] / child);
            dfs(y);
        }
        std::sort(adj[x].begin(), adj[x].end(), 
            [&](int i, int j) {
                return dp[i][1] - dp[i][0] > dp[j][1] - dp[j][0];
            }
        );
        for (auto k : {0, 1}) {
            int total = f[x][k];
            dp[x][k] = 1LL * s[x] * total;
            for (int j = 0; j < child; j++) {
                int y = adj[x][j];
                // next = 1 -> high
                // next = 0 -> low
                int next = f[y][0] * child + (j + 1) <= total;
                dp[x][k] += dp[y][next];
            }
        }
    };

    f[0] = {k, k};
    dfs(0);
    std::cout << dp[0][1] << "\n";
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