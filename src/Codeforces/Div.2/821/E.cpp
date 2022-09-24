/**
 * @author: XiaFan
 * @date: 09-21 20:35
 **/
#include <bits/stdc++.h>
using i64 = long long;

i64 get(i64 t, int x, int y) {
    std::vector a(121, std::vector<i64>(121, 0));
    a[0][0] = std::max(t - (x + y) + 1, 0ll);
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            a[i + 1][j] += a[i][j] / 2;
            a[i][j + 1] += a[i][j] - a[i][j] / 2;
        }
    }
    return a[x][y];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    while (n--) {
        i64 t;
        int x, y;
        std::cin >> t >> x >> y;
        if (get(t, x, y) - get(t - 1, x, y) > 0) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }

    return 0;
}