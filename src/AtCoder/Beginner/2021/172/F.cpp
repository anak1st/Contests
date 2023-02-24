/**
 * @author: XiaFan
 * @date: 2023-01-08 21:39
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    i64 xsum = 0;
    for (int i = 2; i < n; i++) {
        xsum ^= a[i];
    }
    i64 sum = a[0] + a[1];
    if (sum < xsum || (sum - xsum) % 2 != 0) {
        std::cout << -1;
        return 0;
    }
    i64 andsum = (sum - xsum) / 2;
    if (andsum & xsum) {
        std::cout << -1;
        return 0;
    }
    std::bitset<64> ans, x(xsum), y(andsum);
    for (int i = 60; i >= 0; i--) {
        if (!x[i] && y[i]) {
            ans[i] = true;
        }
    }
    for (int i = 60; i >= 0; i--) {
        if (x[i] && !y[i]) {
            ans[i] = true;
            if ((i64)ans.to_ullong() > a[0]) {
                ans[i] = false;
            }
        }
    }
    // std::cerr << ans.to_ullong();
    if ((i64)ans.to_ullong() > a[0] || ans.to_ullong() == 0) {
        std::cout << -1;
        return 0;
    }
    std::cout << a[0] - ans.to_ullong();

    return 0;
}