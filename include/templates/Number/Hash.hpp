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
template <int Mod>
struct MintBase {
    int x;
    int M() {
        if constexpr(Mod == -1) {
            return P;
        } else {
            return Mod;
        }
    }
    // assume -M <= x < 2 M
    int mod(int x) {
        if (x < 0) {
            x += M();
        }
        if (x >= P) {
            x -= M();
        }
        return x;
    }
    MintBase() : x(0) {}
    MintBase(int x) : x(mod(x)) {}
    MintBase(i64 x) : x(mod(x % M())) {}
    using Mint = MintBase<Mod>;
    int val() const {
        return x;
    }
    Mint operator-() const {
        return Mint(mod(M() - x));
    }
    Mint inv() const {
        assert(x != 0);
        return power(*this, M() - 2);
    }
    friend bool operator==(const Mint &lhs, const Mint &rhs) {
        return lhs.x == rhs.x;
    }
    Mint &operator*=(const Mint &rhs) {
        x = 1LL * x * rhs.x % M();
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
using Mint = MintBase<-1>;

constexpr int Mod1 = 1e9 + 7, Mod2 = 1e9 + 9;
struct Hash {
    MintBase<Mod1> x;
    MintBase<Mod2> y;
    Hash() : x(0), y(0) {}
    Hash(int _x, int _y) : x(_x), y(_y) {}
    Hash(MintBase<Mod1> _x, MintBase<Mod2> _y) : x(_x), y(_y) {}
    friend Hash operator+(const Hash &lhs, const Hash &rhs) {
        return Hash(lhs.x + rhs.x, lhs.y + rhs.y);
    }
    friend Hash operator-(const Hash &lhs, const Hash &rhs) {
        return Hash(lhs.x - rhs.x, lhs.y - rhs.y);
    }
    friend Hash operator*(const Hash &lhs, const Hash &rhs) {
        return Hash(lhs.x * rhs.x, lhs.y * rhs.y);
    }
    friend bool operator==(const Hash &lhs, const Hash &rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
};
Hash base(13331, 23333);
