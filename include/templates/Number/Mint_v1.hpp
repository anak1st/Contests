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
    using Self = Mint;

    int v;

    Mint() : v(0) {}
    Mint(int x) : v(mod(x)) {}
    Mint(i64 x) : v(mod(x)) {}

    int val() const {
        return v;
    }

    friend std::istream &operator>>(std::istream &is, Self &a) {
        i64 x;
        is >> x;
        a.v = mod(x);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Self &a) {
        os << a.val();
        return os;
    }

    Self operator-() const {
        return Self(-v);
    }

    Self inv() const {
        assert(v != 0);
        return power(*this, P - 2);
    }

    Self &operator++() {
        return *this += 1;
    }
    Self &operator--() {
        return *this -= 1;
    }
    Self operator++(int) {
        Self res = *this;
        *this += 1;
        return res;
    }
    Self operator--(int) {
        Self res = *this;
        *this -= 1;
        return res;
    }

    Self &operator+=(const Self &rhs) {
        v = mod(v + rhs.v);
        return *this;
    }
    Self &operator-=(const Self &rhs) {
        v = mod(v - rhs.v);
        return *this;
    }
    Self &operator*=(const Self &rhs) {
        v = mod(1LL * v * rhs.v);
        return *this;
    }
    Self &operator/=(const Self &rhs) {
        *this *= rhs.inv();
        return *this;
    }

    friend Self operator*(const Self &lhs, const Self &rhs) {
        Self res = lhs;
        res *= rhs;
        return res;
    }
    friend Self operator+(const Self &lhs, const Self &rhs) {
        Self res = lhs;
        res += rhs;
        return res;
    }
    friend Self operator-(const Self &lhs, const Self &rhs) {
        Self res = lhs;
        res -= rhs;
        return res;
    }
    friend Self operator/(const Self &lhs, const Self &rhs) {
        Self res = lhs;
        res /= rhs;
        return res;
    }
};
