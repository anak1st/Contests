/**
 * @author: XiaFan
 * @date: 10-10 20:30
 **/
#include <bits/stdc++.h>
using i64 = long long;

i64 fun(i64 x) {
    if (x <= 0) {
        return 0;
    }
    i64 y = sqrt(x);
    if (y * y > x) {
        y--;
    }
    i64 res = y * 3 - 2;
    if (y * (y + 1) <= x) {
        res++;
    }
    if (y * (y + 2) <= x) {
        res++;
    }
    return res;
}

void solve() {
    i64 l, r;
    std::cin >> l >> r;
    std::cout << fun(r) - fun(l - 1) << "\n";
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