#pragma once
#include "XCPC.h"

template <typename T> constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
template <i64 P> struct MintBase {
    i64 v;
    constexpr i64 norm(i64 x) const {
        x %= P;
        if (x < 0) {
            x += P;
        }
        return x;
    }
    constexpr MintBase() : v{0} {}
    constexpr MintBase(i64 x) : v{norm(x)} {}
    explicit constexpr operator i64() const {
        return v;
    }
    constexpr i64 val() const {
        return v;
    }
    constexpr MintBase operator-() const {
        return MintBase(norm(P - v));
    }
    constexpr MintBase inv() const {
        assert(v != 0);
        return power(*this, P - 2);
    }
    constexpr MintBase &operator+=(const MintBase &rhs) {
        v = norm(v + rhs.v);
        return *this;
    }
    constexpr MintBase &operator-=(const MintBase &rhs) {
        v = norm(v - rhs.v);
        return *this;
    }
    constexpr MintBase &operator*=(const MintBase &rhs) {
        v = norm(v * rhs.v);
        return *this;
    }
    constexpr MintBase &operator/=(const MintBase &rhs) {
        return *this *= rhs.inv();
    }
    friend constexpr MintBase operator+(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MintBase operator-(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MintBase operator*(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MintBase operator/(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MintBase &a) {
        i64 x;
        is >> x;
        a = MintBase(x);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MintBase &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(const MintBase &lhs, const MintBase &rhs) {
        return lhs.val() == rhs.val();
    }
};
// constexpr i64 P = 1e9 + 7;
// using Mint = MintBase<P>;
