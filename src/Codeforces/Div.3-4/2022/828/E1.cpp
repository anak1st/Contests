/**
 * @author: XiaFan
 * @date: 10-16 23:19
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    i64 a, b, c, d;
    std::cin >> a >> b >> c >> d;
    i64 ab = a * b;
    for (i64 x = a + 1; x <= c; x++) {
        i64 xy = std::lcm(x, ab);
        i64 miny = xy / x;
        i64 begin = b / miny * miny;
        for (i64 y = begin; y <= d; y += miny) {
            if (b < y) {
                std::cout << x << " " << y << "\n";
                return;
            }
        }
        
    }
    std::cout << "-1 -1\n";
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