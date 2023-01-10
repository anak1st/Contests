/**
 * @author: XiaFan
 * @date: 09-28 19:25
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, x, y;
    std::cin >> n >> x >> y;
    x--, y--;
    std::vector<std::vector<int>> G(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    bool ok = false;
    std::vector<int> ans;
    std::function<void (int, int)> dfs = [&](int p, int f) {
        if (ok || p == y) {
            ok = true;
            return;
        }
        for (auto v : G[p]) {
            if (v == f) {
                continue;
            }
            ans.push_back(v);
            dfs(v, p);
            if (ok) {
                return;
            }
            ans.pop_back();
        }
    };

    ans.push_back(x);
    dfs(x, -1);
    for (auto i : ans) {
        std::cout << i + 1 << " ";
    }
    
    return 0;
}