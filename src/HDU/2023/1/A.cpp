/**
 * @author: XiaFan
 * @date: 2023-09-15 18:00
 */
#include <bits/stdc++.h>

using i64 = long long;
constexpr int INF = 1e9;


std::array<i64, 3> exgcd(i64 a, i64 b) {
    if (b == 0) {
        return {a, 1, 0};
    }
    auto [g, x, y] = exgcd(b, a % b);
    return {g, y, x - a / b * y};
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto find = [&](int s, int t) -> std::vector<int> {
        std::vector<int> vis;
        bool find = false;
        auto dfs = [&](auto &&dfs, int p, int f, int t) -> void {
            vis.push_back(p);
            if (p == t) {
                find = true;
                return;
            }

            for (int u : adj[p]) {
                if (u == f) continue;
                dfs(dfs, u, p, t);
                if (find) return;
            }
            vis.pop_back();
        };

        dfs(dfs, s, -1, t);
        return vis;
    };
    
    

    while (m--) {
        int s1, t1, s2, t2;
        std::cin >> s1 >> t1 >> s2 >> t2;
        s1--, t1--, s2--, t2--;
        std::vector<std::vector<int>> fst(n, std::vector<int>(4, -1));
        auto p1 = find(s1, t1);
        auto p2 = find(s2, t2);

        int k1 = 2 * (p1.size() - 1), k2 = 2 * (p2.size() - 1);

        for (int i = 0; i < (int)p1.size(); i++) {
            //std::cerr << p1[i] + 1 << " \n"[i == (int)p1.size() - 1];
            fst[p1[i]][0] = i;
            fst[p1[i]][1] = (p1.size() - 1) * 2 - i;
        }
        for (int i = 0; i < (int)p2.size(); i++) {
            //std::cerr << p2[i] + 1 << " \n"[i == (int)p2.size() - 1];
            fst[p2[i]][2] = i;
            fst[p2[i]][3] = (p2.size() - 1) * 2 - i;
        }

        auto calc__ = [&](int b1, int b2) -> int {
            // k1 * x + b1 = k2 * y + b2
            // k1 * x - k2 * y = z
            // x >= 0 && y >= 0
            int z = b2 - b1;
            
            auto [g, x, y] = exgcd(k1, k2);
            if (z % g != 0) return INF;
            x *= z / g, y *= z / g;
            int t = std::abs(k2 / g);
            x = (x % t + t) % t;

            return x;
        };

        auto calc = [&](int b1, int b2) -> int {
            if (b1 < 0 || b2 < 0) return INF;
            int x = calc__(b1, b2);
            if (x == INF) return INF;
            int y = b1 + k1 * x;
            return y;
        };

        int ans = INF, pos = -2;
        for (int i = 0; i < n; i++) {
            // k1 * x + b1 = k2 * x + b2
            int tmp = INF;

            // for (int j = 0; j < 4; j++) {
            //     std::cerr << fst[i][j] << " \n"[j == 3];
            // }

            tmp = std::min(tmp, calc(fst[i][0], fst[i][2]));
            tmp = std::min(tmp, calc(fst[i][0], fst[i][3]));
            tmp = std::min(tmp, calc(fst[i][1], fst[i][2]));
            tmp = std::min(tmp, calc(fst[i][1], fst[i][3]));

            // std::cerr << i + 1 << " " << tmp << "\n\n";
            if (tmp < ans) {
                ans = tmp, pos = i;
            }
        }

        std::cout << pos + 1 << '\n';
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