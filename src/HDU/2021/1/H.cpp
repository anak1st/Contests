/**
 * @author: XiaFan
 * @date: 2023-02-16 23:11
 **/
#include <bits/stdc++.h>
// #include <debug/vector>
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }

    std::vector<std::vector<int>> b(n, std::vector<int>(m));
    for (int j = 0; j < m; j++) {
        b[n - 1][j] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (a[i][j] <= a[i + 1][j]) {
                b[i][j] = b[i + 1][j] + 1;
            } else {
                b[i][j] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        std::vector<int> l(m), r(m);
        std::iota(l.begin(), l.end(), 0);
        std::iota(r.begin(), r.end(), 0);
        for (int j = 0; j < m; j++) {
            while (l[j] != 0     && b[i][j] <= b[i][l[j] - 1]) {
                l[j] = l[l[j] - 1];
            }
        }
        for (int j = m - 1; j >= 0; j--) {
            while (r[j] != m - 1 && b[i][j] <= b[i][r[j] + 1]) {
                r[j] = r[r[j] + 1];
            }
        }
        for (int j = 0; j < m; j++) {
            ans = std::max(ans, (r[j] - l[j] + 1) * b[i][j]);
        }
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