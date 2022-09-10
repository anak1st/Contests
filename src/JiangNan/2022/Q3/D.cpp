/**
 * @author: XiaFan
 * @date: 09-09 19:24
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 n, m, t;
    std::cin >> n >> m >> t;
    std::vector<i64> a(n);
    for (int i = 0; i < n - 1; i++) {
        std::cin >> a[i];
    }

    std::vector<i64> b(n, 0);
    for (int i = 0; i < m; i++) {
        i64 x, y;
        std::cin >> x >> y;
        x--;
        b[x] += y;
    }


    for (int i = 0; i < n; i++) {
        t += b[i];
        t -= a[i];
        if (t <= 0) {
            break;
        }

        if (i == n - 1) {
            std::cout << "Yes\n";
            return 0;
        }
    }

    std::cout << "No\n";
    return 0;
}