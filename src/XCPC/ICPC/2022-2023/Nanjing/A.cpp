/**
 * @author: XiaFan
 * @date: 2023-10-24 16:02
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::string s;
    std::cin >> s;
    
    int len = s.size();
    
    std::vector<int> x(len + 1), y(len + 1);
    int cx = 0, cy = 0;
    int minx = 0, maxx = 0, miny = 0, maxy = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'U') cx--;
        else if (s[i] == 'D') cx++;
        else if (s[i] == 'L') cy--;
        else cy++;
        x[i + 1] = cx, y[i + 1] = cy;
        minx = std::min(minx, cx);
        maxx = std::max(maxx, cx);
        miny = std::min(miny, cy);
        maxy = std::max(maxy, cy);
    }

    if (maxx - minx >= n || maxy - miny >= m) {
        if (k == 0) std::cout << n * m << "\n";
        else std::cout << 0 << "\n";
        return;
    }
    
    std::vector a(n, std::vector<int>(m));
    for (int i = 0; i <= len; i++) {
        a[x[i] - minx][y[i] - miny] = 1;
    }
    
    int dx = n - (maxx - minx);
    int dy = m - (maxy - miny);
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (a[i][j] == 1) {
                if (i + dx < n) a[i + dx][j]--;
                if (j + dy < m) a[i][j + dy]--;
                if (i + dx < n && j + dy < m) a[i + dx][j + dy]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            a[i][j] += a[i][j - 1];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] += a[i - 1][j];
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (k == dx * dy - a[i][j]) {
                ans++;
            }
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