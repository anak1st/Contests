/**
 * @author: XiaFan
 * @date: 2023-03-12 15:21
 **/
#include <bits/stdc++.h>
using i64 = long long;

struct DSU {
    int n;
    std::vector<int> f, cntv;
    DSU(int size) : n(size), f(n), cntv(n, 1) {
        std::iota(f.begin(), f.end(), 0);
    }
    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) {
            return false;
        }
        cntv[x] += cntv[y];
        f[y] = x;
        return true;
    }
    int cnt_v(int x) {
        return cntv[find(x)];
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    DSU dsu(n);
    int sz = n;
    std::vector<std::pair<int, int>> e;
    for (int i = 0; i < m; i++) {
        int x, y;
        char op;
        std::cin >> x >> op >> y;
        x--, y--;
        if (op == '=') {
            dsu.merge(x, y);
            sz--;
        } else {
            if (op == '>') {
                std::swap(x, y);
            }
            e.emplace_back(x, y);
        }
    }

    std::vector<std::vector<int>> adj(n);
    std::vector<int> deg(n);
    for (auto [x, y] : e) {
        x = dsu.find(x);
        y = dsu.find(y);
        adj[x].push_back(y);
        deg[y]++;
    }

    std::queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0 && dsu.find(i) == i) {
            q.push(i);
        }
    }

    bool ok = true;
    while (!q.empty()) {
        if (q.size() > 1) {
            ok = false;
            break;
        }
        int u = q.front();
        q.pop();
        sz--;
        for (int v : adj[u]) {
            if (--deg[v] == 0) {
                q.push(v);
            }
        }
    }

    if (sz > 0) {
        ok = false;
    }

    std::cout << (ok ? "YES" : "NO") << "\n";
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