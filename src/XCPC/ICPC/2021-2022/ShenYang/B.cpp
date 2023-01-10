/**
 * @author: XiaFan
 * @date: 11-13 22:19
 **/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::array<int, 2>>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        x--, y--;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }

    std::vector<int> a(n, -1);
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != -1) {
            continue;
        }
        a[i] = 0;
        
        std::vector<int> now;
        now.push_back(i);
        std::queue<int> q;
        q.push(i);
        
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto [y, z] : adj[x]) {
                if (a[y] == -1) {
                    a[y] = a[x] ^ z;
                    now.push_back(y);
                    q.push(y);
                } else if (a[y] != (a[x] ^ z)) {
                    std::cout << -1;
                    return 0;
                }
            }
        }

        for (int i = 0; i < 30; i++) {
            int cnt = 0;
            for (auto j : now) {
                if (std::bitset<32>(a[j])[i]) {
                    cnt++;
                }
            }
            ans += std::min(cnt, int(now.size()) - cnt) * (1LL << i);
        }
    }
    std::cout << ans;

    return 0;
}