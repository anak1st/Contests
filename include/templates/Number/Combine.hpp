#pragma once

#include <vector>

using i64 = long long;

template <typename T>
T A(T n, T m) {
    if (m > n)
        return 0;
    T ans = 1;
    for (int i = 1; i <= m; i++) {
        T a = n + i - m;
        ans *= a;
    }
    return ans;
}

template <typename T>
T C(T n, T m) {
    if (m > n)
        return 0;
    T ans = 1;
    for (int i = 1; i <= m; i++) {
        T a = n + i - m;
        ans = ans * a / i;
    }
    return ans;
}

#include "templates/Number/Modint.hpp"

namespace Fast {

constexpr int P = 1e9 + 7;
using Mint = Modint::MintBase<P>;

std::vector<Mint> fact;

void init() {
    fact.push_back(1);
}

Mint C(i64 n, i64 k) {
    if (k < 0 || k > n) {
        return 0;
    }
    while ((i64)fact.size() <= n) {
        fact.push_back(fact.back() * (i64)fact.size());
    }
    return fact[n] / fact[k] / fact[n - k];
}

} // namespace Fast
