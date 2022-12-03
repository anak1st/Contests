#pragma once

#include <array>
#include <cmath>

std::array<int, 3> exgcd(int a, int b) {
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

template <typename T>
T A(T n, T m) {
    if (m > n) return 0;
    T ans = 1;
    for (int i = 1; i <= m; i++) {
        T a = n + i - m;
        ans *= a;
    }
    return ans;
}

template <typename T>
T C(T n, T m) {
    if (m > n) return 0;
    T ans = 1;
    for (int i = 1; i <= m; i++) {
        T a = n + i - m;
        ans = ans * a / i;
    }
    return ans;
}