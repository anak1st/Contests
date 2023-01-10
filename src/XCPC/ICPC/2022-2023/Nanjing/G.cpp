/**
 * @author: XiaFan
 * @date: 12-18 19:47
 **/
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &x : a) std::cin >> x;

    int x = 1, y = 1;
    auto fun1 = [&]() {
        x++, y++;
    };
    auto fun2 = [&]() {
        y--;
    };
    int z = 0;
    for (auto t : a) {
        if (t == 1) {
            fun1();
        }
        if (t == -1) {
            fun2();
        }
        if (t == 0) {
            z++;
        }
        if (y == 0) {
            if (z > 0) {
                z--;
                fun1();
            } else {
                std::cout << -1 << "\n";
                return;
            }
        }
    }

    while (z--) {
        if (y > 1) fun2();
        else fun1();
    }

    int g = std::gcd(x, y);
    x /= g;
    y /= g;
    std::cout << x << ' ' << y << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    
    return 0;
}