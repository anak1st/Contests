/**
 * @author: XiaFan
 * @date: 2023-09-21 22:24
 */
#include <bits/stdc++.h>

using i64 = long long;
using i128 = __int128;

void solve() {
    i64 n, x;
    std::cin >> n >> x;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    i128 left = 1, right = 1e18, h = 1;
    while (left <= right) {
        i128 mid = (left + right) / 2;
        
        i128 cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += std::max((i128)0, mid - a[i]);
        }

        if (cnt <= x) {
            left = mid + 1;
            h = mid;
        } else {
            right = mid - 1;
        }
    }
    std::cout << (i64)h << "\n";
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