/**
 * @author: XiaFan
 * @date: 10-05 20:35
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::array<int, 3>> a(m);
    for (int i = 0; i < m; i++) {
        std::cin >> a[i][0] >> a[i][1] >> a[i][2];
        a[i][0]--;
        a[i][1]--;
    }
    std::vector<int> e(k);
    for (int i = 0; i < k; i++) {
        std::cin >> e[i];
        e[i]--;
    }

    const i64 inf = 1e18;
    std::vector<i64> d(n, inf);
    d[0] = 0;
    for (int i = 0; i < k; i++) {
        auto [x, y, z] = a[e[i]];
        if (d[x] == inf) {
            continue;
        }
        d[y] = std::min(d[y], d[x] + z);
    }
    if (d[n - 1] == inf) {
        std::cout << -1;
    } else {
        std::cout << d[n - 1];
    }
    
    return 0;
}