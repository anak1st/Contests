/**
 * @author: XiaFan
 * @date: 2023-02-24 21:58
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr int N = 5000;
constexpr i64 inf = 4e18;
int n;
i64 g[N][N];

i64 Prime() {
    std::vector<bool> vis(n);
    std::vector<i64> d(n, inf);
    d[0] = 0;
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        int k = -1;
        for (int j = 0; j < n; j++) {
            if (vis[j]) continue;
            if (k == -1 || d[j] < d[k]) {
                k = j;
            }
        }
        vis[k] = true;
        ans = std::max(ans, d[k]);
        for (int j = 0; j < n; j++) {
            if (vis[j]) continue;
            if (d[j] > g[k][j]) {
                d[j] = g[k][j];
            }
        }
    }
    return ans;
}

void solve() {
    std::cin >> n;
    std::vector<std::array<i64, 2>> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i][0] >> a[i][1];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            i64 dx = a[i][0] - a[j][0];
            i64 dy = a[i][1] - a[j][1];
            g[i][j] = dx * dx + dy * dy;
        }
    }
    std::cout << Prime() << std::endl;
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