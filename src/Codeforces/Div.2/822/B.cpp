/**
 * @author: XiaFan
 * @date: 09-23 20:21
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cout << 1 << " ";
        for (int j = 1; j < i; j++) {
            std::cout << 0 << " ";
        }
        if (i >= 1) {
            std::cout << 1;
        }
        std::cout << "\n";
    }
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