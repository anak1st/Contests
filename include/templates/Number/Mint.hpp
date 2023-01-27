#pragma once
#include "XCPC.h"

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
    int v;
    int M() const {
        if constexpr (Mod <= 0) {
            return P;
        } else {
            return Mod;
        }
    }
    // assume -M <= __x < 2 M
    int norm(int x) const {
        if (x >= P) {
            x -= M();
        } else if (x < 0) {
            x += M();
        }
        return x;
    }
    MintBase() : v(0) {}
    MintBase(int x) : v(norm(x)) {}
    MintBase(i64 x) : v(norm(x % M())) {}
    int val() const {
        return v;
    }
    MintBase operator-() const {
        return MintBase(norm(M() - v));
    }
    MintBase inv() const {
        assert(v != 0);
        return power(*this, M() - 2);
    }
    MintBase &operator+=(const MintBase &rhs) {
        v = norm(v + rhs.v);
        return *this;
    }
    MintBase &operator-=(const MintBase &rhs) {
        v = norm(v - rhs.v);
        return *this;
    }
    MintBase &operator*=(const MintBase &rhs) {
        v = 1LL * v * rhs.v % M();
        return *this;
    }
    MintBase &operator/=(const MintBase &rhs) {
        return *this *= rhs.inv();
    }
    friend bool operator==(const MintBase &lhs, const MintBase &rhs) {
        return lhs.val() == rhs.val();
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
    friend MintBase operator*(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res *= rhs;
        return res;
    }
    friend MintBase operator/(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, MintBase &a) {
        i64 x;
        is >> x;
        a = MintBase(x);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const MintBase &a) {
        return os << a.val();
    }
};
// using Mint = MintBase<0>;
