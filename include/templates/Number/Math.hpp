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

i64 euler(i64 n) {
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

template <typename T>
double Ternary(std::function<double(T)> F, std::pair<double, double> range,
               int limit = 1000) {
    double L = range.first, R = range.second;
    double Lmid, Rmid;
    for (int i = 0; i < limit; i++) {
        Lmid = L + (R - L) / 3;
        Rmid = R - (R - L) / 3;
        if (F(Lmid) < F(Rmid)) {
            R = Rmid;
        } else {
            L = Lmid;
        }
    }
    if constexpr (std::is_integral_v<T>) {
        return std::min(F(ceil(L)), F(floor(L)));
    } else {
        return F(L);
    }
}
