/**
 * @author: XiaFan
 * @date: 2023-03-11 13:15
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int l, r;
    std::cin >> l >> r;
    

    int len = r - l + 1;

    if (len == 1) {
        if (l == 1) {
            std::cout << 1 << "\n";
        } else {
            std::cout << -1 << "\n";
        }
        return;
    }
    
    if (len % 2 == 1 && l % 2 == 0) {
        std::cout << -1 << "\n";
        return;
    }

    std::vector<int> a(len);
    std::iota(a.begin(), a.end(), l);

    if (len % 2) {
        std::swap(a[0], a[2]);
    }

    for (int i = len % 2; i + 1 < len; i += 2) {
        std::swap(a[i], a[i + 1]);
    }

    for (int i = 0; i < r - l + 1; i++) {
        // assert(std::gcd(a[i], i + l) == 1);
        std::cout << a[i] << " ";
    }
    
    std::cout << "\n";
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