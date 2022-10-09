/**
 * @author: XiaFan
 * @date: 09-30 19:12
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    i64 k;
    std::cin >> n >> k;
    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    auto check = [&](i64 m) -> i64 {
        i64 res = 0, b = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] + b < m) {
                b = 0;
            }
            res += (a[i] + b) / m;
            b = (a[i] + b) % m;
        }
        return res;
    };

    i64 left = 1, right = 1e15;
    i64 ans = 0;
    while (left <= right) {
        i64 mid = (left + right) / 2;
        if (check(mid) >= k) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid - 1;
        }
    }

    std::cout << ans * k << "\n";
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