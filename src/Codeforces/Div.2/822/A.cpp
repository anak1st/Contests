/**
 * @author: XiaFan
 * @date: 09-23 20:03
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
    i64 ans = 1e12;
    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j < 3; j++) {
            i64 temp = 0;
            for (int k = 0; k < 3; k++) {
                temp += std::abs(a[i + j] - a[i + k]);
            }
            ans = std::min(ans, temp);
        }
        
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