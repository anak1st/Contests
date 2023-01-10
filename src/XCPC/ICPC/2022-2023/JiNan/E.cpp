/**
 * @author: XiaFan
 * @date: 11-28 00:03
 **/
#include <bits/stdc++.h>
// #include "xf.hpp"

#ifndef DEBUG_XF
#define printIn(...)
#endif

using i64 = long long;

std::array<int, 3> exgcd(int a, int b) {
    if (b == 0) {
        return {a, 1, 0};
    }
    auto [g, x, y] = exgcd(b, a % b);
    return {g, y, x - a / b * y};
}

std::tuple<bool, int, int> fun(int a, int b, int c) {
    auto [g, x0, y0] = exgcd(a, b);
    int x1 = x0 * c / g;
    int y1 = y0 * c / g;
    int dx = b / g;
    int dy = a / g;
    for (int k = 0; true; k++) {
        int x = x1 + k * dx;
        int y = y1 - k * dy;
        if (x < 0) continue;
        if (y < 0) break;

        return {true, x, y};
    }
    return {false, 0, 0};
}

void solve() {
    int n, k;
    std::cin >> n >> k;

    if (k % 2 == 0) {
        std::cout << "Yes\n";
        return;
    }

    int a = n / k + 1;
    int b = n / k;
    int c = n / 2;

    auto [g, x0, y0] = exgcd(a, b);
    int x1 = x0 * c / g;
    int y1 = y0 * c / g;
    int dx = b / g;
    int dy = a / g;

    int maxx = n % k, maxy = k - maxx;

    bool ok = false;
    
    printIn(x1, y1, dx, dy);

    i64 L = -1e9, R = 1e9;
    while (L <= R) {
        i64 mid = (L + R) / 2;
        i64 x = x1 + mid * dx;
        i64 y = y1 - mid * dy;
        if (x < 0 || y > maxy) {
            L = mid + 1;
            continue;
        }
        if (y < 0 || x > maxx) {
            R = mid - 1;
            continue;
        }
        ok = true;
        break;
    }

    if (ok) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
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