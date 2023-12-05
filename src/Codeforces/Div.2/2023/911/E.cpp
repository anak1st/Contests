#include <bits/stdc++.h>

using i64 = long long;
struct SCC {
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> stk;
    std::vector<int> dfn, low, bel;
    
    int cur, cnt;
    
    SCC() {}
    SCC(int n) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        bel.assign(n, -1);
        stk.clear();
        cur = cnt = 0;
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    
    void dfs(int x) {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);
        
        for (auto y : adj[x]) {
            if (dfn[y] == -1) {
                dfs(y);
                low[x] = std::min(low[x], low[y]);
            } else if (bel[y] == -1) {
                low[x] = std::min(low[x], dfn[y]);
            }
        }
        
        if (dfn[x] == low[x]) {
            int y;
            do {
                y = stk.back();
                bel[y] = cnt;
                stk.pop_back();
            } while (y != x);
            cnt++;
        }
    }
    
    std::vector<int> work() {
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                dfs(i);
            }
        }
        return bel;
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    SCC g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g.addEdge(u, v);
    }
    
    auto bel = g.work();
    std::vector<std::vector<int>> scc_adj(n);
    std::vector<std::pair<int, i64>> s(g.cnt), dp(n);
    for (int i = 0; i < n; i++) {
        s[bel[i]].first += 1;
        s[bel[i]].second += -a[i];
        for (auto j : g.adj[i]) {
            if (bel[i] != bel[j]) {
                scc_adj[bel[i]].push_back(bel[j]);
            }
        }
    }
    for (int i = g.cnt - 1; i >= 0; i--) {
        dp[i].first += s[i].first;
        dp[i].second += s[i].second;
        for (auto j : scc_adj[i]) {
            dp[j] = std::max(dp[j], dp[i]);
        }
    }

    auto ans = *std::max_element(dp.begin(), dp.end());
    std::cout << ans.first << " " << -ans.second << "\n";
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