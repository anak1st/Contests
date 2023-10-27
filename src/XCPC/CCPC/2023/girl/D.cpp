/**
 * @author: XiaFan
 * @date: 2023-10-23 18:02
 */
#include <bits/stdc++.h>

using i64 = long long;

struct MCFGraph {
    struct Edge {
        int v, c, f;
        Edge(int v, int c, int f) : v(v), c(c), f(f) {}
    };
    const int n;
    std::vector<Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<i64> h, dis;
    std::vector<int> pre;
    bool dijkstra(int s, int t) {
        dis.assign(n, std::numeric_limits<i64>::max());
        pre.assign(n, -1);
        std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>,
                            std::greater<std::pair<i64, int>>>
            que;
        dis[s] = 0;
        que.emplace(0, s);
        while (!que.empty()) {
            i64 d = que.top().first;
            int u = que.top().second;
            que.pop();
            if (dis[u] < d) continue;
            for (int i : g[u]) {
                int v = e[i].v;
                int c = e[i].c;
                int f = e[i].f;
                if (c > 0 && dis[v] > d + h[u] - h[v] + f) {
                    dis[v] = d + h[u] - h[v] + f;
                    pre[v] = i;
                    que.emplace(dis[v], v);
                }
            }
        }
        return dis[t] != std::numeric_limits<i64>::max();
    }
    MCFGraph(int n) : n(n), g(n) {}
    void addEdge(int u, int v, int c, int f) {
        // if (f < 0) {
        //     g[u].push_back(e.size());
        //     e.emplace_back(v, 0, f);
        //     g[v].push_back(e.size());
        //     e.emplace_back(u, c, -f);
        // } else {
        //     g[u].push_back(e.size());
        //     e.emplace_back(v, c, f);
        //     g[v].push_back(e.size());
        //     e.emplace_back(u, 0, -f);
        // }

        g[u].push_back(e.size());
        e.emplace_back(v, c, f);
        g[v].push_back(e.size());
        e.emplace_back(u, 0, -f);
    }
    std::pair<int, i64> flow(int s, int t) {
        int flow = 0;
        i64 cost = 0;
        h.assign(n, 0);
        while (dijkstra(s, t)) {
            for (int i = 0; i < n; ++i) h[i] += dis[i];
            int aug = std::numeric_limits<int>::max();
            for (int i = t; i != s; i = e[pre[i] ^ 1].v) aug = std::min(aug, e[pre[i]].c);
            for (int i = t; i != s; i = e[pre[i] ^ 1].v) {
                e[pre[i]].c -= aug;
                e[pre[i] ^ 1].c += aug;
            }
            flow += aug;
            cost += i64(aug) * h[t];
        }
        return std::make_pair(flow, cost);
    }
};

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }

    auto id = [&](int i, int j, bool is_in) -> int {
        if (is_in) {
            return i * m + j;
        } else {
            return n * m + i * m + j;
        }
    };

    int s = n * m * 2;
    int t = s + 1;

    MCFGraph g(t + 1);

    for (int i = 0; i < k; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        g.addEdge(s, id(x, y, true), 1e9, 0);
    }

    for (int i = 0; i < k; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        g.addEdge(id(x, y, false), t, 1e9, -100);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] >= 0) {
                g.addEdge(id(i, j, true), id(i, j, false), 1, 1 - a[i][j]);
            }

            if (i > 0) {
                g.addEdge(id(i, j, false), id(i - 1, j, true), 1, 0);
            }
            if (i < n - 1) {
                g.addEdge(id(i, j, false), id(i + 1, j, true), 1, 0);
            }
            if (j > 0) {
                g.addEdge(id(i, j, false), id(i, j - 1, true), 1, 0);
            }
            if (j < m - 1) {
                g.addEdge(id(i, j, false), id(i, j + 1, true), 1, 0);
            }
        }
    }

    auto [flow, cost] = g.flow(s, t);
    std::cout << -cost << "\n";
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