#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

typedef long long i64;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int a[25][25];
int sx, sy;
int ex, ey;
int n, m;
int ans;

void dfs(int x, int y, int step) {
    if(step >= ans) {
        return;
    }

    for(int i = 0; i < 4; i++) {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if(cx < 1 || cx > n || cy < 1 || cy > m) {
            continue;
        }
        if(a[cx][cy] == 1) {
            continue;
        }

        bool out = false;
        while(1) {
            if(cx < 1 || cx > n || cy < 1 || cy > m) {
                out = true;
                break;
            }
            if(a[cx][cy] == 1) {
                cx -= dx[i];
                cy -= dy[i];
                break;
            }
            if(cx == ex && cy == ey) {
                ans = std::min(ans, step + 1);
                return;
            }
            cx += dx[i];
            cy += dy[i];
        }

        if(out) {
            continue;
        }

        a[cx + dx[i]][cy + dy[i]] = 0;
        dfs(cx, cy, step + 1);
        a[cx + dx[i]][cy + dy[i]] = 1;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    while(true) {
        std::cin >> m >> n;
        if(n == 0 && n == 0) {
            break;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                std::cin >> a[i][j];
                if(a[i][j] == 2) {
                    sx = i;
                    sy = j;
                }
                if(a[i][j] == 3) {
                    ex = i;
                    ey = j;
                }
            }
        }

        ans = 11;
        dfs(sx, sy, 0);
        if(ans > 10) {
            std::cout << -1 << '\n';
        } else {
            std::cout << ans << '\n';
        }
    }

    return 0;
}