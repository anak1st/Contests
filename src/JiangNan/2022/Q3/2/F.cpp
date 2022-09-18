/**
 * @author: XiaFan
 * @date: 09-16 19:36
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    double n, p1, v1, p2, v2;
    std::cin >> n >> p1 >> v1 >> p2 >> v2;
    if (p1 > p2) {
        p1 = n - p1;
        p2 = n - p2;
    }

    auto fun1 = [&](int a, int b, int c, int d) -> double {
        double temp = 1e18;
        double left = p1, right = p2;
        while (right - left > 1e-10) {
            double mid = (right + left) / 2;
            double x = mid - p1;
            double y = p2 - mid;
            double t1 = (a * p1 + b * x) / v1;
            double t2 = (c * (n - p2) + d * y) / v2;
            if (t1 >= t2) {
                right = mid;
            } else {
                left = mid;
            }
            temp = std::min(temp, std::max(t1, t2));
        }
        return temp;
    };

    double ans = 1e18;
    ans = std::min(ans, fun1(2, 1, 2, 1));
    ans = std::min(ans, fun1(1, 2, 2, 1));
    ans = std::min(ans, fun1(2, 1, 1, 2));
    ans = std::min(ans, fun1(1, 2, 1, 2));

    auto fun2 = [&]() -> double {
        double t1 = (n - p1) / v1;
        double t2 = p2 / v2;
        return std::max(t1, t2);
    };

    ans = std::min(ans, fun2());

    auto fun3 = [&](int a, int b) -> double {
        double t1 = (a * p1 + b * (n - p1)) / v1;
        double t2 = (a * p2 + b * (n - p2)) / v2;
        return std::min(t1, t2);
    };

    ans = std::min(ans, fun3(2, 1));
    ans = std::min(ans, fun3(1, 2));

    std::cout << std::fixed << std::setprecision(10) << ans << "\n";
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