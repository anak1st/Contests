/**
 * @author: XiaFan
 * @date: 12-31 15:39
 **/
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector a(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }

    auto check = [&](int x) -> bool {
        std::vector f(n + 1, std::vector<int>(m + 1));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                f[i][j] = std::min(f[i + 1][j], f[i][j + 1]) + 1;
                if (a[i + f[i][j] - 1][j + f[i][j] - 1] < x) {
                    f[i][j]--;
                }
                if (a[i][j] < x) {
                    f[i][j] = 0;
                }
                if (f[i][j] >= x) {
                    return true;
                }
            }
        }
        return false;
    };

    int left = 1, right = std::max(n, m), ans = 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}