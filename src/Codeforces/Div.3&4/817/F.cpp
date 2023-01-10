/**
 * @author: XiaFan
 * @date: 09-05 19:41
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector a(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '*') {
                a[i][j] = 1;
            }
        }
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = { 0, 0,-1, 1};

    std::vector<std::pair<int, int>> v;
    std::vector vis(n, std::vector<bool>(m, false));
    std::function<void(int, int)> dfs = [&](int x, int y) {
        v.push_back({x, y});
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (!vis[nx][ny] && a[nx][ny] == a[x][y]) {
                vis[nx][ny] = true;
                dfs(nx, ny);
            }
        }
    };

    bool ok = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            v.clear();
            if (a[i][j] == 0 || vis[i][j]) {
                continue;
            }
            vis[i][j] = true;
            dfs(i, j);
            if (v.size() != 3) {
                ok = false;
                // std::cout << "size\n";
                continue;
            }
            if ((v[0].first  == v[1].first  && v[0].first  == v[2].first) || 
                (v[0].second == v[1].second && v[0].second == v[2].second)) {
                ok = false;
                continue;
            }
            for (auto [x, y] : v) {
                int count = 0;
                for (int ii = std::max(x - 1, 0); ii <= std::min(x + 1, n - 1); ii++) {
                    for (int jj = std::max(y - 1, 0); jj <= std::min(y + 1, m - 1); jj++) {
                        count += a[ii][jj];
                    }
                }
                if (count != 3) {
                    ok = false;
                    // std::cout << "count\n";
                }
            }
        }
    }

    if (ok) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    
    return 0;
}