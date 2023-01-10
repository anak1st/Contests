#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> parent(n, -1);
    auto dfs = [&](auto dfs, int x) -> void {
        for (auto y : adj[x]) {
            if (y == parent[x]) continue;
            parent[y] = x;
            dfs(dfs, y);
        }
    };
    dfs(dfs, 0);

    std::vector f(n + n, std::vector<int>(n + n, -1));
    /**
     * @param b parent of a
     * @param d parent of c
     */
    auto rec = [&](auto rec, int a, int b, int c, int d) -> int {
        // 方向错误，反向节点需要 + n
        int u = a, v = c;
        if (parent[a] != b) u += n;
        if (parent[c] != d) v += n;
        if (f[u][v] != -1) {
            return f[u][v];
        }
        int &res = f[u][v];
        res = 0;
        for (auto x : adj[a]) {
            if (x == b) continue;
            res = std::max(res, rec(rec, x, a, c, d));
        }
        for (auto y : adj[c]) {
            if (y == d) continue;
            res = std::max(res, rec(rec, a, b, y, c));
        }
        if (s[a] == s[c]) {
            res = std::max(res, 1);
            for (auto x : adj[a]) {
                if (x == b) continue;
                for (auto y : adj[c]) {
                    if (y == d) continue;
                    res = std::max(res, 1 + rec(rec, x, a, y, c));
                }
            }
        }
        return res;
    };

    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (auto j : adj[i]) {
            ans = std::max(ans, 2 * rec(rec, i, j, j, i));
            for (auto k : adj[i]) {
                if (k == j) continue;
                ans = std::max(ans, 2 * rec(rec, j, i, k, i) + 1);
            }
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    std::cin >> T;
    while (T--) solve();

    return 0;
}
