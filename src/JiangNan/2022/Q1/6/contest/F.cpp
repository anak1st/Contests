/**
 * @author: XiaFan
 * @date: 04-17 19:47
 **/
#include <bits/stdc++.h>

typedef long long i64;
typedef unsigned long long u64;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::string> s(n);
    int sx = 0, sy = 0;
    int blank = 0;
    for(int i = 0; i < n; i++) {
        std::cin >> s[i];
        for(int j = 0; j < m; j++) {
            if(s[i][j] == '.') {
                sx = i, sy = j;
                blank++;
                s[i][j] = 'X';
            }
        }
    }
    int need = blank - k;

    std::queue<std::pair<int, int>> q;
    if(need > 0) {
        s[sx][sy] = '.';
        need--;
    }
    q.push({sx, sy});
    while(!q.empty() && need > 0) {
        auto [x, y] = q.front();
        q.pop();

        // std::cout << x << " " << y << "\n";
        for(int i = 0; i < 4 && need > 0; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if(s[nx][ny] == 'X') {
                s[nx][ny] = '.';
                q.push({nx, ny});
                need--;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        std::cout << s[i] << "\n";
    }

    return 0;
}