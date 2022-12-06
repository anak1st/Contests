#pragma once

#include <array>
#include <cmath>
#include <functional>

template <typename T>
std::array<T, 3> exgcd(T a, T b) {
    if (b == 0) {
        return {a, 1, 0};
    }
    auto [g, x, y] = exgcd(b, a % b);
    return {g, y, x - a / b * y};
}

template <typename T>
T euler(T n) {
    T res = n;
    for (T i = 2; i * i <= n; i++) {
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

double Ternary(std::function<double(double)> F, int limit) {
    double L = 0, R = 1e18;
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
    // if input_type is float / double
    // double ans = F(L);
    // if input_type is int / i64
    double ans = std::min(F(ceil(L)), F(floor(L)));
    return ans;
}
