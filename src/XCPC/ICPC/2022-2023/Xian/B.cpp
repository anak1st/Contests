#include <bits/stdc++.h>

using i64 = long long;


constexpr int inf = 1e9;

template <typename T> struct MaxFlow {
    struct edge {
        int to;
        T cap;
        edge(int to, T cap) : to(to), cap(cap) {}
    };
    const int n;
    std::vector<edge> E;
    std::vector<std::vector<int>> G;
    std::vector<int> cur, h;
    MaxFlow(int n) : n(n), G(n) {}
    bool bfs(int s, int t) {
        h.assign(n, -1);
        std::queue<int> Q;
        h[s] = 0;
        Q.push(s);
        while (!Q.empty()) {
            const int u = Q.front();
            Q.pop();
            for (int i : G[u]) {
                auto [v, c] = E[i];
                if (c > 0 && h[v] == -1) {
                    h[v] = h[u] + 1;
                    if (v == t) {
                        return true;
                    }
                    Q.push(v);
                }
            }
        }
        return false;
    }
    T dfs(int u, int t, T f) {
        if (u == t) {
            return f;
        }
        auto r = f;
        for (int &i = cur[u]; i < int(G[u].size()); i++) {
            const int j = G[u][i];
            auto [v, c] = E[j];
            if (c > 0 && h[v] == h[u] + 1) {
                auto a = dfs(v, t, std::min(r, c));
                E[j].cap -= a;
                E[j ^ 1].cap += a;
                r -= a;
                if (r == 0) {
                    return f;
                }
            }
        }
        return f - r;
    }
    void add_edge(int u, int v, T cap) {
        G[u].push_back(E.size());
        E.emplace_back(v, cap);
        G[v].push_back(E.size());
        E.emplace_back(u, 0);
    }
    T Dinic(int s, int t) {
        T ans = 0;
        while (bfs(s, t)) {
            cur.assign(n, 0);
            ans += dfs(s, t, inf);
        }
        return ans;
    }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, c, d;
	std::cin >> n >> m >> c >> d;
	int siz = n + m + n * m;

    
    std::vector<std::string> a(n);
    int sum = 0;
	for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        for (int j = 0; j < m; j++) {
			if (a[i][j] == '.') {
				sum++;
			}
		}
    }

    i64 ans = 1LL * sum * d;

    int sz = n + m + n * m + 2;
    int s = sz - 2, t = sz - 1;
    MaxFlow<int> F(sz);
    for (int i = 0; i < n; i++) {
        F.add_edge(s, i, 0);
    }
    for (int j = 0; j < m; j++) {
        F.add_edge(n + j, t, 0);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.') {
                F.add_edge(i, n + j, 1);
            }
        }
    }
	
	for (int k = 1, col = 0; k <= std::max(n, m); k++) {
        for (int i = 0; i < n + m; i++) {
            F.E[i * 2].cap++;
        }

        col += F.Dinic(s, t);
		ans = std::min(ans, 1LL * k * c + 1LL * (sum - col) * d);        
	}
	std::cout << ans << '\n';
    

    return 0;
}