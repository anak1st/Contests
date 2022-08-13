#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

typedef long long i64;

int a[1005][1005];
int b[1005][1005];

struct point {
    int x, y;
    point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

int lx, ly;
int mxx = -1, mxy = -1, mxs = 0;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y) {
    for(int i = 0; i < lx; i++) {
        for(int j = 0; j < ly; j++) {
            b[i][j] = -1;
        }
    }

    std::queue<point> q;
    q.push(point(x, y));
    b[x][y] = 0;
    while(!q.empty()) {
        point cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx < 0 || nx >= lx || ny < 0 || ny >= ly) {
                continue;
            }
            if(a[nx][ny] || b[nx][ny] >= 0) {
                continue;
            }

            b[nx][ny] = b[cur.x][cur.y] + 1;
            q.push(point(nx, ny));
            if(b[nx][ny] > mxs) {
                mxs = b[nx][ny];
                mxx = nx;
                mxy = ny;
            }
        }
    }
}

void solve() {
    std::cin >> ly >> lx;
    mxx = -1, mxy = -1, mxs = 0;
    for(int i = 0; i < lx; i++) {
        std::string str;
        std::cin >> str;
        for(int j = 0; j < ly; j++) {
            if(str[j] == '#') {
                a[i][j] = 1;
            } else {
                a[i][j] = 0;
                mxx = i;
                mxy = j;
            }
        }
    }

    if(mxy >= 0) {
        bfs(mxx, mxy);
        bfs(mxx, mxy);
    }
    std::cout << "Maximum rope length is " << mxs << ".\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}