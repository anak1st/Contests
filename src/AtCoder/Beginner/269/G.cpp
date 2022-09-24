/**
 * @author: XiaFan
 * @date: 09-20 18:59
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(n), cnt(2 * m + 1);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
        sum += a[i];
        cnt[m + b[i] - a[i]]++;
    }

    std::vector<int> dp(2 * m + 1, n + 1);
    dp[sum] = 0;
    for (int i = 0; i <= 2 * m; i++) {
        if (cnt[i] == 0) {
            continue;
        }

        for (int j = 0; cnt[i] > 0; j++) {
            int flip = std::min(1 << j, cnt[i]);
            cnt[i] -= flip;
            int add = flip * (i - m);
            if (add >= 0) {
                for (int k = m; k - add >= 0; k--) {
                    dp[k] = std::min(dp[k], dp[k - add] + flip);
                }
            } else {
                for (int k = 0; k <= m; k++) {
                    dp[k] = std::min(dp[k], dp[k - add] + flip);
                }
            }
        }
    }

    for (int i = 0; i <= m; i++) {
        if (dp[i] > n) {
            std::cout << -1 << "\n";
        } else {
            std::cout << dp[i] << "\n";
        }
    }

    return 0;
}