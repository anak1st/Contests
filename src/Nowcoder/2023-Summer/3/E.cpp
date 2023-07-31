/**
 * @author: XiaFan
 * @date: 2023-07-24 14:24
 */
#include <bits/stdc++.h>

using i64 = long long;
constexpr int B = 30;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    std::vector<int> d(n);
    std::vector<int> vis(n);

    std::random_device seed;
    std::mt19937 gen(seed());

    auto dfs = [&](auto &&dfs, int u) -> void {
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) {
                d[v] = d[u] + 1;
                dfs(dfs, v);
            }
        }
    };

    dfs(dfs, 0);
    for (int i = 0; i < 40; i++) {
        auto bak = d;
        std::fill(vis.begin(), vis.end(), false);
        for (int j = 0; j < n; j++) {
            std::shuffle(adj[j].begin(), adj[j].end(), gen);
        }
        d[0] = 0;
        dfs(dfs, 0);
        if (d != bak) {
            std::cout << "No\n";
            return;
        }
    }

    std::cout << "Yes\n";
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