/**
 * @author: XiaFan
 * @date: 12-04 13:34
 **/
#include <bits/stdc++.h>
// #include "xf.hpp"

#ifndef DEBUG_XF
#define printIn(...)
#endif

using i64 = long long;

template <typename T>
std::array<T, 3> exgcd(T a, T b) {
    if (b == 0) {
        return {a, 1, 0};
    }
    auto [g, x, y] = exgcd(b, a % b);
    return {g, y, x - a / b * y};
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 n, m;
    std::cin >> n >> m;
    i64 sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        sum += x;
    }
    auto mod = [&](i64 x) -> i64 {
        return (x % m + m) % m;
    };

    sum = mod(sum);
    
    // a * s + b * d + (sum - dif) = 0 mod m
    // (a * s + b * d) * k1 + m * (-k2) = - (sum - dif) mod m
    i64 a = n, b = 1ll * n * (n + 1) / 2;
	auto [g1, s, d] = exgcd(a, b);

	i64 dif = sum % std::gcd(g1, m);

	auto [g2, x, y] = exgcd(g1, m);
	i64 k1 = mod(x * (dif - sum) / g2);
	s = mod(s * k1);
	d = mod(d * k1);

	std::cout << dif << "\n";
	std::cout << s << " " << d << "\n";
    
    return 0;
}