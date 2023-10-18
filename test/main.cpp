/**
 * @author: XiaFan
 * @date: 2023-10-17 21:53
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> vis(n);
    for (int i = 0; i < k; i++) {
        int x;
        std::cin >> x;
        x--;
        vis[x] = 1;
    }

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> dis(n);
    auto bfs = [&](int st) -> int {
        std::fill(dis.begin(), dis.end(), -1);
        dis[st] = 0;
        std::queue<int> q;
        q.push(st);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dis[v] == -1) {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
        int res = -1;
        for (int i = 0; i < n; i++) {
            if (vis[i] && (res == -1 || dis[i] > dis[res])) {
                res = i;
            }
        }
        return res;
    };

    int u = bfs(0);
    int v = bfs(u);

    auto dis1 = dis;
    bfs(v);

    std::vector<int> mind(n);
    for (int i = 0; i < n; i++) {
        mind[i] = std::max(dis1[i], dis[i]);
        // std::cerr << mind[i] << ' ';
    }
    // std::cerr << '\n';
    int ans = std::ranges::min(mind);
    std::cout << ans << '\n';
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