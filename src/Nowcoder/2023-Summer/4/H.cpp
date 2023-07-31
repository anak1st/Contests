/**
 * @author: XiaFan
 * @date: 2023-07-28 16:38
 */
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;


    // 
    
    auto fun = [&](auto &&fun, int x, int y, int k) {
        if (k % 2 == 0) {
            fun(fun, x, y, k / 2);
            fun(fun, x + k / 2, y, k / 2);
            fun(fun, x, y + k / 2, k / 2);
            fun(fun, x + k / 2, y + k / 2, k / 2);
        } else {
            // int k1 = k / 3;
            // int k2 = k - k1 * 2;
            // int k3 = 2 * k1;
            // fun(fun, x, y, z);
        }

        std::cout << x << ' ' << y << ' ' << k << '\n';
    };

    return 0;
}