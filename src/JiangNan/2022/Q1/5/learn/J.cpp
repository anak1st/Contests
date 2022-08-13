#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

typedef long long i64;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

struct point {
    int x, y;
    point(int _x = 0, int _y = 0) {
        x = _x;
        y = _y;
    }
};

int lx, ly;
int a[30][30];

void bfs(point &start) {
    std::queue<point> q;
    q.push(start);
    a[start.x][start.y] = 1;
    while(!q.empty()) {
        point cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx < 0 || ny < 0 || nx >= lx || ny >= ly) {
                continue;
            }
            if(!a[nx][ny]) {
                a[nx][ny] = 1;
                q.push(point(nx, ny));
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    while(1) {
        std::cin >> ly >> lx;
        if(lx == 0 && ly == 0) {
            break;
        }

        point start;
        for(int i = 0; i < lx; i++) {
            for(int j = 0; j < ly; j++) {
                char c;
                std::cin >> c;

                if(c == '#') {
                    a[i][j] = 2;
                } else {
                    if(c == '@') {
                        start.x = i;
                        start.y = j;
                    }
                    a[i][j] = 0;
                }
            }
        }

        bfs(start);

        int ans = 0;
        for(int i = 0; i < lx; i++) {
            for(int j = 0; j < ly; j++) {
                if(a[i][j] == 1) {
                    ans++;
                }
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}