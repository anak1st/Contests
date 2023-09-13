#pragma once
#include "XCPC.h"

template <typename T> T power(T a, i64 b, T mod) {
    T res = 1;
    for (; b; b /= 2, a = (a * a) % mod) {
        if (b % 2) {
            res = (res * a) % mod;
        }
    }
    return res;
}
template <typename T> T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

std::array<i64, 3> exgcd(i64 a, i64 b) {
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


void subset(int x) {
    for (int i = x; ; i = (i - 1) & x) {
        // do something
        if (!i) break;
    }
}


// return sum_{i = 0}^{n - 1} (a0 + i * d) // div
template <typename T> 
T seq_div_sum(T a0, T d, T n, T div) {
    if (n <= 0) return 0;
    if (n == 1) return (a0 / div);
    T tmp = 0;
    tmp += (d / div) * (n - 1) * n / 2;
    tmp += (a0 / div) * n;
    d = d % div;
    a0 = a0 % div;
    if (d == 0) {
        return tmp;
    } else {
        return tmp + seq_div_sum((d * n + a0) % div, div, (d * n + a0) / div, d);
    }
}
