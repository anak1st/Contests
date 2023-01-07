#pragma once
#include <cassert>
#include <iostream>
#include <vector>
using i64 = long long;

constexpr int P = 1e9 + 7;
template <typename T> T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
template <int Mod> struct MintBase {
    int x;
    int M() {
        if constexpr (Mod == -1) {
            return P;
        } else {
            return Mod;
        }
    }
    // assume -M <= x < 2 M
    int mod(int x) {
        if (x < 0) x += M();
        if (x >= P) x -= M();
        return x;
    }
    MintBase() : x(0) {}
    MintBase(int x) : x(mod(x)) {}
    MintBase(i64 x) : x(mod(x % M())) {}
    using Mint = MintBase<Mod>;
    int val() const { return x; }
    Mint operator-() const { return Mint(mod(M() - x)); }
    Mint inv() const {
        assert(x != 0);
        return power(*this, M() - 2);
    }
    friend bool operator==(const Mint &lhs, const Mint &rhs) { return lhs.x == rhs.x; }
    Mint &operator*=(const Mint &rhs) {
        x = 1LL * x * rhs.x % M();
        return *this;
    }
    Mint &operator+=(const Mint &rhs) {
        x = mod(x + rhs.x);
        return *this;
    }
    Mint &operator-=(const Mint &rhs) {
        x = mod(x - rhs.x);
        return *this;
    }
    Mint &operator/=(const Mint &rhs) { return *this *= rhs.inv(); }
    friend Mint operator*(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res *= rhs;
        return res;
    }
    friend Mint operator+(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res += rhs;
        return res;
    }
    friend Mint operator-(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res -= rhs;
        return res;
    }
    friend Mint operator/(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Mint &a) {
        i64 v;
        is >> v;
        a = Mint(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Mint &a) {
        return os << a.val();
    }
};
using Mint = MintBase<-1>;

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
