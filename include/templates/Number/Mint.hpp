#pragma once
#include "templates/XCPC.h"

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
    int val() const { return x; }
    MintBase operator-() const { return MintBase(mod(M() - x)); }
    MintBase inv() const {
        assert(x != 0);
        return power(*this, M() - 2);
    }
    friend bool operator==(const MintBase &lhs, const MintBase &rhs) {
        return lhs.x == rhs.x;
    }
    MintBase &operator*=(const MintBase &rhs) {
        x = 1LL * x * rhs.x % M();
        return *this;
    }
    MintBase &operator+=(const MintBase &rhs) {
        x = mod(x + rhs.x);
        return *this;
    }
    MintBase &operator-=(const MintBase &rhs) {
        x = mod(x - rhs.x);
        return *this;
    }
    MintBase &operator/=(const MintBase &rhs) { return *this *= rhs.inv(); }
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
    friend std::istream &operator>>(std::istream &is, MintBase &a) {
        i64 v;
        is >> v;
        a = MintBase(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const MintBase &a) {
        return os << a.val();
    }
};
// using Mint = MintBase<-1>;
