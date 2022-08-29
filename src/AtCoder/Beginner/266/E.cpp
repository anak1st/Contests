/**
 * @author: XiaFan
 * @date: 08-27 20:47
 **/
#include <bits/stdc++.h>
using i64 = long long;

double fun(int n) {
    if (n == 1) {
        return 3.5;
    }

    double e_max = fun(n - 1);
    double e_ceil = ceil(e_max);
    double res = (e_ceil - 1) / 6.0 * e_max;
    for (int i = e_ceil; i <= 6; i++) {
        res += 1.0 / 6.0 * i;
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    double ans = fun(n);
    std::cout << std::fixed << std::setprecision(10) << ans;
    
    return 0;
}