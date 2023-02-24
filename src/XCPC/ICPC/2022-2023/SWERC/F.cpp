/**
 * @author: XiaFan
 * @date: 2023-02-19 22:02
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> e(m);
    std::vector<int> deg(n);
    for (auto &[u, v] : e) {
        std::cin >> u >> v;
        u--, v--;
        deg[u]++, deg[v]++;
    }

    for (int i = 0; i < n; i++) {
        if (deg[i] < n - 1) {
            std::cout << 2 << "\n";
            for (int j = 0; j < m; j++) {
                auto [u, v] = e[j];
                if (u == i || v == i) {
                    std::cout << 1 << " \n"[j == m - 1];
                } else {
                    std::cout << 2 << " \n"[j == m - 1];
                }
            }
            return;
        }
    }
    
    std::vector<int> ans(m);
    auto [u0, v0] = e[0];
    for (int i = 0; i < m; i++) {
        auto [u, v] = e[i];
        if (u == u0 || v == u0) {
            ans[i] = 1;
        }
    }
    ans[0] = 2;

    std::cout << 3 << "\n";
    for (int i = 0; i < m; i++) {
        std::cout << ans[i] + 1 << " \n"[i == m - 1];
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