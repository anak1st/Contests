/**
 * @author: XiaFan
 * @date: 07-28 22:35
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    i64 n, l, r;
    std::cin >> n >> l >> r;
    std::vector<i64> a(n + 1);

    for (i64 i = 1; i <= n; i++) {
        i64 j = ((l - 1) / i + 1) * i;
        if (j > r) {
            std::cout << "NO\n";
            return;        
        }
        a[i] = j;
    }

    std::cout << "YES\n";
    for (int i = 1; i <= n; i++) {
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