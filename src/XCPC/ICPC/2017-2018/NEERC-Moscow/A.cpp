/**
 * @author: XiaFan
 * @date: 2023-01-09 20:48
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, k;
    std::cin >> n >> k;
    
    if (k >= n) {
        std::cout << 1;
        return 0;
    }
    
    auto fun = [&](i64 x) {
        return x + std::min(x, (n - x) / 2);
    };

    i64 ans = 1e9;
    for (i64 i = 1; i <= k - 1; i++) {
        i64 d = 1, a = i;
        while (a < n) {
            a = fun(a);
            d++;
            if (fun(a + k - i) >= n) {
                break;
            }
        }
        ans = std::min(ans, d);
    }

    std::cout << ans;

    return 0;
}