/**
 * @author: XiaFan
 * @date: 2023-02-03 15:13
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    std::vector<int> d(n, -1);
    d[0] = 0;
    std::queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, w] : adj[u]) {
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    int len = d[n - 1];
    if (len < m) {
        std::cout << len << "\n";
    } else {
        int ans = 1e9;
        for (auto [v, w] : adj[0]) {
            ans = std::min(ans, w);
        }
        ans += len - 1;
        std::cout << ans << "\n";
    }

    return 0;
}