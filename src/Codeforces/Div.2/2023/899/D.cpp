#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector<int> siz(n);
    std::vector<i64> add(n);
    i64 ans = 0;
    auto dfs1 = [&](auto self, int x, int p) -> void {
        siz[x] = 1;
        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }
            self(self, y, x);
            siz[x] += siz[y];
            ans += 1LL * siz[y] * (a[x] ^ a[y]);
            
            // add[y] -= siz[y] * (a[x] ^ a[y]);
            // add[y] += (n - siz[y]) * (a[x] ^ a[y]);
            add[y] += 1LL * (n - siz[y] * 2) * (a[x] ^ a[y]);
        }
    };
    dfs1(dfs1, 0, -1);
    
    auto dfs2 = [&](auto self, int x, int p) -> void {
        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }
            add[y] += add[x];
            self(self, y, x);
        }
    };
    dfs2(dfs2, 0, -1);
    
    for (int i = 0; i < n; i++) {
        std::cout << ans + add[i] << " \n"[i == n - 1];
    }
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