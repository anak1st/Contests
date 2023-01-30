/**
 * @author: XiaFan
 * @date: 2023-01-30 15:57
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, Xs, Ys, Q;
    std::cin >> N >> M >> Xs >> Ys >> Q;
    std::vector<std::string> a(N);
    for (auto &s : a) {
        std::cin >> s;
    }

    std::vector<std::vector<int>> b(N, std::vector<int>(M, -1));
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
            if (b[nx][ny] != -1) {
                continue;
            }
            b[nx][ny] = b[x][y] + 1;
            q.emplace(nx, ny);
        }
    }

    const int inf = N * M;

    while (Q--) {
        int x, y;
        std::cin >> x >> y;
        int ans = inf;
        for (int i = 1; i <= inf; i++) {
            int tx = x, ty = y;
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
                x = tx, y = ty;
            }
            if (b[x][y] != -1 && b[x][y] <= i) {
                ans = i;
                break;
            }
        }
        if (ans == inf) {
            std::cout << -1 << "\n";
        } else {
            std::cout << ans << "\n";
        }
    }

    return 0;
}