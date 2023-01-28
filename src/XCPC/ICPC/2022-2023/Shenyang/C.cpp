/**
 * @author: XiaFan
 * @date: 11-06 15:55
 **/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, d;
    std::cin >> n >> d;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    auto get_sum = [&](i64 l, i64 r) -> i64 {
        std::vector<i64> b(a);
        for (int i = 0; i < n; i++) {
            b[i] = std::clamp(b[i], l, r);
        }

        i64 tmp = 0;
        for (int i = 0; i < n - 1; i++) {
            tmp += std::abs(b[i] - b[i + 1]);
        }
        return tmp;
    };

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans = std::max(ans, get_sum(a[i], a[i] + d));
        ans = std::max(ans, get_sum(a[i] - d, a[i]));
    }
    std::cout << ans << "\n";
    
    return 0;
}