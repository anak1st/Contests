/**
 * @author: XiaFan
 * @date: 2023-11-19 22:02
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    int x = n + m - 2;
    if (k < x) {
        std::cout << "NO\n";
        return;
    }
    if ((k - x) % 2) {
        std::cout << "NO\n";
        return;
    }

    std::vector<std::vector<int>> a(n, std::vector<int>(m - 1, 0));
    std::vector<std::vector<int>> b(n - 1, std::vector<int>(m, 0));

    for (int i = 0; i < n - 1; i++) {
        b[i][0] = i % 2;
    }

    int c = b[n - 2][0];

    for (int j = 0; j < m - 1; j++) {
        a[n - 1][j] = c == (j % 2);
    }

    c = a[n - 1][m - 2];

    b[n - 2][m - 3] = b[n - 2][m - 2] = b[n - 2][m - 1] = c;

    a[n - 2][m - 2] = a[n - 2][m - 3] = c ^ 1;

    std::cout << "YES\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            std::cout << (a[i][j] ? 'B' : 'R') << " ";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << (b[i][j] ? 'B' : 'R') << " ";
        }
        std::cout << "\n";
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