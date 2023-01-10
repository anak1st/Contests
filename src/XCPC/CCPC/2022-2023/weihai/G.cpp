/**
 * @author: XiaFan
 * @date: 11-09 20:00
 **/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 x, n;
    std::cin >> x >> n;

    auto F = [&](i64 k) -> bool {
        return std::gcd((k * x) ^ x, x) == 1; 
    };

    i64 N = pow(2, int(log2(x)) + 1);
    std::vector<i64> a(N + 1);

    for (int i = 1; i <= N; i++) {
        a[i] = a[i - 1] + F(i);
        // std::cout << i << " " << F(i) << "\n";
    }

    auto fun = [&](i64 x) -> i64 {
        i64 res = a[N] * (x / N) + a[x % N];
        return res;
    };

    auto slow = [&](i64 l, i64 r) -> i64 {
        i64 res = 0;
        for (i64 i = l; i <= r; i++) {
            res += F(i);
        }
        return res;
    };

    while (n--) {
        i64 l, r;
        std::cin >> l >> r;

        i64 ans = fun(r) - fun(l - 1);

        std::cout << ans << "\n";
    }

    return 0;
}