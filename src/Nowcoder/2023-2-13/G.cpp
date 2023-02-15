/**
 * @author: XiaFan
 * @date: 2023-02-15 19:14
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr int N = 200000;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n;
    std::cin >> n;

    std::vector<i64> a(N + 1);
    for (int i = 0; i < n; i++) {
        i64 x;
        std::cin >> x;
        while (x % 2 == 0) x /= 2;
        while (x % 5 == 0) x /= 5;
        a[x]++;
    }

    // a / b (b is a divisor of a)

    std::vector<i64> b(N + 1);
    i64 ans = n * n;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            b[j] += a[i];
        }
        ans -= b[i] * a[i];
    }
    std::cout << ans;

    return 0;
}