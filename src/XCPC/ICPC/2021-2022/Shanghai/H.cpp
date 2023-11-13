/**
 * @author: XiaFan
 * @date: 2023-11-02 20:25
 */
#include <bits/stdc++.h>

using i64 = long long;

std::pair<std::vector<int>, std::vector<int>> kruskalRebuildTree(
    int n, std::vector<std::array<int, 3>> edges) {
    std::vector<int> f(2 * n);
    std::iota(f.begin(), f.end(), 0);
    std::function<int(int)> find = [&](int x) {
        if (x != f[x]) f[x] = find(f[x]);
        return f[x];
    };

    std::sort(edges.begin(), edges.end(), [](auto a, auto b) { 
        return a[2] < b[2]; 
    });

    std::vector<int> v(n + 1);
    std::vector<int> p(2 * n);
    for (auto [x, y, w] : edges) {
        x = find(x);
        y = find(y);
        if (x == y) continue;

        f[x] = f[y] = v.size();
        p[x] = p[y] = v.size();
        v.push_back(w);
    }

    p.resize(v.size());
    return {v, p};
}

constexpr int B = 20;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::vector<std::array<int, 3>> e(m);
    for (int i = 0; i < m; i++) {
        auto &[u, v, w] = e[i];
        std::cin >> u >> v >> w;
    }

    auto [v, p] = kruskalRebuildTree(n, e);

    int N = v.size() - 1;
    std::vector<std::vector<int>> adj(N + 1);
    for (int i = 1; i <= N; i++) {
        if (p[i]) {
            adj[p[i]].push_back(i);
        }
    }

    std::vector<i64> A(N + 1);
    std::function<i64(int)> dfs = [&](int x) {
        if (x <= n) A[x] = a[x];
        for (int y : adj[x]) {
            A[x] += dfs(y);
        }
        return A[x];
    };
    dfs(N);

    std::vector<std::array<i64, B>> ans(N + 1);
    std::vector<std::array<int, B>> P(N + 1);
    for (int i = 1; i <= N; i++) {
        P[i][0] = p[i];
        ans[i][0] = v[P[i][0]] - A[i];
    }

    for (int i = 1; i < B; i++) {
        for (int j = 1; j <= N; j++) {
            P[j][i] = P[P[j][i - 1]][i - 1];
            ans[j][i] = std::max(ans[j][i - 1], ans[P[j][i - 1]][i - 1]);
        }
    }

    while (q--) {
        int x, k;
        std::cin >> x >> k;
        for (int i = B - 1; i >= 0; i--) {
            if (P[x][i] != 0 && ans[x][i] <= k) {
                x = P[x][i];
            }
        }
        std::cout << k + A[x] << '\n';
    }
}