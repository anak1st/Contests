/**
 * @author: XiaFan
 * @date: 09-05 19:19
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    
    std::vector a(1001, std::vector<i64>(1001));
    for (int i = 0; i < n; i++) {
        int h, w;
        std::cin >> h >> w;
        a[h][w]++;
    }

    std::vector b(1001, std::vector<i64>(1001));
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            b[i][j] = b[i][j - 1] + a[i][j] * i * j;
        }
    }

    for (int i = 0; i < q; i++) {
        int h1, w1, h2, w2;
        std::cin >> h1 >> w1 >> h2 >> w2;
        i64 ans = 0;
        for (int j = h1 + 1; j < h2; j++) {
            ans += b[j][w2 - 1] - b[j][w1];
        }
        std::cout << ans << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}