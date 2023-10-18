/**
 * @author: XiaFan
 * @date: 2023-10-18 16:30
 */
#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 1e18;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < n; i++) std::cin >> b[i];

    std::sort(a.begin(), a.end(), std::greater());
    std::sort(b.begin(), b.end(), std::greater());

    k = std::min(k, n);

    std::vector dp(k + 1, std::vector<i64>(k + 1));

    for (int i = n - 1; i >= 0; i--) {
        auto ndp = dp;
        for (int x = 0; x <= k; x++) {
            for (int y = 0; y <= k; y++) {
                ndp[x][y] = inf;
                int ia = x + i - y;
                int ib = y + (i + 1) - x;
                if (ia < 0 || ia > n || ib < 0 || ib > n) continue;

                if (ia < n) 
                    ndp[x][y] = std::min(ndp[x][y], dp[x][y]);
                if (ib < n && y < k) 
                    ndp[x][y] = std::min(ndp[x][y], dp[x][y + 1] - b[ib]);
            }
        }
        std::swap(dp, ndp);
        for (int x = 0; x <= k; x++) {
            for (int y = 0; y <= k; y++) {
                ndp[x][y] = -inf;
                int ia = x + i - y;
                int ib = y + i - x;
                if (ia < 0 || ia > n || ib < 0 || ib > n) continue;

                if (ib < n) 
                    ndp[x][y] = std::max(ndp[x][y], dp[x][y]);
                if (ia < n && x < k) 
                    ndp[x][y] = std::max(ndp[x][y], dp[x + 1][y] + a[ia]);
            }
        }
        std::swap(dp, ndp);
    }

    std::cout << dp[0][0] << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}