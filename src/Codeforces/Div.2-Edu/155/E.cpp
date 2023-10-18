/**
 * @author: XiaFan
 * @date: 2023-09-25 20:27
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n - 1);
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        std::cin >> p[i];
        p[i]--;
        adj[p[i]].push_back(i + 1);
    }

    std::vector<int> c(n);
    c[0] = -1;
    auto dfs = [&](auto &&dfs, int v) -> void {
        for (int u : adj[v]) {
            c[u] = (c[v] + 1) % 3;
            dfs(dfs, u);
        }
    };

    dfs(dfs, 0);

    int use = 1 + (*std::max_element(c.begin() + 1, c.end()));
    std::cout << use << "\n";
    for (int i = 1; i < n; i++) {
        std::cout << c[i] + 1 << " ";
    }
    std::cout << "\n";

    int in;
    std::cin >> in;

    while (in == 0) {
        std::vector<int> co(3);
        for (int i = 0; i < use; i++) {
            std::cin >> co[i];
        }
        int out = -1;
        for (int i = 0; i < 3; i++) {
            if (co[i] && co[(i + 1) % 3]) {
                out = i;
            }
        }
        if (out == -1) {
            for (int i = 0; i < 3; i++) {
                if (co[i]) {
                    out = i;
                }
            }
        }
        std::cout << out + 1 << "\n";

        std::cin >> in;
    }
}

int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}