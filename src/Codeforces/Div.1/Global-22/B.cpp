/**
 * @author: XiaFan
 * @date: 09-30 22:57
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<i64> s(k + 1);
    for (int i = 1; i <= k; i++) {
        std::cin >> s[i];
    }

    if (k == 1) {
        std::cout << "YES\n";
        return;
    }

    std::vector<i64> a(k + 1);
    for (int i = 1; i <= k; i++) {
        a[i] = s[i] - s[i - 1];
    }
    
    for (int i = 2; i < k; i++) {
        if (a[i] > a[i + 1]) {
            std::cout << "NO\n";
            return;
        }
    }
    if (a[2] * (n - k + 1) < a[1]) {
        std::cout << "NO\n";
        return;
    }

    std::cout << "YES\n";
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