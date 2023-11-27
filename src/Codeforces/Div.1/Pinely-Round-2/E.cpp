#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 1E18;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    
    std::vector<int> h(n);
    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
    }
    
    std::vector<std::vector<int>> adj(n);
    std::vector<int> deg(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        deg[v]++;
    }
    std::vector<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            q.push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        int x = q[i];
        for (auto y : adj[x]) {
            if (--deg[y] == 0) {
                q.push_back(y);
            }
        }
    }
    std::vector<i64> dp(n);
    for (int i = n - 1; i >= 0; i--) {
        int x = q[i];
        for (auto y : adj[x]) {
            dp[x] = std::max(dp[x], dp[y] + (h[y] - h[x] + k) % k);
        }
    }

    for (int i = 0; i < n; i++) {
        std::cerr << dp[i] << " \n"[i == n - 1];
    }

    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(),
        [&](int i, int j) {
            return h[i] < h[j];
        });
    
    
    for (int i = 0; i < n; i++) {
        dp[i] += h[i];
    }
    i64 res = *std::max_element(dp.begin(), dp.end());
    i64 ans = inf;
    for (auto i : p) {
        ans = std::min(ans, res - h[i]);
        res = std::max(res, dp[i] + k);
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}