/**
 * @author: XiaFan
 * @date: 2023-10-19 19:11
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        std::cin >> p[i];
        p[i]--;
        adj[p[i]].push_back(i);
    }

    std::vector<int> d(n, 1);
    std::vector<int> cnt(n + 1);
    std::function<void(int, int)> dfs = [&](int x, int f) {
        for (int y : adj[x]) {
            if (y != f) {
                dfs(y, x);
                d[x] = std::max(d[x], d[y] + 1);
            }
        }
        cnt[d[x]]++;
    };

    dfs(0, -1);

    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        // std::cerr << cnt[i] << " \n"[i == n];
        ans = std::min(ans, i + cnt[i] - 1);
    }
    std::cout << ans << "\n";
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