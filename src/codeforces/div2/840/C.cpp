/**
 * @author: XiaFan
 * @date: 12-19 23:06
 **/
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    i64 mx = *std::max_element(a.begin(), a.end());
    if (n > 3) {
        std::cout << mx * n << "\n";
        return;
    }
    if (n == 1) {
        std::cout << a[0] << "\n";
        return;
    }
    if (n == 2) {
        std::cout << std::max(a[0] + a[1], 2 * std::abs(a[0] - a[1])) << "\n";
        return;
    }
    if (mx == a[0] || mx == a[2]) {
        std::cout << mx * n << "\n";
        return;
    }
    i64 ans = a[0] + a[1] + a[2];
    ans = std::max(ans, 3 * a[0]);
    ans = std::max(ans, 3 * a[2]);
    ans = std::max(ans, 3 * std::abs(a[0] - a[2]));
    ans = std::max(ans, 3 * std::abs(a[0] - a[1]));
    ans = std::max(ans, 3 * std::abs(a[1] - a[2]));
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    
    return 0;
}