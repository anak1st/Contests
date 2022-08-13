/**
 * @author: XiaFan
 * @date: 04-17 20:08
 **/
#include <bits/stdc++.h>

typedef long long i64;
typedef unsigned long long u64;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> s(n);
    std::vector<std::pair<int, int>> g, b;
    for(int i = 0; i < n; i++) {
        std::cin >> s[i];
        for(int j = 0; j < m; j++) {
            if(s[i][j] == 'G') {
                g.push_back({i, j});
            } else if(s[i][j] == 'B') {
                b.push_back({i, j});
            }
        }
    }

    for(auto [x, y] : b) {
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if(s[nx][ny] == '.') {
                s[nx][ny] = '#';
            }
        }
    }

    std::queue<std::pair<int, int>> q;
    if(s[n - 1][m - 1] != '#') {
        q.push({n - 1, m - 1});
    }
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if(s[nx][ny] != '#' && s[nx][ny] != '@') {
                s[nx][ny] = '@';
                q.push({nx, ny});
            }
        }
    }

    for(auto [x, y] : b) {
        if(s[x][y] == '@') {
            std::cout << "No\n";
            return;
        }
    }
    for(auto [x, y] : g) {
        if(s[x][y] != '@') {
            std::cout << "No\n";
            return;
        }
    }
    std::cout << "Yes\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}