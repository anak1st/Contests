#pragma once

#include <cmath>
#include <tuple>

using i64 = long long;

bool isPrime(i64 x) {
    if (x <= 1) return false;
    i64 n = std::sqrt(x);
    for (i64 i = 2; i <= n; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

std::tuple<int, int, int> exgcd(int a, int b) {
    if (b == 0) {
        return {a, 1, 0};
    }
    auto [g, x, y] = exgcd(b, a % b);
    return {g, y, x - a / b * y};
}

i64 Euler(i64 n) {
    i64 res = n;
    for (i64 i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res = res / i * (i - 1);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        res = res / n * (n - 1);
    }
    return res;
}
