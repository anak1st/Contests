/**
 * @author: XiaFan
 * @date: 2022-04-09 10:37:35
 * @brief: full-contest
 **/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

typedef long long i64;

struct point {
    int x, y;
    point(int x = 0, int y = 0) : x(x), y(y) {}

    friend bool operator==(const point &lhs, const point &rhs) {
        return (lhs.x == rhs.x && lhs.y == rhs.y);
    }

    friend bool operator<(const point &lhs, const point &rhs) {
        if(lhs.x == rhs.x) {
            return (lhs.y < rhs.y);
        }
        return (lhs.x < rhs.x);
    }

    bool in(int min_x, int max_x, int min_y, int max_y) {
        return (min_x <= x && x <= max_x && min_y <= y && y <= max_y);
    }
};

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
// left, right, top, bot

int n, m;
int a[500][500], vis[500][500][3];

struct bloxorz {
    point p;
    int direct, step;
    // 0 stand
    // 1 left to right
    // 2 top to bot
    bloxorz(point p, int direct, int step) : p(p), direct(direct), step(step) {}

    bool ok() {
        if(!p.in(0, n - 1, 0, m - 1)) {
            return false;
        }
        if(direct == 0) {
            return a[p.x][p.y] >= 2;
        }

        point other = p;
        if(direct == 1) {
            other.y++;
            if(!other.in(0, n - 1, 0, m - 1)) {
                return false;
            }
        }
        if(direct == 2) {
            other.x++;
            if(!other.in(0, n - 1, 0, m - 1)) {
                return false;
            }
        }
        return (a[p.x][p.y] >= 1 && a[other.x][other.y] >= 1);
    }
};

int bfs(point start, int direct, point end) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < 3; k++) {
                vis[i][j][k] = false;
            }
        }
    }
    std::queue<bloxorz> q;
    q.push(bloxorz(start, direct, 0));
    vis[start.x][start.y][direct] = true;
    while(!q.empty()) {
        bloxorz now = q.front();
        q.pop();

        if(now.direct == 0 && now.p == end) {
            return now.step;
        }

        for(int i = 0; i < 4; i++) {
            // left, right, top, bot
            bloxorz next = now;
            switch(next.direct) {
            case 0:
                switch(i) {
                case 0:
                    next.p.y -= 2;
                    next.direct = 1;
                    break;  // swich i
                case 1:
                    next.p.y += 1;
                    next.direct = 1;
                    break;  // swich i
                case 2:
                    next.p.x -= 2;
                    next.direct = 2;
                    break;  // swich i
                case 3:
                    next.p.x += 1;
                    next.direct = 2;
                    break;  // swich i
                }
                break;  // swich next.direct
            case 1:
                switch(i) {
                case 0:
                    next.p.y -= 1;
                    next.direct = 0;
                    break;  // swich i
                case 1:
                    next.p.y += 2;
                    next.direct = 0;
                    break;  // swich i
                case 2:
                    next.p.x -= 1;
                    break;  // swich i
                case 3:
                    next.p.x += 1;
                    break;  // swich i
                }
                break;  // swich next.direct
            case 2:
                switch(i) {
                case 0:
                    next.p.y -= 1;
                    break;  // swich i
                case 1:
                    next.p.y += 1;
                    break;  // swich i
                case 2:
                    next.p.x -= 1;
                    next.direct = 0;
                    break;  // swich i
                case 3:
                    next.p.x += 2;
                    next.direct = 0;
                    break;  // swich i
                }
                break;  // swich next.direct
            }
            if(next.ok() && !vis[next.p.x][next.p.y][next.direct]) {
                vis[next.p.x][next.p.y][next.direct] = true;
                next.step++;
                q.push(next);
            }
        }
    }

    return -1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    while(true) {
        std::cin >> n >> m;
        if(n == 0 && m == 0) {
            break;
        }

        point start(-1, -1), end;
        int direct = 0;
        for(int i = 0; i < n; i++) {
            std::string s;
            std::cin >> s;
            for(int j = 0; j < m; j++) {
                if(s[j] == '#') {
                    a[i][j] = 0;
                } else if(s[j] == 'E') {
                    a[i][j] = 1;
                } else {
                    a[i][j] = 2;
                    if(s[j] == 'X') {
                        if(start.y >= 0) {
                            if(j > start.y) {
                                direct = 1;
                            } else {
                                direct = 2;
                            }
                        } else {
                            start = point(i, j);
                        }
                    } else if(s[j] == 'O') {
                        end = point(i, j);
                    }
                }
            }
        }

        int res = bfs(start, direct, end);
        if(res == -1) {
            std::cout << "Impossible\n";
        } else {
            std::cout << res << '\n';
        }
    }

    return 0;
}