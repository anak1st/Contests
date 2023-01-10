#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    
    auto check = [&](int x) {
        std::vector<int> c(n), d(n);
        for (int i = 0; i < n; i++) {
            c[i] = a[i] & x;
            d[i] = ~b[i] & x;
        }
        std::sort(c.begin(), c.end());
        std::sort(d.begin(), d.end());
        return c == d;
    };
    
    std::bitset<32> bit;
    for (int d = 29; d >= 0; d--) {
        auto next = bit;
        next[d] = true;
        if (check(next.to_ulong())) {
            bit = next;
        }
    }
    std::cout << bit.to_ulong() << "\n";
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
