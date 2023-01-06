// from jiangly
#pragma once

#include <cassert>
#include <iostream>

using i64 = long long;

constexpr int P = 1e9 + 7;

template <typename T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

int mod(i64 x) {
    return (x % P + P) % P;
}

struct Mint {
    int v;

    Mint() : v(0) {}
    Mint(int x) : v(mod(x)) {}
    Mint(i64 x) : v(mod(x)) {}

    int val() const {
        return v;
    }

    friend std::istream &operator>>(std::istream &is, Mint &a) {
        i64 x;
        is >> x;
        a = mod(x);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Mint &a) {
        os << a.val();
        return os;
    }

    Mint operator-() const {
        return Mint(-v);
    }

    Mint inv() const {
        assert(v != 0);
        return power(*this, P - 2);
    }

    Mint &operator++() {
        return *this += 1;
    }
    Mint &operator--() {
        return *this -= 1;
    }
    Mint operator++(int) {
        Mint res = *this;
        *this += 1;
        return res;
    }
    Mint operator--(int) {
        Mint res = *this;
        *this -= 1;
        return res;
    }

    Mint &operator+=(const Mint &rhs) {
        v = mod(v + rhs.v);
        return *this;
    }
    Mint &operator-=(const Mint &rhs) {
        v = mod(v - rhs.v);
        return *this;
    }
    Mint &operator*=(const Mint &rhs) {
        v = mod(1LL * v * rhs.v);
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
};
