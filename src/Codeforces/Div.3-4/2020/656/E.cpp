/**
 * @author: XiaFan
 * @date: 2023-03-04 22:49
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> edge(m);
    std::vector<int> deg(n);
    std::vector<std::vector<int>> adj(n);
    for (auto &[u, v] : edge) {
        int op;
        std::cin >> op;
        std::cin >> u >> v;
        u--, v--;
        if (op == 1) {
            adj[u].push_back(v);
            deg[v]++;
        }
    }

    std::queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    std::vector<int> d(n);
    int deep = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        d[u] = deep++;
        for (auto v : adj[u]) {
            if (--deg[v] == 0) {
                q.push(v);
            }
        }
    }
    if (deep != n) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
        for (auto [u, v] : edge) {
            if (d[u] > d[v]) {
                std::swap(u, v);
            }
            std::cout << u + 1 << ' ' << v + 1 << "\n";
        }
    }
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