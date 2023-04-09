#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5;
std::vector<int> adj[2][N + 1];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        adj[i % 2][a[i]].push_back(i);
    }

    i64 ans = 1LL * (k / 2) * (n - k + 1);

    for (int ii = 0; ii < 2; ii++) {
        for (int jj = 0; jj <= N; jj++) {
            auto &v = adj[ii][jj];
            int m = v.size();
            int x = m, y = m;
            for (int i = 0, j = 0; i < m; i++) {
                while (v[i] - v[j] >= k) {
                    j++;
                }
                while (x > 0 && v[x - 1] + v[i] >= k - 1) {
                    x--;
                }
                while (y > 0 && v[y - 1] + v[i] >= 2 * n - k) {
                    y--;
                }
                ans -= std::max(0, std::min(i, y) - std::max(x, j));
            }
        }
    }
    std::cout << ans << "\n";

    return 0;
}