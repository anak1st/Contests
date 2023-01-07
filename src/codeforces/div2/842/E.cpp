/**
 * @author: XiaFan
 * @date: 01-07 09:55
 **/
#include <bits/stdc++.h>

// #include "debug.hpp"
#ifndef DEBUG_HPP
#define printIn(...)
#define Timer int
#endif

using i64 = long long;

int P;

int mod(i64 x) {
    x %= P;
    if (x < 0) {
        x += P;
    }
    return x;
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
        return *this *= rhs.inv();
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

void solve() {
    int n;
    std::cin >> n;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n >> P;

    init(3 * n);

    Mint ans[4];
    ans[0] = 1;
    ans[1] = fact[2 * n] * 2 - fact[n];
    ans[1] -= ans[0];
    ans[2] = C(2 * n, n) * 2 * fact[2 * n] * fact[n];
    for (int i = 0; i <= n; i++) {
        ans[2] -= C(n, i) * C(n, n - i) * C(2 * n - i, n) * fact[n] * fact[n] * fact[n];
    }
    ans[2] -= ans[1] + ans[0];
    ans[3] = fact[3 * n] - ans[2] - ans[1] - ans[0];
    Mint tot = ans[1] * 1 + ans[2] * 2 + ans[3] * 3;
    std::cout << tot << std::endl;

    return 0;
}