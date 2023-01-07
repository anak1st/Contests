#pragma once

#include <cassert>
#include <iostream>
#include <vector>

using i64 = long long;

constexpr int P = 1e9 + 7;

int mod(i64 x) {
    return (x % P + P) % P;
}

template <class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

struct Mint {
    int x;

    Mint() : x(0) {}
    Mint(int x) : x(mod(x)) {}
    Mint(i64 x) : x(mod(x)) {}

    int val() const {
        return x;
    }
    Mint operator+() const {
        return *this;
    }
    Mint operator-() const {
        return Mint(mod(P - x));
    }
    Mint inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }

    Mint &operator*=(const Mint &rhs) {
        x = mod(1LL * x * rhs.x);
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
    Mint &operator/=(const Mint &rhs) {
        *this *= rhs.inv();
        return *this;
    }

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

    Mint &operator++() {
        *this += 1;
        return *this;
    }
    Mint &operator--() {
        *this -= 1;
        return *this;
    }
    Mint operator++(int) {
        Mint res = *this;
        ++(*this);
        return res;
    }
    Mint operator--(int) {
        Mint res = *this;
        --(*this);
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

std::vector<Mint> fact, invfact;

void init(int sz) {
    fact.resize(sz + 1);
    invfact.resize(sz + 1);
    fact[0] = 1;
    for (int i = 1; i <= sz; i++) {
        fact[i] = fact[i - 1] * i;
    }
    invfact[sz] = fact[sz].inv();
    for (int i = sz; i; i--) {
        invfact[i - 1] = invfact[i] * i;
    }
}

Mint A(i64 n, i64 k) {
    if (k < 0 || k > n) {
        return 0;
    }
    return fact[n] * invfact[n - k];
}

Mint C(i64 n, i64 k) {
    if (k < 0 || k > n) {
        return 0;
    }
    return fact[n] * invfact[n - k] * invfact[k];
}

// template <typename T>
// T A(T n, T m) {
//     if (m > n)
//         return 0;
//     T ans = 1;
//     for (int i = 1; i <= m; i++) {
//         T a = n + i - m;
//         ans *= a;
//     }
//     return ans;
// }

// template <typename T>
// T C(T n, T m) {
//     if (m > n)
//         return 0;
//     T ans = 1;
//     for (int i = 1; i <= m; i++) {
//         T a = n + i - m;
//         ans = ans * a / i;
//     }
//     return ans;
// }
