/**
 * @author: XiaFan
 * @date: 2023-01-30 15:12
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj1(n), adj2(n);
    std::vector<int> cnt1(n), cnt2(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj1[u].push_back(v);
        adj2[v].push_back(u);
        cnt1[v]++;
        cnt2[u]++;
    }

    auto fun = [&](std::vector<std::vector<int>> &adj, std::vector<int> &cnt) {
        std::queue<int> q;
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[i] == 0) {
                q.push(i);
                k++;
            }
        }
        std::vector<int> b(n + 1, -1);
        if (q.size() == 1) {
            b[k] = q.front();
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                cnt[v]--;
                if (cnt[v] == 0) {
                    q.push(v);
                    k++;
                }
            }
            if (q.size() == 1) {
                b[k] = q.front();
            }
        }
        return b;
    };

    auto b1 = fun(adj1, cnt1);
    auto b2 = fun(adj2, cnt2);
    std::reverse(b2.begin() + 1, b2.end());

    for (int i = 1; i <= n; i++) {
        if (b1[i] == b2[i] && b1[i] != -1) {
            std::cout << b1[i] + 1 << " ";
        } else {
            std::cout << -1 << " ";
        }
    }

    return 0;
}