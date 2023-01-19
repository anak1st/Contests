/**
 * @author: XiaFan
 * @date: 2023-01-18 14:57
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector a(n + 1, std::vector<bool>(4));
    while (k--) {
        int x, y;
        std::cin >> x >> y;
        a[x][y] = !a[x][y];
    }
    
    std::vector b(n + 1, std::vector<int>(4));
    b[n][3] = 1;

    std::function<int(int, int)> dfs = [&](int x, int y) -> int {
        if (x > n || y > 3 || a[x][y]) {
            return -1;
        }
        // std::cerr << "vis " << x << " " << y << "\n";
        if (b[x][y] != 0) {
            return b[x][y];
        }
        int j1 = dfs(x + 1, y);
        int j2 = dfs(x, y + 1);
        if (j1 == 1 || j2 == 1) {
            b[x][y] = 1;
        } else {
            b[x][y] = -1;
        }
        return b[x][y];
    };

    dfs(1, 1);
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 3; ++j) {
            if (b[i][j] == 1) {
                cnt++;
            }
        }
    }
    std::cout << cnt - 1 << "\n";
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