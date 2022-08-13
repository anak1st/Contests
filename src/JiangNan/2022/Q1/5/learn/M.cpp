#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

typedef long long i64;

struct point {
    int x, y;
    point(int _x = 0, int _y = 0) {
        x = _x;
        y = _y;
    }
    friend bool operator==(const point &lhs, const point &rhs) {
        return (lhs.x == rhs.x && lhs.y == rhs.y);
    }
};

int bfs(point start, point end) {
    const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
    const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

    int a[8][8];
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            a[i][j] = -1;
        }
    }

    std::queue<point> q;
    q.push(start);
    a[start.x][start.y] = 0;
    while(!q.empty()) {
        point cur = q.front();
        q.pop();
        if(cur == end) {
            break;
        }

        for(int i = 0; i < 8; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx < 0 || nx >= 8 || ny < 0 || ny >= 8) {
                continue;
            }
            if(a[nx][ny] == -1) {
                a[nx][ny] = a[cur.x][cur.y] + 1;
                q.push(point(nx, ny));
            }
        }
    }

    return a[end.x][end.y];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::string s1, s2;
    while(std::cin >> s1 >> s2) {
        int x1 = s1[0] - 'a';
        int y1 = s1[1] - '1';
        int x2 = s2[0] - 'a';
        int y2 = s2[1] - '1';
        int res = bfs(point(x1, y1), point(x2, y2));
        std::cout << "To get from " << s1 << " to " << s2;
        std::cout << " takes " << res << " knight moves.\n";
    }

    return 0;
}