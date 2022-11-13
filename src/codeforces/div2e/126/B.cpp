/**
 * @author: XiaFan
 * @date: 2022-04-10 11:00:21
 * @brief: contest
 **/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> vis(32768 + 1, -1);
    std::queue<int> q;
    q.push(32768);
    vis[32768] = 0;
    vis[0] = 0;
    while(!q.empty()) {
        int x = q.front();
        int step = vis[x];
        q.pop();

        int next;
        if(x % 2 == 0) {
            next = x / 2;
            if(vis[next] == -1) {
                vis[next] = step + 1;
                q.push(next);
            }

            next = (x + 32768) / 2;
            if(vis[next] == -1) {
                vis[next] = step + 1;
                q.push(next);
            }
        }

        if(x > 0) {
            next = x - 1;
            if(vis[next] == -1) {
                vis[next] = step + 1;
                q.push(next);
            }
        }
    }
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        std::cout << vis[x] << ' ';
    }
    std::cout << '\n';
    return 0;
}