#pragma once

#include <cassert>
#include <iostream>

template <int Mod>
class MintBase {
public:
    using i64 = long long;

    int mod(i64 x) const { return (x % Mod + Mod) % Mod; }

    MintBase power(MintBase a, i64 b) {
        MintBase res = 1;
        for (; b; b /= 2, a *= a) {
            if (b % 2) {
                res *= a;
            }
        }
        return res;
    }

private:
    int v;

public:
    MintBase() : v(0) {}
    MintBase(int x) : v(mod(x)) {}
    MintBase(i64 x) : v(mod(x)) {}

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

    int val() const { return v; }

    MintBase operator-() const { return MintBase(mod(-v)); }

    MintBase inv() const {
        assert(v != 0);
        return power(*this, Mod - 2);
    }

    MintBase &operator++() { return *this += 1; }
    MintBase &operator--() { return *this -= 1; }

    MintBase &operator+=(const MintBase &rhs) {
        v = modulo(v + rhs.v);
        return *this;
    }
    MintBase &operator-=(const MintBase &rhs) {
        v = modulo(v - rhs.v);
        return *this;
    }
    MintBase &operator*=(const MintBase &rhs) {
        v = modulo(1LL * v * rhs.v);
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


