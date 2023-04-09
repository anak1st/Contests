/**
 * @author: XiaFan
 * @date: 2023-03-11 18:55
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<i64, i64>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        i64 w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    std::vector<int> a{0};
    std::vector<bool> vis(n);
    std::vector<i64> dis(n, 1e18);
    vis[0] = true;
    dis[0] = 0;
    for (int i = 2; ; i++) {
        std::vector<int> b;
        for (auto u : a) {
            for (auto [v, w] : adj[u]) {
                if (vis[v]) continue;
                dis[v] = std::min(dis[v], dis[u] + w);
            }
        }

        for (auto u : a) {
            for (auto [v, w] : adj[u]) {
                if (vis[v]) continue;
                vis[v] = true;
                if (v == n - 1) {
                    std::cout << i << ' ' << dis[v] << '\n';
                    return 0;
                }
                b.push_back(v);
            }
        }
        a = b;
    }

    return 0;
}