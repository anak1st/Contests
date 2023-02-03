/**
 * @author: XiaFan
 * @date: 2023-01-30 15:57
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr int inf = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, Xs, Ys, Q;
    std::cin >> N >> M >> Xs >> Ys >> Q;
    std::vector<std::string> a(N);
    for (auto &s : a) {
        std::cin >> s;
    }

    std::vector<std::vector<int>> b(N, std::vector<int>(M, inf));
    b[Xs][Ys] = 0;
    std::queue<std::pair<int, int>> q;
    q.emplace(Xs, Ys);

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (a[nx][ny] == '#') {
                continue;
            }
            if (b[nx][ny] != inf) {
                continue;
            }
            b[nx][ny] = b[x][y] + 1;
            q.emplace(nx, ny);
        }
    }

    int step = 20;
    std::vector dp(N, std::vector(M, std::vector<std::pair<int, int>>(step + 1)));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x = i, y = j;
            if (a[x][y] == 'L') {
                y--;
            } else if (a[x][y] == 'R') {
                y++;
            } else if (a[x][y] == 'U') {
                x--;
            } else if (a[x][y] == 'D') {
                x++;
            }
            if (a[x][y] == '#') {
                x = i, y = j;
            }
            dp[i][j][0] = {x, y};
        }
    }
    for (int k = 1; k <= step; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                auto [x, y] = dp[i][j][k - 1];
                dp[i][j][k] = dp[x][y][k - 1];
            }
        }
    }

    while (Q--) {
        int X, Y;
        std::cin >> X >> Y;
        bool ok = false;
        int ans = 0;
        for (int i = step; i >= 0; i--) {
            auto [x, y] = dp[X][Y][i];
            int tmp = ans + (1 << i);
            if (b[x][y] > tmp) {
                X = x, Y = y;
                ans = tmp;
            } else {
                ok = true;
            }
        }
        if (!ok) {
            std::cout << -1 << "\n";
        } else {
            std::cout << ans + 1 << "\n";
        }
    }

    return 0;
}