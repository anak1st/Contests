/**
 * @author: XiaFan
 * @date: 09-05 20:07
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);

    if (n == 3) {
        std::cout << "2 1 3\n";
        return;
    }

    std::iota(a.begin(), a.end(), 1);

    int m = n - 2;
    if (n % 2 == 1) {
        m--;
        a[n - 1] = 0;
    }

    int x = 0, y = 0;
    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            x ^= a[i];
        } else {
            y ^= a[i];
        }
    }
    a[m] = 114514 * 16;
    a[m + 1] = a[m] ^ x ^ y;

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    } 
    std::cout << "\n";
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