#pragma once

#include <cmath>

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
