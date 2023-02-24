/**
 * @author: XiaFan
 * @date: 09-07 18:58
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<i64> costs(n);
    std::vector<std::vector<int>> G(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        costs[x] += a[y];
        costs[y] += a[x];
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    std::set<std::pair<i64, int>> p;
    for (int i = 0; i < n; i++) {
        p.insert({costs[i], i});
    }

    i64 ans = 0;
    std::vector<bool> del(n, false);
    for (int i = 0; i < n; i++) {
        auto [cost, x] = *p.begin();
        ans = std::max(ans, cost);
        del[x] = true;
        p.erase(p.begin());
        for (auto y : G[x]) {
            if (del[y]) 
                continue;
            p.erase({costs[y], y});
            costs[y] -= a[x];
            p.insert({costs[y], y});
        }
    }

    std::cout << ans;
    
    return 0;
}