/**
 * @author: XiaFan
 * @date: 04-17 19:15
 **/
#include <bits/stdc++.h>

typedef long long i64;
typedef unsigned long long u64;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::pair<int, int> a, b;
    std::cin >> a.first >> a.second;
    a.first--, a.second--;
    std::cin >> b.first >> b.second;
    b.first--, b.second--;
    std::vector<std::string> s(n);
    for(int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    std::set<std::pair<int, int>> sa;
    sa.insert(a);
    std::set<std::pair<int, int>> sb;
    sb.insert(b);

    std::queue<std::pair<int, int>> q;
    q.push(a);
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || s[nx][ny] == '1') {
                continue;
            }
            if(!sa.count({nx, ny})) {
                sa.insert({nx, ny});
                q.push({nx, ny});
            }
        }
    }

    q.push(b);
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || s[nx][ny] == '1') {
                continue;
            }
            if(!sb.count({nx, ny})) {
                sb.insert({nx, ny});
                q.push({nx, ny});
            }
        }
    }

    int ans = 2500 * 2;
    for(auto i : sa) {
        for(auto j : sb) {
            int d = 0;
            d += (i.first - j.first) * (i.first - j.first);
            d += (i.second - j.second) * (i.second - j.second);
            ans = std::min(ans, d);
        }
    }

    std::cout << ans << "\n";

    return 0;
}