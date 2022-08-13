/**
 * @author: XiaFan
 * @date: 2022-04-10 19:48:39
 * @brief: full-contest
 **/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

typedef long long i64;

struct point {
    int x, y;
    point(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}

    friend bool operator==(const point &lhs, const point &rhs) {
        return (lhs.x == rhs.x && lhs.y == rhs.y);
    }

    friend bool operator<(const point &lhs, const point &rhs) {
        if(lhs.x == rhs.x) {
            return (lhs.y < rhs.y);
        }
        return (lhs.x < rhs.x);
    }

    bool in(point limit) {
        return (0 <= x && 0 <= y && x < limit.x && y < limit.y);
    }
};

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int n, m;
int a[200][200];
int b[200][200];

void bfs(point start) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            b[i][j] = 404;
        }
    }
    std::queue<point> q;
    q.push(start);
    b[start.x][start.y] = 0;
    while(!q.empty()) {
        point now = q.front();
        q.pop();

        for(int d = 0; d < 4; d++) {
            int nx = now.x + dx[d];
            int ny = now.y + dy[d];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny] == -1) {
                continue;
            }
            if(b[nx][ny] == 404) {
                b[nx][ny] = b[now.x][now.y] + 1;
                q.push(point(nx, ny));
            }
        }
    }
    return;
}

void solve() {
    point start1, start2;
    std::vector<point> kfc;
    for(int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == '#') {
                a[i][j] = -1;
            } else if(s[j] == '@') {
                a[i][j] = 1;
                kfc.push_back(point(i, j));
            } else {
                a[i][j] = 0;
                if(s[j] == 'Y') {
                    start1 = point(i, j);
                } else if(s[j] == 'M') {
                    start2 = point(i, j);
                }
            }
        }
    }
    int kfcnum = kfc.size();

    std::vector<int> ans(kfcnum, 0);
    bfs(start1);
    for(int i = 0; i < kfcnum; i++) {
        ans[i] += b[kfc[i].x][kfc[i].y];
    }
    bfs(start2);
    for(int i = 0; i < kfcnum; i++) {
        ans[i] += b[kfc[i].x][kfc[i].y];
    }
    int mn = 404;
    for(int i = 0; i < kfcnum; i++) {
        mn = std::min(mn, ans[i]);
    }
    std::cout << mn * 11 << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    while(std::cin >> n >> m) {
        solve();
    }

    return 0;
}