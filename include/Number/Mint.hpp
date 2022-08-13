#pragma once

#include <assert.h>
#include <iostream>

using i64 = long long;
constexpr int P = 998244353;

int mod(i64 x) {
    x = (x % P + P) % P;
    return x;
}

template <typename T> T fastPower(T a, int x) {
    T res = 1;
    while (x > 0) {
        if (x % 2) {
            res *= a;
        }
        x /= 2;
        a *= a;
    }
    return res;
}

struct Mint {
    int x;
    Mint(int _x = 0) : x(mod(_x)) {}
    int val() const {
        return x;
    }

    Mint operator-() const {
        return Mint(mod(-x));
    }

    Mint &operator+=(const Mint &rhs) {
        x = mod(x + rhs.x);
        return *this;
    }
    Mint &operator-=(const Mint &rhs) {
        x = mod(x - rhs.x);
        return *this;
    }
    Mint &operator*=(const Mint &rhs) {
        x = mod(1ll * x * rhs.x);
        return *this;
    }
    Mint &operator/=(const Mint &rhs) {
        assert(rhs.x != 0);
        x = mod(x / rhs.x);
        return *this;
    }

    friend Mint operator+(const Mint &lhs, const Mint &rhs) {
        Mint res(lhs.x);
        res += rhs;
        return res;
    }
    friend Mint operator-(const Mint &lhs, const Mint &rhs) {
        Mint res(lhs.x);
        res -= rhs;
        return res;
    }
    friend Mint operator*(const Mint &lhs, const Mint &rhs) {
        Mint res(lhs.x);
        res *= rhs;
        return res;
    }
    friend Mint operator/(const Mint &lhs, const Mint &rhs) {
        Mint res(lhs.x);
        res /= rhs;
        return res;
    }

    friend std::istream &operator>>(std::istream &is, Mint &m) {
        i64 val;
        is >> val;
        m.x = mod(val);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, Mint &m) {
        os << m.val();
        return os;
    }
};
