/**
 * @author: XiaFan
 * @date: 2023-07-17 14:50
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::queue<int> q;
    std::vector<int> d(n, -1);
    std::vector<int> f(n, -1);
    q.push(0);
    d[0] = 0;

    i64 ans = 0;

    while (q.size()) {
        int u = q.front();
        q.pop();
        ans++;

        bool end = true;

        for (int v : adj[u]) {
            if (d[v] == -1 && d[u] + 1 <= k) {
                d[v] = d[u] + 1;
                f[v] = u;
                q.push(v);
                end = false;
            } else if (v != f[u]) {
                //std::cerr << u + 1 << " -> " << v + 1 << " add " << k - d[u] << '\n';
                ans += k - d[u];
                end = false;
            }
        }

        if (end && adj[u].size() >= 1) {
            //std::cerr << u + 1 << " end " << k - d[u] << '\n';
            ans += k - d[u];
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}