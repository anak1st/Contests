/**
 * @author: XiaFan
 * @date: 10-16 23:19
 **/
#include <bits/stdc++.h>
using i64 = long long;

std::vector<i64> fun(i64 x) {
    std::vector<i64> res;
    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
            res.push_back(i);
            if (i * i != x) {
                res.push_back(x / i);
            }
        }
    }
    return res;
}

void solve() {
    i64 a, b, c, d;
    std::cin >> a >> b >> c >> d;
    
    auto A = fun(a);
    auto B = fun(b);
    for (auto x1 : A) {
        for (auto x2 : B) {
            i64 minx = x1 * x2;
            i64 miny = a * b / minx;
            i64 x = (a / minx + 1) * minx;
            i64 y = (b / miny + 1) * miny;
            if (x <= c && y <= d) {
                std::cout << x << " " << y << "\n";
                return;
            }
        }
    }

    std::cout << -1 << " " << -1 << "\n";
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