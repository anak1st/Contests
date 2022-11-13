/**
 * @author: XiaFan
 * @date: 10-30 21:45
 **/
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    i64 ans = 0;
    for (int i = 2; i < n; i++) {
        i64 tmp = std::abs(2 * a[i] - a[0] - a[i - 1]);
        ans = std::max(ans, tmp);
    }
    for (int i = 0; i < n - 2; i++) {
        i64 tmp = std::abs(2 * a[i] - a[n - 1] - a[i + 1]);
        ans = std::max(ans, tmp);
    }
    std::cout << ans << "\n";
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