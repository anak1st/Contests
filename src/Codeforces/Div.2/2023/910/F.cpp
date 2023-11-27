/**
 * @author: XiaFan
 * @date: 2023-11-20 20:56
 */
#include <bits/stdc++.h>

using i64 = long long;


constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0 , 0,-1, 1};

constexpr int inf = 1e9;

std::string out_put(int x) {
    if (x == inf) {
        return "inf";
    } else {
        auto r = std::to_string(x);
        while (r.size() < 3) {
            r = ' ' + r;
        }
        return r;
    }
}


void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::vector<int>> a(n, std::vector<int>(m));

    int sx, sy;
    int cnt_empty = 0;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'V') {
                sx = i, sy = j;
            }
            if (s[j] == '#') {
                a[i][j] = 1;
            } else {
                cnt_empty++;
            }
        }
    }

    std::vector<std::vector<int>> d1(n, std::vector<int>(m, inf));
    std::queue<std::tuple<int, int, int>> Q1;
    Q1.push({sx, sy, 1});
    while (!Q1.empty()) {
        auto [x, y, d] = Q1.front();
        Q1.pop();
        if (d1[x][y] != inf) {
            continue;
        }
        d1[x][y] = d;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == 1) {
                continue;
            }
            Q1.push({nx, ny, d + 1});
        }
    }

    int cnt_out = 0;
    int min_out_d = 1e9;

    std::queue<std::tuple<int, int, int, int>> Q2;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if ((x == 0 || y == 0 || x == n - 1 || y == m - 1) && d1[x][y] != inf) {
                cnt_out++;
                min_out_d = std::min(min_out_d, d1[x][y]);
                Q2.push({x, y, 1, x * m + y});
            }
        }
    }

    if (cnt_out == 0) {
        std::cout << cnt_empty - 1 << '\n';
        return;
    }

    if (cnt_out == 1) {
        std::cout << cnt_empty - min_out_d << '\n';
        return;
    }

    std::vector<std::vector<int>> d2(n, std::vector<int>(m, inf));
    std::vector<std::vector<int>> d3(n, std::vector<int>(m, inf));
    std::vector<std::vector<int>> t2(n, std::vector<int>(m, -1));
    std::vector<std::vector<int>> t3(n, std::vector<int>(m, -1));
    
    while (!Q2.empty()) {
        auto [x, y, d, type] = Q2.front();
        Q2.pop();
        if (t2[x][y] == -1) {
            d2[x][y] = d;
            t2[x][y] = type;
        } else if (t2[x][y] != type && t3[x][y] == -1) {
            d3[x][y] = d;
            t3[x][y] = type;
        } else {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == 1) {
                continue;
            }
            Q2.push({nx, ny, d + 1, type});
        }
    }

    int ans = -1;

    auto update = [&](int x, int y) -> void {
        // std::cerr << std::string(20, '=') << '\n';
        // std::cerr << x << ' ' << y << "\n";
        // std::cerr << d1[x][y] << ' ' << d2[x][y] << ' ' << d3[x][y] << '\n';
        // std::cerr << cnt_empty + 1 - d1[x][y] - d2[x][y] - d3[x][y] << '\n';
        ans = std::max(ans, cnt_empty + 2 - d1[x][y] - d2[x][y] - d3[x][y]);
    };

    // std::cerr << std::string(20, '=') << '\n';
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         std::cerr << out_put(d1[i][j]) << " \n"[j == m - 1];
    //     }
    // }

    // std::cerr << std::string(20, '=') << '\n';
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         std::cerr << out_put(d2[i][j]) << " \n"[j == m - 1];
    //     }
    // }

    // std::cerr << std::string(20, '=') << '\n';
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         std::cerr << out_put(d3[i][j]) << " \n"[j == m - 1];
    //     }
    // }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (d1[x][y] != inf) {
                update(x, y);
            }
        }
    }

    std::cout << ans << '\n';
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