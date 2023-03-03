#include <bits/stdc++.h>

using i64 = long long;

std::vector<bool> sym;
std::map<std::vector<int>, int> tree;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    auto dfs = [&](auto self, int x, int p) -> int {
        std::vector<int> a;
        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }
            a.push_back(self(self, y, x));
        }
        std::sort(a.begin(), a.end());
        
        if (!tree.contains(a)) {
            tree[a] = sym.size();
            int i = 0;
            while (i + 1 < a.size() && a[i] == a[i + 1]) {
                i += 2;
            }
            bool ok = true;
            if (i < a.size()) {
                if (!sym[a[i]]) {
                    ok = false;
                }
                i += 1;
                while (i + 1 < a.size() && a[i] == a[i + 1]) {
                    i += 2;
                }
                if (i != a.size()) {
                    ok = false;
                }
            }
            sym.push_back(ok);
        }
        return tree[a];
    };
    int x = dfs(dfs, 0, -1);
    
    if (sym[x]) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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