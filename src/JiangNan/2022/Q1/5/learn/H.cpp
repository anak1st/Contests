#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

typedef long long i64;

struct point {
    int x, y;
    point(int _x = 0, int _y = 0) {
        x = _x;
        y = _y;
    }
};

int a[400][400], b[400][400];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    for(int i = 0; i < 400; i++) {
        for(int j = 0; j < 400; j++) {
            a[i][j] = 2000;
            b[i][j] = -1;
        }
    }

    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y, t;
        std::cin >> x >> y >> t;
        a[x][y] = std::min(a[x][y], t);
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0) {
                continue;
            }
            a[nx][ny] = std::min(a[nx][ny], t);
        }
    }

    if(a[0][0] == 0) {
        std::cout << -1 << '\n';
        return 0;
    }

    std::queue<point> q;
    q.push(point(0, 0));

    b[0][0] = 0;
    while(!q.empty()) {
        point cur = q.front();
        q.pop();
        int t = b[cur.x][cur.y];
        if(a[cur.x][cur.y] == 2000) {
            std::cout << t << '\n';
            return 0;
        }

        for(int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if(nx < 0 || ny < 0) {
                continue;
            }
            if(b[nx][ny] == -1 && a[nx][ny] > t + 1) {
                b[nx][ny] = t + 1;
                q.push(point(nx, ny));
            }
        }
    }

    std::cout << -1 << '\n';
    return 0;
}