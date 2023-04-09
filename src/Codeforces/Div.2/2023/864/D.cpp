/**
 * @author: XiaFan
 * @date: 2023-04-08 23:14
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> size(n);
    std::vector<int> f(n, -1);
    std::vector<i64> impo(n);
    std::vector<std::set<std::pair<int, int>>> son(n);

    auto dfs = [&](auto dfs, int u) -> void {
        impo[u] = a[u];
        size[u] = 1;
        for (auto v : adj[u]) {
            if (v == f[u]) continue;
            f[v] = u;
            dfs(dfs, v);
            size[u] += size[v];
            impo[u] += impo[v];
            son[u].emplace(-size[v], v);
        }
    };

    dfs(dfs, 0);

    while (q--) {
        int op, x;
        std::cin >> op >> x;
        x--;
        if (op == 1) {
            std::cout << impo[x] << "\n";
        } else {
            if (son[x].empty()) {
                continue;
            }
            // from z -> x -> y
            // to   z -> y -> x
            int z = f[x];
            auto [s, y] = *son[x].begin();
            
            son[z].erase({-size[x], x});
            son[x].erase({-size[y], y});

            size[x] -= size[y];
            size[y] += size[x];
            impo[x] -= impo[y];
            impo[y] += impo[x];

            son[y].emplace(-size[x], x);
            son[z].emplace(-size[y], y);

            f[y] = z;
            f[x] = y;
        }
    }
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