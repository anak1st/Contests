/**
 * @author: XiaFan
 * @date: 2023-02-20 19:58
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr int inf = 1e9;

void Floyd(std::vector<std::vector<int>> &g) {
    int n = g.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }
    std::vector g(n, std::vector<int>(n, inf));
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u][v] = g[v][u] = 1;
    }
    Floyd(g);
    int diameter = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            diameter = std::min(diameter, g[i][j]);
        }
    }
    std::cout << diameter << "\n";

    return 0;
}