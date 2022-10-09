/**
 * @author: XiaFan
 * @date: 10-05 20:50
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector a(n, std::vector<i64>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    }

    std::vector<std::map<int, i64>> mp(n);

    std::function<void (int, int, i64)> 
    dfs1 = [&](int x, int y, i64 z) {
        z ^= a[x][y];
        if (x + y == n - 1) {
            mp[x][z]++;
            return;
        }
        dfs1(x + 1, y, z);
        dfs1(x, y + 1, z);
    };

    i64 ans = 0;

    std::function<void (int, int, i64)> 
    dfs2 = [&](int x, int y, i64 z) {
        if (x + y == n - 1) {
            if (mp[x].count(z)) {
                ans += mp[x][z];
            }
            return;
        }
        z ^= a[x][y];
        dfs2(x - 1, y, z);
        dfs2(x, y - 1, z);
    };

    dfs1(0, 0, 0);
    dfs2(n - 1, n - 1, 0);
    std::cout << ans;
    
    return 0;
}