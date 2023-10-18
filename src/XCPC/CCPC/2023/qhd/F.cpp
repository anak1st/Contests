/**
 * @author: XiaFan
 * @date: 2023-10-17 15:22
 */
#include <bits/stdc++.h>

using i64 = long long;

bool is_prime(int x) {
    if (x == 1) {
        return false;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x : a) {
        std::cin >> x;
    }

    const int inf = n * 2;
    std::vector<std::array<int, 4>> dp(n, {inf, inf, inf, inf});
    /**
     * 0 change to 1
     * 1 change to even
     * 2 change to odd
     */
    dp[0] = {0, 1, 1, 1};

    auto chmin = [](int &x, int y) {
        if (x > y) {
            x = y;
        }
    };

    for (int i = 1; i < n; i++) {
        // 0 -> 0
        if (is_prime(a[i - 1] + a[i])) {
            chmin(dp[i][0], dp[i - 1][0]);
        }
        // 1 -> 0
        if (is_prime(a[i] + 1)) {
            chmin(dp[i][0], dp[i - 1][1]);
        }
        // 2 -> 0
        if (a[i] % 2) {
            chmin(dp[i][0], dp[i - 1][2]);
        }
        // 3 -> 0
        if (a[i] % 2 == 0) {
            chmin(dp[i][0], dp[i - 1][3]);
        }

        // 0 -> 1
        if (is_prime(a[i - 1] + 1)) {
            chmin(dp[i][1], dp[i - 1][0] + 1);
        }
        // 1 -> 1
        chmin(dp[i][1], dp[i - 1][1] + 1);
        // 2 -> 1
        chmin(dp[i][1], dp[i - 1][2] + 1);

        // 0 -> 2
        if (a[i - 1] % 2) {
            chmin(dp[i][2], dp[i - 1][0] + 1);
        }
        // 1 -> 2
        chmin(dp[i][2], dp[i - 1][1] + 1);
        // 3 -> 2
        chmin(dp[i][2], dp[i - 1][3] + 1);

        // 0 -> 3
        if (a[i - 1] % 2 == 0) {
            chmin(dp[i][3], dp[i - 1][0] + 1);
        }
        // 2 -> 3
        chmin(dp[i][3], dp[i - 1][2] + 1);
    }

    // for (int i = 0; i < n; i++) {
    //     std::cerr << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << "\n";
    // }

    auto ans = *std::min_element(dp[n - 1].begin(), dp[n - 1].end());
    std::cout << ans << "\n";
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