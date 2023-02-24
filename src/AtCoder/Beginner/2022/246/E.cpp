/**
 * @author: XiaFan
 * @date: 2022-04-16 13:19:12
 * @brief: contest
 **/
#include <bits/stdc++.h>

using i64 = long long;

struct point {
    int x, y;
    point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    friend bool operator==(const point &lhs, const point &rhs) {
        return (lhs.x == rhs.x && lhs.y == rhs.y);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    point a, b;
    std::cin >> a.x >> a.y;
    a.x--, a.y--;
    std::cin >> b.x >> b.y;
    b.x--, b.y--;

    std::vector<std::string> s(n);
    for(int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    std::vector v(n, std::vector(n, std::vector<int>(2, 0)));
    std::queue<std::tuple<point, int>> q;
    q.push({a, 0});
    v[a.x][a.y][0] = 1;
    v[a.x][a.y][1] = 1;

    const int d[] = {0, 0, 1, 1};
    const int dx[] = {1, -1, -1, 1};
    const int dy[] = {1, -1, 1, -1};

    while(!q.empty()) {
        auto [now, time] = q.front();
        q.pop();

        if(now == b) {
            std::cout << time << "\n";
            return 0;
        }

        for(int i = 0; i < 4; i++) {
            auto [x, y] = now;
            while(true) {
                x += dx[i];
                y += dy[i];
                if(x < 0 || x >= n || y < 0 || y >= n) {
                    break;
                }
                if(s[x][y] == '#' || v[x][y][d[i]]) {
                    break;
                }
                v[x][y][d[i]] = 1;
                q.push({point(x, y), time + 1});
            }
        }
    }

    std::cout << "-1\n";
    return 0;
}