/**
 * @author: XiaFan
 * @date: 2023-01-20 13:21
 **/
#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128_t;

bool fun(i64 n, i64 size) {
    i64 k = (n + 1) / 2;
    if (k >= size) {
        return true;
    }
    i64 x = size / k;
    i64 X = (size + k - 1) / k;
    i128 min = i128(1) * size * x + i128(1) * X * (size % k);
    return min <= n;
}

void solve() {
    i64 n;
    std::cin >> n;
    if (n == 1) {
        std::cout << 1 << "\n";
        return;
    }
    if (n == 2) {
        std::cout << -1 << "\n";
        return;
    }

    i64 l = 2, r = 1e18, ans = -1;
    while (l <= r) {
        i64 mid = (l + r) / 2;
        if (fun(n, mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    // std::cout << n << ": ";
    // std::cout << (i64)(2.0 * n / 3.0) << " ";
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