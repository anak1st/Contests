#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 n, l, r;
    std::cin >> n >> l >> r;
    
    i64 mn = n / l + l - 1;
    i64 p = l;
    
    if (n / r + r - 1 < mn) {
        mn = n / r + r - 1;
        p = r;
    }
    
    i64 x = std::sqrt(n);
    if (l <= x && x <= r && n / x + x - 1 < mn) {
        mn = n / x + x - 1;
        p = x;
    }
    x++;
    if (l <= x && x <= r && n / x + x - 1 < mn) {
        mn = n / x + x - 1;
        p = x;
    }
    
    i64 lo = l, hi = p;
    
    while (lo < hi) {
        i64 x = (lo + hi) / 2;
        if (n / x + x - 1 == mn) hi = x;
        else lo = x + 1;
    }
    
    std::cout << lo << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
