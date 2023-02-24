/**
 * @author: XiaFan
 * @date: 2023-02-23 19:16
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    i64 n, d, k;
    std::cin >> n >> d >> k;
    k--;
    // t * d = n * c
    // t * d = lcm(n, d)
    // t = lcm(n, d) / d = n * d / (gcd(n, d) * d) = n / gcd(n, d)
    i64 t = n / std::gcd(n, d);
    i64 x = (k * d + k / t) % n;
    std::cout << x << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}