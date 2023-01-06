// from tourist
#pragma once

#include <cassert>
#include <iostream>

using i64 = long long;

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

template <int MOD>
struct MintBase {
    using Self = MintBase;

    int v;

    MintBase() : v(0) {}
    MintBase(int x) : v(mod(x)) {}
    MintBase(i64 x) : v(mod(x)) {}

    int mod(i64 x) {
        return (x % MOD + MOD) % MOD;
    }

    int val() const {
        return v;
    }

    friend std::istream &operator>>(std::istream &is, MintBase &a) {
        i64 x;
        is >> x;
        a.v = a.mod(x);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const MintBase &a) {
        os << a.val();
        return os;
    }

    MintBase operator-() const {
        return MintBase(-v);
    }

    MintBase inv() const {
        assert(v != 0);
        return power(*this, MOD - 2);
    }

    MintBase &operator++() {
        return *this += 1;
    }
    MintBase &operator--() {
        return *this -= 1;
    }
    MintBase operator++(int) {
        MintBase res = *this;
        *this += 1;
        return res;
    }
    MintBase operator--(int) {
        MintBase res = *this;
        *this -= 1;
        return res;
    }

    MintBase &operator+=(const MintBase &rhs) {
        v = mod(v + rhs.v);
        return *this;
    }
    MintBase &operator-=(const MintBase &rhs) {
        v = mod(v - rhs.v);
        return *this;
    }
    MintBase &operator*=(const MintBase &rhs) {
        v = mod(1LL * v * rhs.v);
        return *this;
    }
    MintBase &operator/=(const MintBase &rhs) {
        *this *= rhs.inv();
        return *this;
    }

    friend MintBase operator*(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res *= rhs;
        return res;
    }
    friend MintBase operator+(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res += rhs;
        return res;
    }
    friend MintBase operator-(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res -= rhs;
        return res;
    }
    friend MintBase operator/(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res /= rhs;
        return res;
    }
};

// constexpr int P = 1e9 + 7;
// using Mint = MintBase<P>;
