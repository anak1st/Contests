/**
 * @author: XiaFan
 * @date: 2023-01-12 14:53
 **/
#include <bits/stdc++.h>
using i64 = long long;

template <typename T> struct Fenwick {
    int n;
    std::vector<T> a;
    Fenwick(int size) : n(size), a(n) {}
    Fenwick(std::vector<T> &v) : n(v.size()), a(n) {
        for (int i = 0; i < n; i++) {
            add(i, v[i]);
        }
    }
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    // sum of [0, r]
    T sum(int r) {
        T ans = 0;
        for (int i = r + 1; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    // sum of [l, r]
    T sum_range(int l, int r) {
        if (l == 0) {
            return sum(r);
        } else {
            return sum(r) - sum(l - 1);
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::array<int, 3>> edge(n);
    std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        auto &[u, v, w] = edge[i];
        std::cin >> u >> v >> w;
        w = w & 1;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int cnt = 0;
    std::vector<int> in(n + 1), out(n + 1);
    std::vector fa(n + 1, std::vector<int>(21));
    std::vector<int> dep(n + 1), len(n + 1);
    std::function<void(int, int)> dfs = [&](int u, int f) {
        in[u] = ++cnt;
        fa[u][0] = f;
        for (int i = 1; (1 << i) <= dep[u]; ++i) {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (auto [v, w] : adj[u]) {
            if (v == f) continue;
            dep[v] = dep[u] + 1;
            len[v] = len[u] + w;
            dfs(v, u);
        }
        out[u] = cnt;
    };
    dfs(1, 0);

    auto lca = [&](int v, int u) -> int {
        if (dep[v] > dep[u]) std::swap(v, u);
        std::bitset<32> dif(dep[u] - dep[v]);
        for (int i = 0; i <= 20; i++) {
            if (dif[i]) {
                u = fa[u][i];
            }
        }
        for (int i = 20; i >= 0; i--) {
            if (fa[v][i] != fa[u][i]) {
                v = fa[v][i];
                u = fa[u][i];
            }
        }
        return v == u ? v : fa[v][0];
    };

    Fenwick<int> fen(n + 2);

    int q;
    std::cin >> q;
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, y;
            std::cin >> x >> y;
            int old = len[x] + len[y] - 2 * len[lca(x, y)];
            int now = fen.sum(in[x]) + fen.sum(in[y]);
            if ((old + now) & 1) {
                std::cout << "WE NEED BLACK PANDA\n";
            } else {
                std::cout << "JAKANDA FOREVER\n";
            }
        } else {
            int i, l;
            std::cin >> i >> l;
            l = l & 1;
            auto [u, v, w] = edge[i];
            if (dep[v] < dep[u]) std::swap(u, v);
            if (w != l) {
                fen.add(in[v], 1);
                fen.add(out[v] + 1, -1);
                edge[i][2] = w;
            }
        }
    }
    return 0;
}