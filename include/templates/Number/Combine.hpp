#pragma once
#include "templates/XCPC.h"
#include "templates/Number/Mint.hpp"

constexpr int Mod = 1e9 + 7;
using Mint = MintBase<Mod>;
std::vector<Mint> fact, invfact;
void init(int size) {
    fact.resize(size + 1);
    invfact.resize(size + 1);
    fact[0] = 1;
    for (int i = 1; i <= size; i++) {
        fact[i] = fact[i - 1] * i;
    }
    invfact[size] = fact[size].inv();
    for (int i = size; i > 0; i--) {
        invfact[i - 1] = invfact[i] * i;
    }
}
Mint A(i64 n, i64 k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[n - k];
}
Mint C(i64 n, i64 k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[n - k] * invfact[k];
}

// template <typename T>
// T A(T n, T m) {
//     if (m > n) return 0;
//     T ans = 1;
//     for (int i = 1; i <= m; i++) {
//         T a = n + i - m;
//         ans *= a;
//     }
//     return ans;
// }
// template <typename T>
// T C(T n, T m) {
//     if (m > n) return 0;
//     T ans = 1;
//     for (int i = 1; i <= m; i++) {
//         T a = n + i - m;
//         ans = ans * a / i;
//     }
//     return ans;
// }
